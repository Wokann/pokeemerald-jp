	.section .rodata.battle_transition_legendary_resources, "a", %progbits

	.globl sKyogre_Tileset
sKyogre_Tileset:
	.incbin "graphics/battle_transitions/kyogre.4bpp.lz"

	.globl sKyogre_Tilemap
sKyogre_Tilemap:
	.incbin "graphics/battle_transitions/kyogre.bin.lz"

	.globl sGroudon_Tileset
sGroudon_Tileset:
	.incbin "graphics/battle_transitions/groudon.4bpp.lz"

	.globl sGroudon_Tilemap
sGroudon_Tilemap:
	.incbin "graphics/battle_transitions/groudon.bin.lz"

	.globl sKyogre1_Palette
sKyogre1_Palette:
	.incbin "graphics/battle_transitions/kyogre_pt1.gbapal"

	.globl sKyogre2_Palette
sKyogre2_Palette:
	.incbin "graphics/battle_transitions/kyogre_pt2.gbapal"

	.globl sGroudon1_Palette
sGroudon1_Palette:
	.incbin "graphics/battle_transitions/groudon_pt1.gbapal"

	.globl sGroudon2_Palette
sGroudon2_Palette:
	.incbin "graphics/battle_transitions/groudon_pt2.gbapal"

	.globl sRayquaza_Palette
sRayquaza_Palette:
	.incbin "graphics/battle_transitions/rayquaza.gbapal"

	.globl sRayquaza_Tileset
sRayquaza_Tileset:
	.incbin "graphics/battle_transitions/rayquaza.4bpp"

	.globl sRayquaza_Tilemap
sRayquaza_Tilemap:
	.incbin "graphics/battle_transitions/rayquaza.bin"
