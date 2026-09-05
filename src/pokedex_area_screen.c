#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex_area_screen.h"
#include "pokedex_area_region_map.h"
#include "region_map.h"
#include "roamer.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "trig.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define AREA_SCREEN_WIDTH 32
#define AREA_SCREEN_HEIGHT 20

#define MAP_GROUP_TOWNS_AND_ROUTES MAP_GROUP(MAP_PETALBURG_CITY)
#define MAP_GROUP_DUNGEONS MAP_GROUP(MAP_METEOR_FALLS_1F_1R)
#define MAP_GROUP_SPECIAL_AREA MAP_GROUP(MAP_SAFARI_ZONE_NORTHWEST)

#define GLOW_FULL      0xFFFF
#define GLOW_EDGE_R    (1 << 0)
#define GLOW_EDGE_L    (1 << 1)
#define GLOW_EDGE_B    (1 << 2)
#define GLOW_EDGE_T    (1 << 3)
#define GLOW_CORNER_TL (1 << 4)
#define GLOW_CORNER_BL (1 << 5)
#define GLOW_CORNER_TR (1 << 6)
#define GLOW_CORNER_BR (1 << 7)

#define GLOW_PALETTE 10

#define TAG_AREA_MARKER 2
#define TAG_AREA_UNKNOWN 3

#define MAX_AREA_HIGHLIGHTS 64
#define MAX_AREA_MARKERS 32

struct OverworldArea
{
    u8 mapGroup;
    u8 mapNum;
    mapsec_u16_t regionMapSectionId;
};

struct PokedexAreaScreen
{
    /*0x000*/ void (*callback)(void);
    /*0x004*/ MainCallback prev;
    /*0x008*/ MainCallback next;
    /*0x00C*/ u16 state;
    /*0x00E*/ u16 species;
    /*0x010*/ struct OverworldArea overworldAreasWithMons[MAX_AREA_HIGHLIGHTS];
    /*0x110*/ u16 numOverworldAreas;
    /*0x112*/ u16 numSpecialAreas;
    /*0x114*/ u16 drawAreaGlowState;
    /*0x116*/ u16 areaGlowTilemap[AREA_SCREEN_WIDTH * AREA_SCREEN_HEIGHT];
    /*0x616*/ u16 markerTimer;
    /*0x618*/ u16 glowTimer;
    /*0x61A*/ u16 areaShadeBldArgLo;
    /*0x61C*/ u16 areaShadeBldArgHi;
    /*0x61E*/ bool8 showingMarkers;
    /*0x61F*/ u8 markerFlashCounter;
    /*0x620*/ mapsec_u16_t specialAreaRegionMapSectionIds[MAX_AREA_MARKERS];
    /*0x660*/ struct Sprite *areaMarkerSprites[MAX_AREA_MARKERS];
    /*0x6E0*/ u16 numAreaMarkerSprites;
    /*0x6E2*/ u16 alteringCaveCounter;
    /*0x6E4*/ u16 alteringCaveId;
    /*0x6E8*/ u8 *screenSwitchState;
    /*0x6EC*/ struct RegionMap regionMap;
    /*0xF70*/ u8 charBuffer[64];
    /*0xFB0*/ struct Sprite *areaUnknownSprites[3];
    /*0xFBC*/ u8 areaUnknownGraphicsBuffer[0x600];
};

extern struct PokedexAreaScreen *gUnknown_203A848;
extern u32 gUnknown_20374F4[];
extern const u32 gUnknown_859381C[];
extern const u32 gUnknown_859383C[];
extern const u16 gUnknown_8593970[];
extern const u16 gUnknown_8593972[];
extern const u16 gUnknown_8593978[][3];
extern const u16 gUnknown_8593984[][2];
extern const struct PokedexAreaMapTemplate gUnknown_85939A0;
extern const struct SpriteSheet gUnknown_85939A4;
extern const struct SpritePalette gUnknown_85939AC;
extern const struct SpriteTemplate gUnknown_85939BC;
extern const struct SpritePalette gUnknown_8593A74;
extern const struct SpriteTemplate gUnknown_8593A84;
extern const u32 gUnknown_8593ABC[];
extern s16 gUnknown_30011FC;
extern s16 gUnknown_30011FE;
extern s16 gUnknown_3001200;
extern s16 gUnknown_3001202;
extern s16 gUnknown_3001204;

struct JPRegionMapEntry
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u8 unused[4];
};

extern const struct JPRegionMapEntry gUnknown_857CD6C[];

bool8 DrawAreaGlow(void);
void FindMapsWithMon(u16 species);
void BuildAreaGlowTilemap(void);
void SetAreaHasMon(u16 mapGroup, u16 mapNum);
void SetSpecialMapHasMon(u16 mapGroup, u16 mapNum);
mapsec_u16_t GetRegionMapSectionId(u8 mapGroup, u8 mapNum);
bool8 MapHasMon(const struct WildPokemonHeader *info, u16 species);
bool8 MonListHasMon(const struct WildPokemonInfo *info, u16 species, u16 size);
void StartAreaGlow(void);
void DoAreaGlow(void);
void Task_PokedexAreaScreen_0(u8 taskId);
void Task_PokedexAreaScreen_1(u8 taskId);
void sub_0813D7B8(void);
void CreateAreaMarkerSprites(void);
void DestroyAreaMarkerSprites(void);
void LoadAreaUnknownGraphics(void);
void CreateAreaUnknownSprites(void);
void sub_08122D94(struct RegionMap *regionMap);
void EvolutionScene(struct Pokemon *mon, u16 postEvoSpecies, bool8 canStopEvo, u8 partyId);

void ResetDrawAreaGlowState(void)
{
    gUnknown_203A848->drawAreaGlowState = 0;
}

bool8 DrawAreaGlow(void)
{
    switch (gUnknown_203A848->drawAreaGlowState)
    {
    case 0:
        FindMapsWithMon(gUnknown_203A848->species);
        break;
    case 1:
        BuildAreaGlowTilemap();
        break;
    case 2:
        DecompressAndCopyTileDataToVram(2, gUnknown_859383C, 0, 0, 0);
        LoadBgTilemap(2, gUnknown_203A848->areaGlowTilemap, sizeof(gUnknown_203A848->areaGlowTilemap), 0);
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            CpuSet(gUnknown_859381C, gUnknown_20374F4, 0x04000008);
            gUnknown_203A848->drawAreaGlowState++;
        }
        return TRUE;
    case 4:
        ChangeBgY(2, -0x800, BG_COORD_SET);
        break;
    default:
        return FALSE;
    }

    gUnknown_203A848->drawAreaGlowState++;
    return TRUE;
}

void FindMapsWithMon(u16 species)
{
    u16 i;
    struct Roamer *roamer;

    gUnknown_203A848->alteringCaveCounter = 0;
    gUnknown_203A848->alteringCaveId = VarGet(VAR_ALTERING_CAVE_WILD_SET);
    if (gUnknown_203A848->alteringCaveId >= NUM_ALTERING_CAVE_TABLES)
        gUnknown_203A848->alteringCaveId = 0;

    roamer = &gSaveBlock1Ptr->roamer;
    if (species != roamer->species)
    {
        gUnknown_203A848->numOverworldAreas = 0;
        gUnknown_203A848->numSpecialAreas = 0;

        for (i = 0; i < 1; i++)
        {
            if (gUnknown_8593970[i] == species)
                return;
        }

        for (i = 0; gUnknown_8593978[i][0] != NUM_SPECIES; i++)
        {
            if (species == gUnknown_8593978[i][0])
            {
                switch (gUnknown_8593978[i][1])
                {
                case MAP_GROUP_TOWNS_AND_ROUTES:
                    SetAreaHasMon(gUnknown_8593978[i][1], gUnknown_8593978[i][2]);
                    break;
                case MAP_GROUP_DUNGEONS:
                case MAP_GROUP_SPECIAL_AREA:
                    SetSpecialMapHasMon(gUnknown_8593978[i][1], gUnknown_8593978[i][2]);
                    break;
                }
            }
        }

        for (i = 0; gWildMonHeaders[i].mapGroup != MAP_GROUP(MAP_UNDEFINED); i++)
        {
            if (MapHasMon(&gWildMonHeaders[i], species))
            {
                switch (gWildMonHeaders[i].mapGroup)
                {
                case MAP_GROUP_TOWNS_AND_ROUTES:
                    SetAreaHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                    break;
                case MAP_GROUP_DUNGEONS:
                case MAP_GROUP_SPECIAL_AREA:
                    SetSpecialMapHasMon(gWildMonHeaders[i].mapGroup, gWildMonHeaders[i].mapNum);
                    break;
                }
            }
        }
    }
    else
    {
        gUnknown_203A848->numSpecialAreas = 0;
        if (roamer->active)
        {
            GetRoamerLocation(&gUnknown_203A848->overworldAreasWithMons[0].mapGroup, &gUnknown_203A848->overworldAreasWithMons[0].mapNum);
            gUnknown_203A848->overworldAreasWithMons[0].regionMapSectionId =
                Overworld_GetMapHeaderByGroupAndId(gUnknown_203A848->overworldAreasWithMons[0].mapGroup, gUnknown_203A848->overworldAreasWithMons[0].mapNum)->regionMapSectionId;
            gUnknown_203A848->numOverworldAreas = 1;
        }
        else
        {
            gUnknown_203A848->numOverworldAreas = 0;
        }
    }
}

void SetAreaHasMon(u16 mapGroup, u16 mapNum)
{
    if (gUnknown_203A848->numOverworldAreas < MAX_AREA_HIGHLIGHTS)
    {
        gUnknown_203A848->overworldAreasWithMons[gUnknown_203A848->numOverworldAreas].mapGroup = mapGroup;
        gUnknown_203A848->overworldAreasWithMons[gUnknown_203A848->numOverworldAreas].mapNum = mapNum;
        gUnknown_203A848->overworldAreasWithMons[gUnknown_203A848->numOverworldAreas].regionMapSectionId =
            CorrectSpecialMapSecId(Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId);
        gUnknown_203A848->numOverworldAreas++;
    }
}

void SetSpecialMapHasMon(u16 mapGroup, u16 mapNum)
{
    int i;

    if (gUnknown_203A848->numSpecialAreas < MAX_AREA_MARKERS)
    {
        mapsec_u16_t regionMapSectionId = GetRegionMapSectionId(mapGroup, mapNum);
        if (regionMapSectionId < MAPSEC_NONE)
        {
            for (i = 0; (u32)i < 3; i++)
            {
                if (regionMapSectionId == gUnknown_8593972[i])
                    return;
            }

            for (i = 0; gUnknown_8593984[i][0] != MAPSEC_NONE; i++)
            {
                if (regionMapSectionId == gUnknown_8593984[i][0] && !FlagGet(gUnknown_8593984[i][1]))
                    return;
            }

            for (i = 0; i < gUnknown_203A848->numSpecialAreas; i++)
            {
                if (gUnknown_203A848->specialAreaRegionMapSectionIds[i] == regionMapSectionId)
                    break;
            }

            if (i == gUnknown_203A848->numSpecialAreas)
            {
                gUnknown_203A848->specialAreaRegionMapSectionIds[i] = regionMapSectionId;
                gUnknown_203A848->numSpecialAreas++;
            }
        }
    }
}

mapsec_u16_t GetRegionMapSectionId(u8 mapGroup, u8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->regionMapSectionId;
}

bool8 MapHasMon(const struct WildPokemonHeader *info, u16 species)
{
    if (GetRegionMapSectionId(info->mapGroup, info->mapNum) == MAPSEC_ALTERING_CAVE)
    {
        gUnknown_203A848->alteringCaveCounter++;
        if (gUnknown_203A848->alteringCaveCounter != gUnknown_203A848->alteringCaveId + 1)
            return FALSE;
    }

    if (MonListHasMon(info->landMonsInfo, species, NUM_LAND_MONS_ENCOUNTER_SLOTS))
        return TRUE;
    if (MonListHasMon(info->waterMonsInfo, species, NUM_WATER_MONS_ENCOUNTER_SLOTS))
        return TRUE;
    if (MonListHasMon(info->fishingMonsInfo, species, NUM_LAND_MONS_ENCOUNTER_SLOTS))
        return TRUE;
    if (MonListHasMon(info->rockSmashMonsInfo, species, NUM_ROCK_SMASH_MONS_ENCOUNTER_SLOTS))
        return TRUE;
    return FALSE;
}

bool8 MonListHasMon(const struct WildPokemonInfo *info, u16 species, u16 size)
{
    u16 i;

    if (info != NULL)
    {
        for (i = 0; i < size; i++)
        {
            if (info->wildPokemon[i].species == species)
                return TRUE;
        }
    }
    return FALSE;
}

// Byte-exact JP exception: this 0x3E4-byte tilemap state machine has an
// 11-entry edge/corner dispatch and data layout absent from the US 0x2BC C
// body, so agbcc cannot currently reproduce its branch-expanded ROM code.
__attribute__((naked)) void BuildAreaGlowTilemap(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r7, #0\n\t"
        "	ldr r0, _0813D0F4\n\t"
        "	mov sb, r0\n\t"
        "	mov r5, sb\n\t"
        "	movs r4, #0x8b\n\t"
        "	lsls r4, r4, #1\n\t"
        "	movs r3, #0\n\t"
        "	ldr r2, _0813D0F8\n\t"
        "_0813CF04:\n\t"
        "	ldr r0, [r5]\n\t"
        "	lsls r1, r7, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r3, [r0]\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	cmp r7, r2\n\t"
        "	bls _0813CF04\n\t"
        "	movs r7, #0\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r2, #0x88\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	bhs _0813CF92\n\t"
        "	mov r3, sb\n\t"
        "_0813CF2C:\n\t"
        "	movs r5, #0\n\t"
        "	movs r6, #0\n\t"
        "	adds r0, r7, #1\n\t"
        "	mov r8, r0\n\t"
        "	lsls r7, r7, #2\n\t"
        "	mov sl, r7\n\t"
        "_0813CF38:\n\t"
        "	movs r4, #0\n\t"
        "_0813CF3A:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	str r3, [sp]\n\t"
        "	bl GetRegionMapSectionIdAt\n\t"
        "	ldr r3, [sp]\n\t"
        "	ldr r2, [r3]\n\t"
        "	mov r7, sl\n\t"
        "	adds r1, r2, r7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrh r1, [r1, #0x12]\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0813CF64\n\t"
        "	lsls r0, r5, #1\n\t"
        "	movs r7, #0x8b\n\t"
        "	lsls r7, r7, #1\n\t"
        "	adds r1, r2, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0813D0FC\n\t"
        "	strh r0, [r1]\n\t"
        "_0813CF64:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #0x1f\n\t"
        "	bls _0813CF3A\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	cmp r6, #0x13\n\t"
        "	bls _0813CF38\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	ldr r0, [r3]\n\t"
        "	movs r2, #0x88\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	blo _0813CF2C\n\t"
        "_0813CF92:\n\t"
        "	movs r5, #0\n\t"
        "	movs r6, #0\n\t"
        "	ldr r7, _0813D0F4\n\t"
        "	mov ip, r7\n\t"
        "	movs r7, #0x8b\n\t"
        "	lsls r7, r7, #1\n\t"
        "	ldr r3, _0813D0FC\n\t"
        "_0813CFA0:\n\t"
        "	movs r4, #0\n\t"
        "	adds r0, r6, #1\n\t"
        "	mov sl, r0\n\t"
        "_0813CFA6:\n\t"
        "	mov r1, ip\n\t"
        "	ldr r0, [r1]\n\t"
        "	lsls r1, r5, #1\n\t"
        "	adds r2, r0, r7\n\t"
        "	adds r1, r2, r1\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r1, r5, #1\n\t"
        "	mov r8, r1\n\t"
        "	cmp r0, r3\n\t"
        "	bne _0813D0B2\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0813CFD0\n\t"
        "	subs r0, r5, #1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r2, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813CFD0\n\t"
        "	movs r0, #2\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813CFD0:\n\t"
        "	adds r2, r5, #1\n\t"
        "	mov r8, r2\n\t"
        "	cmp r4, #0x1f\n\t"
        "	beq _0813CFEE\n\t"
        "	mov r1, ip\n\t"
        "	ldr r0, [r1]\n\t"
        "	lsls r1, r2, #1\n\t"
        "	adds r0, r0, r7\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrh r1, [r2]\n\t"
        "	cmp r1, r3\n\t"
        "	beq _0813CFEE\n\t"
        "	movs r0, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "_0813CFEE:\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0813D00C\n\t"
        "	mov r2, ip\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r0, r5, #0\n\t"
        "	subs r0, #0x20\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D00C\n\t"
        "	movs r0, #8\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D00C:\n\t"
        "	cmp r6, #0x13\n\t"
        "	beq _0813D02A\n\t"
        "	mov r0, ip\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x20\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D02A\n\t"
        "	movs r0, #4\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D02A:\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0813D04C\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0813D04C\n\t"
        "	mov r2, ip\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r0, r5, #0\n\t"
        "	subs r0, #0x21\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D04C\n\t"
        "	movs r0, #0x10\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D04C:\n\t"
        "	cmp r4, #0x1f\n\t"
        "	beq _0813D06E\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0813D06E\n\t"
        "	mov r0, ip\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	subs r0, #0x1f\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D06E\n\t"
        "	movs r0, #0x40\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D06E:\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0813D090\n\t"
        "	cmp r6, #0x13\n\t"
        "	beq _0813D090\n\t"
        "	mov r2, ip\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x1f\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D090\n\t"
        "	movs r0, #0x20\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D090:\n\t"
        "	cmp r4, #0x1f\n\t"
        "	beq _0813D0B2\n\t"
        "	cmp r6, #0x13\n\t"
        "	beq _0813D0B2\n\t"
        "	mov r0, ip\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r2, r3\n\t"
        "	beq _0813D0B2\n\t"
        "	movs r0, #0x80\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D0B2:\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #0x1f\n\t"
        "	bhi _0813D0C4\n\t"
        "	b _0813CFA6\n\t"
        "_0813D0C4:\n\t"
        "	mov r2, sl\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	cmp r6, #0x13\n\t"
        "	bhi _0813D0D0\n\t"
        "	b _0813CFA0\n\t"
        "_0813D0D0:\n\t"
        "	movs r7, #0\n\t"
        "_0813D0D2:\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	lsls r1, r7, #1\n\t"
        "	movs r6, #0x8b\n\t"
        "	lsls r6, r6, #1\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrh r4, [r3]\n\t"
        "	adds r2, r4, #0\n\t"
        "	ldr r0, _0813D0FC\n\t"
        "	adds r5, r1, #0\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0813D104\n\t"
        "	ldr r0, _0813D100\n\t"
        "	strh r0, [r3]\n\t"
        "	b _0813D2A8\n\t"
        "	.align 2, 0\n\t"
        "_0813D0F4: .4byte gUnknown_203A848\n\t"
        "_0813D0F8: .4byte 0x0000027F\n\t"
        "_0813D0FC: .4byte 0x0000FFFF\n\t"
        "_0813D100: .4byte 0x0000A010\n\t"
        "_0813D104:\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0813D10A\n\t"
        "	b _0813D2A8\n\t"
        "_0813D10A:\n\t"
        "	movs r2, #0xa0\n\t"
        "	lsls r2, r2, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r0, #0\n\t"
        "	orrs r1, r4\n\t"
        "	strh r1, [r3]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813D124\n\t"
        "	ldr r0, _0813D198\n\t"
        "	ands r1, r0\n\t"
        "	strh r1, [r3]\n\t"
        "_0813D124:\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r2, r0, r5\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813D13C\n\t"
        "	ldr r0, _0813D19C\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "_0813D13C:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r2, r0, r5\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813D154\n\t"
        "	ldr r0, _0813D1A0\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "_0813D154:\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r2, r0, r5\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813D16C\n\t"
        "	ldr r0, _0813D1A4\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "_0813D16C:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r4, r0, r5\n\t"
        "	ldrh r0, [r4]\n\t"
        "	movs r1, #0xf\n\t"
        "	ands r1, r0\n\t"
        "	adds r3, r1, #0\n\t"
        "	movs r2, #0xf0\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0813D186\n\t"
        "	b _0813D2A8\n\t"
        "_0813D186:\n\t"
        "	strh r1, [r4]\n\t"
        "	cmp r3, #0xa\n\t"
        "	bls _0813D18E\n\t"
        "	b _0813D2A8\n\t"
        "_0813D18E:\n\t"
        "	lsls r0, r3, #2\n\t"
        "	ldr r1, _0813D1A8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0813D198: .4byte 0x0000FFCF\n\t"
        "_0813D19C: .4byte 0x0000FF3F\n\t"
        "_0813D1A0: .4byte 0x0000FFAF\n\t"
        "_0813D1A4: .4byte 0x0000FF5F\n\t"
        "_0813D1A8: .4byte _0813D1AC\n\t"
        "_0813D1AC:\n\t"
        "	.4byte _0813D1D8\n\t"
        "	.4byte _0813D208\n\t"
        "	.4byte _0813D1F0\n\t"
        "	.4byte _0813D2A8\n\t"
        "	.4byte _0813D254\n\t"
        "	.4byte _0813D284\n\t"
        "	.4byte _0813D284\n\t"
        "	.4byte _0813D2A8\n\t"
        "	.4byte _0813D224\n\t"
        "	.4byte _0813D296\n\t"
        "	.4byte _0813D296\n\t"
        "_0813D1D8:\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D2A8\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0x8b\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #0x10\n\t"
        "	lsrs r2, r2, #4\n\t"
        "	b _0813D21E\n\t"
        "_0813D1F0:\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D2A8\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0x8b\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #0x1e\n\t"
        "	lsrs r2, r2, #4\n\t"
        "	b _0813D21E\n\t"
        "_0813D208:\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D2A8\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0x8b\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #0x20\n\t"
        "	lsrs r2, r2, #6\n\t"
        "_0813D21E:\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r1, [r0]\n\t"
        "	b _0813D2A8\n\t"
        "_0813D224:\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D2A8\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsrs r3, r0, #0x1f\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D240\n\t"
        "	movs r0, #2\n\t"
        "	orrs r3, r0\n\t"
        "_0813D240:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x8b\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #0x20\n\t"
        "	adds r0, r0, r3\n\t"
        "	b _0813D2A6\n\t"
        "_0813D254:\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D2A8\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsrs r3, r0, #0x1f\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0813D270\n\t"
        "	movs r0, #2\n\t"
        "	orrs r3, r0\n\t"
        "_0813D270:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x8b\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #0x21\n\t"
        "	adds r0, r0, r3\n\t"
        "	b _0813D2A6\n\t"
        "_0813D284:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x8b\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #0x27\n\t"
        "	b _0813D2A6\n\t"
        "_0813D296:\n\t"
        "	mov r2, sb\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x8b\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #0x25\n\t"
        "_0813D2A6:\n\t"
        "	strh r0, [r1]\n\t"
        "_0813D2A8:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	ldr r0, _0813D2C8\n\t"
        "	cmp r7, r0\n\t"
        "	bhi _0813D2B6\n\t"
        "	b _0813D0D2\n\t"
        "_0813D2B6:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813D2C8: .4byte 0x0000027F\n\t"
        ".syntax divided\n\t"
    );
}

void StartAreaGlow(void)
{
    if (gUnknown_203A848->numSpecialAreas && gUnknown_203A848->numOverworldAreas == 0)
        gUnknown_203A848->showingMarkers = TRUE;
    else
        gUnknown_203A848->showingMarkers = FALSE;

    gUnknown_203A848->markerTimer = 0;
    gUnknown_203A848->glowTimer = 0;
    gUnknown_203A848->areaShadeBldArgLo = 0;
    gUnknown_203A848->areaShadeBldArgHi = 64;
    gUnknown_203A848->markerFlashCounter = 1;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    DoAreaGlow();
}

void DoAreaGlow(void)
{
    u16 x;
    u16 y;
    u16 i;

    if (!gUnknown_203A848->showingMarkers)
    {
        if (gUnknown_203A848->markerTimer == 0)
        {
            gUnknown_203A848->glowTimer++;
            if (gUnknown_203A848->glowTimer & 1)
                gUnknown_203A848->areaShadeBldArgLo = (gUnknown_203A848->areaShadeBldArgLo + 4) & 0x7F;
            else
                gUnknown_203A848->areaShadeBldArgHi = (gUnknown_203A848->areaShadeBldArgHi + 4) & 0x7F;

            x = gSineTable[gUnknown_203A848->areaShadeBldArgLo] >> 4;
            y = gSineTable[gUnknown_203A848->areaShadeBldArgHi] >> 4;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(x, y));
            gUnknown_203A848->markerTimer = 0;
            if (gUnknown_203A848->glowTimer == 64)
            {
                gUnknown_203A848->glowTimer = 0;
                if (gUnknown_203A848->numSpecialAreas != 0)
                    gUnknown_203A848->showingMarkers = TRUE;
            }
        }
        else
        {
            gUnknown_203A848->markerTimer--;
        }
    }
    else
    {
        gUnknown_203A848->markerTimer++;
        if (gUnknown_203A848->markerTimer > 12)
        {
            gUnknown_203A848->markerTimer = 0;
            gUnknown_203A848->markerFlashCounter++;
            for (i = 0; i < gUnknown_203A848->numSpecialAreas; i++)
                gUnknown_203A848->areaMarkerSprites[i]->invisible = gUnknown_203A848->markerFlashCounter & 1;

            if (gUnknown_203A848->markerFlashCounter > 4)
            {
                gUnknown_203A848->markerFlashCounter = 1;
                if (gUnknown_203A848->numOverworldAreas != 0)
                    gUnknown_203A848->showingMarkers = FALSE;
            }
        }
    }
}

void ShowPokedexAreaScreen(u16 species, u8 *screenSwitchState)
{
    u8 taskId;

    gUnknown_203A848 = AllocZeroed(sizeof(*gUnknown_203A848));
    gUnknown_203A848->species = species;
    gUnknown_203A848->screenSwitchState = screenSwitchState;
    screenSwitchState[0] = 0;
    taskId = CreateTask(Task_PokedexAreaScreen_0, 0);
    gTasks[taskId].data[0] = 0;
}

void Task_PokedexAreaScreen_0(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        ResetSpriteData();
        FreeAllSpritePalettes();
        HideBg(3);
        HideBg(2);
        HideBg(0);
        break;
    case 1:
        SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 3);
        LoadPokedexAreaMapGfx(&gUnknown_85939A0);
        StringFill(gUnknown_203A848->charBuffer, 0, 10);
        break;
    case 2:
        if (TryShowPokedexAreaMap() == TRUE)
            return;
        PokedexAreaMapChangeBgY(-8);
        break;
    case 3:
        ResetDrawAreaGlowState();
        break;
    case 4:
        if (DrawAreaGlow())
            return;
        break;
    case 5:
        sub_08122D94(&gUnknown_203A848->regionMap);
        CreateRegionMapPlayerIcon(1, 1);
        PokedexAreaScreen_UpdateRegionMapVariablesAndVideoRegs(0, -8);
        break;
    case 6:
        CreateAreaMarkerSprites();
        break;
    case 7:
        LoadAreaUnknownGraphics();
        break;
    case 8:
        CreateAreaUnknownSprites();
        break;
    case 9:
        BeginNormalPaletteFade(-0x15, 0, 16, 0, RGB_BLACK);
        break;
    case 10:
        SetGpuReg(REG_OFFSET_BLDCNT, 0x3F41);
        StartAreaGlow();
        ShowBg(2);
        ShowBg(3);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON);
        break;
    case 11:
        gTasks[taskId].func = Task_PokedexAreaScreen_1;
        gTasks[taskId].data[0] = 0;
        return;
    }

    gTasks[taskId].data[0]++;
}

void Task_PokedexAreaScreen_1(u8 taskId)
{
    DoAreaGlow();
    switch (gTasks[taskId].data[0])
    {
    default:
        gTasks[taskId].data[0] = 0;
    case 0:
        if (gPaletteFade.active)
            return;
        break;
    case 1:
        if (JOY_NEW(B_BUTTON))
        {
            gTasks[taskId].data[1] = 1;
            PlaySE(SE_PC_OFF);
        }
        else if (JOY_NEW(DPAD_RIGHT) || (JOY_NEW(R_BUTTON) && gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR))
        {
            gTasks[taskId].data[1] = 2;
            PlaySE(SE_DEX_PAGE);
        }
        else
        {
            return;
        }
        break;
    case 2:
        BeginNormalPaletteFade(-0x15, 0, 0, 16, RGB_BLACK);
        break;
    case 3:
        if (gPaletteFade.active)
            return;
        DestroyAreaMarkerSprites();
        gUnknown_203A848->screenSwitchState[0] = gTasks[taskId].data[1];
        sub_0813D7B8();
        DestroyTask(taskId);
        FreePokedexAreaMapBgNum();
        Free(gUnknown_203A848);
        gUnknown_203A848 = NULL;
        return;
    }

    gTasks[taskId].data[0]++;
}

void sub_0813D7B8(void)
{
    SetBgAttribute(3, BG_ATTR_CHARBASEINDEX, 0);
    SetBgAttribute(3, BG_ATTR_PALETTEMODE, 0);
}

void CreateAreaMarkerSprites(void)
{
    u8 spriteId;

    LoadSpriteSheet(&gUnknown_85939A4);
    LoadSpritePalette(&gUnknown_85939AC);
    gUnknown_3001204 = 0;
    for (gUnknown_3001200 = 0; gUnknown_3001200 < gUnknown_203A848->numSpecialAreas; gUnknown_3001200++)
    {
        gUnknown_3001202 = gUnknown_203A848->specialAreaRegionMapSectionIds[gUnknown_3001200];
        gUnknown_30011FC = 8 * (gUnknown_857CD6C[gUnknown_3001202].x + 1) + 4;
        gUnknown_30011FE = 8 * gUnknown_857CD6C[gUnknown_3001202].y + 28;
        gUnknown_30011FC += 4 * (gUnknown_857CD6C[gUnknown_3001202].width - 1);
        gUnknown_30011FE += 4 * (gUnknown_857CD6C[gUnknown_3001202].height - 1);
        spriteId = CreateSprite(&gUnknown_85939BC, gUnknown_30011FC, gUnknown_30011FE, 0);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].invisible = TRUE;
            gUnknown_203A848->areaMarkerSprites[gUnknown_3001204++] = &gSprites[spriteId];
        }
    }

    gUnknown_203A848->numAreaMarkerSprites = gUnknown_3001204;
}

void DestroyAreaMarkerSprites(void)
{
    u16 i;

    FreeSpriteTilesByTag(TAG_AREA_MARKER);
    FreeSpritePaletteByTag(TAG_AREA_MARKER);
    for (i = 0; i < gUnknown_203A848->numAreaMarkerSprites; i++)
        DestroySprite(gUnknown_203A848->areaMarkerSprites[i]);

    FreeSpriteTilesByTag(TAG_AREA_UNKNOWN);
    FreeSpritePaletteByTag(TAG_AREA_UNKNOWN);
    for (i = 0; i < 3; i++)
    {
        if (gUnknown_203A848->areaUnknownSprites[i])
            DestroySprite(gUnknown_203A848->areaUnknownSprites[i]);
    }
}

void LoadAreaUnknownGraphics(void)
{
    struct SpriteSheet spriteSheet =
    {
        .data = gUnknown_203A848->areaUnknownGraphicsBuffer,
        .size = sizeof(gUnknown_203A848->areaUnknownGraphicsBuffer),
        .tag = TAG_AREA_UNKNOWN,
    };

    LZ77UnCompWram(gUnknown_8593ABC, gUnknown_203A848->areaUnknownGraphicsBuffer);
    LoadSpriteSheet(&spriteSheet);
    LoadSpritePalette(&gUnknown_8593A74);
}

void CreateAreaUnknownSprites(void)
{
    u16 i;

    if (gUnknown_203A848->numOverworldAreas || gUnknown_203A848->numSpecialAreas)
    {
        for (i = 0; i < 3; i++)
            gUnknown_203A848->areaUnknownSprites[i] = NULL;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            u8 spriteId = CreateSprite(&gUnknown_8593A84, i * 32 + 160, 140, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.tileNum += i * 16;
                gUnknown_203A848->areaUnknownSprites[i] = &gSprites[spriteId];
            }
            else
            {
                gUnknown_203A848->areaUnknownSprites[i] = NULL;
            }
        }
    }
}

void sub_0813DAB4(void)
{
    UpdatePaletteFade();
    RunTasks();
}

// Byte-exact exception: agbcc preserves r8 for the final EvolutionScene
// argument in every C shape audited, yielding 0x88 or 0x8C bytes rather than
// this ROM function's 0x80-byte r4-r7-only register allocation.
__attribute__((naked)) void sub_0813DAC4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r7, #0\n\t"
        "	ldr r1, _0813DAE8\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r6, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813DAEC\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0813DB04\n\t"
        "	b _0813DB34\n\t"
        "	.align 2, 0\n\t"
        "_0813DAE8: .4byte gTasks\n\t"
        "_0813DAEC:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	str r7, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x10\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldrh r0, [r6, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #8]\n\t"
        "	b _0813DB34\n\t"
        "_0813DB04:\n\t"
        "	ldr r0, _0813DB3C\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813DB34\n\t"
        "	movs r0, #0x1c\n\t"
        "	ldrsh r1, [r6, r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0813DB40\n\t"
        "	adds r7, r1, r0\n\t"
        "	ldrh r4, [r6, #0xc]\n\t"
        "	ldrb r5, [r6, #0xe]\n\t"
        "	ldrb r6, [r6, #0x1c]\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl DestroyTask\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl EvolutionScene\n\t"
        "_0813DB34:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813DB3C: .4byte gPaletteFade\n\t"
        "_0813DB40: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}
