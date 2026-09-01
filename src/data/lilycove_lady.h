#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/moves.h"

#define LILYCOVE_LADY_DATA __attribute__((section(".rodata.lilycove_lady_data")))

static const u16 sContestLadyMonGfxId[] LILYCOVE_LADY_DATA =
{
    [CONTEST_CATEGORY_COOL]   = OBJ_EVENT_GFX_ZIGZAGOON_1,
    [CONTEST_CATEGORY_BEAUTY] = OBJ_EVENT_GFX_SKITTY,
    [CONTEST_CATEGORY_CUTE]   = OBJ_EVENT_GFX_POOCHYENA,
    [CONTEST_CATEGORY_SMART]  = OBJ_EVENT_GFX_KECLEON,
    [CONTEST_CATEGORY_TOUGH]  = OBJ_EVENT_GFX_PIKACHU
};

static const u16 sLilycoveLadyGfxId[] LILYCOVE_LADY_DATA =
{
    OBJ_EVENT_GFX_WOMAN_4,
    OBJ_EVENT_GFX_WOMAN_2,
    OBJ_EVENT_GFX_GIRL_2
};

// Quiz Lady data
static const u16 sQuizLadyQuestion1[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_NO_1,
    EC_WORD_BIG,
    EC_WORD_POKEMON,
    EC_WORD_THAT_S,
    EC_WORD_NEAR,
    EC_WORD_QUES,
    EC_POKEMON_NATIONAL(RHYDON),
    EC_POKEMON_NATIONAL(SLUGMA),
    EC_POKEMON(WAILORD)
};

static const u16 sQuizLadyQuestion2[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_POKEMON(SWALOT),
    EC_WORD_THAT_S,
    EC_WORD_WHEN,
    EC_WORD_POKEMON,
    EC_WORD_FROM,
    EC_WORD_EVOLVE,
    EC_WORD_SLIDE,
    EC_WORD_QUES,
    EC_EMPTY_WORD
};

static const u16 sQuizLadyQuestion3[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_LINK,
    EC_WORD_EVOLVE,
    EC_WORD_SLIDE,
    EC_WORD_POKEMON,
    EC_WORD_NEAR,
    EC_WORD_QUES,
    EC_POKEMON(LAIRON),
    EC_POKEMON_NATIONAL(MACHOKE),
    EC_POKEMON(VIGOROTH)
};

static const u16 sQuizLadyQuestion4[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_LEFT,
    EC_WORD_WENT,
    EC_WORD_AS_MUCH_AS,
    EC_WORD_EXPENSIVE,
    EC_WORD_DIDN_T,
    EC_WORD_THAT_S,
    EC_WORD_SHALLOW,
    EC_WORD_QUES,
    EC_EMPTY_WORD
};

static const u16 sQuizLadyQuestion5[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_SEES,
    EC_WORD_CASE,
    EC_WORD_COULDN_T,
    EC_WORD_BUT,
    EC_WORD_BIG,
    EC_WORD_SMALL,
    EC_WORD_THAT_S,
    EC_WORD_WHAT,
    EC_WORD_QUES,
};

static const u16 sQuizLadyQuestion6[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_MOVE(AGILITY),
    EC_WORD_TASTY,
    EC_WORD_PERSON,
    EC_WORD_OF,
    EC_WORD_WORK,
    EC_WORD_THAT_S,
    EC_WORD_WHEN,
    EC_WORD_WORK,
    EC_WORD_QUES
};

static const u16 sQuizLadyQuestion7[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_ABSENT,
    EC_WORD_AGE,
    EC_WORD_NEED,
    EC_WORD_NEED,
    EC_WORD_AGE,
    EC_WORD_ABSENT,
    EC_WORD_THAT_S,
    EC_WORD_SHALLOW,
    EC_WORD_QUES,
};

static const u16 sQuizLadyQuestion8[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_KEEN_EYE,
    EC_WORD_OF,
    EC_WORD_BROTHER,
    EC_WORD_OF,
    EC_WORD_LOOKS,
    EC_WORD_NEED,
    EC_WORD_TELEVISION,
    EC_WORD_THAT_S,
    EC_WORD_QUES,
};

static const u16 sQuizLadyQuestion9[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_WENT,
    EC_WORD_COME,
    EC_WORD_CHOICE,
    EC_WORD_EVEN_SO,
    EC_WORD_MYSELF,
    EC_WORD_WHEN_I_WIN,
    EC_WORD_FOR,
    EC_WORD_THAT_S,
    EC_WORD_QUES,
};

static const u16 sQuizLadyQuestion10[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_CONTEST,
    EC_WORD_JUDGE,
    EC_WORD_THAT_S,
    EC_WORD_WHEN,
    EC_WORD_PERSON,
    EC_WORD_QUES,
    EC_WORD_AUNT,
    EC_WORD_BROTHER,
    EC_WORD_GRANDFATHER
};

static const u16 sQuizLadyQuestion11[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_NO_1,
    EC_WORD_EXPENSIVE,
    EC_WORD_POKEMON,
    EC_WORD_THAT_S,
    EC_WORD_NEAR,
    EC_WORD_QUES,
    EC_POKEMON(TORCHIC),
    EC_POKEMON(TREECKO),
    EC_POKEMON(MUDKIP)
};

static const u16 sQuizLadyQuestion12[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_RUBY,
    EC_WORD_VERSION,
    EC_WORD_ONLY,
    EC_WORD_APPEAR,
    EC_WORD_POKEMON,
    EC_WORD_CHOICE,
    EC_WORD_QUES,
    EC_POKEMON(ZANGOOSE),
    EC_POKEMON(SEVIPER)
};

static const u16 sQuizLadyQuestion13[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_SAPPHIRE,
    EC_WORD_VERSION,
    EC_WORD_IS,
    EC_WORD_DISAPPEAR,
    EC_WORD_POKEMON,
    EC_WORD_CHOICE,
    EC_WORD_QUES,
    EC_POKEMON(LOTAD),
    EC_POKEMON(SEEDOT)
};

static const u16 sQuizLadyQuestion14[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_THEY_RE,
    EC_WORD_STEEL,
    EC_WORD_MATCH_UP,
    EC_WORD_GOOD,
    EC_WORD_OF,
    EC_WORD_CHOICE,
    EC_WORD_QUES,
    EC_WORD_ICE,
    EC_WORD_GROUND
};

static const u16 sQuizLadyQuestion15[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_WORD_SHE_IS,
    EC_WORD_DARK,
    EC_WORD_MATCH_UP,
    EC_WORD_BADLY,
    EC_WORD_OF,
    EC_WORD_CHOICE,
    EC_WORD_QUES,
    EC_WORD_PSYCHIC,
    EC_WORD_FIGHTING
};

static const u16 sQuizLadyQuestion16[QUIZ_QUESTION_LEN] LILYCOVE_LADY_DATA =
{
    EC_MOVE2(MUD_SPORT),
    EC_WORD_CAPABLE,
    EC_WORD_POKEMON,
    EC_WORD_NEAR,
    EC_WORD_WERE,
    EC_WORD_QUES,
    EC_POKEMON(CORPHISH),
    EC_POKEMON(TRAPINCH),
    EC_POKEMON_NATIONAL(SANDSHREW)
};

static const u16 *const sQuizLadyQuizQuestions[] LILYCOVE_LADY_DATA =
{
    sQuizLadyQuestion1,
    sQuizLadyQuestion2,
    sQuizLadyQuestion3,
    sQuizLadyQuestion4,
    sQuizLadyQuestion5,
    sQuizLadyQuestion6,
    sQuizLadyQuestion7,
    sQuizLadyQuestion8,
    sQuizLadyQuestion9,
    sQuizLadyQuestion10,
    sQuizLadyQuestion11,
    sQuizLadyQuestion12,
    sQuizLadyQuestion13,
    sQuizLadyQuestion14,
    sQuizLadyQuestion15,
    sQuizLadyQuestion16
};

static const u16 sQuizLadyQuizAnswers[] LILYCOVE_LADY_DATA =
{
    EC_POKEMON(WAILORD),
    EC_POKEMON(GULPIN),
    EC_POKEMON_NATIONAL(MACHOKE),
    EC_WORD_MONEY,
    EC_MOVE2(GROWL),
    EC_WORD_TEACHER,
    EC_WORD_STAY_AT_HOME,
    EC_WORD_ANIME,
    EC_WORD_TIME,
    EC_WORD_GRANDFATHER,
    EC_POKEMON(TREECKO),
    EC_POKEMON(ZANGOOSE),
    EC_POKEMON(SEEDOT),
    EC_WORD_ICE,
    EC_WORD_FIGHTING,
    EC_POKEMON(CORPHISH)
};

static const u16 sQuizLadyPrizes[] LILYCOVE_LADY_DATA =
{
    ITEM_GLITTER_MAIL,
    ITEM_BEAD_MAIL,
    ITEM_TROPIC_MAIL,
    ITEM_MAX_ETHER,
    ITEM_MAX_ETHER,
    ITEM_MAX_ETHER,
    ITEM_WATMEL_BERRY,
    ITEM_BELUE_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_LUXURY_BALL,
    ITEM_TM15,
    ITEM_BIG_PEARL,
    ITEM_STAR_PIECE,
    ITEM_RARE_CANDY,
    ITEM_RARE_CANDY,
    ITEM_PREMIER_BALL
};

const u8 gText_FavorLady_Slippery[] LILYCOVE_LADY_DATA = _("すべすべ");
const u8 gText_FavorLady_Roundish[] LILYCOVE_LADY_DATA = _("まるまる");
const u8 gText_FavorLady_Whamish[] LILYCOVE_LADY_DATA = _("バキバキ");
const u8 gText_FavorLady_Shiny[] LILYCOVE_LADY_DATA = _("ピカピカ");
const u8 gText_FavorLady_Sticky[] LILYCOVE_LADY_DATA = _("ねばねば");
const u8 gText_FavorLady_Pointy[] LILYCOVE_LADY_DATA = _("ちくちく");

// Favor Lady data
static const u8 *const sFavorLadyRequests[] LILYCOVE_LADY_DATA =
{
    gText_FavorLady_Slippery,
    gText_FavorLady_Roundish,
    gText_FavorLady_Whamish,
    gText_FavorLady_Shiny,
    gText_FavorLady_Sticky,
    gText_FavorLady_Pointy
};

static const u16 sFavorLadyAcceptedItems_Slippery[] LILYCOVE_LADY_DATA =
{
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_MAX_REPEL,
    ITEM_ANTIDOTE,
    ITEM_PARALYZE_HEAL,
    ITEM_BURN_HEAL,
    ITEM_BELUE_BERRY,
    ITEM_AWAKENING,
    ITEM_ICE_HEAL,
    ITEM_REVIVE,
    ITEM_MAX_REVIVE,
    ITEM_ENERGY_POWDER,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Roundish[] LILYCOVE_LADY_DATA =
{
    ITEM_FLUFFY_TAIL,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_HARD_STONE,
    ITEM_SMOKE_BALL,
    ITEM_SHOAL_SHELL,
    ITEM_TINY_MUSHROOM,
    ITEM_BIG_MUSHROOM,
    ITEM_PECHA_BERRY,
    ITEM_ASPEAR_BERRY,
    ITEM_ORAN_BERRY,
    ITEM_GREPA_BERRY,
    ITEM_MAGOST_BERRY,
    ITEM_WATMEL_BERRY,
    ITEM_POKE_BALL,
    ITEM_ULTRA_BALL,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Whamish[] LILYCOVE_LADY_DATA =
{
    ITEM_REVIVAL_HERB,
    ITEM_POTION,
    ITEM_FRESH_WATER,
    ITEM_SODA_POP,
    ITEM_LEMONADE,
    ITEM_HARD_STONE,
    ITEM_LIGHT_BALL,
    ITEM_LAVA_COOKIE,
    ITEM_CHESTO_BERRY,
    ITEM_NANAB_BERRY,
    ITEM_WEPEAR_BERRY,
    ITEM_KELPSY_BERRY,
    ITEM_NOMEL_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Shiny[] LILYCOVE_LADY_DATA =
{
    ITEM_HEAL_POWDER,
    ITEM_X_SPEED,
    ITEM_X_ATTACK,
    ITEM_X_DEFEND,
    ITEM_BLUE_FLUTE,
    ITEM_YELLOW_FLUTE,
    ITEM_RED_FLUTE,
    ITEM_BLACK_FLUTE,
    ITEM_WHITE_FLUTE,
    ITEM_NUGGET,
    ITEM_SUN_STONE,
    ITEM_STARDUST,
    ITEM_STAR_PIECE,
    ITEM_PEARL,
    ITEM_BIG_PEARL,
    ITEM_TWISTED_SPOON,
    ITEM_SILVER_POWDER,
    ITEM_BRIGHT_POWDER,
    ITEM_LUXURY_BALL,
    ITEM_PREMIER_BALL,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Sticky[] LILYCOVE_LADY_DATA =
{
    ITEM_ENERGY_ROOT,
    ITEM_FULL_RESTORE,
    ITEM_MAX_POTION,
    ITEM_DIRE_HIT,
    ITEM_X_ACCURACY,
    ITEM_GUARD_SPEC,
    ITEM_WATMEL_BERRY,
    ITEM_LEFTOVERS,
    ITEM_TINY_MUSHROOM,
    ITEM_HEART_SCALE,
    ITEM_NONE
};

static const u16 sFavorLadyAcceptedItems_Pointy[] LILYCOVE_LADY_DATA =
{
    ITEM_QUICK_CLAW,
    ITEM_POISON_BARB,
    ITEM_SHARP_BEAK,
    ITEM_DRAGON_FANG,
    ITEM_TAMATO_BERRY,
    ITEM_DURIN_BERRY,
    ITEM_PETAYA_BERRY,
    ITEM_SALAC_BERRY,
    ITEM_STARDUST,
    ITEM_STAR_PIECE,
    ITEM_NONE
};

static const u16 *const sFavorLadyAcceptedItemLists[] LILYCOVE_LADY_DATA =
{
    sFavorLadyAcceptedItems_Slippery,
    sFavorLadyAcceptedItems_Roundish,
    sFavorLadyAcceptedItems_Whamish,
    sFavorLadyAcceptedItems_Shiny,
    sFavorLadyAcceptedItems_Sticky,
    sFavorLadyAcceptedItems_Pointy
};

static const u16 sFavorLadyPrizes[] LILYCOVE_LADY_DATA =
{
    ITEM_LUXURY_BALL,
    ITEM_NUGGET,
    ITEM_PROTEIN,
    ITEM_HEART_SCALE,
    ITEM_RARE_CANDY,
    ITEM_PP_MAX
};

const u8 gText_QuizLady_Lady[] LILYCOVE_LADY_DATA = _("おねえ");
const u8 gText_ContestLady_Handsome[] LILYCOVE_LADY_DATA = _("ハンサム");
const u8 gText_ContestLady_Vinny[] LILYCOVE_LADY_DATA = _("ジョバンニ");
const u8 gText_ContestLady_Moreme[] LILYCOVE_LADY_DATA = _("もあもあ");
const u8 gText_ContestLady_Ironhard[] LILYCOVE_LADY_DATA = _("てつ");
const u8 gText_ContestLady_Muscle[] LILYCOVE_LADY_DATA = _("きんにくん");

static const u8 *const sContestLadyMonNames[] LILYCOVE_LADY_DATA =
{
    [CONTEST_CATEGORY_COOL]   = gText_ContestLady_Handsome,
    [CONTEST_CATEGORY_BEAUTY] = gText_ContestLady_Vinny,
    [CONTEST_CATEGORY_CUTE]   = gText_ContestLady_Moreme,
    [CONTEST_CATEGORY_SMART]  = gText_ContestLady_Ironhard,
    [CONTEST_CATEGORY_TOUGH]  = gText_ContestLady_Muscle
};

const u8 gText_ContestLady_Coolness[] LILYCOVE_LADY_DATA = _("かっこよ");
const u8 gText_ContestLady_Beauty[] LILYCOVE_LADY_DATA = _("うつくし");
const u8 gText_ContestLady_Cuteness[] LILYCOVE_LADY_DATA = _("かわい");
const u8 gText_ContestLady_Smartness[] LILYCOVE_LADY_DATA = _("かしこ");
const u8 gText_ContestLady_Toughness[] LILYCOVE_LADY_DATA = _("たくまし");

static const u8 *const sContestLadyCategoryNames[] LILYCOVE_LADY_DATA =
{
    [CONTEST_CATEGORY_COOL]   = gText_ContestLady_Coolness,
    [CONTEST_CATEGORY_BEAUTY] = gText_ContestLady_Beauty,
    [CONTEST_CATEGORY_CUTE]   = gText_ContestLady_Cuteness,
    [CONTEST_CATEGORY_SMART]  = gText_ContestLady_Smartness,
    [CONTEST_CATEGORY_TOUGH]  = gText_ContestLady_Toughness
};

static const u16 sContestLadyMonSpecies[] LILYCOVE_LADY_DATA =
{
    [CONTEST_CATEGORY_COOL]   = SPECIES_ZIGZAGOON,
    [CONTEST_CATEGORY_BEAUTY] = SPECIES_SKITTY,
    [CONTEST_CATEGORY_CUTE]   = SPECIES_POOCHYENA,
    [CONTEST_CATEGORY_SMART]  = SPECIES_KECLEON,
    [CONTEST_CATEGORY_TOUGH]  = SPECIES_PIKACHU
};

static const u8 sLilycoveLadyDataPadding[2] LILYCOVE_LADY_DATA = {0};

#undef LILYCOVE_LADY_DATA
