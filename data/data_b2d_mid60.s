.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl sGiftRibbonsMonDataIds
sGiftRibbonsMonDataIds: @ 0x8569552
	.byte 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x00, 0x00, 0x00

	.include "data/field_effects/secret_power.inc"

	.section .rodata.mid60_tail_prefix
	.include "data/field_effects/secret_power_descriptors.inc"

	.include "data/field_effects/record_mix_lights.inc"

	.include "data/field_special_scene/truck_and_ss_tidal.inc"

	.section .rodata.easy_chat_unreferenced_palette_data

	.globl gUnknown_85733B0
gUnknown_85733B0: @ 0x85733B0
	@ Unreferenced BGR555 palette; semantic owner has not been established.
	.incbin "baserom_jp.gba", 0x5733b0, 0x20

	.section .rodata.mid60_tail_after_rs_interview_frame_data

	.globl gUnknown_8573E64
gUnknown_8573E64: @ 0x8573E64
	.incbin "baserom_jp.gba", 0x573e64, 0x20

	.globl gUnknown_8573E84
gUnknown_8573E84: @ 0x8573E84
	.incbin "baserom_jp.gba", 0x573e84, 0x260

	.globl gUnknown_85740E4
gUnknown_85740E4: @ 0x85740E4
	.incbin "baserom_jp.gba", 0x5740e4, 0x158

	.globl gUnknown_857423C
gUnknown_857423C: @ 0x857423C
	.incbin "baserom_jp.gba", 0x57423c, 0x20

	.globl gUnknown_857425C
gUnknown_857425C: @ 0x857425C
	.incbin "baserom_jp.gba", 0x57425c, 0x20

	.globl gUnknown_857427C
gUnknown_857427C: @ 0x857427C
	.incbin "baserom_jp.gba", 0x57427c, 0xc8

	.globl gUnknown_8574344
gUnknown_8574344: @ 0x8574344
	.incbin "baserom_jp.gba", 0x574344, 0x8

	.globl gUnknown_857434C
gUnknown_857434C: @ 0x857434C
	.incbin "baserom_jp.gba", 0x57434c, 0xc

	.globl gUnknown_8574358
gUnknown_8574358: @ 0x8574358
	.incbin "baserom_jp.gba", 0x574358, 0x24

	.globl gUnknown_857437C
gUnknown_857437C: @ 0x857437C
	.incbin "baserom_jp.gba", 0x57437c, 0x10

	.globl gUnknown_857438C
gUnknown_857438C: @ 0x857438C
	.incbin "baserom_jp.gba", 0x57438c, 0x20

	.globl gUnknown_85743AC
gUnknown_85743AC: @ 0x85743AC
	.incbin "baserom_jp.gba", 0x5743ac, 0x8

	.globl gUnknown_85743B4
gUnknown_85743B4: @ 0x85743B4
	.incbin "baserom_jp.gba", 0x5743b4, 0x8

	.globl gUnknown_85743BC
gUnknown_85743BC: @ 0x85743BC
	.incbin "baserom_jp.gba", 0x5743bc, 0x10

	.globl gUnknown_85743CC
gUnknown_85743CC: @ 0x85743CC
	.incbin "baserom_jp.gba", 0x5743cc, 0x20

	.globl gUnknown_85743EC
gUnknown_85743EC: @ 0x85743EC
	.incbin "baserom_jp.gba", 0x5743ec, 0x28

	.globl gUnknown_8574414
gUnknown_8574414: @ 0x8574414
	.incbin "baserom_jp.gba", 0x574414, 0x28

	.globl gUnknown_857443C
gUnknown_857443C: @ 0x857443C
	.incbin "baserom_jp.gba", 0x57443c, 0x50

	.globl gUnknown_857448C
gUnknown_857448C: @ 0x857448C
	.incbin "baserom_jp.gba", 0x57448c, 0x68

	.globl gUnknown_85744F4
gUnknown_85744F4: @ 0x85744F4
	.incbin "baserom_jp.gba", 0x5744f4, 0x20

	.globl gUnknown_8574514
gUnknown_8574514: @ 0x8574514
	.incbin "baserom_jp.gba", 0x574514, 0x40

	.globl gUnknown_8574554
gUnknown_8574554: @ 0x8574554
	.incbin "baserom_jp.gba", 0x574554, 0x18

	.globl gUnknown_857456C
gUnknown_857456C: @ 0x857456C
	.incbin "baserom_jp.gba", 0x57456c, 0x47a8

	.globl gUnknown_8578D14
gUnknown_8578D14: @ 0x8578D14
	.incbin "baserom_jp.gba", 0x578d14, 0xff0

	.globl gUnknown_8579D04
gUnknown_8579D04: @ 0x8579D04
	.incbin "baserom_jp.gba", 0x579d04, 0x1d4

	.globl gUnknown_8579ED8
gUnknown_8579ED8: @ 0x8579ED8
	.incbin "baserom_jp.gba", 0x579ed8, 0x58
	.globl sEasyChatGroupNamePointers
	.set sEasyChatGroupNamePointers, gUnknown_8579ED8
