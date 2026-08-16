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

	.globl gUnknown_85A86F4
gUnknown_85A86F4: @ 0x85A86F4
	.incbin "baserom_jp.gba", 0x5a86f4, 0x4

	.globl sSlice_Funcs
sSlice_Funcs: @ 0x85A86F8
	.4byte Slice_Init + 1, Slice_Main + 1, Slice_End + 1

	.globl sShredSplit_Funcs
sShredSplit_Funcs: @ 0x85A8704
	.4byte ShredSplit_Init + 1, ShredSplit_Main + 1, ShredSplit_BrokenCheck + 1, ShredSplit_End + 1

	.globl gUnknown_85A8714
gUnknown_85A8714: @ 0x85A8714
	.incbin "baserom_jp.gba", 0x5a8714, 0x2

	.globl gUnknown_85A8716
gUnknown_85A8716: @ 0x85A8716
	.incbin "baserom_jp.gba", 0x5a8716, 0x6

	.globl sBlackhole_Funcs
sBlackhole_Funcs: @ 0x85A871C
	.4byte Blackhole_Init + 1, Blackhole_Vibrate + 1, Blackhole_GrowEnd + 1

	.globl sBlackholePulsate_Funcs
sBlackholePulsate_Funcs: @ 0x85A8728
	.4byte Blackhole_Init + 1, BlackholePulsate_Main + 1

	.globl gUnknown_85A8730
gUnknown_85A8730: @ 0x85A8730
	.incbin "baserom_jp.gba", 0x5a8730, 0x4

	.globl gUnknown_85A8734
gUnknown_85A8734: @ 0x85A8734
	.incbin "baserom_jp.gba", 0x5a8734, 0xb4

	.globl gUnknown_85A87E8
gUnknown_85A87E8: @ 0x85A87E8
	.incbin "baserom_jp.gba", 0x5a87e8, 0x8

	.globl sGroudon_Funcs
sGroudon_Funcs: @ 0x85A87F0
	.4byte WeatherTrio_BgFadeBlack + 1, WeatherTrio_WaitFade + 1, Groudon_Init + 1, Groudon_PaletteFlash + 1, Groudon_PaletteBrighten + 1, FramesCountdown + 1, WeatherDuo_FadeOut + 1, WeatherDuo_End + 1

	.globl sRayquaza_Funcs
sRayquaza_Funcs: @ 0x85A8810
	.4byte WeatherTrio_BgFadeBlack + 1, WeatherTrio_WaitFade + 1, Rayquaza_Init + 1, Rayquaza_SetGfx + 1, Rayquaza_PaletteFlash + 1, Rayquaza_FadeToBlack + 1, Rayquaza_WaitFade + 1, Rayquaza_SetBlack + 1, Rayquaza_TriRing + 1, Blackhole_Vibrate + 1, Blackhole_GrowEnd + 1

	.globl sWhiteBarsFade_Funcs
sWhiteBarsFade_Funcs: @ 0x85A883C
	.4byte WhiteBarsFade_Init + 1, WhiteBarsFade_StartBars + 1, WhiteBarsFade_WaitBars + 1, WhiteBarsFade_BlendToBlack + 1, WhiteBarsFade_End + 1

	.globl gUnknown_85A8850
gUnknown_85A8850: @ 0x85A8850
	.incbin "baserom_jp.gba", 0x5a8850, 0x10

	.globl sGridSquares_Funcs
sGridSquares_Funcs: @ 0x85A8860
	.4byte GridSquares_Init + 1, GridSquares_Main + 1, GridSquares_End + 1

	.globl sAngledWipes_Funcs
sAngledWipes_Funcs: @ 0x85A886C
	.4byte AngledWipes_Init + 1, AngledWipes_SetWipeData + 1, AngledWipes_DoWipe + 1, AngledWipes_TryEnd + 1, AngledWipes_StartNext + 1

	.globl gUnknown_85A8880
gUnknown_85A8880: @ 0x85A8880
	.incbin "baserom_jp.gba", 0x5a8880, 0x46

	.globl gUnknown_85A88C6
gUnknown_85A88C6: @ 0x85A88C6
	.incbin "baserom_jp.gba", 0x5a88c6, 0xe

	.globl gUnknown_85A88D4
gUnknown_85A88D4: @ 0x85A88D4
	.incbin "baserom_jp.gba", 0x5a88d4, 0x44

	.globl gUnknown_85A8918
gUnknown_85A8918: @ 0x85A8918
	.incbin "baserom_jp.gba", 0x5a8918, 0x6c

	.globl gUnknown_85A8984
gUnknown_85A8984: @ 0x85A8984
	.incbin "baserom_jp.gba", 0x5a8984, 0x108

	.globl gUnknown_85A8A8C
gUnknown_85A8A8C: @ 0x85A8A8C
	.incbin "baserom_jp.gba", 0x5a8a8c, 0x14

	.globl gUnknown_85A8AA0
gUnknown_85A8AA0: @ 0x85A8AA0
	.incbin "baserom_jp.gba", 0x5a8aa0, 0x30

	.globl gUnknown_85A8AD0
gUnknown_85A8AD0: @ 0x85A8AD0
	.incbin "baserom_jp.gba", 0x5a8ad0, 0x4b0

	.globl gUnknown_85A8F80
gUnknown_85A8F80: @ 0x85A8F80
	.incbin "baserom_jp.gba", 0x5a8f80, 0x500

	.globl gUnknown_85A9480
gUnknown_85A9480: @ 0x85A9480
	.incbin "baserom_jp.gba", 0x5a9480, 0x18

	.globl gUnknown_85A9498
gUnknown_85A9498: @ 0x85A9498
	.incbin "baserom_jp.gba", 0x5a9498, 0x10

	.globl gUnknown_85A94A8
gUnknown_85A94A8: @ 0x85A94A8
	.incbin "baserom_jp.gba", 0x5a94a8, 0x10

	.globl gUnknown_85A94B8
gUnknown_85A94B8: @ 0x85A94B8
	.incbin "baserom_jp.gba", 0x5a94b8, 0x14

	.globl gUnknown_85A94CC
gUnknown_85A94CC: @ 0x85A94CC
	.incbin "baserom_jp.gba", 0x5a94cc, 0x14

	.globl sFrontierSquaresSpiral_Positions
sFrontierSquaresSpiral_Positions: @ 0x85A94E0
	.incbin "baserom_jp.gba", 0x5a94e0, 0x23

	.globl gUnknown_85A9503
gUnknown_85A9503: @ 0x85A9503
	.incbin "baserom_jp.gba", 0x5a9503, 0x41

	.globl gUnknown_85A9544
gUnknown_85A9544: @ 0x85A9544
	.incbin "baserom_jp.gba", 0x5a9544, 0x7d1
