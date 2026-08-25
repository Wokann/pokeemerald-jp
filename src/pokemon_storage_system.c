#include "global.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "malloc.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fldeff_misc.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "mail.h"
#include "main.h"
#include "menu.h"
#include "mon_markings.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pc_screen_effect.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "util.h"
#include "window.h"

extern u8 sCurrentBoxOption;
extern u8 gUnknown_20399A0;
u8 GetCurrentBoxOption(void);
void EnterPokeStorage(u8 boxOption);
extern bool8 gUnknown_20399AC;
extern u8 gUnknown_20399AE;
extern const u8 gUnknown_8556618[];
extern const u8 gUnknown_8556620[];
extern const u16 gUnknown_854C754[];
extern const u16 gUnknown_854C76C[];
extern const u8 gUnknown_85564E0[];
extern const u8 gUnknown_85564F8[];
extern const struct SpriteTemplate gUnknown_855654C;
extern const struct SpriteTemplate gUnknown_8556564;
extern const u32 gUnknown_854BBFC[];
extern const u32 gUnknown_854BC94[];
extern const u32 gUnknown_854BF9C[];
extern const u32 gUnknown_854BDC0[];
extern const struct BgTemplate gUnknown_854C9E4[];
extern const u16 gUnknown_854BEFC[];
extern const u16 gUnknown_854BF1C[];
extern const u16 gUnknown_854BF5C[];
extern const u16 gUnknown_854BF7C[];
extern const u16 gUnknown_854C9A4[];
extern const u16 gUnknown_854BF3C[];
extern const u32 gUnknown_854C65C[];
extern const u16 gUnknown_854C70C[];
extern const struct SpriteSheet gUnknown_854C9FC;
extern const struct SpriteTemplate gUnknown_854CB6C;
extern const struct SpriteTemplate gUnknown_854CA04;
extern const struct Wallpaper gUnknown_8551868[];
extern const struct Wallpaper gUnknown_8555A40[];
extern const u8 *const gUnknown_8555B00[];
extern u8 gUnknown_3000F78[];
extern u16 gUnknown_2037434[];
extern const u8 gUnknown_855676C[];
extern const u8 *const gUnknown_855657C[];
extern const struct InputFunc gUnknown_85564B8[] __attribute__((aligned(4)));
struct UnkUtil;
struct UnkUtilData;
extern const u8 *GetMovingItemName(void);
extern u32 GetWaldaWallpaperPatternId(void);
extern u32 GetWaldaWallpaperIconId(void);
extern u16 *GetWaldaWallpaperColorsPtr(void);
extern void sub_080CC2B0(const void *tilemap, s8 direction, u8 offset);
extern void sub_080CC354(void *tilemap);
extern void LoadCursorMonSprite(void);
extern void sub_080C99C8(void);
extern void sub_080C9A38(void);
extern void RefreshCursorMonData(void);
extern void LoadCursorMonGfx(u16 species, u32 personality);
extern void PrintCursorMonInfo(void);
extern void sub_080C9EC0(void);
extern void sub_080C9B44(struct Sprite *sprite);
extern void sub_080D1EE4(u8 id, u8 bg, const void *tilemap, u16 width, u16 height);
extern void sub_080D2010(u8 id, u16 x, u16 y);
extern void sub_080D1E3C(u8 count);
extern const u8 gUnknown_854BEBC[];
extern const u8 gUnknown_854B234[];
extern const u8 gUnknown_854B258[];
extern const u16 gUnknown_854B25C[];
extern const u8 gUnknown_854B27C[];
extern const u8 gUnknown_854BA7C[];
extern const u8 gUnknown_85CB584[];
struct PokemonStorageMenuText
{
    const u8 *text;
    const u8 *desc;
};

extern const struct PokemonStorageMenuText gUnknown_854B1E4[];
extern const struct WindowTemplate gUnknown_854B20C[];
extern const u8 gUnknown_85CB534[];
extern const u8 gUnknown_85CB55C[];
extern void UnkUtil_Init(struct UnkUtil *util, struct UnkUtilData *data, u32 max);
extern void sub_080D0A34(void);
extern void Cb_MainPSS(void);
void Cb_ShowPartyPokemon(void);
void Cb_ShowPSS(void);
void Cb_ReshowPSS(void);
extern void Cb_HidePartyPokemon(void);
void Cb_OnCloseBoxPressed(void);
void Cb_OnBPressed(void);
void Cb_HandleBoxOptions(void);
void Cb_OnSelectedMon(void);
extern void sub_080C8F0C(void);
extern void Cb_CloseBoxWhileHoldingItem(void);
extern void Cb_PrintCantStoreMail(void);
extern void Cb_NameBox(void);
extern void Cb_HandleWallpapers(void);
extern void Cb_JumpBox(void);
extern void Cb_ChangeScreen(u8 taskId);
extern void PrintStorageActionText(u8 id);
extern void ShowYesNoWindow(s8 cursorPos);
extern void ClearBottomWindow(void);
extern void sub_080CA444(void);
extern bool8 IsMonBeingMoved(void);
extern u16 GetMovingItemId(void);
extern void FreePSSData(void);
void sub_080CDFDC(void);
void sub_080CE064(void);
bool8 sub_080CF948(void);
s16 sub_080CF94C(void);
u8 sub_080CF268(void);
void sub_080CF724(void);
void sub_080CF748(void);
bool8 sub_080CFA84(void);
void SetUpScrollToBox(u8 boxId);
bool8 ScrollToBox(void);
void SetCurrentBox(u8 boxId);
void sub_080CA384(void);
void sub_080CA224(void);
void StopFlashingCloseBoxButton(void);
void BoxSetMosaic(void);
bool8 sub_080CCDD0(void);
bool8 IsCursorOnCloseBox(void);
void MultiMove_SetFunction(u8 id);
void sub_080CB1C4(void);
u8 GetNumPartySpritesCompacting(void);
void AddWallpaperSetsMenu(void);
void AddWallpapersMenu(u8 wallpaperSet);
void SetWallpaperForCurrentBox(u8 wallpaperId);
bool8 DoWallpaperGfxChange(void);
void Cb_HandleMovingMonFromParty(void);
void sub_080D10B8(void);
bool8 sub_080D10EC(void);
bool8 sub_080D1184(void);
void sub_080CD888(void);
void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos);
void Item_TakeMons(u8 cursorArea, u8 cursorPos);
void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos);
void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos);
void SetMonMarkings(u8 markings);
bool8 TryStorePartyMonInBox(u8 boxId);
void sub_080CDAA8(void);
void SaveCursorPos(void);
void InitMonPlaceChange(u8 type);
bool8 DoMonPlaceChange(void);
void SetMovingMonPriority(u8 priority);
void SetUpDoShowPartyMenu(void);
bool8 DoShowPartyMenu(void);
void Cb_MoveMon(void);
void Cb_PlaceMon(void);
void Cb_ShiftMon(void);
void Cb_WithdrawMon(void);
void Cb_DepositMenu(void);
void Cb_ShowMonSummary(void);
void Cb_ShowMarkMenu(void);
void Cb_TakeItemForMoving(void);
void Cb_GiveMovingItemToMon(void);
void Cb_ItemToBag(void);
void Cb_SwitchSelectedItem(void);
void Cb_GiveItemFromBag(void);
void Cb_ShowItemInfo(void);
void Cb_ReleaseMon(void);
u8 sub_080C9B2C(void);
bool8 CanMovePartyMon(void);
bool8 CanShiftMon(void);
void sub_080C743C(void);
void sub_080C7470(void);
void sub_080C74A0(void);
void sub_080C7528(u8 *str, u16 x, u16 y);
void sub_080C7590(struct Sprite *sprite);
void FieldCb_ReturnToPcMenu(void);
void sub_080C6E88(u8 whichMenu, s16 *windowIdPtr);
extern void sub_080C6738(u8 *str, void *dest, u16 width, u8 fillValue, u8 textColor, u8 shadowColor, void *unused);
struct Sprite *sub_080CCB64(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority);
u8 sub_081984B0(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 itemCount, u8 initialCursorPos);
void InitCanRelaseMonVars(void);
void sub_080CDACC(void);
bool8 sub_080CDB24(void);
void ReleaseMon(void);
void sub_080CB8D8(void);
bool8 sub_080CB914(void);
void sub_080CDBA0(void);

#define WALDA_WALLPAPERS_COUNT 16
#define WALDA_WALLPAPER_ICONS_COUNT 30

enum
{
    MSG_VAR_NONE,
    MSG_VAR_MON_NAME_1,
    MSG_VAR_MON_NAME_2,
    MSG_VAR_MON_NAME_3,
    MSG_VAR_RELEASE_MON_1,
    MSG_VAR_RELEASE_MON_2,
    MSG_VAR_RELEASE_MON_3,
    MSG_VAR_ITEM_NAME,
};

struct StorageMessage
{
    const u8 *text;
    u8 format;
};

extern const struct StorageMessage gUnknown_854CA1C[];

struct Wallpaper
{
    const u32 *tiles;
    const u32 *tilemap;
    const u16 *palettes;
};

struct StorageMenu
{
    const u8 *text;
    int textId;
};

struct InputFunc
{
    u8 (*func)(void);
    s8 area;
};

struct CursorSpriteSheetData
{
    struct SpriteSheet sheets[3];
};

struct CursorSpritePaletteData
{
    struct SpritePalette palettes[2];
};

struct UnkUtilData
{
    const u8 *src;
    u8 *dest;
    u16 size;
    u16 unk;
    u16 height;
    void (*func)(struct UnkUtilData *data);
};

struct UnkUtil
{
    struct UnkUtilData *data;
    u8 numActive;
    u8 max;
};

struct ChooseBoxMenu
{
    struct Sprite *menuSprite;
    struct Sprite *menuSideSprites[4];
    u32 unused1[3];
    struct Sprite *arrowSprites[2];
    u8 unused2[0x200];
    u8 boxName[9];
    u8 unused2a[0xB];
    bool32 loadedPalette;
    u16 tileTag;
    u16 paletteTag;
    u8 curBox;
    u8 unused3;
    u8 subpriority;
};

struct ItemIcon
{
    struct Sprite *sprite;
    u8 *tiles;
    u16 palIndex;
    u8 area;
    u8 pos;
    bool8 active;
};

#define MAX_MON_ICONS max(IN_BOX_COUNT + PARTY_SIZE + 1, 40)
#define MAX_ITEM_ICONS 3
#define GFXTAG_ITEM_ICON_0 7
#define PALTAG_ITEM_ICON_0 0xDACB
#define GFXTAG_BOX_TITLE 3
#define GFXTAG_BOX_TITLE_ALT 4
#define PALTAG_BOX_TITLE 0xDAC9
#define STORAGE_MON_NAME_LENGTH 11 // Fixed US-style display buffer; JP kana names are shorter.

enum
{
    CURSOR_AREA_IN_BOX,
    CURSOR_AREA_IN_PARTY,
    CURSOR_AREA_BOX_TITLE,
    CURSOR_AREA_BUTTONS, // Party Pokemon and Close Box
};
#define CURSOR_AREA_IN_HAND CURSOR_AREA_BOX_TITLE // Alternate name while moving items.

enum
{
    INPUT_NONE,
    INPUT_MOVE_CURSOR,
    INPUT_2,
    INPUT_3,
    INPUT_CLOSE_BOX,
    INPUT_SHOW_PARTY,
    INPUT_HIDE_PARTY,
    INPUT_BOX_OPTIONS,
    INPUT_IN_MENU,
    INPUT_SCROLL_RIGHT,
    INPUT_SCROLL_LEFT,
    INPUT_DEPOSIT,
    INPUT_WITHDRAW,
    INPUT_MOVE_MON,
    INPUT_SHIFT_MON,
    INPUT_PLACE_MON,
    INPUT_TAKE_ITEM,
    INPUT_GIVE_ITEM,
    INPUT_SWITCH_ITEMS,
    INPUT_PRESSED_B,
    INPUT_MULTIMOVE_START,
    INPUT_MULTIMOVE_CHANGE_SELECTION,
    INPUT_MULTIMOVE_SINGLE,
    INPUT_MULTIMOVE_GRAB_SELECTION,
    INPUT_MULTIMOVE_UNABLE,
    INPUT_MULTIMOVE_MOVE_MONS,
    INPUT_MULTIMOVE_PLACE_MONS,
};

enum
{
    MOVE_MODE_NORMAL,
    MOVE_MODE_MULTIPLE_SELECTING,
    MOVE_MODE_MULTIPLE_MOVING,
};

enum
{
    MENU_CANCEL,
    MENU_STORE,
    MENU_WITHDRAW,
    MENU_MOVE,
    MENU_SHIFT,
    MENU_PLACE,
    MENU_SUMMARY,
    MENU_RELEASE,
    MENU_MARK,
    MENU_JUMP,
    MENU_WALLPAPER,
    MENU_NAME,
    MENU_TAKE,
    MENU_GIVE,
    MENU_GIVE_2,
    MENU_SWITCH,
    MENU_BAG,
    MENU_INFO,
    MENU_SCENERY_1,
    MENU_SCENERY_2,
    MENU_SCENERY_3,
    MENU_ETCETERA,
    MENU_FRIENDS,
    MENU_FOREST,
    MENU_CITY,
    MENU_DESERT,
    MENU_SAVANNA,
    MENU_CRAG,
    MENU_VOLCANO,
    MENU_SNOW,
    MENU_CAVE,
    MENU_BEACH,
    MENU_SEAFLOOR,
    MENU_RIVER,
    MENU_SKY,
    MENU_POLKADOT,
    MENU_POKECENTER,
    MENU_MACHINE,
    MENU_SIMPLE,
};
#define MENU_WALLPAPER_SETS_START MENU_SCENERY_1

enum
{
    ITEM_CB_WAIT_ANIM,
    ITEM_CB_TO_HAND,
    ITEM_CB_TO_MON,
    ITEM_CB_SWAP_TO_HAND,
    ITEM_CB_SWAP_TO_MON,
    ITEM_CB_UNUSED_5,
    ITEM_CB_UNUSED_6,
    ITEM_CB_HIDE_PARTY,
};

enum
{
    ITEM_ANIM_NONE,
    ITEM_ANIM_APPEAR,
    ITEM_ANIM_DISAPPEAR,
    ITEM_ANIM_PICK_UP,
    ITEM_ANIM_PUT_DOWN,
    ITEM_ANIM_PUT_AWAY,
    ITEM_ANIM_LARGE,
};

enum
{
    MODE_PARTY,
    MODE_BOX,
    MODE_MOVE,
};

// PC main menu options
enum {
    OPTION_WITHDRAW,
    OPTION_DEPOSIT,
    OPTION_MOVE_MONS,
    OPTION_MOVE_ITEMS,
    OPTION_EXIT,
    OPTIONS_COUNT
};

struct PokemonStorageSystemData
{
    u8 state;
    u8 boxOption;
    u8 screenChangeType;
    bool8 isReopening;
    u8 taskId;
    struct UnkUtil unkUtil;
    struct UnkUtilData unkUtilData[8];
    u16 partyMenuTilemapBuffer[0x108];
    u16 partyMenuUnused1; // Never read
    u16 partyMenuY;
    u8 partyMenuUnused2; // Unused
    u8 partyMenuMoveTimer;
    u8 showPartyMenuState;
    bool8 closeBoxFlashing;
    u8 closeBoxFlashTimer;
    bool8 closeBoxFlashState;
    s16 newCurrBoxId;
    u16 bg2_X;
    s16 scrollSpeed;
    u16 scrollTimer;
    u8 wallpaperOffset;
    u8 scrollUnused1; // Never read
    u8 scrollToBoxIdUnused; // Never read
    u16 scrollUnused2; // Never read
    s16 scrollDirectionUnused; // Never read.
    u16 scrollUnused3; // Never read
    u16 scrollUnused4; // Never read
    u16 scrollUnused5; // Never read
    u16 scrollUnused6; // Never read
    u8 filler1[22];
    u8 ALIGNED(2) boxTitleTiles[1024];
    u8 boxTitleCycleId;
    u8 wallpaperLoadState; // Written to, but never read.
    u8 wallpaperLoadBoxId;
    s8 wallpaperLoadDir;
    u16 boxTitlePal[16];
    u16 boxTitlePalOffset;
    u16 boxTitleAltPalOffset;
    struct Sprite *curBoxTitleSprites[2];
    struct Sprite *nextBoxTitleSprites[2];
    struct Sprite *arrowSprites[2];
    u32 wallpaperPalBits;
    u8 filler2[80]; // Unused
    u16 unkUnused1; // Never read.
    s16 wallpaperSetId;
    s16 wallpaperId;
    u16 wallpaperTilemap[360];
    u8 wallpaperChangeState;
    u8 scrollState;
    u8 scrollToBoxId;
    s8 scrollDirection;
    u8 *wallpaperTiles;
    struct Sprite *movingMonSprite;
    struct Sprite *partySprites[PARTY_SIZE];
    struct Sprite *boxMonsSprites[IN_BOX_COUNT];
    struct Sprite **shiftMonSpritePtr;
    struct Sprite **releaseMonSpritePtr;
    u16 numIconsPerSpecies[MAX_MON_ICONS];
    u16 iconSpeciesList[MAX_MON_ICONS];
    u16 boxSpecies[IN_BOX_COUNT];
    u32 boxPersonalities[IN_BOX_COUNT];
    u8 incomingBoxId;
    u8 shiftTimer;
    u8 numPartyToCompact;
    u16 iconScrollDistance;
    s16 iconScrollPos;
    s16 iconScrollSpeed;
    u16 iconScrollNumIncoming;
    u8 iconScrollCurColumn;
    s8 iconScrollDirection; // Unnecessary duplicate of scrollDirection
    u8 iconScrollState;
    u8 iconScrollToBoxId; // Unused duplicate of scrollToBoxId
    struct WindowTemplate menuWindow;
    struct StorageMenu menuItems[7];
    u8 menuItemsCount;
    u8 menuWidth;
    u8 menuUnusedField; // Never read.
    u16 menuWindowId;
    struct Sprite *cursorSprite;
    struct Sprite *cursorShadowSprite;
    s32 cursorNewX;
    s32 cursorNewY;
    u32 cursorSpeedX;
    u32 cursorSpeedY;
    s16 cursorTargetX;
    s16 cursorTargetY;
    u16 cursorMoveSteps;
    s8 cursorVerticalWrap;
    s8 cursorHorizontalWrap;
    u8 newCursorArea;
    u8 newCursorPosition;
    u8 cursorPrevHorizPos;
    u8 cursorFlipTimer;
    u8 cursorPalNums[2];
    const u32 *displayMonPalette;
    u32 displayMonPersonality;
    u16 displayMonSpecies;
    u16 displayMonItemId;
    u16 displayUnusedVar;
    bool8 setMosaic;
    u8 displayMonMarkings;
    u8 displayMonLevel;
    bool8 displayMonIsEgg;
    u8 displayMonName[STORAGE_MON_NAME_LENGTH];
    u8 displayMonNameText[36];
    u8 displayMonSpeciesName[36];
    u8 displayMonGenderLvlText[36];
    u8 displayMonItemName[39]; // JP item name display buffer is 3 bytes longer than US.
    bool8 (*monPlaceChangeFunc)(void);
    u8 monPlaceChangeState;
    u8 shiftBoxId;
    struct Sprite *markingComboSprite;
    struct Sprite *waveformSprites[2];
    u16 *markingComboTilesPtr;
    struct MonMarkingsMenu markMenu;
    struct ChooseBoxMenu chooseBoxMenu;
    struct Pokemon movingMon;
    struct Pokemon tempMon;
    s8 canReleaseMon;
    bool8 releaseStatusResolved;
    s8 releaseCheckBoxId;
    s8 releaseCheckBoxPos;
    s8 releaseBoxId;
    s8 releaseBoxPos;
    u16 releaseCheckState;
    u16 restrictedReleaseMonMoves;
    u16 restrictedMoveList[8];
    u8 summaryMaxPos;
    u8 summaryStartPos;
    u8 summaryScreenMode;
    union
    {
        struct Pokemon *mon;
        struct BoxPokemon *box;
    } summaryMon;
    u8 messageText[40];
    u8 boxTitleText[40];
    u8 releaseMonName[STORAGE_MON_NAME_LENGTH];
    u8 itemName[20];
    u8 inBoxMovingMode;
    u16 multiMoveWindowId;
    struct ItemIcon itemIcons[MAX_ITEM_ICONS];
    u16 movingItemId;
    u16 itemInfoWindowOffset;
    u8 unkUnused2; // Unused
    u16 displayMonPalOffset;
    u16 *displayMonTilePtr;
    struct Sprite *displayMonSprite;
    u16 displayMonPalBuffer[0x40];
    u8 ALIGNED(4) tileBuffer[MON_PIC_SIZE * MAX_MON_PIC_FRAMES];
    u8 ALIGNED(4) itemIconBuffer[0x800];
    u8 wallpaperBgTilemapBuffer[0x1000];
    u8 displayMenuTilemapBuffer[0x800];
};

struct MultiMove
{
    u8 funcId;
    u8 state;
    u8 fromColumn;
    u8 fromRow;
    u8 toColumn;
    u8 toRow;
    u8 cursorColumn;
    u8 cursorRow;
    u8 minColumn;
    u8 minRow;
    u8 columnsTotal;
    u8 rowsTotal;
    u16 bgX;
    u16 bgY;
    u16 bgMoveSteps;
    struct BoxPokemon boxMons[IN_BOX_COUNT];
};

struct TilemapUtil_RectData
{
    s16 x;
    s16 y;
    u16 width;
    u16 height;
    s16 destX;
    s16 destY;
};

struct TilemapUtil
{
    struct TilemapUtil_RectData prev;
    struct TilemapUtil_RectData cur;
    const void *savedTilemap;
    const void *tilemap;
    u16 altWidth;
    u16 altHeight;
    u16 width;
    u16 height;
    u16 rowSize;
    u8 tileSize;
    u8 bg;
    bool8 active;
};

struct TilemapDimensions
{
    u16 width;
    u16 height;
};

struct RestrictedReleaseMove
{
    s8 mapGroup;
    s8 mapNum;
    u16 move;
};

extern struct PokemonStorageSystemData *sStorage;

extern bool8 (*const sPlaceChangeFuncs[])(void);
extern const u8 *ItemId_GetName(u16 itemId);
extern const u8 gText_EggNickname[];
extern void TilemapUtil_Free(void);
extern void MultiMove_Free(void);
void RemoveMenu(void);
extern void PrintTextArray(u8 windowId, u8 fontId, u8 x, u8 y, u8 lineHeight, u8 itemCount, const void *texts);
extern u8 sub_081984F0(u8 windowId, u8 fontId, u8 x, u8 y, u8 itemCount, u8 initialCursorPos);
extern struct MultiMove *sMultiMove;
extern struct TilemapUtil *sTilemapUtil;
extern struct ChooseBoxMenu *gUnknown_20399A4;
extern u16 gUnknown_2039A28;
extern const struct TilemapDimensions gUnknown_8556784[][4];
extern const struct RestrictedReleaseMove gUnknown_85564A0[];

#define sNumTilemapUtilIds gUnknown_2039A28
#define sTilemapDimensions gUnknown_8556784
extern struct UnkUtil *sUnkUtil;
extern struct Pokemon sSavedMovingMon;
extern s8 sCursorArea;
extern s8 sCursorPosition;
extern s8 gUnknown_2039A18;
extern s8 gUnknown_2039A19;
extern bool8 gUnknown_2039A1D;
extern bool8 gUnknown_2039A1A;
extern u8 gUnknown_2039A1B;
extern u8 gUnknown_2039A1C;
extern u8 gUnknown_20399AF;
extern bool8 sIsMonBeingMoved;
extern u8 sLastUsedBox;
extern u16 sMovingItemId;
extern u8 sSavedCursorPosition;
extern u8 sMovingMonOrigBoxId;
extern void UpdateCloseBoxButtonFlash(void);
extern void UpdateCloseBoxButtonTilemap(bool8 state);
extern void UnkUtil_Run(void);
extern void ScrollBackground(void);
extern void Task_InitPokeStorage(u8 taskId);
extern const struct WindowTemplate sPSSWindowTemplates[];
extern const struct SpritePalette sWaveformSpritePalette;
extern void SetCursorMonData(const void *data, u8 mode);
extern void LoadPSSMenuGfx(void);
extern void LoadWaveformSpritePalette(void);
extern bool8 InitPokeStorageWindows(void);
extern void sub_080CA778(void);
extern void sub_080CCBE8(void);
extern void sub_080CCC68(void);
extern bool8 sub_080CFA04(void);
extern void SetScrollingBackground(void);
extern void sub_080CA480(void);
extern void sub_080C994C(void);
extern void sub_080C9F68(void);
extern void sub_080CBBA0(u8 boxId);
extern bool8 sub_080CBBD0(void);
extern void sub_080CE00C(void);
extern void sub_080CE160(void);
extern void GiveChosenBagItem(void);
extern void sub_080CA720(void);
extern void sub_080D0500(void);
extern void sub_080CA2D8(void);
extern void sub_080CA30C(u8 partyId, bool8 hasMon);
extern bool8 ShowPartyMenu(void);
extern void CreatePartyMonsSprites(bool8 visible);
extern void sub_080CB364(s16 yDelta);
extern void DestroyAllPartyMonIcons(void);
extern s16 CompactPartySlots(void);
extern void sub_080CD41C(void);
extern void SetUpDoShowPartyMenu(void);
extern bool8 DoShowPartyMenu(void);
extern void SetUpHidePartyMenu(void);
extern bool8 HidePartyMenu(void);
extern void sub_080CD474(u8 cursorBoxPosition);
extern u8 GetSavedCursorPos(void);
extern bool8 sub_080CCDD0(void);
extern void BoxSetMosaic(void);
extern u8 SetMenuTexts_Mon(void);
extern u8 SetMenuTexts_Item(void);
extern const u8 *ItemId_GetHoldEffect(u16 itemId);
extern void sub_080D0EA4(u8 id, u8 callbackId, u8 cursorArea, u8 cursorPos);
extern void sub_080D1378(struct Sprite *sprite);
extern u8 sub_080D0C10(u8 cursorArea, u8 cursorPos);
extern bool32 sub_080D0BC4(u8 cursorArea, u8 cursorPos);
extern void sub_080D0CAC(u8 id, u8 cursorArea, u8 cursorPos);
extern u8 sub_080D0B88(void);
extern void sub_080D0DC4(u8 id, const u32 *itemTiles, const u32 *itemPal);
extern void sub_080D0E74(u8 id, u8 animNum);
extern void sub_080D0FE0(u8 id, bool8 active);
extern void sub_080D0A6C(void);
extern u8 GetCursorPosition(void);
extern void StartCursorAnim(u8 anim);
extern void sub_080D07D8(u16 itemId);
extern void sub_080D062C(u8 cursorArea, u8 cursorPos);
extern void sub_080D06F0(u8 cursorArea, u8 cursorPos);
extern const void *GetItemIconPic(u16 itemId);
extern const void *GetItemIconPalette(u16 itemId);
extern void DestroyBoxMonIconAtPosition(u8 boxPosition);
extern void DestroyBoxMonIcon(struct Sprite *sprite);
extern void SpriteCB_HeldMon(struct Sprite *sprite);
extern const struct SpriteTemplate gUnknown_854CB84;
extern const union AffineAnimCmd *const gUnknown_854CBCC[];
extern void LoadWallpaperGfx(u8 boxId, s8 direction);
extern bool32 WaitForWallpaperGfxLoad(void);
extern void sub_080CC3C4(u8 boxId);
extern void sub_080CC8A8(void);
extern void SetBoxWallpaper(u8 boxId, u8 wallpaperId);
extern s8 sub_080CBEB8(u8 boxId);
extern void sub_080CAD40(u8 boxId, s8 direction);
extern bool8 sub_080CADF8(void);
extern void sub_080CC57C(u8 boxId, s8 direction);
extern void sub_080CC934(s8 direction);
extern void sub_080CC76C(void);
extern void sub_080CC9D4(void);
extern void sub_080CCA24(bool8 animate);
extern void sub_080CC828(void);
extern void sub_080CC7BC(struct Sprite *sprite);
extern void sub_080CC7F0(struct Sprite *sprite);
extern const u16 gUnknown_8551824[][2];
extern const struct SpriteTemplate gUnknown_8555BA4;
extern const struct SpriteSheet gUnknown_8555B7C;
extern const struct SpriteTemplate gUnknown_8555BDC;
extern void sub_080C66A4(const u8 *str, u8 *buffer, u8 x, u8 y, void *decompBuffer);
extern bool8 sub_080D0AB8(void);
extern bool8 IsActiveItemMoving(void);
extern void sub_080CD2E4(void);
extern void ClearSavedCursorPos(void);
extern void sub_080CF490(void);
extern void ReshowDisplayMon(void);
extern void CreateMovingMonIcon(void);
extern u8 GetBoxWallpaper(u8 boxId);
extern s16 GetBoxTitleBaseX(u16 len);
extern bool8 IsCursorOnBoxTitle(void);
extern struct Sprite *sub_080CBAA4(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority);
extern void sub_080CAAA8(struct Sprite *sprite);
extern void sub_080CAAEC(struct Sprite *sprite);
extern void sub_080CB244(struct Sprite *sprite, u16 partyId);
extern void sub_080CB2B0(struct Sprite *sprite);
extern void ZeroBoxMonAt(u8 boxId, u8 boxPosition);
extern void sub_080D0050(u8 x, u8 y);
extern void sub_080D00D4(u8 x, u8 y);
extern void sub_080CFF70(u8 column, u8 minRow, u8 maxRow);
extern void sub_080CFFA8(u8 row, u8 minColumn, u8 maxColumn);
extern void sub_080CFFE0(u8 column, u8 minRow, u8 maxRow);
extern void sub_080D0018(u8 row, u8 minColumn, u8 maxColumn);
extern void MultiMove_InitMove(u16 x, u16 y, u16 moveSteps);
extern void sub_080CFECC(void);
extern bool8 sub_080CFAEC(void);
extern bool8 sub_080CFBE4(void);
extern bool8 sub_080CFC50(void);
extern bool8 sub_080CFCC0(void);
extern bool8 sub_080CFD40(void);
extern bool8 sub_080CFD68(void);
extern u8 sub_080D0134(void);
extern void sub_080D016C(void);
extern void sub_080D0244(void);
extern void sub_080D02BC(void);
extern void sub_080D034C(void);
extern void sub_080D03FC(void);
extern void InitMultiMonPlaceChange(bool8 isMoving);
extern bool8 MonPlaceChange_CursorDown(void);
extern bool8 MonPlaceChange_CursorUp(void);
extern void MoveMon(void);
extern void PlaceMon(void);
extern void sub_080CB488(u8 mode, u8 id);
extern void sub_080CB520(u8 boxId, u8 position);
extern void sub_080CB5D0(u8 boxId, u8 position);
extern bool8 sub_080CB638(void);
extern void SetBoxSpeciesAndPersonalities(u8 boxId);
extern u32 GetCurrentBoxMonData(u8 boxPosition, s32 request);
extern void SetMovedMonData(u8 boxId, u8 position);
extern void SetPlacedMonData(u8 boxId, u8 position);
extern void SetShiftedMonData(u8 boxId, u8 position);
extern bool32 AtLeastThreeUsableMons(void);
extern s8 RunCanReleaseMon(void);
extern bool8 MultiMonPlaceChange_Down(void);
extern bool8 MultiMonPlaceChange_Up(void);
extern bool8 InBoxInput_Normal(void);
extern bool8 InBoxInput_GrabbingMultiple(void);
extern bool8 InBoxInput_MovingMultiple(void);
extern u8 SetSelectionMenuTexts(void);
extern void sub_080CF640(void);
extern s8 sub_080CF814(u8 menuIdx);
extern bool8 sub_080CFE20(u8 dir);
extern u8 sub_080D0444(void);
extern bool8 sub_080D0460(void);
extern void AddBoxOptionsMenu(void);
extern void InitMenu(void);
extern void SetMenuText(u8 textId);
extern void AddMenu(void);
extern bool32 IsWaldaWallpaperUnlocked(void);
extern const struct WindowTemplate gUnknown_854CB14;
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern void sub_080D204C(u8 id, u16 x, u16 y, u16 width, u16 height);
extern void sub_080D2094(u8 id, u8 mode, s8 val);
extern void sub_080D21B8(u8 id);
extern void PurgeMonOrBoxMon(u8 boxId, u8 position);
extern void TryRefreshDisplayMon(void);
extern void sub_080C71F0(u8 boxId);
extern void sub_080C73D0(void);
extern void sub_080CBBE4(u8 taskId);
extern const u16 *GetTextWindowPalette(u8 id);

u8 CountMonsInBox(u8 boxId)
{
    u16 i, count;

    for (i = 0, count = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) != SPECIES_NONE)
            count++;
    }

    return count;
}

s16 GetFirstFreeBoxSpot(u8 boxId)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (GetBoxMonDataAt(boxId, i, MON_DATA_SPECIES) == SPECIES_NONE)
            return i;
    }

    return -1; // all spots are taken
}

u8 CountPartyNonEggMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            count++;
        }
    }

    return count;
}

u8 CountPartyAliveNonEggMonsExcept(u8 slotToIgnore)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (i != slotToIgnore
            && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
            && GetMonData(&gPlayerParty[i], MON_DATA_HP) != 0)
        {
            count++;
        }
    }

    return count;
}

u16 CountPartyAliveNonEggMons_IgnoreVar0x8004Slot(void)
{
    return CountPartyAliveNonEggMonsExcept(gSpecialVar_0x8004);
}

u8 CountPartyMons(void)
{
    u16 i, count;

    for (i = 0, count = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            count++;
        }
    }

    return count;
}

u8 *StringCopyAndFillWithSpaces(u8 *dst, const u8 *src, u16 n)
{
    u8 *str;

    for (str = StringCopy(dst, src); str < dst + n; str++)
        *str = CHAR_SPACE;

    *str = EOS;
    return str;
}

void sub_080C69B4(u16 *dest, u16 destLeft, u16 destTop, const u16 *src, u16 srcLeft, u16 srcTop, u16 destWidth, u16 destHeight, u16 srcWidth)
{
    u16 i;

    destWidth *= 2;
    dest += destTop * 0x20 + destLeft;
    src += srcTop * srcWidth + srcLeft;
    for (i = 0; i < destHeight; i++)
    {
        CpuCopy16(src, dest, destWidth);
        dest += 0x20;
        src += srcWidth;
    }
}

void sub_080C6A30(u16 *dest, u16 destLeft, u16 destTop, u16 width, u16 height)
{
    u16 i;

    dest += destTop * 0x20 + destLeft;
    width *= 2;
    for (i = 0; i < height; dest += 0x20, i++)
        Dma3FillLarge16_(0, dest, width);
}

void Task_PokemonStorageSystemPC(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sub_080C6E88(task->data[1], &task->data[15]);
        LoadMessageBoxAndBorderGfx();
        DrawDialogueFrame(0, FALSE);
        FillWindowPixelBuffer(0, PIXEL_FILL(1));
        AddTextPrinterParameterized2(0, 1, gUnknown_854B1E4[task->data[1]].desc, TEXT_SKIP_DRAW, NULL, 2, 1, 3);
        CopyWindowToVram(0, COPYWIN_FULL);
        CopyWindowToVram(task->data[15], COPYWIN_FULL);
        task->data[0]++;
        break;
    case 1:
        if (IsWeatherNotFadingIn())
            task->data[0]++;
        break;
    case 2:
        task->data[2] = Menu_ProcessInput();
        switch (task->data[2])
        {
        case -2:
            task->data[3] = task->data[1];
            if ((gMain.newKeys & DPAD_UP) && --task->data[3] < 0)
                task->data[3] = 4;
            if ((gMain.newKeys & DPAD_DOWN) && ++task->data[3] > 4)
                task->data[3] = 0;

            if (task->data[1] != task->data[3])
            {
                task->data[1] = task->data[3];
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gUnknown_854B1E4[task->data[1]].desc, 0, NULL, 2, 1, 3);
            }
            break;
        case -1:
        case 4:
            ClearStdWindowAndFrame(task->data[15], TRUE);
            UnlockPlayerFieldControls();
            ScriptContext_Enable();
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
            break;
        default:
            if (task->data[2] == 0 && CountPartyMons() == PARTY_SIZE)
            {
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gUnknown_85CB55C, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else if (task->data[2] == 1 && CountPartyMons() == 1)
            {
                FillWindowPixelBuffer(0, PIXEL_FILL(1));
                AddTextPrinterParameterized2(0, 1, gUnknown_85CB534, 0, NULL, 2, 1, 3);
                task->data[0] = 3;
            }
            else
            {
                FadeScreen(1, 0);
                task->data[0] = 4;
            }
            break;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_854B1E4[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_UP)
        {
            if (--task->data[1] < 0)
                task->data[1] = 4;
            Menu_MoveCursor(-1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_854B1E4[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        else if (gMain.newKeys & DPAD_DOWN)
        {
            if (++task->data[1] > 3)
                task->data[1] = 0;
            Menu_MoveCursor(1);
            task->data[1] = Menu_GetCursorPos();
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0, 1, gUnknown_854B1E4[task->data[1]].desc, 0, NULL, 2, 1, 3);
            task->data[0] = 2;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            CleanupOverworldWindowsAndTilemaps();
            EnterPokeStorage(task->data[2]);
            RemoveWindow(task->data[15]);
            DestroyTask(taskId);
        }
        break;
    }
}

void ShowPokemonStorageSystemPC(void)
{
    u8 taskId = CreateTask(Task_PokemonStorageSystemPC, 80);

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    LockPlayerFieldControls();
}

void FieldCb_ReturnToPcMenu(void)
{
    u8 taskId;
    MainCallback vblankCb = gMain.vblankCallback;

    SetVBlankCallback(NULL);
    taskId = CreateTask(Task_PokemonStorageSystemPC, 80);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gUnknown_20399A0;
    Task_PokemonStorageSystemPC(taskId);
    SetVBlankCallback(vblankCb);
    FadeInFromBlack();
}

void sub_080C6E88(u8 whichMenu, s16 *windowIdPtr)
{
    s16 windowId = AddWindow(gUnknown_854B20C);

    DrawStdWindowFrame(windowId, FALSE);
    PrintTextArray(windowId, 1, GetFontAttribute(1, 0), 2, 0x10, 5, gUnknown_854B1E4);
    sub_081984B0(windowId, 1, 0, 2, 0x10, 5, whichMenu);
    *windowIdPtr = windowId;
}

void CB2_ExitPokeStorage(void)
{
    gUnknown_20399A0 = GetCurrentBoxOption();
    gFieldCallback = FieldCb_ReturnToPcMenu;
    SetMainCallback2(CB2_ReturnToField);
}

s16 StorageSystemGetNextMonIndex(struct BoxPokemon *box, s8 startIdx, u8 stopIdx, u8 mode)
{
    s16 i;
    s16 direction;

    if (mode == 0 || mode == 1)
        direction = 1;
    else
        direction = -1;

    if (mode == 1 || mode == 3)
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0)
                return i;
        }
    }
    else
    {
        for (i = startIdx + direction; i >= 0 && i <= stopIdx; i += direction)
        {
            if (GetBoxMonData(box + i, MON_DATA_SPECIES) != 0 && !GetBoxMonData(box + i, MON_DATA_IS_EGG))
                return i;
        }
    }

    return -1;
}

void ResetPokemonStorageSystem(void)
{
    u16 boxId;
    u16 boxPosition;

    SetCurrentBox(0);
    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
            ZeroBoxMonAt(boxId, boxPosition);
    }

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
    {
        u8 *dest = StringCopy(GetBoxNamePtr(boxId), gUnknown_85CB584);

        ConvertIntToDecimalStringN(dest, boxId + 1, 0, 2);
    }

    for (boxId = 0; boxId < TOTAL_BOXES_COUNT; boxId++)
        SetBoxWallpaper(boxId, boxId % 4);

    ResetWaldaWallpaper();
}

void sub_080C7080(struct ChooseBoxMenu *menu, u16 tileTag, u16 paletteTag, u8 subpriority, bool32 loadPalette)
{
    struct SpritePalette palette =
    {
        gUnknown_854B25C, paletteTag
    };
    struct SpriteSheet sheets[] =
    {
        {gUnknown_854B27C, 0x800, tileTag},
        {gUnknown_854BA7C, 0x180, tileTag + 1},
        {}
    };

    if (loadPalette)
        LoadSpritePalette(&palette);

    LoadSpriteSheets(sheets);
    gUnknown_20399A4 = menu;
    menu->tileTag = tileTag;
    menu->paletteTag = paletteTag;
    menu->subpriority = subpriority;
    menu->loadedPalette = loadPalette;
}

void sub_080C7128(void)
{
    if (gUnknown_20399A4->loadedPalette)
        FreeSpritePaletteByTag(gUnknown_20399A4->paletteTag);

    FreeSpriteTilesByTag(gUnknown_20399A4->tileTag);
    FreeSpriteTilesByTag(gUnknown_20399A4->tileTag + 1);
}

void sub_080C716C(u8 boxId)
{
    sub_080C71F0(boxId);
}
void sub_080C717C(void)
{
    sub_080C73D0();
}
bool8 HandleBoxChooseSelectionInput(void)
{
    if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        return 201;
    }
    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        return gUnknown_20399A4->curBox;
    }
    if (gMain.newKeys & DPAD_LEFT)
    {
        PlaySE(SE_SELECT);
        sub_080C7470();
    }
    else if (gMain.newKeys & DPAD_RIGHT)
    {
        PlaySE(SE_SELECT);
        sub_080C743C();
    }

    return 200;
}

void sub_080C71F0(u8 boxId)
{
    u16 i;
    u8 spriteId;
    struct SpriteTemplate template;
    struct OamData oamData = {};

    oamData.size = SPRITE_SIZE(64x64);
    oamData.paletteNum = 1;
    template = (struct SpriteTemplate){
        0, 0, &oamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
    };
    {
        u8 text[4];

        memcpy(text, gUnknown_854B258, sizeof(text));
        gUnknown_20399A4->curBox = boxId;
        template.tileTag = gUnknown_20399A4->tileTag;
        template.paletteTag = gUnknown_20399A4->paletteTag;

        spriteId = CreateSprite(&template, 160, 96, 0);
        gUnknown_20399A4->menuSprite = &gSprites[spriteId];

        oamData.shape = SPRITE_SHAPE(8x32);
        oamData.size = SPRITE_SIZE(8x32);
        template.tileTag = gUnknown_20399A4->tileTag + 1;
        template.anims = (const union AnimCmd *const *)gUnknown_854B234;
        for (i = 0; i < ARRAY_COUNT(gUnknown_20399A4->menuSideSprites); i++)
        {
            u16 anim;

            spriteId = CreateSprite(&template, 124, 80, gUnknown_20399A4->subpriority);
            gUnknown_20399A4->menuSideSprites[i] = &gSprites[spriteId];
            anim = 0;
            if (i & 2)
            {
                gUnknown_20399A4->menuSideSprites[i]->x = 196;
                anim = 2;
            }
            if (i & 1)
            {
                gUnknown_20399A4->menuSideSprites[i]->y = 112;
                gUnknown_20399A4->menuSideSprites[i]->oam.size = 0;
                anim++;
            }
            StartSpriteAnim(gUnknown_20399A4->menuSideSprites[i], anim);
        }

        for (i = 0; i < ARRAY_COUNT(gUnknown_20399A4->arrowSprites); i++)
        {
            gUnknown_20399A4->arrowSprites[i] = sub_080CCB64(72 * i + 124, 88, i, 0, gUnknown_20399A4->subpriority);
            if (gUnknown_20399A4->arrowSprites[i])
            {
                gUnknown_20399A4->arrowSprites[i]->data[0] = (i == 0 ? -1 : 1);
                gUnknown_20399A4->arrowSprites[i]->callback = sub_080C7590;
            }
        }

        sub_080C74A0();
        sub_080C7528(text, 5, 3);
    }
}

void sub_080C73D0(void)
{
    u16 i;

    if (gUnknown_20399A4->menuSprite)
    {
        DestroySprite(gUnknown_20399A4->menuSprite);
        gUnknown_20399A4->menuSprite = NULL;
    }

    for (i = 0; i < ARRAY_COUNT(gUnknown_20399A4->menuSideSprites); i++)
    {
        if (gUnknown_20399A4->menuSideSprites[i])
        {
            DestroySprite(gUnknown_20399A4->menuSideSprites[i]);
            gUnknown_20399A4->menuSideSprites[i] = NULL;
        }
    }

    for (i = 0; i < ARRAY_COUNT(gUnknown_20399A4->arrowSprites); i++)
    {
        if (gUnknown_20399A4->arrowSprites[i])
            DestroySprite(gUnknown_20399A4->arrowSprites[i]);
    }
}

void sub_080C743C(void)
{
    if (++gUnknown_20399A4->curBox > 13)
        gUnknown_20399A4->curBox = 0;

    sub_080C74A0();
}

// Kept as naked asm: agbcc uses a different temporary field-pointer/register
// allocation for the wraparound decrement despite five equivalent C formulations.
__attribute__((naked)) void sub_080C7470(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080C7488\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #0x91\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080C748C\n\t"
        "	subs r1, r0, #1\n\t"
        "	b _080C748E\n\t"
        "	.align 2, 0\n\t"
        "_080C7488: .4byte gUnknown_20399A4\n\t"
        "_080C748C:\n\t"
        "	movs r1, #0xd\n\t"
        "_080C748E:\n\t"
        "	movs r3, #0x91\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r0, r2, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	bl sub_080C74A0\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void sub_080C74A0(void)
{
    u8 numMons = CountMonsInBox(gUnknown_20399A4->curBox);
    u8 *str = StringCopy(gUnknown_20399A4->boxName, GetBoxNamePtr(gUnknown_20399A4->curBox));

    while (str < gUnknown_20399A4->boxName + 8)
        *str++ = 0;
    *str = EOS;

    sub_080C7528(gUnknown_20399A4->boxName, 0, 1);
    ConvertIntToDecimalStringN(gUnknown_20399A4->boxName, numMons, 1, 2);
    sub_080C7528(gUnknown_20399A4->boxName, 3, 3);
}

void sub_080C7528(u8 *str, u16 x, u16 y)
{
    sub_080C6738(str,
                 (void *)(0x06010000 + (GetSpriteTileStartByTag(gUnknown_20399A4->tileTag) << 5) + (y << 8) + (x << 5)),
                 0x100, 4, 0xF, 0xE, gUnknown_20399A4->unused2);
}

void sub_080C7590(struct Sprite *sprite)
{
    sprite->data[1]++;
    if (sprite->data[1] > 3)
    {
        sprite->data[1] = 0;
        sprite->x2 += sprite->data[0];
        sprite->data[2]++;
        if (sprite->data[2] > 5)
        {
            sprite->data[2] = 0;
            sprite->x2 = 0;
        }
    }
}

void VBlankCB_PokeStorage(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    UnkUtil_Run();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG2HOFS, sStorage->bg2_X);
}

void CB2_PokeStorage(void)
{
    RunTasks();
    DoScheduledBgTilemapCopiesToVram();
    ScrollBackground();
    UpdateCloseBoxButtonFlash();
    AnimateSprites();
    BuildOamBuffer();
}

void EnterPokeStorage(u8 boxOption)
{
    ResetTasks();
    sCurrentBoxOption = boxOption;
    sStorage = Alloc(sizeof(*sStorage));
    if (sStorage == NULL)
    {
        SetMainCallback2(CB2_ExitPokeStorage);
    }
    else
    {
        sStorage->boxOption = boxOption;
        sStorage->isReopening = FALSE;
        sMovingItemId = ITEM_NONE;
        sStorage->state = 0;
        sStorage->taskId = CreateTask(Task_InitPokeStorage, 3);
        sLastUsedBox = StorageGetCurrentBox();
        SetMainCallback2(CB2_PokeStorage);
    }
}

void CB2_ReturnToPokeStorage(void)
{
    ResetTasks();
    sStorage = Alloc(sizeof(*sStorage));
    if (sStorage == NULL)
    {
        SetMainCallback2(CB2_ExitPokeStorage);
    }
    else
    {
        sStorage->boxOption = sCurrentBoxOption;
        sStorage->isReopening = TRUE;
        sStorage->state = 0;
        sStorage->taskId = CreateTask(Task_InitPokeStorage, 3);
        SetMainCallback2(CB2_PokeStorage);
    }
}

void ResetAllBgCoords(void)
{
    SetGpuReg(0x10, 0);
    SetGpuReg(0x12, 0);
    SetGpuReg(0x14, 0);
    SetGpuReg(0x16, 0);
    SetGpuReg(0x18, 0);
    SetGpuReg(0x1A, 0);
    SetGpuReg(0x1C, 0);
    SetGpuReg(0x1E, 0);
}

void sub_080C7734(void)
{
    ResetPaletteFade();
    ResetSpriteData();
    FreeSpriteTileRanges();
    FreeAllSpritePalettes();
    ClearDma3Requests();
    gReservedSpriteTileCount = 0x280;
    UnkUtil_Init(&sStorage->unkUtil, sStorage->unkUtilData, 8);
    gKeyRepeatStartDelay = 20;
    ClearScheduledBgCopiesToVram();
    sub_080D1E3C(3);
    sub_080D1EE4(0, 1, gUnknown_854BEBC, 8, 4);
    sub_080D2010(0, 1, 0);
    sStorage->closeBoxFlashing = FALSE;
}

void sub_080C77B8(void)
{
    ClearSavedCursorPos();
    gUnknown_20399AC = (sStorage->boxOption == 1);
    gUnknown_20399AE = 0;
}

void sub_080C77E8(void)
{
    if (sStorage->boxOption == 3)
    {
        SetGpuReg(0x50, 0xFC << 6);
        SetGpuReg(0x52, 0xB07);
    }

    SetGpuReg(0, 0xFA << 5);
}

void SetPSSCallback(void (*func)(void))
{
    gTasks[sStorage->taskId].func = func;
    sStorage->state = 0;
}

void Task_InitPokeStorage(u8 taskId)
{
    switch (sStorage->state)
    {
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(0, 0);
        sub_080C7734();
        if (sStorage->isReopening)
        {
            switch (gUnknown_20399AF)
            {
            case 1:
                sub_080CE00C();
                break;
            case 0:
                sub_080CE160();
                break;
            case 2:
                GiveChosenBagItem();
                break;
            }
        }
        LoadPSSMenuGfx();
        LoadWaveformSpritePalette();
        break;
    case 1:
        if (!InitPokeStorageWindows())
        {
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
            return;
        }
        break;
    case 2:
        PutWindowTilemap(0);
        ClearWindowTilemap(1);
        CpuFill32(0, (void *)VRAM, 0x200);
        LoadUserWindowBorderGfx(1, 0xB, 0xE0);
        break;
    case 3:
        ResetAllBgCoords();
        if (!sStorage->isReopening)
            sub_080C77B8();
        break;
    case 4:
        sub_080CA778();
        if (!sStorage->isReopening)
            sub_080CCBE8();
        else
            sub_080CCC68();
        break;
    case 5:
        if (!sub_080CFA04())
        {
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
            return;
        }
        else
        {
            SetScrollingBackground();
            sub_080CA480();
        }
        break;
    case 6:
        sub_080C994C();
        break;
    case 7:
        sub_080C9F68();
        break;
    case 8:
        sub_080CBBA0(StorageGetCurrentBox());
        break;
    case 9:
        if (sub_080CBBD0())
            return;

        if (sStorage->boxOption != 3)
        {
            sStorage->markMenu.baseTileTag = 0xD;
            sStorage->markMenu.basePaletteTag = 0xDACE;
            InitMonMarkingsMenu(&sStorage->markMenu);
            BufferMonMarkingsMenuTiles();
        }
        else
        {
            sub_080D0500();
            sub_080CA720();
        }
        break;
    case 10:
        sub_080C77E8();
        if (!sStorage->isReopening)
        {
            BlendPalettes(-1, 16, 0);
            SetPSSCallback(Cb_ShowPSS);
        }
        else
        {
            BlendPalettes(-1, 16, 0);
            SetPSSCallback(Cb_ReshowPSS);
        }
        SetVBlankCallback(VBlankCB_PokeStorage);
        return;
    default:
        return;
    }

    sStorage->state++;
}

void Cb_ShowPSS(void)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(2);
        ComputerScreenOpenEffect(20, 0, 1);
        sStorage->state++;
        break;
    case 1:
        if (!IsComputerScreenOpenEffectActive())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ReshowPSS(void)
{
    switch (sStorage->state)
    {
    case 0:
        BeginNormalPaletteFade(-1, -1, 16, 0, 0);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            if (gUnknown_20399AF == 2 && gSpecialVar_ItemId != 0)
            {
                PrintStorageActionText(28);
                sStorage->state++;
            }
            else
            {
                SetPSSCallback(Cb_MainPSS);
            }
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            if (gMain.newKeys & (A_BUTTON | B_BUTTON))
            {
                ClearBottomWindow();
                sStorage->state++;
            }
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_MainPSS(void)
{
    switch (sStorage->state)
    {
    case 0:
        switch (sub_080CF268())
        {
        case INPUT_MOVE_CURSOR:
            PlaySE(SE_SELECT);
            sStorage->state = 1;
            break;
        case INPUT_SHOW_PARTY:
            if (sStorage->boxOption != OPTION_MOVE_MONS && sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                PrintStorageActionText(16);
                sStorage->state = 3;
            }
            else
            {
                ClearSavedCursorPos();
                SetPSSCallback(Cb_ShowPartyPokemon);
            }
            break;
        case INPUT_HIDE_PARTY:
            if (sStorage->boxOption == OPTION_MOVE_MONS)
            {
                if (IsMonBeingMoved() && ItemIsMail(sStorage->displayMonItemId))
                    sStorage->state = 5;
                else
                    SetPSSCallback(Cb_HidePartyPokemon);
            }
            else if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            {
                SetPSSCallback(Cb_HidePartyPokemon);
            }
            break;
        case INPUT_CLOSE_BOX:
            SetPSSCallback(Cb_OnCloseBoxPressed);
            break;
        case INPUT_PRESSED_B:
            SetPSSCallback(Cb_OnBPressed);
            break;
        case INPUT_BOX_OPTIONS:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_HandleBoxOptions);
            break;
        case INPUT_IN_MENU:
            SetPSSCallback(Cb_OnSelectedMon);
            break;
        case INPUT_SCROLL_RIGHT:
            PlaySE(SE_SELECT);
            sStorage->newCurrBoxId = StorageGetCurrentBox() + 1;
            if (sStorage->newCurrBoxId >= TOTAL_BOXES_COUNT)
                sStorage->newCurrBoxId = 0;
            if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sStorage->newCurrBoxId);
                sStorage->state = 2;
            }
            else
            {
                sub_080CF724();
                sStorage->state = 10;
            }
            break;
        case INPUT_SCROLL_LEFT:
            PlaySE(SE_SELECT);
            sStorage->newCurrBoxId = StorageGetCurrentBox() - 1;
            if (sStorage->newCurrBoxId < 0)
                sStorage->newCurrBoxId = TOTAL_BOXES_COUNT - 1;
            if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            {
                SetUpScrollToBox(sStorage->newCurrBoxId);
                sStorage->state = 2;
            }
            else
            {
                sub_080CF724();
                sStorage->state = 10;
            }
            break;
        case INPUT_DEPOSIT:
            if (!CanMovePartyMon())
            {
                if (ItemIsMail(sStorage->displayMonItemId))
                {
                    sStorage->state = 5;
                }
                else
                {
                    PlaySE(SE_SELECT);
                    SetPSSCallback(Cb_DepositMenu);
                }
            }
            else
            {
                sStorage->state = 4;
            }
            break;
        case INPUT_MOVE_MON:
            if (CanMovePartyMon())
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case INPUT_SHIFT_MON:
            if (!CanShiftMon())
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(SE_SELECT);
                SetPSSCallback(Cb_ShiftMon);
            }
            break;
        case INPUT_WITHDRAW:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_WithdrawMon);
            break;
        case INPUT_PLACE_MON:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_PlaceMon);
            break;
        case INPUT_TAKE_ITEM:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_TakeItemForMoving);
            break;
        case INPUT_GIVE_ITEM:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_GiveMovingItemToMon);
            break;
        case INPUT_SWITCH_ITEMS:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_SwitchSelectedItem);
            break;
        case INPUT_MULTIMOVE_START:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(0);
            sStorage->state = 7;
            break;
        case INPUT_MULTIMOVE_SINGLE:
            MultiMove_SetFunction(1);
            sStorage->state = 8;
            break;
        case INPUT_MULTIMOVE_CHANGE_SELECTION:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(2);
            sStorage->state = 9;
            break;
        case INPUT_MULTIMOVE_GRAB_SELECTION:
            MultiMove_SetFunction(3);
            sStorage->state = 7;
            break;
        case INPUT_MULTIMOVE_MOVE_MONS:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(4);
            sStorage->state = 9;
            break;
        case INPUT_MULTIMOVE_PLACE_MONS:
            PlaySE(SE_SELECT);
            MultiMove_SetFunction(5);
            sStorage->state = 7;
            break;
        case INPUT_MULTIMOVE_UNABLE:
            PlaySE(SE_FAILURE);
            break;
        }
        break;
    case 1:
        if (!sub_080CCDD0())
        {
            if (IsCursorOnCloseBox())
                sub_080CA224();
            else
                StopFlashingCloseBoxButton();

            if (sStorage->setMosaic)
                BoxSetMosaic();
            sStorage->state = 0;
        }
        break;
    case 2:
        if (!ScrollToBox())
        {
            SetCurrentBox(sStorage->newCurrBoxId);
            if (!gUnknown_20399AC && !IsMonBeingMoved())
            {
                sub_080CD888();
                BoxSetMosaic();
            }

            if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            {
                sub_080CF748();
                sStorage->state = 11;
            }
            else
            {
                sStorage->state = 0;
            }
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state = 0;
        }
        break;
    case 4:
        PlaySE(SE_FAILURE);
        PrintStorageActionText(13);
        sStorage->state = 6;
        break;
    case 5:
        PlaySE(SE_FAILURE);
        PrintStorageActionText(22);
        sStorage->state = 6;
        break;
    case 6:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 7:
        if (!sub_080CFA84())
            sStorage->state = 0;
        break;
    case 8:
        if (!sub_080CFA84())
            SetPSSCallback(Cb_MoveMon);
        break;
    case 9:
        if (!sub_080CFA84())
        {
            if (sStorage->setMosaic)
                BoxSetMosaic();
            sStorage->state = 0;
        }
        break;
    case 10:
        if (!sub_080D0AB8())
        {
            SetUpScrollToBox(sStorage->newCurrBoxId);
            sStorage->state = 2;
        }
        break;
    case 11:
        if (!sub_080D0AB8())
            sStorage->state = 0;
        break;
    }
}

void Cb_ShowPartyPokemon(void)
{
    switch (sStorage->state)
    {
    case 0:
        SetUpDoShowPartyMenu();
        sStorage->state++;
        break;
    case 1:
        if (!DoShowPartyMenu())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_HidePartyPokemon(void)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(5);
        SetUpHidePartyMenu();
        sStorage->state++;
        break;
    case 1:
        if (!HidePartyMenu())
        {
            sub_080CD474(GetSavedCursorPos());
            sStorage->state++;
        }
        break;
    case 2:
        if (!sub_080CCDD0())
        {
            if (sStorage->setMosaic)
                BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_OnSelectedMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (!sub_080C9B2C())
        {
            PlaySE(5);
            if (sStorage->boxOption != 3)
                PrintStorageActionText(4);
            else if (IsActiveItemMoving() || sStorage->displayMonItemId != ITEM_NONE)
                PrintStorageActionText(23);
            else
                PrintStorageActionText(24);

            AddMenu();
            sStorage->state = 1;
        }
        break;
    case 1:
        if (!sub_080CF948())
            sStorage->state = 2;
        break;
    case 2:
        switch (sub_080CF94C())
        {
        case -1:
        case 0:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 3:
            if (CanMovePartyMon())
            {
                sStorage->state = 3;
            }
            else
            {
                PlaySE(5);
                ClearBottomWindow();
                SetPSSCallback(Cb_MoveMon);
            }
            break;
        case 5:
            PlaySE(5);
            ClearBottomWindow();
            SetPSSCallback(Cb_PlaceMon);
            break;
        case 4:
            if (!CanShiftMon())
            {
                sStorage->state = 3;
            }
            else
            {
                PlaySE(5);
                ClearBottomWindow();
                SetPSSCallback(Cb_ShiftMon);
            }
            break;
        case 2:
            PlaySE(5);
            ClearBottomWindow();
            SetPSSCallback(Cb_WithdrawMon);
            break;
        case 1:
            if (CanMovePartyMon())
            {
                sStorage->state = 3;
            }
            else if (ItemIsMail(sStorage->displayMonItemId))
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(5);
                ClearBottomWindow();
                SetPSSCallback(Cb_DepositMenu);
            }
            break;
        case 7:
            if (CanMovePartyMon())
            {
                sStorage->state = 3;
            }
            else if (sStorage->displayMonIsEgg)
            {
                sStorage->state = 5;
            }
            else if (ItemIsMail(sStorage->displayMonItemId))
            {
                sStorage->state = 4;
            }
            else
            {
                PlaySE(5);
                SetPSSCallback(Cb_ReleaseMon);
            }
            break;
        case 6:
            PlaySE(5);
            SetPSSCallback(Cb_ShowMonSummary);
            break;
        case 8:
            PlaySE(5);
            SetPSSCallback(Cb_ShowMarkMenu);
            break;
        case 12:
            PlaySE(5);
            SetPSSCallback(Cb_TakeItemForMoving);
            break;
        case 13:
            PlaySE(5);
            SetPSSCallback(Cb_GiveMovingItemToMon);
            break;
        case 16:
            SetPSSCallback(Cb_ItemToBag);
            break;
        case 15:
            PlaySE(5);
            SetPSSCallback(Cb_SwitchSelectedItem);
            break;
        case 14:
            PlaySE(5);
            SetPSSCallback(Cb_GiveItemFromBag);
            break;
        case 17:
            SetPSSCallback(Cb_ShowItemInfo);
            break;
        }
        break;
    case 3:
        PlaySE(32);
        PrintStorageActionText(13);
        sStorage->state = 6;
        break;
    case 5:
        PlaySE(32);
        PrintStorageActionText(17);
        sStorage->state = 6;
        break;
    case 4:
        PlaySE(32);
        PrintStorageActionText(22);
        sStorage->state = 6;
        break;
    case 6:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_MoveMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(0);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (gUnknown_20399AC)
                SetPSSCallback(sub_080C8F0C);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_PlaceMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(1);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            if (gUnknown_20399AC)
                SetPSSCallback(sub_080C8F0C);
            else
                SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_ShiftMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        InitMonPlaceChange(2);
        sStorage->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            BoxSetMosaic();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}


void Cb_WithdrawMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (CalculatePlayerPartyCount() == PARTY_SIZE)
        {
            PrintStorageActionText(14);
            sStorage->state = 1;
        }
        else
        {
            SaveCursorPos();
            InitMonPlaceChange(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            SetMovingMonPriority(1);
            SetUpDoShowPartyMenu();
            sStorage->state++;
        }
        break;
    case 3:
        if (!DoShowPartyMenu())
        {
            InitMonPlaceChange(1);
            sStorage->state++;
        }
        break;
    case 4:
        if (!DoMonPlaceChange())
        {
            sub_080CA384();
            sStorage->state++;
        }
        break;
    case 5:
        SetPSSCallback(Cb_HidePartyPokemon);
        break;
    }
}

void Cb_DepositMenu(void)
{
    u8 boxId;

    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(6);
        sub_080C7080(&sStorage->chooseBoxMenu, 10, 0xDAC7, 3, FALSE);
        sub_080C716C(gUnknown_20399AE);
        sStorage->state++;
        break;
    case 1:
        boxId = HandleBoxChooseSelectionInput();
        switch (boxId)
        {
        case 0xC8:
            break;
        case 0xC9:
            ClearBottomWindow();
            sub_080C717C();
            sub_080C7128();
            SetPSSCallback(Cb_MainPSS);
            break;
        default:
            if (TryStorePartyMonInBox(boxId))
            {
                gUnknown_20399AE = boxId;
                ClearBottomWindow();
                sub_080C717C();
                sub_080C7128();
                sStorage->state = 2;
            }
            else
            {
                PrintStorageActionText(8);
                sStorage->state = 4;
            }
            break;
        }
        break;
    case 2:
        CompactPartySlots();
        sub_080CB1C4();
        sStorage->state++;
        break;
    case 3:
        if (GetNumPartySpritesCompacting() == 0)
        {
            sub_080CDAA8();
            BoxSetMosaic();
            sub_080CA384();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(6);
            sStorage->state = 1;
        }
        break;
    }
}

void Cb_ReleaseMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(9);
        ShowYesNoWindow(1);
        sStorage->state++;
        // fall through
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case -1:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            ClearBottomWindow();
            InitCanRelaseMonVars();
            sub_080CDACC();
            sStorage->state++;
            break;
        }
        break;
    case 2:
        RunCanReleaseMon();
        if (!sub_080CDB24())
        {
            while (1)
            {
                s8 canRelease = RunCanReleaseMon();

                if (canRelease == 1)
                {
                    sStorage->state++;
                    break;
                }
                else if (!canRelease)
                {
                    sStorage->state = 8;
                    break;
                }
            }
        }
        break;
    case 3:
        ReleaseMon();
        RefreshCursorMonData();
        PrintStorageActionText(10);
        sStorage->state++;
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(11);
            sStorage->state++;
        }
        break;
    case 5:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            if (gUnknown_20399AC)
            {
                CompactPartySlots();
                sub_080CB1C4();
                sStorage->state++;
            }
            else
            {
                sStorage->state = 7;
            }
        }
        break;
    case 6:
        if (!GetNumPartySpritesCompacting())
        {
            sub_080CD888();
            BoxSetMosaic();
            sub_080CA384();
            sStorage->state++;
        }
        break;
    case 7:
        SetPSSCallback(Cb_MainPSS);
        break;
    case 8:
        PrintStorageActionText(10);
        sStorage->state++;
        break;
    case 9:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(21);
            sStorage->state++;
        }
        break;
    case 10:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_080CB8D8();
            sStorage->state++;
        }
        break;
    case 11:
        if (!sub_080CB914())
        {
            sub_080CDBA0();
            PrintStorageActionText(19);
            sStorage->state++;
        }
        break;
    case 12:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PrintStorageActionText(20);
            sStorage->state++;
        }
        break;
    case 13:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_ShowMarkMenu(void)
{
    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(12);
        sStorage->markMenu.markings = sStorage->displayMonMarkings;
        OpenMonMarkingsMenu(sStorage->displayMonMarkings, 0xB0, 0x10);
        sStorage->state++;
        break;
    case 1:
        if (!HandleMonMarkingsMenuInput())
        {
            FreeMonMarkingsMenu();
            ClearBottomWindow();
            SetMonMarkings(sStorage->markMenu.markings);
            RefreshCursorMonData();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_TakeItemForMoving(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (!ItemIsMail(sStorage->displayMonItemId))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        StartCursorAnim(2);
        Item_FromMonToMoving(gUnknown_20399AC ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_080D0AB8())
        {
            StartCursorAnim(3);
            ClearBottomWindow();
            sub_080CD888();
            PrintCursorMonInfo();
            sStorage->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_GiveMovingItemToMon(void)
{
    switch (sStorage->state)
    {
    case 0:
        ClearBottomWindow();
        sStorage->state++;
        break;
    case 1:
        StartCursorAnim(2);
        Item_GiveMovingToMon(gUnknown_20399AC ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_080D0AB8())
        {
            StartCursorAnim(0);
            sub_080CD888();
            PrintCursorMonInfo();
            PrintStorageActionText(28);
            sStorage->state++;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ItemToBag(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (!AddBagItem(sStorage->displayMonItemId, 1))
        {
            PlaySE(SE_FAILURE);
            PrintStorageActionText(26);
            sStorage->state = 3;
        }
        else
        {
            PlaySE(SE_SELECT);
            Item_TakeMons(gUnknown_20399AC ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetCursorPosition());
            sStorage->state = 1;
        }
        break;
    case 1:
        if (!sub_080D0AB8())
        {
            PrintStorageActionText(25);
            sStorage->state = 2;
        }
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sub_080CD888();
            PrintCursorMonInfo();
            sStorage->state = 4;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_SwitchSelectedItem(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (!ItemIsMail(sStorage->displayMonItemId))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        else
        {
            SetPSSCallback(Cb_PrintCantStoreMail);
        }
        break;
    case 1:
        StartCursorAnim(2);
        Item_SwitchMonsWithMoving(gUnknown_20399AC ? CURSOR_AREA_IN_PARTY : CURSOR_AREA_IN_BOX, GetCursorPosition());
        sStorage->state++;
        break;
    case 2:
        if (!sub_080D0AB8())
        {
            StartCursorAnim(3);
            sub_080CD888();
            PrintCursorMonInfo();
            PrintStorageActionText(29);
            sStorage->state++;
        }
        break;
    case 3:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 4:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_ShowItemInfo(void)
{
    switch (sStorage->state)
    {
    case 0:
        ClearBottomWindow();
        sStorage->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PlaySE(SE_WIN_OPEN);
            Cb_HandleMovingMonFromParty();
            sub_080D10B8();
            sStorage->state++;
        }
        break;
    case 2:
        if (!sub_080D10EC())
            sStorage->state++;
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sStorage->state++;
        break;
    case 4:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            PlaySE(SE_WIN_OPEN);
            sStorage->state++;
        }
        break;
    case 5:
        if (!sub_080D1184())
            sStorage->state++;
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_CloseBoxWhileHoldingItem(void)
{
    switch (sStorage->state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PrintStorageActionText(27);
        ShowYesNoWindow(0);
        sStorage->state = 1;
        break;
    case 1:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case -1:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            if (AddBagItem(sStorage->movingItemId, 1) == TRUE)
            {
                ClearBottomWindow();
                sStorage->state = 3;
            }
            else
            {
                PrintStorageActionText(26);
                sStorage->state = 2;
            }
            break;
        }
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state = 5;
        }
        break;
    case 3:
        sub_080D0A34();
        sStorage->state = 4;
        break;
    case 4:
        if (!sub_080D0AB8())
        {
            StartCursorAnim(0);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void sub_080C8F0C(void)
{
    switch (sStorage->state)
    {
    case 0:
        CompactPartySlots();
        sub_080CB1C4();
        sStorage->state++;
        break;
    case 1:
        if (GetNumPartySpritesCompacting() == 0)
        {
            sub_080CA384();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_PrintCantStoreMail(void)
{
    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(30);
        sStorage->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            sStorage->state++;
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            sStorage->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetPSSCallback(Cb_MainPSS);
        break;
    }
}

void Cb_HandleBoxOptions(void)
{
    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(1);
        AddMenu();
        sStorage->state++;
        break;
    case 1:
        if (sub_080CF948())
            return;
        sStorage->state++;
        // fall through
    case 2:
        switch (sub_080CF94C())
        {
        case -1:
        case 0:
            sub_080CCA24(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 11:
            PlaySE(SE_SELECT);
            SetPSSCallback(Cb_NameBox);
            break;
        case 10:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_HandleWallpapers);
            break;
        case 9:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            SetPSSCallback(Cb_JumpBox);
            break;
        }
        break;
    }
}

void Cb_HandleWallpapers(void)
{
    switch (sStorage->state)
    {
    case 0:
        AddWallpaperSetsMenu();
        PrintStorageActionText(2);
        sStorage->state++;
        break;
    case 1:
        if (!sub_080CF948())
            sStorage->state++;
        break;
    case 2:
        sStorage->wallpaperSetId = sub_080CF94C();
        switch (sStorage->wallpaperSetId)
        {
        case -1:
            sub_080CCA24(TRUE);
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 18:
        case 19:
        case 20:
        case 21:
            PlaySE(SE_SELECT);
            RemoveMenu();
            sStorage->wallpaperSetId -= 18;
            sStorage->state++;
            break;
        case 22:
            PlaySE(SE_SELECT);
            sStorage->wallpaperId = 16;
            RemoveMenu();
            ClearBottomWindow();
            sStorage->state = 6;
            break;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            AddWallpapersMenu((u8)sStorage->wallpaperSetId);
            PrintStorageActionText(3);
            sStorage->state++;
        }
        break;
    case 4:
        sStorage->wallpaperId = sub_080CF94C();
        switch (sStorage->wallpaperId)
        {
        case -2:
            break;
        case -1:
            ClearBottomWindow();
            sStorage->state = 0;
            break;
        default:
            PlaySE(SE_SELECT);
            ClearBottomWindow();
            sStorage->wallpaperId -= 23;
            SetWallpaperForCurrentBox((u8)sStorage->wallpaperId);
            sStorage->state++;
            break;
        }
        break;
    case 5:
        if (!DoWallpaperGfxChange())
        {
            sub_080CCA24(TRUE);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetWallpaperForCurrentBox((u8)sStorage->wallpaperId);
            sStorage->state = 5;
        }
        break;
    }
}

void Cb_JumpBox(void)
{
    switch (sStorage->state)
    {
    case 0:
        PrintStorageActionText(5);
        sub_080C7080(&sStorage->chooseBoxMenu, 10, 0xDAC7, 3, FALSE);
        sub_080C716C(StorageGetCurrentBox());
        sStorage->state++;
        break;
    case 1:
        sStorage->newCurrBoxId = HandleBoxChooseSelectionInput();
        switch (sStorage->newCurrBoxId)
        {
        case 0xC8:
            break;
        default:
            ClearBottomWindow();
            sub_080C717C();
            sub_080C7128();
            if (sStorage->newCurrBoxId == 0xC9 || sStorage->newCurrBoxId == StorageGetCurrentBox())
            {
                sub_080CCA24(TRUE);
                SetPSSCallback(Cb_MainPSS);
            }
            else
            {
                sStorage->state++;
            }
            break;
        }
        break;
    case 2:
        SetUpScrollToBox((u8)sStorage->newCurrBoxId);
        sStorage->state++;
        break;
    case 3:
        if (!ScrollToBox())
        {
            SetCurrentBox((u8)sStorage->newCurrBoxId);
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    }
}

void Cb_NameBox(void)
{
    switch (sStorage->state)
    {
    case 0:
        sub_080CDFDC();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_20399AF = 1;
            sStorage->screenChangeType = 2;
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_ShowMonSummary(void)
{
    switch (sStorage->state)
    {
    case 0:
        sub_080CE064();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_20399AF = 0;
            sStorage->screenChangeType = 1;
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_GiveItemFromBag(void)
{
    switch (sStorage->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sStorage->state++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            gUnknown_20399AF = 2;
            sStorage->screenChangeType = 3;
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_OnCloseBoxPressed(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintStorageActionText(15);
            sStorage->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintStorageActionText(0);
            ShowYesNoWindow(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case -1:
        case 1:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 0:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sStorage->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 1);
        sStorage->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            sub_080CA444();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sStorage->screenChangeType = 0;
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
        }
        break;
    }
}

void Cb_OnBPressed(void)
{
    switch (sStorage->state)
    {
    case 0:
        if (IsMonBeingMoved())
        {
            PlaySE(SE_FAILURE);
            PrintStorageActionText(15);
            sStorage->state = 1;
        }
        else if (IsActiveItemMoving())
        {
            SetPSSCallback(Cb_CloseBoxWhileHoldingItem);
        }
        else
        {
            PlaySE(SE_SELECT);
            PrintStorageActionText(18);
            ShowYesNoWindow(0);
            sStorage->state = 2;
        }
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON | DPAD_ANY))
        {
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
        }
        break;
    case 2:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 0:
            ClearBottomWindow();
            SetPSSCallback(Cb_MainPSS);
            break;
        case 1:
        case -1:
            PlaySE(SE_PC_OFF);
            ClearBottomWindow();
            sStorage->state++;
            break;
        }
        break;
    case 3:
        ComputerScreenCloseEffect(20, 0, 0);
        sStorage->state++;
        break;
    case 4:
        if (!IsComputerScreenCloseEffectActive())
        {
            sub_080CA444();
            gPlayerPartyCount = CalculatePlayerPartyCount();
            sStorage->screenChangeType = 0;
            SetPSSCallback((void (*)(void))Cb_ChangeScreen);
        }
        break;
    }
}


void Cb_ChangeScreen(u8 taskId)
{
    struct BoxPokemon *boxMons;
    u8 mode;
    u8 monIndex;
    u8 maxMonIndex;
    u8 screenChangeType = sStorage->screenChangeType;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS && IsActiveItemMoving() == TRUE)
        sMovingItemId = GetMovingItemId();
    else
        sMovingItemId = ITEM_NONE;

    switch (screenChangeType)
    {
    case 0:
    default:
        FreePSSData();
        SetMainCallback2(CB2_ExitPokeStorage);
        break;
    case 1:
        boxMons = sStorage->summaryMon.box;
        monIndex = sStorage->summaryStartPos;
        maxMonIndex = sStorage->summaryMaxPos;
        mode = sStorage->summaryScreenMode;
        FreePSSData();
        ShowPokemonSummaryScreen(mode, boxMons, monIndex, maxMonIndex, CB2_ReturnToPokeStorage);
        break;
    case 2:
        FreePSSData();
        DoNamingScreen(1, GetBoxNamePtr(StorageGetCurrentBox()), 0, 0, 0, CB2_ReturnToPokeStorage);
        break;
    case 3:
        FreePSSData();
        GoToBagMenu(11, 0, CB2_ReturnToPokeStorage);
        break;
    }

    DestroyTask(taskId);
}

void GiveChosenBagItem(void)
{
    u16 itemId = gSpecialVar_ItemId;

    if (itemId != ITEM_NONE)
    {
        u8 pos = GetCursorPosition();

        if (gUnknown_20399AC)
            SetMonData(&gPlayerParty[pos], MON_DATA_HELD_ITEM, &itemId);
        else
            SetCurrentBoxMonData(pos, MON_DATA_HELD_ITEM, &itemId);

        RemoveBagItem(itemId, 1);
    }
}

void FreePSSData(void)
{
    TilemapUtil_Free();
    MultiMove_Free();
    Free(sStorage);
    sStorage = NULL;
    FreeAllWindowBuffers();
}

void SetScrollingBackground(void)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(3) | BGCNT_16COLOR | BGCNT_SCREENBASE(31));
    DecompressAndLoadBgGfxUsingHeap(3, gUnknown_854BBFC, 0, 0, 0);
    LZ77UnCompVram(gUnknown_854BC94, (void *)BG_SCREEN_ADDR(31));
}

void ScrollBackground(void)
{
    ChangeBgX(3, 128, BG_COORD_ADD);
    ChangeBgY(3, 128, BG_COORD_SUB);
}

void LoadPSSMenuGfx(void)
{
    InitBgsFromTemplates(0, gUnknown_854C9E4, 4);
    DecompressAndLoadBgGfxUsingHeap(1, gUnknown_854BF9C, 0, 0, 0);
    LZ77UnCompWram(gUnknown_854BDC0, sStorage->displayMenuTilemapBuffer);
    SetBgTilemapBuffer(1, sStorage->displayMenuTilemapBuffer);
    ShowBg(1);
    ScheduleBgCopyTilemapToVram(1);
}

bool8 InitPokeStorageWindows(void)
{
    if (!InitWindows(sPSSWindowTemplates))
        return FALSE;
    DeactivateAllTextPrinters();
    return TRUE;
}

void LoadWaveformSpritePalette(void)
{
    LoadSpritePalette(&sWaveformSpritePalette);
}

void sub_080C994C(void)
{
    LoadPalette(gUnknown_854BEFC, BG_PLTT_ID(0), 0x20);
    LoadPalette(gUnknown_854BF1C, BG_PLTT_ID(2), 0x20);
    LoadPalette(gUnknown_854C9A4, BG_PLTT_ID(15), 0x20);
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        LoadPalette(gUnknown_854BF5C, BG_PLTT_ID(3), 0x20);
    else
        LoadPalette(gUnknown_854BF7C, BG_PLTT_ID(3), 0x20);

    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(30));
    LoadCursorMonSprite();
    sub_080C99C8();
    sub_080C9A38();
    RefreshCursorMonData();
}

void sub_080C99C8(void)
{
    sStorage->markingComboSprite = CreateMonMarkingComboSprite(0x10, 0xDAC8, NULL);
    sStorage->markingComboSprite->oam.priority = 1;
    sStorage->markingComboSprite->subpriority = 1;
    sStorage->markingComboSprite->x = 40;
    sStorage->markingComboSprite->y = 150;
    sStorage->markingComboTilesPtr = (void *)OBJ_VRAM0 + 32 * GetSpriteTileStartByTag(0x10);
}

void sub_080C9A38(void)
{
    u16 i;
    struct SpriteSheet sheet = gUnknown_854C9FC;

    LoadSpriteSheet(&sheet);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_854CB6C, i * 63 + 8, 9, 2);
        sStorage->waveformSprites[i] = &gSprites[spriteId];
    }
}

void RefreshCursorMonData(void)
{
    LoadCursorMonGfx(sStorage->displayMonSpecies, sStorage->displayMonPersonality);
    PrintCursorMonInfo();
    sub_080C9EC0();
    ScheduleBgCopyTilemapToVram(0);
}

void BoxSetMosaic(void)
{
    RefreshCursorMonData();
    if (sStorage->displayMonSprite)
    {
        sStorage->displayMonSprite->oam.mosaic = TRUE;
        sStorage->displayMonSprite->data[0] = 10;
        sStorage->displayMonSprite->data[1] = 1;
        sStorage->displayMonSprite->callback = sub_080C9B44;
        SetGpuReg(REG_OFFSET_MOSAIC, (sStorage->displayMonSprite->data[0] << 12) | (sStorage->displayMonSprite->data[0] << 8));
    }
}

u8 sub_080C9B2C(void)
{
    return sStorage->displayMonSprite->oam.mosaic;
}

void sub_080C9B44(struct Sprite *sprite)
{
    sprite->data[0] -= sprite->data[1];
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;
    SetGpuReg(REG_OFFSET_MOSAIC, (sprite->data[0] << 12) | (sprite->data[0] << 8));
    if (sprite->data[0] == 0)
    {
        sprite->oam.mosaic = FALSE;
        sprite->callback = SpriteCallbackDummy;
    }
}

void LoadCursorMonSprite(void)
{
    u16 i;
    u16 tileStart;
    u8 palSlot;
    u8 spriteId;
    struct SpriteSheet sheet = {sStorage->tileBuffer, MON_PIC_SIZE, 2};
    struct SpritePalette palette = {sStorage->displayMonPalBuffer, 0xDAC6};
    struct SpriteTemplate template = gUnknown_854CA04;

    for (i = 0; i < MON_PIC_SIZE; i++)
        sStorage->tileBuffer[i] = 0;
    for (i = 0; i < 16; i++)
        sStorage->displayMonPalBuffer[i] = 0;

    sStorage->displayMonSprite = NULL;

    do
    {
        tileStart = LoadSpriteSheet(&sheet);
        if (tileStart == 0)
            break;

        palSlot = LoadSpritePalette(&palette);
        if (palSlot == 0xFF)
            break;

        spriteId = CreateSprite(&template, 40, 48, 0);
        if (spriteId == MAX_SPRITES)
            break;

        sStorage->displayMonSprite = &gSprites[spriteId];
        sStorage->displayMonPalOffset = OBJ_PLTT_ID(palSlot);
        sStorage->displayMonTilePtr = (void *)OBJ_VRAM0 + tileStart * TILE_SIZE_4BPP;
    } while (0);

    if (sStorage->displayMonSprite == NULL)
    {
        FreeSpriteTilesByTag(2);
        FreeSpritePaletteByTag(0xDAC6);
    }
}

void LoadCursorMonGfx(u16 species, u32 personality)
{
    if (sStorage->displayMonSprite == NULL)
        return;

    if (species != SPECIES_NONE)
    {
        LoadSpecialPokePic(&gMonFrontPicTable[species], sStorage->tileBuffer, species, personality, TRUE);
        LZ77UnCompWram(sStorage->displayMonPalette, sStorage->displayMonPalBuffer);
        CpuCopy32(sStorage->tileBuffer, sStorage->displayMonTilePtr, MON_PIC_SIZE);
        LoadPalette(sStorage->displayMonPalBuffer, sStorage->displayMonPalOffset, PLTT_SIZE_4BPP);
        sStorage->displayMonSprite->invisible = FALSE;
    }
    else
    {
        sStorage->displayMonSprite->invisible = TRUE;
    }
}

void PrintCursorMonInfo(void)
{
    u16 i;
    u16 y;

    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        for (i = 0, y = 0; i < 3; i++, y += 13)
            AddTextPrinterParameterized(0, 1, &sStorage->displayMonNameText[i * 36], (i == 2) ? 4 : 0, y, 0xff, NULL);

        AddTextPrinterParameterized(0, 0, sStorage->displayMonItemName, 0, y + 2, 0xff, NULL);
    }
    else
    {
        AddTextPrinterParameterized(0, 0, sStorage->displayMonItemName, 0, 0, 0xff, NULL);
        for (i = 0, y = 15; i < 3; i++, y += 13)
            AddTextPrinterParameterized(0, 1, &sStorage->displayMonNameText[i * 36], (i == 2) ? 4 : 0, y, 0xff, NULL);
    }

    CopyWindowToVram(0, COPYWIN_GFX);
    if (sStorage->displayMonSpecies != SPECIES_NONE)
    {
        UpdateMonMarkingTiles(sStorage->displayMonMarkings, sStorage->markingComboTilesPtr);
        sStorage->markingComboSprite->invisible = FALSE;
    }
    else
    {
        sStorage->markingComboSprite->invisible = TRUE;
    }
}

void sub_080C9EC0(void)
{
    u16 i;

    if (sStorage->displayMonSpecies != SPECIES_NONE)
    {
        sub_080D204C(0, 0, 0, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnimIfDifferent(sStorage->waveformSprites[i], i * 2 + 1);
    }
    else
    {
        sub_080D204C(0, 0, 2, 8, 2);
        for (i = 0; i < 2; i++)
            StartSpriteAnim(sStorage->waveformSprites[i], i * 2);
    }

    sub_080D21B8(0);
    ScheduleBgCopyTilemapToVram(1);
}

void sub_080C9F68(void)
{
    LZ77UnCompWram(gUnknown_854C65C, sStorage->partyMenuTilemapBuffer);
    LoadPalette(gUnknown_854BF3C, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    sub_080D1EE4(1, 1, sStorage->partyMenuTilemapBuffer, 12, 22);
    sub_080D1EE4(2, 1, gUnknown_854C70C, 9, 4);
    sub_080D2010(1, 10, 0);
    sub_080D2010(2, 21, 0);
    sub_080CA2D8();
    if (gUnknown_20399AC)
    {
        UpdateCloseBoxButtonTilemap(TRUE);
        CreatePartyMonsSprites(TRUE);
        sub_080D21B8(2);
        sub_080D21B8(1);
    }
    else
    {
        sub_080D204C(1, 0, 20, 12, 2);
        UpdateCloseBoxButtonTilemap(TRUE);
        sub_080D21B8(1);
        sub_080D21B8(2);
    }

    ScheduleBgCopyTilemapToVram(1);
    sStorage->closeBoxFlashing = FALSE;
}


void SetUpShowPartyMenu(void)
{
    sStorage->partyMenuUnused1 = 20;
    sStorage->partyMenuY = 2;
    sStorage->partyMenuMoveTimer = 0;
    CreatePartyMonsSprites(FALSE);
}
bool8 ShowPartyMenu(void)
{
    if (sStorage->partyMenuMoveTimer == 20)
        return FALSE;

    sStorage->partyMenuUnused1--;
    sStorage->partyMenuY++;
    sub_080D2094(1, 3, 1);
    sub_080D21B8(1);
    ScheduleBgCopyTilemapToVram(1);
    sub_080CB364(8);
    if (++sStorage->partyMenuMoveTimer == 20)
    {
        gUnknown_20399AC = TRUE;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
void SetUpHidePartyMenu(void)
{
    sStorage->partyMenuUnused1 = 0;
    sStorage->partyMenuY = 22;
    sStorage->partyMenuMoveTimer = 0;
    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
        sub_080D0A6C();
}
bool8 HidePartyMenu(void)
{
    if (sStorage->partyMenuMoveTimer != 20)
    {
        sStorage->partyMenuUnused1++;
        sStorage->partyMenuY--;
        sub_080D2094(1, 3, -1);
        sub_080D21B8(1);
        FillBgTilemapBufferRect_Palette0(1, 0x100, 10, sStorage->partyMenuY, 12, 1);
        sub_080CB364(-8);
        if (++sStorage->partyMenuMoveTimer != 20)
        {
            ScheduleBgCopyTilemapToVram(1);
            return TRUE;
        }
        else
        {
            gUnknown_20399AC = FALSE;
            DestroyAllPartyMonIcons();
            CompactPartySlots();
            sub_080D204C(2, 0, 0, 9, 2);
            sub_080D21B8(2);
            ScheduleBgCopyTilemapToVram(1);
            return FALSE;
        }
    }

    return FALSE;
}
void UpdateCloseBoxButtonTilemap(bool8 state)
{
    if (state)
        sub_080D204C(2, 0, 0, 9, 2);
    else
        sub_080D204C(2, 0, 2, 9, 2);

    sub_080D21B8(2);
    ScheduleBgCopyTilemapToVram(1);
}
void sub_080CA224(void)
{
    sStorage->closeBoxFlashing = TRUE;
    sStorage->closeBoxFlashTimer = 30;
    sStorage->closeBoxFlashState = TRUE;
}
void StopFlashingCloseBoxButton(void)
{
    if (sStorage->closeBoxFlashing)
    {
        sStorage->closeBoxFlashing = FALSE;
        UpdateCloseBoxButtonTilemap(TRUE);
    }
}

void UpdateCloseBoxButtonFlash(void)
{
    if (sStorage->closeBoxFlashing && ++sStorage->closeBoxFlashTimer > 30)
    {
        sStorage->closeBoxFlashTimer = 0;
        sStorage->closeBoxFlashState = (sStorage->closeBoxFlashState == FALSE);
        UpdateCloseBoxButtonTilemap(sStorage->closeBoxFlashState);
    }
}
void sub_080CA2D8(void)
{
    u8 i;

    for (i = 1; i < PARTY_SIZE; i++)
    {
        s32 species = GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES);
        sub_080CA30C(i, species != SPECIES_NONE);
    }
}

void sub_080CA30C(u8 partyId, bool8 hasMon)
{
    u16 i;
    u16 j;
    u16 index;
    const u16 *data;

    if (hasMon)
        data = gUnknown_854C754;
    else
        data = gUnknown_854C76C;

    index = 3 * (3 * (partyId - 1) + 1);
    index *= 4;
    index += 7;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            sStorage->partyMenuTilemapBuffer[index + j] = data[j];

        data += 4;
        index += 12;
    }
}

void sub_080CA384(void)
{
    sub_080CA2D8();
    sub_080D204C(1, 0, 0, 12, 22);
    sub_080D21B8(1);
    ScheduleBgCopyTilemapToVram(1);
}
void SetUpDoShowPartyMenu(void)
{
    sStorage->showPartyMenuState = 0;
    PlaySE(SE_WIN_OPEN);
    SetUpShowPartyMenu();
}

bool8 DoShowPartyMenu(void)
{
    switch (sStorage->showPartyMenuState)
    {
    case 0:
        if (!ShowPartyMenu())
        {
            sub_080CD41C();
            sStorage->showPartyMenuState++;
        }
        break;
    case 1:
        if (!sub_080CCDD0())
        {
            if (sStorage->setMosaic)
                BoxSetMosaic();
            sStorage->showPartyMenuState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}
void sub_080CA444(void)
{
    if (sLastUsedBox != StorageGetCurrentBox())
    {
        FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
        VarSet(VAR_PC_BOX_TO_SEND_MON, StorageGetCurrentBox());
    }
}
void sub_080CA480(void)
{
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(29));
    LoadUserWindowBorderGfx(1, 2, BG_PLTT_ID(13));
    FillBgTilemapBufferRect(0, 0, 0, 0, 32, 20, 17);
    CopyBgTilemapBufferToVram(0);
}
void PrintStorageActionText(u8 id)
{
    u8 *txtPtr;

    DynamicPlaceholderTextUtil_Reset();
    switch (gUnknown_854CA1C[id].format)
    {
    case MSG_VAR_NONE:
        break;
    case MSG_VAR_MON_NAME_1:
    case MSG_VAR_MON_NAME_2:
    case MSG_VAR_MON_NAME_3:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->displayMonName);
        break;
    case MSG_VAR_RELEASE_MON_1:
    case MSG_VAR_RELEASE_MON_2:
    case MSG_VAR_RELEASE_MON_3:
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->releaseMonName);
        break;
    case MSG_VAR_ITEM_NAME:
        if (IsActiveItemMoving())
            txtPtr = StringCopy(sStorage->itemName, GetMovingItemName());
        else
            txtPtr = StringCopy(sStorage->itemName, sStorage->displayMonItemName);

        while (*(txtPtr - 1) == CHAR_SPACE)
            txtPtr--;

        *txtPtr = EOS;
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sStorage->itemName);
        break;
    }

    DynamicPlaceholderTextUtil_ExpandPlaceholders(sStorage->messageText, gUnknown_854CA1C[id].text);
    FillWindowPixelBuffer(1, PIXEL_FILL(1));
    AddTextPrinterParameterized(1, 1, sStorage->messageText, 0, 2, 0xff, NULL);
    DrawTextBorderOuter(1, 2, 14);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_GFX);
    ScheduleBgCopyTilemapToVram(0);
}

void ShowYesNoWindow(s8 cursorPos)
{
    CreateYesNoMenuAtPos(&gUnknown_854CB14, 1, 2, 2, 11, 14, 0);
    Menu_MoveCursorNoWrapAround(cursorPos);
}
void ClearBottomWindow(void)
{
    ClearStdWindowAndFrameToTransparent(1, 0);
    ScheduleBgCopyTilemapToVram(0);
}

void AddWallpaperSetsMenu(void)
{
    InitMenu();
    SetMenuText(MENU_SCENERY_1);
    SetMenuText(MENU_SCENERY_2);
    SetMenuText(MENU_SCENERY_3);
    SetMenuText(MENU_ETCETERA);
    if (IsWaldaWallpaperUnlocked())
        SetMenuText(MENU_FRIENDS);
    AddMenu();
}
void AddWallpapersMenu(u8 wallpaperSet)
{
    InitMenu();
    switch (wallpaperSet)
    {
    case MENU_SCENERY_1 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_FOREST);
        SetMenuText(MENU_CITY);
        SetMenuText(MENU_DESERT);
        SetMenuText(MENU_SAVANNA);
        break;
    case MENU_SCENERY_2 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_CRAG);
        SetMenuText(MENU_VOLCANO);
        SetMenuText(MENU_SNOW);
        SetMenuText(MENU_CAVE);
        break;
    case MENU_SCENERY_3 - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_BEACH);
        SetMenuText(MENU_SEAFLOOR);
        SetMenuText(MENU_RIVER);
        SetMenuText(MENU_SKY);
        break;
    case MENU_ETCETERA - MENU_WALLPAPER_SETS_START:
        SetMenuText(MENU_POLKADOT);
        SetMenuText(MENU_POKECENTER);
        SetMenuText(MENU_MACHINE);
        SetMenuText(MENU_SIMPLE);
        break;
    }
    AddMenu();
}
u8 GetCurrentBoxOption(void)
{
    return sCurrentBoxOption;
}

void sub_080CA720(void)
{
    if (!IsCursorOnBoxTitle())
    {
        if (gUnknown_20399AC)
            sub_080D062C(CURSOR_AREA_IN_PARTY, GetCursorPosition());
        else
            sub_080D062C(CURSOR_AREA_IN_BOX, GetCursorPosition());
    }

    if (sMovingItemId != ITEM_NONE)
    {
        sub_080D07D8(sMovingItemId);
        StartCursorAnim(3);
    }
}
void sub_080CA778(void)
{
    u16 i;

    LoadMonIconPalettes();
    for (i = 0; i < MAX_MON_ICONS; i++)
        sStorage->numIconsPerSpecies[i] = 0;
    for (i = 0; i < MAX_MON_ICONS; i++)
        sStorage->iconSpeciesList[i] = SPECIES_NONE;
    for (i = 0; i < PARTY_SIZE; i++)
        sStorage->partySprites[i] = NULL;
    for (i = 0; i < IN_BOX_COUNT; i++)
        sStorage->boxMonsSprites[i] = NULL;

    sStorage->movingMonSprite = NULL;
    sStorage->unkUnused1 = 0;
}
u8 GetMonIconPriorityByCursorPos(void)
{
    u8 inBox = IsCursorInBox();

    return (inBox ? 2 : 1);
}

void CreateMovingMonIcon(void)
{
    u32 personality = GetMonData3(&sStorage->movingMon, MON_DATA_PERSONALITY);
    u16 species = GetMonData3(&sStorage->movingMon, MON_DATA_SPECIES_OR_EGG);
    u8 priority = GetMonIconPriorityByCursorPos();

    sStorage->movingMonSprite = sub_080CBAA4(species, personality, 0, 0, priority, 7);
    sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
}
void sub_080CA89C(u8 boxId)
{
    u8 boxPosition;
    u16 i;
    u16 j;
    u16 count;
    u16 species;
    u32 personality;

    count = 0;
    boxPosition = 0;

    for (i = 0; i < IN_BOX_ROWS; i++)
    {
        for (j = 0; j < IN_BOX_COLUMNS; j++)
        {
            species = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_SPECIES_OR_EGG);
            if (species != SPECIES_NONE)
            {
                personality = GetBoxMonDataAt(boxId, boxPosition, MON_DATA_PERSONALITY);
                sStorage->boxMonsSprites[count] = sub_080CBAA4(species, personality, 8 * (3 * j) + 100, 8 * (3 * i) + 44, 2, 19 - j);
            }
            else
            {
                sStorage->boxMonsSprites[count] = NULL;
            }
            boxPosition++;
            count++;
        }
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (boxPosition = 0; boxPosition < IN_BOX_COUNT; boxPosition++)
        {
            if (GetBoxMonDataAt(boxId, boxPosition, MON_DATA_HELD_ITEM) == ITEM_NONE)
                sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}
void sub_080CA9B4(u8 boxPosition)
{
    u16 species = GetCurrentBoxMonData(boxPosition, MON_DATA_SPECIES_OR_EGG);

    if (species != SPECIES_NONE)
    {
        s16 x = 8 * (3 * (boxPosition % IN_BOX_COLUMNS)) + 100;
        s16 y = 8 * (3 * (boxPosition / IN_BOX_COLUMNS)) + 44;
        u32 personality = GetCurrentBoxMonData(boxPosition, MON_DATA_PERSONALITY);

        sStorage->boxMonsSprites[boxPosition] = sub_080CBAA4(species, personality, x, y, 2, 19 - (boxPosition % IN_BOX_COLUMNS));
        if (sStorage->boxOption == OPTION_MOVE_ITEMS)
            sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
    }
}
void sub_080CAA64(s16 speed)
{
    u16 i;

    for (i = 0; i < IN_BOX_COUNT; i++)
    {
        if (sStorage->boxMonsSprites[i] != NULL)
        {
            sStorage->boxMonsSprites[i]->data[2] = speed;
            sStorage->boxMonsSprites[i]->data[4] = 1;
            sStorage->boxMonsSprites[i]->callback = sub_080CAAEC;
        }
    }
}
void sub_080CAAA8(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
        sprite->x += sprite->data[2];
    }
    else
    {
        sStorage->iconScrollNumIncoming--;
        sprite->x = sprite->data[3];
        sprite->callback = SpriteCallbackDummy;
    }
}
void sub_080CAAEC(struct Sprite *sprite)
{
    if (sprite->data[4] != 0)
    {
        sprite->data[4]--;
    }
    else
    {
        sprite->x += sprite->data[2];
        sprite->data[5] = sprite->x + sprite->x2;

        if (sprite->data[5] <= 68 || sprite->data[5] >= 252)
            sprite->callback = SpriteCallbackDummy;
    }
}
void DestroyAllIconsInRow(u8 column)
{
    u16 row;
    u8 boxPosition = column;

    for (row = 0; row < IN_BOX_ROWS; row++)
    {
        if (sStorage->boxMonsSprites[boxPosition] != NULL)
        {
            DestroyBoxMonIcon(sStorage->boxMonsSprites[boxPosition]);
            sStorage->boxMonsSprites[boxPosition] = NULL;
        }
        boxPosition += IN_BOX_COLUMNS;
    }
}
u8 sub_080CAB6C(u8 column, u16 distance, s16 speed)
{
    s32 i;
    u16 y = 44;
    s16 xDest = 8 * (3 * column) + 100;
    u16 x = xDest - ((distance + 1) * speed);
    u8 subpriority = 19 - column;
    u8 iconsCreated = 0;
    u8 boxPosition = column;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < IN_BOX_ROWS; i++)
        {
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                sStorage->boxMonsSprites[boxPosition] = sub_080CBAA4(sStorage->boxSpecies[boxPosition],
                                                                     sStorage->boxPersonalities[boxPosition],
                                                                     x, y, 2, subpriority);
                if (sStorage->boxMonsSprites[boxPosition] != NULL)
                {
                    sStorage->boxMonsSprites[boxPosition]->data[1] = distance;
                    sStorage->boxMonsSprites[boxPosition]->data[2] = speed;
                    sStorage->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sStorage->boxMonsSprites[boxPosition]->callback = sub_080CAAA8;
                    iconsCreated++;
                }
            }
            boxPosition += IN_BOX_COLUMNS;
            y += 24;
        }
    }
    else
    {
        for (i = 0; i < IN_BOX_ROWS; i++)
        {
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
            {
                sStorage->boxMonsSprites[boxPosition] = sub_080CBAA4(sStorage->boxSpecies[boxPosition],
                                                                     sStorage->boxPersonalities[boxPosition],
                                                                     x, y, 2, subpriority);
                if (sStorage->boxMonsSprites[boxPosition] != NULL)
                {
                    sStorage->boxMonsSprites[boxPosition]->data[1] = distance;
                    sStorage->boxMonsSprites[boxPosition]->data[2] = speed;
                    sStorage->boxMonsSprites[boxPosition]->data[3] = xDest;
                    sStorage->boxMonsSprites[boxPosition]->callback = sub_080CAAA8;
                    if (GetBoxMonDataAt(sStorage->incomingBoxId, boxPosition, MON_DATA_HELD_ITEM) == ITEM_NONE)
                        sStorage->boxMonsSprites[boxPosition]->oam.objMode = ST_OAM_OBJ_BLEND;
                    iconsCreated++;
                }
            }
            boxPosition += IN_BOX_COLUMNS;
            y += 24;
        }
    }

    return iconsCreated;
}
void sub_080CAD40(u8 boxId, s8 direction)
{
    sStorage->iconScrollState = 0;
    sStorage->iconScrollToBoxId = boxId;
    sStorage->iconScrollDirection = direction;
    sStorage->iconScrollDistance = 32;
    sStorage->iconScrollSpeed = -(6 * direction);
    sStorage->iconScrollNumIncoming = 0;
    SetBoxSpeciesAndPersonalities(boxId);
    if (direction > 0)
        sStorage->iconScrollCurColumn = 0;
    else
        sStorage->iconScrollCurColumn = IN_BOX_COLUMNS - 1;

    sStorage->iconScrollPos = (24 * sStorage->iconScrollCurColumn) + 100;
    sub_080CAA64(sStorage->iconScrollSpeed);
}
bool8 sub_080CADF8(void)
{
    if (sStorage->iconScrollDistance != 0)
        sStorage->iconScrollDistance--;

    switch (sStorage->iconScrollState)
    {
    case 0:
        sStorage->iconScrollPos += sStorage->iconScrollSpeed;
        if (sStorage->iconScrollPos <= 64 || sStorage->iconScrollPos >= 252)
        {
            DestroyAllIconsInRow(sStorage->iconScrollCurColumn);
            sStorage->iconScrollPos += sStorage->iconScrollDirection * 24;
            sStorage->iconScrollState++;
        }
        break;
    case 1:
        sStorage->iconScrollPos += sStorage->iconScrollSpeed;
        sStorage->iconScrollNumIncoming += sub_080CAB6C(sStorage->iconScrollCurColumn, sStorage->iconScrollDistance, sStorage->iconScrollSpeed);

        if ((sStorage->iconScrollDirection > 0 && sStorage->iconScrollCurColumn == IN_BOX_COLUMNS - 1)
         || (sStorage->iconScrollDirection < 0 && sStorage->iconScrollCurColumn == 0))
        {
            sStorage->iconScrollState++;
        }
        else
        {
            sStorage->iconScrollCurColumn += sStorage->iconScrollDirection;
            sStorage->iconScrollState = 0;
        }
        break;
    case 2:
        if (sStorage->iconScrollNumIncoming == 0)
        {
            sStorage->iconScrollDistance++;
            return FALSE;
        }
        break;
    default:
        return FALSE;
    }

    return TRUE;
}
void SetBoxSpeciesAndPersonalities(u8 a)
{
    s32 i, j, boxPosition;

    boxPosition = 0;
    for (i = 0; i < IN_BOX_ROWS; i++)
    {
        for (j = 0; j < IN_BOX_COLUMNS; j++)
        {
            sStorage->boxSpecies[boxPosition] = GetBoxMonDataAt(a, boxPosition, MON_DATA_SPECIES_OR_EGG);
            if (sStorage->boxSpecies[boxPosition] != SPECIES_NONE)
                sStorage->boxPersonalities[boxPosition] = GetBoxMonDataAt(a, boxPosition, MON_DATA_PERSONALITY);
            boxPosition++;
        }
    }

    sStorage->incomingBoxId = a;
}

void DestroyBoxMonIconAtPosition(u8 a)
{
    if (sStorage->boxMonsSprites[a] != NULL)
    {
        DestroyBoxMonIcon(sStorage->boxMonsSprites[a]);
        sStorage->boxMonsSprites[a] = NULL;
    }
}

void SetBoxMonIconObjMode(u8 a, u8 b)
{
    if (sStorage->boxMonsSprites[a] != NULL)
        sStorage->boxMonsSprites[a]->oam.objMode = b;
}

void CreatePartyMonsSprites(bool8 visible)
{
    u16 i, count;
    u16 species = GetMonData(&gPlayerParty[0], MON_DATA_SPECIES_OR_EGG);
    u32 personality = GetMonData(&gPlayerParty[0], MON_DATA_PERSONALITY);

    sStorage->partySprites[0] = sub_080CBAA4(species, personality, 104, 64, 1, 12);
    count = 1;
    for (i = 1; i < PARTY_SIZE; i++)
    {
        species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE)
        {
            personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            sStorage->partySprites[i] = sub_080CBAA4(species, personality, 152, 8 * (3 * (i - 1)) + 16, 1, 12);
            count++;
        }
        else
        {
            sStorage->partySprites[i] = NULL;
        }
    }

    if (!visible)
    {
        for (i = 0; i < count; i++)
        {
            sStorage->partySprites[i]->y -= DISPLAY_HEIGHT;
            sStorage->partySprites[i]->invisible = TRUE;
        }
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sStorage->partySprites[i] != NULL && GetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM) == ITEM_NONE)
                sStorage->partySprites[i]->oam.objMode = ST_OAM_OBJ_BLEND;
        }
    }
}

void sub_080CB1C4(void)
{
    u16 i, targetSlot;

    sStorage->numPartyToCompact = 0;
    for (i = 0, targetSlot = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            if (i != targetSlot)
            {
                sub_080CB244(sStorage->partySprites[i], targetSlot);
                sStorage->partySprites[i] = NULL;
                sStorage->numPartyToCompact++;
            }
            targetSlot++;
        }
    }
}

u8 GetNumPartySpritesCompacting(void)
{
    return sStorage->numPartyToCompact;
}


void sub_080CB244(struct Sprite *sprite, u16 partyId)
{
    s16 x, y;

    sprite->data[1] = partyId;
    if (partyId == 0)
        x = 104, y = 64;
    else
        x = 152, y = 8 * (3 * (partyId - 1)) + 16;

    sprite->data[2] = (u16)(sprite->x) * 8;
    sprite->data[3] = (u16)(sprite->y) * 8;
    sprite->data[4] = ((x * 8) - sprite->data[2]) / 8;
    sprite->data[5] = ((y * 8) - sprite->data[3]) / 8;
    sprite->data[6] = 8;
    sprite->callback = sub_080CB2B0;
}

void sub_080CB2B0(struct Sprite *sprite)
{
    if (sprite->data[6] != 0)
    {
        s16 x = sprite->data[2] += sprite->data[4];
        s16 y = sprite->data[3] += sprite->data[5];
        sprite->x = x / 8u;
        sprite->y = y / 8u;
        sprite->data[6]--;
    }
    else
    {
        if (sprite->data[1] == 0)
        {
            sprite->x = 104;
            sprite->y = 64;
        }
        else
        {
            sprite->x = 152;
            sprite->y = 8 * (3 * (sprite->data[1] - 1)) + 16;
        }
        sprite->callback = SpriteCallbackDummy;
        sStorage->partySprites[sprite->data[1]] = sprite;
        sStorage->numPartyToCompact--;
    }
}

void DestroyMovingMonIcon(void)
{
    if (sStorage->movingMonSprite != NULL)
    {
        DestroyBoxMonIcon(sStorage->movingMonSprite);
        sStorage->movingMonSprite = NULL;
    }
}
void sub_080CB364(s16 yDelta)
{
    u16 i, posY;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            sStorage->partySprites[i]->y += yDelta;
            posY = sStorage->partySprites[i]->y + sStorage->partySprites[i]->y2 + sStorage->partySprites[i]->centerToCornerVecY;
            posY += 16;
            if (posY > 192)
                sStorage->partySprites[i]->invisible = TRUE;
            else
                sStorage->partySprites[i]->invisible = FALSE;
        }
    }
}

void DestroyPartyMonIcon(u8 partyId)
{
    if (sStorage->partySprites[partyId] != NULL)
    {
        DestroyBoxMonIcon(sStorage->partySprites[partyId]);
        sStorage->partySprites[partyId] = NULL;
    }
}
void DestroyAllPartyMonIcons(void)
{
    u16 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sStorage->partySprites[i] != NULL)
        {
            DestroyBoxMonIcon(sStorage->partySprites[i]);
            sStorage->partySprites[i] = NULL;
        }
    }
}
void SetPartyMonIconObjMode(u8 partyId, u8 objMode)
{
    if (sStorage->partySprites[partyId] != NULL)
        sStorage->partySprites[partyId]->oam.objMode = objMode;
}
void sub_080CB488(u8 mode, u8 id)
{
    if (mode == MODE_PARTY)
    {
        sStorage->movingMonSprite = sStorage->partySprites[id];
        sStorage->partySprites[id] = NULL;
    }
    else if (mode == MODE_BOX)
    {
        sStorage->movingMonSprite = sStorage->boxMonsSprites[id];
        sStorage->boxMonsSprites[id] = NULL;
    }
    else
    {
        return;
    }

    sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
    sStorage->movingMonSprite->oam.priority = GetMonIconPriorityByCursorPos();
    sStorage->movingMonSprite->subpriority = 7;
}

void sub_080CB520(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
    {
        sStorage->partySprites[position] = sStorage->movingMonSprite;
        sStorage->partySprites[position]->oam.priority = 1;
        sStorage->partySprites[position]->subpriority = 12;
    }
    else
    {
        sStorage->boxMonsSprites[position] = sStorage->movingMonSprite;
        sStorage->boxMonsSprites[position]->oam.priority = 2;
        sStorage->boxMonsSprites[position]->subpriority = 19 - (position % IN_BOX_COLUMNS);
    }
    sStorage->movingMonSprite->callback = SpriteCallbackDummy;
    sStorage->movingMonSprite = NULL;
}

void sub_080CB5D0(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sStorage->shiftMonSpritePtr = &sStorage->partySprites[position];
    else
        sStorage->shiftMonSpritePtr = &sStorage->boxMonsSprites[position];

    sStorage->movingMonSprite->callback = SpriteCallbackDummy;
    sStorage->shiftTimer = 0;
}

bool8 sub_080CB638(void)
{
    if (sStorage->shiftTimer == 16)
        return FALSE;

    sStorage->shiftTimer++;
    if (sStorage->shiftTimer & 1)
    {
        (*sStorage->shiftMonSpritePtr)->y--;
        sStorage->movingMonSprite->y++;
    }

    (*sStorage->shiftMonSpritePtr)->x2 = gSineTable[sStorage->shiftTimer * 8] / 16;
    sStorage->movingMonSprite->x2 = -(gSineTable[sStorage->shiftTimer * 8] / 16);
    if (sStorage->shiftTimer == 8)
    {
        sStorage->movingMonSprite->oam.priority = (*sStorage->shiftMonSpritePtr)->oam.priority;
        sStorage->movingMonSprite->subpriority = (*sStorage->shiftMonSpritePtr)->subpriority;
        (*sStorage->shiftMonSpritePtr)->oam.priority = GetMonIconPriorityByCursorPos();
        (*sStorage->shiftMonSpritePtr)->subpriority = 7;
    }

    if (sStorage->shiftTimer == 16)
    {
        struct Sprite *sprite = sStorage->movingMonSprite;
        sStorage->movingMonSprite = (*sStorage->shiftMonSpritePtr);
        *sStorage->shiftMonSpritePtr = sprite;

        sStorage->movingMonSprite->callback = SpriteCB_HeldMon;
        (*sStorage->shiftMonSpritePtr)->callback = SpriteCallbackDummy;
    }

    return TRUE;
}

void sub_080CB788(u8 mode, u8 cursorPosition)
{
    switch (mode)
    {
    case MODE_PARTY:
        sStorage->releaseMonSpritePtr = &sStorage->partySprites[cursorPosition];
        break;
    case MODE_BOX:
        sStorage->releaseMonSpritePtr = &sStorage->boxMonsSprites[cursorPosition];
        break;
    case MODE_MOVE:
        sStorage->releaseMonSpritePtr = &sStorage->movingMonSprite;
        break;
    default:
        return;
    }

    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        InitSpriteAffineAnim(*sStorage->releaseMonSpritePtr);
        (*sStorage->releaseMonSpritePtr)->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        (*sStorage->releaseMonSpritePtr)->affineAnims = gUnknown_854CBCC;
        StartSpriteAffineAnim(*sStorage->releaseMonSpritePtr, 0);
    }
}

bool8 sub_080CB84C(void)
{
    if (*sStorage->releaseMonSpritePtr == NULL
     || (*sStorage->releaseMonSpritePtr)->invisible)
        return FALSE;

    if ((*sStorage->releaseMonSpritePtr)->affineAnimEnded)
        (*sStorage->releaseMonSpritePtr)->invisible = TRUE;

    return TRUE;
}

void sub_080CB894(void)
{
    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        FreeOamMatrix((*sStorage->releaseMonSpritePtr)->oam.matrixNum);
        DestroyBoxMonIcon(*sStorage->releaseMonSpritePtr);
        *sStorage->releaseMonSpritePtr = NULL;
    }
}

void sub_080CB8D8(void)
{
    if (*sStorage->releaseMonSpritePtr != NULL)
    {
        (*sStorage->releaseMonSpritePtr)->invisible = FALSE;
        StartSpriteAffineAnim(*sStorage->releaseMonSpritePtr, 1);
    }
}

bool8 sub_080CB914(void)
{
    if (sStorage->releaseMonSpritePtr == NULL)
        return FALSE;

    if ((*sStorage->releaseMonSpritePtr)->affineAnimEnded)
        sStorage->releaseMonSpritePtr = NULL;

    return TRUE;
}

void SetMovingMonPriority(u8 priority)
{
    sStorage->movingMonSprite->oam.priority = priority;
}

void SpriteCB_HeldMon(struct Sprite *sprite)
{
    sprite->x = sStorage->cursorSprite->x;
    sprite->y = sStorage->cursorSprite->y + sStorage->cursorSprite->y2 + 4;
}

u16 sub_080CB998(u16 species)
{
    u16 i, offset;

    for (i = 0; i < MAX_MON_ICONS; i++)
    {
        if (sStorage->iconSpeciesList[i] == species)
            break;
    }

    if (i == MAX_MON_ICONS)
    {
        for (i = 0; i < MAX_MON_ICONS; i++)
        {
            if (sStorage->iconSpeciesList[i] == 0)
                break;
        }

        if (i == MAX_MON_ICONS)
            return 0xFFFF;
    }

    sStorage->iconSpeciesList[i] = species;
    sStorage->numIconsPerSpecies[i]++;
    offset = 16 * i;
    CpuCopy32(GetMonIconTiles(species, TRUE), (void *)(OBJ_VRAM0) + offset * TILE_SIZE_4BPP, 0x200);

    return offset;
}

void sub_080CBA54(u16 species)
{
    u16 i;

    for (i = 0; i < MAX_MON_ICONS; i++)
    {
        if (sStorage->iconSpeciesList[i] == species)
        {
            if (--sStorage->numIconsPerSpecies[i] == 0)
                sStorage->iconSpeciesList[i] = SPECIES_NONE;
            break;
        }
    }
}

struct Sprite *sub_080CBAA4(u16 species, u32 personality, s16 x, s16 y, u8 oamPriority, u8 subpriority)
{
    u16 tileNum;
    u8 spriteId;
    struct SpriteTemplate template = gUnknown_854CB84;

    species = GetIconSpecies(species, personality);
    template.paletteTag = 0xDAC0 + gMonIconPaletteIndices[species];
    tileNum = sub_080CB998(species);
    if (tileNum == 0xFFFF)
        return NULL;

    spriteId = CreateSprite(&template, x, y, subpriority);
    if (spriteId == MAX_SPRITES)
    {
        sub_080CBA54(species);
        return NULL;
    }

    gSprites[spriteId].oam.tileNum = tileNum;
    gSprites[spriteId].oam.priority = oamPriority;
    gSprites[spriteId].data[0] = species;
    return &gSprites[spriteId];
}

void DestroyBoxMonIcon(struct Sprite *sprite)
{
    sub_080CBA54(sprite->data[0]);
    DestroySprite(sprite);
}

void sub_080CBBA0(u8 boxId)
{
    u8 taskId = CreateTask(sub_080CBBE4, 2);

    gTasks[taskId].data[2] = boxId;
}
bool8 sub_080CBBD0(void)
{
    return FuncIsActiveTask(sub_080CBBE4);
}
void sub_080CBBE4(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        sStorage->wallpaperOffset = 0;
        sStorage->bg2_X = 0;
        task->data[1] = RequestDma3Fill(0, sStorage->wallpaperBgTilemapBuffer, sizeof(sStorage->wallpaperBgTilemapBuffer), 1);
        break;
    case 1:
        if (CheckForSpaceForDma3Request(task->data[1]) == -1)
            return;

        SetBgTilemapBuffer(2, sStorage->wallpaperBgTilemapBuffer);
        ShowBg(2);
        break;
    case 2:
        LoadWallpaperGfx(task->data[2], 0);
        break;
    case 3:
        if (!WaitForWallpaperGfxLoad())
            return;

        sub_080CC3C4(task->data[2]);
        sub_080CC8A8();
        sub_080CA89C(task->data[2]);
        SetGpuReg(REG_OFFSET_BG2CNT, 0x5B0A);
        break;
    case 4:
        DestroyTask(taskId);
        break;
    default:
        task->data[0] = 0;
        return;
    }

    task->data[0]++;
}

void SetUpScrollToBox(u8 a)
{
    s8 direction = sub_080CBEB8(a);

    sStorage->scrollSpeed = (direction > 0) ? 6 : -6;
    sStorage->scrollUnused1 = (direction > 0) ? 1 : 2;
    sStorage->scrollTimer = 32;
    sStorage->scrollToBoxIdUnused = a;
    sStorage->scrollUnused2 = (direction <= 0) ? 5 : 0;
    sStorage->scrollDirectionUnused = direction;

    sStorage->scrollUnused3 = (direction > 0) ? 264 : 56;
    sStorage->scrollUnused4 = (direction <= 0) ? 5 : 0;
    sStorage->scrollUnused5 = 0;
    sStorage->scrollUnused6 = 2;
    sStorage->scrollToBoxId = a;
    sStorage->scrollDirection = direction;
    sStorage->scrollState = 0;
}

bool8 ScrollToBox(void)
{
    bool8 iconsScrolling;

    switch (sStorage->scrollState)
    {
    case 0:
        LoadWallpaperGfx(sStorage->scrollToBoxId, sStorage->scrollDirection);
        sStorage->scrollState++;
    case 1:
        if (!WaitForWallpaperGfxLoad())
            return TRUE;

        sub_080CAD40(sStorage->scrollToBoxId, sStorage->scrollDirection);
        sub_080CC57C(sStorage->scrollToBoxId, sStorage->scrollDirection);
        sub_080CC934(sStorage->scrollDirection);
        break;
    case 2:
        iconsScrolling = sub_080CADF8();
        if (sStorage->scrollTimer != 0)
        {
            sStorage->bg2_X += sStorage->scrollSpeed;
            if (--sStorage->scrollTimer != 0)
                return TRUE;
            sub_080CC76C();
            sub_080CC9D4();
        }
        return iconsScrolling;
    }

    sStorage->scrollState++;
    return TRUE;
}

s8 sub_080CBEB8(u8 boxId)
{
    u8 curBoxId = StorageGetCurrentBox();
    u8 steps = 0;

    while (curBoxId != boxId)
    {
        curBoxId++;
        if (curBoxId > TOTAL_BOXES_COUNT - 1)
            curBoxId = 0;
        steps++;
    }

    return (steps <= 6) ? 1 : -1;
}

void SetWallpaperForCurrentBox(u8 a)
{
    SetBoxWallpaper(StorageGetCurrentBox(), a);
    sStorage->wallpaperChangeState = 0;
}

bool8 DoWallpaperGfxChange(void)
{
    switch (sStorage->wallpaperChangeState)
    {
    case 0:
        BeginNormalPaletteFade(sStorage->wallpaperPalBits, 1, 0, 16, RGB_WHITEALPHA);
        sStorage->wallpaperChangeState++;
        break;
    case 1:
        if (!UpdatePaletteFade())
        {
            u8 curBox = StorageGetCurrentBox();
            LoadWallpaperGfx(curBox, 0);
            sStorage->wallpaperChangeState++;
        }
        break;
    case 2:
        if (WaitForWallpaperGfxLoad() == TRUE)
        {
            sub_080CC828();
            BeginNormalPaletteFade(sStorage->wallpaperPalBits, 1, 16, 0, RGB_WHITEALPHA);
            sStorage->wallpaperChangeState++;
        }
        break;
    case 3:
        if (!UpdatePaletteFade())
            sStorage->wallpaperChangeState++;
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

void LoadWallpaperGfx(u8 boxId, s8 direction)
{
    u8 wallpaperId;
    const struct Wallpaper *wallpaper;
    void *iconGfx;
    u32 tilesSize;
    u32 iconSize;

    sStorage->wallpaperLoadState = 0;
    sStorage->wallpaperLoadBoxId = boxId;
    sStorage->wallpaperLoadDir = direction;
    if (sStorage->wallpaperLoadDir != 0)
    {
        sStorage->wallpaperOffset = (sStorage->wallpaperOffset == 0);
        sub_080CC354(sStorage->wallpaperBgTilemapBuffer);
    }

    wallpaperId = GetBoxWallpaper(sStorage->wallpaperLoadBoxId);
    if (wallpaperId != 16)
    {
        wallpaper = &gUnknown_8551868[wallpaperId];
        LZ77UnCompWram(wallpaper->tilemap, sStorage->wallpaperTilemap);
        sub_080CC2B0(sStorage->wallpaperTilemap, sStorage->wallpaperLoadDir, sStorage->wallpaperOffset);

        if (sStorage->wallpaperLoadDir != 0)
            LoadPalette(wallpaper->palettes, BG_PLTT_ID(4) + BG_PLTT_ID(sStorage->wallpaperOffset * 2), 2 * PLTT_SIZE_4BPP);
        else
            CpuCopy16(wallpaper->palettes, gUnknown_2037434 + sStorage->wallpaperOffset * 32, 2 * PLTT_SIZE_4BPP);

        sStorage->wallpaperTiles = malloc_and_decompress(wallpaper->tiles, &tilesSize);
        LoadBgTiles(2, sStorage->wallpaperTiles, tilesSize, sStorage->wallpaperOffset << 8);
    }
    else
    {
        wallpaper = &gUnknown_8555A40[GetWaldaWallpaperPatternId()];
        LZ77UnCompWram(wallpaper->tilemap, sStorage->wallpaperTilemap);
        sub_080CC2B0(sStorage->wallpaperTilemap, sStorage->wallpaperLoadDir, sStorage->wallpaperOffset);

        CpuCopy16(wallpaper->palettes, sStorage->wallpaperTilemap, 0x40);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sStorage->wallpaperTilemap[1], 4);
        CpuCopy16(GetWaldaWallpaperColorsPtr(), &sStorage->wallpaperTilemap[17], 4);

        if (sStorage->wallpaperLoadDir != 0)
            LoadPalette(sStorage->wallpaperTilemap, BG_PLTT_ID(4) + BG_PLTT_ID(sStorage->wallpaperOffset * 2), 2 * PLTT_SIZE_4BPP);
        else
            CpuCopy16(sStorage->wallpaperTilemap, gUnknown_2037434 + sStorage->wallpaperOffset * 32, 2 * PLTT_SIZE_4BPP);

        sStorage->wallpaperTiles = malloc_and_decompress(wallpaper->tiles, &tilesSize);
        iconGfx = malloc_and_decompress(gUnknown_8555B00[GetWaldaWallpaperIconId()], &iconSize);
        CpuCopy32(iconGfx, sStorage->wallpaperTiles + 0x800, iconSize);
        Free(iconGfx);
        LoadBgTiles(2, sStorage->wallpaperTiles, tilesSize, sStorage->wallpaperOffset << 8);
    }

    CopyBgTilemapBufferToVram(2);
}

bool32 WaitForWallpaperGfxLoad(void)
{
    if (IsDma3ManagerBusyWithBgCopy())
        return FALSE;

    TRY_FREE_AND_SET_NULL(sStorage->wallpaperTiles);

    return TRUE;
}

void sub_080CC2B0(const void *tilemap, s8 direction, u8 offset)
{
    s16 tileOffset = offset * 256;
    s16 paletteNum = (offset * 2) + 3;
    s16 x = ((sStorage->bg2_X / 8 + 10) + (direction * 24)) & 0x3F;

    CopyRectToBgTilemapBufferRect(2, tilemap, 0, 0, 20, 18, x, 2, 20, 18, 17, tileOffset, paletteNum);

    if (direction == 0)
        return;
    if (direction > 0)
        x += 20;
    else
        x -= 4;

    FillBgTilemapBufferRect(2, 0, x, 2, 4, 0x12, 17);
}

void sub_080CC354(void *tilemap)
{
    u16 i;
    u16 *dest = tilemap;
    s16 r3 = ((sStorage->bg2_X / 8) + 30) & 0x3F;

    if (r3 <= 31)
        dest += r3 + 0x260;
    else
        dest += r3 + 0x640;

    for (i = 0; i < 0x2C; i++)
    {
        *dest++ = 0;
        r3 = (r3 + 1) & 0x3F;
        if (r3 == 0)
            dest -= 0x420;
        if (r3 == 0x20)
            dest += 0x3e0;
    }
}

void sub_080CC3C4(u8 boxId)
{
    u8 tagIndex;
    s16 x;
    u16 i;

    struct SpriteSheet spriteSheet = {sStorage->boxTitleTiles, 0x200, GFXTAG_BOX_TITLE};
    struct SpritePalette palettes[] = {
        {sStorage->boxTitlePal, PALTAG_BOX_TITLE},
        {}
    };

    u16 wallpaperId = GetBoxWallpaper(boxId);

    sStorage->boxTitlePal[14] = gUnknown_8551824[wallpaperId][0];
    sStorage->boxTitlePal[15] = gUnknown_8551824[wallpaperId][1];
    LoadSpritePalettes(palettes);
    sStorage->wallpaperPalBits = 0x3f0;

    tagIndex = IndexOfSpritePaletteTag(PALTAG_BOX_TITLE);
    sStorage->boxTitlePalOffset = OBJ_PLTT_ID(tagIndex) + 14;
    sStorage->wallpaperPalBits |= (1 << 16) << tagIndex;

    tagIndex = IndexOfSpritePaletteTag(PALTAG_BOX_TITLE);
    sStorage->boxTitleAltPalOffset = OBJ_PLTT_ID(tagIndex) + 14;
    sStorage->wallpaperPalBits |= (1 << 16) << tagIndex;

    StringCopyPadded(sStorage->boxTitleText, GetBoxNamePtr(boxId), 0, BOX_NAME_LENGTH);
    sub_080C66A4(sStorage->boxTitleText, sStorage->boxTitleTiles, 0, 0, sStorage->boxTitleTiles + 0x200);
    LoadSpriteSheet(&spriteSheet);
    x = GetBoxTitleBaseX(StringLength(GetBoxNamePtr(boxId)));

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_8555BA4, x + i * 32, 28, 24);
        sStorage->curBoxTitleSprites[i] = &gSprites[spriteId];
        StartSpriteAnim(sStorage->curBoxTitleSprites[i], i);
    }
    sStorage->boxTitleCycleId = 0;
}

void sub_080CC57C(u8 boxId, s8 direction)
{
    u16 palOffset;
    s16 x, adjustedX;
    u16 i;
    struct SpriteSheet spriteSheet = {sStorage->boxTitleTiles, 0x200, GFXTAG_BOX_TITLE};
    struct SpriteTemplate template = gUnknown_8555BA4;

    sStorage->boxTitleCycleId = (sStorage->boxTitleCycleId == 0);
    if (sStorage->boxTitleCycleId == 0)
    {
        spriteSheet.tag = GFXTAG_BOX_TITLE;
        palOffset = sStorage->boxTitlePalOffset;
    }
    else
    {
        spriteSheet.tag = GFXTAG_BOX_TITLE_ALT;
        palOffset = sStorage->boxTitlePalOffset;
        template.tileTag = GFXTAG_BOX_TITLE_ALT;
        template.paletteTag = PALTAG_BOX_TITLE;
    }

    StringCopyPadded(sStorage->boxTitleText, GetBoxNamePtr(boxId), 0, BOX_NAME_LENGTH);
    sub_080C66A4(sStorage->boxTitleText, sStorage->boxTitleTiles, 0, 0, sStorage->boxTitleTiles + 0x200);
    LoadSpriteSheet(&spriteSheet);
    LoadPalette(gUnknown_8551824[GetBoxWallpaper(boxId)], palOffset, sizeof(gUnknown_8551824[0]));
    x = GetBoxTitleBaseX(StringLength(GetBoxNamePtr(boxId)));
    adjustedX = x;
    adjustedX += direction * 192;

    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&template, i * 32 + adjustedX, 28, 24);

        sStorage->nextBoxTitleSprites[i] = &gSprites[spriteId];
        sStorage->nextBoxTitleSprites[i]->data[0] = (-direction) * 6;
        sStorage->nextBoxTitleSprites[i]->data[1] = i * 32 + x;
        sStorage->nextBoxTitleSprites[i]->data[2] = 0;
        sStorage->nextBoxTitleSprites[i]->callback = sub_080CC7BC;
        StartSpriteAnim(sStorage->nextBoxTitleSprites[i], i);

        sStorage->curBoxTitleSprites[i]->data[0] = (-direction) * 6;
        sStorage->curBoxTitleSprites[i]->data[1] = 1;
        sStorage->curBoxTitleSprites[i]->callback = sub_080CC7F0;
    }
}

void sub_080CC76C(void)
{
    if (sStorage->boxTitleCycleId == 0)
        FreeSpriteTilesByTag(GFXTAG_BOX_TITLE_ALT);
    else
        FreeSpriteTilesByTag(GFXTAG_BOX_TITLE);

    sStorage->curBoxTitleSprites[0] = sStorage->nextBoxTitleSprites[0];
    sStorage->curBoxTitleSprites[1] = sStorage->nextBoxTitleSprites[1];
}

void sub_080CC7BC(struct Sprite *sprite)
{
    if (sprite->data[2] != 0)
        sprite->data[2]--;
    else if ((sprite->x += sprite->data[0]) == sprite->data[1])
        sprite->callback = SpriteCallbackDummy;
}

void sub_080CC7F0(struct Sprite *sprite)
{
    if (sprite->data[1] != 0)
    {
        sprite->data[1]--;
    }
    else
    {
        sprite->x += sprite->data[0];
        sprite->data[2] = sprite->x + sprite->x2;
        if (sprite->data[2] < 64 || sprite->data[2] > DISPLAY_WIDTH + 16)
            DestroySprite(sprite);
    }
}

void sub_080CC828(void)
{
    u8 boxId = StorageGetCurrentBox();
    u8 wallpaperId = GetBoxWallpaper(boxId);

    if (sStorage->boxTitleCycleId == 0)
        CpuCopy16(gUnknown_8551824[wallpaperId], &gPlttBufferUnfaded[sStorage->boxTitlePalOffset], PLTT_SIZEOF(2));
    else
        CpuCopy16(gUnknown_8551824[wallpaperId], &gPlttBufferUnfaded[sStorage->boxTitleAltPalOffset], PLTT_SIZEOF(2));
}

s16 GetBoxTitleBaseX(u16 len)
{
    return (s16)(0xB0 - (len << 2));
}

void sub_080CC8A8(void)
{
    u16 i;

    LoadSpriteSheet(&gUnknown_8555B7C);
    for (i = 0; i < 2; i++)
    {
        u8 spriteId = CreateSprite(&gUnknown_8555BDC, 92 + i * 136, 28, 22);
        if (spriteId != MAX_SPRITES)
        {
            struct Sprite *sprite = &gSprites[spriteId];
            StartSpriteAnim(sprite, i);
            sprite->data[3] = (i == 0) ? -1 : 1;
            sStorage->arrowSprites[i] = sprite;
        }
    }
    if (IsCursorOnBoxTitle())
        sub_080CCA24(TRUE);
}

void sub_080CC934(s8 direction)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sStorage->arrowSprites[i]->x2 = 0;
        sStorage->arrowSprites[i]->data[0] = 2;
    }
    if (direction < 0)
    {
        sStorage->arrowSprites[0]->data[1] = 29;
        sStorage->arrowSprites[1]->data[1] = 5;
        sStorage->arrowSprites[0]->data[2] = 72;
        sStorage->arrowSprites[1]->data[2] = 72;
    }
    else
    {
        sStorage->arrowSprites[0]->data[1] = 5;
        sStorage->arrowSprites[1]->data[1] = 29;
        sStorage->arrowSprites[0]->data[2] = DISPLAY_WIDTH + 8;
        sStorage->arrowSprites[1]->data[2] = DISPLAY_WIDTH + 8;
    }
    sStorage->arrowSprites[0]->data[7] = 0;
    sStorage->arrowSprites[1]->data[7] = 1;
}

void sub_080CC9D4(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        sStorage->arrowSprites[i]->x = 136 * i + 92;
        sStorage->arrowSprites[i]->x2 = 0;
        sStorage->arrowSprites[i]->invisible = FALSE;
    }
    sub_080CCA24(TRUE);
}

void sub_080CCA24(bool8 animate)
{
    u16 i;

    if (animate)
    {
        for (i = 0; i < 2; i++)
        {
            sStorage->arrowSprites[i]->data[0] = 1;
            sStorage->arrowSprites[i]->data[1] = 0;
            sStorage->arrowSprites[i]->data[2] = 0;
            sStorage->arrowSprites[i]->data[4] = 0;
        }
    }
    else
    {
        for (i = 0; i < 2; i++)
            sStorage->arrowSprites[i]->data[0] = 0;
    }
}

void sub_080CCA8C(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->x2 = 0;
        break;
    case 1:
        if (++sprite->data[1] > 3)
        {
            sprite->data[1] = 0;
            sprite->x2 += sprite->data[3];
            if (++sprite->data[2] > 5)
            {
                sprite->data[2] = 0;
                sprite->x2 = 0;
            }
        }
        break;
    case 2:
        sprite->data[0] = 3;
        break;
    case 3:
        sprite->x -= sStorage->scrollSpeed;
        if (sprite->x <= 72 || sprite->x >= DISPLAY_WIDTH + 8)
            sprite->invisible = TRUE;
        if (--sprite->data[1] == 0)
        {
            sprite->x = sprite->data[2];
            sprite->invisible = FALSE;
            sprite->data[0] = 4;
        }
        break;
    case 4:
        sprite->x -= sStorage->scrollSpeed;
        break;
    }
}

struct Sprite *sub_080CCB64(u16 x, u16 y, u8 animId, u8 priority, u8 subpriority)
{
    u8 spriteId = CreateSprite(&gUnknown_8555BDC, x, y, subpriority);

    if (spriteId == MAX_SPRITES)
    {
        return NULL;
    }
    else
    {
        u8 anim = animId & 1;

        StartSpriteAnim(&gSprites[spriteId], anim);
        gSprites[spriteId].oam.priority = priority;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        return &gSprites[spriteId];
    }
}

void sub_080CCBE8(void)
{
    if (sStorage->boxOption != OPTION_DEPOSIT)
        gUnknown_2039A18 = CURSOR_AREA_IN_BOX;
    else
        gUnknown_2039A18 = CURSOR_AREA_IN_PARTY;

    gUnknown_2039A19 = 0;
    gUnknown_2039A1A = FALSE;
    gUnknown_2039A1B = 0;
    gUnknown_2039A1C = 0;
    gUnknown_2039A1D = FALSE;
    ClearSavedCursorPos();
    sub_080CF490();
    sStorage->cursorPrevHorizPos = 1;
    sStorage->inBoxMovingMode = 0;
    TryRefreshDisplayMon();
}

void sub_080CCC68(void)
{
    sub_080CF490();
    ReshowDisplayMon();
    sStorage->cursorPrevHorizPos = 1;
    sStorage->inBoxMovingMode = 0;
    if (gUnknown_2039A1A)
    {
        sStorage->movingMon = sSavedMovingMon;
        CreateMovingMonIcon();
    }
}

void sub_080CCCC0(u8 cursorArea, u8 cursorPosition, u16 *x, u16 *y)
{
    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        *x = (cursorPosition % IN_BOX_COLUMNS) * 24 + 100;
        *y = (cursorPosition / IN_BOX_COLUMNS) * 24 + 32;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPosition == 0)
        {
            *x = 104;
            *y = 52;
        }
        else if (cursorPosition == PARTY_SIZE)
        {
            *x = 152;
            *y = 132;
        }
        else
        {
            *x = 152;
            *y = (cursorPosition - 1) * 24 + 4;
        }
        break;
    case CURSOR_AREA_BOX_TITLE:
        *x = 162;
        *y = 12;
        break;
    case CURSOR_AREA_BUTTONS:
        *y = gUnknown_2039A1A ? 8 : 14;
        *x = cursorPosition * 88 + 120;
        break;
    case 4:
        *x = 160;
        *y = 96;
        break;
    }
}

u16 sub_080CCD80(void)
{
    switch (gUnknown_2039A18)
    {
    case CURSOR_AREA_IN_PARTY:
        return GetMonData3(&gPlayerParty[gUnknown_2039A19], MON_DATA_SPECIES);
    case CURSOR_AREA_IN_BOX:
        return GetCurrentBoxMonData(gUnknown_2039A19, MON_DATA_SPECIES);
    default:
        return SPECIES_NONE;
    }
}

bool8 sub_080CCDD0(void)
{
    s16 tmp;

    if (sStorage->cursorMoveSteps == 0)
    {
        if (sStorage->boxOption != OPTION_MOVE_ITEMS)
            return FALSE;
        else
            return sub_080D0AB8();
    }
    else if (--sStorage->cursorMoveSteps != 0)
    {
        sStorage->cursorNewX += sStorage->cursorSpeedX;
        sStorage->cursorNewY += sStorage->cursorSpeedY;
        sStorage->cursorSprite->x = sStorage->cursorNewX >> 8;
        sStorage->cursorSprite->y = sStorage->cursorNewY >> 8;

        if (sStorage->cursorSprite->x > DISPLAY_WIDTH + 16)
        {
            tmp = sStorage->cursorSprite->x - (DISPLAY_WIDTH + 16);
            sStorage->cursorSprite->x = tmp + 64;
        }

        if (sStorage->cursorSprite->x < 64)
        {
            tmp = 64 - sStorage->cursorSprite->x;
            sStorage->cursorSprite->x = DISPLAY_WIDTH + 16 - tmp;
        }

        if (sStorage->cursorSprite->y > DISPLAY_HEIGHT + 16)
        {
            tmp = sStorage->cursorSprite->y - (DISPLAY_HEIGHT + 16);
            sStorage->cursorSprite->y = tmp - 16;
        }

        if (sStorage->cursorSprite->y < -16)
        {
            tmp = -16 - sStorage->cursorSprite->y;
            sStorage->cursorSprite->y = DISPLAY_HEIGHT + 16 - tmp;
        }

        if (sStorage->cursorFlipTimer && --sStorage->cursorFlipTimer == 0)
            sStorage->cursorSprite->vFlip = (sStorage->cursorSprite->vFlip == FALSE);
    }
    else
    {
        sStorage->cursorSprite->x = sStorage->cursorTargetX;
        sStorage->cursorSprite->y = sStorage->cursorTargetY;
        sub_080CD2E4();
    }

    return TRUE;
}

void sub_080CCF28(u8 newCursorArea, u8 newCursorPosition)
{
    u16 x, y;

    sub_080CCCC0(newCursorArea, newCursorPosition, &x, &y);
    sStorage->newCursorArea = newCursorArea;
    sStorage->newCursorPosition = newCursorPosition;
    sStorage->cursorTargetX = x;
    sStorage->cursorTargetY = y;
}

void sub_080CCF88(void)
{
    int yDistance, xDistance;

    if (sStorage->cursorVerticalWrap != 0 || sStorage->cursorHorizontalWrap != 0)
        sStorage->cursorMoveSteps = 12;
    else
        sStorage->cursorMoveSteps = 6;

    if (sStorage->cursorFlipTimer)
        sStorage->cursorFlipTimer = sStorage->cursorMoveSteps >> 1;

    switch (sStorage->cursorVerticalWrap)
    {
    default:
        yDistance = sStorage->cursorTargetY - sStorage->cursorSprite->y;
        break;
    case -1:
        yDistance = sStorage->cursorTargetY - 192 - sStorage->cursorSprite->y;
        break;
    case 1:
        yDistance = sStorage->cursorTargetY + 192 - sStorage->cursorSprite->y;
        break;
    }

    switch (sStorage->cursorHorizontalWrap)
    {
    default:
        xDistance = sStorage->cursorTargetX - sStorage->cursorSprite->x;
        break;
    case -1:
        xDistance = sStorage->cursorTargetX - 192 - sStorage->cursorSprite->x;
        break;
    case 1:
        xDistance = sStorage->cursorTargetX + 192 - sStorage->cursorSprite->x;
        break;
    }

    yDistance <<= 8;
    xDistance <<= 8;
    sStorage->cursorSpeedX = xDistance / sStorage->cursorMoveSteps;
    sStorage->cursorSpeedY = yDistance / sStorage->cursorMoveSteps;
    sStorage->cursorNewX = sStorage->cursorSprite->x << 8;
    sStorage->cursorNewY = sStorage->cursorSprite->y << 8;
}

void sub_080CD110(u8 newCursorArea, u8 newCursorPosition)
{
    sub_080CCF28(newCursorArea, newCursorPosition);
    sub_080CCF88();
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        if (sStorage->inBoxMovingMode == 0 && !gUnknown_2039A1A)
            StartSpriteAnim(sStorage->cursorSprite, 1);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sStorage->cursorSprite, 1);
    }

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        if (gUnknown_2039A18 == CURSOR_AREA_IN_BOX)
            sub_080D06F0(CURSOR_AREA_IN_BOX, gUnknown_2039A19);
        else if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY)
            sub_080D06F0(CURSOR_AREA_IN_PARTY, gUnknown_2039A19);

        if (newCursorArea == CURSOR_AREA_IN_BOX)
            sub_080D062C(newCursorArea, newCursorPosition);
        else if (newCursorArea == CURSOR_AREA_IN_PARTY)
            sub_080D062C(newCursorArea, newCursorPosition);
    }

    if (newCursorArea == CURSOR_AREA_IN_PARTY && gUnknown_2039A18 != CURSOR_AREA_IN_PARTY)
    {
        sStorage->cursorPrevHorizPos = 1;
        sStorage->cursorShadowSprite->invisible = TRUE;
    }

    switch (newCursorArea)
    {
    case CURSOR_AREA_IN_PARTY:
    case CURSOR_AREA_BOX_TITLE:
    case CURSOR_AREA_BUTTONS:
        sStorage->cursorSprite->oam.priority = 1;
        sStorage->cursorShadowSprite->invisible = TRUE;
        sStorage->cursorShadowSprite->oam.priority = 1;
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode != 0)
        {
            sStorage->cursorSprite->oam.priority = 0;
            sStorage->cursorShadowSprite->invisible = TRUE;
        }
        else
        {
            sStorage->cursorSprite->oam.priority = 2;
            if (gUnknown_2039A18 == CURSOR_AREA_IN_BOX && gUnknown_2039A1A)
                SetMovingMonPriority(2);
        }
        break;
    }
}

void sub_080CD2E4(void)
{
    gUnknown_2039A18 = sStorage->newCursorArea;
    gUnknown_2039A19 = sStorage->newCursorPosition;
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
    {
        if (sStorage->inBoxMovingMode == 0 && !gUnknown_2039A1A)
            StartSpriteAnim(sStorage->cursorSprite, 0);
    }
    else
    {
        if (!IsActiveItemMoving())
            StartSpriteAnim(sStorage->cursorSprite, 0);
    }

    TryRefreshDisplayMon();
    switch (gUnknown_2039A18)
    {
    case CURSOR_AREA_BUTTONS:
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_BOX_TITLE:
        sub_080CCA24(TRUE);
        break;
    case CURSOR_AREA_IN_PARTY:
        sStorage->cursorShadowSprite->subpriority = 13;
        SetMovingMonPriority(1);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode == 0)
        {
            sStorage->cursorSprite->oam.priority = 1;
            sStorage->cursorShadowSprite->oam.priority = 2;
            sStorage->cursorShadowSprite->subpriority = 21;
            sStorage->cursorShadowSprite->invisible = FALSE;
            SetMovingMonPriority(2);
        }
        break;
    }
}

void sub_080CD41C(void)
{
    u8 partyCount;

    if (!gUnknown_2039A1A)
    {
        partyCount = 0;
    }
    else
    {
        partyCount = CalculatePlayerPartyCount();
        if (partyCount >= PARTY_SIZE)
            partyCount = PARTY_SIZE - 1;
    }

    if (sStorage->cursorSprite->vFlip)
        sStorage->cursorFlipTimer = 1;
    sub_080CD110(CURSOR_AREA_IN_PARTY, partyCount);
}

void sub_080CD474(u8 cursorBoxPosition)
{
    sub_080CD110(CURSOR_AREA_IN_BOX, cursorBoxPosition);
}

void ClearSavedCursorPos(void)
{
    sSavedCursorPosition = 0;
}

void SaveCursorPos(void)
{
    sSavedCursorPosition = sCursorPosition;
}

u8 GetSavedCursorPos(void)
{
    return sSavedCursorPosition;
}

void InitMonPlaceChange(u8 type)
{
    sStorage->monPlaceChangeFunc = sPlaceChangeFuncs[type];
    sStorage->monPlaceChangeState = 0;
}

void InitMultiMonPlaceChange(bool8 isMoving)
{
    if (!isMoving)
        sStorage->monPlaceChangeFunc = MultiMonPlaceChange_Down;
    else
        sStorage->monPlaceChangeFunc = MultiMonPlaceChange_Up;

    sStorage->monPlaceChangeState = 0;
}

bool8 DoMonPlaceChange(void)
{
    return sStorage->monPlaceChangeFunc();
}

bool8 MonPlaceChange_Grab(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        if (gUnknown_2039A1A)
            return FALSE;
        StartSpriteAnim(sStorage->cursorSprite, 2);
        sStorage->monPlaceChangeState++;
        break;
    case 1:
        if (!MonPlaceChange_CursorDown())
        {
            StartSpriteAnim(sStorage->cursorSprite, 3);
            MoveMon();
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        if (!MonPlaceChange_CursorUp())
            sStorage->monPlaceChangeState++;
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

bool8 MonPlaceChange_Place(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        if (!MonPlaceChange_CursorDown())
        {
            StartSpriteAnim(sStorage->cursorSprite, 2);
            PlaceMon();
            sStorage->monPlaceChangeState++;
        }
        break;
    case 1:
        if (!MonPlaceChange_CursorUp())
        {
            StartSpriteAnim(sStorage->cursorSprite, 0);
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

bool8 MonPlaceChange_Shift(void)
{
    switch (sStorage->monPlaceChangeState)
    {
    case 0:
        switch (gUnknown_2039A18)
        {
        case CURSOR_AREA_IN_PARTY:
            sStorage->shiftBoxId = TOTAL_BOXES_COUNT;
            break;
        case CURSOR_AREA_IN_BOX:
            sStorage->shiftBoxId = StorageGetCurrentBox();
            break;
        default:
            return FALSE;
        }
        StartSpriteAnim(sStorage->cursorSprite, 2);
        sub_080CB5D0(sStorage->shiftBoxId, gUnknown_2039A19);
        sStorage->monPlaceChangeState++;
        break;
    case 1:
        if (!sub_080CB638())
        {
            StartSpriteAnim(sStorage->cursorSprite, 3);
            SetShiftedMonData(sStorage->shiftBoxId, gUnknown_2039A19);
            sStorage->monPlaceChangeState++;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

bool8 MultiMonPlaceChange_Down(void)
{
    return MonPlaceChange_CursorDown();
}

bool8 MultiMonPlaceChange_Up(void)
{
    return MonPlaceChange_CursorUp();
}

bool8 MonPlaceChange_CursorDown(void)
{
    switch (sStorage->cursorSprite->y2)
    {
    default:
        sStorage->cursorSprite->y2++;
        break;
    case 0:
        sStorage->cursorSprite->y2++;
        break;
    case 8:
        return FALSE;
    }

    return TRUE;
}

bool8 MonPlaceChange_CursorUp(void)
{
    switch (sStorage->cursorSprite->y2)
    {
    case 0:
        return FALSE;
    default:
        sStorage->cursorSprite->y2--;
        break;
    }

    return TRUE;
}

void MoveMon(void)
{
    switch (gUnknown_2039A18)
    {
    case CURSOR_AREA_IN_PARTY:
        SetMovedMonData(TOTAL_BOXES_COUNT, gUnknown_2039A19);
        sub_080CB488(0, gUnknown_2039A19);
        break;
    case CURSOR_AREA_IN_BOX:
        if (sStorage->inBoxMovingMode == 0)
        {
            SetMovedMonData(StorageGetCurrentBox(), gUnknown_2039A19);
            sub_080CB488(1, gUnknown_2039A19);
        }
        break;
    default:
        return;
    }

    gUnknown_2039A1A = TRUE;
}

void PlaceMon(void)
{
    u8 boxId;

    switch (gUnknown_2039A18)
    {
    case CURSOR_AREA_IN_PARTY:
        SetPlacedMonData(TOTAL_BOXES_COUNT, gUnknown_2039A19);
        sub_080CB520(TOTAL_BOXES_COUNT, gUnknown_2039A19);
        break;
    case CURSOR_AREA_IN_BOX:
        boxId = StorageGetCurrentBox();
        SetPlacedMonData(boxId, gUnknown_2039A19);
        sub_080CB520(boxId, gUnknown_2039A19);
        break;
    default:
        return;
    }

    gUnknown_2039A1A = FALSE;
}

void sub_080CD888(void)
{
    TryRefreshDisplayMon();
}



void SetMovedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sStorage->movingMon = gPlayerParty[sCursorPosition];
    else
        BoxMonAtToMon(boxId, position, &sStorage->movingMon);

    PurgeMonOrBoxMon(boxId, position);
    gUnknown_2039A1B = boxId;
    gUnknown_2039A1C = position;
}

void SetPlacedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
    {
        gPlayerParty[position] = sStorage->movingMon;
    }
    else
    {
        BoxMonRestorePP(&sStorage->movingMon.box);
        SetBoxMonAt(boxId, position, &sStorage->movingMon.box);
    }
}

void PurgeMonOrBoxMon(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        ZeroMonData(&gPlayerParty[position]);
    else
        ZeroBoxMonAt(boxId, position);
}

void SetShiftedMonData(u8 boxId, u8 position)
{
    if (boxId == TOTAL_BOXES_COUNT)
        sStorage->tempMon = gPlayerParty[position];
    else
        BoxMonAtToMon(boxId, position, &sStorage->tempMon);

    SetPlacedMonData(boxId, position);
    sStorage->movingMon = sStorage->tempMon;
    SetCursorMonData(&sStorage->movingMon, MODE_PARTY);
    gUnknown_2039A1B = boxId;
    gUnknown_2039A1C = position;
}

bool8 TryStorePartyMonInBox(u8 boxId)
{
    s16 boxPosition = GetFirstFreeBoxSpot(boxId);

    if (boxPosition == -1)
        return FALSE;

    if (gUnknown_2039A1A)
    {
        SetPlacedMonData(boxId, boxPosition);
        DestroyMovingMonIcon();
        gUnknown_2039A1A = FALSE;
    }
    else
    {
        SetMovedMonData(TOTAL_BOXES_COUNT, sCursorPosition);
        SetPlacedMonData(boxId, boxPosition);
        DestroyPartyMonIcon(sCursorPosition);
    }

    if (boxId == StorageGetCurrentBox())
        sub_080CA9B4(boxPosition);

    StartSpriteAnim(sStorage->cursorSprite, 1);
    return TRUE;
}


void sub_080CDAA8(void)
{
    StartSpriteAnim(sStorage->cursorSprite, 0);
    TryRefreshDisplayMon();
}

void sub_080CDACC(void)
{
    u8 mode;

    if (gUnknown_2039A1A)
        mode = MODE_MOVE;
    else if (sCursorArea == CURSOR_AREA_IN_PARTY)
        mode = MODE_PARTY;
    else
        mode = MODE_BOX;

    sub_080CB788(mode, sCursorPosition);
    StringCopy(sStorage->releaseMonName, sStorage->displayMonName);
}

bool8 sub_080CDB24(void)
{
    if (!sub_080CB84C())
    {
        StartSpriteAnim(sStorage->cursorSprite, 0);
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

void ReleaseMon(void)
{
    u8 boxId;

    sub_080CB894();
    if (gUnknown_2039A1A)
    {
        gUnknown_2039A1A = FALSE;
    }
    else
    {
        if (sCursorArea == CURSOR_AREA_IN_PARTY)
            boxId = TOTAL_BOXES_COUNT;
        else
            boxId = StorageGetCurrentBox();

        PurgeMonOrBoxMon(boxId, sCursorPosition);
    }
    TryRefreshDisplayMon();
}

void sub_080CDBA0(void)
{
    if (gUnknown_2039A1A)
        StartSpriteAnim(sStorage->cursorSprite, 3);
}

void sub_080CDBCC(u16 *moves)
{
    s32 i;

    for (i = 0; i < (u32)6; i++)
    {
        if (gUnknown_85564A0[i].mapGroup == MAP_GROUPS_COUNT
         || (gUnknown_85564A0[i].mapGroup == gSaveBlock1Ptr->location.mapGroup
          && gUnknown_85564A0[i].mapNum == gSaveBlock1Ptr->location.mapNum))
        {
            *moves = gUnknown_85564A0[i].move;
            moves++;
        }
    }
    *moves = MOVES_COUNT;
}

void InitCanRelaseMonVars(void)
{
    if (!AtLeastThreeUsableMons())
    {
        sStorage->releaseStatusResolved = TRUE;
        sStorage->canReleaseMon = FALSE;
        return;
    }

    if (gUnknown_2039A1A)
    {
        memcpy(&sStorage->tempMon, &sStorage->movingMon, sizeof(sStorage->tempMon));
        sStorage->releaseBoxId = -1;
        sStorage->releaseBoxPos = -1;
    }
    else
    {
        if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY)
        {
            sStorage->tempMon = gPlayerParty[gUnknown_2039A19];
            sStorage->releaseBoxId = TOTAL_BOXES_COUNT;
        }
        else
        {
            BoxMonAtToMon(StorageGetCurrentBox(), gUnknown_2039A19, &sStorage->tempMon);
            sStorage->releaseBoxId = StorageGetCurrentBox();
        }
        sStorage->releaseBoxPos = gUnknown_2039A19;
    }

    sub_080CDBCC(sStorage->restrictedMoveList);
    sStorage->restrictedReleaseMonMoves = GetMonData3(&sStorage->tempMon, MON_DATA_KNOWN_MOVES, (u8 *)sStorage->restrictedMoveList);
    if (sStorage->restrictedReleaseMonMoves != 0)
    {
        sStorage->releaseStatusResolved = FALSE;
    }
    else
    {
        sStorage->releaseStatusResolved = TRUE;
        sStorage->canReleaseMon = TRUE;
    }

    sStorage->releaseCheckState = 0;
}

bool32 AtLeastThreeUsableMons(void)
{
    s32 i, j;
    s32 count = (gUnknown_2039A1A != FALSE);

    for (j = 0; j < PARTY_SIZE; j++)
    {
        if (GetMonData3(&gPlayerParty[j], MON_DATA_SANITY_HAS_SPECIES))
            count++;
    }

    if (count >= 3)
        return TRUE;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (CheckBoxMonSanityAt(i, j))
            {
                if (++count >= 3)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

s8 RunCanReleaseMon(void)
{
    u16 i;
    u16 knownMoves;

    if (sStorage->releaseStatusResolved)
        return sStorage->canReleaseMon;

    switch (sStorage->releaseCheckState)
    {
    case 0:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (sStorage->releaseBoxId != TOTAL_BOXES_COUNT || sStorage->releaseBoxPos != i)
            {
                knownMoves = GetMonData3(&gPlayerParty[i], MON_DATA_KNOWN_MOVES, (u8 *)sStorage->restrictedMoveList);
                sStorage->restrictedReleaseMonMoves &= ~(knownMoves);
            }
        }
        if (sStorage->restrictedReleaseMonMoves == 0)
        {
            sStorage->releaseStatusResolved = TRUE;
            sStorage->canReleaseMon = TRUE;
        }
        else
        {
            sStorage->releaseCheckBoxId = 0;
            sStorage->releaseCheckBoxPos = 0;
            sStorage->releaseCheckState++;
        }
        break;
    case 1:
        for (i = 0; i < IN_BOX_COUNT; i++)
        {
            knownMoves = GetAndCopyBoxMonDataAt(sStorage->releaseCheckBoxId, sStorage->releaseCheckBoxPos, MON_DATA_KNOWN_MOVES, (u8 *)sStorage->restrictedMoveList);
            if (knownMoves != 0
             && !(sStorage->releaseBoxId == sStorage->releaseCheckBoxId
               && sStorage->releaseBoxPos == sStorage->releaseCheckBoxPos))
            {
                sStorage->restrictedReleaseMonMoves &= ~(knownMoves);
                if (sStorage->restrictedReleaseMonMoves == 0)
                {
                    sStorage->releaseStatusResolved = TRUE;
                    sStorage->canReleaseMon = TRUE;
                    break;
                }
            }
            if (++sStorage->releaseCheckBoxPos >= IN_BOX_COUNT)
            {
                sStorage->releaseCheckBoxPos = 0;
                if (++sStorage->releaseCheckBoxId >= TOTAL_BOXES_COUNT)
                {
                    sStorage->releaseStatusResolved = TRUE;
                    sStorage->canReleaseMon = FALSE;
                }
            }
        }
        break;
    }

    return -1;
}

void sub_080CDFDC(void)
{
    if (gUnknown_2039A1A)
        sSavedMovingMon = sStorage->movingMon;
}

void sub_080CE00C(void)
{
    if (gUnknown_2039A1A)
    {
        if (sMovingMonOrigBoxId == TOTAL_BOXES_COUNT)
            sStorage->movingMon = sSavedMovingMon;
        else
            sStorage->movingMon.box = sSavedMovingMon.box;
    }
}

void sub_080CE064(void)
{
    if (gUnknown_2039A1A)
    {
        sub_080CDFDC();
        sStorage->summaryMon.mon = &sSavedMovingMon;
        sStorage->summaryStartPos = 0;
        sStorage->summaryMaxPos = 0;
        sStorage->summaryScreenMode = 0;
    }
    else if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY)
    {
        sStorage->summaryMon.mon = gPlayerParty;
        sStorage->summaryStartPos = gUnknown_2039A19;
        sStorage->summaryMaxPos = CountPartyMons() - 1;
        sStorage->summaryScreenMode = 0;
    }
    else
    {
        sStorage->summaryMon.box = GetBoxedMonPtr(StorageGetCurrentBox(), 0);
        sStorage->summaryStartPos = gUnknown_2039A19;
        sStorage->summaryMaxPos = IN_BOX_COUNT - 1;
        sStorage->summaryScreenMode = 2;
    }
}

void sub_080CE160(void)
{
    if (gUnknown_2039A1A)
        sub_080CE00C();
    else
        gUnknown_2039A19 = gLastViewedMonIndex;
}

s16 CompactPartySlots(void)
{
    s16 retVal = -1;
    u16 i, last;

    for (i = 0, last = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES);

        if (species != SPECIES_NONE)
        {
            if (i != last)
                gPlayerParty[last] = gPlayerParty[i];
            last++;
        }
        else if (retVal == -1)
        {
            retVal = i;
        }
    }

    for (; last < PARTY_SIZE; last++)
        ZeroMonData(&gPlayerParty[last]);

    return retVal;
}

void SetMonMarkings(u8 markings)
{
    sStorage->displayMonMarkings = markings;
    if (gUnknown_2039A1A)
    {
        SetMonData(&sStorage->movingMon, MON_DATA_MARKINGS, &markings);
    }
    else
    {
        if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY)
            SetMonData(&gPlayerParty[gUnknown_2039A19], MON_DATA_MARKINGS, &markings);
        if (gUnknown_2039A18 == CURSOR_AREA_IN_BOX)
            SetCurrentBoxMonData(gUnknown_2039A19, MON_DATA_MARKINGS, &markings);
    }
}

bool8 CanMovePartyMon(void)
{
    if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY
     && !gUnknown_2039A1A
     && CountPartyAliveNonEggMonsExcept(gUnknown_2039A19) == 0)
        return TRUE;
    else
        return FALSE;
}

bool8 CanShiftMon(void)
{
    if (gUnknown_2039A1A)
    {
        if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY
         && CountPartyAliveNonEggMonsExcept(gUnknown_2039A19) == 0)
        {
            if (sStorage->displayMonIsEgg
             || GetMonData3(&sStorage->movingMon, MON_DATA_HP) == 0)
                return FALSE;
        }
        return TRUE;
    }

    return FALSE;
}

bool8 IsMonBeingMoved(void)
{
    return sIsMonBeingMoved;
}

bool8 IsCursorOnBoxTitle(void)
{
    return sCursorArea == CURSOR_AREA_BOX_TITLE;
}

bool8 IsCursorOnCloseBox(void)
{
    return sCursorArea == CURSOR_AREA_BUTTONS && sCursorPosition == 1;
}

bool8 IsCursorInBox(void)
{
    return sCursorArea == CURSOR_AREA_IN_BOX;
}

void TryRefreshDisplayMon(void)
{
    // If a Pokemon is currently being moved, don't start
    // mosaic or update display. Keep displaying the
    // currently held Pokemon.
    sStorage->setMosaic = (sIsMonBeingMoved == FALSE);
    if (!sIsMonBeingMoved)
    {
        // Update display Pokemon
        switch (sCursorArea)
        {
        case CURSOR_AREA_IN_PARTY:
            if (sCursorPosition < PARTY_SIZE)
            {
                SetCursorMonData(&gPlayerParty[sCursorPosition], MODE_PARTY);
                break;
            }
            // fallthrough
        case CURSOR_AREA_BUTTONS:
        case CURSOR_AREA_BOX_TITLE:
            SetCursorMonData(NULL, MODE_MOVE);
            break;
        case CURSOR_AREA_IN_BOX:
            SetCursorMonData(GetBoxedMonPtr(StorageGetCurrentBox(), sCursorPosition), MODE_BOX);
            break;
        }
    }
}

void ReshowDisplayMon(void)
{
    if (sIsMonBeingMoved)
        SetCursorMonData(&sSavedMovingMon, MODE_PARTY);
    else
        TryRefreshDisplayMon();
}

void SetCursorMonData(const void *data, u8 mode)
{
    u8 *txtPtr;
    u16 gender;
    bool8 sanityIsBadEgg;

    sStorage->displayMonItemId = ITEM_NONE;
    gender = MON_MALE;
    sanityIsBadEgg = FALSE;
    if (mode == MODE_PARTY)
    {
        struct Pokemon *mon = (struct Pokemon *)data;

        sStorage->displayMonSpecies = GetMonData3(mon, MON_DATA_SPECIES_OR_EGG);
        if (sStorage->displayMonSpecies != SPECIES_NONE)
        {
            sanityIsBadEgg = GetMonData3(mon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBadEgg)
                sStorage->displayMonIsEgg = TRUE;
            else
                sStorage->displayMonIsEgg = GetMonData3(mon, MON_DATA_IS_EGG);

            GetMonData3(mon, MON_DATA_NICKNAME, sStorage->displayMonName);
            StringGet_Nickname(sStorage->displayMonName);
            sStorage->displayMonLevel = GetMonData3(mon, MON_DATA_LEVEL);
            sStorage->displayMonMarkings = GetMonData3(mon, MON_DATA_MARKINGS);
            sStorage->displayMonPersonality = GetMonData3(mon, MON_DATA_PERSONALITY);
            sStorage->displayMonPalette = GetMonFrontSpritePal(mon);
            gender = GetMonGender(mon);
            sStorage->displayMonItemId = GetMonData3(mon, MON_DATA_HELD_ITEM);
        }
    }
    else if (mode == MODE_BOX)
    {
        struct BoxPokemon *boxMon = (struct BoxPokemon *)data;

        sStorage->displayMonSpecies = GetBoxMonData(data, MON_DATA_SPECIES_OR_EGG);
        if (sStorage->displayMonSpecies != SPECIES_NONE)
        {
            u32 otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
            sanityIsBadEgg = GetBoxMonData(boxMon, MON_DATA_SANITY_IS_BAD_EGG);
            if (sanityIsBadEgg)
                sStorage->displayMonIsEgg = TRUE;
            else
                sStorage->displayMonIsEgg = GetBoxMonData(boxMon, MON_DATA_IS_EGG);


            GetBoxMonData(boxMon, MON_DATA_NICKNAME, sStorage->displayMonName);
            StringGet_Nickname(sStorage->displayMonName);
            sStorage->displayMonLevel = GetLevelFromBoxMonExp(boxMon);
            sStorage->displayMonMarkings = GetBoxMonData(boxMon, MON_DATA_MARKINGS);
            sStorage->displayMonPersonality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
            sStorage->displayMonPalette = GetMonSpritePalFromSpeciesAndPersonality(sStorage->displayMonSpecies, otId, sStorage->displayMonPersonality);
            gender = GetGenderFromSpeciesAndPersonality(sStorage->displayMonSpecies, sStorage->displayMonPersonality);
            sStorage->displayMonItemId = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM);
        }
    }
    else
    {
        sStorage->displayMonSpecies = SPECIES_NONE;
        sStorage->displayMonItemId = ITEM_NONE;
    }

    if (sStorage->displayMonSpecies == SPECIES_NONE)
    {
        StringFill(sStorage->displayMonName, CHAR_SPACE, 5);
        StringFill(sStorage->displayMonNameText, CHAR_SPACE, 8);
        StringFill(sStorage->displayMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sStorage->displayMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sStorage->displayMonItemName, CHAR_SPACE, 8);
    }
    else if (sStorage->displayMonIsEgg)
    {
        if (sanityIsBadEgg)
            StringCopyPadded(sStorage->displayMonNameText, sStorage->displayMonName, CHAR_SPACE, 5);
        else
            StringCopyPadded(sStorage->displayMonNameText, gText_EggNickname, CHAR_SPACE, 8);

        StringFill(sStorage->displayMonSpeciesName, CHAR_SPACE, 8);
        StringFill(sStorage->displayMonGenderLvlText, CHAR_SPACE, 8);
        StringFill(sStorage->displayMonItemName, CHAR_SPACE, 8);
    }
    else
    {
        if (sStorage->displayMonSpecies == SPECIES_NIDORAN_F || sStorage->displayMonSpecies == SPECIES_NIDORAN_M)
            gender = MON_GENDERLESS;

        StringCopyPadded(sStorage->displayMonNameText, sStorage->displayMonName, CHAR_SPACE, 5);

        txtPtr = sStorage->displayMonSpeciesName;
        *(txtPtr)++ = CHAR_SLASH;
        StringCopyPadded(txtPtr, gSpeciesNames[sStorage->displayMonSpecies], CHAR_SPACE, 5);

        txtPtr = sStorage->displayMonGenderLvlText;
        *(txtPtr)++ = EXT_CTRL_CODE_BEGIN;
        *(txtPtr)++ = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        switch (gender)
        {
        case MON_MALE:
            *(txtPtr)++ = TEXT_COLOR_RED;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_RED;
            *(txtPtr)++ = CHAR_MALE;
            break;
        case MON_FEMALE:
            *(txtPtr)++ = TEXT_COLOR_GREEN;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GREEN;
            *(txtPtr)++ = CHAR_FEMALE;
            break;
        default:
            *(txtPtr)++ = TEXT_COLOR_DARK_GRAY;
            *(txtPtr)++ = TEXT_COLOR_WHITE;
            *(txtPtr)++ = TEXT_COLOR_LIGHT_GRAY;
            *(txtPtr)++ = 0; // JP genderless spacer
            break;
        }

        *(txtPtr++) = EXT_CTRL_CODE_BEGIN;
        *(txtPtr++) = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        *(txtPtr++) = TEXT_COLOR_DARK_GRAY;
        *(txtPtr++) = TEXT_COLOR_WHITE;
        *(txtPtr++) = TEXT_COLOR_LIGHT_GRAY;
        *(txtPtr++) = CHAR_SPACE;
        *(txtPtr++) = CHAR_EXTRA_SYMBOL;
        *(txtPtr++) = CHAR_LV_2;

        txtPtr = ConvertIntToDecimalStringN(txtPtr, sStorage->displayMonLevel, STR_CONV_MODE_LEFT_ALIGN, 3);
        txtPtr[0] = CHAR_SPACE;
        txtPtr[1] = EOS;

        if (sStorage->displayMonItemId != ITEM_NONE)
            StringCopyPadded(sStorage->displayMonItemName, ItemId_GetName(sStorage->displayMonItemId), CHAR_SPACE, 8);
        else
            StringFill(sStorage->displayMonItemName, CHAR_SPACE, 8);
    }
}


bool8 HandleInput_InBox(void)
{
    switch (sStorage->inBoxMovingMode)
    {
    case 0:
    default:
        return InBoxInput_Normal();
    case 1:
        return InBoxInput_GrabbingMultiple();
    case 2:
        return InBoxInput_MovingMultiple();
    }
}

bool8 InBoxInput_Normal(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = gUnknown_2039A18;
        cursorPosition = gUnknown_2039A19;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = INPUT_MOVE_CURSOR;
            if (gUnknown_2039A19 >= IN_BOX_COLUMNS)
            {
                cursorPosition -= IN_BOX_COLUMNS;
            }
            else
            {
                cursorArea = CURSOR_AREA_BOX_TITLE;
                cursorPosition = 0;
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorPosition += IN_BOX_COLUMNS;
            if (cursorPosition >= IN_BOX_COUNT)
            {
                cursorArea = CURSOR_AREA_BUTTONS;
                cursorPosition -= IN_BOX_COUNT;
                cursorPosition /= 3;
                sStorage->cursorVerticalWrap = 1;
                sStorage->cursorFlipTimer = 1;
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = INPUT_MOVE_CURSOR;
            if (gUnknown_2039A19 % IN_BOX_COLUMNS != 0)
            {
                cursorPosition--;
            }
            else
            {
                sStorage->cursorHorizontalWrap = -1;
                cursorPosition += (IN_BOX_COLUMNS - 1);
            }
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = INPUT_MOVE_CURSOR;
            if ((gUnknown_2039A19 + 1) % IN_BOX_COLUMNS != 0)
            {
                cursorPosition++;
            }
            else
            {
                sStorage->cursorHorizontalWrap = 1;
                cursorPosition -= (IN_BOX_COLUMNS - 1);
            }
            break;
        }
        else if (JOY_NEW(START_BUTTON))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorArea = CURSOR_AREA_BOX_TITLE;
            cursorPosition = 0;
            break;
        }

        if ((JOY_NEW(A_BUTTON)) && SetSelectionMenuTexts())
        {
            if (!gUnknown_2039A1D)
                return INPUT_IN_MENU;

            if (sStorage->boxOption != OPTION_MOVE_MONS || gUnknown_2039A1A == TRUE)
            {
                switch (sub_080CF814(0))
                {
                case MENU_STORE:
                    return INPUT_DEPOSIT;
                case MENU_WITHDRAW:
                    return INPUT_WITHDRAW;
                case MENU_MOVE:
                    return INPUT_MOVE_MON;
                case MENU_SHIFT:
                    return INPUT_SHIFT_MON;
                case MENU_PLACE:
                    return INPUT_PLACE_MON;
                case MENU_TAKE:
                    return INPUT_TAKE_ITEM;
                case MENU_GIVE:
                    return INPUT_GIVE_ITEM;
                case MENU_SWITCH:
                    return INPUT_SWITCH_ITEMS;
                }
            }
            else
            {
                sStorage->inBoxMovingMode = MOVE_MODE_MULTIPLE_SELECTING;
                return INPUT_MULTIMOVE_START;
            }
        }

        if (JOY_NEW(B_BUTTON))
            return INPUT_PRESSED_B;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return INPUT_SCROLL_LEFT;
            if (JOY_HELD(R_BUTTON))
                return INPUT_SCROLL_RIGHT;
        }

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_080CF640();
            return INPUT_NONE;
        }

        retVal = INPUT_NONE;

    } while (0);

    if (retVal)
        sub_080CD110(cursorArea, cursorPosition);

    return retVal;
}



bool8 InBoxInput_GrabbingMultiple(void)
{
    if (JOY_HELD(A_BUTTON))
    {
        if (JOY_REPEAT(DPAD_UP))
        {
            if (gUnknown_2039A19 / IN_BOX_COLUMNS != 0)
            {
                sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 - IN_BOX_COLUMNS);
                return INPUT_MULTIMOVE_CHANGE_SELECTION;
            }
            else
            {
                return INPUT_MULTIMOVE_UNABLE;
            }
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            if (gUnknown_2039A19 + IN_BOX_COLUMNS < IN_BOX_COUNT)
            {
                sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 + IN_BOX_COLUMNS);
                return INPUT_MULTIMOVE_CHANGE_SELECTION;
            }
            else
            {
                return INPUT_MULTIMOVE_UNABLE;
            }
        }
        else if (JOY_REPEAT(DPAD_LEFT))
        {
            if (gUnknown_2039A19 % IN_BOX_COLUMNS != 0)
            {
                sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 - 1);
                return INPUT_MULTIMOVE_CHANGE_SELECTION;
            }
            else
            {
                return INPUT_MULTIMOVE_UNABLE;
            }
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            if ((gUnknown_2039A19 + 1) % IN_BOX_COLUMNS != 0)
            {
                sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 + 1);
                return INPUT_MULTIMOVE_CHANGE_SELECTION;
            }
            else
            {
                return INPUT_MULTIMOVE_UNABLE;
            }
        }
        else
        {
            return INPUT_NONE;
        }
    }
    else
    {
        if (sub_080D0444() == gUnknown_2039A19)
        {
            // Doing a multiple mon selection but only chose 1 mon
            sStorage->inBoxMovingMode = MOVE_MODE_NORMAL;
            sStorage->cursorShadowSprite->invisible = FALSE;
            return INPUT_MULTIMOVE_SINGLE;
        }
        else
        {
            gUnknown_2039A1A = (sStorage->displayMonSpecies != SPECIES_NONE);
            sStorage->inBoxMovingMode = MOVE_MODE_MULTIPLE_MOVING;
            sMovingMonOrigBoxId = StorageGetCurrentBox();
            return INPUT_MULTIMOVE_GRAB_SELECTION;
        }
    }
}


bool8 InBoxInput_MovingMultiple(void)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        if (sub_080CFE20(0))
        {
            sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 - IN_BOX_COLUMNS);
            return INPUT_MULTIMOVE_MOVE_MONS;
        }
        else
        {
            return INPUT_MULTIMOVE_UNABLE;
        }
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        if (sub_080CFE20(1))
        {
            sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 + IN_BOX_COLUMNS);
            return INPUT_MULTIMOVE_MOVE_MONS;
        }
        else
        {
            return INPUT_MULTIMOVE_UNABLE;
        }
    }
    else if (JOY_REPEAT(DPAD_LEFT))
    {
        if (sub_080CFE20(2))
        {
            sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 - 1);
            return INPUT_MULTIMOVE_MOVE_MONS;
        }
        else
        {
            return INPUT_SCROLL_LEFT;
        }
    }
    else if (JOY_REPEAT(DPAD_RIGHT))
    {
        if (sub_080CFE20(3))
        {
            sub_080CD110(CURSOR_AREA_IN_BOX, gUnknown_2039A19 + 1);
            return INPUT_MULTIMOVE_MOVE_MONS;
        }
        else
        {
            return INPUT_SCROLL_RIGHT;
        }
    }
    else if (JOY_NEW(A_BUTTON))
    {
        if (sub_080D0460())
        {
            gUnknown_2039A1A = FALSE;
            sStorage->inBoxMovingMode = MOVE_MODE_NORMAL;
            return INPUT_MULTIMOVE_PLACE_MONS;
        }
        else
        {
            return INPUT_MULTIMOVE_UNABLE;
        }
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return INPUT_MULTIMOVE_UNABLE;
    }
    else
    {
        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return INPUT_SCROLL_LEFT;
            if (JOY_HELD(R_BUTTON))
                return INPUT_SCROLL_RIGHT;
        }

        return INPUT_NONE;
    }
}



bool8 HandleInput_InParty(void)
{
    u8 retVal;
    bool8 gotoBox;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = gUnknown_2039A18;
        cursorPosition = gUnknown_2039A19;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;
        gotoBox = FALSE;
        retVal = INPUT_NONE;

        if (JOY_REPEAT(DPAD_UP))
        {
            if (--cursorPosition < 0)
                cursorPosition = PARTY_SIZE;
            if (cursorPosition != gUnknown_2039A19)
                retVal = INPUT_MOVE_CURSOR;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            if (++cursorPosition > PARTY_SIZE)
                cursorPosition = 0;
            if (cursorPosition != gUnknown_2039A19)
                retVal = INPUT_MOVE_CURSOR;
            break;
        }
        else if (JOY_REPEAT(DPAD_LEFT) && gUnknown_2039A19 != 0)
        {
            retVal = INPUT_MOVE_CURSOR;
            sStorage->cursorPrevHorizPos = gUnknown_2039A19;
            cursorPosition = 0;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            if (gUnknown_2039A19 == 0)
            {
                retVal = INPUT_MOVE_CURSOR;
                cursorPosition = sStorage->cursorPrevHorizPos;
            }
            else
            {
                retVal = INPUT_HIDE_PARTY;
                cursorArea = CURSOR_AREA_IN_BOX;
                cursorPosition = 0;
            }
            break;
        }

        if (JOY_NEW(A_BUTTON))
        {
            if (gUnknown_2039A19 == PARTY_SIZE)
            {
                if (sStorage->boxOption == OPTION_DEPOSIT)
                    return INPUT_CLOSE_BOX;

                gotoBox = TRUE;
            }
            else if (SetSelectionMenuTexts())
            {
                if (!gUnknown_2039A1D)
                    return INPUT_IN_MENU;

                switch (sub_080CF814(0))
                {
                case MENU_STORE:
                    return INPUT_DEPOSIT;
                case MENU_WITHDRAW:
                    return INPUT_WITHDRAW;
                case MENU_MOVE:
                    return INPUT_MOVE_MON;
                case MENU_SHIFT:
                    return INPUT_SHIFT_MON;
                case MENU_PLACE:
                    return INPUT_PLACE_MON;
                case MENU_TAKE:
                    return INPUT_TAKE_ITEM;
                case MENU_GIVE:
                    return INPUT_GIVE_ITEM;
                case MENU_SWITCH:
                    return INPUT_SWITCH_ITEMS;
                }
            }
        }

        if (JOY_NEW(B_BUTTON))
        {
            if (sStorage->boxOption == OPTION_DEPOSIT)
                return INPUT_PRESSED_B;

            gotoBox = TRUE;
        }

        if (gotoBox)
        {
            retVal = INPUT_HIDE_PARTY;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 0;
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            sub_080CF640();
            return INPUT_NONE;
        }

    } while (0);

    if (retVal != INPUT_NONE)
    {
        if (retVal != INPUT_HIDE_PARTY)
            sub_080CD110(cursorArea, cursorPosition);
    }

    return retVal;
}


bool8 HandleInput_OnBox(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorArea = CURSOR_AREA_BUTTONS;
            cursorPosition = 0;
            sStorage->cursorFlipTimer = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_DOWN))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorArea = CURSOR_AREA_IN_BOX;
            cursorPosition = 2;
            break;
        }

        if (JOY_HELD(DPAD_LEFT))
            return INPUT_SCROLL_LEFT;
        if (JOY_HELD(DPAD_RIGHT))
            return INPUT_SCROLL_RIGHT;

        if (gSaveBlock2Ptr->optionsButtonMode == OPTIONS_BUTTON_MODE_LR)
        {
            if (JOY_HELD(L_BUTTON))
                return INPUT_SCROLL_LEFT;
            if (JOY_HELD(R_BUTTON))
                return INPUT_SCROLL_RIGHT;
        }

        if (JOY_NEW(A_BUTTON))
        {
            sub_080CCA24(FALSE);
            AddBoxOptionsMenu();
            return INPUT_BOX_OPTIONS;
        }

        if (JOY_NEW(B_BUTTON))
            return INPUT_PRESSED_B;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_080CF640();
            return INPUT_NONE;
        }

        retVal = INPUT_NONE;

    } while (0);

    if (retVal != INPUT_NONE)
    {
        if (cursorArea != CURSOR_AREA_BOX_TITLE)
            sub_080CCA24(FALSE);
        sub_080CD110(cursorArea, cursorPosition);
    }

    return retVal;
}


bool8 HandleInput_OnButtons(void)
{
    u8 retVal;
    s8 cursorArea;
    s8 cursorPosition;

    do
    {
        cursorArea = gUnknown_2039A18;
        cursorPosition = gUnknown_2039A19;
        sStorage->cursorHorizontalWrap = 0;
        sStorage->cursorVerticalWrap = 0;
        sStorage->cursorFlipTimer = 0;

        if (JOY_REPEAT(DPAD_UP))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorArea = CURSOR_AREA_IN_BOX;
            sStorage->cursorVerticalWrap = -1;
            if (gUnknown_2039A19 == 0)
                cursorPosition = IN_BOX_COUNT - 1 - 5;
            else
                cursorPosition = IN_BOX_COUNT - 1;
            sStorage->cursorFlipTimer = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_DOWN | START_BUTTON))
        {
            retVal = INPUT_MOVE_CURSOR;
            cursorArea = CURSOR_AREA_BOX_TITLE;
            cursorPosition = 0;
            sStorage->cursorFlipTimer = 1;
            break;
        }

        if (JOY_REPEAT(DPAD_LEFT))
        {
            retVal = INPUT_MOVE_CURSOR;
            if (--cursorPosition < 0)
                cursorPosition = 1;
            break;
        }
        else if (JOY_REPEAT(DPAD_RIGHT))
        {
            retVal = INPUT_MOVE_CURSOR;
            if (++cursorPosition > 1)
                cursorPosition = 0;
            break;
        }

        // Button was pressed, determine which
        if (JOY_NEW(A_BUTTON))
            return (cursorPosition == 0) ? INPUT_SHOW_PARTY : INPUT_CLOSE_BOX;

        if (JOY_NEW(B_BUTTON))
            return INPUT_PRESSED_B;

        if (JOY_NEW(SELECT_BUTTON))
        {
            sub_080CF640();
            return INPUT_NONE;
        }

        retVal = INPUT_NONE;
    } while (0);

    if (retVal != INPUT_NONE)
        sub_080CD110(cursorArea, cursorPosition);

    return retVal;
}



u8 sub_080CF268(void)
{
    u16 i = 0;

    while (gUnknown_85564B8[i].func != NULL)
    {
        if (gUnknown_85564B8[i].area == gUnknown_2039A18)
            return gUnknown_85564B8[i].func();
        i++;
    }

    return INPUT_NONE;
}

void AddBoxOptionsMenu(void)
{
    InitMenu();
    SetMenuText(MENU_JUMP);
    SetMenuText(MENU_WALLPAPER);
    SetMenuText(MENU_NAME);
    SetMenuText(MENU_CANCEL);
}

u8 SetSelectionMenuTexts(void)
{
    InitMenu();
    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return SetMenuTexts_Mon();
    else
        return SetMenuTexts_Item();
}

u8 SetMenuTexts_Mon(void)
{
    u16 species = sub_080CCD80();

    switch (sStorage->boxOption)
    {
    case OPTION_DEPOSIT:
        if (species != SPECIES_NONE)
            SetMenuText(MENU_STORE);
        else
            return FALSE;
        break;
    case OPTION_WITHDRAW:
        if (species != SPECIES_NONE)
            SetMenuText(MENU_WITHDRAW);
        else
            return FALSE;
        break;
    case OPTION_MOVE_MONS:
        if (gUnknown_2039A1A)
        {
            if (species != SPECIES_NONE)
                SetMenuText(MENU_SHIFT);
            else
                SetMenuText(MENU_PLACE);
        }
        else
        {
            if (species != SPECIES_NONE)
                SetMenuText(MENU_MOVE);
            else
                return FALSE;
        }
        break;
    case OPTION_MOVE_ITEMS:
    default:
        return FALSE;
    }

    SetMenuText(MENU_SUMMARY);
    if (sStorage->boxOption == OPTION_MOVE_MONS)
    {
        if (gUnknown_2039A18 == CURSOR_AREA_IN_BOX)
            SetMenuText(MENU_WITHDRAW);
        else
            SetMenuText(MENU_STORE);
    }

    SetMenuText(MENU_MARK);
    SetMenuText(MENU_RELEASE);
    SetMenuText(MENU_CANCEL);
    return TRUE;
}
u8 SetMenuTexts_Item(void)
{
    if (sStorage->displayMonSpecies == SPECIES_EGG)
        return FALSE;

    if (!IsActiveItemMoving())
    {
        if (sStorage->displayMonItemId == ITEM_NONE)
        {
            if (sStorage->displayMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(MENU_GIVE_2);
        }
        else
        {
            if (!ItemIsMail(sStorage->displayMonItemId))
            {
                SetMenuText(MENU_TAKE);
                SetMenuText(MENU_BAG);
            }
            SetMenuText(MENU_INFO);
        }
    }
    else
    {
        if (sStorage->displayMonItemId == ITEM_NONE)
        {
            if (sStorage->displayMonSpecies == SPECIES_NONE)
                return FALSE;

            SetMenuText(MENU_GIVE);
        }
        else
        {
            if (ItemIsMail(sStorage->displayMonItemId) == TRUE)
                return FALSE;

            SetMenuText(MENU_SWITCH);
        }
    }

    SetMenuText(MENU_CANCEL);
    return TRUE;
}
void sub_080CF470(struct Sprite *sprite)
{
    sprite->x = sStorage->cursorSprite->x;
    sprite->y = sStorage->cursorSprite->y + 20;
}
void sub_080CF490(void)
{
    u16 x;
    u16 y;
    u8 spriteId;
    u8 priority;
    u8 subpriority;
    struct CursorSpriteSheetData spriteSheets;
    struct CursorSpritePaletteData spritePalettes;

    spriteSheets = *(const struct CursorSpriteSheetData *)gUnknown_85564E0;
    spritePalettes = *(const struct CursorSpritePaletteData *)gUnknown_85564F8;
    LoadSpriteSheets(spriteSheets.sheets);
    LoadSpritePalettes(spritePalettes.palettes);
    sStorage->cursorPalNums[0] = IndexOfSpritePaletteTag(0xDACA);
    sStorage->cursorPalNums[1] = IndexOfSpritePaletteTag(0xDAC7);

    sub_080CCCC0(gUnknown_2039A18, gUnknown_2039A19, &x, &y);
    spriteId = CreateSprite(&gUnknown_855654C, x, y, 6);
    if (spriteId != MAX_SPRITES)
    {
        sStorage->cursorSprite = &gSprites[spriteId];
        sStorage->cursorSprite->oam.paletteNum = sStorage->cursorPalNums[gUnknown_2039A1D];
        sStorage->cursorSprite->oam.priority = 1;
        if (gUnknown_2039A1A)
            StartSpriteAnim(sStorage->cursorSprite, 3);
    }
    else
    {
        sStorage->cursorSprite = NULL;
    }

    if (gUnknown_2039A18 == CURSOR_AREA_IN_PARTY)
    {
        subpriority = 13;
        priority = 1;
    }
    else
    {
        subpriority = 21;
        priority = 2;
    }

    spriteId = CreateSprite(&gUnknown_8556564, 0, 0, subpriority);
    if (spriteId != MAX_SPRITES)
    {
        sStorage->cursorShadowSprite = &gSprites[spriteId];
        sStorage->cursorShadowSprite->oam.priority = priority;
        if (gUnknown_2039A18)
            sStorage->cursorShadowSprite->invisible = TRUE;
    }
    else
    {
        sStorage->cursorShadowSprite = NULL;
    }
}
void sub_080CF640(void)
{
    gUnknown_2039A1D = !gUnknown_2039A1D;
    sStorage->cursorSprite->oam.paletteNum = sStorage->cursorPalNums[gUnknown_2039A1D];
}

u8 GetCursorPosition(void)
{
    return sCursorPosition;
}


void sub_080CF690(u8 *column, u8 *row)
{
    if (sCursorArea == CURSOR_AREA_IN_BOX)
    {
        *column = sCursorPosition % IN_BOX_COLUMNS;
        *row = sCursorPosition / IN_BOX_COLUMNS;
    }
    else
    {
        *column = 0;
        *row = 0;
    }
}

void StartCursorAnim(u8 anim)
{
    StartSpriteAnim(sStorage->cursorSprite, anim);
}

u8 GetMovingMonOrigBoxId(void)
{
    return sMovingMonOrigBoxId;
}

void SetCursorPriority(void)
{
    sStorage->cursorSprite->oam.priority = 1;
}

void sub_080CF724(void)
{
    if (sCursorArea == CURSOR_AREA_IN_BOX)
        sub_080D06F0(CURSOR_AREA_IN_BOX, sCursorPosition);
}

void sub_080CF748(void)
{
    if (sCursorArea == CURSOR_AREA_IN_BOX)
        sub_080D062C(CURSOR_AREA_IN_BOX, sCursorPosition);
}

void InitMenu(void)
{
    sStorage->menuItemsCount = 0;
    sStorage->menuWidth = 0;
    sStorage->menuWindow.bg = 0;
    sStorage->menuWindow.paletteNum = 15;
    sStorage->menuWindow.baseBlock = 92;
}

void SetMenuText(u8 textId)
{
    if (sStorage->menuItemsCount < ARRAY_COUNT(sStorage->menuItems))
    {
        u8 len;
        struct StorageMenu *menu = &sStorage->menuItems[sStorage->menuItemsCount];

        menu->text = gUnknown_855657C[textId];
        menu->textId = textId;
        len = StringLength(menu->text);
        if (len > sStorage->menuWidth)
            sStorage->menuWidth = len;

        sStorage->menuItemsCount++;
    }
}

s8 sub_080CF814(u8 menuIdx)
{
    if (menuIdx >= sStorage->menuItemsCount)
        return -1;
    else
        return sStorage->menuItems[menuIdx].textId;
}

void AddMenu(void)
{
    sStorage->menuWindow.width = sStorage->menuWidth + 2;
    sStorage->menuWindow.height = 2 * sStorage->menuItemsCount;
    sStorage->menuWindow.tilemapLeft = 29 - sStorage->menuWindow.width;
    sStorage->menuWindow.tilemapTop = 15 - sStorage->menuWindow.height;
    sStorage->menuWindowId = AddWindow(&sStorage->menuWindow);
    ClearWindowTilemap(sStorage->menuWindowId);
    DrawStdFrameWithCustomTileAndPalette(sStorage->menuWindowId, FALSE, 11, 14);
    PrintTextArray(sStorage->menuWindowId, 1, 8, 2, 0x10, sStorage->menuItemsCount, sStorage->menuItems);
    sub_081984F0(sStorage->menuWindowId, 1, 0, 2, sStorage->menuItemsCount, 0);
    ScheduleBgCopyTilemapToVram(0);
    sStorage->menuUnusedField = 0;
}

bool8 sub_080CF948(void)
{
    return 0;
}

s16 sub_080CF94C(void)
{
    s32 input = MENU_NOTHING_CHOSEN;

    do
    {
        if (JOY_NEW(A_BUTTON))
        {
            input = Menu_GetCursorPos();
            break;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            input = MENU_B_PRESSED;
        }

        if (JOY_NEW(DPAD_UP))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(-1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            Menu_MoveCursor(1);
        }
    } while (0);

    if (input != MENU_NOTHING_CHOSEN)
        RemoveMenu();

    if (input >= 0)
        input = sStorage->menuItems[input].textId;

    return input;
}

void RemoveMenu(void)
{
    ClearStdWindowAndFrameToTransparent(sStorage->menuWindowId, TRUE);
    RemoveWindow(sStorage->menuWindowId);
}

bool8 sub_080CFA04(void)
{
    sMultiMove = Alloc(sizeof(*sMultiMove));
    if (sMultiMove != NULL)
    {
        sStorage->multiMoveWindowId = AddWindow8Bit((const struct WindowTemplate *)gUnknown_8556618);
        if (sStorage->multiMoveWindowId != WINDOW_NONE)
        {
            FillWindowPixelBuffer(sStorage->multiMoveWindowId, PIXEL_FILL(0));
            return TRUE;
        }
    }

    return FALSE;
}

void MultiMove_Free(void)
{
    if (sMultiMove != NULL)
        Free(sMultiMove);
}

void MultiMove_SetFunction(u8 id)
{
    sMultiMove->funcId = id;
    sMultiMove->state = 0;
}

bool8 sub_080CFA84(void)
{
    switch (sMultiMove->funcId)
    {
    case 0:
        return sub_080CFAEC();
    case 1:
        return sub_080CFBE4();
    case 2:
        return sub_080CFC50();
    case 3:
        return sub_080CFCC0();
    case 4:
        return sub_080CFD40();
    case 5:
        return sub_080CFD68();
    }
    return FALSE;
}

bool8 sub_080CFAEC(void)
{
    switch (sMultiMove->state)
    {
    case 0:
        HideBg(0);
        TryLoadAllMonIconPalettesAtOffset(BG_PLTT_ID(8));
        sMultiMove->state++;
        break;
    case 1:
        sub_080CF690(&sMultiMove->fromColumn, &sMultiMove->fromRow);
        sMultiMove->toColumn = sMultiMove->fromColumn;
        sMultiMove->toRow = sMultiMove->fromRow;
        ChangeBgX(0, -1024, BG_COORD_SET);
        ChangeBgY(0, -1024, BG_COORD_SET);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        FillWindowPixelBuffer8Bit(sStorage->multiMoveWindowId, PIXEL_FILL(0));
        sub_080D0050(sMultiMove->fromColumn, sMultiMove->fromRow);
        SetBgAttribute(0, BG_ATTR_PALETTEMODE, 1);
        PutWindowTilemap(sStorage->multiMoveWindowId);
        CopyWindowToVram8Bit(sStorage->multiMoveWindowId, COPYWIN_FULL);
        BlendPalettes(0x3F00, 8, RGB_WHITE);
        StartCursorAnim(2);
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
        sMultiMove->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool8 sub_080CFBE4(void)
{
    switch (sMultiMove->state)
    {
    case 0:
        HideBg(0);
        sMultiMove->state++;
        break;
    case 1:
        sub_080D03FC();
        StartCursorAnim(0);
        sMultiMove->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetCursorPriority();
            LoadPalette(GetTextWindowPalette(3), BG_PLTT_ID(13), PLTT_SIZE_4BPP);
            ShowBg(0);
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool8 sub_080CFC50(void)
{
    switch (sMultiMove->state)
    {
    case 0:
        if (!sub_080CCDD0())
        {
            sub_080CF690(&sMultiMove->cursorColumn, &sMultiMove->cursorRow);
            sub_080CFECC();
            sMultiMove->toColumn = sMultiMove->cursorColumn;
            sMultiMove->toRow = sMultiMove->cursorRow;
            CopyWindowToVram8Bit(sStorage->multiMoveWindowId, COPYWIN_GFX);
            sMultiMove->state++;
        }
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}


bool8 sub_080CFCC0(void)
{
    bool8 movingBg;
    bool8 movingMon;

    switch (sMultiMove->state)
    {
    case 0:
        sub_080D016C();
        sub_080D0244();
        InitMultiMonPlaceChange(FALSE);
        sMultiMove->state++;
        break;
    case 1:
        if (!DoMonPlaceChange())
        {
            StartCursorAnim(3);
            MultiMove_InitMove(0, Q_8_8(1), 8);
            InitMultiMonPlaceChange(TRUE);
            sMultiMove->state++;
        }
        break;
    case 2:
        movingBg = sub_080D0134();
        movingMon = DoMonPlaceChange();
        if (!movingBg && !movingMon)
            return FALSE;
        break;
    }

    return TRUE;
}

bool8 sub_080CFD40(void)
{
    bool8 movingCursor = sub_080CCDD0();
    bool8 movingBg = sub_080D0134();

    if (!movingCursor && !movingBg)
        return FALSE;
    else
        return TRUE;
}

bool8 sub_080CFD68(void)
{
    switch (sMultiMove->state)
    {
    case 0:
        sub_080D034C();
        MultiMove_InitMove(0, Q_8_8(-1), 8);
        InitMultiMonPlaceChange(FALSE);
        sMultiMove->state++;
        break;
    case 1:
        if (!DoMonPlaceChange() && !sub_080D0134())
        {
            sub_080D02BC();
            StartCursorAnim(2);
            InitMultiMonPlaceChange(TRUE);
            HideBg(0);
            sMultiMove->state++;
        }
        break;
    case 2:
        if (!DoMonPlaceChange())
        {
            StartCursorAnim(0);
            sub_080D03FC();
            sMultiMove->state++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LoadPalette(GetTextWindowPalette(3), BG_PLTT_ID(13), PLTT_SIZE_4BPP);
            SetCursorPriority();
            ShowBg(0);
            return FALSE;
        }
        break;
    }
    return TRUE;
}

bool8 sub_080CFE20(u8 dir)
{
    switch (dir)
    {
    case 0:
        if (sMultiMove->minRow == 0)
            return FALSE;
        sMultiMove->minRow--;
        MultiMove_InitMove(0, Q_8_8(4), 6);
        break;
    case 1:
        if (sMultiMove->minRow + sMultiMove->rowsTotal >= IN_BOX_ROWS)
            return FALSE;
        sMultiMove->minRow++;
        MultiMove_InitMove(0, Q_8_8(-4), 6);
        break;
    case 2:
        if (sMultiMove->minColumn == 0)
            return FALSE;
        sMultiMove->minColumn--;
        MultiMove_InitMove(Q_8_8(4), 0, 6);
        break;
    case 3:
        if (sMultiMove->minColumn + sMultiMove->columnsTotal >= IN_BOX_COLUMNS)
            return FALSE;
        sMultiMove->minColumn++;
        MultiMove_InitMove(Q_8_8(-4), 0, 6);
        break;
    }
    return TRUE;
}

void sub_080CFECC(void)
{
    s16 columnChange = (abs(sMultiMove->fromColumn - sMultiMove->cursorColumn)) - (abs(sMultiMove->fromColumn - sMultiMove->toColumn));
    s16 rowChange = (abs(sMultiMove->fromRow - sMultiMove->cursorRow)) - (abs(sMultiMove->fromRow - sMultiMove->toRow));

    if (columnChange > 0)
        sub_080CFF70(sMultiMove->cursorColumn, sMultiMove->fromRow, sMultiMove->toRow);

    if (columnChange < 0)
    {
        sub_080CFFE0(sMultiMove->toColumn, sMultiMove->fromRow, sMultiMove->toRow);
        sub_080CFF70(sMultiMove->cursorColumn, sMultiMove->fromRow, sMultiMove->toRow);
    }

    if (rowChange > 0)
        sub_080CFFA8(sMultiMove->cursorRow, sMultiMove->fromColumn, sMultiMove->toColumn);

    if (rowChange < 0)
    {
        sub_080D0018(sMultiMove->toRow, sMultiMove->fromColumn, sMultiMove->toColumn);
        sub_080CFFA8(sMultiMove->cursorRow, sMultiMove->fromColumn, sMultiMove->toColumn);
    }
}

void sub_080CFF70(u8 column, u8 minRow, u8 maxRow)
{
    if (minRow > maxRow)
    {
        u8 temp;
        SWAP(minRow, maxRow, temp);
    }

    while (minRow <= maxRow)
        sub_080D0050(column, minRow++);
}

void sub_080CFFA8(u8 row, u8 minColumn, u8 maxColumn)
{
    if (minColumn > maxColumn)
    {
        u8 temp;
        SWAP(minColumn, maxColumn, temp);
    }

    while (minColumn <= maxColumn)
        sub_080D0050(minColumn++, row);
}

void sub_080CFFE0(u8 column, u8 minRow, u8 maxRow)
{
    if (minRow > maxRow)
    {
        u8 temp;
        SWAP(minRow, maxRow, temp);
    }

    while (minRow <= maxRow)
        sub_080D00D4(column, minRow++);
}

void sub_080D0018(u8 row, u8 minColumn, u8 maxColumn)
{
    if (minColumn > maxColumn)
    {
        u8 temp;
        SWAP(minColumn, maxColumn, temp);
    }

    while (minColumn <= maxColumn)
        sub_080D00D4(minColumn++, row);
}

void sub_080D0050(u8 x, u8 y)
{
    u8 position = x + (IN_BOX_COLUMNS * y);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES_OR_EGG);
    u32 personality = GetCurrentBoxMonData(position, MON_DATA_PERSONALITY);

    if (species != SPECIES_NONE)
    {
        const u8 *iconGfx = GetMonIconPtr(species, personality, 1);
        u8 index = GetValidMonIconPalIndex(species) + 8;

        BlitBitmapRectToWindow4BitTo8Bit(sStorage->multiMoveWindowId,
                                         iconGfx,
                                         0,
                                         0,
                                         32,
                                         32,
                                         24 * x,
                                         24 * y,
                                         32,
                                         32,
                                         index);
    }
}

void sub_080D00D4(u8 x, u8 y)
{
    u8 position = x + (IN_BOX_COLUMNS * y);
    u16 species = GetCurrentBoxMonData(position, MON_DATA_SPECIES_OR_EGG);

    if (species != SPECIES_NONE)
    {
        FillWindowPixelRect8Bit(sStorage->multiMoveWindowId,
                                PIXEL_FILL(0),
                                24 * x,
                                24 * y,
                                32,
                                32);
    }
}

void MultiMove_InitMove(u16 x, u16 y, u16 moveSteps)
{
    sMultiMove->bgX = x;
    sMultiMove->bgY = y;
    sMultiMove->bgMoveSteps = moveSteps;
}

u8 sub_080D0134(void)
{
    if (sMultiMove->bgMoveSteps != 0)
    {
        ChangeBgX(0, sMultiMove->bgX, BG_COORD_ADD);
        ChangeBgY(0, sMultiMove->bgY, BG_COORD_ADD);
        sMultiMove->bgMoveSteps--;
    }

    return sMultiMove->bgMoveSteps;
}

void sub_080D016C(void)
{
    s32 i, j;
    s32 columnCount, rowCount;
    u8 boxId;
    u8 monArrayId;

    sMultiMove->minColumn = min(sMultiMove->fromColumn, sMultiMove->toColumn);
    sMultiMove->minRow = min(sMultiMove->fromRow, sMultiMove->toRow);
    sMultiMove->columnsTotal = abs(sMultiMove->fromColumn - sMultiMove->toColumn) + 1;
    sMultiMove->rowsTotal = abs(sMultiMove->fromRow - sMultiMove->toRow) + 1;
    boxId = StorageGetCurrentBox();
    monArrayId = 0;
    columnCount = sMultiMove->minColumn + sMultiMove->columnsTotal;
    rowCount = sMultiMove->minRow + sMultiMove->rowsTotal;
    for (i = sMultiMove->minRow; i < rowCount; i++)
    {
        u8 boxPosition = (IN_BOX_COLUMNS * i) + sMultiMove->minColumn;
        for (j = sMultiMove->minColumn; j < columnCount; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(boxId, boxPosition);
            sMultiMove->boxMons[monArrayId] = *boxMon;

            monArrayId++;
            boxPosition++;
        }
    }
}

void sub_080D0244(void)
{
    s32 i, j;
    s32 columnCount = sMultiMove->minColumn + sMultiMove->columnsTotal;
    s32 rowCount = sMultiMove->minRow + sMultiMove->rowsTotal;
    u8 boxId = StorageGetCurrentBox();

    for (i = sMultiMove->minRow; i < rowCount; i++)
    {
        u8 boxPosition = (IN_BOX_COLUMNS * i) + sMultiMove->minColumn;
        for (j = sMultiMove->minColumn; j < columnCount; j++)
        {
            DestroyBoxMonIconAtPosition(boxPosition);
            ZeroBoxMonAt(boxId, boxPosition);
            boxPosition++;
        }
    }
}

void sub_080D02BC(void)
{
    s32 i, j;
    s32 columnCount = sMultiMove->minColumn + sMultiMove->columnsTotal;
    s32 rowCount = sMultiMove->minRow + sMultiMove->rowsTotal;
    u8 monArrayId = 0;

    for (i = sMultiMove->minRow; i < rowCount; i++)
    {
        u8 boxPosition = (IN_BOX_COLUMNS * i) + sMultiMove->minColumn;
        for (j = sMultiMove->minColumn; j < columnCount; j++)
        {
            if (GetBoxMonData(&sMultiMove->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                sub_080CA9B4(boxPosition);
            monArrayId++;
            boxPosition++;
        }
    }
}

void sub_080D034C(void)
{
    s32 i, j;
    s32 columnCount = sMultiMove->minColumn + sMultiMove->columnsTotal;
    s32 rowCount = sMultiMove->minRow + sMultiMove->rowsTotal;
    u8 boxId = StorageGetCurrentBox();
    u8 monArrayId = 0;

    for (i = sMultiMove->minRow; i < rowCount; i++)
    {
        u8 boxPosition = (IN_BOX_COLUMNS * i) + sMultiMove->minColumn;
        for (j = sMultiMove->minColumn; j < columnCount; j++)
        {
            if (GetBoxMonData(&sMultiMove->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES))
                SetBoxMonAt(boxId, boxPosition, &sMultiMove->boxMons[monArrayId]);
            boxPosition++;
            monArrayId++;
        }
    }
}

void sub_080D03FC(void)
{
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    SetBgAttribute(0, BG_ATTR_PALETTEMODE, 0);
    ClearGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_256COLOR);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

u8 sub_080D0444(void)
{
    return (IN_BOX_COLUMNS * sMultiMove->fromRow) + sMultiMove->fromColumn;
}

bool8 sub_080D0460(void)
{
    s32 i, j;
    s32 columnCount = sMultiMove->minColumn + sMultiMove->columnsTotal;
    s32 rowCount = sMultiMove->minRow + sMultiMove->rowsTotal;
    u8 monArrayId = 0;

    for (i = sMultiMove->minRow; i < rowCount; i++)
    {
        u8 boxPosition = (IN_BOX_COLUMNS * i) + sMultiMove->minColumn;
        for (j = sMultiMove->minColumn; j < columnCount; j++)
        {
            if (GetBoxMonData(&sMultiMove->boxMons[monArrayId], MON_DATA_SANITY_HAS_SPECIES)
                && GetCurrentBoxMonData(boxPosition, MON_DATA_SANITY_HAS_SPECIES))
                return FALSE;

            monArrayId++;
            boxPosition++;
        }
    }
    return TRUE;
}


void sub_080D0500(void)
{
    s32 i;
    u8 spriteId;
    struct CompressedSpriteSheet spriteSheet;
    struct SpriteTemplate spriteTemplate;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        spriteSheet.data = gUnknown_3000F78;
        spriteSheet.size = 0x200;
        spriteTemplate = *(const struct SpriteTemplate *)gUnknown_855676C;

        for (i = 0; i < MAX_ITEM_ICONS; i++)
        {
            spriteSheet.tag = GFXTAG_ITEM_ICON_0 + i;
            LoadCompressedSpriteSheet(&spriteSheet);
            sStorage->itemIcons[i].tiles = GetSpriteTileStartByTag(spriteSheet.tag) * TILE_SIZE_4BPP + (void *)(OBJ_VRAM0);
            sStorage->itemIcons[i].palIndex = AllocSpritePalette(PALTAG_ITEM_ICON_0 + i);
            sStorage->itemIcons[i].palIndex = OBJ_PLTT_ID(sStorage->itemIcons[i].palIndex);
            spriteTemplate.tileTag = GFXTAG_ITEM_ICON_0 + i;
            spriteTemplate.paletteTag = PALTAG_ITEM_ICON_0 + i;
            spriteId = CreateSprite(&spriteTemplate, 0, 0, 11);
            sStorage->itemIcons[i].sprite = &gSprites[spriteId];
            sStorage->itemIcons[i].sprite->invisible = TRUE;
            sStorage->itemIcons[i].active = FALSE;
        }
    }
    sStorage->movingItemId = ITEM_NONE;
}

void sub_080D062C(u8 cursorArea, u8 cursorPos)
{
    u16 heldItem;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    if (sub_080D0BC4(cursorArea, cursorPos))
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        if (!GetCurrentBoxMonData(cursorPos, MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos >= PARTY_SIZE || !GetMonData3(&gPlayerParty[cursorPos], MON_DATA_SANITY_HAS_SPECIES))
            return;
        heldItem = GetMonData3(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        break;
    default:
        return;
    }

    if (heldItem != ITEM_NONE)
    {
        const u32 *tiles = GetItemIconPic(heldItem);
        const u32 *pal = GetItemIconPalette(heldItem);
        u8 id = sub_080D0B88();

        sub_080D0CAC(id, cursorArea, cursorPos);
        sub_080D0DC4(id, tiles, pal);
        sub_080D0E74(id, ITEM_ANIM_APPEAR);
        sub_080D0FE0(id, TRUE);
    }
}

void sub_080D06F0(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_080D0C10(cursorArea, cursorPos);
    sub_080D0E74(id, ITEM_ANIM_DISAPPEAR);
    sub_080D0EA4(id, ITEM_CB_WAIT_ANIM, cursorArea, cursorPos);
}

void Item_FromMonToMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 itemId;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_080D0C10(cursorArea, cursorPos);
    itemId = ITEM_NONE;
    sub_080D0E74(id, ITEM_ANIM_PICK_UP);
    sub_080D0EA4(id, ITEM_CB_TO_HAND, cursorArea, cursorPos);
    sub_080D0CAC(id, CURSOR_AREA_IN_HAND, 0);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &itemId);
        SetBoxMonIconObjMode(cursorPos, ST_OAM_OBJ_BLEND);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &itemId);
        SetPartyMonIconObjMode(cursorPos, ST_OAM_OBJ_BLEND);
    }

    sStorage->movingItemId = sStorage->displayMonItemId;
}

void sub_080D07D8(u16 itemId)
{
    const u32 *tiles = GetItemIconPic(itemId);
    const u32 *pal = GetItemIconPalette(itemId);
    u8 id = sub_080D0B88();

    sub_080D0DC4(id, tiles, pal);
    sub_080D0E74(id, ITEM_ANIM_LARGE);
    sub_080D0EA4(id, ITEM_CB_TO_HAND, CURSOR_AREA_IN_BOX, 0);
    sub_080D0CAC(id, CURSOR_AREA_IN_HAND, 0);
    sub_080D0FE0(id, TRUE);
    sStorage->movingItemId = itemId;
}

void Item_SwitchMonsWithMoving(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 itemId;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_080D0C10(cursorArea, cursorPos);
    sub_080D0E74(id, ITEM_ANIM_PICK_UP);
    sub_080D0EA4(id, ITEM_CB_SWAP_TO_HAND, CURSOR_AREA_IN_HAND, 0);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        itemId = GetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM);
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sStorage->movingItemId);
        sStorage->movingItemId = itemId;
    }
    else
    {
        itemId = GetMonData3(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM);
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sStorage->movingItemId);
        sStorage->movingItemId = itemId;
    }

    id = sub_080D0C10(CURSOR_AREA_IN_HAND, 0);
    sub_080D0E74(id, ITEM_ANIM_PUT_DOWN);
    sub_080D0EA4(id, ITEM_CB_SWAP_TO_MON, cursorArea, cursorPos);
}

void Item_GiveMovingToMon(u8 cursorArea, u8 cursorPos)
{
    u8 id;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    id = sub_080D0C10(CURSOR_AREA_IN_HAND, 0);
    sub_080D0E74(id, ITEM_ANIM_PUT_DOWN);
    sub_080D0EA4(id, ITEM_CB_TO_MON, cursorArea, cursorPos);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &sStorage->movingItemId);
        SetBoxMonIconObjMode(cursorPos, ST_OAM_OBJ_NORMAL);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &sStorage->movingItemId);
        SetPartyMonIconObjMode(cursorPos, ST_OAM_OBJ_NORMAL);
    }
}

void Item_TakeMons(u8 cursorArea, u8 cursorPos)
{
    u8 id;
    u16 itemId;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    itemId = ITEM_NONE;
    id = sub_080D0C10(cursorArea, cursorPos);
    sub_080D0E74(id, ITEM_ANIM_DISAPPEAR);
    sub_080D0EA4(id, ITEM_CB_WAIT_ANIM, cursorArea, cursorPos);
    if (cursorArea == CURSOR_AREA_IN_BOX)
    {
        SetCurrentBoxMonData(cursorPos, MON_DATA_HELD_ITEM, &itemId);
        SetBoxMonIconObjMode(cursorPos, ST_OAM_OBJ_BLEND);
    }
    else
    {
        SetMonData(&gPlayerParty[cursorPos], MON_DATA_HELD_ITEM, &itemId);
        SetPartyMonIconObjMode(cursorPos, ST_OAM_OBJ_BLEND);
    }
}

void sub_080D0A34(void)
{
    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        u8 id = sub_080D0C10(CURSOR_AREA_IN_HAND, 0);
        sub_080D0E74(id, ITEM_ANIM_PUT_AWAY);
        sub_080D0EA4(id, ITEM_CB_WAIT_ANIM, CURSOR_AREA_IN_HAND, 0);
    }
}

void sub_080D0A6C(void)
{
    s32 i;

    if (sStorage->boxOption != OPTION_MOVE_ITEMS)
        return;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (sStorage->itemIcons[i].active
         && sStorage->itemIcons[i].area == CURSOR_AREA_IN_PARTY)
            sub_080D0EA4(i, ITEM_CB_HIDE_PARTY, CURSOR_AREA_IN_HAND, 0);
    }
}

bool8 sub_080D0AB8(void)
{
    s32 i;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (sStorage->itemIcons[i].active)
        {
            if (!sStorage->itemIcons[i].sprite->affineAnimEnded
             && sStorage->itemIcons[i].sprite->affineAnimBeginning)
                return TRUE;
            if (sStorage->itemIcons[i].sprite->callback != SpriteCallbackDummy
             && sStorage->itemIcons[i].sprite->callback != sub_080D1378)
                return TRUE;
        }
    }
    return FALSE;
}

bool8 IsActiveItemMoving(void)
{
    s32 i;

    if (sStorage->boxOption == OPTION_MOVE_ITEMS)
    {
        for (i = 0; i < MAX_ITEM_ICONS; i++)
        {
            if (sStorage->itemIcons[i].active
             && sStorage->itemIcons[i].area == CURSOR_AREA_IN_HAND)
                return TRUE;
        }
    }
    return FALSE;
}

const u8 *GetMovingItemName(void)
{
    return ItemId_GetName(sStorage->movingItemId);
}

u16 GetMovingItemId(void)
{
    return sStorage->movingItemId;
}

u8 sub_080D0B88(void)
{
    u8 i;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (!sStorage->itemIcons[i].active)
        {
            sStorage->itemIcons[i].active = TRUE;
            return i;
        }
    }
    return MAX_ITEM_ICONS;
}

bool32 sub_080D0BC4(u8 cursorArea, u8 cursorPos)
{
    s32 i;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (sStorage->itemIcons[i].active
         && sStorage->itemIcons[i].area == cursorArea
         && sStorage->itemIcons[i].pos == cursorPos)
            return TRUE;
    }
    return FALSE;
}

u8 sub_080D0C10(u8 cursorArea, u8 cursorPos)
{
    u8 i;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (sStorage->itemIcons[i].active
         && sStorage->itemIcons[i].area == cursorArea
         && sStorage->itemIcons[i].pos == cursorPos)
            return i;
    }
    return MAX_ITEM_ICONS;
}

u8 sub_080D0C64(struct Sprite *sprite)
{
    u8 i;

    for (i = 0; i < MAX_ITEM_ICONS; i++)
    {
        if (sStorage->itemIcons[i].active
         && sStorage->itemIcons[i].sprite == sprite)
            return i;
    }
    return MAX_ITEM_ICONS;
}

void sub_080D0CAC(u8 id, u8 cursorArea, u8 cursorPos)
{
    u8 x, y;

    if (id >= MAX_ITEM_ICONS)
        return;

    switch (cursorArea)
    {
    case CURSOR_AREA_IN_BOX:
        x = cursorPos % IN_BOX_COLUMNS;
        y = cursorPos / IN_BOX_COLUMNS;
        sStorage->itemIcons[id].sprite->x = (24 * x) + 112;
        sStorage->itemIcons[id].sprite->y = (24 * y) + 56;
        sStorage->itemIcons[id].sprite->oam.priority = 2;
        break;
    case CURSOR_AREA_IN_PARTY:
        if (cursorPos == 0)
        {
            sStorage->itemIcons[id].sprite->x = 116;
            sStorage->itemIcons[id].sprite->y = 76;
        }
        else
        {
            sStorage->itemIcons[id].sprite->x = 164;
            sStorage->itemIcons[id].sprite->y = 24 * (cursorPos - 1) + 28;
        }
        sStorage->itemIcons[id].sprite->oam.priority = 1;
        break;
    }

    sStorage->itemIcons[id].area = cursorArea;
    sStorage->itemIcons[id].pos = cursorPos;
}

void sub_080D0DC4(u8 id, const u32 *itemTiles, const u32 *itemPal)
{
    s32 i;

    if (id >= MAX_ITEM_ICONS)
        return;

    CpuFastFill(0, sStorage->itemIconBuffer, 0x200);
    LZ77UnCompWram(itemTiles, sStorage->tileBuffer);
    for (i = 0; i < 3; i++)
        CpuFastCopy(&sStorage->tileBuffer[i * 0x60], &sStorage->itemIconBuffer[i * 0x80], 0x60);

    CpuFastCopy(sStorage->itemIconBuffer, sStorage->itemIcons[id].tiles, 0x200);
    LZ77UnCompWram(itemPal, sStorage->itemIconBuffer);
    LoadPalette(sStorage->itemIconBuffer, sStorage->itemIcons[id].palIndex, PLTT_SIZE_4BPP);
}


void sub_080D0E74(u8 id, u8 animNum)
{
    if (id >= MAX_ITEM_ICONS)
        return;

    StartSpriteAffineAnim(sStorage->itemIcons[id].sprite, animNum);
}

// Kept as naked asm: JP callback IDs retain cases 6/7, so the US-shaped dispatcher
// emits 0x134 rather than the JP 0x13C bytes and differs after relocation normalization.
__attribute__((naked)) void sub_080D0EA4(u8 id, u8 callbackId, u8 cursorArea, u8 cursorPos)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r0, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r5, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	cmp r4, #2\n\t"
        "	bls _080D0EBC\n\t"
        "	b _080D0FCE\n\t"
        "_080D0EBC:\n\t"
        "	cmp r0, #7\n\t"
        "	bls _080D0EC2\n\t"
        "	b _080D0FCE\n\t"
        "_080D0EC2:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080D0ECC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080D0ECC: .4byte 0x080D0ED0\n\t"
        "_080D0ED0: @ jump table\n\t"
        "	.4byte _080D0EF0 @ case 0\n\t"
        "	.4byte _080D0F14 @ case 1\n\t"
        "	.4byte _080D0F38 @ case 2\n\t"
        "	.4byte _080D0F64 @ case 3\n\t"
        "	.4byte _080D0F90 @ case 4\n\t"
        "	.4byte _080D0FCE @ case 5\n\t"
        "	.4byte _080D0FCE @ case 6\n\t"
        "	.4byte _080D0FBC @ case 7\n\t"
        "_080D0EF0:\n\t"
        "	ldr r0, _080D0F08\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0F0C\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	strh r4, [r1, #0x2e]\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080D0F10\n\t"
        "	b _080D0FCC\n\t"
        "	.align 2, 0\n\t"
        "_080D0F08: .4byte gUnknown_20399A8\n\t"
        "_080D0F0C: .4byte 0x00002204\n\t"
        "_080D0F10: .4byte sub_080D12E8 + 1\n\t"
        "_080D0F14:\n\t"
        "	ldr r0, _080D0F2C\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0F30\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r2, #0x2e]\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080D0F34\n\t"
        "	b _080D0FCC\n\t"
        "	.align 2, 0\n\t"
        "_080D0F2C: .4byte gUnknown_20399A8\n\t"
        "_080D0F30: .4byte 0x00002204\n\t"
        "_080D0F34: .4byte sub_080D1314 + 1\n\t"
        "_080D0F38:\n\t"
        "	ldr r0, _080D0F58\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0F5C\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r2, #0x2e]\n\t"
        "	ldr r1, [r0]\n\t"
        "	strh r5, [r1, #0x3a]\n\t"
        "	ldr r1, [r0]\n\t"
        "	strh r3, [r1, #0x3c]\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080D0F60\n\t"
        "	b _080D0FCC\n\t"
        "	.align 2, 0\n\t"
        "_080D0F58: .4byte gUnknown_20399A8\n\t"
        "_080D0F5C: .4byte 0x00002204\n\t"
        "_080D0F60: .4byte sub_080D13B4 + 1\n\t"
        "_080D0F64:\n\t"
        "	ldr r0, _080D0F84\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0F88\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r2, #0x2e]\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldr r1, _080D0F8C\n\t"
        "	str r1, [r2, #0x1c]\n\t"
        "	strh r5, [r2, #0x3a]\n\t"
        "	ldr r0, [r0]\n\t"
        "	strh r3, [r0, #0x3c]\n\t"
        "	b _080D0FCE\n\t"
        "	.align 2, 0\n\t"
        "_080D0F84: .4byte gUnknown_20399A8\n\t"
        "_080D0F88: .4byte 0x00002204\n\t"
        "_080D0F8C: .4byte sub_080D1434 + 1\n\t"
        "_080D0F90:\n\t"
        "	ldr r0, _080D0FB0\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0FB4\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r2, #0x2e]\n\t"
        "	ldr r1, [r0]\n\t"
        "	strh r5, [r1, #0x3a]\n\t"
        "	ldr r1, [r0]\n\t"
        "	strh r3, [r1, #0x3c]\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080D0FB8\n\t"
        "	b _080D0FCC\n\t"
        "	.align 2, 0\n\t"
        "_080D0FB0: .4byte gUnknown_20399A8\n\t"
        "_080D0FB4: .4byte 0x00002204\n\t"
        "_080D0FB8: .4byte sub_080D14D0 + 1\n\t"
        "_080D0FBC:\n\t"
        "	ldr r0, _080D0FD4\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r4, #4\n\t"
        "	ldr r2, _080D0FD8\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080D0FDC\n\t"
        "_080D0FCC:\n\t"
        "	str r0, [r1, #0x1c]\n\t"
        "_080D0FCE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D0FD4: .4byte gUnknown_20399A8\n\t"
        "_080D0FD8: .4byte 0x00002204\n\t"
        "_080D0FDC: .4byte sub_080D156C + 1\n\t"
        ".syntax divided\n\t"
    );
}

void sub_080D0FE0(u8 id, bool8 active)
{
    if (id >= MAX_ITEM_ICONS)
        return;

    sStorage->itemIcons[id].active = active;
    sStorage->itemIcons[id].sprite->invisible = (active == FALSE);
}

const void *GetItemIconPic(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 0);
}

const void *GetItemIconPalette(u16 itemId)
{
    return GetItemIconPicOrPalette(itemId, 1);
}

void Cb_HandleMovingMonFromParty(void)
{
    const u8 *description;

    if (IsActiveItemMoving())
        description = ItemId_GetHoldEffect(sStorage->movingItemId);
    else
        description = ItemId_GetHoldEffect(sStorage->displayMonItemId);

    FillWindowPixelBuffer(2, PIXEL_FILL(1));
    AddTextPrinterParameterized5(2, 1, description, 4, 0, 0, NULL, 0, 1);
}

void sub_080D1254(u32 x);

void sub_080D10B8(void)
{
    sStorage->itemInfoWindowOffset = 21;
    LoadBgTiles(0, gUnknown_8556620, 0x80, 0x13A);
    sub_080D1254(0);
}

bool8 sub_080D10EC(void)
{
    s32 i, pos;

    if (sStorage->itemInfoWindowOffset == 0)
        return FALSE;

    sStorage->itemInfoWindowOffset--;
    pos = 21 - sStorage->itemInfoWindowOffset;
    for (i = 0; i < pos; i++)
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sStorage->itemInfoWindowOffset + i, i, 13, 1, 7, 15, 21);

    sub_080D1254(pos);
    return (sStorage->itemInfoWindowOffset != 0);
}

bool8 sub_080D1184(void)
{
    s32 i, pos;

    if (sStorage->itemInfoWindowOffset == 22)
        return FALSE;

    if (sStorage->itemInfoWindowOffset == 0)
        FillBgTilemapBufferRect(0, 0, 21, 12, 1, 9, 17);

    sStorage->itemInfoWindowOffset++;
    pos = 21 - sStorage->itemInfoWindowOffset;
    for (i = 0; i < pos; i++)
    {
        WriteSequenceToBgTilemapBuffer(0, GetBgAttribute(0, BG_ATTR_BASETILE) + 0x14 + sStorage->itemInfoWindowOffset + i, i, 13, 1, 7, 15, 21);
    }

    if (pos >= 0)
        sub_080D1254(pos);

    FillBgTilemapBufferRect(0, 0, pos + 1, 12, 1, 9, 17);
    ScheduleBgCopyTilemapToVram(0);
    return TRUE;
}

void sub_080D1254(u32 x)
{
    if (x != 0)
    {
        FillBgTilemapBufferRect(0, 0x13A, 0, 0xC, x, 1, 15);
        FillBgTilemapBufferRect(0, 0x93A, 0, 0x14, x, 1, 15);
    }
    FillBgTilemapBufferRect(0, 0x13B, x, 0xD, 1, 7, 15);
    FillBgTilemapBufferRect(0, 0x13C, x, 0xC, 1, 1, 15);
    FillBgTilemapBufferRect(0, 0x13D, x, 0x14, 1, 1, 15);
    ScheduleBgCopyTilemapToVram(0);
}

void sub_080D12E8(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sub_080D0FE0(sprite->data[0], FALSE);
        sprite->callback = SpriteCallbackDummy;
    }
}

void sub_080D1378(struct Sprite *sprite);

void sub_080D1314(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->x << 4;
        sprite->data[2] = sprite->y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->x = sprite->data[1] >> 4;
        sprite->y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
            sprite->callback = sub_080D1378;
        break;
    }
}

void sub_080D1378(struct Sprite *sprite)
{
    sprite->x = sStorage->cursorSprite->x + 4;
    sprite->y = sStorage->cursorSprite->y + sStorage->cursorSprite->y2 + 8;
    sprite->oam.priority = sStorage->cursorSprite->oam.priority;
}

void sub_080D13B4(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->x << 4;
        sprite->data[2] = sprite->y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->x = sprite->data[1] >> 4;
        sprite->y = sprite->data[2] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_080D0CAC(sub_080D0C64(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

void sub_080D1434(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->x << 4;
        sprite->data[2] = sprite->y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] -= sprite->data[3];
        sprite->data[2] -= sprite->data[4];
        sprite->x = sprite->data[1] >> 4;
        sprite->y = sprite->data[2] >> 4;
        sprite->x2 = gSineTable[sprite->data[5] * 8] >> 4;
        if (++sprite->data[5] > 11)
        {
            sub_080D0CAC(sub_080D0C64(sprite), sprite->data[6], sprite->data[7]);
            sprite->x2 = 0;
            sprite->callback = sub_080D1378;
        }
        break;
    }
}

void sub_080D14D0(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = sprite->x << 4;
        sprite->data[2] = sprite->y << 4;
        sprite->data[3] = 10;
        sprite->data[4] = 21;
        sprite->data[5] = 0;
        sprite->data[0]++;
    case 1:
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->x = sprite->data[1] >> 4;
        sprite->y = sprite->data[2] >> 4;
        sprite->x2 = -(gSineTable[sprite->data[5] * 8] >> 4);
        if (++sprite->data[5] > 11)
        {
            sub_080D0CAC(sub_080D0C64(sprite), sprite->data[6], sprite->data[7]);
            sprite->callback = SpriteCallbackDummy;
            sprite->x2 = 0;
        }
        break;
    }
}

void sub_080D156C(struct Sprite *sprite)
{
    sprite->y -= 8;
    if (sprite->y + sprite->y2 < -16)
    {
        sprite->callback = SpriteCallbackDummy;
        sub_080D0FE0(sub_080D0C64(sprite), FALSE);
    }
}

void nullsub_98(void) {}
void nullsub_pss(void) {}
u8 StorageGetCurrentBox(void)
{
    return gPokemonStoragePtr->currentBox;
}


void SetCurrentBox(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        gPokemonStoragePtr->currentBox = boxId;
}

u32 GetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request);
    else
        return 0;
}

void SetBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, const void *value)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, value);
}

u32 GetCurrentBoxMonData(u8 boxPosition, s32 request)
{
    return GetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request);
}

void SetCurrentBoxMonData(u8 boxPosition, s32 request, const void *value)
{
    SetBoxMonDataAt(gPokemonStoragePtr->currentBox, boxPosition, request, value);
}

void GetBoxMonNickAt(u8 boxId, u8 boxPosition, u8 *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, dst);
    else
        *dst = EOS;
}

u32 GetBoxMonLevelAt(u8 boxId, u8 boxPosition)
{
    u32 lvl;

    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES))
        lvl = GetLevelFromBoxMonExp(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
    lvl = 0;

    return lvl;
}

void SetBoxMonNickAt(u8 boxId, u8 boxPosition, const u8 *nick)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        SetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_NICKNAME, nick);
}

u32 GetAndCopyBoxMonDataAt(u8 boxId, u8 boxPosition, s32 request, void *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], request, dst);
    else
        return 0;
}

void SetBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *src)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        gPokemonStoragePtr->boxes[boxId][boxPosition] = *src;
}

void CopyBoxMonAt(u8 boxId, u8 boxPosition, struct BoxPokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        *dst = gPokemonStoragePtr->boxes[boxId][boxPosition];
}

void CreateBoxMonAt(u8 boxId, u8 boxPosition, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 personality, u8 otIDType, u32 otID)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
    {
        CreateBoxMon(&gPokemonStoragePtr->boxes[boxId][boxPosition],
                     species,
                     level,
                     fixedIV,
                     hasFixedPersonality, personality,
                     otIDType, otID);
    }
}

void ZeroBoxMonAt(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        ZeroBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition]);
}

void BoxMonAtToMon(u8 boxId, u8 boxPosition, struct Pokemon *dst)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        BoxMonToMon(&gPokemonStoragePtr->boxes[boxId][boxPosition], dst);
}

struct BoxPokemon *GetBoxedMonPtr(u8 boxId, u8 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT && boxPosition < IN_BOX_COUNT)
        return &gPokemonStoragePtr->boxes[boxId][boxPosition];
    else
        return NULL;
}

u8 *GetBoxNamePtr(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxNames[boxId];
    else
        return NULL;
}

u8 GetBoxWallpaper(u8 boxId)
{
    if (boxId < TOTAL_BOXES_COUNT)
        return gPokemonStoragePtr->boxWallpapers[boxId];
    else
        return 0;
}

void SetBoxWallpaper(u8 boxId, u8 wallpaperId)
{
    if (boxId < TOTAL_BOXES_COUNT && wallpaperId <= 16)
        gPokemonStoragePtr->boxWallpapers[boxId] = wallpaperId;
}

bool8 CheckFreePokemonStorageSpace(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES))
                return TRUE;
        }
    }

    return FALSE;
}

s16 sub_080D19EC(struct BoxPokemon *boxMons, u8 currIndex, u8 maxIndex, u8 mode)
{
    s16 i;
    s16 direction = -1;

    if (mode == 0 || mode == 1)
        direction = 1;

    if (mode == 1 || mode == 3)
    {
        for (i = (s8)currIndex + direction; i >= 0 && i <= maxIndex; i += direction)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE)
                return i;
        }
    }
    else
    {
        for (i = (s8)currIndex + direction; i >= 0 && i <= maxIndex; i += direction)
        {
            if (GetBoxMonData(&boxMons[i], MON_DATA_SPECIES) != SPECIES_NONE
                && !GetBoxMonData(&boxMons[i], MON_DATA_IS_EGG))
                return i;
        }
    }

    return -1;
}

bool32 CheckBoxMonSanityAt(u32 boxId, u32 boxPosition)
{
    if (boxId < TOTAL_BOXES_COUNT
        && boxPosition < IN_BOX_COUNT
        && GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_HAS_SPECIES)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_EGG)
        && !GetBoxMonData(&gPokemonStoragePtr->boxes[boxId][boxPosition], MON_DATA_SANITY_IS_BAD_EGG))
        return TRUE;
    else
        return FALSE;
}

u32 CountStorageNonEggMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

u32 CountAllStorageMons(void)
{
    s32 i, j;
    u32 count = 0;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                || GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG))
                count++;
        }
    }

    return count;
}

bool32 AnyStorageMonWithMove(u16 move)
{
    u16 moves[] = {move, MOVES_COUNT};
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_HAS_SPECIES)
                && !GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_SANITY_IS_EGG)
                && GetBoxMonData(&gPokemonStoragePtr->boxes[i][j], MON_DATA_KNOWN_MOVES, (u8 *)moves))
                return TRUE;
        }
    }

    return FALSE;
}

void ResetWaldaWallpaper(void)
{
    gSaveBlock1Ptr->waldaPhrase.iconId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternId = 0;
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = FALSE;
    gSaveBlock1Ptr->waldaPhrase.colors[0] = RGB(21, 25, 30);
    gSaveBlock1Ptr->waldaPhrase.colors[1] = RGB(6, 12, 24);
    gSaveBlock1Ptr->waldaPhrase.text[0] = EOS;
}

void SetWaldaWallpaperLockedOrUnlocked(bool32 unlocked)
{
    gSaveBlock1Ptr->waldaPhrase.patternUnlocked = unlocked;
}

bool32 IsWaldaWallpaperUnlocked(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternUnlocked;
}

u32 GetWaldaWallpaperPatternId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.patternId;
}

void SetWaldaWallpaperPatternId(u8 id)
{
    if (id < WALDA_WALLPAPERS_COUNT)
        gSaveBlock1Ptr->waldaPhrase.patternId = id;
}

u32 GetWaldaWallpaperIconId(void)
{
    return gSaveBlock1Ptr->waldaPhrase.iconId;
}

void SetWaldaWallpaperIconId(u8 id)
{
    if (id < WALDA_WALLPAPER_ICONS_COUNT)
        gSaveBlock1Ptr->waldaPhrase.iconId = id;
}

u16 *GetWaldaWallpaperColorsPtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.colors;
}

void SetWaldaWallpaperColors(u16 color1, u16 color2)
{
    gSaveBlock1Ptr->waldaPhrase.colors[0] = color1;
    gSaveBlock1Ptr->waldaPhrase.colors[1] = color2;
}

u8 *GetWaldaPhrasePtr(void)
{
    return gSaveBlock1Ptr->waldaPhrase.text;
}

void SetWaldaPhrase(const u8 *src)
{
    StringCopy(gSaveBlock1Ptr->waldaPhrase.text, src);
}

bool32 IsWaldaPhraseEmpty(void)
{
    return gSaveBlock1Ptr->waldaPhrase.text[0] == EOS;
}

void sub_080D1E3C(u8 count)
{
    u16 i;

    sTilemapUtil = Alloc(sizeof(*sTilemapUtil) * count);
    sNumTilemapUtilIds = (sTilemapUtil == NULL) ? 0 : count;
    for (i = 0; i < sNumTilemapUtilIds; i++)
    {
        sTilemapUtil[i].savedTilemap = NULL;
        sTilemapUtil[i].active = FALSE;
    }
}

void TilemapUtil_Free(void)
{
    Free(sTilemapUtil);
}

void sub_080D2200(u8 id);
void sub_080D2298(u8 id);
void sub_080D21B8(u8 id);

void sub_080D1EA4(void)
{
    s32 i;

    for (i = 0; i < sNumTilemapUtilIds; i++)
    {
        if (sTilemapUtil[i].active == TRUE)
            sub_080D21B8(i);
    }
}

void sub_080D1EE4(u8 id, u8 bg, const void *tilemap, u16 width, u16 height)
{
    u16 bgScreenSize, bgType;

    if (id >= sNumTilemapUtilIds)
        return;

    sTilemapUtil[id].savedTilemap = NULL;
    sTilemapUtil[id].tilemap = tilemap;
    sTilemapUtil[id].bg = bg;
    sTilemapUtil[id].width = width;
    sTilemapUtil[id].height = height;

    bgScreenSize = GetBgAttribute(bg, BG_ATTR_SCREENSIZE);
    bgType = GetBgAttribute(bg, BG_ATTR_TYPE);
    sTilemapUtil[id].altWidth = sTilemapDimensions[bgType][bgScreenSize].width;
    sTilemapUtil[id].altHeight = sTilemapDimensions[bgType][bgScreenSize].height;
    if (bgType != 0)
        sTilemapUtil[id].tileSize = 1;
    else
        sTilemapUtil[id].tileSize = 2;

    sTilemapUtil[id].rowSize = sTilemapUtil[id].tileSize * width;
    sTilemapUtil[id].cur.width = width;
    sTilemapUtil[id].cur.height = height;
    sTilemapUtil[id].cur.x = 0;
    sTilemapUtil[id].cur.y = 0;
    sTilemapUtil[id].cur.destX = 0;
    sTilemapUtil[id].cur.destY = 0;
    sTilemapUtil[id].prev = sTilemapUtil[id].cur;
    sTilemapUtil[id].active = TRUE;
}


void sub_080D1FE0(u8 id, const void *tilemap)
{
    if (id >= sNumTilemapUtilIds)
        return;

    sTilemapUtil[id].savedTilemap = tilemap;
    sTilemapUtil[id].active = TRUE;
}

void sub_080D2010(u8 id, u16 x, u16 y)
{
    if (id >= sNumTilemapUtilIds)
        return;

    sTilemapUtil[id].cur.destX = x;
    sTilemapUtil[id].cur.destY = y;
    sTilemapUtil[id].active = TRUE;
}

void sub_080D204C(u8 id, u16 x, u16 y, u16 width, u16 height)
{
    if (id >= sNumTilemapUtilIds)
        return;

    sTilemapUtil[id].cur.x = x;
    sTilemapUtil[id].cur.y = y;
    sTilemapUtil[id].cur.width = width;
    sTilemapUtil[id].cur.height = height;
    sTilemapUtil[id].active = TRUE;
}

void sub_080D2094(u8 id, u8 mode, s8 val)
{
    if (id >= sNumTilemapUtilIds)
        return;

    switch (mode)
    {
    case 0:
        sTilemapUtil[id].cur.destX += val;
        sTilemapUtil[id].cur.width -= val;
        break;
    case 1:
        sTilemapUtil[id].cur.x += val;
        sTilemapUtil[id].cur.width += val;
        break;
    case 2:
        sTilemapUtil[id].cur.destY += val;
        sTilemapUtil[id].cur.height -= val;
        break;
    case 3:
        sTilemapUtil[id].cur.y -= val;
        sTilemapUtil[id].cur.height += val;
        break;
    case 4:
        sTilemapUtil[id].cur.destX += val;
        break;
    case 5:
        sTilemapUtil[id].cur.destY += val;
        break;
    }

    sTilemapUtil[id].active = TRUE;
}

void sub_080D21B8(u8 id)
{
    if (id >= sNumTilemapUtilIds)
        return;

    if (sTilemapUtil[id].savedTilemap != NULL)
        sub_080D2200(id);

    sub_080D2298(id);
    sTilemapUtil[id].prev = sTilemapUtil[id].cur;
}

void sub_080D2200(u8 id)
{
    s32 i;
    u32 adder = sTilemapUtil[id].tileSize * sTilemapUtil[id].altWidth;
    const void *tiles = (sTilemapUtil[id].savedTilemap + (adder * sTilemapUtil[id].prev.destY))
                      + (sTilemapUtil[id].tileSize * sTilemapUtil[id].prev.destX);

    for (i = 0; i < sTilemapUtil[id].prev.height; i++)
    {
        CopyToBgTilemapBufferRect(sTilemapUtil[id].bg,
                                  tiles,
                                  sTilemapUtil[id].prev.destX,
                                  sTilemapUtil[id].prev.destY + i,
                                  sTilemapUtil[id].prev.width,
                                  1);
        tiles += adder;
    }
}

void sub_080D2298(u8 id)
{
    s32 i;
    u32 adder = sTilemapUtil[id].tileSize * sTilemapUtil[id].width;
    const void *tiles = (sTilemapUtil[id].tilemap + (adder * sTilemapUtil[id].cur.y))
                      + (sTilemapUtil[id].tileSize * sTilemapUtil[id].cur.x);

    for (i = 0; i < sTilemapUtil[id].cur.height; i++)
    {
        CopyToBgTilemapBufferRect(sTilemapUtil[id].bg,
                                  tiles,
                                  sTilemapUtil[id].cur.destX,
                                  sTilemapUtil[id].cur.destY + i,
                                  sTilemapUtil[id].cur.width,
                                  1);
        tiles += adder;
    }
}

void UnkUtil_Init(struct UnkUtil *util, struct UnkUtilData *data, u32 max)
{
    sUnkUtil = util;
    util->data = data;
    util->max = max;
    util->numActive = 0;
}

void UnkUtil_Run(void)
{
    u16 i;

    if (sUnkUtil->numActive)
    {
        for (i = 0; i < sUnkUtil->numActive; i++)
        {
            struct UnkUtilData *data = &sUnkUtil->data[i];
            data->func(data);
        }
        sUnkUtil->numActive = 0;
    }
}

void sub_080D2428(struct UnkUtilData *data);

bool8 sub_080D238C(u8 *dest, u16 dLeft, u16 dTop, const u8 *src, u16 sLeft, u16 sTop, u16 width, u16 height, u16 unkArg)
{
    struct UnkUtilData *data;

    if (sUnkUtil->numActive >= sUnkUtil->max)
        return FALSE;

    data = &sUnkUtil->data[sUnkUtil->numActive++];
    data->size = width * 2;
    data->dest = dest + 2 * (dTop * 32 + dLeft);
    data->src = src + 2 * (sTop * unkArg + sLeft);
    data->height = height;
    data->unk = unkArg;
    data->func = sub_080D2428;
    return TRUE;
}

void sub_080D2428(struct UnkUtilData *data)
{
    u16 i;

    for (i = 0; i < data->height; i++)
    {
        CpuSet(data->src, data->dest, data->size / 2);
        data->dest += 64;
        data->src += data->unk * 2;
    }
}

void sub_080D24BC(struct UnkUtilData *data);

bool8 sub_080D2460(void *dest, u16 dLeft, u16 dTop, u16 width, u16 height)
{
    struct UnkUtilData *data;

    if (sUnkUtil->numActive >= sUnkUtil->max)
        return FALSE;

    data = &sUnkUtil->data[sUnkUtil->numActive++];
    data->size = width * 2;
    data->dest = dest + (dTop * 32 + dLeft) * 2;
    data->height = height;
    data->func = sub_080D24BC;
    return TRUE;
}

void sub_080D24BC(struct UnkUtilData *data)
{
    u16 i;

    for (i = 0; i < data->height; i++)
    {
        Dma3FillLarge16_(0, data->dest, data->size);
        data->dest += 64;
    }
}
