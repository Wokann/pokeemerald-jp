#ifndef GUARD_DATA_SOUND_CHECK_H
#define GUARD_DATA_SOUND_CHECK_H

// JP-only Sound Check data, retained in its native ROM order.
#define SOUND_CHECK_DATA __attribute__((section(".rodata.sound_check_data"), aligned(1)))

struct SoundCheckParameterRange
{
    s32 min;
    s32 max;
};

SOUND_CHECK_DATA static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

SOUND_CHECK_DATA static const struct WindowTemplate sMainWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 8,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 132,
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 244,
    },
    DUMMY_WIN_TEMPLATE,
};

SOUND_CHECK_DATA static const u8 sText_SoundCheckControls[] = _("サウンドチェック　A⋯さいせい　B⋯おわり");

SOUND_CHECK_DATA static const u8 sText_Bgm[] = _("BGM");

SOUND_CHECK_DATA static const u8 sText_Se[] = _("SE　");

SOUND_CHECK_DATA static const u8 sText_PageControls[] = _("L⋯UP　R⋯DOWN");

SOUND_CHECK_DATA static const u8 sText_DriverTestControls[] = _("R⋯DRIVERーTEST");

SOUND_CHECK_DATA static const struct WindowTemplate sDriverWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 28,
        .height = 18,
        .paletteNum = 15,
        .baseBlock = 20,
    },
    DUMMY_WIN_TEMPLATE,
};

SOUND_CHECK_DATA static const u8 sText_BToReturn[] = _("Bボタンで　もどる");

SOUND_CHECK_DATA static const u8 sText_AToPlay[] = _("Aボタンで　さいせい");

SOUND_CHECK_DATA static const u8 sText_Voice[] = _("VOICE⋯⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Volume[] = _("VOLUME⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Panpot[] = _("PANPOT⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Pitch[] = _("PITCH⋯⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Length[] = _("LENGTH⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Release[] = _("RELEASE⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Progress[] = _("PROGRESS⋯");

SOUND_CHECK_DATA static const u8 sText_Chorus[] = _("CHORUS⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Priority[] = _("PRIORITY⋯");

SOUND_CHECK_DATA static const u8 sText_Playing[] = _("さいせいちゆう⋯");

SOUND_CHECK_DATA static const u8 sText_Reverse[] = _("はんてん⋯⋯⋯⋯");

SOUND_CHECK_DATA static const u8 sText_Stereo[11] = _("ステレオ⋯⋯⋯⋯");

SOUND_CHECK_DATA static const struct SoundCheckParameterRange sDriverParameterRanges[] =
{
    {0, 387},
    {0, 127},
    {-127, 127},
    {-128, 32639},
    {0, 65535},
    {0, 255},
    {0, 65535},
    {-64, 63},
};

SOUND_CHECK_DATA static const s32 sDecimalPowers[] = {1, 10, 100, 1000, 10000, 100000};

SOUND_CHECK_DATA static const s8 sPanValues[] = {63, 0, -64, 127, -128};

SOUND_CHECK_DATA static const u8 sText_StereoSe[] = _("SE");

SOUND_CHECK_DATA static const u8 sText_StereoPan[] = _("PAN");

SOUND_CHECK_DATA static const u8 sText_LR[] = _("　　LR");

SOUND_CHECK_DATA static const u8 sText_RL[] = _("　　RL");

SOUND_CHECK_DATA static const u8 sText_Stop[] = _("STOP");

SOUND_CHECK_DATA static const u8 sText_MusDummy[] = _("MUSーDUMMY");

SOUND_CHECK_DATA static const u8 sText_SeKaifuku[] = _("SEーKAIFUKU");

SOUND_CHECK_DATA static const u8 sText_SePcLogin[] = _("SEーPCーLOGIN");

SOUND_CHECK_DATA static const u8 sText_SePcOff[] = _("SEーPCーOFF");

SOUND_CHECK_DATA static const u8 sText_SePcOn[] = _("SEーPCーON");

SOUND_CHECK_DATA static const u8 sText_SeSelect[] = _("SEーSELECT");

SOUND_CHECK_DATA static const u8 sText_SeWinOpen[] = _("SEーWINーOPEN");

SOUND_CHECK_DATA static const u8 sText_SeWallHit[] = _("SEーWALLーHIT");

SOUND_CHECK_DATA static const u8 sText_SeDoor[] = _("SEーDOOR");

SOUND_CHECK_DATA static const u8 sText_SeKaidan[] = _("SEーKAIDAN");

SOUND_CHECK_DATA static const u8 sText_SeDansa[] = _("SEーDANSA");

SOUND_CHECK_DATA static const u8 sText_SeJitensya[] = _("SEーJITENSYA");

SOUND_CHECK_DATA static const u8 sText_SeKoukaL[] = _("SEーKOUKAーL");

SOUND_CHECK_DATA static const u8 sText_SeKoukaM[] = _("SEーKOUKAーM");

SOUND_CHECK_DATA static const u8 sText_SeKoukaH[] = _("SEーKOUKAーH");

SOUND_CHECK_DATA static const u8 sText_SeBowa2[] = _("SEーBOWA2");

SOUND_CHECK_DATA static const u8 sText_SePokeDead[] = _("SEーPOKEーDEAD");

SOUND_CHECK_DATA static const u8 sText_SeNigeru[] = _("SEーNIGERU");

SOUND_CHECK_DATA static const u8 sText_SeJidoDoa[] = _("SEーJIDOーDOA");

SOUND_CHECK_DATA static const u8 sText_SeNaminori[] = _("SEーNAMINORI");

SOUND_CHECK_DATA static const u8 sText_SeBan[] = _("SEーBAN");

SOUND_CHECK_DATA static const u8 sText_SePin[] = _("SEーPIN");

SOUND_CHECK_DATA static const u8 sText_SeBoo[] = _("SEーBOO");

SOUND_CHECK_DATA static const u8 sText_SeBowa[] = _("SEーBOWA");

SOUND_CHECK_DATA static const u8 sText_SeJyuni[] = _("SEーJYUNI");

SOUND_CHECK_DATA static const u8 sText_SeA[] = _("SEーA");

SOUND_CHECK_DATA static const u8 sText_SeI[] = _("SEーI");

SOUND_CHECK_DATA static const u8 sText_SeU[] = _("SEーU");

SOUND_CHECK_DATA static const u8 sText_SeE[] = _("SEーE");

SOUND_CHECK_DATA static const u8 sText_SeO[] = _("SEーO");

SOUND_CHECK_DATA static const u8 sText_SeN[] = _("SEーN");

SOUND_CHECK_DATA static const u8 sText_SeSeikai[] = _("SEーSEIKAI");

SOUND_CHECK_DATA static const u8 sText_SeHazure[] = _("SEーHAZURE");

SOUND_CHECK_DATA static const u8 sText_SeExp[] = _("SEーEXP");

SOUND_CHECK_DATA static const u8 sText_SeJitePyoko[] = _("SEーJITEーPYOKO");

SOUND_CHECK_DATA static const u8 sText_SeMuPachi[] = _("SEーMUーPACHI");

SOUND_CHECK_DATA static const u8 sText_SeTkKasya[] = _("SEーTKーKASYA");

SOUND_CHECK_DATA static const u8 sText_SeFuZaku[] = _("SEーFUーZAKU");

SOUND_CHECK_DATA static const u8 sText_SeFuZaku2[] = _("SEーFUーZAKU2");

SOUND_CHECK_DATA static const u8 sText_SeFuZuzuzu[] = _("SEーFUーZUZUZU");

SOUND_CHECK_DATA static const u8 sText_SeRuGashin[] = _("SEーRUーGASHIN");

SOUND_CHECK_DATA static const u8 sText_SeRuGasyan[] = _("SEーRUーGASYAN");

SOUND_CHECK_DATA static const u8 sText_SeRuBari[] = _("SEーRUーBARI");

SOUND_CHECK_DATA static const u8 sText_SeRuHyuu[] = _("SEーRUーHYUU");

SOUND_CHECK_DATA static const u8 sText_SeKiGasyan[] = _("SEーKIーGASYAN");

SOUND_CHECK_DATA static const u8 sText_SeTkWarpin[] = _("SEーTKーWARPIN");

SOUND_CHECK_DATA static const u8 sText_SeTkWarpout[] = _("SEーTKーWARPOUT");

SOUND_CHECK_DATA static const u8 sText_SeTuSaa[] = _("SEーTUーSAA");

SOUND_CHECK_DATA static const u8 sText_SeHiTurun[] = _("SEーHIーTURUN");

SOUND_CHECK_DATA static const u8 sText_SeTrackMove[] = _("SEーTRACKーMOVE");

SOUND_CHECK_DATA static const u8 sText_SeTrackStop[] = _("SEーTRACKーSTOP");

SOUND_CHECK_DATA static const u8 sText_SeTrackHaiki[] = _("SEーTRACKーHAIKI");

SOUND_CHECK_DATA static const u8 sText_SeTrackDoor[] = _("SEーTRACKーDOOR");

SOUND_CHECK_DATA static const u8 sText_SeMoter[] = _("SEーMOTER");

SOUND_CHECK_DATA static const u8 sText_SeCard[] = _("SEーCARD");

SOUND_CHECK_DATA static const u8 sText_SeSave[] = _("SEーSAVE");

SOUND_CHECK_DATA static const u8 sText_SeKon[] = _("SEーKON");

SOUND_CHECK_DATA static const u8 sText_SeKon2[] = _("SEーKON2");

SOUND_CHECK_DATA static const u8 sText_SeKon3[] = _("SEーKON3");

SOUND_CHECK_DATA static const u8 sText_SeKon4[] = _("SEーKON4");

SOUND_CHECK_DATA static const u8 sText_SeSuikomu[] = _("SEーSUIKOMU");

SOUND_CHECK_DATA static const u8 sText_SeNageru[] = _("SEーNAGERU");

SOUND_CHECK_DATA static const u8 sText_SeToyC[] = _("SEーTOYーC");

SOUND_CHECK_DATA static const u8 sText_SeToyD[] = _("SEーTOYーD");

SOUND_CHECK_DATA static const u8 sText_SeToyE[] = _("SEーTOYーE");

SOUND_CHECK_DATA static const u8 sText_SeToyF[] = _("SEーTOYーF");

SOUND_CHECK_DATA static const u8 sText_SeToyG[] = _("SEーTOYーG");

SOUND_CHECK_DATA static const u8 sText_SeToyA[] = _("SEーTOYーA");

SOUND_CHECK_DATA static const u8 sText_SeToyB[] = _("SEーTOYーB");

SOUND_CHECK_DATA static const u8 sText_SeToyC1[] = _("SEーTOYーC1");

SOUND_CHECK_DATA static const u8 sText_SeMizu[] = _("SEーMIZU");

SOUND_CHECK_DATA static const u8 sText_SeHashi[] = _("SEーHASHI");

SOUND_CHECK_DATA static const u8 sText_SeDaugi[] = _("SEーDAUGI");

SOUND_CHECK_DATA static const u8 sText_SePinpon[] = _("SEーPINPON");

SOUND_CHECK_DATA static const u8 sText_SeFuusen1[] = _("SEーFUUSEN1");

SOUND_CHECK_DATA static const u8 sText_SeFuusen2[] = _("SEーFUUSEN2");

SOUND_CHECK_DATA static const u8 sText_SeFuusen3[] = _("SEーFUUSEN3");

SOUND_CHECK_DATA static const u8 sText_SeToyKabe[] = _("SEーTOYーKABE");

SOUND_CHECK_DATA static const u8 sText_SeToyDango[] = _("SEーTOYーDANGO");

SOUND_CHECK_DATA static const u8 sText_SeDoku[] = _("SEーDOKU");

SOUND_CHECK_DATA static const u8 sText_SeEsuka[] = _("SEーESUKA");

SOUND_CHECK_DATA static const u8 sText_SeTAme[] = _("SEーTーAME");

SOUND_CHECK_DATA static const u8 sText_SeTAmeE[] = _("SEーTーAMEーE");

SOUND_CHECK_DATA static const u8 sText_SeTOoame[] = _("SEーTーOOAME");

SOUND_CHECK_DATA static const u8 sText_SeTOoameE[] = _("SEーTーOOAMEーE");

SOUND_CHECK_DATA static const u8 sText_SeTKoame[] = _("SEーTーKOAME");

SOUND_CHECK_DATA static const u8 sText_SeTKoameE[] = _("SEーTーKOAMEーE");

SOUND_CHECK_DATA static const u8 sText_SeTKami[] = _("SEーTーKAMI");

SOUND_CHECK_DATA static const u8 sText_SeTKami2[] = _("SEーTーKAMI2");

SOUND_CHECK_DATA static const u8 sText_SeElebeta[] = _("SEーELEBETA");

SOUND_CHECK_DATA static const u8 sText_SeHinsi[] = _("SEーHINSI");

SOUND_CHECK_DATA static const u8 sText_SeExpmax[] = _("SEーEXPMAX");

SOUND_CHECK_DATA static const u8 sText_SeTamakoro[] = _("SEーTAMAKORO");

SOUND_CHECK_DATA static const u8 sText_SeTamakoroE[] = _("SEーTAMAKOROーE");

SOUND_CHECK_DATA static const u8 sText_SeBasabasa[] = _("SEーBASABASA");

SOUND_CHECK_DATA static const u8 sText_SeRegi[] = _("SEーREGI");

SOUND_CHECK_DATA static const u8 sText_SeCGaji[] = _("SEーCーGAJI");

SOUND_CHECK_DATA static const u8 sText_SeCMakuU[] = _("SEーCーMAKUーU");

SOUND_CHECK_DATA static const u8 sText_SeCMakuD[] = _("SEーCーMAKUーD");

SOUND_CHECK_DATA static const u8 sText_SeCPasi[] = _("SEーCーPASI");

SOUND_CHECK_DATA static const u8 sText_SeCSyu[] = _("SEーCーSYU");

SOUND_CHECK_DATA static const u8 sText_SeCPikon[] = _("SEーCーPIKON");

SOUND_CHECK_DATA static const u8 sText_SeReapoke[] = _("SEーREAPOKE");

SOUND_CHECK_DATA static const u8 sText_SeOpBasyu[] = _("SEーOPーBASYU");

SOUND_CHECK_DATA static const u8 sText_SeBtStart[] = _("SEーBTーSTART");

SOUND_CHECK_DATA static const u8 sText_SeDendou[] = _("SEーDENDOU");

SOUND_CHECK_DATA static const u8 sText_SeJihanki[] = _("SEーJIHANKI");

SOUND_CHECK_DATA static const u8 sText_SeTama[] = _("SEーTAMA");

SOUND_CHECK_DATA static const u8 sText_SeZScroll[] = _("SEーZーSCROLL");

SOUND_CHECK_DATA static const u8 sText_SeZPage[] = _("SEーZーPAGE");

SOUND_CHECK_DATA static const u8 sText_SePnOn[] = _("SEーPNーON");

SOUND_CHECK_DATA static const u8 sText_SePnOff[] = _("SEーPNーOFF");

SOUND_CHECK_DATA static const u8 sText_SeZSearch[] = _("SEーZーSEARCH");

SOUND_CHECK_DATA static const u8 sText_SeTamago[] = _("SEーTAMAGO");

SOUND_CHECK_DATA static const u8 sText_SeTbStart[] = _("SEーTBーSTART");

SOUND_CHECK_DATA static const u8 sText_SeTbKon[] = _("SEーTBーKON");

SOUND_CHECK_DATA static const u8 sText_SeTbKara[] = _("SEーTBーKARA");

SOUND_CHECK_DATA static const u8 sText_SeBidoro[] = _("SEーBIDORO");

SOUND_CHECK_DATA static const u8 sText_SeW085[] = _("SEーW085");

SOUND_CHECK_DATA static const u8 sText_SeW085B[] = _("SEーW085B");

SOUND_CHECK_DATA static const u8 sText_SeW231[] = _("SEーW231");

SOUND_CHECK_DATA static const u8 sText_SeW171[] = _("SEーW171");

SOUND_CHECK_DATA static const u8 sText_SeW233[] = _("SEーW233");

SOUND_CHECK_DATA static const u8 sText_SeW233B[] = _("SEーW233B");

SOUND_CHECK_DATA static const u8 sText_SeW145[] = _("SEーW145");

SOUND_CHECK_DATA static const u8 sText_SeW145B[] = _("SEーW145B");

SOUND_CHECK_DATA static const u8 sText_SeW145C[] = _("SEーW145C");

SOUND_CHECK_DATA static const u8 sText_SeW240[] = _("SEーW240");

SOUND_CHECK_DATA static const u8 sText_SeW015[] = _("SEーW015");

SOUND_CHECK_DATA static const u8 sText_SeW081[] = _("SEーW081");

SOUND_CHECK_DATA static const u8 sText_SeW081B[] = _("SEーW081B");

SOUND_CHECK_DATA static const u8 sText_SeW088[] = _("SEーW088");

SOUND_CHECK_DATA static const u8 sText_SeW016[] = _("SEーW016");

SOUND_CHECK_DATA static const u8 sText_SeW016B[] = _("SEーW016B");

SOUND_CHECK_DATA static const u8 sText_SeW003[] = _("SEーW003");

SOUND_CHECK_DATA static const u8 sText_SeW104[] = _("SEーW104");

SOUND_CHECK_DATA static const u8 sText_SeW013[] = _("SEーW013");

SOUND_CHECK_DATA static const u8 sText_SeW196[] = _("SEーW196");

SOUND_CHECK_DATA static const u8 sText_SeW086[] = _("SEーW086");

SOUND_CHECK_DATA static const u8 sText_SeW004[] = _("SEーW004");

SOUND_CHECK_DATA static const u8 sText_SeW025[] = _("SEーW025");

SOUND_CHECK_DATA static const u8 sText_SeW025B[] = _("SEーW025B");

SOUND_CHECK_DATA static const u8 sText_SeW152[] = _("SEーW152");

SOUND_CHECK_DATA static const u8 sText_SeW026[] = _("SEーW026");

SOUND_CHECK_DATA static const u8 sText_SeW172[] = _("SEーW172");

SOUND_CHECK_DATA static const u8 sText_SeW172B[] = _("SEーW172B");

SOUND_CHECK_DATA static const u8 sText_SeW053[] = _("SEーW053");

SOUND_CHECK_DATA static const u8 sText_SeW007[] = _("SEーW007");

SOUND_CHECK_DATA static const u8 sText_SeW092[] = _("SEーW092");

SOUND_CHECK_DATA static const u8 sText_SeW221[] = _("SEーW221");

SOUND_CHECK_DATA static const u8 sText_SeW221B[] = _("SEーW221B");

SOUND_CHECK_DATA static const u8 sText_SeW052[] = _("SEーW052");

SOUND_CHECK_DATA static const u8 sText_SeW036[] = _("SEーW036");

SOUND_CHECK_DATA static const u8 sText_SeW059[] = _("SEーW059");

SOUND_CHECK_DATA static const u8 sText_SeW059B[] = _("SEーW059B");

SOUND_CHECK_DATA static const u8 sText_SeW010[] = _("SEーW010");

SOUND_CHECK_DATA static const u8 sText_SeW011[] = _("SEーW011");

SOUND_CHECK_DATA static const u8 sText_SeW017[] = _("SEーW017");

SOUND_CHECK_DATA static const u8 sText_SeW019[] = _("SEーW019");

SOUND_CHECK_DATA static const u8 sText_SeW028[] = _("SEーW028");

SOUND_CHECK_DATA static const u8 sText_SeW013B[] = _("SEーW013B");

SOUND_CHECK_DATA static const u8 sText_SeW044[] = _("SEーW044");

SOUND_CHECK_DATA static const u8 sText_SeW029[] = _("SEーW029");

SOUND_CHECK_DATA static const u8 sText_SeW057[] = _("SEーW057");

SOUND_CHECK_DATA static const u8 sText_SeW056[] = _("SEーW056");

SOUND_CHECK_DATA static const u8 sText_SeW250[] = _("SEーW250");

SOUND_CHECK_DATA static const u8 sText_SeW030[] = _("SEーW030");

SOUND_CHECK_DATA static const u8 sText_SeW039[] = _("SEーW039");

SOUND_CHECK_DATA static const u8 sText_SeW054[] = _("SEーW054");

SOUND_CHECK_DATA static const u8 sText_SeW077[] = _("SEーW077");

SOUND_CHECK_DATA static const u8 sText_SeW020[] = _("SEーW020");

SOUND_CHECK_DATA static const u8 sText_SeW082[] = _("SEーW082");

SOUND_CHECK_DATA static const u8 sText_SeW047[] = _("SEーW047");

SOUND_CHECK_DATA static const u8 sText_SeW195[] = _("SEーW195");

SOUND_CHECK_DATA static const u8 sText_SeW006[] = _("SEーW006");

SOUND_CHECK_DATA static const u8 sText_SeW091[] = _("SEーW091");

SOUND_CHECK_DATA static const u8 sText_SeW146[] = _("SEーW146");

SOUND_CHECK_DATA static const u8 sText_SeW120[] = _("SEーW120");

SOUND_CHECK_DATA static const u8 sText_SeW153[] = _("SEーW153");

SOUND_CHECK_DATA static const u8 sText_SeW071B[] = _("SEーW071B");

SOUND_CHECK_DATA static const u8 sText_SeW071[] = _("SEーW071");

SOUND_CHECK_DATA static const u8 sText_SeW103[] = _("SEーW103");

SOUND_CHECK_DATA static const u8 sText_SeW062[] = _("SEーW062");

SOUND_CHECK_DATA static const u8 sText_SeW062B[] = _("SEーW062B");

SOUND_CHECK_DATA static const u8 sText_SeW048[] = _("SEーW048");

SOUND_CHECK_DATA static const u8 sText_SeW187[] = _("SEーW187");

SOUND_CHECK_DATA static const u8 sText_SeW118[] = _("SEーW118");

SOUND_CHECK_DATA static const u8 sText_SeW155[] = _("SEーW155");

SOUND_CHECK_DATA static const u8 sText_SeW122[] = _("SEーW122");

SOUND_CHECK_DATA static const u8 sText_SeW060[] = _("SEーW060");

SOUND_CHECK_DATA static const u8 sText_SeW185[] = _("SEーW185");

SOUND_CHECK_DATA static const u8 sText_SeW014[] = _("SEーW014");

SOUND_CHECK_DATA static const u8 sText_SeW043[] = _("SEーW043");

SOUND_CHECK_DATA static const u8 sText_SeW207[] = _("SEーW207");

SOUND_CHECK_DATA static const u8 sText_SeW207B[] = _("SEーW207B");

SOUND_CHECK_DATA static const u8 sText_SeW215[] = _("SEーW215");

SOUND_CHECK_DATA static const u8 sText_SeW109[] = _("SEーW109");

SOUND_CHECK_DATA static const u8 sText_SeW173[] = _("SEーW173");

SOUND_CHECK_DATA static const u8 sText_SeW280[] = _("SEーW280");

SOUND_CHECK_DATA static const u8 sText_SeW202[] = _("SEーW202");

SOUND_CHECK_DATA static const u8 sText_SeW060B[] = _("SEーW060B");

SOUND_CHECK_DATA static const u8 sText_SeW076[] = _("SEーW076");

SOUND_CHECK_DATA static const u8 sText_SeW080[] = _("SEーW080");

SOUND_CHECK_DATA static const u8 sText_SeW100[] = _("SEーW100");

SOUND_CHECK_DATA static const u8 sText_SeW107[] = _("SEーW107");

SOUND_CHECK_DATA static const u8 sText_SeW166[] = _("SEーW166");

SOUND_CHECK_DATA static const u8 sText_SeW129[] = _("SEーW129");

SOUND_CHECK_DATA static const u8 sText_SeW115[] = _("SEーW115");

SOUND_CHECK_DATA static const u8 sText_SeW112[] = _("SEーW112");

SOUND_CHECK_DATA static const u8 sText_SeW197[] = _("SEーW197");

SOUND_CHECK_DATA static const u8 sText_SeW199[] = _("SEーW199");

SOUND_CHECK_DATA static const u8 sText_SeW236[] = _("SEーW236");

SOUND_CHECK_DATA static const u8 sText_SeW204[] = _("SEーW204");

SOUND_CHECK_DATA static const u8 sText_SeW268[] = _("SEーW268");

SOUND_CHECK_DATA static const u8 sText_SeW070[] = _("SEーW070");

SOUND_CHECK_DATA static const u8 sText_SeW063[] = _("SEーW063");

SOUND_CHECK_DATA static const u8 sText_SeW127[] = _("SEーW127");

SOUND_CHECK_DATA static const u8 sText_SeW179[] = _("SEーW179");

SOUND_CHECK_DATA static const u8 sText_SeW151[] = _("SEーW151");

SOUND_CHECK_DATA static const u8 sText_SeW201[] = _("SEーW201");

SOUND_CHECK_DATA static const u8 sText_SeW161[] = _("SEーW161");

SOUND_CHECK_DATA static const u8 sText_SeW161B[] = _("SEーW161B");

SOUND_CHECK_DATA static const u8 sText_SeW227[] = _("SEーW227");

SOUND_CHECK_DATA static const u8 sText_SeW227B[] = _("SEーW227B");

SOUND_CHECK_DATA static const u8 sText_SeW226[] = _("SEーW226");

SOUND_CHECK_DATA static const u8 sText_SeW208[] = _("SEーW208");

SOUND_CHECK_DATA static const u8 sText_SeW213[] = _("SEーW213");

SOUND_CHECK_DATA static const u8 sText_SeW213B[] = _("SEーW213B");

SOUND_CHECK_DATA static const u8 sText_SeW234[] = _("SEーW234");

SOUND_CHECK_DATA static const u8 sText_SeW260[] = _("SEーW260");

SOUND_CHECK_DATA static const u8 sText_SeW328[] = _("SEーW328");

SOUND_CHECK_DATA static const u8 sText_SeW320[] = _("SEーW320");

SOUND_CHECK_DATA static const u8 sText_SeW255[] = _("SEーW255");

SOUND_CHECK_DATA static const u8 sText_SeW291[] = _("SEーW291");

SOUND_CHECK_DATA static const u8 sText_SeW089[] = _("SEーW089");

SOUND_CHECK_DATA static const u8 sText_SeW239[] = _("SEーW239");

SOUND_CHECK_DATA static const u8 sText_SeW230[] = _("SEーW230");

SOUND_CHECK_DATA static const u8 sText_SeW281[] = _("SEーW281");

SOUND_CHECK_DATA static const u8 sText_SeW327[] = _("SEーW327");

SOUND_CHECK_DATA static const u8 sText_SeW287[] = _("SEーW287");

SOUND_CHECK_DATA static const u8 sText_SeW257[] = _("SEーW257");

SOUND_CHECK_DATA static const u8 sText_SeW253[] = _("SEーW253");

SOUND_CHECK_DATA static const u8 sText_SeW258[] = _("SEーW258");

SOUND_CHECK_DATA static const u8 sText_SeW322[] = _("SEーW322");

SOUND_CHECK_DATA static const u8 sText_SeW298[] = _("SEーW298");

SOUND_CHECK_DATA static const u8 sText_SeW287B[] = _("SEーW287B");

SOUND_CHECK_DATA static const u8 sText_SeW114[] = _("SEーW114");

SOUND_CHECK_DATA static const u8 sText_SeW063B[] = _("SEーW063B");

SOUND_CHECK_DATA static const u8 sText_SeRgWDoor[] = _("SEーRGーWーDOOR");

SOUND_CHECK_DATA static const u8 sText_SeRgCard1[] = _("SEーRGーCARD1");

SOUND_CHECK_DATA static const u8 sText_SeRgCard2[] = _("SEーRGーCARD2");

SOUND_CHECK_DATA static const u8 sText_SeRgCard3[] = _("SEーRGーCARD3");

SOUND_CHECK_DATA static const u8 sText_SeRgBag1[] = _("SEーRGーBAG1");

SOUND_CHECK_DATA static const u8 sText_SeRgBag2[] = _("SEーRGーBAG2");

SOUND_CHECK_DATA static const u8 sText_SeRgGetting[] = _("SEーRGーGETTING");

SOUND_CHECK_DATA static const u8 sText_SeRgShop[] = _("SEーRGーSHOP");

SOUND_CHECK_DATA static const u8 sText_SeRgKiteki[] = _("SEーRGーKITEKI");

SOUND_CHECK_DATA static const u8 sText_SeRgHelpOp[] = _("SEーRGーHELPーOP");

SOUND_CHECK_DATA static const u8 sText_SeRgHelpCl[] = _("SEーRGーHELPーCL");

SOUND_CHECK_DATA static const u8 sText_SeRgHelpNg[] = _("SEーRGーHELPーNG");

SOUND_CHECK_DATA static const u8 sText_SeRgDeomov[] = _("SEーRGーDEOMOV");

SOUND_CHECK_DATA static const u8 sText_SeRgExcellent[] = _("SEーRGーEXCELLENT");

SOUND_CHECK_DATA static const u8 sText_SeRgNawamiss[] = _("SEーRGーNAWAMISS");

SOUND_CHECK_DATA static const u8 sText_SeToreeye[] = _("SEーTOREEYE");

SOUND_CHECK_DATA static const u8 sText_SeToreoff[] = _("SEーTOREOFF");

SOUND_CHECK_DATA static const u8 sText_SeHantei1[] = _("SEーHANTEI1");

SOUND_CHECK_DATA static const u8 sText_SeHantei2[] = _("SEーHANTEI2");

SOUND_CHECK_DATA static const u8 sText_SeCurtain[] = _("SEーCURTAIN");

SOUND_CHECK_DATA static const u8 sText_SeCurtain1[] = _("SEーCURTAIN1");

SOUND_CHECK_DATA static const u8 sText_SeUssoki[] = _("SEーUSSOKI");

SOUND_CHECK_DATA static const u8 sText_MusTetsuji[] = _("MUSーTETSUJI");

SOUND_CHECK_DATA static const u8 sText_MusField13[] = _("MUSーFIELD13");

SOUND_CHECK_DATA static const u8 sText_MusKachi22[] = _("MUSーKACHI22");

SOUND_CHECK_DATA static const u8 sText_MusKachi2[] = _("MUSーKACHI2");

SOUND_CHECK_DATA static const u8 sText_MusKachi3[] = _("MUSーKACHI3");

SOUND_CHECK_DATA static const u8 sText_MusKachi5[] = _("MUSーKACHI5");

SOUND_CHECK_DATA static const u8 sText_MusPcc[] = _("MUSーPCC");

SOUND_CHECK_DATA static const u8 sText_MusNibi[] = _("MUSーNIBI");

SOUND_CHECK_DATA static const u8 sText_MusSuikun[] = _("MUSーSUIKUN");

SOUND_CHECK_DATA static const u8 sText_MusDooro1[] = _("MUSーDOORO1");

SOUND_CHECK_DATA static const u8 sText_MusDooroX1[] = _("MUSーDOOROーX1");

SOUND_CHECK_DATA static const u8 sText_MusDooroX3[] = _("MUSーDOOROーX3");

SOUND_CHECK_DATA static const u8 sText_MusMachiS2[] = _("MUSーMACHIーS2");

SOUND_CHECK_DATA static const u8 sText_MusMachiS4[] = _("MUSーMACHIーS4");

SOUND_CHECK_DATA static const u8 sText_MusGim[] = _("MUSーGIM");

SOUND_CHECK_DATA static const u8 sText_MusNaminori[] = _("MUSーNAMINORI");

SOUND_CHECK_DATA static const u8 sText_MusDan01[] = _("MUSーDAN01");

SOUND_CHECK_DATA static const u8 sText_MusFanfa1[] = _("MUSーFANFA1");

SOUND_CHECK_DATA static const u8 sText_MusMeAsa[] = _("MUSーMEーASA");

SOUND_CHECK_DATA static const u8 sText_MusMeBachi[] = _("MUSーMEーBACHI");

SOUND_CHECK_DATA static const u8 sText_MusFanfa4[] = _("MUSーFANFA4");

SOUND_CHECK_DATA static const u8 sText_MusFanfa5[] = _("MUSーFANFA5");

SOUND_CHECK_DATA static const u8 sText_MusMeWaza[] = _("MUSーMEーWAZA");

SOUND_CHECK_DATA static const u8 sText_MusBijyutu[] = _("MUSーBIJYUTU");

SOUND_CHECK_DATA static const u8 sText_MusDooroX4[] = _("MUSーDOOROーX4");

SOUND_CHECK_DATA static const u8 sText_MusFuneKan[] = _("MUSーFUNEーKAN");

SOUND_CHECK_DATA static const u8 sText_MusMeShinka[] = _("MUSーMEーSHINKA");

SOUND_CHECK_DATA static const u8 sText_MusShinka[] = _("MUSーSHINKA");

SOUND_CHECK_DATA static const u8 sText_MusMeWasure[] = _("MUSーMEーWASURE");

SOUND_CHECK_DATA static const u8 sText_MusSyoujoeye[] = _("MUSーSYOUJOEYE");

SOUND_CHECK_DATA static const u8 sText_MusBoyeye[] = _("MUSーBOYEYE");

SOUND_CHECK_DATA static const u8 sText_MusDan02[] = _("MUSーDAN02");

SOUND_CHECK_DATA static const u8 sText_MusMachiS3[] = _("MUSーMACHIーS3");

SOUND_CHECK_DATA static const u8 sText_MusOdamaki[] = _("MUSーODAMAKI");

SOUND_CHECK_DATA static const u8 sText_MusBTower[] = _("MUSーBーTOWER");

SOUND_CHECK_DATA static const u8 sText_MusSwimeye[] = _("MUSーSWIMEYE");

SOUND_CHECK_DATA static const u8 sText_MusDan03[] = _("MUSーDAN03");

SOUND_CHECK_DATA static const u8 sText_MusMeKinomi[] = _("MUSーMEーKINOMI");

SOUND_CHECK_DATA static const u8 sText_MusMeTama[] = _("MUSーMEーTAMA");

SOUND_CHECK_DATA static const u8 sText_MusMeBBig[] = _("MUSーMEーBーBIG");

SOUND_CHECK_DATA static const u8 sText_MusMeBSmall[] = _("MUSーMEーBーSMALL");

SOUND_CHECK_DATA static const u8 sText_MusMeZannen[] = _("MUSーMEーZANNEN");

SOUND_CHECK_DATA static const u8 sText_MusBdTime[] = _("MUSーBDーTIME");

SOUND_CHECK_DATA static const u8 sText_MusTest1[] = _("MUSーTEST1");

SOUND_CHECK_DATA static const u8 sText_MusTest2[] = _("MUSーTEST2");

SOUND_CHECK_DATA static const u8 sText_MusTest3[] = _("MUSーTEST3");

SOUND_CHECK_DATA static const u8 sText_MusTest4[] = _("MUSーTEST4");

SOUND_CHECK_DATA static const u8 sText_MusTest[] = _("MUSーTEST");

SOUND_CHECK_DATA static const u8 sText_MusGomachi0[] = _("MUSーGOMACHI0");

SOUND_CHECK_DATA static const u8 sText_MusGotown[] = _("MUSーGOTOWN");

SOUND_CHECK_DATA static const u8 sText_MusPokecen[] = _("MUSーPOKECEN");

SOUND_CHECK_DATA static const u8 sText_MusNextroad[] = _("MUSーNEXTROAD");

SOUND_CHECK_DATA static const u8 sText_MusGranroad[] = _("MUSーGRANROAD");

SOUND_CHECK_DATA static const u8 sText_MusCycling[] = _("MUSーCYCLING");

SOUND_CHECK_DATA static const u8 sText_MusFriendly[] = _("MUSーFRIENDLY");

SOUND_CHECK_DATA static const u8 sText_MusMishiro[] = _("MUSーMISHIRO");

SOUND_CHECK_DATA static const u8 sText_MusTozan[] = _("MUSーTOZAN");

SOUND_CHECK_DATA static const u8 sText_MusGirleye[] = _("MUSーGIRLEYE");

SOUND_CHECK_DATA static const u8 sText_MusMinamo[] = _("MUSーMINAMO");

SOUND_CHECK_DATA static const u8 sText_MusAshroad[] = _("MUSーASHROAD");

SOUND_CHECK_DATA static const u8 sText_MusEvent0[] = _("MUSーEVENT0");

SOUND_CHECK_DATA static const u8 sText_MusDeepdeep[] = _("MUSーDEEPDEEP");

SOUND_CHECK_DATA static const u8 sText_MusKachi1[] = _("MUSーKACHI1");

SOUND_CHECK_DATA static const u8 sText_MusTitle3[] = _("MUSーTITLE3");

SOUND_CHECK_DATA static const u8 sText_MusDemo1[] = _("MUSーDEMO1");

SOUND_CHECK_DATA static const u8 sText_MusGirlSup[] = _("MUSーGIRLーSUP");

SOUND_CHECK_DATA static const u8 sText_MusHageshii[] = _("MUSーHAGESHII");

SOUND_CHECK_DATA static const u8 sText_MusKakkoii[] = _("MUSーKAKKOII");

SOUND_CHECK_DATA static const u8 sText_MusKazanbai[] = _("MUSーKAZANBAI");

SOUND_CHECK_DATA static const u8 sText_MusAqa0[] = _("MUSーAQAー0");

SOUND_CHECK_DATA static const u8 sText_MusTsuretek[] = _("MUSーTSURETEK");

SOUND_CHECK_DATA static const u8 sText_MusBoySup[] = _("MUSーBOYーSUP");

SOUND_CHECK_DATA static const u8 sText_MusRainbow[] = _("MUSーRAINBOW");

SOUND_CHECK_DATA static const u8 sText_MusAyasii[] = _("MUSーAYASII");

SOUND_CHECK_DATA static const u8 sText_MusKachi4[] = _("MUSーKACHI4");

SOUND_CHECK_DATA static const u8 sText_MusRopeway[] = _("MUSーROPEWAY");

SOUND_CHECK_DATA static const u8 sText_MusCasino[] = _("MUSーCASINO");

SOUND_CHECK_DATA static const u8 sText_MusHightown[] = _("MUSーHIGHTOWN");

SOUND_CHECK_DATA static const u8 sText_MusSafari[] = _("MUSーSAFARI");

SOUND_CHECK_DATA static const u8 sText_MusCRoad[] = _("MUSーCーROAD");

SOUND_CHECK_DATA static const u8 sText_MusAjito[] = _("MUSーAJITO");

SOUND_CHECK_DATA static const u8 sText_MusMBoat[] = _("MUSーMーBOAT");

SOUND_CHECK_DATA static const u8 sText_MusMDungon[] = _("MUSーMーDUNGON");

SOUND_CHECK_DATA static const u8 sText_MusFinecity[] = _("MUSーFINECITY");

SOUND_CHECK_DATA static const u8 sText_MusMachupi[] = _("MUSーMACHUPI");

SOUND_CHECK_DATA static const u8 sText_MusPSchool[] = _("MUSーPーSCHOOL");

SOUND_CHECK_DATA static const u8 sText_MusDendou[] = _("MUSーDENDOU");

SOUND_CHECK_DATA static const u8 sText_MusTonekusa[] = _("MUSーTONEKUSA");

SOUND_CHECK_DATA static const u8 sText_MusMaborosi[] = _("MUSーMABOROSI");

SOUND_CHECK_DATA static const u8 sText_MusConFan[] = _("MUSーCONーFAN");

SOUND_CHECK_DATA static const u8 sText_MusContest0[] = _("MUSーCONTEST0");

SOUND_CHECK_DATA static const u8 sText_MusMgm0[] = _("MUSーMGM0");

SOUND_CHECK_DATA static const u8 sText_MusTBattle[] = _("MUSーTーBATTLE");

SOUND_CHECK_DATA static const u8 sText_MusOoame[] = _("MUSーOOAME");

SOUND_CHECK_DATA static const u8 sText_MusHideri[] = _("MUSーHIDERI");

SOUND_CHECK_DATA static const u8 sText_MusRunecity[] = _("MUSーRUNECITY");

SOUND_CHECK_DATA static const u8 sText_MusConK[] = _("MUSーCONーK");

SOUND_CHECK_DATA static const u8 sText_MusEikouR[] = _("MUSーEIKOUーR");

SOUND_CHECK_DATA static const u8 sText_MusKarakuri[] = _("MUSーKARAKURI");

SOUND_CHECK_DATA static const u8 sText_MusHutago[] = _("MUSーHUTAGO");

SOUND_CHECK_DATA static const u8 sText_MusSitennou[] = _("MUSーSITENNOU");

SOUND_CHECK_DATA static const u8 sText_MusYamaEye[] = _("MUSーYAMAーEYE");

SOUND_CHECK_DATA static const u8 sText_MusConlobby[] = _("MUSーCONLOBBY");

SOUND_CHECK_DATA static const u8 sText_MusInterV[] = _("MUSーINTERーV");

SOUND_CHECK_DATA static const u8 sText_MusDaigo[] = _("MUSーDAIGO");

SOUND_CHECK_DATA static const u8 sText_MusThankfor[] = _("MUSーTHANKFOR");

SOUND_CHECK_DATA static const u8 sText_MusEnd[] = _("MUSーEND");

SOUND_CHECK_DATA static const u8 sText_MusBFrontier[] = _("MUSーBーFRONTIER");

SOUND_CHECK_DATA static const u8 sText_MusBArena[] = _("MUSーBーARENA");

SOUND_CHECK_DATA static const u8 sText_MusMePointget[] = _("MUSーMEーPOINTGET");

SOUND_CHECK_DATA static const u8 sText_MusMeToreEye[] = _("MUSーMEーTOREーEYE");

SOUND_CHECK_DATA static const u8 sText_MusPyramid[] = _("MUSーPYRAMID");

SOUND_CHECK_DATA static const u8 sText_MusPyramidTop[] = _("MUSーPYRAMIDーTOP");

SOUND_CHECK_DATA static const u8 sText_MusBPalace[] = _("MUSーBーPALACE");

SOUND_CHECK_DATA static const u8 sText_MusRekkuuKourin[] = _("MUSーREKKUUーKOURIN");

SOUND_CHECK_DATA static const u8 sText_MusSattower[] = _("MUSーSATTOWER");

SOUND_CHECK_DATA static const u8 sText_MusMeSymbolget[] = _("MUSーMEーSYMBOLGET");

SOUND_CHECK_DATA static const u8 sText_MusBDome[] = _("MUSーBーDOME");

SOUND_CHECK_DATA static const u8 sText_MusBTube[] = _("MUSーBーTUBE");

SOUND_CHECK_DATA static const u8 sText_MusBFactory[] = _("MUSーBーFACTORY");

SOUND_CHECK_DATA static const u8 sText_MusVsRekku[] = _("MUSーVSーREKKU");

SOUND_CHECK_DATA static const u8 sText_MusVsFront[] = _("MUSーVSーFRONT");

SOUND_CHECK_DATA static const u8 sText_MusVsMew[] = _("MUSーVSーMEW");

SOUND_CHECK_DATA static const u8 sText_MusBDome1[] = _("MUSーBーDOME1");

SOUND_CHECK_DATA static const u8 sText_MusBattle27[] = _("MUSーBATTLE27");

SOUND_CHECK_DATA static const u8 sText_MusBattle31[] = _("MUSーBATTLE31");

SOUND_CHECK_DATA static const u8 sText_MusBattle20[] = _("MUSーBATTLE20");

SOUND_CHECK_DATA static const u8 sText_MusBattle32[] = _("MUSーBATTLE32");

SOUND_CHECK_DATA static const u8 sText_MusBattle33[] = _("MUSーBATTLE33");

SOUND_CHECK_DATA static const u8 sText_MusBattle36[] = _("MUSーBATTLE36");

SOUND_CHECK_DATA static const u8 sText_MusBattle34[] = _("MUSーBATTLE34");

SOUND_CHECK_DATA static const u8 sText_MusBattle35[] = _("MUSーBATTLE35");

SOUND_CHECK_DATA static const u8 sText_MusBattle38[] = _("MUSーBATTLE38");

SOUND_CHECK_DATA static const u8 sText_MusBattle30[] = _("MUSーBATTLE30");

SOUND_CHECK_DATA static const u8 sText_MusRgAnnai[] = _("MUSーRGーANNAI");

SOUND_CHECK_DATA static const u8 sText_MusRgSlot[] = _("MUSーRGーSLOT");

SOUND_CHECK_DATA static const u8 sText_MusRgAjito[] = _("MUSーRGーAJITO");

SOUND_CHECK_DATA static const u8 sText_MusRgGym[] = _("MUSーRGーGYM");

SOUND_CHECK_DATA static const u8 sText_MusRgPurin[] = _("MUSーRGーPURIN");

SOUND_CHECK_DATA static const u8 sText_MusRgDemo[] = _("MUSーRGーDEMO");

SOUND_CHECK_DATA static const u8 sText_MusRgTitle[] = _("MUSーRGーTITLE");

SOUND_CHECK_DATA static const u8 sText_MusRgGuren[] = _("MUSーRGーGUREN");

SOUND_CHECK_DATA static const u8 sText_MusRgShion[] = _("MUSーRGーSHION");

SOUND_CHECK_DATA static const u8 sText_MusRgKaihuku[] = _("MUSーRGーKAIHUKU");

SOUND_CHECK_DATA static const u8 sText_MusRgCycling[] = _("MUSーRGーCYCLING");

SOUND_CHECK_DATA static const u8 sText_MusRgRocket[] = _("MUSーRGーROCKET");

SOUND_CHECK_DATA static const u8 sText_MusRgShoujo[] = _("MUSーRGーSHOUJO");

SOUND_CHECK_DATA static const u8 sText_MusRgShounen[] = _("MUSーRGーSHOUNEN");

SOUND_CHECK_DATA static const u8 sText_MusRgDendou[] = _("MUSーRGーDENDOU");

SOUND_CHECK_DATA static const u8 sText_MusRgTMori[] = _("MUSーRGーTーMORI");

SOUND_CHECK_DATA static const u8 sText_MusRgOtsukimi[] = _("MUSーRGーOTSUKIMI");

SOUND_CHECK_DATA static const u8 sText_MusRgPokeyashi[] = _("MUSーRGーPOKEYASHI");

SOUND_CHECK_DATA static const u8 sText_MusRgEnding[] = _("MUSーRGーENDING");

SOUND_CHECK_DATA static const u8 sText_MusRgLoad01[] = _("MUSーRGーLOAD01");

SOUND_CHECK_DATA static const u8 sText_MusRgOpening[] = _("MUSーRGーOPENING");

SOUND_CHECK_DATA static const u8 sText_MusRgLoad02[] = _("MUSーRGーLOAD02");

SOUND_CHECK_DATA static const u8 sText_MusRgLoad03[] = _("MUSーRGーLOAD03");

SOUND_CHECK_DATA static const u8 sText_MusRgChampR[] = _("MUSーRGーCHAMPーR");

SOUND_CHECK_DATA static const u8 sText_MusRgVsGym[] = _("MUSーRGーVSーGYM");

SOUND_CHECK_DATA static const u8 sText_MusRgVsTore[] = _("MUSーRGーVSーTORE");

SOUND_CHECK_DATA static const u8 sText_MusRgVsYasei[] = _("MUSーRGーVSーYASEI");

SOUND_CHECK_DATA static const u8 sText_MusRgVsLast[] = _("MUSーRGーVSーLAST");

SOUND_CHECK_DATA static const u8 sText_MusRgMasara[] = _("MUSーRGーMASARA");

SOUND_CHECK_DATA static const u8 sText_MusRgKenkyu[] = _("MUSーRGーKENKYU");

SOUND_CHECK_DATA static const u8 sText_MusRgOhkido[] = _("MUSーRGーOHKIDO");

SOUND_CHECK_DATA static const u8 sText_MusRgPokecen[] = _("MUSーRGーPOKECEN");

SOUND_CHECK_DATA static const u8 sText_MusRgSantoan[] = _("MUSーRGーSANTOAN");

SOUND_CHECK_DATA static const u8 sText_MusRgNaminori[] = _("MUSーRGーNAMINORI");

SOUND_CHECK_DATA static const u8 sText_MusRgPTower[] = _("MUSーRGーPーTOWER");

SOUND_CHECK_DATA static const u8 sText_MusRgShiruhu[] = _("MUSーRGーSHIRUHU");

SOUND_CHECK_DATA static const u8 sText_MusRgHanada[] = _("MUSーRGーHANADA");

SOUND_CHECK_DATA static const u8 sText_MusRgTamamusi[] = _("MUSーRGーTAMAMUSI");

SOUND_CHECK_DATA static const u8 sText_MusRgWinTre[] = _("MUSーRGーWINーTRE");

SOUND_CHECK_DATA static const u8 sText_MusRgWinYasei[] = _("MUSーRGーWINーYASEI");

SOUND_CHECK_DATA static const u8 sText_MusRgWinGym[] = _("MUSーRGーWINーGYM");

SOUND_CHECK_DATA static const u8 sText_MusRgKuchiba[] = _("MUSーRGーKUCHIBA");

SOUND_CHECK_DATA static const u8 sText_MusRgNibi[] = _("MUSーRGーNIBI");

SOUND_CHECK_DATA static const u8 sText_MusRgRival1[] = _("MUSーRGーRIVAL1");

SOUND_CHECK_DATA static const u8 sText_MusRgRival2[] = _("MUSーRGーRIVAL2");

SOUND_CHECK_DATA static const u8 sText_MusRgFan2[] = _("MUSーRGーFAN2");

SOUND_CHECK_DATA static const u8 sText_MusRgFan5[] = _("MUSーRGーFAN5");

SOUND_CHECK_DATA static const u8 sText_MusRgFan6[] = _("MUSーRGーFAN6");

SOUND_CHECK_DATA static const u8 sText_MusMeRgPhoto[] = _("MUSーMEーRGーPHOTO");

SOUND_CHECK_DATA static const u8 sText_MusRgTitlerog[] = _("MUSーRGーTITLEROG");

SOUND_CHECK_DATA static const u8 sText_MusRgGetYasei[] = _("MUSーRGーGETーYASEI");

SOUND_CHECK_DATA static const u8 sText_MusRgSousa[] = _("MUSーRGーSOUSA");

SOUND_CHECK_DATA static const u8 sText_MusRgSekaikan[] = _("MUSーRGーSEKAIKAN");

SOUND_CHECK_DATA static const u8 sText_MusRgSeibetu[] = _("MUSーRGーSEIBETU");

SOUND_CHECK_DATA static const u8 sText_MusRgJump[] = _("MUSーRGーJUMP");

SOUND_CHECK_DATA static const u8 sText_MusRgUnion[] = _("MUSーRGーUNION");

SOUND_CHECK_DATA static const u8 sText_MusRgNetwork[] = _("MUSーRGーNETWORK");

SOUND_CHECK_DATA static const u8 sText_MusRgOkurimono[] = _("MUSーRGーOKURIMONO");

SOUND_CHECK_DATA static const u8 sText_MusRgKinomikui[] = _("MUSーRGーKINOMIKUI");

SOUND_CHECK_DATA static const u8 sText_MusRgNanadungeon[] = _("MUSーRGーNANADUNGEON");

SOUND_CHECK_DATA static const u8 sText_MusRgOshieTv[] = _("MUSーRGーOSHIEーTV");

SOUND_CHECK_DATA static const u8 sText_MusRgNanashima[] = _("MUSーRGーNANASHIMA");

SOUND_CHECK_DATA static const u8 sText_MusRgNanaiseki[] = _("MUSーRGーNANAISEKI");

SOUND_CHECK_DATA static const u8 sText_MusRgNana123[] = _("MUSーRGーNANA123");

SOUND_CHECK_DATA static const u8 sText_MusRgNana45[] = _("MUSーRGーNANA45");

SOUND_CHECK_DATA static const u8 sText_MusRgNana67[] = _("MUSーRGーNANA67");

SOUND_CHECK_DATA static const u8 sText_MusRgPokefue[] = _("MUSーRGーPOKEFUE");

SOUND_CHECK_DATA static const u8 sText_MusRgVsDeo[] = _("MUSーRGーVSーDEO");

SOUND_CHECK_DATA static const u8 sText_MusRgVsMyu2[] = _("MUSーRGーVSーMYU2");

SOUND_CHECK_DATA static const u8 sText_MusRgVsDen[] = _("MUSーRGーVSーDEN");

SOUND_CHECK_DATA static const u8 sText_MusRgExeye[] = _("MUSーRGーEXEYE");

SOUND_CHECK_DATA static const u8 sText_MusRgDeoeye[] = _("MUSーRGーDEOEYE");

SOUND_CHECK_DATA static const u8 sText_MusRgTTower[] = _("MUSーRGーTーTOWER");

SOUND_CHECK_DATA static const u8 sText_MusRgSlowmasara[] = _("MUSーRGーSLOWMASARA");

SOUND_CHECK_DATA static const u8 sText_MusRgTvnoize[] = _("MUSーRGーTVNOIZE");

SOUND_CHECK_DATA static const u8 sNamePadding[] = {0};

SOUND_CHECK_DATA static const u8 *const sSoundEffectNames[] =
{
    [0] = sText_Stop,
    [SE_USE_ITEM] = sText_SeKaifuku,
    [SE_PC_LOGIN] = sText_SePcLogin,
    [SE_PC_OFF] = sText_SePcOff,
    [SE_PC_ON] = sText_SePcOn,
    [SE_SELECT] = sText_SeSelect,
    [SE_WIN_OPEN] = sText_SeWinOpen,
    [SE_WALL_HIT] = sText_SeWallHit,
    [SE_DOOR] = sText_SeDoor,
    [SE_EXIT] = sText_SeKaidan,
    [SE_LEDGE] = sText_SeDansa,
    [SE_BIKE_BELL] = sText_SeJitensya,
    [SE_NOT_EFFECTIVE] = sText_SeKoukaL,
    [SE_EFFECTIVE] = sText_SeKoukaM,
    [SE_SUPER_EFFECTIVE] = sText_SeKoukaH,
    [SE_BALL_OPEN] = sText_SeBowa2,
    [SE_FAINT] = sText_SePokeDead,
    [SE_FLEE] = sText_SeNigeru,
    [SE_SLIDING_DOOR] = sText_SeJidoDoa,
    [SE_SHIP] = sText_SeNaminori,
    [SE_BANG] = sText_SeBan,
    [SE_PIN] = sText_SePin,
    [SE_BOO] = sText_SeBoo,
    [SE_BALL] = sText_SeBowa,
    [SE_CONTEST_PLACE] = sText_SeJyuni,
    [SE_A] = sText_SeA,
    [SE_I] = sText_SeI,
    [SE_U] = sText_SeU,
    [SE_E] = sText_SeE,
    [SE_O] = sText_SeO,
    [SE_N] = sText_SeN,
    [SE_SUCCESS] = sText_SeSeikai,
    [SE_FAILURE] = sText_SeHazure,
    [SE_EXP] = sText_SeExp,
    [SE_BIKE_HOP] = sText_SeJitePyoko,
    [SE_SWITCH] = sText_SeMuPachi,
    [SE_CLICK] = sText_SeTkKasya,
    [SE_FU_ZAKU] = sText_SeFuZaku,
    [SE_CONTEST_CONDITION_LOSE] = sText_SeFuZaku2,
    [SE_LAVARIDGE_FALL_WARP] = sText_SeFuZuzuzu,
    [SE_ICE_STAIRS] = sText_SeRuGashin,
    [SE_ICE_BREAK] = sText_SeRuGasyan,
    [SE_ICE_CRACK] = sText_SeRuBari,
    [SE_FALL] = sText_SeRuHyuu,
    [SE_UNLOCK] = sText_SeKiGasyan,
    [SE_WARP_IN] = sText_SeTkWarpin,
    [SE_WARP_OUT] = sText_SeTkWarpout,
    [SE_REPEL] = sText_SeTuSaa,
    [SE_ROTATING_GATE] = sText_SeHiTurun,
    [SE_TRUCK_MOVE] = sText_SeTrackMove,
    [SE_TRUCK_STOP] = sText_SeTrackStop,
    [SE_TRUCK_UNLOAD] = sText_SeTrackHaiki,
    [SE_TRUCK_DOOR] = sText_SeTrackDoor,
    [SE_BERRY_BLENDER] = sText_SeMoter,
    [SE_CARD] = sText_SeCard,
    [SE_SAVE] = sText_SeSave,
    [SE_BALL_BOUNCE_1] = sText_SeKon,
    [SE_BALL_BOUNCE_2] = sText_SeKon2,
    [SE_BALL_BOUNCE_3] = sText_SeKon3,
    [SE_BALL_BOUNCE_4] = sText_SeKon4,
    [SE_BALL_TRADE] = sText_SeSuikomu,
    [SE_BALL_THROW] = sText_SeNageru,
    [SE_NOTE_C] = sText_SeToyC,
    [SE_NOTE_D] = sText_SeToyD,
    [SE_NOTE_E] = sText_SeToyE,
    [SE_NOTE_F] = sText_SeToyF,
    [SE_NOTE_G] = sText_SeToyG,
    [SE_NOTE_A] = sText_SeToyA,
    [SE_NOTE_B] = sText_SeToyB,
    [SE_NOTE_C_HIGH] = sText_SeToyC1,
    [SE_PUDDLE] = sText_SeMizu,
    [SE_BRIDGE_WALK] = sText_SeHashi,
    [SE_ITEMFINDER] = sText_SeDaugi,
    [SE_DING_DONG] = sText_SePinpon,
    [SE_BALLOON_RED] = sText_SeFuusen1,
    [SE_BALLOON_BLUE] = sText_SeFuusen2,
    [SE_BALLOON_YELLOW] = sText_SeFuusen3,
    [SE_BREAKABLE_DOOR] = sText_SeToyKabe,
    [SE_MUD_BALL] = sText_SeToyDango,
    [SE_FIELD_POISON] = sText_SeDoku,
    [SE_ESCALATOR] = sText_SeEsuka,
    [SE_THUNDERSTORM] = sText_SeTAme,
    [SE_THUNDERSTORM_STOP] = sText_SeTAmeE,
    [SE_DOWNPOUR] = sText_SeTOoame,
    [SE_DOWNPOUR_STOP] = sText_SeTOoameE,
    [SE_RAIN] = sText_SeTKoame,
    [SE_RAIN_STOP] = sText_SeTKoameE,
    [SE_THUNDER] = sText_SeTKami,
    [SE_THUNDER2] = sText_SeTKami2,
    [SE_ELEVATOR] = sText_SeElebeta,
    [SE_LOW_HEALTH] = sText_SeHinsi,
    [SE_EXP_MAX] = sText_SeExpmax,
    [SE_ROULETTE_BALL] = sText_SeTamakoro,
    [SE_ROULETTE_BALL2] = sText_SeTamakoroE,
    [SE_TAILLOW_WING_FLAP] = sText_SeBasabasa,
    [SE_SHOP] = sText_SeRegi,
    [SE_CONTEST_HEART] = sText_SeCGaji,
    [SE_CONTEST_CURTAIN_RISE] = sText_SeCMakuU,
    [SE_CONTEST_CURTAIN_FALL] = sText_SeCMakuD,
    [SE_CONTEST_ICON_CHANGE] = sText_SeCPasi,
    [SE_CONTEST_ICON_CLEAR] = sText_SeCSyu,
    [SE_CONTEST_MONS_TURN] = sText_SeCPikon,
    [SE_SHINY] = sText_SeReapoke,
    [SE_INTRO_BLAST] = sText_SeOpBasyu,
    [SE_MUGSHOT] = sText_SeBtStart,
    [SE_APPLAUSE] = sText_SeDendou,
    [SE_VEND] = sText_SeJihanki,
    [SE_ORB] = sText_SeTama,
    [SE_DEX_SCROLL] = sText_SeZScroll,
    [SE_DEX_PAGE] = sText_SeZPage,
    [SE_POKENAV_ON] = sText_SePnOn,
    [SE_POKENAV_OFF] = sText_SePnOff,
    [SE_DEX_SEARCH] = sText_SeZSearch,
    [SE_EGG_HATCH] = sText_SeTamago,
    [SE_BALL_TRAY_ENTER] = sText_SeTbStart,
    [SE_BALL_TRAY_BALL] = sText_SeTbKon,
    [SE_BALL_TRAY_EXIT] = sText_SeTbKara,
    [SE_GLASS_FLUTE] = sText_SeBidoro,
    [SE_M_THUNDERBOLT] = sText_SeW085,
    [SE_M_THUNDERBOLT2] = sText_SeW085B,
    [SE_M_HARDEN] = sText_SeW231,
    [SE_M_NIGHTMARE] = sText_SeW171,
    [SE_M_VITAL_THROW] = sText_SeW233,
    [SE_M_VITAL_THROW2] = sText_SeW233B,
    [SE_M_BUBBLE] = sText_SeW145,
    [SE_M_BUBBLE2] = sText_SeW145B,
    [SE_M_BUBBLE3] = sText_SeW145C,
    [SE_M_RAIN_DANCE] = sText_SeW240,
    [SE_M_CUT] = sText_SeW015,
    [SE_M_STRING_SHOT] = sText_SeW081,
    [SE_M_STRING_SHOT2] = sText_SeW081B,
    [SE_M_ROCK_THROW] = sText_SeW088,
    [SE_M_GUST] = sText_SeW016,
    [SE_M_GUST2] = sText_SeW016B,
    [SE_M_DOUBLE_SLAP] = sText_SeW003,
    [SE_M_DOUBLE_TEAM] = sText_SeW104,
    [SE_M_RAZOR_WIND] = sText_SeW013,
    [SE_M_ICY_WIND] = sText_SeW196,
    [SE_M_THUNDER_WAVE] = sText_SeW086,
    [SE_M_COMET_PUNCH] = sText_SeW004,
    [SE_M_MEGA_KICK] = sText_SeW025,
    [SE_M_MEGA_KICK2] = sText_SeW025B,
    [SE_M_CRABHAMMER] = sText_SeW152,
    [SE_M_JUMP_KICK] = sText_SeW026,
    [SE_M_FLAME_WHEEL] = sText_SeW172,
    [SE_M_FLAME_WHEEL2] = sText_SeW172B,
    [SE_M_FLAMETHROWER] = sText_SeW053,
    [SE_M_FIRE_PUNCH] = sText_SeW007,
    [SE_M_TOXIC] = sText_SeW092,
    [SE_M_SACRED_FIRE] = sText_SeW221,
    [SE_M_SACRED_FIRE2] = sText_SeW221B,
    [SE_M_EMBER] = sText_SeW052,
    [SE_M_TAKE_DOWN] = sText_SeW036,
    [SE_M_BLIZZARD] = sText_SeW059,
    [SE_M_BLIZZARD2] = sText_SeW059B,
    [SE_M_SCRATCH] = sText_SeW010,
    [SE_M_VICEGRIP] = sText_SeW011,
    [SE_M_WING_ATTACK] = sText_SeW017,
    [SE_M_FLY] = sText_SeW019,
    [SE_M_SAND_ATTACK] = sText_SeW028,
    [SE_M_RAZOR_WIND2] = sText_SeW013B,
    [SE_M_BITE] = sText_SeW044,
    [SE_M_HEADBUTT] = sText_SeW029,
    [SE_M_SURF] = sText_SeW057,
    [SE_M_HYDRO_PUMP] = sText_SeW056,
    [SE_M_WHIRLPOOL] = sText_SeW250,
    [SE_M_HORN_ATTACK] = sText_SeW030,
    [SE_M_TAIL_WHIP] = sText_SeW039,
    [SE_M_MIST] = sText_SeW054,
    [SE_M_POISON_POWDER] = sText_SeW077,
    [SE_M_BIND] = sText_SeW020,
    [SE_M_DRAGON_RAGE] = sText_SeW082,
    [SE_M_SING] = sText_SeW047,
    [SE_M_PERISH_SONG] = sText_SeW195,
    [SE_M_PAY_DAY] = sText_SeW006,
    [SE_M_DIG] = sText_SeW091,
    [SE_M_DIZZY_PUNCH] = sText_SeW146,
    [SE_M_SELF_DESTRUCT] = sText_SeW120,
    [SE_M_EXPLOSION] = sText_SeW153,
    [SE_M_ABSORB_2] = sText_SeW071B,
    [SE_M_ABSORB] = sText_SeW071,
    [SE_M_SCREECH] = sText_SeW103,
    [SE_M_BUBBLE_BEAM] = sText_SeW062,
    [SE_M_BUBBLE_BEAM2] = sText_SeW062B,
    [SE_M_SUPERSONIC] = sText_SeW048,
    [SE_M_BELLY_DRUM] = sText_SeW187,
    [SE_M_METRONOME] = sText_SeW118,
    [SE_M_BONEMERANG] = sText_SeW155,
    [SE_M_LICK] = sText_SeW122,
    [SE_M_PSYBEAM] = sText_SeW060,
    [SE_M_FAINT_ATTACK] = sText_SeW185,
    [SE_M_SWORDS_DANCE] = sText_SeW014,
    [SE_M_LEER] = sText_SeW043,
    [SE_M_SWAGGER] = sText_SeW207,
    [SE_M_SWAGGER2] = sText_SeW207B,
    [SE_M_HEAL_BELL] = sText_SeW215,
    [SE_M_CONFUSE_RAY] = sText_SeW109,
    [SE_M_SNORE] = sText_SeW173,
    [SE_M_BRICK_BREAK] = sText_SeW280,
    [SE_M_GIGA_DRAIN] = sText_SeW202,
    [SE_M_PSYBEAM2] = sText_SeW060B,
    [SE_M_SOLAR_BEAM] = sText_SeW076,
    [SE_M_PETAL_DANCE] = sText_SeW080,
    [SE_M_TELEPORT] = sText_SeW100,
    [SE_M_MINIMIZE] = sText_SeW107,
    [SE_M_SKETCH] = sText_SeW166,
    [SE_M_SWIFT] = sText_SeW129,
    [SE_M_REFLECT] = sText_SeW115,
    [SE_M_BARRIER] = sText_SeW112,
    [SE_M_DETECT] = sText_SeW197,
    [SE_M_LOCK_ON] = sText_SeW199,
    [SE_M_MOONLIGHT] = sText_SeW236,
    [SE_M_CHARM] = sText_SeW204,
    [SE_M_CHARGE] = sText_SeW268,
    [SE_M_STRENGTH] = sText_SeW070,
    [SE_M_HYPER_BEAM] = sText_SeW063,
    [SE_M_WATERFALL] = sText_SeW127,
    [SE_M_REVERSAL] = sText_SeW179,
    [SE_M_ACID_ARMOR] = sText_SeW151,
    [SE_M_SANDSTORM] = sText_SeW201,
    [SE_M_TRI_ATTACK] = sText_SeW161,
    [SE_M_TRI_ATTACK2] = sText_SeW161B,
    [SE_M_ENCORE] = sText_SeW227,
    [SE_M_ENCORE2] = sText_SeW227B,
    [SE_M_BATON_PASS] = sText_SeW226,
    [SE_M_MILK_DRINK] = sText_SeW208,
    [SE_M_ATTRACT] = sText_SeW213,
    [SE_M_ATTRACT2] = sText_SeW213B,
    [SE_M_MORNING_SUN] = sText_SeW234,
    [SE_M_FLATTER] = sText_SeW260,
    [SE_M_SAND_TOMB] = sText_SeW328,
    [SE_M_GRASSWHISTLE] = sText_SeW320,
    [SE_M_SPIT_UP] = sText_SeW255,
    [SE_M_DIVE] = sText_SeW291,
    [SE_M_EARTHQUAKE] = sText_SeW089,
    [SE_M_TWISTER] = sText_SeW239,
    [SE_M_SWEET_SCENT] = sText_SeW230,
    [SE_M_YAWN] = sText_SeW281,
    [SE_M_SKY_UPPERCUT] = sText_SeW327,
    [SE_M_STAT_INCREASE] = sText_SeW287,
    [SE_M_HEAT_WAVE] = sText_SeW257,
    [SE_M_UPROAR] = sText_SeW253,
    [SE_M_HAIL] = sText_SeW258,
    [SE_M_COSMIC_POWER] = sText_SeW322,
    [SE_M_TEETER_DANCE] = sText_SeW298,
    [SE_M_STAT_DECREASE] = sText_SeW287B,
    [SE_M_HAZE] = sText_SeW114,
    [SE_M_HYPER_BEAM2] = sText_SeW063B,
    [SE_RG_DOOR] = sText_SeRgWDoor,
    [SE_RG_CARD_FLIP] = sText_SeRgCard1,
    [SE_RG_CARD_FLIPPING] = sText_SeRgCard2,
    [SE_RG_CARD_OPEN] = sText_SeRgCard3,
    [SE_RG_BAG_CURSOR] = sText_SeRgBag1,
    [SE_RG_BAG_POCKET] = sText_SeRgBag2,
    [SE_RG_BALL_CLICK] = sText_SeRgGetting,
    [SE_RG_SHOP] = sText_SeRgShop,
    [SE_RG_SS_ANNE_HORN] = sText_SeRgKiteki,
    [SE_RG_HELP_OPEN] = sText_SeRgHelpOp,
    [SE_RG_HELP_CLOSE] = sText_SeRgHelpCl,
    [SE_RG_HELP_ERROR] = sText_SeRgHelpNg,
    [SE_RG_DEOXYS_MOVE] = sText_SeRgDeomov,
    [SE_RG_POKE_JUMP_SUCCESS] = sText_SeRgExcellent,
    [SE_RG_POKE_JUMP_FAILURE] = sText_SeRgNawamiss,
    [SE_POKENAV_CALL] = sText_SeToreeye,
    [SE_POKENAV_HANG_UP] = sText_SeToreoff,
    [SE_ARENA_TIMEUP1] = sText_SeHantei1,
    [SE_ARENA_TIMEUP2] = sText_SeHantei2,
    [SE_PIKE_CURTAIN_CLOSE] = sText_SeCurtain,
    [SE_PIKE_CURTAIN_OPEN] = sText_SeCurtain1,
    [SE_SUDOWOODO_SHAKE] = sText_SeUssoki,
};

SOUND_CHECK_DATA static const u8 *const sMusicNames[] =
{
    [0] = sText_Stop,
    [MUS_LITTLEROOT_TEST - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTetsuji,
    [MUS_GSC_ROUTE38 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusField13,
    [MUS_CAUGHT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi22,
    [MUS_VICTORY_WILD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi2,
    [MUS_VICTORY_GYM_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi3,
    [MUS_VICTORY_LEAGUE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi5,
    [MUS_C_COMM_CENTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusPcc,
    [MUS_GSC_PEWTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusNibi,
    [MUS_C_VS_LEGEND_BEAST - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSuikun,
    [MUS_ROUTE101 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDooro1,
    [MUS_ROUTE110 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDooroX1,
    [MUS_ROUTE120 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDooroX3,
    [MUS_PETALBURG - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMachiS2,
    [MUS_OLDALE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMachiS4,
    [MUS_GYM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGim,
    [MUS_SURF - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusNaminori,
    [MUS_PETALBURG_WOODS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDan01,
    [MUS_LEVEL_UP - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFanfa1,
    [MUS_HEAL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeAsa,
    [MUS_OBTAIN_BADGE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeBachi,
    [MUS_OBTAIN_ITEM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFanfa4,
    [MUS_EVOLVED - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFanfa5,
    [MUS_OBTAIN_TMHM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeWaza,
    [MUS_LILYCOVE_MUSEUM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBijyutu,
    [MUS_ROUTE122 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDooroX4,
    [MUS_OCEANIC_MUSEUM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFuneKan,
    [MUS_EVOLUTION_INTRO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeShinka,
    [MUS_EVOLUTION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusShinka,
    [MUS_MOVE_DELETED - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeWasure,
    [MUS_ENCOUNTER_GIRL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSyoujoeye,
    [MUS_ENCOUNTER_MALE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBoyeye,
    [MUS_ABANDONED_SHIP - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDan02,
    [MUS_FORTREE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMachiS3,
    [MUS_BIRCH_LAB - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusOdamaki,
    [MUS_B_TOWER_RS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBTower,
    [MUS_ENCOUNTER_SWIMMER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSwimeye,
    [MUS_CAVE_OF_ORIGIN - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDan03,
    [MUS_OBTAIN_BERRY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeKinomi,
    [MUS_AWAKEN_LEGEND - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeTama,
    [MUS_SLOTS_JACKPOT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeBBig,
    [MUS_SLOTS_WIN - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeBSmall,
    [MUS_TOO_BAD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeZannen,
    [MUS_ROULETTE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBdTime,
    [MUS_LINK_CONTEST_P1 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTest1,
    [MUS_LINK_CONTEST_P2 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTest2,
    [MUS_LINK_CONTEST_P3 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTest3,
    [MUS_LINK_CONTEST_P4 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTest4,
    [MUS_ENCOUNTER_RICH - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTest,
    [MUS_VERDANTURF - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGomachi0,
    [MUS_RUSTBORO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGotown,
    [MUS_POKE_CENTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusPokecen,
    [MUS_ROUTE104 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusNextroad,
    [MUS_ROUTE119 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGranroad,
    [MUS_CYCLING - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusCycling,
    [MUS_POKE_MART - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFriendly,
    [MUS_LITTLEROOT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMishiro,
    [MUS_MT_CHIMNEY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTozan,
    [MUS_ENCOUNTER_FEMALE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGirleye,
    [MUS_LILYCOVE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMinamo,
    [MUS_DESERT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusAshroad,
    [MUS_HELP - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusEvent0,
    [MUS_UNDERWATER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDeepdeep,
    [MUS_VICTORY_TRAINER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi1,
    [MUS_TITLE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTitle3,
    [MUS_INTRO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDemo1,
    [MUS_ENCOUNTER_MAY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusGirlSup,
    [MUS_ENCOUNTER_INTENSE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusHageshii,
    [MUS_ENCOUNTER_COOL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKakkoii,
    [MUS_ROUTE113 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKazanbai,
    [MUS_ENCOUNTER_AQUA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusAqa0,
    [MUS_FOLLOW_ME - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTsuretek,
    [MUS_ENCOUNTER_BRENDAN - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBoySup,
    [MUS_EVER_GRANDE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRainbow,
    [MUS_ENCOUNTER_SUSPICIOUS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusAyasii,
    [MUS_VICTORY_AQUA_MAGMA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKachi4,
    [MUS_CABLE_CAR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRopeway,
    [MUS_GAME_CORNER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusCasino,
    [MUS_DEWFORD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusHightown,
    [MUS_SAFARI_ZONE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSafari,
    [MUS_VICTORY_ROAD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusCRoad,
    [MUS_AQUA_MAGMA_HIDEOUT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusAjito,
    [MUS_SAILING - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMBoat,
    [MUS_MT_PYRE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMDungon,
    [MUS_SLATEPORT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusFinecity,
    [MUS_MT_PYRE_EXTERIOR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMachupi,
    [MUS_SCHOOL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusPSchool,
    [MUS_HALL_OF_FAME - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDendou,
    [MUS_FALLARBOR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTonekusa,
    [MUS_SEALED_CHAMBER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMaborosi,
    [MUS_CONTEST_WINNER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusConFan,
    [MUS_CONTEST - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusContest0,
    [MUS_ENCOUNTER_MAGMA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMgm0,
    [MUS_INTRO_BATTLE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusTBattle,
    [MUS_ABNORMAL_WEATHER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusOoame,
    [MUS_WEATHER_GROUDON - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusHideri,
    [MUS_SOOTOPOLIS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRunecity,
    [MUS_CONTEST_RESULTS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusConK,
    [MUS_HALL_OF_FAME_ROOM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusEikouR,
    [MUS_TRICK_HOUSE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusKarakuri,
    [MUS_ENCOUNTER_TWINS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusHutago,
    [MUS_ENCOUNTER_ELITE_FOUR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSitennou,
    [MUS_ENCOUNTER_HIKER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusYamaEye,
    [MUS_CONTEST_LOBBY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusConlobby,
    [MUS_ENCOUNTER_INTERVIEWER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusInterV,
    [MUS_ENCOUNTER_CHAMPION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusDaigo,
    [MUS_CREDITS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusThankfor,
    [MUS_END - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusEnd,
    [MUS_B_FRONTIER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBFrontier,
    [MUS_B_ARENA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBArena,
    [MUS_OBTAIN_B_POINTS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMePointget,
    [MUS_REGISTER_MATCH_CALL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeToreEye,
    [MUS_B_PYRAMID - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusPyramid,
    [MUS_B_PYRAMID_TOP - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusPyramidTop,
    [MUS_B_PALACE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBPalace,
    [MUS_RAYQUAZA_APPEARS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRekkuuKourin,
    [MUS_B_TOWER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusSattower,
    [MUS_OBTAIN_SYMBOL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeSymbolget,
    [MUS_B_DOME - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBDome,
    [MUS_B_PIKE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBTube,
    [MUS_B_FACTORY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBFactory,
    [MUS_VS_RAYQUAZA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusVsRekku,
    [MUS_VS_FRONTIER_BRAIN - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusVsFront,
    [MUS_VS_MEW - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusVsMew,
    [MUS_B_DOME_LOBBY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBDome1,
    [MUS_VS_WILD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle27,
    [MUS_VS_AQUA_MAGMA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle31,
    [MUS_VS_TRAINER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle20,
    [MUS_VS_GYM_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle32,
    [MUS_VS_CHAMPION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle33,
    [MUS_VS_REGI - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle36,
    [MUS_VS_KYOGRE_GROUDON - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle34,
    [MUS_VS_RIVAL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle35,
    [MUS_VS_ELITE_FOUR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle38,
    [MUS_VS_AQUA_MAGMA_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusBattle30,
    [MUS_RG_FOLLOW_ME - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgAnnai,
    [MUS_RG_GAME_CORNER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSlot,
    [MUS_RG_ROCKET_HIDEOUT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgAjito,
    [MUS_RG_GYM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgGym,
    [MUS_RG_JIGGLYPUFF - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgPurin,
    [MUS_RG_INTRO_FIGHT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgDemo,
    [MUS_RG_TITLE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTitle,
    [MUS_RG_CINNABAR - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgGuren,
    [MUS_RG_LAVENDER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgShion,
    [MUS_RG_HEAL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgKaihuku,
    [MUS_RG_CYCLING - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgCycling,
    [MUS_RG_ENCOUNTER_ROCKET - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgRocket,
    [MUS_RG_ENCOUNTER_GIRL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgShoujo,
    [MUS_RG_ENCOUNTER_BOY - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgShounen,
    [MUS_RG_HALL_OF_FAME - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgDendou,
    [MUS_RG_VIRIDIAN_FOREST - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTMori,
    [MUS_RG_MT_MOON - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgOtsukimi,
    [MUS_RG_POKE_MANSION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgPokeyashi,
    [MUS_RG_CREDITS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgEnding,
    [MUS_RG_ROUTE1 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgLoad01,
    [MUS_RG_ROUTE24 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgOpening,
    [MUS_RG_ROUTE3 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgLoad02,
    [MUS_RG_ROUTE11 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgLoad03,
    [MUS_RG_VICTORY_ROAD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgChampR,
    [MUS_RG_VS_GYM_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsGym,
    [MUS_RG_VS_TRAINER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsTore,
    [MUS_RG_VS_WILD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsYasei,
    [MUS_RG_VS_CHAMPION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsLast,
    [MUS_RG_PALLET - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgMasara,
    [MUS_RG_OAK_LAB - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgKenkyu,
    [MUS_RG_OAK - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgOhkido,
    [MUS_RG_POKE_CENTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgPokecen,
    [MUS_RG_SS_ANNE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSantoan,
    [MUS_RG_SURF - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNaminori,
    [MUS_RG_POKE_TOWER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgPTower,
    [MUS_RG_SILPH - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgShiruhu,
    [MUS_RG_FUCHSIA - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgHanada,
    [MUS_RG_CELADON - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTamamusi,
    [MUS_RG_VICTORY_TRAINER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgWinTre,
    [MUS_RG_VICTORY_WILD - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgWinYasei,
    [MUS_RG_VICTORY_GYM_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgWinGym,
    [MUS_RG_VERMILLION - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgKuchiba,
    [MUS_RG_PEWTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNibi,
    [MUS_RG_ENCOUNTER_RIVAL - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgRival1,
    [MUS_RG_RIVAL_EXIT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgRival2,
    [MUS_RG_DEX_RATING - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgFan2,
    [MUS_RG_OBTAIN_KEY_ITEM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgFan5,
    [MUS_RG_CAUGHT_INTRO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgFan6,
    [MUS_RG_PHOTO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusMeRgPhoto,
    [MUS_RG_GAME_FREAK - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTitlerog,
    [MUS_RG_CAUGHT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgGetYasei,
    [MUS_RG_NEW_GAME_INSTRUCT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSousa,
    [MUS_RG_NEW_GAME_INTRO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSekaikan,
    [MUS_RG_NEW_GAME_EXIT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSeibetu,
    [MUS_RG_POKE_JUMP - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgJump,
    [MUS_RG_UNION_ROOM - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgUnion,
    [MUS_RG_NET_CENTER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNetwork,
    [MUS_RG_MYSTERY_GIFT - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgOkurimono,
    [MUS_RG_BERRY_PICK - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgKinomikui,
    [MUS_RG_SEVII_CAVE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNanadungeon,
    [MUS_RG_TEACHY_TV_SHOW - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgOshieTv,
    [MUS_RG_SEVII_ROUTE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNanashima,
    [MUS_RG_SEVII_DUNGEON - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNanaiseki,
    [MUS_RG_SEVII_123 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNana123,
    [MUS_RG_SEVII_45 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNana45,
    [MUS_RG_SEVII_67 - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgNana67,
    [MUS_RG_POKE_FLUTE - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgPokefue,
    [MUS_RG_VS_DEOXYS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsDeo,
    [MUS_RG_VS_MEWTWO - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsMyu2,
    [MUS_RG_VS_LEGEND - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgVsDen,
    [MUS_RG_ENCOUNTER_GYM_LEADER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgExeye,
    [MUS_RG_ENCOUNTER_DEOXYS - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgDeoeye,
    [MUS_RG_TRAINER_TOWER - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTTower,
    [MUS_RG_SLOW_PALLET - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgSlowmasara,
    [MUS_RG_TEACHY_TV_MENU - SOUND_CHECK_MUSIC_ID_BASE] = sText_MusRgTvnoize,
};

#undef SOUND_CHECK_DATA

#endif // GUARD_DATA_SOUND_CHECK_H
