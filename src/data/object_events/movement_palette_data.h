// Object-event palette, reflection-palette, and palette-tag data reconstructed
// from the JP ROM. The linker emits this complete family at 0x084E401C so its
// original order remains intact while the adjacent Berry Tree data remains in
// ASM.

// These values are the JP ROM palette tags. The original source did not yet
// name them, so keep the semantic pret names local to this data family.
enum
{
    OBJ_EVENT_PAL_TAG_BRENDAN                  = 0x1100,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION       = 0x1101,
    OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION        = 0x1102,
    OBJ_EVENT_PAL_TAG_NPC_1                    = 0x1103,
    OBJ_EVENT_PAL_TAG_NPC_2                    = 0x1104,
    OBJ_EVENT_PAL_TAG_NPC_3                    = 0x1105,
    OBJ_EVENT_PAL_TAG_NPC_4                    = 0x1106,
    OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION         = 0x1107,
    OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION         = 0x1108,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION         = 0x1109,
    OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION         = 0x110A,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP             = 0x110B,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION  = 0x110C,
    OBJ_EVENT_PAL_TAG_TRUCK                    = 0x110D,
    OBJ_EVENT_PAL_TAG_VIGOROTH                 = 0x110E,
    OBJ_EVENT_PAL_TAG_ZIGZAGOON                = 0x110F,
    OBJ_EVENT_PAL_TAG_MAY                      = 0x1110,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION           = 0x1111,
    OBJ_EVENT_PAL_TAG_MOVING_BOX               = 0x1112,
    OBJ_EVENT_PAL_TAG_CABLE_CAR                = 0x1113,
    OBJ_EVENT_PAL_TAG_SSTIDAL                  = 0x1114,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER        = 0x1115,
    OBJ_EVENT_PAL_TAG_KYOGRE                   = 0x1116,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION        = 0x1117,
    OBJ_EVENT_PAL_TAG_GROUDON                  = 0x1118,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION       = 0x1119,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW         = 0x111B,
    OBJ_EVENT_PAL_TAG_POOCHYENA                = 0x111C,
    OBJ_EVENT_PAL_TAG_RED_LEAF                 = 0x111D,
    OBJ_EVENT_PAL_TAG_DEOXYS                   = 0x111E,
    OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE       = 0x111F,
    OBJ_EVENT_PAL_TAG_HO_OH                    = 0x1120,
    OBJ_EVENT_PAL_TAG_LUGIA                    = 0x1121,
    OBJ_EVENT_PAL_TAG_RS_BRENDAN               = 0x1122,
    OBJ_EVENT_PAL_TAG_RS_MAY                   = 0x1123,
};

extern const u16 gObjectEventPal_Npc1[];
extern const u16 gObjectEventPal_Npc2[];
extern const u16 gObjectEventPal_Npc3[];
extern const u16 gObjectEventPal_Npc4[];
extern const u16 gObjectEventPal_Npc1Reflection[];
extern const u16 gObjectEventPal_Npc2Reflection[];
extern const u16 gObjectEventPal_Npc3Reflection[];
extern const u16 gObjectEventPal_Npc4Reflection[];
extern const u16 gObjectEventPal_Brendan[];
extern const u16 gObjectEventPal_BrendanReflection[];
extern const u16 gObjectEventPal_BridgeReflection[];
extern const u16 gObjectEventPal_PlayerUnderwater[];
extern const u16 gObjectEventPal_QuintyPlump[];
extern const u16 gObjectEventPal_QuintyPlumpReflection[];
extern const u16 gObjectEventPal_Truck[];
extern const u16 gObjectEventPal_Vigoroth[];
extern const u16 gObjectEventPal_EnemyZigzagoon[];
extern const u16 gObjectEventPal_May[];
extern const u16 gObjectEventPal_MayReflection[];
extern const u16 gObjectEventPal_MovingBox[];
extern const u16 gObjectEventPal_CableCar[];
extern const u16 gObjectEventPal_SSTidal[];
extern const u16 gObjectEventPal_Kyogre[];
extern const u16 gObjectEventPal_KyogreReflection[];
extern const u16 gObjectEventPal_Groudon[];
extern const u16 gObjectEventPal_GroudonReflection[];
extern const u16 gObjectEventPal_SubmarineShadow[];
extern const u16 gObjectEventPal_Poochyena[];
extern const u16 gObjectEventPal_RedLeaf[];
extern const u16 gObjectEventPal_Deoxys[];
extern const u16 gObjectEventPal_BirthIslandStone[];
extern const u16 gObjectEventPal_HoOh[];
extern const u16 gObjectEventPal_Lugia[];
extern const u16 gObjectEventPal_RubySapphireBrendan[];
extern const u16 gObjectEventPal_RubySapphireMay[];

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const struct SpritePalette sObjectEventSpritePalettes[] =
{
    {gObjectEventPal_Npc1,                  OBJ_EVENT_PAL_TAG_NPC_1},
    {gObjectEventPal_Npc2,                  OBJ_EVENT_PAL_TAG_NPC_2},
    {gObjectEventPal_Npc3,                  OBJ_EVENT_PAL_TAG_NPC_3},
    {gObjectEventPal_Npc4,                  OBJ_EVENT_PAL_TAG_NPC_4},
    {gObjectEventPal_Npc1Reflection,        OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION},
    {gObjectEventPal_Npc2Reflection,        OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION},
    {gObjectEventPal_Npc3Reflection,        OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION},
    {gObjectEventPal_Npc4Reflection,        OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION},
    {gObjectEventPal_Brendan,               OBJ_EVENT_PAL_TAG_BRENDAN},
    {gObjectEventPal_BrendanReflection,     OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION},
    {gObjectEventPal_BridgeReflection,      OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION},
    {gObjectEventPal_PlayerUnderwater,      OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER},
    {gObjectEventPal_QuintyPlump,           OBJ_EVENT_PAL_TAG_QUINTY_PLUMP},
    {gObjectEventPal_QuintyPlumpReflection, OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION},
    {gObjectEventPal_Truck,                 OBJ_EVENT_PAL_TAG_TRUCK},
    {gObjectEventPal_Vigoroth,              OBJ_EVENT_PAL_TAG_VIGOROTH},
    {gObjectEventPal_EnemyZigzagoon,        OBJ_EVENT_PAL_TAG_ZIGZAGOON},
    {gObjectEventPal_May,                   OBJ_EVENT_PAL_TAG_MAY},
    {gObjectEventPal_MayReflection,         OBJ_EVENT_PAL_TAG_MAY_REFLECTION},
    {gObjectEventPal_MovingBox,             OBJ_EVENT_PAL_TAG_MOVING_BOX},
    {gObjectEventPal_CableCar,              OBJ_EVENT_PAL_TAG_CABLE_CAR},
    {gObjectEventPal_SSTidal,               OBJ_EVENT_PAL_TAG_SSTIDAL},
    {gObjectEventPal_Kyogre,                OBJ_EVENT_PAL_TAG_KYOGRE},
    {gObjectEventPal_KyogreReflection,      OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION},
    {gObjectEventPal_Groudon,               OBJ_EVENT_PAL_TAG_GROUDON},
    {gObjectEventPal_GroudonReflection,     OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION},
    {gObjectEventPal_SubmarineShadow,       OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW},
    {gObjectEventPal_Poochyena,             OBJ_EVENT_PAL_TAG_POOCHYENA},
    {gObjectEventPal_RedLeaf,               OBJ_EVENT_PAL_TAG_RED_LEAF},
    {gObjectEventPal_Deoxys,                OBJ_EVENT_PAL_TAG_DEOXYS},
    {gObjectEventPal_BirthIslandStone,      OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE},
    {gObjectEventPal_HoOh,                  OBJ_EVENT_PAL_TAG_HO_OH},
    {gObjectEventPal_Lugia,                 OBJ_EVENT_PAL_TAG_LUGIA},
    {gObjectEventPal_RubySapphireBrendan,   OBJ_EVENT_PAL_TAG_RS_BRENDAN},
    {gObjectEventPal_RubySapphireMay,       OBJ_EVENT_PAL_TAG_RS_MAY},
    {}, // Preserve the original zero sentinel (not OBJ_EVENT_PAL_TAG_NONE).
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_Brendan[4] =
{
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_May[4] =
{
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
    OBJ_EVENT_PAL_TAG_MAY_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_PlayerUnderwater[4] =
{
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
    OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const struct PairedPalettes sPlayerReflectionPaletteSets[] =
{
    {OBJ_EVENT_PAL_TAG_BRENDAN,           sReflectionPaletteTags_Brendan},
    {OBJ_EVENT_PAL_TAG_MAY,               sReflectionPaletteTags_May},
    {OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER, sReflectionPaletteTags_PlayerUnderwater},
    {OBJ_EVENT_PAL_TAG_NONE,              NULL},
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_QuintyPlump[4] =
{
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
    OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_Truck[4] =
{
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
    OBJ_EVENT_PAL_TAG_TRUCK,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_VigorothMover[4] =
{
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
    OBJ_EVENT_PAL_TAG_VIGOROTH,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_MovingBox[4] =
{
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
    OBJ_EVENT_PAL_TAG_MOVING_BOX,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_CableCar[4] =
{
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
    OBJ_EVENT_PAL_TAG_CABLE_CAR,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_SSTidal[4] =
{
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
    OBJ_EVENT_PAL_TAG_SSTIDAL,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_SubmarineShadow[4] =
{
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
    OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_Kyogre[4] =
{
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
    OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_Groudon[4] =
{
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
    OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_Npc3[4] =
{
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sReflectionPaletteTags_RedLeaf[4] =
{
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
    OBJ_EVENT_PAL_TAG_RED_LEAF,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const struct PairedPalettes sSpecialObjectReflectionPaletteSets[] =
{
    {OBJ_EVENT_PAL_TAG_BRENDAN,          sReflectionPaletteTags_Brendan},
    {OBJ_EVENT_PAL_TAG_MAY,              sReflectionPaletteTags_May},
    {OBJ_EVENT_PAL_TAG_QUINTY_PLUMP,     sReflectionPaletteTags_QuintyPlump},
    {OBJ_EVENT_PAL_TAG_TRUCK,            sReflectionPaletteTags_Truck},
    {OBJ_EVENT_PAL_TAG_VIGOROTH,         sReflectionPaletteTags_VigorothMover},
    {OBJ_EVENT_PAL_TAG_MOVING_BOX,       sReflectionPaletteTags_MovingBox},
    {OBJ_EVENT_PAL_TAG_CABLE_CAR,        sReflectionPaletteTags_CableCar},
    {OBJ_EVENT_PAL_TAG_SSTIDAL,          sReflectionPaletteTags_SSTidal},
    {OBJ_EVENT_PAL_TAG_KYOGRE,           sReflectionPaletteTags_Kyogre},
    {OBJ_EVENT_PAL_TAG_GROUDON,          sReflectionPaletteTags_Groudon},
    {OBJ_EVENT_PAL_TAG_NPC_3,            sReflectionPaletteTags_Npc3},
    {OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW, sReflectionPaletteTags_SubmarineShadow},
    {OBJ_EVENT_PAL_TAG_RED_LEAF,         sReflectionPaletteTags_RedLeaf},
    {OBJ_EVENT_PAL_TAG_NONE,             NULL},
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sObjectPaletteTags0[] =
{
    [PALSLOT_PLAYER]            = OBJ_EVENT_PAL_TAG_BRENDAN,
    [PALSLOT_PLAYER_REFLECTION] = OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    [PALSLOT_NPC_1]             = OBJ_EVENT_PAL_TAG_NPC_1,
    [PALSLOT_NPC_2]             = OBJ_EVENT_PAL_TAG_NPC_2,
    [PALSLOT_NPC_3]             = OBJ_EVENT_PAL_TAG_NPC_3,
    [PALSLOT_NPC_4]             = OBJ_EVENT_PAL_TAG_NPC_4,
    [PALSLOT_NPC_1_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    [PALSLOT_NPC_2_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    [PALSLOT_NPC_3_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    [PALSLOT_NPC_4_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sObjectPaletteTags1[] =
{
    [PALSLOT_PLAYER]            = OBJ_EVENT_PAL_TAG_BRENDAN,
    [PALSLOT_PLAYER_REFLECTION] = OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    [PALSLOT_NPC_1]             = OBJ_EVENT_PAL_TAG_NPC_1,
    [PALSLOT_NPC_2]             = OBJ_EVENT_PAL_TAG_NPC_2,
    [PALSLOT_NPC_3]             = OBJ_EVENT_PAL_TAG_NPC_3,
    [PALSLOT_NPC_4]             = OBJ_EVENT_PAL_TAG_NPC_4,
    [PALSLOT_NPC_1_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    [PALSLOT_NPC_2_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    [PALSLOT_NPC_3_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    [PALSLOT_NPC_4_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sObjectPaletteTags2[] =
{
    [PALSLOT_PLAYER]            = OBJ_EVENT_PAL_TAG_BRENDAN,
    [PALSLOT_PLAYER_REFLECTION] = OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    [PALSLOT_NPC_1]             = OBJ_EVENT_PAL_TAG_NPC_1,
    [PALSLOT_NPC_2]             = OBJ_EVENT_PAL_TAG_NPC_2,
    [PALSLOT_NPC_3]             = OBJ_EVENT_PAL_TAG_NPC_3,
    [PALSLOT_NPC_4]             = OBJ_EVENT_PAL_TAG_NPC_4,
    [PALSLOT_NPC_1_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    [PALSLOT_NPC_2_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    [PALSLOT_NPC_3_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    [PALSLOT_NPC_4_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 sObjectPaletteTags3[] =
{
    [PALSLOT_PLAYER]            = OBJ_EVENT_PAL_TAG_BRENDAN,
    [PALSLOT_PLAYER_REFLECTION] = OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION,
    [PALSLOT_NPC_1]             = OBJ_EVENT_PAL_TAG_NPC_1,
    [PALSLOT_NPC_2]             = OBJ_EVENT_PAL_TAG_NPC_2,
    [PALSLOT_NPC_3]             = OBJ_EVENT_PAL_TAG_NPC_3,
    [PALSLOT_NPC_4]             = OBJ_EVENT_PAL_TAG_NPC_4,
    [PALSLOT_NPC_1_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION,
    [PALSLOT_NPC_2_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION,
    [PALSLOT_NPC_3_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION,
    [PALSLOT_NPC_4_REFLECTION]  = OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_PALETTE_DATA static const u16 *const sObjectPaletteTagSets[] =
{
    sObjectPaletteTags0,
    sObjectPaletteTags1,
    sObjectPaletteTags2,
    sObjectPaletteTags3,
};
