const u8 gEasyChatWord_Highs[] EASY_CHAT_GROUP_MISC_DATA = _("ああ");
const u8 gEasyChatWord_Lows[] EASY_CHAT_GROUP_MISC_DATA = _("あっち");
const u8 gEasyChatWord_Um[] EASY_CHAT_GROUP_MISC_DATA = _("あの");
const u8 gEasyChatWord_Rear[] EASY_CHAT_GROUP_MISC_DATA = _("ありゃ");
const u8 gEasyChatWord_Things[] EASY_CHAT_GROUP_MISC_DATA = _("あれ");
const u8 gEasyChatWord_Thing[] EASY_CHAT_GROUP_MISC_DATA = _("あれは");
const u8 gEasyChatWord_Below[] EASY_CHAT_GROUP_MISC_DATA = _("あんな");
const u8 gEasyChatWord_Above[] EASY_CHAT_GROUP_MISC_DATA = _("うえ");
const u8 gEasyChatWord_Back[] EASY_CHAT_GROUP_MISC_DATA = _("おく");
const u8 gEasyChatWord_High[] EASY_CHAT_GROUP_MISC_DATA = _("こう");
const u8 gEasyChatWord_Here[] EASY_CHAT_GROUP_MISC_DATA = _("こっち");
const u8 gEasyChatWord_Inside[] EASY_CHAT_GROUP_MISC_DATA = _("この");
const u8 gEasyChatWord_Outside[] EASY_CHAT_GROUP_MISC_DATA = _("こりゃ");
const u8 gEasyChatWord_Beside[] EASY_CHAT_GROUP_MISC_DATA = _("これ");
const u8 gEasyChatWord_ThisIsItExcl[] EASY_CHAT_GROUP_MISC_DATA = _("これだ");
const u8 gEasyChatWord_This[] EASY_CHAT_GROUP_MISC_DATA = _("これは");
const u8 gEasyChatWord_Every[] EASY_CHAT_GROUP_MISC_DATA = _("こんな");
const u8 gEasyChatWord_These[] EASY_CHAT_GROUP_MISC_DATA = _("した");
const u8 gEasyChatWord_TheseWere[] EASY_CHAT_GROUP_MISC_DATA = _("そう");
const u8 gEasyChatWord_Down[] EASY_CHAT_GROUP_MISC_DATA = _("そっち");
const u8 gEasyChatWord_That[] EASY_CHAT_GROUP_MISC_DATA = _("その");
const u8 gEasyChatWord_ThoseAre[] EASY_CHAT_GROUP_MISC_DATA = _("そりゃ");
const u8 gEasyChatWord_ThoseWere[] EASY_CHAT_GROUP_MISC_DATA = _("それ");
const u8 gEasyChatWord_ThatsItExcl[] EASY_CHAT_GROUP_MISC_DATA = _("それだ");
const u8 gEasyChatWord_Am[] EASY_CHAT_GROUP_MISC_DATA = _("それは");
const u8 gEasyChatWord_ThatWas[] EASY_CHAT_GROUP_MISC_DATA = _("そんな");
const u8 gEasyChatWord_Front[] EASY_CHAT_GROUP_MISC_DATA = _("てまえ");
const u8 gEasyChatWord_Up[] EASY_CHAT_GROUP_MISC_DATA = _("どう");
const u8 gEasyChatWord_Choice[] EASY_CHAT_GROUP_MISC_DATA = _("どっち");
const u8 gEasyChatWord_Far[] EASY_CHAT_GROUP_MISC_DATA = _("どの");
const u8 gEasyChatWord_Away[] EASY_CHAT_GROUP_MISC_DATA = _("どりゃ");
const u8 gEasyChatWord_Near[] EASY_CHAT_GROUP_MISC_DATA = _("どれ");
const u8 gEasyChatWord_Where[] EASY_CHAT_GROUP_MISC_DATA = _("どれを");
const u8 gEasyChatWord_When[] EASY_CHAT_GROUP_MISC_DATA = _("どんな");
const u8 gEasyChatWord_What[] EASY_CHAT_GROUP_MISC_DATA = _("なに");
const u8 gEasyChatWord_Deep[] EASY_CHAT_GROUP_MISC_DATA = _("なんか");
const u8 gEasyChatWord_Shallow[] EASY_CHAT_GROUP_MISC_DATA = _("なんだ");
const u8 gEasyChatWord_Why[] EASY_CHAT_GROUP_MISC_DATA = _("なんで");
const u8 gEasyChatWord_Confused[] EASY_CHAT_GROUP_MISC_DATA = _("なんなんだ");
const u8 gEasyChatWord_Opposite[] EASY_CHAT_GROUP_MISC_DATA = _("なんの");
const u8 gEasyChatWord_Left[] EASY_CHAT_GROUP_MISC_DATA = _("ひだり");
const u8 gEasyChatWord_Right[] EASY_CHAT_GROUP_MISC_DATA = _("みぎ");

const u8 sEasyChatGroupMiscPadding[] EASY_CHAT_GROUP_MISC_DATA = {0, 0, 0};

const struct EasyChatWordInfo gEasyChatGroup_Misc[] EASY_CHAT_GROUP_MISC_DATA = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = gEasyChatWord_Highs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = gEasyChatWord_Lows,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = gEasyChatWord_Um,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = gEasyChatWord_Rear,
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = gEasyChatWord_Things,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = gEasyChatWord_Thing,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = gEasyChatWord_Below,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = gEasyChatWord_Above,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = gEasyChatWord_Back,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = gEasyChatWord_High,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = gEasyChatWord_Here,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = gEasyChatWord_Inside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = gEasyChatWord_Outside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = gEasyChatWord_Beside,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThisIsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = gEasyChatWord_This,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = gEasyChatWord_Every,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = gEasyChatWord_These,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = gEasyChatWord_TheseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = gEasyChatWord_Down,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = gEasyChatWord_That,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = gEasyChatWord_ThoseAre,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = gEasyChatWord_ThoseWere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = gEasyChatWord_ThatsItExcl,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = gEasyChatWord_Am,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = gEasyChatWord_ThatWas,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = gEasyChatWord_Front,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = gEasyChatWord_Up,
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = gEasyChatWord_Choice,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = gEasyChatWord_Far,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = gEasyChatWord_Away,
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = gEasyChatWord_Near,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = gEasyChatWord_Where,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = gEasyChatWord_When,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = gEasyChatWord_What,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = gEasyChatWord_Deep,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = gEasyChatWord_Shallow,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = gEasyChatWord_Why,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = gEasyChatWord_Confused,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = gEasyChatWord_Opposite,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = gEasyChatWord_Left,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = gEasyChatWord_Right,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
        .enabled = TRUE,
    },
};
