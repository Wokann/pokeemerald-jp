#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "data.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/battle_string_ids.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

#define BATTLE_MESSAGE_NORMAL_WINDOW_TEXT_DATA __attribute__((section(".rodata.battle_message_normal_window_text_data")))
#define BATTLE_MESSAGE_ARENA_WINDOW_TEXT_DATA __attribute__((section(".rodata.battle_message_arena_window_text_data")))
#define BATTLE_MESSAGE_WINDOW_TEXT_POINTER_DATA __attribute__((section(".rodata.battle_message_window_text_pointer_data")))
#define BATTLE_MESSAGE_RECORDED_TEXT_SPEED_DATA __attribute__((section(".rodata.battle_message_recorded_text_speed_data")))
#define BATTLE_MESSAGE_GRAMMAR_MOVE_DATA __attribute__((section(".rodata.battle_message_grammar_move_data"), aligned(2)))
#define BATTLE_MESSAGE_STRING_ID_DATA __attribute__((section(".rodata.battle_message_string_id_data"), aligned(2)))
#define BATTLE_MESSAGE_STRING_POINTER_DATA __attribute__((section(".rodata.battle_message_string_pointer_data"), aligned(4)))
#define BATTLE_MESSAGE_REGION_TEXT_DATA __attribute__((section(".rodata.battle_message_region_text_data"), aligned(1)))
#define BATTLE_MESSAGE_STAT_TEXT_DATA __attribute__((section(".rodata.battle_message_stat_text_data"), aligned(1)))
#define BATTLE_MESSAGE_STAT_POINTER_DATA __attribute__((section(".rodata.battle_message_stat_pointer_data"), aligned(4)))
#define BATTLE_MESSAGE_FLAVOR_TEXT_DATA __attribute__((section(".rodata.battle_message_flavor_text_data"), aligned(1)))
#define BATTLE_MESSAGE_FLAVOR_POINTER_DATA __attribute__((section(".rodata.battle_message_flavor_pointer_data"), aligned(4)))
#define BATTLE_MESSAGE_TAIL_TEXT_DATA __attribute__((section(".rodata.battle_message_tail_text_data"), aligned(1)))

// Battle message ID lookup tables have the same order and values as US.
const u16 gMissStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
};

const u16 gSandStormHailContinuesStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES
};

const u16 gSandStormHailDmgStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailEndStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED
};

const u16 gRainContinuesStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
};

const u16 gReflectLightScreenSafeguardStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
    [B_MSG_STAYED_AWAKE_USING] = STRINGID_PKMNSTAYEDAWAKEUSING,
};

const u16 gStatUpStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_TURN1_RAZOR_WIND] = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM] = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH] = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK] = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]        = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]        = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]       = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]     = STRINGID_PKMNSPRANGUP,
};

// Index copied from move's index in gTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] BATTLE_MESSAGE_STRING_ID_DATA =
{
    STRINGID_PKMNSQUEEZEDBYBIND,   // MOVE_BIND
    STRINGID_PKMNWRAPPEDBY,        // MOVE_WRAP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_FIRE_SPIN
    STRINGID_PKMNCLAMPED,          // MOVE_CLAMP
    STRINGID_PKMNTRAPPEDINVORTEX,  // MOVE_WHIRLPOOL
    STRINGID_PKMNTRAPPEDBYSANDTOMB // MOVE_SAND_TOMB
};

const u16 gMistUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrozenStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_ITISRAINING,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gInobedientStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gTrainerItemCuredStatusStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [AI_HEAL_CONFUSION] = STRINGID_PKMNSITEMSNAPPEDOUT,
    [AI_HEAL_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [AI_HEAL_FREEZE]    = STRINGID_PKMNSITEMDEFROSTEDIT,
    [AI_HEAL_BURN]      = STRINGID_PKMNSITEMHEALEDBURN,
    [AI_HEAL_POISON]    = STRINGID_PKMNSITEMCUREDPOISON,
    [AI_HEAL_SLEEP]     = STRINGID_PKMNSITEMWOKEIT
};

const u16 gBerryEffectStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] BATTLE_MESSAGE_STRING_ID_DATA =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

// Japanese battle strings at 0x085A9628-0x085A9D15, in ROM order.
#define BATTLE_MESSAGE_TEXT_DATA __attribute__((section(".rodata.battle_message_text_data"), aligned(1)))
// 0x085A9628
const u8 sText_Trainer1LoseText[] BATTLE_MESSAGE_TEXT_DATA = _("{B_TRAINER1_LOSE_TEXT}");
// 0x085A962B
const u8 sText_PkmnGainedEXP[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}{B_BUFF2}　けいけんちを　もらった！\p");
// 0x085A963E
const u8 sText_ExpGainedNoBonus[] BATTLE_MESSAGE_TEXT_DATA = _("は\n");
// 0x085A9641
const u8 sText_ABoosted[] BATTLE_MESSAGE_TEXT_DATA = _("は　おおめに\n");
// 0x085A9649
const u8 sText_PkmnGrewToLv[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}は\nレベル{B_BUFF2}　に　あがった！{WAIT_SE}\p");
// 0x085A965E
const u8 sText_PkmnLearnedMove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}は\n{B_BUFF2}を　おぼえた！{WAIT_SE}\p");
// 0x085A966F
const u8 sText_TryToLearnMove1[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}は　あたらしく\n{B_BUFF2}を　おぼえたい⋯⋯⋯！\p");
// 0x085A9688
const u8 sText_TryToLearnMove2[] BATTLE_MESSAGE_TEXT_DATA = _("しかし　{B_BUFF1}は　わざを　4つ\nおぼえるので　せいいっぱいだ！\p");
// 0x085A96A8
const u8 sText_TryToLearnMove3[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF2}の　かわりに\nほかの　わざを　わすれさせますか？");
// 0x085A96C3
const u8 sText_PkmnForgotMove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}は　{B_BUFF2}の\nつかいかたを　きれいに　わすれた！\p");
// 0x085A96DE
const u8 sText_StopLearningMove[] BATTLE_MESSAGE_TEXT_DATA = _("{PAUSE 0x20}それでは⋯⋯　{B_BUFF2}を\nおぼえるのを　あきらめますか？");
// 0x085A96FC
const u8 sText_DidNotLearnMove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}は　{B_BUFF2}を\nおぼえずに　おわった！\p");
// 0x085A9711
const u8 sText_UseNextPkmn[] BATTLE_MESSAGE_TEXT_DATA = _("つぎの　ポケモンを　つかいますか？");
// 0x085A9723
const u8 sText_AttackMissed[] BATTLE_MESSAGE_TEXT_DATA = _("しかし　{B_ATK_NAME_WITH_PREFIX}の\nこうげきは　はずれた！");
// 0x085A9737
const u8 sText_PkmnProtectedItself[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　こうげきから\nみを　まもった！");
// 0x085A974B
const u8 sText_AvoidedDamage[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\nダメージを　うけない！");
// 0x085A975F
const u8 sText_PkmnMakesGroundMiss[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\nじめんタイプの　わざが　あたらない！");
// 0x085A977A
const u8 sText_PkmnAvoidedAttack[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}には\nあたらなかった！");
// 0x085A9788
const u8 sText_ItDoesntAffect[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}には\nこうかが　ない　みたいだ⋯⋯");
// 0x085A979C
const u8 sText_AttackerFainted[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　たおれた！\p");
// 0x085A97A7
const u8 sText_TargetFainted[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　たおれた！\p");
// 0x085A97B2
const u8 sText_PlayerGotMoney[] BATTLE_MESSAGE_TEXT_DATA = _("{B_PLAYER_NAME}は　しょうきんとして\n{B_BUFF1}¥　てにいれた！\p");
// 0x085A97CB
const u8 sText_PlayerWhiteout[] BATTLE_MESSAGE_TEXT_DATA = _("{B_PLAYER_NAME}の　てもとには\nたたかえる　ポケモンが　いない！\p");
// 0x085A97E7
const u8 sText_PlayerWhiteout2[] BATTLE_MESSAGE_TEXT_DATA = _("{B_PLAYER_NAME}は\nめのまえが　まっくらに　なった！{PAUSE_UNTIL_PRESS}");
// 0x085A97FE
const u8 sText_PreventsEscape[] BATTLE_MESSAGE_TEXT_DATA = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\nにげられない！\p");
// 0x085A980F
const u8 sText_CantEscape2[] BATTLE_MESSAGE_TEXT_DATA = _("にげられない！\p");
// 0x085A9818
const u8 sText_AttackerCantEscape[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　にげられない！");
// 0x085A9824
const u8 sText_HitXTimes[] BATTLE_MESSAGE_TEXT_DATA = _("{B_BUFF1}かい　あたった！");
// 0x085A982F
const u8 sText_PkmnFellAsleep[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\nねむってしまった！");
// 0x085A983D
const u8 sText_PkmnMadeSleep[] BATTLE_MESSAGE_TEXT_DATA = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　ねむってしまった！");
// 0x085A9853
const u8 sText_PkmnAlreadyAsleep[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　すでに\nねむっている");
// 0x085A9862
const u8 sText_PkmnAlreadyAsleep2[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　すでに\nねむっている");
// 0x085A9871
const u8 sText_PkmnWasntAffected[] BATTLE_MESSAGE_TEXT_DATA = _("しかし　{B_DEF_NAME_WITH_PREFIX}には\nきかなかった！");
// 0x085A9882
const u8 sText_PkmnWasPoisoned[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は　どくをあびた！");
// 0x085A988E
const u8 sText_PkmnPoisonedBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　どくをあびた！");
// 0x085A98A2
const u8 sText_PkmnHurtByPoison[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nどくの　ダメージを　うけている！");
// 0x085A98B7
const u8 sText_PkmnAlreadyPoisoned[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　すでに\nどくを　あびている");
// 0x085A98C9
const u8 sText_PkmnBadlyPoisoned[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\nもうどくをあびた！");
// 0x085A98D7
const u8 sText_PkmnEnergyDrained[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}から\nたいりょくを　すいとった！");
// 0x085A98EA
const u8 sText_PkmnWasBurned[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\nやけどをおった！");
// 0x085A98F7
const u8 sText_PkmnBurnedBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　やけどをおった！");
// 0x085A990C
const u8 sText_PkmnHurtByBurn[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nやけどの　ダメージを　うけている！");
// 0x085A9922
const u8 sText_PkmnAlreadyHasBurn[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　すでに\nやけどを　おっている");
// 0x085A9935
const u8 sText_PkmnWasFrozen[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\nこおりづけになった！");
// 0x085A9944
const u8 sText_PkmnFrozenBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　こおりづけになった！");
// 0x085A995B
const u8 sText_PkmnIsFrozen[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nこおって　しまって　うごかない！");
// 0x085A9970
const u8 sText_PkmnWasDefrosted[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}の\nこおりが　とけた！");
// 0x085A997E
const u8 sText_PkmnWasDefrosted2[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}の\nこおりが　とけた！");
// 0x085A998C
const u8 sText_PkmnWasDefrostedBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}の　こおりが\n{B_CURRENT_MOVE}で　とけた！");
// 0x085A999E
const u8 sText_PkmnWasParalyzed[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は　まひして\nわざが　でにくくなった！");
// 0x085A99B4
const u8 sText_PkmnWasParalyzedBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\lまひして　わざが　でにくくなった！");
// 0x085A99D2
const u8 sText_PkmnIsParalyzed[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nからだが　しびれて　うごけない");
// 0x085A99E6
const u8 sText_PkmnIsAlreadyParalyzed[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　すでに\nまひしている");
// 0x085A99F5
const u8 sText_PkmnHealedParalysis[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}の\nまひが　なおった！");
// 0x085A9A03
const u8 sText_PkmnDreamEaten[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}の\nゆめを　くった！");
// 0x085A9A10
const u8 sText_StatsWontIncrease[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}の\n{B_BUFF1}は　もうあがらない！");
// 0x085A9A21
const u8 sText_StatsWontDecrease[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}は　もうさがらない！");
// 0x085A9A32
const u8 sText_TeamStoppedWorking[] BATTLE_MESSAGE_TEXT_DATA = _("みかたの　{B_BUFF1}の\nこうかが　きれた！");
// 0x085A9A45
const u8 sText_FoeStoppedWorking[] BATTLE_MESSAGE_TEXT_DATA = _("あいての　{B_BUFF1}の\nこうかが　きれた！");
// 0x085A9A58
const u8 sText_PkmnIsConfused[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nこんらんしている！");
// 0x085A9A66
const u8 sText_PkmnHealedConfusion[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}の\nこんらんが　とけた！");
// 0x085A9A75
const u8 sText_PkmnWasConfused[] BATTLE_MESSAGE_TEXT_DATA = _("{B_EFF_NAME_WITH_PREFIX}は\nこんらんした！");
// 0x085A9A81
const u8 sText_PkmnAlreadyConfused[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は\nすでに　こんらん　している");
// 0x085A9A93
const u8 sText_PkmnFellInLove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は\nメロメロに　なった！");
// 0x085A9AA2
const u8 sText_PkmnInLove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}に　メロメロだ！");
// 0x085A9AB1
const u8 sText_PkmnImmobilizedByLove[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　メロメロで\nわざが　だせなかった！");
// 0x085A9AC7
const u8 sText_PkmnBlownAway[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は\nふきとばされた！");
// 0x085A9AD4
const u8 sText_PkmnChangedType[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}タイプに　なった！");
// 0x085A9AE4
const u8 sText_PkmnFlinched[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　ひるんで\nうごけなかった！");
// 0x085A9AF6
const u8 sText_PkmnRegainedHealth[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　たいりょくを\nかいふくした！");
// 0x085A9B09
const u8 sText_PkmnHPFull[] BATTLE_MESSAGE_TEXT_DATA = _("しかし　{B_DEF_NAME_WITH_PREFIX}の\nたいりょくは　まんたんだ！");
// 0x085A9B1F
const u8 sText_PkmnRaisedSpDef[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nとくこうに　つよくなった！");
// 0x085A9B34
const u8 sText_PkmnRaisedSpDefALittle[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nとくこうに　すこし　つよくなった！");
// 0x085A9B4D
const u8 sText_PkmnRaisedDef[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nだげきこうげきに　つよくなった！");
// 0x085A9B65
const u8 sText_PkmnRaisedDefALittle[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nだげきこうげきに　すこし　つよくなった！");
// 0x085A9B81
const u8 sText_PkmnCoveredByVeil[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX2}\nしんぴのベールに　つつまれた！");
// 0x085A9B94
const u8 sText_PkmnUsedSafeguard[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は\nしんぴのベールに　まもられている！");
// 0x085A9BAA
const u8 sText_PkmnSafeguardExpired[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_PREFIX3}　つつんでいた\nしんぴの　ベールが　なくなった！");
// 0x085A9BC5
const u8 sText_PkmnWentToSleep[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nねむりはじめた！");
// 0x085A9BD2
const u8 sText_PkmnSleptHealthy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nけんこうになって　ねむりはじめた！");
// 0x085A9BE8
const u8 sText_PkmnWhippedWhirlwind[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}の　まわりで\nくうきが　うずを　まく！");
// 0x085A9BFE
const u8 sText_PkmnTookSunlight[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nひかりを　きゅうしゅうした！");
// 0x085A9C11
const u8 sText_PkmnLoweredHead[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nくびを　ひっこめた！");
// 0x085A9C20
const u8 sText_PkmnIsGlowing[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}を\nはげしい　ひかりが　つつむ！");
// 0x085A9C33
const u8 sText_PkmnFlewHigh[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nそらたかく　とびあがった！");
// 0x085A9C45
const u8 sText_PkmnDugHole[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nあなをほって　ちちゅうに　もぐった！");
// 0x085A9C5C
const u8 sText_PkmnHidUnderwater[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nすいちゅうに　みをひそめた！");
// 0x085A9C6F
const u8 sText_PkmnSprangUp[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\nとびはねた！");
// 0x085A9C7A
const u8 sText_PkmnSqueezedByBind[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}に\nしめつけられた！");
// 0x085A9C8B
const u8 sText_PkmnTrappedInVortex[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　うずの　なかに\nとじこめられた！");
// 0x085A9CA0
const u8 sText_PkmnTrappedBySandTomb[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　すなじごくに\nとらわれた！");
// 0x085A9CB2
const u8 sText_PkmnWrappedBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}に\nまきつかれた！");
// 0x085A9CC2
const u8 sText_PkmnClamped[] BATTLE_MESSAGE_TEXT_DATA = _("{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}の\nからに　はさまれた！");
// 0x085A9CD5
const u8 sText_PkmnHurtBy[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　{B_BUFF1}の\nダメージを　うけている");
// 0x085A9CE9
const u8 sText_PkmnFreedFrom[] BATTLE_MESSAGE_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}から　かいほうされた！");
// 0x085A9CFB
const u8 sText_PkmnCrashed[] BATTLE_MESSAGE_TEXT_DATA = _("いきおい　あまって\n{B_ATK_NAME_WITH_PREFIX}は　じめんに　ぶつかった！");

// Japanese battle strings at 0x085A9D15-0x085AB057, in ROM order.
const u8 gText_PkmnShroudedInMist[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_PREFIX2}\n"
    "しろいきりに　つつまれた！");

const u8 sText_PkmnProtectedByMist[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　しろいきりに\n"
    "まもられている");

const u8 gText_PkmnGettingPumped[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "はりきっている！");

const u8 sText_PkmnHitWithRecoil[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　こうげきの\n"
    "はんどうを　うけた！");

const u8 sText_PkmnProtectedItself2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "まもりの　たいせいに　はいった！");

const u8 sText_PkmnBuffetedBySandstorm[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "すなあらしが　{B_ATK_NAME_WITH_PREFIX}を\n"
    "おそう！");

const u8 sText_PkmnPeltedByHail[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あられが　{B_ATK_NAME_WITH_PREFIX}を\n"
    "おそう！");

const u8 sText_PkmnsXWoreOff[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_PREFIX1}　{B_BUFF1}の\n"
    "こうかが　きれた！");

const u8 sText_PkmnSeeded[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}に\n"
    "たねを　うえつけた！");

const u8 sText_PkmnEvadedAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "こうげきを　かわした！");

const u8 sText_PkmnSappedByLeechSeed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "やどりぎが　{B_ATK_NAME_WITH_PREFIX}の\n"
    "たいりょくを　うばう！");

const u8 sText_PkmnFastAsleep[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "ぐうぐう　ねむっている");

const u8 sText_PkmnWokeUp[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　めを　さました！");

const u8 sText_PkmnUproarKeptAwake[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　{B_SCR_ACTIVE_NAME_WITH_PREFIX}が\n"
    "さわいでいて　ねむれなかった！");

const u8 sText_PkmnWokeUpInUproar[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　さわがしくて\n"
    "めが　さめた！");

const u8 sText_PkmnCausedUproar[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　さわぎだした！");

const u8 sText_PkmnMakingUproar[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　さわいでいる！");

const u8 sText_PkmnCalmedDown[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "おとなしくなった");

const u8 sText_PkmnCantSleepInUproar[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし{B_DEF_NAME_WITH_PREFIX}は\n"
    "さわいでいて　ねむらない！");

const u8 sText_PkmnStockpiled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　{B_BUFF1}つたくわえた！");

const u8 sText_PkmnCantStockpile[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　もう　これいじょう\n"
    "たくわえられない！");

const u8 sText_PkmnCantSleepInUproar2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　{B_DEF_NAME_WITH_PREFIX}は\n"
    "さわいでいて　ねむらない！");

const u8 sText_UproarKeptPkmnAwake[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　{B_DEF_NAME_WITH_PREFIX}は\n"
    "さわがしくて　ねむれない！");

const u8 sText_PkmnStayedAwakeUsing[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "{B_DEF_ABILITY}で　ねむらない！");

const u8 sText_PkmnStoringEnergy[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　がまんしている");

const u8 sText_PkmnUnleashedEnergy[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "がまんが　とかれた！");

const u8 sText_PkmnFatigueConfusion[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "つかれはてて　こんらんした！");

const u8 sText_PlayerPickedUpMoney[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_PLAYER_NAME}は　{B_BUFF1}¥\n"
    "ひろった！\p");

const u8 sText_PkmnUnaffected[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}には\n"
    "ぜんぜんきいてない！");

const u8 sText_PkmnTransformedInto[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "{B_BUFF1}に　へんしんした！");

const u8 sText_PkmnMadeSubstitute[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "ぶんしんが　あらわれた");

const u8 sText_PkmnHasSubstitute[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　{B_ATK_NAME_WITH_PREFIX}の\n"
    "みがわりは　すでに　でていた！");

const u8 sText_SubstituteDamaged[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}に　かわって\n"
    "ぶんしんが　こうげきを　うけた！\p");

const u8 sText_PkmnSubstituteFaded[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　ぶんしんは\n"
    "きえてしまった⋯⋯\p");

const u8 sText_PkmnMustRecharge[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "こうげきの　はんどうで\n"
    "{B_ATK_NAME_WITH_PREFIX}は　うごけない！");

const u8 sText_PkmnRageBuilding[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　いかりの\n"
    "ボルテージが　あがっていく！");

const u8 sText_PkmnMoveWasDisabled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}を　ふうじこめた！");

const u8 sText_PkmnMoveDisabledNoMore[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "かなしばりが　とけた！");

const u8 sText_PkmnGotEncore[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "アンコールを　うけた！");

const u8 sText_PkmnEncoreEnded[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "アンコールじょうたいが　とけた！");

const u8 sText_PkmnTookAim[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}に\n"
    "ねらいを　さだめた！");

const u8 sText_PkmnSketchedMove[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "{B_BUFF1}を　スケッチした！");

const u8 sText_PkmnTryingToTakeFoe[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　あいてを\n"
    "みちづれに　しようとしている");

const u8 sText_PkmnTookFoe[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}を\n"
    "みちづれに　した！");

const u8 sText_PkmnReducedPP[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}を　{B_BUFF2}けずった！");

const u8 sText_PkmnStoleItem[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}から\n"
    "{B_LAST_ITEM}を　うばいとった！");

const u8 sText_TargetCantEscapeNow[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "もう　にげられない！");

const u8 sText_PkmnFellIntoNightmare[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "あくむを　みはじめた！");

const u8 sText_PkmnLockedInNightmare[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "あくむに　うなされている！");

const u8 sText_PkmnLaidCurse[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　じぶんの　たいりょくを\n"
    "けずって　{B_DEF_NAME_WITH_PREFIX}に　のろいを　かけた！");

const u8 sText_PkmnAfflictedByCurse[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "のろわれている！");

const u8 sText_SpikesScattered[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_PREFIX1}　あしもとに\n"
    "まきびしが　ちらばった！");

const u8 sText_PkmnHurtBySpikes[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　まきびしの\n"
    "ダメージを　うけた！");

const u8 sText_PkmnIdentified[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "しょうたいを　みやぶった！");

const u8 sText_PkmnPerishCountFell[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　ほろびの\n"
    "カウントが　{B_BUFF1}になった！");

const u8 sText_PkmnBracedItself[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　こらえる\n"
    "たいせいに　はいった！");

const u8 sText_PkmnEnduredHit[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　こうげきを\n"
    "こらえた！");

const u8 sText_MagnitudeStrength[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("マグニチュード{B_BUFF1}！！");

const u8 sText_PkmnCutHPMaxedAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　たいりょくを　けずって\n"
    "パワーぜんかいに　なった！");

const u8 sText_PkmnCopiedStatChanges[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "ほじょこうかを　コピーした！");

const u8 sText_PkmnGotFree[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}から　かいほうされた！");

const u8 sText_PkmnShedLeechSeed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "やどりぎのタネを　ふきとばした！");

const u8 sText_PkmnBlewAwaySpikes[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　まきびしを\n"
    "ふきとばした！");

const u8 sText_PkmnFledFromBattle[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　せんとうから\n"
    "りだつした！");

const u8 sText_PkmnForesawAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　みらいに\n"
    "こうげきを　よちした！");

const u8 sText_PkmnTookAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_BUFF1}の\n"
    "こうげきを　うけた！");

const u8 sText_PkmnChoseXAsDestiny[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_CURRENT_MOVE}を\n"
    "みらいに　たくした！");

const u8 sText_PkmnAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_BUFF1}の　こうげき！");

const u8 sText_PkmnCenterAttention[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "ちゅうもくの　まとに　なった！");

const u8 sText_PkmnChargingPower[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "じゅうでんを　はじめた！");

const u8 sText_NaturePowerTurnedInto[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しぜんのちからは\n"
    "{B_CURRENT_MOVE}に　なった！");

const u8 sText_PkmnStatusNormal[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　じょうたいいじょうが\n"
    "なおった！");

const u8 sText_PkmnSubjectedToTorment[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は\n"
    "いちゃもんを　つけられた！");

const u8 sText_PkmnTighteningFocus[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "しゅうちゅうりょくを　たかめている！");

const u8 sText_PkmnFellForTaunt[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　\n"
    "ちょうはつに　のってしまった！");

const u8 sText_PkmnReadyToHelp[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}を\n"
    "てだすけ　する　たいせいに　はいった！");

const u8 sText_PkmnSwitchedItems[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　おたがいの\n"
    "どうぐを　いれかえた！");

const u8 sText_PkmnObtainedX[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_BUFF1}を\n"
    "てに　いれた！");

const u8 sText_PkmnObtainedX2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_BUFF2}を\n"
    "てに　いれた！");

const u8 sText_PkmnObtainedXYObtainedZ[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_BUFF1}を\n"
    "てに　いれた！\p"
    "{B_DEF_NAME_WITH_PREFIX}は　{B_BUFF2}を\n"
    "てに　いれた！");

const u8 sText_PkmnCopiedFoe[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_DEF_ABILITY}を　コピーした！");

const u8 sText_PkmnMadeWish[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "ねがいごとを　した！");

const u8 sText_PkmnWishCameTrue[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}の\n"
    "ねがいごとが　かなった！");

const u8 sText_PkmnPlantedRoots[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　ねを　はった！");

const u8 sText_PkmnAbsorbedNutrients[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　ねから\n"
    "ようぶんを　すいとった！");

const u8 sText_PkmnAnchoredItself[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　ねを　はって\n"
    "うごかない！");

const u8 sText_PkmnWasMadeDrowsy[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "ねむけを　さそった！");

const u8 sText_PkmnKnockedOff[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_LAST_ITEM}を　はたきおとした！");

const u8 sText_PkmnSwappedAbilities[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　おたがいの\n"
    "とくせいを　いれかえた！");

const u8 sText_PkmnSealedOpponentMove[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　あいての\n"
    "わざを　ふういんした！");

const u8 sText_PkmnWantsGrudge[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　あいてに\n"
    "おんねんを　かけようと　している！");

const u8 sText_PkmnLostPPGrudge[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　{B_BUFF1}は\n"
    "おんねんで　わざポイントが　0に　なった！");

const u8 sText_PkmnShroudedItself[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "{B_CURRENT_MOVE}に　つつまれた！");

const u8 sText_PkmnMoveBounced[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　{B_CURRENT_MOVE}は\n"
    "マジックコートに　はねかえされた！");

const u8 sText_PkmnWaitsForTarget[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "あいての　でかたを　うかがっている！");

const u8 sText_PkmnSnatchedMove[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_NAME_WITH_PREFIX}の\n"
    "わざを　よこどりした！");

const u8 sText_ElectricityWeakened[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("でんきの　いりょくが　よわまった！");

const u8 sText_FireWeakened[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ほのおの　いりょくが　よわまった！");

const u8 sText_XFoundOneY[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_LAST_ITEM}を\n"
    "ひろってきた！");

const u8 sText_SoothingAroma[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ここちよい　かおりが　ひろがった！");

const u8 sText_ItemsCantBeUsedNow[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "ここでは　どうぐを　つかうことは\n"
    "できません！{PAUSE 64}");

const u8 sText_ForXCommaYZ[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LAST_ITEM}は　{B_SCR_ACTIVE_NAME_WITH_PREFIX}には\n"
    "{B_BUFF1}");

const u8 sText_PkmnUsedXToGetPumped[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}を　つかって\n"
    "はりきり　だした！");

const u8 sText_PkmnLostFocus[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　しゅうちゅうりょくが\n"
    "とぎれて　わざが　だせなかった！");

const u8 sText_PkmnWasDraggedOut[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　せんとうに\n"
    "ひきずりだされた！\p");

const u8 sText_TheWallShattered[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("かべが　こわれた！");

const u8 sText_ButNoEffect[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("しかし　こうかが　なかった！");

const u8 sText_PkmnHasNoMovesLeft[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ACTIVE_NAME_WITH_PREFIX}は　だすことの　できる\n"
    "わざが　ない！\p");

const u8 sText_PkmnMoveIsDisabled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ACTIVE_NAME_WITH_PREFIX}は　かなしばりで\n"
    "{B_CURRENT_MOVE}が　だせない！\p");

const u8 sText_PkmnCantUseMoveTorment[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ACTIVE_NAME_WITH_PREFIX}は　いちゃもんを　つけられたので\n"
    "つづけて　おなじ　わざが　だせない！\p");

const u8 sText_PkmnCantUseMoveTaunt[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ACTIVE_NAME_WITH_PREFIX}は　ちょうはつ　されて\n"
    "{B_CURRENT_MOVE}が　だせない！\p");

const u8 sText_PkmnCantUseMoveSealed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ACTIVE_NAME_WITH_PREFIX}は　ふういんで\n"
    "{B_CURRENT_MOVE}が　だせない！\p");

const u8 sText_PkmnMadeItRain[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n"
    "あめが　ふりはじめた！");

const u8 sText_PkmnRaisedSpeed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "すばやさが　あがった！");

const u8 sText_PkmnProtectedBy[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "きかなかった！");

const u8 sText_PkmnPreventsUsage[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}で\n"
    "{B_ATK_NAME_WITH_PREFIX}は　{B_CURRENT_MOVE}が　できない！");

const u8 sText_PkmnRestoredHPUsing[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "かいふくした！");

const u8 sText_PkmnsXMadeYUseless[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}で\n"
    "{B_CURRENT_MOVE}は　こうかが　なかった！");

const u8 sText_PkmnChangedTypeWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "{B_BUFF1}タイプに　なった！");

const u8 sText_PkmnPreventsParalysisWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_EFF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "まひしない！");

const u8 sText_PkmnPreventsRomanceWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "メロメロに　ならない！");

const u8 sText_PkmnPreventsPoisoningWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_EFF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "どくを　うけない！");

const u8 sText_PkmnPreventsConfusionWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "こんらんしない！");

const u8 sText_PkmnRaisedFirePowerWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "ほのおの　いりょくが　あがった！");

const u8 sText_PkmnAnchorsItselfWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "はりついている！");

const u8 sText_PkmnCutsAttackWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n"
    "{B_DEF_NAME_WITH_PREFIX}の　こうげきりょくが　さがった！");

const u8 sText_PkmnPreventsStatLossWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "のうりょくが　さがらない！");

const u8 sText_PkmnHurtsWith[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}で\n"
    "{B_ATK_NAME_WITH_PREFIX}は　きずついた！");

const u8 sText_PkmnTraced[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_BUFF1}の\n"
    "{B_BUFF2}を　トレースした！");

const u8 sText_PkmnsXPreventsBurns[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_EFF_NAME_WITH_PREFIX}は　{B_EFF_ABILITY}で\n"
    "やけどしない！");

const u8 sText_PkmnsXBlocksY[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "{B_CURRENT_MOVE}を　うけない！");

const u8 sText_PkmnsXBlocksY2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "{B_CURRENT_MOVE}を　うけない！");

const u8 sText_PkmnsXRestoredHPALittle2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　{B_ATK_ABILITY}で\n"
    "すこし　かいふく");

const u8 sText_PkmnsXWhippedUpSandstorm[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n"
    "すなあらしに　なった！");

const u8 sText_PkmnsXIntensifiedSun[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n"
    "ひざしが　つよくなった！");

const u8 sText_PkmnsXPreventsYLoss[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "{B_BUFF1}が　さがらない！");

const u8 sText_PkmnsXInfatuatedY[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}で\n"
    "{B_ATK_NAME_WITH_PREFIX}は　メロメロに　なった！");

const u8 sText_PkmnsXMadeYIneffective[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "{B_CURRENT_MOVE}が　きかない！");

const u8 sText_PkmnsXCuredYProblem[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "{B_BUFF1}じょうたいが　なおった！");

const u8 sText_ItSuckedLiquidOoze[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ヘドロえきを　すいとった！");

const u8 sText_PkmnTransformed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　すがたが\n"
    "へんかした！");

const u8 sText_PkmnsXTookAttack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\n"
    "こうげきを　うけた！");

const u8 gText_PkmnsXPreventsSwitching[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}の　{B_LAST_ABILITY}で\n"
    "{B_BUFF2}を　もどすことが　できない！\p");

const u8 sText_PreventedFromWorking[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}で\n"
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_BUFF1}は　きかなかった！");

const u8 sText_PkmnsXMadeItIneffective[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n"
    "うまく　きまらなかった！");

const u8 sText_PkmnsXPreventsFlinching[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_EFF_NAME_WITH_PREFIX}は　{B_EFF_ABILITY}で\n"
    "ひるまない！");

const u8 sText_PkmnsXPreventsYsZ[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　{B_ATK_ABILITY}で\n"
    "{B_DEF_NAME_WITH_PREFIX}の　{B_DEF_ABILITY}は　きかない！");

const u8 sText_PkmnsXCuredItsYProblem[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_SCR_ACTIVE_ABILITY}で\n"
    "{B_BUFF1}が　なおった！");

const u8 sText_PkmnsXHadNoEffectOnY[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}は\n"
    "{B_EFF_NAME_WITH_PREFIX}に　きかなかった！");

const u8 sText_StatSharply[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ぐーんと　");

const u8 gText_StatRose[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あがった！");

const u8 sText_StatHarshly[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("がくっと　");

const u8 sText_StatFell[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("さがった！");

const u8 sText_AttackersStatRose[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}が　{B_BUFF2}");

const u8 gText_DefendersStatRose[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}が　{B_BUFF2}");

const u8 sText_UsingItemTheStatOfPkmnRose[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "{B_BUFF1}が　{B_BUFF2}");

const u8 sText_AttackersStatFell[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}が　{B_BUFF2}");

const u8 sText_DefendersStatFell[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の\n"
    "{B_BUFF1}が　{B_BUFF2}");

const u8 sText_StatsWontIncrease2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}の　のうりょくは\n"
    "もう　あがらない！");

const u8 sText_StatsWontDecrease2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}の　のうりょくは\n"
    "もう　さがらない！");

const u8 sText_CriticalHit[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("きゅうしょに　あたった！");

const u8 sText_OneHitKO[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("いちげき　ひっさつ！");

const u8 sText_123Poof[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{PAUSE 32}1　{PAUSE 15}2の　{PAUSE 15}⋯{PAUSE 15}⋯{PAUSE 15}⋯　{PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}ポカン！\p");

const u8 sText_AndEllipsis[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("そして⋯⋯！\p");

const u8 sText_HMMovesCantBeForgotten[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "それは　たいせつな　わざです\n"
    "わすれさせることは　できません！\p");

const u8 sText_NotVeryEffective[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("こうかは　いまひとつの　ようだ");

const u8 sText_SuperEffective[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("こうかは　ばつぐんだ！");

const u8 sText_GotAwaySafely[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{PLAY_SE SE_FLEE}うまく　にげきれた！\p");

const u8 sText_PkmnFledUsingIts[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は　もっていた\n"
    "{B_LAST_ITEM}を　つかって　にげた\p");

const u8 sText_PkmnFledUsing[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX}は\n"
    "{B_ATK_ABILITY}を　つかって　にげた\p");

const u8 sText_WildPkmnFled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{PLAY_SE SE_FLEE}やせいの　{B_BUFF1}は　にげだした！");

const u8 sText_PlayerDefeatedLinkTrainer[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}との\n"
    "しょうぶに　かった！");

const u8 sText_TwoLinkTrainersDefeated[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}と　{B_LINK_OPPONENT2_NAME}との\n"
    "しょうぶに　かった！");

const u8 sText_PlayerLostAgainstLinkTrainer[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}との\n"
    "しょうぶに　まけた！");

const u8 sText_PlayerLostToTwo[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}と　{B_LINK_OPPONENT2_NAME}との\n"
    "しょうぶに　まけた！");

const u8 sText_PlayerBattledToDrawLinkTrainer[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}との\n"
    "しょうぶに　ひきわけた！");

const u8 sText_PlayerBattledToDrawVsTwo[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}と　{B_LINK_OPPONENT2_NAME}との\n"
    "しょうぶに　ひきわけた！");

const u8 sText_WildFled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}は　にげだした！");

const u8 sText_TwoWildFled[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME}と　{B_LINK_OPPONENT2_NAME}は\n"
    "にげだした！");

const u8 sText_NoRunningFromTrainers[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "ダメだ！　しょうぶの　さいちゅうに\n"
    "あいてに　せなかは　みせられない！\p");

const u8 sText_CantEscape[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("にげることが　できない！\p");

const u8 sText_DontLeaveBirch[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("オダマキ“み　みすてないでくれー！”\p");

const u8 sText_ButNothingHappened[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("しかし　なにもおこらない");

const u8 sText_ButItFailed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("しかし　うまく　きまらなかった！");

const u8 sText_ItHurtConfusion[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "わけも　わからず\n"
    "じぶんを　こうげきした！");

const u8 sText_MirrorMoveFailed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　オウムがえしは\n"
    "しっぱいにおわった！");

const u8 sText_StartedToRain[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あめが　ふりはじめた！");

const u8 sText_DownpourStarted[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("おおあめに　なった！");

const u8 sText_RainContinues[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あめが　ふりつづいている");

const u8 sText_DownpourContinues[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("おおあめが　ふりつづいている");

const u8 sText_RainStopped[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あめが　ふりやんだ！");

const u8 sText_SandstormBrewed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("すなあらしが　ふきはじめた！");

const u8 sText_SandstormRages[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("すなあらしが　ふきあれる");

const u8 sText_SandstormSubsided[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("すなあらしが　おさまった！");

const u8 sText_SunlightGotBright[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ひざしが　つよくなった！");

const u8 sText_SunlightStrong[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ひざしが　つよい");

const u8 sText_SunlightFaded[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ひざしが　よわくなった！");

const u8 sText_StartedHail[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あられが　ふりはじめた！");

const u8 sText_HailContinues[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あられが　ふりつづいている");

const u8 sText_HailStopped[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あられが　ふりやんだ！");

const u8 sText_FailedToSpitUp[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("しかし　なにも　はきだせなかった！");

const u8 sText_FailedToSwallow[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("しかし　なにも　のみこめなかった！");

const u8 sText_WindBecameHeatWave[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("かぜは　ねっぷうに　なった！");

const u8 sText_StatChangesGone[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "すべての　ステータスが\n"
    "もとに　もどった！");

const u8 sText_CoinsScattered[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("こばんが　あたりに　ちらばった！");

const u8 sText_TooWeakForSubstitute[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし　ぶんしんを　だすには\n"
    "たいりょくが　たりなかった！");

const u8 sText_SharedPain[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "おたがいの　たいりょくを\n"
    "わかちあった！");

const u8 sText_BellChimed[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("すずのねが　ひびきわたった！");

const u8 sText_FaintInThree[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "おたがいのポケモンは\n"
    "3ターンごに　ほろびてしまう！");

const u8 sText_NoPPLeft[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("わざの　のこりポイントが　ない！\p");

const u8 sText_ButNoPPLeft[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "しかし\n"
    "わざの　のこりポイントが　なかった！");

const u8 sText_PkmnIgnoresAsleep[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は　ねむったまま\n"
    "めいれいを　むしした！");

const u8 sText_PkmnIgnoredOrders[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　めいれいを　むしした！");

const u8 sText_PkmnBeganToNap[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　ひるねを　はじめた！");

const u8 sText_PkmnLoafing[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　なまけている！");

const u8 sText_PkmnWontObey[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　いうことを　きかない！");

const u8 sText_PkmnTurnedAway[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　そっぽを　むいた！");

const u8 sText_PkmnPretendNotNotice[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("{B_ATK_NAME_WITH_PREFIX}は　しらんぷりした！");

const u8 sText_EnemyAboutToSwitchPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_BUFF2}を　くりだそうと　している\p"
    "{B_PLAYER_NAME}も　ポケモンを\n"
    "いれかえますか？");

const u8 sText_PkmnLearnedMove2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}は\n"
    "{B_BUFF1}を　おぼえた！");

const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}\n"
    "との　しょうぶに　かった！\p");

const u8 sText_CreptCloser[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_PLAYER_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}に　ちかづいた！");

const u8 sText_CantGetCloser[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_PLAYER_NAME}は\n"
    "これいじょう　ちかづけない！");

const u8 sText_PkmnWatchingCarefully[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}は\n"
    "こちらの　ようすを　うかがっている！");

const u8 sText_PkmnCuriousAboutX[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}は　{B_BUFF1}に\n"
    "きょうみを　しめしている　ようだ！");

const u8 sText_PkmnEnthralledByX[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}は　{B_BUFF1}に\n"
    "むちゅうに　なっている　ようだ！");

const u8 sText_PkmnIgnoredX[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}は　{B_BUFF1}に\n"
    "みむきも　しない　ようだ！");

const u8 sText_ThrewPokeblockAtPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_PLAYER_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}に　ポロックを　なげた！");

const u8 sText_OutOfSafariBalls[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{PLAY_SE SE_DING_DONG}アナウンス“ピンポーン！　サファリボールが\n"
    "なくなったので　しゅうりょうでーす！\p");

const u8 sText_OpponentMon1Appeared[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あ！　{B_OPPONENT_MON1_NAME}が　とびだしてきた！\p");

const u8 sText_WildPkmnAppeared[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あ！　やせいの\n"
    "{B_OPPONENT_MON1_NAME}が　とびだしてきた！\p");

const u8 sText_LegendaryPkmnAppeared[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あ！　やせいの\n"
    "{B_OPPONENT_MON1_NAME}が　あらわれた！\p");

const u8 sText_WildPkmnAppearedPause[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あ！　やせいの\n"
    "{B_OPPONENT_MON1_NAME}が　とびだしてきた！{PAUSE 127}");

const u8 sText_TwoWildPkmnAppeared[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あ！　やせいの\n"
    "{B_OPPONENT_MON1_NAME}と　{B_OPPONENT_MON2_NAME}が　とびだしてきた！\p");

const u8 sText_Trainer1WantsToBattle[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}が\n"
    "しょうぶを　しかけてきた！\p");

const u8 sText_LinkTrainerWantsToBattle[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}が\n"
    "しょうぶを　しかけてきた！");

const u8 sText_TwoLinkTrainersWantToBattle[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}と　{B_LINK_OPPONENT2_NAME}が\n"
    "しょうぶを　しかけてきた！");

const u8 sText_Trainer1SentOutPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}を　くりだした！");

const u8 sText_Trainer1SentOutTwoPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}と　{B_OPPONENT_MON2_NAME}を　くりだした！");

const u8 sText_Trainer1SentOutPkmn2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_BUFF1}を　くりだした！");

const u8 sText_LinkTrainerSentOutPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}を　くりだした！");

const u8 sText_LinkTrainerSentOutTwoPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}は\n"
    "{B_OPPONENT_MON1_NAME}と　{B_OPPONENT_MON2_NAME}を　くりだした！");

const u8 sText_TwoLinkTrainersSentOutPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}は　{B_LINK_OPPONENT_MON1_NAME}を　くりだした！\n"
    "{B_LINK_OPPONENT2_NAME}は　{B_LINK_OPPONENT_MON2_NAME}を　くりだした！");

const u8 sText_LinkTrainerSentOutPkmn2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}は\n"
    "{B_BUFF1}を　くりだした！");

const u8 sText_LinkTrainerMultiSentOutPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_SCR_TRAINER_NAME}は\n"
    "{B_BUFF1}を　くりだした！");

const u8 sText_GoPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ゆけっ！　{B_PLAYER_MON1_NAME}！");

const u8 sText_GoTwoPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ゆけっ！　{B_PLAYER_MON1_NAME}と　{B_PLAYER_MON2_NAME}！");

const u8 sText_GoPkmn2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("ゆけっ！　{B_BUFF1}！");

const u8 sText_DoItPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("いってこい！　{B_BUFF1}！");

const u8 sText_GoForItPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("がんばれ！　{B_BUFF1}！");

const u8 sText_YourFoesWeakGetEmPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "あいてが　よわっている！\n"
    "チャンスだ！　{B_BUFF1}！");

const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_PARTNER_NAME}は　{B_LINK_PLAYER_MON2_NAME}を　くりだした！\n"
    "ゆけっ！　{B_LINK_PLAYER_MON1_NAME}！");

const u8 sText_PkmnThatsEnough[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}　もういい！\n"
    "もどれ！");

const u8 sText_PkmnComeBack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}\n"
    "もどれ！");

const u8 sText_PkmnOkComeBack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}　いいぞ！\n"
    "もどれ！");

const u8 sText_PkmnGoodComeBack[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_BUFF1}　よくやった！\n"
    "もどれ！");

const u8 sText_Trainer1WithdrewPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_BUFF1}を　ひっこめた！");

const u8 sText_LinkTrainer1WithdrewPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_OPPONENT1_NAME}は\n"
    "{B_BUFF1}を　ひっこめた！");

const u8 sText_LinkTrainer2WithdrewPkmn[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_LINK_SCR_TRAINER_NAME}は\n"
    "{B_BUFF1}を　ひっこめた！");

const u8 sText_WildPkmnPrefix[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("やせいの　");

const u8 sText_FoePkmnPrefix[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あいての　");

const u8 sText_EmptyString8[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("");

const u8 sText_FoePkmnPrefix2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あいての");

const u8 sText_AllyPkmnPrefix[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("みかたの");

const u8 sText_FoePkmnPrefix3[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あいては");

const u8 sText_AllyPkmnPrefix2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("みかたは");

const u8 sText_FoePkmnPrefix4[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("あいてを");

const u8 sText_AllyPkmnPrefix3[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("みかたを");

const u8 sText_AttackerUsedX[] BATTLE_MESSAGE_REGION_TEXT_DATA = _(
    "{B_ATK_NAME_WITH_PREFIX}{B_BUFF1}\n"
    "{B_BUFF2}");

const u8 sText_ExclamationMark[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("を　つかった！");

const u8 sText_ExclamationMark2[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("した！");

const u8 sText_ExclamationMark3[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("を　した！");

const u8 sText_ExclamationMark4[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("　こうげき！");

const u8 sText_ExclamationMark5[] BATTLE_MESSAGE_REGION_TEXT_DATA = _("！");

// JP battle text, stat names, and Pokeblock flavor tables at
// 0x085AB057-0x085AB3DC. The pointer tables retain the original order.
const u8 sText_HP2[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("たいりょく");

const u8 sText_Attack2[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("こうげきりょく");

const u8 sText_Defense2[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("ぼうぎょりょく");

const u8 sText_Speed[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("すばやさ");

const u8 sText_SpAtk2[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("とくこう");

const u8 sText_SpDef2[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("とくぼう");

const u8 sText_Accuracy[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("めいちゅうりつ");

const u8 sText_Evasiveness[] BATTLE_MESSAGE_STAT_TEXT_DATA = _("かいひりつ");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] BATTLE_MESSAGE_STAT_POINTER_DATA =
{
    [STAT_HP]      = sText_HP2,
    [STAT_ATK]     = sText_Attack2,
    [STAT_DEF]     = sText_Defense2,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAtk2,
    [STAT_SPDEF]   = sText_SpDef2,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};

const u8 sText_PokeblockWasTooSpicy[] BATTLE_MESSAGE_FLAVOR_TEXT_DATA = _("からすぎた！");

const u8 sText_PokeblockWasTooDry[] BATTLE_MESSAGE_FLAVOR_TEXT_DATA = _("しぶすぎた！");

const u8 sText_PokeblockWasTooSweet[] BATTLE_MESSAGE_FLAVOR_TEXT_DATA = _("あますぎた！");

const u8 sText_PokeblockWasTooBitter[] BATTLE_MESSAGE_FLAVOR_TEXT_DATA = _("にがすぎた！");

const u8 sText_PokeblockWasTooSour[] BATTLE_MESSAGE_FLAVOR_TEXT_DATA = _("すっぱすぎた！");

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] BATTLE_MESSAGE_FLAVOR_POINTER_DATA =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour,
};

const u8 sText_PlayerUsedItem[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_PLAYER_NAME}は　\n"
    "{B_LAST_ITEM}を　つかった！");

const u8 sText_WallyUsedItem[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ミツルは　\n"
    "{B_LAST_ITEM}を　つかった！");

const u8 sText_Trainer1UsedItem[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_TRAINER1_CLASS}の　{B_TRAINER1_NAME}は\n"
    "{B_LAST_ITEM}を　つかった！");

const u8 sText_TrainerBlockedBall[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("トレーナーに　ボールを　はじかれた！");

const u8 sText_DontBeAThief[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("ひとの　ものを　とったら　どろぼう！");

const u8 sText_ItDodgedBall[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "よけられた！\n"
    "こいつは　つかまりそうにないぞ！");

const u8 sText_YouMissedPkmn[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ポケモンに\n"
    "うまく　あたらなかった！");

const u8 sText_PkmnBrokeFree[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "だめだ！　ポケモンが\n"
    "ボールから　でてしまった！");

const u8 sText_ItAppearedCaught[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ああ！\n"
    "つかまえたと　おもったのに！");

const u8 sText_AarghAlmostHadIt[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ざんねん！\n"
    "もうすこしで　つかまえられたのに！");

const u8 sText_ShootSoClose[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "おしい！\n"
    "あと　ちょっとの　ところだったのに！");

const u8 sText_GotchaPkmnCaughtPlayer[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "やったー！\n"
    "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");

const u8 sText_GotchaPkmnCaughtWally[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "やったー！\n"
    "{B_OPPONENT_MON1_NAME}を　つかまえたぞ！{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");

const u8 sText_GiveNicknameCaptured[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "つかまえた　{B_OPPONENT_MON1_NAME}に\n"
    "ニックネームを　つけますか？");

const u8 sText_PkmnSentToPC[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}は　{B_PC_CREATOR_NAME}　パソコンに\n"
    "てんそうされた！");

const u8 sText_Someones[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("だれかの");

const u8 sText_Lanettes[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("マユミの");

const u8 sText_PkmnDataAddedToDex[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_OPPONENT_MON1_NAME}の　データが　あたらしく\n"
    "ポケモンずかんに　セーブされます！\p");

const u8 sText_ItIsRaining[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("あめが　ふっている");

const u8 sText_SandstormIsRaging[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("すなあらしが　ふきあれている");

const u8 sText_BoxIsFull[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ボックスが　いっぱいで\n"
    "これいじょう　つかまえられない！\p");

const u8 sText_EnigmaBerry[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("ナゾのみ");

const u8 sText_BerrySuffix[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("のみ");

const u8 sText_PkmnsItemCuredParalysis[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "まひが　なおった！");

const u8 sText_PkmnsItemCuredPoison[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "どくが　なおった！");

const u8 sText_PkmnsItemHealedBurn[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "やけどが　なおった！");

const u8 sText_PkmnsItemDefrostedIt[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "こおりじょうたいが　なおった！");

const u8 sText_PkmnsItemWokeIt[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "ねむりから　さめた！");

const u8 sText_PkmnsItemSnappedOut[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "こんらんが　なおった！");

const u8 sText_PkmnsItemCuredProblem[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "{B_BUFF1}じょうたいが　なおった！");

const u8 sText_PkmnsItemNormalizedStatus[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "じょうたいいじょうが　なおった！");

const u8 sText_PkmnsItemRestoredHealth[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "たいりょくを　かいふくした！");

const u8 sText_PkmnsItemRestoredPP[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "{B_BUFF1}の　わざポイントを　かいふくした！");

const u8 sText_PkmnsItemRestoredStatus[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "ステータスを　もとに　もどした！");

const u8 sText_PkmnsItemRestoredHPALittle[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_SCR_ACTIVE_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "すこし　かいふく");

const u8 sText_ItemAllowsOnlyYMove[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_LAST_ITEM}の　こうかで\n"
    "{B_CURRENT_MOVE}しか　だすことができない！\p");

const u8 sText_PkmnHungOnWithX[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "{B_DEF_NAME_WITH_PREFIX}は　{B_LAST_ITEM}で\n"
    "もちこたえた！");

const u8 gText_EmptyString3[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _("　");

const u8 sText_YouThrowABallNowRight[] BATTLE_MESSAGE_TAIL_TEXT_DATA = _(
    "ここで　ボールを　なげるんだね\n"
    "ぼく⋯⋯　やってみるよ！");

// Battle string ID order follows the shared JP/US constants. JP pointer
// targets below come from the JP ROM, not from US text addresses.
const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT - BATTLESTRINGS_TABLE_START] BATTLE_MESSAGE_STRING_POINTER_DATA =
{
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = sText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_ExpGainedNoBonus, // JP EXP particle; US has an empty string
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE2F, // US: sText_TwoInGameTrainersDefeated; JP target still needs a semantic label
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE4D, // US: sText_Trainer2LoseText; JP target still needs a semantic label
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE50, // US: sText_PkmnIncapableOfPower; JP target still needs a semantic label
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE6C, // US: sText_GlintAppearsInEye; JP target still needs a semantic label
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE7F, // US: sText_PkmnGettingIntoPosition; JP target still needs a semantic label
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABE93, // US: sText_PkmnBeganGrowlingDeeply; JP target still needs a semantic label
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABEA5, // US: sText_PkmnEagerForMore; JP target still needs a semantic label
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABFE2, // US: sText_DefeatedOpponentByReferee; JP target still needs a semantic label
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085ABFFA, // US: sText_LostToOpponentByReferee; JP target still needs a semantic label
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085AC012, // US: sText_TiedOpponentByReferee; JP target still needs a semantic label
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085AC070, // US: sText_QuestionForfeitMatch; JP target still needs a semantic label
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085AC087, // US: sText_ForfeitedMatch; JP target still needs a semantic label
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = (const u8 *)0x08243E08, // US: gText_PkmnTransferredSomeonesPC; JP target still needs a semantic label
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = (const u8 *)0x08243E2A, // US: gText_PkmnTransferredLanettesPC; JP target still needs a semantic label
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = (const u8 *)0x08243E4C, // US: gText_PkmnTransferredSomeonesPCBoxFull; JP target still needs a semantic label
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = (const u8 *)0x08243E80, // US: gText_PkmnTransferredLanettesPCBoxFull; JP target still needs a semantic label
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085AC098, // US: sText_Trainer1WinText; JP target still needs a semantic label
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = (const u8 *)0x085AC09B, // US: sText_Trainer2WinText; JP target still needs a semantic label
};

// JP text-expand helper (US: BattleStringExpandPlaceholdersToDisplayedString)
extern void TryGetStatusString(const u8 *text);
extern void ChooseMoveUsedParticle(u8 *dest);
extern void ChooseTypeOfMoveUsedString(u8 *dest);
extern const u8 sATypeMove_Table[][12];
extern u8 sBattlerAbilities[MAX_BATTLERS_COUNT];

extern const u8 sText_GotAwaySafely[];
extern const u8 sText_PlayerDefeatedLinkTrainer[];
extern const u8 sText_TwoLinkTrainersDefeated[];
extern const u8 sText_PlayerLostAgainstLinkTrainer[];
extern const u8 sText_PlayerLostToTwo[];
extern const u8 sText_PlayerBattledToDrawLinkTrainer[];
extern const u8 sText_PlayerBattledToDrawVsTwo[];
extern const u8 sText_WildFled[];
extern const u8 sText_TwoWildFled[];
extern const u8 sText_PlayerDefeatedLinkTrainerTrainer1[];
extern const u8 sText_WildPkmnAppearedPause[];
extern const u8 sText_LegendaryPkmnAppeared[];
extern const u8 sText_WildPkmnAppeared[];
extern const u8 sText_TwoWildPkmnAppeared[];
extern const u8 sText_Trainer1WantsToBattle[];
extern const u8 sText_LinkTrainerWantsToBattlePause[];
extern const u8 sText_TwoLinkTrainersWantToBattlePause[];
extern const u8 sText_Trainer1SentOutPkmn[];
extern const u8 sText_Trainer1SentOutTwoPkmn[];
extern const u8 sText_Trainer1SentOutPkmn2[];
extern const u8 sText_LinkTrainerSentOutPkmn[];
extern const u8 sText_LinkTrainerSentOutTwoPkmn[];
extern const u8 sText_TwoLinkTrainersSentOutPkmn[];
extern const u8 sText_LinkTrainerSentOutPkmn2[];
extern const u8 sText_LinkTrainerMultiSentOutPkmn[];
extern const u8 sText_GoPkmn[];
extern const u8 sText_GoTwoPkmn[];
extern const u8 sText_GoPkmn2[];
extern const u8 sText_DoItPkmn[];
extern const u8 sText_YourFoesWeakGetEmPkmn[];
extern const u8 sText_GoForItPkmn[];
extern const u8 sText_LinkPartnerSentOutPkmnGoPkmn[];
extern const u8 sText_PkmnThatsEnough[];
extern const u8 sText_PkmnComeBack[];
extern const u8 sText_PkmnGoodComeBack[];
extern const u8 sText_PkmnOkComeBack[];
extern const u8 sText_Trainer1WithdrewPkmn[];
extern const u8 sText_LinkTrainer1WithdrewPkmn[];
extern const u8 sText_LinkTrainer2WithdrewPkmn[];
extern const u8 sText_AttackerUsedX[];
extern const u8 sText_TwoTrainersSentPkmn[];
extern const u8 sText_Trainer2SentOutPkmn[];
extern const u8 sText_TwoTrainersWantToBattle[];
extern const u8 sText_InGamePartnerSentOutZGoN[];
extern const u8 sText_TwoInGameTrainersDefeated[];
extern const u8 sText_PlayerLostAgainstTrainer1[];
extern const u8 sText_PlayerBattledToDrawTrainer1[];
extern const u8 sText_LinkTrainerWantsToBattle[];
extern const u8 sText_TwoLinkTrainersWantToBattle[];


// The Japanese battle grammar chooses one of four move groups. Keep this
// table at its original ROdata slot while making battle_message.c its owner.
const u16 sGrammarMoveUsedTable[] BATTLE_MESSAGE_GRAMMAR_MOVE_DATA =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, MOVE_NONE,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, MOVE_NONE,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, MOVE_NONE,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VICE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, MOVE_NONE,
};

#undef BATTLE_MESSAGE_GRAMMAR_MOVE_DATA

extern const u8 sText_SpaceIs[];
extern const u8 sText_ApostropheS[];
extern const u8 sText_ExclamationMark[];
extern const u8 sText_ExclamationMark2[];
extern const u8 sText_ExclamationMark3[];
extern const u8 sText_ExclamationMark4[];
extern const u8 sText_ExclamationMark5[];

// JP uses its own text metrics and FONT_SHORT entries where the US build uses
// the unavailable narrow font. The two padding bytes in each entry are emitted
// by this ABI and remain zero-initialized.
BATTLE_MESSAGE_NORMAL_WINDOW_TEXT_DATA const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .y = 2,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fontId = FONT_SHORT,
        .x = 32,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_SHORT,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fontId = FONT_SHORT,
        .x = 4,
        .y = 2,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fontId = FONT_SHORT,
        .x = 2,
        .y = 2,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fontId = FONT_SHORT,
        .x = 2,
        .y = 2,
        .fgColor = 1,
        .shadowColor = 6,
    },
};

BATTLE_MESSAGE_ARENA_WINDOW_TEXT_DATA const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .y = 2,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fontId = FONT_SHORT,
        .x = 32,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 8,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 4,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 8,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 4,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .y = 2,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(1),
        .fontId = FONT_NORMAL,
        .y = 2,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

BATTLE_MESSAGE_WINDOW_TEXT_POINTER_DATA const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA] = sTextOnWindowsInfo_Arena,
};

BATTLE_MESSAGE_RECORDED_TEXT_SPEED_DATA const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}
__attribute__((naked, section(".text.battle_message_tail"))) void BufferStringBattle(u16 stringID)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	movs r7, #0\n\t"
        "	ldr r4, _0814E22C\n\t"
        "	ldr r0, _0814E230\n\t"
        "	mov ip, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #9\n\t"
        "	ldr r0, _0814E234\n\t"
        "	adds r1, r1, r0\n\t"
        "	str r1, [r4]\n\t"
        "	ldr r2, _0814E238\n\t"
        "	ldrh r0, [r1, #4]\n\t"
        "	strh r0, [r2]\n\t"
        "	ldr r2, _0814E23C\n\t"
        "	ldrb r0, [r1, #6]\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r5, _0814E240\n\t"
        "	ldrb r0, [r1, #7]\n\t"
        "	strb r0, [r5, #0x17]\n\t"
        "	ldr r3, _0814E244\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x52\n\t"
        "	ldrb r1, [r1, #8]\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0xb1\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldrb r1, [r1, #9]\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _0814E248\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldrb r0, [r2, #0xa]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x8e\n\t"
        "	ldrb r1, [r2, #0xb]\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	mov r8, r5\n\t"
        "	ldr r1, _0814E24C\n\t"
        "	mov sb, r1\n\t"
        "	ldr r3, _0814E250\n\t"
        "_0814E1E2:\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #3\n\t"
        "	ble _0814E1E2\n\t"
        "	movs r2, #0\n\t"
        "	ldr r5, _0814E24C\n\t"
        "	ldr r3, _0814E22C\n\t"
        "	ldr r4, _0814E254\n\t"
        "_0814E1FC:\n\t"
        "	adds r1, r2, r5\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x10\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, r2, r4\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x20\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0xf\n\t"
        "	ble _0814E1FC\n\t"
        "	cmp r6, #5\n\t"
        "	bls _0814E220\n\t"
        "	b _0814E768\n\t"
        "_0814E220:\n\t"
        "	lsls r0, r6, #2\n\t"
        "	ldr r1, _0814E258\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0814E22C: .4byte 0x0203A874\n\t"
        "_0814E230: .4byte 0x02023D08\n\t"
        "_0814E234: .4byte 0x02022D0C\n\t"
        "_0814E238: .4byte 0x02023EAC\n\t"
        "_0814E23C: .4byte 0x02023EAE\n\t"
        "_0814E240: .4byte 0x02024118\n\t"
        "_0814E244: .4byte 0x02024140\n\t"
        "_0814E248: .4byte 0x02023EB3\n\t"
        "_0814E24C: .4byte 0x02022C0C\n\t"
        "_0814E250: .4byte 0x0203A870\n\t"
        "_0814E254: .4byte 0x02022C1C\n\t"
        "_0814E258: .4byte 0x0814E25C\n\t"
        "_0814E25C:\n\t"
        "	.4byte _0814E274\n\t"
        "	.4byte _0814E354\n\t"
        "	.4byte _0814E43C\n\t"
        "	.4byte _0814E4D8\n\t"
        "	.4byte _0814E5A0\n\t"
        "	.4byte _0814E600\n\t"
        "_0814E274:\n\t"
        "	ldr r0, _0814E2AC\n\t"
        "	ldr r2, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E314\n\t"
        "	ldr r0, _0814E2B0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E2F0\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E308\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E2BC\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	ands r2, r0\n\t"
        "	ldr r7, _0814E2B4\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814E2A8\n\t"
        "	b _0814E788\n\t"
        "_0814E2A8:\n\t"
        "	ldr r7, _0814E2B8\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E2AC: .4byte 0x02022C90\n\t"
        "_0814E2B0: .4byte 0x02000002\n\t"
        "_0814E2B4: .4byte gUnknown_85A9544 + 0x194D\n\t"
        "_0814E2B8: .4byte gUnknown_85ABE2F + 0x2FE\n\t"
        "_0814E2BC:\n\t"
        "	ldr r0, _0814E2CC\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0814E2D4\n\t"
        "	ldr r7, _0814E2D0\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E2CC: .4byte 0x0203886A\n\t"
        "_0814E2D0: .4byte gUnknown_85A9544 + 0x1924\n\t"
        "_0814E2D4:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	ands r2, r0\n\t"
        "	ldr r7, _0814E2E8\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814E2E2\n\t"
        "	b _0814E788\n\t"
        "_0814E2E2:\n\t"
        "	ldr r7, _0814E2EC\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E2E8: .4byte gUnknown_85A9544 + 0x193B\n\t"
        "_0814E2EC: .4byte gUnknown_85ABE2F + 0x2E9\n\t"
        "_0814E2F0:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0xf\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E308\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r2, r0\n\t"
        "	ldr r7, _0814E30C\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814E308\n\t"
        "	b _0814E788\n\t"
        "_0814E308:\n\t"
        "	ldr r7, _0814E310\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E30C: .4byte gUnknown_85A9544 + 0x1924\n\t"
        "_0814E310: .4byte gUnknown_85ABD3C + 0xB8\n\t"
        "_0814E314:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #6\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E328\n\t"
        "	ldr r7, _0814E324\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E324: .4byte gUnknown_85A9544 + 0x18DE\n\t"
        "_0814E328:\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E338\n\t"
        "	ldr r7, _0814E334\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E334: .4byte gUnknown_85A9544 + 0x190A\n\t"
        "_0814E338:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ands r2, r0\n\t"
        "	ldr r7, _0814E34C\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814E346\n\t"
        "	b _0814E788\n\t"
        "_0814E346:\n\t"
        "	ldr r7, _0814E350\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E34C: .4byte gUnknown_85A9544 + 0x18C8\n\t"
        "_0814E350: .4byte gUnknown_85A9544 + 0x18F2\n\t"
        "_0814E354:\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E3B8\n\t"
        "	ldr r0, _0814E37C\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E3B0\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E384\n\t"
        "	ldr r7, _0814E380\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E37C: .4byte 0x02022C90\n\t"
        "_0814E380: .4byte gUnknown_85ABD3C + 0xD7\n\t"
        "_0814E384:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E398\n\t"
        "	ldr r7, _0814E394\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E394: .4byte gUnknown_85A9544 + 0x1A07\n\t"
        "_0814E398:\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r1, r0\n\t"
        "	ldr r7, _0814E3A8\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0814E3A4\n\t"
        "	b _0814E788\n\t"
        "_0814E3A4:\n\t"
        "	ldr r7, _0814E3AC\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E3A8: .4byte gUnknown_85A9544 + 0x1A07\n\t"
        "_0814E3AC: .4byte gUnknown_85A9544 + 0x1A4A\n\t"
        "_0814E3B0:\n\t"
        "	ldr r7, _0814E3B4\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E3B4: .4byte gUnknown_85A9544 + 0x19FE\n\t"
        "_0814E3B8:\n\t"
        "	ldr r0, _0814E3DC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E410\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E3D8\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E3E4\n\t"
        "_0814E3D8:\n\t"
        "	ldr r7, _0814E3E0\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E3DC: .4byte 0x02022C90\n\t"
        "_0814E3E0: .4byte gUnknown_85ABD3C + 0x7F\n\t"
        "_0814E3E4:\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E3F4\n\t"
        "	ldr r7, _0814E3F0\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E3F0: .4byte gUnknown_85A9544 + 0x19C2\n\t"
        "_0814E3F4:\n\t"
        "	ldr r0, _0814E404\n\t"
        "	ands r1, r0\n\t"
        "	ldr r7, _0814E408\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0814E400\n\t"
        "	b _0814E788\n\t"
        "_0814E400:\n\t"
        "	ldr r7, _0814E40C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E404: .4byte 0x02000002\n\t"
        "_0814E408: .4byte gUnknown_85A9544 + 0x1976\n\t"
        "_0814E40C: .4byte gUnknown_85A9544 + 0x19AF\n\t"
        "_0814E410:\n\t"
        "	ldr r0, _0814E42C\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814E428\n\t"
        "	ldr r0, _0814E430\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r7, _0814E434\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0814E428\n\t"
        "	b _0814E788\n\t"
        "_0814E428:\n\t"
        "	ldr r7, _0814E438\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E42C: .4byte 0x02000002\n\t"
        "_0814E430: .4byte 0x0203886A\n\t"
        "_0814E434: .4byte gUnknown_85A9544 + 0x19A0\n\t"
        "_0814E438: .4byte gUnknown_85A9544 + 0x1963\n\t"
        "_0814E43C:\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E494\n\t"
        "	ldr r0, _0814E45C\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xb1\n\t"
        "	ldrb r2, [r0]\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814E464\n\t"
        "	ldr r7, _0814E460\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E45C: .4byte 0x02024140\n\t"
        "_0814E460: .4byte gUnknown_85A9544 + 0x1A62\n\t"
        "_0814E464:\n\t"
        "	cmp r2, #1\n\t"
        "	beq _0814E474\n\t"
        "	ldr r0, _0814E478\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E480\n\t"
        "_0814E474:\n\t"
        "	ldr r7, _0814E47C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E478: .4byte 0x02022C90\n\t"
        "_0814E47C: .4byte gUnknown_85A9544 + 0x1A70\n\t"
        "_0814E480:\n\t"
        "	ldr r7, _0814E48C\n\t"
        "	cmp r2, #2\n\t"
        "	beq _0814E488\n\t"
        "	b _0814E788\n\t"
        "_0814E488:\n\t"
        "	ldr r7, _0814E490\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E48C: .4byte gUnknown_85A9544 + 0x1A85\n\t"
        "_0814E490: .4byte gUnknown_85A9544 + 0x1A78\n\t"
        "_0814E494:\n\t"
        "	ldr r0, _0814E4C0\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r2, _0814E4C4\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0814E4AE\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0x12\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E4D0\n\t"
        "_0814E4AE:\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	ldr r7, _0814E4C8\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E4BC\n\t"
        "	b _0814E788\n\t"
        "_0814E4BC:\n\t"
        "	ldr r7, _0814E4CC\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E4C0: .4byte 0x0203886A\n\t"
        "_0814E4C4: .4byte 0x02022C90\n\t"
        "_0814E4C8: .4byte gUnknown_85A9544 + 0x1AA7\n\t"
        "_0814E4CC: .4byte gUnknown_85A9544 + 0x1AB6\n\t"
        "_0814E4D0:\n\t"
        "	ldr r7, _0814E4D4\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E4D4: .4byte gUnknown_85A9544 + 0x1A94\n\t"
        "_0814E4D8:\n\t"
        "	mov r4, r8\n\t"
        "	ldrb r0, [r4, #0x17]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814E530\n\t"
        "	ldr r0, _0814E504\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xb1\n\t"
        "	ldrb r2, [r0]\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0814E4FE\n\t"
        "	ldr r0, _0814E508\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E510\n\t"
        "_0814E4FE:\n\t"
        "	ldr r7, _0814E50C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E504: .4byte 0x02024140\n\t"
        "_0814E508: .4byte 0x02022C90\n\t"
        "_0814E50C: .4byte gUnknown_85A9544 + 0x1A14\n\t"
        "_0814E510:\n\t"
        "	cmp r2, #1\n\t"
        "	bne _0814E51C\n\t"
        "	ldr r7, _0814E518\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E518: .4byte gUnknown_85A9544 + 0x1A1D\n\t"
        "_0814E51C:\n\t"
        "	ldr r7, _0814E528\n\t"
        "	cmp r2, #2\n\t"
        "	beq _0814E524\n\t"
        "	b _0814E788\n\t"
        "_0814E524:\n\t"
        "	ldr r7, _0814E52C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E528: .4byte gUnknown_85A9544 + 0x1A32\n\t"
        "_0814E52C: .4byte gUnknown_85A9544 + 0x1A28\n\t"
        "_0814E530:\n\t"
        "	ldr r0, _0814E54C\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814E550\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E584\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E554\n\t"
        "	ldrb r0, [r4, #0x17]\n\t"
        "	b _0814E592\n\t"
        "	.align 2, 0\n\t"
        "_0814E54C: .4byte 0x02022C90\n\t"
        "_0814E550: .4byte 0x02000002\n\t"
        "_0814E554:\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814E564\n\t"
        "	ldr r7, _0814E560\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E560: .4byte gUnknown_85A9544 + 0x19EF\n\t"
        "_0814E564:\n\t"
        "	ldr r0, _0814E578\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r7, _0814E57C\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0814E574\n\t"
        "	b _0814E788\n\t"
        "_0814E574:\n\t"
        "	ldr r7, _0814E580\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E578: .4byte 0x0203886A\n\t"
        "_0814E57C: .4byte gUnknown_85A9544 + 0x19E0\n\t"
        "_0814E580: .4byte gUnknown_85A9544 + 0x198D\n\t"
        "_0814E584:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814E574\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1, #0x17]\n\t"
        "_0814E592:\n\t"
        "	ldr r7, _0814E59C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0814E59A\n\t"
        "	b _0814E788\n\t"
        "_0814E59A:\n\t"
        "	b _0814E574\n\t"
        "	.align 2, 0\n\t"
        "_0814E59C: .4byte gUnknown_85ABD3C + 0xA5\n\t"
        "_0814E5A0:\n\t"
        "	mov r0, sb\n\t"
        "	bl ChooseMoveUsedParticle\n\t"
        "	ldr r0, _0814E5CC\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r0, #0xb1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bls _0814E5DC\n\t"
        "	ldr r0, _0814E5D0\n\t"
        "	ldr r1, _0814E5D4\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, #0x8e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	lsls r1, r2, #3\n\t"
        "	subs r1, r1, r2\n\t"
        "	ldr r2, _0814E5D8\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	b _0814E5EA\n\t"
        "	.align 2, 0\n\t"
        "_0814E5CC: .4byte 0x0203A874\n\t"
        "_0814E5D0: .4byte 0x02022C1C\n\t"
        "_0814E5D4: .4byte 0x02024140\n\t"
        "_0814E5D8: .4byte gUnknown_85ABBD8 + 0xC2\n\t"
        "_0814E5DC:\n\t"
        "	ldr r0, _0814E5F4\n\t"
        "	ldrh r1, [r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _0814E5F8\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "_0814E5EA:\n\t"
        "	ldr r0, _0814E5F4\n\t"
        "	bl ChooseTypeOfMoveUsedString\n\t"
        "	ldr r7, _0814E5FC\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E5F4: .4byte 0x02022C1C\n\t"
        "_0814E5F8: .4byte 0x082EACC4\n\t"
        "_0814E5FC: .4byte gUnknown_85A9544 + 0x1AF0\n\t"
        "_0814E600:\n\t"
        "	ldr r4, _0814E640\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E674\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0814E62E\n\t"
        "	ldrb r1, [r4]\n\t"
        "	cmp r1, #3\n\t"
        "	beq _0814E62E\n\t"
        "	movs r0, #3\n\t"
        "	eors r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_0814E62E:\n\t"
        "	ldr r0, _0814E640\n\t"
        "	ldrb r0, [r0]\n\t"
        "	subs r0, #2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _0814E648\n\t"
        "	ldr r7, _0814E644\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E640: .4byte 0x02022C0C\n\t"
        "_0814E644: .4byte gUnknown_85A9544 + 0x142C\n\t"
        "_0814E648:\n\t"
        "	ldr r0, _0814E658\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E660\n\t"
        "	ldr r7, _0814E65C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E658: .4byte 0x02022C90\n\t"
        "_0814E65C: .4byte gUnknown_85A9544 + 0x1501\n\t"
        "_0814E660:\n\t"
        "	ldr r0, _0814E66C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r7, _0814E670\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E66C: .4byte 0x0203886A\n\t"
        "_0814E670: .4byte gUnknown_85A9544 + 0x14F2\n\t"
        "_0814E674:\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0814E690\n\t"
        "	ldrb r1, [r4]\n\t"
        "	cmp r1, #3\n\t"
        "	beq _0814E690\n\t"
        "	movs r0, #3\n\t"
        "	eors r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_0814E690:\n\t"
        "	ldr r0, _0814E6B0\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E6E8\n\t"
        "	ldr r0, _0814E6B4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0814E6D8\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0814E6B8\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0814E6BE\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E6B0: .4byte 0x02022C90\n\t"
        "_0814E6B4: .4byte 0x02022C0C\n\t"
        "_0814E6B8:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _0814E6E0\n\t"
        "	b _0814E788\n\t"
        "_0814E6BE:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ands r1, r0\n\t"
        "	ldr r7, _0814E6D0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814E788\n\t"
        "	ldr r7, _0814E6D4\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E6D0: .4byte gUnknown_85A9544 + 0x1492\n\t"
        "_0814E6D4: .4byte gUnknown_85ABE2F\n\t"
        "_0814E6D8:\n\t"
        "	ldr r7, _0814E6DC\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E6DC: .4byte gUnknown_85A9544 + 0x14B6\n\t"
        "_0814E6E0:\n\t"
        "	ldr r7, _0814E6E4\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E6E4: .4byte gUnknown_85A9544 + 0x14DC\n\t"
        "_0814E6E8:\n\t"
        "	ldr r0, _0814E708\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0814E730\n\t"
        "	ldr r0, _0814E70C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0814E720\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0814E710\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0814E716\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E708: .4byte 0x0203886A\n\t"
        "_0814E70C: .4byte 0x02022C0C\n\t"
        "_0814E710:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _0814E728\n\t"
        "	b _0814E788\n\t"
        "_0814E716:\n\t"
        "	ldr r7, _0814E71C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E71C: .4byte gUnknown_85A9544 + 0x17DE\n\t"
        "_0814E720:\n\t"
        "	ldr r7, _0814E724\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E724: .4byte gUnknown_85ABE2F + 0x282\n\t"
        "_0814E728:\n\t"
        "	ldr r7, _0814E72C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E72C: .4byte gUnknown_85ABE2F + 0x297\n\t"
        "_0814E730:\n\t"
        "	ldr r0, _0814E744\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0814E758\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0814E748\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0814E74E\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E744: .4byte 0x02022C0C\n\t"
        "_0814E748:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _0814E760\n\t"
        "	b _0814E788\n\t"
        "_0814E74E:\n\t"
        "	ldr r7, _0814E754\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E754: .4byte gUnknown_85A9544 + 0x1482\n\t"
        "_0814E758:\n\t"
        "	ldr r7, _0814E75C\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E75C: .4byte gUnknown_85A9544 + 0x14A6\n\t"
        "_0814E760:\n\t"
        "	ldr r7, _0814E764\n\t"
        "	b _0814E788\n\t"
        "	.align 2, 0\n\t"
        "_0814E764: .4byte gUnknown_85A9544 + 0x14CA\n\t"
        "_0814E768:\n\t"
        "	movs r0, #0xbe\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r6, r0\n\t"
        "	bls _0814E77C\n\t"
        "	ldr r1, _0814E778\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0814E78E\n\t"
        "	.align 2, 0\n\t"
        "_0814E778: .4byte 0x02022AE0\n\t"
        "_0814E77C:\n\t"
        "	ldr r1, _0814E79C\n\t"
        "	adds r0, r6, #0\n\t"
        "	subs r0, #0xc\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r7, [r0]\n\t"
        "_0814E788:\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl TryGetStatusString\n\t"
        "_0814E78E:\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814E79C: .4byte gBattleStringsTable\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) void TryGetStatusString(const u8 *text)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _0814E7AC\n\t"
        "	bl BattleStringExpandPlaceholdersToDisplayedString\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0814E7AC: .4byte 0x02022AE0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	mov sb, r0\n\t"
        "	mov r8, r1\n\t"
        "	movs r6, #0\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _0814E7D8\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0x12\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814E7E0\n\t"
        "	ldr r0, _0814E7DC\n\t"
        "	ldrb r7, [r0]\n\t"
        "	b _0814E7E8\n\t"
        "	.align 2, 0\n\t"
        "_0814E7D8: .4byte 0x02022C90\n\t"
        "_0814E7DC: .4byte 0x0203C480\n\t"
        "_0814E7E0:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "_0814E7E8:\n\t"
        "	mov r0, sb\n\t"
        "	ldrb r1, [r0]\n\t"
        "	bl sub_0814F63C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	cmp r1, #0xfd\n\t"
        "	beq _0814E7F8\n\t"
        "	bl BattlePutTextOnWindow\n\t"
        "_0814E7F8:\n\t"
        "	movs r1, #1\n\t"
        "	add sb, r1\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0x33\n\t"
        "	bls _0814E808\n\t"
        "	bl _0814F5DC\n\t"
        "_0814E808:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0814E814\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0814E814: .4byte 0x0814E818\n\t"
        "_0814E818:\n\t"
        "	.4byte _0814E8E8\n\t"
        "	.4byte _0814E8FC\n\t"
        "	.4byte _0814E922\n\t"
        "	.4byte _0814E92C\n\t"
        "	.4byte _0814E938\n\t"
        "	.4byte _0814E944\n\t"
        "	.4byte _0814E978\n\t"
        "	.4byte _0814E9AC\n\t"
        "	.4byte _0814E9E0\n\t"
        "	.4byte _0814EA14\n\t"
        "	.4byte _0814EA50\n\t"
        "	.4byte _0814EA90\n\t"
        "	.4byte _0814EAD0\n\t"
        "	.4byte _0814EB10\n\t"
        "	.4byte _0814EBC8\n\t"
        "	.4byte _0814EC50\n\t"
        "	.4byte _0814ECEC\n\t"
        "	.4byte _0814ED88\n\t"
        "	.4byte _0814EE24\n\t"
        "	.4byte _0814EEC0\n\t"
        "	.4byte _0814EF5C\n\t"
        "	.4byte _0814EF74\n\t"
        "	.4byte _0814EFB0\n\t"
        "	.4byte _0814F098\n\t"
        "	.4byte _0814F0A0\n\t"
        "	.4byte _0814F0B0\n\t"
        "	.4byte _0814F0C0\n\t"
        "	.4byte _0814F0D0\n\t"
        "	.4byte _0814F0F0\n\t"
        "	.4byte _0814F178\n\t"
        "	.4byte _0814F242\n\t"
        "	.4byte _0814F254\n\t"
        "	.4byte _0814F268\n\t"
        "	.4byte _0814F27C\n\t"
        "	.4byte _0814F2A0\n\t"
        "	.4byte _0814F2BC\n\t"
        "	.4byte _0814F2E4\n\t"
        "	.4byte _0814F324\n\t"
        "	.4byte _0814F354\n\t"
        "	.4byte _0814F3E8\n\t"
        "	.4byte _0814F434\n\t"
        "	.4byte _0814F43C\n\t"
        "	.4byte _0814F408\n\t"
        "	.4byte _0814F410\n\t"
        "	.4byte _0814F460\n\t"
        "	.4byte _0814F468\n\t"
        "	.4byte _0814F48C\n\t"
        "	.4byte _0814F4D8\n\t"
        "	.4byte _0814F524\n\t"
        "	.4byte _0814F564\n\t"
        "	.4byte _0814F5B0\n\t"
        "	.4byte _0814F5D0\n\t"
        "_0814E8E8:\n\t"
        "	ldr r1, _0814E8F4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xfd\n\t"
        "	bne _0814E91C\n\t"
        "	ldr r4, _0814E8F8\n\t"
        "	b _0814E906\n\t"
        "	.align 2, 0\n\t"
        "_0814E8F4: .4byte 0x02022C0C\n\t"
        "_0814E8F8: .4byte 0x02021C40\n\t"
        "_0814E8FC:\n\t"
        "	ldr r1, _0814E914\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xfd\n\t"
        "	bne _0814E91C\n\t"
        "	ldr r4, _0814E918\n\t"
        "_0814E906:\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl ExpandBattleTextBuffPlaceholders\n\t"
        "	bl _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814E914: .4byte 0x02022C1C\n\t"
        "_0814E918: .4byte 0x02021C54\n\t"
        "_0814E91C:\n\t"
        "	adds r4, r1, #0\n\t"
        "	bl _0814F5DC\n\t"
        "_0814E922:\n\t"
        "	ldr r4, _0814E928\n\t"
        "	bl _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814E928: .4byte 0x02021C40\n\t"
        "_0814E92C:\n\t"
        "	ldr r4, _0814E934\n\t"
        "	bl _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814E934: .4byte 0x02021C54\n\t"
        "_0814E938:\n\t"
        "	ldr r4, _0814E940\n\t"
        "	bl _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814E940: .4byte 0x02021C68\n\t"
        "_0814E944:\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814E970\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814E974\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814E970: .4byte 0x02023D12\n\t"
        "_0814E974: .4byte 0x02024190\n\t"
        "_0814E978:\n\t"
        "	movs r0, #1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814E9A4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814E9A8\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814E9A4: .4byte 0x02023D12\n\t"
        "_0814E9A8: .4byte 0x020243E8\n\t"
        "_0814E9AC:\n\t"
        "	movs r0, #2\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814E9D8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814E9DC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814E9D8: .4byte 0x02023D12\n\t"
        "_0814E9DC: .4byte 0x02024190\n\t"
        "_0814E9E0:\n\t"
        "	movs r0, #3\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814EA0C\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EA10\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EA0C: .4byte 0x02023D12\n\t"
        "_0814EA10: .4byte 0x020243E8\n\t"
        "_0814EA14:\n\t"
        "	ldr r2, _0814EA44\n\t"
        "	ldr r1, _0814EA48\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x18]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EA4C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EA44: .4byte 0x02023D12\n\t"
        "_0814EA48: .4byte 0x020226A0\n\t"
        "_0814EA4C: .4byte 0x02024190\n\t"
        "_0814EA50:\n\t"
        "	ldr r2, _0814EA84\n\t"
        "	ldr r1, _0814EA88\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #1\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EA8C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EA84: .4byte 0x02023D12\n\t"
        "_0814EA88: .4byte 0x020226A0\n\t"
        "_0814EA8C: .4byte 0x020243E8\n\t"
        "_0814EA90:\n\t"
        "	ldr r2, _0814EAC4\n\t"
        "	ldr r1, _0814EAC8\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #2\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EACC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EAC4: .4byte 0x02023D12\n\t"
        "_0814EAC8: .4byte 0x020226A0\n\t"
        "_0814EACC: .4byte 0x02024190\n\t"
        "_0814EAD0:\n\t"
        "	ldr r2, _0814EB04\n\t"
        "	ldr r1, _0814EB08\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #3\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EB0C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EB04: .4byte 0x02023D12\n\t"
        "_0814EB08: .4byte 0x020226A0\n\t"
        "_0814EB0C: .4byte 0x020243E8\n\t"
        "_0814EB10:\n\t"
        "	ldr r4, _0814EB34\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	adds r2, r4, #0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814EB8C\n\t"
        "	ldr r0, _0814EB38\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814EB3C\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814EB4E\n\t"
        "	ldr r4, _0814EB40\n\t"
        "	b _0814EB4E\n\t"
        "	.align 2, 0\n\t"
        "_0814EB34: .4byte 0x02023EAF\n\t"
        "_0814EB38: .4byte 0x02022C90\n\t"
        "_0814EB3C: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814EB40: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814EB44:\n\t"
        "	mov r3, r8\n\t"
        "	adds r0, r3, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "_0814EB4E:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814EB44\n\t"
        "	ldrb r0, [r2]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814EB84\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EB88\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814EBB6\n\t"
        "	.align 2, 0\n\t"
        "_0814EB84: .4byte 0x02023D12\n\t"
        "_0814EB88: .4byte 0x020243E8\n\t"
        "_0814EB8C:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814EBC0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EBC4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814EBB6:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EBC0: .4byte 0x02023D12\n\t"
        "_0814EBC4: .4byte 0x02024190\n\t"
        "_0814EBC8:\n\t"
        "	ldr r4, _0814EC04\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814EC10\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814EC08\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EC0C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814EC3C\n\t"
        "	.align 2, 0\n\t"
        "_0814EC04: .4byte 0x02023EAF\n\t"
        "_0814EC08: .4byte 0x02023D12\n\t"
        "_0814EC0C: .4byte 0x02024190\n\t"
        "_0814EC10:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0814EC48\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EC4C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814EC3C:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EC48: .4byte 0x02023D12\n\t"
        "_0814EC4C: .4byte 0x020243E8\n\t"
        "_0814EC50:\n\t"
        "	ldr r5, _0814ECA8\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814ECC0\n\t"
        "	ldr r0, _0814ECAC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814ECB0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814EC6E\n\t"
        "	ldr r4, _0814ECB4\n\t"
        "_0814EC6E:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r3, _0814ECB8\n\t"
        "	ldr r2, _0814ECBC\n\t"
        "	mov ip, r2\n\t"
        "	adds r2, r5, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814EC90\n\t"
        "_0814EC7E:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814EC7E\n\t"
        "_0814EC90:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814ECDA\n\t"
        "	.align 2, 0\n\t"
        "_0814ECA8: .4byte 0x02023EAF\n\t"
        "_0814ECAC: .4byte 0x02022C90\n\t"
        "_0814ECB0: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814ECB4: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814ECB8: .4byte 0x02023D12\n\t"
        "_0814ECBC: .4byte 0x020243E8\n\t"
        "_0814ECC0:\n\t"
        "	ldr r1, _0814ECE4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814ECE8\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814ECDA:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814ECE4: .4byte 0x02023D12\n\t"
        "_0814ECE8: .4byte 0x02024190\n\t"
        "_0814ECEC:\n\t"
        "	ldr r5, _0814ED44\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814ED5C\n\t"
        "	ldr r0, _0814ED48\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814ED4C\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814ED0A\n\t"
        "	ldr r4, _0814ED50\n\t"
        "_0814ED0A:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r3, _0814ED54\n\t"
        "	ldr r2, _0814ED58\n\t"
        "	mov ip, r2\n\t"
        "	adds r2, r5, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814ED2C\n\t"
        "_0814ED1A:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814ED1A\n\t"
        "_0814ED2C:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814ED76\n\t"
        "	.align 2, 0\n\t"
        "_0814ED44: .4byte 0x02023EB0\n\t"
        "_0814ED48: .4byte 0x02022C90\n\t"
        "_0814ED4C: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814ED50: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814ED54: .4byte 0x02023D12\n\t"
        "_0814ED58: .4byte 0x020243E8\n\t"
        "_0814ED5C:\n\t"
        "	ldr r1, _0814ED80\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814ED84\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814ED76:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814ED80: .4byte 0x02023D12\n\t"
        "_0814ED84: .4byte 0x02024190\n\t"
        "_0814ED88:\n\t"
        "	ldr r5, _0814EDE0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814EDF8\n\t"
        "	ldr r0, _0814EDE4\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814EDE8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814EDA6\n\t"
        "	ldr r4, _0814EDEC\n\t"
        "_0814EDA6:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r3, _0814EDF0\n\t"
        "	ldr r2, _0814EDF4\n\t"
        "	mov ip, r2\n\t"
        "	adds r2, r5, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814EDC8\n\t"
        "_0814EDB6:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814EDB6\n\t"
        "_0814EDC8:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814EE12\n\t"
        "	.align 2, 0\n\t"
        "_0814EDE0: .4byte 0x02023EB2\n\t"
        "_0814EDE4: .4byte 0x02022C90\n\t"
        "_0814EDE8: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814EDEC: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814EDF0: .4byte 0x02023D12\n\t"
        "_0814EDF4: .4byte 0x020243E8\n\t"
        "_0814EDF8:\n\t"
        "	ldr r1, _0814EE1C\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EE20\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814EE12:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	bl _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EE1C: .4byte 0x02023D12\n\t"
        "_0814EE20: .4byte 0x02024190\n\t"
        "_0814EE24:\n\t"
        "	ldr r5, _0814EE7C\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814EE94\n\t"
        "	ldr r0, _0814EE80\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814EE84\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814EE42\n\t"
        "	ldr r4, _0814EE88\n\t"
        "_0814EE42:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r3, _0814EE8C\n\t"
        "	ldr r2, _0814EE90\n\t"
        "	mov ip, r2\n\t"
        "	adds r2, r5, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814EE64\n\t"
        "_0814EE52:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814EE52\n\t"
        "_0814EE64:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814EEAE\n\t"
        "	.align 2, 0\n\t"
        "_0814EE7C: .4byte 0x02023D08\n\t"
        "_0814EE80: .4byte 0x02022C90\n\t"
        "_0814EE84: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814EE88: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814EE8C: .4byte 0x02023D12\n\t"
        "_0814EE90: .4byte 0x020243E8\n\t"
        "_0814EE94:\n\t"
        "	ldr r1, _0814EEB8\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EEBC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814EEAE:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EEB8: .4byte 0x02023D12\n\t"
        "_0814EEBC: .4byte 0x02024190\n\t"
        "_0814EEC0:\n\t"
        "	ldr r5, _0814EF18\n\t"
        "	ldrb r0, [r5, #0x17]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814EF30\n\t"
        "	ldr r0, _0814EF1C\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814EF20\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814EEDE\n\t"
        "	ldr r4, _0814EF24\n\t"
        "_0814EEDE:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r3, _0814EF28\n\t"
        "	ldr r2, _0814EF2C\n\t"
        "	mov ip, r2\n\t"
        "	adds r2, r5, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814EF00\n\t"
        "_0814EEEE:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814EEEE\n\t"
        "_0814EF00:\n\t"
        "	ldrb r0, [r2, #0x17]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814EF4A\n\t"
        "	.align 2, 0\n\t"
        "_0814EF18: .4byte 0x02024118\n\t"
        "_0814EF1C: .4byte 0x02022C90\n\t"
        "_0814EF20: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814EF24: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814EF28: .4byte 0x02023D12\n\t"
        "_0814EF2C: .4byte 0x020243E8\n\t"
        "_0814EF30:\n\t"
        "	ldr r1, _0814EF54\n\t"
        "	ldrb r0, [r5, #0x17]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814EF58\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814EF4A:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814EF54: .4byte 0x02023D12\n\t"
        "_0814EF58: .4byte 0x02024190\n\t"
        "_0814EF5C:\n\t"
        "	ldr r0, _0814EF70\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r0, #0xb1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bhi _0814EF82\n\t"
        "	ldrh r0, [r2]\n\t"
        "	b _0814EFA2\n\t"
        "	.align 2, 0\n\t"
        "_0814EF70: .4byte 0x0203A874\n\t"
        "_0814EF74:\n\t"
        "	ldr r0, _0814EF94\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	movs r0, #0xb1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bls _0814EFA0\n\t"
        "_0814EF82:\n\t"
        "	ldr r0, _0814EF98\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x8e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	ldr r1, _0814EF9C\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814EF94: .4byte 0x0203A874\n\t"
        "_0814EF98: .4byte 0x02024140\n\t"
        "_0814EF9C: .4byte gUnknown_85ABBD8 + 0xC2\n\t"
        "_0814EFA0:\n\t"
        "	ldrh r0, [r2, #2]\n\t"
        "_0814EFA2:\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0814EFAC\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814EFAC: .4byte 0x082EACC4\n\t"
        "_0814EFB0:\n\t"
        "	ldr r0, _0814EFE4\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814EFE8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F086\n\t"
        "	ldr r2, _0814EFEC\n\t"
        "	ldrh r0, [r2]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _0814F07C\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0814F02C\n\t"
        "	ldr r0, _0814EFF0\n\t"
        "	adds r0, #0x25\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814EFF8\n\t"
        "	ldr r2, _0814EFF4\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814F004\n\t"
        "	b _0814F074\n\t"
        "	.align 2, 0\n\t"
        "_0814EFE4: .4byte 0x02022C90\n\t"
        "_0814EFE8: .4byte 0x02000002\n\t"
        "_0814EFEC: .4byte 0x02023EAC\n\t"
        "_0814EFF0: .4byte 0x02024118\n\t"
        "_0814EFF4: .4byte 0x02023EB3\n\t"
        "_0814EFF8:\n\t"
        "	ldr r2, _0814F020\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814F074\n\t"
        "_0814F004:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0814F024\n\t"
        "	adds r1, r1, r0\n\t"
        "	mov r0, sp\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _0814F028\n\t"
        "	mov r0, sp\n\t"
        "	bl StringAppend\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F020: .4byte 0x02023EB3\n\t"
        "_0814F024: .4byte 0x020240A8\n\t"
        "_0814F028: .4byte sText_BerrySuffix\n\t"
        "_0814F02C:\n\t"
        "	ldr r2, _0814F060\n\t"
        "	ldr r0, _0814F064\n\t"
        "	adds r0, #0x25\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _0814F068\n\t"
        "	ldrb r2, [r1]\n\t"
        "	ldrh r0, [r0, #0x18]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _0814F074\n\t"
        "	lsls r1, r2, #3\n\t"
        "	subs r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0814F06C\n\t"
        "	adds r1, r1, r0\n\t"
        "	mov r0, sp\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _0814F070\n\t"
        "	mov r0, sp\n\t"
        "	bl StringAppend\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F060: .4byte 0x020226A0\n\t"
        "_0814F064: .4byte 0x02024118\n\t"
        "_0814F068: .4byte 0x02023EB3\n\t"
        "_0814F06C: .4byte 0x020240A8\n\t"
        "_0814F070: .4byte sText_BerrySuffix\n\t"
        "_0814F074:\n\t"
        "	ldr r4, _0814F078\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F078: .4byte sText_EnigmaBerry\n\t"
        "_0814F07C:\n\t"
        "	ldrh r0, [r2]\n\t"
        "	mov r1, sp\n\t"
        "	bl CopyItemName\n\t"
        "	b _0814F5DA\n\t"
        "_0814F086:\n\t"
        "	ldr r0, _0814F094\n\t"
        "	ldrh r0, [r0]\n\t"
        "	mov r1, sp\n\t"
        "	bl CopyItemName\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F094: .4byte 0x02023EAC\n\t"
        "_0814F098:\n\t"
        "	ldr r0, _0814F09C\n\t"
        "	b _0814F0D8\n\t"
        "	.align 2, 0\n\t"
        "_0814F09C: .4byte 0x02023EAE\n\t"
        "_0814F0A0:\n\t"
        "	ldr r1, _0814F0A8\n\t"
        "	ldr r0, _0814F0AC\n\t"
        "	b _0814F0D4\n\t"
        "	.align 2, 0\n\t"
        "_0814F0A8: .4byte 0x0203A870\n\t"
        "_0814F0AC: .4byte 0x02023EAF\n\t"
        "_0814F0B0:\n\t"
        "	ldr r1, _0814F0B8\n\t"
        "	ldr r0, _0814F0BC\n\t"
        "	b _0814F0D4\n\t"
        "	.align 2, 0\n\t"
        "_0814F0B8: .4byte 0x0203A870\n\t"
        "_0814F0BC: .4byte 0x02023EB0\n\t"
        "_0814F0C0:\n\t"
        "	ldr r1, _0814F0C8\n\t"
        "	ldr r0, _0814F0CC\n\t"
        "	ldrb r0, [r0, #0x17]\n\t"
        "	b _0814F0D6\n\t"
        "	.align 2, 0\n\t"
        "_0814F0C8: .4byte 0x0203A870\n\t"
        "_0814F0CC: .4byte 0x02024118\n\t"
        "_0814F0D0:\n\t"
        "	ldr r1, _0814F0E4\n\t"
        "	ldr r0, _0814F0E8\n\t"
        "_0814F0D4:\n\t"
        "	ldrb r0, [r0]\n\t"
        "_0814F0D6:\n\t"
        "	adds r0, r0, r1\n\t"
        "_0814F0D8:\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0814F0EC\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F0E4: .4byte 0x0203A870\n\t"
        "_0814F0E8: .4byte 0x02023EB2\n\t"
        "_0814F0EC: .4byte 0x082EBDC4\n\t"
        "_0814F0F0:\n\t"
        "	ldr r0, _0814F104\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x14\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F108\n\t"
        "	bl GetSecretBaseTrainerPicIndex\n\t"
        "	b _0814F5B8\n\t"
        "	.align 2, 0\n\t"
        "_0814F104: .4byte 0x02022C90\n\t"
        "_0814F108:\n\t"
        "	ldr r3, _0814F120\n\t"
        "	ldrh r2, [r3]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814F124\n\t"
        "	bl sub_080686F0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	b _0814F5BC\n\t"
        "	.align 2, 0\n\t"
        "_0814F120: .4byte 0x0203886A\n\t"
        "_0814F124:\n\t"
        "	ldr r0, _0814F130\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814F134\n\t"
        "	bl sub_081A48F8\n\t"
        "	b _0814F5B8\n\t"
        "	.align 2, 0\n\t"
        "_0814F130: .4byte 0x000003FE\n\t"
        "_0814F134:\n\t"
        "	ldr r0, _0814F140\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F144\n\t"
        "	ldrh r0, [r3]\n\t"
        "	b _0814F5B4\n\t"
        "	.align 2, 0\n\t"
        "_0814F140: .4byte 0x003F0100\n\t"
        "_0814F144:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F156\n\t"
        "	ldrh r0, [r3]\n\t"
        "	bl GetTrainerHillOpponentClass\n\t"
        "	b _0814F5B8\n\t"
        "_0814F156:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F166\n\t"
        "	bl GetEreaderTrainerClassId\n\t"
        "	b _0814F5B8\n\t"
        "_0814F166:\n\t"
        "	ldr r1, _0814F174\n\t"
        "	ldrh r0, [r3]\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	movs r0, #0xb\n\t"
        "	b _0814F5BE\n\t"
        "	.align 2, 0\n\t"
        "_0814F174: .4byte 0x082E383C\n\t"
        "_0814F178:\n\t"
        "	ldr r0, _0814F1AC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x14\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F1B4\n\t"
        "	movs r3, #0\n\t"
        "	ldr r0, _0814F1B0\n\t"
        "	ldr r2, [r0]\n\t"
        "_0814F18C:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r1, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r3, #1\n\t"
        "	cmp r3, #6\n\t"
        "	ble _0814F18C\n\t"
        "	mov r2, sp\n\t"
        "	adds r1, r2, r3\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F1AC: .4byte 0x02022C90\n\t"
        "_0814F1B0: .4byte 0x0202414C\n\t"
        "_0814F1B4:\n\t"
        "	ldr r3, _0814F1EC\n\t"
        "	ldrh r2, [r3]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814F1F4\n\t"
        "	movs r3, #0\n\t"
        "	ldr r2, _0814F1F0\n\t"
        "	movs r1, #1\n\t"
        "	adds r0, r7, #0\n\t"
        "	eors r0, r1\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r2, #8\n\t"
        "	adds r2, r1, r2\n\t"
        "_0814F1D4:\n\t"
        "	mov r5, sp\n\t"
        "	adds r1, r5, r3\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r2, #1\n\t"
        "	adds r3, #1\n\t"
        "	cmp r3, #6\n\t"
        "	ble _0814F1D4\n\t"
        "	adds r1, r5, r3\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F1EC: .4byte 0x0203886A\n\t"
        "_0814F1F0: .4byte 0x020226A0\n\t"
        "_0814F1F4:\n\t"
        "	ldr r0, _0814F204\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814F208\n\t"
        "	mov r0, sp\n\t"
        "	bl CopyFrontierBrainTrainerName\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F204: .4byte 0x000003FE\n\t"
        "_0814F208:\n\t"
        "	ldr r0, _0814F214\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F218\n\t"
        "	ldrh r1, [r3]\n\t"
        "	b _0814F5D4\n\t"
        "	.align 2, 0\n\t"
        "_0814F214: .4byte 0x003F0100\n\t"
        "_0814F218:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F22C\n\t"
        "	ldrh r1, [r3]\n\t"
        "	mov r0, sp\n\t"
        "	bl GetTrainerHillTrainerName\n\t"
        "	b _0814F5DA\n\t"
        "_0814F22C:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F23E\n\t"
        "	mov r0, sp\n\t"
        "	bl GetEreaderTrainerName\n\t"
        "	b _0814F5DA\n\t"
        "_0814F23E:\n\t"
        "	ldrh r0, [r3]\n\t"
        "	b _0814F514\n\t"
        "_0814F242:\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0814F250\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F250: .4byte 0x020226A8\n\t"
        "_0814F254:\n\t"
        "	ldr r4, _0814F264\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #2\n\t"
        "	b _0814F28A\n\t"
        "	.align 2, 0\n\t"
        "_0814F264: .4byte 0x020226A0\n\t"
        "_0814F268:\n\t"
        "	ldr r4, _0814F278\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #1\n\t"
        "	b _0814F28A\n\t"
        "	.align 2, 0\n\t"
        "_0814F278: .4byte 0x020226A0\n\t"
        "_0814F27C:\n\t"
        "	ldr r4, _0814F29C\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r0, #3\n\t"
        "_0814F28A:\n\t"
        "	eors r0, r1\n\t"
        "	bl GetBattlerMultiplayerId\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r4, #8\n\t"
        "	adds r4, r1, r4\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F29C: .4byte 0x020226A0\n\t"
        "_0814F2A0:\n\t"
        "	ldr r0, _0814F2B4\n\t"
        "	ldrb r0, [r0, #0x17]\n\t"
        "	bl GetBattlerMultiplayerId\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0814F2B8\n\t"
        "	adds r4, r1, r0\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F2B4: .4byte 0x02024118\n\t"
        "_0814F2B8: .4byte 0x020226A8\n\t"
        "_0814F2BC:\n\t"
        "	ldr r0, _0814F2D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0x11\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F2D8\n\t"
        "	ldr r4, _0814F2D4\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F2D0: .4byte 0x02022C90\n\t"
        "_0814F2D4: .4byte 0x020226A8\n\t"
        "_0814F2D8:\n\t"
        "	ldr r0, _0814F2E0\n\t"
        "	ldr r4, [r0]\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F2E0: .4byte 0x03005AF0\n\t"
        "_0814F2E4:\n\t"
        "	ldr r0, _0814F2F8\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F2FC\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F304\n\t"
        "	ldr r0, _0814F300\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	b _0814F576\n\t"
        "	.align 2, 0\n\t"
        "_0814F2F8: .4byte 0x02022C90\n\t"
        "_0814F2FC: .4byte 0x003F0100\n\t"
        "_0814F300: .4byte 0x0203886A\n\t"
        "_0814F304:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F31C\n\t"
        "	ldr r0, _0814F318\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #4\n\t"
        "	b _0814F5A0\n\t"
        "	.align 2, 0\n\t"
        "_0814F318: .4byte 0x0203886A\n\t"
        "_0814F31C:\n\t"
        "	bl GetTrainerALoseText\n\t"
        "	adds r4, r0, #0\n\t"
        "	b _0814F5DC\n\t"
        "_0814F324:\n\t"
        "	ldr r0, _0814F334\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F338\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F340\n\t"
        "	ldr r0, _0814F33C\n\t"
        "	b _0814F572\n\t"
        "	.align 2, 0\n\t"
        "_0814F334: .4byte 0x02022C90\n\t"
        "_0814F338: .4byte 0x003F0100\n\t"
        "_0814F33C: .4byte 0x0203886A\n\t"
        "_0814F340:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0814F34C\n\t"
        "	b _0814F5DC\n\t"
        "_0814F34C:\n\t"
        "	ldr r0, _0814F350\n\t"
        "	b _0814F59C\n\t"
        "	.align 2, 0\n\t"
        "_0814F350: .4byte 0x0203886A\n\t"
        "_0814F354:\n\t"
        "	ldr r0, _0814F3A8\n\t"
        "	ldrb r0, [r0, #0x17]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F3C0\n\t"
        "	ldr r0, _0814F3AC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r1, r0\n\t"
        "	ldr r4, _0814F3B0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F372\n\t"
        "	ldr r4, _0814F3B4\n\t"
        "_0814F372:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r2, _0814F3B8\n\t"
        "	mov ip, r2\n\t"
        "	ldr r2, _0814F3BC\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814F392\n\t"
        "_0814F380:\n\t"
        "	mov r3, r8\n\t"
        "	adds r0, r3, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814F380\n\t"
        "_0814F392:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x52\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	add r0, ip\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814F3D8\n\t"
        "	.align 2, 0\n\t"
        "_0814F3A8: .4byte 0x02024118\n\t"
        "_0814F3AC: .4byte 0x02022C90\n\t"
        "_0814F3B0: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814F3B4: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814F3B8: .4byte 0x020243E8\n\t"
        "_0814F3BC: .4byte 0x02024140\n\t"
        "_0814F3C0:\n\t"
        "	ldr r0, _0814F3E0\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x52\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814F3E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814F3D8:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F3E0: .4byte 0x02024140\n\t"
        "_0814F3E4: .4byte 0x02024190\n\t"
        "_0814F3E8:\n\t"
        "	ldr r0, _0814F3FC\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r4, _0814F400\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814F3F8\n\t"
        "	b _0814F5DC\n\t"
        "_0814F3F8:\n\t"
        "	ldr r4, _0814F404\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F3FC: .4byte 0x000008AB\n\t"
        "_0814F400: .4byte sText_Someones\n\t"
        "_0814F404: .4byte sText_Lanettes\n\t"
        "_0814F408:\n\t"
        "	ldr r0, _0814F40C\n\t"
        "	b _0814F412\n\t"
        "	.align 2, 0\n\t"
        "_0814F40C: .4byte 0x02023EAF\n\t"
        "_0814F410:\n\t"
        "	ldr r0, _0814F428\n\t"
        "_0814F412:\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r4, _0814F42C\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F422\n\t"
        "	b _0814F5DC\n\t"
        "_0814F422:\n\t"
        "	ldr r4, _0814F430\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F428: .4byte 0x02023EB0\n\t"
        "_0814F42C: .4byte gUnknown_85A9544 + 0x1ADC\n\t"
        "_0814F430: .4byte gUnknown_85A9544 + 0x1AE1\n\t"
        "_0814F434:\n\t"
        "	ldr r0, _0814F438\n\t"
        "	b _0814F43E\n\t"
        "	.align 2, 0\n\t"
        "_0814F438: .4byte 0x02023EAF\n\t"
        "_0814F43C:\n\t"
        "	ldr r0, _0814F454\n\t"
        "_0814F43E:\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r4, _0814F458\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F44E\n\t"
        "	b _0814F5DC\n\t"
        "_0814F44E:\n\t"
        "	ldr r4, _0814F45C\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F454: .4byte 0x02023EB0\n\t"
        "_0814F458: .4byte gUnknown_85A9544 + 0x1AD2\n\t"
        "_0814F45C: .4byte gUnknown_85A9544 + 0x1AD7\n\t"
        "_0814F460:\n\t"
        "	ldr r0, _0814F464\n\t"
        "	b _0814F46A\n\t"
        "	.align 2, 0\n\t"
        "_0814F464: .4byte 0x02023EAF\n\t"
        "_0814F468:\n\t"
        "	ldr r0, _0814F480\n\t"
        "_0814F46A:\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r4, _0814F484\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F47A\n\t"
        "	b _0814F5DC\n\t"
        "_0814F47A:\n\t"
        "	ldr r4, _0814F488\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F480: .4byte 0x02023EB0\n\t"
        "_0814F484: .4byte gUnknown_85A9544 + 0x1AE6\n\t"
        "_0814F488: .4byte gUnknown_85A9544 + 0x1AEB\n\t"
        "_0814F48C:\n\t"
        "	ldr r0, _0814F49C\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F4A0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F4A8\n\t"
        "	ldr r0, _0814F4A4\n\t"
        "	b _0814F5B2\n\t"
        "	.align 2, 0\n\t"
        "_0814F49C: .4byte 0x02022C90\n\t"
        "_0814F4A0: .4byte 0x003F0100\n\t"
        "_0814F4A4: .4byte 0x0203886C\n\t"
        "_0814F4A8:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F4C0\n\t"
        "	ldr r0, _0814F4BC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl GetTrainerHillOpponentClass\n\t"
        "	b _0814F5B8\n\t"
        "	.align 2, 0\n\t"
        "_0814F4BC: .4byte 0x0203886C\n\t"
        "_0814F4C0:\n\t"
        "	ldr r1, _0814F4D0\n\t"
        "	ldr r0, _0814F4D4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	movs r0, #0xb\n\t"
        "	b _0814F5BE\n\t"
        "	.align 2, 0\n\t"
        "_0814F4D0: .4byte 0x082E383C\n\t"
        "_0814F4D4: .4byte 0x0203886C\n\t"
        "_0814F4D8:\n\t"
        "	ldr r0, _0814F4E8\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F4EC\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F4F4\n\t"
        "	ldr r0, _0814F4F0\n\t"
        "	b _0814F5D2\n\t"
        "	.align 2, 0\n\t"
        "_0814F4E8: .4byte 0x02022C90\n\t"
        "_0814F4EC: .4byte 0x003F0100\n\t"
        "_0814F4F0: .4byte 0x0203886C\n\t"
        "_0814F4F4:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F510\n\t"
        "	ldr r0, _0814F50C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	mov r0, sp\n\t"
        "	bl GetTrainerHillTrainerName\n\t"
        "	b _0814F5DA\n\t"
        "	.align 2, 0\n\t"
        "_0814F50C: .4byte 0x0203886C\n\t"
        "_0814F510:\n\t"
        "	ldr r0, _0814F51C\n\t"
        "	ldrh r0, [r0]\n\t"
        "_0814F514:\n\t"
        "	lsls r0, r0, #5\n\t"
        "	ldr r1, _0814F520\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F51C: .4byte 0x0203886C\n\t"
        "_0814F520: .4byte 0x082E3840\n\t"
        "_0814F524:\n\t"
        "	ldr r0, _0814F538\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F53C\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F544\n\t"
        "	ldr r0, _0814F540\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	b _0814F576\n\t"
        "	.align 2, 0\n\t"
        "_0814F538: .4byte 0x02022C90\n\t"
        "_0814F53C: .4byte 0x003F0100\n\t"
        "_0814F540: .4byte 0x0203886C\n\t"
        "_0814F544:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F55C\n\t"
        "	ldr r0, _0814F558\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #4\n\t"
        "	b _0814F5A0\n\t"
        "	.align 2, 0\n\t"
        "_0814F558: .4byte 0x0203886C\n\t"
        "_0814F55C:\n\t"
        "	bl GetTrainerBLoseText\n\t"
        "	adds r4, r0, #0\n\t"
        "	b _0814F5DC\n\t"
        "_0814F564:\n\t"
        "	ldr r0, _0814F580\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0814F584\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F590\n\t"
        "	ldr r0, _0814F588\n\t"
        "_0814F572:\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "_0814F576:\n\t"
        "	bl CopyFrontierTrainerText\n\t"
        "	ldr r4, _0814F58C\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F580: .4byte 0x02022C90\n\t"
        "_0814F584: .4byte 0x003F0100\n\t"
        "_0814F588: .4byte 0x0203886C\n\t"
        "_0814F58C: .4byte 0x02021C7C\n\t"
        "_0814F590:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814F5DC\n\t"
        "	ldr r0, _0814F5A8\n\t"
        "_0814F59C:\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #3\n\t"
        "_0814F5A0:\n\t"
        "	bl CopyTrainerHillTrainerText\n\t"
        "	ldr r4, _0814F5AC\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F5A8: .4byte 0x0203886C\n\t"
        "_0814F5AC: .4byte 0x02021C7C\n\t"
        "_0814F5B0:\n\t"
        "	ldr r0, _0814F5C8\n\t"
        "_0814F5B2:\n\t"
        "	ldrh r0, [r0]\n\t"
        "_0814F5B4:\n\t"
        "	bl GetFrontierOpponentClass\n\t"
        "_0814F5B8:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_0814F5BC:\n\t"
        "	movs r1, #0xb\n\t"
        "_0814F5BE:\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0814F5CC\n\t"
        "	adds r4, r1, r0\n\t"
        "	b _0814F5DC\n\t"
        "	.align 2, 0\n\t"
        "_0814F5C8: .4byte 0x0203886E\n\t"
        "_0814F5CC: .4byte 0x082E3564\n\t"
        "_0814F5D0:\n\t"
        "	ldr r0, _0814F628\n\t"
        "_0814F5D2:\n\t"
        "	ldrh r1, [r0]\n\t"
        "_0814F5D4:\n\t"
        "	mov r0, sp\n\t"
        "	bl GetFrontierTrainerName\n\t"
        "_0814F5DA:\n\t"
        "	mov r4, sp\n\t"
        "_0814F5DC:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	mov r5, sb\n\t"
        "	ldrb r2, [r5]\n\t"
        "	mov r3, sb\n\t"
        "	adds r3, #1\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814F5FE\n\t"
        "_0814F5EC:\n\t"
        "	mov r5, r8\n\t"
        "	adds r0, r5, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814F5EC\n\t"
        "_0814F5FE:\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x24\n\t"
        "	beq _0814F612\n\t"
        "	cmp r0, #0x30\n\t"
        "	beq _0814F612\n\t"
        "	cmp r0, #0x25\n\t"
        "	beq _0814F612\n\t"
        "	cmp r0, #0x31\n\t"
        "	bne _0814F638\n\t"
        "_0814F612:\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r0, r6\n\t"
        "	movs r0, #0xfc\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r6, #1\n\t"
        "	mov r2, r8\n\t"
        "	adds r1, r2, r6\n\t"
        "	movs r0, #9\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r6, #1\n\t"
        "	b _0814F638\n\t"
        "	.align 2, 0\n\t"
        "_0814F628: .4byte 0x0203886E\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	mov r3, r8\n\t"
        "	adds r0, r3, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r6, #1\n\t"
        "	mov r3, sb\n\t"
        "	adds r3, #1\n\t"
        "_0814F638:\n\t"
        "	mov sb, r3\n\t"
        "	ldrb r1, [r3]\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) void sub_0814F63C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814F646\n\t"
        "	bl BattleStringExpandPlaceholders\n\t"
        "_0814F646:\n\t"
        "	mov r5, r8\n\t"
        "	adds r1, r5, r6\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r6, #1\n\t"
        "	adds r0, r6, #0\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail"))) void ExpandBattleTextBuffPlaceholders(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r7, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	movs r5, #1\n\t"
        "	movs r0, #0\n\t"
        "	mov r8, r0\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r6]\n\t"
        "	ldrb r0, [r7, #1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0814F682\n\t"
        "	b _0814F902\n\t"
        "_0814F682:\n\t"
        "	adds r0, r7, r5\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r1, #0xa\n\t"
        "	bls _0814F68E\n\t"
        "	b _0814F8F8\n\t"
        "_0814F68E:\n\t"
        "	lsls r0, r1, #2\n\t"
        "	ldr r1, _0814F698\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0814F698: .4byte 0x0814F69C\n\t"
        "_0814F69C:\n\t"
        "	.4byte _0814F6C8\n\t"
        "	.4byte _0814F6E4\n\t"
        "	.4byte _0814F738\n\t"
        "	.4byte _0814F750\n\t"
        "	.4byte _0814F760\n\t"
        "	.4byte _0814F7D8\n\t"
        "	.4byte _0814F7EC\n\t"
        "	.4byte _0814F7FE\n\t"
        "	.4byte _0814F844\n\t"
        "	.4byte _0814F858\n\t"
        "	.4byte _0814F870\n\t"
        "_0814F6C8:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r1, r0\n\t"
        "	ldr r0, _0814F6E0\n\t"
        "	subs r1, #0xc\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r1, [r1]\n\t"
        "	b _0814F8D6\n\t"
        "	.align 2, 0\n\t"
        "_0814F6E0: .4byte gBattleStringsTable\n\t"
        "_0814F6E4:\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0814F700\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0814F6F4\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0814F6FA\n\t"
        "	b _0814F722\n\t"
        "_0814F6F4:\n\t"
        "	cmp r0, #4\n\t"
        "	beq _0814F708\n\t"
        "	b _0814F722\n\t"
        "_0814F6FA:\n\t"
        "	ldrb r4, [r4, #3]\n\t"
        "	mov r8, r4\n\t"
        "	b _0814F722\n\t"
        "_0814F700:\n\t"
        "	ldrb r1, [r4, #3]\n\t"
        "	ldrb r0, [r4, #4]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	b _0814F71E\n\t"
        "_0814F708:\n\t"
        "	ldrb r0, [r4, #3]\n\t"
        "	mov r8, r0\n\t"
        "	ldrb r0, [r4, #4]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	mov r1, r8\n\t"
        "	orrs r1, r0\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	orrs r1, r0\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "_0814F71E:\n\t"
        "	orrs r1, r0\n\t"
        "	mov r8, r1\n\t"
        "_0814F722:\n\t"
        "	adds r4, r5, r7\n\t"
        "	ldrb r3, [r4, #2]\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, r8\n\t"
        "	movs r2, #0\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	adds r0, r5, #3\n\t"
        "	ldrb r4, [r4, #1]\n\t"
        "	adds r5, r0, r4\n\t"
        "	b _0814F8F8\n\t"
        "_0814F738:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _0814F74C\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _0814F8D6\n\t"
        "	.align 2, 0\n\t"
        "_0814F74C: .4byte 0x082EACC4\n\t"
        "_0814F750:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0814F75C\n\t"
        "	b _0814F860\n\t"
        "	.align 2, 0\n\t"
        "_0814F75C: .4byte 0x082EBC88\n\t"
        "_0814F760:\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814F784\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814F780\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814F7C0\n\t"
        "	.align 2, 0\n\t"
        "_0814F780: .4byte 0x02024190\n\t"
        "_0814F784:\n\t"
        "	ldr r0, _0814F79C\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F7A4\n\t"
        "	ldr r1, _0814F7A0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringAppend\n\t"
        "	b _0814F7AC\n\t"
        "	.align 2, 0\n\t"
        "_0814F79C: .4byte 0x02022C90\n\t"
        "_0814F7A0: .4byte gUnknown_85A9544 + 0x1ACB\n\t"
        "_0814F7A4:\n\t"
        "	ldr r1, _0814F7D0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringAppend\n\t"
        "_0814F7AC:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814F7D4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	mov r2, sp\n\t"
        "	bl GetMonData3\n\t"
        "_0814F7C0:\n\t"
        "	mov r0, sp\n\t"
        "	bl StringGet_Nickname\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl StringAppend\n\t"
        "	b _0814F8F6\n\t"
        "	.align 2, 0\n\t"
        "_0814F7D0: .4byte gUnknown_85A9544 + 0x1AC5\n\t"
        "_0814F7D4: .4byte 0x020243E8\n\t"
        "_0814F7D8:\n\t"
        "	ldr r1, _0814F7E8\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	b _0814F862\n\t"
        "	.align 2, 0\n\t"
        "_0814F7E8: .4byte gStatNamesTable\n\t"
        "_0814F7EC:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r1, r0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetSpeciesName\n\t"
        "	b _0814F8F6\n\t"
        "_0814F7FE:\n\t"
        "	adds r4, r5, r7\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0814F824\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814F820\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl GetMonData3\n\t"
        "	b _0814F836\n\t"
        "	.align 2, 0\n\t"
        "_0814F820: .4byte 0x02024190\n\t"
        "_0814F824:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0814F840\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl GetMonData3\n\t"
        "_0814F836:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringGet_Nickname\n\t"
        "	b _0814F8F6\n\t"
        "	.align 2, 0\n\t"
        "_0814F840: .4byte 0x020243E8\n\t"
        "_0814F844:\n\t"
        "	ldr r1, _0814F854\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	b _0814F862\n\t"
        "	.align 2, 0\n\t"
        "_0814F854: .4byte gPokeblockWasTooXStringTable\n\t"
        "_0814F858:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _0814F86C\n\t"
        "_0814F860:\n\t"
        "	adds r1, r1, r0\n\t"
        "_0814F862:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringAppend\n\t"
        "	adds r5, #2\n\t"
        "	b _0814F8F8\n\t"
        "	.align 2, 0\n\t"
        "_0814F86C: .4byte 0x082EBDC4\n\t"
        "_0814F870:\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r2, [r0, #1]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r2, r0\n\t"
        "	ldr r0, _0814F8B8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0814F8BC\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814F8EE\n\t"
        "	cmp r2, #0xaf\n\t"
        "	bne _0814F8E4\n\t"
        "	ldr r2, _0814F8C0\n\t"
        "	ldr r0, _0814F8C4\n\t"
        "	adds r0, #0x25\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _0814F8C8\n\t"
        "	ldrb r2, [r1]\n\t"
        "	ldrh r0, [r0, #0x18]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _0814F8D4\n\t"
        "	lsls r1, r2, #3\n\t"
        "	subs r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0814F8CC\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _0814F8D0\n\t"
        "	b _0814F8D6\n\t"
        "	.align 2, 0\n\t"
        "_0814F8B8: .4byte 0x02022C90\n\t"
        "_0814F8BC: .4byte 0x02000002\n\t"
        "_0814F8C0: .4byte 0x020226A0\n\t"
        "_0814F8C4: .4byte 0x02024118\n\t"
        "_0814F8C8: .4byte 0x02023EB3\n\t"
        "_0814F8CC: .4byte 0x020240A8\n\t"
        "_0814F8D0: .4byte sText_BerrySuffix\n\t"
        "_0814F8D4:\n\t"
        "	ldr r1, _0814F8E0\n\t"
        "_0814F8D6:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StringAppend\n\t"
        "	b _0814F8F6\n\t"
        "	.align 2, 0\n\t"
        "_0814F8E0: .4byte sText_EnigmaBerry\n\t"
        "_0814F8E4:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl CopyItemName\n\t"
        "	b _0814F8F6\n\t"
        "_0814F8EE:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl CopyItemName\n\t"
        "_0814F8F6:\n\t"
        "	adds r5, #3\n\t"
        "_0814F8F8:\n\t"
        "	adds r0, r7, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0814F902\n\t"
        "	b _0814F682\n\t"
        "_0814F902:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail2"))) void sub_0814FA04(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	ldr r1, _0814FA30\n\t"
        "	ldr r0, _0814FA34\n\t"
        "	adds r0, #0x24\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov r8, r0\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814FA38\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r7, r0\n\t"
        "	b _0814FA56\n\t"
        "	.align 2, 0\n\t"
        "_0814FA30: .4byte sBattleTextOnWindowsInfo\n\t"
        "_0814FA34: .4byte 0x02024118\n\t"
        "_0814FA38:\n\t"
        "	lsls r0, r7, #1\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "_0814FA56:\n\t"
        "	str r4, [sp]\n\t"
        "	mov r0, sp\n\t"
        "	strb r7, [r0, #4]\n\t"
        "	mov r1, sp\n\t"
        "	lsls r6, r7, #1\n\t"
        "	adds r3, r6, r7\n\t"
        "	lsls r3, r3, #2\n\t"
        "	add r3, r8\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldrb r0, [r3, #2]\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	ldrb r0, [r3, #3]\n\t"
        "	strb r0, [r1, #7]\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	strb r0, [r1, #8]\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	strb r0, [r1, #9]\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	strb r0, [r1, #0xa]\n\t"
        "	ldrb r0, [r3, #5]\n\t"
        "	strb r0, [r1, #0xb]\n\t"
        "	mov r4, sp\n\t"
        "	ldrb r2, [r4, #0xc]\n\t"
        "	movs r1, #0x10\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r4, #0xc]\n\t"
        "	mov r2, sp\n\t"
        "	ldrb r0, [r3, #7]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	movs r5, #0xf\n\t"
        "	strb r0, [r2, #0xc]\n\t"
        "	ldrb r2, [r3, #8]\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r2\n\t"
        "	ldrb r2, [r4, #0xd]\n\t"
        "	ands r1, r2\n\t"
        "	orrs r1, r0\n\t"
        "	strb r1, [r4, #0xd]\n\t"
        "	mov r2, sp\n\t"
        "	ldrb r0, [r3, #9]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ands r1, r5\n\t"
        "	orrs r1, r0\n\t"
        "	strb r1, [r2, #0xd]\n\t"
        "	cmp r7, #0x16\n\t"
        "	bne _0814FACC\n\t"
        "	ldr r0, _0814FAC8\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #3\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	b _0814FAD4\n\t"
        "	.align 2, 0\n\t"
        "_0814FAC8: .4byte 0x030030B4\n\t"
        "_0814FACC:\n\t"
        "	ldr r0, _0814FAF0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r1, r2\n\t"
        "_0814FAD4:\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r3, r0, #0\n\t"
        "	ldr r0, _0814FAF4\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r2, _0814FAF8\n\t"
        "	ands r1, r2\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814FAFC\n\t"
        "	ldrb r0, [r3]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	b _0814FB04\n\t"
        "	.align 2, 0\n\t"
        "_0814FAF0: .4byte 0x030030B4\n\t"
        "_0814FAF4: .4byte 0x02022C90\n\t"
        "_0814FAF8: .4byte 0x01000002\n\t"
        "_0814FAFC:\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "_0814FB04:\n\t"
        "	strb r0, [r3]\n\t"
        "	cmp r7, #0\n\t"
        "	beq _0814FB0E\n\t"
        "	cmp r7, #0x16\n\t"
        "	bne _0814FB58\n\t"
        "_0814FB0E:\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldr r0, _0814FB1C\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814FB20\n\t"
        "	movs r6, #1\n\t"
        "	b _0814FB48\n\t"
        "	.align 2, 0\n\t"
        "_0814FB1C: .4byte 0x02000002\n\t"
        "_0814FB20:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814FB40\n\t"
        "	ldr r4, _0814FB3C\n\t"
        "	bl GetBattleSceneInRecordedBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r6, [r0]\n\t"
        "	b _0814FB48\n\t"
        "	.align 2, 0\n\t"
        "_0814FB3C: .4byte sRecordedBattleTextSpeeds\n\t"
        "_0814FB40:\n\t"
        "	bl GetPlayerTextSpeedDelay\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "_0814FB48:\n\t"
        "	ldr r0, _0814FB54\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #1\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0814FB6A\n\t"
        "	.align 2, 0\n\t"
        "_0814FB54: .4byte 0x030030B4\n\t"
        "_0814FB58:\n\t"
        "	adds r0, r6, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	ldrb r6, [r0, #6]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "_0814FB6A:\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl AddTextPrinter\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail2"))) void SetPpNumbersPaletteInMoveSelection(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _0814FBE0\n\t"
        "	ldrb r2, [r0]\n\t"
        "	lsls r1, r2, #9\n\t"
        "	ldr r0, _0814FBE4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0814FBE8\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl GetCurrentPpToMaxPpState\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r5, _0814FBEC\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	ldr r2, _0814FBF0\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrh r1, [r1]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0xb8\n\t"
        "	strh r1, [r2]\n\t"
        "	ldr r1, _0814FBF4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	adds r5, #0xb6\n\t"
        "	strh r0, [r5]\n\t"
        "	ldr r4, _0814FBF8\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl CpuSet\n\t"
        "	subs r4, #2\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl CpuSet\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814FBE0: .4byte 0x02023D08\n\t"
        "_0814FBE4: .4byte 0x02022D0C\n\t"
        "_0814FBE8: .4byte 0x02024154\n\t"
        "_0814FBEC: .4byte 0x020373B4\n\t"
        "_0814FBF0: .4byte gUnknown_8D85604\n\t"
        "_0814FBF4: .4byte gUnknown_8D85606\n\t"
        "_0814FBF8: .4byte 0x0203786C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.battle_message_tail2"))) void GetCurrentPpToMaxPpState(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r3, r2, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r0, r1, #0x18\n\t"
        "	cmp r0, r2\n\t"
        "	beq _0814FC44\n\t"
        "	cmp r0, #2\n\t"
        "	bhi _0814FC16\n\t"
        "	cmp r2, #1\n\t"
        "	bhi _0814FC44\n\t"
        "	b _0814FC1E\n\t"
        "_0814FC16:\n\t"
        "	cmp r0, #7\n\t"
        "	bhi _0814FC28\n\t"
        "	cmp r2, #2\n\t"
        "	bhi _0814FC44\n\t"
        "_0814FC1E:\n\t"
        "	movs r0, #2\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0814FC46\n\t"
        "_0814FC28:\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0814FC30\n\t"
        "	movs r0, #2\n\t"
        "	b _0814FC46\n\t"
        "_0814FC30:\n\t"
        "	lsrs r0, r1, #0x1a\n\t"
        "	cmp r2, r0\n\t"
        "	bhi _0814FC3A\n\t"
        "	movs r0, #1\n\t"
        "	b _0814FC46\n\t"
        "_0814FC3A:\n\t"
        "	lsrs r0, r1, #0x19\n\t"
        "	cmp r3, r0\n\t"
        "	bhi _0814FC44\n\t"
        "	movs r0, #0\n\t"
        "	b _0814FC46\n\t"
        "_0814FC44:\n\t"
        "	movs r0, #3\n\t"
        "_0814FC46:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}
