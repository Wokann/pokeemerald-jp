const u8 gEasyChatWord_Thanks[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ありがとう");
const u8 gEasyChatWord_Yes[] EASY_CHAT_GROUP_GREETINGS_DATA = _("イエス");
const u8 gEasyChatWord_HereGoes[] EASY_CHAT_GROUP_GREETINGS_DATA = _("いくぜ");
const u8 gEasyChatWord_HereICome[] EASY_CHAT_GROUP_GREETINGS_DATA = _("いくよ");
const u8 gEasyChatWord_HereItIs[] EASY_CHAT_GROUP_GREETINGS_DATA = _("いくわよ");
const u8 gEasyChatWord_Yeah[] EASY_CHAT_GROUP_GREETINGS_DATA = _("いやー");
const u8 gEasyChatWord_Welcome[] EASY_CHAT_GROUP_GREETINGS_DATA = _("いらっしゃい");
const u8 gEasyChatWord_Oi[] EASY_CHAT_GROUP_GREETINGS_DATA = _("おーい");
const u8 gEasyChatWord_HowDo[] EASY_CHAT_GROUP_GREETINGS_DATA = _("おっす");
const u8 gEasyChatWord_Congrats[] EASY_CHAT_GROUP_GREETINGS_DATA = _("おめでとう");
const u8 gEasyChatWord_GiveMe[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ください");
const u8 gEasyChatWord_Sorry[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ゴメン");
const u8 gEasyChatWord_Apologize[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ごめんなさい");
const u8 gEasyChatWord_Forgive[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ごめんね");
const u8 gEasyChatWord_HeyThere[] EASY_CHAT_GROUP_GREETINGS_DATA = _("こらっ");
const u8 gEasyChatWord_Hello[] EASY_CHAT_GROUP_GREETINGS_DATA = _("こんにちは");
const u8 gEasyChatWord_GoodBye[] EASY_CHAT_GROUP_GREETINGS_DATA = _("さようなら");
const u8 gEasyChatWord_ThankYou[] EASY_CHAT_GROUP_GREETINGS_DATA = _("サンキュー");
const u8 gEasyChatWord_IveArrived[] EASY_CHAT_GROUP_GREETINGS_DATA = _("さんじょう");
const u8 gEasyChatWord_Pardon[] EASY_CHAT_GROUP_GREETINGS_DATA = _("しっけい");
const u8 gEasyChatWord_Excuse[] EASY_CHAT_GROUP_GREETINGS_DATA = _("しつれい");
const u8 gEasyChatWord_SeeYa[] EASY_CHAT_GROUP_GREETINGS_DATA = _("じゃーね");
const u8 gEasyChatWord_ExcuseMe[] EASY_CHAT_GROUP_GREETINGS_DATA = _("すみません");
const u8 gEasyChatWord_WellThen[] EASY_CHAT_GROUP_GREETINGS_DATA = _("それじゃ");
const u8 gEasyChatWord_GoAhead[] EASY_CHAT_GROUP_GREETINGS_DATA = _("どうぞ");
const u8 gEasyChatWord_Appreciate[] EASY_CHAT_GROUP_GREETINGS_DATA = _("どうも");
const u8 gEasyChatWord_HeyQues[] EASY_CHAT_GROUP_GREETINGS_DATA = _("なあ");
const u8 gEasyChatWord_WhatsUpQues[] EASY_CHAT_GROUP_GREETINGS_DATA = _("なんじゃ");
const u8 gEasyChatWord_HuhQues[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ねえ");
const u8 gEasyChatWord_No[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ノー");
const u8 gEasyChatWord_Hi[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ハーイ");
const u8 gEasyChatWord_YeahYeah[] EASY_CHAT_GROUP_GREETINGS_DATA = _("はいはい");
const u8 gEasyChatWord_ByeBye[] EASY_CHAT_GROUP_GREETINGS_DATA = _("バイバイ");
const u8 gEasyChatWord_MeetYou[] EASY_CHAT_GROUP_GREETINGS_DATA = _("はじめまして");
const u8 gEasyChatWord_Hey[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ヘイ");
const u8 gEasyChatWord_Smell[] EASY_CHAT_GROUP_GREETINGS_DATA = _("またね");
const u8 gEasyChatWord_Listening[] EASY_CHAT_GROUP_GREETINGS_DATA = _("もしもし");
const u8 gEasyChatWord_HooHah[] EASY_CHAT_GROUP_GREETINGS_DATA = _("やあ");
const u8 gEasyChatWord_Yahoo[] EASY_CHAT_GROUP_GREETINGS_DATA = _("やっほー");
const u8 gEasyChatWord_Yo[] EASY_CHAT_GROUP_GREETINGS_DATA = _("よう");
const u8 gEasyChatWord_ComeOver[] EASY_CHAT_GROUP_GREETINGS_DATA = _("ようこそ");
const u8 gEasyChatWord_CountOn[] EASY_CHAT_GROUP_GREETINGS_DATA = _("よろしく");

const u8 sEasyChatGroupGreetingsPadding[] EASY_CHAT_GROUP_GREETINGS_DATA = {0};

const struct EasyChatWordInfo gEasyChatGroup_Greetings[] EASY_CHAT_GROUP_GREETINGS_DATA = {
    [EC_INDEX(EC_WORD_THANKS)] =
    {
        .text = gEasyChatWord_Thanks,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YES)] =
    {
        .text = gEasyChatWord_Yes,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_GOES)] =
    {
        .text = gEasyChatWord_HereGoes,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_GOES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_I_COME)] =
    {
        .text = gEasyChatWord_HereICome,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_I_COME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE_IT_IS)] =
    {
        .text = gEasyChatWord_HereItIs,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE_IT_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH)] =
    {
        .text = gEasyChatWord_Yeah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELCOME)] =
    {
        .text = gEasyChatWord_Welcome,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELCOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OI)] =
    {
        .text = gEasyChatWord_Oi,
        .alphabeticalOrder = EC_INDEX(EC_WORD_OI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOW_DO)] =
    {
        .text = gEasyChatWord_HowDo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOW_DO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONGRATS)] =
    {
        .text = gEasyChatWord_Congrats,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONGRATS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE_ME)] =
    {
        .text = gEasyChatWord_GiveMe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SORRY)] =
    {
        .text = gEasyChatWord_Sorry,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SORRY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APOLOGIZE)] =
    {
        .text = gEasyChatWord_Apologize,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APOLOGIZE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGIVE)] =
    {
        .text = gEasyChatWord_Forgive,
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_THERE)] =
    {
        .text = gEasyChatWord_HeyThere,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_THERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HELLO)] =
    {
        .text = gEasyChatWord_Hello,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HELLO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD_BYE)] =
    {
        .text = gEasyChatWord_GoodBye,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THANK_YOU)] =
    {
        .text = gEasyChatWord_ThankYou,
        .alphabeticalOrder = EC_INDEX(EC_WORD_THANK_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE_ARRIVED)] =
    {
        .text = gEasyChatWord_IveArrived,
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE_ARRIVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARDON)] =
    {
        .text = gEasyChatWord_Pardon,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARDON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE)] =
    {
        .text = gEasyChatWord_Excuse,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEE_YA)] =
    {
        .text = gEasyChatWord_SeeYa,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEE_YA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCUSE_ME)] =
    {
        .text = gEasyChatWord_ExcuseMe,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCUSE_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL_THEN)] =
    {
        .text = gEasyChatWord_WellThen,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL_THEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GO_AHEAD)] =
    {
        .text = gEasyChatWord_GoAhead,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GO_AHEAD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPRECIATE)] =
    {
        .text = gEasyChatWord_Appreciate,
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPRECIATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY_QUES)] =
    {
        .text = gEasyChatWord_HeyQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT_S_UP_QUES)] =
    {
        .text = gEasyChatWord_WhatsUpQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT_S_UP_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUH_QUES)] =
    {
        .text = gEasyChatWord_HuhQues,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUH_QUES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NO)] =
    {
        .text = gEasyChatWord_No,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HI)] =
    {
        .text = gEasyChatWord_Hi,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HI),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YEAH_YEAH)] =
    {
        .text = gEasyChatWord_YeahYeah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YEAH_YEAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BYE_BYE)] =
    {
        .text = gEasyChatWord_ByeBye,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BYE_BYE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MEET_YOU)] =
    {
        .text = gEasyChatWord_MeetYou,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEET_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEY)] =
    {
        .text = gEasyChatWord_Hey,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMELL)] =
    {
        .text = gEasyChatWord_Smell,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMELL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENING)] =
    {
        .text = gEasyChatWord_Listening,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOO_HAH)] =
    {
        .text = gEasyChatWord_HooHah,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOO_HAH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YAHOO)] =
    {
        .text = gEasyChatWord_Yahoo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YAHOO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YO)] =
    {
        .text = gEasyChatWord_Yo,
        .alphabeticalOrder = EC_INDEX(EC_WORD_YO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME_OVER)] =
    {
        .text = gEasyChatWord_ComeOver,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME_OVER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COUNT_ON)] =
    {
        .text = gEasyChatWord_CountOn,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COUNT_ON),
        .enabled = TRUE,
    },
};
