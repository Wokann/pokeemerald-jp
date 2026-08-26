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

#include "constants/tms_hms.inc"

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

	.include "data/maps/PetalburgCity/events.inc"
	.globl gMapEvents_PETALBURG_CITY
	.set gMapEvents_PETALBURG_CITY, PetalburgCity_MapEvents
	.include "data/maps/SlateportCity/events.inc"
	.globl gMapEvents_SLATEPORT_CITY
	.set gMapEvents_SLATEPORT_CITY, SlateportCity_MapEvents
	.include "data/maps/MauvilleCity/events.inc"
	.globl gMapEvents_MAUVILLE_CITY
	.set gMapEvents_MAUVILLE_CITY, MauvilleCity_MapEvents
	.include "data/maps/RustboroCity/events.inc"
	.globl gMapEvents_RUSTBORO_CITY
	.set gMapEvents_RUSTBORO_CITY, RustboroCity_MapEvents
	.include "data/maps/FortreeCity/events.inc"
	.globl gMapEvents_FORTREE_CITY
	.set gMapEvents_FORTREE_CITY, FortreeCity_MapEvents
	.include "data/maps/LilycoveCity/events.inc"
	.globl gMapEvents_LILYCOVE_CITY
	.set gMapEvents_LILYCOVE_CITY, LilycoveCity_MapEvents
	.include "data/maps/MossdeepCity/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY
	.set gMapEvents_MOSSDEEP_CITY, MossdeepCity_MapEvents
	.include "data/maps/SootopolisCity/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY
	.set gMapEvents_SOOTOPOLIS_CITY, SootopolisCity_MapEvents
	.include "data/maps/EverGrandeCity/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY
	.set gMapEvents_EVER_GRANDE_CITY, EverGrandeCity_MapEvents
	.include "data/maps/LittlerootTown/events.inc"
	.globl gMapEvents_LITTLEROOT_TOWN
	.set gMapEvents_LITTLEROOT_TOWN, LittlerootTown_MapEvents
	.include "data/maps/OldaleTown/events.inc"
	.globl gMapEvents_OLDALE_TOWN
	.set gMapEvents_OLDALE_TOWN, OldaleTown_MapEvents
	.include "data/maps/DewfordTown/events.inc"
	.globl gMapEvents_DEWFORD_TOWN
	.set gMapEvents_DEWFORD_TOWN, DewfordTown_MapEvents
	.include "data/maps/LavaridgeTown/events.inc"
	.globl gMapEvents_LAVARIDGE_TOWN
	.set gMapEvents_LAVARIDGE_TOWN, LavaridgeTown_MapEvents
	.include "data/maps/FallarborTown/events.inc"
	.globl gMapEvents_FALLARBOR_TOWN
	.set gMapEvents_FALLARBOR_TOWN, FallarborTown_MapEvents
	.include "data/maps/VerdanturfTown/events.inc"
	.globl gMapEvents_VERDANTURF_TOWN
	.set gMapEvents_VERDANTURF_TOWN, VerdanturfTown_MapEvents
	.include "data/maps/PacifidlogTown/events.inc"
	.globl gMapEvents_PACIFIDLOG_TOWN
	.set gMapEvents_PACIFIDLOG_TOWN, PacifidlogTown_MapEvents
	.include "data/maps/Route101/events.inc"
	.globl gMapEvents_ROUTE101
	.set gMapEvents_ROUTE101, Route101_MapEvents
	.include "data/maps/Route102/events.inc"
	.globl gMapEvents_ROUTE102
	.set gMapEvents_ROUTE102, Route102_MapEvents
	.include "data/maps/Route103/events.inc"
	.globl gMapEvents_ROUTE103
	.set gMapEvents_ROUTE103, Route103_MapEvents
	.include "data/maps/Route104/events.inc"
	.globl gMapEvents_ROUTE104
	.set gMapEvents_ROUTE104, Route104_MapEvents
	.include "data/maps/Route105/events.inc"
	.globl gMapEvents_ROUTE105
	.set gMapEvents_ROUTE105, Route105_MapEvents
	.include "data/maps/Route106/events.inc"
	.globl gMapEvents_ROUTE106
	.set gMapEvents_ROUTE106, Route106_MapEvents
	.include "data/maps/Route107/events.inc"
	.globl gMapEvents_ROUTE107
	.set gMapEvents_ROUTE107, Route107_MapEvents
	.include "data/maps/Route108/events.inc"
	.globl gMapEvents_ROUTE108
	.set gMapEvents_ROUTE108, Route108_MapEvents
	.include "data/maps/Route109/events.inc"
	.globl gMapEvents_ROUTE109
	.set gMapEvents_ROUTE109, Route109_MapEvents
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
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects: @ 0x08506A9C
	object_event 1, 44, 0, 6, 5, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_Attendant, 0x0000
	object_event 2, 55, 0, 1, 5, 3, 5, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_Hiker, 0x0000
	object_event 3, 11, 0, 12, 6, 3, 3, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_LittleBoy, 0x0000
	object_event 4, 47, 0, 10, 9, 3, 8, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_Lass, 0x0000
	object_event 5, 219, 0, 0, 7, 3, 10, 1, 1, 0, 0, FallarborTown_BattleTentLobby_EventScript_Scott, 0x02FF
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps: @ 0x08506B14
	warp_def 6, 9, 0, 1, MAP_FALLARBOR_TOWN
	warp_def 7, 9, 0, 1, MAP_FALLARBOR_TOWN
	.globl FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents: @ 0x08506B24
	bg_event 4, 5, 0, 0, FallarborTown_BattleTentLobby_EventScript_RulesBoard, 0, 0
	.globl gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08506B30
	map_events FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventObjects, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventWarps, 0, FALLARBOR_TOWN_BATTLE_TENT_LOBBY_EventBgEvents
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
	@ Petalburg Gym events remain in this legacy owner until their separate
	@ map.json/events.inc migration; keep every script pointer semantic here.
	.globl PETALBURG_CITY_GYM_EventObjects
PETALBURG_CITY_GYM_EventObjects: @ 0x085074F4
	object_event 1, 129, 0, 4, 2, 0, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_Norman, 0x0304
	object_event 2, 34, 0, 4, 94, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Mary, 0x0000
	object_event 3, 33, 0, 4, 81, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Randall, 0x0000
	object_event 4, 33, 0, 4, 42, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Parker, 0x0000
	object_event 5, 34, 0, 4, 55, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Alexia, 0x0000
	object_event 6, 33, 0, 4, 68, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_George, 0x0000
	object_event 7, 34, 0, 4, 16, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Jody, 0x0000
	object_event 8, 33, 0, 4, 29, 3, 8, 0, 0, 1, 0, PetalburgCity_Gym_EventScript_Berke, 0x0000
	object_event 9, 23, 0, 3, 109, 3, 8, 0, 0, 0, 0, PetalburgCity_Gym_EventScript_GymGuide, 0x030D
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
	bg_event 1, 105, 3, 0, PetalburgCity_Gym_EventScript_SpeedRoomDoor, 0, 0
	bg_event 7, 105, 3, 0, PetalburgCity_Gym_EventScript_AccuracyRoomDoor, 0, 0
	bg_event 1, 79, 3, 0, PetalburgCity_Gym_EventScript_ConfusionRoomDoor, 0, 0
	bg_event 7, 79, 3, 0, PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor, 0, 0
	bg_event 1, 92, 3, 0, PetalburgCity_Gym_EventScript_RightDefenseRoomDoor, 0, 0
	bg_event 7, 92, 3, 0, PetalburgCity_Gym_EventScript_RecoveryRoomDoor, 0, 0
	bg_event 7, 40, 3, 0, PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor, 0, 0
	bg_event 1, 53, 3, 0, PetalburgCity_Gym_EventScript_RightStrengthRoomDoor, 0, 0
	bg_event 7, 53, 3, 0, PetalburgCity_Gym_EventScript_LeftOHKORoomDoor, 0, 0
	bg_event 1, 66, 3, 0, PetalburgCity_Gym_EventScript_RightOHKORoomDoor, 0, 0
	bg_event 7, 14, 3, 0, PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor, 0, 0
	bg_event 1, 27, 3, 0, PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor, 0, 0
	bg_event 1, 110, 3, 1, PetalburgCity_Gym_EventScript_LeftGymStatue, 0, 0
	bg_event 7, 110, 3, 1, PetalburgCity_Gym_EventScript_RightGymStatue, 0, 0
	.globl gMapEvents_PETALBURG_CITY_GYM
gMapEvents_PETALBURG_CITY_GYM: @ 0x085077D4
	map_events PETALBURG_CITY_GYM_EventObjects, PETALBURG_CITY_GYM_EventWarps, 0, PETALBURG_CITY_GYM_EventBgEvents
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
	.globl gMapEvents_RUSTBORO_CITY_HOUSE3
	.set gMapEvents_RUSTBORO_CITY_HOUSE3, RustboroCity_House3_MapEvents
	.include "data/maps/FortreeCity_House1/events.inc"
	.globl gMapEvents_FORTREE_CITY_HOUSE1
	.set gMapEvents_FORTREE_CITY_HOUSE1, FortreeCity_House1_MapEvents
	.include "data/maps/FortreeCity_Gym/events.inc"
	.globl gMapEvents_FORTREE_CITY_GYM
	.set gMapEvents_FORTREE_CITY_GYM, FortreeCity_Gym_MapEvents
	.include "data/maps/FortreeCity_PokemonCenter_1F/events.inc"
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F
	.set gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F, FortreeCity_PokemonCenter_1F_MapEvents
	.include "data/maps/FortreeCity_PokemonCenter_2F/events.inc"
	.globl gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F
	.set gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F, FortreeCity_PokemonCenter_2F_MapEvents
	.include "data/maps/FortreeCity_Mart/events.inc"
	.globl gMapEvents_FORTREE_CITY_MART
	.set gMapEvents_FORTREE_CITY_MART, FortreeCity_Mart_MapEvents
	.include "data/maps/FortreeCity_House2/events.inc"
	.globl gMapEvents_FORTREE_CITY_HOUSE2
	.set gMapEvents_FORTREE_CITY_HOUSE2, FortreeCity_House2_MapEvents
	.include "data/maps/FortreeCity_House3/events.inc"
	.globl gMapEvents_FORTREE_CITY_HOUSE3
	.set gMapEvents_FORTREE_CITY_HOUSE3, FortreeCity_House3_MapEvents
	.include "data/maps/FortreeCity_House4/events.inc"
	.globl gMapEvents_FORTREE_CITY_HOUSE4
	.set gMapEvents_FORTREE_CITY_HOUSE4, FortreeCity_House4_MapEvents
	.include "data/maps/FortreeCity_House5/events.inc"
	.globl gMapEvents_FORTREE_CITY_HOUSE5
	.set gMapEvents_FORTREE_CITY_HOUSE5, FortreeCity_House5_MapEvents
	.include "data/maps/FortreeCity_DecorationShop/events.inc"
	.globl gMapEvents_FORTREE_CITY_DECORATION_SHOP
	.set gMapEvents_FORTREE_CITY_DECORATION_SHOP, FortreeCity_DecorationShop_MapEvents
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
	.set gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F, LilycoveCity_CoveLilyMotel_1F_MapEvents
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
	.set gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F, LilycoveCity_CoveLilyMotel_2F_MapEvents
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
	.set gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F, LilycoveCity_LilycoveMuseum_1F_MapEvents
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
	.set gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, LilycoveCity_LilycoveMuseum_2F_MapEvents
	.include "data/maps/LilycoveCity_ContestLobby/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY
	.set gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY, LilycoveCity_ContestLobby_MapEvents
	.include "data/maps/LilycoveCity_ContestHall/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_CONTEST_HALL
	.set gMapEvents_LILYCOVE_CITY_CONTEST_HALL, LilycoveCity_ContestHall_MapEvents
	.include "data/maps/LilycoveCity_PokemonCenter_1F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F
	.set gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F, LilycoveCity_PokemonCenter_1F_MapEvents
	.include "data/maps/LilycoveCity_PokemonCenter_2F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F
	.set gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F, LilycoveCity_PokemonCenter_2F_MapEvents
	.include "data/maps/LilycoveCity_UnusedMart/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_UNUSED_MART
	.set gMapEvents_LILYCOVE_CITY_UNUSED_MART, LilycoveCity_UnusedMart_MapEvents
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
	.set gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB, LilycoveCity_PokemonTrainerFanClub_MapEvents
	.include "data/maps/LilycoveCity_Harbor/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_HARBOR
	.set gMapEvents_LILYCOVE_CITY_HARBOR, LilycoveCity_Harbor_MapEvents
	.include "data/maps/LilycoveCity_MoveDeletersHouse/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE
	.set gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE, LilycoveCity_MoveDeletersHouse_MapEvents
	.include "data/maps/LilycoveCity_House1/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_HOUSE1
	.set gMapEvents_LILYCOVE_CITY_HOUSE1, LilycoveCity_House1_MapEvents
	.include "data/maps/LilycoveCity_House2/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_HOUSE2
	.set gMapEvents_LILYCOVE_CITY_HOUSE2, LilycoveCity_House2_MapEvents
	.include "data/maps/LilycoveCity_House3/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_HOUSE3
	.set gMapEvents_LILYCOVE_CITY_HOUSE3, LilycoveCity_House3_MapEvents
	.include "data/maps/LilycoveCity_House4/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_HOUSE4
	.set gMapEvents_LILYCOVE_CITY_HOUSE4, LilycoveCity_House4_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStore_1F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F, LilycoveCity_DepartmentStore_1F_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStore_2F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F, LilycoveCity_DepartmentStore_2F_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStore_3F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F, LilycoveCity_DepartmentStore_3F_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStore_4F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F, LilycoveCity_DepartmentStore_4F_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStore_5F/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F, LilycoveCity_DepartmentStore_5F_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP, LilycoveCity_DepartmentStoreRooftop_MapEvents
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/events.inc"
	.globl gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
	.set gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR, LilycoveCity_DepartmentStoreElevator_MapEvents
	.include "data/maps/MossdeepCity_Gym/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_GYM
	.set gMapEvents_MOSSDEEP_CITY_GYM, MossdeepCity_Gym_MapEvents
	.include "data/maps/MossdeepCity_House1/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE1
	.set gMapEvents_MOSSDEEP_CITY_HOUSE1, MossdeepCity_House1_MapEvents
	.include "data/maps/MossdeepCity_House2/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE2
	.set gMapEvents_MOSSDEEP_CITY_HOUSE2, MossdeepCity_House2_MapEvents
	.include "data/maps/MossdeepCity_PokemonCenter_1F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F
	.set gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F, MossdeepCity_PokemonCenter_1F_MapEvents
	.include "data/maps/MossdeepCity_PokemonCenter_2F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F
	.set gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F, MossdeepCity_PokemonCenter_2F_MapEvents
	.include "data/maps/MossdeepCity_Mart/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_MART
	.set gMapEvents_MOSSDEEP_CITY_MART, MossdeepCity_Mart_MapEvents
	.include "data/maps/MossdeepCity_House3/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE3
	.set gMapEvents_MOSSDEEP_CITY_HOUSE3, MossdeepCity_House3_MapEvents
	.include "data/maps/MossdeepCity_StevensHouse/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE
	.set gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE, MossdeepCity_StevensHouse_MapEvents
	.include "data/maps/MossdeepCity_House4/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_HOUSE4
	.set gMapEvents_MOSSDEEP_CITY_HOUSE4, MossdeepCity_House4_MapEvents
	.include "data/maps/MossdeepCity_SpaceCenter_1F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F
	.set gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F, MossdeepCity_SpaceCenter_1F_MapEvents
	.include "data/maps/MossdeepCity_SpaceCenter_2F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F
	.set gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F, MossdeepCity_SpaceCenter_2F_MapEvents
	.include "data/maps/MossdeepCity_GameCorner_1F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F
	.set gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F, MossdeepCity_GameCorner_1F_MapEvents
	.include "data/maps/MossdeepCity_GameCorner_B1F/events.inc"
	.globl gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F
	.set gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F, MossdeepCity_GameCorner_B1F_MapEvents
	.include "data/maps/SootopolisCity_Gym_1F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_1F
	.set gMapEvents_SOOTOPOLIS_CITY_GYM_1F, SootopolisCity_Gym_1F_MapEvents
	.include "data/maps/SootopolisCity_Gym_B1F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_GYM_B1F
	.set gMapEvents_SOOTOPOLIS_CITY_GYM_B1F, SootopolisCity_Gym_B1F_MapEvents
	.include "data/maps/SootopolisCity_PokemonCenter_1F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F
	.set gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F, SootopolisCity_PokemonCenter_1F_MapEvents
	.include "data/maps/SootopolisCity_PokemonCenter_2F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F
	.set gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F, SootopolisCity_PokemonCenter_2F_MapEvents
	.include "data/maps/SootopolisCity_Mart/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_MART
	.set gMapEvents_SOOTOPOLIS_CITY_MART, SootopolisCity_Mart_MapEvents
	.include "data/maps/SootopolisCity_House1/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE1
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE1, SootopolisCity_House1_MapEvents
	.include "data/maps/SootopolisCity_House2/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE2
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE2, SootopolisCity_House2_MapEvents
	.include "data/maps/SootopolisCity_House3/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE3
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE3, SootopolisCity_House3_MapEvents
	.include "data/maps/SootopolisCity_House4/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE4
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE4, SootopolisCity_House4_MapEvents
	.include "data/maps/SootopolisCity_House5/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE5
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE5, SootopolisCity_House5_MapEvents
	.include "data/maps/SootopolisCity_House6/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE6
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE6, SootopolisCity_House6_MapEvents
	.include "data/maps/SootopolisCity_House7/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_HOUSE7
	.set gMapEvents_SOOTOPOLIS_CITY_HOUSE7, SootopolisCity_House7_MapEvents
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
	.set gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE, SootopolisCity_LotadAndSeedotHouse_MapEvents
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
	.set gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, SootopolisCity_MysteryEventsHouse_1F_MapEvents
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/events.inc"
	.globl gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
	.set gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, SootopolisCity_MysteryEventsHouse_B1F_MapEvents
	.include "data/maps/EverGrandeCity_SidneysRoom/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM
	.set gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM, EverGrandeCity_SidneysRoom_MapEvents
	.include "data/maps/EverGrandeCity_PhoebesRoom/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM
	.set gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM, EverGrandeCity_PhoebesRoom_MapEvents
	.include "data/maps/EverGrandeCity_GlaciasRoom/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM
	.set gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM, EverGrandeCity_GlaciasRoom_MapEvents
	.include "data/maps/EverGrandeCity_DrakesRoom/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM
	.set gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM, EverGrandeCity_DrakesRoom_MapEvents
	.include "data/maps/EverGrandeCity_ChampionsRoom/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM
	.set gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM, EverGrandeCity_ChampionsRoom_MapEvents
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
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
	.set gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F, EverGrandeCity_PokemonLeague_1F_MapEvents
	.include "data/maps/EverGrandeCity_HallOfFame/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME
	.set gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME, EverGrandeCity_HallOfFame_MapEvents
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F
	.set gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F, EverGrandeCity_PokemonCenter_1F_MapEvents
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F
	.set gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F, EverGrandeCity_PokemonCenter_2F_MapEvents
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/events.inc"
	.globl gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F
	.set gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F, EverGrandeCity_PokemonLeague_2F_MapEvents
	.include "data/maps/Route104_MrBrineysHouse/events.inc"
	.globl gMapEvents_ROUTE104_MR_BRINEYS_HOUSE
	.set gMapEvents_ROUTE104_MR_BRINEYS_HOUSE, Route104_MrBrineysHouse_MapEvents
	.include "data/maps/Route104_PrettyPetalFlowerShop/events.inc"
	.globl gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
	.set gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP, Route104_PrettyPetalFlowerShop_MapEvents
	.include "data/maps/Route111_WinstrateFamilysHouse/events.inc"
	.globl gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE
	.set gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE, Route111_WinstrateFamilysHouse_MapEvents
	.include "data/maps/Route111_OldLadysRestStop/events.inc"
	.globl gMapEvents_ROUTE111_OLD_LADYS_REST_STOP
	.set gMapEvents_ROUTE111_OLD_LADYS_REST_STOP, Route111_OldLadysRestStop_MapEvents
	.include "data/maps/Route112_CableCarStation/events.inc"
	.globl gMapEvents_ROUTE112_CABLE_CAR_STATION
	.set gMapEvents_ROUTE112_CABLE_CAR_STATION, Route112_CableCarStation_MapEvents
	.include "data/maps/MtChimney_CableCarStation/events.inc"
	.globl gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION
	.set gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION, MtChimney_CableCarStation_MapEvents
	.include "data/maps/Route114_FossilManiacsHouse/events.inc"
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE
	.set gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE, Route114_FossilManiacsHouse_MapEvents
	.include "data/maps/Route114_FossilManiacsTunnel/events.inc"
	.globl gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL
	.set gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL, Route114_FossilManiacsTunnel_MapEvents
	.include "data/maps/Route114_LanettesHouse/events.inc"
	.globl gMapEvents_ROUTE114_LANETTES_HOUSE
	.set gMapEvents_ROUTE114_LANETTES_HOUSE, Route114_LanettesHouse_MapEvents
	.include "data/maps/Route116_TunnelersRestHouse/events.inc"
	.globl gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE
	.set gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE, Route116_TunnelersRestHouse_MapEvents
	.include "data/maps/Route117_PokemonDayCare/events.inc"
	.globl gMapEvents_ROUTE117_POKEMON_DAY_CARE
	.set gMapEvents_ROUTE117_POKEMON_DAY_CARE, Route117_PokemonDayCare_MapEvents
	.include "data/maps/Route121_SafariZoneEntrance/events.inc"
	.globl gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE
	.set gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE, Route121_SafariZoneEntrance_MapEvents
	.include "data/maps/MeteorFalls_1F_1R/events.inc"
	.globl gMapEvents_METEOR_FALLS_1F_1R
	.set gMapEvents_METEOR_FALLS_1F_1R, MeteorFalls_1F_1R_MapEvents
	.include "data/maps/MeteorFalls_1F_2R/events.inc"
	.globl gMapEvents_METEOR_FALLS_1F_2R
	.set gMapEvents_METEOR_FALLS_1F_2R, MeteorFalls_1F_2R_MapEvents
	.include "data/maps/MeteorFalls_B1F_1R/events.inc"
	.globl gMapEvents_METEOR_FALLS_B1F_1R
	.set gMapEvents_METEOR_FALLS_B1F_1R, MeteorFalls_B1F_1R_MapEvents
	.include "data/maps/MeteorFalls_B1F_2R/events.inc"
	.globl gMapEvents_METEOR_FALLS_B1F_2R
	.set gMapEvents_METEOR_FALLS_B1F_2R, MeteorFalls_B1F_2R_MapEvents
	.include "data/maps/RusturfTunnel/events.inc"
	.globl gMapEvents_RUSTURF_TUNNEL
	.set gMapEvents_RUSTURF_TUNNEL, RusturfTunnel_MapEvents
	.include "data/maps/Underwater_SootopolisCity/events.inc"
	.globl gMapEvents_UNDERWATER_SOOTOPOLIS_CITY
	.set gMapEvents_UNDERWATER_SOOTOPOLIS_CITY, Underwater_SootopolisCity_MapEvents
	.include "data/maps/DesertRuins/events.inc"
	.globl gMapEvents_DESERT_RUINS
	.set gMapEvents_DESERT_RUINS, DesertRuins_MapEvents
	.include "data/maps/GraniteCave_1F/events.inc"
	.globl gMapEvents_GRANITE_CAVE_1F
	.set gMapEvents_GRANITE_CAVE_1F, GraniteCave_1F_MapEvents
	.include "data/maps/GraniteCave_B1F/events.inc"
	.globl gMapEvents_GRANITE_CAVE_B1F
	.set gMapEvents_GRANITE_CAVE_B1F, GraniteCave_B1F_MapEvents
	.include "data/maps/GraniteCave_B2F/events.inc"
	.globl gMapEvents_GRANITE_CAVE_B2F
	.set gMapEvents_GRANITE_CAVE_B2F, GraniteCave_B2F_MapEvents
	.include "data/maps/GraniteCave_StevensRoom/events.inc"
	.globl gMapEvents_GRANITE_CAVE_STEVENS_ROOM
	.set gMapEvents_GRANITE_CAVE_STEVENS_ROOM, GraniteCave_StevensRoom_MapEvents
	.include "data/maps/PetalburgWoods/events.inc"
	.globl gMapEvents_PETALBURG_WOODS
	.set gMapEvents_PETALBURG_WOODS, PetalburgWoods_MapEvents
	.include "data/maps/MtChimney/events.inc"
	.globl gMapEvents_MT_CHIMNEY
	.set gMapEvents_MT_CHIMNEY, MtChimney_MapEvents
	.include "data/maps/JaggedPass/events.inc"
	.globl gMapEvents_JAGGED_PASS
	.set gMapEvents_JAGGED_PASS, JaggedPass_MapEvents
	.include "data/maps/FieryPath/events.inc"
	.globl gMapEvents_FIERY_PATH
	.set gMapEvents_FIERY_PATH, FieryPath_MapEvents
	.include "data/maps/MtPyre_1F/events.inc"
	.globl gMapEvents_MT_PYRE_1F
	.set gMapEvents_MT_PYRE_1F, MtPyre_1F_MapEvents
	.include "data/maps/MtPyre_2F/events.inc"
	.globl gMapEvents_MT_PYRE_2F
	.set gMapEvents_MT_PYRE_2F, MtPyre_2F_MapEvents
	.include "data/maps/MtPyre_3F/events.inc"
	.globl gMapEvents_MT_PYRE_3F
	.set gMapEvents_MT_PYRE_3F, MtPyre_3F_MapEvents
	.include "data/maps/MtPyre_4F/events.inc"
	.globl gMapEvents_MT_PYRE_4F
	.set gMapEvents_MT_PYRE_4F, MtPyre_4F_MapEvents
	.include "data/maps/MtPyre_5F/events.inc"
	.globl gMapEvents_MT_PYRE_5F
	.set gMapEvents_MT_PYRE_5F, MtPyre_5F_MapEvents
	.include "data/maps/MtPyre_6F/events.inc"
	.globl gMapEvents_MT_PYRE_6F
	.set gMapEvents_MT_PYRE_6F, MtPyre_6F_MapEvents
	.include "data/maps/MtPyre_Exterior/events.inc"
	.globl gMapEvents_MT_PYRE_EXTERIOR
	.set gMapEvents_MT_PYRE_EXTERIOR, MtPyre_Exterior_MapEvents
	.include "data/maps/MtPyre_Summit/events.inc"
	.globl gMapEvents_MT_PYRE_SUMMIT
	.set gMapEvents_MT_PYRE_SUMMIT, MtPyre_Summit_MapEvents
	.include "data/maps/AquaHideout_1F/events.inc"
	.globl gMapEvents_AQUA_HIDEOUT_1F
	.set gMapEvents_AQUA_HIDEOUT_1F, AquaHideout_1F_MapEvents
	.include "data/maps/AquaHideout_B1F/events.inc"
	.globl gMapEvents_AQUA_HIDEOUT_B1F
	.set gMapEvents_AQUA_HIDEOUT_B1F, AquaHideout_B1F_MapEvents
	.include "data/maps/AquaHideout_B2F/events.inc"
	.globl gMapEvents_AQUA_HIDEOUT_B2F
	.set gMapEvents_AQUA_HIDEOUT_B2F, AquaHideout_B2F_MapEvents
	.include "data/maps/Underwater_SeafloorCavern/events.inc"
	.globl gMapEvents_UNDERWATER_SEAFLOOR_CAVERN
	.set gMapEvents_UNDERWATER_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_MapEvents
	.include "data/maps/SeafloorCavern_Entrance/events.inc"
	.globl gMapEvents_SEAFLOOR_CAVERN_ENTRANCE
	.set gMapEvents_SEAFLOOR_CAVERN_ENTRANCE, SeafloorCavern_Entrance_MapEvents
	.include "data/maps/SeafloorCavern_Room1/events.inc"
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM1
	.set gMapEvents_SEAFLOOR_CAVERN_ROOM1, SeafloorCavern_Room1_MapEvents
	.include "data/maps/SeafloorCavern_Room2/events.inc"
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM2
	.set gMapEvents_SEAFLOOR_CAVERN_ROOM2, SeafloorCavern_Room2_MapEvents
	.include "data/maps/SeafloorCavern_Room3/events.inc"
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM3
	.set gMapEvents_SEAFLOOR_CAVERN_ROOM3, SeafloorCavern_Room3_MapEvents
	.include "data/maps/SeafloorCavern_Room4/events.inc"
	.globl gMapEvents_SEAFLOOR_CAVERN_ROOM4
	.set gMapEvents_SEAFLOOR_CAVERN_ROOM4, SeafloorCavern_Room4_MapEvents
	.include "data/maps/SeafloorCavern_Room5/events.inc"
	.include "data/maps/SeafloorCavern_Room6/events.inc"
	.include "data/maps/SeafloorCavern_Room7/events.inc"
	.include "data/maps/SeafloorCavern_Room8/events.inc"
	.include "data/maps/SeafloorCavern_Room9/events.inc"
	.include "data/maps/CaveOfOrigin_Entrance/events.inc"
	.incbin "baserom_jp.gba", 0x50E46C, 0x1004
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
