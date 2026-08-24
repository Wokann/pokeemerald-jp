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
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_84E8CC8
gUnknown_84E8CC8: @ 0x84E8CC8
	.incbin "baserom_jp.gba", 0x4e8cc8, 0x1a8

	.globl gUnknown_84E8E70
gUnknown_84E8E70: @ 0x84E8E70
	.incbin "baserom_jp.gba", 0x4e8e70, 0xb60

	.globl gUnknown_84E99D0
gUnknown_84E99D0: @ 0x84E99D0
	.incbin "baserom_jp.gba", 0x4e99d0, 0x908

	.globl gUnknown_84EA2D8
gUnknown_84EA2D8: @ 0x84EA2D8
	.incbin "baserom_jp.gba", 0x4ea2d8, 0x9a8

	.globl gUnknown_84EAC80
gUnknown_84EAC80: @ 0x84EAC80
	.incbin "baserom_jp.gba", 0x4eac80, 0x8e0

	.globl gUnknown_84EB560
gUnknown_84EB560: @ 0x84EB560
	.incbin "baserom_jp.gba", 0x4eb560, 0x320

	.globl gUnknown_84EB880
gUnknown_84EB880: @ 0x84EB880
	.incbin "baserom_jp.gba", 0x4eb880, 0x510

	.globl gUnknown_84EBD90
gUnknown_84EBD90: @ 0x84EBD90
	.incbin "baserom_jp.gba", 0x4ebd90, 0x210

	.globl gUnknown_84EBFA0
gUnknown_84EBFA0: @ 0x84EBFA0
	.incbin "baserom_jp.gba", 0x4ebfa0, 0xb50

	.globl gUnknown_84ECAF0
gUnknown_84ECAF0: @ 0x84ECAF0
	.incbin "baserom_jp.gba", 0x4ecaf0, 0x210

	.globl gUnknown_84ECD00
gUnknown_84ECD00: @ 0x84ECD00
	.incbin "baserom_jp.gba", 0x4ecd00, 0x810

	.globl gUnknown_84ED510
gUnknown_84ED510: @ 0x84ED510
	.incbin "baserom_jp.gba", 0x4ed510, 0x540

	.globl gUnknown_84EDA50
gUnknown_84EDA50: @ 0x84EDA50
	.incbin "baserom_jp.gba", 0x4eda50, 0x20

	.globl gUnknown_84EDA70
gUnknown_84EDA70: @ 0x84EDA70
	.incbin "baserom_jp.gba", 0x4eda70, 0x20

	.globl gUnknown_84EDA90
gUnknown_84EDA90: @ 0x84EDA90
	.incbin "baserom_jp.gba", 0x4eda90, 0x30

	.globl gUnknown_84EDAC0
gUnknown_84EDAC0: @ 0x84EDAC0
	.incbin "baserom_jp.gba", 0x4edac0, 0x30

	.globl gUnknown_84EDAF0
gUnknown_84EDAF0: @ 0x84EDAF0
	.incbin "baserom_jp.gba", 0x4edaf0, 0x10

	.globl gUnknown_84EDB00
gUnknown_84EDB00: @ 0x84EDB00
	.incbin "baserom_jp.gba", 0x4edb00, 0x410

	.globl gUnknown_84EDF10
gUnknown_84EDF10: @ 0x84EDF10
	.incbin "baserom_jp.gba", 0x4edf10, 0x20

	.globl gUnknown_84EDF30
gUnknown_84EDF30: @ 0x84EDF30
	.incbin "baserom_jp.gba", 0x4edf30, 0x140

	.globl gUnknown_84EE070
gUnknown_84EE070: @ 0x84EE070
	.incbin "baserom_jp.gba", 0x4ee070, 0x428

	.globl gUnknown_84EE498
gUnknown_84EE498: @ 0x84EE498
	.incbin "baserom_jp.gba", 0x4ee498, 0x430

	.globl gUnknown_84EE8C8
gUnknown_84EE8C8: @ 0x84EE8C8
	.incbin "baserom_jp.gba", 0x4ee8c8, 0x20

	.globl gUnknown_84EE8E8
gUnknown_84EE8E8: @ 0x84EE8E8
	.incbin "baserom_jp.gba", 0x4ee8e8, 0x320

	.globl gUnknown_84EEC08
gUnknown_84EEC08: @ 0x84EEC08
	.incbin "baserom_jp.gba", 0x4eec08, 0x310

	.globl gUnknown_84EEF18
gUnknown_84EEF18: @ 0x84EEF18
	.incbin "baserom_jp.gba", 0x4eef18, 0x310

	.globl gUnknown_84EF228
gUnknown_84EF228: @ 0x84EF228
	.incbin "baserom_jp.gba", 0x4ef228, 0x210

	.globl gUnknown_84EF438
gUnknown_84EF438: @ 0x84EF438
	.incbin "baserom_jp.gba", 0x4ef438, 0x110

	.globl gUnknown_84EF548
gUnknown_84EF548: @ 0x84EF548
	.incbin "baserom_jp.gba", 0x4ef548, 0xc08

	.globl gUnknown_84F0150
gUnknown_84F0150: @ 0x84F0150
	.incbin "baserom_jp.gba", 0x4f0150, 0xc

	.globl gUnknown_84F015C
gUnknown_84F015C: @ 0x84F015C
	.incbin "baserom_jp.gba", 0x4f015c, 0x1ac

	.globl gUnknown_84F0308
gUnknown_84F0308: @ 0x84F0308
	.incbin "baserom_jp.gba", 0x4f0308, 0x10

	.globl gUnknown_84F0318
gUnknown_84F0318: @ 0x84F0318
	.incbin "baserom_jp.gba", 0x4f0318, 0x428

	.globl gUnknown_84F0740
gUnknown_84F0740: @ 0x84F0740
	.incbin "baserom_jp.gba", 0x4f0740, 0x268

	.globl gUnknown_84F09A8
gUnknown_84F09A8: @ 0x84F09A8
	.incbin "baserom_jp.gba", 0x4f09a8, 0x8028

	.globl gUnknown_84F89D0
gUnknown_84F89D0: @ 0x84F89D0
	.incbin "baserom_jp.gba", 0x4f89d0, 0x45a0

	.globl gUnknown_84FCF70
gUnknown_84FCF70: @ 0x84FCF70
	.incbin "baserom_jp.gba", 0x4fcf70, 0xc

	.globl gUnknown_84FCF7C
gUnknown_84FCF7C: @ 0x84FCF7C
	.incbin "baserom_jp.gba", 0x4fcf7c, 0xc

	.globl gUnknown_84FCF88
gUnknown_84FCF88: @ 0x84FCF88
	.incbin "baserom_jp.gba", 0x4fcf88, 0x10

	.globl gUnknown_84FCF98
gUnknown_84FCF98: @ 0x84FCF98
	.incbin "baserom_jp.gba", 0x4fcf98, 0x10

	.globl gUnknown_84FCFA8
gUnknown_84FCFA8: @ 0x84FCFA8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x05, 0x05, 0x05, 0x05, 0x0B, 0x0B
	.byte 0x0B, 0x0B, 0x0B, 0x10, 0x10, 0x10, 0x10, 0x10, 0x15, 0x15, 0x15, 0x15
	.byte 0x15, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1F, 0x1F

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

	.globl PETALBURG_CITY_EventObjects
PETALBURG_CITY_EventObjects: @ 0x084FE6DC
	object_event 1, 26, 0, 16, 18, 3, 2, 1, 1, 0, 0, PetalburgCity_EventScript_001DB919, 0x02D8
	object_event 2, 135, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x00000000, 0x02D6
	object_event 3, 7, 0, 8, 22, 3, 8, 0, 0, 0, 0, PetalburgCity_EventScript_001DB902, 0x0000
	object_event 4, 48, 0, 20, 10, 3, 3, 0, 1, 0, 0, PetalburgCity_EventScript_001DB9A4, 0x0000
	object_event 5, 25, 0, 15, 10, 3, 7, 0, 0, 0, 0, 0x00000000, 0x033E
	object_event 6, 59, 0, 19, 2, 3, 1, 0, 0, 0, 0, 0x08256E0B, 0x040F
	object_event 7, 59, 0, 3, 28, 3, 1, 0, 0, 0, 0, 0x08256E18, 0x0410
	object_event 8, 9, 0, 12, 15, 3, 1, 0, 0, 0, 0, PetalburgCity_EventScript_001DBD4A, 0x0000
	object_event 9, 219, 0, 13, 12, 3, 1, 1, 1, 0, 0, 0x00000000, 0x03E3
	.globl PETALBURG_CITY_EventWarps
PETALBURG_CITY_EventWarps: @ 0x084FE7B4
	warp_def 10, 19, 0, 0, MAP_PETALBURG_CITY_HOUSE1
	warp_def 7, 5, 0, 0, MAP_PETALBURG_CITY_WALLYS_HOUSE
	warp_def 15, 8, 0, 0, MAP_PETALBURG_CITY_GYM
	warp_def 20, 16, 0, 0, MAP_PETALBURG_CITY_POKEMON_CENTER_1F
	warp_def 20, 24, 0, 0, MAP_PETALBURG_CITY_HOUSE2
	warp_def 25, 12, 0, 0, MAP_PETALBURG_CITY_MART
	.globl PETALBURG_CITY_EventCoordEvents
PETALBURG_CITY_EventCoordEvents: @ 0x084FE7E4
	coord_event 8, 10, 3, 16471, 0, PetalburgCity_EventScript_001DB9B6
	coord_event 8, 11, 3, 16471, 0, PetalburgCity_EventScript_001DB9C2
	coord_event 8, 12, 3, 16471, 0, PetalburgCity_EventScript_001DB9CE
	coord_event 8, 13, 3, 16471, 0, PetalburgCity_EventScript_001DB9DA
	coord_event 4, 10, 3, 16585, 0, PetalburgCity_EventScript_001DBBAD
	coord_event 4, 11, 3, 16585, 0, PetalburgCity_EventScript_001DBBC3
	coord_event 4, 12, 3, 16585, 0, PetalburgCity_EventScript_001DBBD9
	coord_event 4, 13, 3, 16585, 0, PetalburgCity_EventScript_001DBBEF
	.globl PETALBURG_CITY_EventBgEvents
PETALBURG_CITY_EventBgEvents: @ 0x084FE864
	bg_event 17, 10, 0, 0, PetalburgCity_EventScript_001DB992, 0, 0
	bg_event 26, 12, 0, 1, 0x08242EF6, 0, 0
	bg_event 21, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 17, 16, 0, 0, PetalburgCity_EventScript_001DB99B, 0, 0
	bg_event 22, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 27, 12, 0, 1, 0x08242EF6, 0, 0
	bg_event 8, 9, 0, 0, PetalburgCity_EventScript_001DB9AD, 0, 0
	bg_event 11, 29, 3, 7, 0x0044, 0x5F, 0x00
	.globl gMapEvents_PETALBURG_CITY
gMapEvents_PETALBURG_CITY: @ 0x084FE8C4
	map_events PETALBURG_CITY_EventObjects, PETALBURG_CITY_EventWarps, PETALBURG_CITY_EventCoordEvents, PETALBURG_CITY_EventBgEvents
	.globl SLATEPORT_CITY_EventObjects
SLATEPORT_CITY_EventObjects: @ 0x084FE8D8
	object_event 1, 17, 0, 21, 11, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC24D, 0x0000
	object_event 2, 19, 0, 34, 29, 3, 5, 1, 0, 0, 0, SlateportCity_EventScript_001DC26A, 0x0000
	object_event 3, 15, 0, 5, 13, 3, 2, 1, 2, 0, 0, SlateportCity_EventScript_001DC22C, 0x0000
	object_event 4, 26, 0, 26, 29, 3, 1, 0, 0, 0, 0, SlateportCity_EventScript_001DC28B, 0x0000
	object_event 5, 118, 0, 31, 27, 3, 7, 0, 0, 0, 0, SlateportCity_EventScript_001DC37D, 0x0372
	object_event 6, 27, 0, 5, 43, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC1B6, 0x0000
	object_event 7, 30, 0, 20, 37, 3, 1, 1, 1, 0, 0, SlateportCity_EventScript_001DC1D7, 0x0000
	object_event 8, 8, 0, 8, 42, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC1F8, 0x0000
	object_event 9, 110, 0, 29, 13, 3, 9, 0, 0, 0, 0, SlateportCity_EventScript_001DC6C7, 0x0343
	object_event 10, 68, 0, 28, 14, 3, 7, 0, 0, 0, 0, SlateportCity_EventScript_001DC6D0, 0x0343
	object_event 11, 46, 0, 28, 13, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC56C, 0x0348
	object_event 12, 49, 0, 37, 41, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC359, 0x0000
	object_event 13, 49, 0, 28, 46, 3, 5, 1, 0, 0, 0, SlateportCity_EventScript_001DC362, 0x0000
	object_event 14, 18, 0, 9, 50, 3, 3, 0, 1, 0, 0, SlateportCity_EventScript_001DC36B, 0x0000
	object_event 15, 33, 0, 16, 46, 3, 2, 1, 1, 0, 0, SlateportCity_EventScript_001DC374, 0x0000
	object_event 16, 39, 0, 8, 24, 3, 3, 0, 1, 0, 0, SlateportCity_EventScript_001DC32F, 0x0000
	object_event 17, 34, 0, 15, 31, 3, 1, 0, 0, 0, 0, SlateportCity_EventScript_001DC350, 0x0000
	object_event 18, 117, 0, 30, 27, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC394, 0x0372
	object_event 19, 117, 0, 29, 27, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC3AB, 0x0372
	object_event 20, 83, 0, 6, 38, 3, 10, 0, 0, 0, 0, SlateportCity_EventScript_001DC50C, 0x0000
	object_event 21, 83, 0, 5, 51, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC4DE, 0x0000
	object_event 22, 66, 0, 34, 51, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC6D9, 0x0000
	object_event 23, 34, 0, 4, 47, 3, 8, 0, 0, 0, 0, SlateportCity_EventScript_001DC158, 0x0000
	object_event 24, 83, 0, 11, 47, 3, 8, 1, 1, 0, 0, SlateportCity_EventScript_001DC54C, 0x03B4
	object_event 25, 25, 0, 5, 47, 3, 8, 1, 1, 0, 0, SlateportCity_EventScript_001DC12F, 0x0000
	object_event 26, 117, 0, 22, 27, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC3C2, 0x0372
	object_event 27, 117, 0, 23, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC3D9, 0x0372
	object_event 28, 117, 0, 24, 27, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC3F0, 0x0372
	object_event 29, 117, 0, 21, 26, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC407, 0x0372
	object_event 30, 117, 0, 20, 26, 3, 10, 1, 1, 0, 0, SlateportCity_EventScript_001DC41E, 0x0372
	object_event 31, 117, 0, 26, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC435, 0x0372
	object_event 32, 117, 0, 28, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC4BE, 0x0372
	object_event 33, 117, 0, 25, 27, 3, 7, 1, 1, 0, 0, SlateportCity_EventScript_001DC4C7, 0x0372
	object_event 34, 18, 0, 11, 37, 3, 9, 1, 2, 0, 0, SlateportCity_EventScript_001DC6E2, 0x0000
	object_event 35, 219, 0, 10, 12, 0, 8, 1, 2, 0, 0, 0x00000000, 0x02ED
	.globl SLATEPORT_CITY_EventWarps
SLATEPORT_CITY_EventWarps: @ 0x084FEC20
	warp_def 19, 19, 0, 0, MAP_SLATEPORT_CITY_POKEMON_CENTER_1F
	warp_def 13, 26, 0, 0, MAP_SLATEPORT_CITY_MART
	warp_def 26, 38, 0, 0, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F
	warp_def 10, 12, 0, 0, MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY
	warp_def 4, 26, 0, 0, MAP_SLATEPORT_CITY_POKEMON_FAN_CLUB
	warp_def 30, 26, 0, 0, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	warp_def 5, 19, 0, 0, MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE
	warp_def 31, 26, 0, 1, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	warp_def 28, 12, 0, 0, MAP_SLATEPORT_CITY_HARBOR
	warp_def 40, 7, 0, 2, MAP_SLATEPORT_CITY_HARBOR
	warp_def 21, 44, 0, 0, MAP_SLATEPORT_CITY_HOUSE
	.globl SLATEPORT_CITY_EventCoordEvents
SLATEPORT_CITY_EventCoordEvents: @ 0x084FEC78
	coord_event 10, 13, 3, 16594, 2, SlateportCity_EventScript_001DC950
	.globl SLATEPORT_CITY_EventBgEvents
SLATEPORT_CITY_EventBgEvents: @ 0x084FEC88
	bg_event 8, 19, 0, 0, SlateportCity_EventScript_001DC326, 0, 0
	bg_event 20, 19, 0, 1, 0x08242EFF, 0, 0
	bg_event 21, 19, 0, 1, 0x08242EFF, 0, 0
	bg_event 14, 26, 0, 1, 0x08242EF6, 0, 0
	bg_event 24, 12, 0, 0, SlateportCity_EventScript_001DC308, 0, 0
	bg_event 15, 26, 0, 1, 0x08242EF6, 0, 0
	bg_event 14, 51, 0, 0, SlateportCity_EventScript_001DC2FF, 0, 0
	bg_event 26, 26, 0, 0, SlateportCity_EventScript_001DC2ED, 0, 0
	bg_event 16, 22, 0, 0, SlateportCity_EventScript_001DC2F6, 0, 0
	bg_event 8, 26, 0, 0, SlateportCity_EventScript_001DC2E4, 0, 0
	bg_event 7, 13, 0, 0, SlateportCity_EventScript_001DC2AA, 0, 0
	bg_event 23, 38, 0, 0, SlateportCity_EventScript_001DC2B3, 0, 0
	bg_event 10, 36, 0, 1, SlateportCity_EventScript_001DC9B7, 0, 0
	.globl gMapEvents_SLATEPORT_CITY
gMapEvents_SLATEPORT_CITY: @ 0x084FED24
	map_events SLATEPORT_CITY_EventObjects, SLATEPORT_CITY_EventWarps, SLATEPORT_CITY_EventCoordEvents, SLATEPORT_CITY_EventBgEvents
	.globl MAUVILLE_CITY_EventObjects
MAUVILLE_CITY_EventObjects: @ 0x084FED38
	object_event 1, 13, 0, 29, 16, 3, 5, 1, 1, 0, 0, MauvilleCity_EventScript_001DD9EC, 0x0000
	object_event 2, 15, 0, 24, 10, 3, 5, 1, 0, 0, 0, MauvilleCity_EventScript_001DDA07, 0x0000
	object_event 3, 39, 0, 14, 11, 3, 10, 0, 0, 0, 0, MauvilleCity_EventScript_001DD9F5, 0x0000
	object_event 4, 26, 0, 18, 6, 3, 1, 0, 0, 0, 0, MauvilleCity_EventScript_001DD9FE, 0x0000
	object_event 5, 38, 0, 17, 14, 3, 8, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA34, 0x0000
	object_event 6, 135, 0, 8, 6, 3, 7, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA8B, 0x0324
	object_event 7, 25, 0, 9, 6, 3, 9, 0, 0, 0, 0, MauvilleCity_EventScript_001DDA56, 0x0325
	object_event 8, 127, 0, 29, 9, 3, 1, 0, 0, 0, 0, MauvilleCity_EventScript_001DDD73, 0x0390
	object_event 9, 59, 0, 28, 19, 3, 1, 1, 1, 0, 0, 0x08256E25, 0x045C
	object_event 10, 17, 0, 13, 7, 3, 9, 0, 0, 0, 0, 0x0827689A, 0x0000
	object_event 11, 219, 0, 12, 14, 3, 7, 0, 0, 0, 0, 0x00000000, 0x02FD
	.globl MAUVILLE_CITY_EventWarps
MAUVILLE_CITY_EventWarps: @ 0x084FEE40
	warp_def 8, 5, 0, 0, MAP_MAUVILLE_CITY_GYM
	warp_def 22, 5, 0, 0, MAP_MAUVILLE_CITY_POKEMON_CENTER_1F
	warp_def 35, 5, 0, 0, MAP_MAUVILLE_CITY_BIKE_SHOP
	warp_def 23, 14, 0, 0, MAP_MAUVILLE_CITY_MART
	warp_def 32, 14, 0, 0, MAP_MAUVILLE_CITY_HOUSE1
	warp_def 8, 13, 0, 0, MAP_MAUVILLE_CITY_GAME_CORNER
	warp_def 19, 14, 0, 0, MAP_MAUVILLE_CITY_HOUSE2
	.globl MAUVILLE_CITY_EventBgEvents
MAUVILLE_CITY_EventBgEvents: @ 0x084FEE78
	bg_event 23, 5, 0, 1, 0x08242EFF, 0, 0
	bg_event 11, 6, 3, 0, MauvilleCity_EventScript_001DDA19, 0, 0
	bg_event 24, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 25, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 24, 5, 0, 1, 0x08242EFF, 0, 0
	bg_event 19, 7, 0, 0, MauvilleCity_EventScript_001DDA10, 0, 0
	bg_event 33, 6, 0, 0, MauvilleCity_EventScript_001DDA22, 0, 0
	bg_event 11, 15, 0, 0, MauvilleCity_EventScript_001DDA2B, 0, 0
	.globl gMapEvents_MAUVILLE_CITY
gMapEvents_MAUVILLE_CITY: @ 0x084FEED8
	map_events MAUVILLE_CITY_EventObjects, MAUVILLE_CITY_EventWarps, 0, MAUVILLE_CITY_EventBgEvents
	.globl RUSTBORO_CITY_EventObjects
RUSTBORO_CITY_EventObjects: @ 0x084FEEEC
	object_event 1, 34, 0, 22, 34, 3, 3, 0, 1, 0, 0, RustboroCity_EventScript_001DE8C3, 0x0000
	object_event 2, 17, 0, 19, 13, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DE898, 0x0000
	object_event 3, 5, 0, 25, 37, 3, 7, 0, 0, 0, 0, RustboroCity_EventScript_001DE913, 0x0000
	object_event 4, 6, 0, 21, 46, 3, 3, 0, 1, 0, 0, RustboroCity_EventScript_001DE90A, 0x0000
	object_event 5, 9, 0, 12, 45, 3, 1, 0, 0, 0, 0, RustboroCity_EventScript_001DE8EB, 0x0000
	object_event 6, 33, 0, 26, 23, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DE8CC, 0x0000
	object_event 7, 11, 0, 24, 51, 3, 10, 0, 0, 0, 0, RustboroCity_EventScript_001DE95B, 0x0000
	object_event 8, 12, 0, 25, 51, 3, 9, 0, 0, 0, 0, RustboroCity_EventScript_001DE971, 0x0000
	object_event 9, 23, 0, 30, 10, 3, 10, 1, 1, 0, 0, RustboroCity_EventScript_001DEB16, 0x02DC
	object_event 10, 117, 0, 13, 21, 3, 10, 0, 0, 0, 0, 0x00000000, 0x02DB
	object_event 11, 116, 0, 13, 34, 3, 2, 1, 1, 0, 0, RustboroCity_EventScript_001DE8B7, 0x0000
	object_event 12, 59, 0, 36, 51, 3, 1, 0, 0, 0, 0, 0x08256E32, 0x0411
	object_event 13, 65, 0, 19, 27, 3, 8, 0, 1, 0, 0, RustboroCity_EventScript_001DE987, 0x0000
	object_event 14, 240, 0, 16, 50, 3, 1, 1, 1, 0, 0, RustboroCity_EventScript_001DEDF1, 0x032E
	object_event 15, 46, 0, 11, 15, 0, 1, 1, 1, 0, 0, 0x00000000, 0x034C
	object_event 16, 7, 0, 31, 36, 3, 1, 0, 1, 0, 0, RustboroCity_EventScript_001DF26F, 0x0000
	.globl RUSTBORO_CITY_EventWarps
RUSTBORO_CITY_EventWarps: @ 0x084FF06C
	warp_def 27, 19, 0, 0, MAP_RUSTBORO_CITY_GYM
	warp_def 13, 30, 0, 0, MAP_RUSTBORO_CITY_FLAT1_1F
	warp_def 16, 45, 0, 0, MAP_RUSTBORO_CITY_MART
	warp_def 16, 38, 0, 0, MAP_RUSTBORO_CITY_POKEMON_CENTER_1F
	warp_def 27, 34, 0, 0, MAP_RUSTBORO_CITY_POKEMON_SCHOOL
	warp_def 11, 15, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 12, 15, 0, 1, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 33, 19, 0, 0, MAP_RUSTBORO_CITY_HOUSE1
	warp_def 9, 38, 0, 0, MAP_RUSTBORO_CITY_CUTTERS_HOUSE
	warp_def 30, 28, 0, 0, MAP_RUSTBORO_CITY_HOUSE2
	warp_def 5, 51, 0, 0, MAP_RUSTBORO_CITY_FLAT2_1F
	warp_def 26, 46, 0, 0, MAP_RUSTBORO_CITY_HOUSE3
	.globl RUSTBORO_CITY_EventCoordEvents
RUSTBORO_CITY_EventCoordEvents: @ 0x084FF0CC
	coord_event 23, 20, 3, 16474, 1, RustboroCity_EventScript_001DE993
	coord_event 23, 21, 3, 16474, 1, RustboroCity_EventScript_001DE9AA
	coord_event 23, 22, 3, 16474, 1, RustboroCity_EventScript_001DE9C1
	coord_event 23, 23, 3, 16474, 1, RustboroCity_EventScript_001DE9D8
	coord_event 23, 24, 3, 16474, 1, RustboroCity_EventScript_001DE9EF
	coord_event 30, 9, 3, 16474, 2, RustboroCity_EventScript_001DEB37
	coord_event 29, 10, 3, 16474, 2, RustboroCity_EventScript_001DEB43
	coord_event 30, 11, 3, 16474, 2, RustboroCity_EventScript_001DEB4F
	coord_event 30, 12, 3, 16474, 2, RustboroCity_EventScript_001DEB5B
	coord_event 30, 9, 3, 16474, 4, RustboroCity_EventScript_001DEC64
	coord_event 31, 10, 3, 16474, 4, RustboroCity_EventScript_001DEC70
	coord_event 30, 11, 3, 16474, 4, RustboroCity_EventScript_001DEC7C
	coord_event 30, 12, 3, 16474, 4, RustboroCity_EventScript_001DEC88
	coord_event 12, 53, 3, 16474, 7, RustboroCity_EventScript_001DEE2C
	coord_event 13, 53, 3, 16474, 7, RustboroCity_EventScript_001DEE6C
	coord_event 14, 53, 3, 16474, 7, RustboroCity_EventScript_001DEEAC
	coord_event 15, 53, 3, 16474, 7, RustboroCity_EventScript_001DEEEC
	coord_event 16, 53, 3, 16474, 7, RustboroCity_EventScript_001DEF2C
	coord_event 17, 53, 3, 16474, 7, RustboroCity_EventScript_001DEF6C
	coord_event 18, 53, 3, 16474, 7, RustboroCity_EventScript_001DEFAC
	coord_event 19, 53, 3, 16474, 7, RustboroCity_EventScript_001DEFEC
	.globl RUSTBORO_CITY_EventBgEvents
RUSTBORO_CITY_EventBgEvents: @ 0x084FF21C
	bg_event 23, 19, 0, 0, RustboroCity_EventScript_001DE92E, 0, 0
	bg_event 25, 35, 0, 0, RustboroCity_EventScript_001DE949, 0, 0
	bg_event 17, 45, 0, 1, 0x08242EF6, 0, 0
	bg_event 18, 38, 0, 1, 0x08242EFF, 0, 0
	bg_event 19, 49, 0, 0, RustboroCity_EventScript_001DE940, 0, 0
	bg_event 18, 45, 0, 1, 0x08242EF6, 0, 0
	bg_event 17, 38, 0, 1, 0x08242EFF, 0, 0
	bg_event 17, 20, 0, 0, RustboroCity_EventScript_001DE925, 0, 0
	bg_event 30, 8, 0, 0, RustboroCity_EventScript_001DE91C, 0, 0
	bg_event 12, 38, 3, 0, RustboroCity_EventScript_001DE952, 0, 0
	.globl gMapEvents_RUSTBORO_CITY
gMapEvents_RUSTBORO_CITY: @ 0x084FF294
	map_events RUSTBORO_CITY_EventObjects, RUSTBORO_CITY_EventWarps, RUSTBORO_CITY_EventCoordEvents, RUSTBORO_CITY_EventBgEvents
	.globl FORTREE_CITY_EventObjects
FORTREE_CITY_EventObjects: @ 0x084FF2A8
	object_event 1, 23, 0, 31, 3, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE00, 0x0000
	object_event 2, 8, 0, 32, 16, 3, 2, 1, 1, 0, 0, FortreeCity_EventScript_001DFE28, 0x0000
	object_event 3, 34, 0, 32, 10, 3, 3, 0, 1, 0, 0, FortreeCity_EventScript_001DFE09, 0x0000
	object_event 4, 7, 0, 11, 14, 4, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE3A, 0x0000
	object_event 5, 29, 0, 8, 10, 3, 1, 0, 0, 0, 0, FortreeCity_EventScript_001DFE31, 0x0000
	object_event 6, 189, 0, 9, 16, 3, 8, 0, 0, 0, 0, FortreeCity_EventScript_001DFE43, 0x0000
	object_event 7, 204, 0, 25, 8, 3, 76, 1, 1, 0, 0, FortreeCity_EventScript_001DFE5E, 0x03C9
	.globl FORTREE_CITY_EventWarps
FORTREE_CITY_EventWarps: @ 0x084FF350
	warp_def 5, 6, 0, 0, MAP_FORTREE_CITY_POKEMON_CENTER_1F
	warp_def 10, 3, 0, 0, MAP_FORTREE_CITY_HOUSE1
	warp_def 22, 11, 0, 0, MAP_FORTREE_CITY_GYM
	warp_def 4, 14, 0, 0, MAP_FORTREE_CITY_MART
	warp_def 17, 3, 0, 0, MAP_FORTREE_CITY_HOUSE2
	warp_def 25, 3, 0, 0, MAP_FORTREE_CITY_HOUSE3
	warp_def 32, 2, 0, 0, MAP_FORTREE_CITY_HOUSE4
	warp_def 12, 13, 0, 0, MAP_FORTREE_CITY_HOUSE5
	warp_def 37, 13, 0, 0, MAP_FORTREE_CITY_DECORATION_SHOP
	.globl FORTREE_CITY_EventBgEvents
FORTREE_CITY_EventBgEvents: @ 0x084FF398
	bg_event 6, 9, 0, 0, FortreeCity_EventScript_001DFE4C, 0, 0
	bg_event 7, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 5, 14, 0, 1, 0x08242EF6, 0, 0
	bg_event 26, 10, 0, 0, FortreeCity_EventScript_001DFE55, 0, 0
	bg_event 6, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 14, 0, 1, 0x08242EF6, 0, 0
	.globl gMapEvents_FORTREE_CITY
gMapEvents_FORTREE_CITY: @ 0x084FF3E0
	map_events FORTREE_CITY_EventObjects, FORTREE_CITY_EventWarps, 0, FORTREE_CITY_EventBgEvents
	.globl LILYCOVE_CITY_EventObjects
LILYCOVE_CITY_EventObjects: @ 0x084FF3F4
	object_event 1, 49, 0, 32, 20, 3, 3, 0, 1, 0, 0, LilycoveCity_EventScript_001E0288, 0x0000
	object_event 2, 8, 0, 15, 18, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E0260, 0x0000
	object_event 3, 19, 0, 28, 28, 3, 1, 0, 0, 0, 0, LilycoveCity_EventScript_001E0257, 0x0000
	object_event 4, 15, 0, 21, 15, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E027F, 0x0000
	object_event 5, 23, 0, 16, 9, 5, 5, 1, 0, 0, 0, LilycoveCity_EventScript_001E02C6, 0x0000
	object_event 6, 20, 0, 35, 27, 3, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E02A7, 0x0000
	object_event 7, 21, 0, 35, 37, 5, 8, 0, 0, 0, 0, LilycoveCity_EventScript_001E02CF, 0x0000
	object_event 8, 22, 0, 34, 37, 5, 8, 0, 0, 0, 0, LilycoveCity_EventScript_001E02D8, 0x0000
	object_event 9, 21, 0, 57, 17, 3, 1, 0, 0, 0, 0, LilycoveCity_EventScript_001E02E1, 0x0000
	object_event 10, 117, 0, 73, 15, 3, 10, 0, 0, 0, 0, LilycoveCity_EventScript_001E03B2, 0x0354
	object_event 11, 59, 0, 61, 36, 5, 1, 0, 0, 0, 0, 0x08256E3F, 0x0412
	object_event 12, 117, 0, 43, 18, 3, 5, 1, 0, 0, 0, LilycoveCity_EventScript_001E040A, 0x0354
	object_event 13, 117, 0, 46, 12, 3, 9, 0, 0, 0, 0, LilycoveCity_EventScript_001E03EF, 0x0354
	object_event 14, 117, 0, 45, 12, 3, 10, 0, 0, 0, 0, LilycoveCity_EventScript_001E03F8, 0x0354
	object_event 15, 117, 0, 38, 9, 5, 9, 0, 0, 0, 0, LilycoveCity_EventScript_001E0401, 0x0354
	object_event 16, 48, 0, 50, 7, 5, 2, 1, 1, 0, 0, LilycoveCity_EventScript_001E020D, 0x0000
	object_event 17, 240, 0, 27, 7, 5, 8, 1, 1, 0, 0, LilycoveCity_EventScript_001E0413, 0x03CB
	object_event 18, 38, 0, 16, 23, 3, 10, 1, 1, 0, 0, LilycoveCity_EventScript_001E0662, 0x0000
	object_event 19, 24, 0, 41, 25, 3, 9, 1, 1, 0, 0, LilycoveCity_EventScript_001E0323, 0x0000
	object_event 20, 23, 0, 40, 25, 3, 10, 1, 1, 0, 0, LilycoveCity_EventScript_001E0312, 0x0000
	object_event 21, 49, 0, 16, 34, 3, 8, 1, 1, 0, 0, LilycoveCity_EventScript_001E0300, 0x0000
	object_event 22, 17, 0, 16, 35, 3, 7, 1, 1, 0, 0, LilycoveCity_EventScript_001E0309, 0x0000
	.globl LILYCOVE_CITY_EventWarps
LILYCOVE_CITY_EventWarps: @ 0x084FF604
	warp_def 27, 6, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	warp_def 37, 24, 0, 0, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
	warp_def 24, 14, 0, 0, MAP_LILYCOVE_CITY_POKEMON_CENTER_1F
	warp_def 11, 5, 0, 0, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	warp_def 23, 24, 0, 0, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 39, 14, 0, 1, MAP_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
	warp_def 70, 5, 1, 0, MAP_AQUA_HIDEOUT_1F
	warp_def 36, 6, 0, 0, MAP_LILYCOVE_CITY_MOVE_DELETERS_HOUSE
	warp_def 42, 6, 0, 0, MAP_LILYCOVE_CITY_HOUSE1
	warp_def 55, 15, 0, 0, MAP_LILYCOVE_CITY_HOUSE2
	warp_def 11, 22, 0, 0, MAP_LILYCOVE_CITY_HOUSE3
	warp_def 12, 14, 0, 0, MAP_LILYCOVE_CITY_HOUSE4
	warp_def 12, 32, 0, 0, MAP_LILYCOVE_CITY_HARBOR
	warp_def 12, 5, 0, 1, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	.globl LILYCOVE_CITY_EventBgEvents
LILYCOVE_CITY_EventBgEvents: @ 0x084FF674
	bg_event 19, 7, 0, 0, LilycoveCity_EventScript_001E034F, 0, 0
	bg_event 25, 14, 0, 1, 0x08242EFF, 0, 0
	bg_event 29, 7, 0, 0, LilycoveCity_EventScript_001E03A0, 0, 0
	bg_event 26, 14, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 15, 0, 0, LilycoveCity_EventScript_001E0334, 0, 0
	bg_event 29, 24, 0, 0, LilycoveCity_EventScript_001E033D, 0, 0
	bg_event 35, 24, 0, 0, LilycoveCity_EventScript_001E0346, 0, 0
	bg_event 6, 30, 3, 0, LilycoveCity_EventScript_001E0379, 0, 0
	bg_event 36, 14, 0, 0, LilycoveCity_EventScript_001E0397, 0, 0
	bg_event 34, 6, 0, 0, LilycoveCity_EventScript_001E03A9, 0, 0
	bg_event 36, 31, 3, 7, 0x006F, 0x1B, 0x00
	bg_event 61, 7, 0, 7, 0x0045, 0x2B, 0x00
	bg_event 64, 31, 0, 7, 0x0004, 0x4B, 0x00
	.globl gMapEvents_LILYCOVE_CITY
gMapEvents_LILYCOVE_CITY: @ 0x084FF710
	map_events LILYCOVE_CITY_EventObjects, LILYCOVE_CITY_EventWarps, 0, LILYCOVE_CITY_EventBgEvents
	.globl MOSSDEEP_CITY_EventObjects
MOSSDEEP_CITY_EventObjects: @ 0x084FF724
	object_event 1, 49, 0, 38, 12, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E15A0, 0x0000
	object_event 2, 21, 0, 50, 34, 5, 5, 1, 0, 0, 0, MossdeepCity_EventScript_001E15C8, 0x0000
	object_event 3, 18, 0, 32, 12, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E1581, 0x0000
	object_event 4, 5, 0, 26, 21, 5, 3, 0, 1, 0, 0, MossdeepCity_EventScript_001E15BF, 0x0000
	object_event 5, 8, 0, 45, 18, 7, 9, 0, 0, 0, 0, MossdeepCity_EventScript_001E15D1, 0x0000
	object_event 6, 59, 0, 62, 35, 5, 1, 0, 0, 0, 0, 0x08256E4C, 0x0413
	object_event 7, 19, 0, 55, 5, 7, 7, 0, 0, 0, 0, MossdeepCity_EventScript_001E16DF, 0x0000
	object_event 8, 16, 0, 56, 21, 7, 10, 1, 1, 0, 0, MossdeepCity_EventScript_001E15DA, 0x0000
	object_event 9, 9, 0, 23, 13, 5, 2, 1, 1, 0, 0, MossdeepCity_EventScript_001E16F5, 0x0000
	object_event 10, 119, 0, 44, 23, 5, 8, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 11, 119, 0, 44, 24, 5, 7, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 12, 119, 0, 44, 25, 5, 8, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 13, 119, 0, 44, 26, 5, 7, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 14, 196, 0, 45, 25, 5, 9, 1, 1, 0, 0, 0x00000000, 0x0337
	object_event 15, 44, 0, 19, 25, 3, 64, 3, 3, 0, 0, 0x08276B0A, 0x0000
	object_event 16, 219, 0, 61, 29, 5, 17, 0, 0, 0, 0, MossdeepCity_EventScript_001E1754, 0x0314
	object_event 17, 44, 0, 31, 29, 3, 64, 3, 3, 0, 0, MossdeepCity_EventScript_001E174B, 0x0000
	.globl MOSSDEEP_CITY_EventWarps
MOSSDEEP_CITY_EventWarps: @ 0x084FF8BC
	warp_def 28, 9, 0, 0, MAP_MOSSDEEP_CITY_HOUSE1
	warp_def 38, 9, 0, 0, MAP_MOSSDEEP_CITY_GYM
	warp_def 28, 16, 0, 0, MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F
	warp_def 67, 25, 0, 0, MAP_MOSSDEEP_CITY_HOUSE2
	warp_def 37, 18, 0, 0, MAP_MOSSDEEP_CITY_MART
	warp_def 49, 6, 0, 0, MAP_MOSSDEEP_CITY_HOUSE3
	warp_def 19, 10, 0, 0, MAP_MOSSDEEP_CITY_STEVENS_HOUSE
	warp_def 18, 16, 0, 1, MAP_MOSSDEEP_CITY_HOUSE4
	warp_def 64, 15, 0, 0, MAP_MOSSDEEP_CITY_SPACE_CENTER_1F
	warp_def 36, 24, 0, 0, MAP_MOSSDEEP_CITY_GAME_CORNER_1F
	.globl MOSSDEEP_CITY_EventCoordEvents
MOSSDEEP_CITY_EventCoordEvents: @ 0x084FF90C
	coord_event 25, 25, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 26, 25, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 32, 27, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 33, 27, 0, 16385, 0, MossdeepCity_EventScript_001E1607
	coord_event 42, 21, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 22, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 23, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 41, 24, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 40, 25, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	coord_event 40, 26, 5, 16477, 1, MossdeepCity_EventScript_001E1610
	.globl MOSSDEEP_CITY_EventBgEvents
MOSSDEEP_CITY_EventBgEvents: @ 0x084FF9AC
	bg_event 25, 16, 0, 0, MossdeepCity_EventScript_001E15F5, 0, 0
	bg_event 34, 9, 0, 0, MossdeepCity_EventScript_001E15EC, 0, 0
	bg_event 29, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 38, 18, 0, 1, 0x08242EF6, 0, 0
	bg_event 66, 16, 0, 0, MossdeepCity_EventScript_001E15FE, 0, 0
	bg_event 30, 16, 0, 1, 0x08242EFF, 0, 0
	bg_event 39, 18, 0, 1, 0x08242EF6, 0, 0
	bg_event 57, 21, 7, 0, MossdeepCity_EventScript_001E15E3, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY
gMapEvents_MOSSDEEP_CITY: @ 0x084FFA0C
	map_events MOSSDEEP_CITY_EventObjects, MOSSDEEP_CITY_EventWarps, MOSSDEEP_CITY_EventCoordEvents, MOSSDEEP_CITY_EventBgEvents
	.globl SOOTOPOLIS_CITY_EventObjects
SOOTOPOLIS_CITY_EventObjects: @ 0x084FFA20
	object_event 1, 21, 0, 31, 18, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_001E2527, 0x0000
	object_event 2, 26, 0, 47, 33, 0, 9, 0, 0, 0, 0, SootopolisCity_EventScript_001E267C, 0x0356
	object_event 3, 10, 0, 9, 43, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_001E2572, 0x0000
	object_event 4, 5, 0, 51, 14, 3, 8, 0, 0, 0, 0, SootopolisCity_EventScript_001E2728, 0x0000
	object_event 5, 7, 0, 43, 26, 3, 1, 0, 0, 0, 0, SootopolisCity_EventScript_001E277D, 0x0000
	object_event 6, 19, 0, 26, 4, 3, 5, 1, 0, 0, 0, SootopolisCity_EventScript_001E26B1, 0x0347
	object_event 7, 134, 0, 20, 36, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2800, 0x03CD
	object_event 8, 34, 0, 49, 34, 3, 3, 1, 1, 0, 0, SootopolisCity_EventScript_001E26D2, 0x0000
	object_event 9, 222, 0, 28, 44, 0, 80, 1, 1, 0, 0, 0x00000000, 0x03E6
	object_event 10, 221, 0, 34, 44, 1, 79, 1, 1, 0, 0, 0x00000000, 0x03E5
	object_event 11, 207, 0, 31, 41, 1, 10, 1, 1, 0, 0, 0x00000000, 0x03E4
	object_event 12, 39, 0, 17, 44, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2AAB, 0x0356
	object_event 13, 14, 0, 14, 42, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2A75, 0x0356
	object_event 14, 44, 0, 17, 40, 3, 10, 1, 1, 0, 0, SootopolisCity_EventScript_001E2A2D, 0x0356
	object_event 15, 9, 0, 19, 37, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E29F7, 0x0356
	object_event 16, 196, 0, 29, 33, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2B8C, 0x033B
	object_event 17, 195, 0, 31, 33, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2BB9, 0x033A
	object_event 18, 133, 0, 31, 18, 3, 8, 1, 1, 0, 0, SootopolisCity_EventScript_001E2AE0, 0x0330
	.globl SOOTOPOLIS_CITY_EventWarps
SOOTOPOLIS_CITY_EventWarps: @ 0x084FFBD0
	warp_def 43, 31, 0, 0, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	warp_def 17, 29, 0, 0, MAP_SOOTOPOLIS_CITY_MART
	warp_def 31, 32, 0, 0, MAP_SOOTOPOLIS_CITY_GYM_1F
	warp_def 31, 16, 3, 0, MAP_CAVE_OF_ORIGIN_ENTRANCE
	warp_def 9, 6, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE1
	warp_def 45, 6, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE2
	warp_def 9, 17, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE3
	warp_def 44, 17, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE4
	warp_def 9, 26, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE5
	warp_def 53, 28, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE6
	warp_def 8, 35, 0, 0, MAP_SOOTOPOLIS_CITY_HOUSE7
	warp_def 48, 25, 0, 0, MAP_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
	warp_def 51, 36, 0, 0, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
	.globl SOOTOPOLIS_CITY_EventBgEvents
SOOTOPOLIS_CITY_EventBgEvents: @ 0x084FFC38
	bg_event 33, 34, 3, 0, SootopolisCity_EventScript_001E27E5, 0, 0
	bg_event 19, 29, 0, 1, 0x08242EF6, 0, 0
	bg_event 44, 31, 0, 1, 0x08242EFF, 0, 0
	bg_event 45, 31, 0, 1, 0x08242EFF, 0, 0
	bg_event 18, 29, 0, 1, 0x08242EF6, 0, 0
	bg_event 41, 37, 0, 0, SootopolisCity_EventScript_001E27EE, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY
gMapEvents_SOOTOPOLIS_CITY: @ 0x084FFC80
	map_events SOOTOPOLIS_CITY_EventObjects, SOOTOPOLIS_CITY_EventWarps, 0, SOOTOPOLIS_CITY_EventBgEvents
	.globl EVER_GRANDE_CITY_EventObjects
EVER_GRANDE_CITY_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_EventWarps
EVER_GRANDE_CITY_EventWarps: @ 0x084FFC94
	warp_def 18, 5, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 27, 48, 0, 0, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	warp_def 18, 41, 0, 0, MAP_VICTORY_ROAD_1F
	warp_def 18, 27, 0, 1, MAP_VICTORY_ROAD_1F
	.globl EVER_GRANDE_CITY_EventCoordEvents
EVER_GRANDE_CITY_EventCoordEvents: @ 0x084FFCB4
	coord_event 17, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 16, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 18, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 19, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 20, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 21, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 22, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 23, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 24, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 25, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	coord_event 26, 58, 1, 16385, 0, EverGrandeCity_EventScript_001E39A4
	.globl EVER_GRANDE_CITY_EventBgEvents
EVER_GRANDE_CITY_EventBgEvents: @ 0x084FFD64
	bg_event 19, 43, 5, 0, EverGrandeCity_EventScript_001E3989, 0, 0
	bg_event 29, 48, 0, 1, 0x08242EFF, 0, 0
	bg_event 18, 52, 5, 0, EverGrandeCity_EventScript_001E3992, 0, 0
	bg_event 23, 15, 0, 0, EverGrandeCity_EventScript_001E399B, 0, 0
	bg_event 28, 48, 0, 1, 0x08242EFF, 0, 0
	.globl gMapEvents_EVER_GRANDE_CITY
gMapEvents_EVER_GRANDE_CITY: @ 0x084FFDA0
	map_events 0, EVER_GRANDE_CITY_EventWarps, EVER_GRANDE_CITY_EventCoordEvents, EVER_GRANDE_CITY_EventBgEvents
	.globl LITTLEROOT_TOWN_EventObjects
LITTLEROOT_TOWN_EventObjects: @ 0x084FFDB4
	object_event 1, 6, 0, 16, 10, 3, 2, 1, 2, 0, 0, LittlerootTown_EventScript_001E3C5E, 0x0000
	object_event 2, 17, 0, 12, 13, 3, 2, 2, 1, 0, 0, LittlerootTown_EventScript_001E3C4C, 0x0364
	object_event 3, 9, 0, 14, 17, 3, 2, 2, 1, 0, 0, LittlerootTown_EventScript_001E3C55, 0x0000
	object_event 4, 215, 0, 5, 8, 3, 7, 0, 0, 0, 0, LittlerootTown_EventScript_001E4267, 0x02F0
	object_event 5, 94, 0, 2, 10, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02F9
	object_event 6, 94, 0, 11, 10, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02FA
	object_event 7, 240, 0, 13, 10, 3, 7, 1, 1, 0, 0, 0x00000000, 0x031A
	object_event 8, 64, 0, 14, 10, 3, 7, 1, 1, 0, 0, 0x00000000, 0x031B
	.globl LITTLEROOT_TOWN_EventWarps
LITTLEROOT_TOWN_EventWarps: @ 0x084FFE74
	warp_def 14, 8, 0, 1, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 5, 8, 0, 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 7, 16, 0, 0, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
	.globl LITTLEROOT_TOWN_EventCoordEvents
LITTLEROOT_TOWN_EventCoordEvents: @ 0x084FFE8C
	coord_event 10, 1, 3, 16464, 0, LittlerootTown_EventScript_001E3CBB
	coord_event 11, 1, 3, 16464, 0, LittlerootTown_EventScript_001E3D19
	coord_event 11, 1, 3, 16464, 1, LittlerootTown_EventScript_001E3D49
	coord_event 8, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E23
	coord_event 9, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E2F
	coord_event 10, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E0B
	coord_event 11, 9, 3, 16464, 3, LittlerootTown_EventScript_001E3E17
	coord_event 10, 2, 3, 16464, 3, LittlerootTown_EventScript_001E3DE5
	coord_event 11, 2, 3, 16464, 3, LittlerootTown_EventScript_001E3DF8
	.globl LITTLEROOT_TOWN_EventBgEvents
LITTLEROOT_TOWN_EventBgEvents: @ 0x084FFF1C
	bg_event 15, 13, 0, 0, LittlerootTown_EventScript_001E3D7B, 0, 0
	bg_event 6, 17, 0, 0, LittlerootTown_EventScript_001E3D84, 0, 0
	bg_event 7, 8, 3, 0, LittlerootTown_EventScript_001E3D8D, 0, 0
	bg_event 12, 8, 3, 0, LittlerootTown_EventScript_001E3DB9, 0, 0
	.globl gMapEvents_LITTLEROOT_TOWN
gMapEvents_LITTLEROOT_TOWN: @ 0x084FFF4C
	map_events LITTLEROOT_TOWN_EventObjects, LITTLEROOT_TOWN_EventWarps, LITTLEROOT_TOWN_EventCoordEvents, LITTLEROOT_TOWN_EventBgEvents
	.include "data/maps/OldaleTown/events.inc"
	.globl gMapEvents_OLDALE_TOWN
	.set gMapEvents_OLDALE_TOWN, OldaleTown_MapEvents
	.include "data/maps/DewfordTown/events.inc"
	.globl gMapEvents_DEWFORD_TOWN
	.set gMapEvents_DEWFORD_TOWN, DewfordTown_MapEvents
	.globl LAVARIDGE_TOWN_EventObjects
LAVARIDGE_TOWN_EventObjects: @ 0x08500160
	object_event 1, 22, 0, 8, 7, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58CA, 0x0000
	object_event 2, 21, 0, 5, 1, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E589D, 0x0000
	object_event 3, 29, 0, 5, 8, 3, 8, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58A6, 0x0000
	object_event 4, 6, 0, 10, 13, 3, 3, 0, 2, 0, 0, LavaridgeTown_EventScript_001E58AF, 0x0000
	object_event 5, 139, 0, 4, 4, 3, 18, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58B8, 0x0000
	object_event 6, 139, 0, 5, 4, 3, 17, 0, 0, 0, 0, LavaridgeTown_EventScript_001E58C1, 0x0000
	object_event 7, 243, 0, 6, 16, 3, 9, 0, 0, 0, 0, 0x00000000, 0x03A2
	object_event 8, 240, 0, 12, 15, 0, 8, 0, 0, 0, 0, 0x00000000, 0x03A1
	object_event 9, 22, 0, 4, 7, 3, 8, 1, 1, 0, 0, LavaridgeTown_EventScript_001E58D3, 0x0000
	.globl LAVARIDGE_TOWN_EventWarps
LAVARIDGE_TOWN_EventWarps: @ 0x08500238
	warp_def 12, 15, 0, 0, MAP_LAVARIDGE_TOWN_HERB_SHOP
	warp_def 5, 15, 0, 0, MAP_LAVARIDGE_TOWN_GYM_1F
	warp_def 15, 5, 0, 0, MAP_LAVARIDGE_TOWN_MART
	warp_def 9, 6, 0, 0, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	warp_def 16, 15, 0, 0, MAP_LAVARIDGE_TOWN_HOUSE
	warp_def 9, 2, 3, 3, MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	.globl LAVARIDGE_TOWN_EventCoordEvents
LAVARIDGE_TOWN_EventCoordEvents: @ 0x08500268
	coord_event 6, 3, 3, 0, 0, LavaridgeTown_EventScript_001E5889
	.globl LAVARIDGE_TOWN_EventBgEvents
LAVARIDGE_TOWN_EventBgEvents: @ 0x08500278
	bg_event 14, 16, 0, 0, LavaridgeTown_EventScript_001E5946, 0, 0
	bg_event 7, 15, 0, 0, LavaridgeTown_EventScript_001E593D, 0, 0
	bg_event 17, 5, 0, 1, 0x08242EF6, 0, 0
	bg_event 13, 8, 0, 0, LavaridgeTown_EventScript_001E5934, 0, 0
	bg_event 10, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 16, 5, 0, 1, 0x08242EF6, 0, 0
	bg_event 11, 6, 0, 1, 0x08242EFF, 0, 0
	bg_event 4, 5, 3, 7, 0x0010, 0x00, 0x00
	.globl gMapEvents_LAVARIDGE_TOWN
gMapEvents_LAVARIDGE_TOWN: @ 0x085002D8
	map_events LAVARIDGE_TOWN_EventObjects, LAVARIDGE_TOWN_EventWarps, LAVARIDGE_TOWN_EventCoordEvents, LAVARIDGE_TOWN_EventBgEvents
	.globl FALLARBOR_TOWN_EventObjects
FALLARBOR_TOWN_EventObjects: @ 0x085002EC
	object_event 1, 8, 0, 8, 11, 3, 8, 0, 1, 0, 0, FallarborTown_EventScript_001E5E94, 0x0000
	object_event 2, 21, 0, 11, 9, 3, 5, 1, 0, 0, 0, FallarborTown_EventScript_001E5E75, 0x0000
	object_event 3, 48, 0, 11, 15, 3, 3, 1, 1, 0, 0, FallarborTown_EventScript_001E5E9D, 0x0000
	object_event 4, 214, 0, 8, 12, 3, 1, 1, 0, 0, 0, FallarborTown_EventScript_001E5EA6, 0x038B
	.globl FALLARBOR_TOWN_EventWarps
FALLARBOR_TOWN_EventWarps: @ 0x0850034C
	warp_def 15, 15, 0, 0, MAP_FALLARBOR_TOWN_MART
	warp_def 8, 7, 0, 0, MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
	warp_def 14, 7, 0, 0, MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F
	warp_def 6, 17, 0, 0, MAP_FALLARBOR_TOWN_COZMOS_HOUSE
	warp_def 1, 6, 0, 0, MAP_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE
	.globl FALLARBOR_TOWN_EventBgEvents
FALLARBOR_TOWN_EventBgEvents: @ 0x08500374
	bg_event 16, 15, 0, 1, 0x08242EF6, 0, 0
	bg_event 15, 7, 0, 1, 0x08242EFF, 0, 0
	bg_event 6, 8, 0, 0, FallarborTown_EventScript_001E5EB9, 0, 0
	bg_event 16, 7, 0, 1, 0x08242EFF, 0, 0
	bg_event 10, 11, 0, 0, FallarborTown_EventScript_001E5EC2, 0, 0
	bg_event 17, 15, 0, 1, 0x08242EF6, 0, 0
	bg_event 3, 7, 0, 0, FallarborTown_EventScript_001E5ECB, 0, 0
	bg_event 2, 15, 3, 7, 0x006E, 0x1C, 0x00
	.globl gMapEvents_FALLARBOR_TOWN
gMapEvents_FALLARBOR_TOWN: @ 0x085003D4
	map_events FALLARBOR_TOWN_EventObjects, FALLARBOR_TOWN_EventWarps, 0, FALLARBOR_TOWN_EventBgEvents
	.globl VERDANTURF_TOWN_EventObjects
VERDANTURF_TOWN_EventObjects: @ 0x085003E8
	object_event 1, 23, 0, 4, 17, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_001E609B, 0x0000
	object_event 2, 6, 0, 9, 2, 3, 9, 1, 0, 0, 0, VerdanturfTown_EventScript_001E6068, 0x0000
	object_event 3, 7, 0, 7, 11, 3, 3, 0, 1, 0, 0, VerdanturfTown_EventScript_001E60AD, 0x0000
	object_event 4, 31, 0, 7, 6, 3, 5, 1, 0, 0, 0, VerdanturfTown_EventScript_001E60A4, 0x0000
	.globl VERDANTURF_TOWN_EventWarps
VERDANTURF_TOWN_EventWarps: @ 0x08500448
	warp_def 3, 7, 0, 0, MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY
	warp_def 12, 3, 0, 0, MAP_VERDANTURF_TOWN_MART
	warp_def 16, 3, 0, 0, MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F
	warp_def 10, 14, 0, 0, MAP_VERDANTURF_TOWN_WANDAS_HOUSE
	warp_def 8, 1, 0, 1, MAP_RUSTURF_TUNNEL
	warp_def 1, 14, 0, 0, MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE
	warp_def 17, 15, 0, 0, MAP_VERDANTURF_TOWN_HOUSE
	.globl VERDANTURF_TOWN_EventBgEvents
VERDANTURF_TOWN_EventBgEvents: @ 0x08500480
	bg_event 14, 3, 0, 1, 0x08242EF6, 0, 0
	bg_event 14, 6, 0, 0, VerdanturfTown_EventScript_001E60CC, 0, 0
	bg_event 17, 3, 0, 1, 0x08242EFF, 0, 0
	bg_event 7, 14, 0, 0, VerdanturfTown_EventScript_001E60D5, 0, 0
	bg_event 13, 3, 0, 1, 0x08242EF6, 0, 0
	bg_event 18, 3, 0, 1, 0x08242EFF, 0, 0
	bg_event 1, 8, 0, 0, VerdanturfTown_EventScript_001E60DE, 0, 0
	bg_event 7, 3, 0, 0, VerdanturfTown_EventScript_001E60E7, 0, 0
	.globl gMapEvents_VERDANTURF_TOWN
gMapEvents_VERDANTURF_TOWN: @ 0x085004E0
	map_events VERDANTURF_TOWN_EventObjects, VERDANTURF_TOWN_EventWarps, 0, VERDANTURF_TOWN_EventBgEvents
	.globl PACIFIDLOG_TOWN_EventObjects
PACIFIDLOG_TOWN_EventObjects: @ 0x085004F4
	object_event 1, 8, 0, 10, 23, 3, 9, 0, 0, 0, 0, PacifidlogTown_EventScript_001E639C, 0x0000
	object_event 2, 50, 0, 11, 14, 3, 10, 0, 0, 0, 0, PacifidlogTown_EventScript_001E63A5, 0x0000
	object_event 3, 5, 0, 9, 16, 3, 8, 0, 0, 0, 0, PacifidlogTown_EventScript_001E6393, 0x0000
	.globl PACIFIDLOG_TOWN_EventWarps
PACIFIDLOG_TOWN_EventWarps: @ 0x0850053C
	warp_def 8, 15, 0, 0, MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
	warp_def 16, 13, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE1
	warp_def 3, 22, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE2
	warp_def 12, 24, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE3
	warp_def 2, 12, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE4
	warp_def 17, 21, 0, 0, MAP_PACIFIDLOG_TOWN_HOUSE5
	.globl PACIFIDLOG_TOWN_EventBgEvents
PACIFIDLOG_TOWN_EventBgEvents: @ 0x0850056C
	bg_event 9, 15, 0, 1, 0x08242EFF, 0, 0
	bg_event 7, 16, 0, 0, PacifidlogTown_EventScript_001E63AE, 0, 0
	bg_event 10, 15, 0, 1, 0x08242EFF, 0, 0
	.globl gMapEvents_PACIFIDLOG_TOWN
gMapEvents_PACIFIDLOG_TOWN: @ 0x08500590
	map_events PACIFIDLOG_TOWN_EventObjects, PACIFIDLOG_TOWN_EventWarps, 0, PACIFIDLOG_TOWN_EventBgEvents
	.globl ROUTE101_EventObjects
ROUTE101_EventObjects: @ 0x085005A4
	object_event 1, 35, 0, 16, 8, 3, 1, 0, 0, 0, 0, Route101_EventScript_001E65F7, 0x0000
	object_event 2, 64, 0, 9, 13, 0, 71, 0, 0, 0, 0, 0x00000000, 0x02D0
	object_event 3, 97, 0, 7, 14, 3, 1, 0, 0, 0, 0, Route101_EventScript_001E6612, 0x02BC
	object_event 4, 98, 0, 10, 13, 0, 70, 0, 0, 0, 0, 0x00000000, 0x02EE
	object_event 5, 64, 0, 5, 11, 3, 1, 0, 0, 0, 0, 0x082431CD, 0x0381
	object_event 6, 9, 0, 2, 13, 3, 5, 1, 1, 0, 0, Route101_EventScript_001E6600, 0x03DF
	.globl ROUTE101_EventCoordEvents
ROUTE101_EventCoordEvents: @ 0x08500634
	coord_event 10, 19, 3, 16480, 1, Route101_EventScript_001E64DA
	coord_event 11, 19, 3, 16480, 1, Route101_EventScript_001E64DA
	coord_event 10, 18, 3, 16480, 2, Route101_EventScript_001E654A
	coord_event 11, 18, 3, 16480, 2, Route101_EventScript_001E654A
	coord_event 6, 16, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 15, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 17, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 6, 18, 3, 16480, 2, Route101_EventScript_001E6560
	coord_event 7, 13, 3, 16480, 2, Route101_EventScript_001E6576
	.globl ROUTE101_EventBgEvents
ROUTE101_EventBgEvents: @ 0x085006C4
	bg_event 5, 9, 0, 0, Route101_EventScript_001E6609, 0, 0
	.globl gMapEvents_ROUTE101
gMapEvents_ROUTE101: @ 0x085006D0
	map_events ROUTE101_EventObjects, 0, ROUTE101_EventCoordEvents, ROUTE101_EventBgEvents
	.globl ROUTE102_EventObjects
ROUTE102_EventObjects: @ 0x085006E4
	object_event 1, 11, 0, 18, 11, 3, 1, 0, 0, 0, 0, 0x081E6825, 0x0000
	object_event 2, 35, 0, 33, 14, 3, 8, 0, 0, 1, 3, 0x081E6849, 0x0000
	object_event 3, 36, 0, 25, 15, 3, 7, 0, 0, 1, 2, 0x081E68F7, 0x0000
	object_event 4, 47, 0, 8, 7, 3, 18, 0, 0, 1, 3, 0x081E690E, 0x0000
	object_event 5, 7, 0, 37, 4, 3, 2, 1, 1, 0, 0, 0x081E6840, 0x0000
	object_event 6, 59, 0, 11, 15, 3, 8, 0, 0, 0, 0, 0x08256A2F, 0x03E8
	object_event 7, 60, 0, 24, 2, 3, 12, 0, 0, 0, 2, 0x08244D23, 0x0000
	object_event 8, 60, 0, 25, 2, 3, 12, 0, 0, 0, 1, 0x08244D23, 0x0000
	object_event 9, 35, 0, 19, 4, 3, 8, 1, 1, 1, 3, 0x081E6925, 0x0000
	.globl ROUTE102_EventBgEvents
ROUTE102_EventBgEvents: @ 0x085007BC
	bg_event 17, 2, 0, 0, 0x081E6837, 0, 0
	bg_event 40, 9, 0, 0, 0x081E682E, 0, 0
	.globl gMapEvents_ROUTE102
gMapEvents_ROUTE102: @ 0x085007D4
	map_events ROUTE102_EventObjects, 0, 0, ROUTE102_EventBgEvents
	.globl ROUTE103_EventObjects
ROUTE103_EventObjects: @ 0x085007E8
	object_event 1, 33, 0, 49, 12, 3, 9, 0, 0, 0, 0, Route103_EventScript_Man, 0x0000
	object_event 2, 240, 0, 10, 3, 3, 10, 0, 0, 0, 0, Route103_EventScript_Rival, 0x02D3
	object_event 3, 20, 0, 71, 11, 3, 18, 0, 0, 1, 3, 0x081E6CBF, 0x0000
	object_event 4, 6, 0, 65, 12, 3, 8, 0, 0, 1, 1, 0x081E6D39, 0x0000
	object_event 5, 6, 0, 64, 12, 3, 8, 0, 0, 1, 1, 0x081E6CD6, 0x0000
	object_event 6, 50, 0, 50, 8, 3, 26, 0, 1, 1, 3, 0x081E6D9C, 0x0000
	object_event 7, 60, 0, 58, 5, 3, 12, 0, 0, 0, 5, 0x08244D23, 0x0000
	object_event 8, 60, 0, 59, 5, 3, 12, 0, 0, 0, 6, 0x08244D23, 0x0000
	object_event 9, 60, 0, 60, 5, 3, 12, 0, 0, 0, 7, 0x08244D23, 0x0000
	object_event 10, 7, 0, 20, 10, 3, 2, 1, 2, 0, 0, Route103_EventScript_Boy, 0x0000
	object_event 11, 64, 0, 7, 3, 3, 2, 1, 1, 0, 0, 0x082431CD, 0x0382
	object_event 12, 25, 0, 56, 13, 3, 10, 0, 0, 1, 5, 0x081E6DB3, 0x0000
	object_event 13, 59, 0, 50, 5, 3, 1, 1, 1, 0, 0, 0x08256A3C, 0x045A
	object_event 14, 82, 0, 67, 7, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0012
	object_event 15, 82, 0, 72, 8, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0013
	object_event 16, 44, 0, 67, 5, 3, 8, 1, 1, 1, 2, 0x081E6E2C, 0x0000
	object_event 17, 66, 0, 67, 9, 3, 7, 1, 1, 1, 2, 0x081E6E15, 0x0000
	object_event 18, 43, 0, 36, 6, 1, 26, 1, 3, 1, 5, 0x081E6E5A, 0x0000
	object_event 19, 42, 0, 36, 13, 1, 25, 1, 3, 1, 5, 0x081E6E43, 0x0000
	object_event 20, 59, 0, 64, 7, 0, 1, 1, 1, 0, 0, 0x08256A49, 0x0471
	.globl ROUTE103_EventWarps
ROUTE103_EventWarps: @ 0x085009C8
	warp_def 45, 6, 0, 0, MAP_ALTERING_CAVE
	.globl ROUTE103_EventBgEvents
ROUTE103_EventBgEvents: @ 0x085009D0
	bg_event 11, 9, 0, 0, Route103_EventScript_RouteSign, 0, 0
	.globl gMapEvents_ROUTE103
gMapEvents_ROUTE103: @ 0x085009DC
	map_events ROUTE103_EventObjects, ROUTE103_EventWarps, 0, ROUTE103_EventBgEvents
	.globl ROUTE104_EventObjects
ROUTE104_EventObjects: @ 0x085009F0
	object_event 1, 36, 0, 15, 60, 3, 9, 0, 0, 0, 0, Route104_EventScript_BugCatcher, 0x0000
	object_event 2, 10, 0, 25, 49, 3, 2, 1, 1, 0, 0, Route104_EventScript_Girl1, 0x0000
	object_event 3, 47, 0, 31, 24, 3, 9, 0, 0, 1, 7, Route104_EventScript_Haley, 0x0000
	object_event 4, 7, 0, 27, 63, 3, 3, 0, 1, 0, 0, Route104_EventScript_Boy1, 0x0000
	object_event 5, 20, 0, 30, 50, 3, 2, 1, 1, 0, 0, Route104_EventScript_Woman, 0x0000
	object_event 6, 14, 0, 28, 74, 3, 7, 0, 0, 0, 0, Route104_EventScript_Girl2, 0x0000
	object_event 7, 88, 0, 12, 54, 1, 7, 0, 0, 0, 0, 0x00000000, 0x02E6
	object_event 8, 21, 0, 12, 51, 4, 10, 0, 0, 0, 0, 0x00000000, 0x02E2
	object_event 9, 50, 0, 29, 8, 3, 8, 0, 0, 1, 0, Route104_EventScript_Ivan, 0x0000
	object_event 10, 60, 0, 34, 6, 3, 12, 0, 0, 0, 8, 0x08244D23, 0x0000
	object_event 11, 60, 0, 35, 6, 3, 12, 0, 0, 0, 9, 0x08244D23, 0x0000
	object_event 12, 60, 0, 36, 6, 3, 12, 0, 0, 0, 10, 0x08244D23, 0x0000
	object_event 13, 60, 0, 22, 41, 3, 12, 0, 0, 0, 11, 0x08244D23, 0x0000
	object_event 14, 60, 0, 23, 41, 3, 12, 0, 0, 0, 12, 0x08244D23, 0x0000
	object_event 15, 60, 0, 24, 41, 3, 12, 0, 0, 0, 13, 0x08244D23, 0x0000
	object_event 16, 22, 0, 37, 8, 3, 9, 1, 1, 0, 0, Route104_EventScript_ExpertF, 0x0000
	object_event 17, 60, 0, 3, 22, 3, 12, 0, 0, 0, 3, 0x08244D23, 0x0000
	object_event 18, 60, 0, 3, 23, 3, 12, 0, 0, 0, 4, 0x08244D23, 0x0000
	object_event 19, 60, 0, 3, 24, 3, 12, 0, 0, 0, 75, 0x08244D23, 0x0000
	object_event 20, 60, 0, 3, 25, 3, 12, 0, 0, 0, 76, 0x08244D23, 0x0000
	object_event 21, 59, 0, 39, 15, 3, 1, 0, 0, 0, 0, 0x08256A56, 0x03EA
	object_event 22, 34, 0, 8, 19, 3, 5, 1, 0, 0, 0, Route104_EventScript_WhiteHerbFlorist, 0x038A
	object_event 23, 6, 0, 27, 15, 3, 8, 0, 0, 1, 1, Route104_EventScript_Gina, 0x0000
	object_event 24, 6, 0, 28, 15, 3, 8, 0, 0, 1, 1, Route104_EventScript_Mia, 0x0000
	object_event 25, 15, 0, 21, 25, 3, 23, 0, 0, 1, 3, Route104_EventScript_Winston, 0x0000
	object_event 26, 20, 0, 11, 44, 3, 16, 0, 0, 1, 3, Route104_EventScript_Cindy, 0x0000
	object_event 27, 59, 0, 29, 53, 3, 1, 1, 1, 0, 0, 0x08256A63, 0x0421
	object_event 28, 35, 0, 18, 67, 3, 46, 5, 6, 1, 2, Route104_EventScript_Billy, 0x0000
	object_event 29, 59, 0, 37, 22, 3, 1, 1, 1, 0, 0, 0x08256A70, 0x045B
	object_event 30, 82, 0, 35, 22, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0011
	object_event 31, 59, 0, 5, 8, 3, 1, 1, 1, 0, 0, 0x08256A7D, 0x046F
	object_event 32, 9, 0, 5, 26, 3, 1, 1, 1, 0, 0, Route104_EventScript_Boy2, 0x0000
	object_event 33, 50, 0, 15, 59, 3, 9, 0, 0, 1, 0, Route104_EventScript_Darian, 0x0000
	object_event 34, 240, 0, 17, 50, 0, 1, 1, 1, 0, 0, Route104_EventScript_Rival, 0x02CF
	.globl ROUTE104_EventWarps
ROUTE104_EventWarps: @ 0x08500D20
	warp_def 17, 50, 0, 0, MAP_ROUTE104_MR_BRINEYS_HOUSE
	warp_def 5, 18, 0, 0, MAP_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
	warp_def 10, 30, 3, 0, MAP_PETALBURG_WOODS
	warp_def 11, 30, 3, 1, MAP_PETALBURG_WOODS
	warp_def 10, 38, 3, 2, MAP_PETALBURG_WOODS
	warp_def 11, 38, 3, 3, MAP_PETALBURG_WOODS
	warp_def 32, 42, 3, 4, MAP_PETALBURG_WOODS
	warp_def 33, 42, 3, 5, MAP_PETALBURG_WOODS
	.globl ROUTE104_EventCoordEvents
ROUTE104_EventCoordEvents: @ 0x08500D60
	coord_event 17, 51, 3, 16483, 1, Route104_EventScript_RivalTrigger
	.globl ROUTE104_EventBgEvents
ROUTE104_EventBgEvents: @ 0x08500D70
	bg_event 20, 50, 0, 0, Route104_EventScript_BrineysCottageSign, 0, 0
	bg_event 27, 66, 0, 0, Route104_EventScript_RouteSignPetalburg, 0, 0
	bg_event 23, 5, 0, 0, Route104_EventScript_RouteSignRustboro, 0, 0
	bg_event 7, 20, 0, 0, Route104_EventScript_FlowerShopSign, 0, 0
	bg_event 17, 23, 3, 0, Route104_EventScript_TrainerTipsDoubleBattles, 0, 0
	bg_event 7, 6, 3, 7, 0x0016, 0x2C, 0x00
	bg_event 3, 9, 3, 7, 0x0004, 0x3E, 0x00
	bg_event 14, 55, 3, 7, 0x000D, 0x25, 0x00
	bg_event 16, 72, 3, 7, 0x000E, 0x55, 0x00
	bg_event 16, 64, 3, 7, 0x006F, 0x58, 0x00
	.globl gMapEvents_ROUTE104
gMapEvents_ROUTE104: @ 0x08500DE8
	map_events ROUTE104_EventObjects, ROUTE104_EventWarps, ROUTE104_EventCoordEvents, ROUTE104_EventBgEvents
	.globl ROUTE105_EventObjects
ROUTE105_EventObjects: @ 0x08500DFC
	object_event 1, 42, 0, 19, 60, 1, 10, 0, 0, 1, 6, Route105_EventScript_Luis, 0x0000
	object_event 2, 42, 0, 27, 36, 1, 27, 7, 0, 1, 3, Route105_EventScript_Dominik, 0x0000
	object_event 3, 43, 0, 8, 45, 1, 25, 0, 7, 1, 3, Route105_EventScript_Beverly, 0x0000
	object_event 4, 43, 0, 19, 9, 1, 24, 0, 5, 1, 3, Route105_EventScript_Imani, 0x0000
	object_event 5, 59, 0, 8, 73, 3, 1, 0, 0, 0, 0, 0x08256A8A, 0x03EB
	object_event 6, 55, 0, 17, 48, 3, 26, 0, 7, 1, 3, Route105_EventScript_Foster, 0x0000
	object_event 7, 66, 0, 4, 54, 3, 8, 0, 2, 1, 2, Route105_EventScript_Josue, 0x0000
	object_event 8, 55, 0, 4, 58, 3, 7, 0, 2, 1, 4, Route105_EventScript_Andres, 0x0000
	.globl ROUTE105_EventWarps
ROUTE105_EventWarps: @ 0x08500EBC
	warp_def 9, 20, 0, 0, MAP_ISLAND_CAVE
	.globl ROUTE105_EventBgEvents
ROUTE105_EventBgEvents: @ 0x08500EC4
	bg_event 15, 68, 3, 7, 0x006F, 0x59, 0x00
	bg_event 5, 56, 3, 7, 0x006B, 0x6F, 0x00
	.globl gMapEvents_ROUTE105
gMapEvents_ROUTE105: @ 0x08500EDC
	map_events ROUTE105_EventObjects, ROUTE105_EventWarps, 0, ROUTE105_EventBgEvents
	.globl ROUTE106_EventObjects
ROUTE106_EventObjects: @ 0x08500EF0
	object_event 1, 42, 0, 18, 5, 1, 27, 4, 0, 1, 3, Route106_EventScript_Douglas, 0x0000
	object_event 2, 43, 0, 29, 10, 1, 1, 0, 0, 1, 3, Route106_EventScript_Kyla, 0x0000
	object_event 3, 50, 0, 51, 14, 3, 10, 0, 0, 1, 4, Route106_EventScript_Elliot, 0x0000
	object_event 4, 50, 0, 65, 14, 3, 1, 0, 0, 1, 3, Route106_EventScript_Ned, 0x0000
	object_event 5, 59, 0, 29, 14, 3, 1, 0, 0, 0, 0, 0x08256A97, 0x03EC
	.globl ROUTE106_EventWarps
ROUTE106_EventWarps: @ 0x08500F68
	warp_def 48, 16, 0, 0, MAP_GRANITE_CAVE_1F
	.globl ROUTE106_EventBgEvents
ROUTE106_EventBgEvents: @ 0x08500F70
	bg_event 41, 11, 3, 7, 0x0004, 0x3F, 0x00
	bg_event 53, 12, 0, 7, 0x006C, 0x2E, 0x00
	bg_event 68, 15, 3, 7, 0x006F, 0x2F, 0x00
	bg_event 59, 13, 3, 0, Route106_EventScript_TrainerTipsSign, 0, 0
	.globl gMapEvents_ROUTE106
gMapEvents_ROUTE106: @ 0x08500FA0
	map_events ROUTE106_EventObjects, ROUTE106_EventWarps, 0, ROUTE106_EventBgEvents
	.globl ROUTE107_EventObjects
ROUTE107_EventObjects: @ 0x08500FB4
	object_event 1, 42, 0, 41, 10, 1, 24, 1, 1, 1, 3, Route107_EventScript_Darrin, 0x0000
	object_event 2, 42, 0, 23, 11, 1, 52, 6, 2, 1, 2, Route107_EventScript_Tony, 0x0000
	object_event 3, 43, 0, 16, 7, 1, 13, 0, 0, 1, 5, Route107_EventScript_Denise, 0x0000
	object_event 4, 43, 0, 50, 11, 1, 65, 1, 1, 1, 5, Route107_EventScript_Beth, 0x0000
	object_event 5, 43, 0, 33, 4, 1, 8, 1, 1, 1, 1, Route107_EventScript_Lisa, 0x0000
	object_event 6, 213, 0, 32, 4, 1, 8, 1, 1, 1, 1, Route107_EventScript_Ray, 0x0000
	object_event 7, 42, 0, 50, 5, 1, 64, 1, 1, 1, 5, Route107_EventScript_Camron, 0x0000
	.globl gMapEvents_ROUTE107
gMapEvents_ROUTE107: @ 0x0850105C
	map_events ROUTE107_EventObjects, 0, 0, 0
	.globl ROUTE108_EventObjects
ROUTE108_EventObjects: @ 0x08501070
	object_event 1, 42, 0, 52, 13, 1, 45, 3, 3, 1, 3, Route108_EventScript_Jerome, 0x0000
	object_event 2, 43, 0, 35, 12, 1, 13, 1, 1, 1, 3, Route108_EventScript_Tara, 0x0000
	object_event 3, 42, 0, 13, 13, 1, 24, 0, 0, 1, 3, Route108_EventScript_Matthew, 0x0000
	object_event 4, 43, 0, 8, 7, 1, 20, 6, 0, 1, 3, Route108_EventScript_Missy, 0x0000
	object_event 5, 34, 0, 41, 5, 3, 10, 1, 1, 1, 1, Route108_EventScript_Carolina, 0x0000
	object_event 6, 49, 0, 43, 5, 3, 9, 1, 1, 1, 1, Route108_EventScript_Cory, 0x0000
	object_event 7, 59, 0, 42, 4, 3, 1, 1, 1, 0, 0, 0x08256AA4, 0x0473
	.globl ROUTE108_EventWarps
ROUTE108_EventWarps: @ 0x08501118
	warp_def 29, 6, 3, 0, MAP_ABANDONED_SHIP_DECK
	.globl ROUTE108_EventBgEvents
ROUTE108_EventBgEvents: @ 0x08501120
	bg_event 38, 14, 3, 7, 0x0044, 0x56, 0x00
	.globl gMapEvents_ROUTE108
gMapEvents_ROUTE108: @ 0x0850112C
	map_events ROUTE108_EventObjects, ROUTE108_EventWarps, 0, ROUTE108_EventBgEvents
	.globl ROUTE109_EventObjects
ROUTE109_EventObjects: @ 0x08501140
	object_event 1, 88, 0, 21, 26, 1, 7, 0, 0, 0, 0, 0x00000000, 0x02E8
	object_event 2, 21, 0, 21, 24, 3, 7, 0, 0, 0, 0, Route109_EventScript_MrBriney, 0x02E5
	object_event 3, 42, 0, 12, 36, 3, 10, 0, 0, 1, 5, Route109_EventScript_David, 0x0000
	object_event 4, 43, 0, 25, 39, 1, 15, 0, 0, 1, 5, Route109_EventScript_Alice, 0x0000
	object_event 5, 49, 0, 15, 17, 4, 8, 0, 0, 1, 1, Route109_EventScript_Huey, 0x0000
	object_event 6, 49, 0, 24, 13, 3, 9, 0, 0, 1, 6, Route109_EventScript_Edmond, 0x0000
	object_event 7, 54, 0, 19, 10, 3, 8, 0, 0, 1, 3, Route109_EventScript_Ricky, 0x0000
	object_event 8, 53, 0, 22, 7, 3, 80, 0, 0, 1, 4, Route109_EventScript_Lola, 0x0000
	object_event 9, 12, 0, 11, 6, 3, 8, 0, 0, 0, 0, Route109_EventScript_SeashoreHouseGirl, 0x0000
	object_event 10, 59, 0, 27, 46, 3, 1, 0, 0, 0, 0, 0x08256AB1, 0x03ED
	object_event 11, 53, 0, 29, 32, 3, 13, 0, 0, 1, 3, Route109_EventScript_Gwen, 0x0000
	object_event 12, 53, 0, 28, 31, 3, 17, 0, 0, 1, 3, Route109_EventScript_Austina, 0x0000
	object_event 13, 50, 0, 21, 56, 0, 9, 0, 0, 1, 3, Route109_EventScript_Carter, 0x0000
	object_event 14, 54, 0, 24, 18, 3, 10, 1, 1, 0, 0, Route109_EventScript_SandCastleBoy, 0x0000
	object_event 15, 53, 0, 25, 18, 3, 9, 1, 1, 0, 0, Route109_EventScript_SoftSandGirl, 0x0000
	object_event 16, 18, 0, 30, 32, 3, 8, 1, 1, 0, 0, Route109_EventScript_Woman, 0x0000
	object_event 17, 26, 0, 8, 41, 3, 8, 1, 1, 1, 1, Route109_EventScript_Mel, 0x0000
	object_event 18, 65, 0, 9, 41, 3, 8, 1, 1, 1, 1, Route109_EventScript_Paul, 0x0000
	object_event 19, 29, 0, 33, 6, 3, 1, 1, 1, 0, 0, Route109_EventScript_OldMan, 0x0000
	object_event 20, 208, 0, 32, 6, 3, 1, 1, 1, 0, 0, Route109_EventScript_Zigzagoon, 0x0000
	object_event 21, 53, 0, 17, 13, 3, 80, 1, 1, 1, 6, Route109_EventScript_Hailey, 0x0000
	object_event 22, 54, 0, 27, 7, 3, 79, 1, 1, 1, 4, Route109_EventScript_Chandler, 0x0000
	object_event 23, 59, 0, 25, 6, 3, 1, 1, 1, 0, 0, 0x08256ABE, 0x0474
	object_event 24, 66, 0, 17, 56, 3, 80, 1, 1, 1, 3, Route109_EventScript_Elijah, 0x0000
	.globl ROUTE109_EventWarps
ROUTE109_EventWarps: @ 0x08501380
	warp_def 12, 5, 0, 0, MAP_ROUTE109_SEASHORE_HOUSE
	.globl ROUTE109_EventBgEvents
ROUTE109_EventBgEvents: @ 0x08501388
	bg_event 15, 5, 0, 0, Route109_EventScript_SeashoreHouseSign, 0, 0
	bg_event 29, 10, 3, 0, Route109_EventScript_TrainerTipsSign, 0, 0
	bg_event 16, 23, 3, 7, 0x0018, 0x32, 0x00
	bg_event 33, 5, 3, 7, 0x006F, 0x34, 0x00
	bg_event 9, 10, 3, 7, 0x0003, 0x33, 0x00
	bg_event 28, 20, 3, 7, 0x0022, 0x40, 0x00
	bg_event 13, 16, 3, 7, 0x006F, 0x5A, 0x00
	bg_event 8, 42, 3, 7, 0x006F, 0x5B, 0x00
	.globl gMapEvents_ROUTE109
gMapEvents_ROUTE109: @ 0x085013E8
	map_events ROUTE109_EventObjects, ROUTE109_EventWarps, 0, ROUTE109_EventBgEvents
	.globl ROUTE110_EventObjects
ROUTE110_EventObjects: @ 0x085013FC
	object_event 1, 31, 0, 17, 90, 3, 8, 0, 0, 0, 0, Route110_EventScript_Boy2, 0x0000
	object_event 2, 56, 0, 29, 79, 4, 8, 0, 0, 0, 0, Route110_EventScript_CyclingGuy2, 0x0000
	object_event 3, 22, 0, 14, 69, 3, 3, 0, 1, 0, 0, Route110_EventScript_OldWoman, 0x0000
	object_event 4, 56, 0, 9, 57, 4, 2, 1, 1, 0, 0, Route110_EventScript_CyclingGuy1, 0x0000
	object_event 5, 21, 0, 10, 11, 3, 2, 1, 1, 0, 0, Route110_EventScript_OldMan, 0x0000
	object_event 6, 57, 0, 27, 24, 4, 2, 1, 3, 0, 0, Route110_EventScript_CyclingGirl1, 0x0000
	object_event 7, 13, 0, 15, 7, 3, 2, 1, 1, 0, 0, Route110_EventScript_Boy1, 0x0000
	object_event 8, 57, 0, 16, 73, 4, 49, 2, 14, 1, 3, Route110_EventScript_Jasmine, 0x0000
	object_event 9, 56, 0, 19, 31, 4, 51, 10, 1, 1, 3, Route110_EventScript_Anthony, 0x0000
	object_event 10, 57, 0, 30, 31, 4, 9, 1, 1, 1, 4, Route110_EventScript_Abigail, 0x0000
	object_event 11, 56, 0, 16, 55, 4, 45, 4, 4, 1, 3, Route110_EventScript_Benjamin, 0x0000
	object_event 12, 37, 0, 3, 39, 3, 10, 0, 0, 1, 6, Route110_EventScript_Edward, 0x0000
	object_event 13, 47, 0, 33, 15, 3, 9, 0, 0, 1, 1, Route110_EventScript_Jaclyn, 0x0000
	object_event 14, 39, 0, 34, 40, 3, 67, 0, 0, 1, 4, Route110_EventScript_Edwin, 0x0000
	object_event 15, 50, 0, 10, 19, 3, 8, 0, 0, 1, 1, Route110_EventScript_Dale, 0x0000
	object_event 16, 60, 0, 5, 11, 3, 12, 0, 0, 0, 16, 0x08244D23, 0x0000
	object_event 17, 60, 0, 6, 11, 3, 12, 0, 0, 0, 17, 0x08244D23, 0x0000
	object_event 18, 60, 0, 7, 11, 3, 12, 0, 0, 0, 18, 0x08244D23, 0x0000
	object_event 19, 59, 0, 30, 69, 3, 1, 0, 0, 0, 0, 0x08256AD8, 0x03EF
	object_event 20, 59, 0, 26, 47, 3, 1, 0, 0, 0, 0, 0x08256ACB, 0x03EE
	object_event 21, 56, 0, 27, 92, 3, 8, 0, 0, 0, 0, Route110_EventScript_ChallengeGuy, 0x0000
	object_event 22, 117, 0, 7, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_AquaGrunt1, 0x0384
	object_event 23, 117, 0, 8, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_AquaGrunt2, 0x0384
	object_event 24, 117, 0, 9, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_AquaGrunt3, 0x0384
	object_event 25, 117, 0, 10, 83, 3, 7, 0, 0, 0, 0, Route110_EventScript_AquaGrunt4, 0x0384
	object_event 26, 117, 0, 8, 82, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0384
	object_event 27, 56, 0, 21, 78, 4, 51, 7, 1, 1, 2, Route110_EventScript_Jacob, 0x0000
	object_event 28, 240, 0, 34, 54, 3, 14, 0, 0, 0, 0, 0x00000000, 0x0397
	object_event 29, 243, 0, 34, 54, 3, 8, 0, 0, 0, 0, 0x00000000, 0x039A
	object_event 30, 35, 0, 33, 69, 3, 14, 0, 0, 1, 3, Route110_EventScript_Timmy, 0x0000
	object_event 31, 18, 0, 10, 76, 3, 9, 0, 0, 1, 2, Route110_EventScript_Isabel, 0x0000
	object_event 32, 25, 0, 7, 76, 3, 10, 1, 1, 1, 2, Route110_EventScript_Kaleb, 0x0000
	object_event 33, 57, 0, 10, 39, 3, 9, 1, 1, 1, 6, Route110_EventScript_Alyssa, 0x0000
	object_event 34, 66, 0, 36, 40, 3, 66, 1, 1, 1, 3, Route110_EventScript_Joseph, 0x0000
	object_event 35, 59, 0, 6, 38, 3, 1, 1, 1, 0, 0, 0x08256AE5, 0x0475
	object_event 36, 64, 0, 9, 79, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0345
	.globl ROUTE110_EventWarps
ROUTE110_EventWarps: @ 0x0850175C
	warp_def 35, 24, 3, 0, MAP_NEW_MAUVILLE_ENTRANCE
	warp_def 11, 66, 0, 0, MAP_ROUTE110_TRICK_HOUSE_ENTRANCE
	warp_def 15, 16, 0, 0, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE
	warp_def 18, 16, 0, 2, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE
	warp_def 16, 88, 0, 0, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE
	warp_def 19, 88, 0, 2, MAP_ROUTE110_SEASIDE_CYCLING_ROAD_SOUTH_ENTRANCE
	.globl ROUTE110_EventCoordEvents
ROUTE110_EventCoordEvents: @ 0x0850178C
	coord_event 28, 92, 3, 16553, 2, Route110_EventScript_CyclingChallengeEnd
	coord_event 29, 92, 3, 16553, 2, Route110_EventScript_CyclingChallengeEnd
	coord_event 33, 56, 3, 16489, 0, Route110_EventScript_RivalTrigger1
	coord_event 34, 56, 3, 16489, 0, Route110_EventScript_RivalTrigger2
	coord_event 35, 56, 3, 16489, 0, Route110_EventScript_RivalTrigger3
	coord_event 7, 85, 3, 16602, 1, Route110_EventScript_BirchScene1
	coord_event 8, 85, 3, 16602, 1, Route110_EventScript_BirchScene2
	coord_event 9, 85, 3, 16602, 1, Route110_EventScript_BirchScene3
	coord_event 10, 85, 3, 16602, 1, Route110_EventScript_BirchScene4
	.globl ROUTE110_EventBgEvents
ROUTE110_EventBgEvents: @ 0x0850181C
	bg_event 15, 25, 0, 0, Route110_EventScript_VandalizedSign, 0, 0
	bg_event 9, 51, 0, 0, Route110_EventScript_SeasideParkingSign, 0, 0
	bg_event 14, 88, 0, 0, Route110_EventScript_CyclingRoadSign, 0, 0
	bg_event 20, 94, 0, 0, Route110_EventScript_SlateportCitySign, 0, 0
	bg_event 7, 79, 0, 0, Route110_EventScript_Route103Sign, 0, 0
	bg_event 3, 17, 0, 0, Route110_EventScript_MauvilleCitySign, 0, 0
	bg_event 16, 25, 0, 8, 0x00B5, 0x00, 0x00
	bg_event 17, 25, 0, 8, 0x00BF, 0x00, 0x00
	bg_event 33, 39, 3, 0, Route110_EventScript_TrainerTipsPrlzSleep, 0, 0
	bg_event 37, 70, 3, 0, Route110_EventScript_TrainerTipsRegisterItems, 0, 0
	bg_event 8, 67, 0, 0, Route110_EventScript_TrickHouseSign, 0, 0
	bg_event 32, 93, 0, 0, Route110_EventScript_CyclingRoadResultsSign, 0, 0
	bg_event 35, 39, 3, 7, 0x0018, 0x36, 0x00
	bg_event 33, 45, 3, 7, 0x0003, 0x35, 0x00
	bg_event 4, 35, 3, 7, 0x0004, 0x41, 0x00
	bg_event 37, 67, 3, 7, 0x0017, 0x37, 0x00
	bg_event 13, 16, 0, 0, Route110_EventScript_CyclingRoadSign, 0, 0
	.globl gMapEvents_ROUTE110
gMapEvents_ROUTE110: @ 0x085018E8
	map_events ROUTE110_EventObjects, ROUTE110_EventWarps, ROUTE110_EventCoordEvents, ROUTE110_EventBgEvents
	.globl ROUTE111_EventObjects
ROUTE111_EventObjects: @ 0x085018FC
	object_event 1, 19, 0, 13, 114, 3, 8, 0, 0, 0, 0, Route111_EventScript_Victor, 0x0300
	object_event 2, 18, 0, 13, 113, 0, 8, 0, 0, 0, 0, 0x00000000, 0x0301
	object_event 3, 47, 0, 13, 113, 0, 8, 1, 0, 0, 0, 0x00000000, 0x0302
	object_event 4, 22, 0, 13, 113, 0, 8, 0, 0, 0, 0, 0x00000000, 0x0303
	object_event 5, 32, 0, 28, 51, 3, 17, 0, 0, 1, 3, Route111_EventScript_Heidi, 0x0000
	object_event 6, 60, 0, 22, 5, 3, 12, 0, 0, 0, 19, 0x08244D23, 0x0000
	object_event 7, 60, 0, 23, 5, 3, 12, 0, 0, 0, 20, 0x08244D23, 0x0000
	object_event 8, 33, 0, 8, 91, 3, 2, 1, 1, 0, 0, Route111_EventScript_Man1, 0x0000
	object_event 9, 31, 0, 29, 37, 3, 17, 0, 0, 1, 3, Route111_EventScript_Drew, 0x0000
	object_event 10, 55, 0, 27, 69, 3, 50, 2, 2, 1, 2, Route111_EventScript_Dusty, 0x0000
	object_event 11, 31, 0, 21, 47, 3, 9, 0, 0, 1, 4, Route111_EventScript_Beau, 0x0000
	object_event 12, 32, 0, 32, 66, 3, 24, 0, 0, 1, 3, Route111_EventScript_Becky, 0x0000
	object_event 13, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x0825420E, 0x031C
	object_event 14, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x082541EE, 0x031C
	object_event 15, 86, 0, 18, 101, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0011
	object_event 16, 86, 0, 19, 100, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0012
	object_event 17, 8, 0, 23, 8, 3, 5, 1, 0, 0, 0, Route111_EventScript_Girl, 0x0000
	object_event 18, 59, 0, 33, 104, 3, 1, 0, 0, 0, 0, 0x08256AF2, 0x03F0
	object_event 19, 60, 0, 18, 5, 3, 12, 0, 0, 0, 80, 0x08244D23, 0x0000
	object_event 20, 60, 0, 19, 5, 3, 12, 0, 0, 0, 81, 0x08244D23, 0x0000
	object_event 21, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x082542AE, 0x031F
	object_event 22, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x082542CE, 0x031F
	object_event 23, 68, 0, 13, 86, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0387
	object_event 24, 110, 0, 14, 86, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0387
	object_event 25, 59, 0, 12, 54, 3, 1, 0, 0, 0, 0, 0x08256AFF, 0x03F1
	object_event 26, 59, 0, 3, 114, 3, 1, 0, 0, 0, 0, 0x08256B0C, 0x03F2
	object_event 27, 82, 0, 22, 21, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0013
	object_event 28, 32, 0, 10, 82, 3, 14, 0, 0, 1, 2, Route111_EventScript_Irene, 0x0000
	object_event 29, 31, 0, 11, 71, 3, 22, 0, 0, 1, 3, Route111_EventScript_Travis, 0x0000
	object_event 30, 44, 0, 32, 29, 3, 28, 1, 0, 1, 2, Route111_EventScript_Daisuke, 0x0000
	object_event 31, 34, 0, 11, 11, 3, 7, 4, 0, 1, 4, Route111_EventScript_Brooke, 0x0000
	object_event 32, 33, 0, 9, 27, 3, 17, 0, 0, 1, 3, Route111_EventScript_Wilton, 0x0000
	object_event 33, 7, 0, 13, 20, 3, 7, 1, 1, 0, 0, 0x08246512, 0x03C0
	object_event 34, 65, 0, 20, 114, 3, 2, 1, 1, 0, 0, Route111_EventScript_Man2, 0x0000
	object_event 35, 31, 0, 26, 132, 3, 9, 1, 1, 1, 5, Route111_EventScript_Tyron, 0x0000
	object_event 36, 20, 0, 20, 132, 3, 10, 1, 1, 1, 5, Route111_EventScript_Celina, 0x0000
	object_event 37, 32, 0, 19, 121, 3, 7, 1, 1, 1, 2, Route111_EventScript_Bianca, 0x0000
	object_event 38, 66, 0, 16, 119, 3, 10, 1, 1, 1, 3, Route111_EventScript_Hayden, 0x0000
	object_event 39, 55, 0, 29, 77, 3, 14, 1, 1, 1, 7, Route111_EventScript_Bryan, 0x0000
	object_event 40, 32, 0, 22, 77, 3, 10, 1, 1, 1, 6, Route111_EventScript_Celia, 0x0000
	object_event 41, 31, 0, 37, 77, 3, 9, 1, 1, 1, 7, Route111_EventScript_Branden, 0x0000
	object_event 42, 59, 0, 19, 118, 3, 1, 1, 1, 0, 0, 0x08256B19, 0x0476
	object_event 43, 55, 0, 14, 56, 3, 16, 1, 1, 0, 0, Route111_EventScript_Hiker, 0x0000
	object_event 44, 199, 0, 20, 53, 3, 8, 1, 1, 0, 0, 0x00000000, 0x036C
	object_event 45, 240, 0, 19, 53, 3, 8, 1, 1, 0, 0, 0x00000000, 0x036B
	object_event 46, 17, 0, 19, 101, 3, 7, 1, 1, 0, 0, Route111_EventScript_RockSmashTipFatMan, 0x034B
	.globl ROUTE111_EventWarps
ROUTE111_EventWarps: @ 0x08501D4C
	warp_def 13, 113, 0, 0, MAP_ROUTE111_WINSTRATE_FAMILYS_HOUSE
	warp_def 29, 87, 0, 0, MAP_DESERT_RUINS
	warp_def 26, 18, 0, 0, MAP_ROUTE111_OLD_LADYS_REST_STOP
	warp_def 19, 58, 0, 0, MAP_MIRAGE_TOWER_1F
	warp_def 31, 113, 0, 0, MAP_TRAINER_HILL_ENTRANCE
	.globl ROUTE111_EventCoordEvents
ROUTE111_EventCoordEvents: @ 0x08501D74
	coord_event 12, 62, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 11, 61, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerDown
	coord_event 12, 61, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerDown
	coord_event 13, 61, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerDown
	coord_event 7, 63, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 12, 44, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 13, 43, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 14, 42, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 16, 40, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 14, 61, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerDown
	coord_event 18, 32, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 17, 31, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 9, 37, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 10, 36, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 17, 39, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 18, 38, 3, 16387, 0, Route111_EventScript_ViciousSandstormTriggerLeft
	coord_event 8, 64, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 9, 65, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 10, 65, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 11, 66, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 12, 67, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 13, 68, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 14, 69, 3, 0, 0, Route111_EventScript_SunTrigger
	coord_event 10, 61, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 11, 62, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 13, 62, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 14, 62, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 17, 38, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 16, 39, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 15, 40, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 14, 41, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 13, 42, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 12, 43, 3, 0, 0, Route111_EventScript_SandstormTrigger
	coord_event 11, 44, 3, 0, 0, Route111_EventScript_SandstormTrigger
	.globl ROUTE111_EventBgEvents
ROUTE111_EventBgEvents: @ 0x08501F94
	bg_event 16, 114, 0, 0, Route111_EventScript_WinstrateHouseSign, 0, 0
	bg_event 24, 126, 0, 0, Route111_EventScript_RouteSignMauville, 0, 0
	bg_event 7, 66, 0, 0, Route111_EventScript_RouteSign112, 0, 0
	bg_event 13, 6, 0, 0, Route111_EventScript_RouteSign113, 0, 0
	bg_event 24, 36, 0, 8, 0x0083, 0x00, 0x00
	bg_event 34, 50, 0, 8, 0x008D, 0x00, 0x00
	bg_event 33, 34, 0, 8, 0x0079, 0x00, 0x00
	bg_event 25, 19, 0, 0, Route111_EventScript_OldLadysRestStopSign, 0, 0
	bg_event 35, 1, 0, 8, 0x000D, 0x00, 0x00
	bg_event 35, 31, 0, 8, 0x0099, 0x00, 0x00
	bg_event 26, 70, 0, 7, 0x006C, 0x02, 0x00
	bg_event 27, 27, 3, 8, 0x0021, 0x00, 0x00
	bg_event 7, 84, 3, 0, Route111_EventScript_TrainerTipsSpAtkSpDef, 0, 0
	bg_event 14, 19, 0, 8, 0x00A4, 0x00, 0x00
	bg_event 13, 19, 0, 8, 0x00A1, 0x00, 0x00
	bg_event 19, 55, 0, 7, 0x0040, 0x38, 0x00
	bg_event 35, 66, 0, 7, 0x0044, 0x39, 0x00
	bg_event 24, 116, 0, 0, Route111_EventScript_TrainerHillSign, 0, 0
	.globl gMapEvents_ROUTE111
gMapEvents_ROUTE111: @ 0x0850206C
	map_events ROUTE111_EventObjects, ROUTE111_EventWarps, ROUTE111_EventCoordEvents, ROUTE111_EventBgEvents
	.globl ROUTE112_EventObjects
ROUTE112_EventObjects: @ 0x08502080
	object_event 1, 119, 0, 26, 30, 3, 7, 1, 1, 0, 0, Route112_EventScript_MagmaGrunts, 0x0333
	object_event 2, 55, 0, 24, 34, 3, 14, 0, 0, 1, 2, Route112_EventScript_Brice, 0x0000
	object_event 3, 31, 0, 29, 49, 3, 8, 0, 0, 1, 3, Route112_EventScript_Larry, 0x0000
	object_event 4, 32, 0, 22, 46, 3, 23, 0, 0, 1, 3, Route112_EventScript_Carol, 0x0000
	object_event 5, 55, 0, 15, 40, 3, 16, 0, 0, 1, 3, Route112_EventScript_Trent, 0x0000
	object_event 6, 119, 0, 27, 30, 3, 7, 0, 0, 0, 0, Route112_EventScript_MagmaGrunts, 0x0333
	object_event 7, 60, 0, 27, 6, 0, 12, 0, 0, 0, 24, 0x08244D23, 0x0000
	object_event 8, 60, 0, 28, 6, 0, 12, 0, 0, 0, 23, 0x08244D23, 0x0000
	object_event 9, 60, 0, 29, 6, 0, 12, 0, 0, 0, 22, 0x08244D23, 0x0000
	object_event 10, 60, 0, 30, 6, 3, 12, 0, 0, 0, 21, 0x08244D23, 0x0000
	object_event 11, 55, 0, 8, 50, 3, 26, 0, 3, 0, 0, Route112_EventScript_Hiker, 0x0000
	object_event 12, 59, 0, 14, 43, 3, 1, 0, 0, 0, 0, 0x08256B26, 0x03F3
	object_event 13, 66, 0, 31, 7, 3, 18, 1, 1, 1, 3, Route112_EventScript_Bryant, 0x0000
	object_event 14, 20, 0, 31, 11, 3, 15, 1, 1, 1, 3, Route112_EventScript_Shayla, 0x0000
	.globl ROUTE112_EventWarps
ROUTE112_EventWarps: @ 0x085021D0
	warp_def 28, 27, 0, 0, MAP_ROUTE112_CABLE_CAR_STATION
	warp_def 29, 27, 0, 1, MAP_ROUTE112_CABLE_CAR_STATION
	warp_def 6, 46, 3, 0, MAP_JAGGED_PASS
	warp_def 7, 46, 3, 1, MAP_JAGGED_PASS
	warp_def 11, 36, 0, 0, MAP_FIERY_PATH
	warp_def 22, 10, 0, 1, MAP_FIERY_PATH
	.globl ROUTE112_EventBgEvents
ROUTE112_EventBgEvents: @ 0x08502200
	bg_event 19, 44, 3, 0, Route112_EventScript_MtChimneySign, 0, 0
	bg_event 22, 37, 0, 0, Route112_EventScript_MtChimneyCableCarSign, 0, 0
	bg_event 4, 49, 0, 0, Route112_EventScript_RouteSignLavaridge, 0, 0
	.globl gMapEvents_ROUTE112
gMapEvents_ROUTE112: @ 0x08502224
	map_events ROUTE112_EventObjects, ROUTE112_EventWarps, 0, ROUTE112_EventBgEvents
	.globl ROUTE113_EventObjects
ROUTE113_EventObjects: @ 0x08502238
	object_event 1, 5, 0, 66, 12, 3, 5, 1, 0, 0, 0, Route113_EventScript_NinjaBoy, 0x0000
	object_event 2, 48, 0, 36, 10, 3, 3, 0, 1, 0, 0, Route113_EventScript_Gentleman, 0x0000
	object_event 3, 35, 0, 62, 8, 3, 8, 0, 0, 1, 3, Route113_EventScript_Jaylen, 0x0000
	object_event 4, 35, 0, 21, 11, 3, 17, 0, 0, 1, 3, Route113_EventScript_Dillon, 0x0000
	object_event 5, 34, 0, 51, 11, 3, 23, 0, 0, 1, 2, Route113_EventScript_Madeline, 0x0000
	object_event 6, 59, 0, 53, 7, 3, 1, 0, 0, 0, 0, 0x08256B33, 0x03F4
	object_event 7, 59, 0, 79, 5, 3, 1, 0, 0, 0, 0, 0x08256B40, 0x03F5
	object_event 8, 5, 0, 29, 6, 3, 63, 0, 0, 3, 1, Route113_EventScript_Lao, 0x0000
	object_event 9, 5, 0, 71, 2, 3, 63, 0, 0, 3, 1, Route113_EventScript_Lung, 0x0000
	object_event 10, 6, 0, 45, 6, 3, 8, 1, 1, 1, 1, Route113_EventScript_Tori, 0x0000
	object_event 11, 6, 0, 46, 6, 3, 8, 1, 1, 1, 1, Route113_EventScript_Tia, 0x0000
	object_event 12, 59, 0, 15, 15, 3, 1, 1, 1, 0, 0, 0x08256B4D, 0x0477
	object_event 13, 39, 0, 75, 3, 3, 9, 1, 1, 1, 4, Route113_EventScript_Wyatt, 0x0000
	object_event 14, 31, 0, 71, 4, 3, 7, 1, 1, 1, 1, Route113_EventScript_Lawrence, 0x0000
	object_event 15, 32, 0, 7, 6, 3, 26, 1, 3, 1, 6, Route113_EventScript_Sophie, 0x0000
	object_event 16, 66, 0, 7, 13, 3, 25, 1, 3, 1, 6, Route113_EventScript_Coby, 0x0000
	.globl ROUTE113_EventWarps
ROUTE113_EventWarps: @ 0x085023B8
	warp_def 33, 5, 0, 0, MAP_ROUTE113_GLASS_WORKSHOP
	warp_def 41, 12, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 88, 5, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE113_EventCoordEvents
ROUTE113_EventCoordEvents: @ 0x085023D0
	coord_event 19, 11, 3, 8, 0, 0x00000000
	coord_event 19, 10, 3, 8, 0, 0x00000000
	coord_event 19, 12, 3, 8, 0, 0x00000000
	coord_event 19, 13, 3, 8, 0, 0x00000000
	coord_event 86, 9, 3, 8, 0, 0x00000000
	coord_event 85, 10, 3, 8, 0, 0x00000000
	coord_event 85, 11, 3, 8, 0, 0x00000000
	coord_event 14, 10, 3, 2, 0, 0x00000000
	coord_event 14, 11, 3, 2, 0, 0x00000000
	coord_event 14, 12, 3, 2, 0, 0x00000000
	coord_event 14, 13, 3, 2, 0, 0x00000000
	coord_event 94, 8, 3, 2, 0, 0x00000000
	coord_event 94, 9, 3, 2, 0, 0x00000000
	coord_event 94, 10, 3, 2, 0, 0x00000000
	coord_event 94, 11, 0, 2, 0, 0x00000000
	coord_event 19, 14, 3, 8, 0, 0x00000000
	coord_event 87, 8, 3, 8, 0, 0x00000000
	coord_event 87, 6, 3, 8, 0, 0x00000000
	coord_event 87, 7, 3, 8, 0, 0x00000000
	.globl ROUTE113_EventBgEvents
ROUTE113_EventBgEvents: @ 0x08502500
	bg_event 85, 6, 0, 0, Route113_EventScript_RouteSign111, 0, 0
	bg_event 12, 9, 0, 0, Route113_EventScript_RouteSignFallarbor, 0, 0
	bg_event 58, 4, 3, 0, Route113_EventScript_TrainerTipsRegisterKeyItems, 0, 0
	bg_event 31, 5, 0, 0, Route113_EventScript_GlassWorkshopSign, 0, 0
	bg_event 49, 8, 3, 8, 0x0003, 0x00, 0x00
	bg_event 66, 3, 3, 7, 0x0022, 0x03, 0x00
	bg_event 22, 5, 3, 7, 0x0140, 0x1E, 0x00
	bg_event 73, 3, 3, 7, 0x006E, 0x62, 0x00
	.globl gMapEvents_ROUTE113
gMapEvents_ROUTE113: @ 0x08502560
	map_events ROUTE113_EventObjects, ROUTE113_EventWarps, ROUTE113_EventCoordEvents, ROUTE113_EventBgEvents
	.globl ROUTE114_EventObjects
ROUTE114_EventObjects: @ 0x08502574
	object_event 1, 60, 0, 31, 43, 3, 12, 0, 0, 0, 77, 0x08244D23, 0x0000
	object_event 2, 60, 0, 31, 44, 3, 12, 0, 0, 0, 78, 0x08244D23, 0x0000
	object_event 3, 55, 0, 15, 65, 7, 10, 0, 0, 1, 6, Route114_EventScript_Lenny, 0x0000
	object_event 4, 55, 0, 30, 72, 5, 9, 0, 0, 1, 4, Route114_EventScript_Lucas, 0x0000
	object_event 5, 31, 0, 22, 50, 3, 10, 0, 0, 1, 3, Route114_EventScript_Shane, 0x0000
	object_event 6, 32, 0, 19, 35, 3, 1, 0, 0, 1, 3, Route114_EventScript_Nancy, 0x0000
	object_event 7, 39, 0, 20, 56, 3, 7, 0, 0, 1, 3, Route114_EventScript_Steve, 0x0000
	object_event 8, 60, 0, 31, 45, 3, 12, 0, 0, 0, 68, 0x08244D23, 0x0000
	object_event 9, 59, 0, 7, 6, 3, 1, 0, 0, 0, 0, 0x08256B5A, 0x03F6
	object_event 10, 59, 0, 11, 37, 4, 1, 0, 0, 0, 0, 0x08256B67, 0x03F7
	object_event 11, 86, 0, 12, 43, 4, 1, 0, 0, 0, 0, 0x0825667C, 0x0011
	object_event 12, 48, 0, 19, 11, 3, 10, 0, 0, 0, 0, Route114_EventScript_RoarGentleman, 0x0000
	object_event 13, 220, 0, 19, 12, 3, 10, 0, 0, 0, 0, Route114_EventScript_Poochyena, 0x0000
	object_event 14, 65, 0, 27, 42, 3, 3, 0, 1, 0, 0, Route114_EventScript_Man, 0x0000
	object_event 15, 50, 0, 25, 6, 3, 8, 0, 0, 1, 0, Route114_EventScript_Nolan, 0x0000
	object_event 16, 50, 0, 19, 26, 3, 9, 0, 0, 1, 0, Route114_EventScript_Claude, 0x0000
	object_event 17, 66, 0, 30, 58, 5, 23, 0, 0, 1, 3, Route114_EventScript_Bernie, 0x0000
	object_event 18, 86, 0, 29, 53, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0012
	object_event 19, 86, 0, 30, 54, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0013
	object_event 20, 86, 0, 22, 69, 7, 1, 1, 1, 0, 0, 0x0825667C, 0x0014
	object_event 21, 86, 0, 11, 64, 5, 1, 1, 1, 0, 0, 0x0825667C, 0x0015
	object_event 22, 47, 0, 24, 44, 3, 8, 1, 1, 1, 1, Route114_EventScript_Ivy, 0x0000
	object_event 23, 47, 0, 23, 44, 3, 8, 1, 1, 1, 1, Route114_EventScript_Tyra, 0x0000
	object_event 24, 32, 0, 28, 20, 3, 7, 1, 1, 1, 3, Route114_EventScript_Charlotte, 0x0000
	object_event 25, 32, 0, 26, 72, 5, 18, 1, 1, 1, 4, Route114_EventScript_Angelina, 0x0000
	object_event 26, 59, 0, 31, 19, 3, 1, 1, 1, 0, 0, 0x08256B74, 0x0488
	object_event 27, 50, 0, 28, 16, 3, 17, 1, 1, 1, 3, Route114_EventScript_Kai, 0x0000
	.globl ROUTE114_EventWarps
ROUTE114_EventWarps: @ 0x085027FC
	warp_def 8, 63, 0, 0, MAP_METEOR_FALLS_1F_1R
	warp_def 29, 5, 0, 0, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 27, 36, 0, 0, MAP_ROUTE114_LANETTES_HOUSE
	warp_def 6, 46, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 7, 4, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE114_EventBgEvents
ROUTE114_EventBgEvents: @ 0x08502824
	bg_event 7, 64, 0, 0, Route114_EventScript_MeteorFallsSign, 0, 0
	bg_event 31, 7, 0, 0, Route114_EventScript_FossilManiacsHouseSign, 0, 0
	bg_event 9, 47, 0, 8, 0x0029, 0x00, 0x00
	bg_event 30, 51, 0, 8, 0x0033, 0x00, 0x00
	bg_event 11, 62, 0, 8, 0x003D, 0x00, 0x00
	bg_event 19, 70, 0, 8, 0x0047, 0x00, 0x00
	bg_event 11, 27, 0, 8, 0x00B6, 0x00, 0x00
	bg_event 12, 27, 0, 8, 0x00C0, 0x00, 0x00
	bg_event 25, 38, 3, 0, Route114_EventScript_LanettesHouseSign, 0, 0
	bg_event 20, 57, 3, 7, 0x0042, 0x04, 0x00
	bg_event 32, 57, 0, 8, 0x0049, 0x00, 0x00
	bg_event 7, 30, 3, 7, 0x0018, 0x2A, 0x00
	.globl gMapEvents_ROUTE114
gMapEvents_ROUTE114: @ 0x085028B4
	map_events ROUTE114_EventObjects, ROUTE114_EventWarps, 0, ROUTE114_EventBgEvents
	.globl ROUTE115_EventObjects
ROUTE115_EventObjects: @ 0x085028C8
	object_event 1, 20, 0, 18, 68, 3, 2, 1, 1, 0, 0, Route115_EventScript_Woman, 0x0000
	object_event 2, 21, 0, 5, 15, 3, 10, 0, 0, 1, 6, Route115_EventScript_Timothy, 0x0000
	object_event 3, 44, 0, 27, 53, 3, 15, 1, 1, 1, 4, Route115_EventScript_Nob, 0x0000
	object_event 4, 60, 0, 12, 5, 3, 12, 0, 0, 0, 69, 0x08244D23, 0x0000
	object_event 5, 60, 0, 13, 5, 3, 12, 0, 0, 0, 70, 0x08244D23, 0x0000
	object_event 6, 60, 0, 14, 5, 3, 12, 0, 0, 0, 71, 0x08244D23, 0x0000
	object_event 7, 14, 0, 15, 50, 3, 64, 0, 0, 1, 3, Route115_EventScript_Cyndy, 0x0000
	object_event 8, 44, 0, 19, 15, 3, 27, 5, 0, 1, 2, Route115_EventScript_Koichi, 0x0000
	object_event 9, 39, 0, 24, 62, 3, 18, 0, 0, 1, 4, Route115_EventScript_Hector, 0x0000
	object_event 10, 59, 0, 20, 60, 3, 1, 0, 0, 0, 0, 0x08256B81, 0x03F8
	object_event 11, 59, 0, 18, 7, 3, 1, 0, 0, 0, 0, 0x08256B8E, 0x03F9
	object_event 12, 59, 0, 23, 29, 3, 1, 0, 0, 0, 0, 0x08256B9B, 0x03FA
	object_event 13, 60, 0, 31, 64, 3, 12, 0, 0, 0, 55, 0x08244D23, 0x0000
	object_event 14, 60, 0, 31, 65, 3, 12, 0, 0, 0, 56, 0x08244D23, 0x0000
	object_event 15, 86, 0, 29, 50, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0011
	object_event 16, 59, 0, 31, 56, 3, 1, 1, 1, 0, 0, 0x08256BA8, 0x045E
	object_event 17, 52, 0, 10, 15, 3, 46, 3, 3, 1, 2, Route115_EventScript_Kyra, 0x0000
	object_event 18, 5, 0, 11, 12, 3, 57, 1, 1, 1, 3, Route115_EventScript_Jaiden, 0x0000
	object_event 19, 14, 0, 15, 7, 3, 9, 1, 1, 1, 4, Route115_EventScript_Helene, 0x0000
	object_event 20, 47, 0, 10, 7, 3, 10, 1, 1, 1, 4, Route115_EventScript_Alix, 0x0000
	object_event 21, 47, 0, 28, 62, 3, 9, 1, 1, 1, 4, Route115_EventScript_Marlene, 0x0000
	object_event 22, 59, 0, 26, 67, 3, 1, 1, 1, 0, 0, 0x08256BC2, 0x0489
	object_event 23, 59, 0, 12, 14, 3, 1, 1, 1, 0, 0, 0x08256BB5, 0x0478
	.globl ROUTE115_EventWarps
ROUTE115_EventWarps: @ 0x08502AF0
	warp_def 27, 37, 0, 1, MAP_METEOR_FALLS_1F_1R
	warp_def 21, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 36, 10, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE115_EventBgEvents
ROUTE115_EventBgEvents: @ 0x08502B08
	bg_event 32, 6, 0, 8, 0x0048, 0x00, 0x00
	bg_event 21, 18, 0, 8, 0x003E, 0x00, 0x00
	bg_event 16, 64, 0, 0, Route115_EventScript_RouteSignRustboro, 0, 0
	bg_event 25, 38, 3, 0, Route115_EventScript_MeteorFallsSign, 0, 0
	bg_event 8, 30, 0, 8, 0x0085, 0x00, 0x00
	bg_event 32, 39, 0, 8, 0x002A, 0x00, 0x00
	bg_event 26, 15, 0, 8, 0x0034, 0x00, 0x00
	bg_event 23, 8, 0, 8, 0x002B, 0x00, 0x00
	bg_event 32, 46, 0, 8, 0x0035, 0x00, 0x00
	bg_event 7, 20, 0, 8, 0x00AE, 0x00, 0x00
	bg_event 8, 20, 0, 8, 0x00B7, 0x00, 0x00
	bg_event 25, 24, 0, 8, 0x003F, 0x00, 0x00
	bg_event 20, 53, 0, 8, 0x0015, 0x00, 0x00
	bg_event 15, 49, 3, 7, 0x006F, 0x61, 0x00
	.globl gMapEvents_ROUTE115
gMapEvents_ROUTE115: @ 0x08502BB0
	map_events ROUTE115_EventObjects, ROUTE115_EventWarps, 0, ROUTE115_EventBgEvents
	.globl ROUTE116_EventObjects
ROUTE116_EventObjects: @ 0x08502BC4
	object_event 1, 60, 0, 18, 2, 3, 12, 0, 0, 0, 25, 0x08244D23, 0x0000
	object_event 2, 60, 0, 19, 2, 3, 12, 0, 0, 0, 26, 0x08244D23, 0x0000
	object_event 3, 35, 0, 12, 7, 3, 16, 0, 0, 1, 3, Route116_EventScript_Joey, 0x0000
	object_event 4, 82, 0, 21, 6, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 5, 82, 0, 32, 10, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 6, 36, 0, 13, 17, 3, 24, 0, 0, 1, 2, Route116_EventScript_Jose, 0x0000
	object_event 7, 59, 0, 19, 6, 3, 1, 0, 0, 0, 0, 0x08256BDC, 0x03FB
	object_event 8, 59, 0, 10, 17, 3, 1, 0, 0, 0, 0, 0x08256BE9, 0x03FC
	object_event 9, 60, 0, 20, 2, 3, 12, 0, 0, 0, 66, 0x08244D23, 0x0000
	object_event 10, 60, 0, 21, 2, 3, 12, 0, 0, 0, 67, 0x08244D23, 0x0000
	object_event 11, 21, 0, 46, 9, 3, 1, 0, 0, 0, 0, Route116_EventScript_Briney, 0x037B
	object_event 12, 82, 0, 28, 11, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0013
	object_event 13, 55, 0, 36, 17, 3, 15, 0, 0, 1, 3, Route116_EventScript_Clark, 0x0000
	object_event 14, 82, 0, 24, 9, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0014
	object_event 15, 59, 0, 80, 8, 3, 1, 0, 0, 0, 0, 0x08256BF6, 0x03FD
	object_event 16, 47, 0, 26, 6, 3, 10, 0, 0, 1, 2, Route116_EventScript_Janice, 0x0000
	object_event 17, 14, 0, 22, 16, 3, 13, 0, 0, 1, 3, Route116_EventScript_Karen, 0x0000
	object_event 18, 38, 0, 28, 8, 3, 7, 0, 0, 1, 4, Route116_EventScript_Jerry, 0x0000
	object_event 19, 23, 0, 46, 11, 3, 1, 1, 1, 0, 0, Route116_EventScript_DevonEmployee, 0x03B3
	object_event 20, 59, 0, 55, 12, 4, 1, 1, 1, 0, 0, 0x08256BCF, 0x03E9
	object_event 21, 44, 0, 38, 9, 3, 10, 1, 1, 0, 0, Route116_EventScript_WandasBoyfriend, 0x037E
	object_event 22, 39, 0, 74, 13, 3, 1, 1, 1, 0, 0, Route116_EventScript_GlassesMan, 0x032D
	object_event 23, 20, 0, 33, 8, 3, 7, 0, 0, 1, 1, Route116_EventScript_Sarah, 0x0000
	object_event 24, 9, 0, 33, 5, 3, 8, 0, 0, 1, 2, Route116_EventScript_Dawson, 0x0000
	object_event 25, 59, 0, 34, 7, 0, 1, 1, 1, 0, 0, 0x08256C03, 0x047A
	object_event 26, 82, 0, 30, 5, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0015
	object_event 27, 35, 0, 36, 13, 3, 18, 1, 1, 1, 5, Route116_EventScript_Johnson, 0x0000
	object_event 28, 55, 0, 42, 13, 3, 9, 1, 1, 1, 5, Route116_EventScript_Devan, 0x0000
	.globl ROUTE116_EventWarps
ROUTE116_EventWarps: @ 0x08502E64
	warp_def 47, 8, 0, 0, MAP_RUSTURF_TUNNEL
	warp_def 38, 8, 0, 0, MAP_ROUTE116_TUNNELERS_REST_HOUSE
	warp_def 65, 10, 0, 2, MAP_RUSTURF_TUNNEL
	warp_def 59, 13, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 79, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE116_EventCoordEvents
ROUTE116_EventCoordEvents: @ 0x08502E8C
	coord_event 47, 9, 3, 16495, 1, Route116_EventScript_BrineyTrigger
	.globl ROUTE116_EventBgEvents
ROUTE116_EventBgEvents: @ 0x08502E9C
	bg_event 5, 10, 0, 0, Route116_EventScript_RouteSignRustboro, 0, 0
	bg_event 48, 9, 0, 0, Route116_EventScript_RusturfTunnelSign, 0, 0
	bg_event 40, 9, 0, 0, Route116_EventScript_TunnelersRestHouseSign, 0, 0
	bg_event 71, 4, 0, 8, 0x0051, 0x00, 0x00
	bg_event 79, 11, 0, 8, 0x005B, 0x00, 0x00
	bg_event 16, 12, 0, 0, Route116_EventScript_TrainerTipsBToStopEvolution, 0, 0
	bg_event 29, 10, 0, 0, Route116_EventScript_TrainerTipsBagHasPockets, 0, 0
	bg_event 56, 6, 0, 8, 0x0066, 0x00, 0x00
	bg_event 55, 15, 0, 8, 0x0070, 0x00, 0x00
	bg_event 22, 9, 3, 7, 0x0016, 0x2D, 0x00
	bg_event 70, 13, 3, 7, 0x00CE, 0x60, 0x00
	.globl gMapEvents_ROUTE116
gMapEvents_ROUTE116: @ 0x08502F20
	map_events ROUTE116_EventObjects, ROUTE116_EventWarps, ROUTE116_EventCoordEvents, ROUTE116_EventBgEvents
	.globl ROUTE117_EventObjects
ROUTE117_EventObjects: @ 0x08502F34
	object_event 1, 16, 0, 13, 13, 3, 8, 0, 0, 0, 0, Route117_EventScript_Woman, 0x0000
	object_event 2, 11, 0, 25, 5, 3, 40, 2, 2, 0, 0, Route117_EventScript_LittleBoy, 0x0000
	object_event 3, 29, 0, 47, 4, 3, 8, 0, 0, 0, 0, 0x082576E1, 0x0000
	object_event 4, 208, 0, 33, 3, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 5, 204, 0, 39, 4, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 6, 210, 0, 42, 2, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 7, 209, 0, 49, 2, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 8, 51, 0, 38, 16, 3, 28, 8, 0, 1, 4, Route117_EventScript_Dylan, 0x0000
	object_event 9, 20, 0, 8, 10, 3, 23, 0, 0, 1, 3, Route117_EventScript_Lydia, 0x0000
	object_event 10, 65, 0, 33, 11, 3, 16, 0, 0, 1, 4, Route117_EventScript_Isaac, 0x0000
	object_event 11, 60, 0, 41, 13, 3, 12, 0, 0, 0, 29, 0x08244D23, 0x0000
	object_event 12, 60, 0, 42, 13, 3, 12, 0, 0, 0, 28, 0x08244D23, 0x0000
	object_event 13, 60, 0, 43, 13, 3, 12, 0, 0, 0, 27, 0x08244D23, 0x0000
	object_event 14, 59, 0, 16, 18, 3, 1, 0, 0, 0, 0, 0x08256C10, 0x03FE
	object_event 15, 82, 0, 15, 2, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 16, 59, 0, 9, 1, 3, 1, 0, 0, 0, 0, 0x08256C1D, 0x03FF
	object_event 17, 52, 0, 26, 13, 3, 33, 2, 2, 1, 5, Route117_EventScript_Maria, 0x0000
	object_event 18, 39, 0, 17, 12, 3, 7, 1, 1, 1, 4, Route117_EventScript_Derek, 0x0000
	object_event 19, 47, 0, 43, 6, 3, 8, 0, 0, 1, 1, Route117_EventScript_Meg, 0x0000
	object_event 20, 47, 0, 42, 6, 3, 8, 0, 0, 1, 1, Route117_EventScript_Anna, 0x0000
	object_event 21, 10, 0, 48, 10, 3, 2, 1, 1, 0, 0, Route117_EventScript_Girl, 0x0000
	object_event 22, 47, 0, 15, 4, 3, 10, 1, 1, 1, 4, Route117_EventScript_Brandi, 0x0000
	object_event 23, 14, 0, 21, 4, 3, 9, 1, 1, 1, 4, Route117_EventScript_Aisha, 0x0000
	object_event 24, 52, 0, 16, 4, 3, 28, 4, 1, 1, 4, Route117_EventScript_Melina, 0x0000
	.globl ROUTE117_EventWarps
ROUTE117_EventWarps: @ 0x08503174
	warp_def 51, 5, 0, 0, MAP_ROUTE117_POKEMON_DAY_CARE
	.globl ROUTE117_EventBgEvents
ROUTE117_EventBgEvents: @ 0x0850317C
	bg_event 16, 6, 0, 0, Route117_EventScript_RouteSignVerdanturf, 0, 0
	bg_event 49, 12, 0, 0, Route117_EventScript_RouteSignMauville, 0, 0
	bg_event 49, 5, 0, 0, Route117_EventScript_DayCareSign, 0, 0
	bg_event 3, 18, 3, 7, 0x0056, 0x48, 0x00
	.globl gMapEvents_ROUTE117
gMapEvents_ROUTE117: @ 0x085031AC
	map_events ROUTE117_EventObjects, ROUTE117_EventWarps, 0, ROUTE117_EventBgEvents
	.globl ROUTE118_EventObjects
ROUTE118_EventObjects: @ 0x085031C0
	object_event 1, 60, 0, 35, 5, 3, 12, 0, 0, 0, 31, 0x08244D23, 0x0000
	object_event 2, 60, 0, 36, 5, 3, 12, 0, 0, 0, 32, 0x08244D23, 0x0000
	object_event 3, 60, 0, 37, 5, 3, 12, 0, 0, 0, 33, 0x08244D23, 0x0000
	object_event 4, 66, 0, 64, 10, 3, 8, 0, 0, 1, 3, Route118_EventScript_Perry, 0x0000
	object_event 5, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x0825422E, 0x031D
	object_event 6, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825424E, 0x031D
	object_event 7, 10, 0, 12, 10, 3, 2, 1, 1, 0, 0, Route118_EventScript_Girl, 0x0000
	object_event 8, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x082542EE, 0x0385
	object_event 9, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825430E, 0x0385
	object_event 10, 68, 0, 33, 8, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0388
	object_event 11, 110, 0, 34, 8, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0388
	object_event 12, 82, 0, 38, 8, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 13, 50, 0, 28, 8, 3, 9, 0, 0, 0, 0, Route118_EventScript_GoodRodFisherman, 0x0000
	object_event 14, 20, 0, 7, 12, 3, 7, 0, 0, 1, 4, Route118_EventScript_Rose, 0x0000
	object_event 15, 50, 0, 14, 14, 3, 8, 0, 0, 1, 0, Route118_EventScript_Wade, 0x0000
	object_event 16, 66, 0, 56, 7, 3, 16, 0, 0, 1, 3, Route118_EventScript_Chester, 0x0000
	object_event 17, 50, 0, 39, 15, 3, 1, 0, 0, 1, 2, Route118_EventScript_Barny, 0x0000
	object_event 18, 66, 0, 17, 11, 3, 15, 1, 1, 1, 3, Route118_EventScript_Dalton, 0x0000
	object_event 19, 134, 0, 44, 7, 3, 8, 1, 1, 0, 0, 0x00000000, 0x03C6
	object_event 20, 59, 0, 69, 7, 3, 1, 1, 1, 0, 0, 0x08256C2A, 0x0461
	object_event 21, 35, 0, 7, 7, 3, 8, 1, 1, 1, 4, Route118_EventScript_Deandre, 0x0000
	.globl ROUTE118_EventWarps
ROUTE118_EventWarps: @ 0x085033B8
	warp_def 42, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	warp_def 9, 6, 0, 0, MAP_TERRA_CAVE_ENTRANCE
	.globl ROUTE118_EventCoordEvents
ROUTE118_EventCoordEvents: @ 0x085033C8
	coord_event 43, 11, 3, 16497, 0, Route118_EventScript_StevenTrigger0
	coord_event 44, 11, 3, 16497, 0, Route118_EventScript_StevenTrigger1
	coord_event 45, 11, 3, 16497, 0, Route118_EventScript_StevenTrigger2
	.globl ROUTE118_EventBgEvents
ROUTE118_EventBgEvents: @ 0x085033F8
	bg_event 47, 14, 0, 8, 0x0001, 0x00, 0x00
	bg_event 13, 6, 0, 0, Route118_EventScript_RouteSignMauville, 0, 0
	bg_event 56, 8, 0, 0, Route118_EventScript_RouteSign119, 0, 0
	bg_event 67, 6, 0, 8, 0x000B, 0x00, 0x00
	bg_event 29, 5, 0, 8, 0x007A, 0x00, 0x00
	bg_event 47, 5, 0, 8, 0x00A3, 0x00, 0x00
	bg_event 46, 5, 0, 8, 0x00AB, 0x00, 0x00
	bg_event 31, 13, 3, 7, 0x0041, 0x43, 0x00
	bg_event 12, 14, 3, 7, 0x006F, 0x42, 0x00
	.globl gMapEvents_ROUTE118
gMapEvents_ROUTE118: @ 0x08503464
	map_events ROUTE118_EventObjects, ROUTE118_EventWarps, ROUTE118_EventCoordEvents, ROUTE118_EventBgEvents
	.globl ROUTE119_EventObjects
ROUTE119_EventObjects: @ 0x08503478
	object_event 1, 60, 0, 24, 5, 3, 12, 0, 0, 0, 34, 0x08244D23, 0x0000
	object_event 2, 60, 0, 25, 5, 3, 12, 0, 0, 0, 35, 0x08244D23, 0x0000
	object_event 3, 60, 0, 26, 5, 3, 12, 0, 0, 0, 36, 0x08244D23, 0x0000
	object_event 4, 36, 0, 12, 123, 3, 59, 0, 0, 1, 1, Route119_EventScript_Greg, 0x0000
	object_event 5, 39, 0, 26, 123, 3, 60, 0, 0, 1, 1, Route119_EventScript_Taylor, 0x0000
	object_event 6, 39, 0, 5, 125, 3, 62, 0, 0, 1, 1, Route119_EventScript_Donald, 0x0000
	object_event 7, 31, 0, 7, 74, 3, 18, 0, 0, 1, 3, Route119_EventScript_Jackson, 0x0000
	object_event 8, 39, 0, 28, 116, 3, 60, 0, 0, 1, 1, Route119_EventScript_Brent, 0x0000
	object_event 9, 32, 0, 35, 83, 4, 8, 0, 0, 1, 2, Route119_EventScript_Catherine, 0x0000
	object_event 10, 36, 0, 34, 122, 3, 61, 0, 0, 1, 1, Route119_EventScript_Doug, 0x0000
	object_event 11, 36, 0, 17, 128, 3, 61, 0, 0, 1, 1, Route119_EventScript_Kent, 0x0000
	object_event 12, 5, 0, 28, 14, 3, 57, 0, 0, 1, 1, Route119_EventScript_Yasu, 0x0000
	object_event 13, 5, 0, 19, 49, 3, 58, 0, 0, 1, 3, Route119_EventScript_Takashi, 0x0000
	object_event 14, 66, 0, 10, 50, 4, 10, 0, 0, 1, 3, Route119_EventScript_Hugh, 0x0000
	object_event 15, 66, 0, 8, 63, 3, 8, 0, 0, 1, 5, Route119_EventScript_Phil, 0x0000
	object_event 16, 240, 0, 25, 32, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0353
	object_event 17, 59, 0, 12, 121, 3, 1, 0, 0, 0, 0, 0x08256C37, 0x0400
	object_event 18, 59, 0, 4, 96, 3, 1, 0, 0, 0, 0, 0x08256C44, 0x0401
	object_event 19, 59, 0, 29, 53, 3, 1, 0, 0, 0, 0, 0x08256C51, 0x0402
	object_event 20, 59, 0, 25, 76, 3, 1, 0, 0, 0, 0, 0x08256C5E, 0x0403
	object_event 21, 59, 0, 8, 18, 3, 1, 0, 0, 0, 0, 0x08256C6B, 0x0404
	object_event 22, 59, 0, 33, 117, 3, 1, 0, 0, 0, 0, 0x08256C78, 0x0405
	object_event 23, 117, 0, 13, 33, 4, 10, 0, 0, 0, 0, Route119_EventScript_BridgeAquaGrunt1, 0x037A
	object_event 24, 117, 0, 13, 34, 4, 10, 0, 0, 0, 0, Route119_EventScript_BridgeAquaGrunt2, 0x037A
	object_event 25, 243, 0, 17, 33, 4, 7, 0, 0, 0, 0, 0x00000000, 0x039B
	object_event 26, 13, 0, 31, 109, 3, 8, 1, 1, 0, 0, Route119_EventScript_Boy1, 0x0000
	object_event 27, 60, 0, 8, 23, 3, 12, 0, 0, 0, 83, 0x08244D23, 0x0000
	object_event 28, 60, 0, 9, 23, 3, 12, 0, 0, 0, 84, 0x08244D23, 0x0000
	object_event 29, 60, 0, 29, 90, 3, 12, 0, 0, 0, 85, 0x08244D23, 0x0000
	object_event 30, 60, 0, 30, 90, 3, 12, 0, 0, 0, 86, 0x08244D23, 0x0000
	object_event 31, 56, 0, 19, 133, 3, 5, 2, 1, 0, 0, Route119_EventScript_CyclingTriathleteM, 0x0000
	object_event 32, 59, 0, 3, 56, 3, 1, 1, 1, 0, 0, 0x08256C85, 0x0452
	object_event 33, 9, 0, 35, 93, 4, 2, 1, 1, 0, 0, Route119_EventScript_Boy2, 0x0000
	object_event 34, 5, 0, 29, 6, 3, 57, 1, 1, 1, 3, Route119_EventScript_Hideo, 0x0000
	object_event 35, 204, 0, 31, 6, 3, 76, 1, 1, 0, 0, 0x0824339F, 0x03DD
	object_event 36, 204, 0, 25, 15, 3, 76, 1, 1, 0, 0, 0x082433AC, 0x03DE
	object_event 37, 50, 0, 13, 104, 3, 10, 1, 1, 1, 0, Route119_EventScript_Chris, 0x0000
	object_event 38, 20, 0, 8, 68, 3, 7, 1, 1, 1, 5, Route119_EventScript_Rachel, 0x0000
	object_event 39, 66, 0, 16, 52, 3, 10, 1, 1, 1, 3, Route119_EventScript_Dayton, 0x0000
	object_event 40, 66, 0, 32, 15, 3, 9, 1, 1, 1, 4, Route119_EventScript_Fabian, 0x0000
	object_event 41, 59, 0, 19, 5, 4, 1, 1, 1, 0, 0, 0x082570F0, 0x046E
	object_event 42, 59, 0, 24, 42, 3, 1, 1, 1, 0, 0, 0x08256C92, 0x047B
	object_event 43, 219, 0, 28, 25, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0312
	.globl ROUTE119_EventWarps
ROUTE119_EventWarps: @ 0x08503880
	warp_def 6, 32, 0, 0, MAP_ROUTE119_WEATHER_INSTITUTE_1F
	warp_def 33, 109, 0, 0, MAP_ROUTE119_HOUSE
	.globl ROUTE119_EventCoordEvents
ROUTE119_EventCoordEvents: @ 0x08503890
	coord_event 25, 31, 0, 16498, 0, Route119_EventScript_RivalTrigger1
	coord_event 26, 31, 0, 16498, 0, Route119_EventScript_RivalTrigger2
	coord_event 28, 13, 0, 20, 0, 0x00000000
	coord_event 29, 13, 3, 20, 0, 0x00000000
	coord_event 30, 13, 3, 20, 0, 0x00000000
	coord_event 31, 13, 3, 20, 0, 0x00000000
	coord_event 32, 13, 3, 20, 0, 0x00000000
	coord_event 33, 13, 3, 20, 0, 0x00000000
	coord_event 15, 133, 3, 20, 0, 0x00000000
	coord_event 16, 132, 3, 20, 0, 0x00000000
	coord_event 17, 131, 3, 20, 0, 0x00000000
	coord_event 18, 130, 3, 20, 0, 0x00000000
	coord_event 19, 131, 3, 20, 0, 0x00000000
	coord_event 20, 132, 3, 20, 0, 0x00000000
	coord_event 21, 133, 3, 20, 0, 0x00000000
	coord_event 36, 6, 3, 2, 0, 0x00000000
	coord_event 36, 7, 3, 2, 0, 0x00000000
	coord_event 35, 8, 3, 2, 0, 0x00000000
	coord_event 35, 9, 3, 2, 0, 0x00000000
	coord_event 34, 10, 3, 2, 0, 0x00000000
	coord_event 16, 137, 3, 2, 0, 0x00000000
	coord_event 17, 137, 3, 2, 0, 0x00000000
	coord_event 18, 137, 3, 2, 0, 0x00000000
	coord_event 19, 137, 3, 2, 0, 0x00000000
	coord_event 20, 137, 3, 2, 0, 0x00000000
	.globl ROUTE119_EventBgEvents
ROUTE119_EventBgEvents: @ 0x08503A20
	bg_event 9, 33, 0, 0, Route119_EventScript_WeatherInstituteSign, 0, 0
	bg_event 27, 19, 0, 0, Route119_EventScript_RouteSignFortree, 0, 0
	bg_event 5, 2, 0, 8, 0x00C9, 0x00, 0x00
	bg_event 4, 89, 0, 8, 0x00CA, 0x00, 0x00
	bg_event 5, 15, 0, 8, 0x00D3, 0x00, 0x00
	bg_event 7, 101, 3, 8, 0x00D4, 0x00, 0x00
	bg_event 34, 24, 3, 8, 0x00DD, 0x00, 0x00
	bg_event 31, 73, 3, 8, 0x00E7, 0x00, 0x00
	bg_event 16, 81, 0, 8, 0x0067, 0x00, 0x00
	bg_event 16, 28, 0, 8, 0x0071, 0x00, 0x00
	bg_event 17, 82, 3, 7, 0x0043, 0x05, 0x00
	bg_event 38, 63, 3, 7, 0x0002, 0x06, 0x00
	bg_event 26, 81, 0, 8, 0x0017, 0x00, 0x00
	bg_event 19, 76, 0, 8, 0x00AD, 0x00, 0x00
	bg_event 18, 76, 0, 8, 0x00C1, 0x00, 0x00
	bg_event 4, 15, 0, 8, 0x00DF, 0x00, 0x00
	bg_event 6, 2, 0, 8, 0x00E9, 0x00, 0x00
	bg_event 26, 120, 3, 7, 0x0017, 0x44, 0x00
	bg_event 20, 29, 3, 7, 0x0023, 0x57, 0x00
	bg_event 28, 9, 0, 0, Route119_EventScript_TrainerTipsDecoration, 0, 0
	.globl gMapEvents_ROUTE119
gMapEvents_ROUTE119: @ 0x08503B10
	map_events ROUTE119_EventObjects, ROUTE119_EventWarps, ROUTE119_EventCoordEvents, ROUTE119_EventBgEvents
	.globl ROUTE120_EventObjects
ROUTE120_EventObjects: @ 0x08503B24
	object_event 1, 60, 0, 4, 79, 3, 12, 0, 0, 0, 46, 0x08244D23, 0x0000
	object_event 2, 60, 0, 5, 79, 3, 12, 0, 0, 0, 45, 0x08244D23, 0x0000
	object_event 3, 60, 0, 6, 79, 3, 12, 0, 0, 0, 44, 0x08244D23, 0x0000
	object_event 4, 60, 0, 7, 79, 3, 12, 0, 0, 0, 43, 0x08244D23, 0x0000
	object_event 5, 60, 0, 34, 24, 3, 12, 0, 0, 0, 37, 0x08244D23, 0x0000
	object_event 6, 60, 0, 35, 24, 3, 12, 0, 0, 0, 38, 0x08244D23, 0x0000
	object_event 7, 60, 0, 36, 24, 3, 12, 0, 0, 0, 39, 0x08244D23, 0x0000
	object_event 8, 60, 0, 9, 92, 5, 12, 0, 0, 0, 40, 0x08244D23, 0x0000
	object_event 9, 60, 0, 10, 92, 5, 12, 0, 0, 0, 41, 0x08244D23, 0x0000
	object_event 10, 60, 0, 11, 92, 5, 12, 0, 0, 0, 42, 0x08244D23, 0x0000
	object_event 11, 66, 0, 5, 22, 3, 14, 0, 0, 1, 3, Route120_EventScript_Colin, 0x0000
	object_event 12, 66, 0, 32, 14, 3, 10, 0, 0, 1, 3, Route120_EventScript_Robert, 0x0000
	object_event 13, 31, 0, 27, 51, 3, 9, 0, 0, 1, 7, Route120_EventScript_Lorenzo, 0x0000
	object_event 14, 32, 0, 36, 45, 3, 9, 0, 0, 1, 2, Route120_EventScript_Jenna, 0x0000
	object_event 15, 39, 0, 19, 80, 5, 15, 0, 0, 1, 3, Route120_EventScript_Jeffrey, 0x0000
	object_event 16, 59, 0, 20, 55, 3, 1, 0, 0, 0, 0, 0x08256C9F, 0x0406
	object_event 17, 110, 0, 37, 5, 3, 8, 0, 0, 0, 0, 0x0825428E, 0x031E
	object_event 18, 68, 0, 36, 5, 3, 8, 0, 0, 0, 0, 0x0825426E, 0x031E
	object_event 19, 68, 0, 36, 5, 3, 8, 0, 0, 0, 0, 0x0825432E, 0x0386
	object_event 20, 110, 0, 37, 5, 3, 8, 0, 0, 0, 0, 0x0825434E, 0x0386
	object_event 21, 82, 0, 35, 32, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 22, 59, 0, 7, 89, 3, 1, 0, 0, 0, 0, 0x08256CAC, 0x0407
	object_event 23, 45, 0, 14, 92, 5, 5, 1, 0, 0, 0, Route120_EventScript_BerryBeauty, 0x0000
	object_event 24, 34, 0, 31, 37, 3, 15, 0, 0, 1, 4, Route120_EventScript_Jennifer, 0x0000
	object_event 25, 55, 0, 9, 60, 3, 21, 0, 0, 1, 4, Route120_EventScript_Chip, 0x0000
	object_event 26, 34, 0, 16, 6, 3, 23, 0, 0, 1, 4, Route120_EventScript_Clarissa, 0x0000
	object_event 27, 34, 0, 18, 34, 3, 9, 0, 0, 1, 3, Route120_EventScript_Angelica, 0x0000
	object_event 28, 59, 0, 22, 13, 3, 1, 1, 1, 0, 0, 0x08256CC6, 0x0454
	object_event 29, 59, 0, 23, 82, 5, 1, 1, 1, 0, 0, 0x08256CB9, 0x0453
	object_event 30, 204, 0, 12, 16, 4, 76, 1, 1, 0, 0, Route120_EventScript_BridgeKecleon, 0x03CA
	object_event 31, 134, 0, 13, 15, 4, 8, 1, 1, 0, 0, Route120_EventScript_Steven, 0x03CC
	object_event 32, 82, 0, 20, 1, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0014
	object_event 33, 82, 0, 15, 1, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0012
	object_event 34, 5, 0, 10, 72, 3, 58, 1, 1, 1, 3, Route120_EventScript_Keigo, 0x0000
	object_event 35, 5, 0, 19, 28, 3, 57, 1, 1, 1, 3, Route120_EventScript_Riley, 0x0000
	object_event 36, 212, 0, 12, 16, 3, 8, 1, 1, 0, 0, 0x00000000, 0x03D5
	object_event 37, 204, 0, 20, 11, 3, 76, 1, 1, 0, 0, 0x0824335E, 0x03D6
	object_event 38, 204, 0, 27, 2, 3, 76, 1, 1, 0, 0, 0x0824336B, 0x03D9
	object_event 39, 204, 0, 4, 77, 3, 76, 1, 1, 0, 0, 0x08243378, 0x03DA
	object_event 40, 204, 0, 7, 51, 3, 76, 1, 1, 0, 0, 0x08243392, 0x03DC
	object_event 41, 204, 0, 19, 48, 3, 76, 1, 1, 0, 0, 0x08243385, 0x03DB
	object_event 42, 14, 0, 19, 32, 3, 7, 1, 1, 1, 3, Route120_EventScript_Callie, 0x0000
	object_event 43, 33, 0, 14, 34, 3, 10, 1, 1, 1, 3, Route120_EventScript_Leonel, 0x0000
	object_event 44, 59, 0, 24, 33, 3, 1, 1, 1, 0, 0, 0x08256CD3, 0x047C
	.globl ROUTE120_EventWarps
ROUTE120_EventWarps: @ 0x08503F44
	warp_def 7, 55, 0, 0, MAP_ANCIENT_TOMB
	warp_def 19, 23, 1, 0, MAP_SCORCHED_SLAB
	.globl ROUTE120_EventCoordEvents
ROUTE120_EventCoordEvents: @ 0x08503F54
	coord_event 7, 15, 0, 3, 0, 0x00000000
	coord_event 7, 16, 0, 3, 0, 0x00000000
	coord_event 22, 61, 3, 3, 0, 0x00000000
	coord_event 12, 64, 3, 3, 0, 0x00000000
	coord_event 35, 63, 3, 1, 0, 0x00000000
	coord_event 36, 63, 3, 1, 0, 0x00000000
	coord_event 37, 63, 3, 1, 0, 0x00000000
	coord_event 38, 63, 3, 1, 0, 0x00000000
	coord_event 32, 88, 5, 1, 0, 0x00000000
	coord_event 28, 15, 0, 2, 0, 0x00000000
	coord_event 28, 16, 0, 2, 0, 0x00000000
	coord_event 28, 17, 3, 2, 0, 0x00000000
	coord_event 32, 89, 5, 1, 0, 0x00000000
	coord_event 32, 90, 5, 1, 0, 0x00000000
	coord_event 32, 91, 5, 1, 0, 0x00000000
	coord_event 10, 75, 3, 1, 0, 0x00000000
	coord_event 11, 75, 3, 1, 0, 0x00000000
	coord_event 12, 75, 3, 1, 0, 0x00000000
	coord_event 13, 75, 3, 1, 0, 0x00000000
	.globl ROUTE120_EventBgEvents
ROUTE120_EventBgEvents: @ 0x08504084
	bg_event 27, 3, 3, 0, Route120_EventScript_RouteSignFortree, 0, 0
	bg_event 38, 88, 3, 0, Route120_EventScript_RouteSign121, 0, 0
	bg_event 28, 62, 0, 8, 0x0065, 0x00, 0x00
	bg_event 30, 62, 0, 8, 0x006F, 0x00, 0x00
	bg_event 26, 10, 0, 8, 0x00DE, 0x00, 0x00
	bg_event 29, 85, 5, 8, 0x00E8, 0x00, 0x00
	bg_event 18, 12, 0, 8, 0x005D, 0x00, 0x00
	bg_event 38, 54, 0, 8, 0x00CB, 0x00, 0x00
	bg_event 31, 23, 0, 8, 0x00D5, 0x00, 0x00
	bg_event 9, 1, 3, 7, 0x0044, 0x47, 0x00
	bg_event 31, 11, 3, 7, 0x0018, 0x54, 0x00
	bg_event 0, 86, 3, 7, 0x0044, 0x45, 0x00
	bg_event 24, 42, 3, 7, 0x0046, 0x46, 0x00
	bg_event 5, 76, 0, 8, 0x00CC, 0x00, 0x00
	.globl gMapEvents_ROUTE120
gMapEvents_ROUTE120: @ 0x0850412C
	map_events ROUTE120_EventObjects, ROUTE120_EventWarps, ROUTE120_EventCoordEvents, ROUTE120_EventBgEvents
	.globl ROUTE121_EventObjects
ROUTE121_EventObjects: @ 0x08504140
	object_event 1, 24, 0, 29, 14, 3, 10, 1, 1, 0, 0, Route121_EventScript_Woman, 0x0000
	object_event 2, 60, 0, 14, 2, 3, 12, 0, 0, 0, 47, 0x08244D23, 0x0000
	object_event 3, 60, 0, 15, 2, 3, 12, 0, 0, 0, 48, 0x08244D23, 0x0000
	object_event 4, 60, 0, 16, 2, 3, 12, 0, 0, 0, 49, 0x08244D23, 0x0000
	object_event 5, 60, 0, 17, 2, 3, 12, 0, 0, 0, 50, 0x08244D23, 0x0000
	object_event 6, 60, 0, 64, 14, 3, 12, 0, 0, 0, 51, 0x08244D23, 0x0000
	object_event 7, 60, 0, 65, 14, 3, 12, 0, 0, 0, 52, 0x08244D23, 0x0000
	object_event 8, 60, 0, 66, 14, 3, 12, 0, 0, 0, 53, 0x08244D23, 0x0000
	object_event 9, 60, 0, 67, 14, 3, 12, 0, 0, 0, 54, 0x08244D23, 0x0000
	object_event 10, 47, 0, 39, 9, 3, 8, 0, 0, 1, 1, Route121_EventScript_Kate, 0x0000
	object_event 11, 47, 0, 40, 9, 3, 8, 0, 0, 1, 1, Route121_EventScript_Joy, 0x0000
	object_event 12, 117, 0, 30, 8, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 13, 117, 0, 30, 7, 3, 10, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 14, 117, 0, 31, 7, 3, 9, 0, 0, 0, 0, 0x00000000, 0x0392
	object_event 15, 82, 0, 32, 5, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 16, 82, 0, 65, 4, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 17, 18, 0, 63, 5, 3, 9, 0, 0, 1, 4, Route121_EventScript_Vanessa, 0x0000
	object_event 18, 48, 0, 55, 8, 3, 9, 0, 0, 1, 3, Route121_EventScript_Walter, 0x0000
	object_event 19, 40, 0, 11, 11, 3, 7, 0, 0, 1, 4, Route121_EventScript_Tammy, 0x0000
	object_event 20, 45, 0, 22, 5, 3, 17, 0, 0, 1, 4, Route121_EventScript_Jessica, 0x0000
	object_event 21, 59, 0, 55, 10, 3, 1, 1, 1, 0, 0, 0x08256CE0, 0x044F
	object_event 22, 82, 0, 26, 12, 3, 1, 1, 1, 0, 0, 0x082565C8, 0x0013
	object_event 23, 39, 0, 11, 6, 3, 26, 1, 4, 1, 3, Route121_EventScript_Cale, 0x0000
	object_event 24, 65, 0, 59, 8, 3, 8, 1, 1, 1, 4, Route121_EventScript_Myles, 0x0000
	object_event 25, 20, 0, 59, 13, 3, 7, 1, 1, 1, 4, Route121_EventScript_Pat, 0x0000
	object_event 26, 33, 0, 65, 9, 3, 18, 1, 1, 1, 6, Route121_EventScript_Marcel, 0x0000
	object_event 27, 34, 0, 72, 9, 3, 17, 1, 1, 1, 6, Route121_EventScript_Cristin, 0x0000
	object_event 28, 59, 0, 60, 10, 3, 1, 1, 1, 0, 0, 0x08256CED, 0x047D
	object_event 29, 59, 0, 38, 13, 3, 1, 1, 1, 0, 0, 0x08256CFA, 0x047E
	.globl ROUTE121_EventWarps
ROUTE121_EventWarps: @ 0x085043F8
	warp_def 37, 5, 0, 2, MAP_ROUTE121_SAFARI_ZONE_ENTRANCE
	.globl ROUTE121_EventCoordEvents
ROUTE121_EventCoordEvents: @ 0x08504400
	coord_event 25, 5, 3, 16500, 0, Route121_EventScript_AquaGruntsMoveOut
	coord_event 25, 6, 3, 16500, 0, Route121_EventScript_AquaGruntsMoveOut
	coord_event 25, 7, 3, 16500, 0, Route121_EventScript_AquaGruntsMoveOut
	coord_event 25, 8, 3, 16500, 0, Route121_EventScript_AquaGruntsMoveOut
	.globl ROUTE121_EventBgEvents
ROUTE121_EventBgEvents: @ 0x08504440
	bg_event 32, 14, 0, 0, Route121_EventScript_MtPyrePierSign, 0, 0
	bg_event 40, 11, 0, 8, 0x000C, 0x00, 0x00
	bg_event 18, 13, 0, 8, 0x0016, 0x00, 0x00
	bg_event 43, 7, 0, 8, 0x00A2, 0x00, 0x00
	bg_event 42, 7, 0, 8, 0x00AC, 0x00, 0x00
	bg_event 39, 6, 0, 0, Route121_EventScript_SafariZoneSign, 0, 0
	bg_event 23, 10, 3, 7, 0x003F, 0x27, 0x00
	bg_event 58, 3, 3, 7, 0x006E, 0x28, 0x00
	bg_event 72, 5, 3, 7, 0x0017, 0x49, 0x00
	bg_event 68, 8, 3, 7, 0x0019, 0x64, 0x00
	.globl gMapEvents_ROUTE121
gMapEvents_ROUTE121: @ 0x085044B8
	map_events ROUTE121_EventObjects, ROUTE121_EventWarps, ROUTE121_EventCoordEvents, ROUTE121_EventBgEvents
	.globl ROUTE122_EventObjects
ROUTE122_EventObjects: @ 0x00000000
	.globl ROUTE122_EventWarps
ROUTE122_EventWarps: @ 0x085044CC
	warp_def 22, 29, 0, 0, MAP_MT_PYRE_1F
	.globl gMapEvents_ROUTE122
gMapEvents_ROUTE122: @ 0x085044D4
	map_events 0, ROUTE122_EventWarps, 0, 0
	.include "data/maps/Route123/events.inc"
	.globl EventScript_CutTree
	.set EventScript_CutTree, 0x082565C8
	.globl gMapEvents_ROUTE123
	.set gMapEvents_ROUTE123, Route123_MapEvents

	.include "data/maps/Route124/events.inc"
	.globl gMapEvents_ROUTE124
	.set gMapEvents_ROUTE124, Route124_MapEvents
	.include "data/maps/Route125/events.inc"
	.globl gMapEvents_ROUTE125
	.set gMapEvents_ROUTE125, Route125_MapEvents
	.include "data/maps/Route126/events.inc"
	.globl gMapEvents_ROUTE126
	.set gMapEvents_ROUTE126, Route126_MapEvents
	.include "data/maps/Route127/events.inc"
	.globl gMapEvents_ROUTE127
	.set gMapEvents_ROUTE127, Route127_MapEvents
	.include "data/maps/Route128/events.inc"
	.globl gMapEvents_ROUTE128
	.set gMapEvents_ROUTE128, Route128_MapEvents
	.include "data/maps/Route129/events.inc"
	.globl gMapEvents_ROUTE129
	.set gMapEvents_ROUTE129, Route129_MapEvents
	.include "data/maps/Route130/events.inc"
	.globl gMapEvents_ROUTE130
	.set gMapEvents_ROUTE130, Route130_MapEvents
	.include "data/maps/Route131/events.inc"
	.globl gMapEvents_ROUTE131
	.set gMapEvents_ROUTE131, Route131_MapEvents
	.include "data/maps/Route132/events.inc"
	.globl gMapEvents_ROUTE132
	.set gMapEvents_ROUTE132, Route132_MapEvents
	.include "data/maps/Route133/events.inc"
	.globl gMapEvents_ROUTE133
	.set gMapEvents_ROUTE133, Route133_MapEvents
	.include "data/maps/Route134/events.inc"
	.globl gMapEvents_ROUTE134
	.set gMapEvents_ROUTE134, Route134_MapEvents
	.include "data/maps/Underwater_Route124/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE124
	.set gMapEvents_UNDERWATER_ROUTE124, Underwater_Route124_MapEvents
	.include "data/maps/Underwater_Route126/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE126
	.set gMapEvents_UNDERWATER_ROUTE126, Underwater_Route126_MapEvents
	.include "data/maps/Underwater_Route127/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE127
	.set gMapEvents_UNDERWATER_ROUTE127, Underwater_Route127_MapEvents
	.include "data/maps/Underwater_Route128/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE128
	.set gMapEvents_UNDERWATER_ROUTE128, Underwater_Route128_MapEvents
	.include "data/maps/Underwater_Route129/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE129
	.set gMapEvents_UNDERWATER_ROUTE129, Underwater_Route129_MapEvents
	.include "data/maps/Underwater_Route105/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE105
	.set gMapEvents_UNDERWATER_ROUTE105, Underwater_Route105_MapEvents
	.include "data/maps/Underwater_Route125/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE125
	.set gMapEvents_UNDERWATER_ROUTE125, Underwater_Route125_MapEvents
	.include "data/maps/LittlerootTown_BrendansHouse_1F/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	.set gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, LittlerootTown_BrendansHouse_1F_MapEvents
	.include "data/maps/LittlerootTown_BrendansHouse_2F/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	.set gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, LittlerootTown_BrendansHouse_2F_MapEvents
	.include "data/maps/LittlerootTown_MaysHouse_1F/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	.set gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F, LittlerootTown_MaysHouse_1F_MapEvents
	.include "data/maps/LittlerootTown_MaysHouse_2F/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	.set gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F, LittlerootTown_MaysHouse_2F_MapEvents
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
	.set gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, LittlerootTown_ProfessorBirchsLab_MapEvents
	.include "data/maps/OldaleTown_House1/events.inc"
	.globl gMapEvents_OLDALE_TOWN_HOUSE1
	.set gMapEvents_OLDALE_TOWN_HOUSE1, OldaleTown_House1_MapEvents
	.include "data/maps/OldaleTown_House2/events.inc"
	.globl gMapEvents_OLDALE_TOWN_HOUSE2
	.set gMapEvents_OLDALE_TOWN_HOUSE2, OldaleTown_House2_MapEvents
	.include "data/maps/OldaleTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F, OldaleTown_PokemonCenter_1F_MapEvents
	.include "data/maps/OldaleTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F, OldaleTown_PokemonCenter_2F_MapEvents
	.include "data/maps/OldaleTown_Mart/events.inc"
	.globl gMapEvents_OLDALE_TOWN_MART
	.set gMapEvents_OLDALE_TOWN_MART, OldaleTown_Mart_MapEvents
	.globl DEWFORD_TOWN_HOUSE1_EventObjects
DEWFORD_TOWN_HOUSE1_EventObjects: @ 0x085060F4
	object_event 1, 24, 0, 6, 3, 3, 9, 0, 0, 0, 0, 0x081F2C1A, 0x0000
	object_event 2, 19, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x081F2C11, 0x0000
	object_event 3, 208, 0, 4, 2, 3, 8, 3, 1, 0, 0, 0x081F2C23, 0x0000
	.globl DEWFORD_TOWN_HOUSE1_EventWarps
DEWFORD_TOWN_HOUSE1_EventWarps: @ 0x0850613C
	warp_def 3, 7, 0, 3, MAP_DEWFORD_TOWN
	warp_def 4, 7, 0, 3, MAP_DEWFORD_TOWN
	.globl gMapEvents_DEWFORD_TOWN_HOUSE1
gMapEvents_DEWFORD_TOWN_HOUSE1: @ 0x0850614C
	map_events DEWFORD_TOWN_HOUSE1_EventObjects, DEWFORD_TOWN_HOUSE1_EventWarps, 0, 0
	.include "data/maps/DewfordTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F, DewfordTown_PokemonCenter_1F_MapEvents
	.include "data/maps/DewfordTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F, DewfordTown_PokemonCenter_2F_MapEvents
	.include "data/maps/DewfordTown_Gym/events.inc"
	.globl gMapEvents_DEWFORD_TOWN_GYM
	.set gMapEvents_DEWFORD_TOWN_GYM, DewfordTown_Gym_MapEvents
	.include "data/maps/DewfordTown_Hall/events.inc"
	.globl gMapEvents_DEWFORD_TOWN_HALL
	.set gMapEvents_DEWFORD_TOWN_HALL, DewfordTown_Hall_MapEvents
	.include "data/maps/DewfordTown_House2/events.inc"
	.globl gMapEvents_DEWFORD_TOWN_HOUSE2
	.set gMapEvents_DEWFORD_TOWN_HOUSE2, DewfordTown_House2_MapEvents
	.include "data/maps/LavaridgeTown_HerbShop/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_HERB_SHOP
	.set gMapEvents_LAVARIDGE_TOWN_HERB_SHOP, LavaridgeTown_HerbShop_MapEvents
	.include "data/maps/LavaridgeTown_Gym_1F/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_GYM_1F
	.set gMapEvents_LAVARIDGE_TOWN_GYM_1F, LavaridgeTown_Gym_1F_MapEvents
	.include "data/maps/LavaridgeTown_Gym_B1F/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_GYM_B1F
	.set gMapEvents_LAVARIDGE_TOWN_GYM_B1F, LavaridgeTown_Gym_B1F_MapEvents
	.include "data/maps/LavaridgeTown_House/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_HOUSE
	.set gMapEvents_LAVARIDGE_TOWN_HOUSE, LavaridgeTown_House_MapEvents
	.include "data/maps/LavaridgeTown_Mart/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_MART
	.set gMapEvents_LAVARIDGE_TOWN_MART, LavaridgeTown_Mart_MapEvents
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F, LavaridgeTown_PokemonCenter_1F_MapEvents
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F, LavaridgeTown_PokemonCenter_2F_MapEvents
	.include "data/maps/FallarborTown_Mart/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_MART
	.set gMapEvents_FALLARBOR_TOWN_MART, FallarborTown_Mart_MapEvents
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects: @ 0x08506A9C
	object_event 1, 44, 0, 6, 5, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5320, 0x0000
	object_event 2, 55, 0, 1, 5, 3, 5, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F552C, 0x0000
	object_event 3, 11, 0, 12, 6, 3, 3, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5535, 0x0000
	object_event 4, 47, 0, 10, 9, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F553E, 0x0000
	object_event 5, 219, 0, 0, 7, 3, 10, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F5547, 0x02FF
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps: @ 0x08506B14
	warp_def 6, 9, 0, 1, MAP_FALLARBOR_TOWN
	warp_def 7, 9, 0, 1, MAP_FALLARBOR_TOWN
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08506B24
	bg_event 4, 5, 0, 0, FallarborTown_BattleTentLobby_EventScript_001F556E, 0, 0
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08506B30
	map_events FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps, 0, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
	.include "data/maps/FallarborTown_BattleTentCorridor/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
	.set gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, FallarborTown_BattleTentCorridor_MapEvents
	.include "data/maps/FallarborTown_BattleTentBattleRoom/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
	.set gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, FallarborTown_BattleTentBattleRoom_MapEvents
	.include "data/maps/FallarborTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F, FallarborTown_PokemonCenter_1F_MapEvents
	.include "data/maps/FallarborTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F, FallarborTown_PokemonCenter_2F_MapEvents
	.include "data/maps/FallarborTown_CozmosHouse/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE
	.set gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE, FallarborTown_CozmosHouse_MapEvents
	.include "data/maps/FallarborTown_MoveRelearnersHouse/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE
	.set gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE, FallarborTown_MoveRelearnersHouse_MapEvents
	.include "data/maps/VerdanturfTown_BattleTentLobby/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY
	.set gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY, VerdanturfTown_BattleTentLobby_MapEvents
	.include "data/maps/VerdanturfTown_BattleTentCorridor/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR
	.set gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR, VerdanturfTown_BattleTentCorridor_MapEvents
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
	.set gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, VerdanturfTown_BattleTentBattleRoom_MapEvents
	.include "data/maps/VerdanturfTown_Mart/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_MART
	.set gMapEvents_VERDANTURF_TOWN_MART, VerdanturfTown_Mart_MapEvents
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F, VerdanturfTown_PokemonCenter_1F_MapEvents
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F, VerdanturfTown_PokemonCenter_2F_MapEvents
	.include "data/maps/VerdanturfTown_WandasHouse/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE
	.set gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE, VerdanturfTown_WandasHouse_MapEvents
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE
	.set gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE, VerdanturfTown_FriendshipRatersHouse_MapEvents
	.include "data/maps/VerdanturfTown_House/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN_HOUSE
	.set gMapEvents_VERDANTURF_TOWN_HOUSE, VerdanturfTown_House_MapEvents
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F
	.set gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F, PacifidlogTown_PokemonCenter_1F_MapEvents
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F
	.set gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F, PacifidlogTown_PokemonCenter_2F_MapEvents
	.include "data/maps/PacifidlogTown_House1/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE1
	.set gMapEvents_PACIFIDLOG_TOWN_HOUSE1, PacifidlogTown_House1_MapEvents
	.include "data/maps/PacifidlogTown_House2/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE2
	.set gMapEvents_PACIFIDLOG_TOWN_HOUSE2, PacifidlogTown_House2_MapEvents
	.include "data/maps/PacifidlogTown_House3/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE3
	.set gMapEvents_PACIFIDLOG_TOWN_HOUSE3, PacifidlogTown_House3_MapEvents
	.globl PACIFIDLOG_TOWN_HOUSE4_EventObjects
PACIFIDLOG_TOWN_HOUSE4_EventObjects: @ 0x085073E0
	object_event 1, 20, 0, 3, 4, 3, 8, 0, 0, 0, 0, 0x081F7F47, 0x0000
	object_event 2, 12, 0, 7, 5, 3, 2, 1, 1, 0, 0, 0x081F7F3E, 0x0000
	object_event 3, 7, 0, 7, 4, 3, 2, 1, 1, 0, 0, 0x081F7F50, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE4_EventWarps
PACIFIDLOG_TOWN_HOUSE4_EventWarps: @ 0x08507428
	warp_def 4, 8, 0, 4, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 4, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE4
gMapEvents_PACIFIDLOG_TOWN_HOUSE4: @ 0x08507438
	map_events PACIFIDLOG_TOWN_HOUSE4_EventObjects, PACIFIDLOG_TOWN_HOUSE4_EventWarps, 0, 0
	.globl PACIFIDLOG_TOWN_HOUSE5_EventObjects
PACIFIDLOG_TOWN_HOUSE5_EventObjects: @ 0x0850744C
	object_event 1, 21, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x081F8056, 0x0000
	object_event 2, 48, 0, 3, 4, 3, 10, 0, 0, 0, 0, 0x081F807C, 0x0000
	.globl PACIFIDLOG_TOWN_HOUSE5_EventWarps
PACIFIDLOG_TOWN_HOUSE5_EventWarps: @ 0x0850747C
	warp_def 4, 8, 0, 5, MAP_PACIFIDLOG_TOWN
	warp_def 5, 8, 0, 5, MAP_PACIFIDLOG_TOWN
	.globl gMapEvents_PACIFIDLOG_TOWN_HOUSE5
gMapEvents_PACIFIDLOG_TOWN_HOUSE5: @ 0x0850748C
	map_events PACIFIDLOG_TOWN_HOUSE5_EventObjects, PACIFIDLOG_TOWN_HOUSE5_EventWarps, 0, 0
	.globl PETALBURG_CITY_WALLYS_HOUSE_EventObjects
PETALBURG_CITY_WALLYS_HOUSE_EventObjects: @ 0x085074A0
	object_event 1, 25, 0, 3, 4, 3, 10, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_001F815A, 0x0000
	object_event 2, 26, 0, 7, 5, 3, 9, 0, 0, 0, 0, PetalburgCity_WallysHouse_EventScript_001F81A2, 0x0000
	.globl PETALBURG_CITY_WALLYS_HOUSE_EventWarps
PETALBURG_CITY_WALLYS_HOUSE_EventWarps: @ 0x085074D0
	warp_def 3, 7, 0, 1, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 1, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_WALLYS_HOUSE
gMapEvents_PETALBURG_CITY_WALLYS_HOUSE: @ 0x085074E0
	map_events PETALBURG_CITY_WALLYS_HOUSE_EventObjects, PETALBURG_CITY_WALLYS_HOUSE_EventWarps, 0, 0
	.globl PETALBURG_CITY_GYM_EventObjects
PETALBURG_CITY_GYM_EventObjects: @ 0x085074F4
	object_event 1, 129, 0, 4, 2, 0, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_001F8688, 0x0304
	object_event 2, 34, 0, 4, 94, 3, 8, 0, 0, 1, 0, 0x081F9141, 0x0000
	object_event 3, 33, 0, 4, 81, 3, 8, 0, 0, 1, 0, 0x081F9051, 0x0000
	object_event 4, 33, 0, 4, 42, 3, 8, 0, 0, 1, 0, 0x081F908D, 0x0000
	object_event 5, 34, 0, 4, 55, 3, 8, 0, 0, 1, 0, 0x081F917D, 0x0000
	object_event 6, 33, 0, 4, 68, 3, 8, 0, 0, 1, 0, 0x081F90C9, 0x0000
	object_event 7, 34, 0, 4, 16, 3, 8, 0, 0, 1, 0, 0x081F91B9, 0x0000
	object_event 8, 33, 0, 4, 29, 3, 8, 0, 0, 1, 0, 0x081F9105, 0x0000
	object_event 9, 23, 0, 3, 109, 3, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_001F93E6, 0x030D
	object_event 10, 135, 0, 4, 111, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0362
	object_event 11, 25, 0, 1, 7, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0338
	.globl PETALBURG_CITY_GYM_EventWarps
PETALBURG_CITY_GYM_EventWarps: @ 0x085075FC
	warp_def 4, 111, 3, 2, MAP_PETALBURG_CITY
	warp_def 5, 111, 3, 2, MAP_PETALBURG_CITY
	warp_def 1, 105, 3, 3, MAP_PETALBURG_CITY_GYM
	warp_def 7, 85, 3, 2, MAP_PETALBURG_CITY_GYM
	warp_def 6, 85, 3, 2, MAP_PETALBURG_CITY_GYM
	warp_def 7, 105, 3, 6, MAP_PETALBURG_CITY_GYM
	warp_def 1, 98, 3, 5, MAP_PETALBURG_CITY_GYM
	warp_def 2, 98, 3, 5, MAP_PETALBURG_CITY_GYM
	warp_def 1, 79, 3, 10, MAP_PETALBURG_CITY_GYM
	warp_def 7, 79, 3, 12, MAP_PETALBURG_CITY_GYM
	warp_def 7, 46, 3, 8, MAP_PETALBURG_CITY_GYM
	warp_def 6, 46, 3, 8, MAP_PETALBURG_CITY_GYM
	warp_def 1, 59, 3, 9, MAP_PETALBURG_CITY_GYM
	warp_def 2, 59, 3, 9, MAP_PETALBURG_CITY_GYM
	warp_def 1, 92, 3, 16, MAP_PETALBURG_CITY_GYM
	warp_def 7, 92, 3, 18, MAP_PETALBURG_CITY_GYM
	warp_def 7, 59, 3, 14, MAP_PETALBURG_CITY_GYM
	warp_def 6, 59, 3, 14, MAP_PETALBURG_CITY_GYM
	warp_def 1, 72, 3, 15, MAP_PETALBURG_CITY_GYM
	warp_def 2, 72, 3, 15, MAP_PETALBURG_CITY_GYM
	warp_def 7, 40, 3, 24, MAP_PETALBURG_CITY_GYM
	warp_def 1, 53, 3, 26, MAP_PETALBURG_CITY_GYM
	warp_def 7, 53, 3, 28, MAP_PETALBURG_CITY_GYM
	warp_def 1, 66, 3, 30, MAP_PETALBURG_CITY_GYM
	warp_def 1, 20, 3, 20, MAP_PETALBURG_CITY_GYM
	warp_def 2, 20, 3, 20, MAP_PETALBURG_CITY_GYM
	warp_def 7, 20, 3, 21, MAP_PETALBURG_CITY_GYM
	warp_def 6, 20, 3, 21, MAP_PETALBURG_CITY_GYM
	warp_def 1, 33, 3, 22, MAP_PETALBURG_CITY_GYM
	warp_def 2, 33, 3, 22, MAP_PETALBURG_CITY_GYM
	warp_def 7, 33, 3, 23, MAP_PETALBURG_CITY_GYM
	warp_def 6, 33, 3, 23, MAP_PETALBURG_CITY_GYM
	warp_def 7, 14, 3, 34, MAP_PETALBURG_CITY_GYM
	warp_def 1, 27, 3, 36, MAP_PETALBURG_CITY_GYM
	warp_def 1, 7, 3, 32, MAP_PETALBURG_CITY_GYM
	warp_def 2, 7, 3, 32, MAP_PETALBURG_CITY_GYM
	warp_def 7, 7, 3, 33, MAP_PETALBURG_CITY_GYM
	warp_def 6, 7, 3, 33, MAP_PETALBURG_CITY_GYM
	.globl PETALBURG_CITY_GYM_EventBgEvents
PETALBURG_CITY_GYM_EventBgEvents: @ 0x0850772C
	bg_event 1, 105, 3, 0, PetalburgCity_Gym_EventScript_001F8DCE, 0, 0
	bg_event 7, 105, 3, 0, PetalburgCity_Gym_EventScript_001F8E1E, 0, 0
	bg_event 1, 79, 3, 0, PetalburgCity_Gym_EventScript_001F8E53, 0, 0
	bg_event 7, 79, 3, 0, PetalburgCity_Gym_EventScript_001F8E86, 0, 0
	bg_event 1, 92, 3, 0, PetalburgCity_Gym_EventScript_001F8EB9, 0, 0
	bg_event 7, 92, 3, 0, PetalburgCity_Gym_EventScript_001F8EEC, 0, 0
	bg_event 7, 40, 3, 0, PetalburgCity_Gym_EventScript_001F8F1F, 0, 0
	bg_event 1, 53, 3, 0, PetalburgCity_Gym_EventScript_001F8F52, 0, 0
	bg_event 7, 53, 3, 0, PetalburgCity_Gym_EventScript_001F8F85, 0, 0
	bg_event 1, 66, 3, 0, PetalburgCity_Gym_EventScript_001F8FB8, 0, 0
	bg_event 7, 14, 3, 0, PetalburgCity_Gym_EventScript_001F8FEB, 0, 0
	bg_event 1, 27, 3, 0, PetalburgCity_Gym_EventScript_001F901E, 0, 0
	bg_event 1, 110, 3, 1, PetalburgCity_Gym_EventScript_001F9405, 0, 0
	bg_event 7, 110, 3, 1, PetalburgCity_Gym_EventScript_001F9415, 0, 0
	.globl gMapEvents_PETALBURG_CITY_GYM
gMapEvents_PETALBURG_CITY_GYM: @ 0x085077D4
	map_events PETALBURG_CITY_GYM_EventObjects, PETALBURG_CITY_GYM_EventWarps, 0, PETALBURG_CITY_GYM_EventBgEvents
	.globl PETALBURG_CITY_HOUSE1_EventObjects
PETALBURG_CITY_HOUSE1_EventObjects: @ 0x085077E8
	object_event 1, 8, 0, 7, 4, 3, 2, 2, 2, 0, 0, 0x081FA647, 0x0000
	object_event 2, 21, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x081FA63E, 0x0000
	.globl PETALBURG_CITY_HOUSE1_EventWarps
PETALBURG_CITY_HOUSE1_EventWarps: @ 0x08507818
	warp_def 3, 8, 0, 0, MAP_PETALBURG_CITY
	warp_def 4, 8, 0, 0, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_HOUSE1
gMapEvents_PETALBURG_CITY_HOUSE1: @ 0x08507828
	map_events PETALBURG_CITY_HOUSE1_EventObjects, PETALBURG_CITY_HOUSE1_EventWarps, 0, 0
	.globl PETALBURG_CITY_HOUSE2_EventObjects
PETALBURG_CITY_HOUSE2_EventObjects: @ 0x0850783C
	object_event 1, 18, 0, 2, 5, 3, 2, 1, 1, 0, 0, 0x081FA721, 0x0000
	object_event 2, 38, 0, 7, 5, 3, 8, 0, 0, 0, 0, 0x081FA72A, 0x0000
	.globl PETALBURG_CITY_HOUSE2_EventWarps
PETALBURG_CITY_HOUSE2_EventWarps: @ 0x0850786C
	warp_def 3, 7, 0, 4, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 4, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_HOUSE2
gMapEvents_PETALBURG_CITY_HOUSE2: @ 0x0850787C
	map_events PETALBURG_CITY_HOUSE2_EventObjects, PETALBURG_CITY_HOUSE2_EventWarps, 0, 0
	.globl PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects
PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x08507890
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7E1, 0x0000
	object_event 2, 65, 0, 11, 2, 3, 8, 0, 0, 0, 0, 0x08257290, 0x0000
	object_event 3, 17, 0, 2, 3, 3, 8, 0, 0, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7EF, 0x0000
	object_event 4, 35, 0, 9, 6, 3, 2, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA7F8, 0x0000
	object_event 5, 34, 0, 5, 4, 3, 1, 1, 1, 0, 0, PetalburgCity_PokemonCenter_1F_EventScript_001FA801, 0x0000
	.globl PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps
PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08507908
	warp_def 7, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 6, 8, 3, 3, MAP_PETALBURG_CITY
	warp_def 1, 6, 4, 0, MAP_PETALBURG_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F
gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F: @ 0x08507920
	map_events PETALBURG_CITY_POKEMON_CENTER_1F_EventObjects, PETALBURG_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects
PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08507934
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps
PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08507994
	warp_def 1, 6, 4, 2, MAP_PETALBURG_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F
gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F: @ 0x085079AC
	map_events PETALBURG_CITY_POKEMON_CENTER_2F_EventObjects, PETALBURG_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl PETALBURG_CITY_MART_EventObjects
PETALBURG_CITY_MART_EventObjects: @ 0x085079C0
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081FA9EA, 0x0000
	object_event 2, 19, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x081FAA68, 0x0000
	object_event 3, 7, 0, 6, 3, 3, 8, 0, 0, 0, 0, 0x081FAA5F, 0x0000
	object_event 4, 20, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x081FAA56, 0x0000
	.globl PETALBURG_CITY_MART_EventWarps
PETALBURG_CITY_MART_EventWarps: @ 0x08507A20
	warp_def 3, 7, 0, 5, MAP_PETALBURG_CITY
	warp_def 4, 7, 0, 5, MAP_PETALBURG_CITY
	.globl gMapEvents_PETALBURG_CITY_MART
gMapEvents_PETALBURG_CITY_MART: @ 0x08507A30
	map_events PETALBURG_CITY_MART_EventObjects, PETALBURG_CITY_MART_EventWarps, 0, 0
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects
SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects: @ 0x08507A44
	object_event 1, 19, 0, 5, 5, 3, 8, 0, 0, 0, 0, 0x081FAB29, 0x0000
	object_event 2, 46, 0, 10, 7, 3, 7, 0, 0, 0, 0, 0x081FABD6, 0x0000
	object_event 3, 46, 0, 18, 8, 3, 5, 1, 0, 0, 0, 0x081FABDF, 0x0000
	object_event 4, 21, 0, 12, 11, 3, 2, 1, 2, 0, 0, 0x081FABE8, 0x0365
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps
SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps: @ 0x08507AA4
	warp_def 2, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 14, 0, 2, MAP_SLATEPORT_CITY
	warp_def 3, 1, 0, 0, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F
	.globl gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x08507ABC
	map_events SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventObjects, SLATEPORT_CITY_STERNS_SHIPYARD_1F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects
SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects: @ 0x08507AD0
	object_event 1, 46, 0, 10, 7, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 2, 46, 0, 8, 4, 3, 10, 0, 0, 0, 0, 0x081FAFA3, 0x0000
	object_event 3, 46, 0, 0, 9, 3, 7, 0, 0, 0, 0, 0x081FAFAC, 0x0000
	.globl SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps
SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps: @ 0x08507B18
	warp_def 3, 1, 0, 2, MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F
	.globl gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x08507B20
	map_events SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventObjects, SLATEPORT_CITY_STERNS_SHIPYARD_2F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects: @ 0x08507B34
	object_event 1, 46, 0, 6, 5, 3, 8, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB1AD, 0x0000
	object_event 2, 49, 0, 1, 5, 3, 2, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB340, 0x0000
	object_event 3, 33, 0, 3, 7, 3, 7, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB381, 0x0000
	object_event 4, 8, 0, 1, 8, 3, 1, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB38A, 0x0000
	object_event 5, 20, 0, 11, 8, 3, 9, 1, 1, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB393, 0x0000
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps: @ 0x08507BAC
	warp_def 6, 9, 0, 3, MAP_SLATEPORT_CITY
	warp_def 7, 9, 0, 3, MAP_SLATEPORT_CITY
	.globl SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents
SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08507BBC
	bg_event 4, 5, 0, 0, SlateportCity_BattleTentLobby_EventScript_001FB39C, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY: @ 0x08507BC8
	map_events SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventObjects, SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventWarps, 0, SLATEPORT_CITY_BATTLE_TENT_LOBBY_EventBgEvents
	.globl SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects
SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects: @ 0x08507BDC
	object_event 1, 46, 0, 2, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR: @ 0x08507BF4
	map_events SLATEPORT_CITY_BATTLE_TENT_CORRIDOR_EventObjects, 0, 0, 0
	.globl SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects
SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects: @ 0x08507C08
	object_event 1, 46, 0, 1, 4, 0, 10, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 2, 240, 0, 5, 1, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 241, 0, 4, 8, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM
gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM: @ 0x08507C50
	map_events SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM_EventObjects, 0, 0, 0
	.globl SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects
SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects: @ 0x08507C64
	object_event 1, 21, 0, 7, 5, 3, 8, 0, 0, 0, 0, 0x081FBD9E, 0x0000
	.globl SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps
SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps: @ 0x08507C7C
	warp_def 3, 7, 0, 6, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 6, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE
gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE: @ 0x08507C8C
	map_events SLATEPORT_CITY_NAME_RATERS_HOUSE_EventObjects, SLATEPORT_CITY_NAME_RATERS_HOUSE_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects
SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects: @ 0x08507CA0
	object_event 1, 19, 0, 11, 4, 0, 8, 0, 0, 0, 0, 0x081FC37A, 0x0000
	object_event 2, 6, 0, 1, 5, 0, 3, 0, 1, 0, 0, 0x081FC383, 0x0000
	object_event 3, 68, 0, 11, 5, 0, 7, 0, 0, 0, 0, 0x08253D5B, 0x0000
	object_event 4, 26, 0, 6, 2, 3, 1, 0, 0, 0, 0, 0x081FC310, 0x0000
	object_event 5, 48, 0, 6, 5, 4, 8, 0, 0, 0, 0, 0x081FC028, 0x0000
	object_event 6, 208, 0, 3, 9, 3, 1, 1, 1, 0, 0, 0x081FC39F, 0x0000
	object_event 7, 203, 0, 8, 3, 3, 1, 1, 1, 0, 0, 0x081FC38C, 0x0000
	object_event 8, 210, 0, 10, 8, 3, 1, 1, 1, 0, 0, 0x081FC3B2, 0x0000
	object_event 9, 65, 0, 11, 8, 0, 9, 0, 1, 0, 0, 0x08276832, 0x0000
	.globl SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps
SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps: @ 0x08507D78
	warp_def 6, 10, 0, 4, MAP_SLATEPORT_CITY
	warp_def 7, 10, 0, 4, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08507D88
	map_events SLATEPORT_CITY_POKEMON_FAN_CLUB_EventObjects, SLATEPORT_CITY_POKEMON_FAN_CLUB_EventWarps, 0, 0
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects: @ 0x08507D9C
	object_event 1, 45, 0, 7, 7, 3, 10, 0, 0, 0, 0, 0x081FCA3F, 0x0000
	object_event 2, 117, 0, 18, 5, 3, 7, 0, 0, 0, 0, 0x081FCB08, 0x0373
	object_event 3, 117, 0, 12, 2, 3, 7, 0, 0, 0, 0, 0x081FCB11, 0x0373
	object_event 4, 117, 0, 2, 8, 3, 7, 0, 0, 0, 0, 0x081FCAFF, 0x0373
	object_event 5, 118, 0, 3, 4, 3, 9, 0, 0, 0, 0, 0x081FCAF6, 0x0373
	object_event 6, 117, 0, 14, 4, 3, 10, 0, 0, 0, 0, 0x081FCB1A, 0x0373
	object_event 7, 45, 0, 12, 7, 3, 9, 0, 0, 0, 0, 0x081FCA3F, 0x0000
	object_event 8, 117, 0, 8, 3, 3, 8, 0, 0, 0, 0, 0x081FCB23, 0x0373
	object_event 9, 34, 0, 4, 2, 3, 1, 1, 1, 0, 0, 0x081FCB7D, 0x03C1
	object_event 10, 39, 0, 10, 2, 3, 7, 1, 1, 0, 0, 0x081FCB86, 0x03C1
	object_event 11, 25, 0, 17, 7, 3, 10, 1, 1, 0, 0, 0x081FCB8F, 0x03C1
	object_event 12, 12, 0, 18, 8, 3, 7, 1, 1, 0, 0, 0x081FCB98, 0x03C1
	object_event 13, 117, 0, 9, 4, 3, 21, 1, 1, 0, 0, 0x081FCBA1, 0x03C5
	object_event 14, 67, 0, 7, 4, 3, 1, 1, 1, 0, 0, 0x08253C9B, 0x03C1
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps: @ 0x08507EEC
	warp_def 9, 8, 0, 5, MAP_SLATEPORT_CITY
	warp_def 10, 8, 0, 7, MAP_SLATEPORT_CITY
	warp_def 6, 1, 0, 0, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents: @ 0x08507F04
	coord_event 9, 7, 3, 16554, 0, 0x081FCA48
	coord_event 10, 7, 3, 16554, 0, 0x081FCA59
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents: @ 0x08507F24
	bg_event 2, 7, 0, 0, 0x081FCB2C, 0, 0
	bg_event 2, 4, 0, 0, 0x081FCB35, 0, 0
	bg_event 9, 1, 0, 0, 0x081FCB3E, 0, 0
	bg_event 12, 1, 0, 0, 0x081FCB47, 0, 0
	bg_event 10, 1, 0, 0, 0x081FCB3E, 0, 0
	bg_event 13, 1, 0, 0, 0x081FCB47, 0, 0
	bg_event 15, 4, 0, 0, 0x081FCB50, 0, 0
	bg_event 18, 4, 0, 0, 0x081FCB59, 0, 0
	bg_event 18, 7, 0, 0, 0x081FCB62, 0, 0
	bg_event 2, 1, 0, 0, 0x081FCB6B, 0, 0
	bg_event 3, 1, 0, 0, 0x081FCB6B, 0, 0
	bg_event 16, 1, 0, 0, 0x081FCB74, 0, 0
	bg_event 17, 1, 0, 0, 0x081FCB74, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08507FC0
	map_events SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventObjects, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventWarps, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventCoordEvents, SLATEPORT_CITY_OCEANIC_MUSEUM_1F_EventBgEvents
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects: @ 0x08507FD4
	object_event 1, 46, 0, 13, 6, 3, 8, 0, 0, 0, 0, 0x081FD30A, 0x0377
	object_event 2, 195, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0376
	object_event 3, 117, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0374
	object_event 4, 117, 0, 6, 1, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0375
	object_event 5, 29, 0, 12, 7, 3, 10, 1, 1, 0, 0, 0x081FD56E, 0x03C1
	object_event 6, 18, 0, 9, 6, 3, 1, 1, 1, 0, 0, 0x081FD577, 0x03C1
	object_event 7, 5, 0, 1, 3, 3, 10, 1, 1, 0, 0, 0x081FD580, 0x03C1
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps: @ 0x0850807C
	warp_def 6, 1, 0, 2, MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
	.globl SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents
SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents: @ 0x08508084
	bg_event 18, 4, 0, 0, 0x081FD514, 0, 0
	bg_event 18, 7, 0, 0, 0x081FD51D, 0, 0
	bg_event 4, 3, 0, 0, 0x081FD55C, 0, 0
	bg_event 4, 4, 0, 0, 0x081FD55C, 0, 0
	bg_event 3, 3, 0, 0, 0x081FD553, 0, 0
	bg_event 2, 3, 0, 0, 0x081FD553, 0, 0
	bg_event 3, 4, 0, 0, 0x081FD553, 0, 0
	bg_event 3, 6, 0, 0, 0x081FD54A, 0, 0
	bg_event 4, 6, 0, 0, 0x081FD54A, 0, 0
	bg_event 13, 7, 0, 0, 0x081FD565, 0, 0
	bg_event 14, 7, 3, 0, 0x081FD565, 0, 0
	bg_event 18, 1, 0, 0, 0x081FD541, 0, 0
	bg_event 19, 1, 0, 0, 0x081FD541, 0, 0
	bg_event 15, 1, 0, 0, 0x081FD538, 0, 0
	bg_event 16, 1, 0, 0, 0x081FD538, 0, 0
	bg_event 8, 1, 0, 0, 0x081FD52F, 0, 0
	bg_event 9, 1, 0, 0, 0x081FD52F, 0, 0
	bg_event 12, 1, 0, 0, 0x081FD526, 0, 0
	bg_event 13, 1, 0, 0, 0x081FD526, 0, 0
	bg_event 3, 7, 0, 0, 0x081FD54A, 0, 0
	bg_event 4, 7, 0, 0, 0x081FD54A, 0, 0
	.globl gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08508180
	map_events SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventObjects, SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventWarps, 0, SLATEPORT_CITY_OCEANIC_MUSEUM_2F_EventBgEvents
	.globl SLATEPORT_CITY_HARBOR_EventObjects
SLATEPORT_CITY_HARBOR_EventObjects: @ 0x08508194
	object_event 1, 45, 0, 8, 10, 3, 8, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDDE2, 0x0389
	object_event 2, 49, 0, 4, 12, 3, 9, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF43, 0x0389
	object_event 3, 17, 0, 1, 12, 3, 10, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF8A, 0x0389
	object_event 4, 46, 0, 6, 13, 3, 1, 0, 0, 0, 0, SlateportCity_Harbor_EventScript_001FDF93, 0x0349
	object_event 5, 140, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x035C
	object_event 6, 117, 0, 7, 10, 3, 10, 0, 0, 0, 0, 0x00000000, 0x034D
	object_event 7, 195, 0, 8, 10, 3, 9, 0, 0, 0, 0, 0x00000000, 0x034E
	object_event 8, 141, 0, 7, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x0350
	.globl SLATEPORT_CITY_HARBOR_EventWarps
SLATEPORT_CITY_HARBOR_EventWarps: @ 0x08508254
	warp_def 11, 14, 0, 8, MAP_SLATEPORT_CITY
	warp_def 12, 14, 0, 8, MAP_SLATEPORT_CITY
	warp_def 19, 15, 0, 9, MAP_SLATEPORT_CITY
	warp_def 20, 15, 0, 9, MAP_SLATEPORT_CITY
	.globl SLATEPORT_CITY_HARBOR_EventCoordEvents
SLATEPORT_CITY_HARBOR_EventCoordEvents: @ 0x08508274
	coord_event 8, 11, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCAC
	coord_event 8, 12, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCB8
	coord_event 8, 13, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCC4
	coord_event 8, 14, 3, 16544, 1, SlateportCity_Harbor_EventScript_001FDCD0
	.globl gMapEvents_SLATEPORT_CITY_HARBOR
gMapEvents_SLATEPORT_CITY_HARBOR: @ 0x085082B4
	map_events SLATEPORT_CITY_HARBOR_EventObjects, SLATEPORT_CITY_HARBOR_EventWarps, SLATEPORT_CITY_HARBOR_EventCoordEvents, 0
	.globl SLATEPORT_CITY_HOUSE_EventObjects
SLATEPORT_CITY_HOUSE_EventObjects: @ 0x085082C8
	object_event 1, 25, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x081FE773, 0x0000
	object_event 2, 14, 0, 7, 4, 3, 9, 0, 0, 0, 0, 0x081FE77C, 0x0000
	.globl SLATEPORT_CITY_HOUSE_EventWarps
SLATEPORT_CITY_HOUSE_EventWarps: @ 0x085082F8
	warp_def 3, 7, 0, 10, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 10, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_HOUSE
gMapEvents_SLATEPORT_CITY_HOUSE: @ 0x08508308
	map_events SLATEPORT_CITY_HOUSE_EventObjects, SLATEPORT_CITY_HOUSE_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects
SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850831C
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE81D, 0x0000
	object_event 2, 49, 0, 2, 3, 3, 8, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE82B, 0x0000
	object_event 3, 34, 0, 10, 7, 3, 10, 0, 0, 0, 0, SlateportCity_PokemonCenter_1F_EventScript_001FE834, 0x0000
	.globl SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps
SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08508364
	warp_def 7, 8, 3, 0, MAP_SLATEPORT_CITY
	warp_def 6, 8, 3, 0, MAP_SLATEPORT_CITY
	warp_def 1, 6, 4, 0, MAP_SLATEPORT_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F
gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F: @ 0x0850837C
	map_events SLATEPORT_CITY_POKEMON_CENTER_1F_EventObjects, SLATEPORT_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects
SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508390
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps
SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x085083F0
	warp_def 1, 6, 4, 2, MAP_SLATEPORT_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F
gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F: @ 0x08508408
	map_events SLATEPORT_CITY_POKEMON_CENTER_2F_EventObjects, SLATEPORT_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl SLATEPORT_CITY_MART_EventObjects
SLATEPORT_CITY_MART_EventObjects: @ 0x0850841C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x081FE8FA, 0x0000
	object_event 2, 44, 0, 4, 2, 3, 7, 0, 0, 0, 0, 0x081FE92A, 0x0000
	object_event 3, 33, 0, 5, 5, 3, 1, 0, 0, 0, 0, 0x081FE933, 0x0000
	.globl SLATEPORT_CITY_MART_EventWarps
SLATEPORT_CITY_MART_EventWarps: @ 0x08508464
	warp_def 3, 7, 0, 1, MAP_SLATEPORT_CITY
	warp_def 4, 7, 0, 1, MAP_SLATEPORT_CITY
	.globl gMapEvents_SLATEPORT_CITY_MART
gMapEvents_SLATEPORT_CITY_MART: @ 0x08508474
	map_events SLATEPORT_CITY_MART_EventObjects, SLATEPORT_CITY_MART_EventWarps, 0, 0
	.globl MAUVILLE_CITY_GYM_EventObjects
MAUVILLE_CITY_GYM_EventObjects: @ 0x08508488
	object_event 1, 127, 0, 5, 2, 0, 8, 0, 0, 0, 0, 0x081FEB31, 0x0391
	object_event 2, 66, 0, 7, 8, 3, 8, 0, 0, 1, 1, 0x081FED16, 0x0000
	object_event 3, 14, 0, 1, 16, 0, 7, 0, 0, 1, 2, 0x081FED44, 0x0000
	object_event 4, 35, 0, 5, 10, 0, 9, 0, 0, 1, 2, 0x081FED2D, 0x0000
	object_event 5, 66, 0, 1, 13, 0, 8, 0, 0, 1, 2, 0x081FECFF, 0x0000
	object_event 6, 23, 0, 7, 20, 0, 9, 0, 0, 0, 0, MauvilleCity_Gym_EventScript_001FED72, 0x0000
	object_event 7, 39, 0, 7, 10, 3, 7, 1, 1, 1, 1, 0x081FED5B, 0x0000
	.globl MAUVILLE_CITY_GYM_EventWarps
MAUVILLE_CITY_GYM_EventWarps: @ 0x08508530
	warp_def 4, 20, 0, 0, MAP_MAUVILLE_CITY
	warp_def 5, 20, 0, 0, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_GYM_EventCoordEvents
MAUVILLE_CITY_GYM_EventCoordEvents: @ 0x08508540
	coord_event 4, 12, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC64
	coord_event 3, 9, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC89
	coord_event 0, 15, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FEC3F
	coord_event 8, 9, 3, 16384, 0, MauvilleCity_Gym_EventScript_001FECAE
	.globl MAUVILLE_CITY_GYM_EventBgEvents
MAUVILLE_CITY_GYM_EventBgEvents: @ 0x08508580
	bg_event 3, 18, 0, 1, MauvilleCity_Gym_EventScript_001FED91, 0, 0
	bg_event 6, 18, 0, 1, MauvilleCity_Gym_EventScript_001FEDA1, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_GYM
gMapEvents_MAUVILLE_CITY_GYM: @ 0x08508598
	map_events MAUVILLE_CITY_GYM_EventObjects, MAUVILLE_CITY_GYM_EventWarps, MAUVILLE_CITY_GYM_EventCoordEvents, MAUVILLE_CITY_GYM_EventBgEvents
	.globl MAUVILLE_CITY_BIKE_SHOP_EventObjects
MAUVILLE_CITY_BIKE_SHOP_EventObjects: @ 0x085085AC
	object_event 1, 23, 0, 2, 5, 3, 9, 0, 0, 0, 0, 0x081FF3EC, 0x0000
	object_event 2, 66, 0, 7, 6, 3, 2, 1, 1, 0, 0, 0x081FF561, 0x0000
	.globl MAUVILLE_CITY_BIKE_SHOP_EventWarps
MAUVILLE_CITY_BIKE_SHOP_EventWarps: @ 0x085085DC
	warp_def 3, 8, 0, 2, MAP_MAUVILLE_CITY
	warp_def 4, 8, 0, 2, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_BIKE_SHOP_EventBgEvents
MAUVILLE_CITY_BIKE_SHOP_EventBgEvents: @ 0x085085EC
	bg_event 8, 1, 0, 0, 0x081FF56A, 0, 0
	bg_event 11, 1, 0, 0, 0x081FF5DE, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_BIKE_SHOP
gMapEvents_MAUVILLE_CITY_BIKE_SHOP: @ 0x08508604
	map_events MAUVILLE_CITY_BIKE_SHOP_EventObjects, MAUVILLE_CITY_BIKE_SHOP_EventWarps, 0, MAUVILLE_CITY_BIKE_SHOP_EventBgEvents
	.globl MAUVILLE_CITY_HOUSE1_EventObjects
MAUVILLE_CITY_HOUSE1_EventObjects: @ 0x08508618
	object_event 1, 46, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x081FFD78, 0x0000
	.globl MAUVILLE_CITY_HOUSE1_EventWarps
MAUVILLE_CITY_HOUSE1_EventWarps: @ 0x08508630
	warp_def 3, 7, 0, 4, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 4, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_HOUSE1
gMapEvents_MAUVILLE_CITY_HOUSE1: @ 0x08508640
	map_events MAUVILLE_CITY_HOUSE1_EventObjects, MAUVILLE_CITY_HOUSE1_EventWarps, 0, 0
	.globl MAUVILLE_CITY_GAME_CORNER_EventObjects
MAUVILLE_CITY_GAME_CORNER_EventObjects: @ 0x08508654
	object_event 1, 20, 0, 12, 7, 3, 8, 0, 0, 0, 0, 0x08200454, 0x0000
	object_event 2, 48, 0, 16, 5, 3, 8, 0, 0, 0, 0, 0x0820045D, 0x0000
	object_event 3, 45, 0, 11, 2, 3, 8, 0, 0, 0, 0, 0x081FFEE8, 0x0000
	object_event 4, 45, 0, 14, 2, 3, 8, 0, 0, 0, 0, 0x08200020, 0x0000
	object_event 5, 10, 0, 7, 3, 3, 8, 0, 0, 0, 0, 0x08200466, 0x0000
	object_event 6, 25, 0, 19, 4, 3, 8, 0, 0, 0, 0, 0x0820054C, 0x0000
	object_event 7, 29, 0, 20, 8, 3, 9, 0, 0, 0, 0, 0x082005A8, 0x0000
	object_event 8, 27, 0, 6, 8, 3, 10, 0, 0, 0, 0, 0x082005B8, 0x0000
	object_event 9, 45, 0, 13, 2, 3, 8, 1, 1, 0, 0, 0x082001CE, 0x0000
	object_event 10, 33, 0, 1, 7, 3, 10, 1, 1, 0, 0, 0x082005C8, 0x0000
	object_event 11, 39, 0, 9, 8, 3, 9, 1, 1, 0, 0, 0x082005E5, 0x0000
	object_event 12, 34, 0, 4, 6, 3, 9, 1, 1, 0, 0, 0x082005F5, 0x0000
	.globl MAUVILLE_CITY_GAME_CORNER_EventWarps
MAUVILLE_CITY_GAME_CORNER_EventWarps: @ 0x08508774
	warp_def 11, 10, 3, 5, MAP_MAUVILLE_CITY
	warp_def 12, 10, 3, 5, MAP_MAUVILLE_CITY
	.globl MAUVILLE_CITY_GAME_CORNER_EventBgEvents
MAUVILLE_CITY_GAME_CORNER_EventBgEvents: @ 0x08508784
	bg_event 2, 6, 0, 3, 0x08200605, 0, 0
	bg_event 2, 8, 0, 3, 0x08200625, 0, 0
	bg_event 2, 9, 0, 3, 0x08200645, 0, 0
	bg_event 3, 7, 0, 4, 0x08200665, 0, 0
	bg_event 3, 8, 0, 4, 0x08200685, 0, 0
	bg_event 3, 9, 0, 4, 0x082006A5, 0, 0
	bg_event 7, 6, 0, 3, 0x082006C5, 0, 0
	bg_event 7, 7, 0, 3, 0x082006E5, 0, 0
	bg_event 7, 9, 0, 3, 0x08200705, 0, 0
	bg_event 8, 6, 0, 4, 0x08200725, 0, 0
	bg_event 8, 7, 0, 4, 0x08200745, 0, 0
	bg_event 8, 9, 0, 4, 0x08200765, 0, 0
	bg_event 14, 6, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 6, 0, 0, 0x08262C92, 0, 0
	bg_event 14, 7, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 7, 0, 0, 0x08262C92, 0, 0
	bg_event 14, 8, 0, 0, 0x08262C92, 0, 0
	bg_event 15, 8, 0, 0, 0x08262C92, 0, 0
	bg_event 18, 6, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 6, 0, 0, 0x08262CC0, 0, 0
	bg_event 18, 7, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 7, 0, 0, 0x08262CC0, 0, 0
	bg_event 18, 8, 0, 0, 0x08262CC0, 0, 0
	bg_event 19, 8, 0, 0, 0x08262CC0, 0, 0
	.globl gMapEvents_MAUVILLE_CITY_GAME_CORNER
gMapEvents_MAUVILLE_CITY_GAME_CORNER: @ 0x085088A4
	map_events MAUVILLE_CITY_GAME_CORNER_EventObjects, MAUVILLE_CITY_GAME_CORNER_EventWarps, 0, MAUVILLE_CITY_GAME_CORNER_EventBgEvents
	.globl MAUVILLE_CITY_HOUSE2_EventObjects
MAUVILLE_CITY_HOUSE2_EventObjects: @ 0x085088B8
	object_event 1, 24, 0, 4, 5, 3, 9, 0, 0, 0, 0, 0x08200C5B, 0x0000
	.globl MAUVILLE_CITY_HOUSE2_EventWarps
MAUVILLE_CITY_HOUSE2_EventWarps: @ 0x085088D0
	warp_def 3, 8, 0, 6, MAP_MAUVILLE_CITY
	warp_def 4, 8, 0, 6, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_HOUSE2
gMapEvents_MAUVILLE_CITY_HOUSE2: @ 0x085088E0
	map_events MAUVILLE_CITY_HOUSE2_EventObjects, MAUVILLE_CITY_HOUSE2_EventWarps, 0, 0
	.globl MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects
MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x085088F4
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200DF1, 0x0000
	object_event 2, 240, 0, 2, 3, 3, 9, 1, 0, 0, 0, 0x08254D6B, 0x0000
	object_event 3, 16, 0, 8, 6, 3, 1, 0, 0, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200DFF, 0x0000
	object_event 4, 34, 0, 11, 4, 3, 3, 0, 1, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200E08, 0x0000
	object_event 5, 35, 0, 2, 8, 3, 1, 1, 1, 0, 0, MauvilleCity_PokemonCenter_1F_EventScript_00200E11, 0x0000
	.globl MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps
MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850896C
	warp_def 7, 8, 3, 1, MAP_MAUVILLE_CITY
	warp_def 6, 8, 3, 1, MAP_MAUVILLE_CITY
	warp_def 1, 6, 4, 0, MAP_MAUVILLE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F
gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F: @ 0x08508984
	map_events MAUVILLE_CITY_POKEMON_CENTER_1F_EventObjects, MAUVILLE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects
MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508998
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	object_event 5, 35, 0, 8, 8, 3, 7, 1, 1, 0, 0, MauvilleCity_PokemonCenter_2F_EventScript_00200EF6, 0x0000
	.globl MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps
MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08508A10
	warp_def 1, 6, 4, 2, MAP_MAUVILLE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F
gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F: @ 0x08508A28
	map_events MAUVILLE_CITY_POKEMON_CENTER_2F_EventObjects, MAUVILLE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl MAUVILLE_CITY_MART_EventObjects
MAUVILLE_CITY_MART_EventObjects: @ 0x08508A3C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x08200F50, 0x0000
	object_event 2, 21, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x08200F84, 0x0000
	object_event 3, 33, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x08200F8D, 0x0000
	.globl MAUVILLE_CITY_MART_EventWarps
MAUVILLE_CITY_MART_EventWarps: @ 0x08508A84
	warp_def 3, 7, 0, 3, MAP_MAUVILLE_CITY
	warp_def 4, 7, 0, 3, MAP_MAUVILLE_CITY
	.globl gMapEvents_MAUVILLE_CITY_MART
gMapEvents_MAUVILLE_CITY_MART: @ 0x08508A94
	map_events MAUVILLE_CITY_MART_EventObjects, MAUVILLE_CITY_MART_EventWarps, 0, 0
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventObjects
RUSTBORO_CITY_DEVON_CORP_1F_EventObjects: @ 0x08508AA8
	object_event 1, 116, 0, 2, 6, 3, 2, 1, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_0020104C, 0x0000
	object_event 2, 116, 0, 15, 5, 3, 2, 2, 1, 0, 0, RustboroCity_DevonCorp_1F_EventScript_0020107E, 0x0000
	object_event 3, 24, 0, 5, 3, 3, 8, 0, 0, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010B9, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventWarps
RUSTBORO_CITY_DEVON_CORP_1F_EventWarps: @ 0x08508AF0
	warp_def 5, 8, 0, 5, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 6, MAP_RUSTBORO_CITY
	warp_def 14, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_2F
	.globl RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents
RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents: @ 0x08508B08
	bg_event 3, 2, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010FD, 0, 0
	bg_event 8, 2, 0, 0, RustboroCity_DevonCorp_1F_EventScript_002010F4, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08508B20
	map_events RUSTBORO_CITY_DEVON_CORP_1F_EventObjects, RUSTBORO_CITY_DEVON_CORP_1F_EventWarps, 0, RUSTBORO_CITY_DEVON_CORP_1F_EventBgEvents
	.globl RUSTBORO_CITY_DEVON_CORP_2F_EventObjects
RUSTBORO_CITY_DEVON_CORP_2F_EventObjects: @ 0x08508B34
	object_event 1, 46, 0, 6, 5, 3, 7, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201441, 0x0000
	object_event 2, 46, 0, 1, 5, 3, 10, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201458, 0x0000
	object_event 3, 46, 0, 2, 6, 3, 15, 0, 0, 0, 0, RustboroCity_DevonCorp_2F_EventScript_00201482, 0x0000
	object_event 4, 46, 0, 10, 5, 3, 7, 0, 10, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002014AC, 0x0000
	object_event 5, 46, 0, 14, 8, 3, 7, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002014C3, 0x0000
	object_event 6, 46, 0, 14, 5, 3, 7, 1, 1, 0, 0, RustboroCity_DevonCorp_2F_EventScript_002017A1, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_2F_EventWarps
RUSTBORO_CITY_DEVON_CORP_2F_EventWarps: @ 0x08508BC4
	warp_def 14, 1, 0, 2, MAP_RUSTBORO_CITY_DEVON_CORP_1F
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_DEVON_CORP_3F
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x08508BD4
	map_events RUSTBORO_CITY_DEVON_CORP_2F_EventObjects, RUSTBORO_CITY_DEVON_CORP_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventObjects
RUSTBORO_CITY_DEVON_CORP_3F_EventObjects: @ 0x08508BE8
	object_event 1, 48, 0, 17, 5, 3, 9, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_MrStone, 0x0000
	object_event 2, 23, 0, 3, 5, 3, 10, 0, 0, 0, 0, RustboroCity_DevonCorp_3F_EventScript_Employee, 0x03B5
	object_event 3, 48, 0, 15, 5, 3, 76, 1, 1, 0, 0, RustboroCity_DevonCorp_3F_EventScript_MrStone, 0x0000
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventWarps
RUSTBORO_CITY_DEVON_CORP_3F_EventWarps: @ 0x08508C30
	warp_def 2, 1, 0, 1, MAP_RUSTBORO_CITY_DEVON_CORP_2F
	.globl RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents
RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents: @ 0x08508C38
	bg_event 1, 5, 3, 0, RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay, 0, 0
	bg_event 1, 7, 3, 0, RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F
gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x08508C50
	map_events RUSTBORO_CITY_DEVON_CORP_3F_EventObjects, RUSTBORO_CITY_DEVON_CORP_3F_EventWarps, 0, RUSTBORO_CITY_DEVON_CORP_3F_EventBgEvents
	.globl RUSTBORO_CITY_GYM_EventObjects
RUSTBORO_CITY_GYM_EventObjects: @ 0x08508C64
	object_event 1, 125, 0, 5, 2, 3, 8, 0, 0, 0, 0, 0x082022C6, 0x0000
	object_event 2, 35, 0, 5, 13, 3, 8, 0, 0, 1, 2, 0x08202378, 0x0000
	object_event 3, 35, 0, 3, 9, 3, 9, 0, 0, 1, 3, 0x0820238F, 0x0000
	object_event 4, 23, 0, 3, 18, 3, 8, 0, 0, 0, 0, 0x082023BD, 0x0000
	object_event 5, 55, 0, 1, 6, 3, 8, 1, 1, 1, 3, 0x082023A6, 0x0000
	.globl RUSTBORO_CITY_GYM_EventWarps
RUSTBORO_CITY_GYM_EventWarps: @ 0x08508CDC
	warp_def 5, 19, 0, 0, MAP_RUSTBORO_CITY
	warp_def 6, 19, 0, 0, MAP_RUSTBORO_CITY
	.globl RUSTBORO_CITY_GYM_EventBgEvents
RUSTBORO_CITY_GYM_EventBgEvents: @ 0x08508CEC
	bg_event 2, 18, 0, 1, 0x082023DC, 0, 0
	bg_event 8, 18, 0, 1, 0x082023EC, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_GYM
gMapEvents_RUSTBORO_CITY_GYM: @ 0x08508D04
	map_events RUSTBORO_CITY_GYM_EventObjects, RUSTBORO_CITY_GYM_EventWarps, 0, RUSTBORO_CITY_GYM_EventBgEvents
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects
RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects: @ 0x08508D18
	object_event 1, 189, 0, 8, 6, 3, 10, 0, 0, 0, 0, 0x08202CD1, 0x0000
	object_event 2, 189, 0, 9, 6, 3, 9, 0, 0, 0, 0, 0x08202CDA, 0x0000
	object_event 3, 15, 0, 3, 8, 3, 7, 0, 0, 0, 0, 0x08202CE3, 0x0000
	object_event 4, 47, 0, 10, 8, 3, 7, 0, 0, 0, 0, 0x08202CEC, 0x0000
	object_event 5, 38, 0, 3, 6, 3, 8, 0, 0, 0, 0, 0x08202CF5, 0x0000
	object_event 6, 48, 0, 5, 3, 3, 8, 1, 1, 0, 0, 0x08202D07, 0x0000
	object_event 7, 219, 0, 0, 10, 0, 7, 1, 1, 0, 0, 0x08202DB2, 0x03E7
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps
RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps: @ 0x08508DC0
	warp_def 5, 10, 0, 4, MAP_RUSTBORO_CITY
	warp_def 6, 10, 0, 4, MAP_RUSTBORO_CITY
	.globl RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents
RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents: @ 0x08508DD0
	bg_event 5, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 4, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 6, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 7, 2, 0, 0, 0x08202C1B, 0, 0
	bg_event 3, 5, 0, 0, 0x08202CFE, 0, 0
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL
gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08508E0C
	map_events RUSTBORO_CITY_POKEMON_SCHOOL_EventObjects, RUSTBORO_CITY_POKEMON_SCHOOL_EventWarps, 0, RUSTBORO_CITY_POKEMON_SCHOOL_EventBgEvents
	.globl RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects
RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x08508E20
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034C7, 0x0000
	object_event 2, 19, 0, 11, 2, 3, 9, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034D5, 0x0000
	object_event 3, 7, 0, 3, 4, 3, 2, 1, 1, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034DE, 0x0000
	object_event 4, 14, 0, 10, 6, 3, 10, 0, 0, 0, 0, RustboroCity_PokemonCenter_1F_EventScript_002034E7, 0x0000
	.globl RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps
RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08508E80
	warp_def 7, 8, 3, 3, MAP_RUSTBORO_CITY
	warp_def 6, 8, 3, 3, MAP_RUSTBORO_CITY
	warp_def 1, 6, 4, 0, MAP_RUSTBORO_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F
gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F: @ 0x08508E98
	map_events RUSTBORO_CITY_POKEMON_CENTER_1F_EventObjects, RUSTBORO_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects
RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x08508EAC
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps
RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x08508F0C
	warp_def 1, 6, 4, 2, MAP_RUSTBORO_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F
gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F: @ 0x08508F24
	map_events RUSTBORO_CITY_POKEMON_CENTER_2F_EventObjects, RUSTBORO_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_MART_EventObjects
RUSTBORO_CITY_MART_EventObjects: @ 0x08508F38
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x082035E1, 0x0000
	object_event 2, 7, 0, 2, 5, 3, 7, 0, 0, 0, 0, 0x08203659, 0x0000
	object_event 3, 18, 0, 8, 4, 3, 3, 0, 1, 0, 0, 0x08203650, 0x0000
	object_event 4, 36, 0, 8, 2, 3, 7, 1, 1, 0, 0, 0x08203662, 0x0000
	.globl RUSTBORO_CITY_MART_EventWarps
RUSTBORO_CITY_MART_EventWarps: @ 0x08508F98
	warp_def 3, 7, 0, 2, MAP_RUSTBORO_CITY
	warp_def 4, 7, 0, 2, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_MART
gMapEvents_RUSTBORO_CITY_MART: @ 0x08508FA8
	map_events RUSTBORO_CITY_MART_EventObjects, RUSTBORO_CITY_MART_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT1_1F_EventObjects
RUSTBORO_CITY_FLAT1_1F_EventObjects: @ 0x08508FBC
	object_event 1, 33, 0, 9, 4, 3, 10, 0, 0, 0, 0, 0x08203715, 0x0000
	object_event 2, 34, 0, 12, 4, 3, 9, 0, 0, 0, 0, 0x0820371E, 0x0000
	.globl RUSTBORO_CITY_FLAT1_1F_EventWarps
RUSTBORO_CITY_FLAT1_1F_EventWarps: @ 0x08508FEC
	warp_def 6, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 7, 7, 0, 1, MAP_RUSTBORO_CITY
	warp_def 2, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT1_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT1_1F
gMapEvents_RUSTBORO_CITY_FLAT1_1F: @ 0x08509004
	map_events RUSTBORO_CITY_FLAT1_1F_EventObjects, RUSTBORO_CITY_FLAT1_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT1_2F_EventObjects
RUSTBORO_CITY_FLAT1_2F_EventObjects: @ 0x08509018
	object_event 1, 18, 0, 4, 6, 3, 5, 3, 1, 0, 0, 0x08203874, 0x0000
	object_event 2, 6, 0, 9, 5, 3, 8, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 3, 162, 0, 9, 4, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 4, 154, 0, 10, 5, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 5, 155, 0, 10, 6, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 6, 19, 0, 8, 5, 3, 10, 1, 1, 0, 0, 0x08203771, 0x0000
	object_event 7, 156, 0, 8, 6, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	object_event 8, 143, 0, 9, 7, 3, 1, 1, 1, 0, 0, 0x0820387D, 0x0000
	.globl RUSTBORO_CITY_FLAT1_2F_EventWarps
RUSTBORO_CITY_FLAT1_2F_EventWarps: @ 0x085090D8
	warp_def 2, 1, 0, 2, MAP_RUSTBORO_CITY_FLAT1_1F
	.globl gMapEvents_RUSTBORO_CITY_FLAT1_2F
gMapEvents_RUSTBORO_CITY_FLAT1_2F: @ 0x085090E0
	map_events RUSTBORO_CITY_FLAT1_2F_EventObjects, RUSTBORO_CITY_FLAT1_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE1_EventObjects
RUSTBORO_CITY_HOUSE1_EventObjects: @ 0x085090F4
	object_event 1, 31, 0, 6, 4, 3, 9, 0, 0, 0, 0, 0x08203BC9, 0x0000
	object_event 2, 55, 0, 9, 2, 3, 8, 0, 0, 0, 0, 0x08203C69, 0x0000
	.globl RUSTBORO_CITY_HOUSE1_EventWarps
RUSTBORO_CITY_HOUSE1_EventWarps: @ 0x08509124
	warp_def 5, 7, 0, 7, MAP_RUSTBORO_CITY
	warp_def 6, 7, 0, 7, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE1
gMapEvents_RUSTBORO_CITY_HOUSE1: @ 0x08509134
	map_events RUSTBORO_CITY_HOUSE1_EventObjects, RUSTBORO_CITY_HOUSE1_EventWarps, 0, 0
	.globl RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects
RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects: @ 0x08509148
	object_event 1, 25, 0, 7, 5, 3, 10, 0, 0, 0, 0, 0x08203D7D, 0x0000
	object_event 2, 47, 0, 9, 2, 3, 5, 1, 0, 0, 0, 0x08203DB3, 0x0000
	.globl RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps
RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps: @ 0x08509178
	warp_def 5, 8, 0, 8, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 8, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE
gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08509188
	map_events RUSTBORO_CITY_CUTTERS_HOUSE_EventObjects, RUSTBORO_CITY_CUTTERS_HOUSE_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE2_EventObjects
RUSTBORO_CITY_HOUSE2_EventObjects: @ 0x0850919C
	object_event 1, 18, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08203F16, 0x0000
	object_event 2, 12, 0, 4, 5, 3, 7, 0, 0, 0, 0, 0x08203F1F, 0x0000
	.globl RUSTBORO_CITY_HOUSE2_EventWarps
RUSTBORO_CITY_HOUSE2_EventWarps: @ 0x085091CC
	warp_def 5, 8, 0, 9, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 9, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE2
gMapEvents_RUSTBORO_CITY_HOUSE2: @ 0x085091DC
	map_events RUSTBORO_CITY_HOUSE2_EventObjects, RUSTBORO_CITY_HOUSE2_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_1F_EventObjects
RUSTBORO_CITY_FLAT2_1F_EventObjects: @ 0x085091F0
	object_event 1, 203, 0, 11, 4, 3, 9, 0, 0, 0, 0, 0x08203FA3, 0x0000
	object_event 2, 30, 0, 8, 4, 3, 10, 0, 0, 0, 0, 0x08203F9A, 0x0000
	.globl RUSTBORO_CITY_FLAT2_1F_EventWarps
RUSTBORO_CITY_FLAT2_1F_EventWarps: @ 0x08509220
	warp_def 2, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 8, 0, 10, MAP_RUSTBORO_CITY
	warp_def 3, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT2_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_1F
gMapEvents_RUSTBORO_CITY_FLAT2_1F: @ 0x08509238
	map_events RUSTBORO_CITY_FLAT2_1F_EventObjects, RUSTBORO_CITY_FLAT2_1F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_2F_EventObjects
RUSTBORO_CITY_FLAT2_2F_EventObjects: @ 0x0850924C
	object_event 1, 29, 0, 11, 4, 3, 10, 0, 0, 0, 0, 0x08203FE9, 0x0000
	object_event 2, 5, 0, 7, 3, 3, 5, 2, 0, 0, 0, 0x08203FF2, 0x0000
	.globl RUSTBORO_CITY_FLAT2_2F_EventWarps
RUSTBORO_CITY_FLAT2_2F_EventWarps: @ 0x0850927C
	warp_def 3, 1, 0, 2, MAP_RUSTBORO_CITY_FLAT2_1F
	warp_def 1, 1, 0, 0, MAP_RUSTBORO_CITY_FLAT2_3F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_2F
gMapEvents_RUSTBORO_CITY_FLAT2_2F: @ 0x0850928C
	map_events RUSTBORO_CITY_FLAT2_2F_EventObjects, RUSTBORO_CITY_FLAT2_2F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_FLAT2_3F_EventObjects
RUSTBORO_CITY_FLAT2_3F_EventObjects: @ 0x085092A0
	object_event 1, 116, 0, 7, 3, 3, 5, 2, 0, 0, 0, 0x082040B6, 0x0000
	object_event 2, 16, 0, 12, 2, 3, 8, 0, 0, 0, 0, 0x082040BF, 0x0000
	.globl RUSTBORO_CITY_FLAT2_3F_EventWarps
RUSTBORO_CITY_FLAT2_3F_EventWarps: @ 0x085092D0
	warp_def 1, 1, 0, 1, MAP_RUSTBORO_CITY_FLAT2_2F
	.globl gMapEvents_RUSTBORO_CITY_FLAT2_3F
gMapEvents_RUSTBORO_CITY_FLAT2_3F: @ 0x085092D8
	map_events RUSTBORO_CITY_FLAT2_3F_EventObjects, RUSTBORO_CITY_FLAT2_3F_EventWarps, 0, 0
	.globl RUSTBORO_CITY_HOUSE3_EventObjects
RUSTBORO_CITY_HOUSE3_EventObjects: @ 0x085092EC
	object_event 1, 29, 0, 4, 5, 3, 10, 0, 0, 0, 0, 0x08204118, 0x0000
	object_event 2, 30, 0, 7, 5, 3, 9, 0, 0, 0, 0, 0x08204121, 0x0000
	object_event 3, 209, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x0820412A, 0x0000
	.globl RUSTBORO_CITY_HOUSE3_EventWarps
RUSTBORO_CITY_HOUSE3_EventWarps: @ 0x08509334
	warp_def 5, 8, 0, 11, MAP_RUSTBORO_CITY
	warp_def 6, 8, 0, 11, MAP_RUSTBORO_CITY
	.globl gMapEvents_RUSTBORO_CITY_HOUSE3
gMapEvents_RUSTBORO_CITY_HOUSE3: @ 0x08509344
	map_events RUSTBORO_CITY_HOUSE3_EventObjects, RUSTBORO_CITY_HOUSE3_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE1_EventObjects
FORTREE_CITY_HOUSE1_EventObjects: @ 0x08509358
	object_event 1, 5, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x082041CB, 0x0000
	object_event 2, 208, 0, 2, 3, 3, 9, 0, 0, 0, 0, 0x08204278, 0x0000
	object_event 3, 22, 0, 7, 4, 3, 1, 1, 1, 0, 0, 0x0820426F, 0x0000
	.globl FORTREE_CITY_HOUSE1_EventWarps
FORTREE_CITY_HOUSE1_EventWarps: @ 0x085093A0
	warp_def 3, 5, 0, 1, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 1, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE1
gMapEvents_FORTREE_CITY_HOUSE1: @ 0x085093B0
	map_events FORTREE_CITY_HOUSE1_EventObjects, FORTREE_CITY_HOUSE1_EventWarps, 0, 0
	.globl FORTREE_CITY_GYM_EventObjects
FORTREE_CITY_GYM_EventObjects: @ 0x085093C4
	object_event 1, 130, 0, 15, 2, 3, 8, 0, 0, 0, 0, 0x082043BB, 0x0000
	object_event 2, 66, 0, 4, 14, 3, 8, 0, 0, 1, 3, 0x0820449B, 0x0000
	object_event 3, 31, 0, 10, 10, 3, 9, 0, 0, 1, 2, 0x082044C9, 0x0000
	object_event 4, 32, 0, 5, 17, 3, 9, 0, 0, 1, 1, 0x082044E0, 0x0000
	object_event 5, 66, 0, 9, 8, 3, 8, 0, 0, 1, 2, 0x082044B2, 0x0000
	object_event 6, 23, 0, 15, 21, 3, 8, 0, 0, 0, 0, FortreeCity_Gym_EventScript_00204525, 0x0000
	object_event 7, 66, 0, 4, 23, 3, 10, 1, 1, 1, 1, 0x082044F7, 0x0000
	object_event 8, 66, 0, 1, 10, 3, 7, 1, 1, 1, 3, 0x0820450E, 0x0000
	.globl FORTREE_CITY_GYM_EventWarps
FORTREE_CITY_GYM_EventWarps: @ 0x08509484
	warp_def 15, 24, 0, 2, MAP_FORTREE_CITY
	warp_def 16, 24, 0, 2, MAP_FORTREE_CITY
	.globl FORTREE_CITY_GYM_EventBgEvents
FORTREE_CITY_GYM_EventBgEvents: @ 0x08509494
	bg_event 14, 21, 0, 1, FortreeCity_Gym_EventScript_00204544, 0, 0
	bg_event 17, 21, 0, 1, FortreeCity_Gym_EventScript_00204554, 0, 0
	.globl gMapEvents_FORTREE_CITY_GYM
gMapEvents_FORTREE_CITY_GYM: @ 0x085094AC
	map_events FORTREE_CITY_GYM_EventObjects, FORTREE_CITY_GYM_EventWarps, 0, FORTREE_CITY_GYM_EventBgEvents
	.globl FORTREE_CITY_POKEMON_CENTER_1F_EventObjects
FORTREE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x085094C0
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C6C, 0x0000
	object_event 2, 48, 0, 4, 7, 3, 1, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C7A, 0x0000
	object_event 3, 33, 0, 8, 5, 3, 1, 0, 0, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C83, 0x0000
	object_event 4, 13, 0, 2, 3, 3, 8, 1, 1, 0, 0, FortreeCity_PokemonCenter_1F_EventScript_00204C8C, 0x0000
	.globl FORTREE_CITY_POKEMON_CENTER_1F_EventWarps
FORTREE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x08509520
	warp_def 7, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 6, 8, 3, 0, MAP_FORTREE_CITY
	warp_def 1, 6, 4, 0, MAP_FORTREE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F
gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F: @ 0x08509538
	map_events FORTREE_CITY_POKEMON_CENTER_1F_EventObjects, FORTREE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl FORTREE_CITY_POKEMON_CENTER_2F_EventObjects
FORTREE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850954C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl FORTREE_CITY_POKEMON_CENTER_2F_EventWarps
FORTREE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x085095AC
	warp_def 1, 6, 4, 2, MAP_FORTREE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F
gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F: @ 0x085095C4
	map_events FORTREE_CITY_POKEMON_CENTER_2F_EventObjects, FORTREE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl FORTREE_CITY_MART_EventObjects
FORTREE_CITY_MART_EventObjects: @ 0x085095D8
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x08204DBE, 0x0000
	object_event 2, 20, 0, 9, 3, 3, 7, 0, 0, 0, 0, 0x08204DF0, 0x0000
	object_event 3, 14, 0, 8, 5, 3, 2, 1, 1, 0, 0, 0x08204DF9, 0x0000
	object_event 4, 9, 0, 5, 6, 3, 10, 1, 1, 0, 0, 0x08204E02, 0x0000
	.globl FORTREE_CITY_MART_EventWarps
FORTREE_CITY_MART_EventWarps: @ 0x08509638
	warp_def 3, 7, 0, 3, MAP_FORTREE_CITY
	warp_def 4, 7, 0, 3, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_MART
gMapEvents_FORTREE_CITY_MART: @ 0x08509648
	map_events FORTREE_CITY_MART_EventObjects, FORTREE_CITY_MART_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE2_EventObjects
FORTREE_CITY_HOUSE2_EventObjects: @ 0x0850965C
	object_event 1, 22, 0, 2, 3, 3, 5, 1, 0, 0, 0, 0x08204E9C, 0x0000
	object_event 2, 21, 0, 6, 3, 3, 9, 1, 0, 0, 0, 0x08276A3A, 0x0000
	.globl FORTREE_CITY_HOUSE2_EventWarps
FORTREE_CITY_HOUSE2_EventWarps: @ 0x0850968C
	warp_def 3, 5, 0, 4, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 4, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE2
gMapEvents_FORTREE_CITY_HOUSE2: @ 0x0850969C
	map_events FORTREE_CITY_HOUSE2_EventObjects, FORTREE_CITY_HOUSE2_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE3_EventObjects
FORTREE_CITY_HOUSE3_EventObjects: @ 0x085096B0
	object_event 1, 39, 0, 0, 3, 3, 10, 0, 0, 0, 0, 0x082050D1, 0x0000
	object_event 2, 38, 0, 5, 4, 3, 2, 1, 1, 0, 0, 0x082050DA, 0x0000
	.globl FORTREE_CITY_HOUSE3_EventWarps
FORTREE_CITY_HOUSE3_EventWarps: @ 0x085096E0
	warp_def 3, 5, 0, 5, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 5, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE3
gMapEvents_FORTREE_CITY_HOUSE3: @ 0x085096F0
	map_events FORTREE_CITY_HOUSE3_EventObjects, FORTREE_CITY_HOUSE3_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE4_EventObjects
FORTREE_CITY_HOUSE4_EventObjects: @ 0x08509704
	object_event 1, 26, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x082051A3, 0x0000
	object_event 2, 13, 0, 1, 3, 3, 8, 0, 0, 0, 0, 0x082051AC, 0x0000
	object_event 3, 211, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x08205242, 0x03A5
	.globl FORTREE_CITY_HOUSE4_EventWarps
FORTREE_CITY_HOUSE4_EventWarps: @ 0x0850974C
	warp_def 3, 5, 0, 6, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 6, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE4
gMapEvents_FORTREE_CITY_HOUSE4: @ 0x0850975C
	map_events FORTREE_CITY_HOUSE4_EventObjects, FORTREE_CITY_HOUSE4_EventWarps, 0, 0
	.globl FORTREE_CITY_HOUSE5_EventObjects
FORTREE_CITY_HOUSE5_EventObjects: @ 0x08509770
	object_event 1, 18, 0, 6, 4, 3, 20, 0, 0, 0, 0, 0x08205344, 0x0000
	object_event 2, 208, 0, 6, 3, 3, 8, 0, 0, 0, 0, 0x08205356, 0x0000
	object_event 3, 19, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820534D, 0x0000
	.globl FORTREE_CITY_HOUSE5_EventWarps
FORTREE_CITY_HOUSE5_EventWarps: @ 0x085097B8
	warp_def 3, 5, 0, 7, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 7, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_HOUSE5
gMapEvents_FORTREE_CITY_HOUSE5: @ 0x085097C8
	map_events FORTREE_CITY_HOUSE5_EventObjects, FORTREE_CITY_HOUSE5_EventWarps, 0, 0
	.globl FORTREE_CITY_DECORATION_SHOP_EventObjects
FORTREE_CITY_DECORATION_SHOP_EventObjects: @ 0x085097DC
	object_event 1, 25, 0, 6, 5, 3, 1, 1, 1, 0, 0, 0x082053F1, 0x0000
	object_event 2, 14, 0, 0, 4, 3, 9, 0, 0, 0, 0, 0x082053FA, 0x0000
	object_event 3, 83, 0, 1, 2, 3, 8, 0, 0, 0, 0, 0x08205403, 0x0000
	object_event 4, 83, 0, 6, 2, 3, 8, 0, 0, 0, 0, 0x08205430, 0x0000
	.globl FORTREE_CITY_DECORATION_SHOP_EventWarps
FORTREE_CITY_DECORATION_SHOP_EventWarps: @ 0x0850983C
	warp_def 3, 5, 0, 8, MAP_FORTREE_CITY
	warp_def 4, 5, 0, 8, MAP_FORTREE_CITY
	.globl gMapEvents_FORTREE_CITY_DECORATION_SHOP
gMapEvents_FORTREE_CITY_DECORATION_SHOP: @ 0x0850984C
	map_events FORTREE_CITY_DECORATION_SHOP_EventObjects, FORTREE_CITY_DECORATION_SHOP_EventWarps, 0, 0
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects: @ 0x08509860
	object_event 1, 19, 0, 10, 3, 3, 7, 0, 0, 0, 0, 0x082054FD, 0x0000
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps: @ 0x08509878
	warp_def 5, 8, 0, 1, MAP_LILYCOVE_CITY
	warp_def 6, 8, 0, 1, MAP_LILYCOVE_CITY
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents
LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents: @ 0x08509890
	coord_event 10, 2, 3, 16385, 0, 0x08205585
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x085098A0
	map_events LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventObjects, LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventWarps, LILYCOVE_CITY_COVE_LILY_MOTEL_1F_EventCoordEvents, 0
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects
LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects: @ 0x085098B4
	object_event 1, 33, 0, 4, 6, 3, 9, 0, 0, 0, 0, 0x08205888, 0x039D
	object_event 2, 46, 0, 1, 4, 3, 10, 0, 0, 0, 0, 0x082058DE, 0x039D
	object_event 3, 17, 0, 7, 7, 3, 10, 0, 0, 0, 0, 0x082058E7, 0x039D
	object_event 4, 65, 0, 10, 3, 3, 9, 0, 0, 0, 0, 0x082058D5, 0x039D
	object_event 5, 189, 0, 7, 3, 3, 8, 1, 1, 0, 0, 0x082058F9, 0x039D
	object_event 6, 20, 0, 4, 4, 3, 9, 1, 1, 0, 0, 0x082058F0, 0x039D
	object_event 7, 219, 0, 1, 7, 3, 10, 0, 0, 0, 0, 0x08205902, 0x0313
	.globl LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps
LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps: @ 0x0850995C
	warp_def 2, 1, 0, 2, MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x08509964
	map_events LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventObjects, LILYCOVE_CITY_COVE_LILY_MOTEL_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects: @ 0x08509978
	object_event 1, 45, 0, 5, 12, 3, 10, 0, 0, 0, 0, 0x08205BE3, 0x0000
	object_event 2, 48, 0, 16, 2, 3, 8, 0, 0, 0, 0, 0x08205BEC, 0x0307
	object_event 3, 38, 0, 13, 7, 3, 10, 0, 0, 0, 0, 0x08205D1F, 0x0000
	object_event 4, 99, 0, 13, 10, 3, 5, 2, 0, 0, 0, 0x08205D28, 0x0000
	object_event 5, 5, 0, 2, 8, 3, 7, 0, 0, 0, 0, 0x08205D31, 0x0000
	object_event 6, 26, 0, 3, 8, 3, 7, 0, 0, 0, 0, 0x08205D3A, 0x0000
	object_event 7, 20, 0, 11, 3, 3, 2, 1, 1, 0, 0, 0x08205D43, 0x0308
	object_event 8, 99, 0, 19, 3, 3, 7, 0, 0, 0, 0, 0x08205D55, 0x030B
	object_event 9, 17, 0, 2, 2, 3, 2, 2, 2, 0, 0, 0x08205D6C, 0x030C
	object_event 10, 37, 0, 6, 2, 3, 2, 1, 1, 0, 0, 0x08205D4C, 0x030A
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps: @ 0x08509A68
	warp_def 9, 13, 0, 3, MAP_LILYCOVE_CITY
	warp_def 10, 13, 0, 13, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents
LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents: @ 0x08509A80
	bg_event 1, 1, 0, 0, 0x08205CD7, 0, 0
	bg_event 2, 1, 0, 0, 0x08205CD7, 0, 0
	bg_event 5, 1, 0, 0, 0x08205CFB, 0, 0
	bg_event 6, 1, 0, 0, 0x08205CFB, 0, 0
	bg_event 9, 1, 0, 0, 0x08205CCE, 0, 0
	bg_event 3, 6, 0, 0, 0x08205CE0, 0, 0
	bg_event 2, 6, 0, 0, 0x08205CE0, 0, 0
	bg_event 15, 12, 0, 0, 0x08205D04, 0, 0
	bg_event 11, 1, 0, 0, 0x08205CCE, 0, 0
	bg_event 6, 6, 0, 0, 0x08205CF2, 0, 0
	bg_event 17, 9, 0, 0, 0x08205D16, 0, 0
	bg_event 19, 1, 0, 0, 0x08205CE9, 0, 0
	bg_event 20, 1, 0, 0, 0x08205CE9, 0, 0
	bg_event 18, 9, 0, 0, 0x08205D16, 0, 0
	bg_event 18, 11, 0, 0, 0x08205D0D, 0, 0
	bg_event 16, 9, 0, 0, 0x08205D16, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08509B40
	map_events LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventObjects, LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventWarps, 0, LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_EventBgEvents
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects: @ 0x08509B54
	object_event 1, 48, 0, 10, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206312, 0x0000
	object_event 2, 10, 0, 19, 10, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206436, 0x0309
	object_event 3, 21, 0, 7, 3, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_0020643F, 0x030C
	object_event 4, 15, 0, 14, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206448, 0x030C
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps: @ 0x08509BB4
	warp_def 13, 1, 0, 2, MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	.globl LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents
LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents: @ 0x08509BBC
	bg_event 14, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063D7, 0, 0
	bg_event 15, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063D7, 0, 0
	bg_event 3, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063EA, 0, 0
	bg_event 2, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063EA, 0, 0
	bg_event 10, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063FD, 0, 0
	bg_event 11, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_002063FD, 0, 0
	bg_event 19, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206410, 0, 0
	bg_event 18, 6, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206410, 0, 0
	bg_event 6, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206423, 0, 0
	bg_event 7, 10, 0, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_00206423, 0, 0
	bg_event 11, 2, 0, 0, 0x08205D04, 0, 0
	bg_event 15, 2, 0, 0, 0x08205D04, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x08509C4C
	map_events LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventObjects, LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventWarps, 0, LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_EventBgEvents
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventObjects
LILYCOVE_CITY_CONTEST_LOBBY_EventObjects: @ 0x08509C60
	object_event 1, 85, 0, 14, 2, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206C14, 0x0000
	object_event 2, 85, 0, 15, 2, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206EC6, 0x0000
	object_event 3, 65, 0, 26, 9, 3, 10, 0, 0, 0, 0, 0x082590D2, 0x0000
	object_event 4, 99, 0, 9, 1, 0, 1, 0, 0, 0, 0, 0x00000000, 0x0306
	object_event 5, 44, 0, 18, 8, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DC8, 0x0000
	object_event 6, 10, 0, 4, 9, 3, 2, 2, 2, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DD1, 0x0000
	object_event 7, 99, 0, 3, 4, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DDA, 0x0000
	object_event 8, 67, 0, 13, 10, 3, 10, 0, 0, 0, 0, 0x08253E71, 0x0322
	object_event 9, 7, 0, 23, 8, 3, 8, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E28, 0x0000
	object_event 10, 6, 0, 28, 9, 3, 9, 0, 0, 0, 0, 0x082590E4, 0x0000
	object_event 11, 99, 0, 21, 1, 0, 8, 0, 0, 0, 0, 0x00000000, 0x037F
	object_event 12, 50, 0, 5, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DEC, 0x0000
	object_event 13, 17, 0, 0, 8, 3, 10, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DE3, 0x0000
	object_event 14, 5, 0, 8, 7, 3, 3, 0, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DF5, 0x0000
	object_event 15, 18, 0, 22, 9, 3, 10, 0, 0, 0, 0, 0x082590DB, 0x0000
	object_event 16, 21, 0, 26, 5, 3, 10, 0, 0, 0, 0, 0x082590ED, 0x0369
	object_event 17, 8, 0, 24, 9, 3, 9, 0, 0, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E31, 0x0000
	object_event 18, 66, 0, 27, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E73, 0x0340
	object_event 19, 31, 0, 28, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E7E, 0x0340
	object_event 20, 12, 0, 28, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E89, 0x0340
	object_event 21, 115, 0, 26, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E99, 0x0340
	object_event 22, 16, 0, 27, 7, 3, 7, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206EA9, 0x0340
	object_event 23, 5, 0, 26, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E68, 0x0340
	object_event 24, 29, 0, 26, 5, 3, 10, 1, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E58, 0x0340
	object_event 25, 12, 0, 9, 10, 3, 10, 2, 2, 0, 0, LilycoveCity_ContestLobby_EventScript_002073B1, 0x0000
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventWarps
LILYCOVE_CITY_CONTEST_LOBBY_EventWarps: @ 0x08509EB8
	warp_def 14, 11, 0, 4, MAP_LILYCOVE_CITY
	warp_def 15, 11, 0, 4, MAP_LILYCOVE_CITY
	warp_def 9, 1, 0, 0, MAP_LILYCOVE_CITY_CONTEST_HALL
	warp_def 21, 1, 0, 1, MAP_LILYCOVE_CITY_CONTEST_HALL
	.globl LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents
LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents: @ 0x08509ED8
	bg_event 23, 5, 0, 0, 0x08259185, 0, 0
	bg_event 23, 9, 0, 0, 0x08258F4E, 0, 0
	bg_event 23, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E13, 0, 0
	bg_event 25, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E1A, 0, 0
	bg_event 27, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E21, 0, 0
	bg_event 30, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E3A, 0, 0
	bg_event 3, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206DFE, 0, 0
	bg_event 5, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E05, 0, 0
	bg_event 7, 1, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E0C, 0, 0
	bg_event 27, 5, 0, 0, 0x08258D6E, 0, 0
	bg_event 27, 9, 0, 0, 0x08258E7D, 0, 0
	bg_event 18, 3, 0, 0, LilycoveCity_ContestLobby_EventScript_00206E44, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY
gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08509F68
	map_events LILYCOVE_CITY_CONTEST_LOBBY_EventObjects, LILYCOVE_CITY_CONTEST_LOBBY_EventWarps, 0, LILYCOVE_CITY_CONTEST_LOBBY_EventBgEvents
	.globl LILYCOVE_CITY_CONTEST_HALL_EventObjects
LILYCOVE_CITY_CONTEST_HALL_EventObjects: @ 0x08509F7C
	object_event 1, 7, 0, 30, 30, 3, 2, 4, 4, 0, 0, 0x082077BA, 0x0000
	object_event 2, 13, 0, 11, 7, 3, 2, 3, 3, 0, 0, 0x082077C3, 0x0000
	object_event 3, 14, 0, 40, 8, 3, 2, 2, 2, 0, 0, 0x082077CC, 0x0000
	object_event 4, 24, 0, 12, 22, 3, 8, 0, 0, 0, 0, 0x082077DE, 0x0000
	object_event 5, 190, 0, 15, 22, 3, 8, 0, 0, 0, 0, 0x082077F5, 0x0000
	object_event 6, 44, 0, 10, 25, 3, 7, 0, 0, 0, 0, 0x0820780C, 0x0000
	object_event 7, 21, 0, 12, 25, 3, 7, 0, 0, 0, 0, 0x08207823, 0x0000
	object_event 8, 39, 0, 14, 25, 3, 7, 0, 0, 0, 0, 0x0820783A, 0x0000
	object_event 9, 28, 0, 16, 25, 3, 7, 0, 0, 0, 0, 0x08207851, 0x0000
	object_event 10, 22, 0, 8, 24, 3, 10, 0, 0, 0, 0, 0x08207868, 0x0000
	object_event 11, 34, 0, 18, 24, 3, 9, 0, 0, 0, 0, 0x0820789F, 0x0000
	object_event 12, 7, 0, 8, 22, 3, 10, 0, 0, 0, 0, 0x08207871, 0x0000
	object_event 13, 24, 0, 24, 10, 3, 8, 0, 0, 0, 0, 0x082078B6, 0x0000
	object_event 14, 190, 0, 27, 10, 3, 8, 0, 0, 0, 0, 0x082078CD, 0x0000
	object_event 15, 26, 0, 22, 13, 3, 7, 0, 0, 0, 0, 0x082078E4, 0x0000
	object_event 16, 6, 0, 24, 13, 3, 7, 0, 0, 0, 0, 0x082078FB, 0x0000
	object_event 17, 37, 0, 26, 13, 3, 7, 0, 0, 0, 0, 0x08207912, 0x0000
	object_event 18, 18, 0, 28, 13, 3, 7, 0, 0, 0, 0, 0x08207929, 0x0000
	object_event 19, 20, 0, 20, 10, 3, 10, 0, 0, 0, 0, 0x08207940, 0x0000
	object_event 20, 16, 0, 30, 11, 3, 9, 0, 0, 0, 0, 0x0820796E, 0x0000
	object_event 21, 19, 0, 26, 8, 3, 8, 0, 0, 0, 0, 0x08207957, 0x0000
	object_event 22, 31, 0, 13, 20, 3, 8, 0, 0, 0, 0, 0x08207888, 0x0000
	object_event 23, 24, 0, 36, 22, 3, 8, 0, 0, 0, 0, 0x08207985, 0x0000
	object_event 24, 190, 0, 39, 22, 3, 8, 0, 0, 0, 0, 0x0820799C, 0x0000
	object_event 25, 9, 0, 34, 25, 3, 7, 0, 0, 0, 0, 0x082079B3, 0x0000
	object_event 26, 10, 0, 36, 25, 3, 7, 0, 0, 0, 0, 0x082079CA, 0x0000
	object_event 27, 13, 0, 38, 25, 3, 7, 0, 0, 0, 0, 0x082079E1, 0x0000
	object_event 28, 22, 0, 40, 25, 3, 7, 0, 0, 0, 0, 0x082079F8, 0x0000
	object_event 29, 20, 0, 32, 23, 3, 10, 0, 0, 0, 0, 0x08207A0F, 0x0000
	object_event 30, 19, 0, 37, 20, 3, 8, 0, 0, 0, 0, 0x08207A51, 0x0000
	object_event 31, 12, 0, 42, 24, 3, 9, 0, 0, 0, 0, 0x08207A3A, 0x0000
	object_event 32, 49, 0, 23, 26, 3, 2, 1, 1, 0, 0, 0x082077D5, 0x0000
	.globl LILYCOVE_CITY_CONTEST_HALL_EventWarps
LILYCOVE_CITY_CONTEST_HALL_EventWarps: @ 0x0850A27C
	warp_def 19, 32, 0, 2, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 30, 32, 0, 3, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 20, 32, 0, 2, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	warp_def 31, 32, 0, 3, MAP_LILYCOVE_CITY_CONTEST_LOBBY
	.globl LILYCOVE_CITY_CONTEST_HALL_EventBgEvents
LILYCOVE_CITY_CONTEST_HALL_EventBgEvents: @ 0x0850A29C
	bg_event 27, 16, 0, 0, 0x08207A68, 0, 0
	bg_event 39, 28, 0, 0, 0x08207A71, 0, 0
	bg_event 11, 28, 0, 0, 0x08207A7A, 0, 0
	bg_event 15, 28, 0, 0, 0x08207A7A, 0, 0
	bg_event 23, 16, 0, 0, 0x08207A68, 0, 0
	bg_event 35, 28, 0, 0, 0x08207A71, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_HALL
gMapEvents_LILYCOVE_CITY_CONTEST_HALL: @ 0x0850A2E4
	map_events LILYCOVE_CITY_CONTEST_HALL_EventObjects, LILYCOVE_CITY_CONTEST_HALL_EventWarps, 0, LILYCOVE_CITY_CONTEST_HALL_EventBgEvents
	.globl LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects
LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850A2F8
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_00208280, 0x0000
	object_event 2, 7, 0, 10, 7, 3, 10, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_0020828E, 0x0000
	object_event 3, 39, 0, 11, 8, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonCenter_1F_EventScript_00208297, 0x0000
	object_event 4, 240, 0, 1, 3, 3, 8, 0, 0, 0, 0, 0x08264373, 0x0000
	object_event 5, 241, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x082649CF, 0x03E1
	.globl LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps
LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850A370
	warp_def 7, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 6, 8, 3, 2, MAP_LILYCOVE_CITY
	warp_def 1, 6, 4, 0, MAP_LILYCOVE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F
gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F: @ 0x0850A388
	map_events LILYCOVE_CITY_POKEMON_CENTER_1F_EventObjects, LILYCOVE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects
LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850A39C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps
LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850A3FC
	warp_def 1, 6, 4, 2, MAP_LILYCOVE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F
gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F: @ 0x0850A414
	map_events LILYCOVE_CITY_POKEMON_CENTER_2F_EventObjects, LILYCOVE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_UNUSED_MART_EventObjects
LILYCOVE_CITY_UNUSED_MART_EventObjects: @ 0x00000000
	.globl LILYCOVE_CITY_UNUSED_MART_EventWarps
LILYCOVE_CITY_UNUSED_MART_EventWarps: @ 0x0850A428
	warp_def 3, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 0, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_UNUSED_MART
gMapEvents_LILYCOVE_CITY_UNUSED_MART: @ 0x0850A438
	map_events 0, LILYCOVE_CITY_UNUSED_MART_EventWarps, 0, 0
	.globl LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects
LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects: @ 0x0850A44C
	object_event 1, 47, 0, 3, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_002086A7, 0x0000
	object_event 2, 65, 0, 8, 10, 3, 9, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208630, 0x0000
	object_event 3, 25, 0, 6, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020871E, 0x0000
	object_event 4, 12, 0, 5, 8, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208795, 0x0000
	object_event 5, 5, 0, 7, 11, 3, 7, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020880C, 0x0317
	object_event 6, 9, 0, 1, 9, 3, 8, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_0020886E, 0x0316
	object_event 7, 24, 0, 3, 10, 3, 10, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_002088D0, 0x0318
	object_event 8, 22, 0, 10, 10, 3, 9, 0, 0, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208932, 0x0315
	object_event 9, 7, 0, 11, 5, 3, 8, 1, 1, 0, 0, LilycoveCity_PokemonTrainerFanClub_EventScript_00208994, 0x02DA
	.globl LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps
LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps: @ 0x0850A524
	warp_def 6, 13, 0, 5, MAP_LILYCOVE_CITY
	warp_def 5, 13, 0, 5, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x0850A534
	map_events LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventObjects, LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HARBOR_EventObjects
LILYCOVE_CITY_HARBOR_EventObjects: @ 0x0850A548
	object_event 1, 45, 0, 8, 10, 3, 8, 0, 0, 0, 0, LilycoveCity_Harbor_EventScript_002094E3, 0x038C
	object_event 2, 140, 0, 8, 9, 1, 10, 0, 0, 0, 0, 0x00000000, 0x035D
	object_event 3, 49, 0, 3, 13, 3, 2, 1, 1, 0, 0, LilycoveCity_Harbor_EventScript_00209B0B, 0x0000
	object_event 4, 49, 0, 8, 10, 3, 8, 0, 0, 0, 0, 0x00000000, 0x038D
	object_event 5, 21, 0, 8, 10, 3, 8, 1, 1, 0, 0, 0x00000000, 0x02EC
	.globl LILYCOVE_CITY_HARBOR_EventWarps
LILYCOVE_CITY_HARBOR_EventWarps: @ 0x0850A5C0
	warp_def 11, 14, 0, 12, MAP_LILYCOVE_CITY
	warp_def 12, 14, 0, 12, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HARBOR
gMapEvents_LILYCOVE_CITY_HARBOR: @ 0x0850A5D0
	map_events LILYCOVE_CITY_HARBOR_EventObjects, LILYCOVE_CITY_HARBOR_EventWarps, 0, 0
	.globl LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects
LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects: @ 0x0850A5E4
	object_event 1, 21, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08209D71, 0x0000
	.globl LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps
LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps: @ 0x0850A5FC
	warp_def 3, 7, 0, 7, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 7, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE
gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE: @ 0x0850A60C
	map_events LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventObjects, LILYCOVE_CITY_MOVE_DELETERS_HOUSE_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE1_EventObjects
LILYCOVE_CITY_HOUSE1_EventObjects: @ 0x0850A620
	object_event 1, 21, 0, 4, 5, 3, 9, 1, 1, 0, 0, 0x08209F67, 0x0000
	object_event 2, 204, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x08209F70, 0x0000
	.globl LILYCOVE_CITY_HOUSE1_EventWarps
LILYCOVE_CITY_HOUSE1_EventWarps: @ 0x0850A650
	warp_def 3, 8, 0, 8, MAP_LILYCOVE_CITY
	warp_def 4, 8, 0, 8, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE1
gMapEvents_LILYCOVE_CITY_HOUSE1: @ 0x0850A660
	map_events LILYCOVE_CITY_HOUSE1_EventObjects, LILYCOVE_CITY_HOUSE1_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE2_EventObjects
LILYCOVE_CITY_HOUSE2_EventObjects: @ 0x0850A674
	object_event 1, 17, 0, 0, 4, 3, 8, 0, 0, 0, 0, 0x08209FDD, 0x0000
	.globl LILYCOVE_CITY_HOUSE2_EventWarps
LILYCOVE_CITY_HOUSE2_EventWarps: @ 0x0850A68C
	warp_def 2, 7, 0, 9, MAP_LILYCOVE_CITY
	warp_def 3, 7, 0, 9, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE2
gMapEvents_LILYCOVE_CITY_HOUSE2: @ 0x0850A69C
	map_events LILYCOVE_CITY_HOUSE2_EventObjects, LILYCOVE_CITY_HOUSE2_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE3_EventObjects
LILYCOVE_CITY_HOUSE3_EventObjects: @ 0x0850A6B0
	object_event 1, 189, 0, 3, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A166, 0x0000
	object_event 2, 18, 0, 7, 4, 3, 9, 0, 0, 0, 0, LilycoveCity_House3_EventScript_0020A074, 0x0000
	object_event 3, 189, 0, 1, 4, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0FE, 0x0000
	object_event 4, 189, 0, 2, 5, 3, 7, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A132, 0x0000
	object_event 5, 189, 0, 2, 3, 3, 8, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0CA, 0x0000
	object_event 6, 19, 0, 7, 5, 3, 9, 1, 1, 0, 0, LilycoveCity_House3_EventScript_0020A0B3, 0x0000
	.globl LILYCOVE_CITY_HOUSE3_EventWarps
LILYCOVE_CITY_HOUSE3_EventWarps: @ 0x0850A740
	warp_def 3, 7, 0, 10, MAP_LILYCOVE_CITY
	warp_def 4, 7, 0, 10, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE3
gMapEvents_LILYCOVE_CITY_HOUSE3: @ 0x0850A750
	map_events LILYCOVE_CITY_HOUSE3_EventObjects, LILYCOVE_CITY_HOUSE3_EventWarps, 0, 0
	.globl LILYCOVE_CITY_HOUSE4_EventObjects
LILYCOVE_CITY_HOUSE4_EventObjects: @ 0x0850A764
	object_event 1, 65, 0, 1, 4, 3, 2, 1, 1, 0, 0, 0x0820A51B, 0x0000
	object_event 2, 19, 0, 7, 4, 3, 2, 1, 1, 0, 0, 0x0820A524, 0x0000
	.globl LILYCOVE_CITY_HOUSE4_EventWarps
LILYCOVE_CITY_HOUSE4_EventWarps: @ 0x0850A794
	warp_def 3, 8, 0, 11, MAP_LILYCOVE_CITY
	warp_def 4, 8, 0, 11, MAP_LILYCOVE_CITY
	.globl gMapEvents_LILYCOVE_CITY_HOUSE4
gMapEvents_LILYCOVE_CITY_HOUSE4: @ 0x0850A7A4
	map_events LILYCOVE_CITY_HOUSE4_EventObjects, LILYCOVE_CITY_HOUSE4_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects: @ 0x0850A7B8
	object_event 1, 45, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820A5B0, 0x0000
	object_event 2, 45, 0, 10, 2, 3, 8, 0, 0, 0, 0, 0x0820A5B9, 0x0000
	object_event 3, 18, 0, 14, 5, 3, 2, 1, 1, 0, 0, 0x0820A74C, 0x0000
	object_event 4, 12, 0, 4, 4, 3, 2, 1, 1, 0, 0, 0x0820A755, 0x0000
	object_event 5, 25, 0, 3, 6, 3, 2, 1, 1, 0, 0, 0x0820A75E, 0x0000
	object_event 6, 210, 0, 2, 6, 3, 1, 1, 1, 0, 0, 0x0820A767, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps: @ 0x0850A848
	warp_def 8, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 9, 7, 0, 0, MAP_LILYCOVE_CITY
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents
LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents: @ 0x0850A868
	bg_event 0, 8, 0, 1, 0x0820A77A, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x0850A874
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventWarps, 0, LILYCOVE_CITY_DEPARTMENT_STORE_1F_EventBgEvents
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects: @ 0x0850A888
	object_event 1, 27, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820A921, 0x0000
	object_event 2, 18, 0, 0, 5, 3, 2, 1, 1, 0, 0, 0x0820A92A, 0x0000
	object_event 3, 49, 0, 13, 5, 3, 2, 1, 1, 0, 0, 0x0820A933, 0x0000
	object_event 4, 24, 0, 10, 6, 3, 7, 0, 0, 0, 0, 0x0820A96E, 0x0000
	object_event 5, 24, 0, 7, 6, 3, 7, 0, 0, 0, 0, 0x0820A93C, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps: @ 0x0850A900
	warp_def 16, 1, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	warp_def 13, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x0850A918
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_2F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects: @ 0x0850A92C
	object_event 1, 51, 0, 0, 5, 3, 2, 1, 1, 0, 0, 0x0820AA6E, 0x0000
	object_event 2, 25, 0, 7, 7, 3, 2, 1, 1, 0, 0, 0x0820AA77, 0x0000
	object_event 3, 34, 0, 13, 5, 3, 2, 1, 1, 0, 0, 0x0820AA80, 0x0000
	object_event 4, 24, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x0820AA1A, 0x0000
	object_event 5, 24, 0, 10, 2, 3, 8, 1, 1, 0, 0, 0x0820AA44, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps: @ 0x0850A9A4
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x0850A9BC
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_3F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects: @ 0x0850A9D0
	object_event 1, 48, 0, 0, 2, 3, 2, 1, 1, 0, 0, 0x0820AB4F, 0x0000
	object_event 2, 20, 0, 6, 2, 3, 2, 1, 1, 0, 0, 0x0820AB58, 0x0000
	object_event 3, 35, 0, 13, 4, 3, 2, 1, 1, 0, 0, 0x0820AB61, 0x0000
	object_event 4, 24, 0, 7, 6, 3, 7, 0, 0, 0, 0, 0x0820AB6A, 0x0000
	object_event 5, 24, 0, 9, 6, 3, 7, 0, 0, 0, 0, 0x0820AB90, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps: @ 0x0850AA48
	warp_def 16, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	warp_def 13, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x0850AA60
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_4F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects: @ 0x0850AA74
	object_event 1, 12, 0, 1, 6, 3, 2, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD90, 0x0000
	object_event 2, 18, 0, 7, 7, 3, 17, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD40, 0x0000
	object_event 3, 24, 0, 7, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AC7A, 0x0000
	object_event 4, 24, 0, 9, 2, 3, 8, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020ACB0, 0x0000
	object_event 5, 24, 0, 15, 6, 3, 9, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020ACDE, 0x0000
	object_event 6, 24, 0, 17, 6, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD0E, 0x0000
	object_event 7, 20, 0, 9, 5, 3, 10, 1, 1, 0, 0, LilycoveCity_DepartmentStore_5F_EventScript_0020AD49, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps: @ 0x0850AB1C
	warp_def 13, 1, 0, 1, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	warp_def 2, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	warp_def 16, 1, 0, 0, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x0850AB34
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_5F_EventWarps, 0, 0
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects: @ 0x0850AB48
	object_event 1, 23, 0, 4, 4, 3, 7, 0, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEB4, 0x0000
	object_event 2, 33, 0, 7, 5, 3, 5, 1, 0, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AED8, 0x0000
	object_event 3, 84, 0, 6, 1, 3, 8, 1, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AE7B, 0x03C2
	object_event 4, 24, 0, 15, 5, 3, 8, 1, 0, 0, 0, 0x08276AA2, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps: @ 0x0850ABA8
	warp_def 13, 3, 0, 2, MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents
LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents: @ 0x0850ABB0
	bg_event 9, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEE1, 0, 0
	bg_event 10, 1, 0, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_0020AEE1, 0, 0
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x0850ABC8
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventWarps, 0, LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_EventBgEvents
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects
LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects: @ 0x0850ABDC
	object_event 1, 85, 0, 0, 5, 3, 8, 0, 0, 0, 0, 0x0820B18D, 0x0000
	.globl LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps
LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps: @ 0x0850ABF4
	warp_def 1, 5, 3, 127, 0x7F7F
	warp_def 2, 5, 3, 127, 0x7F7F
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x0850AC04
	map_events LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventObjects, LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_GYM_EventObjects
MOSSDEEP_CITY_GYM_EventObjects: @ 0x0850AC18
	object_event 1, 132, 0, 23, 7, 0, 8, 0, 0, 0, 0, 0x0820B401, 0x0000
	object_event 2, 37, 0, 1, 30, 3, 8, 0, 0, 1, 1, 0x0820B666, 0x0000
	object_event 3, 37, 0, 5, 20, 3, 7, 0, 0, 1, 1, 0x0820B694, 0x0000
	object_event 4, 47, 0, 4, 29, 3, 7, 0, 0, 1, 1, 0x0820B6D9, 0x0000
	object_event 5, 47, 0, 4, 23, 0, 7, 0, 0, 1, 1, 0x0820B6C2, 0x0000
	object_event 6, 37, 0, 6, 9, 3, 8, 0, 0, 1, 1, 0x0820B67D, 0x0000
	object_event 7, 47, 0, 6, 3, 0, 8, 0, 0, 1, 1, 0x0820B6AB, 0x0000
	object_event 8, 23, 0, 5, 33, 0, 8, 0, 0, 0, 0, MossdeepCity_Gym_EventScript_0020B77A, 0x0000
	object_event 9, 131, 0, 24, 7, 0, 8, 0, 0, 0, 0, 0x0820B401, 0x0000
	object_event 10, 224, 0, 2, 30, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 11, 224, 0, 1, 29, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 12, 224, 0, 4, 30, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 13, 224, 0, 5, 29, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 14, 224, 0, 5, 21, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 15, 224, 0, 7, 9, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 16, 224, 0, 10, 8, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 17, 48, 0, 9, 8, 3, 7, 1, 1, 1, 1, 0x0820B707, 0x0000
	object_event 18, 40, 0, 7, 5, 3, 10, 1, 1, 1, 1, 0x0820B6F0, 0x0000
	object_event 19, 224, 0, 6, 6, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 20, 224, 0, 12, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 21, 224, 0, 11, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 22, 224, 0, 11, 34, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 23, 224, 0, 12, 33, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 24, 224, 0, 12, 34, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 25, 48, 0, 22, 25, 3, 7, 1, 1, 1, 1, 0x0820B735, 0x0000
	object_event 26, 224, 0, 23, 26, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 27, 47, 0, 25, 25, 0, 9, 1, 1, 1, 1, 0x0820B71E, 0x0000
	object_event 28, 40, 0, 22, 23, 3, 8, 1, 1, 1, 1, 0x0820B763, 0x0000
	object_event 29, 224, 0, 21, 23, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 30, 224, 0, 21, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 31, 224, 0, 22, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 32, 37, 0, 25, 22, 3, 7, 1, 1, 1, 1, 0x0820B74C, 0x0000
	object_event 33, 224, 0, 24, 22, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 34, 224, 0, 24, 23, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 35, 224, 0, 6, 5, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	object_event 36, 224, 0, 23, 25, 3, 1, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl MOSSDEEP_CITY_GYM_EventWarps
MOSSDEEP_CITY_GYM_EventWarps: @ 0x0850AF78
	warp_def 6, 35, 3, 1, MAP_MOSSDEEP_CITY
	warp_def 7, 35, 3, 1, MAP_MOSSDEEP_CITY
	warp_def 3, 28, 0, 3, MAP_MOSSDEEP_CITY_GYM
	warp_def 1, 23, 3, 2, MAP_MOSSDEEP_CITY_GYM
	warp_def 7, 18, 0, 5, MAP_MOSSDEEP_CITY_GYM
	warp_def 8, 12, 0, 4, MAP_MOSSDEEP_CITY_GYM
	warp_def 9, 18, 0, 7, MAP_MOSSDEEP_CITY_GYM
	warp_def 23, 20, 0, 6, MAP_MOSSDEEP_CITY_GYM
	warp_def 1, 33, 3, 9, MAP_MOSSDEEP_CITY_GYM
	warp_def 20, 24, 0, 8, MAP_MOSSDEEP_CITY_GYM
	warp_def 11, 3, 0, 11, MAP_MOSSDEEP_CITY_GYM
	warp_def 11, 35, 3, 10, MAP_MOSSDEEP_CITY_GYM
	warp_def 13, 32, 0, 13, MAP_MOSSDEEP_CITY_GYM
	warp_def 21, 10, 0, 12, MAP_MOSSDEEP_CITY_GYM
	.globl MOSSDEEP_CITY_GYM_EventCoordEvents
MOSSDEEP_CITY_GYM_EventCoordEvents: @ 0x0850AFE8
	coord_event 2, 21, 3, 16385, 0, 0x0820B7D0
	coord_event 8, 10, 3, 16385, 0, 0x0820B7E6
	coord_event 6, 7, 3, 16385, 0, 0x0820B7E6
	coord_event 15, 34, 3, 16385, 0, 0x0820B7FC
	coord_event 23, 24, 3, 16385, 0, 0x0820B812
	coord_event 23, 21, 3, 16385, 0, 0x0820B812
	coord_event 8, 6, 3, 16385, 0, 0x0820B828
	coord_event 21, 6, 0, 16385, 0, 0x0820B65A
	coord_event 3, 30, 3, 16385, 0, 0x0820B7D0
	.globl MOSSDEEP_CITY_GYM_EventBgEvents
MOSSDEEP_CITY_GYM_EventBgEvents: @ 0x0850B078
	bg_event 4, 34, 0, 1, MossdeepCity_Gym_EventScript_0020B79C, 0, 0
	bg_event 8, 34, 0, 1, MossdeepCity_Gym_EventScript_0020B7AC, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_GYM
gMapEvents_MOSSDEEP_CITY_GYM: @ 0x0850B090
	map_events MOSSDEEP_CITY_GYM_EventObjects, MOSSDEEP_CITY_GYM_EventWarps, MOSSDEEP_CITY_GYM_EventCoordEvents, MOSSDEEP_CITY_GYM_EventBgEvents
	.globl MOSSDEEP_CITY_HOUSE1_EventObjects
MOSSDEEP_CITY_HOUSE1_EventObjects: @ 0x0850B0A4
	object_event 1, 44, 0, 3, 3, 3, 3, 1, 1, 0, 0, 0x0820C333, 0x0000
	object_event 2, 20, 0, 7, 4, 3, 9, 0, 0, 0, 0, 0x0820C363, 0x0000
	.globl MOSSDEEP_CITY_HOUSE1_EventWarps
MOSSDEEP_CITY_HOUSE1_EventWarps: @ 0x0850B0D4
	warp_def 3, 7, 0, 0, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 0, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE1
gMapEvents_MOSSDEEP_CITY_HOUSE1: @ 0x0850B0E4
	map_events MOSSDEEP_CITY_HOUSE1_EventObjects, MOSSDEEP_CITY_HOUSE1_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_HOUSE2_EventObjects
MOSSDEEP_CITY_HOUSE2_EventObjects: @ 0x0850B0F8
	object_event 1, 65, 0, 6, 6, 3, 9, 0, 0, 0, 0, 0x0820C3D3, 0x0000
	object_event 2, 6, 0, 4, 4, 3, 8, 0, 0, 0, 0, 0x0820C3DC, 0x0000
	object_event 3, 211, 0, 4, 5, 3, 7, 0, 0, 0, 0, 0x0820C3E5, 0x03A6
	.globl MOSSDEEP_CITY_HOUSE2_EventWarps
MOSSDEEP_CITY_HOUSE2_EventWarps: @ 0x0850B140
	warp_def 3, 8, 0, 3, MAP_MOSSDEEP_CITY
	warp_def 4, 8, 0, 3, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE2
gMapEvents_MOSSDEEP_CITY_HOUSE2: @ 0x0850B150
	map_events MOSSDEEP_CITY_HOUSE2_EventObjects, MOSSDEEP_CITY_HOUSE2_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects
MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850B164
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4C1, 0x0000
	object_event 2, 20, 0, 8, 4, 3, 7, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4CF, 0x0000
	object_event 3, 8, 0, 3, 5, 3, 1, 0, 0, 0, 0, MossdeepCity_PokemonCenter_1F_EventScript_0020C4D8, 0x0000
	.globl MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps
MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850B1AC
	warp_def 7, 8, 3, 2, MAP_MOSSDEEP_CITY
	warp_def 6, 8, 3, 2, MAP_MOSSDEEP_CITY
	warp_def 1, 6, 4, 0, MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F
gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F: @ 0x0850B1C4
	map_events MOSSDEEP_CITY_POKEMON_CENTER_1F_EventObjects, MOSSDEEP_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects
MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850B1D8
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	object_event 5, 34, 0, 11, 7, 3, 5, 1, 1, 0, 0, MossdeepCity_PokemonCenter_2F_EventScript_0020C571, 0x0000
	.globl MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps
MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850B250
	warp_def 1, 6, 4, 2, MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F
gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F: @ 0x0850B268
	map_events MOSSDEEP_CITY_POKEMON_CENTER_2F_EventObjects, MOSSDEEP_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_MART_EventObjects
MOSSDEEP_CITY_MART_EventObjects: @ 0x0850B27C
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x0820C5B3, 0x0000
	object_event 2, 34, 0, 1, 5, 3, 7, 0, 0, 0, 0, 0x0820C5E2, 0x0000
	object_event 3, 9, 0, 8, 3, 3, 3, 0, 1, 0, 0, 0x0820C5EB, 0x0000
	object_event 4, 49, 0, 5, 3, 3, 2, 1, 1, 0, 0, 0x0820C5F4, 0x0000
	.globl MOSSDEEP_CITY_MART_EventWarps
MOSSDEEP_CITY_MART_EventWarps: @ 0x0850B2DC
	warp_def 3, 7, 0, 4, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 4, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_MART
gMapEvents_MOSSDEEP_CITY_MART: @ 0x0850B2EC
	map_events MOSSDEEP_CITY_MART_EventObjects, MOSSDEEP_CITY_MART_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_HOUSE3_EventObjects
MOSSDEEP_CITY_HOUSE3_EventObjects: @ 0x0850B300
	object_event 1, 50, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x0820C6FB, 0x0000
	.globl MOSSDEEP_CITY_HOUSE3_EventWarps
MOSSDEEP_CITY_HOUSE3_EventWarps: @ 0x0850B318
	warp_def 3, 7, 0, 5, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 5, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE3
gMapEvents_MOSSDEEP_CITY_HOUSE3: @ 0x0850B328
	map_events MOSSDEEP_CITY_HOUSE3_EventObjects, MOSSDEEP_CITY_HOUSE3_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects
MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects: @ 0x0850B33C
	object_event 1, 134, 0, 9, 6, 3, 10, 0, 0, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C9A4, 0x03C7
	object_event 2, 59, 0, 4, 3, 3, 1, 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C8D3, 0x03C8
	object_event 3, 5, 0, 6, 4, 3, 76, 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C9AD, 0x02D7
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps
MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps: @ 0x0850B384
	warp_def 3, 7, 0, 6, MAP_MOSSDEEP_CITY
	warp_def 4, 7, 0, 6, MAP_MOSSDEEP_CITY
	.globl MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents
MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents: @ 0x0850B394
	bg_event 0, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 1, 1, 0, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 10, 4, 3, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	bg_event 10, 6, 3, 0, MossdeepCity_StevensHouse_EventScript_0020C99B, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE
gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x0850B3C4
	map_events MOSSDEEP_CITY_STEVENS_HOUSE_EventObjects, MOSSDEEP_CITY_STEVENS_HOUSE_EventWarps, 0, MOSSDEEP_CITY_STEVENS_HOUSE_EventBgEvents
	.globl MOSSDEEP_CITY_HOUSE4_EventObjects
MOSSDEEP_CITY_HOUSE4_EventObjects: @ 0x0850B3D8
	object_event 1, 20, 0, 3, 4, 3, 9, 0, 0, 0, 0, 0x0820CC5C, 0x0000
	object_event 2, 5, 0, 6, 6, 3, 5, 1, 0, 0, 0, 0x0820CC7B, 0x0000
	object_event 3, 203, 0, 2, 4, 3, 1, 1, 1, 0, 0, 0x0820CCA2, 0x0000
	.globl MOSSDEEP_CITY_HOUSE4_EventWarps
MOSSDEEP_CITY_HOUSE4_EventWarps: @ 0x0850B420
	warp_def 4, 7, 0, 7, MAP_MOSSDEEP_CITY
	warp_def 3, 7, 0, 7, MAP_MOSSDEEP_CITY
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE4
gMapEvents_MOSSDEEP_CITY_HOUSE4: @ 0x0850B430
	map_events MOSSDEEP_CITY_HOUSE4_EventObjects, MOSSDEEP_CITY_HOUSE4_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects
MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects: @ 0x0850B444
	object_event 1, 46, 0, 7, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CDF4, 0x0000
	object_event 2, 46, 0, 2, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CE7F, 0x0000
	object_event 3, 49, 0, 6, 6, 3, 9, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CEAA, 0x0000
	object_event 4, 29, 0, 10, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CF84, 0x0000
	object_event 5, 26, 0, 14, 7, 3, 3, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CF49, 0x0000
	object_event 6, 120, 0, 12, 9, 3, 9, 1, 1, 1, 2, 0x0820CFF6, 0x02F4
	object_event 7, 119, 0, 11, 6, 3, 9, 1, 1, 1, 2, 0x0820D00D, 0x02F4
	object_event 8, 119, 0, 10, 2, 3, 8, 1, 1, 1, 2, 0x0820D024, 0x02F4
	object_event 9, 119, 0, 13, 2, 3, 8, 1, 1, 1, 0, 0x0820D03B, 0x02F4
	object_event 10, 5, 0, 2, 5, 0, 76, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CFEB, 0x02E1
	object_event 11, 134, 0, 1, 4, 3, 8, 1, 1, 0, 0, MossdeepCity_SpaceCenter_1F_EventScript_0020CFD5, 0x02F1
	.globl MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps
MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps: @ 0x0850B54C
	warp_def 7, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 8, 9, 0, 8, MAP_MOSSDEEP_CITY
	warp_def 13, 1, 0, 0, MAP_MOSSDEEP_CITY_SPACE_CENTER_2F
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x0850B564
	map_events MOSSDEEP_CITY_SPACE_CENTER_1F_EventObjects, MOSSDEEP_CITY_SPACE_CENTER_1F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects
MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects: @ 0x0850B578
	object_event 1, 15, 0, 6, 2, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D82D, 0x0000
	object_event 2, 48, 0, 11, 8, 3, 7, 0, 0, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D7F2, 0x0000
	object_event 3, 46, 0, 5, 6, 3, 2, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D7B7, 0x0000
	object_event 4, 134, 0, 1, 8, 3, 8, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D8A4, 0x035F
	object_event 5, 119, 0, 12, 2, 3, 10, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D868, 0x035E
	object_event 6, 119, 0, 13, 3, 3, 7, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D87A, 0x035E
	object_event 7, 119, 0, 14, 2, 3, 9, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D871, 0x035E
	object_event 8, 119, 0, 0, 8, 3, 10, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D883, 0x035E
	object_event 9, 196, 0, 1, 9, 3, 7, 1, 1, 0, 0, MossdeepCity_SpaceCenter_2F_EventScript_0020D899, 0x035E
	.globl MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps
MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps: @ 0x0850B650
	warp_def 13, 1, 0, 2, MAP_MOSSDEEP_CITY_SPACE_CENTER_1F
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x0850B658
	map_events MOSSDEEP_CITY_SPACE_CENTER_2F_EventObjects, MOSSDEEP_CITY_SPACE_CENTER_2F_EventWarps, 0, 0
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects
MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects: @ 0x0850B66C
	object_event 1, 21, 0, 6, 2, 0, 8, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E04B, 0x0000
	object_event 2, 65, 0, 4, 2, 0, 8, 0, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E042, 0x0000
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps
MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps: @ 0x0850B69C
	warp_def 5, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 6, 9, 0, 9, MAP_MOSSDEEP_CITY
	warp_def 2, 0, 0, 0, MAP_MOSSDEEP_CITY_GAME_CORNER_B1F
	.globl MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents
MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents: @ 0x0850B6B4
	bg_event 3, 0, 0, 0, MossdeepCity_GameCorner_1F_EventScript_0020E054, 0, 0
	bg_event 0, 1, 0, 0, 0x08247B79, 0, 0
	bg_event 1, 1, 0, 0, 0x08247B72, 0, 0
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F
gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x0850B6D8
	map_events MOSSDEEP_CITY_GAME_CORNER_1F_EventObjects, MOSSDEEP_CITY_GAME_CORNER_1F_EventWarps, 0, MOSSDEEP_CITY_GAME_CORNER_1F_EventBgEvents
	.globl MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects
MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects: @ 0x0850B6EC
	object_event 1, 240, 0, 6, 5, 3, 9, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps
MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps: @ 0x0850B704
	warp_def 3, 1, 0, 2, MAP_MOSSDEEP_CITY_GAME_CORNER_1F
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x0850B70C
	map_events MOSSDEEP_CITY_GAME_CORNER_B1F_EventObjects, MOSSDEEP_CITY_GAME_CORNER_B1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_GYM_1F_EventObjects
SOOTOPOLIS_CITY_GYM_1F_EventObjects: @ 0x0850B720
	object_event 1, 218, 0, 8, 2, 0, 8, 0, 0, 0, 0, 0x0820E31C, 0x0000
	object_event 2, 23, 0, 7, 24, 3, 8, 0, 0, 0, 0, SootopolisCity_Gym_1F_EventScript_0020E418, 0x0000
	.globl SOOTOPOLIS_CITY_GYM_1F_EventWarps
SOOTOPOLIS_CITY_GYM_1F_EventWarps: @ 0x0850B750
	warp_def 8, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 9, 25, 0, 2, MAP_SOOTOPOLIS_CITY
	warp_def 11, 22, 3, 0, MAP_SOOTOPOLIS_CITY_GYM_B1F
	.globl SOOTOPOLIS_CITY_GYM_1F_EventBgEvents
SOOTOPOLIS_CITY_GYM_1F_EventBgEvents: @ 0x0850B768
	bg_event 6, 24, 0, 0, SootopolisCity_Gym_1F_EventScript_0020E437, 0, 0
	bg_event 10, 24, 0, 1, SootopolisCity_Gym_1F_EventScript_0020E447, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_1F
gMapEvents_SOOTOPOLIS_CITY_GYM_1F: @ 0x0850B780
	map_events SOOTOPOLIS_CITY_GYM_1F_EventObjects, SOOTOPOLIS_CITY_GYM_1F_EventWarps, 0, SOOTOPOLIS_CITY_GYM_1F_EventBgEvents
	.globl SOOTOPOLIS_CITY_GYM_B1F_EventObjects
SOOTOPOLIS_CITY_GYM_B1F_EventObjects: @ 0x0850B794
	object_event 1, 47, 0, 7, 17, 3, 10, 0, 0, 1, 1, 0x0820EAC7, 0x0000
	object_event 2, 45, 0, 9, 19, 3, 9, 0, 0, 1, 1, 0x0820EB0C, 0x0000
	object_event 3, 20, 0, 12, 7, 3, 9, 0, 0, 1, 1, 0x0820EAF5, 0x0000
	object_event 4, 45, 0, 11, 9, 0, 7, 0, 0, 1, 5, 0x0820EB23, 0x0000
	object_event 5, 45, 0, 5, 6, 3, 8, 0, 0, 1, 4, 0x0820EB51, 0x0000
	object_event 6, 18, 0, 7, 8, 3, 10, 0, 0, 1, 2, 0x0820EB68, 0x0000
	object_event 7, 47, 0, 4, 8, 3, 10, 0, 0, 1, 2, 0x0820EADE, 0x0000
	object_event 8, 45, 0, 9, 7, 3, 8, 0, 0, 1, 3, 0x0820EB3A, 0x0000
	object_event 9, 20, 0, 6, 13, 3, 10, 1, 1, 1, 3, 0x0820EB96, 0x0000
	object_event 10, 18, 0, 10, 13, 3, 9, 1, 1, 1, 3, 0x0820EB7F, 0x0000
	.globl SOOTOPOLIS_CITY_GYM_B1F_EventWarps
SOOTOPOLIS_CITY_GYM_B1F_EventWarps: @ 0x0850B884
	warp_def 11, 22, 3, 2, MAP_SOOTOPOLIS_CITY_GYM_1F
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_B1F
gMapEvents_SOOTOPOLIS_CITY_GYM_B1F: @ 0x0850B88C
	map_events SOOTOPOLIS_CITY_GYM_B1F_EventObjects, SOOTOPOLIS_CITY_GYM_B1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects
SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850B8A0
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020EFE4, 0x0000
	object_event 2, 48, 0, 12, 4, 3, 2, 1, 1, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020EFF2, 0x0000
	object_event 3, 34, 0, 4, 7, 3, 5, 1, 0, 0, 0, SootopolisCity_PokemonCenter_1F_EventScript_0020F01C, 0x0000
	object_event 4, 16, 0, 2, 3, 3, 2, 1, 1, 0, 0, 0x08276B72, 0x0000
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps
SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850B900
	warp_def 7, 8, 3, 0, MAP_SOOTOPOLIS_CITY
	warp_def 6, 8, 3, 0, MAP_SOOTOPOLIS_CITY
	warp_def 1, 6, 4, 0, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F: @ 0x0850B918
	map_events SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventObjects, SOOTOPOLIS_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects
SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850B92C
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps
SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850B98C
	warp_def 1, 6, 4, 2, MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F: @ 0x0850B9A4
	map_events SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventObjects, SOOTOPOLIS_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_MART_EventObjects
SOOTOPOLIS_CITY_MART_EventObjects: @ 0x0850B9B8
	object_event 1, 83, 0, 1, 3, 3, 10, 0, 0, 0, 0, 0x0820F1B8, 0x0000
	object_event 2, 17, 0, 5, 5, 3, 10, 0, 0, 0, 0, 0x0820F1E6, 0x0000
	object_event 3, 48, 0, 9, 5, 3, 10, 0, 0, 0, 0, 0x0820F210, 0x0000
	.globl SOOTOPOLIS_CITY_MART_EventWarps
SOOTOPOLIS_CITY_MART_EventWarps: @ 0x0850BA00
	warp_def 3, 7, 0, 1, MAP_SOOTOPOLIS_CITY
	warp_def 4, 7, 0, 1, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_MART
gMapEvents_SOOTOPOLIS_CITY_MART: @ 0x0850BA10
	map_events SOOTOPOLIS_CITY_MART_EventObjects, SOOTOPOLIS_CITY_MART_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE1_EventObjects
SOOTOPOLIS_CITY_HOUSE1_EventObjects: @ 0x0850BA24
	object_event 1, 44, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F301, 0x0000
	object_event 2, 204, 0, 2, 3, 3, 8, 0, 0, 0, 0, 0x0820F342, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE1_EventWarps
SOOTOPOLIS_CITY_HOUSE1_EventWarps: @ 0x0850BA54
	warp_def 3, 6, 0, 4, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 4, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE1
gMapEvents_SOOTOPOLIS_CITY_HOUSE1: @ 0x0850BA64
	map_events SOOTOPOLIS_CITY_HOUSE1_EventObjects, SOOTOPOLIS_CITY_HOUSE1_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE2_EventObjects
SOOTOPOLIS_CITY_HOUSE2_EventObjects: @ 0x0850BA78
	object_event 1, 22, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x0820F3C7, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE2_EventWarps
SOOTOPOLIS_CITY_HOUSE2_EventWarps: @ 0x0850BA90
	warp_def 3, 6, 0, 5, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 5, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE2
gMapEvents_SOOTOPOLIS_CITY_HOUSE2: @ 0x0850BAA0
	map_events SOOTOPOLIS_CITY_HOUSE2_EventObjects, SOOTOPOLIS_CITY_HOUSE2_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE3_EventObjects
SOOTOPOLIS_CITY_HOUSE3_EventObjects: @ 0x0850BAB4
	object_event 1, 26, 0, 2, 4, 3, 8, 0, 0, 0, 0, 0x0820F47A, 0x0000
	object_event 2, 10, 0, 6, 4, 3, 2, 1, 1, 0, 0, 0x0820F4A3, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE3_EventWarps
SOOTOPOLIS_CITY_HOUSE3_EventWarps: @ 0x0850BAE4
	warp_def 3, 6, 0, 6, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 6, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE3
gMapEvents_SOOTOPOLIS_CITY_HOUSE3: @ 0x0850BAF4
	map_events SOOTOPOLIS_CITY_HOUSE3_EventObjects, SOOTOPOLIS_CITY_HOUSE3_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE4_EventObjects
SOOTOPOLIS_CITY_HOUSE4_EventObjects: @ 0x0850BB08
	object_event 1, 19, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F594, 0x0000
	object_event 2, 26, 0, 5, 2, 3, 7, 1, 2, 0, 0, 0x0820F59D, 0x0000
	object_event 3, 210, 0, 2, 3, 3, 1, 1, 1, 0, 0, 0x0820F5A6, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE4_EventWarps
SOOTOPOLIS_CITY_HOUSE4_EventWarps: @ 0x0850BB50
	warp_def 3, 6, 0, 7, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 7, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE4
gMapEvents_SOOTOPOLIS_CITY_HOUSE4: @ 0x0850BB60
	map_events SOOTOPOLIS_CITY_HOUSE4_EventObjects, SOOTOPOLIS_CITY_HOUSE4_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE5_EventObjects
SOOTOPOLIS_CITY_HOUSE5_EventObjects: @ 0x0850BB74
	object_event 1, 39, 0, 3, 3, 3, 10, 0, 0, 0, 0, 0x0820F658, 0x0000
	object_event 2, 14, 0, 6, 3, 3, 9, 0, 0, 0, 0, 0x0820F661, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE5_EventWarps
SOOTOPOLIS_CITY_HOUSE5_EventWarps: @ 0x0850BBA4
	warp_def 3, 6, 0, 8, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 8, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE5
gMapEvents_SOOTOPOLIS_CITY_HOUSE5: @ 0x0850BBB4
	map_events SOOTOPOLIS_CITY_HOUSE5_EventObjects, SOOTOPOLIS_CITY_HOUSE5_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE6_EventObjects
SOOTOPOLIS_CITY_HOUSE6_EventObjects: @ 0x0850BBC8
	object_event 1, 20, 0, 4, 3, 3, 2, 1, 1, 0, 0, 0x0820F6D1, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE6_EventWarps
SOOTOPOLIS_CITY_HOUSE6_EventWarps: @ 0x0850BBE0
	warp_def 3, 6, 0, 9, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 9, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE6
gMapEvents_SOOTOPOLIS_CITY_HOUSE6: @ 0x0850BBF0
	map_events SOOTOPOLIS_CITY_HOUSE6_EventObjects, SOOTOPOLIS_CITY_HOUSE6_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_HOUSE7_EventObjects
SOOTOPOLIS_CITY_HOUSE7_EventObjects: @ 0x0850BC04
	object_event 1, 29, 0, 5, 3, 3, 9, 0, 0, 0, 0, 0x0820F7BB, 0x0000
	object_event 2, 18, 0, 1, 4, 3, 2, 1, 1, 0, 0, 0x0820F7C4, 0x0000
	.globl SOOTOPOLIS_CITY_HOUSE7_EventWarps
SOOTOPOLIS_CITY_HOUSE7_EventWarps: @ 0x0850BC34
	warp_def 3, 6, 0, 10, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 10, MAP_SOOTOPOLIS_CITY
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE7
gMapEvents_SOOTOPOLIS_CITY_HOUSE7: @ 0x0850BC44
	map_events SOOTOPOLIS_CITY_HOUSE7_EventObjects, SOOTOPOLIS_CITY_HOUSE7_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects: @ 0x0850BC58
	object_event 1, 50, 0, 2, 4, 3, 10, 0, 0, 0, 0, 0x0820F8F3, 0x0000
	object_event 2, 55, 0, 5, 4, 3, 9, 0, 0, 0, 0, 0x0820F862, 0x0000
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps: @ 0x0850BC88
	warp_def 3, 6, 0, 11, MAP_SOOTOPOLIS_CITY
	warp_def 4, 6, 0, 11, MAP_SOOTOPOLIS_CITY
	.globl SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents
SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents: @ 0x0850BC98
	bg_event 5, 1, 0, 0, 0x0820F984, 0, 0
	bg_event 2, 1, 0, 0, 0x0820F992, 0, 0
	.globl gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0850BCB0
	map_events SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventObjects, SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventWarps, 0, SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_EventBgEvents
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects: @ 0x0850BCC4
	object_event 1, 29, 0, 6, 4, 0, 10, 0, 0, 0, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_0020FE31, 0x0000
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps: @ 0x0850BCDC
	warp_def 3, 7, 0, 12, MAP_SOOTOPOLIS_CITY
	warp_def 4, 7, 0, 12, MAP_SOOTOPOLIS_CITY
	warp_def 3, 1, 3, 0, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0850BCF4
	map_events SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventObjects, SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_EventWarps, 0, 0
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects: @ 0x0850BD08
	object_event 1, 240, 0, 6, 5, 0, 9, 1, 1, 0, 0, 0x00000000, 0x0000
	.globl SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps
SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps: @ 0x0850BD20
	warp_def 3, 1, 0, 2, MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0850BD28
	map_events SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventObjects, SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects
EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects: @ 0x0850BD3C
	object_event 1, 121, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x08210249, 0x0000
	.globl EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps
EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps: @ 0x0850BD54
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL1
	.globl gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x0850BD64
	map_events EVER_GRANDE_CITY_SIDNEYS_ROOM_EventObjects, EVER_GRANDE_CITY_SIDNEYS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects
EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects: @ 0x0850BD78
	object_event 1, 122, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x082103C8, 0x0000
	.globl EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps
EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps: @ 0x0850BD90
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL1
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL2
	.globl gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x0850BDA0
	map_events EVER_GRANDE_CITY_PHOEBES_ROOM_EventObjects, EVER_GRANDE_CITY_PHOEBES_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects
EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects: @ 0x0850BDB4
	object_event 1, 123, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x0821057A, 0x0000
	.globl EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps
EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps: @ 0x0850BDCC
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL2
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL3
	.globl gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x0850BDDC
	map_events EVER_GRANDE_CITY_GLACIAS_ROOM_EventObjects, EVER_GRANDE_CITY_GLACIAS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects
EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects: @ 0x0850BDF0
	object_event 1, 124, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x08210715, 0x0000
	.globl EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps
EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps: @ 0x0850BE08
	warp_def 6, 13, 3, 1, MAP_EVER_GRANDE_CITY_HALL3
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL4
	.globl gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM
gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x0850BE18
	map_events EVER_GRANDE_CITY_DRAKES_ROOM_EventObjects, EVER_GRANDE_CITY_DRAKES_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects
EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects: @ 0x0850BE2C
	object_event 1, 133, 0, 6, 5, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0000
	object_event 2, 240, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0398
	object_event 3, 64, 0, 6, 12, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0399
	.globl EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps
EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps: @ 0x0850BE74
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_HALL4
	warp_def 6, 2, 0, 0, MAP_EVER_GRANDE_CITY_HALL_OF_FAME
	.globl gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x0850BE84
	map_events EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventObjects, EVER_GRANDE_CITY_CHAMPIONS_ROOM_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL1_EventObjects
EVER_GRANDE_CITY_HALL1_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL1_EventWarps
EVER_GRANDE_CITY_HALL1_EventWarps: @ 0x0850BE98
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL1
gMapEvents_EVER_GRANDE_CITY_HALL1: @ 0x0850BEB8
	map_events 0, EVER_GRANDE_CITY_HALL1_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL2_EventObjects
EVER_GRANDE_CITY_HALL2_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL2_EventWarps
EVER_GRANDE_CITY_HALL2_EventWarps: @ 0x0850BECC
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_PHOEBES_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL2
gMapEvents_EVER_GRANDE_CITY_HALL2: @ 0x0850BEEC
	map_events 0, EVER_GRANDE_CITY_HALL2_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL3_EventObjects
EVER_GRANDE_CITY_HALL3_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL3_EventWarps
EVER_GRANDE_CITY_HALL3_EventWarps: @ 0x0850BF00
	warp_def 5, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_DRAKES_ROOM
	warp_def 4, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	warp_def 6, 12, 3, 1, MAP_EVER_GRANDE_CITY_GLACIAS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL3
gMapEvents_EVER_GRANDE_CITY_HALL3: @ 0x0850BF20
	map_events 0, EVER_GRANDE_CITY_HALL3_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL4_EventObjects
EVER_GRANDE_CITY_HALL4_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL4_EventWarps
EVER_GRANDE_CITY_HALL4_EventWarps: @ 0x0850BF34
	warp_def 5, 33, 3, 1, MAP_EVER_GRANDE_CITY_DRAKES_ROOM
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL4
gMapEvents_EVER_GRANDE_CITY_HALL4: @ 0x0850BF44
	map_events 0, EVER_GRANDE_CITY_HALL4_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL5_EventObjects
EVER_GRANDE_CITY_HALL5_EventObjects: @ 0x00000000
	.globl EVER_GRANDE_CITY_HALL5_EventWarps
EVER_GRANDE_CITY_HALL5_EventWarps: @ 0x0850BF58
	warp_def 5, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 5, 2, 0, 0, MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM
	warp_def 4, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 6, 12, 3, 2, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	.globl gMapEvents_EVER_GRANDE_CITY_HALL5
gMapEvents_EVER_GRANDE_CITY_HALL5: @ 0x0850BF78
	map_events 0, EVER_GRANDE_CITY_HALL5_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects
EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects: @ 0x0850BF8C
	object_event 1, 58, 0, 3, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_002110FE, 0x0000
	object_event 2, 83, 0, 16, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_0021110C, 0x0000
	object_event 3, 33, 0, 8, 2, 3, 8, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_00211136, 0x0000
	object_event 4, 33, 0, 11, 2, 3, 8, 1, 1, 0, 0, EverGrandeCity_PokemonLeague_1F_EventScript_00211136, 0x0000
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps
EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps: @ 0x0850BFEC
	warp_def 9, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 10, 11, 3, 0, MAP_EVER_GRANDE_CITY
	warp_def 9, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 10, 1, 3, 0, MAP_EVER_GRANDE_CITY_HALL5
	warp_def 1, 7, 4, 0, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x0850C014
	map_events EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventObjects, EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects
EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects: @ 0x0850C028
	object_event 1, 133, 0, 6, 16, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps
EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps: @ 0x0850C040
	warp_def 7, 11, 3, 1, MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM
	.globl gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME
gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0850C048
	map_events EVER_GRANDE_CITY_HALL_OF_FAME_EventObjects, EVER_GRANDE_CITY_HALL_OF_FAME_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects
EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects: @ 0x0850C05C
	object_event 1, 58, 0, 7, 2, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211421, 0x0000
	object_event 2, 34, 0, 5, 5, 3, 8, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_0021142F, 0x0000
	object_event 3, 21, 0, 10, 7, 3, 10, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211438, 0x0000
	object_event 4, 219, 0, 9, 4, 3, 7, 0, 0, 0, 0, EverGrandeCity_PokemonCenter_1F_EventScript_00211441, 0x0319
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps
EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps: @ 0x0850C0BC
	warp_def 7, 8, 3, 1, MAP_EVER_GRANDE_CITY
	warp_def 6, 8, 3, 1, MAP_EVER_GRANDE_CITY
	warp_def 1, 6, 4, 0, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F
gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F: @ 0x0850C0D4
	map_events EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventObjects, EVER_GRANDE_CITY_POKEMON_CENTER_1F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects
EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects: @ 0x0850C0E8
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 3, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps
EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps: @ 0x0850C148
	warp_def 1, 6, 4, 2, MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F
gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F: @ 0x0850C160
	map_events EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventObjects, EVER_GRANDE_CITY_POKEMON_CENTER_2F_EventWarps, 0, 0
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects
EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects: @ 0x0850C174
	object_event 1, 85, 0, 6, 2, 0, 8, 1, 1, 0, 0, 0x08244185, 0x0000
	object_event 2, 85, 0, 2, 2, 0, 8, 1, 1, 0, 0, 0x0824418B, 0x0000
	object_event 3, 85, 0, 10, 2, 0, 8, 1, 1, 0, 0, 0x08244191, 0x0000
	object_event 4, 223, 0, 1, 2, 0, 8, 1, 1, 0, 0, 0x08246801, 0x02BE
	.globl EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps
EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps: @ 0x0850C1D4
	warp_def 1, 6, 4, 4, MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	warp_def 5, 1, 3, 0, MAP_UNION_ROOM
	warp_def 9, 1, 3, 0, MAP_TRADE_CENTER
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F
gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F: @ 0x0850C1EC
	map_events EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventObjects, EVER_GRANDE_CITY_POKEMON_LEAGUE_2F_EventWarps, 0, 0
	.globl ROUTE104_MR_BRINEYS_HOUSE_EventObjects
ROUTE104_MR_BRINEYS_HOUSE_EventObjects: @ 0x0850C200
	object_event 1, 21, 0, 5, 3, 3, 50, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_00211629, 0x02E3
	object_event 2, 211, 0, 6, 3, 3, 8, 3, 3, 0, 0, Route104_MrBrineysHouse_EventScript_0021171F, 0x0371
	.globl ROUTE104_MR_BRINEYS_HOUSE_EventWarps
ROUTE104_MR_BRINEYS_HOUSE_EventWarps: @ 0x0850C230
	warp_def 5, 8, 0, 0, MAP_ROUTE104
	warp_def 6, 8, 0, 0, MAP_ROUTE104
	.globl gMapEvents_ROUTE104_MR_BRINEYS_HOUSE
gMapEvents_ROUTE104_MR_BRINEYS_HOUSE: @ 0x0850C240
	map_events ROUTE104_MR_BRINEYS_HOUSE_EventObjects, ROUTE104_MR_BRINEYS_HOUSE_EventWarps, 0, 0
	.globl ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects
ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects: @ 0x0850C254
	object_event 1, 20, 0, 0, 3, 3, 10, 0, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_002119DB, 0x0000
	object_event 2, 14, 0, 7, 3, 3, 5, 1, 0, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_00211A74, 0x0000
	object_event 3, 8, 0, 11, 6, 4, 2, 2, 2, 0, 0, Route104_PrettyPetalFlowerShop_EventScript_00211AAA, 0x0000
	.globl ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps
ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps: @ 0x0850C29C
	warp_def 2, 8, 0, 1, MAP_ROUTE104
	warp_def 3, 8, 0, 1, MAP_ROUTE104
	.globl gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x0850C2AC
	map_events ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventObjects, ROUTE104_PRETTY_PETAL_FLOWER_SHOP_EventWarps, 0, 0
	.globl ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects
ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects: @ 0x0850C2C0
	object_event 1, 47, 0, 7, 5, 3, 9, 0, 0, 0, 0, 0x08211B50, 0x0000
	object_event 2, 19, 0, 4, 5, 3, 10, 0, 0, 0, 0, 0x08211AF5, 0x0000
	object_event 3, 18, 0, 7, 4, 3, 9, 1, 0, 0, 0, 0x08211B0A, 0x0000
	object_event 4, 22, 0, 4, 4, 3, 10, 0, 0, 0, 0, 0x08211B65, 0x0000
	.globl ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps
ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps: @ 0x0850C320
	warp_def 3, 7, 0, 0, MAP_ROUTE111
	warp_def 4, 7, 0, 0, MAP_ROUTE111
	.globl gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE
gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE: @ 0x0850C330
	map_events ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventObjects, ROUTE111_WINSTRATE_FAMILYS_HOUSE_EventWarps, 0, 0
	.globl ROUTE111_OLD_LADYS_REST_STOP_EventObjects
ROUTE111_OLD_LADYS_REST_STOP_EventObjects: @ 0x0850C344
	object_event 1, 22, 0, 6, 3, 3, 9, 0, 0, 0, 0, Route111_OldLadysRestStop_EventScript_00211DF7, 0x0000
	.globl ROUTE111_OLD_LADYS_REST_STOP_EventWarps
ROUTE111_OLD_LADYS_REST_STOP_EventWarps: @ 0x0850C35C
	warp_def 3, 7, 0, 2, MAP_ROUTE111
	warp_def 4, 7, 0, 2, MAP_ROUTE111
	.globl gMapEvents_ROUTE111_OLD_LADYS_REST_STOP
gMapEvents_ROUTE111_OLD_LADYS_REST_STOP: @ 0x0850C36C
	map_events ROUTE111_OLD_LADYS_REST_STOP_EventObjects, ROUTE111_OLD_LADYS_REST_STOP_EventWarps, 0, 0
	.globl ROUTE112_CABLE_CAR_STATION_EventObjects
ROUTE112_CABLE_CAR_STATION_EventObjects: @ 0x0850C380
	object_event 1, 45, 0, 6, 6, 3, 8, 0, 0, 0, 0, Route112_CableCarStation_EventScript_00211F63, 0x0000
	object_event 2, 114, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl ROUTE112_CABLE_CAR_STATION_EventWarps
ROUTE112_CABLE_CAR_STATION_EventWarps: @ 0x0850C3B0
	warp_def 6, 11, 0, 0, MAP_ROUTE112
	warp_def 7, 11, 0, 1, MAP_ROUTE112
	.globl gMapEvents_ROUTE112_CABLE_CAR_STATION
gMapEvents_ROUTE112_CABLE_CAR_STATION: @ 0x0850C3C0
	map_events ROUTE112_CABLE_CAR_STATION_EventObjects, ROUTE112_CABLE_CAR_STATION_EventWarps, 0, 0
	.globl MT_CHIMNEY_CABLE_CAR_STATION_EventObjects
MT_CHIMNEY_CABLE_CAR_STATION_EventObjects: @ 0x0850C3D4
	object_event 1, 45, 0, 6, 6, 3, 8, 0, 0, 0, 0, MtChimney_CableCarStation_EventScript_00212070, 0x0000
	object_event 2, 114, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl MT_CHIMNEY_CABLE_CAR_STATION_EventWarps
MT_CHIMNEY_CABLE_CAR_STATION_EventWarps: @ 0x0850C404
	warp_def 6, 11, 0, 0, MAP_MT_CHIMNEY
	warp_def 7, 11, 0, 1, MAP_MT_CHIMNEY
	.globl gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION
gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION: @ 0x0850C414
	map_events MT_CHIMNEY_CABLE_CAR_STATION_EventObjects, MT_CHIMNEY_CABLE_CAR_STATION_EventWarps, 0, 0
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects
ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects: @ 0x0850C428
	object_event 1, 5, 0, 3, 2, 3, 8, 1, 1, 0, 0, Route114_FossilManiacsHouse_EventScript_00212136, 0x0000
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps
ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps: @ 0x0850C440
	warp_def 4, 7, 0, 1, MAP_ROUTE114
	warp_def 5, 7, 0, 1, MAP_ROUTE114
	warp_def 4, 1, 0, 0, MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL
	.globl ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents
ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents: @ 0x0850C458
	bg_event 5, 3, 0, 1, Route114_FossilManiacsHouse_EventScript_0021216F, 0, 0
	bg_event 6, 3, 0, 1, Route114_FossilManiacsHouse_EventScript_0021216F, 0, 0
	bg_event 7, 2, 0, 1, Route114_FossilManiacsHouse_EventScript_00212178, 0, 0
	bg_event 8, 2, 0, 1, Route114_FossilManiacsHouse_EventScript_00212178, 0, 0
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x0850C488
	map_events ROUTE114_FOSSIL_MANIACS_HOUSE_EventObjects, ROUTE114_FOSSIL_MANIACS_HOUSE_EventWarps, 0, ROUTE114_FOSSIL_MANIACS_HOUSE_EventBgEvents
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects: @ 0x0850C49C
	object_event 1, 39, 0, 5, 3, 3, 7, 1, 1, 0, 0, Route114_FossilManiacsTunnel_EventScript_002122EC, 0x0000
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps: @ 0x0850C4B4
	warp_def 6, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 7, 25, 3, 2, MAP_ROUTE114_FOSSIL_MANIACS_HOUSE
	warp_def 6, 2, 0, 0, MAP_DESERT_UNDERPASS
	.globl ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents
ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents: @ 0x0850C4CC
	coord_event 5, 4, 3, 16588, 1, Route114_FossilManiacsTunnel_EventScript_002122CB
	coord_event 6, 4, 3, 16588, 1, Route114_FossilManiacsTunnel_EventScript_002122CB
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x0850C4EC
	map_events ROUTE114_FOSSIL_MANIACS_TUNNEL_EventObjects, ROUTE114_FOSSIL_MANIACS_TUNNEL_EventWarps, ROUTE114_FOSSIL_MANIACS_TUNNEL_EventCoordEvents, 0
	.globl ROUTE114_LANETTES_HOUSE_EventObjects
ROUTE114_LANETTES_HOUSE_EventObjects: @ 0x0850C500
	object_event 1, 20, 0, 5, 4, 3, 1, 0, 0, 0, 0, Route114_LanettesHouse_EventScript_002124DB, 0x0366
	.globl ROUTE114_LANETTES_HOUSE_EventWarps
ROUTE114_LANETTES_HOUSE_EventWarps: @ 0x0850C518
	warp_def 5, 7, 0, 2, MAP_ROUTE114
	warp_def 6, 7, 0, 2, MAP_ROUTE114
	.globl ROUTE114_LANETTES_HOUSE_EventBgEvents
ROUTE114_LANETTES_HOUSE_EventBgEvents: @ 0x0850C528
	bg_event 5, 1, 0, 0, Route114_LanettesHouse_EventScript_00212512, 0, 0
	bg_event 8, 1, 0, 0, Route114_LanettesHouse_EventScript_0021254E, 0, 0
	bg_event 7, 1, 0, 0, Route114_LanettesHouse_EventScript_0021254E, 0, 0
	.globl gMapEvents_ROUTE114_LANETTES_HOUSE
gMapEvents_ROUTE114_LANETTES_HOUSE: @ 0x0850C54C
	map_events ROUTE114_LANETTES_HOUSE_EventObjects, ROUTE114_LANETTES_HOUSE_EventWarps, 0, ROUTE114_LANETTES_HOUSE_EventBgEvents
	.globl ROUTE116_TUNNELERS_REST_HOUSE_EventObjects
ROUTE116_TUNNELERS_REST_HOUSE_EventObjects: @ 0x0850C560
	object_event 1, 25, 0, 6, 5, 3, 10, 0, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_0021282A, 0x0000
	object_event 2, 25, 0, 3, 6, 3, 1, 1, 1, 0, 0, Route116_TunnelersRestHouse_EventScript_0021283C, 0x0000
	object_event 3, 25, 0, 7, 2, 3, 7, 1, 0, 0, 0, Route116_TunnelersRestHouse_EventScript_00212833, 0x0000
	.globl ROUTE116_TUNNELERS_REST_HOUSE_EventWarps
ROUTE116_TUNNELERS_REST_HOUSE_EventWarps: @ 0x0850C5A8
	warp_def 4, 8, 0, 1, MAP_ROUTE116
	warp_def 5, 8, 0, 1, MAP_ROUTE116
	.globl gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE
gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x0850C5B8
	map_events ROUTE116_TUNNELERS_REST_HOUSE_EventObjects, ROUTE116_TUNNELERS_REST_HOUSE_EventWarps, 0, 0
	.globl ROUTE117_POKEMON_DAY_CARE_EventObjects
ROUTE117_POKEMON_DAY_CARE_EventObjects: @ 0x0850C5CC
	object_event 1, 30, 0, 2, 2, 3, 8, 0, 0, 0, 0, 0x082577DA, 0x0000
	.globl ROUTE117_POKEMON_DAY_CARE_EventWarps
ROUTE117_POKEMON_DAY_CARE_EventWarps: @ 0x0850C5E4
	warp_def 2, 8, 0, 0, MAP_ROUTE117
	warp_def 3, 8, 0, 0, MAP_ROUTE117
	.globl gMapEvents_ROUTE117_POKEMON_DAY_CARE
gMapEvents_ROUTE117_POKEMON_DAY_CARE: @ 0x0850C5F4
	map_events ROUTE117_POKEMON_DAY_CARE_EventObjects, ROUTE117_POKEMON_DAY_CARE_EventWarps, 0, 0
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects
ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects: @ 0x0850C608
	object_event 1, 32, 0, 17, 9, 3, 9, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_00212A10, 0x0000
	object_event 2, 31, 0, 10, 2, 3, 8, 0, 0, 0, 0, Route121_SafariZoneEntrance_EventScript_00212A19, 0x0000
	object_event 3, 31, 0, 8, 2, 3, 8, 0, 0, 0, 0, 0x00000000, 0x0000
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps
ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps: @ 0x0850C650
	warp_def 2, 5, 0, 0, MAP_SAFARI_ZONE_SOUTH
	warp_def 3, 5, 0, 0, MAP_SAFARI_ZONE_SOUTH
	warp_def 14, 13, 0, 0, MAP_ROUTE121
	warp_def 15, 13, 0, 0, MAP_ROUTE121
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents
ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents: @ 0x0850C670
	coord_event 8, 4, 3, 16385, 0, Route121_SafariZoneEntrance_EventScript_00212A42
	.globl ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents
ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents: @ 0x0850C680
	bg_event 15, 1, 0, 0, Route121_SafariZoneEntrance_EventScript_00212B4B, 0, 0
	.globl gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x0850C68C
	map_events ROUTE121_SAFARI_ZONE_ENTRANCE_EventObjects, ROUTE121_SAFARI_ZONE_ENTRANCE_EventWarps, ROUTE121_SAFARI_ZONE_ENTRANCE_EventCoordEvents, ROUTE121_SAFARI_ZONE_ENTRANCE_EventBgEvents
	.globl METEOR_FALLS_1F_1R_EventObjects
METEOR_FALLS_1F_1R_EventObjects: @ 0x0850C6A0
	object_event 1, 59, 0, 2, 4, 3, 1, 0, 0, 0, 0, 0x08256F02, 0x0414
	object_event 2, 59, 0, 2, 14, 3, 1, 0, 0, 0, 0, 0x08256F1C, 0x0416
	object_event 3, 59, 0, 27, 5, 3, 1, 0, 0, 0, 0, 0x08256F0F, 0x0415
	object_event 4, 59, 0, 26, 32, 3, 1, 0, 0, 0, 0, 0x08256F29, 0x0417
	object_event 5, 119, 0, 12, 20, 3, 8, 0, 0, 0, 0, 0x00000000, 0x03AB
	object_event 6, 119, 0, 14, 21, 3, 9, 0, 0, 0, 0, 0x00000000, 0x03AB
	object_event 7, 195, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 8, 117, 0, 6, 20, 3, 10, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 9, 117, 0, 6, 21, 3, 1, 0, 0, 0, 0, 0x00000000, 0x03AA
	object_event 10, 46, 0, 13, 23, 3, 21, 0, 0, 0, 0, MeteorFalls_1F_1R_EventScript_00212D4F, 0x03AE
	.globl METEOR_FALLS_1F_1R_EventWarps
METEOR_FALLS_1F_1R_EventWarps: @ 0x0850C790
	warp_def 27, 18, 4, 0, MAP_ROUTE114
	warp_def 6, 39, 3, 0, MAP_ROUTE115
	warp_def 10, 3, 3, 0, MAP_METEOR_FALLS_1F_2R
	warp_def 5, 4, 3, 4, MAP_METEOR_FALLS_B1F_1R
	warp_def 26, 28, 3, 5, MAP_METEOR_FALLS_B1F_1R
	warp_def 4, 2, 0, 0, MAP_METEOR_FALLS_STEVENS_CAVE
	.globl METEOR_FALLS_1F_1R_EventCoordEvents
METEOR_FALLS_1F_1R_EventCoordEvents: @ 0x0850C7C0
	coord_event 14, 18, 4, 16575, 0, MeteorFalls_1F_1R_EventScript_00212B89
	.globl METEOR_FALLS_1F_1R_EventBgEvents
METEOR_FALLS_1F_1R_EventBgEvents: @ 0x0850C7D0
	bg_event 9, 58, 0, 0, 0x00000000, 0, 0
	.globl gMapEvents_METEOR_FALLS_1F_1R
gMapEvents_METEOR_FALLS_1F_1R: @ 0x0850C7DC
	map_events METEOR_FALLS_1F_1R_EventObjects, METEOR_FALLS_1F_1R_EventWarps, METEOR_FALLS_1F_1R_EventCoordEvents, METEOR_FALLS_1F_1R_EventBgEvents
	.globl METEOR_FALLS_1F_2R_EventObjects
METEOR_FALLS_1F_2R_EventObjects: @ 0x0850C7F0
	object_event 1, 33, 0, 13, 2, 3, 8, 0, 0, 1, 1, 0x0821307A, 0x0000
	object_event 2, 21, 0, 6, 12, 3, 8, 1, 1, 1, 1, 0x082130DC, 0x0000
	object_event 3, 22, 0, 7, 12, 3, 8, 1, 1, 1, 1, 0x08213140, 0x0000
	.globl METEOR_FALLS_1F_2R_EventWarps
METEOR_FALLS_1F_2R_EventWarps: @ 0x0850C838
	warp_def 10, 29, 3, 2, MAP_METEOR_FALLS_1F_1R
	warp_def 4, 14, 3, 0, MAP_METEOR_FALLS_B1F_1R
	warp_def 7, 20, 3, 1, MAP_METEOR_FALLS_B1F_1R
	warp_def 21, 23, 3, 2, MAP_METEOR_FALLS_B1F_1R
	.globl METEOR_FALLS_1F_2R_EventBgEvents
METEOR_FALLS_1F_2R_EventBgEvents: @ 0x0850C858
	bg_event 9, 58, 0, 0, 0x00000000, 0, 0
	.globl gMapEvents_METEOR_FALLS_1F_2R
gMapEvents_METEOR_FALLS_1F_2R: @ 0x0850C864
	map_events METEOR_FALLS_1F_2R_EventObjects, METEOR_FALLS_1F_2R_EventWarps, 0, METEOR_FALLS_1F_2R_EventBgEvents
	.globl METEOR_FALLS_B1F_1R_EventObjects
METEOR_FALLS_B1F_1R_EventObjects: @ 0x00000000
	.globl METEOR_FALLS_B1F_1R_EventWarps
METEOR_FALLS_B1F_1R_EventWarps: @ 0x0850C878
	warp_def 5, 6, 4, 1, MAP_METEOR_FALLS_1F_2R
	warp_def 7, 11, 5, 2, MAP_METEOR_FALLS_1F_2R
	warp_def 18, 15, 4, 3, MAP_METEOR_FALLS_1F_2R
	warp_def 17, 3, 3, 0, MAP_METEOR_FALLS_B1F_2R
	warp_def 3, 23, 5, 3, MAP_METEOR_FALLS_1F_1R
	warp_def 20, 36, 3, 4, MAP_METEOR_FALLS_1F_1R
	.globl gMapEvents_METEOR_FALLS_B1F_1R
gMapEvents_METEOR_FALLS_B1F_1R: @ 0x0850C8A8
	map_events 0, METEOR_FALLS_B1F_1R_EventWarps, 0, 0
	.globl METEOR_FALLS_B1F_2R_EventObjects
METEOR_FALLS_B1F_2R_EventObjects: @ 0x0850C8BC
	object_event 1, 59, 0, 5, 3, 3, 1, 1, 1, 0, 0, 0x08256F36, 0x0438
	.globl METEOR_FALLS_B1F_2R_EventWarps
METEOR_FALLS_B1F_2R_EventWarps: @ 0x0850C8D4
	warp_def 5, 15, 3, 3, MAP_METEOR_FALLS_B1F_1R
	.globl gMapEvents_METEOR_FALLS_B1F_2R
gMapEvents_METEOR_FALLS_B1F_2R: @ 0x0850C8DC
	map_events METEOR_FALLS_B1F_2R_EventObjects, METEOR_FALLS_B1F_2R_EventWarps, 0, 0
	.globl RUSTURF_TUNNEL_EventObjects
RUSTURF_TUNNEL_EventObjects: @ 0x0850C8F0
	object_event 1, 44, 0, 23, 5, 3, 10, 0, 0, 0, 0, RusturfTunnel_EventScript_0021363F, 0x0327
	object_event 2, 86, 0, 24, 5, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x03A3
	object_event 3, 59, 0, 3, 1, 3, 1, 0, 0, 0, 0, 0x08256E8D, 0x0418
	object_event 4, 59, 0, 30, 2, 3, 1, 0, 0, 0, 0, 0x08256E9A, 0x0419
	object_event 5, 21, 0, 5, 4, 3, 10, 0, 0, 0, 0, 0x00000000, 0x036F
	object_event 6, 117, 0, 14, 5, 3, 9, 0, 0, 0, 0, 0x0821388B, 0x036E
	object_event 7, 211, 0, 14, 4, 3, 9, 0, 0, 0, 0, RusturfTunnel_EventScript_00213878, 0x0370
	object_event 8, 86, 0, 24, 4, 3, 8, 0, 0, 0, 0, 0x0825667C, 0x03A4
	object_event 9, 55, 0, 32, 13, 3, 9, 1, 1, 1, 3, 0x0821397A, 0x0000
	object_event 10, 20, 0, 25, 4, 3, 9, 1, 1, 0, 0, RusturfTunnel_EventScript_00213628, 0x03D7
	.globl RUSTURF_TUNNEL_EventWarps
RUSTURF_TUNNEL_EventWarps: @ 0x0850C9E0
	warp_def 4, 10, 3, 0, MAP_ROUTE116
	warp_def 29, 16, 3, 4, MAP_VERDANTURF_TOWN
	warp_def 18, 20, 3, 2, MAP_ROUTE116
	.globl RUSTURF_TUNNEL_EventCoordEvents
RUSTURF_TUNNEL_EventCoordEvents: @ 0x0850C9F8
	coord_event 23, 4, 3, 0, 0, RusturfTunnel_EventScript_0021383A
	coord_event 9, 4, 3, 16538, 2, RusturfTunnel_EventScript_0021384C
	coord_event 9, 5, 3, 16538, 2, RusturfTunnel_EventScript_0021384C
	coord_event 25, 4, 3, 0, 0, RusturfTunnel_EventScript_00213840
	coord_event 25, 5, 3, 0, 0, RusturfTunnel_EventScript_00213846
	.globl gMapEvents_RUSTURF_TUNNEL
gMapEvents_RUSTURF_TUNNEL: @ 0x0850CA48
	map_events RUSTURF_TUNNEL_EventObjects, RUSTURF_TUNNEL_EventWarps, RUSTURF_TUNNEL_EventCoordEvents, 0
	.globl UNDERWATER_SOOTOPOLIS_CITY_EventObjects
UNDERWATER_SOOTOPOLIS_CITY_EventObjects: @ 0x00000000
	.globl UNDERWATER_SOOTOPOLIS_CITY_EventWarps
UNDERWATER_SOOTOPOLIS_CITY_EventWarps: @ 0x0850CA5C
	warp_def 9, 8, 0, 0, MAP_UNDERWATER_ROUTE126
	warp_def 10, 8, 0, 0, MAP_UNDERWATER_ROUTE126
	.globl gMapEvents_UNDERWATER_SOOTOPOLIS_CITY
gMapEvents_UNDERWATER_SOOTOPOLIS_CITY: @ 0x0850CA6C
	map_events 0, UNDERWATER_SOOTOPOLIS_CITY_EventWarps, 0, 0
	.globl DESERT_RUINS_EventObjects
DESERT_RUINS_EventObjects: @ 0x0850CA80
	object_event 1, 200, 0, 8, 7, 3, 8, 0, 0, 0, 0, DesertRuins_EventScript_00213E86, 0x03A7
	.globl DESERT_RUINS_EventWarps
DESERT_RUINS_EventWarps: @ 0x0850CA98
	warp_def 8, 29, 3, 1, MAP_ROUTE111
	warp_def 8, 20, 0, 2, MAP_DESERT_RUINS
	warp_def 8, 11, 3, 1, MAP_DESERT_RUINS
	.globl DESERT_RUINS_EventBgEvents
DESERT_RUINS_EventBgEvents: @ 0x0850CAB0
	bg_event 8, 20, 0, 0, DesertRuins_EventScript_00213E5F, 0, 0
	bg_event 7, 20, 0, 0, DesertRuins_EventScript_00213E7C, 0, 0
	bg_event 9, 20, 0, 0, DesertRuins_EventScript_00213E7C, 0, 0
	.globl gMapEvents_DESERT_RUINS
gMapEvents_DESERT_RUINS: @ 0x0850CAD4
	map_events DESERT_RUINS_EventObjects, DESERT_RUINS_EventWarps, 0, DESERT_RUINS_EventBgEvents
	.globl GRANITE_CAVE_1F_EventObjects
GRANITE_CAVE_1F_EventObjects: @ 0x0850CAE8
	object_event 1, 55, 0, 36, 9, 3, 1, 0, 0, 0, 0, 0x08213EE2, 0x0000
	object_event 2, 59, 0, 17, 7, 3, 8, 0, 0, 0, 0, 0x08256EA7, 0x041A
	.globl GRANITE_CAVE_1F_EventWarps
GRANITE_CAVE_1F_EventWarps: @ 0x0850CB18
	warp_def 37, 12, 3, 0, MAP_ROUTE106
	warp_def 35, 3, 3, 0, MAP_GRANITE_CAVE_B1F
	warp_def 17, 11, 3, 1, MAP_GRANITE_CAVE_B1F
	warp_def 5, 10, 3, 0, MAP_GRANITE_CAVE_STEVENS_ROOM
	.globl gMapEvents_GRANITE_CAVE_1F
gMapEvents_GRANITE_CAVE_1F: @ 0x0850CB38
	map_events GRANITE_CAVE_1F_EventObjects, GRANITE_CAVE_1F_EventWarps, 0, 0
	.globl GRANITE_CAVE_B1F_EventObjects
GRANITE_CAVE_B1F_EventObjects: @ 0x0850CB4C
	object_event 1, 59, 0, 15, 21, 3, 1, 0, 0, 0, 0, 0x08256EB4, 0x041B
	.globl GRANITE_CAVE_B1F_EventWarps
GRANITE_CAVE_B1F_EventWarps: @ 0x0850CB64
	warp_def 25, 13, 3, 1, MAP_GRANITE_CAVE_1F
	warp_def 4, 21, 3, 2, MAP_GRANITE_CAVE_1F
	warp_def 29, 13, 3, 0, MAP_GRANITE_CAVE_B2F
	warp_def 28, 21, 3, 1, MAP_GRANITE_CAVE_B2F
	warp_def 8, 5, 3, 2, MAP_GRANITE_CAVE_B2F
	warp_def 12, 3, 3, 3, MAP_GRANITE_CAVE_B2F
	warp_def 29, 2, 3, 4, MAP_GRANITE_CAVE_B2F
	.globl gMapEvents_GRANITE_CAVE_B1F
gMapEvents_GRANITE_CAVE_B1F: @ 0x0850CB9C
	map_events GRANITE_CAVE_B1F_EventObjects, GRANITE_CAVE_B1F_EventWarps, 0, 0
	.globl GRANITE_CAVE_B2F_EventObjects
GRANITE_CAVE_B2F_EventObjects: @ 0x0850CBB0
	object_event 1, 59, 0, 4, 4, 3, 1, 0, 0, 0, 0, 0x08256EC1, 0x041D
	object_event 2, 59, 0, 29, 4, 3, 1, 0, 0, 0, 0, 0x08256ECE, 0x041E
	object_event 3, 86, 0, 5, 14, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0011
	object_event 4, 86, 0, 3, 14, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0012
	object_event 5, 86, 0, 2, 16, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0013
	object_event 6, 86, 0, 7, 12, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0014
	object_event 7, 86, 0, 4, 22, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0015
	object_event 8, 86, 0, 6, 22, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0016
	object_event 9, 86, 0, 3, 21, 3, 1, 1, 1, 0, 0, 0x0825667C, 0x0017
	.globl GRANITE_CAVE_B2F_EventWarps
GRANITE_CAVE_B2F_EventWarps: @ 0x0850CC88
	warp_def 29, 13, 3, 2, MAP_GRANITE_CAVE_B1F
	warp_def 28, 21, 3, 3, MAP_GRANITE_CAVE_B1F
	warp_def 8, 5, 3, 4, MAP_GRANITE_CAVE_B1F
	warp_def 12, 3, 3, 5, MAP_GRANITE_CAVE_B1F
	warp_def 29, 2, 3, 6, MAP_GRANITE_CAVE_B1F
	.globl GRANITE_CAVE_B2F_EventBgEvents
GRANITE_CAVE_B2F_EventBgEvents: @ 0x0850CCB0
	bg_event 28, 6, 3, 7, 0x00C3, 0x30, 0x00
	bg_event 15, 11, 3, 7, 0x00C3, 0x31, 0x00
	.globl gMapEvents_GRANITE_CAVE_B2F
gMapEvents_GRANITE_CAVE_B2F: @ 0x0850CCC8
	map_events GRANITE_CAVE_B2F_EventObjects, GRANITE_CAVE_B2F_EventWarps, 0, GRANITE_CAVE_B2F_EventBgEvents
	.globl GRANITE_CAVE_STEVENS_ROOM_EventObjects
GRANITE_CAVE_STEVENS_ROOM_EventObjects: @ 0x0850CCDC
	object_event 1, 134, 0, 7, 8, 3, 1, 0, 0, 0, 0, 0x08214028, 0x0341
	.globl GRANITE_CAVE_STEVENS_ROOM_EventWarps
GRANITE_CAVE_STEVENS_ROOM_EventWarps: @ 0x0850CCF4
	warp_def 7, 3, 3, 3, MAP_GRANITE_CAVE_1F
	.globl gMapEvents_GRANITE_CAVE_STEVENS_ROOM
gMapEvents_GRANITE_CAVE_STEVENS_ROOM: @ 0x0850CCFC
	map_events GRANITE_CAVE_STEVENS_ROOM_EventObjects, GRANITE_CAVE_STEVENS_ROOM_EventWarps, 0, 0
	.globl PETALBURG_WOODS_EventObjects
PETALBURG_WOODS_EventObjects: @ 0x0850CD10
	object_event 1, 82, 0, 19, 10, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0011
	object_event 2, 82, 0, 19, 11, 3, 1, 0, 0, 0, 0, 0x082565C8, 0x0012
	object_event 3, 117, 0, 26, 17, 3, 10, 0, 0, 0, 0, 0x00000000, 0x02D5
	object_event 4, 23, 0, 26, 20, 3, 1, 0, 0, 0, 0, 0x00000000, 0x02D4
	object_event 5, 59, 0, 45, 7, 3, 8, 0, 0, 0, 0, 0x08256E66, 0x0420
	object_event 6, 59, 0, 35, 20, 3, 8, 0, 0, 0, 0, 0x08256E59, 0x041F
	object_event 7, 59, 0, 4, 8, 3, 1, 0, 0, 0, 0, 0x08256E73, 0x0422
	object_event 8, 9, 0, 15, 19, 3, 3, 1, 2, 0, 0, 0x082144B2, 0x0000
	object_event 9, 36, 0, 7, 32, 3, 22, 0, 0, 1, 3, 0x0821450F, 0x0000
	object_event 10, 36, 0, 4, 14, 3, 20, 0, 0, 1, 3, 0x08214526, 0x0000
	object_event 11, 13, 0, 30, 34, 3, 2, 2, 1, 0, 0, 0x082144BB, 0x0000
	object_event 12, 59, 0, 4, 26, 3, 1, 1, 1, 0, 0, 0x08256E80, 0x045D
	object_event 13, 10, 0, 33, 5, 3, 1, 1, 1, 0, 0, 0x082144C4, 0x0000
	.globl PETALBURG_WOODS_EventWarps
PETALBURG_WOODS_EventWarps: @ 0x0850CE48
	warp_def 14, 5, 0, 2, MAP_ROUTE104
	warp_def 15, 5, 0, 3, MAP_ROUTE104
	warp_def 16, 38, 0, 4, MAP_ROUTE104
	warp_def 17, 38, 0, 5, MAP_ROUTE104
	warp_def 36, 38, 0, 6, MAP_ROUTE104
	warp_def 37, 38, 0, 7, MAP_ROUTE104
	.globl PETALBURG_WOODS_EventCoordEvents
PETALBURG_WOODS_EventCoordEvents: @ 0x0850CE78
	coord_event 26, 23, 3, 16536, 0, 0x08214279
	coord_event 27, 23, 3, 16536, 0, 0x0821431B
	.globl PETALBURG_WOODS_EventBgEvents
PETALBURG_WOODS_EventBgEvents: @ 0x0850CE98
	bg_event 14, 32, 3, 0, 0x082144FD, 0, 0
	bg_event 39, 35, 3, 7, 0x000D, 0x3A, 0x00
	bg_event 26, 6, 3, 7, 0x0067, 0x3B, 0x00
	bg_event 40, 29, 3, 7, 0x0067, 0x3C, 0x00
	bg_event 4, 19, 3, 7, 0x0004, 0x3D, 0x00
	bg_event 11, 8, 3, 0, 0x08214506, 0, 0
	.globl gMapEvents_PETALBURG_WOODS
gMapEvents_PETALBURG_WOODS: @ 0x0850CEE0
	map_events PETALBURG_WOODS_EventObjects, PETALBURG_WOODS_EventWarps, PETALBURG_WOODS_EventCoordEvents, PETALBURG_WOODS_EventBgEvents
	.globl MT_CHIMNEY_EventObjects
MT_CHIMNEY_EventObjects: @ 0x0850CEF4
	object_event 1, 195, 0, 24, 19, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214BA8, 0x039E
	object_event 2, 196, 0, 13, 6, 3, 10, 0, 0, 0, 0, 0x08214BDE, 0x039F
	object_event 3, 119, 0, 12, 11, 3, 9, 0, 0, 1, 2, 0x08214E41, 0x039F
	object_event 4, 119, 0, 32, 5, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E93, 0x039F
	object_event 5, 119, 0, 28, 12, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E8A, 0x039F
	object_event 6, 117, 0, 19, 39, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E2F, 0x039E
	object_event 7, 117, 0, 29, 5, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E26, 0x039E
	object_event 8, 117, 0, 31, 12, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E38, 0x039E
	object_event 9, 30, 0, 19, 39, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214CC6, 0x03E2
	object_event 10, 119, 0, 22, 39, 3, 9, 0, 0, 0, 0, MtChimney_EventScript_00214E9C, 0x039F
	object_event 11, 220, 0, 23, 19, 3, 74, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 12, 220, 0, 23, 18, 3, 64, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 13, 119, 0, 23, 17, 3, 8, 0, 0, 0, 0, MtChimney_EventScript_00214E78, 0x039F
	object_event 14, 220, 0, 23, 20, 3, 65, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 15, 220, 0, 22, 19, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 16, 119, 0, 23, 21, 3, 7, 0, 0, 0, 0, MtChimney_EventScript_00214E81, 0x039F
	object_event 17, 119, 0, 21, 19, 3, 10, 0, 0, 0, 0, MtChimney_EventScript_00214E6F, 0x039F
	object_event 18, 220, 0, 30, 12, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 19, 220, 0, 29, 12, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 20, 220, 0, 30, 5, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 21, 220, 0, 31, 5, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 22, 119, 0, 9, 16, 3, 10, 0, 0, 1, 3, 0x08214E58, 0x039F
	object_event 23, 220, 0, 20, 39, 3, 67, 0, 0, 0, 0, MtChimney_EventScript_00214EAE, 0x039E
	object_event 24, 220, 0, 21, 39, 3, 66, 0, 0, 0, 0, MtChimney_EventScript_00214EA5, 0x039F
	object_event 25, 22, 0, 16, 18, 3, 13, 0, 0, 1, 3, 0x08214F1D, 0x036D
	object_event 26, 45, 0, 14, 7, 3, 70, 0, 0, 1, 6, 0x08214F7F, 0x036D
	object_event 27, 45, 0, 29, 7, 3, 17, 1, 1, 1, 3, 0x08214F96, 0x036D
	object_event 28, 45, 0, 27, 17, 3, 16, 1, 1, 1, 3, 0x08214FAD, 0x036D
	object_event 29, 120, 0, 13, 16, 3, 9, 1, 1, 1, 3, 0x08214FC4, 0x039F
	object_event 30, 55, 0, 7, 7, 3, 10, 1, 1, 1, 6, 0x08214FDB, 0x036D
	.globl MT_CHIMNEY_EventWarps
MT_CHIMNEY_EventWarps: @ 0x0850D1C4
	warp_def 17, 36, 0, 0, MAP_MT_CHIMNEY_CABLE_CAR_STATION
	warp_def 18, 36, 0, 1, MAP_MT_CHIMNEY_CABLE_CAR_STATION
	warp_def 20, 41, 3, 2, MAP_JAGGED_PASS
	warp_def 21, 41, 3, 3, MAP_JAGGED_PASS
	.globl MT_CHIMNEY_EventBgEvents
MT_CHIMNEY_EventBgEvents: @ 0x0850D1E4
	bg_event 14, 6, 0, 0, MtChimney_EventScript_00214EB7, 0, 0
	bg_event 24, 37, 3, 0, MtChimney_EventScript_00214F14, 0, 0
	.globl gMapEvents_MT_CHIMNEY
gMapEvents_MT_CHIMNEY: @ 0x0850D1FC
	map_events MT_CHIMNEY_EventObjects, MT_CHIMNEY_EventWarps, 0, MT_CHIMNEY_EventBgEvents
	.globl JAGGED_PASS_EventObjects
JAGGED_PASS_EventObjects: @ 0x0850D210
	object_event 1, 55, 0, 10, 8, 3, 10, 0, 0, 1, 3, 0x08215C21, 0x0000
	object_event 2, 31, 0, 16, 35, 3, 14, 0, 0, 1, 4, 0x08215C97, 0x0000
	object_event 3, 59, 0, 23, 24, 3, 1, 0, 0, 0, 0, 0x08256EDB, 0x042E
	object_event 4, 32, 0, 9, 21, 3, 16, 1, 1, 1, 3, 0x08215C38, 0x0000
	object_event 5, 119, 0, 16, 19, 3, 7, 1, 1, 0, 0, 0x08215BB4, 0x034F
	object_event 6, 32, 0, 14, 25, 3, 10, 1, 1, 1, 3, 0x08215D0D, 0x0000
	object_event 7, 56, 0, 18, 25, 3, 9, 1, 1, 1, 3, 0x08215CF6, 0x0000
	.globl JAGGED_PASS_EventWarps
JAGGED_PASS_EventWarps: @ 0x0850D2B8
	warp_def 14, 40, 3, 2, MAP_ROUTE112
	warp_def 15, 40, 3, 3, MAP_ROUTE112
	warp_def 13, 5, 3, 2, MAP_MT_CHIMNEY
	warp_def 14, 5, 3, 3, MAP_MT_CHIMNEY
	warp_def 16, 18, 0, 0, MAP_MAGMA_HIDEOUT_1F
	.globl JAGGED_PASS_EventCoordEvents
JAGGED_PASS_EventCoordEvents: @ 0x0850D2E0
	coord_event 13, 15, 3, 2, 0, 0x00000000
	coord_event 21, 12, 3, 8, 0, 0x00000000
	coord_event 14, 15, 3, 2, 0, 0x00000000
	coord_event 18, 17, 3, 2, 0, 0x00000000
	coord_event 22, 19, 3, 2, 0, 0x00000000
	coord_event 21, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 22, 20, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 21, 20, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 14, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	coord_event 13, 15, 3, 16584, 1, JaggedPass_EventScript_00215B57
	.globl JAGGED_PASS_EventBgEvents
JAGGED_PASS_EventBgEvents: @ 0x0850D380
	bg_event 8, 10, 3, 7, 0x0017, 0x4D, 0x00
	bg_event 7, 29, 3, 7, 0x0003, 0x4C, 0x00
	.globl gMapEvents_JAGGED_PASS
gMapEvents_JAGGED_PASS: @ 0x0850D398
	map_events JAGGED_PASS_EventObjects, JAGGED_PASS_EventWarps, JAGGED_PASS_EventCoordEvents, JAGGED_PASS_EventBgEvents
	.globl FIERY_PATH_EventObjects
FIERY_PATH_EventObjects: @ 0x0850D3AC
	object_event 1, 59, 0, 8, 3, 3, 1, 1, 1, 0, 0, 0x08256EF5, 0x0443
	object_event 2, 87, 0, 10, 15, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 3, 87, 0, 17, 15, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 4, 87, 0, 8, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0013
	object_event 5, 87, 0, 3, 12, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0014
	object_event 6, 87, 0, 6, 23, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 7, 87, 0, 5, 24, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 8, 59, 0, 7, 32, 3, 1, 1, 1, 0, 0, 0x08256EE8, 0x0457
	.globl FIERY_PATH_EventWarps
FIERY_PATH_EventWarps: @ 0x0850D46C
	warp_def 26, 36, 3, 4, MAP_ROUTE112
	warp_def 26, 4, 3, 5, MAP_ROUTE112
	.globl gMapEvents_FIERY_PATH
gMapEvents_FIERY_PATH: @ 0x0850D47C
	map_events FIERY_PATH_EventObjects, FIERY_PATH_EventWarps, 0, 0
	.globl MT_PYRE_1F_EventObjects
MT_PYRE_1F_EventObjects: @ 0x0850D490
	object_event 1, 30, 0, 21, 2, 3, 8, 1, 1, 0, 0, 0x0821611A, 0x0000
	object_event 2, 18, 0, 17, 8, 3, 7, 1, 1, 0, 0, 0x08216153, 0x0000
	object_event 3, 65, 0, 13, 10, 3, 9, 1, 1, 0, 0, 0x0821615C, 0x0000
	.globl MT_PYRE_1F_EventWarps
MT_PYRE_1F_EventWarps: @ 0x0850D4D8
	warp_def 17, 18, 3, 0, MAP_ROUTE122
	warp_def 3, 6, 3, 0, MAP_MT_PYRE_EXTERIOR
	warp_def 18, 18, 3, 0, MAP_ROUTE122
	warp_def 4, 6, 3, 0, MAP_MT_PYRE_EXTERIOR
	warp_def 11, 1, 3, 0, MAP_MT_PYRE_2F
	warp_def 20, 9, 3, 4, MAP_MT_PYRE_2F
	.globl gMapEvents_MT_PYRE_1F
gMapEvents_MT_PYRE_1F: @ 0x0850D508
	map_events MT_PYRE_1F_EventObjects, MT_PYRE_1F_EventWarps, 0, 0
	.globl MT_PYRE_2F_EventObjects
MT_PYRE_2F_EventObjects: @ 0x0850D51C
	object_event 1, 39, 0, 3, 6, 3, 10, 1, 1, 1, 2, 0x0821625D, 0x0000
	object_event 2, 59, 0, 0, 10, 3, 1, 1, 1, 0, 0, 0x08257054, 0x0469
	object_event 3, 16, 0, 9, 3, 3, 10, 1, 1, 0, 0, MtPyre_2F_EventScript_0021624B, 0x0000
	object_event 4, 25, 0, 12, 10, 3, 8, 1, 1, 0, 0, MtPyre_2F_EventScript_00216254, 0x0000
	object_event 5, 26, 0, 2, 9, 3, 8, 1, 1, 1, 1, 0x0821628F, 0x0000
	object_event 6, 65, 0, 3, 9, 3, 8, 1, 1, 1, 1, 0x08216274, 0x0000
	object_event 7, 44, 0, 6, 9, 3, 7, 1, 1, 1, 2, 0x082162C1, 0x0000
	object_event 8, 40, 0, 6, 6, 3, 17, 1, 1, 1, 2, 0x082162AA, 0x0000
	.globl MT_PYRE_2F_EventWarps
MT_PYRE_2F_EventWarps: @ 0x0850D5DC
	warp_def 2, 1, 3, 4, MAP_MT_PYRE_1F
	warp_def 10, 1, 3, 0, MAP_MT_PYRE_3F
	warp_def 10, 12, 3, 4, MAP_MT_PYRE_3F
	warp_def 6, 12, 3, 5, MAP_MT_PYRE_3F
	warp_def 11, 9, 3, 5, MAP_MT_PYRE_1F
	.globl gMapEvents_MT_PYRE_2F
gMapEvents_MT_PYRE_2F: @ 0x0850D604
	map_events MT_PYRE_2F_EventObjects, MT_PYRE_2F_EventWarps, 0, 0
	.globl MT_PYRE_3F_EventObjects
MT_PYRE_3F_EventObjects: @ 0x0850D618
	object_event 1, 37, 0, 1, 4, 3, 18, 1, 1, 1, 4, 0x082165F2, 0x0000
	object_event 2, 47, 0, 11, 4, 3, 17, 1, 1, 1, 4, 0x08216609, 0x0000
	object_event 3, 59, 0, 0, 7, 3, 1, 1, 1, 0, 0, 0x08257061, 0x0460
	object_event 4, 20, 0, 6, 4, 3, 14, 1, 1, 1, 4, 0x08216620, 0x0000
	.globl MT_PYRE_3F_EventWarps
MT_PYRE_3F_EventWarps: @ 0x0850D678
	warp_def 10, 1, 3, 1, MAP_MT_PYRE_2F
	warp_def 2, 1, 3, 1, MAP_MT_PYRE_4F
	warp_def 9, 10, 3, 4, MAP_MT_PYRE_4F
	warp_def 1, 12, 3, 5, MAP_MT_PYRE_4F
	warp_def 10, 12, 3, 2, MAP_MT_PYRE_2F
	warp_def 6, 12, 3, 3, MAP_MT_PYRE_2F
	.globl gMapEvents_MT_PYRE_3F
gMapEvents_MT_PYRE_3F: @ 0x0850D6A8
	map_events MT_PYRE_3F_EventObjects, MT_PYRE_3F_EventWarps, 0, 0
	.globl MT_PYRE_4F_EventObjects
MT_PYRE_4F_EventObjects: @ 0x0850D6BC
	object_event 1, 40, 0, 11, 7, 3, 24, 1, 1, 1, 2, 0x082168FB, 0x0000
	object_event 2, 59, 0, 3, 11, 3, 1, 1, 1, 0, 0, 0x0825706E, 0x046A
	.globl MT_PYRE_4F_EventWarps
MT_PYRE_4F_EventWarps: @ 0x0850D6EC
	warp_def 10, 1, 3, 1, MAP_MT_PYRE_5F
	warp_def 2, 5, 3, 1, MAP_MT_PYRE_3F
	warp_def 12, 10, 3, 3, MAP_MT_PYRE_5F
	warp_def 12, 12, 3, 4, MAP_MT_PYRE_5F
	warp_def 9, 10, 3, 2, MAP_MT_PYRE_3F
	warp_def 2, 12, 3, 3, MAP_MT_PYRE_3F
	.globl gMapEvents_MT_PYRE_4F
gMapEvents_MT_PYRE_4F: @ 0x0850D71C
	map_events MT_PYRE_4F_EventObjects, MT_PYRE_4F_EventWarps, 0, 0
	.globl MT_PYRE_5F_EventObjects
MT_PYRE_5F_EventObjects: @ 0x0850D730
	object_event 1, 44, 0, 3, 7, 3, 17, 1, 1, 1, 2, 0x08216881, 0x0000
	object_event 2, 59, 0, 6, 11, 3, 1, 1, 1, 0, 0, 0x0825707B, 0x041C
	.globl MT_PYRE_5F_EventWarps
MT_PYRE_5F_EventWarps: @ 0x0850D760
	warp_def 2, 1, 3, 0, MAP_MT_PYRE_6F
	warp_def 10, 5, 3, 0, MAP_MT_PYRE_4F
	warp_def 1, 10, 3, 1, MAP_MT_PYRE_6F
	warp_def 12, 10, 3, 2, MAP_MT_PYRE_4F
	warp_def 12, 12, 3, 3, MAP_MT_PYRE_4F
	.globl gMapEvents_MT_PYRE_5F
gMapEvents_MT_PYRE_5F: @ 0x0850D788
	map_events MT_PYRE_5F_EventObjects, MT_PYRE_5F_EventWarps, 0, 0
	.globl MT_PYRE_6F_EventObjects
MT_PYRE_6F_EventObjects: @ 0x0850D79C
	object_event 1, 40, 0, 6, 3, 3, 23, 1, 1, 1, 3, 0x08216987, 0x0000
	object_event 2, 59, 0, 6, 9, 3, 1, 1, 1, 0, 0, 0x08257088, 0x0441
	object_event 3, 37, 0, 10, 3, 3, 24, 1, 1, 1, 3, 0x082169E9, 0x0000
	.globl MT_PYRE_6F_EventWarps
MT_PYRE_6F_EventWarps: @ 0x0850D7E4
	warp_def 2, 1, 3, 0, MAP_MT_PYRE_5F
	warp_def 1, 10, 3, 2, MAP_MT_PYRE_5F
	.globl gMapEvents_MT_PYRE_6F
gMapEvents_MT_PYRE_6F: @ 0x0850D7F4
	map_events MT_PYRE_6F_EventObjects, MT_PYRE_6F_EventWarps, 0, 0
	.globl MT_PYRE_EXTERIOR_EventObjects
MT_PYRE_EXTERIOR_EventObjects: @ 0x0850D808
	object_event 1, 59, 0, 27, 15, 3, 1, 0, 0, 0, 0, 0x08257095, 0x0431
	object_event 2, 59, 0, 19, 40, 3, 1, 0, 0, 0, 0, 0x082570A2, 0x0432
	.globl MT_PYRE_EXTERIOR_EventWarps
MT_PYRE_EXTERIOR_EventWarps: @ 0x0850D838
	warp_def 10, 42, 3, 1, MAP_MT_PYRE_1F
	warp_def 19, 10, 3, 1, MAP_MT_PYRE_SUMMIT
	warp_def 20, 10, 3, 1, MAP_MT_PYRE_SUMMIT
	.globl MT_PYRE_EXTERIOR_EventCoordEvents
MT_PYRE_EXTERIOR_EventCoordEvents: @ 0x0850D850
	coord_event 24, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	coord_event 25, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	coord_event 22, 27, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6F
	coord_event 23, 28, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6F
	coord_event 26, 21, 3, 0, 0, MtPyre_Exterior_EventScript_00216B6A
	.globl MT_PYRE_EXTERIOR_EventBgEvents
MT_PYRE_EXTERIOR_EventBgEvents: @ 0x0850D8A0
	bg_event 9, 8, 0, 7, 0x0002, 0x1D, 0x00
	bg_event 16, 22, 0, 7, 0x0023, 0x4E, 0x00
	.globl gMapEvents_MT_PYRE_EXTERIOR
gMapEvents_MT_PYRE_EXTERIOR: @ 0x0850D8B8
	map_events MT_PYRE_EXTERIOR_EventObjects, MT_PYRE_EXTERIOR_EventWarps, MT_PYRE_EXTERIOR_EventCoordEvents, MT_PYRE_EXTERIOR_EventBgEvents
	.globl MT_PYRE_SUMMIT_EventObjects
MT_PYRE_SUMMIT_EventObjects: @ 0x0850D8CC
	object_event 1, 29, 0, 22, 5, 3, 8, 0, 0, 0, 0, MtPyre_Summit_EventScript_00216CB9, 0x0000
	object_event 2, 195, 0, 23, 6, 3, 7, 0, 0, 0, 0, 0x00000000, 0x0394
	object_event 3, 22, 0, 23, 5, 3, 8, 0, 0, 0, 0, MtPyre_Summit_EventScript_00216D1F, 0x0000
	object_event 4, 117, 0, 21, 15, 3, 10, 0, 0, 1, 3, 0x08216F7A, 0x0395
	object_event 5, 117, 0, 25, 18, 3, 9, 0, 0, 1, 3, 0x08216F91, 0x0395
	object_event 6, 117, 0, 21, 11, 3, 10, 0, 0, 1, 3, 0x08216FA8, 0x0395
	object_event 7, 118, 0, 25, 11, 3, 9, 1, 1, 1, 3, 0x08216FBF, 0x0395
	object_event 8, 196, 0, 23, 6, 3, 7, 1, 1, 0, 0, 0x00000000, 0x0358
	.globl MT_PYRE_SUMMIT_EventWarps
MT_PYRE_SUMMIT_EventWarps: @ 0x0850D98C
	warp_def 22, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 23, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	warp_def 24, 31, 3, 1, MAP_MT_PYRE_EXTERIOR
	.globl MT_PYRE_SUMMIT_EventCoordEvents
MT_PYRE_SUMMIT_EventCoordEvents: @ 0x0850D9A4
	coord_event 22, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216B95
	coord_event 23, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216BA1
	coord_event 24, 7, 3, 16569, 0, MtPyre_Summit_EventScript_00216BAD
	coord_event 22, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D69
	coord_event 23, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D75
	coord_event 24, 9, 3, 16569, 2, MtPyre_Summit_EventScript_00216D81
	.globl MT_PYRE_SUMMIT_EventBgEvents
MT_PYRE_SUMMIT_EventBgEvents: @ 0x0850DA04
	bg_event 9, 25, 0, 7, 0x0046, 0x4F, 0x00
	bg_event 37, 7, 3, 7, 0x0044, 0x50, 0x00
	.globl gMapEvents_MT_PYRE_SUMMIT
gMapEvents_MT_PYRE_SUMMIT: @ 0x0850DA1C
	map_events MT_PYRE_SUMMIT_EventObjects, MT_PYRE_SUMMIT_EventWarps, MT_PYRE_SUMMIT_EventCoordEvents, MT_PYRE_SUMMIT_EventBgEvents
	.globl AQUA_HIDEOUT_1F_EventObjects
AQUA_HIDEOUT_1F_EventObjects: @ 0x0850DA30
	object_event 1, 117, 0, 13, 11, 3, 8, 0, 0, 0, 0, 0x08217936, 0x0335
	object_event 2, 117, 0, 14, 11, 3, 8, 0, 0, 0, 0, 0x08217968, 0x0336
	object_event 3, 117, 0, 20, 4, 3, 50, 13, 5, 1, 3, 0x0821799A, 0x039C
	.globl AQUA_HIDEOUT_1F_EventWarps
AQUA_HIDEOUT_1F_EventWarps: @ 0x0850DA78
	warp_def 13, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 14, 27, 1, 6, MAP_LILYCOVE_CITY
	warp_def 22, 1, 3, 0, MAP_AQUA_HIDEOUT_B1F
	.globl gMapEvents_AQUA_HIDEOUT_1F
gMapEvents_AQUA_HIDEOUT_1F: @ 0x0850DA90
	map_events AQUA_HIDEOUT_1F_EventObjects, AQUA_HIDEOUT_1F_EventWarps, 0, 0
	.globl AQUA_HIDEOUT_B1F_EventObjects
AQUA_HIDEOUT_B1F_EventObjects: @ 0x0850DAA4
	object_event 1, 117, 0, 28, 16, 3, 8, 0, 0, 1, 4, 0x08217D8E, 0x039C
	object_event 2, 117, 0, 6, 6, 3, 9, 0, 0, 1, 5, 0x08217DB9, 0x039C
	object_event 3, 59, 0, 29, 12, 3, 1, 0, 0, 0, 0, 0x082570C9, 0x042F
	object_event 4, 118, 0, 20, 18, 3, 23, 4, 0, 1, 4, 0x08217DDE, 0x039C
	object_event 5, 59, 0, 15, 9, 3, 1, 1, 1, 0, 0, 0x082570AF, 0x0464
	object_event 6, 59, 0, 16, 9, 3, 1, 1, 1, 0, 0, AquaHideout_B1F_EventScript_00217CF4, 0x03D1
	object_event 7, 59, 0, 15, 10, 3, 1, 1, 1, 0, 0, 0x082570BC, 0x046C
	object_event 8, 59, 0, 16, 10, 3, 1, 1, 1, 0, 0, AquaHideout_B1F_EventScript_00217D41, 0x03D2
	object_event 9, 118, 0, 28, 21, 3, 7, 1, 1, 1, 4, 0x08217DF5, 0x039C
	.globl AQUA_HIDEOUT_B1F_EventWarps
AQUA_HIDEOUT_B1F_EventWarps: @ 0x0850DB7C
	warp_def 29, 1, 3, 2, MAP_AQUA_HIDEOUT_1F
	warp_def 18, 1, 3, 0, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 1, 3, 1, MAP_AQUA_HIDEOUT_B2F
	warp_def 3, 3, 3, 2, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 4, 3, 7, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 4, 3, 8, MAP_AQUA_HIDEOUT_B1F
	warp_def 20, 4, 3, 10, MAP_AQUA_HIDEOUT_B1F
	warp_def 27, 12, 3, 4, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 15, 3, 5, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 20, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 32, 19, 3, 6, MAP_AQUA_HIDEOUT_B1F
	warp_def 23, 10, 3, 22, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 3, 3, 9, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 5, 3, 18, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 5, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 5, 3, 16, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 9, 3, 15, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 9, 3, 20, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 9, 3, 13, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 13, 3, 24, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 13, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 13, 3, 12, MAP_AQUA_HIDEOUT_B1F
	warp_def 42, 17, 3, 11, MAP_AQUA_HIDEOUT_B1F
	warp_def 45, 17, 3, 17, MAP_AQUA_HIDEOUT_B1F
	warp_def 48, 17, 3, 19, MAP_AQUA_HIDEOUT_B1F
	.globl gMapEvents_AQUA_HIDEOUT_B1F
gMapEvents_AQUA_HIDEOUT_B1F: @ 0x0850DC44
	map_events AQUA_HIDEOUT_B1F_EventObjects, AQUA_HIDEOUT_B1F_EventWarps, 0, 0
	.globl AQUA_HIDEOUT_B2F_EventObjects
AQUA_HIDEOUT_B2F_EventObjects: @ 0x0850DC58
	object_event 1, 117, 0, 23, 19, 3, 9, 0, 0, 0, 0, 0x08217FD9, 0x039C
	object_event 2, 117, 0, 23, 10, 3, 45, 4, 3, 1, 3, 0x0821805A, 0x039C
	object_event 3, 59, 0, 3, 13, 3, 1, 0, 0, 0, 0, 0x082570D6, 0x0430
	object_event 4, 141, 0, 19, 20, 1, 9, 0, 0, 0, 0, 0x00000000, 0x03AF
	object_event 5, 118, 0, 7, 5, 3, 10, 1, 1, 1, 5, 0x0821807F, 0x039C
	object_event 6, 117, 0, 13, 5, 3, 9, 1, 1, 1, 5, 0x08218096, 0x039C
	.globl AQUA_HIDEOUT_B2F_EventWarps
AQUA_HIDEOUT_B2F_EventWarps: @ 0x0850DCE8
	warp_def 18, 1, 3, 1, MAP_AQUA_HIDEOUT_B1F
	warp_def 12, 1, 3, 2, MAP_AQUA_HIDEOUT_B1F
	warp_def 3, 3, 3, 3, MAP_AQUA_HIDEOUT_B1F
	warp_def 31, 8, 3, 5, MAP_AQUA_HIDEOUT_B2F
	warp_def 8, 8, 3, 8, MAP_AQUA_HIDEOUT_B2F
	warp_def 5, 8, 3, 3, MAP_AQUA_HIDEOUT_B2F
	warp_def 18, 13, 3, 7, MAP_AQUA_HIDEOUT_B2F
	warp_def 12, 13, 3, 6, MAP_AQUA_HIDEOUT_B2F
	warp_def 31, 17, 3, 4, MAP_AQUA_HIDEOUT_B2F
	warp_def 32, 20, 3, 4, MAP_AQUA_HIDEOUT_B1F
	.globl AQUA_HIDEOUT_B2F_EventCoordEvents
AQUA_HIDEOUT_B2F_EventCoordEvents: @ 0x0850DD38
	coord_event 28, 17, 3, 16385, 0, AquaHideout_B2F_EventScript_00217FB5
	coord_event 28, 16, 3, 16385, 0, AquaHideout_B2F_EventScript_00217FB5
	.globl gMapEvents_AQUA_HIDEOUT_B2F
gMapEvents_AQUA_HIDEOUT_B2F: @ 0x0850DD58
	map_events AQUA_HIDEOUT_B2F_EventObjects, AQUA_HIDEOUT_B2F_EventWarps, AQUA_HIDEOUT_B2F_EventCoordEvents, 0
	.globl UNDERWATER_SEAFLOOR_CAVERN_EventObjects
UNDERWATER_SEAFLOOR_CAVERN_EventObjects: @ 0x0850DD6C
	object_event 1, 100, 0, 5, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 2, 100, 0, 6, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 3, 100, 0, 7, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	object_event 4, 100, 0, 8, 4, 3, 76, 1, 1, 0, 0, Underwater_SeafloorCavern_EventScript_002183EF, 0x03D4
	.globl UNDERWATER_SEAFLOOR_CAVERN_EventWarps
UNDERWATER_SEAFLOOR_CAVERN_EventWarps: @ 0x0850DDCC
	warp_def 6, 7, 0, 0, MAP_UNDERWATER_ROUTE128
	.globl gMapEvents_UNDERWATER_SEAFLOOR_CAVERN
gMapEvents_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0850DDD4
	map_events UNDERWATER_SEAFLOOR_CAVERN_EventObjects, UNDERWATER_SEAFLOOR_CAVERN_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ENTRANCE_EventObjects
SEAFLOOR_CAVERN_ENTRANCE_EventObjects: @ 0x0850DDE8
	object_event 1, 117, 0, 10, 2, 3, 7, 1, 1, 0, 0, SeafloorCavern_Entrance_EventScript_00218465, 0x03AD
	.globl SEAFLOOR_CAVERN_ENTRANCE_EventWarps
SEAFLOOR_CAVERN_ENTRANCE_EventWarps: @ 0x0850DE00
	warp_def 10, 18, 3, 0, MAP_UNDERWATER_ROUTE128
	warp_def 10, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM1
	.globl gMapEvents_SEAFLOOR_CAVERN_ENTRANCE
gMapEvents_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0850DE10
	map_events SEAFLOOR_CAVERN_ENTRANCE_EventObjects, SEAFLOOR_CAVERN_ENTRANCE_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM1_EventObjects
SEAFLOOR_CAVERN_ROOM1_EventObjects: @ 0x0850DE24
	object_event 1, 87, 0, 5, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 2, 87, 0, 12, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 3, 86, 0, 5, 10, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0013
	object_event 4, 117, 0, 8, 6, 3, 1, 1, 1, 1, 2, 0x0821865F, 0x03B2
	object_event 5, 117, 0, 15, 10, 3, 16, 1, 1, 1, 3, 0x08218676, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM1_EventWarps
SEAFLOOR_CAVERN_ROOM1_EventWarps: @ 0x0850DE9C
	warp_def 5, 18, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE
	warp_def 17, 13, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 6, 2, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM2
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM1
gMapEvents_SEAFLOOR_CAVERN_ROOM1: @ 0x0850DEB4
	map_events SEAFLOOR_CAVERN_ROOM1_EventObjects, SEAFLOOR_CAVERN_ROOM1_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM2_EventObjects
SEAFLOOR_CAVERN_ROOM2_EventObjects: @ 0x0850DEC8
	object_event 1, 87, 0, 13, 3, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 2, 87, 0, 10, 3, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0013
	object_event 3, 87, 0, 13, 5, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0011
	object_event 4, 87, 0, 4, 5, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 5, 87, 0, 7, 4, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 6, 86, 0, 8, 7, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0018
	object_event 7, 86, 0, 9, 3, 3, 1, 0, 0, 0, 0, 0x0825667C, 0x0019
	object_event 8, 87, 0, 4, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0017
	.globl SEAFLOOR_CAVERN_ROOM2_EventWarps
SEAFLOOR_CAVERN_ROOM2_EventWarps: @ 0x0850DF88
	warp_def 10, 7, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM1
	warp_def 4, 10, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM4
	warp_def 6, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM6
	warp_def 11, 1, 3, 0, MAP_SEAFLOOR_CAVERN_ROOM7
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM2
gMapEvents_SEAFLOOR_CAVERN_ROOM2: @ 0x0850DFA8
	map_events SEAFLOOR_CAVERN_ROOM2_EventObjects, SEAFLOOR_CAVERN_ROOM2_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM3_EventObjects
SEAFLOOR_CAVERN_ROOM3_EventObjects: @ 0x0850DFBC
	object_event 1, 87, 0, 13, 10, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0012
	object_event 2, 87, 0, 11, 10, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0014
	object_event 3, 87, 0, 12, 9, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0015
	object_event 4, 87, 0, 12, 7, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0016
	object_event 5, 87, 0, 11, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0017
	object_event 6, 87, 0, 12, 11, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0018
	object_event 7, 87, 0, 13, 8, 3, 1, 0, 0, 0, 0, 0x08256754, 0x0019
	object_event 8, 118, 0, 9, 5, 3, 9, 1, 1, 1, 6, 0x0821873F, 0x03B2
	object_event 9, 117, 0, 5, 5, 3, 10, 1, 1, 1, 4, 0x08218756, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM3_EventWarps
SEAFLOOR_CAVERN_ROOM3_EventWarps: @ 0x0850E094
	warp_def 8, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM8
	warp_def 9, 13, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM7
	warp_def 4, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM6
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM3
gMapEvents_SEAFLOOR_CAVERN_ROOM3: @ 0x0850E0AC
	map_events SEAFLOOR_CAVERN_ROOM3_EventObjects, SEAFLOOR_CAVERN_ROOM3_EventWarps, 0, 0
	.globl SEAFLOOR_CAVERN_ROOM4_EventObjects
SEAFLOOR_CAVERN_ROOM4_EventObjects: @ 0x0850E0C0
	object_event 1, 117, 0, 5, 8, 3, 17, 1, 1, 1, 3, 0x0821892F, 0x03B2
	object_event 2, 118, 0, 5, 12, 3, 7, 1, 1, 1, 3, 0x08218946, 0x03B2
	.globl SEAFLOOR_CAVERN_ROOM4_EventWarps
SEAFLOOR_CAVERN_ROOM4_EventWarps: @ 0x0850E0F0
	warp_def 13, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM2
	warp_def 4, 1, 3, 1, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 9, 10, 3, 2, MAP_SEAFLOOR_CAVERN_ROOM5
	warp_def 10, 15, 3, 1, MAP_SEAFLOOR_CAVERN_ENTRANCE
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM4
gMapEvents_SEAFLOOR_CAVERN_ROOM4: @ 0x0850E110
	map_events SEAFLOOR_CAVERN_ROOM4_EventObjects, SEAFLOOR_CAVERN_ROOM4_EventWarps, 0, 0
	.incbin "baserom_jp.gba", 0x50E124, 0x134C
	.include "data/maps/Underwater_Route134/events.inc"
	.globl gMapEvents_UNDERWATER_ROUTE134
	.set gMapEvents_UNDERWATER_ROUTE134, Underwater_Route134_MapEvents
	.incbin "baserom_jp.gba", 0x50F48C, 0x8210

	.globl sFrozenIceCubeSubspriteTable
sFrozenIceCubeSubspriteTable: @ 0x851769C
sFrozenIceCubeSubspriteTable: @ 0x851769C
	.4byte 4
	.4byte 0x0851768C

	.globl sFrozenIceCubeSpriteTemplate
sFrozenIceCubeSpriteTemplate: @ 0x85176A4
sFrozenIceCubeSpriteTemplate: @ 0x85176A4
	.hword 0x271A, 0x271A
	.4byte sOam_MoveEffectMons + 0x108, gDummySpriteAnimTable, 0, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.globl sFlashingCircleImpactSpriteTemplate
sFlashingCircleImpactSpriteTemplate: @ 0x85176BC
	.hword 0x2798, 0x2798
	.4byte 0x084FD010, gDummySpriteAnimTable, 0, gDummySpriteAffineAnimTable, 0x080A970D
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

	.globl gUnknown_851ADE8
gUnknown_851ADE8: @ 0x851ADE8
	.incbin "baserom_jp.gba", 0x51ade8, 0xc000

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
	.incbin "baserom_jp.gba", 0x536ef0, 0x68

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
