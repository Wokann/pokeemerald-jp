#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "starter_choose.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "constants/rgb.h"

#define STARTER_MON_COUNT   3

// Position of the sprite of the selected starter PokÃ©mon
#define STARTER_PKMN_POS_X (DISPLAY_WIDTH / 2)
#define STARTER_PKMN_POS_Y 64

#define TAG_POKEBALL_SELECT 0x1000
#define TAG_STARTER_CIRCLE  0x1001

// JP note: the EWRAM window id and all static tables live in the JP ROM
// data region; they are bound via ld aliases using the sStarter* names so
// they do not clash with the sTextColors/sWindowTemplates aliases of other
// modules.
extern u16 sStarterLabelWindowId;
extern const u16 sStarterMon[];
extern const struct BgTemplate sStarterBgTemplates[];
extern const struct WindowTemplate sStarterWindowTemplates[];
extern const u8 sStarterPokeballCoords[][2];
extern const u8 sStarterLabelCoords[][2];
extern const u8 sStarterTextColors[];
extern const u8 sStarterCursorCoords[][2];
extern const struct WindowTemplate sStarterWindowTemplate_ConfirmStarter;
extern const struct WindowTemplate sStarterWindowTemplate_StarterLabel;
extern const struct CompressedSpriteSheet sStarterSpriteSheet_PokeballSelect[];
extern const struct CompressedSpriteSheet sStarterSpriteSheet_StarterCircle[];
extern const struct SpritePalette sStarterSpritePalettes[];
extern const struct SpriteTemplate sStarterSpriteTemplate_Hand;
extern const struct SpriteTemplate sStarterSpriteTemplate_Pokeball;
extern const struct SpriteTemplate sStarterSpriteTemplate_StarterCircle;
extern const union AffineAnimCmd *const sStarterAffineAnims_StarterPokemon[];
// JP note: the JP yes/no menu entry (menu_helpers asm, 0x08198D44) takes
// (window, u8 mode, u16 tileNum, u8 paletteNum), unlike the US
// CreateYesNoMenu signature.
extern void sub_08198D44(const struct WindowTemplate *window, u8 mode, u16 tileNum, u8 paletteNum);

static void CB2_StarterChoose(void);
void CreateStarterPokemonLabel(u8 selection);
static void ClearStarterLabel(void);
static void Task_StarterChoose(u8 taskId);
static void Task_HandleStarterChooseInput(u8 taskId);
static void Task_WaitForStarterSprite(u8 taskId);
static void Task_AskConfirmStarter(u8 taskId);
static void Task_HandleConfirmStarterInput(u8 taskId);
static void Task_DeclineStarter(u8 taskId);
static void Task_MoveStarterChooseCursor(u8 taskId);
static void Task_CreateStarterLabel(u8 taskId);
static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y);
static void SpriteCB_SelectionHand(struct Sprite *sprite);
static void SpriteCB_Pokeball(struct Sprite *sprite);
static void SpriteCB_StarterPokemon(struct Sprite *sprite);

// JP note: CreateStarterPokemonLabel has JP-specific Japanese-text handling
// (category-name pointer helper, 6-byte species names, 9-wide label window)
// whose register allocation agbcc cannot reproduce byte-for-byte; it stays
// in asm/starter_choose_label.s.

// Data for Task_StarterChoose
#define tStarterSelection   data[0]
#define tPkmnSpriteId       data[1]
#define tCircleSpriteId     data[2]

// Data for sSpriteTemplate_Pokeball
#define sTaskId data[0]
#define sBallId data[1]

// .text
u16 GetStarterPokemon(u16 chosenStarterId)
{
    if (chosenStarterId > STARTER_MON_COUNT)
        chosenStarterId = 0;
    return sStarterMon[chosenStarterId];
}

static void VblankCB_StarterChoose(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_ChooseStarter(void)
{
    u8 taskId;
    u8 spriteId;

    SetVBlankCallback(NULL);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);

    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);

    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);

    LZ77UnCompVram(gBirchBagGrass_Gfx, (void *)VRAM);
    LZ77UnCompVram(gBirchBagTilemap, (void *)(BG_SCREEN_ADDR(6)));
    LZ77UnCompVram(gBirchGrassTilemap, (void *)(BG_SCREEN_ADDR(7)));

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sStarterBgTemplates, 3);
    InitWindows(sStarterWindowTemplates);

    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x298, BG_PLTT_ID(13));
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(gBirchBagGrass_Pal, BG_PLTT_ID(0), 0x40);
    LoadCompressedSpriteSheet(&sStarterSpriteSheet_PokeballSelect[0]);
    LoadCompressedSpriteSheet(&sStarterSpriteSheet_StarterCircle[0]);
    LoadSpritePalettes(sStarterSpritePalettes);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);

    EnableInterrupts(DISPSTAT_VBLANK);
    SetVBlankCallback(VblankCB_StarterChoose);
    SetMainCallback2(CB2_StarterChoose);

    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 7);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    taskId = CreateTask(Task_StarterChoose, 0);
    gTasks[taskId].tStarterSelection = 1;

    // Create hand sprite
    spriteId = CreateSprite(&sStarterSpriteTemplate_Hand, 120, 56, 2);
    gSprites[spriteId].data[0] = taskId;

    // Create three PokÃ© Ball sprites
    spriteId = CreateSprite(&sStarterSpriteTemplate_Pokeball, sStarterPokeballCoords[0][0], sStarterPokeballCoords[0][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 0;

    spriteId = CreateSprite(&sStarterSpriteTemplate_Pokeball, sStarterPokeballCoords[1][0], sStarterPokeballCoords[1][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 1;

    spriteId = CreateSprite(&sStarterSpriteTemplate_Pokeball, sStarterPokeballCoords[2][0], sStarterPokeballCoords[2][1], 2);
    gSprites[spriteId].sTaskId = taskId;
    gSprites[spriteId].sBallId = 2;

    sStarterLabelWindowId = WINDOW_NONE;
}

static void CB2_StarterChoose(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Task_StarterChoose(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 0x298, 0xD);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_BirchInTrouble, 0, 2, 0, NULL);
    PutWindowTilemap(0);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = Task_HandleStarterChooseInput;
}

static void Task_HandleStarterChooseInput(u8 taskId)
{
    u8 selection = gTasks[taskId].tStarterSelection;

    if (JOY_NEW(A_BUTTON))
    {
        u8 spriteId;

        ClearStarterLabel();

        // Create white circle background
        spriteId = CreateSprite(&sStarterSpriteTemplate_StarterCircle, sStarterPokeballCoords[selection][0], sStarterPokeballCoords[selection][1], 1);
        gTasks[taskId].tCircleSpriteId = spriteId;

        // Create PokÃ©mon sprite
        spriteId = CreatePokemonFrontSprite(GetStarterPokemon(gTasks[taskId].tStarterSelection), sStarterPokeballCoords[selection][0], sStarterPokeballCoords[selection][1]);
        gSprites[spriteId].affineAnims = sStarterAffineAnims_StarterPokemon;
        gSprites[spriteId].callback = SpriteCB_StarterPokemon;

        gTasks[taskId].tPkmnSpriteId = spriteId;
        gTasks[taskId].func = Task_WaitForStarterSprite;
    }
    else if (JOY_NEW(DPAD_LEFT) && selection > 0)
    {
        gTasks[taskId].tStarterSelection--;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
    else if (JOY_NEW(DPAD_RIGHT) && selection < STARTER_MON_COUNT - 1)
    {
        gTasks[taskId].tStarterSelection++;
        gTasks[taskId].func = Task_MoveStarterChooseCursor;
    }
}

static void Task_WaitForStarterSprite(u8 taskId)
{
    if (gSprites[gTasks[taskId].tCircleSpriteId].affineAnimEnded &&
        gSprites[gTasks[taskId].tCircleSpriteId].x == STARTER_PKMN_POS_X &&
        gSprites[gTasks[taskId].tCircleSpriteId].y == STARTER_PKMN_POS_Y)
    {
        gTasks[taskId].func = Task_AskConfirmStarter;
    }
}

static void Task_AskConfirmStarter(u8 taskId)
{
    PlayCry_Normal(GetStarterPokemon(gTasks[taskId].tStarterSelection), 0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ConfirmStarterChoice, 0, 2, 0, NULL);
    ScheduleBgCopyTilemapToVram(0);
    sub_08198D44(&sStarterWindowTemplate_ConfirmStarter, 1, 0x298, 0xD);
    gTasks[taskId].func = Task_HandleConfirmStarterInput;
}

static void Task_HandleConfirmStarterInput(u8 taskId)
{
    u8 spriteId;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:  // YES
        // Return the starter choice and exit.
        gSpecialVar_Result = gTasks[taskId].tStarterSelection;
        ResetAllPicSprites();
        SetMainCallback2(gMain.savedCallback);
        break;
    case 1:  // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        spriteId = gTasks[taskId].tPkmnSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        FreeAndDestroyMonPicSprite(spriteId);

        spriteId = gTasks[taskId].tCircleSpriteId;
        FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
        DestroySprite(&gSprites[spriteId]);
        gTasks[taskId].func = Task_DeclineStarter;
        break;
    }
}

static void Task_DeclineStarter(u8 taskId)
{
    gTasks[taskId].func = Task_StarterChoose;
}

static void ClearStarterLabel(void)
{
    FillWindowPixelBuffer(sStarterLabelWindowId, PIXEL_FILL(0));
    ClearWindowTilemap(sStarterLabelWindowId);
    RemoveWindow(sStarterLabelWindowId);
    sStarterLabelWindowId = WINDOW_NONE;
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_MoveStarterChooseCursor(u8 taskId)
{
    ClearStarterLabel();
    gTasks[taskId].func = Task_CreateStarterLabel;
}

static void Task_CreateStarterLabel(u8 taskId)
{
    CreateStarterPokemonLabel(gTasks[taskId].tStarterSelection);
    gTasks[taskId].func = Task_HandleStarterChooseInput;
}

static u8 CreatePokemonFrontSprite(u16 species, u8 x, u8 y)
{
    u8 spriteId;

    spriteId = CreateMonPicSprite_Affine(species, SHINY_ODDS, 0, MON_PIC_AFFINE_FRONT, x, y, 14, TAG_NONE);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

static void SpriteCB_SelectionHand(struct Sprite *sprite)
{
    // Float up and down above selected PokÃ© Ball
    sprite->x = sStarterCursorCoords[gTasks[sprite->data[0]].tStarterSelection][0];
    sprite->y = sStarterCursorCoords[gTasks[sprite->data[0]].tStarterSelection][1];
    sprite->y2 = Sin(sprite->data[1], 8);
    sprite->data[1] = (u8)(sprite->data[1]) + 4;
}

static void SpriteCB_Pokeball(struct Sprite *sprite)
{
    // Animate PokÃ© Ball if currently selected
    if (gTasks[sprite->sTaskId].tStarterSelection == sprite->sBallId)
        StartSpriteAnimIfDifferent(sprite, 1);
    else
        StartSpriteAnimIfDifferent(sprite, 0);
}

static void SpriteCB_StarterPokemon(struct Sprite *sprite)
{
    // Move sprite to upper center of screen
    if (sprite->x > STARTER_PKMN_POS_X)
        sprite->x -= 4;
    if (sprite->x < STARTER_PKMN_POS_X)
        sprite->x += 4;
    if (sprite->y > STARTER_PKMN_POS_Y)
        sprite->y -= 2;
    if (sprite->y < STARTER_PKMN_POS_Y)
        sprite->y += 2;
}

#undef tStarterSelection
#undef tPkmnSpriteId
#undef tCircleSpriteId
#undef sTaskId
#undef sBallId

__attribute__((naked)) void CreateStarterPokemonLabel(u8 selection)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x30\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetStarterPokemon\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl HoennToNationalOrder\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl sub_080BFB68\n\t"
        "	adds r2, r0, #0\n\t"
        "	movs r3, #0\n\t"
        "	movs r5, #0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	add r1, sp, #0x18\n\t"
        "	mov sl, r1\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #0x24\n\t"
        "	str r1, [sp, #0x2c]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081344E2\n\t"
        "_081344BE:\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081344E2\n\t"
        "	cmp r3, #4\n\t"
        "	bls _081344BE\n\t"
        "_081344E2:\n\t"
        "	movs r3, #0\n\t"
        "	ldr r2, _0813462C\n\t"
        "	mov r8, r2\n\t"
        "	lsls r4, r7, #1\n\t"
        "	ldr r0, _08134630\n\t"
        "	mov sb, r0\n\t"
        "	lsls r6, r6, #1\n\t"
        "	mov ip, r6\n\t"
        "	ldr r2, _08134634\n\t"
        "_081344F4:\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r3, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r3, #4\n\t"
        "	bls _081344F4\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, #0xc\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r3, #0\n\t"
        "	movs r5, #0\n\t"
        "	adds r0, r4, r7\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08134558\n\t"
        "	mov r6, r8\n\t"
        "	mov r8, sl\n\t"
        "_0813452E:\n\t"
        "	mov r1, r8\n\t"
        "	adds r2, r1, r5\n\t"
        "	adds r1, r4, r7\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r3, r1\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r1, r3, r1\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08134558\n\t"
        "	cmp r3, #9\n\t"
        "	bls _0813452E\n\t"
        "_08134558:\n\t"
        "	mov r2, sl\n\t"
        "	adds r1, r2, r5\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r2, sb\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r2, #4]\n\t"
        "	str r0, [sp, #0x24]\n\t"
        "	str r1, [sp, #0x28]\n\t"
        "	ldr r0, _08134638\n\t"
        "	add r0, ip\n\t"
        "	mov sb, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ldr r1, _0813463C\n\t"
        "	ldr r2, [sp, #0x24]\n\t"
        "	ands r2, r1\n\t"
        "	orrs r2, r0\n\t"
        "	str r2, [sp, #0x24]\n\t"
        "	ldr r1, _08134638\n\t"
        "	adds r1, #1\n\t"
        "	mov r8, r1\n\t"
        "	add r8, ip\n\t"
        "	mov r0, r8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	ldr r0, _08134640\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [sp, #0x24]\n\t"
        "	ldr r0, [sp, #0x2c]\n\t"
        "	bl AddWindow\n\t"
        "	ldr r4, _08134644\n\t"
        "	strh r0, [r4]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r6, _08134648\n\t"
        "	str r6, [sp]\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp, #4]\n\t"
        "	add r1, sp, #0xc\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldrb r0, [r4]\n\t"
        "	str r6, [sp]\n\t"
        "	str r5, [sp, #4]\n\t"
        "	mov r2, sl\n\t"
        "	str r2, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x12\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	movs r0, #0\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	mov r0, sb\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #0x1b\n\t"
        "	movs r2, #0xfc\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r1, #9\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, #4\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	mov r2, r8\n\t"
        "	ldrb r4, [r2]\n\t"
        "	lsls r5, r4, #0x1b\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	adds r4, #4\n\t"
        "	lsls r4, r4, #0x1b\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsrs r1, r1, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	lsls r5, r5, #8\n\t"
        "	orrs r5, r4\n\t"
        "	movs r0, #0x44\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	add sp, #0x30\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813462C: .4byte gSpeciesNames\n\t"
        "_08134630: .4byte 0x08590BF4\n\t"
        "_08134634: .4byte 0x085C9393\n\t"
        "_08134638: .4byte 0x08590C02\n\t"
        "_0813463C: .4byte 0xFFFF00FF\n\t"
        "_08134640: .4byte 0xFF00FFFF\n\t"
        "_08134644: .4byte gUnknown_30011F8\n\t"
        "_08134648: .4byte 0x08590C1C\n\t"
        ".syntax divided\n\t"
    );
}

