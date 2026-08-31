#include "constants/global.h"
#include "constants/event_bg.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/secret_bases.h"
#include "constants/trainer_types.h"
#include "constants/berry.h"
#include "constants/vars.h"
#include "constants/weather.h"

#define NULL 0

.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid26_before_tileset_anims_data
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.section .rodata.data_b2d_mid26_after_tileset_anims_data_before_palette_static_data

	.section .rodata.data_b2d_mid26_after_palette_static_data_before_battle_anim_status_effects

	.globl sFanfares
	.globl sFanfares
sFanfares: @ 0x84FCFC8
	.hword 367, 80  @ [FANFARE_LEVEL_UP] = { MUS_LEVEL_UP, 80 }
	.hword 370, 160  @ [FANFARE_OBTAIN_ITEM] = { MUS_OBTAIN_ITEM, 160 }
	.hword 371, 220  @ [FANFARE_EVOLVED] = { MUS_EVOLVED, 220 }
	.hword 372, 220  @ [FANFARE_OBTAIN_TMHM] = { MUS_OBTAIN_TMHM, 220 }
	.hword 368, 160  @ [FANFARE_HEAL] = { MUS_HEAL, 160 }
	.hword 369, 340  @ [FANFARE_OBTAIN_BADGE] = { MUS_OBTAIN_BADGE, 340 }
	.hword 378, 180  @ [FANFARE_MOVE_DELETED] = { MUS_MOVE_DELETED, 180 }
	.hword 387, 120  @ [FANFARE_OBTAIN_BERRY] = { MUS_OBTAIN_BERRY, 120 }
	.hword 388, 710  @ [FANFARE_AWAKEN_LEGEND] = { MUS_AWAKEN_LEGEND, 710 }
	.hword 389, 250  @ [FANFARE_SLOTS_JACKPOT] = { MUS_SLOTS_JACKPOT, 250 }
	.hword 390, 150  @ [FANFARE_SLOTS_WIN] = { MUS_SLOTS_WIN, 150 }
	.hword 391, 160  @ [FANFARE_TOO_BAD] = { MUS_TOO_BAD, 160 }
	.hword 550, 450  @ [FANFARE_RG_POKE_FLUTE] = { MUS_RG_POKE_FLUTE, 450 }
	.hword 530, 170  @ [FANFARE_RG_OBTAIN_KEY_ITEM] = { MUS_RG_OBTAIN_KEY_ITEM, 170 }
	.hword 529, 196  @ [FANFARE_RG_DEX_RATING] = { MUS_RG_DEX_RATING, 196 }
	.hword 459, 313  @ [FANFARE_OBTAIN_B_POINTS] = { MUS_OBTAIN_B_POINTS, 313 }
	.hword 466, 318  @ [FANFARE_OBTAIN_SYMBOL] = { MUS_OBTAIN_SYMBOL, 318 }
	.hword 460, 135  @ [FANFARE_REGISTER_MATCH_CALL] = { MUS_REGISTER_MATCH_CALL, 135 }

	.globl gUnknown_84FD010
	.globl gUnknown_84FD010
gUnknown_84FD010: @ 0x4FD010
	.incbin "baserom_jp.gba", 0x4fd010, 0x30

	.globl gUnknown_84FD040
	.globl sOam_MoveEffectMons
gUnknown_84FD040:
sOam_MoveEffectMons: @ 0x84FD040
	.4byte 0x80004000
	.hword 0x0800, 0x0000
	.4byte 0xC0004000
	.hword 0x0800, 0x0000
	.4byte 0x00008000
	.hword 0x0800, 0x0000
	.4byte 0x40008000
	.hword 0x0800, 0x0000
	.4byte 0x80008000
	.hword 0x0800, 0x0000
	.4byte 0xC0008000
	.hword 0x0800, 0x0000
	.4byte 0x00000100
	.hword 0x0800, 0x0000
	.4byte 0x40000100
	.hword 0x0800, 0x0000
	.4byte 0x80000100
	.hword 0x0800, 0x0000
	.4byte 0xC0000100
	.hword 0x0800, 0x0000
	.4byte 0x00004100
	.hword 0x0800, 0x0000
	.4byte 0x40004100
	.hword 0x0800, 0x0000
	.4byte 0x80004100
	.hword 0x0800, 0x0000
	.4byte 0xC0004100
	.hword 0x0800, 0x0000
	.4byte 0x00008100
	.hword 0x0800, 0x0000
	.4byte 0x40008100
	.hword 0x0800, 0x0000
	.4byte 0x80008100
	.hword 0x0800, 0x0000
	.4byte 0xC0008100
	.hword 0x0800, 0x0000
	.4byte 0x00000300
	.hword 0x0800, 0x0000
	.4byte 0x40000300
	.hword 0x0800, 0x0000
	.4byte 0x80000300
	.hword 0x0800, 0x0000
	.4byte 0xC0000300
	.hword 0x0800, 0x0000
	.4byte 0x00004300
	.hword 0x0800, 0x0000
	.4byte 0x40004300
	.hword 0x0800, 0x0000
	.4byte 0x80004300
	.hword 0x0800, 0x0000
	.4byte 0xC0004300
	.hword 0x0800, 0x0000
	.4byte 0x00008300
	.hword 0x0800, 0x0000
	.4byte 0x40008300
	.hword 0x0800, 0x0000
	.4byte 0x80008300
	.hword 0x0800, 0x0000
	.4byte 0xC0008300
	.hword 0x0800, 0x0000
	.4byte 0x00000400
	.hword 0x0800, 0x0000
	.4byte 0x40000400
	.hword 0x0800, 0x0000
	.4byte 0x80000400
	.hword 0x0800, 0x0000
	.4byte 0xC0000400
	.hword 0x0800, 0x0000
	.4byte 0x00004400
	.hword 0x0800, 0x0000
	.4byte 0x40004400
	.hword 0x0800, 0x0000
	.4byte 0x80004400
	.hword 0x0800, 0x0000
	.4byte 0xC0004400
	.hword 0x0800, 0x0000
	.4byte 0x00008400
	.hword 0x0800, 0x0000
	.4byte 0x40008400
	.hword 0x0800, 0x0000
	.4byte 0x80008400
	.hword 0x0800, 0x0000
	.4byte 0xC0008400
	.hword 0x0800, 0x0000
	.4byte 0x00000500
	.hword 0x0800, 0x0000
	.4byte 0x40000500
	.hword 0x0800, 0x0000
	.4byte 0x80000500
	.hword 0x0800, 0x0000
	.4byte 0xC0000500
	.hword 0x0800, 0x0000
	.4byte 0x00004500
	.hword 0x0800, 0x0000
	.4byte 0x40004500
	.hword 0x0800, 0x0000
	.4byte 0x80004500
	.hword 0x0800, 0x0000
	.4byte 0xC0004500
	.hword 0x0800, 0x0000
	.4byte 0x00008500
	.hword 0x0800, 0x0000
	.4byte 0x40008500
	.hword 0x0800, 0x0000
	.4byte 0x80008500
	.hword 0x0800, 0x0000
	.4byte 0xC0008500
	.hword 0x0800, 0x0000
	.4byte 0x00000700
	.hword 0x0800, 0x0000
	.4byte 0x40000700
	.hword 0x0800, 0x0000
	.4byte 0x80000700
	.hword 0x0800, 0x0000
	.4byte 0xC0000700
	.hword 0x0800, 0x0000
	.4byte 0x00004700
	.hword 0x0800, 0x0000
	.4byte 0x40004700
	.hword 0x0800, 0x0000
	.4byte 0x80004700
	.hword 0x0800, 0x0000
	.4byte 0xC0004700
	.hword 0x0800, 0x0000
	.4byte 0x00008700
	.hword 0x0800, 0x0000
	.4byte 0x40008700
	.hword 0x0800, 0x0000
	.4byte 0x80008700
	.hword 0x0800, 0x0000
	.4byte 0xC0008700
	.hword 0x0800, 0x0000

	.globl gBattleAnimPicTable
gBattleAnimPicTable: @ 0x004FD250
	.4byte 0x08C02540
	.hword 0x0200, 0x2710  @ size=512, tag=0x2710
	.4byte 0x08C1C728
	.hword 0x0300, 0x2711  @ size=768, tag=0x2711
	.4byte 0x08C20828
	.hword 0x0200, 0x2712  @ size=512, tag=0x2712
	.4byte 0x08C025F0
	.hword 0x0100, 0x2713  @ size=256, tag=0x2713
	.4byte 0x08C02664
	.hword 0x0200, 0x2714  @ size=512, tag=0x2714
	.4byte 0x08C02714
	.hword 0x0400, 0x2715  @ size=1024, tag=0x2715
	.4byte 0x08C027E8
	.hword 0x0180, 0x2716  @ size=384, tag=0x2716
	.4byte 0x08C029D4
	.hword 0x0800, 0x2717  @ size=2048, tag=0x2717
	.4byte 0x08C02B70
	.hword 0x0020, 0x2718  @ size=32, tag=0x2718
	.4byte 0x08C02FAC
	.hword 0x0400, 0x2719  @ size=1024, tag=0x2719
	.4byte 0x08C02BCC
	.hword 0x1200, 0x271A  @ size=4608, tag=0x271A
	.4byte 0x08C032B4
	.hword 0x0180, 0x271B  @ size=384, tag=0x271B
	.4byte 0x08C03354
	.hword 0x0080, 0x271C  @ size=128, tag=0x271C
	.4byte 0x08C03440
	.hword 0x0080, 0x271D  @ size=128, tag=0x271D
	.4byte 0x08C1FC78
	.hword 0x0280, 0x271E  @ size=640, tag=0x271E
	.4byte 0x08C0348C
	.hword 0x0080, 0x271F  @ size=128, tag=0x271F
	.4byte 0x08C03520
	.hword 0x0100, 0x2720  @ size=256, tag=0x2720
	.4byte 0x08C035A0
	.hword 0x0020, 0x2721  @ size=32, tag=0x2721
	.4byte 0x08C24E20
	.hword 0x0080, 0x2722  @ size=128, tag=0x2722
	.4byte 0x08C03600
	.hword 0x0400, 0x2723  @ size=1024, tag=0x2723
	.4byte 0x08C036C0
	.hword 0x0200, 0x2724  @ size=512, tag=0x2724
	.4byte 0x08C03A30
	.hword 0x0A00, 0x2725  @ size=2560, tag=0x2725
	.4byte 0x08C03A30
	.hword 0x0A00, 0x2726  @ size=2560, tag=0x2726
	.4byte 0x08C037DC
	.hword 0x0380, 0x2727  @ size=896, tag=0x2727
	.4byte 0x08C03EA8
	.hword 0x0300, 0x2728  @ size=768, tag=0x2728
	.4byte 0x08C03DB8
	.hword 0x0A00, 0x2729  @ size=2560, tag=0x2729
	.4byte 0x08C0449C
	.hword 0x0A00, 0x272A  @ size=2560, tag=0x272A
	.4byte 0x08C04824
	.hword 0x0A00, 0x272B  @ size=2560, tag=0x272B
	.4byte 0x08C04B48
	.hword 0x0A00, 0x272C  @ size=2560, tag=0x272C
	.4byte 0x08C04E98
	.hword 0x0A00, 0x272D  @ size=2560, tag=0x272D
	.4byte 0x08C05178
	.hword 0x0A00, 0x272E  @ size=2560, tag=0x272E
	.4byte 0x08C03F88
	.hword 0x0E00, 0x272F  @ size=3584, tag=0x272F
	.4byte 0x08C043B0
	.hword 0x0380, 0x2730  @ size=896, tag=0x2730
	.4byte 0x08C05584
	.hword 0x1000, 0x2731  @ size=4096, tag=0x2731
	.4byte 0x08C05EF4
	.hword 0x0800, 0x2732  @ size=2048, tag=0x2732
	.4byte 0x08C062C0
	.hword 0x0A00, 0x2733  @ size=2560, tag=0x2733
	.4byte 0x08C06680
	.hword 0x0800, 0x2734  @ size=2048, tag=0x2734
	.4byte 0x08C06A54
	.hword 0x0A00, 0x2735  @ size=2560, tag=0x2735
	.4byte 0x08C0796C
	.hword 0x0A00, 0x2736  @ size=2560, tag=0x2736
	.4byte 0x08C07B90
	.hword 0x0A00, 0x2737  @ size=2560, tag=0x2737
	.4byte 0x08C07E8C
	.hword 0x0A00, 0x2738  @ size=2560, tag=0x2738
	.4byte 0x08C08098
	.hword 0x0A00, 0x2739  @ size=2560, tag=0x2739
	.4byte 0x08C082CC
	.hword 0x0A00, 0x273A  @ size=2560, tag=0x273A
	.4byte 0x08C085C4
	.hword 0x0A00, 0x273B  @ size=2560, tag=0x273B
	.4byte 0x08C08A14
	.hword 0x0A00, 0x273C  @ size=2560, tag=0x273C
	.4byte 0x08C08CA8
	.hword 0x0A00, 0x273D  @ size=2560, tag=0x273D
	.4byte 0x08C0960C
	.hword 0x1000, 0x273E  @ size=4096, tag=0x273E
	.4byte 0x08C0960C
	.hword 0x1000, 0x273F  @ size=4096, tag=0x273F
	.4byte 0x08C09CF8
	.hword 0x1000, 0x2740  @ size=4096, tag=0x2740
	.4byte 0x08C09CF8
	.hword 0x1000, 0x2741  @ size=4096, tag=0x2741
	.4byte 0x08C0A004
	.hword 0x0200, 0x2742  @ size=512, tag=0x2742
	.4byte 0x08C0A0A4
	.hword 0x0200, 0x2743  @ size=512, tag=0x2743
	.4byte 0x08C0A150
	.hword 0x0200, 0x2744  @ size=512, tag=0x2744
	.4byte 0x08C2E8D4
	.hword 0x0800, 0x2745  @ size=2048, tag=0x2745
	.4byte 0x08C0A3B0
	.hword 0x0080, 0x2746  @ size=128, tag=0x2746
	.4byte 0x08C0A8C4
	.hword 0x0200, 0x2747  @ size=512, tag=0x2747
	.4byte 0x08C0A3F4
	.hword 0x1000, 0x2748  @ size=4096, tag=0x2748
	.4byte 0x08C0A988
	.hword 0x0180, 0x2749  @ size=384, tag=0x2749

	.globl gUnknown_84FD420
gUnknown_84FD420: @ 0x004FD420
	.incbin "baserom_jp.gba", 0x4fd420, 0x270

	.globl gUnknown_84FD690
gUnknown_84FD690: @ 0x004FD690
	.incbin "baserom_jp.gba", 0x4fd690, 0x308

	.globl gUnknown_84FD998
gUnknown_84FD998: @ 0x004FD998
	.incbin "baserom_jp.gba", 0x4fd998, 0x120

	.globl gUnknown_84FDAB8
gUnknown_84FDAB8: @ 0x004FDAB8
	.incbin "baserom_jp.gba", 0x4fdab8, 0xa0

	.globl gBattleAnimPaletteTable
gBattleAnimPaletteTable: @ 0x004FDB58
	.4byte 0x08C028D4
	.hword 0x2710, 0x0000
	.4byte 0x08C1C7DC
	.hword 0x2711, 0x0000
	.4byte 0x08C2090C
	.hword 0x2712, 0x0000
	.4byte 0x08C028F8
	.hword 0x2713, 0x0000
	.4byte 0x08C02920
	.hword 0x2714, 0x0000
	.4byte 0x08C02934
	.hword 0x2715, 0x0000
	.4byte 0x08C0295C
	.hword 0x2716, 0x0000
	.4byte 0x08C02B50
	.hword 0x2717, 0x0000
	.4byte 0x08C02B90
	.hword 0x2718, 0x0000
	.4byte 0x08C03294
	.hword 0x2719, 0x0000
	.4byte 0x08C02BAC
	.hword 0x271A, 0x0000
	.4byte 0x08C0332C
	.hword 0x271B, 0x0000
	.4byte 0x08C033BC
	.hword 0x271C, 0x0000
	.4byte 0x08C03474
	.hword 0x271D, 0x0000
	.4byte 0x08C1FD0C
	.hword 0x271E, 0x0000
	.4byte 0x08C034F8
	.hword 0x271F, 0x0000
	.4byte 0x08C03590
	.hword 0x2720, 0x0000
	.4byte 0x08C03590
	.hword 0x2721, 0x0000
	.4byte 0x08C24E5C
	.hword 0x2722, 0x0000
	.4byte 0x08C035E4
	.hword 0x2723, 0x0000
	.4byte 0x08C0378C
	.hword 0x2724, 0x0000
	.4byte 0x08C03A08
	.hword 0x2725, 0x0000
	.4byte 0x08C03D68
	.hword 0x2726, 0x0000
	.4byte 0x08C037B4
	.hword 0x2727, 0x0000
	.4byte 0x08C03F74
	.hword 0x2728, 0x0000
	.4byte 0x08C03D90
	.hword 0x2729, 0x0000
	.4byte 0x08C047D4
	.hword 0x272A, 0x0000
	.4byte 0x08C047FC
	.hword 0x272B, 0x0000
	.4byte 0x08C04B20
	.hword 0x272C, 0x0000
	.4byte 0x08C05150
	.hword 0x272D, 0x0000
	.4byte 0x08C05538
	.hword 0x272E, 0x0000
	.4byte 0x08C04368
	.hword 0x272F, 0x0000
	.4byte 0x08C04388
	.hword 0x2730, 0x0000
	.4byte 0x08C0555C
	.hword 0x2731, 0x0000
	.4byte 0x08C0555C
	.hword 0x2732, 0x0000
	.4byte 0x08C0555C
	.hword 0x2733, 0x0000
	.4byte 0x08C06658
	.hword 0x2734, 0x0000
	.4byte 0x08C06658
	.hword 0x2735, 0x0000
	.4byte 0x08C0791C
	.hword 0x2736, 0x0000
	.4byte 0x08C07944
	.hword 0x2737, 0x0000
	.4byte 0x08C0791C
	.hword 0x2738, 0x0000
	.4byte 0x08C0791C
	.hword 0x2739, 0x0000
	.4byte 0x08C0859C
	.hword 0x273A, 0x0000
	.4byte 0x08C089C4
	.hword 0x273B, 0x0000
	.4byte 0x08C089EC
	.hword 0x273C, 0x0000
	.4byte 0x08C08C80
	.hword 0x273D, 0x0000
	.4byte 0x08C099EC
	.hword 0x273E, 0x0000
	.4byte 0x08C09A0C
	.hword 0x273E, 0x0000
	.4byte 0x08C09F90
	.hword 0x2740, 0x0000
	.4byte 0x08C09FB8
	.hword 0x2741, 0x0000
	.4byte 0x08C09FE0
	.hword 0x2742, 0x0000
	.4byte 0x08C09FE0
	.hword 0x2743, 0x0000
	.4byte 0x08C09FE0
	.hword 0x2744, 0x0000
	.4byte 0x08C047D4
	.hword 0x2745, 0x0000
	.4byte 0x08C0A3DC
	.hword 0x2746, 0x0000
	.4byte 0x08C09FE0
	.hword 0x2747, 0x0000
	.4byte 0x08C0A89C
	.hword 0x2748, 0x0000
	.4byte 0x08C0AA10
	.hword 0x2749, 0x0000

	.globl gUnknown_84FDD28
gUnknown_84FDD28: @ 0x84FDD28
	.incbin "baserom_jp.gba", 0x4fdd28, 0x270

	.globl gUnknown_84FDF98
gUnknown_84FDF98: @ 0x84FDF98
	.incbin "baserom_jp.gba", 0x4fdf98, 0x308

	.globl gUnknown_84FE2A0
gUnknown_84FE2A0: @ 0x84FE2A0
	.incbin "baserom_jp.gba", 0x4fe2a0, 0x120

	.globl gUnknown_84FE3C0
gUnknown_84FE3C0: @ 0x84FE3C0
	.incbin "baserom_jp.gba", 0x4fe3c0, 0xa0

	.globl gUnknown_84FE460
gUnknown_84FE460: @ 0x84FE460
	.incbin "baserom_jp.gba", 0x4fe460, 0x144

	.globl gUnknown_84FE5A4
gUnknown_84FE5A4: @ 0x84FE5A4
	.incbin "baserom_jp.gba", 0x4fe5a4, 0xc0

	.globl sBattlerCoords
sBattlerCoords: @ 0x84FE664
sBattlerCoords: @ 0x84FE664
	.4byte 0x00005048, 0x000028B0, 0x00002830, 0x00005070, 0x00005020, 0x000028C8, 0x0000585A, 0x00002098

	.globl gCastformFrontSpriteCoords
gCastformFrontSpriteCoords: @ 0x84FE684
	.byte 68 @ entry 0 size
	.byte 17 @ entry 0 y_offset
	.hword 0
	.byte 102 @ entry 1 size
	.byte 9 @ entry 1 y_offset
	.hword 0
	.byte 70 @ entry 2 size
	.byte 9 @ entry 2 y_offset
	.hword 0
	.byte 134 @ entry 3 size
	.byte 8 @ entry 3 y_offset
	.hword 0

	.globl sCastformElevations
sCastformElevations: @ 0x84FE694
	.byte 0x0D, 0x0E, 0x0D, 0x0D

	.globl sCastformBackSpriteYCoords
sCastformBackSpriteYCoords: @ 0x84FE698
	.byte 0x00, 0x00, 0x00, 0x00

	.globl sSpriteTemplates_MoveEffectMons
sSpriteTemplates_MoveEffectMons: @ 0x84FE69C
sSpriteTemplates_MoveEffectMons: @ 0x84FE69C
	.hword 0xD755, 0xD755
	.4byte sOam_MoveEffectMons + 0x48, gDummySpriteAnimTable, 0, gDummySpriteAffineAnimTable, SpriteCallbackDummy
	.hword 0xD756, 0xD756
	.4byte sOam_MoveEffectMons + 0x48, gDummySpriteAnimTable, 0, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.globl sSpriteSheets_MoveEffectMons
sSpriteSheets_MoveEffectMons: @ 0x84FE6CC
sSpriteSheets_MoveEffectMons: @ 0x84FE6CC
	.4byte 0x082FAF64
	.hword 0x0800, 0xD755
	.4byte 0x082FAF64
	.hword 0x0800, 0xD756

	.include "data/maps/PetalburgCity/events.inc"
	.include "data/maps/SlateportCity/events.inc"
	.include "data/maps/MauvilleCity/events.inc"
	.include "data/maps/RustboroCity/events.inc"
	.include "data/maps/FortreeCity/events.inc"
	.include "data/maps/LilycoveCity/events.inc"
	.include "data/maps/MossdeepCity/events.inc"
	.include "data/maps/SootopolisCity/events.inc"
	.include "data/maps/EverGrandeCity/events.inc"
	.include "data/maps/LittlerootTown/events.inc"
	.include "data/maps/OldaleTown/events.inc"
	.include "data/maps/DewfordTown/events.inc"
	.include "data/maps/LavaridgeTown/events.inc"
	.include "data/maps/FallarborTown/events.inc"
	.include "data/maps/VerdanturfTown/events.inc"
	.include "data/maps/PacifidlogTown/events.inc"
	.include "data/maps/Route101/events.inc"
	.include "data/maps/Route102/events.inc"
	.include "data/maps/Route103/events.inc"
	.include "data/maps/Route104/events.inc"
	.include "data/maps/Route105/events.inc"
	.include "data/maps/Route106/events.inc"
	.include "data/maps/Route107/events.inc"
	.include "data/maps/Route108/events.inc"
	.include "data/maps/Route109/events.inc"
	.include "data/maps/Route110/events.inc"
	.include "data/maps/Route111/events.inc"
	.include "data/maps/Route112/events.inc"
	.include "data/maps/Route113/events.inc"
	.include "data/maps/Route114/events.inc"
	.include "data/maps/Route115/events.inc"
	.include "data/maps/Route116/events.inc"
	.include "data/maps/Route117/events.inc"
	.include "data/maps/Route118/events.inc"
	.include "data/maps/Route119/events.inc"
	.include "data/maps/Route120/events.inc"
	.include "data/maps/Route121/events.inc"
	.include "data/maps/Route122/events.inc"
	.include "data/maps/Route123/events.inc"

	.include "data/maps/Route124/events.inc"
	.include "data/maps/Route125/events.inc"
	.include "data/maps/Route126/events.inc"
	.include "data/maps/Route127/events.inc"
	.include "data/maps/Route128/events.inc"
	.include "data/maps/Route129/events.inc"
	.include "data/maps/Route130/events.inc"
	.include "data/maps/Route131/events.inc"
	.include "data/maps/Route132/events.inc"
	.include "data/maps/Route133/events.inc"
	.include "data/maps/Route134/events.inc"
	.include "data/maps/Underwater_Route124/events.inc"
	.include "data/maps/Underwater_Route126/events.inc"
	.include "data/maps/Underwater_Route127/events.inc"
	.include "data/maps/Underwater_Route128/events.inc"
	.include "data/maps/Underwater_Route129/events.inc"
	.include "data/maps/Underwater_Route105/events.inc"
	.include "data/maps/Underwater_Route125/events.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_1F/events.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_2F/events.inc"
	.include "data/maps/LittlerootTown_MaysHouse_1F/events.inc"
	.include "data/maps/LittlerootTown_MaysHouse_2F/events.inc"
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/events.inc"
	.include "data/maps/OldaleTown_House1/events.inc"
	.include "data/maps/OldaleTown_House2/events.inc"
	.include "data/maps/OldaleTown_PokemonCenter_1F/events.inc"
	.include "data/maps/OldaleTown_PokemonCenter_2F/events.inc"
	.include "data/maps/OldaleTown_Mart/events.inc"
	.include "data/maps/DewfordTown_House1/events.inc"
	.include "data/maps/DewfordTown_PokemonCenter_1F/events.inc"
	.include "data/maps/DewfordTown_PokemonCenter_2F/events.inc"
	.include "data/maps/DewfordTown_Gym/events.inc"
	.include "data/maps/DewfordTown_Hall/events.inc"
	.include "data/maps/DewfordTown_House2/events.inc"
	.include "data/maps/LavaridgeTown_HerbShop/events.inc"
	.include "data/maps/LavaridgeTown_Gym_1F/events.inc"
	.include "data/maps/LavaridgeTown_Gym_B1F/events.inc"
	.include "data/maps/LavaridgeTown_House/events.inc"
	.include "data/maps/LavaridgeTown_Mart/events.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/events.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/events.inc"
	.include "data/maps/FallarborTown_Mart/events.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/events.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/events.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/events.inc"
	.include "data/maps/FallarborTown_PokemonCenter_1F/events.inc"
	.include "data/maps/FallarborTown_PokemonCenter_2F/events.inc"
	.include "data/maps/FallarborTown_CozmosHouse/events.inc"
	.include "data/maps/FallarborTown_MoveRelearnersHouse/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/events.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/events.inc"
	.include "data/maps/VerdanturfTown_Mart/events.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/events.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/events.inc"
	.include "data/maps/VerdanturfTown_WandasHouse/events.inc"
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/events.inc"
	.include "data/maps/VerdanturfTown_House/events.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/events.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/events.inc"
	.include "data/maps/PacifidlogTown_House1/events.inc"
	.include "data/maps/PacifidlogTown_House2/events.inc"
	.include "data/maps/PacifidlogTown_House3/events.inc"
	.include "data/maps/PacifidlogTown_House4/events.inc"
	.include "data/maps/PacifidlogTown_House5/events.inc"
	.include "data/maps/PetalburgCity_WallysHouse/events.inc"
	.include "data/maps/PetalburgCity_Gym/events.inc"
	.include "data/maps/PetalburgCity_House1/events.inc"
	.include "data/maps/PetalburgCity_House2/events.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_1F/events.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_2F/events.inc"
	.include "data/maps/PetalburgCity_Mart/events.inc"
	.include "data/maps/SlateportCity_SternsShipyard_1F/events.inc"
	.include "data/maps/SlateportCity_SternsShipyard_2F/events.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/events.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/events.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/events.inc"
	.include "data/maps/SlateportCity_NameRatersHouse/events.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/events.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/events.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/events.inc"
	.include "data/maps/SlateportCity_Harbor/events.inc"
	.include "data/maps/SlateportCity_House/events.inc"
	.include "data/maps/SlateportCity_PokemonCenter_1F/events.inc"
	.include "data/maps/SlateportCity_PokemonCenter_2F/events.inc"
	.include "data/maps/SlateportCity_Mart/events.inc"
	.include "data/maps/MauvilleCity_Gym/events.inc"
	.include "data/maps/MauvilleCity_BikeShop/events.inc"
	.include "data/maps/MauvilleCity_House1/events.inc"
	.include "data/maps/MauvilleCity_GameCorner/events.inc"
	.include "data/maps/MauvilleCity_House2/events.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_1F/events.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_2F/events.inc"
	.include "data/maps/MauvilleCity_Mart/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_1F/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_2F/events.inc"
	.include "data/maps/RustboroCity_DevonCorp_3F/events.inc"
	.include "data/maps/RustboroCity_Gym/events.inc"
	.include "data/maps/RustboroCity_PokemonSchool/events.inc"
	.include "data/maps/RustboroCity_PokemonCenter_1F/events.inc"
	.include "data/maps/RustboroCity_PokemonCenter_2F/events.inc"
	.include "data/maps/RustboroCity_Mart/events.inc"
	.include "data/maps/RustboroCity_Flat1_1F/events.inc"
	.include "data/maps/RustboroCity_Flat1_2F/events.inc"
	.include "data/maps/RustboroCity_House1/events.inc"
	.include "data/maps/RustboroCity_CuttersHouse/events.inc"
	.include "data/maps/RustboroCity_House2/events.inc"
	.include "data/maps/RustboroCity_Flat2_1F/events.inc"
	.include "data/maps/RustboroCity_Flat2_2F/events.inc"
	.include "data/maps/RustboroCity_Flat2_3F/events.inc"
	.include "data/maps/RustboroCity_House3/events.inc"
	.include "data/maps/FortreeCity_House1/events.inc"
	.include "data/maps/FortreeCity_Gym/events.inc"
	.include "data/maps/FortreeCity_PokemonCenter_1F/events.inc"
	.include "data/maps/FortreeCity_PokemonCenter_2F/events.inc"
	.include "data/maps/FortreeCity_Mart/events.inc"
	.include "data/maps/FortreeCity_House2/events.inc"
	.include "data/maps/FortreeCity_House3/events.inc"
	.include "data/maps/FortreeCity_House4/events.inc"
	.include "data/maps/FortreeCity_House5/events.inc"
	.include "data/maps/FortreeCity_DecorationShop/events.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/events.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/events.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/events.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/events.inc"
	.include "data/maps/LilycoveCity_ContestLobby/events.inc"
	.include "data/maps/LilycoveCity_ContestHall/events.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_1F/events.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_2F/events.inc"
	.include "data/maps/LilycoveCity_UnusedMart/events.inc"
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/events.inc"
	.include "data/maps/LilycoveCity_Harbor/events.inc"
	.include "data/maps/LilycoveCity_MoveDeletersHouse/events.inc"
	.include "data/maps/LilycoveCity_House1/events.inc"
	.include "data/maps/LilycoveCity_House2/events.inc"
	.include "data/maps/LilycoveCity_House3/events.inc"
	.include "data/maps/LilycoveCity_House4/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_1F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_2F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_3F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_4F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_5F/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/events.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/events.inc"
	.include "data/maps/MossdeepCity_Gym/events.inc"
	.include "data/maps/MossdeepCity_House1/events.inc"
	.include "data/maps/MossdeepCity_House2/events.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_1F/events.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_2F/events.inc"
	.include "data/maps/MossdeepCity_Mart/events.inc"
	.include "data/maps/MossdeepCity_House3/events.inc"
	.include "data/maps/MossdeepCity_StevensHouse/events.inc"
	.include "data/maps/MossdeepCity_House4/events.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_1F/events.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_2F/events.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/events.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/events.inc"
	.include "data/maps/SootopolisCity_Gym_1F/events.inc"
	.include "data/maps/SootopolisCity_Gym_B1F/events.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_1F/events.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_2F/events.inc"
	.include "data/maps/SootopolisCity_Mart/events.inc"
	.include "data/maps/SootopolisCity_House1/events.inc"
	.include "data/maps/SootopolisCity_House2/events.inc"
	.include "data/maps/SootopolisCity_House3/events.inc"
	.include "data/maps/SootopolisCity_House4/events.inc"
	.include "data/maps/SootopolisCity_House5/events.inc"
	.include "data/maps/SootopolisCity_House6/events.inc"
	.include "data/maps/SootopolisCity_House7/events.inc"
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/events.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/events.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/events.inc"
	.include "data/maps/EverGrandeCity_SidneysRoom/events.inc"
	.include "data/maps/EverGrandeCity_PhoebesRoom/events.inc"
	.include "data/maps/EverGrandeCity_GlaciasRoom/events.inc"
	.include "data/maps/EverGrandeCity_DrakesRoom/events.inc"
	.include "data/maps/EverGrandeCity_ChampionsRoom/events.inc"
	.include "data/maps/EverGrandeCity_Hall1/events.inc"
	.include "data/maps/EverGrandeCity_Hall2/events.inc"
	.include "data/maps/EverGrandeCity_Hall3/events.inc"
	.include "data/maps/EverGrandeCity_Hall4/events.inc"
	.include "data/maps/EverGrandeCity_Hall5/events.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/events.inc"
	.include "data/maps/EverGrandeCity_HallOfFame/events.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/events.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/events.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/events.inc"
	.include "data/maps/Route104_MrBrineysHouse/events.inc"
	.include "data/maps/Route104_PrettyPetalFlowerShop/events.inc"
	.include "data/maps/Route111_WinstrateFamilysHouse/events.inc"
	.include "data/maps/Route111_OldLadysRestStop/events.inc"
	.include "data/maps/Route112_CableCarStation/events.inc"
	.include "data/maps/MtChimney_CableCarStation/events.inc"
	.include "data/maps/Route114_FossilManiacsHouse/events.inc"
	.include "data/maps/Route114_FossilManiacsTunnel/events.inc"
	.include "data/maps/Route114_LanettesHouse/events.inc"
	.include "data/maps/Route116_TunnelersRestHouse/events.inc"
	.include "data/maps/Route117_PokemonDayCare/events.inc"
	.include "data/maps/Route121_SafariZoneEntrance/events.inc"
	.include "data/maps/MeteorFalls_1F_1R/events.inc"
	.include "data/maps/MeteorFalls_1F_2R/events.inc"
	.include "data/maps/MeteorFalls_B1F_1R/events.inc"
	.include "data/maps/MeteorFalls_B1F_2R/events.inc"
	.include "data/maps/RusturfTunnel/events.inc"
	.include "data/maps/Underwater_SootopolisCity/events.inc"
	.include "data/maps/DesertRuins/events.inc"
	.include "data/maps/GraniteCave_1F/events.inc"
	.include "data/maps/GraniteCave_B1F/events.inc"
	.include "data/maps/GraniteCave_B2F/events.inc"
	.include "data/maps/GraniteCave_StevensRoom/events.inc"
	.include "data/maps/PetalburgWoods/events.inc"
	.include "data/maps/MtChimney/events.inc"
	.include "data/maps/JaggedPass/events.inc"
	.include "data/maps/FieryPath/events.inc"
	.include "data/maps/MtPyre_1F/events.inc"
	.include "data/maps/MtPyre_2F/events.inc"
	.include "data/maps/MtPyre_3F/events.inc"
	.include "data/maps/MtPyre_4F/events.inc"
	.include "data/maps/MtPyre_5F/events.inc"
	.include "data/maps/MtPyre_6F/events.inc"
	.include "data/maps/MtPyre_Exterior/events.inc"
	.include "data/maps/MtPyre_Summit/events.inc"
	.include "data/maps/AquaHideout_1F/events.inc"
	.include "data/maps/AquaHideout_B1F/events.inc"
	.include "data/maps/AquaHideout_B2F/events.inc"
	.include "data/maps/Underwater_SeafloorCavern/events.inc"
	.include "data/maps/SeafloorCavern_Entrance/events.inc"
	.include "data/maps/SeafloorCavern_Room1/events.inc"
	.include "data/maps/SeafloorCavern_Room2/events.inc"
	.include "data/maps/SeafloorCavern_Room3/events.inc"
	.include "data/maps/SeafloorCavern_Room4/events.inc"
	.include "data/maps/SeafloorCavern_Room5/events.inc"
	.include "data/maps/SeafloorCavern_Room6/events.inc"
	.include "data/maps/SeafloorCavern_Room7/events.inc"
	.include "data/maps/SeafloorCavern_Room8/events.inc"
	.include "data/maps/SeafloorCavern_Room9/events.inc"
	.include "data/maps/CaveOfOrigin_Entrance/events.inc"
	.include "data/maps/CaveOfOrigin_1F/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/events.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/events.inc"
	.include "data/maps/CaveOfOrigin_B1F/events.inc"
	.include "data/maps/VictoryRoad_1F/events.inc"
	.include "data/maps/VictoryRoad_B1F/events.inc"
	.include "data/maps/VictoryRoad_B2F/events.inc"
	.include "data/maps/ShoalCave_LowTideEntranceRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideInnerRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideStairsRoom/events.inc"
	.include "data/maps/ShoalCave_LowTideLowerRoom/events.inc"
	.include "data/maps/ShoalCave_HighTideEntranceRoom/events.inc"
	.include "data/maps/ShoalCave_HighTideInnerRoom/events.inc"
	.include "data/maps/NewMauville_Entrance/events.inc"
	.include "data/maps/NewMauville_Inside/events.inc"
	.include "data/maps/AbandonedShip_Deck/events.inc"
	.include "data/maps/AbandonedShip_Corridors_1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms_1F/events.inc"
	.include "data/maps/AbandonedShip_Corridors_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms2_B1F/events.inc"
	.include "data/maps/AbandonedShip_Underwater1/events.inc"
	.include "data/maps/AbandonedShip_Room_B1F/events.inc"
	.include "data/maps/AbandonedShip_Rooms2_1F/events.inc"
	.include "data/maps/AbandonedShip_CaptainsOffice/events.inc"
	.include "data/maps/AbandonedShip_Underwater2/events.inc"
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/events.inc"
	.include "data/maps/AbandonedShip_HiddenFloorRooms/events.inc"
	.include "data/maps/IslandCave/events.inc"
	.include "data/maps/AncientTomb/events.inc"
	.include "data/maps/Underwater_Route134/events.inc"
	.include "data/maps/Underwater_SealedChamber/events.inc"
	.include "data/maps/SealedChamber_OuterRoom/events.inc"
	.include "data/maps/SealedChamber_InnerRoom/events.inc"
	.include "data/maps/ScorchedSlab/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap1/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap2/events.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap3/events.inc"
	.include "data/maps/SkyPillar_Entrance/events.inc"
	.include "data/maps/SkyPillar_Outside/events.inc"
	.include "data/maps/SkyPillar_1F/events.inc"
	.include "data/maps/SkyPillar_2F/events.inc"
	.include "data/maps/SkyPillar_3F/events.inc"
	.include "data/maps/SkyPillar_4F/events.inc"
	.include "data/maps/ShoalCave_LowTideIceRoom/events.inc"
	.include "data/maps/SkyPillar_5F/events.inc"
	.include "data/maps/SkyPillar_Top/events.inc"
	.include "data/maps/MagmaHideout_1F/events.inc"
	.include "data/maps/MagmaHideout_2F_1R/events.inc"
	.include "data/maps/MagmaHideout_2F_2R/events.inc"
	.include "data/maps/MagmaHideout_3F_1R/events.inc"
	.include "data/maps/MagmaHideout_3F_2R/events.inc"
	.include "data/maps/MagmaHideout_4F/events.inc"
	.include "data/maps/MagmaHideout_3F_3R/events.inc"
	.include "data/maps/MagmaHideout_2F_3R/events.inc"
	.include "data/maps/MirageTower_1F/events.inc"
	.include "data/maps/MirageTower_2F/events.inc"
	.include "data/maps/MirageTower_3F/events.inc"
	.include "data/maps/MirageTower_4F/events.inc"
	.include "data/maps/DesertUnderpass/events.inc"
	.include "data/maps/ArtisanCave_B1F/events.inc"
	.include "data/maps/ArtisanCave_1F/events.inc"
	.include "data/maps/Underwater_MarineCave/events.inc"
	.include "data/maps/MarineCave_Entrance/events.inc"
	.include "data/maps/MarineCave_End/events.inc"
	.include "data/maps/TerraCave_Entrance/events.inc"
	.include "data/maps/TerraCave_End/events.inc"
	.include "data/maps/AlteringCave/events.inc"
	.include "data/maps/MeteorFalls_StevensCave/events.inc"
	.include "data/maps/SecretBase_RedCave1/events.inc"
	.include "data/maps/SecretBase_BrownCave1/events.inc"
	.include "data/maps/SecretBase_BlueCave1/events.inc"
	.include "data/maps/SecretBase_YellowCave1/events.inc"
	.include "data/maps/SecretBase_Tree1/events.inc"
	.include "data/maps/SecretBase_Shrub1/events.inc"
	.include "data/maps/SecretBase_RedCave2/events.inc"
	.include "data/maps/SecretBase_BrownCave2/events.inc"
	.include "data/maps/SecretBase_BlueCave2/events.inc"
	.include "data/maps/SecretBase_YellowCave2/events.inc"
	.include "data/maps/SecretBase_Tree2/events.inc"
	.include "data/maps/SecretBase_Shrub2/events.inc"
	.include "data/maps/SecretBase_RedCave3/events.inc"
	.include "data/maps/SecretBase_BrownCave3/events.inc"
	.include "data/maps/SecretBase_BlueCave3/events.inc"
	.include "data/maps/SecretBase_YellowCave3/events.inc"
	.include "data/maps/SecretBase_Tree3/events.inc"
	.include "data/maps/SecretBase_Shrub3/events.inc"
	.include "data/maps/SecretBase_RedCave4/events.inc"
	.include "data/maps/SecretBase_BrownCave4/events.inc"
	.include "data/maps/SecretBase_BlueCave4/events.inc"
	.include "data/maps/SecretBase_YellowCave4/events.inc"
	.include "data/maps/SecretBase_Tree4/events.inc"
	.include "data/maps/SecretBase_Shrub4/events.inc"
	.include "data/maps/BattleColosseum_2P/events.inc"
	.include "data/maps/TradeCenter/events.inc"
	.include "data/maps/RecordCorner/events.inc"
	.include "data/maps/BattleColosseum_4P/events.inc"
	.include "data/maps/ContestHall/events.inc"
	.include "data/maps/InsideOfTruck/events.inc"
	.include "data/maps/SSTidalCorridor/events.inc"
	.include "data/maps/SSTidalLowerDeck/events.inc"
	.include "data/maps/SSTidalRooms/events.inc"
	.include "data/maps/BattlePyramidSquare01/events.inc"
	.include "data/maps/BattlePyramidSquare02/events.inc"
	.include "data/maps/BattlePyramidSquare03/events.inc"
	.include "data/maps/BattlePyramidSquare04/events.inc"
	.include "data/maps/BattlePyramidSquare05/events.inc"
	.include "data/maps/BattlePyramidSquare06/events.inc"
	.include "data/maps/BattlePyramidSquare07/events.inc"
	.include "data/maps/BattlePyramidSquare08/events.inc"
	.include "data/maps/BattlePyramidSquare09/events.inc"
	.include "data/maps/BattlePyramidSquare10/events.inc"
	.include "data/maps/BattlePyramidSquare11/events.inc"
	.include "data/maps/BattlePyramidSquare12/events.inc"
	.include "data/maps/BattlePyramidSquare13/events.inc"
	.include "data/maps/BattlePyramidSquare14/events.inc"
	.include "data/maps/BattlePyramidSquare15/events.inc"
	.include "data/maps/BattlePyramidSquare16/events.inc"
	.include "data/maps/UnionRoom/events.inc"
	.include "data/maps/SafariZone_Northwest/events.inc"
	.include "data/maps/SafariZone_North/events.inc"
	.include "data/maps/SafariZone_Southwest/events.inc"
	.include "data/maps/SafariZone_South/events.inc"
	.include "data/maps/BattleFrontier_OutsideWest/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/events.inc"
	.include "data/maps/SouthernIsland_Exterior/events.inc"
	.include "data/maps/SouthernIsland_Interior/events.inc"
	.include "data/maps/SafariZone_RestHouse/events.inc"
	.include "data/maps/SafariZone_Northeast/events.inc"
	.include "data/maps/SafariZone_Southeast/events.inc"
	.include "data/maps/BattleFrontier_OutsideEast/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/events.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/events.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/events.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/events.inc"
	.incbin "baserom_jp.gba", 0x5152DC, 0x22A0

	.globl gWeatherBallUpSpriteTemplate
gWeatherBallUpSpriteTemplate: @ 0x851757C
	.incbin "baserom_jp.gba", 0x51757C, 0x18

	.globl gWeatherBallNormalDownSpriteTemplate
gWeatherBallNormalDownSpriteTemplate: @ 0x8517594
	.incbin "baserom_jp.gba", 0x517594, 0x18

	.incbin "baserom_jp.gba", 0x5175AC, 0x1C

	.globl gSpinningSparkleSpriteTemplate
gSpinningSparkleSpriteTemplate: @ 0x85175C8
	.incbin "baserom_jp.gba", 0x5175C8, 0x18

	.incbin "baserom_jp.gba", 0x5175E0, 0xAC

	.section .rodata.data_b2d_mid26_after_battle_anim_status_effects_before_field_weather_drought
	.incbin "baserom_jp.gba", 0x5176d4, 0x3cc

	.globl gTitleScreenPokemonLogoTilemap
gTitleScreenPokemonLogoTilemap: @ 0x8517AA0
	.incbin "graphics/title_screen/gTitleScreenPokemonLogoTilemap.bin"

	.globl gTitleScreenBgPalettes
gTitleScreenBgPalettes: @ 0x8517B58
	.incbin "graphics/title_screen/gTitleScreenBgPalettes.bin"

	.globl gTitleScreenPokemonLogoGfx
gTitleScreenPokemonLogoGfx: @ 0x8517C18
	.incbin "graphics/title_screen/gTitleScreenPokemonLogoGfx.bin"

	.globl sTitleScreenRayquazaGfx
sTitleScreenRayquazaGfx: @ 0x8519AB4
	.incbin "graphics/title_screen/sTitleScreenRayquazaGfx.bin"

	.globl sTitleScreenRayquazaTilemap
sTitleScreenRayquazaTilemap: @ 0x851A298
	.incbin "graphics/title_screen/sTitleScreenRayquazaTilemap.bin"

	.globl sTitleScreenCloudsGfx
sTitleScreenCloudsGfx: @ 0x851A6E8
	.incbin "graphics/title_screen/sTitleScreenCloudsGfx.bin"

	.globl gTitleScreenCloudsTilemap
gTitleScreenCloudsTilemap: @ 0x851A9CC
	.incbin "graphics/title_screen/gTitleScreenCloudsTilemap.bin"

	.globl gTitleScreenAlphaBlend
gTitleScreenAlphaBlend: @ 0x851AC0C
	.4byte 0x01100010, 0x03100210, 0x05100410, 0x07100610
	.4byte 0x09100810, 0x0B100A10, 0x0D100C10, 0x0F100E10
	.4byte 0x100E100F, 0x100C100D, 0x100A100B, 0x10081009
	.4byte 0x10061007, 0x10041005, 0x10021003, 0x10001001
	.4byte 0x10001000, 0x10001000, 0x10001000, 0x10001000
	.4byte 0x10001000, 0x10001000, 0x10001000, 0x10001000
	.4byte 0x10001000, 0x10001000, 0x10001000, 0x10001000
	.4byte 0x10001000, 0x10001000, 0x10001000, 0x10001000

	.globl sOam_VersionBannerLeft
sOam_VersionBannerLeft: @ 0x851AC8C
	.4byte 0xC00060A0
	.hword 0x0000, 0x0000

	.globl sOam_VersionBannerRight
sOam_VersionBannerRight: @ 0x851AC94
	.4byte 0x800020A0
	.hword 0x0000, 0x0000

	.globl sAnim_VersionBanner
sAnim_VersionBanner: @ 0x851AC9C
	.hword 0x0000, 0x001E
	.hword 0xFFFF, 0x0000
sAnim_VersionBanner_1: @ 0x851ACA4
	.hword 0x0040, 0x001E
	.hword 0xFFFF, 0x0000

	.globl sAnims_VersionBanner
sAnims_VersionBanner: @ 0x851ACAC
	.4byte sAnim_VersionBanner, sAnim_VersionBanner_1

	.globl sVersionBannerLeftSpriteTemplate
sVersionBannerLeftSpriteTemplate: @ 0x851ACB4
	.hword 0x03E8, 0x03E8
	.4byte sOam_VersionBannerLeft, sAnims_VersionBanner, 0, gDummySpriteAffineAnimTable, 0x080A9CD5

	.globl sVersionBannerRightSpriteTemplate
sVersionBannerRightSpriteTemplate: @ 0x851ACCC
	.hword 0x03E8, 0x03E8
	.4byte sOam_VersionBannerRight, sAnims_VersionBanner + 4, 0, gDummySpriteAffineAnimTable, 0x080A9D3D

	.globl sSpriteSheet_EmeraldVersion
sSpriteSheet_EmeraldVersion: @ 0x851ACE4
	.4byte 0x0851938C
	.hword 0x1000, 0x03E8
	.4byte 0x00000000, 0x00000000

	.globl sOam_EmeraldVersion
sOam_EmeraldVersion: @ 0x851ACF4
	.4byte 0x400040A0
	.hword 0x0000, 0x0000

	.globl sAnim_EmeraldVersion
sAnim_EmeraldVersion: @ 0x851ACFC
	.hword 0x0001, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0005, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0009, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x000D, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0011, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0015, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0019, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x001D, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0021, 0x0004
	.hword 0xFFFF, 0x0000
	.hword 0x0025, 0x0004
	.hword 0xFFFF, 0x0000

	.globl sAnims_EmeraldVersion
sAnims_EmeraldVersion: @ 0x851AD4C
	.4byte sAnim_EmeraldVersion + 0x0, sAnim_EmeraldVersion + 0x8, sAnim_EmeraldVersion + 0x10, sAnim_EmeraldVersion + 0x18
	.4byte sAnim_EmeraldVersion + 0x20, sAnim_EmeraldVersion + 0x28, sAnim_EmeraldVersion + 0x30, sAnim_EmeraldVersion + 0x38
	.4byte sAnim_EmeraldVersion + 0x40, sAnim_EmeraldVersion + 0x48

	.globl sStartCopyrightBannerSpriteTemplate
sStartCopyrightBannerSpriteTemplate: @ 0x851AD74
	.hword 0x03E9, 0x03E9
	.4byte sOam_EmeraldVersion, sAnims_EmeraldVersion, 0, gDummySpriteAffineAnimTable, 0x080A9D7D

	.globl sSpriteSheet_PressStart
sSpriteSheet_PressStart: @ 0x851AD8C
	.4byte 0x085176F4
	.hword 0x0520, 0x03E9
	.4byte 0x00000000, 0x00000000

	.globl sSpritePalette_PressStart
sSpritePalette_PressStart: @ 0x851AD9C
	.4byte 0x085176D4
	.hword 0x03E9, 0x0000
	.4byte 0x00000000, 0x00000000

	.globl sOam_PokemonLogoShine
sOam_PokemonLogoShine: @ 0x851ADAC
	.4byte 0xC00000A0
	.hword 0x0000, 0x0000

	.globl sAnim_PokemonLogoShine
sAnim_PokemonLogoShine: @ 0x851ADB4
	.hword 0x0000, 0x0004
	.hword 0xFFFF, 0x0000

	.globl sAnims_PokemonLogoShine
sAnims_PokemonLogoShine: @ 0x851ADBC
	.4byte sAnim_PokemonLogoShine

	.globl sPokemonLogoShineSpriteTemplate
sPokemonLogoShineSpriteTemplate: @ 0x851ADC0
	.hword 0x03EA, 0x03E9
	.4byte sOam_PokemonLogoShine, sAnims_PokemonLogoShine, 0, gDummySpriteAffineAnimTable, 0x080A9E6D

	.globl sPokemonLogoShineSpriteSheet
sPokemonLogoShineSpriteSheet: @ 0x851ADD8
	.4byte 0x0851A598
	.hword 0x0800, 0x03EA
	.4byte 0x00000000, 0x00000000

	.section .rodata.data_b2d_mid26_after_field_weather_drought

	.globl gWeatherPtr
gWeatherPtr: @ 0x8526DE8
	.4byte gUnknown_20380F4 @ &gWeather

	.globl gUnknown_8526DEC
gUnknown_8526DEC: @ 0x8526DEC
	.incbin "baserom_jp.gba", 0x526dec, 0xf0

	.globl gUnknown_8526EDC
gUnknown_8526EDC: @ 0x8526EDC
	.incbin "baserom_jp.gba", 0x526edc, 0x10

	.globl gUnknown_8526EEC
gUnknown_8526EEC: @ 0x8526EEC
	.incbin "baserom_jp.gba", 0x526eec, 0x20

	.globl gFogPalette
gFogPalette: @ 0x8526F0C
	.incbin "graphics/field_effects/gFogPalette.bin"

	.globl gUnknown_8526F2C
gUnknown_8526F2C: @ 0x8526F2C
	.incbin "baserom_jp.gba", 0x526f2c, 0x20

	.globl gUnknown_8526F4C
gUnknown_8526F4C: @ 0x8526F4C
	.incbin "baserom_jp.gba", 0x526f4c, 0x820

	.globl gWeatherFogHorizontalTiles
gWeatherFogHorizontalTiles: @ 0x852776C
	.incbin "graphics/misc/gWeatherFogHorizontalTiles.bin"

	.globl gUnknown_852A7EC
gUnknown_852A7EC: @ 0x852A7EC
	.incbin "baserom_jp.gba", 0x52a7ec, 0xc

	.globl gUnknown_852A7F8
gUnknown_852A7F8: @ 0x852A7F8
	.incbin "baserom_jp.gba", 0x52a7f8, 0x1c

	.globl gUnknown_852A814
gUnknown_852A814: @ 0x852A814
	.incbin "baserom_jp.gba", 0x52a814, 0x18

	.globl gUnknown_852A82C
gUnknown_852A82C: @ 0x852A82C
	.incbin "baserom_jp.gba", 0x52a82c, 0x9c

	.globl gUnknown_852A8C8
gUnknown_852A8C8: @ 0x852A8C8
	.incbin "baserom_jp.gba", 0x52a8c8, 0x18

	.globl gUnknown_852A8E0
gUnknown_852A8E0: @ 0x852A8E0
	.incbin "baserom_jp.gba", 0x52a8e0, 0x8

	.globl gUnknown_852A8E8
gUnknown_852A8E8: @ 0x852A8E8
	.incbin "baserom_jp.gba", 0x52a8e8, 0x8

	.globl gUnknown_852A8F0
gUnknown_852A8F0: @ 0x852A8F0
	.incbin "baserom_jp.gba", 0x52a8f0, 0x38

	.globl gUnknown_852A928
gUnknown_852A928: @ 0x852A928
	.incbin "baserom_jp.gba", 0x52a928, 0x8c

	.globl gUnknown_852A9B4
gUnknown_852A9B4: @ 0x852A9B4
	.incbin "baserom_jp.gba", 0x52a9b4, 0x18

	.globl gUnknown_852A9CC
gUnknown_852A9CC: @ 0x852A9CC
	.incbin "baserom_jp.gba", 0x52a9cc, 0x8

	.globl gUnknown_852A9D4
gUnknown_852A9D4: @ 0x852A9D4
	.incbin "baserom_jp.gba", 0x52a9d4, 0x20

	.globl gUnknown_852A9F4
gUnknown_852A9F4: @ 0x852A9F4
	.incbin "baserom_jp.gba", 0x52a9f4, 0x18

	.globl gUnknown_852AA0C
gUnknown_852AA0C: @ 0x852AA0C
	.incbin "baserom_jp.gba", 0x52aa0c, 0x1c

	.globl gUnknown_852AA28
gUnknown_852AA28: @ 0x852AA28
	.incbin "baserom_jp.gba", 0x52aa28, 0x38

	.globl gUnknown_852AA60
gUnknown_852AA60: @ 0x852AA60
	.incbin "baserom_jp.gba", 0x52aa60, 0x18

	.globl gUnknown_852AA78
gUnknown_852AA78: @ 0x852AA78
	.incbin "baserom_jp.gba", 0x52aa78, 0x8

	.globl gUnknown_852AA80
gUnknown_852AA80: @ 0x852AA80
	.incbin "baserom_jp.gba", 0x52aa80, 0xc

	.globl gUnknown_852AA8C
gUnknown_852AA8C: @ 0x852AA8C
	.incbin "baserom_jp.gba", 0x52aa8c, 0x8

	.globl gUnknown_852AA94
gUnknown_852AA94: @ 0x852AA94
	.incbin "baserom_jp.gba", 0x52aa94, 0x8

	.globl gUnknown_852AA9C
gUnknown_852AA9C: @ 0x852AA9C
	.incbin "baserom_jp.gba", 0x52aa9c, 0x44

	.globl gUnknown_852AAE0
gUnknown_852AAE0: @ 0x852AAE0
	.incbin "baserom_jp.gba", 0x52aae0, 0x18

	.globl sWeatherCycleRoute119
sWeatherCycleRoute119: @ 0x852AAF8
	.byte 0x02, 0x03, 0x05, 0x03

	.globl sWeatherCycleRoute123
sWeatherCycleRoute123: @ 0x852AAFC
	.byte 0x02, 0x02, 0x03, 0x02

	.globl sFlashLevelToRadius
sFlashLevelToRadius: @ 0x852AB00
	.hword 0x00C8, 0x0048, 0x0040, 0x0038, 0x0030, 0x0028, 0x0020, 0x0018, 0x0000, 0x0000

	.globl gMaxFlashLevel
gMaxFlashLevel: @ 0x852AB14
gMaxFlashLevel: @ 0x852AB14
	.4byte 8

	.globl sFlashEffectParams
sFlashEffectParams: @ 0x852AB18
sFlashEffectParams: @ 0x852AB18
	.4byte 0x04000040  @ dmaDest
	.4byte 0xA2600001  @ dmaControl
	.byte 0x01  @ initState
	.byte 0x00, 0x00, 0x00

	.globl sBattleTransitionTable_Wild
sBattleTransitionTable_Wild: @ 0x852AB24
	.byte 0x08, 0x09, 0x05, 0x0A, 0x00, 0x0A, 0x07, 0x06

	.globl sBattleTransitionTable_Trainer
sBattleTransitionTable_Trainer: @ 0x852AB2C
	.byte 0x04, 0x0B, 0x02, 0x03, 0x00, 0x0A, 0x01, 0x06

	.globl sBattleTransitionTable_BattleFrontier
sBattleTransitionTable_BattleFrontier: @ 0x852AB34
	.byte 0x1D, 0x1E, 0x1F, 0x20, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29

	.globl sBattleTransitionTable_BattlePyramid
sBattleTransitionTable_BattlePyramid: @ 0x852AB40
	.byte 0x1F, 0x20, 0x21

	.globl sBattleTransitionTable_BattleDome
sBattleTransitionTable_BattleDome: @ 0x852AB43
	.byte 0x1D, 0x1F, 0x20, 0x21, 0x00

	.globl sOrdinaryBattleParams
sOrdinaryBattleParams: @ 0x0052AB48
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptBattleParams
sContinueScriptBattleParams: @ 0x0052AB90
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sDoubleBattleParams
sDoubleBattleParams: @ 0x0052ABD8
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sOrdinaryNoIntroBattleParams
sOrdinaryNoIntroBattleParams: @ 0x0052AC20
	.4byte 0x02038868  @ varPtr
	.byte 0x00  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870  @ varPtr
	.byte 0x01  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C  @ varPtr
	.byte 0x02  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890  @ varPtr
	.byte 0x05  @ ptrType
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C  @ varPtr
	.byte 0x06  @ ptrType
	.byte 0x00, 0x00, 0x00

	.globl sContinueScriptDoubleBattleParams
sContinueScriptDoubleBattleParams: @ 0x0052AC68
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886A
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038874
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203887C
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038890
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBOrdinaryBattleParams
sTrainerBOrdinaryBattleParams: @ 0x0052ACB0
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl sTrainerBContinueScriptBattleParams
sTrainerBContinueScriptBattleParams: @ 0x0052ACF8
	.4byte 0x02038868
	.byte 0x00
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203886C
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038870
	.byte 0x01
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038878
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038880
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038884
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038888
	.byte 0x05
	.byte 0x00, 0x00, 0x00
	.4byte 0x02038894
	.byte 0x02
	.byte 0x00, 0x00, 0x00
	.4byte 0x0203888C
	.byte 0x06
	.byte 0x00, 0x00, 0x00

	.globl gUnknown_852AD40
gUnknown_852AD40: @ 0x852AD40
	.incbin "baserom_jp.gba", 0x52ad40, 0x4e0

	.globl sBadgeFlagsJp
sBadgeFlagsJp: @ 0x852B220
	.hword 0x0867, 0x0868, 0x0869, 0x086A, 0x086B, 0x086C, 0x086D, 0x086E

	.globl sWindowTemplate_LinkPlayerCount
	.set sWindowTemplate_LinkPlayerCount, sBadgeFlagsJp + 0x1C

	.globl sTrainerCardColorNames
	.set sTrainerCardColorNames, sBadgeFlagsJp + 0x1F

	.incbin "baserom_jp.gba", 0x52b230, 0x1a8

	.globl sDirectionalApproachDistanceFuncs
sDirectionalApproachDistanceFuncs: @ 0x852B3D8
	.4byte 0x080B35F9, 0x080B363D, 0x080B3681, 0x080B36C5

	.globl sTrainerSeeFuncList
sTrainerSeeFuncList: @ 0x852B3E8
	.4byte 0x080B38D1, 0x080B38D5, 0x080B3919, 0x080B3959
	.4byte 0x080B39B5, 0x080B3A71, 0x080B3AB5, 0x080B3AE9
	.4byte 0x080B3B05, 0x080B3B39, 0x080B3B91, 0x080B3C05

	.globl sTrainerSeeFuncList2
sTrainerSeeFuncList2: @ 0x852B418
	.4byte 0x080B3B05, 0x080B3B39, 0x080B3B91, 0x080B3C05
	.4byte 0x40000000, 0x00000400, 0x0852B258, 0x00000080
	.4byte 0x0852B2D8, 0x00000080, 0x0852B358, 0x00000080
	.4byte 0x003C0000, 0x0000FFFF, 0x003C0001, 0x0000FFFF
	.4byte 0x0852B448, 0x0852B450

	.globl sSpriteTemplate_ExclamationQuestionMark
sSpriteTemplate_ExclamationQuestionMark: @ 0x852B460
	.hword 0xFFFF, 0xFFFF
	.4byte 0x0852B428, 0x0852B458, 0x0852B430, gDummySpriteAffineAnimTable, 0x080B3E7D
	.globl sSpriteTemplate_HeartIcon
sSpriteTemplate_HeartIcon: @ 0x852B478
	.hword 0xFFFF, 0x1004
	.4byte 0x0852B428, 0x0852B458, 0x0852B440, gDummySpriteAffineAnimTable, 0x080B3E7D
	.incbin "baserom_jp.gba", 0x52b490, 0x2564

	.globl gUnknown_852D9F4
gUnknown_852D9F4: @ 0x852D9F4
	.incbin "baserom_jp.gba", 0x52d9f4, 0x9c4
	.globl gBattlePyramid_1_LandMons
gBattlePyramid_1_LandMons: @ 0x852E3B8
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_BULBASAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_1_LandMonsInfo
gBattlePyramid_1_LandMonsInfo: @ 0x852E3E8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_1_LandMons
	.globl gBattlePyramid_2_LandMons
gBattlePyramid_2_LandMons: @ 0x852E3F0
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_IVYSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.globl gBattlePyramid_2_LandMonsInfo
gBattlePyramid_2_LandMonsInfo: @ 0x852E420
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_2_LandMons
	.globl gBattlePyramid_3_LandMons
gBattlePyramid_3_LandMons: @ 0x852E428
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_VENUSAUR
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.globl gBattlePyramid_3_LandMonsInfo
gBattlePyramid_3_LandMonsInfo: @ 0x852E458
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_3_LandMons
	.globl gBattlePyramid_4_LandMons
gBattlePyramid_4_LandMons: @ 0x852E460
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMANDER
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.globl gBattlePyramid_4_LandMonsInfo
gBattlePyramid_4_LandMonsInfo: @ 0x852E490
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_4_LandMons
	.globl gBattlePyramid_5_LandMons
gBattlePyramid_5_LandMons: @ 0x852E498
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_5_LandMonsInfo
gBattlePyramid_5_LandMonsInfo: @ 0x852E4C8
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_5_LandMons
	.globl gBattlePyramid_6_LandMons
gBattlePyramid_6_LandMons: @ 0x852E4D0
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.globl gBattlePyramid_6_LandMonsInfo
gBattlePyramid_6_LandMonsInfo: @ 0x852E500
	.byte 4
	.byte 0, 0, 0
	.4byte gBattlePyramid_6_LandMons
	.globl gBattlePyramid_7_LandMons
gBattlePyramid_7_LandMons: @ 0x852E508
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_WARTORTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_SQUIRTLE
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARIZARD
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.byte 5, 5
	.hword SPECIES_CHARMELEON
	.globl gBattlePyramid_7_LandMonsInfo
gBattlePyramid_7_LandMonsInfo: @ 0x852E538
	.byte 8
	.byte 0, 0, 0
	.4byte gBattlePyramid_7_LandMons

	.globl gBattlePyramidWildMonHeaders
gBattlePyramidWildMonHeaders: @ 0x852E540
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_1_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_2_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_3_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_4_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 5 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_5_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 6 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_6_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 0, 7 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePyramid_7_LandMonsInfo
	.4byte 0x00000000 @ waterMonsInfo
	.4byte 0x00000000 @ rockSmashMonsInfo
	.4byte 0x00000000 @ fishingMonsInfo
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.globl gBattlePike_1_LandMons
gBattlePike_1_LandMons: @ 0x852E5E0
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_DUSCLOPS
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_1_LandMonsInfo
gBattlePike_1_LandMonsInfo: @ 0x852E610
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_1_LandMons
	.globl gBattlePike_2_LandMons
gBattlePike_2_LandMons: @ 0x852E618
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_ELECTRODE
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_2_LandMonsInfo
gBattlePike_2_LandMonsInfo: @ 0x852E648
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_2_LandMons
	.globl gBattlePike_3_LandMons
gBattlePike_3_LandMons: @ 0x852E650
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_BRELOOM
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_3_LandMonsInfo
gBattlePike_3_LandMonsInfo: @ 0x852E680
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_3_LandMons
	.globl gBattlePike_4_LandMons
gBattlePike_4_LandMons: @ 0x852E688
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_WOBBUFFET
	.byte 5, 5
	.hword SPECIES_SEVIPER
	.byte 5, 5
	.hword SPECIES_MILOTIC
	.globl gBattlePike_4_LandMonsInfo
gBattlePike_4_LandMonsInfo: @ 0x852E6B8
	.byte 10
	.byte 0, 0, 0
	.4byte gBattlePike_4_LandMons

	.globl gBattlePikeWildMonHeaders
gBattlePikeWildMonHeaders: @ 0x852E6C0
	.byte 0, 1 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_1_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 2 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_2_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 3 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_3_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 0, 4 @ mapGroup, mapNum
	.hword 0
	.4byte gBattlePike_4_LandMonsInfo
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL
	.byte 255, 255
	.hword 0
	.4byte 0 @ landMonsInfo NULL
	.4byte 0 @ waterMonsInfo NULL
	.4byte 0 @ rockSmashMonsInfo NULL
	.4byte 0 @ fishingMonsInfo NULL

	.globl sWildFeebas
sWildFeebas: @ 0x852E724
	.byte 20, 25 @ minLevel, maxLevel
	.hword SPECIES_FEEBAS @ 0x0148

	.globl gUnknown_852E728
gUnknown_852E728: @ 0x852E728
	.incbin "baserom_jp.gba", 0x52e728, 0x73d4

	.globl gUnknown_8535AFC
gUnknown_8535AFC: @ 0x8535AFC
	.incbin "baserom_jp.gba", 0x535afc, 0x200

	.globl gUnknown_8535CFC
gUnknown_8535CFC: @ 0x8535CFC
	.incbin "baserom_jp.gba", 0x535cfc, 0x20

	.globl gUnknown_8535D1C
gUnknown_8535D1C: @ 0x8535D1C
	.incbin "baserom_jp.gba", 0x535d1c, 0x280

	.globl gUnknown_8535F9C
gUnknown_8535F9C: @ 0x8535F9C
	.incbin "baserom_jp.gba", 0x535f9c, 0x80

	.globl gUnknown_853601C
gUnknown_853601C: @ 0x853601C
	.incbin "baserom_jp.gba", 0x53601c, 0x20

	.globl gUnknown_853603C
gUnknown_853603C: @ 0x853603C
	.incbin "baserom_jp.gba", 0x53603c, 0x280

	.globl gUnknown_85362BC
gUnknown_85362BC: @ 0x85362BC
	.incbin "baserom_jp.gba", 0x5362bc, 0x20

	.globl gUnknown_85362DC
gUnknown_85362DC: @ 0x85362DC
	.incbin "baserom_jp.gba", 0x5362dc, 0xbc0

	.globl gFieldEffectScriptFuncs
gFieldEffectScriptFuncs: @ 0x8536E9C
	.4byte FieldEffectCmd_loadtiles + 1, FieldEffectCmd_loadfadedpal + 1, FieldEffectCmd_loadpal + 1, FieldEffectCmd_callnative + 1, FieldEffectCmd_end + 1, FieldEffectCmd_loadgfx_callnative + 1, FieldEffectCmd_loadtiles_callnative + 1, FieldEffectCmd_loadfadedpal_callnative + 1

	.globl gUnknown_8536EBC
gUnknown_8536EBC: @ 0x8536EBC
	.incbin "baserom_jp.gba", 0x536ebc, 0x20

	.globl gUnknown_8536EDC
gUnknown_8536EDC: @ 0x8536EDC
	.incbin "baserom_jp.gba", 0x536edc, 0x14

	.globl gUnknown_8536EF0
gUnknown_8536EF0: @ 0x8536EF0
	.incbin "baserom_jp.gba", 0x536ef0, 0x18

	.globl gSpritePalette_PokeballGlow
gSpritePalette_PokeballGlow: @ 0x8536F08
	.incbin "baserom_jp.gba", 0x536f08, 0x8

	.globl gSpritePalette_HofMonitor
gSpritePalette_HofMonitor: @ 0x8536F10
	.incbin "baserom_jp.gba", 0x536f10, 0x8

	.incbin "baserom_jp.gba", 0x536f18, 0x40

	.globl gUnknown_8536F58
gUnknown_8536F58: @ 0x8536F58
	.incbin "baserom_jp.gba", 0x536f58, 0x18

	.globl gUnknown_8536F70
gUnknown_8536F70: @ 0x8536F70
	.incbin "baserom_jp.gba", 0x536f70, 0x40

	.globl gUnknown_8536FB0
gUnknown_8536FB0: @ 0x8536FB0
	.incbin "baserom_jp.gba", 0x536fb0, 0x18

	.globl gUnknown_8536FC8
gUnknown_8536FC8: @ 0x8536FC8
	.incbin "baserom_jp.gba", 0x536fc8, 0x18

	.globl gUnknown_8536FE0
gUnknown_8536FE0: @ 0x8536FE0
	.incbin "baserom_jp.gba", 0x536fe0, 0x18

	.globl gUnknown_8536FF8
gUnknown_8536FF8: @ 0x8536FF8
	.incbin "baserom_jp.gba", 0x536ff8, 0x18

	.globl sPokecenterHealEffectFuncs
sPokecenterHealEffectFuncs: @ 0x8537010
	.4byte PokecenterHealEffect_Init + 1, PokecenterHealEffect_WaitForBallPlacement + 1, PokecenterHealEffect_2 + 1, PokecenterHealEffect_WaitForSoundAndEnd + 1

	.globl sHallOfFameRecordEffectFuncs
sHallOfFameRecordEffectFuncs: @ 0x8537020
	.4byte HallOfFameRecordEffect_Init + 1, HallOfFameRecordEffect_WaitForBallPlacement + 1, HallOfFameRecordEffect_2 + 1, HallOfFameRecordEffect_WaitForSoundAndEnd + 1

	.globl sPokeballGlowEffectFuncs
sPokeballGlowEffectFuncs: @ 0x8537030
	.4byte PokeballGlowEffect_PlaceBalls + 1, PokeballGlowEffect_TryPlaySe + 1, PokeballGlowEffect_Flash1 + 1, PokeballGlowEffect_Flash2 + 1, PokeballGlowEffect_4 + 1, PokeballGlowEffect_Dummy + 1, PokeballGlowEffect_6 + 1, PokeballGlowEffect_7 + 1

	.globl gUnknown_8537050
gUnknown_8537050: @ 0x8537050
	.incbin "baserom_jp.gba", 0x537050, 0x18

	.globl gUnknown_8537068
gUnknown_8537068: @ 0x8537068
	.incbin "baserom_jp.gba", 0x537068, 0x4

	.globl gUnknown_853706C
gUnknown_853706C: @ 0x853706C
	.incbin "baserom_jp.gba", 0x53706c, 0x4

	.globl gUnknown_8537070
gUnknown_8537070: @ 0x8537070
	.incbin "baserom_jp.gba", 0x537070, 0x4

	.globl sFallWarpFieldEffectFuncs
sFallWarpFieldEffectFuncs: @ 0x8537074
	.4byte FallWarpEffect_Init + 1, FallWarpEffect_WaitWeather + 1, FallWarpEffect_StartFall + 1, FallWarpEffect_Fall + 1, FallWarpEffect_Land + 1, FallWarpEffect_CameraShake + 1, FallWarpEffect_End + 1

	.globl sEscalatorWarpOutFieldEffectFuncs
sEscalatorWarpOutFieldEffectFuncs: @ 0x8537090
	.4byte EscalatorWarpOut_Init + 1, EscalatorWarpOut_WaitForPlayer + 1, EscalatorWarpOut_Up_Ride + 1, EscalatorWarpOut_Up_End + 1, EscalatorWarpOut_Down_Ride + 1, EscalatorWarpOut_Down_End + 1

	.globl sEscalatorWarpInFieldEffectFuncs
sEscalatorWarpInFieldEffectFuncs: @ 0x85370A8
	.4byte EscalatorWarpIn_Init + 1, EscalatorWarpIn_Down_Init + 1, EscalatorWarpIn_Down_Ride + 1, EscalatorWarpIn_Up_Init + 1, EscalatorWarpIn_Up_Ride + 1, EscalatorWarpIn_WaitForMovement + 1, EscalatorWarpIn_End + 1

	.globl gUnknown_85370C4
gUnknown_85370C4: @ 0x85370C4
	.incbin "baserom_jp.gba", 0x5370c4, 0x14

	.globl sDiveFieldEffectFuncs
sDiveFieldEffectFuncs: @ 0x85370D8
	.4byte DiveFieldEffect_Init + 1, DiveFieldEffect_ShowMon + 1, DiveFieldEffect_TryWarp + 1

	.globl sLavaridgeGymB1FWarpEffectFuncs
sLavaridgeGymB1FWarpEffectFuncs: @ 0x85370E4
	.4byte LavaridgeGymB1FWarpEffect_Init + 1, LavaridgeGymB1FWarpEffect_CameraShake + 1, LavaridgeGymB1FWarpEffect_Launch + 1, LavaridgeGymB1FWarpEffect_Rise + 1, LavaridgeGymB1FWarpEffect_FadeOut + 1, LavaridgeGymB1FWarpEffect_Warp + 1

	.globl sLavaridgeGymB1FWarpExitEffectFuncs
sLavaridgeGymB1FWarpExitEffectFuncs: @ 0x85370FC
	.4byte LavaridgeGymB1FWarpExitEffect_Init + 1, LavaridgeGymB1FWarpExitEffect_StartPopOut + 1, LavaridgeGymB1FWarpExitEffect_PopOut + 1, LavaridgeGymB1FWarpExitEffect_End + 1

	.globl sLavaridgeGym1FWarpEffectFuncs
sLavaridgeGym1FWarpEffectFuncs: @ 0x853710C
	.4byte LavaridgeGym1FWarpEffect_Init + 1, LavaridgeGym1FWarpEffect_AshPuff + 1, LavaridgeGym1FWarpEffect_Disappear + 1, LavaridgeGym1FWarpEffect_FadeOut + 1, LavaridgeGym1FWarpEffect_Warp + 1

	.globl sEscapeRopeWarpOutEffectFuncs
sEscapeRopeWarpOutEffectFuncs: @ 0x8537120
	.4byte EscapeRopeWarpOutEffect_Init + 1, EscapeRopeWarpOutEffect_Spin + 1

	.globl gUnknown_8537128
gUnknown_8537128: @ 0x8537128
	.incbin "baserom_jp.gba", 0x537128, 0x8

	.globl sEscapeRopeWarpInEffectFuncs
sEscapeRopeWarpInEffectFuncs: @ 0x8537130
	.4byte EscapeRopeWarpInEffect_Init + 1, EscapeRopeWarpInEffect_Spin + 1

	.globl sTeleportWarpOutFieldEffectFuncs
sTeleportWarpOutFieldEffectFuncs: @ 0x8537138
	.4byte TeleportWarpOutFieldEffect_Init + 1, TeleportWarpOutFieldEffect_SpinGround + 1, TeleportWarpOutFieldEffect_SpinExit + 1, TeleportWarpOutFieldEffect_End + 1

	.globl sTeleportWarpInFieldEffectFuncs
sTeleportWarpInFieldEffectFuncs: @ 0x8537148
	.4byte TeleportWarpInFieldEffect_Init + 1, TeleportWarpInFieldEffect_SpinEnter + 1, TeleportWarpInFieldEffect_SpinGround + 1

	.globl sFieldMoveShowMonOutdoorsEffectFuncs
sFieldMoveShowMonOutdoorsEffectFuncs: @ 0x8537154
	.4byte FieldMoveShowMonOutdoorsEffect_Init + 1, FieldMoveShowMonOutdoorsEffect_LoadGfx + 1, FieldMoveShowMonOutdoorsEffect_CreateBanner + 1, FieldMoveShowMonOutdoorsEffect_WaitForMon + 1, FieldMoveShowMonOutdoorsEffect_ShrinkBanner + 1, FieldMoveShowMonOutdoorsEffect_RestoreBg + 1, FieldMoveShowMonOutdoorsEffect_End + 1

	.globl sFieldMoveShowMonIndoorsEffectFuncs
sFieldMoveShowMonIndoorsEffectFuncs: @ 0x8537170
	.4byte FieldMoveShowMonIndoorsEffect_Init + 1, FieldMoveShowMonIndoorsEffect_LoadGfx + 1, FieldMoveShowMonIndoorsEffect_SlideBannerOn + 1, FieldMoveShowMonIndoorsEffect_WaitForMon + 1, FieldMoveShowMonIndoorsEffect_RestoreBg + 1, FieldMoveShowMonIndoorsEffect_SlideBannerOff + 1, FieldMoveShowMonIndoorsEffect_End + 1

	.globl sSurfFieldEffectFuncs
sSurfFieldEffectFuncs: @ 0x853718C
	.4byte SurfFieldEffect_Init + 1, SurfFieldEffect_FieldMovePose + 1, SurfFieldEffect_ShowMon + 1, SurfFieldEffect_JumpOnSurfBlob + 1, SurfFieldEffect_End + 1

	.globl gUnknown_85371A0
gUnknown_85371A0: @ 0x85371A0
	.incbin "baserom_jp.gba", 0x5371a0, 0x54

	.globl gUnknown_85371F4
gUnknown_85371F4: @ 0x85371F4
	.incbin "baserom_jp.gba", 0x5371f4, 0x8

	.globl sFlyInFieldEffectFuncs
sFlyInFieldEffectFuncs: @ 0x85371FC
	.4byte FlyInFieldEffect_BirdSwoopDown + 1, FlyInFieldEffect_FlyInWithBird + 1, FlyInFieldEffect_JumpOffBird + 1, FlyInFieldEffect_FieldMovePose + 1, FlyInFieldEffect_BirdReturnToBall + 1, FlyInFieldEffect_WaitBirdReturn + 1, FlyInFieldEffect_End + 1

	.globl gUnknown_8537218
gUnknown_8537218: @ 0x8537218
	.incbin "baserom_jp.gba", 0x537218, 0x24

	.globl gUnknown_853723C
gUnknown_853723C: @ 0x853723C
	.incbin "baserom_jp.gba", 0x53723c, 0x5c

	.globl gUnknown_8537298
gUnknown_8537298: @ 0x8537298
	.incbin "baserom_jp.gba", 0x537298, 0x18

	.globl gUnknown_85372B0
gUnknown_85372B0: @ 0x85372B0
	.incbin "baserom_jp.gba", 0x5372b0, 0x60
