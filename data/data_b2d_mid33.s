.include "sound/MPlayDef.s"
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.section .rodata.data_b2d_mid33_pokeblock_case_favorite_suffix, "a", %progbits

	.globl gUnknown_85921F4
gUnknown_85921F4: @ 0x85921F4
	.incbin "baserom_jp.gba", 0x5921f4, 0x8

	.globl gUnknown_85921FC
gUnknown_85921FC: @ 0x85921FC
	.incbin "baserom_jp.gba", 0x5921fc, 0x18

	.section .rodata.data_b2d_mid33_shoal_tide_suffix, "a", %progbits

	.globl gUnknown_85925A8
gUnknown_85925A8: @ 0x85925A8
	.incbin "baserom_jp.gba", 0x5925a8, 0x4

	.globl gUnknown_85925AC
gUnknown_85925AC: @ 0x85925AC
	.incbin "baserom_jp.gba", 0x5925ac, 0x8

	.globl gUnknown_85925B4
gUnknown_85925B4: @ 0x85925B4
	.incbin "baserom_jp.gba", 0x5925b4, 0x10

	.globl gUnknown_85925C4
gUnknown_85925C4: @ 0x85925C4
	.incbin "baserom_jp.gba", 0x5925c4, 0x6

	.globl gUnknown_85925CA
gUnknown_85925CA: @ 0x85925CA
	.incbin "baserom_jp.gba", 0x5925ca, 0xa

	.globl sSlotMachineRandomSeeds
sSlotMachineRandomSeeds: @ 0x85925D4
	.incbin "baserom_jp.gba", 0x5925d4, 0xc

	.globl sSlotMachineIds
sSlotMachineIds: @ 0x85925E0
	.incbin "baserom_jp.gba", 0x5925e0, 0xc

	.globl sSlotMachineServiceDayIds
sSlotMachineServiceDayIds: @ 0x85925EC
	.incbin "baserom_jp.gba", 0x5925ec, 0xc

	.globl gUnknown_85925F8
gUnknown_85925F8: @ 0x85925F8
	.incbin "baserom_jp.gba", 0x5925f8, 0xc

	.globl gUnknown_8592604
gUnknown_8592604: @ 0x8592604
	.incbin "baserom_jp.gba", 0x592604, 0x4

	.globl gUnknown_8592608
gUnknown_8592608: @ 0x8592608
	.incbin "baserom_jp.gba", 0x592608, 0x8

	.globl gUnknown_8592610
gUnknown_8592610: @ 0x8592610
	.incbin "baserom_jp.gba", 0x592610, 0x40

	.globl gUnknown_8592650
gUnknown_8592650: @ 0x8592650
	.incbin "baserom_jp.gba", 0x592650, 0x12

	.globl gUnknown_8592662
gUnknown_8592662: @ 0x8592662
	.incbin "baserom_jp.gba", 0x592662, 0x12

	.globl sElevatorTripLength
sElevatorTripLength: @ 0x8592674
	.incbin "baserom_jp.gba", 0x592674, 0x9

	.globl sElevatorLightCycles
sElevatorLightCycles: @ 0x859267D
	.incbin "baserom_jp.gba", 0x59267d, 0x9
