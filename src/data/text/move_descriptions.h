#ifndef GUARD_DATA_TEXT_MOVE_DESCRIPTIONS_H
#define GUARD_DATA_TEXT_MOVE_DESCRIPTIONS_H

#define JP_MOVE_DESCRIPTION_LENGTH 56
#define JP_MOVE_DESCRIPTIONS_DATA __attribute__((section(".rodata.move_descriptions_jp")))

JP_MOVE_DESCRIPTIONS_DATA
static const u8 sMoveDescriptionsJP[] = INCBIN_U8("data/text/move_descriptions_jp.bin");

// Move 0 has no description. The JP table base is one fixed-width entry
// before MOVE_POUND, overlapping the tail of the Mirage Tower data.
__asm__(".global gMoveDescriptionsJP\n"
        ".set gMoveDescriptionsJP, sMoveDescriptionsJP - 56\n"
        ".global gUnknown_85E7FFC\n"
        ".set gUnknown_85E7FFC, gMoveDescriptionsJP");

#endif
