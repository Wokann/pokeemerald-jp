// JP Trainer Fan Club tables kept in their original ROM order.

#define FIELD_SPECIALS_FAN_CLUB_DATA __attribute__((section(".rodata.field_specials_fan_club_data"), aligned(1)))

const u8 sFanClubCounterIncrements[4] FIELD_SPECIALS_FAN_CLUB_DATA = INCBIN_U8("data/field_specials/jp/fan_club_counter_increments.bin");
const u8 sFanClubGainOrder[8] FIELD_SPECIALS_FAN_CLUB_DATA = INCBIN_U8("data/field_specials/jp/fan_club_gain_order.bin");
const u8 sFanClubLossOrder[8] FIELD_SPECIALS_FAN_CLUB_DATA = INCBIN_U8("data/field_specials/jp/fan_club_loss_order.bin");

#undef FIELD_SPECIALS_FAN_CLUB_DATA

// Retain labels used by the remaining JP naked implementations.
__asm__(
    ".global gUnknown_8592ECC\n"
    ".set gUnknown_8592ECC, sFanClubCounterIncrements\n"
    ".global gUnknown_8592ED0\n"
    ".set gUnknown_8592ED0, sFanClubGainOrder\n"
    ".global gUnknown_8592ED8\n"
    ".set gUnknown_8592ED8, sFanClubLossOrder\n"
);
