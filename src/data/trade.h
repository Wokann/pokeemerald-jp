// JP Trade resources retain original ROM order. Verified menu resources use
// their semantic names; only the unclassified JP-only suffix remains address-named.

#define TRADE_UNUSED_STRUCT_SIZES __attribute__((section(".rodata.trade_unused_struct_sizes"), aligned(1)))
#define TRADE_MENU_RESOURCES __attribute__((section(".rodata.trade_menu_resources"), aligned(1)))
#define TRADE_MENU_RESOURCES_AFTER_MON_BOX __attribute__((section(".rodata.trade_menu_resources_after_mon_box"), aligned(1)))
#define TRADE_ANIMATION_RESOURCES __attribute__((section(".rodata.trade_animation_resources"), aligned(1)))
#define TRADE_POST_ANIMATION_RESOURCES __attribute__((section(".rodata.trade_post_animation_resources"), aligned(1)))

// Exists unused in Ruby/Sapphire as well. The final literal is 0x528 in JP.
static const u32 sUnusedStructSizes[] TRADE_UNUSED_STRUCT_SIZES __attribute__((used)) =
{
    sizeof(struct SaveBlock2),
    sizeof(struct SaveBlock1),
    sizeof(struct MapHeader),
    sizeof(struct Mail),
    sizeof(struct Pokemon),
    0x00000528,
};

const u16 sTradeMovesBoxTilemap[] TRADE_MENU_RESOURCES = INCBIN_U16("graphics/trade/moves_box_map.bin");
const u16 sTradePartyBoxTilemap[] TRADE_MENU_RESOURCES = INCBIN_U16("graphics/trade/party_box_map.bin");
const u8 sTradeStripesBG2Tilemap[] TRADE_MENU_RESOURCES = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");
const u8 sTradeStripesBG3Tilemap[] TRADE_MENU_RESOURCES = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");

// The first 0x24 bytes of the preceding block are gTradeMenuMonBox_Tilemap.
// Its remaining JP-only 0x848 bytes have no confirmed semantic owner yet.
const u8 gUnknown_82FFFEC[] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/82fffec.bin");
const u8 gUnknown_8300834[0x8] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/8300834.bin");
const u8 gUnknown_830083C[0x50] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/830083c.bin");
const u8 gUnknown_830088C[0x18] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/830088c.bin");
const u8 gUnknown_83008A4[0x38] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/83008a4.bin");
const u8 gUnknown_83008DC[0x8] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/83008dc.bin");
const u8 gUnknown_83008E4[13][4][6] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/83008e4.bin");
const u8 gUnknown_8300A1C[13][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/8300a1c.bin");
const u8 gUnknown_8300A36[12][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/8300a36.bin");
const u8 gUnknown_8300A4E[30][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCBIN_U8("graphics/trade/jp/menu/8300a4e.bin");

const u8 gUnknown_8300AB1[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300ab1.bin");
const u8 gUnknown_8300AFC[0x2C] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300afc.bin");
const u8 gUnknown_8300B28[0xB4] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300b28.bin");
const u8 gUnknown_8300BDC[0x24] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300bdc.bin");
const u8 gUnknown_8300C00[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300c00.bin");
const u8 gUnknown_8300C04[0x10] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300c04.bin");
const u8 gUnknown_8300C14[0x98] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300c14.bin");
const u8 gUnknown_8300CAC[0x94] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300cac.bin");
const u8 gUnknown_8300D40[0x2024] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300d40.bin");
const u8 gUnknown_8302D64[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8302d64.bin");
const u8 gUnknown_8304D04[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8304d04.bin");
const u8 gUnknown_8305D24[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8305d24.bin");
const u8 gUnknown_8305D84[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8305d84.bin");
const u8 gUnknown_83071A4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/83071a4.bin");
const u8 gUnknown_83099E4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/83099e4.bin");
const u8 gUnknown_8309AE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8309ae4.bin");
const u8 gUnknown_8309BE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8309be4.bin");
const u8 gUnknown_830ABE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830abe4.bin");
const u8 gUnknown_830BBE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bbe4.bin");
const u8 gUnknown_830BCE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bce4.bin");
const u8 gUnknown_830BEE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bee4.bin");
const u8 gUnknown_830C0E4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c0e4.bin");
const u8 gUnknown_830C104[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c104.bin");
const u8 gUnknown_830C794[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c794.bin");
const u8 gUnknown_830CF5C[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf5c.bin");
const u8 gUnknown_830CF64[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf64.bin");
const u8 gUnknown_830CF6C[0x48] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf6c.bin");
const u8 gUnknown_830CFB4[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfb4.bin");
const u8 gUnknown_830CFBC[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfbc.bin");
const u8 gUnknown_830CFC4[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfc4.bin");
const u8 gUnknown_830CFCC[0x38] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfcc.bin");
const u8 gUnknown_830D004[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d004.bin");
const u8 gUnknown_830D00C[0x2C] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d00c.bin");
const u8 gUnknown_830D038[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d038.bin");
const u8 gUnknown_830D040[0x70] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d040.bin");
const u8 gUnknown_830D0B0[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0b0.bin");
const u8 gUnknown_830D0B8[0x18] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0b8.bin");
const u8 gUnknown_830D0D0[0x18] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0d0.bin");
const u8 gUnknown_830D0E8[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0e8.bin");
const u8 gUnknown_830D110[0x4] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d110.bin");
const u8 gUnknown_830D114[0xF0] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d114.bin");
const u8 gUnknown_830D204[0x3C] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d204.bin");

// This short block follows region_texts49 and precedes the Berry Blender data.
const u8 gUnknown_830D26A[0x12] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d26a.bin");
const u8 gUnknown_830D27C[0x10] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d27c.bin");
const u8 gUnknown_830D28C[0x8] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d28c.bin");
const u8 gUnknown_830D294[0x10] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d294.bin");
const u8 gUnknown_830D2A4[0x6C] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d2a4.bin");
const u8 gUnknown_830D310[0x44] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d310.bin");

#undef TRADE_UNUSED_STRUCT_SIZES
#undef TRADE_MENU_RESOURCES
#undef TRADE_MENU_RESOURCES_AFTER_MON_BOX
#undef TRADE_ANIMATION_RESOURCES
#undef TRADE_POST_ANIMATION_RESOURCES
