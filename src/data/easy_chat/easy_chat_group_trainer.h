const u8 gEasyChatWord_IChooseYou[] EASY_CHAT_GROUP_TRAINER_DATA = _("きみにきめた！");
const u8 gEasyChatWord_Gotcha[] EASY_CHAT_GROUP_TRAINER_DATA = _("ゲット");
const u8 gEasyChatWord_Trade[] EASY_CHAT_GROUP_TRAINER_DATA = _("こうかん");
const u8 gEasyChatWord_Sapphire[] EASY_CHAT_GROUP_TRAINER_DATA = _("サファイア");
const u8 gEasyChatWord_Evolve[] EASY_CHAT_GROUP_TRAINER_DATA = _("しんか");
const u8 gEasyChatWord_Encyclopedia[] EASY_CHAT_GROUP_TRAINER_DATA = _("ずかん");
const u8 gEasyChatWord_Nature[] EASY_CHAT_GROUP_TRAINER_DATA = _("せいかく");
const u8 gEasyChatWord_Center[] EASY_CHAT_GROUP_TRAINER_DATA = _("センター");
const u8 gEasyChatWord_Egg[] EASY_CHAT_GROUP_TRAINER_DATA = _("タマゴ");
const u8 gEasyChatWord_Link[] EASY_CHAT_GROUP_TRAINER_DATA = _("つうしん");
const u8 gEasyChatWord_SpAbility[] EASY_CHAT_GROUP_TRAINER_DATA = _("とくせい");
const u8 gEasyChatWord_Trainer[] EASY_CHAT_GROUP_TRAINER_DATA = _("トレーナー");
const u8 gEasyChatWord_Version[] EASY_CHAT_GROUP_TRAINER_DATA = _("バージョン");
const u8 gEasyChatWord_Pokenav[] EASY_CHAT_GROUP_TRAINER_DATA = _("ポケナビ");
const u8 gEasyChatWord_Pokemon[] EASY_CHAT_GROUP_TRAINER_DATA = _("ポケモン");
const u8 gEasyChatWord_Get[] EASY_CHAT_GROUP_TRAINER_DATA = _("ポケモンゲット");
const u8 gEasyChatWord_Pokedex[] EASY_CHAT_GROUP_TRAINER_DATA = _("ポケモンずかん");
const u8 gEasyChatWord_Ruby[] EASY_CHAT_GROUP_TRAINER_DATA = _("ルビー");
const u8 gEasyChatWord_Level[] EASY_CHAT_GROUP_TRAINER_DATA = _("レベル");
const u8 gEasyChatWord_Red[] EASY_CHAT_GROUP_TRAINER_DATA = _("あか");
const u8 gEasyChatWord_Green[] EASY_CHAT_GROUP_TRAINER_DATA = _("グリーン");
const u8 gEasyChatWord_Bag[] EASY_CHAT_GROUP_TRAINER_DATA = _("バッグ");
const u8 gEasyChatWord_Flame[] EASY_CHAT_GROUP_TRAINER_DATA = _("ファイア");
const u8 gEasyChatWord_Gold[] EASY_CHAT_GROUP_TRAINER_DATA = _("みどり");
const u8 gEasyChatWord_Leaf[] EASY_CHAT_GROUP_TRAINER_DATA = _("リーフ");
const u8 gEasyChatWord_Silver[] EASY_CHAT_GROUP_TRAINER_DATA = _("レッド");
const u8 gEasyChatWord_Emerald[] EASY_CHAT_GROUP_TRAINER_DATA = _("エメラルド");

const struct EasyChatWordInfo gEasyChatGroup_Trainer[] EASY_CHAT_GROUP_TRAINER_DATA = {
    [EC_INDEX(EC_WORD_I_CHOOSE_YOU)] =
    {
        .text = gEasyChatWord_IChooseYou,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOTCHA)] =
    {
        .text = gEasyChatWord_Gotcha,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EMERALD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRADE)] =
    {
        .text = gEasyChatWord_Trade,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_CHOOSE_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAPPHIRE)] =
    {
        .text = gEasyChatWord_Sapphire,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GREEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLVE)] =
    {
        .text = gEasyChatWord_Evolve,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOTCHA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENCYCLOPEDIA)] =
    {
        .text = gEasyChatWord_Encyclopedia,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRADE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURE)] =
    {
        .text = gEasyChatWord_Nature,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAPPHIRE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CENTER)] =
    {
        .text = gEasyChatWord_Center,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EGG)] =
    {
        .text = gEasyChatWord_Egg,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENCYCLOPEDIA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LINK)] =
    {
        .text = gEasyChatWord_Link,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SP_ABILITY)] =
    {
        .text = gEasyChatWord_SpAbility,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CENTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINER)] =
    {
        .text = gEasyChatWord_Trainer,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EGG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VERSION)] =
    {
        .text = gEasyChatWord_Version,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LINK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKENAV)] =
    {
        .text = gEasyChatWord_Pokenav,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SP_ABILITY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEMON)] =
    {
        .text = gEasyChatWord_Pokemon,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GET)] =
    {
        .text = gEasyChatWord_Get,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VERSION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEDEX)] =
    {
        .text = gEasyChatWord_Pokedex,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BAG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUBY)] =
    {
        .text = gEasyChatWord_Ruby,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVEL)] =
    {
        .text = gEasyChatWord_Level,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKENAV),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RED)] =
    {
        .text = gEasyChatWord_Red,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEMON),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GREEN)] =
    {
        .text = gEasyChatWord_Green,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GET),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_BAG)] =
    {
        .text = gEasyChatWord_Bag,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEDEX),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME)] =
    {
        .text = gEasyChatWord_Flame,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOLD),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_GOLD)] =
    {
        .text = gEasyChatWord_Gold,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEAF),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_LEAF)] =
    {
        .text = gEasyChatWord_Leaf,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUBY),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_SILVER)] =
    {
        .text = gEasyChatWord_Silver,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILVER),
        .enabled = FALSE,
    },
    [EC_INDEX(EC_WORD_EMERALD)] =
    {
        .text = gEasyChatWord_Emerald,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVEL),
        .enabled = TRUE,
    },
};
