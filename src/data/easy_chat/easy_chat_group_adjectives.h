const u8 gEasyChatWord_Wandering[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("うろうろ");
const u8 gEasyChatWord_Rickety[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("がたがた");
const u8 gEasyChatWord_RockSolid[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("カチカチ");
const u8 gEasyChatWord_Hungry[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("がつがつ");
const u8 gEasyChatWord_Tight[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ぎゅうぎゅう");
const u8 gEasyChatWord_Ticklish[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("クスクス");
const u8 gEasyChatWord_Twirling[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("くるくる");
const u8 gEasyChatWord_Spiraling[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("グルグル");
const u8 gEasyChatWord_Thirsty[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ごくごく");
const u8 gEasyChatWord_Lolling[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ごろごろ");
const u8 gEasyChatWord_Silky[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("さらさら");
const u8 gEasyChatWord_Sadly[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("しくしく");
const u8 gEasyChatWord_Hopeless[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ぜんぜん");
const u8 gEasyChatWord_Useless[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ダメダメ");
const u8 gEasyChatWord_Drooling[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("だらだら");
const u8 gEasyChatWord_Exciting[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ドキドキ");
const u8 gEasyChatWord_Thick[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("どんどん");
const u8 gEasyChatWord_Smooth[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("なでなで");
const u8 gEasyChatWord_Slimy[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ぬるぬる");
const u8 gEasyChatWord_Thin[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("はあはあ");
const u8 gEasyChatWord_Break[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("バキバキ");
const u8 gEasyChatWord_Voracious[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ぱくぱく");
const u8 gEasyChatWord_Scatter[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("パラパラ");
const u8 gEasyChatWord_Awesome[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("バリバリ");
const u8 gEasyChatWord_Wimpy[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ふにゃふにゃ");
const u8 gEasyChatWord_Wobbly[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ふらふら");
const u8 gEasyChatWord_Shaky[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ブルブル");
const u8 gEasyChatWord_Ripped[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("べろべろ");
const u8 gEasyChatWord_Shredded[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ボロボロ");
const u8 gEasyChatWord_Increasing[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ますます");
const u8 gEasyChatWord_Yet[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("まだまだ");
const u8 gEasyChatWord_Destroyed[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("めちゃめちゃ");
const u8 gEasyChatWord_Fiery[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("メラメラ");
const u8 gEasyChatWord_LoveyDovey[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("ラブラブ");
const u8 gEasyChatWord_Happily[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("るんるん");
const u8 gEasyChatWord_Anticipation[] EASY_CHAT_GROUP_ADJECTIVES_DATA = _("わくわく");

const u8 sEasyChatGroupAdjectivesPadding[] EASY_CHAT_GROUP_ADJECTIVES_DATA = {0, 0};

const struct EasyChatWordInfo gEasyChatGroup_Adjectives[] EASY_CHAT_GROUP_ADJECTIVES_DATA = {
    [EC_INDEX(EC_WORD_WANDERING)] =
    {
        .text = gEasyChatWord_Wandering,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WANDERING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RICKETY)] =
    {
        .text = gEasyChatWord_Rickety,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RICKETY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_SOLID)] =
    {
        .text = gEasyChatWord_RockSolid,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_SOLID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUNGRY)] =
    {
        .text = gEasyChatWord_Hungry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUNGRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIGHT)] =
    {
        .text = gEasyChatWord_Tight,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TICKLISH)] =
    {
        .text = gEasyChatWord_Ticklish,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TICKLISH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TWIRLING)] =
    {
        .text = gEasyChatWord_Twirling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TWIRLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPIRALING)] =
    {
        .text = gEasyChatWord_Spiraling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPIRALING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIRSTY)] =
    {
        .text = gEasyChatWord_Thirsty,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIRSTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOLLING)] =
    {
        .text = gEasyChatWord_Lolling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOLLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SILKY)] =
    {
        .text = gEasyChatWord_Silky,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SILKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SADLY)] =
    {
        .text = gEasyChatWord_Sadly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOPELESS)] =
    {
        .text = gEasyChatWord_Hopeless,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOPELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USELESS)] =
    {
        .text = gEasyChatWord_Useless,
        .alphabeticalOrder = EC_INDEX(EC_WORD_USELESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROOLING)] =
    {
        .text = gEasyChatWord_Drooling,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROOLING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCITING)] =
    {
        .text = gEasyChatWord_Exciting,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCITING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK)] =
    {
        .text = gEasyChatWord_Thick,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMOOTH)] =
    {
        .text = gEasyChatWord_Smooth,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMOOTH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIMY)] =
    {
        .text = gEasyChatWord_Slimy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIMY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIN)] =
    {
        .text = gEasyChatWord_Thin,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BREAK)] =
    {
        .text = gEasyChatWord_Break,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BREAK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VORACIOUS)] =
    {
        .text = gEasyChatWord_Voracious,
        .alphabeticalOrder = EC_INDEX(EC_WORD_VORACIOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCATTER)] =
    {
        .text = gEasyChatWord_Scatter,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCATTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWESOME)] =
    {
        .text = gEasyChatWord_Awesome,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWESOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WIMPY)] =
    {
        .text = gEasyChatWord_Wimpy,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WIMPY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOBBLY)] =
    {
        .text = gEasyChatWord_Wobbly,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOBBLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHAKY)] =
    {
        .text = gEasyChatWord_Shaky,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHAKY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIPPED)] =
    {
        .text = gEasyChatWord_Ripped,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIPPED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHREDDED)] =
    {
        .text = gEasyChatWord_Shredded,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHREDDED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INCREASING)] =
    {
        .text = gEasyChatWord_Increasing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INCREASING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YET)] =
    {
        .text = gEasyChatWord_Yet,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESTROYED)] =
    {
        .text = gEasyChatWord_Destroyed,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESTROYED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIERY)] =
    {
        .text = gEasyChatWord_Fiery,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOVEY_DOVEY)] =
    {
        .text = gEasyChatWord_LoveyDovey,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOVEY_DOVEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAPPILY)] =
    {
        .text = gEasyChatWord_Happily,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAPPILY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANTICIPATION)] =
    {
        .text = gEasyChatWord_Anticipation,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANTICIPATION),
        .enabled = TRUE,
    },
};
