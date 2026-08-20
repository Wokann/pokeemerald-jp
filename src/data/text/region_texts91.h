const u8 gUnknown_85CA976[] = _("メールは　1つうも　ありません{PAUSE_UNTIL_PRESS}");

const u8 gUnknown_85CA988[] = _(
    "{STR_VAR_1}　の\n"
    "メールを　どうしますか？");

const u8 gUnknown_85CA99A[] = _(
    "ないようは　きえてしまいますが\n"
    "よろしいですか？");

const u8 gUnknown_85CA9B3[] = _("バッグが　いっぱいです！{PAUSE_UNTIL_PRESS}");

const u8 gUnknown_85CA9C2[] = _(
    "ないようを　けした　メールを\n"
    "バッグに　いれました{PAUSE_UNTIL_PRESS}");

const u8 gUnknown_85CA9DE[] = _("パパ");

const u8 gUnknown_85CA9E1[] = _("ママ");

const u8 gUnknown_85CA9E4[] = _("ミクリ");

const u8 gUnknown_85CA9E8[] = _("ダイゴ");

const u8 gUnknown_85CA9EC[] = _("トウキ");

const u8 gUnknown_85CA9F0[] = _("ナギ");

const u8 gUnknown_85CA9F3[] = _("フヨウ");

const u8 gUnknown_85CA9F7[] = _("プリム$トウカ$カイナ$ミシロ$ミナモ$ムロ$さんか　する$せつめいをきく$ポケモンコンテストって？$コンテストの　しゅるい$ランクに　ついて$しんさいんに　ついて$かっこよさコンテスト$うつくしさコンテスト$かわいさコンテスト$かしこさコンテスト$たくましさコンテスト$もようがえ$ひっこし$カウント$とうろく　リスト$とうろく　せつめい$マッハ$ダート$どく$まひ$ねむり$やけど$こおり$どくどく$ふつう$よむのを　やめる$みました$これから");

// Script Menu aliases share the exact JP menu-text storage above.
#define SCRIPT_MENU_TEXT_ALIAS(name, offset) \
    __asm__(".global " #name "\n" \
            ".set " #name ", gUnknown_85CA9F7 + " #offset)

SCRIPT_MENU_TEXT_ALIAS(gText_Petalburg, 0x4);
SCRIPT_MENU_TEXT_ALIAS(gText_Slateport, 0x8);
SCRIPT_MENU_TEXT_ALIAS(gText_Dewford, 0x14);
SCRIPT_MENU_TEXT_ALIAS(gText_Enter2, 0x17);
SCRIPT_MENU_TEXT_ALIAS(gText_Info2, 0x1E);
SCRIPT_MENU_TEXT_ALIAS(gText_WhatsAContest, 0x26);
SCRIPT_MENU_TEXT_ALIAS(gText_TypesOfContests, 0x33);
SCRIPT_MENU_TEXT_ALIAS(gText_Ranks, 0x3F);
SCRIPT_MENU_TEXT_ALIAS(gText_CoolnessContest, 0x53);
SCRIPT_MENU_TEXT_ALIAS(gText_BeautyContest, 0x5E);
SCRIPT_MENU_TEXT_ALIAS(gText_CutenessContest, 0x69);
SCRIPT_MENU_TEXT_ALIAS(gText_SmartnessContest, 0x73);
SCRIPT_MENU_TEXT_ALIAS(gText_ToughnessContest, 0x7D);
SCRIPT_MENU_TEXT_ALIAS(gText_Decoration2, 0x88);
SCRIPT_MENU_TEXT_ALIAS(gText_PackUp, 0x8E);
SCRIPT_MENU_TEXT_ALIAS(gText_Registry, 0x98);
SCRIPT_MENU_TEXT_ALIAS(gText_Information, 0xA1);
SCRIPT_MENU_TEXT_ALIAS(gText_Mach, 0xAB);
SCRIPT_MENU_TEXT_ALIAS(gText_Acro, 0xAF);
SCRIPT_MENU_TEXT_ALIAS(gText_Psn, 0xB3);
SCRIPT_MENU_TEXT_ALIAS(gText_Par, 0xB6);
SCRIPT_MENU_TEXT_ALIAS(gText_Slp, 0xB9);
SCRIPT_MENU_TEXT_ALIAS(gText_Brn, 0xBD);
SCRIPT_MENU_TEXT_ALIAS(gText_Frz, 0xC1);
SCRIPT_MENU_TEXT_ALIAS(gText_SawIt, 0xD7);
SCRIPT_MENU_TEXT_ALIAS(gText_NotYet, 0xDC);
SCRIPT_MENU_TEXT_ALIAS(gText_SingleBattle, 0xED);
SCRIPT_MENU_TEXT_ALIAS(gText_DoubleBattle, 0xF5);
SCRIPT_MENU_TEXT_ALIAS(gText_MultiBattle, 0xFC);
SCRIPT_MENU_TEXT_ALIAS(gText_Challenge, 0x106);
SCRIPT_MENU_TEXT_ALIAS(gText_Info3, 0x10E);
SCRIPT_MENU_TEXT_ALIAS(gText_Lv50, 0x116);
SCRIPT_MENU_TEXT_ALIAS(gText_OpenLevel, 0x11C);
SCRIPT_MENU_TEXT_ALIAS(gText_FreshWaterAndPrice, 0x124);
SCRIPT_MENU_TEXT_ALIAS(gText_SodaPopAndPrice, 0x130);
SCRIPT_MENU_TEXT_ALIAS(gText_LemonadeAndPrice, 0x13C);
SCRIPT_MENU_TEXT_ALIAS(gText_HowToRide, 0x148);
SCRIPT_MENU_TEXT_ALIAS(gText_HowToTurn, 0x14E);
SCRIPT_MENU_TEXT_ALIAS(gText_SandySlopes, 0x154);
SCRIPT_MENU_TEXT_ALIAS(gText_Wheelies, 0x15A);
SCRIPT_MENU_TEXT_ALIAS(gText_BunnyHops, 0x15F);
SCRIPT_MENU_TEXT_ALIAS(gText_Jump, 0x164);
SCRIPT_MENU_TEXT_ALIAS(gText_Satisfied, 0x169);
SCRIPT_MENU_TEXT_ALIAS(gText_Dissatisfied, 0x16E);
SCRIPT_MENU_TEXT_ALIAS(gText_DeepSeaTooth, 0x172);
SCRIPT_MENU_TEXT_ALIAS(gText_DeepSeaScale, 0x17A);
SCRIPT_MENU_TEXT_ALIAS(gText_BlueFlute2, 0x183);
SCRIPT_MENU_TEXT_ALIAS(gText_YellowFlute2, 0x18B);
SCRIPT_MENU_TEXT_ALIAS(gText_RedFlute2, 0x193);
SCRIPT_MENU_TEXT_ALIAS(gText_WhiteFlute2, 0x19B);
SCRIPT_MENU_TEXT_ALIAS(gText_BlackFlute2, 0x1A3);
SCRIPT_MENU_TEXT_ALIAS(gText_GlassChair, 0x1AB);
SCRIPT_MENU_TEXT_ALIAS(gText_GlassDesk, 0x1B2);
SCRIPT_MENU_TEXT_ALIAS(gText_TreeckoDollAndPrice, 0x1BA);
SCRIPT_MENU_TEXT_ALIAS(gText_TorchicDollAndPrice, 0x1CA);
SCRIPT_MENU_TEXT_ALIAS(gText_MudkipDollAndPrice, 0x1DA);
SCRIPT_MENU_TEXT_ALIAS(gText_50CoinsAndPrice, 0x1EA);
SCRIPT_MENU_TEXT_ALIAS(gText_500CoinsAndPrice, 0x1F7);
SCRIPT_MENU_TEXT_ALIAS(gText_Excellent2, 0x204);
SCRIPT_MENU_TEXT_ALIAS(gText_NotSoGood, 0x209);
SCRIPT_MENU_TEXT_ALIAS(gText_RedShard, 0x20E);
SCRIPT_MENU_TEXT_ALIAS(gText_YellowShard, 0x215);
SCRIPT_MENU_TEXT_ALIAS(gText_BlueShard, 0x21D);
SCRIPT_MENU_TEXT_ALIAS(gText_GreenShard, 0x224);
SCRIPT_MENU_TEXT_ALIAS(gText_Right, 0x236);
SCRIPT_MENU_TEXT_ALIAS(gText_Left, 0x239);
SCRIPT_MENU_TEXT_ALIAS(gText_TM32AndPrice, 0x23D);
SCRIPT_MENU_TEXT_ALIAS(gText_TM29AndPrice, 0x24D);
SCRIPT_MENU_TEXT_ALIAS(gText_TM35AndPrice, 0x25D);
SCRIPT_MENU_TEXT_ALIAS(gText_TM24AndPrice, 0x26D);
SCRIPT_MENU_TEXT_ALIAS(gText_TM13AndPrice, 0x27D);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionPokedex, 0x3B7);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionPokemon, 0x3BB);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionBag, 0x3C0);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionPokenav, 0x3C4);
SCRIPT_MENU_TEXT_ALIAS(gText_Blank, 0x3C9);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionSave, 0x3CF);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionOption, 0x3D4);
SCRIPT_MENU_TEXT_ALIAS(gText_MenuOptionExit, 0x3D9);
SCRIPT_MENU_TEXT_ALIAS(gText_5BP, 0x3DD);
SCRIPT_MENU_TEXT_ALIAS(gText_10BP, 0x3E2);
SCRIPT_MENU_TEXT_ALIAS(gText_15BP, 0x3E7);
SCRIPT_MENU_TEXT_ALIAS(gText_RedTent, 0x3EC);
SCRIPT_MENU_TEXT_ALIAS(gText_BlueTent, 0x3F3);
SCRIPT_MENU_TEXT_ALIAS(gText_ClawFossil, 0x41A);
SCRIPT_MENU_TEXT_ALIAS(gText_RootFossil, 0x421);
SCRIPT_MENU_TEXT_ALIAS(gText_No4, 0x429);
SCRIPT_MENU_TEXT_ALIAS(gText_IllBattleNow, 0x42E);
SCRIPT_MENU_TEXT_ALIAS(gText_IWon, 0x439);
SCRIPT_MENU_TEXT_ALIAS(gText_ILost, 0x443);
SCRIPT_MENU_TEXT_ALIAS(gText_IWontTell, 0x44D);
SCRIPT_MENU_TEXT_ALIAS(gText_TradeCenter, 0x453);
SCRIPT_MENU_TEXT_ALIAS(gText_Colosseum, 0x45C);
SCRIPT_MENU_TEXT_ALIAS(gText_RecordCorner, 0x462);
SCRIPT_MENU_TEXT_ALIAS(gText_BerryCrush3, 0x46B);
SCRIPT_MENU_TEXT_ALIAS(gText_PokemonJump, 0x47D);
SCRIPT_MENU_TEXT_ALIAS(gText_DodrioBerryPicking, 0x489);
SCRIPT_MENU_TEXT_ALIAS(gText_BecomeLeader, 0x495);
SCRIPT_MENU_TEXT_ALIAS(gText_JoinGroup, 0x49D);
SCRIPT_MENU_TEXT_ALIAS(gText_TwoStyles, 0x4A6);
SCRIPT_MENU_TEXT_ALIAS(gText_Lv50_3, 0x4AD);
SCRIPT_MENU_TEXT_ALIAS(gText_OpenLevel2, 0x4B3);
SCRIPT_MENU_TEXT_ALIAS(gText_MonTypeAndNo, 0x4BB);
SCRIPT_MENU_TEXT_ALIAS(gText_HoldItems, 0x4C8);
SCRIPT_MENU_TEXT_ALIAS(gText_Symbols2, 0x4D0);
SCRIPT_MENU_TEXT_ALIAS(gText_Record3, 0x4D5);
SCRIPT_MENU_TEXT_ALIAS(gText_BattlePts, 0x4DE);
SCRIPT_MENU_TEXT_ALIAS(gText_TowerInfo, 0x4E6);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleMon, 0x4EE);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleSalon, 0x4F8);
SCRIPT_MENU_TEXT_ALIAS(gText_MultiLink2, 0x4FF);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleRules, 0x507);
SCRIPT_MENU_TEXT_ALIAS(gText_JudgeMind, 0x512);
SCRIPT_MENU_TEXT_ALIAS(gText_JudgeSkill, 0x51C);
SCRIPT_MENU_TEXT_ALIAS(gText_JudgeBody, 0x525);
SCRIPT_MENU_TEXT_ALIAS(gText_Matchup, 0x52F);
SCRIPT_MENU_TEXT_ALIAS(gText_TourneyTree, 0x535);
SCRIPT_MENU_TEXT_ALIAS(gText_DoubleKO, 0x53F);
SCRIPT_MENU_TEXT_ALIAS(gText_BasicRules, 0x549);
SCRIPT_MENU_TEXT_ALIAS(gText_SwapPartners, 0x550);
SCRIPT_MENU_TEXT_ALIAS(gText_SwapNumber, 0x559);
SCRIPT_MENU_TEXT_ALIAS(gText_SwapNotes, 0x563);
SCRIPT_MENU_TEXT_ALIAS(gText_OpenLevel3, 0x56D);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleBasics, 0x575);
SCRIPT_MENU_TEXT_ALIAS(gText_PokemonNature, 0x57E);
SCRIPT_MENU_TEXT_ALIAS(gText_PokemonMoves, 0x588);
SCRIPT_MENU_TEXT_ALIAS(gText_Underpowered, 0x590);
SCRIPT_MENU_TEXT_ALIAS(gText_WhenInDanger, 0x59C);
SCRIPT_MENU_TEXT_ALIAS(gText_PyramidPokemon, 0x5A5);
SCRIPT_MENU_TEXT_ALIAS(gText_PyramidTrainers, 0x5B1);
SCRIPT_MENU_TEXT_ALIAS(gText_PyramidMaze, 0x5BE);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleBag2, 0x5C9);
SCRIPT_MENU_TEXT_ALIAS(gText_PokenavAndBag, 0x5D0);
SCRIPT_MENU_TEXT_ALIAS(gText_HeldItems, 0x5DA);
SCRIPT_MENU_TEXT_ALIAS(gText_PokemonOrder, 0x5E3);
SCRIPT_MENU_TEXT_ALIAS(gText_BattlePokemon, 0x5EF);
SCRIPT_MENU_TEXT_ALIAS(gText_BattleTrainers, 0x5F8);
SCRIPT_MENU_TEXT_ALIAS(gText_GoOn, 0x603);
SCRIPT_MENU_TEXT_ALIAS(gText_Record2, 0x608);
SCRIPT_MENU_TEXT_ALIAS(gText_Rest, 0x60E);
SCRIPT_MENU_TEXT_ALIAS(gText_Retire, 0x612);
SCRIPT_MENU_TEXT_ALIAS(gText_1F, 0x680);
SCRIPT_MENU_TEXT_ALIAS(gText_2F, 0x684);
SCRIPT_MENU_TEXT_ALIAS(gText_3F, 0x688);
SCRIPT_MENU_TEXT_ALIAS(gText_4F, 0x68C);
SCRIPT_MENU_TEXT_ALIAS(gText_5F, 0x690);
SCRIPT_MENU_TEXT_ALIAS(gText_LilycoveCity, 0x796);
SCRIPT_MENU_TEXT_ALIAS(gText_CaveOfOrigin, 0x7A4);
SCRIPT_MENU_TEXT_ALIAS(gText_MtPyre, 0x7AC);
SCRIPT_MENU_TEXT_ALIAS(gText_SkyPillar, 0x7B3);
SCRIPT_MENU_TEXT_ALIAS(gText_DontRemember, 0x7BA);
#undef SCRIPT_MENU_TEXT_ALIAS
