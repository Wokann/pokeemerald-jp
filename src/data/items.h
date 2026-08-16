const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MASTER_BALL] =
    {
        .name = __("マスターボール$$"),
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = sMasterBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 0,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = __("ハイパーボール$$"),
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = sUltraBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 1,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 1,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = __("スーパーボール$$"),
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = sGreatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 2,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 2,
    },

    [ITEM_POKE_BALL] =
    {
        .name = __("モンスターボール$"),
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = sPokeBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 3,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 3,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = __("サファリボール$$"),
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = sSafariBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 4,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 4,
    },

    [ITEM_NET_BALL] =
    {
        .name = __("ネットボール$$$"),
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = sNetBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 5,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 5,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = __("ダイブボール$$$"),
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = sDiveBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 6,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 6,
    },

    [ITEM_NEST_BALL] =
    {
        .name = __("ネストボール$$$"),
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = sNestBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 7,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 7,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = __("リピートボール$$"),
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = sRepeatBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 8,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 8,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = __("タイマーボール$$"),
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = sTimerBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 9,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 9,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = __("ゴージャスボール$"),
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = sLuxuryBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 10,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 10,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = __("プレミアボール$$"),
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = sPremierBallDesc,
        .pocket = POCKET_POKE_BALLS,
        .type = 11,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_PokeBall,
        .secondaryId = 11,
    },

    [ITEM_POTION] =
    {
        .name = __("キズぐすり$$$$"),
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = __("どくけし$$$$$"),
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = sAntidoteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = __("やけどなおし$$$"),
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = sBurnHealDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = __("こおりなおし$$$"),
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = sIceHealDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_AWAKENING] =
    {
        .name = __("ねむけざまし$$$"),
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = sAwakeningDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = __("まひなおし$$$$"),
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = sParalyzeHealDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = __("かいふくのくすり$"),
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_POTION] =
    {
        .name = __("まんたんのくすり$"),
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = __("すごいキズぐすり$"),
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 200,
        .description = sHyperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = __("いいキズぐすり$$"),
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 50,
        .description = sSuperPotionDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = __("なんでもなおし$$"),
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = sFullHealDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVE] =
    {
        .name = __("げんきのかけら$$"),
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = sReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = __("げんきのかたまり$"),
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = __("おいしいみず$$$"),
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 50,
        .description = sFreshWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SODA_POP] =
    {
        .name = __("サイコソーダ$$$"),
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 60,
        .description = sSodaPopDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEMONADE] =
    {
        .name = __("ミックスオレ$$$"),
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 80,
        .description = sLemonadeDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = __("モーモーミルク$$"),
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = __("ちからのこな$$$"),
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = sEnergyPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = __("ちからのねっこ$$"),
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = sEnergyRootDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = __("ばんのうごな$$$"),
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = sHealPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = __("ふっかつそう$$$"),
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = sRevivalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ETHER] =
    {
        .name = __("ピーピーエイド$$"),
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = __("ピーピーリカバー$"),
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ELIXIR] =
    {
        .name = __("ピーピーエイダー$"),
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = __("ピーピーマックス$"),
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = __("フエンせんべい$$"),
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = sLavaCookieDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLUE_FLUTE] =
    {
        .name = __("あおいビードロ$$"),
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = sBlueFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = __("きいろビードロ$$"),
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = sYellowFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = __("あかいビードロ$$"),
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = sRedFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_BLACK_FLUTE] =
    {
        .name = __("くろいビードロ$$"),
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = __("しろいビードロ$$"),
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = __("きのみジュース$$"),
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffect = 1,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = __("せいなるはい$$$"),
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = sSacredAshDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
    },

    [ITEM_SHOAL_SALT] =
    {
        .name = __("あさせのしお$$$"),
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = sShoalSaltDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = __("あさせのかいがら$"),
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = sShoalShellDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SHARD] =
    {
        .name = __("あかいかけら$$$"),
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = sRedShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = __("あおいかけら$$$"),
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = sBlueShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = __("きいろいかけら$$"),
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = sYellowShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = __("みどりのかけら$$"),
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = sGreenShardDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_034] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_035] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_036] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_037] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_038] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_039] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03A] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03B] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03C] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03D] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_03E] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HP_UP] =
    {
        .name = __("マックスアップ$$"),
        .itemId = ITEM_HP_UP,
        .price = 9800,
        .description = sHPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PROTEIN] =
    {
        .name = __("タウリン$$$$$"),
        .itemId = ITEM_PROTEIN,
        .price = 9800,
        .description = sProteinDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_IRON] =
    {
        .name = __("ブロムヘキシン$$"),
        .itemId = ITEM_IRON,
        .price = 9800,
        .description = sIronDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CARBOS] =
    {
        .name = __("インドメタシン$$"),
        .itemId = ITEM_CARBOS,
        .price = 9800,
        .description = sCarbosDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_CALCIUM] =
    {
        .name = __("リゾチウム$$$$"),
        .itemId = ITEM_CALCIUM,
        .price = 9800,
        .description = sCalciumDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_RARE_CANDY] =
    {
        .name = __("ふしぎなアメ$$$"),
        .itemId = ITEM_RARE_CANDY,
        .price = 4800,
        .description = sRareCandyDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
    },

    [ITEM_PP_UP] =
    {
        .name = __("ポイントアップ$$"),
        .itemId = ITEM_PP_UP,
        .price = 9800,
        .description = sPPUpDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_ZINC] =
    {
        .name = __("キトサン$$$$$"),
        .itemId = ITEM_ZINC,
        .price = 9800,
        .description = sZincDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
    },

    [ITEM_PP_MAX] =
    {
        .name = __("ポイントマックス$"),
        .itemId = ITEM_PP_MAX,
        .price = 9800,
        .description = sPPMaxDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
    },

    [ITEM_048] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GUARD_SPEC] =
    {
        .name = __("エフェクトガード$"),
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = sGuardSpecDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = __("クリティカッター$"),
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = sDireHitDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ATTACK] =
    {
        .name = __("プラスパワー$$$"),
        .itemId = ITEM_X_ATTACK,
        .price = 500,
        .description = sXAttackDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_DEFEND] =
    {
        .name = __("ディフェンダー$$"),
        .itemId = ITEM_X_DEFEND,
        .price = 550,
        .description = sXDefendDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPEED] =
    {
        .name = __("スピーダー$$$$"),
        .itemId = ITEM_X_SPEED,
        .price = 350,
        .description = sXSpeedDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = __("ヨクアタール$$$"),
        .itemId = ITEM_X_ACCURACY,
        .price = 950,
        .description = sXAccuracyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_X_SPECIAL] =
    {
        .name = __("スペシャルアップ$"),
        .itemId = ITEM_X_SPECIAL,
        .price = 350,
        .description = sXSpecialDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_StatIncrease,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = __("ピッピにんぎょう$"),
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = __("エネコのシッポ$$"),
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = sFluffyTailDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_OTHER,
        .battleUseFunc = ItemUseInBattle_Escape,
    },

    [ITEM_052] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SUPER_REPEL] =
    {
        .name = __("シルバースプレー$"),
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = __("ゴールドスプレー$"),
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = __("あなぬけのヒモ$$"),
        .itemId = ITEM_ESCAPE_ROPE,
        .price = 550,
        .description = sEscapeRopeDesc,
        .pocket = POCKET_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
    },

    [ITEM_REPEL] =
    {
        .name = __("むしよけスプレー$"),
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
    },

    [ITEM_057] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_058] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_059] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05A] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05B] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_05C] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SUN_STONE] =
    {
        .name = __("たいようのいし$$"),
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = sSunStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_MOON_STONE] =
    {
        .name = __("つきのいし$$$$"),
        .itemId = ITEM_MOON_STONE,
        .price = 0,
        .description = sMoonStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_FIRE_STONE] =
    {
        .name = __("ほのおのいし$$$"),
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = sFireStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = __("かみなりのいし$$"),
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = sThunderStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_WATER_STONE] =
    {
        .name = __("みずのいし$$$$"),
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = sWaterStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = __("リーフのいし$$$"),
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = sLeafStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
    },

    [ITEM_063] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_064] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_065] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_066] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TINY_MUSHROOM] =
    {
        .name = __("ちいさなキノコ$$"),
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = sTinyMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = __("おおきなキノコ$$"),
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = sBigMushroomDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_069] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PEARL] =
    {
        .name = __("しんじゅ$$$$$"),
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = sPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = __("おおきなしんじゅ$"),
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = sBigPearlDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARDUST] =
    {
        .name = __("ほしのすな$$$$"),
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = sStardustDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = __("ほしのかけら$$$"),
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = sStarPieceDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NUGGET] =
    {
        .name = __("きんのたま$$$$"),
        .itemId = ITEM_NUGGET,
        .price = 10000,
        .description = sNuggetDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = __("ハートのウロコ$$"),
        .itemId = ITEM_HEART_SCALE,
        .price = 100,
        .description = sHeartScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_070] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_071] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_072] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_073] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_074] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_075] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_076] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_077] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_078] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ORANGE_MAIL] =
    {
        .name = __("オレンジメール$$"),
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = sOrangeMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = __("ハーバーメール$$"),
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = sHarborMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 1,
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = __("キラキラメール$$"),
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = sGlitterMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 2,
    },

    [ITEM_MECH_MAIL] =
    {
        .name = __("メカニカルメール$"),
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = sMechMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 3,
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = __("ウッディメール$$"),
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = sWoodMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 4,
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = __("クロスメール$$$"),
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = sWaveMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 5,
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = __("トレジャーメール$"),
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 6,
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = __("シャドーメール$$"),
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = sShadowMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 7,
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = __("トロピカルメール$"),
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = sTropicMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 8,
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = __("ドリームメール$$"),
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = sDreamMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 9,
    },

    [ITEM_FAB_MAIL] =
    {
        .name = __("ミラクルメール$$"),
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = sFabMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 10,
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = __("レトロメール$$$"),
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = sRetroMailDesc,
        .pocket = POCKET_ITEMS,
        .type = 0,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = 11,
    },

    [ITEM_CHERI_BERRY] =
    {
        .name = __("クラボのみ$$$$"),
        .itemId = ITEM_CHERI_BERRY,
        .price = 20,
        .holdEffect = 2,
        .description = sCheriBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = __("カゴのみ$$$$$"),
        .itemId = ITEM_CHESTO_BERRY,
        .price = 20,
        .holdEffect = 3,
        .description = sChestoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = __("モモンのみ$$$$"),
        .itemId = ITEM_PECHA_BERRY,
        .price = 20,
        .holdEffect = 4,
        .description = sPechaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = __("チーゴのみ$$$$"),
        .itemId = ITEM_RAWST_BERRY,
        .price = 20,
        .holdEffect = 5,
        .description = sRawstBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = __("ナナシのみ$$$$"),
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 20,
        .holdEffect = 6,
        .description = sAspearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = __("ヒメリのみ$$$$"),
        .itemId = ITEM_LEPPA_BERRY,
        .price = 20,
        .holdEffect = 7,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_PPRecovery,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = __("オレンのみ$$$$"),
        .itemId = ITEM_ORAN_BERRY,
        .price = 20,
        .holdEffect = 1,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = __("キーのみ$$$$$"),
        .itemId = ITEM_PERSIM_BERRY,
        .price = 20,
        .holdEffect = 8,
        .description = sPersimBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = __("ラムのみ$$$$$"),
        .itemId = ITEM_LUM_BERRY,
        .price = 20,
        .holdEffect = 9,
        .description = sLumBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = __("オボンのみ$$$$"),
        .itemId = ITEM_SITRUS_BERRY,
        .price = 20,
        .holdEffect = 1,
        .holdEffectParam = 30,
        .description = sSitrusBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_Medicine,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = __("フィラのみ$$$$"),
        .itemId = ITEM_FIGY_BERRY,
        .price = 20,
        .holdEffect = 10,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = __("ウイのみ$$$$$"),
        .itemId = ITEM_WIKI_BERRY,
        .price = 20,
        .holdEffect = 11,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = __("マゴのみ$$$$$"),
        .itemId = ITEM_MAGO_BERRY,
        .price = 20,
        .holdEffect = 12,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = __("バンジのみ$$$$"),
        .itemId = ITEM_AGUAV_BERRY,
        .price = 20,
        .holdEffect = 13,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = __("イアのみ$$$$$"),
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 20,
        .holdEffect = 14,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = __("ズリのみ$$$$$"),
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = sRazzBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = __("ブリーのみ$$$$"),
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = sBlukBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = __("ナナのみ$$$$$"),
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = sNanabBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = __("セシナのみ$$$$"),
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = sWepearBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = __("パイルのみ$$$$"),
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = sPinapBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = __("ザロクのみ$$$$"),
        .itemId = ITEM_POMEG_BERRY,
        .price = 20,
        .description = sPomegBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = __("ネコブのみ$$$$"),
        .itemId = ITEM_KELPSY_BERRY,
        .price = 20,
        .description = sKelpsyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = __("タポルのみ$$$$"),
        .itemId = ITEM_QUALOT_BERRY,
        .price = 20,
        .description = sQualotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = __("ロメのみ$$$$$"),
        .itemId = ITEM_HONDEW_BERRY,
        .price = 20,
        .description = sHondewBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = __("ウブのみ$$$$$"),
        .itemId = ITEM_GREPA_BERRY,
        .price = 20,
        .description = sGrepaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = __("マトマのみ$$$$"),
        .itemId = ITEM_TAMATO_BERRY,
        .price = 20,
        .description = sTamatoBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = __("モコシのみ$$$$"),
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = sCornnBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = __("ゴスのみ$$$$$"),
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = sMagostBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = __("ラブタのみ$$$$"),
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = sRabutaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = __("ノメルのみ$$$$"),
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = sNomelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = __("ノワキのみ$$$$"),
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = sSpelonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = __("シーヤのみ$$$$"),
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = sPamtreBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = __("カイスのみ$$$$"),
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = sWatmelBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = __("ドリのみ$$$$$"),
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = sDurinBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = __("ベリブのみ$$$$"),
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = sBelueBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = __("チイラのみ$$$$"),
        .itemId = ITEM_LIECHI_BERRY,
        .price = 20,
        .holdEffect = 15,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = __("リュガのみ$$$$"),
        .itemId = ITEM_GANLON_BERRY,
        .price = 20,
        .holdEffect = 16,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = __("カムラのみ$$$$"),
        .itemId = ITEM_SALAC_BERRY,
        .price = 20,
        .holdEffect = 17,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = __("ヤタピのみ$$$$"),
        .itemId = ITEM_PETAYA_BERRY,
        .price = 20,
        .holdEffect = 18,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = __("ズアのみ$$$$$"),
        .itemId = ITEM_APICOT_BERRY,
        .price = 20,
        .holdEffect = 19,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = __("サンのみ$$$$$"),
        .itemId = ITEM_LANSAT_BERRY,
        .price = 20,
        .holdEffect = 20,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = __("スターのみ$$$$"),
        .itemId = ITEM_STARF_BERRY,
        .price = 20,
        .holdEffect = 21,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = __("ナゾのみ$$$$$"),
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = sEnigmaBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = ITEM_B_USE_MEDICINE,
        .battleUseFunc = ItemUseInBattle_EnigmaBerry,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BRIGHT_POWDER] =
    {
        .name = __("ひかりのこな$$$"),
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffect = 22,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = __("しろいハーブ$$$"),
        .itemId = ITEM_WHITE_HERB,
        .price = 100,
        .holdEffect = 23,
        .description = sWhiteHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACHO_BRACE] =
    {
        .name = __("きょうせいギプス$"),
        .itemId = ITEM_MACHO_BRACE,
        .price = 3000,
        .holdEffect = 24,
        .description = sMachoBraceDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = __("がくしゅうそうち$"),
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .holdEffect = 25,
        .description = sExpShareDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = __("せんせいのツメ$$"),
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffect = 26,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = __("やすらぎのすず$$"),
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .holdEffect = 27,
        .description = sSootheBellDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = __("メンタルハーブ$$"),
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .holdEffect = 28,
        .description = sMentalHerbDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHOICE_BAND] =
    {
        .name = __("こだわりハチマキ$"),
        .itemId = ITEM_CHOICE_BAND,
        .price = 100,
        .holdEffect = 29,
        .description = sChoiceBandDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = __("おうじゃのしるし$"),
        .itemId = ITEM_KINGS_ROCK,
        .price = 100,
        .holdEffect = 30,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = __("ぎんのこな$$$$"),
        .itemId = ITEM_SILVER_POWDER,
        .price = 100,
        .holdEffect = 31,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = __("おまもりこばん$$"),
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffect = 32,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = __("きよめのおふだ$$"),
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .holdEffect = 33,
        .description = sCleanseTagDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = __("こころのしずく$$"),
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .holdEffect = 34,
        .description = sSoulDewDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = __("しんかいのキバ$$"),
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 200,
        .holdEffect = 35,
        .description = sDeepSeaToothDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = __("しんかいのウロコ$"),
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 200,
        .holdEffect = 36,
        .description = sDeepSeaScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = __("けむりだま$$$$"),
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .holdEffect = 37,
        .description = sSmokeBallDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EVERSTONE] =
    {
        .name = __("かわらずのいし$$"),
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .holdEffect = 38,
        .description = sEverstoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = __("きあいのハチマキ$"),
        .itemId = ITEM_FOCUS_BAND,
        .price = 200,
        .holdEffect = 39,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = __("しあわせタマゴ$$"),
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .holdEffect = 40,
        .description = sLuckyEggDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = __("ピントレンズ$$$"),
        .itemId = ITEM_SCOPE_LENS,
        .price = 200,
        .holdEffect = 41,
        .description = sScopeLensDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_COAT] =
    {
        .name = __("メタルコート$$$"),
        .itemId = ITEM_METAL_COAT,
        .price = 100,
        .holdEffect = 42,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = __("たべのこし$$$$"),
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffect = 43,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = __("りゅうのウロコ$$"),
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffect = 44,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIGHT_BALL] =
    {
        .name = __("でんきだま$$$$"),
        .itemId = ITEM_LIGHT_BALL,
        .price = 100,
        .holdEffect = 45,
        .description = sLightBallDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = __("やわらかいすな$$"),
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffect = 46,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HARD_STONE] =
    {
        .name = __("かたいいし$$$$"),
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffect = 47,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = __("きせきのタネ$$$"),
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffect = 48,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = __("くろいメガネ$$$"),
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffect = 49,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = __("くろおび$$$$$"),
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffect = 50,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGNET] =
    {
        .name = __("じしゃく$$$$$"),
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffect = 51,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = __("しんぴのしずく$$"),
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffect = 52,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = __("するどいくちばし$"),
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffect = 53,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POISON_BARB] =
    {
        .name = __("どくバリ$$$$$"),
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffect = 54,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = __("とけないこおり$$"),
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffect = 55,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = __("のろいのおふだ$$"),
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffect = 56,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = __("まがったスプーン$"),
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffect = 57,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CHARCOAL] =
    {
        .name = __("もくたん$$$$$"),
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffect = 58,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = __("りゅうのキバ$$$"),
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffect = 59,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILK_SCARF] =
    {
        .name = __("シルクのスカーフ$"),
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffect = 60,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_UP_GRADE] =
    {
        .name = __("アップグレード$$"),
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .holdEffect = 61,
        .description = sUpGradeDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = __("かいがらのすず$$"),
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffect = 62,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SEA_INCENSE] =
    {
        .name = __("うしおのおこう$$"),
        .itemId = ITEM_SEA_INCENSE,
        .price = 9600,
        .holdEffect = 52,
        .holdEffectParam = 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = __("のんきのおこう$$"),
        .itemId = ITEM_LAX_INCENSE,
        .price = 9600,
        .holdEffect = 22,
        .holdEffectParam = 5,
        .description = sLaxIncenseDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = __("ラッキーパンチ$$"),
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 10,
        .holdEffect = 63,
        .description = sLuckyPunchDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = __("メタルパウダー$$"),
        .itemId = ITEM_METAL_POWDER,
        .price = 10,
        .holdEffect = 64,
        .description = sMetalPowderDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = __("ふといホネ$$$$"),
        .itemId = ITEM_THICK_CLUB,
        .price = 500,
        .holdEffect = 65,
        .description = sThickClubDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STICK] =
    {
        .name = __("ながねぎ$$$$$"),
        .itemId = ITEM_STICK,
        .price = 200,
        .holdEffect = 66,
        .description = sStickDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E2] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E3] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E4] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E5] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E6] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E7] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E8] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0E9] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EA] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EB] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EC] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0ED] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EE] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0EF] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F0] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F1] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F2] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F3] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F4] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F5] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F6] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F7] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F8] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0F9] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FA] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FB] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FC] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_0FD] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RED_SCARF] =
    {
        .name = __("あかいバンダナ$$"),
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = sRedScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = __("あおいバンダナ$$"),
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = sBlueScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = __("ピンクのバンダナ$"),
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = sPinkScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = __("みどりのバンダナ$"),
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = sGreenScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = __("きいろのバンダナ$"),
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = sYellowScarfDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MACH_BIKE] =
    {
        .name = __("マッハじてんしゃ$"),
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = sMachBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
    },

    [ITEM_COIN_CASE] =
    {
        .name = __("コインケース$$$"),
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = sCoinCaseDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
    },

    [ITEM_ITEMFINDER] =
    {
        .name = __("ダウジングマシン$"),
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = sItemfinderDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
    },

    [ITEM_OLD_ROD] =
    {
        .name = __("ボロのつりざお$$"),
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = sOldRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = __("いいつりざお$$$"),
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = sGoodRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = 1,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = __("すごいつりざお$$"),
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = sSuperRodDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = 2,
    },

    [ITEM_SS_TICKET] =
    {
        .name = __("ふねのチケット$$"),
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = sSSTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = __("コンテストパス$$"),
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = sContestPassDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_10B] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = __("ホエルコじょうろ$"),
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = sWailmerPailDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
    },

    [ITEM_DEVON_GOODS] =
    {
        .name = __("デボンのにもつ$$"),
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = sDevonGoodsDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = __("はいぶくろ$$$$"),
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = sSootSackDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = __("ちかのカギ$$$$"),
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = sBasementKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = __("ダートじてんしゃ$"),
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = sAcroBikeDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = 1,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
        .name = __("ポロックケース$$"),
        .itemId = ITEM_POKEBLOCK_CASE,
        .price = 0,
        .description = sPokeblockCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 3,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
    },

    [ITEM_LETTER] =
    {
        .name = __("ダイゴへのてがみ$"),
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = sLetterDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_EON_TICKET] =
    {
        .name = __("むげんのチケット$"),
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = sEonTicketDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
        .name = __("べにいろのたま$$"),
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = sRedOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = __("あいいろのたま$$"),
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = sBlueOrbDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SCANNER] =
    {
        .name = __("たんちき$$$$$"),
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = sScannerDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = __("ゴーゴーゴーグル$"),
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = sGoGogglesDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_METEORITE] =
    {
        .name = __("いんせき$$$$$"),
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = sMeteoriteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .name = __("1ごうしつのカギ$"),
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = sRoom1KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .name = __("2ごうしつのカギ$"),
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = sRoom2KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .name = __("4ごうしつのカギ$"),
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = sRoom4KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .name = __("6ごうしつのカギ$"),
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = sRoom6KeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = __("そうこのカギ$$$"),
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = sStorageKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = __("ねっこのカセキ$$"),
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = sRootFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = __("ツメのカセキ$$$"),
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = sClawFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = __("デボンスコープ$$"),
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = sDevonScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TM01] =
    {
        .name = __("わざマシン01$$"),
        .itemId = ITEM_TM01,
        .price = 3000,
        .description = sItem289Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM02] =
    {
        .name = __("わざマシン02$$"),
        .itemId = ITEM_TM02,
        .price = 3000,
        .description = sItem290Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM03] =
    {
        .name = __("わざマシン03$$"),
        .itemId = ITEM_TM03,
        .price = 3000,
        .description = sItem291Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM04] =
    {
        .name = __("わざマシン04$$"),
        .itemId = ITEM_TM04,
        .price = 3000,
        .description = sItem292Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM05] =
    {
        .name = __("わざマシン05$$"),
        .itemId = ITEM_TM05,
        .price = 1000,
        .description = sItem293Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM06] =
    {
        .name = __("わざマシン06$$"),
        .itemId = ITEM_TM06,
        .price = 3000,
        .description = sItem294Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM07] =
    {
        .name = __("わざマシン07$$"),
        .itemId = ITEM_TM07,
        .price = 3000,
        .description = sItem295Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM08] =
    {
        .name = __("わざマシン08$$"),
        .itemId = ITEM_TM08,
        .price = 3000,
        .description = sItem296Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM09] =
    {
        .name = __("わざマシン09$$"),
        .itemId = ITEM_TM09,
        .price = 3000,
        .description = sItem297Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM10] =
    {
        .name = __("わざマシン10$$"),
        .itemId = ITEM_TM10,
        .price = 3000,
        .description = sItem298Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM11] =
    {
        .name = __("わざマシン11$$"),
        .itemId = ITEM_TM11,
        .price = 2000,
        .description = sItem299Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM12] =
    {
        .name = __("わざマシン12$$"),
        .itemId = ITEM_TM12,
        .price = 3000,
        .description = sItem300Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM13] =
    {
        .name = __("わざマシン13$$"),
        .itemId = ITEM_TM13,
        .price = 3000,
        .description = sItem301Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM14] =
    {
        .name = __("わざマシン14$$"),
        .itemId = ITEM_TM14,
        .price = 5500,
        .description = sItem302Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM15] =
    {
        .name = __("わざマシン15$$"),
        .itemId = ITEM_TM15,
        .price = 7500,
        .description = sItem303Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM16] =
    {
        .name = __("わざマシン16$$"),
        .itemId = ITEM_TM16,
        .price = 3000,
        .description = sItem304Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM17] =
    {
        .name = __("わざマシン17$$"),
        .itemId = ITEM_TM17,
        .price = 3000,
        .description = sItem305Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM18] =
    {
        .name = __("わざマシン18$$"),
        .itemId = ITEM_TM18,
        .price = 2000,
        .description = sItem306Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM19] =
    {
        .name = __("わざマシン19$$"),
        .itemId = ITEM_TM19,
        .price = 3000,
        .description = sItem307Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM20] =
    {
        .name = __("わざマシン20$$"),
        .itemId = ITEM_TM20,
        .price = 3000,
        .description = sItem308Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM21] =
    {
        .name = __("わざマシン21$$"),
        .itemId = ITEM_TM21,
        .price = 1000,
        .description = sItem309Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM22] =
    {
        .name = __("わざマシン22$$"),
        .itemId = ITEM_TM22,
        .price = 3000,
        .description = sItem310Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM23] =
    {
        .name = __("わざマシン23$$"),
        .itemId = ITEM_TM23,
        .price = 3000,
        .description = sItem311Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM24] =
    {
        .name = __("わざマシン24$$"),
        .itemId = ITEM_TM24,
        .price = 3000,
        .description = sItem312Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM25] =
    {
        .name = __("わざマシン25$$"),
        .itemId = ITEM_TM25,
        .price = 5500,
        .description = sItem313Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM26] =
    {
        .name = __("わざマシン26$$"),
        .itemId = ITEM_TM26,
        .price = 3000,
        .description = sItem314Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM27] =
    {
        .name = __("わざマシン27$$"),
        .itemId = ITEM_TM27,
        .price = 1000,
        .description = sItem315Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM28] =
    {
        .name = __("わざマシン28$$"),
        .itemId = ITEM_TM28,
        .price = 2000,
        .description = sItem316Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM29] =
    {
        .name = __("わざマシン29$$"),
        .itemId = ITEM_TM29,
        .price = 2000,
        .description = sItem317Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM30] =
    {
        .name = __("わざマシン30$$"),
        .itemId = ITEM_TM30,
        .price = 3000,
        .description = sItem318Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM31] =
    {
        .name = __("わざマシン31$$"),
        .itemId = ITEM_TM31,
        .price = 3000,
        .description = sItem319Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM32] =
    {
        .name = __("わざマシン32$$"),
        .itemId = ITEM_TM32,
        .price = 2000,
        .description = sItem320Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM33] =
    {
        .name = __("わざマシン33$$"),
        .itemId = ITEM_TM33,
        .price = 3000,
        .description = sItem321Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM34] =
    {
        .name = __("わざマシン34$$"),
        .itemId = ITEM_TM34,
        .price = 3000,
        .description = sItem322Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM35] =
    {
        .name = __("わざマシン35$$"),
        .itemId = ITEM_TM35,
        .price = 3000,
        .description = sItem323Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM36] =
    {
        .name = __("わざマシン36$$"),
        .itemId = ITEM_TM36,
        .price = 1000,
        .description = sItem324Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM37] =
    {
        .name = __("わざマシン37$$"),
        .itemId = ITEM_TM37,
        .price = 2000,
        .description = sItem325Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM38] =
    {
        .name = __("わざマシン38$$"),
        .itemId = ITEM_TM38,
        .price = 5500,
        .description = sItem326Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM39] =
    {
        .name = __("わざマシン39$$"),
        .itemId = ITEM_TM39,
        .price = 3000,
        .description = sItem327Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM40] =
    {
        .name = __("わざマシン40$$"),
        .itemId = ITEM_TM40,
        .price = 3000,
        .description = sItem328Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM41] =
    {
        .name = __("わざマシン41$$"),
        .itemId = ITEM_TM41,
        .price = 3000,
        .description = sItem329Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM42] =
    {
        .name = __("わざマシン42$$"),
        .itemId = ITEM_TM42,
        .price = 3000,
        .description = sItem330Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM43] =
    {
        .name = __("わざマシン43$$"),
        .itemId = ITEM_TM43,
        .price = 3000,
        .description = sItem331Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM44] =
    {
        .name = __("わざマシン44$$"),
        .itemId = ITEM_TM44,
        .price = 3000,
        .description = sItem332Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM45] =
    {
        .name = __("わざマシン45$$"),
        .itemId = ITEM_TM45,
        .price = 3000,
        .description = sItem333Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM46] =
    {
        .name = __("わざマシン46$$"),
        .itemId = ITEM_TM46,
        .price = 3000,
        .description = sItem334Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM47] =
    {
        .name = __("わざマシン47$$"),
        .itemId = ITEM_TM47,
        .price = 3000,
        .description = sItem335Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM48] =
    {
        .name = __("わざマシン48$$"),
        .itemId = ITEM_TM48,
        .price = 3000,
        .description = sItem336Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM49] =
    {
        .name = __("わざマシン49$$"),
        .itemId = ITEM_TM49,
        .price = 3000,
        .description = sItem337Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM50] =
    {
        .name = __("わざマシン50$$"),
        .itemId = ITEM_TM50,
        .price = 3000,
        .description = sItem338Desc,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM01] =
    {
        .name = __("ひでんマシン01$"),
        .itemId = ITEM_HM01,
        .price = 0,
        .description = sItem339Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM02] =
    {
        .name = __("ひでんマシン02$"),
        .itemId = ITEM_HM02,
        .price = 0,
        .description = sItem340Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM03] =
    {
        .name = __("ひでんマシン03$"),
        .itemId = ITEM_HM03,
        .price = 0,
        .description = sItem341Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM04] =
    {
        .name = __("ひでんマシン04$"),
        .itemId = ITEM_HM04,
        .price = 0,
        .description = sItem342Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM05] =
    {
        .name = __("ひでんマシン05$"),
        .itemId = ITEM_HM05,
        .price = 0,
        .description = sItem343Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM06] =
    {
        .name = __("ひでんマシン06$"),
        .itemId = ITEM_HM06,
        .price = 0,
        .description = sItem344Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM07] =
    {
        .name = __("ひでんマシン07$"),
        .itemId = ITEM_HM07,
        .price = 0,
        .description = sItem345Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM08] =
    {
        .name = __("ひでんマシン08$"),
        .itemId = ITEM_HM08,
        .price = 0,
        .description = sItem346Desc,
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = 1,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_15B] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_15C] =
    {
        .name = __("？？？？？？？？$"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .pocket = POCKET_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OAKS_PARCEL] =
    {
        .name = __("おとどけもの$$$"),
        .itemId = ITEM_OAKS_PARCEL,
        .price = 0,
        .description = sOaksParcelDesc,
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = __("ポケモンのふえ$$"),
        .itemId = ITEM_POKE_FLUTE,
        .price = 0,
        .description = sPokeFluteDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = __("ひみつのカギ$$$"),
        .itemId = ITEM_SECRET_KEY,
        .price = 0,
        .description = sSecretKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = __("ひきかえけん$$$"),
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = sBikeVoucherDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = __("きんのいれば$$$"),
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = sGoldTeethDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = __("ひみつのコハク$$"),
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = sOldAmberDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_CARD_KEY] =
    {
        .name = __("カードキー$$$$"),
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = sCardKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = __("エレベータのカギ$"),
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = sLiftKeyDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_HELIX_FOSSIL] =
    {
        .name = __("かいのカセキ$$$"),
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = sHelixFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = __("こうらのカセキ$$"),
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = sDomeFossilDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = __("シルフスコープ$$"),
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = sSilphScopeDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BICYCLE] =
    {
        .name = __("じてんしゃ$$$$"),
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = sBicycleDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = __("タウンマップ$$$"),
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = sTownMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = __("バトルサーチャー$"),
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = sVSSeekerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = __("ボイスチェッカー$"),
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = sFameCheckerDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TM_CASE] =
    {
        .name = __("わざマシンケース$"),
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = sTMCaseDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = __("きのみぶくろ$$$"),
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = sBerryPouchDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = __("おしえテレビ$$$"),
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = sTeachyTVDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 2,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TRI_PASS] =
    {
        .name = __("トライパス$$$$"),
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = sTriPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = __("レインボーパス$$"),
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = sRainbowPassDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_TEA] =
    {
        .name = __("おちゃ$$$$$$"),
        .itemId = ITEM_TEA,
        .price = 0,
        .description = sTeaDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = __("しんぴのチケット$"),
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = sMysticTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = __("オーロラチケット$"),
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = sAuroraTicketDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = __("こないれ$$$$$"),
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = sPowderJarDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
    },

    [ITEM_RUBY] =
    {
        .name = __("ルビー$$$$$$"),
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = sRubyDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = __("サファイア$$$$"),
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = sSapphireDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = __("マグマのしるし$$"),
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = sMagmaEmblemDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = __("ふるびたかいず$$"),
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = sOldSeaMapDesc,
        .importance = 1,
        .registrability = TRUE,
        .pocket = POCKET_KEY_ITEMS,
        .type = 4,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
    },

};
