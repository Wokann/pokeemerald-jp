#include "global.h"
#include "pokemon.h"
#include "random.h"
#include "data.h"
#include "link.h"
#include "region_map.h"
#include "field_camera.h"
#include "menu.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/field_specials.h"
#include "constants/event_object_movement.h"
#include "constants/metatile_labels.h"
#include "constants/event_objects.h"
#include "constants/weather.h"
#include "constants/songs.h"
#include "overworld.h"
#include "fieldmap.h"
extern void CB2_ShowDiploma(void);
extern void CB2_ReturnToField(void);
extern void CB2_ViewWallClock(void);

#include "task.h"
extern void Task_LotteryCornerComputerEffect(u8 taskId);
extern void Task_PCTurnOnEffect(u8 taskId);
#define tPaused       data[0]
#define tTaskId       data[1]
#define tFlickerCount data[2]
#define tTimer        data[3]
#define tIsScreenOn   data[4]

#include "rtc.h"
#include "field_player_avatar.h"
#include "event_data.h"
#include "tv.h"
#include "battle.h"
#include "string_util.h"
#include "strings.h"
#include "data/field_specials.h"
#include "window.h"
extern u32 sBikeCyclingTimer;
extern u8 gUnknown_203A82A;
extern u16 gUnknown_203A82C;
extern u16 gUnknown_203A82E;
extern u8 gUnknown_203A839;
extern u8 gUnknown_203A83A;
extern const u8 gUnknown_8592E5C[];
extern const u8 gUnknown_8592E7C[];
extern u16 ItemIdToBattleMoveId(u16 itemId);
extern s32 GetRematchIdxByTrainerIdx(u16 trainerId);
extern void TV_PrintIntToStringVar(u8 stringVarIndex, s32 value);
void PCTurnOnEffect(struct Task *task);
void PCTurnOnEffect_SetMetatile(s16 isScreenOn, s8 dx, s8 dy);
void LotteryCornerComputerEffect(struct Task *task);
void TryLoseFansFromPlayTime(void);
u16 GetNumFansOfPlayerInTrainerFanClub(void);
u16 sub_0813BBAC(void);
u16 sub_0813BC38(void);
void sub_0813BDBC(void);
void sub_0813BE68(struct LinkBattleRecords *linkRecords, u8 whichLinkTrainer, u8 whichNPCTrainer);
bool8 DidPlayerGetFirstFans(void);

#define FANCLUB_BITFIELD (gSaveBlock1Ptr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START])
#define FANCLUB_COUNTER 0x007F
#define GET_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD >> (flag) & 1)
#define SET_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD |= 1 << (flag))
#define FLIP_TRAINER_FAN_CLUB_FLAG(flag) (FANCLUB_BITFIELD ^= 1 << (flag))
#define GET_TRAINER_FAN_CLUB_COUNTER (FANCLUB_BITFIELD & FANCLUB_COUNTER)
#define SET_TRAINER_FAN_CLUB_COUNTER(count) (FANCLUB_BITFIELD = (FANCLUB_BITFIELD & ~FANCLUB_COUNTER) | (count))
#define INCR_TRAINER_FAN_CLUB_COUNTER(count) (FANCLUB_BITFIELD += (count))
#define CLEAR_TRAINER_FAN_CLUB_COUNTER (FANCLUB_BITFIELD &= ~FANCLUB_COUNTER)
extern void Task_DeoxysRockInteraction(u8 taskId);

extern u8 sub_081370D8(u8 nature, u8 *dest);
extern void GetEreaderTrainerName(u8 *dest);
#include "field_specials.h"
#include "constants/characters.h"
#include "constants/map_types.h"
#include "constants/battle_frontier.h"

extern const u8 gUnknown_85CB025[];
extern const u8 gUnknown_85CB00E[];
extern const u8 gUnknown_85CB021[];
extern const u8 gUnknown_85CB018[];

#define FIELD_SPECIALS_DATA __attribute__((section(".rodata.field_specials_data")))
#define FIELD_SPECIALS_DATA_EARLY __attribute__((section(".rodata.field_specials_data_early")))
#define FIELD_SPECIALS_DATA_SLOT_MACHINE_SELECTORS __attribute__((section(".rodata.field_specials_slot_machine_selectors")))
#define FIELD_SPECIALS_DATA_ELEVATOR __attribute__((section(".rodata.field_specials_elevator_data")))
#define FIELD_SPECIALS_DATA_LINK_PARTNER __attribute__((section(".rodata.field_specials_link_partner_data")))
#define FIELD_SPECIALS_DATA_MAUVILLE_GYM __attribute__((section(".rodata.field_specials_mauville_gym_data")))
#define FIELD_SPECIALS_DATA_PETALBURG_GYM __attribute__((section(".rodata.field_specials_petalburg_gym_data")))
#define FIELD_SPECIALS_DATA_MYSTERY_GIFT_ASSERT __attribute__((section(".rodata.field_specials_mystery_gift_assert_data")))

#define ELEVATOR_WINDOW_WIDTH  3
#define ELEVATOR_WINDOW_HEIGHT 3
#define ELEVATOR_LIGHT_STAGES  3

void Special_ShowDiploma(void)
{
    SetMainCallback2(CB2_ShowDiploma);
    LockPlayerFieldControls();
}

void Special_ViewWallClock(void)
{
    gMain.savedCallback = CB2_ReturnToField;
    SetMainCallback2(CB2_ViewWallClock);
    LockPlayerFieldControls();
}

void ResetCyclingRoadChallengeData(void)
{
    gBikeCyclingChallenge = FALSE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = 0;
}

void Special_BeginCyclingRoadChallenge(void)
{
    gBikeCyclingChallenge = TRUE;
    gBikeCollisions = 0;
    sBikeCyclingTimer = gMain.vblankCounter1;
}

u16 GetPlayerAvatarBike(void)
{
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        return 1;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        return 2;
    return 0;
}

void DetermineCyclingRoadResults(u32 numFrames, u16 bikeCollisions)
{
    u8 numBikeCollisions = bikeCollisions;
    u8 result;

    if (numBikeCollisions < 100)
    {
        ConvertIntToDecimalStringN(gStringVar1, numBikeCollisions, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gStringVar1, gUnknown_85CB025);
    }
    else
    {
        StringCopy(gStringVar1, gUnknown_85CB00E);
    }

    if (numFrames < 3600)
    {
        ConvertIntToDecimalStringN(gStringVar2, numFrames / 60, STR_CONV_MODE_RIGHT_ALIGN, 2);
        gStringVar2[2] = CHAR_COMMA;
        ConvertIntToDecimalStringN(&gStringVar2[3], ((numFrames % 60) * 100) / 60, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringAppend(gStringVar2, gUnknown_85CB021);
    }
    else
    {
        StringCopy(gStringVar2, gUnknown_85CB018);
    }

    result = 0;
    if (numBikeCollisions == 0)
        result = 5;
    else if (numBikeCollisions < 4)
        result = 4;
    else if (numBikeCollisions < 10)
        result = 3;
    else if (numBikeCollisions < 20)
        result = 2;
    else if (numBikeCollisions < 100)
        result = 1;

    if (numFrames / 60 <= 10)
        result += 5;
    else if (numFrames / 60 <= 15)
        result += 4;
    else if (numFrames / 60 <= 20)
        result += 3;
    else if (numFrames / 60 <= 40)
        result += 2;
    else if (numFrames / 60 < 60)
        result += 1;

    gSpecialVar_Result = result;
}

void FinishCyclingRoadChallenge(void)
{
    const u32 numFrames = gMain.vblankCounter1 - sBikeCyclingTimer;

    DetermineCyclingRoadResults(numFrames, gBikeCollisions);
    RecordCyclingRoadResults(numFrames, gBikeCollisions);
}

void RecordCyclingRoadResults(u32 numFrames, u16 bikeCollisions)
{
    u8 numBikeCollisions = bikeCollisions;
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord > numFrames || framesRecord == 0)
    {
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_L, numFrames);
        VarSet(VAR_CYCLING_ROAD_RECORD_TIME_H, numFrames >> 16);
        VarSet(VAR_CYCLING_ROAD_RECORD_COLLISIONS, numBikeCollisions);
    }
}

u16 GetRecordedCyclingRoadResults(void)
{
    u16 low = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_L);
    u16 high = VarGet(VAR_CYCLING_ROAD_RECORD_TIME_H);
    u32 framesRecord = low + (high << 16);

    if (framesRecord == 0)
        return FALSE;

    DetermineCyclingRoadResults(framesRecord, (u8)VarGet(VAR_CYCLING_ROAD_RECORD_COLLISIONS));
    return TRUE;
}

void UpdateCyclingRoadState(void)
{
    if (gLastUsedWarp.mapNum == MAP_NUM(MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE) && gLastUsedWarp.mapGroup == MAP_GROUP(MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE))
        return;

    if (VarGet(VAR_CYCLING_CHALLENGE_STATE) == 2 || VarGet(VAR_CYCLING_CHALLENGE_STATE) == 3)
    {
        VarSet(VAR_CYCLING_CHALLENGE_STATE, 0);
        Overworld_SetSavedMusic(MUS_DUMMY);
    }
}

void SetSSTidalFlag(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    *GetVarPointer(VAR_CRUISE_STEP_COUNT) = 0;
}

void ResetSSTidalFlag(void)
{
    FlagClear(FLAG_SYS_CRUISE_MODE);
}

bool32 CountSSTidalStep(u16 delta)
{
    if (!FlagGet(FLAG_SYS_CRUISE_MODE) || (*GetVarPointer(VAR_CRUISE_STEP_COUNT) += delta) < SS_TIDAL_MAX_STEPS)
        return FALSE;

    return TRUE;
}

u8 GetSSTidalLocation(s8 *mapGroup, s8 *mapNum, s16 *x, s16 *y)
{
    u16 *varCruiseStepCount = GetVarPointer(VAR_CRUISE_STEP_COUNT);
    switch (*GetVarPointer(VAR_SS_TIDAL_STATE))
    {
    case SS_TIDAL_BOARD_SLATEPORT:
    case SS_TIDAL_LAND_SLATEPORT:
        return SS_TIDAL_LOCATION_SLATEPORT;
    case SS_TIDAL_HALFWAY_LILYCOVE:
    case SS_TIDAL_EXIT_CURRENTS_RIGHT:
        return SS_TIDAL_LOCATION_ROUTE131;
    case SS_TIDAL_LAND_LILYCOVE:
    case SS_TIDAL_BOARD_LILYCOVE:
        return SS_TIDAL_LOCATION_LILYCOVE;
    case SS_TIDAL_DEPART_LILYCOVE:
    case SS_TIDAL_EXIT_CURRENTS_LEFT:
        return SS_TIDAL_LOCATION_ROUTE124;
    case SS_TIDAL_DEPART_SLATEPORT:
        if (*varCruiseStepCount < 60)
        {
            *mapNum = MAP_NUM(MAP_ROUTE134);
            *x = *varCruiseStepCount + 19;
        }
        else if (*varCruiseStepCount < 140)
        {
            *mapNum = MAP_NUM(MAP_ROUTE133);
            *x = *varCruiseStepCount - 60;
        }
        else
        {
            *mapNum = MAP_NUM(MAP_ROUTE132);
            *x = *varCruiseStepCount - 140;
        }
        break;
    case SS_TIDAL_HALFWAY_SLATEPORT:
        if (*varCruiseStepCount < 66)
        {
            *mapNum = MAP_NUM(MAP_ROUTE132);
            *x = 65 - *varCruiseStepCount;
        }
        else if (*varCruiseStepCount < 146)
        {
            *mapNum = MAP_NUM(MAP_ROUTE133);
            *x = 145 - *varCruiseStepCount;
        }
        else
        {
            *mapNum = MAP_NUM(MAP_ROUTE134);
            *x = 224 - *varCruiseStepCount;
        }
        break;
    }
    *mapGroup = MAP_GROUP(MAP_ROUTE132);
    *y = 20;
    return SS_TIDAL_LOCATION_CURRENTS;
}

bool32 ShouldDoWallyCall(void)
{
    if (FlagGet(FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_WALLY_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoWinonaCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_FORTREE_GYM))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_SCOTT_FORTREE_CALL_STEP_COUNTER)) < 10)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoScottCall(void)
{
    if (FlagGet(FLAG_SCOTT_CALL_BATTLE_FRONTIER))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_SCOTT_BF_CALL_STEP_COUNTER)) < 10)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRoxanneCall(void)
{
    if (FlagGet(FLAG_ENABLE_ROXANNE_FIRST_CALL))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_ROXANNE_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

bool32 ShouldDoRivalRayquazaCall(void)
{
    if (FlagGet(FLAG_DEFEATED_MAGMA_SPACE_CENTER))
    {
        switch (gMapHeader.mapType)
        {
        case MAP_TYPE_TOWN:
        case MAP_TYPE_CITY:
        case MAP_TYPE_ROUTE:
        case MAP_TYPE_OCEAN_ROUTE:
            if (++(*GetVarPointer(VAR_RIVAL_RAYQUAZA_CALL_STEP_COUNTER)) < 250)
                return FALSE;
            break;
        default:
            return FALSE;
        }
    }
    else
    {
        return FALSE;
    }

    return TRUE;
}

__attribute__((naked)) void GetLinkPartnerNames(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	movs r6, #0\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	bl GetLinkPlayerCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	cmp r4, r5\n\t"
        "	bhs _081382FA\n\t"
        "	ldr r0, _08138308\n\t"
        "	mov r8, r0\n\t"
        "_081382D2:\n\t"
        "	cmp r7, r4\n\t"
        "	beq _081382F0\n\t"
        "	lsls r0, r6, #2\n\t"
        "	add r0, r8\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #3\n\t"
        "	subs r1, r1, r4\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _0813830C\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "_081382F0:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, r5\n\t"
        "	blo _081382D2\n\t"
        "_081382FA:\n\t"
        "	adds r0, r5, #0\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08138308: .4byte gTVStringVarPtrs\n\t"
        "_0813830C: .4byte gUnknown_20226A8\n\t"
        ".syntax divided\n\t"
    );
}

// Kept externally visible while SpawnLinkPartnerEventObject remains naked assembly.
FIELD_SPECIALS_DATA_LINK_PARTNER const u8 sLinkPartnerMovementTypes[] =
{
    MOVEMENT_TYPE_FACE_UP,
    MOVEMENT_TYPE_FACE_LEFT,
    MOVEMENT_TYPE_FACE_DOWN,
    MOVEMENT_TYPE_FACE_RIGHT,
};

FIELD_SPECIALS_DATA_LINK_PARTNER const s8 sLinkPartnerCoordOffsets[][2] =
{
    { 0,  1},
    { 1,  0},
    { 0, -1},
    {-1,  0},
};

__attribute__((naked)) void SpawnLinkPartnerEventObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	movs r7, #0\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _0813835C\n\t"
        "	add r0, sp, #8\n\t"
        "	movs r2, #4\n\t"
        "	bl memcpy\n\t"
        "	add r4, sp, #0xc\n\t"
        "	ldr r1, _08138360\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r0, #2\n\t"
        "	beq _08138380\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _08138364\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081383AC\n\t"
        "	b _081383C0\n\t"
        "	.align 2, 0\n\t"
        "_0813835C: .4byte sLinkPartnerMovementTypes\n\t"
        "_08138360: .4byte sLinkPartnerCoordOffsets\n\t"
        "_08138364:\n\t"
        "	cmp r1, #3\n\t"
        "	beq _0813836E\n\t"
        "	cmp r1, #4\n\t"
        "	beq _08138394\n\t"
        "	b _081383C0\n\t"
        "_0813836E:\n\t"
        "	movs r7, #2\n\t"
        "	ldr r0, _0813837C\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	subs r0, #1\n\t"
        "	b _0813839C\n\t"
        "	.align 2, 0\n\t"
        "_0813837C: .4byte gSaveBlock1Ptr\n\t"
        "_08138380:\n\t"
        "	movs r7, #1\n\t"
        "	ldr r0, _08138390\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0]\n\t"
        "	mov sb, r1\n\t"
        "	ldrh r0, [r0, #2]\n\t"
        "	subs r0, #1\n\t"
        "	b _081383BA\n\t"
        "	.align 2, 0\n\t"
        "_08138390: .4byte gSaveBlock1Ptr\n\t"
        "_08138394:\n\t"
        "	ldr r0, _081383A8\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "_0813839C:\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	ldrh r1, [r1, #2]\n\t"
        "	mov r8, r1\n\t"
        "	b _081383C0\n\t"
        "	.align 2, 0\n\t"
        "_081383A8: .4byte gSaveBlock1Ptr\n\t"
        "_081383AC:\n\t"
        "	movs r7, #3\n\t"
        "	ldr r0, _081383C4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r3, [r0]\n\t"
        "	mov sb, r3\n\t"
        "	ldrh r0, [r0, #2]\n\t"
        "	adds r0, #1\n\t"
        "_081383BA:\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "_081383C0:\n\t"
        "	movs r6, #0\n\t"
        "	b _08138480\n\t"
        "	.align 2, 0\n\t"
        "_081383C4: .4byte gSaveBlock1Ptr\n\t"
        "_081383C8:\n\t"
        "	cmp sl, r6\n\t"
        "	beq _0813847A\n\t"
        "	ldr r0, _081383E8\n\t"
        "	lsls r2, r6, #3\n\t"
        "	subs r1, r2, r6\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r3, [r1]\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r3, #1\n\t"
        "	blt _081383FC\n\t"
        "	cmp r3, #2\n\t"
        "	ble _081383EC\n\t"
        "	cmp r3, #3\n\t"
        "	beq _081383F8\n\t"
        "	b _081383FC\n\t"
        "	.align 2, 0\n\t"
        "_081383E8: .4byte gLinkPlayers\n\t"
        "_081383EC:\n\t"
        "	ldrb r0, [r1, #0x13]\n\t"
        "	movs r5, #0xec\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813840C\n\t"
        "	movs r5, #0xeb\n\t"
        "	b _0813840C\n\t"
        "_081383F8:\n\t"
        "	ldrb r0, [r1, #0x13]\n\t"
        "	b _08138404\n\t"
        "_081383FC:\n\t"
        "	subs r0, r2, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0, #0x13]\n\t"
        "_08138404:\n\t"
        "	movs r5, #0x69\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813840C\n\t"
        "	movs r5, #0x64\n\t"
        "_0813840C:\n\t"
        "	mov r0, sp\n\t"
        "	adds r0, r0, r7\n\t"
        "	adds r0, #8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r4, #0xf0\n\t"
        "	subs r4, r4, r6\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r2, r7, #1\n\t"
        "	mov r0, sp\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0xc\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	mov r3, sb\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	mov ip, r3\n\t"
        "	add r0, ip\n\t"
        "	adds r3, r0, #7\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	mov ip, r3\n\t"
        "	mov r0, sp\n\t"
        "	adds r0, #0xd\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r2, #0\n\t"
        "	ldrsb r2, [r0, r2]\n\t"
        "	mov r3, r8\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	mov r3, ip\n\t"
        "	bl SpawnSpecialObjectEventParameterized\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl LoadLinkPartnerEventObjectSpritePalette\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #4\n\t"
        "	bne _0813847A\n\t"
        "	movs r7, #0\n\t"
        "_0813847A:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "_08138480:\n\t"
        "	ldr r0, _08138498\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r6, r0\n\t"
        "	blo _081383C8\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08138498: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LoadLinkPartnerEventObjectSpritePalette(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r3, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsrs r5, r2, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r2, #0xa8\n\t"
        "	lsls r2, r2, #0x15\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bls _081384C4\n\t"
        "	cmp r4, #0x64\n\t"
        "	beq _081384C4\n\t"
        "	cmp r4, #0x69\n\t"
        "	bne _08138556\n\t"
        "_081384C4:\n\t"
        "	ldr r0, _0813850C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl GetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x10\n\t"
        "	beq _08138556\n\t"
        "	ldr r1, _08138510\n\t"
        "	lsls r0, r2, #3\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _08138514\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r3, r5, #4\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r3\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	cmp r4, #0x69\n\t"
        "	beq _08138548\n\t"
        "	cmp r4, #0x69\n\t"
        "	bgt _08138518\n\t"
        "	cmp r4, #0x64\n\t"
        "	beq _08138534\n\t"
        "	b _08138556\n\t"
        "	.align 2, 0\n\t"
        "_0813850C: .4byte gSaveBlock1Ptr\n\t"
        "_08138510: .4byte gObjectEvents\n\t"
        "_08138514: .4byte gSprites\n\t"
        "_08138518:\n\t"
        "	cmp r4, #0xeb\n\t"
        "	beq _08138522\n\t"
        "	cmp r4, #0xec\n\t"
        "	beq _0813852C\n\t"
        "	b _08138556\n\t"
        "_08138522:\n\t"
        "	ldr r0, _08138528\n\t"
        "	b _08138536\n\t"
        "	.align 2, 0\n\t"
        "_08138528: .4byte gUnknown_8471E6C\n\t"
        "_0813852C:\n\t"
        "	ldr r0, _08138530\n\t"
        "	b _08138536\n\t"
        "	.align 2, 0\n\t"
        "_08138530: .4byte gUnknown_847D90C\n\t"
        "_08138534:\n\t"
        "	ldr r0, _08138544\n\t"
        "_08138536:\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r2, #0x20\n\t"
        "	bl LoadPalette\n\t"
        "	b _08138556\n\t"
        "	.align 2, 0\n\t"
        "_08138544: .4byte gUnknown_8470C4C\n\t"
        "_08138548:\n\t"
        "	ldr r0, _0813855C\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r2, #0x20\n\t"
        "	bl LoadPalette\n\t"
        "_08138556:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813855C: .4byte gUnknown_847C6CC\n\t"
        ".syntax divided\n\t"
    );
}

// Kept externally visible while the two Mauville Gym routines remain naked assembly.
FIELD_SPECIALS_DATA_MAUVILLE_GYM const struct UCoords8 sMauvilleGymSwitchCoords[] =
{
    { 0 + MAP_OFFSET, 15 + MAP_OFFSET},
    { 4 + MAP_OFFSET, 12 + MAP_OFFSET},
    { 3 + MAP_OFFSET,  9 + MAP_OFFSET},
    { 8 + MAP_OFFSET,  9 + MAP_OFFSET},
};

__attribute__((naked)) void MauvilleGymPressSwitch(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r4, #0\n\t"
        "	ldr r5, _08138580\n\t"
        "_08138566:\n\t"
        "	ldr r0, _08138584\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	bne _0813858C\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldrb r1, [r1, #1]\n\t"
        "	ldr r2, _08138588\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	b _0813859A\n\t"
        "	.align 2, 0\n\t"
        "_08138580: .4byte sMauvilleGymSwitchCoords\n\t"
        "_08138584: .4byte gSpecialVar_0x8004\n\t"
        "_08138588: .4byte SPECIAL_IsLastMonThatKnowsSurf\n\t"
        "_0813858C:\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldrb r1, [r1, #1]\n\t"
        "	ldr r2, _081385AC\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "_0813859A:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _08138566\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081385AC: .4byte SPECIAL_ResetHealLocationFromDewford\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MauvilleGymSetDefaultBarriers(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	movs r5, #0xc\n\t"
        "_081385B4:\n\t"
        "	movs r4, #7\n\t"
        "	adds r6, r5, #1\n\t"
        "_081385B8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridGetMetatileIdAt\n\t"
        "	ldr r1, _081385D4\n\t"
        "	adds r0, r0, r1\n\t"
        "	cmp r0, #0x37\n\t"
        "	bls _081385CA\n\t"
        "	b _081387A4\n\t"
        "_081385CA:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081385D8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081385D4: .4byte 0xFFFFFDE6\n\t"
        "_081385D8: .4byte _081385DC\n\t"
        "_081385DC:\n\t"
        "	.4byte _08138762\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081386BC\n\t"
        "	.4byte _081386C2\n\t"
        "	.4byte _081386FC\n\t"
        "	.4byte _08138704\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081386CC\n\t"
        "	.4byte _081386D2\n\t"
        "	.4byte _0813870C\n\t"
        "	.4byte _08138714\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081386DC\n\t"
        "	.4byte _081386E2\n\t"
        "	.4byte _0813871C\n\t"
        "	.4byte _08138724\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081386EC\n\t"
        "	.4byte _081386F4\n\t"
        "	.4byte _0813872C\n\t"
        "	.4byte _08138734\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _0813873C\n\t"
        "	.4byte _0813874C\n\t"
        "	.4byte _0813875C\n\t"
        "	.4byte _08138784\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _08138744\n\t"
        "	.4byte _08138754\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _081387A4\n\t"
        "	.4byte _0813879A\n\t"
        "	.4byte _0813878C\n\t"
        "_081386BC:\n\t"
        "	movs r2, #0x8c\n\t"
        "	lsls r2, r2, #2\n\t"
        "	b _08138790\n\t"
        "_081386C2:\n\t"
        "	ldr r2, _081386C8\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_081386C8: .4byte 0x00000231\n\t"
        "_081386CC:\n\t"
        "	movs r2, #0x8e\n\t"
        "	lsls r2, r2, #2\n\t"
        "	b _08138790\n\t"
        "_081386D2:\n\t"
        "	ldr r2, _081386D8\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_081386D8: .4byte 0x00000239\n\t"
        "_081386DC:\n\t"
        "	movs r2, #0x88\n\t"
        "	lsls r2, r2, #2\n\t"
        "	b _08138790\n\t"
        "_081386E2:\n\t"
        "	ldr r2, _081386E8\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_081386E8: .4byte 0x00000221\n\t"
        "_081386EC:\n\t"
        "	ldr r2, _081386F0\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_081386F0: .4byte 0x00000E28\n\t"
        "_081386F4:\n\t"
        "	ldr r2, _081386F8\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_081386F8: .4byte 0x00000E29\n\t"
        "_081386FC:\n\t"
        "	ldr r2, _08138700\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138700: .4byte 0x00000232\n\t"
        "_08138704:\n\t"
        "	ldr r2, _08138708\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138708: .4byte 0x00000233\n\t"
        "_0813870C:\n\t"
        "	ldr r2, _08138710\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138710: .4byte 0x0000023A\n\t"
        "_08138714:\n\t"
        "	ldr r2, _08138718\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138718: .4byte 0x0000023B\n\t"
        "_0813871C:\n\t"
        "	ldr r2, _08138720\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138720: .4byte 0x00000222\n\t"
        "_08138724:\n\t"
        "	ldr r2, _08138728\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138728: .4byte 0x00000223\n\t"
        "_0813872C:\n\t"
        "	ldr r2, _08138730\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138730: .4byte 0x00000E2A\n\t"
        "_08138734:\n\t"
        "	ldr r2, _08138738\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138738: .4byte 0x00000E2B\n\t"
        "_0813873C:\n\t"
        "	ldr r2, _08138740\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138740: .4byte 0x00000E42\n\t"
        "_08138744:\n\t"
        "	ldr r2, _08138748\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138748: .4byte 0x0000021A\n\t"
        "_0813874C:\n\t"
        "	ldr r2, _08138750\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138750: .4byte 0x00000E43\n\t"
        "_08138754:\n\t"
        "	ldr r2, _08138758\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138758: .4byte 0x0000021A\n\t"
        "_0813875C:\n\t"
        "	movs r2, #0xe4\n\t"
        "	lsls r2, r2, #4\n\t"
        "	b _08138790\n\t"
        "_08138762:\n\t"
        "	subs r1, r5, #1\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl MapGridGetMetatileIdAt\n\t"
        "	movs r1, #0x90\n\t"
        "	lsls r1, r1, #2\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0813877C\n\t"
        "	ldr r2, _08138778\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138778: .4byte 0x00000E48\n\t"
        "_0813877C:\n\t"
        "	ldr r2, _08138780\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138780: .4byte 0x00000E49\n\t"
        "_08138784:\n\t"
        "	ldr r2, _08138788\n\t"
        "	b _08138790\n\t"
        "	.align 2, 0\n\t"
        "_08138788: .4byte 0x00000E41\n\t"
        "_0813878C:\n\t"
        "	movs r2, #0xe5\n\t"
        "	lsls r2, r2, #4\n\t"
        "_08138790:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	b _081387A4\n\t"
        "_0813879A:\n\t"
        "	ldr r2, _081387BC\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "_081387A4:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #0xf\n\t"
        "	bgt _081387AC\n\t"
        "	b _081385B8\n\t"
        "_081387AC:\n\t"
        "	adds r5, r6, #0\n\t"
        "	cmp r5, #0x17\n\t"
        "	bgt _081387B4\n\t"
        "	b _081385B4\n\t"
        "_081387B4:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081387BC: .4byte 0x00000251\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MauvilleGymDeactivatePuzzle(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r4, _081387FC\n\t"
        "	movs r5, #3\n\t"
        "_081387C6:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	ldr r2, _08138800\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	adds r4, #4\n\t"
        "	subs r5, #1\n\t"
        "	cmp r5, #0\n\t"
        "	bge _081387C6\n\t"
        "	movs r5, #0xc\n\t"
        "_081387DA:\n\t"
        "	movs r4, #7\n\t"
        "	adds r6, r5, #1\n\t"
        "_081387DE:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridGetMetatileIdAt\n\t"
        "	ldr r1, _08138804\n\t"
        "	adds r0, r0, r1\n\t"
        "	cmp r0, #0x30\n\t"
        "	bls _081387F0\n\t"
        "	b _0813893A\n\t"
        "_081387F0:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08138808\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081387FC: .4byte sMauvilleGymSwitchCoords\n\t"
        "_08138800: .4byte SPECIAL_IsLastMonThatKnowsSurf\n\t"
        "_08138804: .4byte 0xFFFFFDE0\n\t"
        "_08138808: .4byte _0813880C\n\t"
        "_0813880C:\n\t"
        "	.4byte _081388D0\n\t"
        "	.4byte _081388D6\n\t"
        "	.4byte _081388F0\n\t"
        "	.4byte _081388F8\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _081388E0\n\t"
        "	.4byte _081388E6\n\t"
        "	.4byte _08138900\n\t"
        "	.4byte _08138908\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _08138910\n\t"
        "	.4byte _08138918\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _08138920\n\t"
        "	.4byte _08138920\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _0813893A\n\t"
        "	.4byte _08138930\n\t"
        "_081388D0:\n\t"
        "	movs r2, #0x8c\n\t"
        "	lsls r2, r2, #2\n\t"
        "	b _08138922\n\t"
        "_081388D6:\n\t"
        "	ldr r2, _081388DC\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_081388DC: .4byte 0x00000231\n\t"
        "_081388E0:\n\t"
        "	movs r2, #0x8e\n\t"
        "	lsls r2, r2, #2\n\t"
        "	b _08138922\n\t"
        "_081388E6:\n\t"
        "	ldr r2, _081388EC\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_081388EC: .4byte 0x00000239\n\t"
        "_081388F0:\n\t"
        "	ldr r2, _081388F4\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_081388F4: .4byte 0x00000232\n\t"
        "_081388F8:\n\t"
        "	ldr r2, _081388FC\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_081388FC: .4byte 0x00000233\n\t"
        "_08138900:\n\t"
        "	ldr r2, _08138904\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_08138904: .4byte 0x0000023A\n\t"
        "_08138908:\n\t"
        "	ldr r2, _0813890C\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_0813890C: .4byte 0x0000023B\n\t"
        "_08138910:\n\t"
        "	ldr r2, _08138914\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_08138914: .4byte 0x00000E42\n\t"
        "_08138918:\n\t"
        "	ldr r2, _0813891C\n\t"
        "	b _08138922\n\t"
        "	.align 2, 0\n\t"
        "_0813891C: .4byte 0x00000E43\n\t"
        "_08138920:\n\t"
        "	ldr r2, _0813892C\n\t"
        "_08138922:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	b _0813893A\n\t"
        "	.align 2, 0\n\t"
        "_0813892C: .4byte 0x0000021A\n\t"
        "_08138930:\n\t"
        "	ldr r2, _08138950\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "_0813893A:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #0xf\n\t"
        "	bgt _08138942\n\t"
        "	b _081387DE\n\t"
        "_08138942:\n\t"
        "	adds r5, r6, #0\n\t"
        "	cmp r5, #0x17\n\t"
        "	bgt _0813894A\n\t"
        "	b _081387DA\n\t"
        "_0813894A:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08138950: .4byte 0x00000251\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PetalburgGymSlideOpenRoomDoors(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _08138974\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08138978\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0x2c\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _0813897C\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08138974: .4byte gUnknown_203A828\n\t"
        "_08138978: .4byte gUnknown_203A829\n\t"
        "_0813897C: .4byte Task_PetalburgGym + 1\n\t"
        ".syntax divided\n\t"
    );
}

// Kept externally visible while the Petalburg Gym door routines remain naked assembly.
FIELD_SPECIALS_DATA_PETALBURG_GYM const bool8 sSlidingDoorNextFrameDelay[] = {0, 1, 1, 1, 1};

FIELD_SPECIALS_DATA_PETALBURG_GYM const u16 sPetalburgGymSlidingDoorMetatiles[] =
{
    METATILE_PetalburgGym_SlidingDoor_Frame0,
    METATILE_PetalburgGym_SlidingDoor_Frame1,
    METATILE_PetalburgGym_SlidingDoor_Frame2,
    METATILE_PetalburgGym_SlidingDoor_Frame3,
    METATILE_PetalburgGym_SlidingDoor_Frame4,
};

__attribute__((naked)) void Task_PetalburgGym(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, _081389C8\n\t"
        "	ldr r5, _081389CC\n\t"
        "	ldrb r1, [r5]\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r4, _081389D0\n\t"
        "	ldrb r2, [r4]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _081389DC\n\t"
        "	ldr r0, _081389D4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r2, _081389D8\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r1, [r1]\n\t"
        "	bl PetalburgGymFunc\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r5]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #5\n\t"
        "	bne _081389E0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	b _081389E0\n\t"
        "	.align 2, 0\n\t"
        "_081389C8: .4byte sSlidingDoorNextFrameDelay\n\t"
        "_081389CC: .4byte gUnknown_203A829\n\t"
        "_081389D0: .4byte gUnknown_203A828\n\t"
        "_081389D4: .4byte gSpecialVar_0x8004\n\t"
        "_081389D8: .4byte sPetalburgGymSlidingDoorMetatiles\n\t"
        "_081389DC:\n\t"
        "	adds r0, r2, #1\n\t"
        "	strb r0, [r4]\n\t"
        "_081389E0:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PetalburgGymFunc(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r2, r1, #0x10\n\t"
        "	movs r7, #0\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, #7\n\t"
        "	bhi _08138AB0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08138A0C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08138A0C: .4byte _08138A10\n\t"
        "_08138A10:\n\t"
        "	.4byte _08138A30\n\t"
        "	.4byte _08138A42\n\t"
        "	.4byte _08138A54\n\t"
        "	.4byte _08138A66\n\t"
        "	.4byte _08138A74\n\t"
        "	.4byte _08138A8A\n\t"
        "	.4byte _08138A96\n\t"
        "	.4byte _08138AA4\n\t"
        "_08138A30:\n\t"
        "	movs r7, #2\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x68\n\t"
        "	b _08138A84\n\t"
        "_08138A42:\n\t"
        "	movs r7, #2\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x4e\n\t"
        "	b _08138A84\n\t"
        "_08138A54:\n\t"
        "	movs r7, #2\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x5b\n\t"
        "	b _08138A84\n\t"
        "_08138A66:\n\t"
        "	movs r7, #1\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x27\n\t"
        "	b _08138AAE\n\t"
        "_08138A74:\n\t"
        "	movs r7, #2\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x34\n\t"
        "_08138A84:\n\t"
        "	strh r0, [r1]\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	b _08138AB0\n\t"
        "_08138A8A:\n\t"
        "	movs r7, #1\n\t"
        "	mov r0, sp\n\t"
        "	strh r7, [r0]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x41\n\t"
        "	b _08138AAE\n\t"
        "_08138A96:\n\t"
        "	movs r7, #1\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0xd\n\t"
        "	b _08138AAE\n\t"
        "_08138AA4:\n\t"
        "	movs r7, #1\n\t"
        "	mov r0, sp\n\t"
        "	strh r7, [r0]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0x1a\n\t"
        "_08138AAE:\n\t"
        "	strh r0, [r1]\n\t"
        "_08138AB0:\n\t"
        "	movs r6, #0\n\t"
        "	cmp r6, r7\n\t"
        "	bhs _08138B02\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	mov sb, r1\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	mov r8, r1\n\t"
        "_08138ACE:\n\t"
        "	lsls r1, r6, #1\n\t"
        "	mov r3, sp\n\t"
        "	adds r5, r3, r1\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #7\n\t"
        "	add r4, sp, #8\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrh r1, [r4]\n\t"
        "	adds r1, #7\n\t"
        "	mov r3, sb\n\t"
        "	lsrs r2, r3, #0x10\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #7\n\t"
        "	ldrh r1, [r4]\n\t"
        "	adds r1, #8\n\t"
        "	mov r3, r8\n\t"
        "	lsrs r2, r3, #0x10\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, r7\n\t"
        "	blo _08138ACE\n\t"
        "_08138B02:\n\t"
        "	bl DrawWholeMapView\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PetalburgGymUnlockRoomDoors(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _08138B28\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _08138B2C\n\t"
        "	ldrh r1, [r1, #8]\n\t"
        "	bl PetalburgGymFunc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08138B28: .4byte gSpecialVar_0x8004\n\t"
        "_08138B2C: .4byte sPetalburgGymSlidingDoorMetatiles\n\t"
        ".syntax divided\n\t"
    );
}

void ShowFieldMessageStringVar4(void)
{
    ShowFieldMessage(gStringVar4);
}

void StorePlayerCoordsInVars(void)
{
    gSpecialVar_0x8004 = gSaveBlock1Ptr->pos.x;
    gSpecialVar_0x8005 = gSaveBlock1Ptr->pos.y;
}

u8 GetPlayerTrainerIdOnesDigit(void)
{
    return (u16)((gSaveBlock2Ptr->playerTrainerId[1] << 8) | gSaveBlock2Ptr->playerTrainerId[0]) % 10;
}

void GetPlayerBigGuyGirlString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        StringCopy(gStringVar1, gText_BigGuy);
    else
        StringCopy(gStringVar1, gText_BigGirl);
}

void GetRivalSonDaughterString(void)
{
    if (gSaveBlock2Ptr->playerGender == MALE)
        StringCopy(gStringVar1, gText_Daughter);
    else
        StringCopy(gStringVar1, gText_Son);
}

u8 GetBattleOutcome(void)
{
    return gBattleOutcome;
}

void CableCarWarp(void)
{
    if (gSpecialVar_0x8004 != 0)
        SetWarpDestination(MAP_GROUP(MAP_ROUTE112_CABLE_CAR_STATION), MAP_NUM(MAP_ROUTE112_CABLE_CAR_STATION), WARP_ID_NONE, 6, 4);
    else
        SetWarpDestination(MAP_GROUP(MAP_MT_CHIMNEY_CABLE_CAR_STATION), MAP_NUM(MAP_MT_CHIMNEY_CABLE_CAR_STATION), WARP_ID_NONE, 6, 4);
}

void SetHiddenItemFlag(void)
{
    FlagSet(gSpecialVar_0x8004);
}

u16 GetWeekCount(void)
{
    u16 weekCount = gLocalTime.days / 7;
    if (weekCount > 9999)
        weekCount = 9999;

    return weekCount;
}

u8 GetLeadMonFriendshipScore(void)
{
    struct Pokemon *pokemon = &gPlayerParty[GetLeadMonIndex()];
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) == MAX_FRIENDSHIP)
        return FRIENDSHIP_MAX;
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) >= 200)
        return FRIENDSHIP_200_TO_254;
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) >= 150)
        return FRIENDSHIP_150_TO_199;
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) >= 100)
        return FRIENDSHIP_100_TO_149;
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) >= 50)
        return FRIENDSHIP_50_TO_99;
    if (GetMonData3(pokemon, MON_DATA_FRIENDSHIP) >= 1)
        return FRIENDSHIP_1_TO_49;

    return FRIENDSHIP_NONE;
}

void CB2_FieldShowRegionMap(void)
{
    FieldInitRegionMap(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void FieldShowRegionMap(void)
{
    SetMainCallback2(CB2_FieldShowRegionMap);
}

void DoPCTurnOnEffect(void)
{
    if (FuncIsActiveTask(Task_PCTurnOnEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_PCTurnOnEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

void Task_PCTurnOnEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        PCTurnOnEffect(task);
}

void PCTurnOnEffect(struct Task *task)
{
    u8 playerDirection;
    s8 dx = 0;
    s8 dy = 0;
    if (task->tTimer == 6)
    {
        task->tTimer = 0;

        // Get where the PC should be, depending on where the player is looking.
        playerDirection = GetPlayerFacingDirection();
        switch (playerDirection)
        {
        case DIR_NORTH:
            dx = 0;
            dy = -1;
            break;
        case DIR_WEST:
            dx = -1;
            dy = -1;
            break;
        case DIR_EAST:
            dx = 1;
            dy = -1;
            break;
        }

        // Update map
        PCTurnOnEffect_SetMetatile(task->tIsScreenOn, dx, dy);
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

void PCTurnOnEffect_SetMetatile(s16 isScreenOn, s8 dx, s8 dy)
{
    u16 metatileId = 0;
    if (isScreenOn)
    {
        // Screen is on, set it off
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = METATILE_Building_PC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_Off;
    }
    else
    {
        // Screen is off, set it on
        if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
            metatileId = METATILE_Building_PC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_BrendanPC_On;
        else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
            metatileId = METATILE_BrendansMaysHouse_MayPC_On;
    }
    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + MAP_OFFSET, gSaveBlock1Ptr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
}

void DoPCTurnOffEffect(void)
{
    PCTurnOffEffect();
}


void PCTurnOffEffect(void)
{
    s8 dx = 0;
    s8 dy = 0;
    u16 metatileId = 0;

    // Get where the PC should be, depending on where the player is looking.
    u8 playerDirection = GetPlayerFacingDirection();
    switch (playerDirection)
    {
    case DIR_NORTH:
        dx = 0;
        dy = -1;
        break;
    case DIR_WEST:
        dx = -1;
        dy = -1;
        break;
    case DIR_EAST:
        dx = 1;
        dy = -1;
        break;
    }

    if (gSpecialVar_0x8004 == PC_LOCATION_OTHER)
        metatileId = METATILE_Building_PC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_BRENDANS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_BrendanPC_Off;
    else if (gSpecialVar_0x8004 == PC_LOCATION_MAYS_HOUSE)
        metatileId = METATILE_BrendansMaysHouse_MayPC_Off;

    MapGridSetMetatileIdAt(gSaveBlock1Ptr->pos.x + dx + MAP_OFFSET, gSaveBlock1Ptr->pos.y + dy + MAP_OFFSET, metatileId | MAPGRID_IMPASSABLE);
    DrawWholeMapView();
}

void DoLotteryCornerComputerEffect(void)
{
    if (FuncIsActiveTask(Task_LotteryCornerComputerEffect) != TRUE)
    {
        u8 taskId = CreateTask(Task_LotteryCornerComputerEffect, 8);
        gTasks[taskId].tPaused = FALSE;
        gTasks[taskId].tTaskId = taskId;
        gTasks[taskId].tFlickerCount = 0;
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tIsScreenOn = FALSE;
    }
}

void Task_LotteryCornerComputerEffect(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->tPaused)
        LotteryCornerComputerEffect(task);
}

void LotteryCornerComputerEffect(struct Task *task)
{
    if (task->tTimer == 6)
    {
        task->tTimer = 0;
        if (task->tIsScreenOn)
        {
            // Screen is on, set it off
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_IMPASSABLE);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_IMPASSABLE);
        }
        else
        {
            // Screen is off, set it on
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Flash | MAPGRID_IMPASSABLE);
            MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Flash | MAPGRID_IMPASSABLE);
        }
        DrawWholeMapView();

        // Screen flickers 5 times. Odd number and starting with the
        // screen off means the animation ends with the screen on.
        task->tIsScreenOn ^= 1;
        if (++task->tFlickerCount == 5)
            DestroyTask(task->tTaskId);
    }
    task->tTimer++;
}

void EndLotteryCornerComputerEffect(void)
{
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 1 + MAP_OFFSET, METATILE_Shop_Laptop1_Normal | MAPGRID_IMPASSABLE);
    MapGridSetMetatileIdAt(11 + MAP_OFFSET, 2 + MAP_OFFSET, METATILE_Shop_Laptop2_Normal | MAPGRID_IMPASSABLE);
    DrawWholeMapView();
}

void SetTrickHouseNuggetFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    *specVar = flag;
    FlagSet(flag);
}

void ResetTrickHouseNuggetFlag(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET;
    *specVar = flag;
    FlagClear(flag);
}

bool8 CheckLeadMonCool(void)
{
    if (GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_COOL) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonBeauty(void)
{
    if (GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_BEAUTY) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonCute(void)
{
    if (GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_CUTE) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonSmart(void)
{
    if (GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_SMART) < 200)
        return FALSE;

    return TRUE;
}

bool8 CheckLeadMonTough(void)
{
    if (GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_TOUGH) < 200)
        return FALSE;

    return TRUE;
}

void IsGrassTypeInParty(void)
{
    u8 i;
    u16 species;
    struct Pokemon *pokemon;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData3(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData3(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData3(pokemon, MON_DATA_SPECIES);
            if (gSpeciesInfo[species].types[0] == TYPE_GRASS || gSpeciesInfo[species].types[1] == TYPE_GRASS)
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }
    gSpecialVar_Result = FALSE;
}

__attribute__((naked)) void SpawnCameraObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _08139214\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r3, [r0]\n\t"
        "	adds r3, #7\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	ldrh r0, [r0, #2]\n\t"
        "	adds r0, #7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #7\n\t"
        "	movs r1, #8\n\t"
        "	movs r2, #0x7f\n\t"
        "	bl SpawnSpecialObjectEventParameterized\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _08139218\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	movs r2, #0x20\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	bl CameraObjectSetFollowedSpriteId\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139214: .4byte gSaveBlock1Ptr\n\t"
        "_08139218: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

void RemoveCameraObject(void)
{
    CameraObjectSetFollowedSpriteId(GetPlayerAvatarSpriteId());
    RemoveObjectEventByLocalIdAndMap(LOCALID_CAMERA, (u8)gSaveBlock1Ptr->location.mapNum, (u8)gSaveBlock1Ptr->location.mapGroup);
}

u8 GetPokeblockNameByMonNature(void)
{
    return sub_081370D8(GetNature(&gPlayerParty[GetLeadMonIndex()]), gStringVar1);
}

void GetSecretBaseNearbyMapName(void)
{
    GetMapName(gStringVar1, VarGet(VAR_SECRET_BASE_MAP), 0);
}

u16 GetBattleTowerSinglesStreak(void)
{
    return GetGameStat(GAME_STAT_BATTLE_TOWER_SINGLES_STREAK);
}

void BufferEReaderTrainerName(void)
{
    GetEreaderTrainerName(gStringVar1);
}

// Kept externally visible while GetSlotMachineId remains naked assembly.
FIELD_SPECIALS_DATA_SLOT_MACHINE_SELECTORS const u8 sSlotMachineRandomSeeds[] =
{
    12, 2, 4, 5, 1, 8, 7, 11, 3, 10, 9, 6,
};

FIELD_SPECIALS_DATA_SLOT_MACHINE_SELECTORS const u8 sSlotMachineIds[] =
{
    0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5,
};

FIELD_SPECIALS_DATA_SLOT_MACHINE_SELECTORS const u8 sSlotMachineServiceDayIds[] =
{
    3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5,
};

__attribute__((naked)) void GetSlotMachineId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _081392EC\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldr r1, _081392F0\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #0x19\n\t"
        "	ldr r0, _081392F4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081392F8\n\t"
        "	ldr r0, _081392FC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r5, r1, r0\n\t"
        "	movs r0, #2\n\t"
        "	bl GetPriceReduction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08139304\n\t"
        "	ldr r4, _08139300\n\t"
        "	b _08139306\n\t"
        "	.align 2, 0\n\t"
        "_081392EC: .4byte gSaveBlock1Ptr\n\t"
        "_081392F0: .4byte 0x00002E68\n\t"
        "_081392F4: .4byte 0x00002E6A\n\t"
        "_081392F8: .4byte sSlotMachineRandomSeeds\n\t"
        "_081392FC: .4byte gSpecialVar_0x8004\n\t"
        "_08139300: .4byte sSlotMachineIds\n\t"
        "_08139304:\n\t"
        "	ldr r4, _08139318\n\t"
        "_08139306:\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl __umodsi3\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08139318: .4byte sSlotMachineServiceDayIds\n\t"
        ".syntax divided\n\t"
    );
}

bool8 FoundAbandonedShipRoom1Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom2Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom4Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 FoundAbandonedShipRoom6Key(void)
{
    u16 *specVar = &gSpecialVar_0x8004;
    u16 flag = FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY;
    *specVar = flag;
    if (!FlagGet(flag))
        return FALSE;

    return TRUE;
}

bool8 LeadMonHasEffortRibbon(void)
{
    return GetMonData3(&gPlayerParty[GetLeadMonIndex()], MON_DATA_EFFORT_RIBBON, NULL);
}

void GiveLeadMonEffortRibbon(void)
{
    bool8 ribbonSet;
    struct Pokemon *leadMon;
    IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
    FlagSet(FLAG_SYS_RIBBON_GET);
    ribbonSet = TRUE;
    leadMon = &gPlayerParty[GetLeadMonIndex()];
    SetMonData(leadMon, MON_DATA_EFFORT_RIBBON, &ribbonSet);
    if (GetRibbonCount(leadMon) > NUM_CUTIES_RIBBONS)
        TryPutSpotTheCutiesOnAir(leadMon, MON_DATA_EFFORT_RIBBON);
}

bool8 Special_AreLeadMonEVsMaxedOut(void)
{
    if (GetMonEVCount(&gPlayerParty[GetLeadMonIndex()]) >= MAX_TOTAL_EVS)
        return TRUE;

    return FALSE;
}

u8 TryUpdateRusturfTunnelState(void)
{
    if (!FlagGet(FLAG_RUSTURF_TUNNEL_OPENED)
        && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_RUSTURF_TUNNEL)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_RUSTURF_TUNNEL))
    {
        if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 4);
            return TRUE;
        }
        else if (FlagGet(FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2))
        {
            VarSet(VAR_RUSTURF_TUNNEL_STATE, 5);
            return TRUE;
        }
    }
    return FALSE;
}

void SetShoalItemFlag(u16 unused)
{
    FlagSet(FLAG_SYS_SHOAL_ITEM);
}

__attribute__((naked)) void PutZigzagoonInPlayerParty(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x14\n\t"
        "	ldr r5, _08139544\n\t"
        "	movs r1, #0x90\n\t"
        "	lsls r1, r1, #1\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #7\n\t"
        "	movs r3, #0x20\n\t"
        "	bl CreateMon\n\t"
        "	movs r1, #1\n\t"
        "	add r0, sp, #0x10\n\t"
        "	strh r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x2e\n\t"
        "	add r2, sp, #0x10\n\t"
        "	bl SetMonData\n\t"
        "	add r1, sp, #0x10\n\t"
        "	movs r0, #0x21\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xd\n\t"
        "	add r2, sp, #0x10\n\t"
        "	bl SetMonData\n\t"
        "	add r0, sp, #0x10\n\t"
        "	strh r4, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xe\n\t"
        "	add r2, sp, #0x10\n\t"
        "	bl SetMonData\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xf\n\t"
        "	add r2, sp, #0x10\n\t"
        "	bl SetMonData\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x10\n\t"
        "	add r2, sp, #0x10\n\t"
        "	bl SetMonData\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139544: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

bool8 IsStarterInParty(void)
{
    u8 i;
    u16 starter = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) == starter)
            return TRUE;
    }
    return FALSE;
}

bool8 ScriptCheckFreePokemonStorageSpace(void)
{
    return CheckFreePokemonStorageSpace();
}

bool8 IsPokerusInParty(void)
{
    if (!CheckPartyPokerus(gPlayerParty, (1 << PARTY_SIZE) - 1))
        return FALSE;

    return TRUE;
}

__attribute__((naked)) void ShakeCamera(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _08139614\n\t"
        "	movs r1, #9\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _08139618\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r0, _0813961C\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	strh r2, [r1, #0xa]\n\t"
        "	ldr r0, _08139620\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	ldr r0, _08139624\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0xe]\n\t"
        "	ldr r0, _08139628\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0x10]\n\t"
        "	movs r0, #0\n\t"
        "	bl SetCameraPanningCallback\n\t"
        "	movs r0, #0xd6\n\t"
        "	bl PlaySE\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139614: .4byte sub_0813962C + 1\n\t"
        "_08139618: .4byte gTasks\n\t"
        "_0813961C: .4byte gSpecialVar_0x8005\n\t"
        "_08139620: .4byte gSpecialVar_0x8006\n\t"
        "_08139624: .4byte gSpecialVar_0x8007\n\t"
        "_08139628: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813962C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813968C\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	movs r1, #2\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #6\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl __modsi3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08139684\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #4]\n\t"
        "	ldrh r0, [r4]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl SetCameraPanning\n\t"
        "	movs r1, #4\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08139684\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08139690\n\t"
        "	bl InstallCameraPanAheadCallback\n\t"
        "_08139684:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813968C: .4byte gUnknown_3005B68\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08139690(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 FoundBlackGlasses(void)
{
    return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);
}

void SetRoute119Weather(void)
{
    if ((u8)IsMapTypeOutdoors((u8)GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE119_CYCLE);
}

void SetRoute123Weather(void)
{
    if ((u8)IsMapTypeOutdoors((u8)GetLastUsedWarpMapType()) != TRUE)
        SetSavedWeather(WEATHER_ROUTE123_CYCLE);
}

u8 GetLeadMonIndex(void)
{
    u8 i;
    u8 partyCount = CalculatePlayerPartyCount();
    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG
         && GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != 0)
            return i;
    }
    return 0; // Shouldn't happen
}

u16 ScriptGetPartyMonSpecies(void)
{
    return GetMonData3(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES_OR_EGG, NULL);
}

// Removed for Emerald
void TryInitBattleTowerAwardManObjectEvent(void) {}
u16 GetDaysUntilPacifidlogTMAvailable(void)
{
    u16 tmReceivedDay = VarGet(VAR_PACIFIDLOG_TM_RECEIVED_DAY);
    if (gLocalTime.days - tmReceivedDay >= 7)
        return 0;
    else if (gLocalTime.days < 0)
        return 8;

    return 7 - (gLocalTime.days - tmReceivedDay);
}

u16 SetPacifidlogTMReceivedDay(void)
{
    VarSet(VAR_PACIFIDLOG_TM_RECEIVED_DAY, gLocalTime.days);
    return gLocalTime.days;
}

bool8 MonOTNameNotPlayer(void)
{
    GetMonData3(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_OT_NAME, gStringVar1);

    if (!StringCompare(gSaveBlock2Ptr->playerName, gStringVar1))
        return FALSE;

    return TRUE;
}

void BufferLottoTicketNumber(void)
{
    if (gSpecialVar_Result >= 10000)
    {
        TV_PrintIntToStringVar(0, gSpecialVar_Result);
    }
    else if (gSpecialVar_Result >= 1000)
    {
        gStringVar1[0] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 1, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 100)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 2, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else if (gSpecialVar_Result >= 10)
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 3, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
    else
    {
        gStringVar1[0] = CHAR_0;
        gStringVar1[1] = CHAR_0;
        gStringVar1[2] = CHAR_0;
        gStringVar1[3] = CHAR_0;
        ConvertIntToDecimalStringN(gStringVar1 + 4, gSpecialVar_Result, STR_CONV_MODE_LEFT_ALIGN, CountDigits(gSpecialVar_Result));
    }
}

// JP-specific source-location diagnostics retained by GetMysteryGiftCardStat.
FIELD_SPECIALS_DATA_MYSTERY_GIFT_ASSERT const char sGetMysteryGiftCardStatAssertFile[12] = "scr_tool.c";
FIELD_SPECIALS_DATA_MYSTERY_GIFT_ASSERT const char sGetMysteryGiftCardStatAssertExpression[4] = "0";

__attribute__((naked)) u16 GetMysteryGiftCardStat(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081398E0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _08139918\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081398E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081398E0: .4byte gSpecialVar_Result\n\t"
        "_081398E4: .4byte _081398E8\n\t"
        "_081398E8:\n\t"
        "	.4byte _081398FC\n\t"
        "	.4byte _08139900\n\t"
        "	.4byte _08139904\n\t"
        "	.4byte _08139908\n\t"
        "	.4byte _0813990C\n\t"
        "_081398FC:\n\t"
        "	movs r0, #3\n\t"
        "	b _0813990E\n\t"
        "_08139900:\n\t"
        "	movs r0, #4\n\t"
        "	b _0813990E\n\t"
        "_08139904:\n\t"
        "	movs r0, #0\n\t"
        "	b _0813990E\n\t"
        "_08139908:\n\t"
        "	movs r0, #1\n\t"
        "	b _0813990E\n\t"
        "_0813990C:\n\t"
        "	movs r0, #2\n\t"
        "_0813990E:\n\t"
        "	bl MysteryGift_GetCardStat\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	b _08139926\n\t"
        "_08139918:\n\t"
        "	ldr r0, _0813992C\n\t"
        "	ldr r1, _08139930\n\t"
        "	ldr r2, _08139934\n\t"
        "	movs r3, #1\n\t"
        "	bl AGBAssert\n\t"
        "	movs r0, #0\n\t"
        "_08139926:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0813992C: .4byte sGetMysteryGiftCardStatAssertFile\n\t"
        "_08139930: .4byte 0x00000B14\n\t"
        "_08139934: .4byte sGetMysteryGiftCardStatAssertExpression\n\t"
        ".syntax divided\n\t"
    );
}

bool8 BufferTMHMMoveName(void)
{
    if (gSpecialVar_0x8004 >= ITEM_TM01 && gSpecialVar_0x8004 <= ITEM_HM08)
    {
        StringCopy(gStringVar2, gMoveNames[ItemIdToBattleMoveId(gSpecialVar_0x8004)]);
        return TRUE;
    }

    return FALSE;
}

bool8 IsBadEggInParty(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u8 i;

    for (i = 0; i < partyCount; i++)
    {
        if (GetMonData3(&gPlayerParty[i], MON_DATA_SANITY_IS_BAD_EGG) == TRUE)
            return TRUE;
    }

    return FALSE;
}

__attribute__((naked)) bool8 InMultiPartnerRoom(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081399E0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	ldr r0, _081399E4\n\t"
        "	cmp r1, r0\n\t"
        "	bne _081399EC\n\t"
        "	ldr r0, _081399E8\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #2\n\t"
        "	bne _081399EC\n\t"
        "	movs r0, #1\n\t"
        "	b _081399EE\n\t"
        "	.align 2, 0\n\t"
        "_081399E0: .4byte gSaveBlock1Ptr\n\t"
        "_081399E4: .4byte 0x00000F1A\n\t"
        "_081399E8: .4byte 0x000040CE\n\t"
        "_081399EC:\n\t"
        "	movs r0, #0\n\t"
        "_081399EE:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void OffsetCameraForBattle(void)
{
    SetCameraPanningCallback(NULL);
    SetCameraPanning(8, 0);
}

void SetDeptStoreFloor(void)
{
    u8 deptStoreFloor;
    switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
    {
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_1F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_2F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_3F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_4F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F):
        deptStoreFloor = DEPT_STORE_FLOORNUM_5F;
        break;
    case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP):
        deptStoreFloor = DEPT_STORE_FLOORNUM_ROOFTOP;
        break;
    default:
        deptStoreFloor = DEPT_STORE_FLOORNUM_1F;
        break;
    }
    VarSet(VAR_DEPT_STORE_FLOOR, deptStoreFloor);
}

u16 GetDeptStoreDefaultFloorChoice(void)
{
    gUnknown_203A82C = 0;
    gUnknown_203A82E = 0;

    if (gSaveBlock1Ptr->dynamicWarp.mapGroup == MAP_GROUP(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F))
    {
        switch (gSaveBlock1Ptr->dynamicWarp.mapNum)
        {
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F):
            gUnknown_203A82C = 0;
            gUnknown_203A82E = 0;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F):
            gUnknown_203A82C = 0;
            gUnknown_203A82E = 1;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F):
            gUnknown_203A82C = 0;
            gUnknown_203A82E = 2;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F):
            gUnknown_203A82C = 0;
            gUnknown_203A82E = 3;
            break;
        case MAP_NUM(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F):
            gUnknown_203A82C = 0;
            gUnknown_203A82E = 4;
            break;
        }
    }

    return gUnknown_203A82E;
}

// Kept externally visible while the Department Store elevator routines remain
// byte-exact naked assembly.
FIELD_SPECIALS_DATA_ELEVATOR const struct WindowTemplate sWindowTemplate_ElevatorFloor =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 1,
    .width = 8,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 8,
};

FIELD_SPECIALS_DATA_ELEVATOR const u8 *const sDeptStoreFloorNames[] =
{
    [DEPT_STORE_FLOORNUM_B4F] = gText_B4F,
    [DEPT_STORE_FLOORNUM_B3F] = gText_B3F,
    [DEPT_STORE_FLOORNUM_B2F] = gText_B2F,
    [DEPT_STORE_FLOORNUM_B1F] = gText_B1F,
    [DEPT_STORE_FLOORNUM_1F] = gText_1F,
    [DEPT_STORE_FLOORNUM_2F] = gText_2F,
    [DEPT_STORE_FLOORNUM_3F] = gText_3F,
    [DEPT_STORE_FLOORNUM_4F] = gText_4F,
    [DEPT_STORE_FLOORNUM_5F] = gText_5F,
    [DEPT_STORE_FLOORNUM_6F] = gText_6F,
    [DEPT_STORE_FLOORNUM_7F] = gText_7F,
    [DEPT_STORE_FLOORNUM_8F] = gText_8F,
    [DEPT_STORE_FLOORNUM_9F] = gText_9F,
    [DEPT_STORE_FLOORNUM_10F] = gText_10F,
    [DEPT_STORE_FLOORNUM_11F] = gText_11F,
    [DEPT_STORE_FLOORNUM_ROOFTOP] = gText_Rooftop,
};

FIELD_SPECIALS_DATA_ELEVATOR const u16 sElevatorWindowTiles_Ascending[ELEVATOR_WINDOW_HEIGHT][ELEVATOR_LIGHT_STAGES] =
{
    {
        METATILE_BattleFrontier_Elevator_Top0,
        METATILE_BattleFrontier_Elevator_Top1,
        METATILE_BattleFrontier_Elevator_Top2,
    },
    {
        METATILE_BattleFrontier_Elevator_Mid0,
        METATILE_BattleFrontier_Elevator_Mid1,
        METATILE_BattleFrontier_Elevator_Mid2,
    },
    {
        METATILE_BattleFrontier_Elevator_Bottom0,
        METATILE_BattleFrontier_Elevator_Bottom1,
        METATILE_BattleFrontier_Elevator_Bottom2,
    },
};

FIELD_SPECIALS_DATA_ELEVATOR const u16 sElevatorWindowTiles_Descending[ELEVATOR_WINDOW_HEIGHT][ELEVATOR_LIGHT_STAGES] =
{
    {
        METATILE_BattleFrontier_Elevator_Top0,
        METATILE_BattleFrontier_Elevator_Top2,
        METATILE_BattleFrontier_Elevator_Top1,
    },
    {
        METATILE_BattleFrontier_Elevator_Mid0,
        METATILE_BattleFrontier_Elevator_Mid2,
        METATILE_BattleFrontier_Elevator_Mid1,
    },
    {
        METATILE_BattleFrontier_Elevator_Bottom0,
        METATILE_BattleFrontier_Elevator_Bottom2,
        METATILE_BattleFrontier_Elevator_Bottom1,
    },
};

FIELD_SPECIALS_DATA_ELEVATOR const u8 sElevatorTripLength[] = { 8, 16, 24, 32, 38, 46, 52, 56, 57 };
FIELD_SPECIALS_DATA_ELEVATOR const u8 sElevatorLightCycles[] = { 3, 6, 9, 12, 15, 18, 21, 24, 27 };

__attribute__((naked)) void MoveElevator(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _08139B24\n\t"
        "	movs r1, #9\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _08139B28\n\t"
        "	adds r4, r1, r0\n\t"
        "	movs r3, #0\n\t"
        "	strh r3, [r4, #2]\n\t"
        "	strh r3, [r4, #4]\n\t"
        "	movs r6, #1\n\t"
        "	strh r6, [r4, #8]\n\t"
        "	ldr r0, _08139B2C\n\t"
        "	ldr r1, _08139B30\n\t"
        "	ldrh r2, [r0]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r2, r0\n\t"
        "	bls _08139B34\n\t"
        "	subs r0, r2, r0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	strh r6, [r4, #0xc]\n\t"
        "	b _08139B3C\n\t"
        "	.align 2, 0\n\t"
        "_08139B24: .4byte sub_08139B68 + 1\n\t"
        "_08139B28: .4byte gUnknown_3005B68\n\t"
        "_08139B2C: .4byte gSpecialVar_0x8005\n\t"
        "_08139B30: .4byte gSpecialVar_0x8006\n\t"
        "_08139B34:\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	strh r3, [r4, #0xc]\n\t"
        "_08139B3C:\n\t"
        "	cmp r5, #8\n\t"
        "	bls _08139B42\n\t"
        "	movs r5, #8\n\t"
        "_08139B42:\n\t"
        "	ldr r0, _08139B64\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	movs r0, #0\n\t"
        "	bl SetCameraPanningCallback\n\t"
        "	ldrb r1, [r4, #0xc]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08139C68\n\t"
        "	movs r0, #0x59\n\t"
        "	bl PlaySE\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139B64: .4byte sElevatorTripLength\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08139B68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08139BD0\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	movs r1, #2\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #3\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08139BC8\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #4]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	movs r0, #0\n\t"
        "	bl SetCameraPanning\n\t"
        "	movs r0, #4\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08139BC8\n\t"
        "	movs r0, #0x49\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	bl InstallCameraPanAheadCallback\n\t"
        "_08139BC8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139BD0: .4byte gUnknown_3005B68\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShowDeptStoreElevatorFloorSelect(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r4, _08139C38\n\t"
        "	ldr r0, _08139C3C\n\t"
        "	bl AddWindow\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08139C40\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r6, #0xff\n\t"
        "	str r6, [sp, #4]\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08139C44\n\t"
        "	ldr r1, _08139C48\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0x13\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139C38: .4byte gUnknown_203A82A\n\t"
        "_08139C3C: .4byte sWindowTemplate_ElevatorFloor\n\t"
        "_08139C40: .4byte gText_ElevatorNowOn\n\t"
        "_08139C44: .4byte sDeptStoreFloorNames\n\t"
        "_08139C48: .4byte gSpecialVar_0x8005\n\t"
        ".syntax divided\n\t"
    );
}

void CloseDeptStoreElevatorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_203A82A, TRUE);
    RemoveWindow(gUnknown_203A82A);
}

__attribute__((naked)) void sub_08139C68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	ldr r4, _08139CB0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FuncIsActiveTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08139CA8\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _08139CB4\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	strh r5, [r1, #0xc]\n\t"
        "	ldr r0, _08139CB8\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strh r0, [r1, #0xe]\n\t"
        "_08139CA8:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139CB0: .4byte MoveElevatorWindowLights + 1\n\t"
        "_08139CB4: .4byte gTasks\n\t"
        "_08139CB8: .4byte sElevatorLightCycles\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MoveElevatorWindowLights(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, [sp]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08139D44\n\t"
        "	adds r6, r0, r1\n\t"
        "	movs r2, #2\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r0, #6\n\t"
        "	bne _08139DB8\n\t"
        "	ldrh r0, [r6]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6]\n\t"
        "	movs r1, #4\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08139D4C\n\t"
        "	movs r1, #0\n\t"
        "	ldr r2, _08139D48\n\t"
        "	mov sl, r2\n\t"
        "_08139CF6:\n\t"
        "	movs r5, #0\n\t"
        "	adds r7, r1, #7\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r2, r1, #1\n\t"
        "	mov r8, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	mov sb, r0\n\t"
        "_08139D06:\n\t"
        "	adds r4, r5, #0\n\t"
        "	adds r4, #8\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	movs r1, #3\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0xf\n\t"
        "	add r0, sb\n\t"
        "	add r0, sl\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r2, r1, #0\n\t"
        "	orrs r2, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #2\n\t"
        "	bls _08139D06\n\t"
        "	mov r2, r8\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #2\n\t"
        "	bls _08139CF6\n\t"
        "	b _08139D9E\n\t"
        "	.align 2, 0\n\t"
        "_08139D44: .4byte gUnknown_3005B68\n\t"
        "_08139D48: .4byte sElevatorWindowTiles_Ascending\n\t"
        "_08139D4C:\n\t"
        "	movs r1, #0\n\t"
        "	ldr r0, _08139DD0\n\t"
        "	mov sl, r0\n\t"
        "_08139D52:\n\t"
        "	movs r5, #0\n\t"
        "	adds r7, r1, #7\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r2, r1, #1\n\t"
        "	mov r8, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	mov sb, r0\n\t"
        "_08139D62:\n\t"
        "	adds r4, r5, #0\n\t"
        "	adds r4, #8\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	movs r1, #3\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0xf\n\t"
        "	add r0, sb\n\t"
        "	add r0, sl\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r2, r1, #0\n\t"
        "	orrs r2, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #2\n\t"
        "	bls _08139D62\n\t"
        "	mov r2, r8\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #2\n\t"
        "	bls _08139D52\n\t"
        "_08139D9E:\n\t"
        "	bl DrawWholeMapView\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r6, #2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r6, r0]\n\t"
        "	movs r2, #6\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08139DB8\n\t"
        "	ldr r0, [sp]\n\t"
        "	bl DestroyTask\n\t"
        "_08139DB8:\n\t"
        "	ldrh r0, [r6, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #2]\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08139DD0: .4byte sElevatorWindowTiles_Descending\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BufferVarsForIVRater(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0x18\n\t"
        "	ldr r6, _08139E7C\n\t"
        "	ldrh r0, [r6]\n\t"
        "	movs r5, #0x64\n\t"
        "	muls r0, r5, r0\n\t"
        "	ldr r4, _08139E80\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x27\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x28\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x29\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp, #8]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x2a\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x2b\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp, #0x10]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x2c\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [sp, #0x14]\n\t"
        "	ldr r1, _08139E84\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r4, #0\n\t"
        "	adds r2, r1, #0\n\t"
        "_08139E3C:\n\t"
        "	lsls r0, r4, #2\n\t"
        "	add r0, sp\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r2]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _08139E3C\n\t"
        "	ldr r2, _08139E88\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	ldr r1, _08139E8C\n\t"
        "	ldr r0, [sp]\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r4, #1\n\t"
        "	adds r6, r2, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "_08139E64:\n\t"
        "	ldrh r0, [r6]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r2, sp\n\t"
        "	adds r1, r2, r0\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r5, r2, r0\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	cmp r1, r0\n\t"
        "	bhs _08139E90\n\t"
        "	strh r4, [r6]\n\t"
        "	b _08139EA8\n\t"
        "	.align 2, 0\n\t"
        "_08139E7C: .4byte gSpecialVar_0x8004\n\t"
        "_08139E80: .4byte gPlayerParty\n\t"
        "_08139E84: .4byte gSpecialVar_0x8005\n\t"
        "_08139E88: .4byte gSpecialVar_0x8006\n\t"
        "_08139E8C: .4byte gSpecialVar_0x8007\n\t"
        "_08139E90:\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08139EAA\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08139EAA\n\t"
        "	strh r4, [r6]\n\t"
        "	ldr r0, [r5]\n\t"
        "_08139EA8:\n\t"
        "	strh r0, [r7]\n\t"
        "_08139EAA:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _08139E64\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void warp0_in_pokecenter(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _08139EEC\n\t"
        "	movs r1, #0\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	ldr r2, _08139EF0\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldr r1, _08139EF4\n\t"
        "	cmp r0, r1\n\t"
        "	beq _08139F02\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "_08139EE0:\n\t"
        "	ldrh r0, [r2]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _08139EF8\n\t"
        "	movs r0, #1\n\t"
        "	b _08139F04\n\t"
        "	.align 2, 0\n\t"
        "_08139EEC: .4byte gUnknown_2031F7C\n\t"
        "_08139EF0: .4byte sElevatorLightCycles + 0x9\n\t"
        "_08139EF4: .4byte 0x0000FFFF\n\t"
        "_08139EF8:\n\t"
        "	adds r1, #2\n\t"
        "	adds r2, #2\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, r4\n\t"
        "	bne _08139EE0\n\t"
        "_08139F02:\n\t"
        "	movs r0, #0\n\t"
        "_08139F04:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool32 PlayerNotAtTrainerHillEntrance(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_TRAINER_HILL_ENTRANCE) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_TRAINER_HILL_ENTRANCE))
        return FALSE;

    return TRUE;
}

void UpdateFrontierManiac(u16 daysSince)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_MANIAC_FACILITY);
    *var += daysSince;
    *var %= 10;
}

__attribute__((naked)) void ShowFrontierManiacMessage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _08139F7C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	cmp r6, #9\n\t"
        "	bls _08139F70\n\t"
        "	b _0813A076\n\t"
        "_08139F70:\n\t"
        "	lsls r0, r6, #2\n\t"
        "	ldr r1, _08139F80\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r2, r0, #0\n\t"
        "	mov pc, r1\n\t"
        "	.align 2, 0\n\t"
        "_08139F7C: .4byte 0x0000402F\n\t"
        "_08139F80: .4byte _08139F84\n\t"
        "_08139F84:\n\t"
        "	.4byte _08139FAC\n\t"
        "	.4byte _08139FAC\n\t"
        "	.4byte _08139FAC\n\t"
        "	.4byte _08139FAC\n\t"
        "	.4byte _08139FD0\n\t"
        "	.4byte _08139FF0\n\t"
        "	.4byte _0813A008\n\t"
        "	.4byte _0813A020\n\t"
        "	.4byte _0813A038\n\t"
        "	.4byte _0813A050\n\t"
        "_08139FAC:\n\t"
        "	ldr r0, _08139FC8\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r3, #0xce\n\t"
        "	lsls r3, r3, #4\n\t"
        "	adds r1, r0, r3\n\t"
        "	adds r3, r1, r2\n\t"
        "	ldr r1, _08139FCC\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrh r0, [r3]\n\t"
        "	ldrh r2, [r1]\n\t"
        "	cmp r0, r2\n\t"
        "	bhs _0813A064\n\t"
        "	b _0813A074\n\t"
        "	.align 2, 0\n\t"
        "_08139FC8: .4byte gSaveBlock2Ptr\n\t"
        "_08139FCC: .4byte 0x00000CE2\n\t"
        "_08139FD0:\n\t"
        "	ldr r0, _08139FE8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r3, _08139FEC\n\t"
        "	adds r2, r0, r3\n\t"
        "	adds r3, #2\n\t"
        "_08139FDA:\n\t"
        "	adds r1, r0, r3\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldrh r3, [r1]\n\t"
        "	cmp r0, r3\n\t"
        "	bhs _0813A064\n\t"
        "	b _0813A074\n\t"
        "	.align 2, 0\n\t"
        "_08139FE8: .4byte gSaveBlock2Ptr\n\t"
        "_08139FEC: .4byte 0x00000D0C\n\t"
        "_08139FF0:\n\t"
        "	ldr r0, _08139FFC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A000\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r3, _0813A004\n\t"
        "	b _08139FDA\n\t"
        "	.align 2, 0\n\t"
        "_08139FFC: .4byte gSaveBlock2Ptr\n\t"
        "_0813A000: .4byte 0x00000DE2\n\t"
        "_0813A004: .4byte 0x00000DE4\n\t"
        "_0813A008:\n\t"
        "	ldr r0, _0813A014\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A018\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r3, _0813A01C\n\t"
        "	b _08139FDA\n\t"
        "	.align 2, 0\n\t"
        "_0813A014: .4byte gSaveBlock2Ptr\n\t"
        "_0813A018: .4byte 0x00000DC8\n\t"
        "_0813A01C: .4byte 0x00000DCA\n\t"
        "_0813A020:\n\t"
        "	ldr r0, _0813A02C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A030\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r3, _0813A034\n\t"
        "	b _08139FDA\n\t"
        "	.align 2, 0\n\t"
        "_0813A02C: .4byte gSaveBlock2Ptr\n\t"
        "_0813A030: .4byte 0x00000DDA\n\t"
        "_0813A034: .4byte 0x00000DDC\n\t"
        "_0813A038:\n\t"
        "	ldr r0, _0813A044\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A048\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r3, _0813A04C\n\t"
        "	b _08139FDA\n\t"
        "	.align 2, 0\n\t"
        "_0813A044: .4byte gSaveBlock2Ptr\n\t"
        "_0813A048: .4byte 0x00000E04\n\t"
        "_0813A04C: .4byte 0x00000E06\n\t"
        "_0813A050:\n\t"
        "	ldr r0, _0813A068\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A06C\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r3, _0813A070\n\t"
        "	adds r1, r0, r3\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldrh r3, [r1]\n\t"
        "	cmp r0, r3\n\t"
        "	blo _0813A074\n\t"
        "_0813A064:\n\t"
        "	adds r4, r0, #0\n\t"
        "	b _0813A076\n\t"
        "	.align 2, 0\n\t"
        "_0813A068: .4byte gSaveBlock2Ptr\n\t"
        "_0813A06C: .4byte 0x00000E1A\n\t"
        "_0813A070: .4byte 0x00000E1C\n\t"
        "_0813A074:\n\t"
        "	ldrh r4, [r1]\n\t"
        "_0813A076:\n\t"
        "	movs r2, #0\n\t"
        "	ldr r5, _0813A0B4\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r1, r0, r5\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r3, r0, #0\n\t"
        "	ldr r7, _0813A0B8\n\t"
        "	cmp r1, r4\n\t"
        "	bhs _0813A09E\n\t"
        "	adds r1, r3, #0\n\t"
        "_0813A08A:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #1\n\t"
        "	bhi _0813A09E\n\t"
        "	adds r0, r2, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r4\n\t"
        "	blo _0813A08A\n\t"
        "_0813A09E:\n\t"
        "	adds r0, r3, r6\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl ShowFieldMessage\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A0B4: .4byte gUnknown_8592724\n\t"
        "_0813A0B8: .4byte gUnknown_85926AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BufferBattleTowerElevatorFloors(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r0, _0813A0F8\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r0, _0813A0FC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A100\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r4, r0, #0x1e\n\t"
        "	cmp r5, #2\n\t"
        "	bne _0813A114\n\t"
        "	movs r0, #0xa9\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813A114\n\t"
        "	ldr r1, _0813A104\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _0813A108\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r1]\n\t"
        "	b _0813A14C\n\t"
        "	.align 2, 0\n\t"
        "_0813A0F8: .4byte 0x000040CE\n\t"
        "_0813A0FC: .4byte gSaveBlock2Ptr\n\t"
        "_0813A100: .4byte 0x00000CA9\n\t"
        "_0813A104: .4byte gSpecialVar_0x8005\n\t"
        "_0813A108: .4byte gSpecialVar_0x8006\n\t"
        "_0813A10C:\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r6]\n\t"
        "	adds r0, r3, #5\n\t"
        "	b _0813A14A\n\t"
        "_0813A114:\n\t"
        "	movs r3, #0\n\t"
        "	ldr r6, _0813A154\n\t"
        "	ldr r7, _0813A158\n\t"
        "	lsls r1, r4, #1\n\t"
        "	lsls r2, r5, #2\n\t"
        "	ldr r4, _0813A15C\n\t"
        "	ldr r0, _0813A160\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #0xce\n\t"
        "	lsls r2, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "_0813A130:\n\t"
        "	lsls r0, r3, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r1\n\t"
        "	bhi _0813A10C\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #8\n\t"
        "	bls _0813A130\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r6]\n\t"
        "	movs r0, #0xc\n\t"
        "_0813A14A:\n\t"
        "	strh r0, [r7]\n\t"
        "_0813A14C:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A154: .4byte gSpecialVar_0x8005\n\t"
        "_0813A158: .4byte gSpecialVar_0x8006\n\t"
        "_0813A15C: .4byte gUnknown_8592738\n\t"
        "_0813A160: .4byte gSaveBlock2Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShowScrollableMultichoice(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _0813A194\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813A198\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldr r1, _0813A19C\n\t"
        "	ldrh r0, [r1]\n\t"
        "	strh r0, [r3, #0x1e]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, #0xc\n\t"
        "	bls _0813A18A\n\t"
        "	b _0813A302\n\t"
        "_0813A18A:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0813A1A0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A194: .4byte sub_0813A318 + 1\n\t"
        "_0813A198: .4byte gTasks\n\t"
        "_0813A19C: .4byte gSpecialVar_0x8004\n\t"
        "_0813A1A0: .4byte _0813A1A4\n\t"
        "_0813A1A4:\n\t"
        "	.4byte _0813A1D8\n\t"
        "	.4byte _0813A1E6\n\t"
        "	.4byte _0813A1FE\n\t"
        "	.4byte _0813A212\n\t"
        "	.4byte _0813A22C\n\t"
        "	.4byte _0813A244\n\t"
        "	.4byte _0813A25E\n\t"
        "	.4byte _0813A278\n\t"
        "	.4byte _0813A296\n\t"
        "	.4byte _0813A2B0\n\t"
        "	.4byte _0813A2B0\n\t"
        "	.4byte _0813A2CA\n\t"
        "	.4byte _0813A2E4\n\t"
        "_0813A1D8:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	b _0813A2F8\n\t"
        "_0813A1E6:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #9\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xa\n\t"
        "	b _0813A2FA\n\t"
        "_0813A1FE:\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r1, #0xc\n\t"
        "	strh r1, [r3, #0xa]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #7\n\t"
        "	b _0813A28C\n\t"
        "_0813A212:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0xe\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A22C:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0xe\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A244:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0xe\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A25E:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #0xa\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0xe\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A278:\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r1, #0xc\n\t"
        "	strh r1, [r3, #0xa]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xe\n\t"
        "_0813A28C:\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	strh r1, [r3, #0x12]\n\t"
        "	strh r2, [r3, #0x14]\n\t"
        "	strh r4, [r3, #0x26]\n\t"
        "	b _0813A30E\n\t"
        "_0813A296:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #0xa\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0x11\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A2B0:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0xf\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xe\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A2CA:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0x13\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xa\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0813A2FA\n\t"
        "_0813A2E4:\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r3, #8]\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r3, #0xa]\n\t"
        "	movs r0, #0x11\n\t"
        "	strh r0, [r3, #0xc]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r3, #0xe]\n\t"
        "	movs r0, #0xc\n\t"
        "_0813A2F8:\n\t"
        "	strh r0, [r3, #0x10]\n\t"
        "_0813A2FA:\n\t"
        "	strh r0, [r3, #0x12]\n\t"
        "	strh r1, [r3, #0x14]\n\t"
        "	strh r4, [r3, #0x26]\n\t"
        "	b _0813A30E\n\t"
        "_0813A302:\n\t"
        "	ldr r1, _0813A314\n\t"
        "	movs r0, #0x7f\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813A30E:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A314: .4byte gSpecialVar_Result\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A318(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0x20\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813A410\n\t"
        "	adds r5, r0, r1\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	ldr r1, _0813A414\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _0813A418\n\t"
        "	movs r0, #0x40\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrh r0, [r5, #0x1e]\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_0813AAAC\n\t"
        "	ldrb r0, [r5, #0x1e]\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_0813AD2C\n\t"
        "	ldrb r2, [r5, #0xc]\n\t"
        "	ldrb r3, [r5, #0xe]\n\t"
        "	ldrb r0, [r5, #0x10]\n\t"
        "	str r0, [sp]\n\t"
        "	ldrb r0, [r5, #0x12]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0xf\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0x5c\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	add r0, sp, #0x10\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateWindowTemplate\n\t"
        "	ldr r0, [sp, #0x10]\n\t"
        "	ldr r1, [sp, #0x14]\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	str r1, [sp, #0x1c]\n\t"
        "	add r0, sp, #0x18\n\t"
        "	bl AddWindow\n\t"
        "	movs r4, #0\n\t"
        "	strh r0, [r5, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	ldr r6, _0813A41C\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r6]\n\t"
        "	ldr r0, _0813A420\n\t"
        "	strh r4, [r0]\n\t"
        "	bl sub_0813A434\n\t"
        "	movs r3, #0\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r3, r0\n\t"
        "	bge _0813A3CE\n\t"
        "	mov ip, r6\n\t"
        "	ldr r6, _0813A424\n\t"
        "	ldr r4, _0813A428\n\t"
        "_0813A3A8:\n\t"
        "	mov r1, ip\n\t"
        "	ldr r0, [r1]\n\t"
        "	lsls r2, r3, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r1, r3, #2\n\t"
        "	ldrh r0, [r4]\n\t"
        "	lsls r0, r0, #6\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldr r0, [r1]\n\t"
        "	str r0, [r2]\n\t"
        "	str r3, [r2, #4]\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r3, r0\n\t"
        "	blt _0813A3A8\n\t"
        "_0813A3CE:\n\t"
        "	ldr r4, _0813A42C\n\t"
        "	ldrh r0, [r5, #0xa]\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	ldrh r0, [r5, #0x22]\n\t"
        "	strb r0, [r4, #0x10]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl sub_0813A69C\n\t"
        "	ldrh r1, [r5, #0x16]\n\t"
        "	ldrh r2, [r5, #0x18]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ListMenuInit\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5, #0x24]\n\t"
        "	movs r0, #0\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _0813A410\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0813A430\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #0x20\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A410: .4byte gTasks\n\t"
        "_0813A414: .4byte gUnknown_203A834\n\t"
        "_0813A418: .4byte gUnknown_203A838\n\t"
        "_0813A41C: .4byte gUnknown_203A830\n\t"
        "_0813A420: .4byte gUnknown_203A836\n\t"
        "_0813A424: .4byte gUnknown_859274C\n\t"
        "_0813A428: .4byte gSpecialVar_0x8004\n\t"
        "_0813A42C: .4byte gUnknown_3005F10\n\t"
        "_0813A430: .4byte sub_0813A4F4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A434(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _0813A468\n\t"
        "	ldr r0, _0813A46C\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _0813A470\n\t"
        "	str r0, [r1, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1, #8]\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	strh r0, [r1, #0xe]\n\t"
        "	strb r2, [r1, #0x10]\n\t"
        "	strb r2, [r1, #0x11]\n\t"
        "	movs r0, #8\n\t"
        "	strb r0, [r1, #0x12]\n\t"
        "	strb r2, [r1, #0x13]\n\t"
        "	movs r0, #0x20\n\t"
        "	strb r0, [r1, #0x14]\n\t"
        "	movs r0, #0x31\n\t"
        "	strb r0, [r1, #0x15]\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #0x16]\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #0x17]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0813A468: .4byte gUnknown_3005F10\n\t"
        "_0813A46C: .4byte gUnknown_203A830\n\t"
        "_0813A470: .4byte sub_0813A474 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A474(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _0813A4E4\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0813A4DC\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r0, _0813A4E8\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r1, sp\n\t"
        "	movs r2, #0\n\t"
        "	bl ListMenuGetScrollAndRow\n\t"
        "	ldr r1, _0813A4EC\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldrh r0, [r4, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r1, sp\n\t"
        "	bl ListMenuGetCurrentItemArrayId\n\t"
        "	ldrh r0, [r4, #0x1e]\n\t"
        "	ldr r5, _0813A4F0\n\t"
        "	ldrh r1, [r5]\n\t"
        "	bl sub_0813AC90\n\t"
        "	ldrh r0, [r4, #0x1e]\n\t"
        "	mov r1, sp\n\t"
        "	ldrh r1, [r1]\n\t"
        "	bl sub_0813AAAC\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	mov r1, sp\n\t"
        "	ldrh r1, [r1]\n\t"
        "	bl sub_0813AD6C\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r5]\n\t"
        "_0813A4DC:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A4E4: .4byte sub_0813A4F4 + 1\n\t"
        "_0813A4E8: .4byte gTasks\n\t"
        "_0813A4EC: .4byte gUnknown_203A834\n\t"
        "_0813A4F0: .4byte gUnknown_203A836\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A4F4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813A520\n\t"
        "	adds r6, r0, r1\n\t"
        "	ldrh r0, [r6, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl ListMenu_ProcessInput\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0813A524\n\t"
        "	adds r0, #1\n\t"
        "	cmp r4, r0\n\t"
        "	bne _0813A538\n\t"
        "	b _0813A56E\n\t"
        "	.align 2, 0\n\t"
        "_0813A520: .4byte gTasks\n\t"
        "_0813A524:\n\t"
        "	ldr r1, _0813A534\n\t"
        "	movs r0, #0x7f\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	b _0813A554\n\t"
        "	.align 2, 0\n\t"
        "_0813A534: .4byte gSpecialVar_Result\n\t"
        "_0813A538:\n\t"
        "	ldr r0, _0813A55C\n\t"
        "	strh r4, [r0]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813A554\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r4, r0\n\t"
        "	bne _0813A560\n\t"
        "_0813A554:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_0813A578\n\t"
        "	b _0813A56E\n\t"
        "	.align 2, 0\n\t"
        "_0813A55C: .4byte gSpecialVar_Result\n\t"
        "_0813A560:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_0813A740\n\t"
        "	ldr r0, _0813A574\n\t"
        "	str r0, [r6]\n\t"
        "	bl ScriptContext_Enable\n\t"
        "_0813A56E:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A574: .4byte sub_0813A608 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A578(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r0, _0813A600\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r1, sp\n\t"
        "	bl ListMenuGetCurrentItemArrayId\n\t"
        "	ldrh r0, [r4, #0x1e]\n\t"
        "	mov r1, sp\n\t"
        "	ldrh r1, [r1]\n\t"
        "	bl sub_0813AC90\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_0813A740\n\t"
        "	ldrh r0, [r4, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl DestroyListMenuTask\n\t"
        "	ldr r0, _0813A604\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl Free\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrameToTransparent\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl RemoveWindow\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A600: .4byte gTasks\n\t"
        "_0813A604: .4byte gUnknown_203A830\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A608(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0813A630\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #0x14\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0813A62C\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0813A62C\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1, #0x14]\n\t"
        "	ldr r0, _0813A634\n\t"
        "	str r0, [r1]\n\t"
        "_0813A62C:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A630: .4byte gTasks\n\t"
        "_0813A634: .4byte sub_0813A66C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ScrollableMultichoice_TryReturnToList(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813A650\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0xff\n\t"
        "	bne _0813A654\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	b _0813A664\n\t"
        "	.align 2, 0\n\t"
        "_0813A650: .4byte sub_0813A608 + 1\n\t"
        "_0813A654:\n\t"
        "	ldr r0, _0813A668\n\t"
        "	lsls r1, r2, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r1, #0x14]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r1, #0x14]\n\t"
        "_0813A664:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A668: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A66C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_0813A69C\n\t"
        "	ldr r1, _0813A694\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0813A698\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A694: .4byte gTasks\n\t"
        "_0813A698: .4byte sub_0813A4F4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A69C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _0813A734\n\t"
        "	adds r4, r1, r0\n\t"
        "	mov r1, sp\n\t"
        "	ldr r0, _0813A738\n\t"
        "	ldm r0!, {r2, r3, r5}\n\t"
        "	stm r1!, {r2, r3, r5}\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0813A72C\n\t"
        "	mov r2, sp\n\t"
        "	movs r3, #0x10\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	lsrs r0, r1, #0x1f\n\t"
        "	adds r1, r1, r0\n\t"
        "	asrs r1, r1, #1\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, #0xc\n\t"
        "	movs r5, #0xc\n\t"
        "	ldrsh r0, [r4, r5]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r3, #0\n\t"
        "	strb r1, [r2, #1]\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #8\n\t"
        "	strb r0, [r1, #2]\n\t"
        "	movs r0, #0x10\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsrs r0, r1, #0x1f\n\t"
        "	adds r1, r1, r0\n\t"
        "	asrs r1, r1, #1\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, #0xc\n\t"
        "	movs r5, #0xc\n\t"
        "	ldrsh r0, [r4, r5]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	strb r1, [r2, #4]\n\t"
        "	mov r1, sp\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #0xa\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	mov r0, sp\n\t"
        "	strh r3, [r0, #6]\n\t"
        "	mov r2, sp\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	ldrh r1, [r4, #8]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #8]\n\t"
        "	ldr r1, _0813A73C\n\t"
        "	mov r0, sp\n\t"
        "	bl AddScrollIndicatorArrowPair\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "_0813A72C:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A734: .4byte gTasks\n\t"
        "_0813A738: .4byte gUnknown_8592A8C\n\t"
        "_0813A73C: .4byte gUnknown_203A834\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A740(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _0813A76C\n\t"
        "	adds r2, r1, r0\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "	movs r3, #0xa\n\t"
        "	ldrsh r0, [r2, r3]\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0813A766\n\t"
        "	ldrh r0, [r2, #0x20]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl RemoveScrollIndicatorArrowPair\n\t"
        "_0813A766:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A76C: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

// Removed for Emerald (replaced by ShowScrollableMultichoice)
void ShowGlassWorkshopMenu(void)
{
}
void SetBattleTowerLinkPlayerGfx(void)
{
    u8 i;
    for (i = 0; i < 2; i++)
    {
        if (gLinkPlayers[i].gender == MALE)
            VarSet(VAR_OBJ_GFX_ID_F - i, OBJ_EVENT_GFX_BRENDAN_NORMAL);
        else
            VarSet(VAR_OBJ_GFX_ID_F - i, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL);
    }
}

__attribute__((naked)) void ShowNatureGirlMessage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _0813A7F0\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, #5\n\t"
        "	bls _0813A7CE\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "_0813A7CE:\n\t"
        "	ldrh r1, [r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0813A7F4\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl GetNature\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _0813A7F8\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl ShowFieldMessage\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A7F0: .4byte gSpecialVar_0x8004\n\t"
        "_0813A7F4: .4byte gPlayerParty\n\t"
        "_0813A7F8: .4byte gUnknown_8592A9C\n\t"
        ".syntax divided\n\t"
    );
}

void UpdateFrontierGambler(u16 daysSince)
{
    u16 *var = GetVarPointer(VAR_FRONTIER_GAMBLER_CHALLENGE);
    *var += daysSince;
    *var %= 12;
}

__attribute__((naked)) void ShowFrontierGamblerLookingMessage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _0813A850\n\t"
        "	bl VarGet\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r1, _0813A854\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl ShowFieldMessage\n\t"
        "	ldr r0, _0813A858\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl VarSet\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A850: .4byte 0x00004030\n\t"
        "_0813A854: .4byte gUnknown_8592B00\n\t"
        "_0813A858: .4byte 0x00004031\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShowFrontierGamblerGoMessage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0813A878\n\t"
        "	ldr r0, _0813A87C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0xe\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl ShowFieldMessage\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A878: .4byte gUnknown_8592B30\n\t"
        "_0813A87C: .4byte 0x00004031\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813A880(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r0, _0813A8DC\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	ldr r0, _0813A8E0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	ldr r0, _0813A8E4\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r4, _0813A8E8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813A8F8\n\t"
        "	ldr r1, _0813A8EC\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r5, #8\n\t"
        "	adds r0, r0, r7\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0813A8F8\n\t"
        "	mov r0, r8\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813A8F0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	bl VarSet\n\t"
        "	b _0813A8F8\n\t"
        "	.align 2, 0\n\t"
        "_0813A8DC: .4byte 0x000040CE\n\t"
        "_0813A8E0: .4byte 0x00004031\n\t"
        "_0813A8E4: .4byte 0x000040CF\n\t"
        "_0813A8E8: .4byte 0x00004033\n\t"
        "_0813A8EC: .4byte gUnknown_8592B60\n\t"
        "_0813A8F0:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl VarSet\n\t"
        "_0813A8F8:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShowBattlePointsWindow(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r5, _0813A974\n\t"
        "	ldr r0, _0813A978\n\t"
        "	bl AddWindow\n\t"
        "	strb r0, [r5]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	ldrb r0, [r5]\n\t"
        "	ldr r2, _0813A97C\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	mov r8, r1\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0x38\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldr r6, _0813A980\n\t"
        "	ldr r0, _0813A984\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A988\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #4\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldrb r0, [r5]\n\t"
        "	str r4, [sp]\n\t"
        "	mov r1, r8\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r6, #0\n\t"
        "	movs r3, #0x18\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A974: .4byte gUnknown_203A839\n\t"
        "_0813A978: .4byte gUnknown_8592B78\n\t"
        "_0813A97C: .4byte gText_BP\n\t"
        "_0813A980: .4byte gStringVar1\n\t"
        "_0813A984: .4byte gSaveBlock2Ptr\n\t"
        "_0813A988: .4byte 0x00000EB8\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdateBattlePointsWindow(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r4, _0813A9C4\n\t"
        "	ldr r0, _0813A9C8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0813A9CC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #4\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _0813A9D0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #0x18\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813A9C4: .4byte gStringVar1\n\t"
        "_0813A9C8: .4byte gSaveBlock2Ptr\n\t"
        "_0813A9CC: .4byte 0x00000EB8\n\t"
        "_0813A9D0: .4byte gUnknown_203A839\n\t"
        ".syntax divided\n\t"
    );
}

void CloseBattlePointsWindow(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_203A839, TRUE);
    RemoveWindow(gUnknown_203A839);
}

void TakeFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints < gSpecialVar_0x8004)
        gSaveBlock2Ptr->frontier.battlePoints = 0;
    else
        gSaveBlock2Ptr->frontier.battlePoints -= gSpecialVar_0x8004;
}

void GiveFrontierBattlePoints(void)
{
    if (gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004 > MAX_BATTLE_FRONTIER_POINTS)
        gSaveBlock2Ptr->frontier.battlePoints = MAX_BATTLE_FRONTIER_POINTS;
    else
        gSaveBlock2Ptr->frontier.battlePoints = gSaveBlock2Ptr->frontier.battlePoints + gSpecialVar_0x8004;
}

u16 GetFrontierBattlePoints(void)
{
    return gSaveBlock2Ptr->frontier.battlePoints;
}

__attribute__((naked)) void ShowFrontierExchangeCornerItemIconWindow(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0813AA88\n\t"
        "	ldr r0, _0813AA8C\n\t"
        "	bl AddWindow\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AA88: .4byte gUnknown_203A83A\n\t"
        "_0813AA8C: .4byte gUnknown_8592B80\n\t"
        ".syntax divided\n\t"
    );
}

void CloseFrontierExchangeCornerItemIconWindow(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_203A83A, TRUE);
    RemoveWindow(gUnknown_203A83A);
}

__attribute__((naked)) void sub_0813AAAC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r1, _0813AAE8\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #3\n\t"
        "	bls _0813AAC4\n\t"
        "	b _0813AC0E\n\t"
        "_0813AAC4:\n\t"
        "	movs r0, #0xb0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x20\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0x11\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillWindowPixelRect\n\t"
        "	cmp r4, #4\n\t"
        "	beq _0813AB34\n\t"
        "	cmp r4, #4\n\t"
        "	bgt _0813AAEC\n\t"
        "	cmp r4, #3\n\t"
        "	beq _0813AAF6\n\t"
        "	b _0813AC0E\n\t"
        "	.align 2, 0\n\t"
        "_0813AAE8: .4byte 0xFFFD0000\n\t"
        "_0813AAEC:\n\t"
        "	cmp r4, #5\n\t"
        "	beq _0813ABA8\n\t"
        "	cmp r4, #6\n\t"
        "	beq _0813ABE0\n\t"
        "	b _0813AC0E\n\t"
        "_0813AAF6:\n\t"
        "	ldr r1, _0813AB28\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldr r1, _0813AB2C\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldrh r5, [r1]\n\t"
        "	ldr r0, _0813AB30\n\t"
        "	cmp r5, r0\n\t"
        "	beq _0813AB64\n\t"
        "	b _0813AB78\n\t"
        "	.align 2, 0\n\t"
        "_0813AB28: .4byte gUnknown_8592BCC\n\t"
        "_0813AB2C: .4byte gUnknown_8592B80 + 0x8\n\t"
        "_0813AB30: .4byte 0x0000FFFF\n\t"
        "_0813AB34:\n\t"
        "	ldr r1, _0813AB6C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldr r1, _0813AB70\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldrh r5, [r1]\n\t"
        "	ldr r0, _0813AB74\n\t"
        "	cmp r5, r0\n\t"
        "	bne _0813AB78\n\t"
        "_0813AB64:\n\t"
        "	ldrh r0, [r1]\n\t"
        "	bl sub_0813AC20\n\t"
        "	b _0813AC0E\n\t"
        "	.align 2, 0\n\t"
        "_0813AB6C: .4byte gUnknown_8592BF8\n\t"
        "_0813AB70: .4byte gUnknown_8592B80 + 0x1E\n\t"
        "_0813AB74: .4byte 0x0000FFFF\n\t"
        "_0813AB78:\n\t"
        "	ldr r4, _0813ABA0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	movs r1, #0x21\n\t"
        "	movs r2, #0x58\n\t"
        "	movs r3, #0\n\t"
        "	bl AddDecorationIconObject\n\t"
        "	ldr r1, _0813ABA4\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0813AC0E\n\t"
        "	.align 2, 0\n\t"
        "_0813ABA0: .4byte 0x0000157C\n\t"
        "_0813ABA4: .4byte gUnknown_203A838\n\t"
        "_0813ABA8:\n\t"
        "	ldr r1, _0813ABD8\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldr r1, _0813ABDC\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl sub_0813AC20\n\t"
        "	b _0813AC0E\n\t"
        "	.align 2, 0\n\t"
        "_0813ABD8: .4byte gUnknown_8592C10\n\t"
        "_0813ABDC: .4byte gUnknown_8592B80 + 0x2A\n\t"
        "_0813ABE0:\n\t"
        "	ldr r1, _0813AC18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldr r1, _0813AC1C\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl sub_0813AC20\n\t"
        "_0813AC0E:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AC18: .4byte gUnknown_8592C2C\n\t"
        "_0813AC1C: .4byte gUnknown_8592B80 + 0x38\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813AC20(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	ldr r4, _0813AC84\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl AddItemIconSprite\n\t"
        "	ldr r4, _0813AC88\n\t"
        "	strb r0, [r4]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _0813AC7E\n\t"
        "	ldr r3, _0813AC8C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r1, #0x24\n\t"
        "	strh r1, [r0, #0x20]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r1, #0x5c\n\t"
        "	strh r1, [r0, #0x22]\n\t"
        "_0813AC7E:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AC84: .4byte 0x0000157C\n\t"
        "_0813AC88: .4byte gUnknown_203A838\n\t"
        "_0813AC8C: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813AC90(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r2, _0813ACC0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _0813ACBC\n\t"
        "	cmp r1, #6\n\t"
        "	bgt _0813ACB6\n\t"
        "	cmp r1, #3\n\t"
        "	blt _0813ACB6\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0813ACC4\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl DestroySpriteAndFreeResources\n\t"
        "_0813ACB6:\n\t"
        "	ldr r1, _0813ACC0\n\t"
        "	movs r0, #0x40\n\t"
        "	strb r0, [r1]\n\t"
        "_0813ACBC:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813ACC0: .4byte gUnknown_203A838\n\t"
        "_0813ACC4: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BufferBattleFrontierTutorMoveName(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813ACEC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813AD00\n\t"
        "	ldr r0, _0813ACF0\n\t"
        "	ldr r2, _0813ACF4\n\t"
        "	ldr r1, _0813ACF8\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _0813ACFC\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	b _0813AD18\n\t"
        "	.align 2, 0\n\t"
        "_0813ACEC: .4byte gSpecialVar_0x8005\n\t"
        "_0813ACF0: .4byte gStringVar1\n\t"
        "_0813ACF4: .4byte gUnknown_8592C68\n\t"
        "_0813ACF8: .4byte gSpecialVar_0x8004\n\t"
        "_0813ACFC: .4byte gMoveNames\n\t"
        "_0813AD00:\n\t"
        "	ldr r0, _0813AD1C\n\t"
        "	ldr r2, _0813AD20\n\t"
        "	ldr r1, _0813AD24\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _0813AD28\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "_0813AD18:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AD1C: .4byte gStringVar1\n\t"
        "_0813AD20: .4byte gUnknown_8592C54\n\t"
        "_0813AD24: .4byte gSpecialVar_0x8004\n\t"
        "_0813AD28: .4byte gMoveNames\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813AD2C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r1, #0xf7\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _0813AD5C\n\t"
        "	ldr r4, _0813AD64\n\t"
        "	ldr r0, _0813AD68\n\t"
        "	bl AddWindow\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_0813AD6C\n\t"
        "_0813AD5C:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AD64: .4byte gUnknown_203A82A\n\t"
        "_0813AD68: .4byte gUnknown_8592C7C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813AD6C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	adds r7, r5, #0\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r1, #0xf7\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _0813ADE4\n\t"
        "	ldr r4, _0813ADC0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0x50\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0x30\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0x11\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillWindowPixelRect\n\t"
        "	cmp r6, #0xa\n\t"
        "	bne _0813ADC8\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _0813ADC4\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	b _0813ADE4\n\t"
        "	.align 2, 0\n\t"
        "_0813ADC0: .4byte gUnknown_203A82A\n\t"
        "_0813ADC4: .4byte gUnknown_8592CB0\n\t"
        "_0813ADC8:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _0813ADEC\n\t"
        "	lsls r1, r7, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "_0813ADE4:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813ADEC: .4byte gUnknown_8592C84\n\t"
        ".syntax divided\n\t"
    );
}

void CloseBattleFrontierTutorWindow(void)
{
    ClearStdWindowAndFrameToTransparent(gUnknown_203A82A, TRUE);
    RemoveWindow(gUnknown_203A82A);
}

__attribute__((naked)) void ScrollableMultichoice_RedrawPersistentMenu(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0x18\n\t"
        "	ldr r0, _0813AED8\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #0xff\n\t"
        "	beq _0813AEC8\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813AEDC\n\t"
        "	adds r6, r0, r1\n\t"
        "	ldrh r0, [r6, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #0x16\n\t"
        "	add r1, sp, #0x14\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl ListMenuGetScrollAndRow\n\t"
        "	ldrh r0, [r6, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	movs r5, #0\n\t"
        "	mov sb, r4\n\t"
        "	ldr r0, _0813AEE0\n\t"
        "	mov r8, r0\n\t"
        "	movs r4, #0\n\t"
        "_0813AE56:\n\t"
        "	ldrh r0, [r6, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	add r1, sp, #0x14\n\t"
        "	ldrh r2, [r1]\n\t"
        "	adds r2, r2, r5\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r1, _0813AEE4\n\t"
        "	ldrh r1, [r1]\n\t"
        "	lsls r1, r1, #6\n\t"
        "	adds r2, r2, r1\n\t"
        "	add r2, r8\n\t"
        "	ldr r2, [r2]\n\t"
        "	lsls r1, r5, #0x1c\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	str r1, [sp]\n\t"
        "	movs r7, #0xff\n\t"
        "	str r7, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	str r4, [sp, #0x10]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0xa\n\t"
        "	bl AddTextPrinterParameterized5\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _0813AE56\n\t"
        "	ldrh r0, [r6, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0813AEE8\n\t"
        "	mov r3, sb\n\t"
        "	ldrh r1, [r3]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	str r1, [sp]\n\t"
        "	str r7, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrh r0, [r6, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldrh r0, [r6, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "_0813AEC8:\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AED8: .4byte sub_0813A608 + 1\n\t"
        "_0813AEDC: .4byte gTasks\n\t"
        "_0813AEE0: .4byte gUnknown_859274C\n\t"
        "_0813AEE4: .4byte gSpecialVar_0x8004\n\t"
        "_0813AEE8: .4byte gText_SelectorArrow\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetBattleFrontierTutorMoveIndex(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	movs r1, #0\n\t"
        "	ldr r0, _0813AF30\n\t"
        "	strh r1, [r0]\n\t"
        "	ldr r0, _0813AF34\n\t"
        "	bl VarGet\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r0, _0813AF38\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0813AF50\n\t"
        "	movs r2, #0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	ldr r3, _0813AF3C\n\t"
        "	ldr r0, _0813AF40\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrh r1, [r0]\n\t"
        "_0813AF1A:\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0813AF44\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x1d\n\t"
        "	bls _0813AF1A\n\t"
        "	b _0813AF70\n\t"
        "	.align 2, 0\n\t"
        "_0813AF30: .4byte gSpecialVar_0x8005\n\t"
        "_0813AF34: .4byte 0x0000400E\n\t"
        "_0813AF38: .4byte 0x0000400D\n\t"
        "_0813AF3C: .4byte gUnknown_85E08C4\n\t"
        "_0813AF40: .4byte gUnknown_8592C68\n\t"
        "_0813AF44:\n\t"
        "	ldr r0, _0813AF4C\n\t"
        "	strh r2, [r0]\n\t"
        "	b _0813AF70\n\t"
        "	.align 2, 0\n\t"
        "_0813AF4C: .4byte gSpecialVar_0x8005\n\t"
        "_0813AF50:\n\t"
        "	movs r2, #0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	ldr r3, _0813AF78\n\t"
        "	ldr r0, _0813AF7C\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrh r1, [r0]\n\t"
        "_0813AF5C:\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0813AF44\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x1d\n\t"
        "	bls _0813AF5C\n\t"
        "_0813AF70:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AF78: .4byte gUnknown_85E08C4\n\t"
        "_0813AF7C: .4byte gUnknown_8592C54\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ScrollableMultichoice_ClosePersistentMenu(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _0813AFF4\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0xff\n\t"
        "	beq _0813AFEE\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r0, _0813AFF8\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x24]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl DestroyListMenuTask\n\t"
        "	ldr r0, _0813AFFC\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl Free\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrameToTransparent\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl RemoveWindow\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813AFEE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813AFF4: .4byte sub_0813A608 + 1\n\t"
        "_0813AFF8: .4byte gTasks\n\t"
        "_0813AFFC: .4byte gUnknown_203A830\n\t"
        ".syntax divided\n\t"
    );
}

void DoDeoxysRockInteraction(void)
{
    CreateTask(Task_DeoxysRockInteraction, 8);
}

__attribute__((naked)) void Task_DeoxysRockInteraction(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _0813B034\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B03C\n\t"
        "	ldr r1, _0813B038\n\t"
        "	movs r0, #3\n\t"
        "	b _0813B0A2\n\t"
        "	.align 2, 0\n\t"
        "_0813B034: .4byte 0x000008D4\n\t"
        "_0813B038: .4byte gSpecialVar_Result\n\t"
        "_0813B03C:\n\t"
        "	ldr r0, _0813B084\n\t"
        "	mov r8, r0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r4, _0813B088\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl VarSet\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0813B094\n\t"
        "	ldr r0, _0813B08C\n\t"
        "	subs r1, r5, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, r6\n\t"
        "	bhs _0813B094\n\t"
        "	movs r0, #0\n\t"
        "	bl ChangeDeoxysRockLevel\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0\n\t"
        "	bl VarSet\n\t"
        "	ldr r1, _0813B090\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	b _0813B0A8\n\t"
        "	.align 2, 0\n\t"
        "_0813B084: .4byte 0x00004035\n\t"
        "_0813B088: .4byte 0x00004034\n\t"
        "_0813B08C: .4byte sStoneMaxStepCounts\n\t"
        "_0813B090: .4byte gSpecialVar_Result\n\t"
        "_0813B094:\n\t"
        "	cmp r5, #0xa\n\t"
        "	bne _0813B0B8\n\t"
        "	ldr r0, _0813B0B0\n\t"
        "	bl FlagSet\n\t"
        "	ldr r1, _0813B0B4\n\t"
        "	movs r0, #2\n\t"
        "_0813B0A2:\n\t"
        "	strh r0, [r1]\n\t"
        "	bl ScriptContext_Enable\n\t"
        "_0813B0A8:\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _0813B0DA\n\t"
        "	.align 2, 0\n\t"
        "_0813B0B0: .4byte 0x000008D4\n\t"
        "_0813B0B4: .4byte gSpecialVar_Result\n\t"
        "_0813B0B8:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl ChangeDeoxysRockLevel\n\t"
        "	ldr r0, _0813B0E4\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl VarSet\n\t"
        "	ldr r1, _0813B0E8\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813B0DA:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B0E4: .4byte 0x00004035\n\t"
        "_0813B0E8: .4byte gSpecialVar_Result\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ChangeDeoxysRockLevel(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #5\n\t"
        "	ldr r1, _0813B120\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xd0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	movs r2, #8\n\t"
        "	bl LoadPalette\n\t"
        "	ldr r0, _0813B124\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	movs r0, #1\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	cmp r4, #0\n\t"
        "	bne _0813B128\n\t"
        "	movs r0, #0xc4\n\t"
        "	bl PlaySE\n\t"
        "	b _0813B130\n\t"
        "	.align 2, 0\n\t"
        "_0813B120: .4byte gUnknown_8592CDC\n\t"
        "_0813B124: .4byte gSaveBlock1Ptr\n\t"
        "_0813B128:\n\t"
        "	movs r0, #0x82\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlaySE\n\t"
        "_0813B130:\n\t"
        "	ldr r0, _0813B164\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	ldr r3, _0813B168\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [r3]\n\t"
        "	movs r0, #0x3a\n\t"
        "	str r0, [r3, #4]\n\t"
        "	movs r0, #0x1a\n\t"
        "	str r0, [r3, #8]\n\t"
        "	ldr r0, _0813B16C\n\t"
        "	lsls r2, r4, #1\n\t"
        "	adds r1, r2, r0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	str r1, [r3, #0xc]\n\t"
        "	adds r0, #1\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	str r0, [r3, #0x10]\n\t"
        "	adds r5, r2, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bne _0813B170\n\t"
        "	movs r0, #0x3c\n\t"
        "	b _0813B172\n\t"
        "	.align 2, 0\n\t"
        "_0813B164: .4byte WaitForDeoxysRockMovement + 1\n\t"
        "_0813B168: .4byte gFieldEffectArguments\n\t"
        "_0813B16C: .4byte gUnknown_8592E3C\n\t"
        "_0813B170:\n\t"
        "	movs r0, #5\n\t"
        "_0813B172:\n\t"
        "	str r0, [r3, #0x14]\n\t"
        "	movs r0, #0x42\n\t"
        "	bl FieldEffectStart\n\t"
        "	ldr r0, _0813B194\n\t"
        "	adds r1, r5, r0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	bl Overworld_SetEventObjTemplateCoords\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B194: .4byte gUnknown_8592E3C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void WaitForDeoxysRockMovement(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #0x42\n\t"
        "	bl FieldEffectActiveListContains\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B1B4\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813B1B4:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void IncrementBirthIslandRockStepCount(void)
{
    u16 stepCount = VarGet(VAR_DEOXYS_ROCK_STEP_COUNT);
    if (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR))
    {
        if (++stepCount > 99)
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, 0);
        else
            VarSet(VAR_DEOXYS_ROCK_STEP_COUNT, stepCount);
    }
}

__attribute__((naked)) void SetDeoxysRockPalette(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813B234\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x13\n\t"
        "	ldr r1, _0813B238\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xd0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	movs r2, #8\n\t"
        "	bl LoadPalette\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	movs r1, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	bl BlendPalettes\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B234: .4byte 0x00004035\n\t"
        "_0813B238: .4byte gUnknown_8592CDC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void set_unknown_box_id(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _0813B244\n\t"
        "	strb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0813B244: .4byte gUnknown_203A83B\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void get_unknown_box_id(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, _0813B250\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0813B250: .4byte gUnknown_203A83B\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813B254(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r5, _0813B288\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B290\n\t"
        "	bl StorageGetCurrentBox\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _0813B28C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0813B290\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl FlagSet\n\t"
        "	movs r0, #1\n\t"
        "	b _0813B292\n\t"
        "	.align 2, 0\n\t"
        "_0813B288: .4byte 0x000008D7\n\t"
        "_0813B28C: .4byte 0x00004036\n\t"
        "_0813B290:\n\t"
        "	movs r0, #0\n\t"
        "_0813B292:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813B298(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r0, _0813B2F0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl set_unknown_box_id\n\t"
        "	bl StorageGetCurrentBox\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_0813B2B0:\n\t"
        "	movs r5, #0\n\t"
        "	lsls r6, r4, #0x18\n\t"
        "	lsls r7, r4, #0x10\n\t"
        "_0813B2B6:\n\t"
        "	lsls r1, r5, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsrs r0, r6, #0x18\n\t"
        "	bl GetBoxedMonPtr\n\t"
        "	movs r1, #0xb\n\t"
        "	movs r2, #0\n\t"
        "	bl GetBoxMonData\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B2F8\n\t"
        "	bl get_unknown_box_id\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, r4\n\t"
        "	beq _0813B2DE\n\t"
        "	ldr r0, _0813B2F4\n\t"
        "	bl FlagClear\n\t"
        "_0813B2DE:\n\t"
        "	ldr r0, _0813B2F0\n\t"
        "	lsrs r1, r7, #0x10\n\t"
        "	bl VarSet\n\t"
        "	bl sub_0813B254\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0813B314\n\t"
        "	.align 2, 0\n\t"
        "_0813B2F0: .4byte 0x00004036\n\t"
        "_0813B2F4: .4byte 0x000008D7\n\t"
        "_0813B2F8:\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #0x1d\n\t"
        "	ble _0813B2B6\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #0xe\n\t"
        "	bne _0813B306\n\t"
        "	movs r4, #0\n\t"
        "_0813B306:\n\t"
        "	bl StorageGetCurrentBox\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	bne _0813B2B0\n\t"
        "	movs r0, #0\n\t"
        "_0813B314:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateAbnormalWeatherEvent(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r0, _0813B35C\n\t"
        "	movs r1, #0\n\t"
        "	bl VarSet\n\t"
        "	movs r0, #0xdf\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0813B378\n\t"
        "	ldr r0, _0813B360\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B368\n\t"
        "	ldr r0, _0813B364\n\t"
        "	movs r1, #7\n\t"
        "	ands r4, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #9\n\t"
        "	bl VarSet\n\t"
        "	b _0813B3A2\n\t"
        "	.align 2, 0\n\t"
        "_0813B35C: .4byte 0x00004038\n\t"
        "_0813B360: .4byte SPECIAL_ChooseItemsToTossFromPyramidBag\n\t"
        "_0813B364: .4byte 0x00004037\n\t"
        "_0813B368:\n\t"
        "	movs r0, #1\n\t"
        "	ands r4, r0\n\t"
        "	cmp r4, #0\n\t"
        "	bne _0813B38C\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "_0813B378:\n\t"
        "	ldr r0, _0813B388\n\t"
        "	movs r1, #7\n\t"
        "	ands r4, r1\n\t"
        "	adds r1, r4, #1\n\t"
        "	bl VarSet\n\t"
        "	b _0813B3A2\n\t"
        "	.align 2, 0\n\t"
        "_0813B388: .4byte 0x00004037\n\t"
        "_0813B38C:\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r0, _0813B3A8\n\t"
        "	movs r1, #7\n\t"
        "	ands r4, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #9\n\t"
        "	bl VarSet\n\t"
        "_0813B3A2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B3A8: .4byte 0x00004037\n\t"
        ".syntax divided\n\t"
    );
}

bool32 GetAbnormalWeatherMapNameAndType(void)
{
    u16 abnormalWeather = VarGet(VAR_ABNORMAL_WEATHER_LOCATION);

    GetMapName(gStringVar1, gUnknown_8592E5C[abnormalWeather - 1], 0);

    if (abnormalWeather < MARINE_CAVE_LOCATIONS_START)
        return FALSE;
    else
        return TRUE;
}

__attribute__((naked)) bool8 AbnormalWeatherHasExpired(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r5, _0813B438\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r0, _0813B43C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0813B4B4\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r0, _0813B440\n\t"
        "	cmp r4, r0\n\t"
        "	bls _0813B4AC\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl VarSet\n\t"
        "	ldr r0, _0813B444\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #4\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	cmp r0, #0x18\n\t"
        "	bne _0813B44C\n\t"
        "	movs r0, #5\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	cmp r0, #0x69\n\t"
        "	bgt _0813B44C\n\t"
        "	cmp r0, #0x65\n\t"
        "	blt _0813B44C\n\t"
        "	ldr r0, _0813B448\n\t"
        "	movs r1, #1\n\t"
        "	b _0813B4B0\n\t"
        "	.align 2, 0\n\t"
        "_0813B438: .4byte 0x00004038\n\t"
        "_0813B43C: .4byte 0x00004037\n\t"
        "_0813B440: .4byte 0x000003E7\n\t"
        "_0813B444: .4byte gSaveBlock1Ptr\n\t"
        "_0813B448: .4byte 0x00004039\n\t"
        "_0813B44C:\n\t"
        "	ldr r0, _0813B474\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #4\n\t"
        "	ldrsb r1, [r2, r1]\n\t"
        "	adds r3, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0813B47C\n\t"
        "	movs r0, #5\n\t"
        "	ldrsb r0, [r2, r0]\n\t"
        "	cmp r0, #0x34\n\t"
        "	beq _0813B46E\n\t"
        "	cmp r0, #0x34\n\t"
        "	blt _0813B47C\n\t"
        "	cmp r0, #0x38\n\t"
        "	bgt _0813B47C\n\t"
        "	cmp r0, #0x36\n\t"
        "	blt _0813B47C\n\t"
        "_0813B46E:\n\t"
        "	ldr r0, _0813B478\n\t"
        "	movs r1, #1\n\t"
        "	b _0813B4B0\n\t"
        "	.align 2, 0\n\t"
        "_0813B474: .4byte gSaveBlock1Ptr\n\t"
        "_0813B478: .4byte 0x00004039\n\t"
        "_0813B47C:\n\t"
        "	ldr r3, [r3]\n\t"
        "	movs r2, #5\n\t"
        "	ldrsb r2, [r3, r2]\n\t"
        "	ldr r1, _0813B49C\n\t"
        "	subs r0, r6, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0813B4A0\n\t"
        "	movs r0, #4\n\t"
        "	ldrsb r0, [r3, r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B4A0\n\t"
        "	movs r0, #1\n\t"
        "	b _0813B4B6\n\t"
        "	.align 2, 0\n\t"
        "_0813B49C: .4byte gUnknown_8592E6C\n\t"
        "_0813B4A0:\n\t"
        "	ldr r0, _0813B4A8\n\t"
        "	movs r1, #0\n\t"
        "	b _0813B4B0\n\t"
        "	.align 2, 0\n\t"
        "_0813B4A8: .4byte 0x00004037\n\t"
        "_0813B4AC:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "_0813B4B0:\n\t"
        "	bl VarSet\n\t"
        "_0813B4B4:\n\t"
        "	movs r0, #0\n\t"
        "_0813B4B6:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

void Unused_SetWeatherSunny(void)
{
    SetCurrentAndNextWeather(WEATHER_SUNNY);
}

u32 GetMartEmployeeObjectEventId(void)
{
    u8 i;
    for (i = 0; i < 12; i++)
    {
        if (gSaveBlock1Ptr->location.mapGroup == gUnknown_8592E7C[i * 3])
        {
            if (gSaveBlock1Ptr->location.mapNum == (gUnknown_8592E7C + 1)[i * 3])
                return (gUnknown_8592E7C + 2)[i * 3];
        }
    }
    return 1;
}

bool32 IsTrainerRegistered(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
    {
        if (FlagGet(TRAINER_REGISTERED_FLAGS_START + index) == TRUE)
            return TRUE;
    }
    return FALSE;
}

bool32 ShouldDistributeEonTicket(void)
{
    if (!VarGet(VAR_DISTRIBUTE_EON_TICKET))
        return FALSE;

    return TRUE;
}

__attribute__((naked)) void BattleTowerReconnectLink(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, _0813B590\n\t"
        "	ldr r1, _0813B594\n\t"
        "	ldr r0, [r1]\n\t"
        "	str r0, [r2]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _0813B598\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B58A\n\t"
        "	ldr r0, _0813B59C\n\t"
        "	movs r1, #5\n\t"
        "	bl CreateTask\n\t"
        "_0813B58A:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B590: .4byte gUnknown_203A83C\n\t"
        "_0813B594: .4byte gBattleTypeFlags\n\t"
        "_0813B598: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_0813B59C: .4byte Task_ReconnectWithLinkPlayers + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LinkRetireStatusWithBattleTowerPartner(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813B5B0\n\t"
        "	movs r1, #5\n\t"
        "	bl CreateTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B5B0: .4byte sub_0813B5B4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0813B5B4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _0813B5D8\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #9\n\t"
        "	bls _0813B5CE\n\t"
        "	b _0813B7FE\n\t"
        "_0813B5CE:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0813B5DC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B5D8: .4byte gTasks\n\t"
        "_0813B5DC: .4byte _0813B5E0\n\t"
        "_0813B5E0:\n\t"
        "	.4byte _0813B608\n\t"
        "	.4byte _0813B61C\n\t"
        "	.4byte _0813B64C\n\t"
        "	.4byte _0813B6EC\n\t"
        "	.4byte _0813B71C\n\t"
        "	.4byte _0813B760\n\t"
        "	.4byte _0813B79C\n\t"
        "	.4byte _0813B7AA\n\t"
        "	.4byte _0813B7BC\n\t"
        "	.4byte _0813B7E0\n\t"
        "_0813B608:\n\t"
        "	ldr r0, _0813B618\n\t"
        "	bl FuncIsActiveTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813B616\n\t"
        "	b _0813B7FE\n\t"
        "_0813B616:\n\t"
        "	b _0813B7C8\n\t"
        "	.align 2, 0\n\t"
        "_0813B618: .4byte Task_ReconnectWithLinkPlayers + 1\n\t"
        "_0813B61C:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0813B62A\n\t"
        "	b _0813B7FE\n\t"
        "_0813B62A:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B636\n\t"
        "	b _0813B7C8\n\t"
        "_0813B636:\n\t"
        "	bl BitmaskAllOtherLinkPlayers\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0813B648\n\t"
        "	movs r2, #2\n\t"
        "	bl SendBlock\n\t"
        "	b _0813B740\n\t"
        "	.align 2, 0\n\t"
        "_0813B648: .4byte gSpecialVar_0x8004\n\t"
        "_0813B64C:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	movs r1, #2\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0813B65A\n\t"
        "	b _0813B7FE\n\t"
        "_0813B65A:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813B666\n\t"
        "	b _0813B7C8\n\t"
        "_0813B666:\n\t"
        "	ldr r5, _0813B690\n\t"
        "	ldr r0, _0813B694\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #1\n\t"
        "	bl ResetBlockReceivedFlag\n\t"
        "	ldr r0, _0813B698\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B6A0\n\t"
        "	ldrh r1, [r5]\n\t"
        "	cmp r1, #1\n\t"
        "	bne _0813B6A0\n\t"
        "	ldr r0, _0813B69C\n\t"
        "	strh r1, [r0]\n\t"
        "	b _0813B7C8\n\t"
        "	.align 2, 0\n\t"
        "_0813B690: .4byte gSpecialVar_0x8005\n\t"
        "_0813B694: .4byte gBlockRecvBuffer\n\t"
        "_0813B698: .4byte gSpecialVar_0x8004\n\t"
        "_0813B69C: .4byte gSpecialVar_Result\n\t"
        "_0813B6A0:\n\t"
        "	ldr r0, _0813B6B8\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0813B6C4\n\t"
        "	ldr r0, _0813B6BC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B6C4\n\t"
        "	ldr r1, _0813B6C0\n\t"
        "	movs r0, #2\n\t"
        "	b _0813B6E4\n\t"
        "	.align 2, 0\n\t"
        "_0813B6B8: .4byte gSpecialVar_0x8004\n\t"
        "_0813B6BC: .4byte gSpecialVar_0x8005\n\t"
        "_0813B6C0: .4byte gSpecialVar_Result\n\t"
        "_0813B6C4:\n\t"
        "	ldrh r0, [r2]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B6E0\n\t"
        "	ldr r0, _0813B6D8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B6E0\n\t"
        "	ldr r1, _0813B6DC\n\t"
        "	movs r0, #3\n\t"
        "	b _0813B6E4\n\t"
        "	.align 2, 0\n\t"
        "_0813B6D8: .4byte gSpecialVar_0x8005\n\t"
        "_0813B6DC: .4byte gSpecialVar_Result\n\t"
        "_0813B6E0:\n\t"
        "	ldr r1, _0813B6E8\n\t"
        "	movs r0, #0\n\t"
        "_0813B6E4:\n\t"
        "	strh r0, [r1]\n\t"
        "	b _0813B7C8\n\t"
        "	.align 2, 0\n\t"
        "_0813B6E8: .4byte gSpecialVar_Result\n\t"
        "_0813B6EC:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0813B6FA\n\t"
        "	b _0813B7FE\n\t"
        "_0813B6FA:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B7C8\n\t"
        "	bl BitmaskAllOtherLinkPlayers\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0813B718\n\t"
        "	movs r2, #2\n\t"
        "	bl SendBlock\n\t"
        "	b _0813B740\n\t"
        "	.align 2, 0\n\t"
        "_0813B718: .4byte gSpecialVar_Result\n\t"
        "_0813B71C:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0813B7FE\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0813B7C8\n\t"
        "	ldr r1, _0813B754\n\t"
        "	ldr r0, _0813B758\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBlockReceivedFlag\n\t"
        "_0813B740:\n\t"
        "	ldr r1, _0813B75C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r0, #8]\n\t"
        "	b _0813B7FE\n\t"
        "	.align 2, 0\n\t"
        "_0813B754: .4byte gSpecialVar_Result\n\t"
        "_0813B758: .4byte gBlockRecvBuffer\n\t"
        "_0813B75C: .4byte gTasks\n\t"
        "_0813B760:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B784\n\t"
        "	ldr r0, _0813B77C\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0813B7C8\n\t"
        "	ldr r0, _0813B780\n\t"
        "	bl ShowFieldAutoScrollMessage\n\t"
        "	b _0813B7C8\n\t"
        "	.align 2, 0\n\t"
        "_0813B77C: .4byte gSpecialVar_Result\n\t"
        "_0813B780: .4byte 0x08226D61\n\t"
        "_0813B784:\n\t"
        "	ldr r0, _0813B794\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0813B7C8\n\t"
        "	ldr r0, _0813B798\n\t"
        "	bl ShowFieldAutoScrollMessage\n\t"
        "	b _0813B7C8\n\t"
        "	.align 2, 0\n\t"
        "_0813B794: .4byte gSpecialVar_Result\n\t"
        "_0813B798: .4byte 0x08226D61\n\t"
        "_0813B79C:\n\t"
        "	movs r0, #0\n\t"
        "	bl IsTextPrinterActive\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B7FE\n\t"
        "	b _0813B7C8\n\t"
        "_0813B7AA:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B7FE\n\t"
        "	bl SetLinkStandbyCallback\n\t"
        "	b _0813B7C8\n\t"
        "_0813B7BC:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813B7FE\n\t"
        "_0813B7C8:\n\t"
        "	ldr r0, _0813B7DC\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r1, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	b _0813B7FE\n\t"
        "	.align 2, 0\n\t"
        "_0813B7DC: .4byte gTasks\n\t"
        "_0813B7E0:\n\t"
        "	ldr r0, _0813B804\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B7EC\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "_0813B7EC:\n\t"
        "	ldr r0, _0813B808\n\t"
        "	ldr r1, _0813B80C\n\t"
        "	ldr r1, [r1]\n\t"
        "	str r1, [r0]\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813B7FE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B804: .4byte gWirelessCommType\n\t"
        "_0813B808: .4byte gBattleTypeFlags\n\t"
        "_0813B80C: .4byte gUnknown_203A83C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Script_DoRayquazaScene(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813B828\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B830\n\t"
        "	ldr r2, _0813B82C\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DoRayquazaScene\n\t"
        "	b _0813B83A\n\t"
        "	.align 2, 0\n\t"
        "_0813B828: .4byte gSpecialVar_0x8004\n\t"
        "_0813B82C: .4byte CB2_ReturnToFieldContinueScriptPlayMapMusic + 1\n\t"
        "_0813B830:\n\t"
        "	ldr r2, _0813B840\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl DoRayquazaScene\n\t"
        "_0813B83A:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B840: .4byte CB2_ReturnToFieldContinueScriptPlayMapMusic + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LoopWingFlapSE(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813B858\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	movs r0, #0x9d\n\t"
        "	bl PlaySE\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B858: .4byte Task_LoopWingFlapSE + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_LoopWingFlapSE(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813B8AC\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	ldr r0, _0813B8B0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0813B890\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	movs r0, #0x9d\n\t"
        "	bl PlaySE\n\t"
        "_0813B890:\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	ldr r0, _0813B8B4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0813B8A4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0813B8A4:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B8AC: .4byte gUnknown_3005B68\n\t"
        "_0813B8B0: .4byte gSpecialVar_0x8005\n\t"
        "_0813B8B4: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CloseBattlePikeCurtain(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0813B8E0\n\t"
        "	movs r1, #8\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0813B8E4\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	strh r2, [r1, #0xe]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B8E0: .4byte Task_CloseBattlePikeCurtain + 1\n\t"
        "_0813B8E4: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_CloseBattlePikeCurtain(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sb\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0813B994\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r0, #6\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r1]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r1, #6\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0813B986\n\t"
        "	movs r6, #0\n\t"
        "_0813B922:\n\t"
        "	movs r4, #0\n\t"
        "	lsls r3, r6, #3\n\t"
        "	mov sl, r3\n\t"
        "	adds r7, r6, #1\n\t"
        "	mov r8, r7\n\t"
        "_0813B92C:\n\t"
        "	ldr r0, _0813B998\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #6\n\t"
        "	movs r3, #2\n\t"
        "	ldrsh r1, [r1, r3]\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r1, #4\n\t"
        "	ldr r7, _0813B99C\n\t"
        "	adds r2, r4, r7\n\t"
        "	add r2, sl\n\t"
        "	movs r7, #6\n\t"
        "	ldrsh r3, [r5, r7]\n\t"
        "	lsls r3, r3, #5\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #2\n\t"
        "	bls _0813B92C\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #3\n\t"
        "	bls _0813B922\n\t"
        "	bl DrawWholeMapView\n\t"
        "	ldrh r0, [r5, #6]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #6]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0813B986\n\t"
        "	mov r0, sb\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "_0813B986:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B994: .4byte gUnknown_3005B68\n\t"
        "_0813B998: .4byte gSaveBlock1Ptr\n\t"
        "_0813B99C: .4byte SPECIAL_GetBattlePyramidHint\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetBattlePyramidHint(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r5, _0813B9D0\n\t"
        "	ldr r0, _0813B9D4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #7\n\t"
        "	bl __udivsi3\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrh r4, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x14\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	subs r4, r4, r1\n\t"
        "	strh r4, [r5]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813B9D0: .4byte gSpecialVar_Result\n\t"
        "_0813B9D4: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

void ResetHealLocationFromDewford(void)
{
    if (gSaveBlock1Ptr->lastHealLocation.mapGroup == MAP_GROUP(MAP_DEWFORD_TOWN) && gSaveBlock1Ptr->lastHealLocation.mapNum == MAP_NUM(MAP_DEWFORD_TOWN))
        SetLastHealLocationWarp(HEAL_LOCATION_PETALBURG_CITY);
}

__attribute__((naked)) bool8 InPokemonCenter()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _0813BA28\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #4\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	ldr r2, _0813BA2C\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldr r1, _0813BA30\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0813BA3E\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "_0813BA1E:\n\t"
        "	ldrh r0, [r2]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _0813BA34\n\t"
        "	movs r0, #1\n\t"
        "	b _0813BA40\n\t"
        "	.align 2, 0\n\t"
        "_0813BA28: .4byte gSaveBlock1Ptr\n\t"
        "_0813BA2C: .4byte gUnknown_8592E7C + 0x24\n\t"
        "_0813BA30: .4byte 0x0000FFFF\n\t"
        "_0813BA34:\n\t"
        "	adds r1, #2\n\t"
        "	adds r2, #2\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, r4\n\t"
        "	bne _0813BA1E\n\t"
        "_0813BA3E:\n\t"
        "	movs r0, #0\n\t"
        "_0813BA40:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void ResetFanClub(void)
{
    gSaveBlock1Ptr->vars[VAR_FANCLUB_FAN_COUNTER - VARS_START] = 0;
    gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = 0;
}

void TryLoseFansFromPlayTimeAfterLinkBattle(void)
{
    if (DidPlayerGetFirstFans())
    {
        TryLoseFansFromPlayTime();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
    }
}

void UpdateTrainerFanClubGameClear(void)
{
    if (!GET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS))
    {
        SetPlayerGotFirstFans();
        sub_0813BDBC();
        gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
        FlagClear(FLAG_HIDE_FANCLUB_OLD_LADY);
        FlagClear(FLAG_HIDE_FANCLUB_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LITTLE_BOY);
        FlagClear(FLAG_HIDE_FANCLUB_LADY);
        FlagClear(FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER);
        VarSet(VAR_LILYCOVE_FAN_CLUB_STATE, 1);
    }
}

u8 sub_0813BB14(u8 incrementId)
{
    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        if (GET_TRAINER_FAN_CLUB_COUNTER + sFanClubCounterIncrements[incrementId] > 19)
        {
            if (GetNumFansOfPlayerInTrainerFanClub() < 3)
            {
                sub_0813BBAC();
                CLEAR_TRAINER_FAN_CLUB_COUNTER;
            }
            else
            {
                SET_TRAINER_FAN_CLUB_COUNTER(20);
            }
        }
        else
        {
            INCR_TRAINER_FAN_CLUB_COUNTER(sFanClubCounterIncrements[incrementId]);
        }
    }

    return GET_TRAINER_FAN_CLUB_COUNTER;
}

u16 sub_0813BBAC(void)
{
    u8 i;
    u8 idx = 0;

    for (i = 0; i < ARRAY_COUNT(sFanClubGainOrder); i++)
    {
        if (!GET_TRAINER_FAN_CLUB_FLAG(sFanClubGainOrder[i]))
        {
            idx = i;
            if (Random() & 1)
            {
                SET_TRAINER_FAN_CLUB_FLAG(sFanClubGainOrder[idx]);
                return idx;
            }
        }
    }
    SET_TRAINER_FAN_CLUB_FLAG(sFanClubGainOrder[idx]);
    return idx;
}

u16 sub_0813BC38(void)
{
    u8 i;
    u8 idx = 0;

    if (GetNumFansOfPlayerInTrainerFanClub() == 1)
        return 0;

    for (i = 0; i < ARRAY_COUNT(sFanClubLossOrder); i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubLossOrder[i]))
        {
            idx = i;
            if (Random() & 1)
            {
                FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubLossOrder[idx]);
                return idx;
            }
        }
    }

    if (GET_TRAINER_FAN_CLUB_FLAG(sFanClubLossOrder[idx]))
        FLIP_TRAINER_FAN_CLUB_FLAG(sFanClubLossOrder[idx]);

    return idx;
}

u16 GetNumFansOfPlayerInTrainerFanClub(void)
{
    u8 i;
    u8 numFans = 0;

    for (i = 0; i < NUM_TRAINER_FAN_CLUB_MEMBERS; i++)
    {
        if (GET_TRAINER_FAN_CLUB_FLAG(i + FANCLUB_MEMBER1))
            numFans++;
    }

    return numFans;
}

void TryLoseFansFromPlayTime(void)
{
    u8 i = 0;
    if (gSaveBlock2Ptr->playTimeHours < 999)
    {
        while (TRUE)
        {
            if (GetNumFansOfPlayerInTrainerFanClub() < 5)
            {
                gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] = gSaveBlock2Ptr->playTimeHours;
                break;
            }
            else if (i == NUM_TRAINER_FAN_CLUB_MEMBERS)
            {
                break;
            }
            else if (gSaveBlock2Ptr->playTimeHours - gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] < 12)
            {
                return;
            }
            sub_0813BC38();
            gSaveBlock1Ptr->vars[VAR_FANCLUB_LOSE_FAN_TIMER - VARS_START] += 12;
            i++;
        }
    }
}

bool8 IsFanClubMemberFanOfPlayer(void)
{
    return GET_TRAINER_FAN_CLUB_FLAG(gSpecialVar_0x8004);
}

void sub_0813BDBC(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER6);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER1);
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_MEMBER3);
}

void BufferFanClubTrainerName(void)
{
    u8 whichLinkTrainer = 0;
    u8 whichNPCTrainer = 0;
    switch (gSpecialVar_0x8004)
    {
    case FANCLUB_MEMBER1:
        break;
    case FANCLUB_MEMBER2:
        break;
    case FANCLUB_MEMBER3:
        whichLinkTrainer = 0;
        whichNPCTrainer = 3;
        break;
    case FANCLUB_MEMBER4:
        whichLinkTrainer = 0;
        whichNPCTrainer = 1;
        break;
    case FANCLUB_MEMBER5:
        whichLinkTrainer = 1;
        whichNPCTrainer = 0;
        break;
    case FANCLUB_MEMBER6:
        whichLinkTrainer = 0;
        whichNPCTrainer = 4;
        break;
    case FANCLUB_MEMBER7:
        whichLinkTrainer = 1;
        whichNPCTrainer = 5;
        break;
    case FANCLUB_MEMBER8:
        break;
    }
    sub_0813BE68(&gSaveBlock1Ptr->linkBattleRecords, whichLinkTrainer, whichNPCTrainer);
}

void sub_0813BE68(struct LinkBattleRecords *linkRecords, u8 whichLinkTrainer, u8 whichNPCTrainer)
{
    struct LinkBattleRecord *record = &linkRecords->entries[whichLinkTrainer];
    if (record->name[0] == EOS)
    {
        switch (whichNPCTrainer)
        {
        case 0:
            StringCopy(gStringVar1, gText_Wallace);
            break;
        case 1:
            StringCopy(gStringVar1, gText_Steven);
            break;
        case 2:
            StringCopy(gStringVar1, gText_Brawly);
            break;
        case 3:
            StringCopy(gStringVar1, gText_Winona);
            break;
        case 4:
            StringCopy(gStringVar1, gText_Phoebe);
            break;
        case 5:
            StringCopy(gStringVar1, gText_Glacia);
            break;
        default:
            StringCopy(gStringVar1, gText_Wallace);
            break;
        }
    }
    else
    {
        StringCopyN(gStringVar1, record->name, PLAYER_NAME_LENGTH);
        gStringVar1[PLAYER_NAME_LENGTH] = EOS;
    }
}

void sub_0813BF34(void)
{
    if (VarGet(VAR_LILYCOVE_FAN_CLUB_STATE) == 2)
    {
        TryLoseFansFromPlayTimeAfterLinkBattle();
        if (gBattleOutcome == B_OUTCOME_WON)
            sub_0813BBAC();
        else
            sub_0813BC38();
    }
}

bool8 DidPlayerGetFirstFans(void)
{
    return GET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS);
}

void SetPlayerGotFirstFans(void)
{
    SET_TRAINER_FAN_CLUB_FLAG(FANCLUB_GOT_FIRST_FANS);
}

u8 Script_TryGainNewFanFromCounter(void)
{
    return sub_0813BB14(gSpecialVar_0x8004);
}


FIELD_SPECIALS_DATA const u8 gUnknown_8592BCC[] = {0x01, 0x67, 0x23, 0x08, 0x1C, 0x67, 0x23, 0x08, 0x3C, 0x67, 0x23, 0x08, 0x5C, 0x67, 0x23, 0x08, 0x7B, 0x67, 0x23, 0x08, 0x9A, 0x67, 0x23, 0x08, 0xB8, 0x67, 0x23, 0x08, 0xD7, 0x67, 0x23, 0x08, 0xF7, 0x67, 0x23, 0x08, 0x17, 0x68, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592BF8[] = {0x36, 0x68, 0x23, 0x08, 0x36, 0x68, 0x23, 0x08, 0x36, 0x68, 0x23, 0x08, 0x36, 0x68, 0x23, 0x08, 0x36, 0x68, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C10[] = {0x54, 0x68, 0x23, 0x08, 0x66, 0x68, 0x23, 0x08, 0x78, 0x68, 0x23, 0x08, 0x8A, 0x68, 0x23, 0x08, 0x9C, 0x68, 0x23, 0x08, 0xAE, 0x68, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C2C[] = {0xC1, 0x68, 0x23, 0x08, 0xE5, 0x68, 0x23, 0x08, 0x04, 0x69, 0x23, 0x08, 0x23, 0x69, 0x23, 0x08, 0x43, 0x69, 0x23, 0x08, 0x66, 0x69, 0x23, 0x08, 0x87, 0x69, 0x23, 0x08, 0xAA, 0x69, 0x23, 0x08, 0xCA, 0x69, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C54[] = {0x87, 0x00, 0x45, 0x00, 0x8A, 0x00, 0x05, 0x00, 0x19, 0x00, 0x22, 0x00, 0x9D, 0x00, 0x44, 0x00, 0x56, 0x00, 0x0E, 0x00};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C68[] = {0x6F, 0x00, 0xAD, 0x00, 0xBD, 0x00, 0x81, 0x00, 0xC4, 0x00, 0xCB, 0x00, 0xF4, 0x00, 0x08, 0x00, 0x09, 0x00, 0x07, 0x00};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C7C[] = {0x00, 0x01, 0x07, 0x0A, 0x06, 0x0F, 0x20, 0x00};
FIELD_SPECIALS_DATA const u8 gUnknown_8592C84[] = {0x0F, 0xA0, 0x23, 0x08, 0x2B, 0xA0, 0x23, 0x08, 0x49, 0xA0, 0x23, 0x08, 0x68, 0xA0, 0x23, 0x08, 0x85, 0xA0, 0x23, 0x08, 0xA2, 0xA0, 0x23, 0x08, 0xBF, 0xA0, 0x23, 0x08, 0xD9, 0xA0, 0x23, 0x08, 0xF2, 0xA0, 0x23, 0x08, 0x0D, 0xA1, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592CB0[] = {0x27, 0xA1, 0x23, 0x08, 0x3B, 0xA1, 0x23, 0x08, 0x58, 0xA1, 0x23, 0x08, 0x6D, 0xA1, 0x23, 0x08, 0x8E, 0xA1, 0x23, 0x08, 0xA6, 0xA1, 0x23, 0x08, 0xC2, 0xA1, 0x23, 0x08, 0xDA, 0xA1, 0x23, 0x08, 0xF5, 0xA1, 0x23, 0x08, 0x10, 0xA2, 0x23, 0x08, 0xC8, 0x93, 0x5C, 0x08};
FIELD_SPECIALS_DATA const u8 gUnknown_8592CDC[] = {0x0E, 0x53, 0xD6, 0x5A, 0x52, 0x4A, 0x6B, 0x31, 0xE7, 0x24, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x7B, 0x6F, 0x00, 0x00, 0x0E, 0x53, 0xD6, 0x56, 0x33, 0x46, 0x4C, 0x2D, 0xC7, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0xD7, 0x56, 0x14, 0x42, 0x2D, 0x29, 0xA8, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0xD8, 0x56, 0xF5, 0x3D, 0x0F, 0x25, 0xA9, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0xF9, 0x52, 0xD7, 0x39, 0x10, 0x21, 0x8A, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0xFA, 0x52, 0xD8, 0x39, 0xF2, 0x20, 0x8B, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0xFB, 0x52, 0xB9, 0x35, 0xD3, 0x1C, 0x6C, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0x1C, 0x4F, 0x9B, 0x31, 0xD4, 0x18, 0x4D, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0x1D, 0x4F, 0x7C, 0x2D, 0xB6, 0x14, 0x4E, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0x1E, 0x4F, 0x5D, 0x29, 0x97, 0x10, 0x2F, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x53, 0x3F, 0x4F, 0x5F, 0x29, 0x99, 0x10, 0x30, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
FIELD_SPECIALS_DATA const u8 gUnknown_8592E3C[] = {0x0F, 0x0C, 0x0B, 0x0E, 0x0F, 0x08, 0x13, 0x0E, 0x0C, 0x0B, 0x12, 0x0B, 0x0F, 0x0E, 0x0B, 0x0E, 0x13, 0x0E, 0x0F, 0x0F, 0x0F, 0x0A};
FIELD_SPECIALS_DATA const u8 sStoneMaxStepCounts[] = {0x04, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x06, 0x03, 0x03};
FIELD_SPECIALS_DATA const u8 gUnknown_8592E5C[] = {0x1D, 0x1D, 0x1E, 0x1E, 0x1F, 0x1F, 0x21, 0x21, 0x14, 0x14, 0x28, 0x28, 0x2A, 0x2A, 0x2C, 0x2C};
FIELD_SPECIALS_DATA const u8 gUnknown_8592E6C[] = {0x1D, 0x1D, 0x1E, 0x1E, 0x1F, 0x1F, 0x21, 0x21, 0x14, 0x14, 0x28, 0x28, 0x2A, 0x2A, 0x2C, 0x2C};
FIELD_SPECIALS_DATA const u8 gUnknown_8592E7C[] = {0x02, 0x04, 0x01, 0x04, 0x04, 0x01, 0x05, 0x00, 0x01, 0x06, 0x03, 0x01, 0x08, 0x06, 0x01, 0x09, 0x0D, 0x01, 0x0A, 0x07, 0x01, 0x0B, 0x07, 0x01, 0x0C, 0x04, 0x01, 0x0E, 0x05, 0x01, 0x0F, 0x04, 0x01, 0x1A, 0x37, 0x01};

FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_85926AC[] = {0x08, 0x6C, 0x23, 0x08, 0x60, 0x6C, 0x23, 0x08, 0xD0, 0x6C, 0x23, 0x08, 0xF3, 0x74, 0x23, 0x08, 0x57, 0x75, 0x23, 0x08, 0x95, 0x75, 0x23, 0x08, 0xD9, 0x75, 0x23, 0x08, 0xD9, 0x75, 0x23, 0x08, 0xD9, 0x75, 0x23, 0x08, 0x2C, 0x76, 0x23, 0x08, 0x2C, 0x76, 0x23, 0x08, 0x2C, 0x76, 0x23, 0x08, 0x4C, 0x6D, 0x23, 0x08, 0xA7, 0x6D, 0x23, 0x08, 0x27, 0x6E, 0x23, 0x08, 0xAF, 0x6E, 0x23, 0x08, 0x08, 0x6F, 0x23, 0x08, 0x66, 0x6F, 0x23, 0x08, 0x65, 0x72, 0x23, 0x08, 0xB8, 0x72, 0x23, 0x08, 0x30, 0x73, 0x23, 0x08, 0x11, 0x71, 0x23, 0x08, 0x6C, 0x71, 0x23, 0x08, 0xEB, 0x71, 0x23, 0x08, 0xD3, 0x6F, 0x23, 0x08, 0x2D, 0x70, 0x23, 0x08, 0x98, 0x70, 0x23, 0x08, 0xA4, 0x73, 0x23, 0x08, 0xFE, 0x73, 0x23, 0x08, 0x70, 0x74, 0x23, 0x08};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592724[] = {0x15, 0x38, 0x15, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x04, 0x07, 0x15, 0x07, 0x15, 0x0E, 0x1C, 0x0D, 0x70, 0x07, 0x38};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592738[] = {0x07, 0x00, 0x0E, 0x00, 0x15, 0x00, 0x1C, 0x00, 0x23, 0x00, 0x31, 0x00, 0x3F, 0x00, 0x4D, 0x00, 0x5B, 0x00, 0x00, 0x00};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_859274C[] = {0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xB0, 0x5C, 0x08, 0x48, 0xB0, 0x5C, 0x08, 0x50, 0xB0, 0x5C, 0x08, 0x58, 0xB0, 0x5C, 0x08, 0x60, 0xB0, 0x5C, 0x08, 0x68, 0xB0, 0x5C, 0x08, 0x6F, 0xB0, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0xBF, 0x5C, 0x08, 0xF5, 0xBF, 0x5C, 0x08, 0xFB, 0xBF, 0x5C, 0x08, 0x01, 0xC0, 0x5C, 0x08, 0x07, 0xC0, 0x5C, 0x08, 0x0D, 0xC0, 0x5C, 0x08, 0x13, 0xC0, 0x5C, 0x08, 0x19, 0xC0, 0x5C, 0x08, 0x1F, 0xC0, 0x5C, 0x08, 0x25, 0xC0, 0x5C, 0x08, 0x2B, 0xC0, 0x5C, 0x08, 0x31, 0xC0, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0xC0, 0x5C, 0x08, 0x44, 0xC0, 0x5C, 0x08, 0x53, 0xC0, 0x5C, 0x08, 0x62, 0xC0, 0x5C, 0x08, 0x71, 0xC0, 0x5C, 0x08, 0x80, 0xC0, 0x5C, 0x08, 0x8F, 0xC0, 0x5C, 0x08, 0x9E, 0xC0, 0x5C, 0x08, 0xAD, 0xC0, 0x5C, 0x08, 0xBC, 0xC0, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCB, 0xC0, 0x5C, 0x08, 0xDA, 0xC0, 0x5C, 0x08, 0xE9, 0xC0, 0x5C, 0x08, 0xF8, 0xC0, 0x5C, 0x08, 0x07, 0xC1, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0xC1, 0x5C, 0x08, 0x25, 0xC1, 0x5C, 0x08, 0x34, 0xC1, 0x5C, 0x08, 0x43, 0xC1, 0x5C, 0x08, 0x52, 0xC1, 0x5C, 0x08, 0x61, 0xC1, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xC1, 0x5C, 0x08, 0x7F, 0xC1, 0x5C, 0x08, 0x8E, 0xC1, 0x5C, 0x08, 0x9D, 0xC1, 0x5C, 0x08, 0xAC, 0xC1, 0x5C, 0x08, 0xBB, 0xC1, 0x5C, 0x08, 0xCA, 0xC1, 0x5C, 0x08, 0xD9, 0xC1, 0x5C, 0x08, 0xE8, 0xC1, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCB, 0xB0, 0x5C, 0x08, 0xDB, 0xB0, 0x5C, 0x08, 0xEB, 0xB0, 0x5C, 0x08, 0xFB, 0xB0, 0x5C, 0x08, 0x0B, 0xB1, 0x5C, 0x08, 0x1B, 0xB1, 0x5C, 0x08, 0x2B, 0xB1, 0x5C, 0x08, 0x3B, 0xB1, 0x5C, 0x08, 0x4B, 0xB1, 0x5C, 0x08, 0x5B, 0xB1, 0x5C, 0x08, 0x6B, 0xB1, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0xC4, 0x5C, 0x08, 0x2A, 0xC4, 0x5C, 0x08, 0x31, 0xC4, 0x5C, 0x08, 0x42, 0xC4, 0x5C, 0x08, 0x38, 0xC4, 0x5C, 0x08, 0x4A, 0xC4, 0x5C, 0x08, 0x52, 0xC4, 0x5C, 0x08, 0x7B, 0xB1, 0x5C, 0x08, 0x84, 0xB1, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0xC1, 0x5C, 0x08, 0x05, 0xC2, 0x5C, 0x08, 0x13, 0xC2, 0x5C, 0x08, 0x21, 0xC2, 0x5C, 0x08, 0x2F, 0xC2, 0x5C, 0x08, 0x3D, 0xC2, 0x5C, 0x08, 0x4B, 0xC2, 0x5C, 0x08, 0x59, 0xC2, 0x5C, 0x08, 0x67, 0xC2, 0x5C, 0x08, 0x75, 0xC2, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xC2, 0x5C, 0x08, 0x91, 0xC2, 0x5C, 0x08, 0x9F, 0xC2, 0x5C, 0x08, 0xAD, 0xC2, 0x5C, 0x08, 0xBB, 0xC2, 0x5C, 0x08, 0xC9, 0xC2, 0x5C, 0x08, 0xD7, 0xC2, 0x5C, 0x08, 0xE5, 0xC2, 0x5C, 0x08, 0xF3, 0xC2, 0x5C, 0x08, 0x01, 0xC3, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xB1, 0x5C, 0x08, 0x23, 0xAC, 0x5C, 0x08, 0xF1, 0xAD, 0x5C, 0x08, 0x0B, 0xAE, 0x5C, 0x08, 0xF9, 0xAD, 0x5C, 0x08, 0x02, 0xAE, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0xAF, 0x5C, 0x08, 0x6C, 0xAF, 0x5C, 0x08, 0x75, 0xAF, 0x5C, 0x08, 0x7F, 0xAF, 0x5C, 0x08, 0x87, 0xAF, 0x5C, 0x08, 0x93, 0xAF, 0x5C, 0x08, 0xC8, 0x93, 0x5C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592A8C[] = {0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0x07, 0x64, 0x00, 0x00, 0x00};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592A9C[] = {0x47, 0x90, 0x23, 0x08, 0x7B, 0x90, 0x23, 0x08, 0xB5, 0x90, 0x23, 0x08, 0xF5, 0x90, 0x23, 0x08, 0x29, 0x91, 0x23, 0x08, 0x62, 0x91, 0x23, 0x08, 0xA0, 0x91, 0x23, 0x08, 0xD4, 0x91, 0x23, 0x08, 0x0E, 0x92, 0x23, 0x08, 0x4D, 0x92, 0x23, 0x08, 0x83, 0x92, 0x23, 0x08, 0xBD, 0x92, 0x23, 0x08, 0xF1, 0x92, 0x23, 0x08, 0x27, 0x93, 0x23, 0x08, 0xA0, 0x91, 0x23, 0x08, 0x65, 0x93, 0x23, 0x08, 0x99, 0x93, 0x23, 0x08, 0xA0, 0x91, 0x23, 0x08, 0xD1, 0x93, 0x23, 0x08, 0x05, 0x94, 0x23, 0x08, 0x3B, 0x94, 0x23, 0x08, 0x6F, 0x94, 0x23, 0x08, 0xA8, 0x94, 0x23, 0x08, 0xE2, 0x94, 0x23, 0x08, 0xA0, 0x91, 0x23, 0x08};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592B00[] = {0xB5, 0x7A, 0x23, 0x08, 0x0D, 0x7B, 0x23, 0x08, 0x64, 0x7B, 0x23, 0x08, 0xBB, 0x7B, 0x23, 0x08, 0x1B, 0x7C, 0x23, 0x08, 0x7A, 0x7C, 0x23, 0x08, 0xDB, 0x7C, 0x23, 0x08, 0x3B, 0x7D, 0x23, 0x08, 0x93, 0x7D, 0x23, 0x08, 0xEA, 0x7D, 0x23, 0x08, 0x47, 0x7E, 0x23, 0x08, 0xA0, 0x7E, 0x23, 0x08};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592B30[] = {0xD4, 0x7F, 0x23, 0x08, 0x2A, 0x80, 0x23, 0x08, 0x7F, 0x80, 0x23, 0x08, 0xD4, 0x80, 0x23, 0x08, 0x2D, 0x81, 0x23, 0x08, 0x85, 0x81, 0x23, 0x08, 0xDF, 0x81, 0x23, 0x08, 0x38, 0x82, 0x23, 0x08, 0x8E, 0x82, 0x23, 0x08, 0xE3, 0x82, 0x23, 0x08, 0x39, 0x83, 0x23, 0x08, 0x8B, 0x83, 0x23, 0x08};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592B60[] = {0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x04, 0x01, 0x04, 0x00, 0x02, 0x01, 0x02, 0x00, 0x03, 0x00, 0x05, 0x00, 0x06};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592B78[] = {0x00, 0x01, 0x01, 0x09, 0x02, 0x0F, 0x08, 0x00};
FIELD_SPECIALS_DATA_EARLY const u8 gUnknown_8592B80[] = {0x00, 0x02, 0x09, 0x04, 0x04, 0x0F, 0x1A, 0x00};
