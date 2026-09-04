// data/text/apprentice.inc
extern const u8 gText_ApprenticePleaseTeach0[];
extern const u8 gText_ApprenticePleaseTeach1[];
extern const u8 gText_ApprenticePleaseTeach2[];
extern const u8 gText_ApprenticePleaseTeach3[];
extern const u8 gText_ApprenticePleaseTeach4[];
extern const u8 gText_ApprenticePleaseTeach5[];
extern const u8 gText_ApprenticePleaseTeach6[];
extern const u8 gText_ApprenticePleaseTeach7[];
extern const u8 gText_ApprenticePleaseTeach8[];
extern const u8 gText_ApprenticePleaseTeach9[];
extern const u8 gText_ApprenticePleaseTeach10[];
extern const u8 gText_ApprenticePleaseTeach11[];
extern const u8 gText_ApprenticePleaseTeach12[];
extern const u8 gText_ApprenticePleaseTeach13[];
extern const u8 gText_ApprenticePleaseTeach14[];
extern const u8 gText_ApprenticePleaseTeach15[];
extern const u8 gText_ApprenticeRejectTeaching0[];
extern const u8 gText_ApprenticeRejectTeaching1[];
extern const u8 gText_ApprenticeRejectTeaching2[];
extern const u8 gText_ApprenticeRejectTeaching3[];
extern const u8 gText_ApprenticeRejectTeaching4[];
extern const u8 gText_ApprenticeRejectTeaching5[];
extern const u8 gText_ApprenticeRejectTeaching6[];
extern const u8 gText_ApprenticeRejectTeaching7[];
extern const u8 gText_ApprenticeRejectTeaching8[];
extern const u8 gText_ApprenticeRejectTeaching9[];
extern const u8 gText_ApprenticeRejectTeaching10[];
extern const u8 gText_ApprenticeRejectTeaching11[];
extern const u8 gText_ApprenticeRejectTeaching12[];
extern const u8 gText_ApprenticeRejectTeaching13[];
extern const u8 gText_ApprenticeRejectTeaching14[];
extern const u8 gText_ApprenticeRejectTeaching15[];
extern const u8 gText_ApprenticeWhichLevelMode0[];
extern const u8 gText_ApprenticeWhichLevelMode1[];
extern const u8 gText_ApprenticeWhichLevelMode2[];
extern const u8 gText_ApprenticeWhichLevelMode3[];
extern const u8 gText_ApprenticeWhichLevelMode4[];
extern const u8 gText_ApprenticeWhichLevelMode5[];
extern const u8 gText_ApprenticeWhichLevelMode6[];
extern const u8 gText_ApprenticeWhichLevelMode7[];
extern const u8 gText_ApprenticeWhichLevelMode8[];
extern const u8 gText_ApprenticeWhichLevelMode9[];
extern const u8 gText_ApprenticeWhichLevelMode10[];
extern const u8 gText_ApprenticeWhichLevelMode11[];
extern const u8 gText_ApprenticeWhichLevelMode12[];
extern const u8 gText_ApprenticeWhichLevelMode13[];
extern const u8 gText_ApprenticeWhichLevelMode14[];
extern const u8 gText_ApprenticeWhichLevelMode15[];
extern const u8 gText_ApprenticeLevelModeThanks0[];
extern const u8 gText_ApprenticeLevelModeThanks1[];
extern const u8 gText_ApprenticeLevelModeThanks2[];
extern const u8 gText_ApprenticeLevelModeThanks3[];
extern const u8 gText_ApprenticeLevelModeThanks4[];
extern const u8 gText_ApprenticeLevelModeThanks5[];
extern const u8 gText_ApprenticeLevelModeThanks6[];
extern const u8 gText_ApprenticeLevelModeThanks7[];
extern const u8 gText_ApprenticeLevelModeThanks8[];
extern const u8 gText_ApprenticeLevelModeThanks9[];
extern const u8 gText_ApprenticeLevelModeThanks10[];
extern const u8 gText_ApprenticeLevelModeThanks11[];
extern const u8 gText_ApprenticeLevelModeThanks12[];
extern const u8 gText_ApprenticeLevelModeThanks13[];
extern const u8 gText_ApprenticeLevelModeThanks14[];
extern const u8 gText_ApprenticeLevelModeThanks15[];

// Japanese-language ApprenticeTrainer records. Their ROM layout is 0x30 bytes.

APPRENTICE_DATA const struct ApprenticeTrainer gApprentices[NUM_APPRENTICES] =
{
    {
        .name = _("サダヒロ"),
        .otId = 48585,
        .facilityClass = FACILITY_CLASS_BUG_CATCHER,
        .species = {SPECIES_BEAUTIFLY, SPECIES_DUSTOX, SPECIES_ILLUMISE, SPECIES_SHIFTRY, SPECIES_BRELOOM, SPECIES_NINJASK, SPECIES_SHEDINJA, SPECIES_PINSIR, SPECIES_HERACROSS, SPECIES_VOLBEAT},
        .id = 0,
        .speechLost = {EC_WORD_URGH, EC_WORD_CRIES, EC_WORD_EXCL, EC_WORD_ANY, EC_WORD_LOSS, EC_WORD_WAS},
    },
    {
        .name = _("ヒロオ"),
        .otId = 53001,
        .facilityClass = FACILITY_CLASS_YOUNGSTER,
        .species = {SPECIES_SWELLOW, SPECIES_SWALOT, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_TORKOAL, SPECIES_HARIYAMA, SPECIES_MIGHTYENA, SPECIES_LUDICOLO, SPECIES_CRAWDAUNT, SPECIES_WHISCASH},
        .id = 1,
        .speechLost = {EC_WORD_THEIR, EC_WORD_LOSS, EC_WORD_WERE, EC_WORD_HE, EC_WORD_STRONG, EC_WORD_EVER},
    },
    {
        .name = _("ケイジ"),
        .otId = 11828,
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_M,
        .species = {SPECIES_LINOONE, SPECIES_MIGHTYENA, SPECIES_WHISCASH, SPECIES_ZANGOOSE, SPECIES_SEVIPER, SPECIES_NINETALES, SPECIES_KECLEON, SPECIES_SHUCKLE, SPECIES_MANECTRIC, SPECIES_MACHAMP},
        .id = 2,
        .speechLost = {EC_WORD_UH_OH, EC_WORD_LOST, EC_WORD_DARN, EC_WORD_ANGRY, EC_WORD_HEY_QUES, EC_WORD_EXCL},
    },
    {
        .name = _("ユラ"),
        .otId = 34031,
        .facilityClass = FACILITY_CLASS_LASS,
        .species = {SPECIES_SWALOT, SPECIES_XATU, SPECIES_ALTARIA, SPECIES_GOLDUCK, SPECIES_FLYGON, SPECIES_ALAKAZAM, SPECIES_GARDEVOIR, SPECIES_WAILORD, SPECIES_GRUMPIG, SPECIES_MIGHTYENA},
        .id = 3,
        .speechLost = {EC_WORD_SHE, EC_WORD_ALTHOUGH, EC_WORD_YET, EC_WORD_FAST, EC_WORD_OF, EC_WORD_IS_IT_QUES},
    },
    {
        .name = _("ヨウカ"),
        .otId = 7747,
        .facilityClass = FACILITY_CLASS_SCHOOL_KID_F,
        .species = {SPECIES_WIGGLYTUFF, SPECIES_LINOONE, SPECIES_KINGDRA, SPECIES_DELCATTY, SPECIES_RAICHU, SPECIES_FEAROW, SPECIES_STARMIE, SPECIES_MEDICHAM, SPECIES_SHIFTRY, SPECIES_BEAUTIFLY},
        .id = 4,
        .speechLost = {EC_WORD_NEXT, EC_WORD_HOWEVER, EC_WORD_ABSOLUTELY, EC_WORD_LOSS, EC_WORD_NONE, EC_WORD_ANYWHERE},
    },
    {
        .name = _("ヤスシ"),
        .otId = 14239,
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_M,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_AGGRON, SPECIES_MAGNETON, SPECIES_MACHAMP, SPECIES_ARMALDO, SPECIES_HERACROSS, SPECIES_NOSEPASS, SPECIES_EXPLOUD, SPECIES_MIGHTYENA},
        .id = 5,
        .speechLost = {EC_WORD_FOR_NOW, EC_WORD_RUN, EC_WORD_EXCL_EXCL, EC_WORD_SMELL, EC_WORD_DASH, EC_WORD_EXCL_EXCL},
    },
    {
        .name = _("ミサオ"),
        .otId = 62805,
        .facilityClass = FACILITY_CLASS_RUNNING_TRIATHLETE_F,
        .species = {SPECIES_STARMIE, SPECIES_DODRIO, SPECIES_MAGNETON, SPECIES_MEDICHAM, SPECIES_MIGHTYENA, SPECIES_GLALIE, SPECIES_GOLEM, SPECIES_ELECTRODE, SPECIES_PELIPPER, SPECIES_SHARPEDO},
        .id = 6,
        .speechLost = {EC_WORD_AHAHA, EC_WORD_DEFEATED, EC_WORD_DASH, EC_WORD_YET, EC_WORD_WERE, EC_WORD_DASH},
    },
    {
        .name = _("カズサ"),
        .otId = 36134,
        .facilityClass = FACILITY_CLASS_BEAUTY,
        .species = {SPECIES_NINETALES, SPECIES_ALAKAZAM, SPECIES_SCEPTILE, SPECIES_SALAMENCE, SPECIES_GOLDUCK, SPECIES_MAWILE, SPECIES_WEEZING, SPECIES_LANTURN, SPECIES_GARDEVOIR, SPECIES_MILOTIC},
        .id = 7,
        .speechLost = {EC_WORD_STRONG, EC_WORD_OF, EC_WORD_THERE, EC_WORD_EVER, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
    },
    {
        .name = _("スミレ"),
        .otId = 32780,
        .facilityClass = FACILITY_CLASS_AROMA_LADY,
        .species = {SPECIES_SCEPTILE, SPECIES_VILEPLUME, SPECIES_BELLOSSOM, SPECIES_ROSELIA, SPECIES_CORSOLA, SPECIES_FLYGON, SPECIES_BRELOOM, SPECIES_MILOTIC, SPECIES_ALTARIA, SPECIES_CRADILY},
        .id = 8,
        .speechLost = {EC_WORD_JOKING, EC_WORD_STRONG, EC_WORD_POKEMON, EC_WORD_FOR, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
    },
    {
        .name = _("アキノリ"),
        .otId = 18079,
        .facilityClass = FACILITY_CLASS_HIKER,
        .species = {SPECIES_SKARMORY, SPECIES_GOLEM, SPECIES_BLAZIKEN, SPECIES_CAMERUPT, SPECIES_DONPHAN, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_TROPIUS, SPECIES_SOLROCK, SPECIES_RHYDON},
        .id = 9,
        .speechLost = {EC_WORD_TRULY, EC_WORD_SHREDDED, EC_WORD_OF, EC_WORD_USELESS, EC_WORD_WERE, EC_WORD_EXCL_EXCL},
    },
    {
        .name = _("トウゾウ"),
        .otId = 29180,
        .facilityClass = FACILITY_CLASS_FISHERMAN,
        .species = {SPECIES_SEAKING, SPECIES_STARMIE, SPECIES_GOLDUCK, SPECIES_TENTACRUEL, SPECIES_OCTILLERY, SPECIES_GOREBYSS, SPECIES_GLALIE, SPECIES_WAILORD, SPECIES_SHARPEDO, SPECIES_KINGDRA},
        .id = 10,
        .speechLost = {EC_WORD_LIE, EC_WORD_OF, EC_WORD_LIE, EC_WORD_REALLY, EC_WORD_EXCL_EXCL, EC_EMPTY_WORD},
    },
    {
        .name = _("セイヤ"),
        .otId = 41886,
        .facilityClass = FACILITY_CLASS_SAILOR,
        .species = {SPECIES_QUAGSIRE, SPECIES_STARMIE, SPECIES_PELIPPER, SPECIES_CRAWDAUNT, SPECIES_WAILORD, SPECIES_GYARADOS, SPECIES_SWAMPERT, SPECIES_LANTURN, SPECIES_WHISCASH, SPECIES_SHUCKLE},
        .id = 11,
        .speechLost = {EC_WORD_LOST, EC_WORD_DARN, EC_WORD_BUT, EC_WORD_UPBEAT, EC_WORD_ISN_T, EC_WORD_EXCL},
    },
    {
        .name = _("リュウジ"),
        .otId = 58768,
        .facilityClass = FACILITY_CLASS_GUITARIST,
        .species = {SPECIES_ABSOL, SPECIES_CROBAT, SPECIES_EXPLOUD, SPECIES_MAGNETON, SPECIES_SHARPEDO, SPECIES_MANECTRIC, SPECIES_METAGROSS, SPECIES_ELECTRODE, SPECIES_NOSEPASS, SPECIES_WEEZING},
        .id = 12,
        .speechLost = {EC_WORD_PERFECT, EC_WORD_LOSS, EC_WORD_THAT_S, EC_WORD_CASE, EC_WORD_ISN_T, EC_WORD_EXCL_EXCL},
    },
    {
        .name = _("カツアキ"),
        .otId = 53272,
        .facilityClass = FACILITY_CLASS_BLACK_BELT,
        .species = {SPECIES_BLAZIKEN, SPECIES_GOLEM, SPECIES_MACHAMP, SPECIES_RHYDON, SPECIES_HARIYAMA, SPECIES_AGGRON, SPECIES_MEDICHAM, SPECIES_ZANGOOSE, SPECIES_VIGOROTH, SPECIES_SLAKING},
        .id = 13,
        .speechLost = {EC_WORD_URGH, EC_WORD_FROM, EC_WORD_WERE, EC_WORD_TOO_WEAK, EC_WORD_ELLIPSIS, EC_EMPTY_WORD},
    },
    {
        .name = _("トシミツ"),
        .otId = 48245,
        .facilityClass = FACILITY_CLASS_RUIN_MANIAC,
        .species = {SPECIES_SCEPTILE, SPECIES_SANDSLASH, SPECIES_FLYGON, SPECIES_CLAYDOL, SPECIES_ARMALDO, SPECIES_CROBAT, SPECIES_CRADILY, SPECIES_SOLROCK, SPECIES_LUNATONE, SPECIES_GOLEM},
        .id = 14,
        .speechLost = {EC_WORD_EXCITING, EC_WORD_KNOWS, EC_WORD_WELL, EC_WORD_UNDERSTAND, EC_WORD_NONE, EC_WORD_ELLIPSIS},
    },
    {
        .name = _("ローウェン"),
        .otId = 64002,
        .facilityClass = FACILITY_CLASS_GENTLEMAN,
        .species = {SPECIES_ABSOL, SPECIES_MIGHTYENA, SPECIES_ALAKAZAM, SPECIES_BANETTE, SPECIES_NINETALES, SPECIES_CLAYDOL, SPECIES_MUK, SPECIES_SALAMENCE, SPECIES_WALREIN, SPECIES_DUSCLOPS},
        .id = 15,
        .speechLost = {EC_WORD_SHE_WAS, EC_WORD_LOSE, EC_WORD_JOKING, EC_WORD_LIE, EC_WORD_WERE, EC_WORD_DASH},
    },
};

// Sequence of four messages for the first meeting with the apprentice.
static APPRENTICE_DATA const u8 *const sApprenticeFirstMeetingTexts[NUM_APPRENTICES][4] =
{
    {gText_ApprenticePleaseTeach0,  gText_ApprenticeRejectTeaching0,  gText_ApprenticeWhichLevelMode0,  gText_ApprenticeLevelModeThanks0},
    {gText_ApprenticePleaseTeach1,  gText_ApprenticeRejectTeaching1,  gText_ApprenticeWhichLevelMode1,  gText_ApprenticeLevelModeThanks1},
    {gText_ApprenticePleaseTeach2,  gText_ApprenticeRejectTeaching2,  gText_ApprenticeWhichLevelMode2,  gText_ApprenticeLevelModeThanks2},
    {gText_ApprenticePleaseTeach3,  gText_ApprenticeRejectTeaching3,  gText_ApprenticeWhichLevelMode3,  gText_ApprenticeLevelModeThanks3},
    {gText_ApprenticePleaseTeach4,  gText_ApprenticeRejectTeaching4,  gText_ApprenticeWhichLevelMode4,  gText_ApprenticeLevelModeThanks4},
    {gText_ApprenticePleaseTeach5,  gText_ApprenticeRejectTeaching5,  gText_ApprenticeWhichLevelMode5,  gText_ApprenticeLevelModeThanks5},
    {gText_ApprenticePleaseTeach6,  gText_ApprenticeRejectTeaching6,  gText_ApprenticeWhichLevelMode6,  gText_ApprenticeLevelModeThanks6},
    {gText_ApprenticePleaseTeach7,  gText_ApprenticeRejectTeaching7,  gText_ApprenticeWhichLevelMode7,  gText_ApprenticeLevelModeThanks7},
    {gText_ApprenticePleaseTeach8,  gText_ApprenticeRejectTeaching8,  gText_ApprenticeWhichLevelMode8,  gText_ApprenticeLevelModeThanks8},
    {gText_ApprenticePleaseTeach9,  gText_ApprenticeRejectTeaching9,  gText_ApprenticeWhichLevelMode9,  gText_ApprenticeLevelModeThanks9},
    {gText_ApprenticePleaseTeach10, gText_ApprenticeRejectTeaching10, gText_ApprenticeWhichLevelMode10, gText_ApprenticeLevelModeThanks10},
    {gText_ApprenticePleaseTeach11, gText_ApprenticeRejectTeaching11, gText_ApprenticeWhichLevelMode11, gText_ApprenticeLevelModeThanks11},
    {gText_ApprenticePleaseTeach12, gText_ApprenticeRejectTeaching12, gText_ApprenticeWhichLevelMode12, gText_ApprenticeLevelModeThanks12},
    {gText_ApprenticePleaseTeach13, gText_ApprenticeRejectTeaching13, gText_ApprenticeWhichLevelMode13, gText_ApprenticeLevelModeThanks13},
    {gText_ApprenticePleaseTeach14, gText_ApprenticeRejectTeaching14, gText_ApprenticeWhichLevelMode14, gText_ApprenticeLevelModeThanks14},
    {gText_ApprenticePleaseTeach15, gText_ApprenticeRejectTeaching15, gText_ApprenticeWhichLevelMode15, gText_ApprenticeLevelModeThanks15},
};
