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

	.globl sMapSecInfoWindow_Pal
sMapSecInfoWindow_Pal: @ 0x85F4208
	.incbin "graphics/misc/sMapSecInfoWindow_Pal.bin"

	.globl gRegionMapCityZoomTiles_Pal
gRegionMapCityZoomTiles_Pal: @ 0x85F4228
	.incbin "graphics/misc/gRegionMapCityZoomTiles_Pal.bin"

	.globl sRegionMapCityZoomTiles_Gfx
	.globl sRegionMapCityZoomTiles_Gfx
sRegionMapCityZoomTiles_Gfx: @ 0x5F4248
	.incbin "graphics/misc/sRegionMapCityZoomTiles_Gfx.bin"

	.balign 4

	.globl gPokenavCityMap_Lavaridge_0
gPokenavCityMap_Lavaridge_0: @ 0x085F443C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Lavaridge_0.bin"
	.balign 4

	.globl gPokenavCityMap_Fallarbor_0
gPokenavCityMap_Fallarbor_0: @ 0x085F4480
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Fallarbor_0.bin"
	.balign 4

	.globl gPokenavCityMap_Fortree_0
gPokenavCityMap_Fortree_0: @ 0x085F44C8
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Fortree_0.bin"
	.balign 4

	.globl gPokenavCityMap_Slateport_0
gPokenavCityMap_Slateport_0: @ 0x085F4518
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Slateport_0.bin"
	.balign 4

	.globl gPokenavCityMap_Slateport_1
gPokenavCityMap_Slateport_1: @ 0x085F4578
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Slateport_1.bin"
	.balign 4

	.globl gPokenavCityMap_Rustboro_0
gPokenavCityMap_Rustboro_0: @ 0x085F45C4
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Rustboro_0.bin"
	.balign 4

	.globl gPokenavCityMap_Rustboro_1
gPokenavCityMap_Rustboro_1: @ 0x085F4618
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Rustboro_1.bin"
	.balign 4

	.globl gPokenavCityMap_Pacifidlog_0
gPokenavCityMap_Pacifidlog_0: @ 0x085F466C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Pacifidlog_0.bin"
	.balign 4

	.globl gPokenavCityMap_Mauville_1
gPokenavCityMap_Mauville_1: @ 0x085F46AC
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Mauville_1.bin"
	.balign 4

	.globl gPokenavCityMap_Mauville_0
gPokenavCityMap_Mauville_0: @ 0x085F4704
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Mauville_0.bin"
	.balign 4

	.globl gPokenavCityMap_Oldale_0
gPokenavCityMap_Oldale_0: @ 0x085F4758
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Oldale_0.bin"
	.balign 4

	.globl gPokenavCityMap_Lilycove_1
gPokenavCityMap_Lilycove_1: @ 0x085F4788
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Lilycove_1.bin"
	.balign 4

	.globl gPokenavCityMap_Lilycove_0
gPokenavCityMap_Lilycove_0: @ 0x085F47D4
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Lilycove_0.bin"
	.balign 4

	.globl gPokenavCityMap_Littleroot_0
gPokenavCityMap_Littleroot_0: @ 0x085F482C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Littleroot_0.bin"
	.balign 4

	.globl gPokenavCityMap_Dewford_0
gPokenavCityMap_Dewford_0: @ 0x085F485C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Dewford_0.bin"
	.balign 4

	.globl gPokenavCityMap_Sootopolis_0
gPokenavCityMap_Sootopolis_0: @ 0x085F4894
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Sootopolis_0.bin"
	.balign 4

	.globl gPokenavCityMap_EverGrande_0
gPokenavCityMap_EverGrande_0: @ 0x085F48D4
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_EverGrande_0.bin"
	.balign 4

	.globl gPokenavCityMap_EverGrande_1
gPokenavCityMap_EverGrande_1: @ 0x085F491C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_EverGrande_1.bin"
	.balign 4

	.globl gPokenavCityMap_Verdanturf_0
gPokenavCityMap_Verdanturf_0: @ 0x085F4960
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Verdanturf_0.bin"
	.balign 4

	.globl gPokenavCityMap_Mossdeep_1
gPokenavCityMap_Mossdeep_1: @ 0x085F4998
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Mossdeep_1.bin"
	.balign 4

	.globl gPokenavCityMap_Mossdeep_0
gPokenavCityMap_Mossdeep_0: @ 0x085F49E0
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Mossdeep_0.bin"
	.balign 4

	.globl gPokenavCityMap_Petalburg_0
gPokenavCityMap_Petalburg_0: @ 0x085F4A3C
	.incbin "graphics/pokenav/region_map/gPokenavCityMap_Petalburg_0.bin"
	.balign 4

	.globl gRegionMapCityZoomText_Gfx
gRegionMapCityZoomText_Gfx: @ 0x5F4A98
	.incbin "graphics/misc/gRegionMapCityZoomText_Gfx.bin"

