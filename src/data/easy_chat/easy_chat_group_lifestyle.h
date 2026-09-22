const u8 gEasyChatWord_Chores[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("アルバイト");
const u8 gEasyChatWord_Home[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("うち");
const u8 gEasyChatWord_Money[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("おかね");
const u8 gEasyChatWord_Allowance[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("おこづかい");
const u8 gEasyChatWord_Bath[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("おふろ");
const u8 gEasyChatWord_Conversation[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("かいわ");
const u8 gEasyChatWord_School[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("がっこう");
const u8 gEasyChatWord_Commemorate[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("きねん");
const u8 gEasyChatWord_Habit[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("くせ");
const u8 gEasyChatWord_Group[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("グループ");
const u8 gEasyChatWord_Word[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ことば");
const u8 gEasyChatWord_Store[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("コンビニ");
const u8 gEasyChatWord_Service[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("サービス");
const u8 gEasyChatWord_Work[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("しごと");
const u8 gEasyChatWord_System[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("システム");
const u8 gEasyChatWord_Train[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("しゅぎょう");
const u8 gEasyChatWord_Class[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("じゅぎょう");
const u8 gEasyChatWord_Lessons[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("じゅく");
const u8 gEasyChatWord_Information[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("じょうほう");
const u8 gEasyChatWord_Living[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("せいかつ");
const u8 gEasyChatWord_Teacher[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("せんせい");
const u8 gEasyChatWord_Tournament[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("たいかい");
const u8 gEasyChatWord_Letter[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("てがみ");
const u8 gEasyChatWord_Event[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("できごと");
const u8 gEasyChatWord_Digital[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("デジタル");
const u8 gEasyChatWord_Test[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("テスト");
const u8 gEasyChatWord_DeptStore[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("デパート");
const u8 gEasyChatWord_Television[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("テレビ");
const u8 gEasyChatWord_Phone[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("でんわ");
const u8 gEasyChatWord_Item[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("どうぐ");
const u8 gEasyChatWord_Name[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("なまえ");
const u8 gEasyChatWord_News[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ニュース");
const u8 gEasyChatWord_Popular[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("にんき");
const u8 gEasyChatWord_Party[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("パーティー");
const u8 gEasyChatWord_Study[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("べんきょう");
const u8 gEasyChatWord_Machine[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("マシン");
const u8 gEasyChatWord_Mail[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("メール");
const u8 gEasyChatWord_Message[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("メッセージ");
const u8 gEasyChatWord_Promise[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("やくそく");
const u8 gEasyChatWord_Dream[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ゆめ");
const u8 gEasyChatWord_Kindergarten[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ようちえん");
const u8 gEasyChatWord_Life[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ライフ");
const u8 gEasyChatWord_Radio[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ラジオ");
const u8 gEasyChatWord_Rental[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("レンタル");
const u8 gEasyChatWord_World[] EASY_CHAT_GROUP_LIFESTYLE_DATA = _("ワールド");

const u8 sEasyChatGroupLifestylePadding[] EASY_CHAT_GROUP_LIFESTYLE_DATA = {0, 0};

const struct EasyChatWordInfo gEasyChatGroup_Lifestyle[] EASY_CHAT_GROUP_LIFESTYLE_DATA = {
    [EC_INDEX(EC_WORD_CHORES)] =
    {
        .text = gEasyChatWord_Chores,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHORES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOME)] =
    {
        .text = gEasyChatWord_Home,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONEY)] =
    {
        .text = gEasyChatWord_Money,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOWANCE)] =
    {
        .text = gEasyChatWord_Allowance,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOWANCE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATH)] =
    {
        .text = gEasyChatWord_Bath,
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONVERSATION)] =
    {
        .text = gEasyChatWord_Conversation,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONVERSATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCHOOL)] =
    {
        .text = gEasyChatWord_School,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCHOOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMMEMORATE)] =
    {
        .text = gEasyChatWord_Commemorate,
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMMEMORATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HABIT)] =
    {
        .text = gEasyChatWord_Habit,
        .alphabeticalOrder = EC_INDEX(EC_WORD_HABIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GROUP)] =
    {
        .text = gEasyChatWord_Group,
        .alphabeticalOrder = EC_INDEX(EC_WORD_GROUP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORD)] =
    {
        .text = gEasyChatWord_Word,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORE)] =
    {
        .text = gEasyChatWord_Store,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERVICE)] =
    {
        .text = gEasyChatWord_Service,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERVICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORK)] =
    {
        .text = gEasyChatWord_Work,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SYSTEM)] =
    {
        .text = gEasyChatWord_System,
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYSTEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAIN)] =
    {
        .text = gEasyChatWord_Train,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLASS)] =
    {
        .text = gEasyChatWord_Class,
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLASS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESSONS)] =
    {
        .text = gEasyChatWord_Lessons,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESSONS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INFORMATION)] =
    {
        .text = gEasyChatWord_Information,
        .alphabeticalOrder = EC_INDEX(EC_WORD_INFORMATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIVING)] =
    {
        .text = gEasyChatWord_Living,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIVING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHER)] =
    {
        .text = gEasyChatWord_Teacher,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOURNAMENT)] =
    {
        .text = gEasyChatWord_Tournament,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOURNAMENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LETTER)] =
    {
        .text = gEasyChatWord_Letter,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LETTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENT)] =
    {
        .text = gEasyChatWord_Event,
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIGITAL)] =
    {
        .text = gEasyChatWord_Digital,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIGITAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEST)] =
    {
        .text = gEasyChatWord_Test,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEPT_STORE)] =
    {
        .text = gEasyChatWord_DeptStore,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEPT_STORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TELEVISION)] =
    {
        .text = gEasyChatWord_Television,
        .alphabeticalOrder = EC_INDEX(EC_WORD_TELEVISION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PHONE)] =
    {
        .text = gEasyChatWord_Phone,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PHONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ITEM)] =
    {
        .text = gEasyChatWord_Item,
        .alphabeticalOrder = EC_INDEX(EC_WORD_ITEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAME)] =
    {
        .text = gEasyChatWord_Name,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEWS)] =
    {
        .text = gEasyChatWord_News,
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POPULAR)] =
    {
        .text = gEasyChatWord_Popular,
        .alphabeticalOrder = EC_INDEX(EC_WORD_POPULAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTY)] =
    {
        .text = gEasyChatWord_Party,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STUDY)] =
    {
        .text = gEasyChatWord_Study,
        .alphabeticalOrder = EC_INDEX(EC_WORD_STUDY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MACHINE)] =
    {
        .text = gEasyChatWord_Machine,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MACHINE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAIL)] =
    {
        .text = gEasyChatWord_Mail,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAIL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MESSAGE)] =
    {
        .text = gEasyChatWord_Message,
        .alphabeticalOrder = EC_INDEX(EC_WORD_MESSAGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROMISE)] =
    {
        .text = gEasyChatWord_Promise,
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROMISE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DREAM)] =
    {
        .text = gEasyChatWord_Dream,
        .alphabeticalOrder = EC_INDEX(EC_WORD_DREAM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KINDERGARTEN)] =
    {
        .text = gEasyChatWord_Kindergarten,
        .alphabeticalOrder = EC_INDEX(EC_WORD_KINDERGARTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIFE)] =
    {
        .text = gEasyChatWord_Life,
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIFE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RADIO)] =
    {
        .text = gEasyChatWord_Radio,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RADIO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RENTAL)] =
    {
        .text = gEasyChatWord_Rental,
        .alphabeticalOrder = EC_INDEX(EC_WORD_RENTAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORLD)] =
    {
        .text = gEasyChatWord_World,
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORLD),
        .enabled = TRUE,
    },
};
