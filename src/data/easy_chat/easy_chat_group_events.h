const u8 gEasyChatWord_Appeal[] EASY_CHAT_GROUP_EVENTS_DATA = _("アピール");
const u8 gEasyChatWord_Events[] EASY_CHAT_GROUP_EVENTS_DATA = _("イベント");
const u8 gEasyChatWord_StayAtHome[] EASY_CHAT_GROUP_EVENTS_DATA = _("おるすばん");
const u8 gEasyChatWord_Berry[] EASY_CHAT_GROUP_EVENTS_DATA = _("きのみ");
const u8 gEasyChatWord_Contest[] EASY_CHAT_GROUP_EVENTS_DATA = _("コンテスト");
const u8 gEasyChatWord_Mc[] EASY_CHAT_GROUP_EVENTS_DATA = _("しかいしゃ");
const u8 gEasyChatWord_Judge[] EASY_CHAT_GROUP_EVENTS_DATA = _("しんさいん");
const u8 gEasyChatWord_Super[] EASY_CHAT_GROUP_EVENTS_DATA = _("スーパー");
const u8 gEasyChatWord_Stage[] EASY_CHAT_GROUP_EVENTS_DATA = _("ステージ");
const u8 gEasyChatWord_HallOfFame[] EASY_CHAT_GROUP_EVENTS_DATA = _("でんどういり");
const u8 gEasyChatWord_Evolution[] EASY_CHAT_GROUP_EVENTS_DATA = _("ノーマル");
const u8 gEasyChatWord_Hyper[] EASY_CHAT_GROUP_EVENTS_DATA = _("ハイパー");
const u8 gEasyChatWord_BattleTower[] EASY_CHAT_GROUP_EVENTS_DATA = _("バトルタワー");
const u8 gEasyChatWord_Leaders[] EASY_CHAT_GROUP_EVENTS_DATA = _("バトルリーダー");
const u8 gEasyChatWord_BattleRoom[] EASY_CHAT_GROUP_EVENTS_DATA = _("バトルルーム");
const u8 gEasyChatWord_Hidden[] EASY_CHAT_GROUP_EVENTS_DATA = _("ひでん");
const u8 gEasyChatWord_SecretBase[] EASY_CHAT_GROUP_EVENTS_DATA = _("ひみつきち");
const u8 gEasyChatWord_Blend[] EASY_CHAT_GROUP_EVENTS_DATA = _("ブレンド");
const u8 gEasyChatWord_POKEBLOCK[] EASY_CHAT_GROUP_EVENTS_DATA = _("ポロック");
const u8 gEasyChatWord_Master[] EASY_CHAT_GROUP_EVENTS_DATA = _("マスター");
const u8 gEasyChatWord_Rank[] EASY_CHAT_GROUP_EVENTS_DATA = _("ランク");
const u8 gEasyChatWord_Ribbon[] EASY_CHAT_GROUP_EVENTS_DATA = _("リボン");
const u8 gEasyChatWord_Crush[] EASY_CHAT_GROUP_EVENTS_DATA = _("クラッシュ");
const u8 gEasyChatWord_Direct[] EASY_CHAT_GROUP_EVENTS_DATA = _("ダイレクト");
const u8 gEasyChatWord_Tower[] EASY_CHAT_GROUP_EVENTS_DATA = _("タワー");
const u8 gEasyChatWord_Union[] EASY_CHAT_GROUP_EVENTS_DATA = _("ユニオン");
const u8 gEasyChatWord_Room[] EASY_CHAT_GROUP_EVENTS_DATA = _("ルーム");
const u8 gEasyChatWord_Wireless[] EASY_CHAT_GROUP_EVENTS_DATA = _("ワイヤレス");
const u8 gEasyChatWord_Frontier[] EASY_CHAT_GROUP_EVENTS_DATA = _("フロンティア");

const u8 sEasyChatGroupEventsPadding[] EASY_CHAT_GROUP_EVENTS_DATA = {0, 0};

const struct EasyChatWordInfo gEasyChatGroup_Events[] EASY_CHAT_GROUP_EVENTS_DATA = {
    [EC_INDEX(EC_WORD_APPEAL)] =
    {
        .text = gEasyChatWord_Appeal,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENTS)] =
    {
        .text = gEasyChatWord_Events,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAY_AT_HOME)] =
    {
        .text = gEasyChatWord_StayAtHome,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAY_AT_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BERRY)] =
    {
        .text = gEasyChatWord_Berry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BERRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONTEST)] =
    {
        .text = gEasyChatWord_Contest,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CRUSH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MC)] =
    {
        .text = gEasyChatWord_Mc,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONTEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_JUDGE)] =
    {
        .text = gEasyChatWord_Judge,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUPER)] =
    {
        .text = gEasyChatWord_Super,
        .alphabeticalOrder = EC_INDEX(EC_WORD_JUDGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STAGE)] =
    {
        .text = gEasyChatWord_Stage,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HALL_OF_FAME)] =
    {
        .text = gEasyChatWord_HallOfFame,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STAGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVOLUTION)] =
    {
        .text = gEasyChatWord_Evolution,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER)] =
    {
        .text = gEasyChatWord_Hyper,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_TOWER)] =
    {
        .text = gEasyChatWord_BattleTower,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HALL_OF_FAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEADERS)] =
    {
        .text = gEasyChatWord_Leaders,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVOLUTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ROOM)] =
    {
        .text = gEasyChatWord_BattleRoom,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIDDEN)] =
    {
        .text = gEasyChatWord_Hidden,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_TOWER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET_BASE)] =
    {
        .text = gEasyChatWord_SecretBase,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEADERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLEND)] =
    {
        .text = gEasyChatWord_Blend,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POKEBLOCK)] =
    {
        .text = gEasyChatWord_POKEBLOCK,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIDDEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MASTER)] =
    {
        .text = gEasyChatWord_Master,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET_BASE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RANK)] =
    {
        .text = gEasyChatWord_Rank,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIBBON)] =
    {
        .text = gEasyChatWord_Ribbon,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONTIER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CRUSH)] =
    {
        .text = gEasyChatWord_Crush,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POKEBLOCK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIRECT)] =
    {
        .text = gEasyChatWord_Direct,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MASTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOWER)] =
    {
        .text = gEasyChatWord_Tower,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNION)] =
    {
        .text = gEasyChatWord_Union,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RANK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROOM)] =
    {
        .text = gEasyChatWord_Room,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIBBON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIRELESS)] =
    {
        .text = gEasyChatWord_Wireless,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONTIER)] =
    {
        .text = gEasyChatWord_Frontier,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIRELESS),
        .enabled = TRUE,
    },
};
