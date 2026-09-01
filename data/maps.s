.include "sound/MPlayDef.s"
	.section .rodata.after_tilesets, "a", %progbits
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/map_header.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.include "data/layouts/layouts.inc"
	.include "data/layouts/layouts_table.inc"
	.globl gMapHeaders
gMapHeaders: @ 0x0845A8D8
	@ Map headers and map groups are generated from data/maps/map_groups.json.
	.include "data/maps/headers.inc"
	.include "data/maps/groups.inc"
	.include "data/maps/connections.inc"
