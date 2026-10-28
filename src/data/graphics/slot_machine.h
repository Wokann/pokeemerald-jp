#ifndef GUARD_GRAPHICS_SLOT_MACHINE_H
#define GUARD_GRAPHICS_SLOT_MACHINE_H

// JP preserves the original interleaving of graphics and module data.
#define SLOT_MACHINE_GRAPHICS(symbol) __attribute__((section(".rodata.slot_machine_gfx." #symbol), aligned(1)))

SLOT_MACHINE_GRAPHICS(gSlotMachineMenu_Pal) const u16 gSlotMachineMenu_Pal[] = INCGFX_U16("graphics/slot_machine/menu.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineMenu_Gfx) const u32 gSlotMachineMenu_Gfx[] = INCGFX_U32("graphics/slot_machine/menu.png", ".4bpp.lz");
SLOT_MACHINE_GRAPHICS(gSlotMachineMenu_Tilemap) const u16 gSlotMachineMenu_Tilemap[] = INCBIN_U16("graphics/slot_machine/menu.bin");
SLOT_MACHINE_GRAPHICS(gSlotMachineInfoBox_Tilemap) const u16 gSlotMachineInfoBox_Tilemap[] = INCBIN_U16("graphics/slot_machine/info_box.bin");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbols_Pal) const u16 gSlotMachineReelSymbols_Pal[] = INCGFX_U16("graphics/slot_machine/reel_symbols/1.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimePikachu_Pal) const u16 gSlotMachineReelTimePikachu_Pal[] = INCGFX_U16("graphics/slot_machine/reel_time_pikachu.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeMisc_Pal) const u16 gSlotMachineReelTimeMisc_Pal[] = INCGFX_U16("graphics/slot_machine/shadow.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeMachine_Pal) const u16 gSlotMachineReelTimeMachine_Pal[] = INCGFX_U16("graphics/slot_machine/reel_time_machine.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineMisc_Pal) const u16 gSlotMachineMisc_Pal[] = INCGFX_U16("graphics/slot_machine/smoke.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeExplosion_Pal) const u16 gSlotMachineReelTimeExplosion_Pal[] = INCGFX_U16("graphics/slot_machine/reel_time_explosion/0.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineDigitalDisplay_Pal) const u16 gSlotMachineDigitalDisplay_Pal[] = INCGFX_U16("graphics/slot_machine/digital_display.png", ".gbapal");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol1Tiles) const u8 gSlotMachineReelSymbol1Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/1.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol2Tiles) const u8 gSlotMachineReelSymbol2Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/2.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol3Tiles) const u8 gSlotMachineReelSymbol3Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/3.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol4Tiles) const u8 gSlotMachineReelSymbol4Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/4.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol5Tiles) const u8 gSlotMachineReelSymbol5Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/5.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol6Tiles) const u8 gSlotMachineReelSymbol6Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/6.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelSymbol7Tiles) const u8 gSlotMachineReelSymbol7Tiles[] = INCGFX_U8("graphics/slot_machine/reel_symbols/7.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineDigitalDisplay_Gfx) const u32 gSlotMachineDigitalDisplay_Gfx[] = INCGFX_U32("graphics/slot_machine/digital_display.png", ".4bpp.lz");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber0Tiles) const u8 gSlotMachineNumber0Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/0.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber1Tiles) const u8 gSlotMachineNumber1Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/1.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber2Tiles) const u8 gSlotMachineNumber2Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/2.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber3Tiles) const u8 gSlotMachineNumber3Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/3.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber4Tiles) const u8 gSlotMachineNumber4Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/4.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber5Tiles) const u8 gSlotMachineNumber5Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/5.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber6Tiles) const u8 gSlotMachineNumber6Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/6.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber7Tiles) const u8 gSlotMachineNumber7Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/7.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber8Tiles) const u8 gSlotMachineNumber8Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/8.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineNumber9Tiles) const u8 gSlotMachineNumber9Tiles[] = INCGFX_U8("graphics/slot_machine/numbers/9.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachinePikaPowerBolt) const u8 gSlotMachinePikaPowerBolt[] = INCGFX_U8("graphics/slot_machine/bolt.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeDuck) const u8 gSlotMachineReelTimeDuck[] = INCGFX_U8("graphics/slot_machine/duck.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeSmoke) const u8 gSlotMachineReelTimeSmoke[] = INCGFX_U8("graphics/slot_machine/smoke.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber0) const u8 gSlotMachineReelTimeNumber0[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/0.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber1) const u8 gSlotMachineReelTimeNumber1[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/1.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber2) const u8 gSlotMachineReelTimeNumber2[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/2.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber3) const u8 gSlotMachineReelTimeNumber3[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/3.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber4) const u8 gSlotMachineReelTimeNumber4[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/4.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumber5) const u8 gSlotMachineReelTimeNumber5[] = INCGFX_U8("graphics/slot_machine/reel_time_numbers/5.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeBolt0) const u8 gSlotMachineReelTimeBolt0[] = INCGFX_U8("graphics/slot_machine/large_bolt/0.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeBolt1) const u8 gSlotMachineReelTimeBolt1[] = INCGFX_U8("graphics/slot_machine/large_bolt/1.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeExplosion0) const u8 gSlotMachineReelTimeExplosion0[] = INCGFX_U8("graphics/slot_machine/reel_time_explosion/0.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeExplosion1) const u8 gSlotMachineReelTimeExplosion1[] = INCGFX_U8("graphics/slot_machine/reel_time_explosion/1.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeShadow) const u8 gSlotMachineReelTimeShadow[] = INCGFX_U8("graphics/slot_machine/shadow.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimePikaAura) const u8 gSlotMachineReelTimePikaAura[] = INCGFX_U8("graphics/slot_machine/pika_aura.png", ".4bpp");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelBackground_Tilemap) const u8 gSlotMachineReelBackground_Tilemap[] = INCBIN_U8("graphics/slot_machine/reel_background.bin");
SLOT_MACHINE_GRAPHICS(gSlotMachineReelTimeNumberGap_Gfx) const u8 gSlotMachineReelTimeNumberGap_Gfx[] = INCGFX_U8("graphics/slot_machine/reel_time_number_gap.png", ".4bpp");

#undef SLOT_MACHINE_GRAPHICS

#endif // GUARD_GRAPHICS_SLOT_MACHINE_H
