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

	.globl gText_CallCantBeMadeHere
gText_CallCantBeMadeHere: @ 0x85F3E99
	.string "ここでは　よびだすことが　できないようだ$　　"

	.globl sMatchCallUI_Pal
sMatchCallUI_Pal: @ 0x85F3EB0
	.incbin "graphics/misc/sMatchCallUI_Pal.bin"

	.globl sMatchCallUI_Gfx
sMatchCallUI_Gfx: @ 0x85F3ED0
	.incbin "graphics/misc/sMatchCallUI_Gfx.bin"

	.globl sMatchCallUI_Tilemap
	.globl sMatchCallUI_Tilemap
sMatchCallUI_Tilemap: @ 0x5F3F74
	.incbin "graphics/misc/sMatchCallUI_Tilemap.bin"

	.globl sOptionsCursor_Pal
sOptionsCursor_Pal: @ 0x5F4038
	.incbin "graphics/misc/sOptionsCursor_Pal.bin"

	.globl sOptionsCursor_Gfx
sOptionsCursor_Gfx: @ 0x5F4058
	.incbin "graphics/misc/sOptionsCursor_Gfx.bin"


	.globl sCallWindow_Pal
sCallWindow_Pal: @ 0x85F4080
	.incbin "graphics/misc/sCallWindow_Pal.bin"

	.globl sListWindow_Pal
sListWindow_Pal: @ 0x85F40A0
	.incbin "graphics/list_ui/sListWindow_Pal.bin"

	.globl sPokeball_Pal
sPokeball_Pal: @ 0x85F40C0
	.incbin "graphics/misc/sPokeball_Pal.bin"

	.globl sPokeball_Gfx
sPokeball_Gfx: @ 0x85F4100
	.incbin "graphics/misc/sPokeball_Gfx.bin"
