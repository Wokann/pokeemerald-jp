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
	.globl gMonStillFrontPic_Bulbasaur
gMonStillFrontPic_Bulbasaur: @ 0x8C2FAAC
	.incbin "graphics/pokemon/bulbasaur/front.4bpp.lz"

	.globl gMonPalette_Bulbasaur
gMonPalette_Bulbasaur: @ 0x8C2FD44
	.incbin "graphics/pokemon/bulbasaur/normal.gbapal.lz"

	.globl gMonBackPic_Bulbasaur
gMonBackPic_Bulbasaur: @ 0x8C2FD6C
	.incbin "graphics/pokemon/bulbasaur/back.4bpp.lz"

	.globl gMonShinyPalette_Bulbasaur
gMonShinyPalette_Bulbasaur: @ 0x8C3001C
	.incbin "graphics/pokemon/bulbasaur/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc30044, 0x420

	.globl gMonStillFrontPic_Ivysaur
gMonStillFrontPic_Ivysaur: @ 0x8C30464
	.incbin "graphics/pokemon/ivysaur/front.4bpp.lz"

	.globl gMonPalette_Ivysaur
gMonPalette_Ivysaur: @ 0x8C307D8
	.incbin "graphics/pokemon/ivysaur/normal.gbapal.lz"

	.globl gMonBackPic_Ivysaur
gMonBackPic_Ivysaur: @ 0x8C30800
	.incbin "graphics/pokemon/ivysaur/back.4bpp.lz"

	.globl gMonShinyPalette_Ivysaur
gMonShinyPalette_Ivysaur: @ 0x8C30B8C
	.incbin "graphics/pokemon/ivysaur/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc30bb4, 0x420

	.globl gMonStillFrontPic_Venusaur
gMonStillFrontPic_Venusaur: @ 0x8C30FD4
	.incbin "graphics/pokemon/venusaur/front.4bpp.lz"

	.globl gMonPalette_Venusaur
gMonPalette_Venusaur: @ 0x8C31560
	.incbin "graphics/pokemon/venusaur/normal.gbapal.lz"

	.globl gMonBackPic_Venusaur
gMonBackPic_Venusaur: @ 0x8C31588
	.incbin "graphics/pokemon/venusaur/back.4bpp.lz"

	.globl gMonShinyPalette_Venusaur
gMonShinyPalette_Venusaur: @ 0x8C31A58
	.incbin "graphics/pokemon/venusaur/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc31a80, 0x420

	.globl gMonStillFrontPic_Charmander
gMonStillFrontPic_Charmander: @ 0x8C31EA0
	.incbin "graphics/pokemon/charmander/front.4bpp.lz"

	.globl gMonPalette_Charmander
gMonPalette_Charmander: @ 0x8C32150
	.incbin "graphics/pokemon/charmander/normal.gbapal.lz"

	.globl gMonBackPic_Charmander
gMonBackPic_Charmander: @ 0x8C32178
	.incbin "graphics/pokemon/charmander/back.4bpp.lz"

	.globl gMonShinyPalette_Charmander
gMonShinyPalette_Charmander: @ 0x8C3240C
	.incbin "graphics/pokemon/charmander/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc32434, 0x420

	.globl gMonStillFrontPic_Charmeleon
gMonStillFrontPic_Charmeleon: @ 0x8C32854
	.incbin "graphics/pokemon/charmeleon/front.4bpp.lz"

	.globl gMonPalette_Charmeleon
gMonPalette_Charmeleon: @ 0x8C32BFC
	.incbin "graphics/pokemon/charmeleon/normal.gbapal.lz"

	.globl gMonBackPic_Charmeleon
gMonBackPic_Charmeleon: @ 0x8C32C24
	.incbin "graphics/pokemon/charmeleon/back.4bpp.lz"

	.globl gMonShinyPalette_Charmeleon
gMonShinyPalette_Charmeleon: @ 0x8C32F04
	.incbin "graphics/pokemon/charmeleon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc32f2c, 0x420

	.globl gMonStillFrontPic_Charizard
gMonStillFrontPic_Charizard: @ 0x8C3334C
	.incbin "graphics/pokemon/charizard/front.4bpp.lz"

	.globl gMonPalette_Charizard
gMonPalette_Charizard: @ 0x8C3389C
	.incbin "graphics/pokemon/charizard/normal.gbapal.lz"

	.globl gMonBackPic_Charizard
gMonBackPic_Charizard: @ 0x8C338C4
	.incbin "graphics/pokemon/charizard/back.4bpp.lz"

	.globl gMonShinyPalette_Charizard
gMonShinyPalette_Charizard: @ 0x8C33CE0
	.incbin "graphics/pokemon/charizard/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc33d08, 0x420

	.globl gMonStillFrontPic_Squirtle
gMonStillFrontPic_Squirtle: @ 0x8C34128
	.incbin "graphics/pokemon/squirtle/front.4bpp.lz"

	.globl gMonPalette_Squirtle
gMonPalette_Squirtle: @ 0x8C34404
	.incbin "graphics/pokemon/squirtle/normal.gbapal.lz"

	.globl gMonBackPic_Squirtle
gMonBackPic_Squirtle: @ 0x8C3442C
	.incbin "graphics/pokemon/squirtle/back.4bpp.lz"

	.globl gMonShinyPalette_Squirtle
gMonShinyPalette_Squirtle: @ 0x8C346AC
	.incbin "graphics/pokemon/squirtle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc346d4, 0x420

	.globl gMonStillFrontPic_Wartortle
gMonStillFrontPic_Wartortle: @ 0x8C34AF4
	.incbin "graphics/pokemon/wartortle/front.4bpp.lz"

	.globl gMonPalette_Wartortle
gMonPalette_Wartortle: @ 0x8C34E70
	.incbin "graphics/pokemon/wartortle/normal.gbapal.lz"

	.globl gMonBackPic_Wartortle
gMonBackPic_Wartortle: @ 0x8C34E98
	.incbin "graphics/pokemon/wartortle/back.4bpp.lz"

	.globl gMonShinyPalette_Wartortle
gMonShinyPalette_Wartortle: @ 0x8C351CC
	.incbin "graphics/pokemon/wartortle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc351f4, 0x420

	.globl gMonStillFrontPic_Blastoise
gMonStillFrontPic_Blastoise: @ 0x8C35614
	.incbin "graphics/pokemon/blastoise/front.4bpp.lz"

	.globl gMonPalette_Blastoise
gMonPalette_Blastoise: @ 0x8C35B18
	.incbin "graphics/pokemon/blastoise/normal.gbapal.lz"

	.globl gMonBackPic_Blastoise
gMonBackPic_Blastoise: @ 0x8C35B40
	.incbin "graphics/pokemon/blastoise/back.4bpp.lz"

	.globl gMonShinyPalette_Blastoise
gMonShinyPalette_Blastoise: @ 0x8C35F5C
	.incbin "graphics/pokemon/blastoise/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc35f84, 0x420

	.globl gMonStillFrontPic_Caterpie
gMonStillFrontPic_Caterpie: @ 0x8C363A4
	.incbin "graphics/pokemon/caterpie/front.4bpp.lz"

	.globl gMonPalette_Caterpie
gMonPalette_Caterpie: @ 0x8C36604
	.incbin "graphics/pokemon/caterpie/normal.gbapal.lz"

	.globl gMonBackPic_Caterpie
gMonBackPic_Caterpie: @ 0x8C3662C
	.incbin "graphics/pokemon/caterpie/back.4bpp.lz"

	.globl gMonShinyPalette_Caterpie
gMonShinyPalette_Caterpie: @ 0x8C368B4
	.incbin "graphics/pokemon/caterpie/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc368dc, 0x420

	.globl gMonStillFrontPic_Metapod
gMonStillFrontPic_Metapod: @ 0x8C36CFC
	.incbin "graphics/pokemon/metapod/front.4bpp.lz"

	.globl gMonPalette_Metapod
gMonPalette_Metapod: @ 0x8C36F14
	.incbin "graphics/pokemon/metapod/normal.gbapal.lz"

	.globl gMonBackPic_Metapod
gMonBackPic_Metapod: @ 0x8C36F34
	.incbin "graphics/pokemon/metapod/back.4bpp.lz"

	.globl gMonShinyPalette_Metapod
gMonShinyPalette_Metapod: @ 0x8C37174
	.incbin "graphics/pokemon/metapod/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc37193, 0x421

	.globl gMonStillFrontPic_Butterfree
gMonStillFrontPic_Butterfree: @ 0x8C375B4
	.incbin "graphics/pokemon/butterfree/front.4bpp.lz"

	.globl gMonPalette_Butterfree
gMonPalette_Butterfree: @ 0x8C37914
	.incbin "graphics/pokemon/butterfree/normal.gbapal.lz"

	.globl gMonBackPic_Butterfree
gMonBackPic_Butterfree: @ 0x8C3793C
	.incbin "graphics/pokemon/butterfree/back.4bpp.lz"

	.globl gMonShinyPalette_Butterfree
gMonShinyPalette_Butterfree: @ 0x8C37D4C
	.incbin "graphics/pokemon/butterfree/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc37d74, 0x420

	.globl gMonStillFrontPic_Weedle
gMonStillFrontPic_Weedle: @ 0x8C38194
	.incbin "graphics/pokemon/weedle/front.4bpp.lz"

	.globl gMonPalette_Weedle
gMonPalette_Weedle: @ 0x8C383D4
	.incbin "graphics/pokemon/weedle/normal.gbapal.lz"

	.globl gMonBackPic_Weedle
gMonBackPic_Weedle: @ 0x8C383FC
	.incbin "graphics/pokemon/weedle/back.4bpp.lz"

	.globl gMonShinyPalette_Weedle
gMonShinyPalette_Weedle: @ 0x8C38664
	.incbin "graphics/pokemon/weedle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3868c, 0x420

	.globl gMonStillFrontPic_Kakuna
gMonStillFrontPic_Kakuna: @ 0x8C38AAC
	.incbin "graphics/pokemon/kakuna/front.4bpp.lz"

	.globl gMonPalette_Kakuna
gMonPalette_Kakuna: @ 0x8C38CF8
	.incbin "graphics/pokemon/kakuna/normal.gbapal.lz"

	.globl gMonBackPic_Kakuna
gMonBackPic_Kakuna: @ 0x8C38D1C
	.incbin "graphics/pokemon/kakuna/back.4bpp.lz"

	.globl gMonShinyPalette_Kakuna
gMonShinyPalette_Kakuna: @ 0x8C38FA0
	.incbin "graphics/pokemon/kakuna/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc38fc1, 0x423

	.globl gMonStillFrontPic_Beedrill
gMonStillFrontPic_Beedrill: @ 0x8C393E4
	.incbin "graphics/pokemon/beedrill/front.4bpp.lz"

	.globl gMonPalette_Beedrill
gMonPalette_Beedrill: @ 0x8C397F4
	.incbin "graphics/pokemon/beedrill/normal.gbapal.lz"

	.globl gMonBackPic_Beedrill
gMonBackPic_Beedrill: @ 0x8C3981C
	.incbin "graphics/pokemon/beedrill/back.4bpp.lz"

	.globl gMonShinyPalette_Beedrill
gMonShinyPalette_Beedrill: @ 0x8C39B90
	.incbin "graphics/pokemon/beedrill/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc39bb8, 0x420

	.globl gMonStillFrontPic_Pidgey
gMonStillFrontPic_Pidgey: @ 0x8C39FD8
	.incbin "graphics/pokemon/pidgey/front.4bpp.lz"

	.globl gMonPalette_Pidgey
gMonPalette_Pidgey: @ 0x8C3A2C4
	.incbin "graphics/pokemon/pidgey/normal.gbapal.lz"

	.globl gMonBackPic_Pidgey
gMonBackPic_Pidgey: @ 0x8C3A2EC
	.incbin "graphics/pokemon/pidgey/back.4bpp.lz"

	.globl gMonShinyPalette_Pidgey
gMonShinyPalette_Pidgey: @ 0x8C3A640
	.incbin "graphics/pokemon/pidgey/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3a668, 0x420

	.globl gMonStillFrontPic_Pidgeotto
gMonStillFrontPic_Pidgeotto: @ 0x8C3AA88
	.incbin "graphics/pokemon/pidgeotto/front.4bpp.lz"

	.globl gMonPalette_Pidgeotto
gMonPalette_Pidgeotto: @ 0x8C3ADFC
	.incbin "graphics/pokemon/pidgeotto/normal.gbapal.lz"

	.globl gMonBackPic_Pidgeotto
gMonBackPic_Pidgeotto: @ 0x8C3AE24
	.incbin "graphics/pokemon/pidgeotto/back.4bpp.lz"

	.globl gMonShinyPalette_Pidgeotto
gMonShinyPalette_Pidgeotto: @ 0x8C3B170
	.incbin "graphics/pokemon/pidgeotto/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3b198, 0x420

	.globl gMonStillFrontPic_Pidgeot
gMonStillFrontPic_Pidgeot: @ 0x8C3B5B8
	.incbin "graphics/pokemon/pidgeot/front.4bpp.lz"

	.globl gMonPalette_Pidgeot
gMonPalette_Pidgeot: @ 0x8C3BAB4
	.incbin "graphics/pokemon/pidgeot/normal.gbapal.lz"

	.globl gMonBackPic_Pidgeot
gMonBackPic_Pidgeot: @ 0x8C3BADC
	.incbin "graphics/pokemon/pidgeot/back.4bpp.lz"

	.globl gMonShinyPalette_Pidgeot
gMonShinyPalette_Pidgeot: @ 0x8C3BE64
	.incbin "graphics/pokemon/pidgeot/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3be8c, 0x420

	.globl gMonStillFrontPic_Rattata
gMonStillFrontPic_Rattata: @ 0x8C3C2AC
	.incbin "graphics/pokemon/rattata/front.4bpp.lz"

	.globl gMonPalette_Rattata
gMonPalette_Rattata: @ 0x8C3C4F8
	.incbin "graphics/pokemon/rattata/normal.gbapal.lz"

	.globl gMonBackPic_Rattata
gMonBackPic_Rattata: @ 0x8C3C520
	.incbin "graphics/pokemon/rattata/back.4bpp.lz"

	.globl gMonShinyPalette_Rattata
gMonShinyPalette_Rattata: @ 0x8C3C7FC
	.incbin "graphics/pokemon/rattata/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3c824, 0x420

	.globl gMonStillFrontPic_Raticate
gMonStillFrontPic_Raticate: @ 0x8C3CC44
	.incbin "graphics/pokemon/raticate/front.4bpp.lz"

	.globl gMonPalette_Raticate
gMonPalette_Raticate: @ 0x8C3CFCC
	.incbin "graphics/pokemon/raticate/normal.gbapal.lz"

	.globl gMonBackPic_Raticate
gMonBackPic_Raticate: @ 0x8C3CFF4
	.incbin "graphics/pokemon/raticate/back.4bpp.lz"

	.globl gMonShinyPalette_Raticate
gMonShinyPalette_Raticate: @ 0x8C3D324
	.incbin "graphics/pokemon/raticate/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3d34c, 0x420

	.globl gMonStillFrontPic_Spearow
gMonStillFrontPic_Spearow: @ 0x8C3D76C
	.incbin "graphics/pokemon/spearow/front.4bpp.lz"

	.globl gMonPalette_Spearow
gMonPalette_Spearow: @ 0x8C3D9F4
	.incbin "graphics/pokemon/spearow/normal.gbapal.lz"

	.globl gMonBackPic_Spearow
gMonBackPic_Spearow: @ 0x8C3DA1C
	.incbin "graphics/pokemon/spearow/back.4bpp.lz"

	.globl gMonShinyPalette_Spearow
gMonShinyPalette_Spearow: @ 0x8C3DCF8
	.incbin "graphics/pokemon/spearow/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3dd20, 0x420

	.globl gMonStillFrontPic_Fearow
gMonStillFrontPic_Fearow: @ 0x8C3E140
	.incbin "graphics/pokemon/fearow/front.4bpp.lz"

	.globl gMonPalette_Fearow
gMonPalette_Fearow: @ 0x8C3E5D4
	.incbin "graphics/pokemon/fearow/normal.gbapal.lz"

	.globl gMonBackPic_Fearow
gMonBackPic_Fearow: @ 0x8C3E5FC
	.incbin "graphics/pokemon/fearow/back.4bpp.lz"

	.globl gMonShinyPalette_Fearow
gMonShinyPalette_Fearow: @ 0x8C3E8F4
	.incbin "graphics/pokemon/fearow/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3e91c, 0x420

	.globl gMonStillFrontPic_Ekans
gMonStillFrontPic_Ekans: @ 0x8C3ED3C
	.incbin "graphics/pokemon/ekans/front.4bpp.lz"

	.globl gMonPalette_Ekans
gMonPalette_Ekans: @ 0x8C3F03C
	.incbin "graphics/pokemon/ekans/normal.gbapal.lz"

	.globl gMonBackPic_Ekans
gMonBackPic_Ekans: @ 0x8C3F064
	.incbin "graphics/pokemon/ekans/back.4bpp.lz"

	.globl gMonShinyPalette_Ekans
gMonShinyPalette_Ekans: @ 0x8C3F354
	.incbin "graphics/pokemon/ekans/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3f37c, 0x420

	.globl gMonStillFrontPic_Arbok
gMonStillFrontPic_Arbok: @ 0x8C3F79C
	.incbin "graphics/pokemon/arbok/front.4bpp.lz"

	.globl gMonPalette_Arbok
gMonPalette_Arbok: @ 0x8C3FBE8
	.incbin "graphics/pokemon/arbok/normal.gbapal.lz"

	.globl gMonBackPic_Arbok
gMonBackPic_Arbok: @ 0x8C3FC10
	.incbin "graphics/pokemon/arbok/back.4bpp.lz"

	.globl gMonShinyPalette_Arbok
gMonShinyPalette_Arbok: @ 0x8C3FEB0
	.incbin "graphics/pokemon/arbok/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc3fed8, 0x420

	.globl gMonStillFrontPic_Pikachu
gMonStillFrontPic_Pikachu: @ 0x8C402F8
	.incbin "graphics/pokemon/pikachu/front.4bpp.lz"

	.globl gMonPalette_Pikachu
gMonPalette_Pikachu: @ 0x8C405C8
	.incbin "graphics/pokemon/pikachu/normal.gbapal.lz"

	.globl gMonBackPic_Pikachu
gMonBackPic_Pikachu: @ 0x8C405F0
	.incbin "graphics/pokemon/pikachu/back.4bpp.lz"

	.globl gMonShinyPalette_Pikachu
gMonShinyPalette_Pikachu: @ 0x8C408C8
	.incbin "graphics/pokemon/pikachu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc408ee, 0x422

	.globl gMonStillFrontPic_Raichu
gMonStillFrontPic_Raichu: @ 0x8C40D10
	.incbin "graphics/pokemon/raichu/front.4bpp.lz"

	.globl gMonPalette_Raichu
gMonPalette_Raichu: @ 0x8C410BC
	.incbin "graphics/pokemon/raichu/normal.gbapal.lz"

	.globl gMonBackPic_Raichu
gMonBackPic_Raichu: @ 0x8C410E4
	.incbin "graphics/pokemon/raichu/back.4bpp.lz"

	.globl gMonShinyPalette_Raichu
gMonShinyPalette_Raichu: @ 0x8C41404
	.incbin "graphics/pokemon/raichu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4142c, 0x420

	.globl gMonStillFrontPic_Sandshrew
gMonStillFrontPic_Sandshrew: @ 0x8C4184C
	.incbin "graphics/pokemon/sandshrew/front.4bpp.lz"

	.globl gMonPalette_Sandshrew
gMonPalette_Sandshrew: @ 0x8C41B0C
	.incbin "graphics/pokemon/sandshrew/normal.gbapal.lz"

	.globl gMonBackPic_Sandshrew
gMonBackPic_Sandshrew: @ 0x8C41B34
	.incbin "graphics/pokemon/sandshrew/back.4bpp.lz"

	.globl gMonShinyPalette_Sandshrew
gMonShinyPalette_Sandshrew: @ 0x8C41E5C
	.incbin "graphics/pokemon/sandshrew/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc41e82, 0x422

	.globl gMonStillFrontPic_Sandslash
gMonStillFrontPic_Sandslash: @ 0x8C422A4
	.incbin "graphics/pokemon/sandslash/front.4bpp.lz"

	.globl gMonPalette_Sandslash
gMonPalette_Sandslash: @ 0x8C42690
	.incbin "graphics/pokemon/sandslash/normal.gbapal.lz"

	.globl gMonBackPic_Sandslash
gMonBackPic_Sandslash: @ 0x8C426B8
	.incbin "graphics/pokemon/sandslash/back.4bpp.lz"

	.globl gMonShinyPalette_Sandslash
gMonShinyPalette_Sandslash: @ 0x8C42AD4
	.incbin "graphics/pokemon/sandslash/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc42afc, 0x420

	.globl gMonStillFrontPic_NidoranF
gMonStillFrontPic_NidoranF: @ 0x8C42F1C
	.incbin "graphics/pokemon/nidoran_f/front.4bpp.lz"

	.globl gMonPalette_NidoranF
gMonPalette_NidoranF: @ 0x8C43194
	.incbin "graphics/pokemon/nidoran_f/normal.gbapal.lz"

	.globl gMonBackPic_NidoranF
gMonBackPic_NidoranF: @ 0x8C431BC
	.incbin "graphics/pokemon/nidoran_f/back.4bpp.lz"

	.globl gMonShinyPalette_NidoranF
gMonShinyPalette_NidoranF: @ 0x8C43494
	.incbin "graphics/pokemon/nidoran_f/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc434ba, 0x422

	.globl gMonStillFrontPic_Nidorina
gMonStillFrontPic_Nidorina: @ 0x8C438DC
	.incbin "graphics/pokemon/nidorina/front.4bpp.lz"

	.globl gMonPalette_Nidorina
gMonPalette_Nidorina: @ 0x8C43C08
	.incbin "graphics/pokemon/nidorina/normal.gbapal.lz"

	.globl gMonBackPic_Nidorina
gMonBackPic_Nidorina: @ 0x8C43C30
	.incbin "graphics/pokemon/nidorina/back.4bpp.lz"

	.globl gMonShinyPalette_Nidorina
gMonShinyPalette_Nidorina: @ 0x8C43FC4
	.incbin "graphics/pokemon/nidorina/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc43fec, 0x420

	.globl gMonStillFrontPic_Nidoqueen
gMonStillFrontPic_Nidoqueen: @ 0x8C4440C
	.incbin "graphics/pokemon/nidoqueen/front.4bpp.lz"

	.globl gMonPalette_Nidoqueen
gMonPalette_Nidoqueen: @ 0x8C44898
	.incbin "graphics/pokemon/nidoqueen/normal.gbapal.lz"

	.globl gMonBackPic_Nidoqueen
gMonBackPic_Nidoqueen: @ 0x8C448C0
	.incbin "graphics/pokemon/nidoqueen/back.4bpp.lz"

	.globl gMonShinyPalette_Nidoqueen
gMonShinyPalette_Nidoqueen: @ 0x8C44C84
	.incbin "graphics/pokemon/nidoqueen/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc44cac, 0x420

	.globl gMonStillFrontPic_NidoranM
gMonStillFrontPic_NidoranM: @ 0x8C450CC
	.incbin "graphics/pokemon/nidoran_m/front.4bpp.lz"

	.globl gMonPalette_NidoranM
gMonPalette_NidoranM: @ 0x8C4539C
	.incbin "graphics/pokemon/nidoran_m/normal.gbapal.lz"

	.globl gMonBackPic_NidoranM
gMonBackPic_NidoranM: @ 0x8C453C4
	.incbin "graphics/pokemon/nidoran_m/back.4bpp.lz"

	.globl gMonShinyPalette_NidoranM
gMonShinyPalette_NidoranM: @ 0x8C456F8
	.incbin "graphics/pokemon/nidoran_m/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc45720, 0x420

	.globl gMonStillFrontPic_Nidorino
gMonStillFrontPic_Nidorino: @ 0x8C45B40
	.incbin "graphics/pokemon/nidorino/front.4bpp.lz"

	.globl gMonPalette_Nidorino
gMonPalette_Nidorino: @ 0x8C45ED4
	.incbin "graphics/pokemon/nidorino/normal.gbapal.lz"

	.globl gMonBackPic_Nidorino
gMonBackPic_Nidorino: @ 0x8C45EFC
	.incbin "graphics/pokemon/nidorino/back.4bpp.lz"

	.globl gMonShinyPalette_Nidorino
gMonShinyPalette_Nidorino: @ 0x8C462B8
	.incbin "graphics/pokemon/nidorino/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc462e0, 0x420

	.globl gMonStillFrontPic_Nidoking
gMonStillFrontPic_Nidoking: @ 0x8C46700
	.incbin "graphics/pokemon/nidoking/front.4bpp.lz"

	.globl gMonPalette_Nidoking
gMonPalette_Nidoking: @ 0x8C46BF8
	.incbin "graphics/pokemon/nidoking/normal.gbapal.lz"

	.globl gMonBackPic_Nidoking
gMonBackPic_Nidoking: @ 0x8C46C20
	.incbin "graphics/pokemon/nidoking/back.4bpp.lz"

	.globl gMonShinyPalette_Nidoking
gMonShinyPalette_Nidoking: @ 0x8C4705C
	.incbin "graphics/pokemon/nidoking/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc47082, 0x422

	.globl gMonStillFrontPic_Clefairy
gMonStillFrontPic_Clefairy: @ 0x8C474A4
	.incbin "graphics/pokemon/clefairy/front.4bpp.lz"

	.globl gMonPalette_Clefairy
gMonPalette_Clefairy: @ 0x8C4772C
	.incbin "graphics/pokemon/clefairy/normal.gbapal.lz"

	.globl gMonBackPic_Clefairy
gMonBackPic_Clefairy: @ 0x8C47754
	.incbin "graphics/pokemon/clefairy/back.4bpp.lz"

	.globl gMonShinyPalette_Clefairy
gMonShinyPalette_Clefairy: @ 0x8C47A24
	.incbin "graphics/pokemon/clefairy/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc47a4c, 0x420

	.globl gMonStillFrontPic_Clefable
gMonStillFrontPic_Clefable: @ 0x8C47E6C
	.incbin "graphics/pokemon/clefable/front.4bpp.lz"

	.globl gMonPalette_Clefable
gMonPalette_Clefable: @ 0x8C481A8
	.incbin "graphics/pokemon/clefable/normal.gbapal.lz"

	.globl gMonBackPic_Clefable
gMonBackPic_Clefable: @ 0x8C481D0
	.incbin "graphics/pokemon/clefable/back.4bpp.lz"

	.globl gMonShinyPalette_Clefable
gMonShinyPalette_Clefable: @ 0x8C48508
	.incbin "graphics/pokemon/clefable/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc48530, 0x420

	.globl gMonStillFrontPic_Vulpix
gMonStillFrontPic_Vulpix: @ 0x8C48950
	.incbin "graphics/pokemon/vulpix/front.4bpp.lz"

	.globl gMonPalette_Vulpix
gMonPalette_Vulpix: @ 0x8C48C8C
	.incbin "graphics/pokemon/vulpix/normal.gbapal.lz"

	.globl gMonBackPic_Vulpix
gMonBackPic_Vulpix: @ 0x8C48CB4
	.incbin "graphics/pokemon/vulpix/back.4bpp.lz"

	.globl gMonShinyPalette_Vulpix
gMonShinyPalette_Vulpix: @ 0x8C48FB0
	.incbin "graphics/pokemon/vulpix/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc48fd8, 0x420

	.globl gMonStillFrontPic_Ninetales
gMonStillFrontPic_Ninetales: @ 0x8C493F8
	.incbin "graphics/pokemon/ninetales/front.4bpp.lz"

	.globl gMonPalette_Ninetales
gMonPalette_Ninetales: @ 0x8C49834
	.incbin "graphics/pokemon/ninetales/normal.gbapal.lz"

	.globl gMonBackPic_Ninetales
gMonBackPic_Ninetales: @ 0x8C49854
	.incbin "graphics/pokemon/ninetales/back.4bpp.lz"

	.globl gMonShinyPalette_Ninetales
gMonShinyPalette_Ninetales: @ 0x8C49BD4
	.incbin "graphics/pokemon/ninetales/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc49bf3, 0x421

	.globl gMonStillFrontPic_Jigglypuff
gMonStillFrontPic_Jigglypuff: @ 0x8C4A014
	.incbin "graphics/pokemon/jigglypuff/front.4bpp.lz"

	.globl gMonPalette_Jigglypuff
gMonPalette_Jigglypuff: @ 0x8C4A28C
	.incbin "graphics/pokemon/jigglypuff/normal.gbapal.lz"

	.globl gMonBackPic_Jigglypuff
gMonBackPic_Jigglypuff: @ 0x8C4A2B4
	.incbin "graphics/pokemon/jigglypuff/back.4bpp.lz"

	.globl gMonShinyPalette_Jigglypuff
gMonShinyPalette_Jigglypuff: @ 0x8C4A510
	.incbin "graphics/pokemon/jigglypuff/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4a538, 0x420

	.globl gMonStillFrontPic_Wigglytuff
gMonStillFrontPic_Wigglytuff: @ 0x8C4A958
	.incbin "graphics/pokemon/wigglytuff/front.4bpp.lz"

	.globl gMonPalette_Wigglytuff
gMonPalette_Wigglytuff: @ 0x8C4ACAC
	.incbin "graphics/pokemon/wigglytuff/normal.gbapal.lz"

	.globl gMonBackPic_Wigglytuff
gMonBackPic_Wigglytuff: @ 0x8C4ACD4
	.incbin "graphics/pokemon/wigglytuff/back.4bpp.lz"

	.globl gMonShinyPalette_Wigglytuff
gMonShinyPalette_Wigglytuff: @ 0x8C4AF7C
	.incbin "graphics/pokemon/wigglytuff/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4afa4, 0x420

	.globl gMonStillFrontPic_Zubat
gMonStillFrontPic_Zubat: @ 0x8C4B3C4
	.incbin "graphics/pokemon/zubat/front.4bpp.lz"

	.globl gMonPalette_Zubat
gMonPalette_Zubat: @ 0x8C4B69C
	.incbin "graphics/pokemon/zubat/normal.gbapal.lz"

	.globl gMonBackPic_Zubat
gMonBackPic_Zubat: @ 0x8C4B6C4
	.incbin "graphics/pokemon/zubat/back.4bpp.lz"

	.globl gMonShinyPalette_Zubat
gMonShinyPalette_Zubat: @ 0x8C4B980
	.incbin "graphics/pokemon/zubat/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4b9a8, 0x420

	.globl gMonStillFrontPic_Golbat
gMonStillFrontPic_Golbat: @ 0x8C4BDC8
	.incbin "graphics/pokemon/golbat/front.4bpp.lz"

	.globl gMonPalette_Golbat
gMonPalette_Golbat: @ 0x8C4C164
	.incbin "graphics/pokemon/golbat/normal.gbapal.lz"

	.globl gMonBackPic_Golbat
gMonBackPic_Golbat: @ 0x8C4C18C
	.incbin "graphics/pokemon/golbat/back.4bpp.lz"

	.globl gMonShinyPalette_Golbat
gMonShinyPalette_Golbat: @ 0x8C4C448
	.incbin "graphics/pokemon/golbat/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4c46e, 0x422

	.globl gMonStillFrontPic_Oddish
gMonStillFrontPic_Oddish: @ 0x8C4C890
	.incbin "graphics/pokemon/oddish/front.4bpp.lz"

	.globl gMonPalette_Oddish
gMonPalette_Oddish: @ 0x8C4CAC4
	.incbin "graphics/pokemon/oddish/normal.gbapal.lz"

	.globl gMonBackPic_Oddish
gMonBackPic_Oddish: @ 0x8C4CAEC
	.incbin "graphics/pokemon/oddish/back.4bpp.lz"

	.globl gMonShinyPalette_Oddish
gMonShinyPalette_Oddish: @ 0x8C4CD64
	.incbin "graphics/pokemon/oddish/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4cd8a, 0x422

	.globl gMonStillFrontPic_Gloom
gMonStillFrontPic_Gloom: @ 0x8C4D1AC
	.incbin "graphics/pokemon/gloom/front.4bpp.lz"

	.globl gMonPalette_Gloom
gMonPalette_Gloom: @ 0x8C4D524
	.incbin "graphics/pokemon/gloom/normal.gbapal.lz"

	.globl gMonBackPic_Gloom
gMonBackPic_Gloom: @ 0x8C4D54C
	.incbin "graphics/pokemon/gloom/back.4bpp.lz"

	.globl gMonShinyPalette_Gloom
gMonShinyPalette_Gloom: @ 0x8C4D8B4
	.incbin "graphics/pokemon/gloom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4d8dc, 0x420

	.globl gMonStillFrontPic_Vileplume
gMonStillFrontPic_Vileplume: @ 0x8C4DCFC
	.incbin "graphics/pokemon/vileplume/front.4bpp.lz"

	.globl gMonPalette_Vileplume
gMonPalette_Vileplume: @ 0x8C4E078
	.incbin "graphics/pokemon/vileplume/normal.gbapal.lz"

	.globl gMonBackPic_Vileplume
gMonBackPic_Vileplume: @ 0x8C4E0A0
	.incbin "graphics/pokemon/vileplume/back.4bpp.lz"

	.globl gMonShinyPalette_Vileplume
gMonShinyPalette_Vileplume: @ 0x8C4E4B8
	.incbin "graphics/pokemon/vileplume/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4e4e0, 0x420

	.globl gMonStillFrontPic_Paras
gMonStillFrontPic_Paras: @ 0x8C4E900
	.incbin "graphics/pokemon/paras/front.4bpp.lz"

	.globl gMonPalette_Paras
gMonPalette_Paras: @ 0x8C4EB6C
	.incbin "graphics/pokemon/paras/normal.gbapal.lz"

	.globl gMonBackPic_Paras
gMonBackPic_Paras: @ 0x8C4EB94
	.incbin "graphics/pokemon/paras/back.4bpp.lz"

	.globl gMonShinyPalette_Paras
gMonShinyPalette_Paras: @ 0x8C4EE34
	.incbin "graphics/pokemon/paras/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4ee5c, 0x420

	.globl gMonStillFrontPic_Parasect
gMonStillFrontPic_Parasect: @ 0x8C4F27C
	.incbin "graphics/pokemon/parasect/front.4bpp.lz"

	.globl gMonPalette_Parasect
gMonPalette_Parasect: @ 0x8C4F640
	.incbin "graphics/pokemon/parasect/normal.gbapal.lz"

	.globl gMonBackPic_Parasect
gMonBackPic_Parasect: @ 0x8C4F668
	.incbin "graphics/pokemon/parasect/back.4bpp.lz"

	.globl gMonShinyPalette_Parasect
gMonShinyPalette_Parasect: @ 0x8C4F964
	.incbin "graphics/pokemon/parasect/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc4f98c, 0x420

	.globl gMonStillFrontPic_Venonat
gMonStillFrontPic_Venonat: @ 0x8C4FDAC
	.incbin "graphics/pokemon/venonat/front.4bpp.lz"

	.globl gMonPalette_Venonat
gMonPalette_Venonat: @ 0x8C50124
	.incbin "graphics/pokemon/venonat/normal.gbapal.lz"

	.globl gMonBackPic_Venonat
gMonBackPic_Venonat: @ 0x8C5014C
	.incbin "graphics/pokemon/venonat/back.4bpp.lz"

	.globl gMonShinyPalette_Venonat
gMonShinyPalette_Venonat: @ 0x8C5047C
	.incbin "graphics/pokemon/venonat/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc504a4, 0x420

	.globl gMonStillFrontPic_Venomoth
gMonStillFrontPic_Venomoth: @ 0x8C508C4
	.incbin "graphics/pokemon/venomoth/front.4bpp.lz"

	.globl gMonPalette_Venomoth
gMonPalette_Venomoth: @ 0x8C50D68
	.incbin "graphics/pokemon/venomoth/normal.gbapal.lz"

	.globl gMonBackPic_Venomoth
gMonBackPic_Venomoth: @ 0x8C50D90
	.incbin "graphics/pokemon/venomoth/back.4bpp.lz"

	.globl gMonShinyPalette_Venomoth
gMonShinyPalette_Venomoth: @ 0x8C51154
	.incbin "graphics/pokemon/venomoth/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5117c, 0x420

	.globl gMonStillFrontPic_Diglett
gMonStillFrontPic_Diglett: @ 0x8C5159C
	.incbin "graphics/pokemon/diglett/front.4bpp.lz"

	.globl gMonPalette_Diglett
gMonPalette_Diglett: @ 0x8C517A8
	.incbin "graphics/pokemon/diglett/normal.gbapal.lz"

	.globl gMonBackPic_Diglett
gMonBackPic_Diglett: @ 0x8C517D0
	.incbin "graphics/pokemon/diglett/back.4bpp.lz"

	.globl gMonShinyPalette_Diglett
gMonShinyPalette_Diglett: @ 0x8C519DC
	.incbin "graphics/pokemon/diglett/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc51a04, 0x420

	.globl gMonStillFrontPic_Dugtrio
gMonStillFrontPic_Dugtrio: @ 0x8C51E24
	.incbin "graphics/pokemon/dugtrio/front.4bpp.lz"

	.globl gMonPalette_Dugtrio
gMonPalette_Dugtrio: @ 0x8C52148
	.incbin "graphics/pokemon/dugtrio/normal.gbapal.lz"

	.globl gMonBackPic_Dugtrio
gMonBackPic_Dugtrio: @ 0x8C52170
	.incbin "graphics/pokemon/dugtrio/back.4bpp.lz"

	.globl gMonShinyPalette_Dugtrio
gMonShinyPalette_Dugtrio: @ 0x8C5241C
	.incbin "graphics/pokemon/dugtrio/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc52444, 0x420

	.globl gMonStillFrontPic_Meowth
gMonStillFrontPic_Meowth: @ 0x8C52864
	.incbin "graphics/pokemon/meowth/front.4bpp.lz"

	.globl gMonPalette_Meowth
gMonPalette_Meowth: @ 0x8C52B50
	.incbin "graphics/pokemon/meowth/normal.gbapal.lz"

	.globl gMonBackPic_Meowth
gMonBackPic_Meowth: @ 0x8C52B78
	.incbin "graphics/pokemon/meowth/back.4bpp.lz"

	.globl gMonShinyPalette_Meowth
gMonShinyPalette_Meowth: @ 0x8C52E5C
	.incbin "graphics/pokemon/meowth/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc52e84, 0x420

	.globl gMonStillFrontPic_Persian
gMonStillFrontPic_Persian: @ 0x8C532A4
	.incbin "graphics/pokemon/persian/front.4bpp.lz"

	.globl gMonPalette_Persian
gMonPalette_Persian: @ 0x8C53658
	.incbin "graphics/pokemon/persian/normal.gbapal.lz"

	.globl gMonBackPic_Persian
gMonBackPic_Persian: @ 0x8C53680
	.incbin "graphics/pokemon/persian/back.4bpp.lz"

	.globl gMonShinyPalette_Persian
gMonShinyPalette_Persian: @ 0x8C539E4
	.incbin "graphics/pokemon/persian/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc53a0c, 0x420

	.globl gMonStillFrontPic_Psyduck
gMonStillFrontPic_Psyduck: @ 0x8C53E2C
	.incbin "graphics/pokemon/psyduck/front.4bpp.lz"

	.globl gMonPalette_Psyduck
gMonPalette_Psyduck: @ 0x8C54104
	.incbin "graphics/pokemon/psyduck/normal.gbapal.lz"

	.globl gMonBackPic_Psyduck
gMonBackPic_Psyduck: @ 0x8C5412C
	.incbin "graphics/pokemon/psyduck/back.4bpp.lz"

	.globl gMonShinyPalette_Psyduck
gMonShinyPalette_Psyduck: @ 0x8C543C8
	.incbin "graphics/pokemon/psyduck/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc543ee, 0x422

	.globl gMonStillFrontPic_Golduck
gMonStillFrontPic_Golduck: @ 0x8C54810
	.incbin "graphics/pokemon/golduck/front.4bpp.lz"

	.globl gMonPalette_Golduck
gMonPalette_Golduck: @ 0x8C54BE8
	.incbin "graphics/pokemon/golduck/normal.gbapal.lz"

	.globl gMonBackPic_Golduck
gMonBackPic_Golduck: @ 0x8C54C10
	.incbin "graphics/pokemon/golduck/back.4bpp.lz"

	.globl gMonShinyPalette_Golduck
gMonShinyPalette_Golduck: @ 0x8C54F3C
	.incbin "graphics/pokemon/golduck/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc54f64, 0x420

	.globl gMonStillFrontPic_Mankey
gMonStillFrontPic_Mankey: @ 0x8C55384
	.incbin "graphics/pokemon/mankey/front.4bpp.lz"

	.globl gMonPalette_Mankey
gMonPalette_Mankey: @ 0x8C5569C
	.incbin "graphics/pokemon/mankey/normal.gbapal.lz"

	.globl gMonBackPic_Mankey
gMonBackPic_Mankey: @ 0x8C556C4
	.incbin "graphics/pokemon/mankey/back.4bpp.lz"

	.globl gMonShinyPalette_Mankey
gMonShinyPalette_Mankey: @ 0x8C55A2C
	.incbin "graphics/pokemon/mankey/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc55a54, 0x420

	.globl gMonStillFrontPic_Primeape
gMonStillFrontPic_Primeape: @ 0x8C55E74
	.incbin "graphics/pokemon/primeape/front.4bpp.lz"

	.globl gMonPalette_Primeape
gMonPalette_Primeape: @ 0x8C56224
	.incbin "graphics/pokemon/primeape/normal.gbapal.lz"

	.globl gMonBackPic_Primeape
gMonBackPic_Primeape: @ 0x8C5624C
	.incbin "graphics/pokemon/primeape/back.4bpp.lz"

	.globl gMonShinyPalette_Primeape
gMonShinyPalette_Primeape: @ 0x8C565BC
	.incbin "graphics/pokemon/primeape/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc565e4, 0x420

	.globl gMonStillFrontPic_Growlithe
gMonStillFrontPic_Growlithe: @ 0x8C56A04
	.incbin "graphics/pokemon/growlithe/front.4bpp.lz"

	.globl gMonPalette_Growlithe
gMonPalette_Growlithe: @ 0x8C56D5C
	.incbin "graphics/pokemon/growlithe/normal.gbapal.lz"

	.globl gMonBackPic_Growlithe
gMonBackPic_Growlithe: @ 0x8C56D84
	.incbin "graphics/pokemon/growlithe/back.4bpp.lz"

	.globl gMonShinyPalette_Growlithe
gMonShinyPalette_Growlithe: @ 0x8C570C0
	.incbin "graphics/pokemon/growlithe/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc570e6, 0x422

	.globl gMonStillFrontPic_Arcanine
gMonStillFrontPic_Arcanine: @ 0x8C57508
	.incbin "graphics/pokemon/arcanine/front.4bpp.lz"

	.globl gMonPalette_Arcanine
gMonPalette_Arcanine: @ 0x8C57A3C
	.incbin "graphics/pokemon/arcanine/normal.gbapal.lz"

	.globl gMonBackPic_Arcanine
gMonBackPic_Arcanine: @ 0x8C57A64
	.incbin "graphics/pokemon/arcanine/back.4bpp.lz"

	.globl gMonShinyPalette_Arcanine
gMonShinyPalette_Arcanine: @ 0x8C57E44
	.incbin "graphics/pokemon/arcanine/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc57e6c, 0x420

	.globl gMonStillFrontPic_Poliwag
gMonStillFrontPic_Poliwag: @ 0x8C5828C
	.incbin "graphics/pokemon/poliwag/front.4bpp.lz"

	.globl gMonPalette_Poliwag
gMonPalette_Poliwag: @ 0x8C58514
	.incbin "graphics/pokemon/poliwag/normal.gbapal.lz"

	.globl gMonBackPic_Poliwag
gMonBackPic_Poliwag: @ 0x8C5853C
	.incbin "graphics/pokemon/poliwag/back.4bpp.lz"

	.globl gMonShinyPalette_Poliwag
gMonShinyPalette_Poliwag: @ 0x8C587AC
	.incbin "graphics/pokemon/poliwag/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc587d2, 0x422

	.globl gMonStillFrontPic_Poliwhirl
gMonStillFrontPic_Poliwhirl: @ 0x8C58BF4
	.incbin "graphics/pokemon/poliwhirl/front.4bpp.lz"

	.globl gMonPalette_Poliwhirl
gMonPalette_Poliwhirl: @ 0x8C58FB8
	.incbin "graphics/pokemon/poliwhirl/normal.gbapal.lz"

	.globl gMonBackPic_Poliwhirl
gMonBackPic_Poliwhirl: @ 0x8C58FE0
	.incbin "graphics/pokemon/poliwhirl/back.4bpp.lz"

	.globl gMonShinyPalette_Poliwhirl
gMonShinyPalette_Poliwhirl: @ 0x8C592A0
	.incbin "graphics/pokemon/poliwhirl/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc592c6, 0x422

	.globl gMonStillFrontPic_Poliwrath
gMonStillFrontPic_Poliwrath: @ 0x8C596E8
	.incbin "graphics/pokemon/poliwrath/front.4bpp.lz"

	.globl gMonPalette_Poliwrath
gMonPalette_Poliwrath: @ 0x8C59AB0
	.incbin "graphics/pokemon/poliwrath/normal.gbapal.lz"

	.globl gMonBackPic_Poliwrath
gMonBackPic_Poliwrath: @ 0x8C59AD8
	.incbin "graphics/pokemon/poliwrath/back.4bpp.lz"

	.globl gMonShinyPalette_Poliwrath
gMonShinyPalette_Poliwrath: @ 0x8C59DF8
	.incbin "graphics/pokemon/poliwrath/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc59e1e, 0x422

	.globl gMonStillFrontPic_Abra
gMonStillFrontPic_Abra: @ 0x8C5A240
	.incbin "graphics/pokemon/abra/front.4bpp.lz"

	.globl gMonPalette_Abra
gMonPalette_Abra: @ 0x8C5A524
	.incbin "graphics/pokemon/abra/normal.gbapal.lz"

	.globl gMonBackPic_Abra
gMonBackPic_Abra: @ 0x8C5A548
	.incbin "graphics/pokemon/abra/back.4bpp.lz"

	.globl gMonShinyPalette_Abra
gMonShinyPalette_Abra: @ 0x8C5A85C
	.incbin "graphics/pokemon/abra/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5a87d, 0x423

	.globl gMonStillFrontPic_Kadabra
gMonStillFrontPic_Kadabra: @ 0x8C5ACA0
	.incbin "graphics/pokemon/kadabra/front.4bpp.lz"

	.globl gMonPalette_Kadabra
gMonPalette_Kadabra: @ 0x8C5B104
	.incbin "graphics/pokemon/kadabra/normal.gbapal.lz"

	.globl gMonBackPic_Kadabra
gMonBackPic_Kadabra: @ 0x8C5B12C
	.incbin "graphics/pokemon/kadabra/back.4bpp.lz"

	.globl gMonShinyPalette_Kadabra
gMonShinyPalette_Kadabra: @ 0x8C5B508
	.incbin "graphics/pokemon/kadabra/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5b530, 0x420

	.globl gMonStillFrontPic_Alakazam
gMonStillFrontPic_Alakazam: @ 0x8C5B950
	.incbin "graphics/pokemon/alakazam/front.4bpp.lz"

	.globl gMonPalette_Alakazam
gMonPalette_Alakazam: @ 0x8C5BD4C
	.incbin "graphics/pokemon/alakazam/normal.gbapal.lz"

	.globl gMonBackPic_Alakazam
gMonBackPic_Alakazam: @ 0x8C5BD74
	.incbin "graphics/pokemon/alakazam/back.4bpp.lz"

	.globl gMonShinyPalette_Alakazam
gMonShinyPalette_Alakazam: @ 0x8C5C1B8
	.incbin "graphics/pokemon/alakazam/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5c1e0, 0x420

	.globl gMonStillFrontPic_Machop
gMonStillFrontPic_Machop: @ 0x8C5C600
	.incbin "graphics/pokemon/machop/front.4bpp.lz"

	.globl gMonPalette_Machop
gMonPalette_Machop: @ 0x8C5C8A4
	.incbin "graphics/pokemon/machop/normal.gbapal.lz"

	.globl gMonBackPic_Machop
gMonBackPic_Machop: @ 0x8C5C8CC
	.incbin "graphics/pokemon/machop/back.4bpp.lz"

	.globl gMonShinyPalette_Machop
gMonShinyPalette_Machop: @ 0x8C5CBAC
	.incbin "graphics/pokemon/machop/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5cbd4, 0x420

	.globl gMonStillFrontPic_Machoke
gMonStillFrontPic_Machoke: @ 0x8C5CFF4
	.incbin "graphics/pokemon/machoke/front.4bpp.lz"

	.globl gMonPalette_Machoke
gMonPalette_Machoke: @ 0x8C5D3A4
	.incbin "graphics/pokemon/machoke/normal.gbapal.lz"

	.globl gMonBackPic_Machoke
gMonBackPic_Machoke: @ 0x8C5D3CC
	.incbin "graphics/pokemon/machoke/back.4bpp.lz"

	.globl gMonShinyPalette_Machoke
gMonShinyPalette_Machoke: @ 0x8C5D71C
	.incbin "graphics/pokemon/machoke/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5d744, 0x420

	.globl gMonStillFrontPic_Machamp
gMonStillFrontPic_Machamp: @ 0x8C5DB64
	.incbin "graphics/pokemon/machamp/front.4bpp.lz"

	.globl gMonPalette_Machamp
gMonPalette_Machamp: @ 0x8C5E0B4
	.incbin "graphics/pokemon/machamp/normal.gbapal.lz"

	.globl gMonBackPic_Machamp
gMonBackPic_Machamp: @ 0x8C5E0DC
	.incbin "graphics/pokemon/machamp/back.4bpp.lz"

	.globl gMonShinyPalette_Machamp
gMonShinyPalette_Machamp: @ 0x8C5E538
	.incbin "graphics/pokemon/machamp/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5e560, 0x420

	.globl gMonStillFrontPic_Bellsprout
gMonStillFrontPic_Bellsprout: @ 0x8C5E980
	.incbin "graphics/pokemon/bellsprout/front.4bpp.lz"

	.globl gMonPalette_Bellsprout
gMonPalette_Bellsprout: @ 0x8C5EC00
	.incbin "graphics/pokemon/bellsprout/normal.gbapal.lz"

	.globl gMonBackPic_Bellsprout
gMonBackPic_Bellsprout: @ 0x8C5EC28
	.incbin "graphics/pokemon/bellsprout/back.4bpp.lz"

	.globl gMonShinyPalette_Bellsprout
gMonShinyPalette_Bellsprout: @ 0x8C5EEC4
	.incbin "graphics/pokemon/bellsprout/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5eeec, 0x420

	.globl gMonStillFrontPic_Weepinbell
gMonStillFrontPic_Weepinbell: @ 0x8C5F30C
	.incbin "graphics/pokemon/weepinbell/front.4bpp.lz"

	.globl gMonPalette_Weepinbell
gMonPalette_Weepinbell: @ 0x8C5F630
	.incbin "graphics/pokemon/weepinbell/normal.gbapal.lz"

	.globl gMonBackPic_Weepinbell
gMonBackPic_Weepinbell: @ 0x8C5F658
	.incbin "graphics/pokemon/weepinbell/back.4bpp.lz"

	.globl gMonShinyPalette_Weepinbell
gMonShinyPalette_Weepinbell: @ 0x8C5F954
	.incbin "graphics/pokemon/weepinbell/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc5f97c, 0x420

	.globl gMonStillFrontPic_Victreebel
gMonStillFrontPic_Victreebel: @ 0x8C5FD9C
	.incbin "graphics/pokemon/victreebel/front.4bpp.lz"

	.globl gMonPalette_Victreebel
gMonPalette_Victreebel: @ 0x8C601C8
	.incbin "graphics/pokemon/victreebel/normal.gbapal.lz"

	.globl gMonBackPic_Victreebel
gMonBackPic_Victreebel: @ 0x8C601F0
	.incbin "graphics/pokemon/victreebel/back.4bpp.lz"

	.globl gMonShinyPalette_Victreebel
gMonShinyPalette_Victreebel: @ 0x8C60588
	.incbin "graphics/pokemon/victreebel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc605b0, 0x420

	.globl gMonStillFrontPic_Tentacool
gMonStillFrontPic_Tentacool: @ 0x8C609D0
	.incbin "graphics/pokemon/tentacool/front.4bpp.lz"

	.globl gMonPalette_Tentacool
gMonPalette_Tentacool: @ 0x8C60C70
	.incbin "graphics/pokemon/tentacool/normal.gbapal.lz"

	.globl gMonBackPic_Tentacool
gMonBackPic_Tentacool: @ 0x8C60C98
	.incbin "graphics/pokemon/tentacool/back.4bpp.lz"

	.globl gMonShinyPalette_Tentacool
gMonShinyPalette_Tentacool: @ 0x8C60F64
	.incbin "graphics/pokemon/tentacool/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc60f8c, 0x420

	.globl gMonStillFrontPic_Tentacruel
gMonStillFrontPic_Tentacruel: @ 0x8C613AC
	.incbin "graphics/pokemon/tentacruel/front.4bpp.lz"

	.globl gMonPalette_Tentacruel
gMonPalette_Tentacruel: @ 0x8C61848
	.incbin "graphics/pokemon/tentacruel/normal.gbapal.lz"

	.globl gMonBackPic_Tentacruel
gMonBackPic_Tentacruel: @ 0x8C61870
	.incbin "graphics/pokemon/tentacruel/back.4bpp.lz"

	.globl gMonShinyPalette_Tentacruel
gMonShinyPalette_Tentacruel: @ 0x8C61C0C
	.incbin "graphics/pokemon/tentacruel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc61c34, 0x420

	.globl gMonStillFrontPic_Geodude
gMonStillFrontPic_Geodude: @ 0x8C62054
	.incbin "graphics/pokemon/geodude/front.4bpp.lz"

	.globl gMonPalette_Geodude
gMonPalette_Geodude: @ 0x8C622C0
	.incbin "graphics/pokemon/geodude/normal.gbapal.lz"

	.globl gMonBackPic_Geodude
gMonBackPic_Geodude: @ 0x8C622DC
	.incbin "graphics/pokemon/geodude/back.4bpp.lz"

	.globl gMonShinyPalette_Geodude
gMonShinyPalette_Geodude: @ 0x8C62570
	.incbin "graphics/pokemon/geodude/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6258b, 0x421

	.globl gMonStillFrontPic_Graveler
gMonStillFrontPic_Graveler: @ 0x8C629AC
	.incbin "graphics/pokemon/graveler/front.4bpp.lz"

	.globl gMonPalette_Graveler
gMonPalette_Graveler: @ 0x8C62DB4
	.incbin "graphics/pokemon/graveler/normal.gbapal.lz"

	.globl gMonBackPic_Graveler
gMonBackPic_Graveler: @ 0x8C62DD4
	.incbin "graphics/pokemon/graveler/back.4bpp.lz"

	.globl gMonShinyPalette_Graveler
gMonShinyPalette_Graveler: @ 0x8C63050
	.incbin "graphics/pokemon/graveler/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6306d, 0x423

	.globl gMonStillFrontPic_Golem
gMonStillFrontPic_Golem: @ 0x8C63490
	.incbin "graphics/pokemon/golem/front.4bpp.lz"

	.globl gMonPalette_Golem
gMonPalette_Golem: @ 0x8C6390C
	.incbin "graphics/pokemon/golem/normal.gbapal.lz"

	.globl gMonBackPic_Golem
gMonBackPic_Golem: @ 0x8C63934
	.incbin "graphics/pokemon/golem/back.4bpp.lz"

	.globl gMonShinyPalette_Golem
gMonShinyPalette_Golem: @ 0x8C63BF4
	.incbin "graphics/pokemon/golem/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc63c1c, 0x420

	.globl gMonStillFrontPic_Ponyta
gMonStillFrontPic_Ponyta: @ 0x8C6403C
	.incbin "graphics/pokemon/ponyta/front.4bpp.lz"

	.globl gMonPalette_Ponyta
gMonPalette_Ponyta: @ 0x8C643E4
	.incbin "graphics/pokemon/ponyta/normal.gbapal.lz"

	.globl gMonBackPic_Ponyta
gMonBackPic_Ponyta: @ 0x8C6440C
	.incbin "graphics/pokemon/ponyta/back.4bpp.lz"

	.globl gMonShinyPalette_Ponyta
gMonShinyPalette_Ponyta: @ 0x8C64748
	.incbin "graphics/pokemon/ponyta/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6476e, 0x422

	.globl gMonStillFrontPic_Rapidash
gMonStillFrontPic_Rapidash: @ 0x8C64B90
	.incbin "graphics/pokemon/rapidash/front.4bpp.lz"

	.globl gMonPalette_Rapidash
gMonPalette_Rapidash: @ 0x8C65060
	.incbin "graphics/pokemon/rapidash/normal.gbapal.lz"

	.globl gMonBackPic_Rapidash
gMonBackPic_Rapidash: @ 0x8C65088
	.incbin "graphics/pokemon/rapidash/back.4bpp.lz"

	.globl gMonShinyPalette_Rapidash
gMonShinyPalette_Rapidash: @ 0x8C65498
	.incbin "graphics/pokemon/rapidash/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc654c0, 0x420

	.globl gMonStillFrontPic_Slowpoke
gMonStillFrontPic_Slowpoke: @ 0x8C658E0
	.incbin "graphics/pokemon/slowpoke/front.4bpp.lz"

	.globl gMonPalette_Slowpoke
gMonPalette_Slowpoke: @ 0x8C65BEC
	.incbin "graphics/pokemon/slowpoke/normal.gbapal.lz"

	.globl gMonBackPic_Slowpoke
gMonBackPic_Slowpoke: @ 0x8C65C14
	.incbin "graphics/pokemon/slowpoke/back.4bpp.lz"

	.globl gMonShinyPalette_Slowpoke
gMonShinyPalette_Slowpoke: @ 0x8C65E78
	.incbin "graphics/pokemon/slowpoke/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc65ea0, 0x420

	.globl gMonStillFrontPic_Slowbro
gMonStillFrontPic_Slowbro: @ 0x8C662C0
	.incbin "graphics/pokemon/slowbro/front.4bpp.lz"

	.globl gMonPalette_Slowbro
gMonPalette_Slowbro: @ 0x8C66780
	.incbin "graphics/pokemon/slowbro/normal.gbapal.lz"

	.globl gMonBackPic_Slowbro
gMonBackPic_Slowbro: @ 0x8C667A8
	.incbin "graphics/pokemon/slowbro/back.4bpp.lz"

	.globl gMonShinyPalette_Slowbro
gMonShinyPalette_Slowbro: @ 0x8C66B44
	.incbin "graphics/pokemon/slowbro/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc66b6c, 0x420

	.globl gMonStillFrontPic_Magnemite
gMonStillFrontPic_Magnemite: @ 0x8C66F8C
	.incbin "graphics/pokemon/magnemite/front.4bpp.lz"

	.globl gMonPalette_Magnemite
gMonPalette_Magnemite: @ 0x8C67164
	.incbin "graphics/pokemon/magnemite/normal.gbapal.lz"

	.globl gMonBackPic_Magnemite
gMonBackPic_Magnemite: @ 0x8C6718C
	.incbin "graphics/pokemon/magnemite/back.4bpp.lz"

	.globl gMonShinyPalette_Magnemite
gMonShinyPalette_Magnemite: @ 0x8C67374
	.incbin "graphics/pokemon/magnemite/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc67398, 0x420

	.globl gMonStillFrontPic_Magneton
gMonStillFrontPic_Magneton: @ 0x8C677B8
	.incbin "graphics/pokemon/magneton/front.4bpp.lz"

	.globl gMonPalette_Magneton
gMonPalette_Magneton: @ 0x8C67BBC
	.incbin "graphics/pokemon/magneton/normal.gbapal.lz"

	.globl gMonBackPic_Magneton
gMonBackPic_Magneton: @ 0x8C67BE4
	.incbin "graphics/pokemon/magneton/back.4bpp.lz"

	.globl gMonShinyPalette_Magneton
gMonShinyPalette_Magneton: @ 0x8C67F64
	.incbin "graphics/pokemon/magneton/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc67f8a, 0x422

	.globl gMonStillFrontPic_Farfetchd
gMonStillFrontPic_Farfetchd: @ 0x8C683AC
	.incbin "graphics/pokemon/farfetchd/front.4bpp.lz"

	.globl gMonPalette_Farfetchd
gMonPalette_Farfetchd: @ 0x8C68728
	.incbin "graphics/pokemon/farfetchd/normal.gbapal.lz"

	.globl gMonBackPic_Farfetchd
gMonBackPic_Farfetchd: @ 0x8C68750
	.incbin "graphics/pokemon/farfetchd/back.4bpp.lz"

	.globl gMonShinyPalette_Farfetchd
gMonShinyPalette_Farfetchd: @ 0x8C68ABC
	.incbin "graphics/pokemon/farfetchd/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc68ae4, 0x420

	.globl gMonStillFrontPic_Doduo
gMonStillFrontPic_Doduo: @ 0x8C68F04
	.incbin "graphics/pokemon/doduo/front.4bpp.lz"

	.globl gMonPalette_Doduo
gMonPalette_Doduo: @ 0x8C69258
	.incbin "graphics/pokemon/doduo/normal.gbapal.lz"

	.globl gMonBackPic_Doduo
gMonBackPic_Doduo: @ 0x8C6927C
	.incbin "graphics/pokemon/doduo/back.4bpp.lz"

	.globl gMonShinyPalette_Doduo
gMonShinyPalette_Doduo: @ 0x8C69594
	.incbin "graphics/pokemon/doduo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc695b8, 0x420

	.globl gMonStillFrontPic_Dodrio
gMonStillFrontPic_Dodrio: @ 0x8C699D8
	.incbin "graphics/pokemon/dodrio/front.4bpp.lz"

	.globl gMonPalette_Dodrio
gMonPalette_Dodrio: @ 0x8C69EB4
	.incbin "graphics/pokemon/dodrio/normal.gbapal.lz"

	.globl gMonBackPic_Dodrio
gMonBackPic_Dodrio: @ 0x8C69EDC
	.incbin "graphics/pokemon/dodrio/back.4bpp.lz"

	.globl gMonShinyPalette_Dodrio
gMonShinyPalette_Dodrio: @ 0x8C6A340
	.incbin "graphics/pokemon/dodrio/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6a368, 0x420

	.globl gMonStillFrontPic_Seel
gMonStillFrontPic_Seel: @ 0x8C6A788
	.incbin "graphics/pokemon/seel/front.4bpp.lz"

	.globl gMonPalette_Seel
gMonPalette_Seel: @ 0x8C6AA90
	.incbin "graphics/pokemon/seel/normal.gbapal.lz"

	.globl gMonBackPic_Seel
gMonBackPic_Seel: @ 0x8C6AAB8
	.incbin "graphics/pokemon/seel/back.4bpp.lz"

	.globl gMonShinyPalette_Seel
gMonShinyPalette_Seel: @ 0x8C6ADA4
	.incbin "graphics/pokemon/seel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6adca, 0x422

	.globl gMonStillFrontPic_Dewgong
gMonStillFrontPic_Dewgong: @ 0x8C6B1EC
	.incbin "graphics/pokemon/dewgong/front.4bpp.lz"

	.globl gMonPalette_Dewgong
gMonPalette_Dewgong: @ 0x8C6B5B4
	.incbin "graphics/pokemon/dewgong/normal.gbapal.lz"

	.globl gMonBackPic_Dewgong
gMonBackPic_Dewgong: @ 0x8C6B5D4
	.incbin "graphics/pokemon/dewgong/back.4bpp.lz"

	.globl gMonShinyPalette_Dewgong
gMonShinyPalette_Dewgong: @ 0x8C6B868
	.incbin "graphics/pokemon/dewgong/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6b885, 0x423

	.globl gMonStillFrontPic_Grimer
gMonStillFrontPic_Grimer: @ 0x8C6BCA8
	.incbin "graphics/pokemon/grimer/front.4bpp.lz"

	.globl gMonPalette_Grimer
gMonPalette_Grimer: @ 0x8C6BFC4
	.incbin "graphics/pokemon/grimer/normal.gbapal.lz"

	.globl gMonBackPic_Grimer
gMonBackPic_Grimer: @ 0x8C6BFE8
	.incbin "graphics/pokemon/grimer/back.4bpp.lz"

	.globl gMonShinyPalette_Grimer
gMonShinyPalette_Grimer: @ 0x8C6C2CC
	.incbin "graphics/pokemon/grimer/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6c2f0, 0x420

	.globl gMonStillFrontPic_Muk
gMonStillFrontPic_Muk: @ 0x8C6C710
	.incbin "graphics/pokemon/muk/front.4bpp.lz"

	.globl gMonPalette_Muk
gMonPalette_Muk: @ 0x8C6CB5C
	.incbin "graphics/pokemon/muk/normal.gbapal.lz"

	.globl gMonBackPic_Muk
gMonBackPic_Muk: @ 0x8C6CB80
	.incbin "graphics/pokemon/muk/back.4bpp.lz"

	.globl gMonShinyPalette_Muk
gMonShinyPalette_Muk: @ 0x8C6CED8
	.incbin "graphics/pokemon/muk/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6cefc, 0x420

	.globl gMonStillFrontPic_Shellder
gMonStillFrontPic_Shellder: @ 0x8C6D31C
	.incbin "graphics/pokemon/shellder/front.4bpp.lz"

	.globl gMonPalette_Shellder
gMonPalette_Shellder: @ 0x8C6D584
	.incbin "graphics/pokemon/shellder/normal.gbapal.lz"

	.globl gMonBackPic_Shellder
gMonBackPic_Shellder: @ 0x8C6D5A8
	.incbin "graphics/pokemon/shellder/back.4bpp.lz"

	.globl gMonShinyPalette_Shellder
gMonShinyPalette_Shellder: @ 0x8C6D8BC
	.incbin "graphics/pokemon/shellder/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6d8e0, 0x420

	.globl gMonStillFrontPic_Cloyster
gMonStillFrontPic_Cloyster: @ 0x8C6DD00
	.incbin "graphics/pokemon/cloyster/front.4bpp.lz"

	.globl gMonPalette_Cloyster
gMonPalette_Cloyster: @ 0x8C6E138
	.incbin "graphics/pokemon/cloyster/normal.gbapal.lz"

	.globl gMonBackPic_Cloyster
gMonBackPic_Cloyster: @ 0x8C6E15C
	.incbin "graphics/pokemon/cloyster/back.4bpp.lz"

	.globl gMonShinyPalette_Cloyster
gMonShinyPalette_Cloyster: @ 0x8C6E568
	.incbin "graphics/pokemon/cloyster/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6e58c, 0x420

	.globl gMonStillFrontPic_Gastly
gMonStillFrontPic_Gastly: @ 0x8C6E9AC
	.incbin "graphics/pokemon/gastly/front.4bpp.lz"

	.globl gMonPalette_Gastly
gMonPalette_Gastly: @ 0x8C6ED64
	.incbin "graphics/pokemon/gastly/normal.gbapal.lz"

	.globl gMonBackPic_Gastly
gMonBackPic_Gastly: @ 0x8C6ED8C
	.incbin "graphics/pokemon/gastly/back.4bpp.lz"

	.globl gMonShinyPalette_Gastly
gMonShinyPalette_Gastly: @ 0x8C6F0B0
	.incbin "graphics/pokemon/gastly/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6f0d8, 0x420

	.globl gMonStillFrontPic_Haunter
gMonStillFrontPic_Haunter: @ 0x8C6F4F8
	.incbin "graphics/pokemon/haunter/front.4bpp.lz"

	.globl gMonPalette_Haunter
gMonPalette_Haunter: @ 0x8C6F8F8
	.incbin "graphics/pokemon/haunter/normal.gbapal.lz"

	.globl gMonBackPic_Haunter
gMonBackPic_Haunter: @ 0x8C6F91C
	.incbin "graphics/pokemon/haunter/back.4bpp.lz"

	.globl gMonShinyPalette_Haunter
gMonShinyPalette_Haunter: @ 0x8C6FC44
	.incbin "graphics/pokemon/haunter/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc6fc68, 0x420

	.globl gMonStillFrontPic_Gengar
gMonStillFrontPic_Gengar: @ 0x8C70088
	.incbin "graphics/pokemon/gengar/front.4bpp.lz"

	.globl gMonPalette_Gengar
gMonPalette_Gengar: @ 0x8C70424
	.incbin "graphics/pokemon/gengar/normal.gbapal.lz"

	.globl gMonBackPic_Gengar
gMonBackPic_Gengar: @ 0x8C70448
	.incbin "graphics/pokemon/gengar/back.4bpp.lz"

	.globl gMonShinyPalette_Gengar
gMonShinyPalette_Gengar: @ 0x8C70730
	.incbin "graphics/pokemon/gengar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc70754, 0x420

	.globl gMonStillFrontPic_Onix
gMonStillFrontPic_Onix: @ 0x8C70B74
	.incbin "graphics/pokemon/onix/front.4bpp.lz"

	.globl gMonPalette_Onix
gMonPalette_Onix: @ 0x8C70FEC
	.incbin "graphics/pokemon/onix/normal.gbapal.lz"

	.globl gMonBackPic_Onix
gMonBackPic_Onix: @ 0x8C71008
	.incbin "graphics/pokemon/onix/back.4bpp.lz"

	.globl gMonShinyPalette_Onix
gMonShinyPalette_Onix: @ 0x8C71384
	.incbin "graphics/pokemon/onix/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7139f, 0x421

	.globl gMonStillFrontPic_Drowzee
gMonStillFrontPic_Drowzee: @ 0x8C717C0
	.incbin "graphics/pokemon/drowzee/front.4bpp.lz"

	.globl gMonPalette_Drowzee
gMonPalette_Drowzee: @ 0x8C71B38
	.incbin "graphics/pokemon/drowzee/normal.gbapal.lz"

	.globl gMonBackPic_Drowzee
gMonBackPic_Drowzee: @ 0x8C71B5C
	.incbin "graphics/pokemon/drowzee/back.4bpp.lz"

	.globl gMonShinyPalette_Drowzee
gMonShinyPalette_Drowzee: @ 0x8C71DB8
	.incbin "graphics/pokemon/drowzee/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc71dda, 0x422

	.globl gMonStillFrontPic_Hypno
gMonStillFrontPic_Hypno: @ 0x8C721FC
	.incbin "graphics/pokemon/hypno/front.4bpp.lz"

	.globl gMonPalette_Hypno
gMonPalette_Hypno: @ 0x8C725E8
	.incbin "graphics/pokemon/hypno/normal.gbapal.lz"

	.globl gMonBackPic_Hypno
gMonBackPic_Hypno: @ 0x8C7260C
	.incbin "graphics/pokemon/hypno/back.4bpp.lz"

	.globl gMonShinyPalette_Hypno
gMonShinyPalette_Hypno: @ 0x8C7293C
	.incbin "graphics/pokemon/hypno/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc72960, 0x420

	.globl gMonStillFrontPic_Krabby
gMonStillFrontPic_Krabby: @ 0x8C72D80
	.incbin "graphics/pokemon/krabby/front.4bpp.lz"

	.globl gMonPalette_Krabby
gMonPalette_Krabby: @ 0x8C73038
	.incbin "graphics/pokemon/krabby/normal.gbapal.lz"

	.globl gMonBackPic_Krabby
gMonBackPic_Krabby: @ 0x8C73060
	.incbin "graphics/pokemon/krabby/back.4bpp.lz"

	.globl gMonShinyPalette_Krabby
gMonShinyPalette_Krabby: @ 0x8C733EC
	.incbin "graphics/pokemon/krabby/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc73412, 0x422

	.globl gMonStillFrontPic_Kingler
gMonStillFrontPic_Kingler: @ 0x8C73834
	.incbin "graphics/pokemon/kingler/front.4bpp.lz"

	.globl gMonPalette_Kingler
gMonPalette_Kingler: @ 0x8C73D68
	.incbin "graphics/pokemon/kingler/normal.gbapal.lz"

	.globl gMonBackPic_Kingler
gMonBackPic_Kingler: @ 0x8C73D8C
	.incbin "graphics/pokemon/kingler/back.4bpp.lz"

	.globl gMonShinyPalette_Kingler
gMonShinyPalette_Kingler: @ 0x8C74110
	.incbin "graphics/pokemon/kingler/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc74134, 0x420

	.globl gMonStillFrontPic_Voltorb
gMonStillFrontPic_Voltorb: @ 0x8C74554
	.incbin "graphics/pokemon/voltorb/front.4bpp.lz"

	.globl gMonPalette_Voltorb
gMonPalette_Voltorb: @ 0x8C7475C
	.incbin "graphics/pokemon/voltorb/normal.gbapal.lz"

	.globl gMonBackPic_Voltorb
gMonBackPic_Voltorb: @ 0x8C74780
	.incbin "graphics/pokemon/voltorb/back.4bpp.lz"

	.globl gMonShinyPalette_Voltorb
gMonShinyPalette_Voltorb: @ 0x8C749F4
	.incbin "graphics/pokemon/voltorb/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc74a16, 0x422

	.globl gMonStillFrontPic_Electrode
gMonStillFrontPic_Electrode: @ 0x8C74E38
	.incbin "graphics/pokemon/electrode/front.4bpp.lz"

	.globl gMonPalette_Electrode
gMonPalette_Electrode: @ 0x8C750A4
	.incbin "graphics/pokemon/electrode/normal.gbapal.lz"

	.globl gMonBackPic_Electrode
gMonBackPic_Electrode: @ 0x8C750C8
	.incbin "graphics/pokemon/electrode/back.4bpp.lz"

	.globl gMonShinyPalette_Electrode
gMonShinyPalette_Electrode: @ 0x8C75338
	.incbin "graphics/pokemon/electrode/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7535c, 0x420

	.globl gMonStillFrontPic_Exeggcute
gMonStillFrontPic_Exeggcute: @ 0x8C7577C
	.incbin "graphics/pokemon/exeggcute/front.4bpp.lz"

	.globl gMonPalette_Exeggcute
gMonPalette_Exeggcute: @ 0x8C75B80
	.incbin "graphics/pokemon/exeggcute/normal.gbapal.lz"

	.globl gMonBackPic_Exeggcute
gMonBackPic_Exeggcute: @ 0x8C75BA4
	.incbin "graphics/pokemon/exeggcute/back.4bpp.lz"

	.globl gMonShinyPalette_Exeggcute
gMonShinyPalette_Exeggcute: @ 0x8C75EAC
	.incbin "graphics/pokemon/exeggcute/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc75ece, 0x422

	.globl gMonStillFrontPic_Exeggutor
gMonStillFrontPic_Exeggutor: @ 0x8C762F0
	.incbin "graphics/pokemon/exeggutor/front.4bpp.lz"

	.globl gMonPalette_Exeggutor
gMonPalette_Exeggutor: @ 0x8C767F0
	.incbin "graphics/pokemon/exeggutor/normal.gbapal.lz"

	.globl gMonBackPic_Exeggutor
gMonBackPic_Exeggutor: @ 0x8C76818
	.incbin "graphics/pokemon/exeggutor/back.4bpp.lz"

	.globl gMonShinyPalette_Exeggutor
gMonShinyPalette_Exeggutor: @ 0x8C76CB8
	.incbin "graphics/pokemon/exeggutor/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc76ce0, 0x420

	.globl gMonStillFrontPic_Cubone
gMonStillFrontPic_Cubone: @ 0x8C77100
	.incbin "graphics/pokemon/cubone/front.4bpp.lz"

	.globl gMonPalette_Cubone
gMonPalette_Cubone: @ 0x8C773D0
	.incbin "graphics/pokemon/cubone/normal.gbapal.lz"

	.globl gMonBackPic_Cubone
gMonBackPic_Cubone: @ 0x8C773F8
	.incbin "graphics/pokemon/cubone/back.4bpp.lz"

	.globl gMonShinyPalette_Cubone
gMonShinyPalette_Cubone: @ 0x8C77738
	.incbin "graphics/pokemon/cubone/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc77760, 0x420

	.globl gMonStillFrontPic_Marowak
gMonStillFrontPic_Marowak: @ 0x8C77B80
	.incbin "graphics/pokemon/marowak/front.4bpp.lz"

	.globl gMonPalette_Marowak
gMonPalette_Marowak: @ 0x8C77F08
	.incbin "graphics/pokemon/marowak/normal.gbapal.lz"

	.globl gMonBackPic_Marowak
gMonBackPic_Marowak: @ 0x8C77F30
	.incbin "graphics/pokemon/marowak/back.4bpp.lz"

	.globl gMonShinyPalette_Marowak
gMonShinyPalette_Marowak: @ 0x8C78278
	.incbin "graphics/pokemon/marowak/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc782a0, 0x420

	.globl gMonStillFrontPic_Hitmonlee
gMonStillFrontPic_Hitmonlee: @ 0x8C786C0
	.incbin "graphics/pokemon/hitmonlee/front.4bpp.lz"

	.globl gMonPalette_Hitmonlee
gMonPalette_Hitmonlee: @ 0x8C78AC0
	.incbin "graphics/pokemon/hitmonlee/normal.gbapal.lz"

	.globl gMonBackPic_Hitmonlee
gMonBackPic_Hitmonlee: @ 0x8C78AE8
	.incbin "graphics/pokemon/hitmonlee/back.4bpp.lz"

	.globl gMonShinyPalette_Hitmonlee
gMonShinyPalette_Hitmonlee: @ 0x8C78D8C
	.incbin "graphics/pokemon/hitmonlee/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc78db4, 0x420

	.globl gMonStillFrontPic_Hitmonchan
gMonStillFrontPic_Hitmonchan: @ 0x8C791D4
	.incbin "graphics/pokemon/hitmonchan/front.4bpp.lz"

	.globl gMonPalette_Hitmonchan
gMonPalette_Hitmonchan: @ 0x8C79514
	.incbin "graphics/pokemon/hitmonchan/normal.gbapal.lz"

	.globl gMonBackPic_Hitmonchan
gMonBackPic_Hitmonchan: @ 0x8C7953C
	.incbin "graphics/pokemon/hitmonchan/back.4bpp.lz"

	.globl gMonShinyPalette_Hitmonchan
gMonShinyPalette_Hitmonchan: @ 0x8C79880
	.incbin "graphics/pokemon/hitmonchan/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc798a8, 0x420

	.globl gMonStillFrontPic_Lickitung
gMonStillFrontPic_Lickitung: @ 0x8C79CC8
	.incbin "graphics/pokemon/lickitung/front.4bpp.lz"

	.globl gMonPalette_Lickitung
gMonPalette_Lickitung: @ 0x8C7A080
	.incbin "graphics/pokemon/lickitung/normal.gbapal.lz"

	.globl gMonBackPic_Lickitung
gMonBackPic_Lickitung: @ 0x8C7A0A8
	.incbin "graphics/pokemon/lickitung/back.4bpp.lz"

	.globl gMonShinyPalette_Lickitung
gMonShinyPalette_Lickitung: @ 0x8C7A368
	.incbin "graphics/pokemon/lickitung/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7a390, 0x420

	.globl gMonStillFrontPic_Koffing
gMonStillFrontPic_Koffing: @ 0x8C7A7B0
	.incbin "graphics/pokemon/koffing/front.4bpp.lz"

	.globl gMonPalette_Koffing
gMonPalette_Koffing: @ 0x8C7AB0C
	.incbin "graphics/pokemon/koffing/normal.gbapal.lz"

	.globl gMonBackPic_Koffing
gMonBackPic_Koffing: @ 0x8C7AB34
	.incbin "graphics/pokemon/koffing/back.4bpp.lz"

	.globl gMonShinyPalette_Koffing
gMonShinyPalette_Koffing: @ 0x8C7AE34
	.incbin "graphics/pokemon/koffing/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7ae5c, 0x420

	.globl gMonStillFrontPic_Weezing
gMonStillFrontPic_Weezing: @ 0x8C7B27C
	.incbin "graphics/pokemon/weezing/front.4bpp.lz"

	.globl gMonPalette_Weezing
gMonPalette_Weezing: @ 0x8C7B704
	.incbin "graphics/pokemon/weezing/normal.gbapal.lz"

	.globl gMonBackPic_Weezing
gMonBackPic_Weezing: @ 0x8C7B72C
	.incbin "graphics/pokemon/weezing/back.4bpp.lz"

	.globl gMonShinyPalette_Weezing
gMonShinyPalette_Weezing: @ 0x8C7BA5C
	.incbin "graphics/pokemon/weezing/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7ba84, 0x420

	.globl gMonStillFrontPic_Rhyhorn
gMonStillFrontPic_Rhyhorn: @ 0x8C7BEA4
	.incbin "graphics/pokemon/rhyhorn/front.4bpp.lz"

	.globl gMonPalette_Rhyhorn
gMonPalette_Rhyhorn: @ 0x8C7C2A8
	.incbin "graphics/pokemon/rhyhorn/normal.gbapal.lz"

	.globl gMonBackPic_Rhyhorn
gMonBackPic_Rhyhorn: @ 0x8C7C2C8
	.incbin "graphics/pokemon/rhyhorn/back.4bpp.lz"

	.globl gMonShinyPalette_Rhyhorn
gMonShinyPalette_Rhyhorn: @ 0x8C7C610
	.incbin "graphics/pokemon/rhyhorn/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7c62f, 0x421

	.globl gMonStillFrontPic_Rhydon
gMonStillFrontPic_Rhydon: @ 0x8C7CA50
	.incbin "graphics/pokemon/rhydon/front.4bpp.lz"

	.globl gMonPalette_Rhydon
gMonPalette_Rhydon: @ 0x8C7CF58
	.incbin "graphics/pokemon/rhydon/normal.gbapal.lz"

	.globl gMonBackPic_Rhydon
gMonBackPic_Rhydon: @ 0x8C7CF80
	.incbin "graphics/pokemon/rhydon/back.4bpp.lz"

	.globl gMonShinyPalette_Rhydon
gMonShinyPalette_Rhydon: @ 0x8C7D3D0
	.incbin "graphics/pokemon/rhydon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7d3f8, 0x420

	.globl gMonStillFrontPic_Chansey
gMonStillFrontPic_Chansey: @ 0x8C7D818
	.incbin "graphics/pokemon/chansey/front.4bpp.lz"

	.globl gMonPalette_Chansey
gMonPalette_Chansey: @ 0x8C7DB6C
	.incbin "graphics/pokemon/chansey/normal.gbapal.lz"

	.globl gMonBackPic_Chansey
gMonBackPic_Chansey: @ 0x8C7DB90
	.incbin "graphics/pokemon/chansey/back.4bpp.lz"

	.globl gMonShinyPalette_Chansey
gMonShinyPalette_Chansey: @ 0x8C7DE64
	.incbin "graphics/pokemon/chansey/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7de88, 0x420

	.globl gMonStillFrontPic_Tangela
gMonStillFrontPic_Tangela: @ 0x8C7E2A8
	.incbin "graphics/pokemon/tangela/front.4bpp.lz"

	.globl gMonPalette_Tangela
gMonPalette_Tangela: @ 0x8C7E67C
	.incbin "graphics/pokemon/tangela/normal.gbapal.lz"

	.globl gMonBackPic_Tangela
gMonBackPic_Tangela: @ 0x8C7E6A0
	.incbin "graphics/pokemon/tangela/back.4bpp.lz"

	.globl gMonShinyPalette_Tangela
gMonShinyPalette_Tangela: @ 0x8C7EA4C
	.incbin "graphics/pokemon/tangela/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7ea70, 0x420

	.globl gMonStillFrontPic_Kangaskhan
gMonStillFrontPic_Kangaskhan: @ 0x8C7EE90
	.incbin "graphics/pokemon/kangaskhan/front.4bpp.lz"

	.globl gMonPalette_Kangaskhan
gMonPalette_Kangaskhan: @ 0x8C7F388
	.incbin "graphics/pokemon/kangaskhan/normal.gbapal.lz"

	.globl gMonBackPic_Kangaskhan
gMonBackPic_Kangaskhan: @ 0x8C7F3B0
	.incbin "graphics/pokemon/kangaskhan/back.4bpp.lz"

	.globl gMonShinyPalette_Kangaskhan
gMonShinyPalette_Kangaskhan: @ 0x8C7F7E0
	.incbin "graphics/pokemon/kangaskhan/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc7f807, 0x421

	.globl gMonStillFrontPic_Horsea
gMonStillFrontPic_Horsea: @ 0x8C7FC28
	.incbin "graphics/pokemon/horsea/front.4bpp.lz"

	.globl gMonPalette_Horsea
gMonPalette_Horsea: @ 0x8C7FEA0
	.incbin "graphics/pokemon/horsea/normal.gbapal.lz"

	.globl gMonBackPic_Horsea
gMonBackPic_Horsea: @ 0x8C7FEC8
	.incbin "graphics/pokemon/horsea/back.4bpp.lz"

	.globl gMonShinyPalette_Horsea
gMonShinyPalette_Horsea: @ 0x8C801A8
	.incbin "graphics/pokemon/horsea/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc801ce, 0x422

	.globl gMonStillFrontPic_Seadra
gMonStillFrontPic_Seadra: @ 0x8C805F0
	.incbin "graphics/pokemon/seadra/front.4bpp.lz"

	.globl gMonPalette_Seadra
gMonPalette_Seadra: @ 0x8C809B0
	.incbin "graphics/pokemon/seadra/normal.gbapal.lz"

	.globl gMonBackPic_Seadra
gMonBackPic_Seadra: @ 0x8C809D8
	.incbin "graphics/pokemon/seadra/back.4bpp.lz"

	.globl gMonShinyPalette_Seadra
gMonShinyPalette_Seadra: @ 0x8C80D78
	.incbin "graphics/pokemon/seadra/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc80da0, 0x420

	.globl gMonStillFrontPic_Goldeen
gMonStillFrontPic_Goldeen: @ 0x8C811C0
	.incbin "graphics/pokemon/goldeen/front.4bpp.lz"

	.globl gMonPalette_Goldeen
gMonPalette_Goldeen: @ 0x8C81528
	.incbin "graphics/pokemon/goldeen/normal.gbapal.lz"

	.globl gMonBackPic_Goldeen
gMonBackPic_Goldeen: @ 0x8C81550
	.incbin "graphics/pokemon/goldeen/back.4bpp.lz"

	.globl gMonShinyPalette_Goldeen
gMonShinyPalette_Goldeen: @ 0x8C818C0
	.incbin "graphics/pokemon/goldeen/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc818e8, 0x420

	.globl gMonStillFrontPic_Seaking
gMonStillFrontPic_Seaking: @ 0x8C81D08
	.incbin "graphics/pokemon/seaking/front.4bpp.lz"

	.globl gMonPalette_Seaking
gMonPalette_Seaking: @ 0x8C8217C
	.incbin "graphics/pokemon/seaking/normal.gbapal.lz"

	.globl gMonBackPic_Seaking
gMonBackPic_Seaking: @ 0x8C821A4
	.incbin "graphics/pokemon/seaking/back.4bpp.lz"

	.globl gMonShinyPalette_Seaking
gMonShinyPalette_Seaking: @ 0x8C824F4
	.incbin "graphics/pokemon/seaking/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8251c, 0x420

	.globl gMonStillFrontPic_Staryu
gMonStillFrontPic_Staryu: @ 0x8C8293C
	.incbin "graphics/pokemon/staryu/front.4bpp.lz"

	.globl gMonPalette_Staryu
gMonPalette_Staryu: @ 0x8C82C20
	.incbin "graphics/pokemon/staryu/normal.gbapal.lz"

	.globl gMonBackPic_Staryu
gMonBackPic_Staryu: @ 0x8C82C48
	.incbin "graphics/pokemon/staryu/back.4bpp.lz"

	.globl gMonShinyPalette_Staryu
gMonShinyPalette_Staryu: @ 0x8C82ED4
	.incbin "graphics/pokemon/staryu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc82efc, 0x420

	.globl gMonStillFrontPic_Starmie
gMonStillFrontPic_Starmie: @ 0x8C8331C
	.incbin "graphics/pokemon/starmie/front.4bpp.lz"

	.globl gMonPalette_Starmie
gMonPalette_Starmie: @ 0x8C83744
	.incbin "graphics/pokemon/starmie/normal.gbapal.lz"

	.globl gMonBackPic_Starmie
gMonBackPic_Starmie: @ 0x8C8376C
	.incbin "graphics/pokemon/starmie/back.4bpp.lz"

	.globl gMonShinyPalette_Starmie
gMonShinyPalette_Starmie: @ 0x8C83A10
	.incbin "graphics/pokemon/starmie/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc83a38, 0x420

	.globl gMonStillFrontPic_MrMime
gMonStillFrontPic_MrMime: @ 0x8C83E58
	.incbin "graphics/pokemon/mr_mime/front.4bpp.lz"

	.globl gMonPalette_MrMime
gMonPalette_MrMime: @ 0x8C84208
	.incbin "graphics/pokemon/mr_mime/normal.gbapal.lz"

	.globl gMonBackPic_MrMime
gMonBackPic_MrMime: @ 0x8C84230
	.incbin "graphics/pokemon/mr_mime/back.4bpp.lz"

	.globl gMonShinyPalette_MrMime
gMonShinyPalette_MrMime: @ 0x8C84564
	.incbin "graphics/pokemon/mr_mime/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8458c, 0x420

	.globl gMonStillFrontPic_Scyther
gMonStillFrontPic_Scyther: @ 0x8C849AC
	.incbin "graphics/pokemon/scyther/front.4bpp.lz"

	.globl gMonPalette_Scyther
gMonPalette_Scyther: @ 0x8C84E58
	.incbin "graphics/pokemon/scyther/normal.gbapal.lz"

	.globl gMonBackPic_Scyther
gMonBackPic_Scyther: @ 0x8C84E80
	.incbin "graphics/pokemon/scyther/back.4bpp.lz"

	.globl gMonShinyPalette_Scyther
gMonShinyPalette_Scyther: @ 0x8C85228
	.incbin "graphics/pokemon/scyther/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc85250, 0x420

	.globl gMonStillFrontPic_Jynx
gMonStillFrontPic_Jynx: @ 0x8C85670
	.incbin "graphics/pokemon/jynx/front.4bpp.lz"

	.globl gMonPalette_Jynx
gMonPalette_Jynx: @ 0x8C85B0C
	.incbin "graphics/pokemon/jynx/normal.gbapal.lz"

	.globl gMonBackPic_Jynx
gMonBackPic_Jynx: @ 0x8C85B34
	.incbin "graphics/pokemon/jynx/back.4bpp.lz"

	.globl gMonShinyPalette_Jynx
gMonShinyPalette_Jynx: @ 0x8C85E2C
	.incbin "graphics/pokemon/jynx/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc85e54, 0x420

	.globl gMonStillFrontPic_Electabuzz
gMonStillFrontPic_Electabuzz: @ 0x8C86274
	.incbin "graphics/pokemon/electabuzz/front.4bpp.lz"

	.globl gMonPalette_Electabuzz
gMonPalette_Electabuzz: @ 0x8C866F0
	.incbin "graphics/pokemon/electabuzz/normal.gbapal.lz"

	.globl gMonBackPic_Electabuzz
gMonBackPic_Electabuzz: @ 0x8C86718
	.incbin "graphics/pokemon/electabuzz/back.4bpp.lz"

	.globl gMonShinyPalette_Electabuzz
gMonShinyPalette_Electabuzz: @ 0x8C86A28
	.incbin "graphics/pokemon/electabuzz/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc86a50, 0x420

	.globl gMonStillFrontPic_Magmar
gMonStillFrontPic_Magmar: @ 0x8C86E70
	.incbin "graphics/pokemon/magmar/front.4bpp.lz"

	.globl gMonPalette_Magmar
gMonPalette_Magmar: @ 0x8C87318
	.incbin "graphics/pokemon/magmar/normal.gbapal.lz"

	.globl gMonBackPic_Magmar
gMonBackPic_Magmar: @ 0x8C87340
	.incbin "graphics/pokemon/magmar/back.4bpp.lz"

	.globl gMonShinyPalette_Magmar
gMonShinyPalette_Magmar: @ 0x8C87688
	.incbin "graphics/pokemon/magmar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc876b0, 0x420

	.globl gMonStillFrontPic_Pinsir
gMonStillFrontPic_Pinsir: @ 0x8C87AD0
	.incbin "graphics/pokemon/pinsir/front.4bpp.lz"

	.globl gMonPalette_Pinsir
gMonPalette_Pinsir: @ 0x8C87EF8
	.incbin "graphics/pokemon/pinsir/normal.gbapal.lz"

	.globl gMonBackPic_Pinsir
gMonBackPic_Pinsir: @ 0x8C87F1C
	.incbin "graphics/pokemon/pinsir/back.4bpp.lz"

	.globl gMonShinyPalette_Pinsir
gMonShinyPalette_Pinsir: @ 0x8C88270
	.incbin "graphics/pokemon/pinsir/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc88292, 0x422

	.globl gMonStillFrontPic_Tauros
gMonStillFrontPic_Tauros: @ 0x8C886B4
	.incbin "graphics/pokemon/tauros/front.4bpp.lz"

	.globl gMonPalette_Tauros
gMonPalette_Tauros: @ 0x8C88B84
	.incbin "graphics/pokemon/tauros/normal.gbapal.lz"

	.globl gMonBackPic_Tauros
gMonBackPic_Tauros: @ 0x8C88BAC
	.incbin "graphics/pokemon/tauros/back.4bpp.lz"

	.globl gMonShinyPalette_Tauros
gMonShinyPalette_Tauros: @ 0x8C88E60
	.incbin "graphics/pokemon/tauros/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc88e88, 0x420

	.globl gMonStillFrontPic_Magikarp
gMonStillFrontPic_Magikarp: @ 0x8C892A8
	.incbin "graphics/pokemon/magikarp/front.4bpp.lz"

	.globl gMonPalette_Magikarp
gMonPalette_Magikarp: @ 0x8C895F8
	.incbin "graphics/pokemon/magikarp/normal.gbapal.lz"

	.globl gMonBackPic_Magikarp
gMonBackPic_Magikarp: @ 0x8C89620
	.incbin "graphics/pokemon/magikarp/back.4bpp.lz"

	.globl gMonShinyPalette_Magikarp
gMonShinyPalette_Magikarp: @ 0x8C89950
	.incbin "graphics/pokemon/magikarp/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc89978, 0x420

	.globl gMonStillFrontPic_Gyarados
gMonStillFrontPic_Gyarados: @ 0x8C89D98
	.incbin "graphics/pokemon/gyarados/front.4bpp.lz"

	.globl gMonPalette_Gyarados
gMonPalette_Gyarados: @ 0x8C8A300
	.incbin "graphics/pokemon/gyarados/normal.gbapal.lz"

	.globl gMonBackPic_Gyarados
gMonBackPic_Gyarados: @ 0x8C8A328
	.incbin "graphics/pokemon/gyarados/back.4bpp.lz"

	.globl gMonShinyPalette_Gyarados
gMonShinyPalette_Gyarados: @ 0x8C8A7FC
	.incbin "graphics/pokemon/gyarados/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8a824, 0x420

	.globl gMonStillFrontPic_Lapras
gMonStillFrontPic_Lapras: @ 0x8C8AC44
	.incbin "graphics/pokemon/lapras/front.4bpp.lz"

	.globl gMonPalette_Lapras
gMonPalette_Lapras: @ 0x8C8B004
	.incbin "graphics/pokemon/lapras/normal.gbapal.lz"

	.globl gMonBackPic_Lapras
gMonBackPic_Lapras: @ 0x8C8B02C
	.incbin "graphics/pokemon/lapras/back.4bpp.lz"

	.globl gMonShinyPalette_Lapras
gMonShinyPalette_Lapras: @ 0x8C8B370
	.incbin "graphics/pokemon/lapras/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8b398, 0x420

	.globl gMonStillFrontPic_Ditto
gMonStillFrontPic_Ditto: @ 0x8C8B7B8
	.incbin "graphics/pokemon/ditto/front.4bpp.lz"

	.globl gMonPalette_Ditto
gMonPalette_Ditto: @ 0x8C8B9A8
	.incbin "graphics/pokemon/ditto/normal.gbapal.lz"

	.globl gMonBackPic_Ditto
gMonBackPic_Ditto: @ 0x8C8B9C8
	.incbin "graphics/pokemon/ditto/back.4bpp.lz"

	.globl gMonShinyPalette_Ditto
gMonShinyPalette_Ditto: @ 0x8C8BBC8
	.incbin "graphics/pokemon/ditto/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8bbe5, 0x423

	.globl gMonStillFrontPic_Eevee
gMonStillFrontPic_Eevee: @ 0x8C8C008
	.incbin "graphics/pokemon/eevee/front.4bpp.lz"

	.globl gMonPalette_Eevee
gMonPalette_Eevee: @ 0x8C8C2AC
	.incbin "graphics/pokemon/eevee/normal.gbapal.lz"

	.globl gMonBackPic_Eevee
gMonBackPic_Eevee: @ 0x8C8C2D0
	.incbin "graphics/pokemon/eevee/back.4bpp.lz"

	.globl gMonShinyPalette_Eevee
gMonShinyPalette_Eevee: @ 0x8C8C5F8
	.incbin "graphics/pokemon/eevee/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8c61c, 0x420

	.globl gMonStillFrontPic_Vaporeon
gMonStillFrontPic_Vaporeon: @ 0x8C8CA3C
	.incbin "graphics/pokemon/vaporeon/front.4bpp.lz"

	.globl gMonPalette_Vaporeon
gMonPalette_Vaporeon: @ 0x8C8CDD0
	.incbin "graphics/pokemon/vaporeon/normal.gbapal.lz"

	.globl gMonBackPic_Vaporeon
gMonBackPic_Vaporeon: @ 0x8C8CDF8
	.incbin "graphics/pokemon/vaporeon/back.4bpp.lz"

	.globl gMonShinyPalette_Vaporeon
gMonShinyPalette_Vaporeon: @ 0x8C8D0C0
	.incbin "graphics/pokemon/vaporeon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8d0e8, 0x420

	.globl gMonStillFrontPic_Jolteon
gMonStillFrontPic_Jolteon: @ 0x8C8D508
	.incbin "graphics/pokemon/jolteon/front.4bpp.lz"

	.globl gMonPalette_Jolteon
gMonPalette_Jolteon: @ 0x8C8D8A8
	.incbin "graphics/pokemon/jolteon/normal.gbapal.lz"

	.globl gMonBackPic_Jolteon
gMonBackPic_Jolteon: @ 0x8C8D8D0
	.incbin "graphics/pokemon/jolteon/back.4bpp.lz"

	.globl gMonShinyPalette_Jolteon
gMonShinyPalette_Jolteon: @ 0x8C8DC60
	.incbin "graphics/pokemon/jolteon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8dc88, 0x420

	.globl gMonStillFrontPic_Flareon
gMonStillFrontPic_Flareon: @ 0x8C8E0A8
	.incbin "graphics/pokemon/flareon/front.4bpp.lz"

	.globl gMonPalette_Flareon
gMonPalette_Flareon: @ 0x8C8E424
	.incbin "graphics/pokemon/flareon/normal.gbapal.lz"

	.globl gMonBackPic_Flareon
gMonBackPic_Flareon: @ 0x8C8E44C
	.incbin "graphics/pokemon/flareon/back.4bpp.lz"

	.globl gMonShinyPalette_Flareon
gMonShinyPalette_Flareon: @ 0x8C8E7DC
	.incbin "graphics/pokemon/flareon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8e802, 0x422

	.globl gMonStillFrontPic_Porygon
gMonStillFrontPic_Porygon: @ 0x8C8EC24
	.incbin "graphics/pokemon/porygon/front.4bpp.lz"

	.globl gMonPalette_Porygon
gMonPalette_Porygon: @ 0x8C8EEE0
	.incbin "graphics/pokemon/porygon/normal.gbapal.lz"

	.globl gMonBackPic_Porygon
gMonBackPic_Porygon: @ 0x8C8EF04
	.incbin "graphics/pokemon/porygon/back.4bpp.lz"

	.globl gMonShinyPalette_Porygon
gMonShinyPalette_Porygon: @ 0x8C8F1BC
	.incbin "graphics/pokemon/porygon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8f1e0, 0x420

	.globl gMonStillFrontPic_Omanyte
gMonStillFrontPic_Omanyte: @ 0x8C8F600
	.incbin "graphics/pokemon/omanyte/front.4bpp.lz"

	.globl gMonPalette_Omanyte
gMonPalette_Omanyte: @ 0x8C8F8A8
	.incbin "graphics/pokemon/omanyte/normal.gbapal.lz"

	.globl gMonBackPic_Omanyte
gMonBackPic_Omanyte: @ 0x8C8F8D0
	.incbin "graphics/pokemon/omanyte/back.4bpp.lz"

	.globl gMonShinyPalette_Omanyte
gMonShinyPalette_Omanyte: @ 0x8C8FC1C
	.incbin "graphics/pokemon/omanyte/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc8fc44, 0x420

	.globl gMonStillFrontPic_Omastar
gMonStillFrontPic_Omastar: @ 0x8C90064
	.incbin "graphics/pokemon/omastar/front.4bpp.lz"

	.globl gMonPalette_Omastar
gMonPalette_Omastar: @ 0x8C90424
	.incbin "graphics/pokemon/omastar/normal.gbapal.lz"

	.globl gMonBackPic_Omastar
gMonBackPic_Omastar: @ 0x8C9044C
	.incbin "graphics/pokemon/omastar/back.4bpp.lz"

	.globl gMonShinyPalette_Omastar
gMonShinyPalette_Omastar: @ 0x8C9078C
	.incbin "graphics/pokemon/omastar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc907b4, 0x420

	.globl gMonStillFrontPic_Kabuto
gMonStillFrontPic_Kabuto: @ 0x8C90BD4
	.incbin "graphics/pokemon/kabuto/front.4bpp.lz"

	.globl gMonPalette_Kabuto
gMonPalette_Kabuto: @ 0x8C90E44
	.incbin "graphics/pokemon/kabuto/normal.gbapal.lz"

	.globl gMonBackPic_Kabuto
gMonBackPic_Kabuto: @ 0x8C90E6C
	.incbin "graphics/pokemon/kabuto/back.4bpp.lz"

	.globl gMonShinyPalette_Kabuto
gMonShinyPalette_Kabuto: @ 0x8C91104
	.incbin "graphics/pokemon/kabuto/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9112c, 0x420

	.globl gMonStillFrontPic_Kabutops
gMonStillFrontPic_Kabutops: @ 0x8C9154C
	.incbin "graphics/pokemon/kabutops/front.4bpp.lz"

	.globl gMonPalette_Kabutops
gMonPalette_Kabutops: @ 0x8C9194C
	.incbin "graphics/pokemon/kabutops/normal.gbapal.lz"

	.globl gMonBackPic_Kabutops
gMonBackPic_Kabutops: @ 0x8C91970
	.incbin "graphics/pokemon/kabutops/back.4bpp.lz"

	.globl gMonShinyPalette_Kabutops
gMonShinyPalette_Kabutops: @ 0x8C91D14
	.incbin "graphics/pokemon/kabutops/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc91d36, 0x422

	.globl gMonStillFrontPic_Aerodactyl
gMonStillFrontPic_Aerodactyl: @ 0x8C92158
	.incbin "graphics/pokemon/aerodactyl/front.4bpp.lz"

	.globl gMonPalette_Aerodactyl
gMonPalette_Aerodactyl: @ 0x8C925D8
	.incbin "graphics/pokemon/aerodactyl/normal.gbapal.lz"

	.globl gMonBackPic_Aerodactyl
gMonBackPic_Aerodactyl: @ 0x8C92600
	.incbin "graphics/pokemon/aerodactyl/back.4bpp.lz"

	.globl gMonShinyPalette_Aerodactyl
gMonShinyPalette_Aerodactyl: @ 0x8C92904
	.incbin "graphics/pokemon/aerodactyl/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9292a, 0x422

	.globl gMonStillFrontPic_Snorlax
gMonStillFrontPic_Snorlax: @ 0x8C92D4C
	.incbin "graphics/pokemon/snorlax/front.4bpp.lz"

	.globl gMonPalette_Snorlax
gMonPalette_Snorlax: @ 0x8C93190
	.incbin "graphics/pokemon/snorlax/normal.gbapal.lz"

	.globl gMonBackPic_Snorlax
gMonBackPic_Snorlax: @ 0x8C931B8
	.incbin "graphics/pokemon/snorlax/back.4bpp.lz"

	.globl gMonShinyPalette_Snorlax
gMonShinyPalette_Snorlax: @ 0x8C933D4
	.incbin "graphics/pokemon/snorlax/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc933fc, 0x420

	.globl gMonStillFrontPic_Articuno
gMonStillFrontPic_Articuno: @ 0x8C9381C
	.incbin "graphics/pokemon/articuno/front.4bpp.lz"

	.globl gMonPalette_Articuno
gMonPalette_Articuno: @ 0x8C93D14
	.incbin "graphics/pokemon/articuno/normal.gbapal.lz"

	.globl gMonBackPic_Articuno
gMonBackPic_Articuno: @ 0x8C93D3C
	.incbin "graphics/pokemon/articuno/back.4bpp.lz"

	.globl gMonShinyPalette_Articuno
gMonShinyPalette_Articuno: @ 0x8C93F98
	.incbin "graphics/pokemon/articuno/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc93fc0, 0x420

	.globl gMonStillFrontPic_Zapdos
gMonStillFrontPic_Zapdos: @ 0x8C943E0
	.incbin "graphics/pokemon/zapdos/front.4bpp.lz"

	.globl gMonPalette_Zapdos
gMonPalette_Zapdos: @ 0x8C94854
	.incbin "graphics/pokemon/zapdos/normal.gbapal.lz"

	.globl gMonBackPic_Zapdos
gMonBackPic_Zapdos: @ 0x8C9487C
	.incbin "graphics/pokemon/zapdos/back.4bpp.lz"

	.globl gMonShinyPalette_Zapdos
gMonShinyPalette_Zapdos: @ 0x8C94BB8
	.incbin "graphics/pokemon/zapdos/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc94be0, 0x420

	.globl gMonStillFrontPic_Moltres
gMonStillFrontPic_Moltres: @ 0x8C95000
	.incbin "graphics/pokemon/moltres/front.4bpp.lz"

	.globl gMonPalette_Moltres
gMonPalette_Moltres: @ 0x8C955B0
	.incbin "graphics/pokemon/moltres/normal.gbapal.lz"

	.globl gMonBackPic_Moltres
gMonBackPic_Moltres: @ 0x8C955D8
	.incbin "graphics/pokemon/moltres/back.4bpp.lz"

	.globl gMonShinyPalette_Moltres
gMonShinyPalette_Moltres: @ 0x8C95914
	.incbin "graphics/pokemon/moltres/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9593c, 0x420

	.globl gMonStillFrontPic_Dratini
gMonStillFrontPic_Dratini: @ 0x8C95D5C
	.incbin "graphics/pokemon/dratini/front.4bpp.lz"

	.globl gMonPalette_Dratini
gMonPalette_Dratini: @ 0x8C96014
	.incbin "graphics/pokemon/dratini/normal.gbapal.lz"

	.globl gMonBackPic_Dratini
gMonBackPic_Dratini: @ 0x8C96038
	.incbin "graphics/pokemon/dratini/back.4bpp.lz"

	.globl gMonShinyPalette_Dratini
gMonShinyPalette_Dratini: @ 0x8C962C8
	.incbin "graphics/pokemon/dratini/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc962ea, 0x422

	.globl gMonStillFrontPic_Dragonair
gMonStillFrontPic_Dragonair: @ 0x8C9670C
	.incbin "graphics/pokemon/dragonair/front.4bpp.lz"

	.globl gMonPalette_Dragonair
gMonPalette_Dragonair: @ 0x8C96A6C
	.incbin "graphics/pokemon/dragonair/normal.gbapal.lz"

	.globl gMonBackPic_Dragonair
gMonBackPic_Dragonair: @ 0x8C96A94
	.incbin "graphics/pokemon/dragonair/back.4bpp.lz"

	.globl gMonShinyPalette_Dragonair
gMonShinyPalette_Dragonair: @ 0x8C96DA4
	.incbin "graphics/pokemon/dragonair/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc96dcc, 0x420

	.globl gMonStillFrontPic_Dragonite
gMonStillFrontPic_Dragonite: @ 0x8C971EC
	.incbin "graphics/pokemon/dragonite/front.4bpp.lz"

	.globl gMonPalette_Dragonite
gMonPalette_Dragonite: @ 0x8C9775C
	.incbin "graphics/pokemon/dragonite/normal.gbapal.lz"

	.globl gMonBackPic_Dragonite
gMonBackPic_Dragonite: @ 0x8C97784
	.incbin "graphics/pokemon/dragonite/back.4bpp.lz"

	.globl gMonShinyPalette_Dragonite
gMonShinyPalette_Dragonite: @ 0x8C97A80
	.incbin "graphics/pokemon/dragonite/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc97aa8, 0x420

	.globl gMonStillFrontPic_Mewtwo
gMonStillFrontPic_Mewtwo: @ 0x8C97EC8
	.incbin "graphics/pokemon/mewtwo/front.4bpp.lz"

	.globl gMonPalette_Mewtwo
gMonPalette_Mewtwo: @ 0x8C98304
	.incbin "graphics/pokemon/mewtwo/normal.gbapal.lz"

	.globl gMonBackPic_Mewtwo
gMonBackPic_Mewtwo: @ 0x8C98328
	.incbin "graphics/pokemon/mewtwo/back.4bpp.lz"

	.globl gMonShinyPalette_Mewtwo
gMonShinyPalette_Mewtwo: @ 0x8C986F4
	.incbin "graphics/pokemon/mewtwo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc98716, 0x422

	.globl gMonStillFrontPic_Mew
gMonStillFrontPic_Mew: @ 0x8C98B38
	.incbin "graphics/pokemon/mew/front.4bpp.lz"

	.globl gMonPalette_Mew
gMonPalette_Mew: @ 0x8C98DB8
	.incbin "graphics/pokemon/mew/normal.gbapal.lz"

	.globl gMonBackPic_Mew
gMonBackPic_Mew: @ 0x8C98DDC
	.incbin "graphics/pokemon/mew/back.4bpp.lz"

	.globl gMonShinyPalette_Mew
gMonShinyPalette_Mew: @ 0x8C990A8
	.incbin "graphics/pokemon/mew/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc990ca, 0x422

	.globl gMonStillFrontPic_Chikorita
gMonStillFrontPic_Chikorita: @ 0x8C994EC
	.incbin "graphics/pokemon/chikorita/front.4bpp.lz"

	.globl gMonPalette_Chikorita
gMonPalette_Chikorita: @ 0x8C99754
	.incbin "graphics/pokemon/chikorita/normal.gbapal.lz"

	.globl gMonBackPic_Chikorita
gMonBackPic_Chikorita: @ 0x8C9977C
	.incbin "graphics/pokemon/chikorita/back.4bpp.lz"

	.globl gMonShinyPalette_Chikorita
gMonShinyPalette_Chikorita: @ 0x8C99A40
	.incbin "graphics/pokemon/chikorita/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc99a68, 0x420

	.globl gMonStillFrontPic_Bayleef
gMonStillFrontPic_Bayleef: @ 0x8C99E88
	.incbin "graphics/pokemon/bayleef/front.4bpp.lz"

	.globl gMonPalette_Bayleef
gMonPalette_Bayleef: @ 0x8C9A25C
	.incbin "graphics/pokemon/bayleef/normal.gbapal.lz"

	.globl gMonBackPic_Bayleef
gMonBackPic_Bayleef: @ 0x8C9A284
	.incbin "graphics/pokemon/bayleef/back.4bpp.lz"

	.globl gMonShinyPalette_Bayleef
gMonShinyPalette_Bayleef: @ 0x8C9A614
	.incbin "graphics/pokemon/bayleef/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9a63c, 0x420

	.globl gMonStillFrontPic_Meganium
gMonStillFrontPic_Meganium: @ 0x8C9AA5C
	.incbin "graphics/pokemon/meganium/front.4bpp.lz"

	.globl gMonPalette_Meganium
gMonPalette_Meganium: @ 0x8C9AFB8
	.incbin "graphics/pokemon/meganium/normal.gbapal.lz"

	.globl gMonBackPic_Meganium
gMonBackPic_Meganium: @ 0x8C9AFE0
	.incbin "graphics/pokemon/meganium/back.4bpp.lz"

	.globl gMonShinyPalette_Meganium
gMonShinyPalette_Meganium: @ 0x8C9B330
	.incbin "graphics/pokemon/meganium/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9b358, 0x420

	.globl gMonStillFrontPic_Cyndaquil
gMonStillFrontPic_Cyndaquil: @ 0x8C9B778
	.incbin "graphics/pokemon/cyndaquil/front.4bpp.lz"

	.globl gMonPalette_Cyndaquil
gMonPalette_Cyndaquil: @ 0x8C9BA04
	.incbin "graphics/pokemon/cyndaquil/normal.gbapal.lz"

	.globl gMonBackPic_Cyndaquil
gMonBackPic_Cyndaquil: @ 0x8C9BA2C
	.incbin "graphics/pokemon/cyndaquil/back.4bpp.lz"

	.globl gMonShinyPalette_Cyndaquil
gMonShinyPalette_Cyndaquil: @ 0x8C9BD58
	.incbin "graphics/pokemon/cyndaquil/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9bd80, 0x420

	.globl gMonStillFrontPic_Quilava
gMonStillFrontPic_Quilava: @ 0x8C9C1A0
	.incbin "graphics/pokemon/quilava/front.4bpp.lz"

	.globl gMonPalette_Quilava
gMonPalette_Quilava: @ 0x8C9C4BC
	.incbin "graphics/pokemon/quilava/normal.gbapal.lz"

	.globl gMonBackPic_Quilava
gMonBackPic_Quilava: @ 0x8C9C4E4
	.incbin "graphics/pokemon/quilava/back.4bpp.lz"

	.globl gMonShinyPalette_Quilava
gMonShinyPalette_Quilava: @ 0x8C9C858
	.incbin "graphics/pokemon/quilava/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9c880, 0x420

	.globl gMonStillFrontPic_Typhlosion
gMonStillFrontPic_Typhlosion: @ 0x8C9CCA0
	.incbin "graphics/pokemon/typhlosion/front.4bpp.lz"

	.globl gMonPalette_Typhlosion
gMonPalette_Typhlosion: @ 0x8C9D0C8
	.incbin "graphics/pokemon/typhlosion/normal.gbapal.lz"

	.globl gMonBackPic_Typhlosion
gMonBackPic_Typhlosion: @ 0x8C9D0F0
	.incbin "graphics/pokemon/typhlosion/back.4bpp.lz"

	.globl gMonShinyPalette_Typhlosion
gMonShinyPalette_Typhlosion: @ 0x8C9D4F4
	.incbin "graphics/pokemon/typhlosion/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9d51c, 0x420

	.globl gMonStillFrontPic_Totodile
gMonStillFrontPic_Totodile: @ 0x8C9D93C
	.incbin "graphics/pokemon/totodile/front.4bpp.lz"

	.globl gMonPalette_Totodile
gMonPalette_Totodile: @ 0x8C9DBE0
	.incbin "graphics/pokemon/totodile/normal.gbapal.lz"

	.globl gMonBackPic_Totodile
gMonBackPic_Totodile: @ 0x8C9DC08
	.incbin "graphics/pokemon/totodile/back.4bpp.lz"

	.globl gMonShinyPalette_Totodile
gMonShinyPalette_Totodile: @ 0x8C9DEE8
	.incbin "graphics/pokemon/totodile/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9df10, 0x420

	.globl gMonStillFrontPic_Croconaw
gMonStillFrontPic_Croconaw: @ 0x8C9E330
	.incbin "graphics/pokemon/croconaw/front.4bpp.lz"

	.globl gMonPalette_Croconaw
gMonPalette_Croconaw: @ 0x8C9E698
	.incbin "graphics/pokemon/croconaw/normal.gbapal.lz"

	.globl gMonBackPic_Croconaw
gMonBackPic_Croconaw: @ 0x8C9E6C0
	.incbin "graphics/pokemon/croconaw/back.4bpp.lz"

	.globl gMonShinyPalette_Croconaw
gMonShinyPalette_Croconaw: @ 0x8C9EA10
	.incbin "graphics/pokemon/croconaw/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9ea38, 0x420

	.globl gMonStillFrontPic_Feraligatr
gMonStillFrontPic_Feraligatr: @ 0x8C9EE58
	.incbin "graphics/pokemon/feraligatr/front.4bpp.lz"

	.globl gMonPalette_Feraligatr
gMonPalette_Feraligatr: @ 0x8C9F3C4
	.incbin "graphics/pokemon/feraligatr/normal.gbapal.lz"

	.globl gMonBackPic_Feraligatr
gMonBackPic_Feraligatr: @ 0x8C9F3EC
	.incbin "graphics/pokemon/feraligatr/back.4bpp.lz"

	.globl gMonShinyPalette_Feraligatr
gMonShinyPalette_Feraligatr: @ 0x8C9F8B8
	.incbin "graphics/pokemon/feraligatr/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xc9f8e0, 0x420

	.globl gMonStillFrontPic_Sentret
gMonStillFrontPic_Sentret: @ 0x8C9FD00
	.incbin "graphics/pokemon/sentret/front.4bpp.lz"

	.globl gMonPalette_Sentret
gMonPalette_Sentret: @ 0x8C9FFDC
	.incbin "graphics/pokemon/sentret/normal.gbapal.lz"

	.globl gMonBackPic_Sentret
gMonBackPic_Sentret: @ 0x8CA0004
	.incbin "graphics/pokemon/sentret/back.4bpp.lz"

	.globl gMonShinyPalette_Sentret
gMonShinyPalette_Sentret: @ 0x8CA02A8
	.incbin "graphics/pokemon/sentret/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca02d0, 0x420

	.globl gMonStillFrontPic_Furret
gMonStillFrontPic_Furret: @ 0x8CA06F0
	.incbin "graphics/pokemon/furret/front.4bpp.lz"

	.globl gMonPalette_Furret
gMonPalette_Furret: @ 0x8CA0A24
	.incbin "graphics/pokemon/furret/normal.gbapal.lz"

	.globl gMonBackPic_Furret
gMonBackPic_Furret: @ 0x8CA0A4C
	.incbin "graphics/pokemon/furret/back.4bpp.lz"

	.globl gMonShinyPalette_Furret
gMonShinyPalette_Furret: @ 0x8CA0D74
	.incbin "graphics/pokemon/furret/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca0d9c, 0x420

	.globl gMonStillFrontPic_Hoothoot
gMonStillFrontPic_Hoothoot: @ 0x8CA11BC
	.incbin "graphics/pokemon/hoothoot/front.4bpp.lz"

	.globl gMonPalette_Hoothoot
gMonPalette_Hoothoot: @ 0x8CA1440
	.incbin "graphics/pokemon/hoothoot/normal.gbapal.lz"

	.globl gMonBackPic_Hoothoot
gMonBackPic_Hoothoot: @ 0x8CA1468
	.incbin "graphics/pokemon/hoothoot/back.4bpp.lz"

	.globl gMonShinyPalette_Hoothoot
gMonShinyPalette_Hoothoot: @ 0x8CA1770
	.incbin "graphics/pokemon/hoothoot/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca1798, 0x420

	.globl gMonStillFrontPic_Noctowl
gMonStillFrontPic_Noctowl: @ 0x8CA1BB8
	.incbin "graphics/pokemon/noctowl/front.4bpp.lz"

	.globl gMonPalette_Noctowl
gMonPalette_Noctowl: @ 0x8CA1F0C
	.incbin "graphics/pokemon/noctowl/normal.gbapal.lz"

	.globl gMonBackPic_Noctowl
gMonBackPic_Noctowl: @ 0x8CA1F34
	.incbin "graphics/pokemon/noctowl/back.4bpp.lz"

	.globl gMonShinyPalette_Noctowl
gMonShinyPalette_Noctowl: @ 0x8CA2290
	.incbin "graphics/pokemon/noctowl/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca22b8, 0x420

	.globl gMonStillFrontPic_Ledyba
gMonStillFrontPic_Ledyba: @ 0x8CA26D8
	.incbin "graphics/pokemon/ledyba/front.4bpp.lz"

	.globl gMonPalette_Ledyba
gMonPalette_Ledyba: @ 0x8CA29CC
	.incbin "graphics/pokemon/ledyba/normal.gbapal.lz"

	.globl gMonBackPic_Ledyba
gMonBackPic_Ledyba: @ 0x8CA29F4
	.incbin "graphics/pokemon/ledyba/back.4bpp.lz"

	.globl gMonShinyPalette_Ledyba
gMonShinyPalette_Ledyba: @ 0x8CA2D24
	.incbin "graphics/pokemon/ledyba/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca2d4c, 0x420

	.globl gMonStillFrontPic_Ledian
gMonStillFrontPic_Ledian: @ 0x8CA316C
	.incbin "graphics/pokemon/ledian/front.4bpp.lz"

	.globl gMonPalette_Ledian
gMonPalette_Ledian: @ 0x8CA34F4
	.incbin "graphics/pokemon/ledian/normal.gbapal.lz"

	.globl gMonBackPic_Ledian
gMonBackPic_Ledian: @ 0x8CA351C
	.incbin "graphics/pokemon/ledian/back.4bpp.lz"

	.globl gMonShinyPalette_Ledian
gMonShinyPalette_Ledian: @ 0x8CA3874
	.incbin "graphics/pokemon/ledian/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca389c, 0x420

	.globl gMonStillFrontPic_Spinarak
gMonStillFrontPic_Spinarak: @ 0x8CA3CBC
	.incbin "graphics/pokemon/spinarak/front.4bpp.lz"

	.globl gMonPalette_Spinarak
gMonPalette_Spinarak: @ 0x8CA3F30
	.incbin "graphics/pokemon/spinarak/normal.gbapal.lz"

	.globl gMonBackPic_Spinarak
gMonBackPic_Spinarak: @ 0x8CA3F58
	.incbin "graphics/pokemon/spinarak/back.4bpp.lz"

	.globl gMonShinyPalette_Spinarak
gMonShinyPalette_Spinarak: @ 0x8CA41BC
	.incbin "graphics/pokemon/spinarak/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca41e4, 0x420

	.globl gMonStillFrontPic_Ariados
gMonStillFrontPic_Ariados: @ 0x8CA4604
	.incbin "graphics/pokemon/ariados/front.4bpp.lz"

	.globl gMonPalette_Ariados
gMonPalette_Ariados: @ 0x8CA49C4
	.incbin "graphics/pokemon/ariados/normal.gbapal.lz"

	.globl gMonBackPic_Ariados
gMonBackPic_Ariados: @ 0x8CA49EC
	.incbin "graphics/pokemon/ariados/back.4bpp.lz"

	.globl gMonShinyPalette_Ariados
gMonShinyPalette_Ariados: @ 0x8CA4D64
	.incbin "graphics/pokemon/ariados/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca4d8c, 0x420

	.globl gMonStillFrontPic_Crobat
gMonStillFrontPic_Crobat: @ 0x8CA51AC
	.incbin "graphics/pokemon/crobat/front.4bpp.lz"

	.globl gMonPalette_Crobat
gMonPalette_Crobat: @ 0x8CA555C
	.incbin "graphics/pokemon/crobat/normal.gbapal.lz"

	.globl gMonBackPic_Crobat
gMonBackPic_Crobat: @ 0x8CA5584
	.incbin "graphics/pokemon/crobat/back.4bpp.lz"

	.globl gMonShinyPalette_Crobat
gMonShinyPalette_Crobat: @ 0x8CA588C
	.incbin "graphics/pokemon/crobat/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca58b4, 0x420

	.globl gMonStillFrontPic_Chinchou
gMonStillFrontPic_Chinchou: @ 0x8CA5CD4
	.incbin "graphics/pokemon/chinchou/front.4bpp.lz"

	.globl gMonPalette_Chinchou
gMonPalette_Chinchou: @ 0x8CA5FAC
	.incbin "graphics/pokemon/chinchou/normal.gbapal.lz"

	.globl gMonBackPic_Chinchou
gMonBackPic_Chinchou: @ 0x8CA5FD4
	.incbin "graphics/pokemon/chinchou/back.4bpp.lz"

	.globl gMonShinyPalette_Chinchou
gMonShinyPalette_Chinchou: @ 0x8CA62CC
	.incbin "graphics/pokemon/chinchou/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca62f4, 0x420

	.globl gMonStillFrontPic_Lanturn
gMonStillFrontPic_Lanturn: @ 0x8CA6714
	.incbin "graphics/pokemon/lanturn/front.4bpp.lz"

	.globl gMonPalette_Lanturn
gMonPalette_Lanturn: @ 0x8CA6A84
	.incbin "graphics/pokemon/lanturn/normal.gbapal.lz"

	.globl gMonBackPic_Lanturn
gMonBackPic_Lanturn: @ 0x8CA6AAC
	.incbin "graphics/pokemon/lanturn/back.4bpp.lz"

	.globl gMonShinyPalette_Lanturn
gMonShinyPalette_Lanturn: @ 0x8CA6DAC
	.incbin "graphics/pokemon/lanturn/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca6dd4, 0x420

	.globl gMonStillFrontPic_Pichu
gMonStillFrontPic_Pichu: @ 0x8CA71F4
	.incbin "graphics/pokemon/pichu/front.4bpp.lz"

	.globl gMonPalette_Pichu
gMonPalette_Pichu: @ 0x8CA7410
	.incbin "graphics/pokemon/pichu/normal.gbapal.lz"

	.globl gMonBackPic_Pichu
gMonBackPic_Pichu: @ 0x8CA7438
	.incbin "graphics/pokemon/pichu/back.4bpp.lz"

	.globl gMonShinyPalette_Pichu
gMonShinyPalette_Pichu: @ 0x8CA7694
	.incbin "graphics/pokemon/pichu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca76bc, 0x420

	.globl gMonStillFrontPic_Cleffa
gMonStillFrontPic_Cleffa: @ 0x8CA7ADC
	.incbin "graphics/pokemon/cleffa/front.4bpp.lz"

	.globl gMonPalette_Cleffa
gMonPalette_Cleffa: @ 0x8CA7CBC
	.incbin "graphics/pokemon/cleffa/normal.gbapal.lz"

	.globl gMonBackPic_Cleffa
gMonBackPic_Cleffa: @ 0x8CA7CE4
	.incbin "graphics/pokemon/cleffa/back.4bpp.lz"

	.globl gMonShinyPalette_Cleffa
gMonShinyPalette_Cleffa: @ 0x8CA7F20
	.incbin "graphics/pokemon/cleffa/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca7f48, 0x420

	.globl gMonStillFrontPic_Igglybuff
gMonStillFrontPic_Igglybuff: @ 0x8CA8368
	.incbin "graphics/pokemon/igglybuff/front.4bpp.lz"

	.globl gMonPalette_Igglybuff
gMonPalette_Igglybuff: @ 0x8CA8550
	.incbin "graphics/pokemon/igglybuff/normal.gbapal.lz"

	.globl gMonBackPic_Igglybuff
gMonBackPic_Igglybuff: @ 0x8CA8578
	.incbin "graphics/pokemon/igglybuff/back.4bpp.lz"

	.globl gMonShinyPalette_Igglybuff
gMonShinyPalette_Igglybuff: @ 0x8CA87B4
	.incbin "graphics/pokemon/igglybuff/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca87dc, 0x420

	.globl gMonStillFrontPic_Togepi
gMonStillFrontPic_Togepi: @ 0x8CA8BFC
	.incbin "graphics/pokemon/togepi/front.4bpp.lz"

	.globl gMonPalette_Togepi
gMonPalette_Togepi: @ 0x8CA8DD0
	.incbin "graphics/pokemon/togepi/normal.gbapal.lz"

	.globl gMonBackPic_Togepi
gMonBackPic_Togepi: @ 0x8CA8DF8
	.incbin "graphics/pokemon/togepi/back.4bpp.lz"

	.globl gMonShinyPalette_Togepi
gMonShinyPalette_Togepi: @ 0x8CA906C
	.incbin "graphics/pokemon/togepi/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca9094, 0x420

	.globl gMonStillFrontPic_Togetic
gMonStillFrontPic_Togetic: @ 0x8CA94B4
	.incbin "graphics/pokemon/togetic/front.4bpp.lz"

	.globl gMonPalette_Togetic
gMonPalette_Togetic: @ 0x8CA9728
	.incbin "graphics/pokemon/togetic/normal.gbapal.lz"

	.globl gMonBackPic_Togetic
gMonBackPic_Togetic: @ 0x8CA9750
	.incbin "graphics/pokemon/togetic/back.4bpp.lz"

	.globl gMonShinyPalette_Togetic
gMonShinyPalette_Togetic: @ 0x8CA9A7C
	.incbin "graphics/pokemon/togetic/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xca9aa2, 0x422

	.globl gMonStillFrontPic_Natu
gMonStillFrontPic_Natu: @ 0x8CA9EC4
	.incbin "graphics/pokemon/natu/front.4bpp.lz"

	.globl gMonPalette_Natu
gMonPalette_Natu: @ 0x8CAA090
	.incbin "graphics/pokemon/natu/normal.gbapal.lz"

	.globl gMonBackPic_Natu
gMonBackPic_Natu: @ 0x8CAA0B8
	.incbin "graphics/pokemon/natu/back.4bpp.lz"

	.globl gMonShinyPalette_Natu
gMonShinyPalette_Natu: @ 0x8CAA2CC
	.incbin "graphics/pokemon/natu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcaa2f4, 0x420

	.globl gMonStillFrontPic_Xatu
gMonStillFrontPic_Xatu: @ 0x8CAA714
	.incbin "graphics/pokemon/xatu/front.4bpp.lz"

	.globl gMonPalette_Xatu
gMonPalette_Xatu: @ 0x8CAA9F0
	.incbin "graphics/pokemon/xatu/normal.gbapal.lz"

	.globl gMonBackPic_Xatu
gMonBackPic_Xatu: @ 0x8CAAA18
	.incbin "graphics/pokemon/xatu/back.4bpp.lz"

	.globl gMonShinyPalette_Xatu
gMonShinyPalette_Xatu: @ 0x8CAAD90
	.incbin "graphics/pokemon/xatu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcaadb8, 0x420

	.globl gMonStillFrontPic_Mareep
gMonStillFrontPic_Mareep: @ 0x8CAB1D8
	.incbin "graphics/pokemon/mareep/front.4bpp.lz"

	.globl gMonPalette_Mareep
gMonPalette_Mareep: @ 0x8CAB48C
	.incbin "graphics/pokemon/mareep/normal.gbapal.lz"

	.globl gMonBackPic_Mareep
gMonBackPic_Mareep: @ 0x8CAB4B4
	.incbin "graphics/pokemon/mareep/back.4bpp.lz"

	.globl gMonShinyPalette_Mareep
gMonShinyPalette_Mareep: @ 0x8CAB7A8
	.incbin "graphics/pokemon/mareep/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcab7d0, 0x420

	.globl gMonStillFrontPic_Flaaffy
gMonStillFrontPic_Flaaffy: @ 0x8CABBF0
	.incbin "graphics/pokemon/flaaffy/front.4bpp.lz"

	.globl gMonPalette_Flaaffy
gMonPalette_Flaaffy: @ 0x8CABEF0
	.incbin "graphics/pokemon/flaaffy/normal.gbapal.lz"

	.globl gMonBackPic_Flaaffy
gMonBackPic_Flaaffy: @ 0x8CABF18
	.incbin "graphics/pokemon/flaaffy/back.4bpp.lz"

	.globl gMonShinyPalette_Flaaffy
gMonShinyPalette_Flaaffy: @ 0x8CAC234
	.incbin "graphics/pokemon/flaaffy/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcac25c, 0x420

	.globl gMonStillFrontPic_Ampharos
gMonStillFrontPic_Ampharos: @ 0x8CAC67C
	.incbin "graphics/pokemon/ampharos/front.4bpp.lz"

	.globl gMonPalette_Ampharos
gMonPalette_Ampharos: @ 0x8CAC9D8
	.incbin "graphics/pokemon/ampharos/normal.gbapal.lz"

	.globl gMonBackPic_Ampharos
gMonBackPic_Ampharos: @ 0x8CACA00
	.incbin "graphics/pokemon/ampharos/back.4bpp.lz"

	.globl gMonShinyPalette_Ampharos
gMonShinyPalette_Ampharos: @ 0x8CACD78
	.incbin "graphics/pokemon/ampharos/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcacda0, 0x420

	.globl gMonStillFrontPic_Bellossom
gMonStillFrontPic_Bellossom: @ 0x8CAD1C0
	.incbin "graphics/pokemon/bellossom/front.4bpp.lz"

	.globl gMonPalette_Bellossom
gMonPalette_Bellossom: @ 0x8CAD430
	.incbin "graphics/pokemon/bellossom/normal.gbapal.lz"

	.globl gMonBackPic_Bellossom
gMonBackPic_Bellossom: @ 0x8CAD458
	.incbin "graphics/pokemon/bellossom/back.4bpp.lz"

	.globl gMonShinyPalette_Bellossom
gMonShinyPalette_Bellossom: @ 0x8CAD77C
	.incbin "graphics/pokemon/bellossom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcad7a4, 0x420

	.globl gMonStillFrontPic_Marill
gMonStillFrontPic_Marill: @ 0x8CADBC4
	.incbin "graphics/pokemon/marill/front.4bpp.lz"

	.globl gMonPalette_Marill
gMonPalette_Marill: @ 0x8CADE88
	.incbin "graphics/pokemon/marill/normal.gbapal.lz"

	.globl gMonBackPic_Marill
gMonBackPic_Marill: @ 0x8CADEB0
	.incbin "graphics/pokemon/marill/back.4bpp.lz"

	.globl gMonShinyPalette_Marill
gMonShinyPalette_Marill: @ 0x8CAE15C
	.incbin "graphics/pokemon/marill/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcae184, 0x420

	.globl gMonStillFrontPic_Azumarill
gMonStillFrontPic_Azumarill: @ 0x8CAE5A4
	.incbin "graphics/pokemon/azumarill/front.4bpp.lz"

	.globl gMonPalette_Azumarill
gMonPalette_Azumarill: @ 0x8CAE8A4
	.incbin "graphics/pokemon/azumarill/normal.gbapal.lz"

	.globl gMonBackPic_Azumarill
gMonBackPic_Azumarill: @ 0x8CAE8CC
	.incbin "graphics/pokemon/azumarill/back.4bpp.lz"

	.globl gMonShinyPalette_Azumarill
gMonShinyPalette_Azumarill: @ 0x8CAEB88
	.incbin "graphics/pokemon/azumarill/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcaebb0, 0x420

	.globl gMonStillFrontPic_Sudowoodo
gMonStillFrontPic_Sudowoodo: @ 0x8CAEFD0
	.incbin "graphics/pokemon/sudowoodo/front.4bpp.lz"

	.globl gMonPalette_Sudowoodo
gMonPalette_Sudowoodo: @ 0x8CAF2E8
	.incbin "graphics/pokemon/sudowoodo/normal.gbapal.lz"

	.globl gMonBackPic_Sudowoodo
gMonBackPic_Sudowoodo: @ 0x8CAF310
	.incbin "graphics/pokemon/sudowoodo/back.4bpp.lz"

	.globl gMonShinyPalette_Sudowoodo
gMonShinyPalette_Sudowoodo: @ 0x8CAF66C
	.incbin "graphics/pokemon/sudowoodo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcaf694, 0x420

	.globl gMonStillFrontPic_Politoed
gMonStillFrontPic_Politoed: @ 0x8CAFAB4
	.incbin "graphics/pokemon/politoed/front.4bpp.lz"

	.globl gMonPalette_Politoed
gMonPalette_Politoed: @ 0x8CAFDF0
	.incbin "graphics/pokemon/politoed/normal.gbapal.lz"

	.globl gMonBackPic_Politoed
gMonBackPic_Politoed: @ 0x8CAFE18
	.incbin "graphics/pokemon/politoed/back.4bpp.lz"

	.globl gMonShinyPalette_Politoed
gMonShinyPalette_Politoed: @ 0x8CB00D4
	.incbin "graphics/pokemon/politoed/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb00fc, 0x420

	.globl gMonStillFrontPic_Hoppip
gMonStillFrontPic_Hoppip: @ 0x8CB051C
	.incbin "graphics/pokemon/hoppip/front.4bpp.lz"

	.globl gMonPalette_Hoppip
gMonPalette_Hoppip: @ 0x8CB07D0
	.incbin "graphics/pokemon/hoppip/normal.gbapal.lz"

	.globl gMonBackPic_Hoppip
gMonBackPic_Hoppip: @ 0x8CB07F8
	.incbin "graphics/pokemon/hoppip/back.4bpp.lz"

	.globl gMonShinyPalette_Hoppip
gMonShinyPalette_Hoppip: @ 0x8CB0AD8
	.incbin "graphics/pokemon/hoppip/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb0aff, 0x421

	.globl gMonStillFrontPic_Skiploom
gMonStillFrontPic_Skiploom: @ 0x8CB0F20
	.incbin "graphics/pokemon/skiploom/front.4bpp.lz"

	.globl gMonPalette_Skiploom
gMonPalette_Skiploom: @ 0x8CB11A8
	.incbin "graphics/pokemon/skiploom/normal.gbapal.lz"

	.globl gMonBackPic_Skiploom
gMonBackPic_Skiploom: @ 0x8CB11D0
	.incbin "graphics/pokemon/skiploom/back.4bpp.lz"

	.globl gMonShinyPalette_Skiploom
gMonShinyPalette_Skiploom: @ 0x8CB14B0
	.incbin "graphics/pokemon/skiploom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb14d8, 0x420

	.globl gMonStillFrontPic_Jumpluff
gMonStillFrontPic_Jumpluff: @ 0x8CB18F8
	.incbin "graphics/pokemon/jumpluff/front.4bpp.lz"

	.globl gMonPalette_Jumpluff
gMonPalette_Jumpluff: @ 0x8CB1C64
	.incbin "graphics/pokemon/jumpluff/normal.gbapal.lz"

	.globl gMonBackPic_Jumpluff
gMonBackPic_Jumpluff: @ 0x8CB1C8C
	.incbin "graphics/pokemon/jumpluff/back.4bpp.lz"

	.globl gMonShinyPalette_Jumpluff
gMonShinyPalette_Jumpluff: @ 0x8CB2084
	.incbin "graphics/pokemon/jumpluff/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb20ac, 0x420

	.globl gMonStillFrontPic_Aipom
gMonStillFrontPic_Aipom: @ 0x8CB24CC
	.incbin "graphics/pokemon/aipom/front.4bpp.lz"

	.globl gMonPalette_Aipom
gMonPalette_Aipom: @ 0x8CB27C8
	.incbin "graphics/pokemon/aipom/normal.gbapal.lz"

	.globl gMonBackPic_Aipom
gMonBackPic_Aipom: @ 0x8CB27F0
	.incbin "graphics/pokemon/aipom/back.4bpp.lz"

	.globl gMonShinyPalette_Aipom
gMonShinyPalette_Aipom: @ 0x8CB2AE4
	.incbin "graphics/pokemon/aipom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb2b0c, 0x420

	.globl gMonStillFrontPic_Sunkern
gMonStillFrontPic_Sunkern: @ 0x8CB2F2C
	.incbin "graphics/pokemon/sunkern/front.4bpp.lz"

	.globl gMonPalette_Sunkern
gMonPalette_Sunkern: @ 0x8CB3164
	.incbin "graphics/pokemon/sunkern/normal.gbapal.lz"

	.globl gMonBackPic_Sunkern
gMonBackPic_Sunkern: @ 0x8CB318C
	.incbin "graphics/pokemon/sunkern/back.4bpp.lz"

	.globl gMonShinyPalette_Sunkern
gMonShinyPalette_Sunkern: @ 0x8CB3450
	.incbin "graphics/pokemon/sunkern/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb3478, 0x420

	.globl gMonStillFrontPic_Sunflora
gMonStillFrontPic_Sunflora: @ 0x8CB3898
	.incbin "graphics/pokemon/sunflora/front.4bpp.lz"

	.globl gMonPalette_Sunflora
gMonPalette_Sunflora: @ 0x8CB3BF0
	.incbin "graphics/pokemon/sunflora/normal.gbapal.lz"

	.globl gMonBackPic_Sunflora
gMonBackPic_Sunflora: @ 0x8CB3C18
	.incbin "graphics/pokemon/sunflora/back.4bpp.lz"

	.globl gMonShinyPalette_Sunflora
gMonShinyPalette_Sunflora: @ 0x8CB3FB8
	.incbin "graphics/pokemon/sunflora/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb3fe0, 0x420

	.globl gMonStillFrontPic_Yanma
gMonStillFrontPic_Yanma: @ 0x8CB4400
	.incbin "graphics/pokemon/yanma/front.4bpp.lz"

	.globl gMonPalette_Yanma
gMonPalette_Yanma: @ 0x8CB4784
	.incbin "graphics/pokemon/yanma/normal.gbapal.lz"

	.globl gMonBackPic_Yanma
gMonBackPic_Yanma: @ 0x8CB47AC
	.incbin "graphics/pokemon/yanma/back.4bpp.lz"

	.globl gMonShinyPalette_Yanma
gMonShinyPalette_Yanma: @ 0x8CB4B60
	.incbin "graphics/pokemon/yanma/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb4b88, 0x420

	.globl gMonStillFrontPic_Wooper
gMonStillFrontPic_Wooper: @ 0x8CB4FA8
	.incbin "graphics/pokemon/wooper/front.4bpp.lz"

	.globl gMonPalette_Wooper
gMonPalette_Wooper: @ 0x8CB51E8
	.incbin "graphics/pokemon/wooper/normal.gbapal.lz"

	.globl gMonBackPic_Wooper
gMonBackPic_Wooper: @ 0x8CB5210
	.incbin "graphics/pokemon/wooper/back.4bpp.lz"

	.globl gMonShinyPalette_Wooper
gMonShinyPalette_Wooper: @ 0x8CB549C
	.incbin "graphics/pokemon/wooper/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb54c2, 0x422

	.globl gMonStillFrontPic_Quagsire
gMonStillFrontPic_Quagsire: @ 0x8CB58E4
	.incbin "graphics/pokemon/quagsire/front.4bpp.lz"

	.globl gMonPalette_Quagsire
gMonPalette_Quagsire: @ 0x8CB5C58
	.incbin "graphics/pokemon/quagsire/normal.gbapal.lz"

	.globl gMonBackPic_Quagsire
gMonBackPic_Quagsire: @ 0x8CB5C80
	.incbin "graphics/pokemon/quagsire/back.4bpp.lz"

	.globl gMonShinyPalette_Quagsire
gMonShinyPalette_Quagsire: @ 0x8CB5F7C
	.incbin "graphics/pokemon/quagsire/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb5fa4, 0x420

	.globl gMonStillFrontPic_Espeon
gMonStillFrontPic_Espeon: @ 0x8CB63C4
	.incbin "graphics/pokemon/espeon/front.4bpp.lz"

	.globl gMonPalette_Espeon
gMonPalette_Espeon: @ 0x8CB6704
	.incbin "graphics/pokemon/espeon/normal.gbapal.lz"

	.globl gMonBackPic_Espeon
gMonBackPic_Espeon: @ 0x8CB6728
	.incbin "graphics/pokemon/espeon/back.4bpp.lz"

	.globl gMonShinyPalette_Espeon
gMonShinyPalette_Espeon: @ 0x8CB6A04
	.incbin "graphics/pokemon/espeon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb6a28, 0x420

	.globl gMonStillFrontPic_Umbreon
gMonStillFrontPic_Umbreon: @ 0x8CB6E48
	.incbin "graphics/pokemon/umbreon/front.4bpp.lz"

	.globl gMonPalette_Umbreon
gMonPalette_Umbreon: @ 0x8CB715C
	.incbin "graphics/pokemon/umbreon/normal.gbapal.lz"

	.globl gMonBackPic_Umbreon
gMonBackPic_Umbreon: @ 0x8CB7184
	.incbin "graphics/pokemon/umbreon/back.4bpp.lz"

	.globl gMonShinyPalette_Umbreon
gMonShinyPalette_Umbreon: @ 0x8CB7498
	.incbin "graphics/pokemon/umbreon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb74c0, 0x420

	.globl gMonStillFrontPic_Murkrow
gMonStillFrontPic_Murkrow: @ 0x8CB78E0
	.incbin "graphics/pokemon/murkrow/front.4bpp.lz"

	.globl gMonPalette_Murkrow
gMonPalette_Murkrow: @ 0x8CB7BC0
	.incbin "graphics/pokemon/murkrow/normal.gbapal.lz"

	.globl gMonBackPic_Murkrow
gMonBackPic_Murkrow: @ 0x8CB7BE8
	.incbin "graphics/pokemon/murkrow/back.4bpp.lz"

	.globl gMonShinyPalette_Murkrow
gMonShinyPalette_Murkrow: @ 0x8CB7F00
	.incbin "graphics/pokemon/murkrow/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb7f28, 0x420

	.globl gMonStillFrontPic_Slowking
gMonStillFrontPic_Slowking: @ 0x8CB8348
	.incbin "graphics/pokemon/slowking/front.4bpp.lz"

	.globl gMonPalette_Slowking
gMonPalette_Slowking: @ 0x8CB86FC
	.incbin "graphics/pokemon/slowking/normal.gbapal.lz"

	.globl gMonBackPic_Slowking
gMonBackPic_Slowking: @ 0x8CB8724
	.incbin "graphics/pokemon/slowking/back.4bpp.lz"

	.globl gMonShinyPalette_Slowking
gMonShinyPalette_Slowking: @ 0x8CB8AB0
	.incbin "graphics/pokemon/slowking/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb8ad8, 0x420

	.globl gMonStillFrontPic_Misdreavus
gMonStillFrontPic_Misdreavus: @ 0x8CB8EF8
	.incbin "graphics/pokemon/misdreavus/front.4bpp.lz"

	.globl gMonPalette_Misdreavus
gMonPalette_Misdreavus: @ 0x8CB91B8
	.incbin "graphics/pokemon/misdreavus/normal.gbapal.lz"

	.globl gMonBackPic_Misdreavus
gMonBackPic_Misdreavus: @ 0x8CB91E0
	.incbin "graphics/pokemon/misdreavus/back.4bpp.lz"

	.globl gMonShinyPalette_Misdreavus
gMonShinyPalette_Misdreavus: @ 0x8CB9504
	.incbin "graphics/pokemon/misdreavus/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb952c, 0x420

	.globl gMonStillFrontPic_UnownA
gMonStillFrontPic_UnownA: @ 0x8CB994C
	.incbin "graphics/pokemon/unown/a/front.4bpp.lz"

	.globl gMonPalette_Unown
gMonPalette_Unown: @ 0x8CB9B20
	.incbin "graphics/pokemon/unown/normal.gbapal.lz"

	.globl gMonBackPic_UnownA
gMonBackPic_UnownA: @ 0x8CB9B40
	.incbin "graphics/pokemon/unown/a/back.4bpp.lz"

	.globl gMonShinyPalette_Unown
gMonShinyPalette_Unown: @ 0x8CB9D40
	.incbin "graphics/pokemon/unown/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcb9d5d, 0x423

	.globl gMonStillFrontPic_Wobbuffet
gMonStillFrontPic_Wobbuffet: @ 0x8CBA180
	.incbin "graphics/pokemon/wobbuffet/front.4bpp.lz"

	.globl gMonPalette_Wobbuffet
gMonPalette_Wobbuffet: @ 0x8CBA4D0
	.incbin "graphics/pokemon/wobbuffet/normal.gbapal.lz"

	.globl gMonBackPic_Wobbuffet
gMonBackPic_Wobbuffet: @ 0x8CBA4F8
	.incbin "graphics/pokemon/wobbuffet/back.4bpp.lz"

	.globl gMonShinyPalette_Wobbuffet
gMonShinyPalette_Wobbuffet: @ 0x8CBA73C
	.incbin "graphics/pokemon/wobbuffet/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcba764, 0x420

	.globl gMonStillFrontPic_Girafarig
gMonStillFrontPic_Girafarig: @ 0x8CBAB84
	.incbin "graphics/pokemon/girafarig/front.4bpp.lz"

	.globl gMonPalette_Girafarig
gMonPalette_Girafarig: @ 0x8CBAF88
	.incbin "graphics/pokemon/girafarig/normal.gbapal.lz"

	.globl gMonBackPic_Girafarig
gMonBackPic_Girafarig: @ 0x8CBAFB0
	.incbin "graphics/pokemon/girafarig/back.4bpp.lz"

	.globl gMonShinyPalette_Girafarig
gMonShinyPalette_Girafarig: @ 0x8CBB35C
	.incbin "graphics/pokemon/girafarig/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbb384, 0x420

	.globl gMonStillFrontPic_Pineco
gMonStillFrontPic_Pineco: @ 0x8CBB7A4
	.incbin "graphics/pokemon/pineco/front.4bpp.lz"

	.globl gMonPalette_Pineco
gMonPalette_Pineco: @ 0x8CBBAE4
	.incbin "graphics/pokemon/pineco/normal.gbapal.lz"

	.globl gMonBackPic_Pineco
gMonBackPic_Pineco: @ 0x8CBBB08
	.incbin "graphics/pokemon/pineco/back.4bpp.lz"

	.globl gMonShinyPalette_Pineco
gMonShinyPalette_Pineco: @ 0x8CBBDE0
	.incbin "graphics/pokemon/pineco/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbbe01, 0x423

	.globl gMonStillFrontPic_Forretress
gMonStillFrontPic_Forretress: @ 0x8CBC224
	.incbin "graphics/pokemon/forretress/front.4bpp.lz"

	.globl gMonPalette_Forretress
gMonPalette_Forretress: @ 0x8CBC640
	.incbin "graphics/pokemon/forretress/normal.gbapal.lz"

	.globl gMonBackPic_Forretress
gMonBackPic_Forretress: @ 0x8CBC668
	.incbin "graphics/pokemon/forretress/back.4bpp.lz"

	.globl gMonShinyPalette_Forretress
gMonShinyPalette_Forretress: @ 0x8CBC928
	.incbin "graphics/pokemon/forretress/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbc950, 0x420

	.globl gMonStillFrontPic_Dunsparce
gMonStillFrontPic_Dunsparce: @ 0x8CBCD70
	.incbin "graphics/pokemon/dunsparce/front.4bpp.lz"

	.globl gMonPalette_Dunsparce
gMonPalette_Dunsparce: @ 0x8CBD080
	.incbin "graphics/pokemon/dunsparce/normal.gbapal.lz"

	.globl gMonBackPic_Dunsparce
gMonBackPic_Dunsparce: @ 0x8CBD0A8
	.incbin "graphics/pokemon/dunsparce/back.4bpp.lz"

	.globl gMonShinyPalette_Dunsparce
gMonShinyPalette_Dunsparce: @ 0x8CBD3A4
	.incbin "graphics/pokemon/dunsparce/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbd3cc, 0x420

	.globl gMonStillFrontPic_Gligar
gMonStillFrontPic_Gligar: @ 0x8CBD7EC
	.incbin "graphics/pokemon/gligar/front.4bpp.lz"

	.globl gMonPalette_Gligar
gMonPalette_Gligar: @ 0x8CBDC14
	.incbin "graphics/pokemon/gligar/normal.gbapal.lz"

	.globl gMonBackPic_Gligar
gMonBackPic_Gligar: @ 0x8CBDC3C
	.incbin "graphics/pokemon/gligar/back.4bpp.lz"

	.globl gMonShinyPalette_Gligar
gMonShinyPalette_Gligar: @ 0x8CBE014
	.incbin "graphics/pokemon/gligar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbe03c, 0x420

	.globl gMonStillFrontPic_Steelix
gMonStillFrontPic_Steelix: @ 0x8CBE45C
	.incbin "graphics/pokemon/steelix/front.4bpp.lz"

	.globl gMonPalette_Steelix
gMonPalette_Steelix: @ 0x8CBE924
	.incbin "graphics/pokemon/steelix/normal.gbapal.lz"

	.globl gMonBackPic_Steelix
gMonBackPic_Steelix: @ 0x8CBE948
	.incbin "graphics/pokemon/steelix/back.4bpp.lz"

	.globl gMonShinyPalette_Steelix
gMonShinyPalette_Steelix: @ 0x8CBED54
	.incbin "graphics/pokemon/steelix/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbed75, 0x423

	.globl gMonStillFrontPic_Snubbull
gMonStillFrontPic_Snubbull: @ 0x8CBF198
	.incbin "graphics/pokemon/snubbull/front.4bpp.lz"

	.globl gMonPalette_Snubbull
gMonPalette_Snubbull: @ 0x8CBF46C
	.incbin "graphics/pokemon/snubbull/normal.gbapal.lz"

	.globl gMonBackPic_Snubbull
gMonBackPic_Snubbull: @ 0x8CBF494
	.incbin "graphics/pokemon/snubbull/back.4bpp.lz"

	.globl gMonShinyPalette_Snubbull
gMonShinyPalette_Snubbull: @ 0x8CBF7BC
	.incbin "graphics/pokemon/snubbull/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcbf7e4, 0x420

	.globl gMonStillFrontPic_Granbull
gMonStillFrontPic_Granbull: @ 0x8CBFC04
	.incbin "graphics/pokemon/granbull/front.4bpp.lz"

	.globl gMonPalette_Granbull
gMonPalette_Granbull: @ 0x8CBFF90
	.incbin "graphics/pokemon/granbull/normal.gbapal.lz"

	.globl gMonBackPic_Granbull
gMonBackPic_Granbull: @ 0x8CBFFB8
	.incbin "graphics/pokemon/granbull/back.4bpp.lz"

	.globl gMonShinyPalette_Granbull
gMonShinyPalette_Granbull: @ 0x8CC02DC
	.incbin "graphics/pokemon/granbull/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc0304, 0x420

	.globl gMonStillFrontPic_Qwilfish
gMonStillFrontPic_Qwilfish: @ 0x8CC0724
	.incbin "graphics/pokemon/qwilfish/front.4bpp.lz"

	.globl gMonPalette_Qwilfish
gMonPalette_Qwilfish: @ 0x8CC09E4
	.incbin "graphics/pokemon/qwilfish/normal.gbapal.lz"

	.globl gMonBackPic_Qwilfish
gMonBackPic_Qwilfish: @ 0x8CC0A0C
	.incbin "graphics/pokemon/qwilfish/back.4bpp.lz"

	.globl gMonShinyPalette_Qwilfish
gMonShinyPalette_Qwilfish: @ 0x8CC0CEC
	.incbin "graphics/pokemon/qwilfish/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc0d14, 0x420

	.globl gMonStillFrontPic_Scizor
gMonStillFrontPic_Scizor: @ 0x8CC1134
	.incbin "graphics/pokemon/scizor/front.4bpp.lz"

	.globl gMonPalette_Scizor
gMonPalette_Scizor: @ 0x8CC161C
	.incbin "graphics/pokemon/scizor/normal.gbapal.lz"

	.globl gMonBackPic_Scizor
gMonBackPic_Scizor: @ 0x8CC1644
	.incbin "graphics/pokemon/scizor/back.4bpp.lz"

	.globl gMonShinyPalette_Scizor
gMonShinyPalette_Scizor: @ 0x8CC19C4
	.incbin "graphics/pokemon/scizor/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc19ec, 0x420

	.globl gMonStillFrontPic_Shuckle
gMonStillFrontPic_Shuckle: @ 0x8CC1E0C
	.incbin "graphics/pokemon/shuckle/front.4bpp.lz"

	.globl gMonPalette_Shuckle
gMonPalette_Shuckle: @ 0x8CC20D4
	.incbin "graphics/pokemon/shuckle/normal.gbapal.lz"

	.globl gMonBackPic_Shuckle
gMonBackPic_Shuckle: @ 0x8CC20FC
	.incbin "graphics/pokemon/shuckle/back.4bpp.lz"

	.globl gMonShinyPalette_Shuckle
gMonShinyPalette_Shuckle: @ 0x8CC2354
	.incbin "graphics/pokemon/shuckle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc237c, 0x420

	.globl gMonStillFrontPic_Heracross
gMonStillFrontPic_Heracross: @ 0x8CC279C
	.incbin "graphics/pokemon/heracross/front.4bpp.lz"

	.globl gMonPalette_Heracross
gMonPalette_Heracross: @ 0x8CC2B8C
	.incbin "graphics/pokemon/heracross/normal.gbapal.lz"

	.globl gMonBackPic_Heracross
gMonBackPic_Heracross: @ 0x8CC2BB4
	.incbin "graphics/pokemon/heracross/back.4bpp.lz"

	.globl gMonShinyPalette_Heracross
gMonShinyPalette_Heracross: @ 0x8CC2F24
	.incbin "graphics/pokemon/heracross/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc2f4c, 0x420

	.globl gMonStillFrontPic_Sneasel
gMonStillFrontPic_Sneasel: @ 0x8CC336C
	.incbin "graphics/pokemon/sneasel/front.4bpp.lz"

	.globl gMonPalette_Sneasel
gMonPalette_Sneasel: @ 0x8CC36B0
	.incbin "graphics/pokemon/sneasel/normal.gbapal.lz"

	.globl gMonBackPic_Sneasel
gMonBackPic_Sneasel: @ 0x8CC36D8
	.incbin "graphics/pokemon/sneasel/back.4bpp.lz"

	.globl gMonShinyPalette_Sneasel
gMonShinyPalette_Sneasel: @ 0x8CC39FC
	.incbin "graphics/pokemon/sneasel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc3a24, 0x420

	.globl gMonStillFrontPic_Teddiursa
gMonStillFrontPic_Teddiursa: @ 0x8CC3E44
	.incbin "graphics/pokemon/teddiursa/front.4bpp.lz"

	.globl gMonPalette_Teddiursa
gMonPalette_Teddiursa: @ 0x8CC40B0
	.incbin "graphics/pokemon/teddiursa/normal.gbapal.lz"

	.globl gMonBackPic_Teddiursa
gMonBackPic_Teddiursa: @ 0x8CC40D8
	.incbin "graphics/pokemon/teddiursa/back.4bpp.lz"

	.globl gMonShinyPalette_Teddiursa
gMonShinyPalette_Teddiursa: @ 0x8CC4350
	.incbin "graphics/pokemon/teddiursa/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc4378, 0x420

	.globl gMonStillFrontPic_Ursaring
gMonStillFrontPic_Ursaring: @ 0x8CC4798
	.incbin "graphics/pokemon/ursaring/front.4bpp.lz"

	.globl gMonPalette_Ursaring
gMonPalette_Ursaring: @ 0x8CC4BD0
	.incbin "graphics/pokemon/ursaring/normal.gbapal.lz"

	.globl gMonBackPic_Ursaring
gMonBackPic_Ursaring: @ 0x8CC4BF8
	.incbin "graphics/pokemon/ursaring/back.4bpp.lz"

	.globl gMonShinyPalette_Ursaring
gMonShinyPalette_Ursaring: @ 0x8CC4F80
	.incbin "graphics/pokemon/ursaring/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc4fa8, 0x420

	.globl gMonStillFrontPic_Slugma
gMonStillFrontPic_Slugma: @ 0x8CC53C8
	.incbin "graphics/pokemon/slugma/front.4bpp.lz"

	.globl gMonPalette_Slugma
gMonPalette_Slugma: @ 0x8CC563C
	.incbin "graphics/pokemon/slugma/normal.gbapal.lz"

	.globl gMonBackPic_Slugma
gMonBackPic_Slugma: @ 0x8CC5660
	.incbin "graphics/pokemon/slugma/back.4bpp.lz"

	.globl gMonShinyPalette_Slugma
gMonShinyPalette_Slugma: @ 0x8CC5948
	.incbin "graphics/pokemon/slugma/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc596c, 0x420

	.globl gMonStillFrontPic_Magcargo
gMonStillFrontPic_Magcargo: @ 0x8CC5D8C
	.incbin "graphics/pokemon/magcargo/front.4bpp.lz"

	.globl gMonPalette_Magcargo
gMonPalette_Magcargo: @ 0x8CC60D4
	.incbin "graphics/pokemon/magcargo/normal.gbapal.lz"

	.globl gMonBackPic_Magcargo
gMonBackPic_Magcargo: @ 0x8CC60FC
	.incbin "graphics/pokemon/magcargo/back.4bpp.lz"

	.globl gMonShinyPalette_Magcargo
gMonShinyPalette_Magcargo: @ 0x8CC6514
	.incbin "graphics/pokemon/magcargo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc653c, 0x420

	.globl gMonStillFrontPic_Swinub
gMonStillFrontPic_Swinub: @ 0x8CC695C
	.incbin "graphics/pokemon/swinub/front.4bpp.lz"

	.globl gMonPalette_Swinub
gMonPalette_Swinub: @ 0x8CC6B58
	.incbin "graphics/pokemon/swinub/normal.gbapal.lz"

	.globl gMonBackPic_Swinub
gMonBackPic_Swinub: @ 0x8CC6B80
	.incbin "graphics/pokemon/swinub/back.4bpp.lz"

	.globl gMonShinyPalette_Swinub
gMonShinyPalette_Swinub: @ 0x8CC6DBC
	.incbin "graphics/pokemon/swinub/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc6de4, 0x420

	.globl gMonStillFrontPic_Piloswine
gMonStillFrontPic_Piloswine: @ 0x8CC7204
	.incbin "graphics/pokemon/piloswine/front.4bpp.lz"

	.globl gMonPalette_Piloswine
gMonPalette_Piloswine: @ 0x8CC752C
	.incbin "graphics/pokemon/piloswine/normal.gbapal.lz"

	.globl gMonBackPic_Piloswine
gMonBackPic_Piloswine: @ 0x8CC7554
	.incbin "graphics/pokemon/piloswine/back.4bpp.lz"

	.globl gMonShinyPalette_Piloswine
gMonShinyPalette_Piloswine: @ 0x8CC77A0
	.incbin "graphics/pokemon/piloswine/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc77c8, 0x420

	.globl gMonStillFrontPic_Corsola
gMonStillFrontPic_Corsola: @ 0x8CC7BE8
	.incbin "graphics/pokemon/corsola/front.4bpp.lz"

	.globl gMonPalette_Corsola
gMonPalette_Corsola: @ 0x8CC7ED0
	.incbin "graphics/pokemon/corsola/normal.gbapal.lz"

	.globl gMonBackPic_Corsola
gMonBackPic_Corsola: @ 0x8CC7EF8
	.incbin "graphics/pokemon/corsola/back.4bpp.lz"

	.globl gMonShinyPalette_Corsola
gMonShinyPalette_Corsola: @ 0x8CC81B8
	.incbin "graphics/pokemon/corsola/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc81de, 0x422

	.globl gMonStillFrontPic_Remoraid
gMonStillFrontPic_Remoraid: @ 0x8CC8600
	.incbin "graphics/pokemon/remoraid/front.4bpp.lz"

	.globl gMonPalette_Remoraid
gMonPalette_Remoraid: @ 0x8CC8868
	.incbin "graphics/pokemon/remoraid/normal.gbapal.lz"

	.globl gMonBackPic_Remoraid
gMonBackPic_Remoraid: @ 0x8CC8890
	.incbin "graphics/pokemon/remoraid/back.4bpp.lz"

	.globl gMonShinyPalette_Remoraid
gMonShinyPalette_Remoraid: @ 0x8CC8BA4
	.incbin "graphics/pokemon/remoraid/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc8bca, 0x422

	.globl gMonStillFrontPic_Octillery
gMonStillFrontPic_Octillery: @ 0x8CC8FEC
	.incbin "graphics/pokemon/octillery/front.4bpp.lz"

	.globl gMonPalette_Octillery
gMonPalette_Octillery: @ 0x8CC9320
	.incbin "graphics/pokemon/octillery/normal.gbapal.lz"

	.globl gMonBackPic_Octillery
gMonBackPic_Octillery: @ 0x8CC9348
	.incbin "graphics/pokemon/octillery/back.4bpp.lz"

	.globl gMonShinyPalette_Octillery
gMonShinyPalette_Octillery: @ 0x8CC9600
	.incbin "graphics/pokemon/octillery/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcc9628, 0x420

	.globl gMonStillFrontPic_Delibird
gMonStillFrontPic_Delibird: @ 0x8CC9A48
	.incbin "graphics/pokemon/delibird/front.4bpp.lz"

	.globl gMonPalette_Delibird
gMonPalette_Delibird: @ 0x8CC9DB8
	.incbin "graphics/pokemon/delibird/normal.gbapal.lz"

	.globl gMonBackPic_Delibird
gMonBackPic_Delibird: @ 0x8CC9DE0
	.incbin "graphics/pokemon/delibird/back.4bpp.lz"

	.globl gMonShinyPalette_Delibird
gMonShinyPalette_Delibird: @ 0x8CCA1A0
	.incbin "graphics/pokemon/delibird/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcca1c8, 0x420

	.globl gMonStillFrontPic_Mantine
gMonStillFrontPic_Mantine: @ 0x8CCA5E8
	.incbin "graphics/pokemon/mantine/front.4bpp.lz"

	.globl gMonPalette_Mantine
gMonPalette_Mantine: @ 0x8CCAA84
	.incbin "graphics/pokemon/mantine/normal.gbapal.lz"

	.globl gMonBackPic_Mantine
gMonBackPic_Mantine: @ 0x8CCAAAC
	.incbin "graphics/pokemon/mantine/back.4bpp.lz"

	.globl gMonShinyPalette_Mantine
gMonShinyPalette_Mantine: @ 0x8CCAD4C
	.incbin "graphics/pokemon/mantine/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccad74, 0x420

	.globl gMonStillFrontPic_Skarmory
gMonStillFrontPic_Skarmory: @ 0x8CCB194
	.incbin "graphics/pokemon/skarmory/front.4bpp.lz"

	.globl gMonPalette_Skarmory
gMonPalette_Skarmory: @ 0x8CCB674
	.incbin "graphics/pokemon/skarmory/normal.gbapal.lz"

	.globl gMonBackPic_Skarmory
gMonBackPic_Skarmory: @ 0x8CCB69C
	.incbin "graphics/pokemon/skarmory/back.4bpp.lz"

	.globl gMonShinyPalette_Skarmory
gMonShinyPalette_Skarmory: @ 0x8CCB9A0
	.incbin "graphics/pokemon/skarmory/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccb9c8, 0x420

	.globl gMonStillFrontPic_Houndour
gMonStillFrontPic_Houndour: @ 0x8CCBDE8
	.incbin "graphics/pokemon/houndour/front.4bpp.lz"

	.globl gMonPalette_Houndour
gMonPalette_Houndour: @ 0x8CCC0A0
	.incbin "graphics/pokemon/houndour/normal.gbapal.lz"

	.globl gMonBackPic_Houndour
gMonBackPic_Houndour: @ 0x8CCC0C8
	.incbin "graphics/pokemon/houndour/back.4bpp.lz"

	.globl gMonShinyPalette_Houndour
gMonShinyPalette_Houndour: @ 0x8CCC348
	.incbin "graphics/pokemon/houndour/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccc370, 0x420

	.globl gMonStillFrontPic_Houndoom
gMonStillFrontPic_Houndoom: @ 0x8CCC790
	.incbin "graphics/pokemon/houndoom/front.4bpp.lz"

	.globl gMonPalette_Houndoom
gMonPalette_Houndoom: @ 0x8CCCB90
	.incbin "graphics/pokemon/houndoom/normal.gbapal.lz"

	.globl gMonBackPic_Houndoom
gMonBackPic_Houndoom: @ 0x8CCCBB8
	.incbin "graphics/pokemon/houndoom/back.4bpp.lz"

	.globl gMonShinyPalette_Houndoom
gMonShinyPalette_Houndoom: @ 0x8CCCEDC
	.incbin "graphics/pokemon/houndoom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcccf04, 0x420

	.globl gMonStillFrontPic_Kingdra
gMonStillFrontPic_Kingdra: @ 0x8CCD324
	.incbin "graphics/pokemon/kingdra/front.4bpp.lz"

	.globl gMonPalette_Kingdra
gMonPalette_Kingdra: @ 0x8CCD744
	.incbin "graphics/pokemon/kingdra/normal.gbapal.lz"

	.globl gMonBackPic_Kingdra
gMonBackPic_Kingdra: @ 0x8CCD76C
	.incbin "graphics/pokemon/kingdra/back.4bpp.lz"

	.globl gMonShinyPalette_Kingdra
gMonShinyPalette_Kingdra: @ 0x8CCDB20
	.incbin "graphics/pokemon/kingdra/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccdb48, 0x420

	.globl gMonStillFrontPic_Phanpy
gMonStillFrontPic_Phanpy: @ 0x8CCDF68
	.incbin "graphics/pokemon/phanpy/front.4bpp.lz"

	.globl gMonPalette_Phanpy
gMonPalette_Phanpy: @ 0x8CCE1C4
	.incbin "graphics/pokemon/phanpy/normal.gbapal.lz"

	.globl gMonBackPic_Phanpy
gMonBackPic_Phanpy: @ 0x8CCE1EC
	.incbin "graphics/pokemon/phanpy/back.4bpp.lz"

	.globl gMonShinyPalette_Phanpy
gMonShinyPalette_Phanpy: @ 0x8CCE4B0
	.incbin "graphics/pokemon/phanpy/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcce4d8, 0x420

	.globl gMonStillFrontPic_Donphan
gMonStillFrontPic_Donphan: @ 0x8CCE8F8
	.incbin "graphics/pokemon/donphan/front.4bpp.lz"

	.globl gMonPalette_Donphan
gMonPalette_Donphan: @ 0x8CCED6C
	.incbin "graphics/pokemon/donphan/normal.gbapal.lz"

	.globl gMonBackPic_Donphan
gMonBackPic_Donphan: @ 0x8CCED94
	.incbin "graphics/pokemon/donphan/back.4bpp.lz"

	.globl gMonShinyPalette_Donphan
gMonShinyPalette_Donphan: @ 0x8CCF090
	.incbin "graphics/pokemon/donphan/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccf0b8, 0x420

	.globl gMonStillFrontPic_Porygon2
gMonStillFrontPic_Porygon2: @ 0x8CCF4D8
	.incbin "graphics/pokemon/porygon2/front.4bpp.lz"

	.globl gMonPalette_Porygon2
gMonPalette_Porygon2: @ 0x8CCF760
	.incbin "graphics/pokemon/porygon2/normal.gbapal.lz"

	.globl gMonBackPic_Porygon2
gMonBackPic_Porygon2: @ 0x8CCF788
	.incbin "graphics/pokemon/porygon2/back.4bpp.lz"

	.globl gMonShinyPalette_Porygon2
gMonShinyPalette_Porygon2: @ 0x8CCFAA4
	.incbin "graphics/pokemon/porygon2/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xccfacc, 0x420

	.globl gMonStillFrontPic_Stantler
gMonStillFrontPic_Stantler: @ 0x8CCFEEC
	.incbin "graphics/pokemon/stantler/front.4bpp.lz"

	.globl gMonPalette_Stantler
gMonPalette_Stantler: @ 0x8CD0300
	.incbin "graphics/pokemon/stantler/normal.gbapal.lz"

	.globl gMonBackPic_Stantler
gMonBackPic_Stantler: @ 0x8CD0328
	.incbin "graphics/pokemon/stantler/back.4bpp.lz"

	.globl gMonShinyPalette_Stantler
gMonShinyPalette_Stantler: @ 0x8CD0674
	.incbin "graphics/pokemon/stantler/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd069c, 0x420

	.globl gMonStillFrontPic_Smeargle
gMonStillFrontPic_Smeargle: @ 0x8CD0ABC
	.incbin "graphics/pokemon/smeargle/front.4bpp.lz"

	.globl gMonPalette_Smeargle
gMonPalette_Smeargle: @ 0x8CD0E50
	.incbin "graphics/pokemon/smeargle/normal.gbapal.lz"

	.globl gMonBackPic_Smeargle
gMonBackPic_Smeargle: @ 0x8CD0E78
	.incbin "graphics/pokemon/smeargle/back.4bpp.lz"

	.globl gMonShinyPalette_Smeargle
gMonShinyPalette_Smeargle: @ 0x8CD119C
	.incbin "graphics/pokemon/smeargle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd11c4, 0x420

	.globl gMonStillFrontPic_Tyrogue
gMonStillFrontPic_Tyrogue: @ 0x8CD15E4
	.incbin "graphics/pokemon/tyrogue/front.4bpp.lz"

	.globl gMonPalette_Tyrogue
gMonPalette_Tyrogue: @ 0x8CD1870
	.incbin "graphics/pokemon/tyrogue/normal.gbapal.lz"

	.globl gMonBackPic_Tyrogue
gMonBackPic_Tyrogue: @ 0x8CD1898
	.incbin "graphics/pokemon/tyrogue/back.4bpp.lz"

	.globl gMonShinyPalette_Tyrogue
gMonShinyPalette_Tyrogue: @ 0x8CD1BB4
	.incbin "graphics/pokemon/tyrogue/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd1bdc, 0x420

	.globl gMonStillFrontPic_Hitmontop
gMonStillFrontPic_Hitmontop: @ 0x8CD1FFC
	.incbin "graphics/pokemon/hitmontop/front.4bpp.lz"

	.globl gMonPalette_Hitmontop
gMonPalette_Hitmontop: @ 0x8CD2388
	.incbin "graphics/pokemon/hitmontop/normal.gbapal.lz"

	.globl gMonBackPic_Hitmontop
gMonBackPic_Hitmontop: @ 0x8CD23B0
	.incbin "graphics/pokemon/hitmontop/back.4bpp.lz"

	.globl gMonShinyPalette_Hitmontop
gMonShinyPalette_Hitmontop: @ 0x8CD27D8
	.incbin "graphics/pokemon/hitmontop/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd2800, 0x420

	.globl gMonStillFrontPic_Smoochum
gMonStillFrontPic_Smoochum: @ 0x8CD2C20
	.incbin "graphics/pokemon/smoochum/front.4bpp.lz"

	.globl gMonPalette_Smoochum
gMonPalette_Smoochum: @ 0x8CD2E78
	.incbin "graphics/pokemon/smoochum/normal.gbapal.lz"

	.globl gMonBackPic_Smoochum
gMonBackPic_Smoochum: @ 0x8CD2EA0
	.incbin "graphics/pokemon/smoochum/back.4bpp.lz"

	.globl gMonShinyPalette_Smoochum
gMonShinyPalette_Smoochum: @ 0x8CD3118
	.incbin "graphics/pokemon/smoochum/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd3140, 0x420

	.globl gMonStillFrontPic_Elekid
gMonStillFrontPic_Elekid: @ 0x8CD3560
	.incbin "graphics/pokemon/elekid/front.4bpp.lz"

	.globl gMonPalette_Elekid
gMonPalette_Elekid: @ 0x8CD3868
	.incbin "graphics/pokemon/elekid/normal.gbapal.lz"

	.globl gMonBackPic_Elekid
gMonBackPic_Elekid: @ 0x8CD3890
	.incbin "graphics/pokemon/elekid/back.4bpp.lz"

	.globl gMonShinyPalette_Elekid
gMonShinyPalette_Elekid: @ 0x8CD3BE8
	.incbin "graphics/pokemon/elekid/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd3c10, 0x420

	.globl gMonStillFrontPic_Magby
gMonStillFrontPic_Magby: @ 0x8CD4030
	.incbin "graphics/pokemon/magby/front.4bpp.lz"

	.globl gMonPalette_Magby
gMonPalette_Magby: @ 0x8CD42B4
	.incbin "graphics/pokemon/magby/normal.gbapal.lz"

	.globl gMonBackPic_Magby
gMonBackPic_Magby: @ 0x8CD42DC
	.incbin "graphics/pokemon/magby/back.4bpp.lz"

	.globl gMonShinyPalette_Magby
gMonShinyPalette_Magby: @ 0x8CD4588
	.incbin "graphics/pokemon/magby/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd45b0, 0x420

	.globl gMonStillFrontPic_Miltank
gMonStillFrontPic_Miltank: @ 0x8CD49D0
	.incbin "graphics/pokemon/miltank/front.4bpp.lz"

	.globl gMonPalette_Miltank
gMonPalette_Miltank: @ 0x8CD4D80
	.incbin "graphics/pokemon/miltank/normal.gbapal.lz"

	.globl gMonBackPic_Miltank
gMonBackPic_Miltank: @ 0x8CD4DA8
	.incbin "graphics/pokemon/miltank/back.4bpp.lz"

	.globl gMonShinyPalette_Miltank
gMonShinyPalette_Miltank: @ 0x8CD5144
	.incbin "graphics/pokemon/miltank/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd516c, 0x420

	.globl gMonStillFrontPic_Blissey
gMonStillFrontPic_Blissey: @ 0x8CD558C
	.incbin "graphics/pokemon/blissey/front.4bpp.lz"

	.globl gMonPalette_Blissey
gMonPalette_Blissey: @ 0x8CD5974
	.incbin "graphics/pokemon/blissey/normal.gbapal.lz"

	.globl gMonBackPic_Blissey
gMonBackPic_Blissey: @ 0x8CD599C
	.incbin "graphics/pokemon/blissey/back.4bpp.lz"

	.globl gMonShinyPalette_Blissey
gMonShinyPalette_Blissey: @ 0x8CD5C68
	.incbin "graphics/pokemon/blissey/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd5c90, 0x420

	.globl gMonStillFrontPic_Raikou
gMonStillFrontPic_Raikou: @ 0x8CD60B0
	.incbin "graphics/pokemon/raikou/front.4bpp.lz"

	.globl gMonPalette_Raikou
gMonPalette_Raikou: @ 0x8CD662C
	.incbin "graphics/pokemon/raikou/normal.gbapal.lz"

	.globl gMonBackPic_Raikou
gMonBackPic_Raikou: @ 0x8CD6654
	.incbin "graphics/pokemon/raikou/back.4bpp.lz"

	.globl gMonShinyPalette_Raikou
gMonShinyPalette_Raikou: @ 0x8CD69FC
	.incbin "graphics/pokemon/raikou/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd6a24, 0x420

	.globl gMonStillFrontPic_Entei
gMonStillFrontPic_Entei: @ 0x8CD6E44
	.incbin "graphics/pokemon/entei/front.4bpp.lz"

	.globl gMonPalette_Entei
gMonPalette_Entei: @ 0x8CD7440
	.incbin "graphics/pokemon/entei/normal.gbapal.lz"

	.globl gMonBackPic_Entei
gMonBackPic_Entei: @ 0x8CD7468
	.incbin "graphics/pokemon/entei/back.4bpp.lz"

	.globl gMonShinyPalette_Entei
gMonShinyPalette_Entei: @ 0x8CD788C
	.incbin "graphics/pokemon/entei/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd78b4, 0x420

	.globl gMonStillFrontPic_Suicune
gMonStillFrontPic_Suicune: @ 0x8CD7CD4
	.incbin "graphics/pokemon/suicune/front.4bpp.lz"

	.globl gMonPalette_Suicune
gMonPalette_Suicune: @ 0x8CD8258
	.incbin "graphics/pokemon/suicune/normal.gbapal.lz"

	.globl gMonBackPic_Suicune
gMonBackPic_Suicune: @ 0x8CD8280
	.incbin "graphics/pokemon/suicune/back.4bpp.lz"

	.globl gMonShinyPalette_Suicune
gMonShinyPalette_Suicune: @ 0x8CD875C
	.incbin "graphics/pokemon/suicune/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd8784, 0x420

	.globl gMonStillFrontPic_Larvitar
gMonStillFrontPic_Larvitar: @ 0x8CD8BA4
	.incbin "graphics/pokemon/larvitar/front.4bpp.lz"

	.globl gMonPalette_Larvitar
gMonPalette_Larvitar: @ 0x8CD8E00
	.incbin "graphics/pokemon/larvitar/normal.gbapal.lz"

	.globl gMonBackPic_Larvitar
gMonBackPic_Larvitar: @ 0x8CD8E28
	.incbin "graphics/pokemon/larvitar/back.4bpp.lz"

	.globl gMonShinyPalette_Larvitar
gMonShinyPalette_Larvitar: @ 0x8CD90D4
	.incbin "graphics/pokemon/larvitar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd90fc, 0x420

	.globl gMonStillFrontPic_Pupitar
gMonStillFrontPic_Pupitar: @ 0x8CD951C
	.incbin "graphics/pokemon/pupitar/front.4bpp.lz"

	.globl gMonPalette_Pupitar
gMonPalette_Pupitar: @ 0x8CD980C
	.incbin "graphics/pokemon/pupitar/normal.gbapal.lz"

	.globl gMonBackPic_Pupitar
gMonBackPic_Pupitar: @ 0x8CD9834
	.incbin "graphics/pokemon/pupitar/back.4bpp.lz"

	.globl gMonShinyPalette_Pupitar
gMonShinyPalette_Pupitar: @ 0x8CD9B6C
	.incbin "graphics/pokemon/pupitar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcd9b92, 0x422

	.globl gMonStillFrontPic_Tyranitar
gMonStillFrontPic_Tyranitar: @ 0x8CD9FB4
	.incbin "graphics/pokemon/tyranitar/front.4bpp.lz"

	.globl gMonPalette_Tyranitar
gMonPalette_Tyranitar: @ 0x8CDA4F0
	.incbin "graphics/pokemon/tyranitar/normal.gbapal.lz"

	.globl gMonBackPic_Tyranitar
gMonBackPic_Tyranitar: @ 0x8CDA518
	.incbin "graphics/pokemon/tyranitar/back.4bpp.lz"

	.globl gMonShinyPalette_Tyranitar
gMonShinyPalette_Tyranitar: @ 0x8CDA904
	.incbin "graphics/pokemon/tyranitar/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcda92c, 0x420

	.globl gMonStillFrontPic_Lugia
gMonStillFrontPic_Lugia: @ 0x8CDAD4C
	.incbin "graphics/pokemon/lugia/front.4bpp.lz"

	.globl gMonPalette_Lugia
gMonPalette_Lugia: @ 0x8CDB210
	.incbin "graphics/pokemon/lugia/normal.gbapal.lz"

	.globl gMonBackPic_Lugia
gMonBackPic_Lugia: @ 0x8CDB238
	.incbin "graphics/pokemon/lugia/back.4bpp.lz"

	.globl gMonShinyPalette_Lugia
gMonShinyPalette_Lugia: @ 0x8CDB60C
	.incbin "graphics/pokemon/lugia/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcdb634, 0x420

	.globl gMonStillFrontPic_HoOh
gMonStillFrontPic_HoOh: @ 0x8CDBA54
	.incbin "graphics/pokemon/ho_oh/front.4bpp.lz"

	.globl gMonPalette_HoOh
gMonPalette_HoOh: @ 0x8CDC0A8
	.incbin "graphics/pokemon/ho_oh/normal.gbapal.lz"

	.globl gMonBackPic_HoOh
gMonBackPic_HoOh: @ 0x8CDC0D0
	.incbin "graphics/pokemon/ho_oh/back.4bpp.lz"

	.globl gMonShinyPalette_HoOh
gMonShinyPalette_HoOh: @ 0x8CDC4E0
	.incbin "graphics/pokemon/ho_oh/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcdc508, 0x420

	.globl gMonStillFrontPic_Celebi
gMonStillFrontPic_Celebi: @ 0x8CDC928
	.incbin "graphics/pokemon/celebi/front.4bpp.lz"

	.globl gMonPalette_Celebi
gMonPalette_Celebi: @ 0x8CDCBA0
	.incbin "graphics/pokemon/celebi/normal.gbapal.lz"

	.globl gMonBackPic_Celebi
gMonBackPic_Celebi: @ 0x8CDCBC8
	.incbin "graphics/pokemon/celebi/back.4bpp.lz"

	.globl gMonShinyPalette_Celebi
gMonShinyPalette_Celebi: @ 0x8CDCF74
	.incbin "graphics/pokemon/celebi/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcdcf9c, 0x420

	.globl gMonStillFrontPic_DoubleQuestionMark
gMonStillFrontPic_DoubleQuestionMark: @ 0x8CDD3BC
	.incbin "graphics/pokemon/question_mark/double/front.4bpp.lz"

	.globl gMonPalette_DoubleQuestionMark
gMonPalette_DoubleQuestionMark: @ 0x8CDD53C
	.incbin "graphics/pokemon/question_mark/double/normal.gbapal.lz"

	.globl gMonBackPic_DoubleQuestionMark
gMonBackPic_DoubleQuestionMark: @ 0x8CDD550
	.incbin "graphics/pokemon/question_mark/double/back.4bpp.lz"

	.globl gMonShinyPalette_DoubleQuestionMark
gMonShinyPalette_DoubleQuestionMark: @ 0x8CDD6D4
	.incbin "graphics/pokemon/question_mark/double/shiny.gbapal.lz"

	.globl gMonStillFrontPic_Treecko
gMonStillFrontPic_Treecko: @ 0x8CDD6E8
	.incbin "graphics/pokemon/treecko/front.4bpp.lz"

	.globl gMonPalette_Treecko
gMonPalette_Treecko: @ 0x8CDD9F0
	.incbin "graphics/pokemon/treecko/normal.gbapal.lz"

	.globl gMonBackPic_Treecko
gMonBackPic_Treecko: @ 0x8CDDA18
	.incbin "graphics/pokemon/treecko/back.4bpp.lz"

	.globl gMonShinyPalette_Treecko
gMonShinyPalette_Treecko: @ 0x8CDDD18
	.incbin "graphics/pokemon/treecko/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcddd40, 0x420

	.globl gMonStillFrontPic_Grovyle
gMonStillFrontPic_Grovyle: @ 0x8CDE160
	.incbin "graphics/pokemon/grovyle/front.4bpp.lz"

	.globl gMonPalette_Grovyle
gMonPalette_Grovyle: @ 0x8CDE5EC
	.incbin "graphics/pokemon/grovyle/normal.gbapal.lz"

	.globl gMonBackPic_Grovyle
gMonBackPic_Grovyle: @ 0x8CDE614
	.incbin "graphics/pokemon/grovyle/back.4bpp.lz"

	.globl gMonShinyPalette_Grovyle
gMonShinyPalette_Grovyle: @ 0x8CDE950
	.incbin "graphics/pokemon/grovyle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcde978, 0x420

	.globl gMonStillFrontPic_Sceptile
gMonStillFrontPic_Sceptile: @ 0x8CDED98
	.incbin "graphics/pokemon/sceptile/front.4bpp.lz"

	.globl gMonPalette_Sceptile
gMonPalette_Sceptile: @ 0x8CDF29C
	.incbin "graphics/pokemon/sceptile/normal.gbapal.lz"

	.globl gMonBackPic_Sceptile
gMonBackPic_Sceptile: @ 0x8CDF2C4
	.incbin "graphics/pokemon/sceptile/back.4bpp.lz"

	.globl gMonShinyPalette_Sceptile
gMonShinyPalette_Sceptile: @ 0x8CDF6C0
	.incbin "graphics/pokemon/sceptile/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcdf6e8, 0x420

	.globl gMonStillFrontPic_Torchic
gMonStillFrontPic_Torchic: @ 0x8CDFB08
	.incbin "graphics/pokemon/torchic/front.4bpp.lz"

	.globl gMonPalette_Torchic
gMonPalette_Torchic: @ 0x8CDFDA4
	.incbin "graphics/pokemon/torchic/normal.gbapal.lz"

	.globl gMonBackPic_Torchic
gMonBackPic_Torchic: @ 0x8CDFDCC
	.incbin "graphics/pokemon/torchic/back.4bpp.lz"

	.globl gMonShinyPalette_Torchic
gMonShinyPalette_Torchic: @ 0x8CE00A4
	.incbin "graphics/pokemon/torchic/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce00cc, 0x420

	.globl gMonStillFrontPic_Combusken
gMonStillFrontPic_Combusken: @ 0x8CE04EC
	.incbin "graphics/pokemon/combusken/front.4bpp.lz"

	.globl gMonPalette_Combusken
gMonPalette_Combusken: @ 0x8CE08D8
	.incbin "graphics/pokemon/combusken/normal.gbapal.lz"

	.globl gMonBackPic_Combusken
gMonBackPic_Combusken: @ 0x8CE0900
	.incbin "graphics/pokemon/combusken/back.4bpp.lz"

	.globl gMonShinyPalette_Combusken
gMonShinyPalette_Combusken: @ 0x8CE0CD0
	.incbin "graphics/pokemon/combusken/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce0cf8, 0x420

	.globl gMonStillFrontPic_Blaziken
gMonStillFrontPic_Blaziken: @ 0x8CE1118
	.incbin "graphics/pokemon/blaziken/front.4bpp.lz"

	.globl gMonPalette_Blaziken
gMonPalette_Blaziken: @ 0x8CE1868
	.incbin "graphics/pokemon/blaziken/normal.gbapal.lz"

	.globl gMonBackPic_Blaziken
gMonBackPic_Blaziken: @ 0x8CE1890
	.incbin "graphics/pokemon/blaziken/back.4bpp.lz"

	.globl gMonShinyPalette_Blaziken
gMonShinyPalette_Blaziken: @ 0x8CE1C6C
	.incbin "graphics/pokemon/blaziken/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce1c94, 0x420

	.globl gMonStillFrontPic_Mudkip
gMonStillFrontPic_Mudkip: @ 0x8CE20B4
	.incbin "graphics/pokemon/mudkip/front.4bpp.lz"

	.globl gMonPalette_Mudkip
gMonPalette_Mudkip: @ 0x8CE236C
	.incbin "graphics/pokemon/mudkip/normal.gbapal.lz"

	.globl gMonBackPic_Mudkip
gMonBackPic_Mudkip: @ 0x8CE2394
	.incbin "graphics/pokemon/mudkip/back.4bpp.lz"

	.globl gMonShinyPalette_Mudkip
gMonShinyPalette_Mudkip: @ 0x8CE2674
	.incbin "graphics/pokemon/mudkip/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce269c, 0x420

	.globl gMonStillFrontPic_Marshtomp
gMonStillFrontPic_Marshtomp: @ 0x8CE2ABC
	.incbin "graphics/pokemon/marshtomp/front.4bpp.lz"

	.globl gMonPalette_Marshtomp
gMonPalette_Marshtomp: @ 0x8CE311C
	.incbin "graphics/pokemon/marshtomp/normal.gbapal.lz"

	.globl gMonBackPic_Marshtomp
gMonBackPic_Marshtomp: @ 0x8CE3144
	.incbin "graphics/pokemon/marshtomp/back.4bpp.lz"

	.globl gMonShinyPalette_Marshtomp
gMonShinyPalette_Marshtomp: @ 0x8CE34F4
	.incbin "graphics/pokemon/marshtomp/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce351c, 0x420

	.globl gMonStillFrontPic_Swampert
gMonStillFrontPic_Swampert: @ 0x8CE393C
	.incbin "graphics/pokemon/swampert/front.4bpp.lz"

	.globl gMonPalette_Swampert
gMonPalette_Swampert: @ 0x8CE3EB8
	.incbin "graphics/pokemon/swampert/normal.gbapal.lz"

	.globl gMonBackPic_Swampert
gMonBackPic_Swampert: @ 0x8CE3EE0
	.incbin "graphics/pokemon/swampert/back.4bpp.lz"

	.globl gMonShinyPalette_Swampert
gMonShinyPalette_Swampert: @ 0x8CE4294
	.incbin "graphics/pokemon/swampert/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce42bc, 0x420

	.globl gMonStillFrontPic_Poochyena
gMonStillFrontPic_Poochyena: @ 0x8CE46DC
	.incbin "graphics/pokemon/poochyena/front.4bpp.lz"

	.globl gMonPalette_Poochyena
gMonPalette_Poochyena: @ 0x8CE4C80
	.incbin "graphics/pokemon/poochyena/normal.gbapal.lz"

	.globl gMonBackPic_Poochyena
gMonBackPic_Poochyena: @ 0x8CE4CA8
	.incbin "graphics/pokemon/poochyena/back.4bpp.lz"

	.globl gMonShinyPalette_Poochyena
gMonShinyPalette_Poochyena: @ 0x8CE4FD4
	.incbin "graphics/pokemon/poochyena/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce4ffc, 0x420

	.globl gMonStillFrontPic_Mightyena
gMonStillFrontPic_Mightyena: @ 0x8CE541C
	.incbin "graphics/pokemon/mightyena/front.4bpp.lz"

	.globl gMonPalette_Mightyena
gMonPalette_Mightyena: @ 0x8CE5854
	.incbin "graphics/pokemon/mightyena/normal.gbapal.lz"

	.globl gMonBackPic_Mightyena
gMonBackPic_Mightyena: @ 0x8CE587C
	.incbin "graphics/pokemon/mightyena/back.4bpp.lz"

	.globl gMonShinyPalette_Mightyena
gMonShinyPalette_Mightyena: @ 0x8CE5BF4
	.incbin "graphics/pokemon/mightyena/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce5c1c, 0x420

	.globl gMonStillFrontPic_Zigzagoon
gMonStillFrontPic_Zigzagoon: @ 0x8CE603C
	.incbin "graphics/pokemon/zigzagoon/front.4bpp.lz"

	.globl gMonPalette_Zigzagoon
gMonPalette_Zigzagoon: @ 0x8CE640C
	.incbin "graphics/pokemon/zigzagoon/normal.gbapal.lz"

	.globl gMonBackPic_Zigzagoon
gMonBackPic_Zigzagoon: @ 0x8CE6434
	.incbin "graphics/pokemon/zigzagoon/back.4bpp.lz"

	.globl gMonShinyPalette_Zigzagoon
gMonShinyPalette_Zigzagoon: @ 0x8CE6774
	.incbin "graphics/pokemon/zigzagoon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce679c, 0x420

	.globl gMonStillFrontPic_Linoone
gMonStillFrontPic_Linoone: @ 0x8CE6BBC
	.incbin "graphics/pokemon/linoone/front.4bpp.lz"

	.globl gMonPalette_Linoone
gMonPalette_Linoone: @ 0x8CE6F2C
	.incbin "graphics/pokemon/linoone/normal.gbapal.lz"

	.globl gMonBackPic_Linoone
gMonBackPic_Linoone: @ 0x8CE6F54
	.incbin "graphics/pokemon/linoone/back.4bpp.lz"

	.globl gMonShinyPalette_Linoone
gMonShinyPalette_Linoone: @ 0x8CE7228
	.incbin "graphics/pokemon/linoone/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce7250, 0x420

	.globl gMonStillFrontPic_Wurmple
gMonStillFrontPic_Wurmple: @ 0x8CE7670
	.incbin "graphics/pokemon/wurmple/front.4bpp.lz"

	.globl gMonPalette_Wurmple
gMonPalette_Wurmple: @ 0x8CE78F8
	.incbin "graphics/pokemon/wurmple/normal.gbapal.lz"

	.globl gMonBackPic_Wurmple
gMonBackPic_Wurmple: @ 0x8CE7920
	.incbin "graphics/pokemon/wurmple/back.4bpp.lz"

	.globl gMonShinyPalette_Wurmple
gMonShinyPalette_Wurmple: @ 0x8CE7B6C
	.incbin "graphics/pokemon/wurmple/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce7b94, 0x420

	.globl gMonStillFrontPic_Silcoon
gMonStillFrontPic_Silcoon: @ 0x8CE7FB4
	.incbin "graphics/pokemon/silcoon/front.4bpp.lz"

	.globl gMonPalette_Silcoon
gMonPalette_Silcoon: @ 0x8CE8234
	.incbin "graphics/pokemon/silcoon/normal.gbapal.lz"

	.globl gMonBackPic_Silcoon
gMonBackPic_Silcoon: @ 0x8CE825C
	.incbin "graphics/pokemon/silcoon/back.4bpp.lz"

	.globl gMonShinyPalette_Silcoon
gMonShinyPalette_Silcoon: @ 0x8CE8478
	.incbin "graphics/pokemon/silcoon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce84a0, 0x420

	.globl gMonStillFrontPic_Beautifly
gMonStillFrontPic_Beautifly: @ 0x8CE88C0
	.incbin "graphics/pokemon/beautifly/front.4bpp.lz"

	.globl gMonPalette_Beautifly
gMonPalette_Beautifly: @ 0x8CE8C18
	.incbin "graphics/pokemon/beautifly/normal.gbapal.lz"

	.globl gMonBackPic_Beautifly
gMonBackPic_Beautifly: @ 0x8CE8C40
	.incbin "graphics/pokemon/beautifly/back.4bpp.lz"

	.globl gMonShinyPalette_Beautifly
gMonShinyPalette_Beautifly: @ 0x8CE8FF0
	.incbin "graphics/pokemon/beautifly/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce9018, 0x420

	.globl gMonStillFrontPic_Cascoon
gMonStillFrontPic_Cascoon: @ 0x8CE9438
	.incbin "graphics/pokemon/cascoon/front.4bpp.lz"

	.globl gMonPalette_Cascoon
gMonPalette_Cascoon: @ 0x8CE96A4
	.incbin "graphics/pokemon/cascoon/normal.gbapal.lz"

	.globl gMonBackPic_Cascoon
gMonBackPic_Cascoon: @ 0x8CE96CC
	.incbin "graphics/pokemon/cascoon/back.4bpp.lz"

	.globl gMonShinyPalette_Cascoon
gMonShinyPalette_Cascoon: @ 0x8CE98DC
	.incbin "graphics/pokemon/cascoon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xce9904, 0x420

	.globl gMonStillFrontPic_Dustox
gMonStillFrontPic_Dustox: @ 0x8CE9D24
	.incbin "graphics/pokemon/dustox/front.4bpp.lz"

	.globl gMonPalette_Dustox
gMonPalette_Dustox: @ 0x8CEA08C
	.incbin "graphics/pokemon/dustox/normal.gbapal.lz"

	.globl gMonBackPic_Dustox
gMonBackPic_Dustox: @ 0x8CEA0B4
	.incbin "graphics/pokemon/dustox/back.4bpp.lz"

	.globl gMonShinyPalette_Dustox
gMonShinyPalette_Dustox: @ 0x8CEA30C
	.incbin "graphics/pokemon/dustox/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcea334, 0x420

	.globl gMonStillFrontPic_Lotad
gMonStillFrontPic_Lotad: @ 0x8CEA754
	.incbin "graphics/pokemon/lotad/front.4bpp.lz"

	.globl gMonPalette_Lotad
gMonPalette_Lotad: @ 0x8CEA9B4
	.incbin "graphics/pokemon/lotad/normal.gbapal.lz"

	.globl gMonBackPic_Lotad
gMonBackPic_Lotad: @ 0x8CEA9DC
	.incbin "graphics/pokemon/lotad/back.4bpp.lz"

	.globl gMonShinyPalette_Lotad
gMonShinyPalette_Lotad: @ 0x8CEACC4
	.incbin "graphics/pokemon/lotad/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xceacec, 0x420

	.globl gMonStillFrontPic_Lombre
gMonStillFrontPic_Lombre: @ 0x8CEB10C
	.incbin "graphics/pokemon/lombre/front.4bpp.lz"

	.globl gMonPalette_Lombre
gMonPalette_Lombre: @ 0x8CEB424
	.incbin "graphics/pokemon/lombre/normal.gbapal.lz"

	.globl gMonBackPic_Lombre
gMonBackPic_Lombre: @ 0x8CEB44C
	.incbin "graphics/pokemon/lombre/back.4bpp.lz"

	.globl gMonShinyPalette_Lombre
gMonShinyPalette_Lombre: @ 0x8CEB748
	.incbin "graphics/pokemon/lombre/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xceb770, 0x420

	.globl gMonStillFrontPic_Ludicolo
gMonStillFrontPic_Ludicolo: @ 0x8CEBB90
	.incbin "graphics/pokemon/ludicolo/front.4bpp.lz"

	.globl gMonPalette_Ludicolo
gMonPalette_Ludicolo: @ 0x8CEC074
	.incbin "graphics/pokemon/ludicolo/normal.gbapal.lz"

	.globl gMonBackPic_Ludicolo
gMonBackPic_Ludicolo: @ 0x8CEC09C
	.incbin "graphics/pokemon/ludicolo/back.4bpp.lz"

	.globl gMonShinyPalette_Ludicolo
gMonShinyPalette_Ludicolo: @ 0x8CEC398
	.incbin "graphics/pokemon/ludicolo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcec3c0, 0x420

	.globl gMonStillFrontPic_Seedot
gMonStillFrontPic_Seedot: @ 0x8CEC7E0
	.incbin "graphics/pokemon/seedot/front.4bpp.lz"

	.globl gMonPalette_Seedot
gMonPalette_Seedot: @ 0x8CECA74
	.incbin "graphics/pokemon/seedot/normal.gbapal.lz"

	.globl gMonBackPic_Seedot
gMonBackPic_Seedot: @ 0x8CECA9C
	.incbin "graphics/pokemon/seedot/back.4bpp.lz"

	.globl gMonShinyPalette_Seedot
gMonShinyPalette_Seedot: @ 0x8CECD7C
	.incbin "graphics/pokemon/seedot/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcecda2, 0x422

	.globl gMonStillFrontPic_Nuzleaf
gMonStillFrontPic_Nuzleaf: @ 0x8CED1C4
	.incbin "graphics/pokemon/nuzleaf/front.4bpp.lz"

	.globl gMonPalette_Nuzleaf
gMonPalette_Nuzleaf: @ 0x8CED4B0
	.incbin "graphics/pokemon/nuzleaf/normal.gbapal.lz"

	.globl gMonBackPic_Nuzleaf
gMonBackPic_Nuzleaf: @ 0x8CED4D8
	.incbin "graphics/pokemon/nuzleaf/back.4bpp.lz"

	.globl gMonShinyPalette_Nuzleaf
gMonShinyPalette_Nuzleaf: @ 0x8CED7A0
	.incbin "graphics/pokemon/nuzleaf/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xced7c8, 0x420

	.globl gMonStillFrontPic_Shiftry
gMonStillFrontPic_Shiftry: @ 0x8CEDBE8
	.incbin "graphics/pokemon/shiftry/front.4bpp.lz"

	.globl gMonPalette_Shiftry
gMonPalette_Shiftry: @ 0x8CEE0A4
	.incbin "graphics/pokemon/shiftry/normal.gbapal.lz"

	.globl gMonBackPic_Shiftry
gMonBackPic_Shiftry: @ 0x8CEE0CC
	.incbin "graphics/pokemon/shiftry/back.4bpp.lz"

	.globl gMonShinyPalette_Shiftry
gMonShinyPalette_Shiftry: @ 0x8CEE390
	.incbin "graphics/pokemon/shiftry/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcee3b8, 0x420

	.globl gMonStillFrontPic_Nincada
gMonStillFrontPic_Nincada: @ 0x8CEE7D8
	.incbin "graphics/pokemon/nincada/front.4bpp.lz"

	.globl gMonPalette_Nincada
gMonPalette_Nincada: @ 0x8CEEA78
	.incbin "graphics/pokemon/nincada/normal.gbapal.lz"

	.globl gMonBackPic_Nincada
gMonBackPic_Nincada: @ 0x8CEEAA0
	.incbin "graphics/pokemon/nincada/back.4bpp.lz"

	.globl gMonShinyPalette_Nincada
gMonShinyPalette_Nincada: @ 0x8CEED58
	.incbin "graphics/pokemon/nincada/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xceed80, 0x420

	.globl gMonStillFrontPic_Ninjask
gMonStillFrontPic_Ninjask: @ 0x8CEF1A0
	.incbin "graphics/pokemon/ninjask/front.4bpp.lz"

	.globl gMonPalette_Ninjask
gMonPalette_Ninjask: @ 0x8CEF510
	.incbin "graphics/pokemon/ninjask/normal.gbapal.lz"

	.globl gMonBackPic_Ninjask
gMonBackPic_Ninjask: @ 0x8CEF538
	.incbin "graphics/pokemon/ninjask/back.4bpp.lz"

	.globl gMonShinyPalette_Ninjask
gMonShinyPalette_Ninjask: @ 0x8CEF904
	.incbin "graphics/pokemon/ninjask/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcef92c, 0x420

	.globl gMonStillFrontPic_Shedinja
gMonStillFrontPic_Shedinja: @ 0x8CEFD4C
	.incbin "graphics/pokemon/shedinja/front.4bpp.lz"

	.globl gMonPalette_Shedinja
gMonPalette_Shedinja: @ 0x8CF006C
	.incbin "graphics/pokemon/shedinja/normal.gbapal.lz"

	.globl gMonBackPic_Shedinja
gMonBackPic_Shedinja: @ 0x8CF0094
	.incbin "graphics/pokemon/shedinja/back.4bpp.lz"

	.globl gMonShinyPalette_Shedinja
gMonShinyPalette_Shedinja: @ 0x8CF0434
	.incbin "graphics/pokemon/shedinja/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf045c, 0x420

	.globl gMonStillFrontPic_Taillow
gMonStillFrontPic_Taillow: @ 0x8CF087C
	.incbin "graphics/pokemon/taillow/front.4bpp.lz"

	.globl gMonPalette_Taillow
gMonPalette_Taillow: @ 0x8CF0AD4
	.incbin "graphics/pokemon/taillow/normal.gbapal.lz"

	.globl gMonBackPic_Taillow
gMonBackPic_Taillow: @ 0x8CF0AFC
	.incbin "graphics/pokemon/taillow/back.4bpp.lz"

	.globl gMonShinyPalette_Taillow
gMonShinyPalette_Taillow: @ 0x8CF0D1C
	.incbin "graphics/pokemon/taillow/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf0d44, 0x420

	.globl gMonStillFrontPic_Swellow
gMonStillFrontPic_Swellow: @ 0x8CF1164
	.incbin "graphics/pokemon/swellow/front.4bpp.lz"

	.globl gMonPalette_Swellow
gMonPalette_Swellow: @ 0x8CF1528
	.incbin "graphics/pokemon/swellow/normal.gbapal.lz"

	.globl gMonBackPic_Swellow
gMonBackPic_Swellow: @ 0x8CF1550
	.incbin "graphics/pokemon/swellow/back.4bpp.lz"

	.globl gMonShinyPalette_Swellow
gMonShinyPalette_Swellow: @ 0x8CF1888
	.incbin "graphics/pokemon/swellow/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf18b0, 0x420

	.globl gMonStillFrontPic_Shroomish
gMonStillFrontPic_Shroomish: @ 0x8CF1CD0
	.incbin "graphics/pokemon/shroomish/front.4bpp.lz"

	.globl gMonPalette_Shroomish
gMonPalette_Shroomish: @ 0x8CF1F38
	.incbin "graphics/pokemon/shroomish/normal.gbapal.lz"

	.globl gMonBackPic_Shroomish
gMonBackPic_Shroomish: @ 0x8CF1F60
	.incbin "graphics/pokemon/shroomish/back.4bpp.lz"

	.globl gMonShinyPalette_Shroomish
gMonShinyPalette_Shroomish: @ 0x8CF2240
	.incbin "graphics/pokemon/shroomish/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf2268, 0x420

	.globl gMonStillFrontPic_Breloom
gMonStillFrontPic_Breloom: @ 0x8CF2688
	.incbin "graphics/pokemon/breloom/front.4bpp.lz"

	.globl gMonPalette_Breloom
gMonPalette_Breloom: @ 0x8CF2A70
	.incbin "graphics/pokemon/breloom/normal.gbapal.lz"

	.globl gMonBackPic_Breloom
gMonBackPic_Breloom: @ 0x8CF2A98
	.incbin "graphics/pokemon/breloom/back.4bpp.lz"

	.globl gMonShinyPalette_Breloom
gMonShinyPalette_Breloom: @ 0x8CF2E78
	.incbin "graphics/pokemon/breloom/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf2ea0, 0x420

	.globl gMonStillFrontPic_Spinda
gMonStillFrontPic_Spinda: @ 0x8CF32C0
	.incbin "graphics/pokemon/spinda/front.4bpp.lz"

	.globl gMonPalette_Spinda
gMonPalette_Spinda: @ 0x8CF35B4
	.incbin "graphics/pokemon/spinda/normal.gbapal.lz"

	.globl gMonBackPic_Spinda
gMonBackPic_Spinda: @ 0x8CF35DC
	.incbin "graphics/pokemon/spinda/back.4bpp.lz"

	.globl gMonShinyPalette_Spinda
gMonShinyPalette_Spinda: @ 0x8CF3918
	.incbin "graphics/pokemon/spinda/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf3940, 0x420

	.globl gMonStillFrontPic_Wingull
gMonStillFrontPic_Wingull: @ 0x8CF3D60
	.incbin "graphics/pokemon/wingull/front.4bpp.lz"

	.globl gMonPalette_Wingull
gMonPalette_Wingull: @ 0x8CF3F9C
	.incbin "graphics/pokemon/wingull/normal.gbapal.lz"

	.globl gMonBackPic_Wingull
gMonBackPic_Wingull: @ 0x8CF3FC4
	.incbin "graphics/pokemon/wingull/back.4bpp.lz"

	.globl gMonShinyPalette_Wingull
gMonShinyPalette_Wingull: @ 0x8CF4314
	.incbin "graphics/pokemon/wingull/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf433c, 0x420

	.globl gMonStillFrontPic_Pelipper
gMonStillFrontPic_Pelipper: @ 0x8CF475C
	.incbin "graphics/pokemon/pelipper/front.4bpp.lz"

	.globl gMonPalette_Pelipper
gMonPalette_Pelipper: @ 0x8CF4AF4
	.incbin "graphics/pokemon/pelipper/normal.gbapal.lz"

	.globl gMonBackPic_Pelipper
gMonBackPic_Pelipper: @ 0x8CF4B1C
	.incbin "graphics/pokemon/pelipper/back.4bpp.lz"

	.globl gMonShinyPalette_Pelipper
gMonShinyPalette_Pelipper: @ 0x8CF4E9C
	.incbin "graphics/pokemon/pelipper/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf4ec4, 0x420

	.globl gMonStillFrontPic_Surskit
gMonStillFrontPic_Surskit: @ 0x8CF52E4
	.incbin "graphics/pokemon/surskit/front.4bpp.lz"

	.globl gMonPalette_Surskit
gMonPalette_Surskit: @ 0x8CF54F0
	.incbin "graphics/pokemon/surskit/normal.gbapal.lz"

	.globl gMonBackPic_Surskit
gMonBackPic_Surskit: @ 0x8CF5518
	.incbin "graphics/pokemon/surskit/back.4bpp.lz"

	.globl gMonShinyPalette_Surskit
gMonShinyPalette_Surskit: @ 0x8CF5750
	.incbin "graphics/pokemon/surskit/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf5778, 0x420

	.globl gMonStillFrontPic_Masquerain
gMonStillFrontPic_Masquerain: @ 0x8CF5B98
	.incbin "graphics/pokemon/masquerain/front.4bpp.lz"

	.globl gMonPalette_Masquerain
gMonPalette_Masquerain: @ 0x8CF5F34
	.incbin "graphics/pokemon/masquerain/normal.gbapal.lz"

	.globl gMonBackPic_Masquerain
gMonBackPic_Masquerain: @ 0x8CF5F5C
	.incbin "graphics/pokemon/masquerain/back.4bpp.lz"

	.globl gMonShinyPalette_Masquerain
gMonShinyPalette_Masquerain: @ 0x8CF62B4
	.incbin "graphics/pokemon/masquerain/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf62dc, 0x420

	.globl gMonStillFrontPic_Wailmer
gMonStillFrontPic_Wailmer: @ 0x8CF66FC
	.incbin "graphics/pokemon/wailmer/front.4bpp.lz"

	.globl gMonPalette_Wailmer
gMonPalette_Wailmer: @ 0x8CF69DC
	.incbin "graphics/pokemon/wailmer/normal.gbapal.lz"

	.globl gMonBackPic_Wailmer
gMonBackPic_Wailmer: @ 0x8CF6A04
	.incbin "graphics/pokemon/wailmer/back.4bpp.lz"

	.globl gMonShinyPalette_Wailmer
gMonShinyPalette_Wailmer: @ 0x8CF6BE8
	.incbin "graphics/pokemon/wailmer/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf6c10, 0x420

	.globl gMonStillFrontPic_Wailord
gMonStillFrontPic_Wailord: @ 0x8CF7030
	.incbin "graphics/pokemon/wailord/front.4bpp.lz"

	.globl gMonPalette_Wailord
gMonPalette_Wailord: @ 0x8CF73F4
	.incbin "graphics/pokemon/wailord/normal.gbapal.lz"

	.globl gMonBackPic_Wailord
gMonBackPic_Wailord: @ 0x8CF741C
	.incbin "graphics/pokemon/wailord/back.4bpp.lz"

	.globl gMonShinyPalette_Wailord
gMonShinyPalette_Wailord: @ 0x8CF7634
	.incbin "graphics/pokemon/wailord/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf765c, 0x420

	.globl gMonStillFrontPic_Skitty
gMonStillFrontPic_Skitty: @ 0x8CF7A7C
	.incbin "graphics/pokemon/skitty/front.4bpp.lz"

	.globl gMonPalette_Skitty
gMonPalette_Skitty: @ 0x8CF7D7C
	.incbin "graphics/pokemon/skitty/normal.gbapal.lz"

	.globl gMonBackPic_Skitty
gMonBackPic_Skitty: @ 0x8CF7DA4
	.incbin "graphics/pokemon/skitty/back.4bpp.lz"

	.globl gMonShinyPalette_Skitty
gMonShinyPalette_Skitty: @ 0x8CF80EC
	.incbin "graphics/pokemon/skitty/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf8114, 0x420

	.globl gMonStillFrontPic_Delcatty
gMonStillFrontPic_Delcatty: @ 0x8CF8534
	.incbin "graphics/pokemon/delcatty/front.4bpp.lz"

	.globl gMonPalette_Delcatty
gMonPalette_Delcatty: @ 0x8CF88C0
	.incbin "graphics/pokemon/delcatty/normal.gbapal.lz"

	.globl gMonBackPic_Delcatty
gMonBackPic_Delcatty: @ 0x8CF88E8
	.incbin "graphics/pokemon/delcatty/back.4bpp.lz"

	.globl gMonShinyPalette_Delcatty
gMonShinyPalette_Delcatty: @ 0x8CF8C84
	.incbin "graphics/pokemon/delcatty/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf8cac, 0x420

	.globl gMonStillFrontPic_Kecleon
gMonStillFrontPic_Kecleon: @ 0x8CF90CC
	.incbin "graphics/pokemon/kecleon/front.4bpp.lz"

	.globl gMonPalette_Kecleon
gMonPalette_Kecleon: @ 0x8CF944C
	.incbin "graphics/pokemon/kecleon/normal.gbapal.lz"

	.globl gMonBackPic_Kecleon
gMonBackPic_Kecleon: @ 0x8CF9474
	.incbin "graphics/pokemon/kecleon/back.4bpp.lz"

	.globl gMonShinyPalette_Kecleon
gMonShinyPalette_Kecleon: @ 0x8CF984C
	.incbin "graphics/pokemon/kecleon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcf9874, 0x420

	.globl gMonStillFrontPic_Baltoy
gMonStillFrontPic_Baltoy: @ 0x8CF9C94
	.incbin "graphics/pokemon/baltoy/front.4bpp.lz"

	.globl gMonPalette_Baltoy
gMonPalette_Baltoy: @ 0x8CF9EB8
	.incbin "graphics/pokemon/baltoy/normal.gbapal.lz"

	.globl gMonBackPic_Baltoy
gMonBackPic_Baltoy: @ 0x8CF9ED8
	.incbin "graphics/pokemon/baltoy/back.4bpp.lz"

	.globl gMonShinyPalette_Baltoy
gMonShinyPalette_Baltoy: @ 0x8CFA180
	.incbin "graphics/pokemon/baltoy/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfa19f, 0x421

	.globl gMonStillFrontPic_Claydol
gMonStillFrontPic_Claydol: @ 0x8CFA5C0
	.incbin "graphics/pokemon/claydol/front.4bpp.lz"

	.globl gMonPalette_Claydol
gMonPalette_Claydol: @ 0x8CFA978
	.incbin "graphics/pokemon/claydol/normal.gbapal.lz"

	.globl gMonBackPic_Claydol
gMonBackPic_Claydol: @ 0x8CFA9A0
	.incbin "graphics/pokemon/claydol/back.4bpp.lz"

	.globl gMonShinyPalette_Claydol
gMonShinyPalette_Claydol: @ 0x8CFAD74
	.incbin "graphics/pokemon/claydol/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfad9c, 0x420

	.globl gMonStillFrontPic_Nosepass
gMonStillFrontPic_Nosepass: @ 0x8CFB1BC
	.incbin "graphics/pokemon/nosepass/front.4bpp.lz"

	.globl gMonPalette_Nosepass
gMonPalette_Nosepass: @ 0x8CFB488
	.incbin "graphics/pokemon/nosepass/normal.gbapal.lz"

	.globl gMonBackPic_Nosepass
gMonBackPic_Nosepass: @ 0x8CFB4B0
	.incbin "graphics/pokemon/nosepass/back.4bpp.lz"

	.globl gMonShinyPalette_Nosepass
gMonShinyPalette_Nosepass: @ 0x8CFB750
	.incbin "graphics/pokemon/nosepass/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfb778, 0x420

	.globl gMonStillFrontPic_Torkoal
gMonStillFrontPic_Torkoal: @ 0x8CFBB98
	.incbin "graphics/pokemon/torkoal/front.4bpp.lz"

	.globl gMonPalette_Torkoal
gMonPalette_Torkoal: @ 0x8CFC044
	.incbin "graphics/pokemon/torkoal/normal.gbapal.lz"

	.globl gMonBackPic_Torkoal
gMonBackPic_Torkoal: @ 0x8CFC06C
	.incbin "graphics/pokemon/torkoal/back.4bpp.lz"

	.globl gMonShinyPalette_Torkoal
gMonShinyPalette_Torkoal: @ 0x8CFC334
	.incbin "graphics/pokemon/torkoal/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfc35c, 0x420

	.globl gMonStillFrontPic_Sableye
gMonStillFrontPic_Sableye: @ 0x8CFC77C
	.incbin "graphics/pokemon/sableye/front.4bpp.lz"

	.globl gMonPalette_Sableye
gMonPalette_Sableye: @ 0x8CFCA50
	.incbin "graphics/pokemon/sableye/normal.gbapal.lz"

	.globl gMonBackPic_Sableye
gMonBackPic_Sableye: @ 0x8CFCA78
	.incbin "graphics/pokemon/sableye/back.4bpp.lz"

	.globl gMonShinyPalette_Sableye
gMonShinyPalette_Sableye: @ 0x8CFCDA0
	.incbin "graphics/pokemon/sableye/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfcdc8, 0x420

	.globl gMonStillFrontPic_Barboach
gMonStillFrontPic_Barboach: @ 0x8CFD1E8
	.incbin "graphics/pokemon/barboach/front.4bpp.lz"

	.globl gMonPalette_Barboach
gMonPalette_Barboach: @ 0x8CFD478
	.incbin "graphics/pokemon/barboach/normal.gbapal.lz"

	.globl gMonBackPic_Barboach
gMonBackPic_Barboach: @ 0x8CFD4A0
	.incbin "graphics/pokemon/barboach/back.4bpp.lz"

	.globl gMonShinyPalette_Barboach
gMonShinyPalette_Barboach: @ 0x8CFD730
	.incbin "graphics/pokemon/barboach/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfd758, 0x420

	.globl gMonStillFrontPic_Whiscash
gMonStillFrontPic_Whiscash: @ 0x8CFDB78
	.incbin "graphics/pokemon/whiscash/front.4bpp.lz"

	.globl gMonPalette_Whiscash
gMonPalette_Whiscash: @ 0x8CFDEF0
	.incbin "graphics/pokemon/whiscash/normal.gbapal.lz"

	.globl gMonBackPic_Whiscash
gMonBackPic_Whiscash: @ 0x8CFDF18
	.incbin "graphics/pokemon/whiscash/back.4bpp.lz"

	.globl gMonShinyPalette_Whiscash
gMonShinyPalette_Whiscash: @ 0x8CFE264
	.incbin "graphics/pokemon/whiscash/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfe28c, 0x420

	.globl gMonStillFrontPic_Luvdisc
gMonStillFrontPic_Luvdisc: @ 0x8CFE6AC
	.incbin "graphics/pokemon/luvdisc/front.4bpp.lz"

	.globl gMonPalette_Luvdisc
gMonPalette_Luvdisc: @ 0x8CFE86C
	.incbin "graphics/pokemon/luvdisc/normal.gbapal.lz"

	.globl gMonBackPic_Luvdisc
gMonBackPic_Luvdisc: @ 0x8CFE890
	.incbin "graphics/pokemon/luvdisc/back.4bpp.lz"

	.globl gMonShinyPalette_Luvdisc
gMonShinyPalette_Luvdisc: @ 0x8CFEA64
	.incbin "graphics/pokemon/luvdisc/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcfea88, 0x420

	.globl gMonStillFrontPic_Corphish
gMonStillFrontPic_Corphish: @ 0x8CFEEA8
	.incbin "graphics/pokemon/corphish/front.4bpp.lz"

	.globl gMonPalette_Corphish
gMonPalette_Corphish: @ 0x8CFF204
	.incbin "graphics/pokemon/corphish/normal.gbapal.lz"

	.globl gMonBackPic_Corphish
gMonBackPic_Corphish: @ 0x8CFF22C
	.incbin "graphics/pokemon/corphish/back.4bpp.lz"

	.globl gMonShinyPalette_Corphish
gMonShinyPalette_Corphish: @ 0x8CFF548
	.incbin "graphics/pokemon/corphish/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xcff570, 0x420

	.globl gMonStillFrontPic_Crawdaunt
gMonStillFrontPic_Crawdaunt: @ 0x8CFF990
	.incbin "graphics/pokemon/crawdaunt/front.4bpp.lz"

	.globl gMonPalette_Crawdaunt
gMonPalette_Crawdaunt: @ 0x8CFFE20
	.incbin "graphics/pokemon/crawdaunt/normal.gbapal.lz"

	.globl gMonBackPic_Crawdaunt
gMonBackPic_Crawdaunt: @ 0x8CFFE48
	.incbin "graphics/pokemon/crawdaunt/back.4bpp.lz"

	.globl gMonShinyPalette_Crawdaunt
gMonShinyPalette_Crawdaunt: @ 0x8D0022C
	.incbin "graphics/pokemon/crawdaunt/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd00254, 0x420

	.globl gMonStillFrontPic_Feebas
gMonStillFrontPic_Feebas: @ 0x8D00674
	.incbin "graphics/pokemon/feebas/front.4bpp.lz"

	.globl gMonPalette_Feebas
gMonPalette_Feebas: @ 0x8D00900
	.incbin "graphics/pokemon/feebas/normal.gbapal.lz"

	.globl gMonBackPic_Feebas
gMonBackPic_Feebas: @ 0x8D00928
	.incbin "graphics/pokemon/feebas/back.4bpp.lz"

	.globl gMonShinyPalette_Feebas
gMonShinyPalette_Feebas: @ 0x8D00C60
	.incbin "graphics/pokemon/feebas/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd00c88, 0x420

	.globl gMonStillFrontPic_Milotic
gMonStillFrontPic_Milotic: @ 0x8D010A8
	.incbin "graphics/pokemon/milotic/front.4bpp.lz"

	.globl gMonPalette_Milotic
gMonPalette_Milotic: @ 0x8D01538
	.incbin "graphics/pokemon/milotic/normal.gbapal.lz"

	.globl gMonBackPic_Milotic
gMonBackPic_Milotic: @ 0x8D01560
	.incbin "graphics/pokemon/milotic/back.4bpp.lz"

	.globl gMonShinyPalette_Milotic
gMonShinyPalette_Milotic: @ 0x8D01854
	.incbin "graphics/pokemon/milotic/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0187c, 0x420

	.globl gMonStillFrontPic_Carvanha
gMonStillFrontPic_Carvanha: @ 0x8D01C9C
	.incbin "graphics/pokemon/carvanha/front.4bpp.lz"

	.globl gMonPalette_Carvanha
gMonPalette_Carvanha: @ 0x8D01FC8
	.incbin "graphics/pokemon/carvanha/normal.gbapal.lz"

	.globl gMonBackPic_Carvanha
gMonBackPic_Carvanha: @ 0x8D01FF0
	.incbin "graphics/pokemon/carvanha/back.4bpp.lz"

	.globl gMonShinyPalette_Carvanha
gMonShinyPalette_Carvanha: @ 0x8D02300
	.incbin "graphics/pokemon/carvanha/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd02328, 0x420

	.globl gMonStillFrontPic_Sharpedo
gMonStillFrontPic_Sharpedo: @ 0x8D02748
	.incbin "graphics/pokemon/sharpedo/front.4bpp.lz"

	.globl gMonPalette_Sharpedo
gMonPalette_Sharpedo: @ 0x8D02AD8
	.incbin "graphics/pokemon/sharpedo/normal.gbapal.lz"

	.globl gMonBackPic_Sharpedo
gMonBackPic_Sharpedo: @ 0x8D02B00
	.incbin "graphics/pokemon/sharpedo/back.4bpp.lz"

	.globl gMonShinyPalette_Sharpedo
gMonShinyPalette_Sharpedo: @ 0x8D02E58
	.incbin "graphics/pokemon/sharpedo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd02e80, 0x420

	.globl gMonStillFrontPic_Trapinch
gMonStillFrontPic_Trapinch: @ 0x8D032A0
	.incbin "graphics/pokemon/trapinch/front.4bpp.lz"

	.globl gMonPalette_Trapinch
gMonPalette_Trapinch: @ 0x8D034BC
	.incbin "graphics/pokemon/trapinch/normal.gbapal.lz"

	.globl gMonBackPic_Trapinch
gMonBackPic_Trapinch: @ 0x8D034E4
	.incbin "graphics/pokemon/trapinch/back.4bpp.lz"

	.globl gMonShinyPalette_Trapinch
gMonShinyPalette_Trapinch: @ 0x8D03704
	.incbin "graphics/pokemon/trapinch/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0372a, 0x422

	.globl gMonStillFrontPic_Vibrava
gMonStillFrontPic_Vibrava: @ 0x8D03B4C
	.incbin "graphics/pokemon/vibrava/front.4bpp.lz"

	.globl gMonPalette_Vibrava
gMonPalette_Vibrava: @ 0x8D03EBC
	.incbin "graphics/pokemon/vibrava/normal.gbapal.lz"

	.globl gMonBackPic_Vibrava
gMonBackPic_Vibrava: @ 0x8D03EE4
	.incbin "graphics/pokemon/vibrava/back.4bpp.lz"

	.globl gMonShinyPalette_Vibrava
gMonShinyPalette_Vibrava: @ 0x8D0415C
	.incbin "graphics/pokemon/vibrava/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd04184, 0x420

	.globl gMonStillFrontPic_Flygon
gMonStillFrontPic_Flygon: @ 0x8D045A4
	.incbin "graphics/pokemon/flygon/front.4bpp.lz"

	.globl gMonPalette_Flygon
gMonPalette_Flygon: @ 0x8D04A94
	.incbin "graphics/pokemon/flygon/normal.gbapal.lz"

	.globl gMonBackPic_Flygon
gMonBackPic_Flygon: @ 0x8D04ABC
	.incbin "graphics/pokemon/flygon/back.4bpp.lz"

	.globl gMonShinyPalette_Flygon
gMonShinyPalette_Flygon: @ 0x8D04EF8
	.incbin "graphics/pokemon/flygon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd04f20, 0x420

	.globl gMonStillFrontPic_Makuhita
gMonStillFrontPic_Makuhita: @ 0x8D05340
	.incbin "graphics/pokemon/makuhita/front.4bpp.lz"

	.globl gMonPalette_Makuhita
gMonPalette_Makuhita: @ 0x8D05658
	.incbin "graphics/pokemon/makuhita/normal.gbapal.lz"

	.globl gMonBackPic_Makuhita
gMonBackPic_Makuhita: @ 0x8D05680
	.incbin "graphics/pokemon/makuhita/back.4bpp.lz"

	.globl gMonShinyPalette_Makuhita
gMonShinyPalette_Makuhita: @ 0x8D05970
	.incbin "graphics/pokemon/makuhita/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd05994, 0x420

	.globl gMonStillFrontPic_Hariyama
gMonStillFrontPic_Hariyama: @ 0x8D05DB4
	.incbin "graphics/pokemon/hariyama/front.4bpp.lz"

	.globl gMonPalette_Hariyama
gMonPalette_Hariyama: @ 0x8D06264
	.incbin "graphics/pokemon/hariyama/normal.gbapal.lz"

	.globl gMonBackPic_Hariyama
gMonBackPic_Hariyama: @ 0x8D0628C
	.incbin "graphics/pokemon/hariyama/back.4bpp.lz"

	.globl gMonShinyPalette_Hariyama
gMonShinyPalette_Hariyama: @ 0x8D0666C
	.incbin "graphics/pokemon/hariyama/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd06694, 0x420

	.globl gMonStillFrontPic_Electrike
gMonStillFrontPic_Electrike: @ 0x8D06AB4
	.incbin "graphics/pokemon/electrike/front.4bpp.lz"

	.globl gMonPalette_Electrike
gMonPalette_Electrike: @ 0x8D06D44
	.incbin "graphics/pokemon/electrike/normal.gbapal.lz"

	.globl gMonBackPic_Electrike
gMonBackPic_Electrike: @ 0x8D06D6C
	.incbin "graphics/pokemon/electrike/back.4bpp.lz"

	.globl gMonShinyPalette_Electrike
gMonShinyPalette_Electrike: @ 0x8D06FF8
	.incbin "graphics/pokemon/electrike/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0701e, 0x422

	.globl gMonStillFrontPic_Manectric
gMonStillFrontPic_Manectric: @ 0x8D07440
	.incbin "graphics/pokemon/manectric/front.4bpp.lz"

	.globl gMonPalette_Manectric
gMonPalette_Manectric: @ 0x8D07770
	.incbin "graphics/pokemon/manectric/normal.gbapal.lz"

	.globl gMonBackPic_Manectric
gMonBackPic_Manectric: @ 0x8D07798
	.incbin "graphics/pokemon/manectric/back.4bpp.lz"

	.globl gMonShinyPalette_Manectric
gMonShinyPalette_Manectric: @ 0x8D079C4
	.incbin "graphics/pokemon/manectric/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd079ec, 0x420

	.globl gMonStillFrontPic_Numel
gMonStillFrontPic_Numel: @ 0x8D07E0C
	.incbin "graphics/pokemon/numel/front.4bpp.lz"

	.globl gMonPalette_Numel
gMonPalette_Numel: @ 0x8D080DC
	.incbin "graphics/pokemon/numel/normal.gbapal.lz"

	.globl gMonBackPic_Numel
gMonBackPic_Numel: @ 0x8D08104
	.incbin "graphics/pokemon/numel/back.4bpp.lz"

	.globl gMonShinyPalette_Numel
gMonShinyPalette_Numel: @ 0x8D083C0
	.incbin "graphics/pokemon/numel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd083e8, 0x420

	.globl gMonStillFrontPic_Camerupt
gMonStillFrontPic_Camerupt: @ 0x8D08808
	.incbin "graphics/pokemon/camerupt/front.4bpp.lz"

	.globl gMonPalette_Camerupt
gMonPalette_Camerupt: @ 0x8D08C20
	.incbin "graphics/pokemon/camerupt/normal.gbapal.lz"

	.globl gMonBackPic_Camerupt
gMonBackPic_Camerupt: @ 0x8D08C48
	.incbin "graphics/pokemon/camerupt/back.4bpp.lz"

	.globl gMonShinyPalette_Camerupt
gMonShinyPalette_Camerupt: @ 0x8D08F0C
	.incbin "graphics/pokemon/camerupt/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd08f34, 0x420

	.globl gMonStillFrontPic_Spheal
gMonStillFrontPic_Spheal: @ 0x8D09354
	.incbin "graphics/pokemon/spheal/front.4bpp.lz"

	.globl gMonPalette_Spheal
gMonPalette_Spheal: @ 0x8D095C8
	.incbin "graphics/pokemon/spheal/normal.gbapal.lz"

	.globl gMonBackPic_Spheal
gMonBackPic_Spheal: @ 0x8D095F0
	.incbin "graphics/pokemon/spheal/back.4bpp.lz"

	.globl gMonShinyPalette_Spheal
gMonShinyPalette_Spheal: @ 0x8D097EC
	.incbin "graphics/pokemon/spheal/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd09812, 0x422

	.globl gMonStillFrontPic_Sealeo
gMonStillFrontPic_Sealeo: @ 0x8D09C34
	.incbin "graphics/pokemon/sealeo/front.4bpp.lz"

	.globl gMonPalette_Sealeo
gMonPalette_Sealeo: @ 0x8D09FB4
	.incbin "graphics/pokemon/sealeo/normal.gbapal.lz"

	.globl gMonBackPic_Sealeo
gMonBackPic_Sealeo: @ 0x8D09FDC
	.incbin "graphics/pokemon/sealeo/back.4bpp.lz"

	.globl gMonShinyPalette_Sealeo
gMonShinyPalette_Sealeo: @ 0x8D0A258
	.incbin "graphics/pokemon/sealeo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0a280, 0x420

	.globl gMonStillFrontPic_Walrein
gMonStillFrontPic_Walrein: @ 0x8D0A6A0
	.incbin "graphics/pokemon/walrein/front.4bpp.lz"

	.globl gMonPalette_Walrein
gMonPalette_Walrein: @ 0x8D0AE14
	.incbin "graphics/pokemon/walrein/normal.gbapal.lz"

	.globl gMonBackPic_Walrein
gMonBackPic_Walrein: @ 0x8D0AE3C
	.incbin "graphics/pokemon/walrein/back.4bpp.lz"

	.globl gMonShinyPalette_Walrein
gMonShinyPalette_Walrein: @ 0x8D0B1C4
	.incbin "graphics/pokemon/walrein/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0b1ec, 0x420

	.globl gMonStillFrontPic_Cacnea
gMonStillFrontPic_Cacnea: @ 0x8D0B60C
	.incbin "graphics/pokemon/cacnea/front.4bpp.lz"

	.globl gMonPalette_Cacnea
gMonPalette_Cacnea: @ 0x8D0B91C
	.incbin "graphics/pokemon/cacnea/normal.gbapal.lz"

	.globl gMonBackPic_Cacnea
gMonBackPic_Cacnea: @ 0x8D0B944
	.incbin "graphics/pokemon/cacnea/back.4bpp.lz"

	.globl gMonShinyPalette_Cacnea
gMonShinyPalette_Cacnea: @ 0x8D0BCA4
	.incbin "graphics/pokemon/cacnea/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0bccc, 0x420

	.globl gMonStillFrontPic_Cacturne
gMonStillFrontPic_Cacturne: @ 0x8D0C0EC
	.incbin "graphics/pokemon/cacturne/front.4bpp.lz"

	.globl gMonPalette_Cacturne
gMonPalette_Cacturne: @ 0x8D0C524
	.incbin "graphics/pokemon/cacturne/normal.gbapal.lz"

	.globl gMonBackPic_Cacturne
gMonBackPic_Cacturne: @ 0x8D0C54C
	.incbin "graphics/pokemon/cacturne/back.4bpp.lz"

	.globl gMonShinyPalette_Cacturne
gMonShinyPalette_Cacturne: @ 0x8D0C84C
	.incbin "graphics/pokemon/cacturne/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0c874, 0x420

	.globl gMonStillFrontPic_Snorunt
gMonStillFrontPic_Snorunt: @ 0x8D0CC94
	.incbin "graphics/pokemon/snorunt/front.4bpp.lz"

	.globl gMonPalette_Snorunt
gMonPalette_Snorunt: @ 0x8D0CF58
	.incbin "graphics/pokemon/snorunt/normal.gbapal.lz"

	.globl gMonBackPic_Snorunt
gMonBackPic_Snorunt: @ 0x8D0CF80
	.incbin "graphics/pokemon/snorunt/back.4bpp.lz"

	.globl gMonShinyPalette_Snorunt
gMonShinyPalette_Snorunt: @ 0x8D0D264
	.incbin "graphics/pokemon/snorunt/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0d28c, 0x420

	.globl gMonStillFrontPic_Glalie
gMonStillFrontPic_Glalie: @ 0x8D0D6AC
	.incbin "graphics/pokemon/glalie/front.4bpp.lz"

	.globl gMonPalette_Glalie
gMonPalette_Glalie: @ 0x8D0DA74
	.incbin "graphics/pokemon/glalie/normal.gbapal.lz"

	.globl gMonBackPic_Glalie
gMonBackPic_Glalie: @ 0x8D0DA9C
	.incbin "graphics/pokemon/glalie/back.4bpp.lz"

	.globl gMonShinyPalette_Glalie
gMonShinyPalette_Glalie: @ 0x8D0DE4C
	.incbin "graphics/pokemon/glalie/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0de74, 0x420

	.globl gMonStillFrontPic_Lunatone
gMonStillFrontPic_Lunatone: @ 0x8D0E294
	.incbin "graphics/pokemon/lunatone/front.4bpp.lz"

	.globl gMonPalette_Lunatone
gMonPalette_Lunatone: @ 0x8D0E5BC
	.incbin "graphics/pokemon/lunatone/normal.gbapal.lz"

	.globl gMonBackPic_Lunatone
gMonBackPic_Lunatone: @ 0x8D0E5E4
	.incbin "graphics/pokemon/lunatone/back.4bpp.lz"

	.globl gMonShinyPalette_Lunatone
gMonShinyPalette_Lunatone: @ 0x8D0E93C
	.incbin "graphics/pokemon/lunatone/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0e964, 0x420

	.globl gMonStillFrontPic_Solrock
gMonStillFrontPic_Solrock: @ 0x8D0ED84
	.incbin "graphics/pokemon/solrock/front.4bpp.lz"

	.globl gMonPalette_Solrock
gMonPalette_Solrock: @ 0x8D0F1D0
	.incbin "graphics/pokemon/solrock/normal.gbapal.lz"

	.globl gMonBackPic_Solrock
gMonBackPic_Solrock: @ 0x8D0F1F8
	.incbin "graphics/pokemon/solrock/back.4bpp.lz"

	.globl gMonShinyPalette_Solrock
gMonShinyPalette_Solrock: @ 0x8D0F5E4
	.incbin "graphics/pokemon/solrock/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd0f60c, 0x420

	.globl gMonStillFrontPic_Azurill
gMonStillFrontPic_Azurill: @ 0x8D0FA2C
	.incbin "graphics/pokemon/azurill/front.4bpp.lz"

	.globl gMonPalette_Azurill
gMonPalette_Azurill: @ 0x8D0FCF4
	.incbin "graphics/pokemon/azurill/normal.gbapal.lz"

	.globl gMonBackPic_Azurill
gMonBackPic_Azurill: @ 0x8D0FD1C
	.incbin "graphics/pokemon/azurill/back.4bpp.lz"

	.globl gMonShinyPalette_Azurill
gMonShinyPalette_Azurill: @ 0x8D10034
	.incbin "graphics/pokemon/azurill/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1005c, 0x420

	.globl gMonStillFrontPic_Spoink
gMonStillFrontPic_Spoink: @ 0x8D1047C
	.incbin "graphics/pokemon/spoink/front.4bpp.lz"

	.globl gMonPalette_Spoink
gMonPalette_Spoink: @ 0x8D106E8
	.incbin "graphics/pokemon/spoink/normal.gbapal.lz"

	.globl gMonBackPic_Spoink
gMonBackPic_Spoink: @ 0x8D10710
	.incbin "graphics/pokemon/spoink/back.4bpp.lz"

	.globl gMonShinyPalette_Spoink
gMonShinyPalette_Spoink: @ 0x8D10950
	.incbin "graphics/pokemon/spoink/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd10978, 0x420

	.globl gMonStillFrontPic_Grumpig
gMonStillFrontPic_Grumpig: @ 0x8D10D98
	.incbin "graphics/pokemon/grumpig/front.4bpp.lz"

	.globl gMonPalette_Grumpig
gMonPalette_Grumpig: @ 0x8D11154
	.incbin "graphics/pokemon/grumpig/normal.gbapal.lz"

	.globl gMonBackPic_Grumpig
gMonBackPic_Grumpig: @ 0x8D1117C
	.incbin "graphics/pokemon/grumpig/back.4bpp.lz"

	.globl gMonShinyPalette_Grumpig
gMonShinyPalette_Grumpig: @ 0x8D114DC
	.incbin "graphics/pokemon/grumpig/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd11504, 0x420

	.globl gMonStillFrontPic_Plusle
gMonStillFrontPic_Plusle: @ 0x8D11924
	.incbin "graphics/pokemon/plusle/front.4bpp.lz"

	.globl gMonPalette_Plusle
gMonPalette_Plusle: @ 0x8D11BB0
	.incbin "graphics/pokemon/plusle/normal.gbapal.lz"

	.globl gMonBackPic_Plusle
gMonBackPic_Plusle: @ 0x8D11BD8
	.incbin "graphics/pokemon/plusle/back.4bpp.lz"

	.globl gMonShinyPalette_Plusle
gMonShinyPalette_Plusle: @ 0x8D11E90
	.incbin "graphics/pokemon/plusle/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd11eb8, 0x420

	.globl gMonStillFrontPic_Minun
gMonStillFrontPic_Minun: @ 0x8D122D8
	.incbin "graphics/pokemon/minun/front.4bpp.lz"

	.globl gMonPalette_Minun
gMonPalette_Minun: @ 0x8D12540
	.incbin "graphics/pokemon/minun/normal.gbapal.lz"

	.globl gMonBackPic_Minun
gMonBackPic_Minun: @ 0x8D12568
	.incbin "graphics/pokemon/minun/back.4bpp.lz"

	.globl gMonShinyPalette_Minun
gMonShinyPalette_Minun: @ 0x8D12830
	.incbin "graphics/pokemon/minun/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd12858, 0x420

	.globl gMonStillFrontPic_Mawile
gMonStillFrontPic_Mawile: @ 0x8D12C78
	.incbin "graphics/pokemon/mawile/front.4bpp.lz"

	.globl gMonPalette_Mawile
gMonPalette_Mawile: @ 0x8D13034
	.incbin "graphics/pokemon/mawile/normal.gbapal.lz"

	.globl gMonBackPic_Mawile
gMonBackPic_Mawile: @ 0x8D1305C
	.incbin "graphics/pokemon/mawile/back.4bpp.lz"

	.globl gMonShinyPalette_Mawile
gMonShinyPalette_Mawile: @ 0x8D1345C
	.incbin "graphics/pokemon/mawile/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd13484, 0x420

	.globl gMonStillFrontPic_Meditite
gMonStillFrontPic_Meditite: @ 0x8D138A4
	.incbin "graphics/pokemon/meditite/front.4bpp.lz"

	.globl gMonPalette_Meditite
gMonPalette_Meditite: @ 0x8D13B5C
	.incbin "graphics/pokemon/meditite/normal.gbapal.lz"

	.globl gMonBackPic_Meditite
gMonBackPic_Meditite: @ 0x8D13B84
	.incbin "graphics/pokemon/meditite/back.4bpp.lz"

	.globl gMonShinyPalette_Meditite
gMonShinyPalette_Meditite: @ 0x8D13E4C
	.incbin "graphics/pokemon/meditite/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd13e70, 0x420

	.globl gMonStillFrontPic_Medicham
gMonStillFrontPic_Medicham: @ 0x8D14290
	.incbin "graphics/pokemon/medicham/front.4bpp.lz"

	.globl gMonPalette_Medicham
gMonPalette_Medicham: @ 0x8D145C0
	.incbin "graphics/pokemon/medicham/normal.gbapal.lz"

	.globl gMonBackPic_Medicham
gMonBackPic_Medicham: @ 0x8D145E8
	.incbin "graphics/pokemon/medicham/back.4bpp.lz"

	.globl gMonShinyPalette_Medicham
gMonShinyPalette_Medicham: @ 0x8D14920
	.incbin "graphics/pokemon/medicham/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd14948, 0x420

	.globl gMonStillFrontPic_Swablu
gMonStillFrontPic_Swablu: @ 0x8D14D68
	.incbin "graphics/pokemon/swablu/front.4bpp.lz"

	.globl gMonPalette_Swablu
gMonPalette_Swablu: @ 0x8D15318
	.incbin "graphics/pokemon/swablu/normal.gbapal.lz"

	.globl gMonBackPic_Swablu
gMonBackPic_Swablu: @ 0x8D15340
	.incbin "graphics/pokemon/swablu/back.4bpp.lz"

	.globl gMonShinyPalette_Swablu
gMonShinyPalette_Swablu: @ 0x8D156F8
	.incbin "graphics/pokemon/swablu/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd15720, 0x420

	.globl gMonStillFrontPic_Altaria
gMonStillFrontPic_Altaria: @ 0x8D15B40
	.incbin "graphics/pokemon/altaria/front.4bpp.lz"

	.globl gMonPalette_Altaria
gMonPalette_Altaria: @ 0x8D15F1C
	.incbin "graphics/pokemon/altaria/normal.gbapal.lz"

	.globl gMonBackPic_Altaria
gMonBackPic_Altaria: @ 0x8D15F44
	.incbin "graphics/pokemon/altaria/back.4bpp.lz"

	.globl gMonShinyPalette_Altaria
gMonShinyPalette_Altaria: @ 0x8D162BC
	.incbin "graphics/pokemon/altaria/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd162e4, 0x420

	.globl gMonStillFrontPic_Wynaut
gMonStillFrontPic_Wynaut: @ 0x8D16704
	.incbin "graphics/pokemon/wynaut/front.4bpp.lz"

	.globl gMonPalette_Wynaut
gMonPalette_Wynaut: @ 0x8D1699C
	.incbin "graphics/pokemon/wynaut/normal.gbapal.lz"

	.globl gMonBackPic_Wynaut
gMonBackPic_Wynaut: @ 0x8D169C4
	.incbin "graphics/pokemon/wynaut/back.4bpp.lz"

	.globl gMonShinyPalette_Wynaut
gMonShinyPalette_Wynaut: @ 0x8D16C54
	.incbin "graphics/pokemon/wynaut/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd16c7c, 0x420

	.globl gMonStillFrontPic_Duskull
gMonStillFrontPic_Duskull: @ 0x8D1709C
	.incbin "graphics/pokemon/duskull/front.4bpp.lz"

	.globl gMonPalette_Duskull
gMonPalette_Duskull: @ 0x8D1738C
	.incbin "graphics/pokemon/duskull/normal.gbapal.lz"

	.globl gMonBackPic_Duskull
gMonBackPic_Duskull: @ 0x8D173B4
	.incbin "graphics/pokemon/duskull/back.4bpp.lz"

	.globl gMonShinyPalette_Duskull
gMonShinyPalette_Duskull: @ 0x8D17664
	.incbin "graphics/pokemon/duskull/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1768c, 0x420

	.globl gMonStillFrontPic_Dusclops
gMonStillFrontPic_Dusclops: @ 0x8D17AAC
	.incbin "graphics/pokemon/dusclops/front.4bpp.lz"

	.globl gMonPalette_Dusclops
gMonPalette_Dusclops: @ 0x8D17E4C
	.incbin "graphics/pokemon/dusclops/normal.gbapal.lz"

	.globl gMonBackPic_Dusclops
gMonBackPic_Dusclops: @ 0x8D17E74
	.incbin "graphics/pokemon/dusclops/back.4bpp.lz"

	.globl gMonShinyPalette_Dusclops
gMonShinyPalette_Dusclops: @ 0x8D18160
	.incbin "graphics/pokemon/dusclops/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd18186, 0x422

	.globl gMonStillFrontPic_Roselia
gMonStillFrontPic_Roselia: @ 0x8D185A8
	.incbin "graphics/pokemon/roselia/front.4bpp.lz"

	.globl gMonPalette_Roselia
gMonPalette_Roselia: @ 0x8D18914
	.incbin "graphics/pokemon/roselia/normal.gbapal.lz"

	.globl gMonBackPic_Roselia
gMonBackPic_Roselia: @ 0x8D1893C
	.incbin "graphics/pokemon/roselia/back.4bpp.lz"

	.globl gMonShinyPalette_Roselia
gMonShinyPalette_Roselia: @ 0x8D18D04
	.incbin "graphics/pokemon/roselia/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd18d2c, 0x420

	.globl gMonStillFrontPic_Slakoth
gMonStillFrontPic_Slakoth: @ 0x8D1914C
	.incbin "graphics/pokemon/slakoth/front.4bpp.lz"

	.globl gMonPalette_Slakoth
gMonPalette_Slakoth: @ 0x8D19434
	.incbin "graphics/pokemon/slakoth/normal.gbapal.lz"

	.globl gMonBackPic_Slakoth
gMonBackPic_Slakoth: @ 0x8D1945C
	.incbin "graphics/pokemon/slakoth/back.4bpp.lz"

	.globl gMonShinyPalette_Slakoth
gMonShinyPalette_Slakoth: @ 0x8D19744
	.incbin "graphics/pokemon/slakoth/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1976c, 0x420

	.globl gMonStillFrontPic_Vigoroth
gMonStillFrontPic_Vigoroth: @ 0x8D19B8C
	.incbin "graphics/pokemon/vigoroth/front.4bpp.lz"

	.globl gMonPalette_Vigoroth
gMonPalette_Vigoroth: @ 0x8D19F88
	.incbin "graphics/pokemon/vigoroth/normal.gbapal.lz"

	.globl gMonBackPic_Vigoroth
gMonBackPic_Vigoroth: @ 0x8D19FB0
	.incbin "graphics/pokemon/vigoroth/back.4bpp.lz"

	.globl gMonShinyPalette_Vigoroth
gMonShinyPalette_Vigoroth: @ 0x8D1A278
	.incbin "graphics/pokemon/vigoroth/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1a2a0, 0x420

	.globl gMonStillFrontPic_Slaking
gMonStillFrontPic_Slaking: @ 0x8D1A6C0
	.incbin "graphics/pokemon/slaking/front.4bpp.lz"

	.globl gMonPalette_Slaking
gMonPalette_Slaking: @ 0x8D1AB94
	.incbin "graphics/pokemon/slaking/normal.gbapal.lz"

	.globl gMonBackPic_Slaking
gMonBackPic_Slaking: @ 0x8D1ABBC
	.incbin "graphics/pokemon/slaking/back.4bpp.lz"

	.globl gMonShinyPalette_Slaking
gMonShinyPalette_Slaking: @ 0x8D1AF80
	.incbin "graphics/pokemon/slaking/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1afa8, 0x420

	.globl gMonStillFrontPic_Gulpin
gMonStillFrontPic_Gulpin: @ 0x8D1B3C8
	.incbin "graphics/pokemon/gulpin/front.4bpp.lz"

	.globl gMonPalette_Gulpin
gMonPalette_Gulpin: @ 0x8D1B5E0
	.incbin "graphics/pokemon/gulpin/normal.gbapal.lz"

	.globl gMonBackPic_Gulpin
gMonBackPic_Gulpin: @ 0x8D1B608
	.incbin "graphics/pokemon/gulpin/back.4bpp.lz"

	.globl gMonShinyPalette_Gulpin
gMonShinyPalette_Gulpin: @ 0x8D1B88C
	.incbin "graphics/pokemon/gulpin/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1b8b4, 0x420

	.globl gMonStillFrontPic_Swalot
gMonStillFrontPic_Swalot: @ 0x8D1BCD4
	.incbin "graphics/pokemon/swalot/front.4bpp.lz"

	.globl gMonPalette_Swalot
gMonPalette_Swalot: @ 0x8D1C018
	.incbin "graphics/pokemon/swalot/normal.gbapal.lz"

	.globl gMonBackPic_Swalot
gMonBackPic_Swalot: @ 0x8D1C040
	.incbin "graphics/pokemon/swalot/back.4bpp.lz"

	.globl gMonShinyPalette_Swalot
gMonShinyPalette_Swalot: @ 0x8D1C388
	.incbin "graphics/pokemon/swalot/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1c3b0, 0x420

	.globl gMonStillFrontPic_Tropius
gMonStillFrontPic_Tropius: @ 0x8D1C7D0
	.incbin "graphics/pokemon/tropius/front.4bpp.lz"

	.globl gMonPalette_Tropius
gMonPalette_Tropius: @ 0x8D1CD48
	.incbin "graphics/pokemon/tropius/normal.gbapal.lz"

	.globl gMonBackPic_Tropius
gMonBackPic_Tropius: @ 0x8D1CD70
	.incbin "graphics/pokemon/tropius/back.4bpp.lz"

	.globl gMonShinyPalette_Tropius
gMonShinyPalette_Tropius: @ 0x8D1D094
	.incbin "graphics/pokemon/tropius/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1d0bc, 0x420

	.globl gMonStillFrontPic_Whismur
gMonStillFrontPic_Whismur: @ 0x8D1D4DC
	.incbin "graphics/pokemon/whismur/front.4bpp.lz"

	.globl gMonPalette_Whismur
gMonPalette_Whismur: @ 0x8D1D770
	.incbin "graphics/pokemon/whismur/normal.gbapal.lz"

	.globl gMonBackPic_Whismur
gMonBackPic_Whismur: @ 0x8D1D798
	.incbin "graphics/pokemon/whismur/back.4bpp.lz"

	.globl gMonShinyPalette_Whismur
gMonShinyPalette_Whismur: @ 0x8D1DA08
	.incbin "graphics/pokemon/whismur/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1da30, 0x420

	.globl gMonStillFrontPic_Loudred
gMonStillFrontPic_Loudred: @ 0x8D1DE50
	.incbin "graphics/pokemon/loudred/front.4bpp.lz"

	.globl gMonPalette_Loudred
gMonPalette_Loudred: @ 0x8D1E2C8
	.incbin "graphics/pokemon/loudred/normal.gbapal.lz"

	.globl gMonBackPic_Loudred
gMonBackPic_Loudred: @ 0x8D1E2F0
	.incbin "graphics/pokemon/loudred/back.4bpp.lz"

	.globl gMonShinyPalette_Loudred
gMonShinyPalette_Loudred: @ 0x8D1E660
	.incbin "graphics/pokemon/loudred/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1e688, 0x420

	.globl gMonStillFrontPic_Exploud
gMonStillFrontPic_Exploud: @ 0x8D1EAA8
	.incbin "graphics/pokemon/exploud/front.4bpp.lz"

	.globl gMonPalette_Exploud
gMonPalette_Exploud: @ 0x8D1F010
	.incbin "graphics/pokemon/exploud/normal.gbapal.lz"

	.globl gMonBackPic_Exploud
gMonBackPic_Exploud: @ 0x8D1F038
	.incbin "graphics/pokemon/exploud/back.4bpp.lz"

	.globl gMonShinyPalette_Exploud
gMonShinyPalette_Exploud: @ 0x8D1F444
	.incbin "graphics/pokemon/exploud/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1f46c, 0x420

	.globl gMonStillFrontPic_Clamperl
gMonStillFrontPic_Clamperl: @ 0x8D1F88C
	.incbin "graphics/pokemon/clamperl/front.4bpp.lz"

	.globl gMonPalette_Clamperl
gMonPalette_Clamperl: @ 0x8D1FB64
	.incbin "graphics/pokemon/clamperl/normal.gbapal.lz"

	.globl gMonBackPic_Clamperl
gMonBackPic_Clamperl: @ 0x8D1FB8C
	.incbin "graphics/pokemon/clamperl/back.4bpp.lz"

	.globl gMonShinyPalette_Clamperl
gMonShinyPalette_Clamperl: @ 0x8D1FE20
	.incbin "graphics/pokemon/clamperl/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd1fe48, 0x420

	.globl gMonStillFrontPic_Huntail
gMonStillFrontPic_Huntail: @ 0x8D20268
	.incbin "graphics/pokemon/huntail/front.4bpp.lz"

	.globl gMonPalette_Huntail
gMonPalette_Huntail: @ 0x8D20634
	.incbin "graphics/pokemon/huntail/normal.gbapal.lz"

	.globl gMonBackPic_Huntail
gMonBackPic_Huntail: @ 0x8D2065C
	.incbin "graphics/pokemon/huntail/back.4bpp.lz"

	.globl gMonShinyPalette_Huntail
gMonShinyPalette_Huntail: @ 0x8D209B0
	.incbin "graphics/pokemon/huntail/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd209d8, 0x420

	.globl gMonStillFrontPic_Gorebyss
gMonStillFrontPic_Gorebyss: @ 0x8D20DF8
	.incbin "graphics/pokemon/gorebyss/front.4bpp.lz"

	.globl gMonPalette_Gorebyss
gMonPalette_Gorebyss: @ 0x8D21108
	.incbin "graphics/pokemon/gorebyss/normal.gbapal.lz"

	.globl gMonBackPic_Gorebyss
gMonBackPic_Gorebyss: @ 0x8D21130
	.incbin "graphics/pokemon/gorebyss/back.4bpp.lz"

	.globl gMonShinyPalette_Gorebyss
gMonShinyPalette_Gorebyss: @ 0x8D21418
	.incbin "graphics/pokemon/gorebyss/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd21440, 0x420

	.globl gMonStillFrontPic_Absol
gMonStillFrontPic_Absol: @ 0x8D21860
	.incbin "graphics/pokemon/absol/front.4bpp.lz"

	.globl gMonPalette_Absol
gMonPalette_Absol: @ 0x8D21C90
	.incbin "graphics/pokemon/absol/normal.gbapal.lz"

	.globl gMonBackPic_Absol
gMonBackPic_Absol: @ 0x8D21CB8
	.incbin "graphics/pokemon/absol/back.4bpp.lz"

	.globl gMonShinyPalette_Absol
gMonShinyPalette_Absol: @ 0x8D22018
	.incbin "graphics/pokemon/absol/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd22040, 0x420

	.globl gMonStillFrontPic_Shuppet
gMonStillFrontPic_Shuppet: @ 0x8D22460
	.incbin "graphics/pokemon/shuppet/front.4bpp.lz"

	.globl gMonPalette_Shuppet
gMonPalette_Shuppet: @ 0x8D22698
	.incbin "graphics/pokemon/shuppet/normal.gbapal.lz"

	.globl gMonBackPic_Shuppet
gMonBackPic_Shuppet: @ 0x8D226C0
	.incbin "graphics/pokemon/shuppet/back.4bpp.lz"

	.globl gMonShinyPalette_Shuppet
gMonShinyPalette_Shuppet: @ 0x8D22958
	.incbin "graphics/pokemon/shuppet/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2297e, 0x422

	.globl gMonStillFrontPic_Banette
gMonStillFrontPic_Banette: @ 0x8D22DA0
	.incbin "graphics/pokemon/banette/front.4bpp.lz"

	.globl gMonPalette_Banette
gMonPalette_Banette: @ 0x8D23054
	.incbin "graphics/pokemon/banette/normal.gbapal.lz"

	.globl gMonBackPic_Banette
gMonBackPic_Banette: @ 0x8D2307C
	.incbin "graphics/pokemon/banette/back.4bpp.lz"

	.globl gMonShinyPalette_Banette
gMonShinyPalette_Banette: @ 0x8D232F8
	.incbin "graphics/pokemon/banette/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd23320, 0x420

	.globl gMonStillFrontPic_Seviper
gMonStillFrontPic_Seviper: @ 0x8D23740
	.incbin "graphics/pokemon/seviper/front.4bpp.lz"

	.globl gMonPalette_Seviper
gMonPalette_Seviper: @ 0x8D23B60
	.incbin "graphics/pokemon/seviper/normal.gbapal.lz"

	.globl gMonBackPic_Seviper
gMonBackPic_Seviper: @ 0x8D23B88
	.incbin "graphics/pokemon/seviper/back.4bpp.lz"

	.globl gMonShinyPalette_Seviper
gMonShinyPalette_Seviper: @ 0x8D24014
	.incbin "graphics/pokemon/seviper/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2403c, 0x420

	.globl gMonStillFrontPic_Zangoose
gMonStillFrontPic_Zangoose: @ 0x8D2445C
	.incbin "graphics/pokemon/zangoose/front.4bpp.lz"

	.globl gMonPalette_Zangoose
gMonPalette_Zangoose: @ 0x8D24828
	.incbin "graphics/pokemon/zangoose/normal.gbapal.lz"

	.globl gMonBackPic_Zangoose
gMonBackPic_Zangoose: @ 0x8D24850
	.incbin "graphics/pokemon/zangoose/back.4bpp.lz"

	.globl gMonShinyPalette_Zangoose
gMonShinyPalette_Zangoose: @ 0x8D24BC4
	.incbin "graphics/pokemon/zangoose/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd24bec, 0x420

	.globl gMonStillFrontPic_Relicanth
gMonStillFrontPic_Relicanth: @ 0x8D2500C
	.incbin "graphics/pokemon/relicanth/front.4bpp.lz"

	.globl gMonPalette_Relicanth
gMonPalette_Relicanth: @ 0x8D253A0
	.incbin "graphics/pokemon/relicanth/normal.gbapal.lz"

	.globl gMonBackPic_Relicanth
gMonBackPic_Relicanth: @ 0x8D253C8
	.incbin "graphics/pokemon/relicanth/back.4bpp.lz"

	.globl gMonShinyPalette_Relicanth
gMonShinyPalette_Relicanth: @ 0x8D25720
	.incbin "graphics/pokemon/relicanth/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd25748, 0x420

	.globl gMonStillFrontPic_Aron
gMonStillFrontPic_Aron: @ 0x8D25B68
	.incbin "graphics/pokemon/aron/front.4bpp.lz"

	.globl gMonPalette_Aron
gMonPalette_Aron: @ 0x8D25D50
	.incbin "graphics/pokemon/aron/normal.gbapal.lz"

	.globl gMonBackPic_Aron
gMonBackPic_Aron: @ 0x8D25D78
	.incbin "graphics/pokemon/aron/back.4bpp.lz"

	.globl gMonShinyPalette_Aron
gMonShinyPalette_Aron: @ 0x8D25FA0
	.incbin "graphics/pokemon/aron/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd25fc8, 0x420

	.globl gMonStillFrontPic_Lairon
gMonStillFrontPic_Lairon: @ 0x8D263E8
	.incbin "graphics/pokemon/lairon/front.4bpp.lz"

	.globl gMonPalette_Lairon
gMonPalette_Lairon: @ 0x8D267B4
	.incbin "graphics/pokemon/lairon/normal.gbapal.lz"

	.globl gMonBackPic_Lairon
gMonBackPic_Lairon: @ 0x8D267DC
	.incbin "graphics/pokemon/lairon/back.4bpp.lz"

	.globl gMonShinyPalette_Lairon
gMonShinyPalette_Lairon: @ 0x8D26AC8
	.incbin "graphics/pokemon/lairon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd26af0, 0x420

	.globl gMonStillFrontPic_Aggron
gMonStillFrontPic_Aggron: @ 0x8D26F10
	.incbin "graphics/pokemon/aggron/front.4bpp.lz"

	.globl gMonPalette_Aggron
gMonPalette_Aggron: @ 0x8D2748C
	.incbin "graphics/pokemon/aggron/normal.gbapal.lz"

	.globl gMonBackPic_Aggron
gMonBackPic_Aggron: @ 0x8D274B4
	.incbin "graphics/pokemon/aggron/back.4bpp.lz"

	.globl gMonShinyPalette_Aggron
gMonShinyPalette_Aggron: @ 0x8D278DC
	.incbin "graphics/pokemon/aggron/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd27904, 0x420

	.globl gMonStillFrontPic_Castform
gMonStillFrontPic_Castform: @ 0x8D27D24
	.incbin "graphics/pokemon/castform/front.4bpp.lz"

	.globl gMonPalette_Castform
gMonPalette_Castform: @ 0x8D287AC
	.incbin "graphics/pokemon/castform/normal.gbapal.lz"

	.globl gMonBackPic_Castform
gMonBackPic_Castform: @ 0x8D2882C
	.incbin "graphics/pokemon/castform/back.4bpp.lz"

	.globl gMonShinyPalette_Castform
gMonShinyPalette_Castform: @ 0x8D291E8
	.incbin "graphics/pokemon/castform/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd29264, 0x420

	.globl gMonStillFrontPic_Volbeat
gMonStillFrontPic_Volbeat: @ 0x8D29684
	.incbin "graphics/pokemon/volbeat/front.4bpp.lz"

	.globl gMonPalette_Volbeat
gMonPalette_Volbeat: @ 0x8D29A14
	.incbin "graphics/pokemon/volbeat/normal.gbapal.lz"

	.globl gMonBackPic_Volbeat
gMonBackPic_Volbeat: @ 0x8D29A3C
	.incbin "graphics/pokemon/volbeat/back.4bpp.lz"

	.globl gMonShinyPalette_Volbeat
gMonShinyPalette_Volbeat: @ 0x8D29D9C
	.incbin "graphics/pokemon/volbeat/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd29dc4, 0x420

	.globl gMonStillFrontPic_Illumise
gMonStillFrontPic_Illumise: @ 0x8D2A1E4
	.incbin "graphics/pokemon/illumise/front.4bpp.lz"

	.globl gMonPalette_Illumise
gMonPalette_Illumise: @ 0x8D2A558
	.incbin "graphics/pokemon/illumise/normal.gbapal.lz"

	.globl gMonBackPic_Illumise
gMonBackPic_Illumise: @ 0x8D2A580
	.incbin "graphics/pokemon/illumise/back.4bpp.lz"

	.globl gMonShinyPalette_Illumise
gMonShinyPalette_Illumise: @ 0x8D2A89C
	.incbin "graphics/pokemon/illumise/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2a8c4, 0x420

	.globl gMonStillFrontPic_Lileep
gMonStillFrontPic_Lileep: @ 0x8D2ACE4
	.incbin "graphics/pokemon/lileep/front.4bpp.lz"

	.globl gMonPalette_Lileep
gMonPalette_Lileep: @ 0x8D2B028
	.incbin "graphics/pokemon/lileep/normal.gbapal.lz"

	.globl gMonBackPic_Lileep
gMonBackPic_Lileep: @ 0x8D2B050
	.incbin "graphics/pokemon/lileep/back.4bpp.lz"

	.globl gMonShinyPalette_Lileep
gMonShinyPalette_Lileep: @ 0x8D2B394
	.incbin "graphics/pokemon/lileep/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2b3bc, 0x420

	.globl gMonStillFrontPic_Cradily
gMonStillFrontPic_Cradily: @ 0x8D2B7DC
	.incbin "graphics/pokemon/cradily/front.4bpp.lz"

	.globl gMonPalette_Cradily
gMonPalette_Cradily: @ 0x8D2BBF8
	.incbin "graphics/pokemon/cradily/normal.gbapal.lz"

	.globl gMonBackPic_Cradily
gMonBackPic_Cradily: @ 0x8D2BC20
	.incbin "graphics/pokemon/cradily/back.4bpp.lz"

	.globl gMonShinyPalette_Cradily
gMonShinyPalette_Cradily: @ 0x8D2C01C
	.incbin "graphics/pokemon/cradily/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2c044, 0x420

	.globl gMonStillFrontPic_Anorith
gMonStillFrontPic_Anorith: @ 0x8D2C464
	.incbin "graphics/pokemon/anorith/front.4bpp.lz"

	.globl gMonPalette_Anorith
gMonPalette_Anorith: @ 0x8D2C788
	.incbin "graphics/pokemon/anorith/normal.gbapal.lz"

	.globl gMonBackPic_Anorith
gMonBackPic_Anorith: @ 0x8D2C7B0
	.incbin "graphics/pokemon/anorith/back.4bpp.lz"

	.globl gMonShinyPalette_Anorith
gMonShinyPalette_Anorith: @ 0x8D2C9F8
	.incbin "graphics/pokemon/anorith/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2ca20, 0x420

	.globl gMonStillFrontPic_Armaldo
gMonStillFrontPic_Armaldo: @ 0x8D2CE40
	.incbin "graphics/pokemon/armaldo/front.4bpp.lz"

	.globl gMonPalette_Armaldo
gMonPalette_Armaldo: @ 0x8D2D3C0
	.incbin "graphics/pokemon/armaldo/normal.gbapal.lz"

	.globl gMonBackPic_Armaldo
gMonBackPic_Armaldo: @ 0x8D2D3E8
	.incbin "graphics/pokemon/armaldo/back.4bpp.lz"

	.globl gMonShinyPalette_Armaldo
gMonShinyPalette_Armaldo: @ 0x8D2D820
	.incbin "graphics/pokemon/armaldo/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2d848, 0x420

	.globl gMonStillFrontPic_Ralts
gMonStillFrontPic_Ralts: @ 0x8D2DC68
	.incbin "graphics/pokemon/ralts/front.4bpp.lz"

	.globl gMonPalette_Ralts
gMonPalette_Ralts: @ 0x8D2DE98
	.incbin "graphics/pokemon/ralts/normal.gbapal.lz"

	.globl gMonBackPic_Ralts
gMonBackPic_Ralts: @ 0x8D2DEC0
	.incbin "graphics/pokemon/ralts/back.4bpp.lz"

	.globl gMonShinyPalette_Ralts
gMonShinyPalette_Ralts: @ 0x8D2E0FC
	.incbin "graphics/pokemon/ralts/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2e124, 0x420

	.globl gMonStillFrontPic_Kirlia
gMonStillFrontPic_Kirlia: @ 0x8D2E544
	.incbin "graphics/pokemon/kirlia/front.4bpp.lz"

	.globl gMonPalette_Kirlia
gMonPalette_Kirlia: @ 0x8D2E840
	.incbin "graphics/pokemon/kirlia/normal.gbapal.lz"

	.globl gMonBackPic_Kirlia
gMonBackPic_Kirlia: @ 0x8D2E868
	.incbin "graphics/pokemon/kirlia/back.4bpp.lz"

	.globl gMonShinyPalette_Kirlia
gMonShinyPalette_Kirlia: @ 0x8D2EBDC
	.incbin "graphics/pokemon/kirlia/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2ec04, 0x420

	.globl gMonStillFrontPic_Gardevoir
gMonStillFrontPic_Gardevoir: @ 0x8D2F024
	.incbin "graphics/pokemon/gardevoir/front.4bpp.lz"

	.globl gMonPalette_Gardevoir
gMonPalette_Gardevoir: @ 0x8D2F3A0
	.incbin "graphics/pokemon/gardevoir/normal.gbapal.lz"

	.globl gMonBackPic_Gardevoir
gMonBackPic_Gardevoir: @ 0x8D2F3C8
	.incbin "graphics/pokemon/gardevoir/back.4bpp.lz"

	.globl gMonShinyPalette_Gardevoir
gMonShinyPalette_Gardevoir: @ 0x8D2F6FC
	.incbin "graphics/pokemon/gardevoir/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd2f724, 0x420

	.globl gMonStillFrontPic_Bagon
gMonStillFrontPic_Bagon: @ 0x8D2FB44
	.incbin "graphics/pokemon/bagon/front.4bpp.lz"

	.globl gMonPalette_Bagon
gMonPalette_Bagon: @ 0x8D2FDBC
	.incbin "graphics/pokemon/bagon/normal.gbapal.lz"

	.globl gMonBackPic_Bagon
gMonBackPic_Bagon: @ 0x8D2FDE4
	.incbin "graphics/pokemon/bagon/back.4bpp.lz"

	.globl gMonShinyPalette_Bagon
gMonShinyPalette_Bagon: @ 0x8D300CC
	.incbin "graphics/pokemon/bagon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd300f3, 0x421

	.globl gMonStillFrontPic_Shelgon
gMonStillFrontPic_Shelgon: @ 0x8D30514
	.incbin "graphics/pokemon/shelgon/front.4bpp.lz"

	.globl gMonPalette_Shelgon
gMonPalette_Shelgon: @ 0x8D30818
	.incbin "graphics/pokemon/shelgon/normal.gbapal.lz"

	.globl gMonBackPic_Shelgon
gMonBackPic_Shelgon: @ 0x8D30840
	.incbin "graphics/pokemon/shelgon/back.4bpp.lz"

	.globl gMonShinyPalette_Shelgon
gMonShinyPalette_Shelgon: @ 0x8D30B28
	.incbin "graphics/pokemon/shelgon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd30b50, 0x420

	.globl gMonStillFrontPic_Salamence
gMonStillFrontPic_Salamence: @ 0x8D30F70
	.incbin "graphics/pokemon/salamence/front.4bpp.lz"

	.globl gMonPalette_Salamence
gMonPalette_Salamence: @ 0x8D313D4
	.incbin "graphics/pokemon/salamence/normal.gbapal.lz"

	.globl gMonBackPic_Salamence
gMonBackPic_Salamence: @ 0x8D313FC
	.incbin "graphics/pokemon/salamence/back.4bpp.lz"

	.globl gMonShinyPalette_Salamence
gMonShinyPalette_Salamence: @ 0x8D316E0
	.incbin "graphics/pokemon/salamence/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd31708, 0x420

	.globl gMonStillFrontPic_Beldum
gMonStillFrontPic_Beldum: @ 0x8D31B28
	.incbin "graphics/pokemon/beldum/front.4bpp.lz"

	.globl gMonPalette_Beldum
gMonPalette_Beldum: @ 0x8D31D98
	.incbin "graphics/pokemon/beldum/normal.gbapal.lz"

	.globl gMonBackPic_Beldum
gMonBackPic_Beldum: @ 0x8D31DC0
	.incbin "graphics/pokemon/beldum/back.4bpp.lz"

	.globl gMonShinyPalette_Beldum
gMonShinyPalette_Beldum: @ 0x8D320B0
	.incbin "graphics/pokemon/beldum/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd320d8, 0x420

	.globl gMonStillFrontPic_Metang
gMonStillFrontPic_Metang: @ 0x8D324F8
	.incbin "graphics/pokemon/metang/front.4bpp.lz"

	.globl gMonPalette_Metang
gMonPalette_Metang: @ 0x8D32954
	.incbin "graphics/pokemon/metang/normal.gbapal.lz"

	.globl gMonBackPic_Metang
gMonBackPic_Metang: @ 0x8D3297C
	.incbin "graphics/pokemon/metang/back.4bpp.lz"

	.globl gMonShinyPalette_Metang
gMonShinyPalette_Metang: @ 0x8D32CA0
	.incbin "graphics/pokemon/metang/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd32cc8, 0x420

	.globl gMonStillFrontPic_Metagross
gMonStillFrontPic_Metagross: @ 0x8D330E8
	.incbin "graphics/pokemon/metagross/front.4bpp.lz"

	.globl gMonPalette_Metagross
gMonPalette_Metagross: @ 0x8D3354C
	.incbin "graphics/pokemon/metagross/normal.gbapal.lz"

	.globl gMonBackPic_Metagross
gMonBackPic_Metagross: @ 0x8D33574
	.incbin "graphics/pokemon/metagross/back.4bpp.lz"

	.globl gMonShinyPalette_Metagross
gMonShinyPalette_Metagross: @ 0x8D33840
	.incbin "graphics/pokemon/metagross/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd33868, 0x420

	.globl gMonStillFrontPic_Regirock
gMonStillFrontPic_Regirock: @ 0x8D33C88
	.incbin "graphics/pokemon/regirock/front.4bpp.lz"

	.globl gMonPalette_Regirock
gMonPalette_Regirock: @ 0x8D34144
	.incbin "graphics/pokemon/regirock/normal.gbapal.lz"

	.globl gMonBackPic_Regirock
gMonBackPic_Regirock: @ 0x8D3416C
	.incbin "graphics/pokemon/regirock/back.4bpp.lz"

	.globl gMonShinyPalette_Regirock
gMonShinyPalette_Regirock: @ 0x8D345B8
	.incbin "graphics/pokemon/regirock/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd345e0, 0x420

	.globl gMonStillFrontPic_Regice
gMonStillFrontPic_Regice: @ 0x8D34A00
	.incbin "graphics/pokemon/regice/front.4bpp.lz"

	.globl gMonPalette_Regice
gMonPalette_Regice: @ 0x8D34E48
	.incbin "graphics/pokemon/regice/normal.gbapal.lz"

	.globl gMonBackPic_Regice
gMonBackPic_Regice: @ 0x8D34E70
	.incbin "graphics/pokemon/regice/back.4bpp.lz"

	.globl gMonShinyPalette_Regice
gMonShinyPalette_Regice: @ 0x8D35160
	.incbin "graphics/pokemon/regice/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd35186, 0x422

	.globl gMonStillFrontPic_Registeel
gMonStillFrontPic_Registeel: @ 0x8D355A8
	.incbin "graphics/pokemon/registeel/front.4bpp.lz"

	.globl gMonPalette_Registeel
gMonPalette_Registeel: @ 0x8D35A30
	.incbin "graphics/pokemon/registeel/normal.gbapal.lz"

	.globl gMonBackPic_Registeel
gMonBackPic_Registeel: @ 0x8D35A58
	.incbin "graphics/pokemon/registeel/back.4bpp.lz"

	.globl gMonShinyPalette_Registeel
gMonShinyPalette_Registeel: @ 0x8D35D90
	.incbin "graphics/pokemon/registeel/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd35db8, 0x420

	.globl gMonStillFrontPic_Kyogre
gMonStillFrontPic_Kyogre: @ 0x8D361D8
	.incbin "graphics/pokemon/kyogre/front.4bpp.lz"

	.globl gMonPalette_Kyogre
gMonPalette_Kyogre: @ 0x8D36648
	.incbin "graphics/pokemon/kyogre/normal.gbapal.lz"

	.globl gMonBackPic_Kyogre
gMonBackPic_Kyogre: @ 0x8D36670
	.incbin "graphics/pokemon/kyogre/back.4bpp.lz"

	.globl gMonShinyPalette_Kyogre
gMonShinyPalette_Kyogre: @ 0x8D368E8
	.incbin "graphics/pokemon/kyogre/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd36910, 0x420

	.globl gMonStillFrontPic_Groudon
gMonStillFrontPic_Groudon: @ 0x8D36D30
	.incbin "graphics/pokemon/groudon/front.4bpp.lz"

	.globl gMonPalette_Groudon
gMonPalette_Groudon: @ 0x8D372C4
	.incbin "graphics/pokemon/groudon/normal.gbapal.lz"

	.globl gMonBackPic_Groudon
gMonBackPic_Groudon: @ 0x8D372EC
	.incbin "graphics/pokemon/groudon/back.4bpp.lz"

	.globl gMonShinyPalette_Groudon
gMonShinyPalette_Groudon: @ 0x8D37754
	.incbin "graphics/pokemon/groudon/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd3777c, 0x420

	.globl gMonStillFrontPic_Rayquaza
gMonStillFrontPic_Rayquaza: @ 0x8D37B9C
	.incbin "graphics/pokemon/rayquaza/front.4bpp.lz"

	.globl gMonPalette_Rayquaza
gMonPalette_Rayquaza: @ 0x8D38388
	.incbin "graphics/pokemon/rayquaza/normal.gbapal.lz"

	.globl gMonBackPic_Rayquaza
gMonBackPic_Rayquaza: @ 0x8D383B0
	.incbin "graphics/pokemon/rayquaza/back.4bpp.lz"

	.globl gMonShinyPalette_Rayquaza
gMonShinyPalette_Rayquaza: @ 0x8D386E8
	.incbin "graphics/pokemon/rayquaza/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd38710, 0x420

	.globl gMonStillFrontPic_Latias
gMonStillFrontPic_Latias: @ 0x8D38B30
	.incbin "graphics/pokemon/latias/front.4bpp.lz"

	.globl gMonPalette_Latias
gMonPalette_Latias: @ 0x8D38F54
	.incbin "graphics/pokemon/latias/normal.gbapal.lz"

	.globl gMonBackPic_Latias
gMonBackPic_Latias: @ 0x8D38F7C
	.incbin "graphics/pokemon/latias/back.4bpp.lz"

	.globl gMonShinyPalette_Latias
gMonShinyPalette_Latias: @ 0x8D39278
	.incbin "graphics/pokemon/latias/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd392a0, 0x420

	.globl gMonStillFrontPic_Latios
gMonStillFrontPic_Latios: @ 0x8D396C0
	.incbin "graphics/pokemon/latios/front.4bpp.lz"

	.globl gMonPalette_Latios
gMonPalette_Latios: @ 0x8D39B14
	.incbin "graphics/pokemon/latios/normal.gbapal.lz"

	.globl gMonBackPic_Latios
gMonBackPic_Latios: @ 0x8D39B3C
	.incbin "graphics/pokemon/latios/back.4bpp.lz"

	.globl gMonShinyPalette_Latios
gMonShinyPalette_Latios: @ 0x8D39E9C
	.incbin "graphics/pokemon/latios/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd39ec4, 0x420

	.globl gMonStillFrontPic_Jirachi
gMonStillFrontPic_Jirachi: @ 0x8D3A2E4
	.incbin "graphics/pokemon/jirachi/front.4bpp.lz"

	.globl gMonPalette_Jirachi
gMonPalette_Jirachi: @ 0x8D3A5F0
	.incbin "graphics/pokemon/jirachi/normal.gbapal.lz"

	.globl gMonBackPic_Jirachi
gMonBackPic_Jirachi: @ 0x8D3A618
	.incbin "graphics/pokemon/jirachi/back.4bpp.lz"

	.globl gMonShinyPalette_Jirachi
gMonShinyPalette_Jirachi: @ 0x8D3A9B8
	.incbin "graphics/pokemon/jirachi/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd3a9e0, 0x420

	.globl gMonStillFrontPic_Deoxys
gMonStillFrontPic_Deoxys: @ 0x8D3AE00
	.incbin "graphics/pokemon/deoxys/front.4bpp.lz"

	.globl gMonPalette_Deoxys
gMonPalette_Deoxys: @ 0x8D3B1DC
	.incbin "graphics/pokemon/deoxys/normal.gbapal.lz"

	.globl gMonBackPic_Deoxys
gMonBackPic_Deoxys: @ 0x8D3B204
	.incbin "graphics/pokemon/deoxys/back.4bpp.lz"

	.globl gMonShinyPalette_Deoxys
gMonShinyPalette_Deoxys: @ 0x8D3B874
	.incbin "graphics/pokemon/deoxys/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd3b89c, 0x8420

	.globl gMonStillFrontPic_Chimecho
gMonStillFrontPic_Chimecho: @ 0x8D43CBC
	.incbin "graphics/pokemon/chimecho/front.4bpp.lz"

	.globl gMonPalette_Chimecho
gMonPalette_Chimecho: @ 0x8D43F08
	.incbin "graphics/pokemon/chimecho/normal.gbapal.lz"

	.globl gMonBackPic_Chimecho
gMonBackPic_Chimecho: @ 0x8D43F30
	.incbin "graphics/pokemon/chimecho/back.4bpp.lz"

	.globl gMonShinyPalette_Chimecho
gMonShinyPalette_Chimecho: @ 0x8D441A4
	.incbin "graphics/pokemon/chimecho/shiny.gbapal.lz"
	.incbin "baserom_jp.gba", 0xd441cc, 0x420

	.globl gMonStillFrontPic_Egg
gMonStillFrontPic_Egg: @ 0x8D445EC
	.incbin "graphics/pokemon/egg/front.4bpp.lz"

	.globl gMonPalette_Egg
gMonPalette_Egg: @ 0x8D447A0
	.incbin "graphics/pokemon/egg/normal.gbapal.lz"

	.globl gMonStillFrontPic_UnownB
gMonStillFrontPic_UnownB: @ 0x8D447C0
	.incbin "graphics/pokemon/unown/b/front.4bpp.lz"

	.globl gMonBackPic_UnownB
gMonBackPic_UnownB: @ 0x8D44998
	.incbin "graphics/pokemon/unown/b/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd44b9b, 0x401

	.globl gMonStillFrontPic_UnownC
gMonStillFrontPic_UnownC: @ 0x8D44F9C
	.incbin "graphics/pokemon/unown/c/front.4bpp.lz"

	.globl gMonBackPic_UnownC
gMonBackPic_UnownC: @ 0x8D451B0
	.incbin "graphics/pokemon/unown/c/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4545c, 0x400

	.globl gMonStillFrontPic_UnownD
gMonStillFrontPic_UnownD: @ 0x8D4585C
	.incbin "graphics/pokemon/unown/d/front.4bpp.lz"

	.globl gMonBackPic_UnownD
gMonBackPic_UnownD: @ 0x8D45A54
	.incbin "graphics/pokemon/unown/d/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd45ca9, 0x403

	.globl gMonStillFrontPic_UnownE
gMonStillFrontPic_UnownE: @ 0x8D460AC
	.incbin "graphics/pokemon/unown/e/front.4bpp.lz"

	.globl gMonBackPic_UnownE
gMonBackPic_UnownE: @ 0x8D46264
	.incbin "graphics/pokemon/unown/e/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd46464, 0x400

	.globl gMonStillFrontPic_UnownF
gMonStillFrontPic_UnownF: @ 0x8D46864
	.incbin "graphics/pokemon/unown/f/front.4bpp.lz"

	.globl gMonBackPic_UnownF
gMonBackPic_UnownF: @ 0x8D46A58
	.incbin "graphics/pokemon/unown/f/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd46c73, 0x401

	.globl gMonStillFrontPic_UnownG
gMonStillFrontPic_UnownG: @ 0x8D47074
	.incbin "graphics/pokemon/unown/g/front.4bpp.lz"

	.globl gMonBackPic_UnownG
gMonBackPic_UnownG: @ 0x8D47250
	.incbin "graphics/pokemon/unown/g/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4749c, 0x400

	.globl gMonStillFrontPic_UnownH
gMonStillFrontPic_UnownH: @ 0x8D4789C
	.incbin "graphics/pokemon/unown/h/front.4bpp.lz"

	.globl gMonBackPic_UnownH
gMonBackPic_UnownH: @ 0x8D47AE0
	.incbin "graphics/pokemon/unown/h/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd47da3, 0x401

	.globl gMonStillFrontPic_UnownI
gMonStillFrontPic_UnownI: @ 0x8D481A4
	.incbin "graphics/pokemon/unown/i/front.4bpp.lz"

	.globl gMonBackPic_UnownI
gMonBackPic_UnownI: @ 0x8D4833C
	.incbin "graphics/pokemon/unown/i/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd484e3, 0x401

	.globl gMonStillFrontPic_UnownJ
gMonStillFrontPic_UnownJ: @ 0x8D488E4
	.incbin "graphics/pokemon/unown/j/front.4bpp.lz"

	.globl gMonBackPic_UnownJ
gMonBackPic_UnownJ: @ 0x8D48AA8
	.incbin "graphics/pokemon/unown/j/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd48c8d, 0x403

	.globl gMonStillFrontPic_UnownK
gMonStillFrontPic_UnownK: @ 0x8D49090
	.incbin "graphics/pokemon/unown/k/front.4bpp.lz"

	.globl gMonBackPic_UnownK
gMonBackPic_UnownK: @ 0x8D49260
	.incbin "graphics/pokemon/unown/k/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd49455, 0x403

	.globl gMonStillFrontPic_UnownL
gMonStillFrontPic_UnownL: @ 0x8D49858
	.incbin "graphics/pokemon/unown/l/front.4bpp.lz"

	.globl gMonBackPic_UnownL
gMonBackPic_UnownL: @ 0x8D49A08
	.incbin "graphics/pokemon/unown/l/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd49bdb, 0x401

	.globl gMonStillFrontPic_UnownM
gMonStillFrontPic_UnownM: @ 0x8D49FDC
	.incbin "graphics/pokemon/unown/m/front.4bpp.lz"

	.globl gMonBackPic_UnownM
gMonBackPic_UnownM: @ 0x8D4A200
	.incbin "graphics/pokemon/unown/m/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4a4a7, 0x401

	.globl gMonStillFrontPic_UnownN
gMonStillFrontPic_UnownN: @ 0x8D4A8A8
	.incbin "graphics/pokemon/unown/n/front.4bpp.lz"

	.globl gMonBackPic_UnownN
gMonBackPic_UnownN: @ 0x8D4AAA0
	.incbin "graphics/pokemon/unown/n/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4ad0c, 0x400

	.globl gMonStillFrontPic_UnownO
gMonStillFrontPic_UnownO: @ 0x8D4B10C
	.incbin "graphics/pokemon/unown/o/front.4bpp.lz"

	.globl gMonBackPic_UnownO
gMonBackPic_UnownO: @ 0x8D4B344
	.incbin "graphics/pokemon/unown/o/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4b604, 0x400

	.globl gMonStillFrontPic_UnownP
gMonStillFrontPic_UnownP: @ 0x8D4BA04
	.incbin "graphics/pokemon/unown/p/front.4bpp.lz"

	.globl gMonBackPic_UnownP
gMonBackPic_UnownP: @ 0x8D4BBA4
	.incbin "graphics/pokemon/unown/p/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4bd68, 0x400

	.globl gMonStillFrontPic_UnownQ
gMonStillFrontPic_UnownQ: @ 0x8D4C168
	.incbin "graphics/pokemon/unown/q/front.4bpp.lz"

	.globl gMonBackPic_UnownQ
gMonBackPic_UnownQ: @ 0x8D4C31C
	.incbin "graphics/pokemon/unown/q/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4c4e7, 0x401

	.globl gMonStillFrontPic_UnownR
gMonStillFrontPic_UnownR: @ 0x8D4C8E8
	.incbin "graphics/pokemon/unown/r/front.4bpp.lz"

	.globl gMonBackPic_UnownR
gMonBackPic_UnownR: @ 0x8D4CA8C
	.incbin "graphics/pokemon/unown/r/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4cc51, 0x403

	.globl gMonStillFrontPic_UnownS
gMonStillFrontPic_UnownS: @ 0x8D4D054
	.incbin "graphics/pokemon/unown/s/front.4bpp.lz"

	.globl gMonBackPic_UnownS
gMonBackPic_UnownS: @ 0x8D4D23C
	.incbin "graphics/pokemon/unown/s/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4d48d, 0x403

	.globl gMonStillFrontPic_UnownT
gMonStillFrontPic_UnownT: @ 0x8D4D890
	.incbin "graphics/pokemon/unown/t/front.4bpp.lz"

	.globl gMonBackPic_UnownT
gMonBackPic_UnownT: @ 0x8D4DA40
	.incbin "graphics/pokemon/unown/t/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4dbf4, 0x400

	.globl gMonStillFrontPic_UnownU
gMonStillFrontPic_UnownU: @ 0x8D4DFF4
	.incbin "graphics/pokemon/unown/u/front.4bpp.lz"

	.globl gMonBackPic_UnownU
gMonBackPic_UnownU: @ 0x8D4E20C
	.incbin "graphics/pokemon/unown/u/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4e45e, 0x402

	.globl gMonStillFrontPic_UnownV
gMonStillFrontPic_UnownV: @ 0x8D4E860
	.incbin "graphics/pokemon/unown/v/front.4bpp.lz"

	.globl gMonBackPic_UnownV
gMonBackPic_UnownV: @ 0x8D4EA44
	.incbin "graphics/pokemon/unown/v/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4ec71, 0x403

	.globl gMonStillFrontPic_UnownW
gMonStillFrontPic_UnownW: @ 0x8D4F074
	.incbin "graphics/pokemon/unown/w/front.4bpp.lz"

	.globl gMonBackPic_UnownW
gMonBackPic_UnownW: @ 0x8D4F248
	.incbin "graphics/pokemon/unown/w/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4f44a, 0x402

	.globl gMonStillFrontPic_UnownX
gMonStillFrontPic_UnownX: @ 0x8D4F84C
	.incbin "graphics/pokemon/unown/x/front.4bpp.lz"

	.globl gMonBackPic_UnownX
gMonBackPic_UnownX: @ 0x8D4FA10
	.incbin "graphics/pokemon/unown/x/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd4fc00, 0x400

	.globl gMonStillFrontPic_UnownY
gMonStillFrontPic_UnownY: @ 0x8D50000
	.incbin "graphics/pokemon/unown/y/front.4bpp.lz"

	.globl gMonBackPic_UnownY
gMonBackPic_UnownY: @ 0x8D501D8
	.incbin "graphics/pokemon/unown/y/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd503cb, 0x401

	.globl gMonStillFrontPic_UnownZ
gMonStillFrontPic_UnownZ: @ 0x8D507CC
	.incbin "graphics/pokemon/unown/z/front.4bpp.lz"

	.globl gMonBackPic_UnownZ
gMonBackPic_UnownZ: @ 0x8D5097C
	.incbin "graphics/pokemon/unown/z/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd50b58, 0x400

	.globl gMonStillFrontPic_UnownExclamationMark
gMonStillFrontPic_UnownExclamationMark: @ 0x8D50F58
	.incbin "graphics/pokemon/unown/exclamation_mark/front.4bpp.lz"

	.globl gMonBackPic_UnownExclamationMark
gMonBackPic_UnownExclamationMark: @ 0x8D510E8
	.incbin "graphics/pokemon/unown/exclamation_mark/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xd512af, 0x401

	.globl gMonStillFrontPic_UnownQuestionMark
gMonStillFrontPic_UnownQuestionMark: @ 0x8D516B0
	.incbin "graphics/pokemon/unown/question_mark/front.4bpp.lz"

	.globl gMonBackPic_UnownQuestionMark
gMonBackPic_UnownQuestionMark: @ 0x8D5186C
	.incbin "graphics/pokemon/unown/question_mark/back.4bpp.lz"
	.incbin "baserom_jp.gba", 0xD51A6B, 0x401
	.globl gTrainerFrontPic_Hiker
gTrainerFrontPic_Hiker: @ 0x8D51E6C
	.incbin "graphics/trainers/front_pics/Hiker.4bpp.lz"
	.globl gTrainerPalette_Hiker
gTrainerPalette_Hiker: @ 0x8D522EC
	.incbin "graphics/trainers/front_pics/Hiker.gbapal.lz"
	.globl gTrainerFrontPic_AquaGruntM
gTrainerFrontPic_AquaGruntM: @ 0x8D52314
	.incbin "graphics/trainers/front_pics/AquaGruntM.4bpp.lz"
	.globl gTrainerPalette_AquaGruntM
gTrainerPalette_AquaGruntM: @ 0x8D52674
	.incbin "graphics/trainers/front_pics/AquaGruntM.gbapal.lz"
	.globl gTrainerFrontPic_PokemonBreederF
gTrainerFrontPic_PokemonBreederF: @ 0x8D5269C
	.incbin "graphics/trainers/front_pics/PokemonBreederF.4bpp.lz"
	.globl gTrainerPalette_PokemonBreederF
gTrainerPalette_PokemonBreederF: @ 0x8D529D0
	.incbin "graphics/trainers/front_pics/PokemonBreederF.gbapal.lz"
	.globl gTrainerFrontPic_CoolTrainerM
gTrainerFrontPic_CoolTrainerM: @ 0x8D529F8
	.incbin "graphics/trainers/front_pics/CoolTrainerM.4bpp.lz"
	.globl gTrainerPalette_CoolTrainerM
gTrainerPalette_CoolTrainerM: @ 0x8D52CE0
	.incbin "graphics/trainers/front_pics/CoolTrainerM.gbapal.lz"
	.globl gTrainerFrontPic_BirdKeeper
gTrainerFrontPic_BirdKeeper: @ 0x8D52D08
	.incbin "graphics/trainers/front_pics/BirdKeeper.4bpp.lz"
	.globl gTrainerPalette_BirdKeeper
gTrainerPalette_BirdKeeper: @ 0x8D53040
	.incbin "graphics/trainers/front_pics/BirdKeeper.gbapal.lz"
	.globl gTrainerFrontPic_Collector
gTrainerFrontPic_Collector: @ 0x8D53068
	.incbin "graphics/trainers/front_pics/Collector.4bpp.lz"
	.globl gTrainerPalette_Collector
gTrainerPalette_Collector: @ 0x8D5346C
	.incbin "graphics/trainers/front_pics/Collector.gbapal.lz"
	.globl gTrainerFrontPic_AquaGruntF
gTrainerFrontPic_AquaGruntF: @ 0x8D53494
	.incbin "graphics/trainers/front_pics/AquaGruntF.4bpp.lz"
	.globl gTrainerPalette_AquaGruntF
gTrainerPalette_AquaGruntF: @ 0x8D537D0
	.incbin "graphics/trainers/front_pics/AquaGruntF.gbapal.lz"
	.globl gTrainerFrontPic_SwimmerM
gTrainerFrontPic_SwimmerM: @ 0x8D537F8
	.incbin "graphics/trainers/front_pics/SwimmerM.4bpp.lz"
	.globl gTrainerPalette_SwimmerM
gTrainerPalette_SwimmerM: @ 0x8D53AB8
	.incbin "graphics/trainers/front_pics/SwimmerM.gbapal.lz"
	.globl gTrainerFrontPic_MagmaGruntM
gTrainerFrontPic_MagmaGruntM: @ 0x8D53AE0
	.incbin "graphics/trainers/front_pics/MagmaGruntM.4bpp.lz"
	.globl gTrainerPalette_MagmaGruntM
gTrainerPalette_MagmaGruntM: @ 0x8D53E60
	.incbin "graphics/trainers/front_pics/MagmaGruntM.gbapal.lz"
	.globl gTrainerFrontPic_ExpertM
gTrainerFrontPic_ExpertM: @ 0x8D53E88
	.incbin "graphics/trainers/front_pics/ExpertM.4bpp.lz"
	.globl gTrainerPalette_ExpertM
gTrainerPalette_ExpertM: @ 0x8D541C8
	.incbin "graphics/trainers/front_pics/ExpertM.gbapal.lz"
	.globl gTrainerFrontPic_AquaAdminM
gTrainerFrontPic_AquaAdminM: @ 0x8D541F0
	.incbin "graphics/trainers/front_pics/AquaAdminM.4bpp.lz"
	.globl gTrainerPalette_AquaAdminM
gTrainerPalette_AquaAdminM: @ 0x8D545A4
	.incbin "graphics/trainers/front_pics/AquaAdminM.gbapal.lz"
	.globl gTrainerFrontPic_BlackBelt
gTrainerFrontPic_BlackBelt: @ 0x8D545CC
	.incbin "graphics/trainers/front_pics/BlackBelt.4bpp.lz"
	.globl gTrainerPalette_BlackBelt
gTrainerPalette_BlackBelt: @ 0x8D54930
	.incbin "graphics/trainers/front_pics/BlackBelt.gbapal.lz"
	.globl gTrainerFrontPic_AquaAdminF
gTrainerFrontPic_AquaAdminF: @ 0x8D54958
	.incbin "graphics/trainers/front_pics/AquaAdminF.4bpp.lz"
	.globl gTrainerPalette_AquaAdminF
gTrainerPalette_AquaAdminF: @ 0x8D54D1C
	.incbin "graphics/trainers/front_pics/AquaAdminF.gbapal.lz"
	.globl gTrainerFrontPic_AquaLeaderArchie
gTrainerFrontPic_AquaLeaderArchie: @ 0x8D54D44
	.incbin "graphics/trainers/front_pics/AquaLeaderArchie.4bpp.lz"
	.globl gTrainerPalette_AquaLeaderArchie
gTrainerPalette_AquaLeaderArchie: @ 0x8D55080
	.incbin "graphics/trainers/front_pics/AquaLeaderArchie.gbapal.lz"
	.globl gTrainerFrontPic_HexManiac
gTrainerFrontPic_HexManiac: @ 0x8D550A8
	.incbin "graphics/trainers/front_pics/HexManiac.4bpp.lz"
	.globl gTrainerPalette_HexManiac
gTrainerPalette_HexManiac: @ 0x8D55414
	.incbin "graphics/trainers/front_pics/HexManiac.gbapal.lz"
	.globl gTrainerFrontPic_AromaLady
gTrainerFrontPic_AromaLady: @ 0x8D5543C
	.incbin "graphics/trainers/front_pics/AromaLady.4bpp.lz"
	.globl gTrainerPalette_AromaLady
gTrainerPalette_AromaLady: @ 0x8D55700
	.incbin "graphics/trainers/front_pics/AromaLady.gbapal.lz"
	.globl gTrainerFrontPic_RuinManiac
gTrainerFrontPic_RuinManiac: @ 0x8D55728
	.incbin "graphics/trainers/front_pics/RuinManiac.4bpp.lz"
	.globl gTrainerPalette_RuinManiac
gTrainerPalette_RuinManiac: @ 0x8D55AC4
	.incbin "graphics/trainers/front_pics/RuinManiac.gbapal.lz"
	.globl gTrainerFrontPic_Interviewer
gTrainerFrontPic_Interviewer: @ 0x8D55AEC
	.incbin "graphics/trainers/front_pics/Interviewer.4bpp.lz"
	.globl gTrainerPalette_Interviewer
gTrainerPalette_Interviewer: @ 0x8D55F90
	.incbin "graphics/trainers/front_pics/Interviewer.gbapal.lz"
	.globl gTrainerFrontPic_TuberF
gTrainerFrontPic_TuberF: @ 0x8D55FB8
	.incbin "graphics/trainers/front_pics/TuberF.4bpp.lz"
	.globl gTrainerPalette_TuberF
gTrainerPalette_TuberF: @ 0x8D5625C
	.incbin "graphics/trainers/front_pics/TuberF.gbapal.lz"
	.globl gTrainerFrontPic_TuberM
gTrainerFrontPic_TuberM: @ 0x8D56284
	.incbin "graphics/trainers/front_pics/TuberM.4bpp.lz"
	.globl gTrainerPalette_TuberM
gTrainerPalette_TuberM: @ 0x8D56510
	.incbin "graphics/trainers/front_pics/TuberM.gbapal.lz"
	.globl gTrainerFrontPic_CoolTrainerF
gTrainerFrontPic_CoolTrainerF: @ 0x8D56538
	.incbin "graphics/trainers/front_pics/CoolTrainerF.4bpp.lz"
	.globl gTrainerPalette_CoolTrainerF
gTrainerPalette_CoolTrainerF: @ 0x8D5684C
	.incbin "graphics/trainers/front_pics/CoolTrainerF.gbapal.lz"
	.globl gTrainerFrontPic_Lady
gTrainerFrontPic_Lady: @ 0x8D56874
	.incbin "graphics/trainers/front_pics/Lady.4bpp.lz"
	.globl gTrainerPalette_Lady
gTrainerPalette_Lady: @ 0x8D56C28
	.incbin "graphics/trainers/front_pics/Lady.gbapal.lz"
	.globl gTrainerFrontPic_Beauty
gTrainerFrontPic_Beauty: @ 0x8D56C50
	.incbin "graphics/trainers/front_pics/Beauty.4bpp.lz"
	.globl gTrainerPalette_Beauty
gTrainerPalette_Beauty: @ 0x8D56F38
	.incbin "graphics/trainers/front_pics/Beauty.gbapal.lz"
	.globl gTrainerFrontPic_RichBoy
gTrainerFrontPic_RichBoy: @ 0x8D56F60
	.incbin "graphics/trainers/front_pics/RichBoy.4bpp.lz"
	.globl gTrainerPalette_RichBoy
gTrainerPalette_RichBoy: @ 0x8D57214
	.incbin "graphics/trainers/front_pics/RichBoy.gbapal.lz"
	.globl gTrainerFrontPic_ExpertF
gTrainerFrontPic_ExpertF: @ 0x8D5723C
	.incbin "graphics/trainers/front_pics/ExpertF.4bpp.lz"
	.globl gTrainerPalette_ExpertF
gTrainerPalette_ExpertF: @ 0x8D57558
	.incbin "graphics/trainers/front_pics/ExpertF.gbapal.lz"
	.globl gTrainerFrontPic_Pokemaniac
gTrainerFrontPic_Pokemaniac: @ 0x8D57580
	.incbin "graphics/trainers/front_pics/Pokemaniac.4bpp.lz"
	.globl gTrainerPalette_Pokemaniac
gTrainerPalette_Pokemaniac: @ 0x8D578F0
	.incbin "graphics/trainers/front_pics/Pokemaniac.gbapal.lz"
	.globl gTrainerFrontPic_MagmaGruntF
gTrainerFrontPic_MagmaGruntF: @ 0x8D57918
	.incbin "graphics/trainers/front_pics/MagmaGruntF.4bpp.lz"
	.globl gTrainerPalette_MagmaGruntF
gTrainerPalette_MagmaGruntF: @ 0x8D57CA4
	.incbin "graphics/trainers/front_pics/MagmaGruntF.gbapal.lz"
	.globl gTrainerFrontPic_Guitarist
gTrainerFrontPic_Guitarist: @ 0x8D57CCC
	.incbin "graphics/trainers/front_pics/Guitarist.4bpp.lz"
	.globl gTrainerPalette_Guitarist
gTrainerPalette_Guitarist: @ 0x8D58050
	.incbin "graphics/trainers/front_pics/Guitarist.gbapal.lz"
	.globl gTrainerFrontPic_Kindler
gTrainerFrontPic_Kindler: @ 0x8D58078
	.incbin "graphics/trainers/front_pics/Kindler.4bpp.lz"
	.globl gTrainerPalette_Kindler
gTrainerPalette_Kindler: @ 0x8D583E4
	.incbin "graphics/trainers/front_pics/Kindler.gbapal.lz"
	.globl gTrainerFrontPic_Camper
gTrainerFrontPic_Camper: @ 0x8D5840C
	.incbin "graphics/trainers/front_pics/Camper.4bpp.lz"
	.globl gTrainerPalette_Camper
gTrainerPalette_Camper: @ 0x8D586F4
	.incbin "graphics/trainers/front_pics/Camper.gbapal.lz"
	.globl gTrainerFrontPic_Picnicker
gTrainerFrontPic_Picnicker: @ 0x8D5871C
	.incbin "graphics/trainers/front_pics/Picnicker.4bpp.lz"
	.globl gTrainerPalette_Picnicker
gTrainerPalette_Picnicker: @ 0x8D589FC
	.incbin "graphics/trainers/front_pics/Picnicker.gbapal.lz"
	.globl gTrainerFrontPic_BugManiac
gTrainerFrontPic_BugManiac: @ 0x8D58A24
	.incbin "graphics/trainers/front_pics/BugManiac.4bpp.lz"
	.globl gTrainerPalette_BugManiac
gTrainerPalette_BugManiac: @ 0x8D58E74
	.incbin "graphics/trainers/front_pics/BugManiac.gbapal.lz"
	.globl gTrainerFrontPic_PokemonBreederM
gTrainerFrontPic_PokemonBreederM: @ 0x8D58E9C
	.incbin "graphics/trainers/front_pics/PokemonBreederM.4bpp.lz"
	.globl gTrainerPalette_PokemonBreederM
gTrainerPalette_PokemonBreederM: @ 0x8D591CC
	.incbin "graphics/trainers/front_pics/PokemonBreederM.gbapal.lz"
	.globl gTrainerFrontPic_PsychicM
gTrainerFrontPic_PsychicM: @ 0x8D591F4
	.incbin "graphics/trainers/front_pics/PsychicM.4bpp.lz"
	.globl gTrainerPalette_PsychicM
gTrainerPalette_PsychicM: @ 0x8D59520
	.incbin "graphics/trainers/front_pics/PsychicM.gbapal.lz"
	.globl gTrainerFrontPic_PsychicF
gTrainerFrontPic_PsychicF: @ 0x8D59548
	.incbin "graphics/trainers/front_pics/PsychicF.4bpp.lz"
	.globl gTrainerPalette_PsychicF
gTrainerPalette_PsychicF: @ 0x8D59870
	.incbin "graphics/trainers/front_pics/PsychicF.gbapal.lz"
	.globl gTrainerFrontPic_Gentleman
gTrainerFrontPic_Gentleman: @ 0x8D59898
	.incbin "graphics/trainers/front_pics/Gentleman.4bpp.lz"
	.globl gTrainerPalette_Gentleman
gTrainerPalette_Gentleman: @ 0x8D59B98
	.incbin "graphics/trainers/front_pics/Gentleman.gbapal.lz"
	.globl gTrainerFrontPic_EliteFourSidney
gTrainerFrontPic_EliteFourSidney: @ 0x8D59BC0
	.incbin "graphics/trainers/front_pics/EliteFourSidney.4bpp.lz"
	.globl gTrainerPalette_EliteFourSidney
gTrainerPalette_EliteFourSidney: @ 0x8D59EF4
	.incbin "graphics/trainers/front_pics/EliteFourSidney.gbapal.lz"
	.globl gTrainerFrontPic_EliteFourPhoebe
gTrainerFrontPic_EliteFourPhoebe: @ 0x8D59F1C
	.incbin "graphics/trainers/front_pics/EliteFourPhoebe.4bpp.lz"
	.globl gTrainerPalette_EliteFourPhoebe
gTrainerPalette_EliteFourPhoebe: @ 0x8D5A21C
	.incbin "graphics/trainers/front_pics/EliteFourPhoebe.gbapal.lz"
	.globl gTrainerFrontPic_EliteFourGlacia
gTrainerFrontPic_EliteFourGlacia: @ 0x8D5A244
	.incbin "graphics/trainers/front_pics/EliteFourGlacia.4bpp.lz"
	.globl gTrainerPalette_EliteFourGlacia
gTrainerPalette_EliteFourGlacia: @ 0x8D5A5C8
	.incbin "graphics/trainers/front_pics/EliteFourGlacia.gbapal.lz"
	.globl gTrainerFrontPic_EliteFourDrake
gTrainerFrontPic_EliteFourDrake: @ 0x8D5A5F0
	.incbin "graphics/trainers/front_pics/EliteFourDrake.4bpp.lz"
	.globl gTrainerPalette_EliteFourDrake
gTrainerPalette_EliteFourDrake: @ 0x8D5A998
	.incbin "graphics/trainers/front_pics/EliteFourDrake.gbapal.lz"
	.globl gTrainerFrontPic_LeaderRoxanne
gTrainerFrontPic_LeaderRoxanne: @ 0x8D5A9C0
	.incbin "graphics/trainers/front_pics/LeaderRoxanne.4bpp.lz"
	.globl gTrainerPalette_LeaderRoxanne
gTrainerPalette_LeaderRoxanne: @ 0x8D5ACAC
	.incbin "graphics/trainers/front_pics/LeaderRoxanne.gbapal.lz"
	.globl gTrainerFrontPic_LeaderBrawly
gTrainerFrontPic_LeaderBrawly: @ 0x8D5ACD4
	.incbin "graphics/trainers/front_pics/LeaderBrawly.4bpp.lz"
	.globl gTrainerPalette_LeaderBrawly
gTrainerPalette_LeaderBrawly: @ 0x8D5B068
	.incbin "graphics/trainers/front_pics/LeaderBrawly.gbapal.lz"
	.globl gTrainerFrontPic_LeaderWattson
gTrainerFrontPic_LeaderWattson: @ 0x8D5B090
	.incbin "graphics/trainers/front_pics/LeaderWattson.4bpp.lz"
	.globl gTrainerPalette_LeaderWattson
gTrainerPalette_LeaderWattson: @ 0x8D5B3D8
	.incbin "graphics/trainers/front_pics/LeaderWattson.gbapal.lz"
	.globl gTrainerFrontPic_LeaderFlannery
gTrainerFrontPic_LeaderFlannery: @ 0x8D5B400
	.incbin "graphics/trainers/front_pics/LeaderFlannery.4bpp.lz"
	.globl gTrainerPalette_LeaderFlannery
gTrainerPalette_LeaderFlannery: @ 0x8D5B780
	.incbin "graphics/trainers/front_pics/LeaderFlannery.gbapal.lz"
	.globl gTrainerFrontPic_LeaderNorman
gTrainerFrontPic_LeaderNorman: @ 0x8D5B7A8
	.incbin "graphics/trainers/front_pics/LeaderNorman.4bpp.lz"
	.globl gTrainerPalette_LeaderNorman
gTrainerPalette_LeaderNorman: @ 0x8D5BAE4
	.incbin "graphics/trainers/front_pics/LeaderNorman.gbapal.lz"
	.globl gTrainerFrontPic_LeaderWinona
gTrainerFrontPic_LeaderWinona: @ 0x8D5BB0C
	.incbin "graphics/trainers/front_pics/LeaderWinona.4bpp.lz"
	.globl gTrainerPalette_LeaderWinona
gTrainerPalette_LeaderWinona: @ 0x8D5BE8C
	.incbin "graphics/trainers/front_pics/LeaderWinona.gbapal.lz"
	.globl gTrainerFrontPic_LeaderTateAndLiza
gTrainerFrontPic_LeaderTateAndLiza: @ 0x8D5BEB4
	.incbin "graphics/trainers/front_pics/LeaderTateAndLiza.4bpp.lz"
	.globl gTrainerPalette_LeaderTateAndLiza
gTrainerPalette_LeaderTateAndLiza: @ 0x8D5C2F8
	.incbin "graphics/trainers/front_pics/LeaderTateAndLiza.gbapal.lz"
	.globl gTrainerFrontPic_LeaderJuan
gTrainerFrontPic_LeaderJuan: @ 0x8D5C320
	.incbin "graphics/trainers/front_pics/LeaderJuan.4bpp.lz"
	.globl gTrainerPalette_LeaderJuan
gTrainerPalette_LeaderJuan: @ 0x8D5C6C8
	.incbin "graphics/trainers/front_pics/LeaderJuan.gbapal.lz"
	.globl gTrainerFrontPic_SchoolKidM
gTrainerFrontPic_SchoolKidM: @ 0x8D5C6F0
	.incbin "graphics/trainers/front_pics/SchoolKidM.4bpp.lz"
	.globl gTrainerPalette_SchoolKidM
gTrainerPalette_SchoolKidM: @ 0x8D5C9B0
	.incbin "graphics/trainers/front_pics/SchoolKidM.gbapal.lz"
	.globl gTrainerFrontPic_SchoolKidF
gTrainerFrontPic_SchoolKidF: @ 0x8D5C9D8
	.incbin "graphics/trainers/front_pics/SchoolKidF.4bpp.lz"
	.globl gTrainerPalette_SchoolKidF
gTrainerPalette_SchoolKidF: @ 0x8D5CC74
	.incbin "graphics/trainers/front_pics/SchoolKidF.gbapal.lz"
	.globl gTrainerFrontPic_SrAndJr
gTrainerFrontPic_SrAndJr: @ 0x8D5CC9C
	.incbin "graphics/trainers/front_pics/SrAndJr.4bpp.lz"
	.globl gTrainerPalette_SrAndJr
gTrainerPalette_SrAndJr: @ 0x8D5D10C
	.incbin "graphics/trainers/front_pics/SrAndJr.gbapal.lz"
	.globl gTrainerFrontPic_PokefanM
gTrainerFrontPic_PokefanM: @ 0x8D5D134
	.incbin "graphics/trainers/front_pics/PokefanM.4bpp.lz"
	.globl gTrainerPalette_PokefanM
gTrainerPalette_PokefanM: @ 0x8D5D4F0
	.incbin "graphics/trainers/front_pics/PokefanM.gbapal.lz"
	.globl gTrainerFrontPic_PokefanF
gTrainerFrontPic_PokefanF: @ 0x8D5D518
	.incbin "graphics/trainers/front_pics/PokefanF.4bpp.lz"
	.globl gTrainerPalette_PokefanF
gTrainerPalette_PokefanF: @ 0x8D5D8E4
	.incbin "graphics/trainers/front_pics/PokefanF.gbapal.lz"
	.globl gTrainerFrontPic_Youngster
gTrainerFrontPic_Youngster: @ 0x8D5D90C
	.incbin "graphics/trainers/front_pics/Youngster.4bpp.lz"
	.globl gTrainerPalette_Youngster
gTrainerPalette_Youngster: @ 0x8D5DBB4
	.incbin "graphics/trainers/front_pics/Youngster.gbapal.lz"
	.globl gTrainerFrontPic_ChampionWallace
gTrainerFrontPic_ChampionWallace: @ 0x8D5DBDC
	.incbin "graphics/trainers/front_pics/ChampionWallace.4bpp.lz"
	.globl gTrainerPalette_ChampionWallace
gTrainerPalette_ChampionWallace: @ 0x8D5E030
	.incbin "graphics/trainers/front_pics/ChampionWallace.gbapal.lz"
	.globl gTrainerFrontPic_Fisherman
gTrainerFrontPic_Fisherman: @ 0x8D5E058
	.incbin "graphics/trainers/front_pics/Fisherman.4bpp.lz"
	.globl gTrainerPalette_Fisherman
gTrainerPalette_Fisherman: @ 0x8D5E43C
	.incbin "graphics/trainers/front_pics/Fisherman.gbapal.lz"
	.globl gTrainerFrontPic_CyclingTriathleteM
gTrainerFrontPic_CyclingTriathleteM: @ 0x8D5E464
	.incbin "graphics/trainers/front_pics/CyclingTriathleteM.4bpp.lz"
	.globl gTrainerPalette_CyclingTriathleteM
gTrainerPalette_CyclingTriathleteM: @ 0x8D5E874
	.incbin "graphics/trainers/front_pics/CyclingTriathleteM.gbapal.lz"
	.globl gTrainerFrontPic_CyclingTriathleteF
gTrainerFrontPic_CyclingTriathleteF: @ 0x8D5E89C
	.incbin "graphics/trainers/front_pics/CyclingTriathleteF.4bpp.lz"
	.globl gTrainerPalette_CyclingTriathleteF
gTrainerPalette_CyclingTriathleteF: @ 0x8D5ECA8
	.incbin "graphics/trainers/front_pics/CyclingTriathleteF.gbapal.lz"
	.globl gTrainerFrontPic_RunningTriathleteM
gTrainerFrontPic_RunningTriathleteM: @ 0x8D5ECD0
	.incbin "graphics/trainers/front_pics/RunningTriathleteM.4bpp.lz"
	.globl gTrainerPalette_RunningTriathleteM
gTrainerPalette_RunningTriathleteM: @ 0x8D5EF88
	.incbin "graphics/trainers/front_pics/RunningTriathleteM.gbapal.lz"
	.globl gTrainerFrontPic_RunningTriathleteF
gTrainerFrontPic_RunningTriathleteF: @ 0x8D5EFB0
	.incbin "graphics/trainers/front_pics/RunningTriathleteF.4bpp.lz"
	.globl gTrainerPalette_RunningTriathleteF
gTrainerPalette_RunningTriathleteF: @ 0x8D5F254
	.incbin "graphics/trainers/front_pics/RunningTriathleteF.gbapal.lz"
	.globl gTrainerFrontPic_SwimmingTriathleteM
gTrainerFrontPic_SwimmingTriathleteM: @ 0x8D5F27C
	.incbin "graphics/trainers/front_pics/SwimmingTriathleteM.4bpp.lz"
	.globl gTrainerPalette_SwimmingTriathleteM
gTrainerPalette_SwimmingTriathleteM: @ 0x8D5F5A8
	.incbin "graphics/trainers/front_pics/SwimmingTriathleteM.gbapal.lz"
	.globl gTrainerFrontPic_SwimmingTriathleteF
gTrainerFrontPic_SwimmingTriathleteF: @ 0x8D5F5D0
	.incbin "graphics/trainers/front_pics/SwimmingTriathleteF.4bpp.lz"
	.globl gTrainerPalette_SwimmingTriathleteF
gTrainerPalette_SwimmingTriathleteF: @ 0x8D5F8AC
	.incbin "graphics/trainers/front_pics/SwimmingTriathleteF.gbapal.lz"
	.globl gTrainerFrontPic_DragonTamer
gTrainerFrontPic_DragonTamer: @ 0x8D5F8D4
	.incbin "graphics/trainers/front_pics/DragonTamer.4bpp.lz"
	.globl gTrainerPalette_DragonTamer
gTrainerPalette_DragonTamer: @ 0x8D5FC28
	.incbin "graphics/trainers/front_pics/DragonTamer.gbapal.lz"
	.globl gTrainerFrontPic_NinjaBoy
gTrainerFrontPic_NinjaBoy: @ 0x8D5FC50
	.incbin "graphics/trainers/front_pics/NinjaBoy.4bpp.lz"
	.globl gTrainerPalette_NinjaBoy
gTrainerPalette_NinjaBoy: @ 0x8D5FF2C
	.incbin "graphics/trainers/front_pics/NinjaBoy.gbapal.lz"
	.globl gTrainerFrontPic_BattleGirl
gTrainerFrontPic_BattleGirl: @ 0x8D5FF54
	.incbin "graphics/trainers/front_pics/BattleGirl.4bpp.lz"
	.globl gTrainerPalette_BattleGirl
gTrainerPalette_BattleGirl: @ 0x8D60274
	.incbin "graphics/trainers/front_pics/BattleGirl.gbapal.lz"
	.globl gTrainerFrontPic_ParasolLady
gTrainerFrontPic_ParasolLady: @ 0x8D6029C
	.incbin "graphics/trainers/front_pics/ParasolLady.4bpp.lz"
	.globl gTrainerPalette_ParasolLady
gTrainerPalette_ParasolLady: @ 0x8D605D4
	.incbin "graphics/trainers/front_pics/ParasolLady.gbapal.lz"
	.globl gTrainerFrontPic_SwimmerF
gTrainerFrontPic_SwimmerF: @ 0x8D605FC
	.incbin "graphics/trainers/front_pics/SwimmerF.4bpp.lz"
	.globl gTrainerPalette_SwimmerF
gTrainerPalette_SwimmerF: @ 0x8D608CC
	.incbin "graphics/trainers/front_pics/SwimmerF.gbapal.lz"
	.globl gTrainerFrontPic_Twins
gTrainerFrontPic_Twins: @ 0x8D608F4
	.incbin "graphics/trainers/front_pics/Twins.4bpp.lz"
	.globl gTrainerPalette_Twins
gTrainerPalette_Twins: @ 0x8D60CB8
	.incbin "graphics/trainers/front_pics/Twins.gbapal.lz"
	.globl gTrainerFrontPic_Sailor
gTrainerFrontPic_Sailor: @ 0x8D60CE0
	.incbin "graphics/trainers/front_pics/Sailor.4bpp.lz"
	.globl gTrainerPalette_Sailor
gTrainerPalette_Sailor: @ 0x8D61090
	.incbin "graphics/trainers/front_pics/Sailor.gbapal.lz"
	.globl gTrainerFrontPic_MagmaAdmin
gTrainerFrontPic_MagmaAdmin: @ 0x8D610B8
	.incbin "graphics/trainers/front_pics/MagmaAdmin.4bpp.lz"
	.globl gTrainerPalette_MagmaAdmin
gTrainerPalette_MagmaAdmin: @ 0x8D61490
	.incbin "graphics/trainers/front_pics/MagmaAdmin.gbapal.lz"
	.globl gTrainerFrontPic_Wally
gTrainerFrontPic_Wally: @ 0x8D614B8
	.incbin "graphics/trainers/front_pics/Wally.4bpp.lz"
	.globl gTrainerPalette_Wally
gTrainerPalette_Wally: @ 0x8D61788
	.incbin "graphics/trainers/front_pics/Wally.gbapal.lz"
	.globl gTrainerFrontPic_Brendan
gTrainerFrontPic_Brendan: @ 0x8D617B0
	.incbin "graphics/trainers/front_pics/Brendan.4bpp.lz"
	.globl gTrainerPalette_Brendan
gTrainerPalette_Brendan: @ 0x8D61AD4
	.incbin "graphics/trainers/front_pics/Brendan.gbapal.lz"
	.globl gTrainerFrontPic_May
gTrainerFrontPic_May: @ 0x8D61AFC
	.incbin "graphics/trainers/front_pics/May.4bpp.lz"
	.globl gTrainerPalette_May
gTrainerPalette_May: @ 0x8D61DFC
	.incbin "graphics/trainers/front_pics/May.gbapal.lz"
	.globl gTrainerFrontPic_BugCatcher
gTrainerFrontPic_BugCatcher: @ 0x8D61E24
	.incbin "graphics/trainers/front_pics/BugCatcher.4bpp.lz"
	.globl gTrainerPalette_BugCatcher
gTrainerPalette_BugCatcher: @ 0x8D62150
	.incbin "graphics/trainers/front_pics/BugCatcher.gbapal.lz"
	.globl gTrainerFrontPic_PokemonRangerM
gTrainerFrontPic_PokemonRangerM: @ 0x8D62178
	.incbin "graphics/trainers/front_pics/PokemonRangerM.4bpp.lz"
	.globl gTrainerPalette_PokemonRangerM
gTrainerPalette_PokemonRangerM: @ 0x8D624C0
	.incbin "graphics/trainers/front_pics/PokemonRangerM.gbapal.lz"
	.globl gTrainerFrontPic_PokemonRangerF
gTrainerFrontPic_PokemonRangerF: @ 0x8D624E8
	.incbin "graphics/trainers/front_pics/PokemonRangerF.4bpp.lz"
	.globl gTrainerPalette_PokemonRangerF
gTrainerPalette_PokemonRangerF: @ 0x8D6281C
	.incbin "graphics/trainers/front_pics/PokemonRangerF.gbapal.lz"
	.globl gTrainerFrontPic_MagmaLeaderMaxie
gTrainerFrontPic_MagmaLeaderMaxie: @ 0x8D62844
	.incbin "graphics/trainers/front_pics/MagmaLeaderMaxie.4bpp.lz"
	.globl gTrainerPalette_MagmaLeaderMaxie
gTrainerPalette_MagmaLeaderMaxie: @ 0x8D62B38
	.incbin "graphics/trainers/front_pics/MagmaLeaderMaxie.gbapal.lz"
	.globl gTrainerFrontPic_Lass
gTrainerFrontPic_Lass: @ 0x8D62B60
	.incbin "graphics/trainers/front_pics/Lass.4bpp.lz"
	.globl gTrainerPalette_Lass
gTrainerPalette_Lass: @ 0x8D62E38
	.incbin "graphics/trainers/front_pics/Lass.gbapal.lz"
	.globl gTrainerFrontPic_YoungCouple
gTrainerFrontPic_YoungCouple: @ 0x8D62E60
	.incbin "graphics/trainers/front_pics/YoungCouple.4bpp.lz"
	.globl gTrainerPalette_YoungCouple
gTrainerPalette_YoungCouple: @ 0x8D63220
	.incbin "graphics/trainers/front_pics/YoungCouple.gbapal.lz"
	.globl gTrainerFrontPic_OldCouple
gTrainerFrontPic_OldCouple: @ 0x8D63248
	.incbin "graphics/trainers/front_pics/OldCouple.4bpp.lz"
	.globl gTrainerPalette_OldCouple
gTrainerPalette_OldCouple: @ 0x8D63758
	.incbin "graphics/trainers/front_pics/OldCouple.gbapal.lz"
	.globl gTrainerFrontPic_SisAndBro
gTrainerFrontPic_SisAndBro: @ 0x8D63780
	.incbin "graphics/trainers/front_pics/SisAndBro.4bpp.lz"
	.globl gTrainerPalette_SisAndBro
gTrainerPalette_SisAndBro: @ 0x8D63BCC
	.incbin "graphics/trainers/front_pics/SisAndBro.gbapal.lz"
	.globl gTrainerFrontPic_Steven
gTrainerFrontPic_Steven: @ 0x8D63BF4
	.incbin "graphics/trainers/front_pics/Steven.4bpp.lz"
	.globl gTrainerPalette_Steven
gTrainerPalette_Steven: @ 0x8D63F2C
	.incbin "graphics/trainers/front_pics/Steven.gbapal.lz"
	.globl gTrainerFrontPic_SalonMaidenAnabel
gTrainerFrontPic_SalonMaidenAnabel: @ 0x8D63F54
	.incbin "graphics/trainers/front_pics/SalonMaidenAnabel.4bpp.lz"
	.globl gTrainerPalette_SalonMaidenAnabel
gTrainerPalette_SalonMaidenAnabel: @ 0x8D6425C
	.incbin "graphics/trainers/front_pics/SalonMaidenAnabel.gbapal.lz"
	.globl gTrainerFrontPic_DomeAceTucker
gTrainerFrontPic_DomeAceTucker: @ 0x8D64284
	.incbin "graphics/trainers/front_pics/DomeAceTucker.4bpp.lz"
	.globl gTrainerPalette_DomeAceTucker
gTrainerPalette_DomeAceTucker: @ 0x8D64688
	.incbin "graphics/trainers/front_pics/DomeAceTucker.gbapal.lz"
	.globl gTrainerFrontPic_PalaceMavenSpenser
gTrainerFrontPic_PalaceMavenSpenser: @ 0x8D646B0
	.incbin "graphics/trainers/front_pics/PalaceMavenSpenser.4bpp.lz"
	.globl gTrainerPalette_PalaceMavenSpenser
gTrainerPalette_PalaceMavenSpenser: @ 0x8D64A54
	.incbin "graphics/trainers/front_pics/PalaceMavenSpenser.gbapal.lz"
	.globl gTrainerFrontPic_ArenaTycoonGreta
gTrainerFrontPic_ArenaTycoonGreta: @ 0x8D64A7C
	.incbin "graphics/trainers/front_pics/ArenaTycoonGreta.4bpp.lz"
	.globl gTrainerPalette_ArenaTycoonGreta
gTrainerPalette_ArenaTycoonGreta: @ 0x8D64DAC
	.incbin "graphics/trainers/front_pics/ArenaTycoonGreta.gbapal.lz"
	.globl gTrainerFrontPic_FactoryHeadNoland
gTrainerFrontPic_FactoryHeadNoland: @ 0x8D64DD4
	.incbin "graphics/trainers/front_pics/FactoryHeadNoland.4bpp.lz"
	.globl gTrainerPalette_FactoryHeadNoland
gTrainerPalette_FactoryHeadNoland: @ 0x8D65150
	.incbin "graphics/trainers/front_pics/FactoryHeadNoland.gbapal.lz"
	.globl gTrainerFrontPic_PikeQueenLucy
gTrainerFrontPic_PikeQueenLucy: @ 0x8D65178
	.incbin "graphics/trainers/front_pics/PikeQueenLucy.4bpp.lz"
	.globl gTrainerPalette_PikeQueenLucy
gTrainerPalette_PikeQueenLucy: @ 0x8D6546C
	.incbin "graphics/trainers/front_pics/PikeQueenLucy.gbapal.lz"
	.globl gTrainerFrontPic_PyramidKingBrandon
gTrainerFrontPic_PyramidKingBrandon: @ 0x8D65494
	.incbin "graphics/trainers/front_pics/PyramidKingBrandon.4bpp.lz"
	.globl gTrainerPalette_PyramidKingBrandon
gTrainerPalette_PyramidKingBrandon: @ 0x8D65800
	.incbin "graphics/trainers/front_pics/PyramidKingBrandon.gbapal.lz"
	.globl gTrainerFrontPic_Red
gTrainerFrontPic_Red: @ 0x8D65828
	.incbin "graphics/trainers/front_pics/Red.4bpp.lz"
	.globl gTrainerPalette_Red
gTrainerPalette_Red: @ 0x8D65B34
	.incbin "graphics/trainers/front_pics/Red.gbapal.lz"
	.globl gTrainerFrontPic_Leaf
gTrainerFrontPic_Leaf: @ 0x8D65B5C
	.incbin "graphics/trainers/front_pics/Leaf.4bpp.lz"
	.globl gTrainerPalette_Leaf
gTrainerPalette_Leaf: @ 0x8D65E98
	.incbin "graphics/trainers/front_pics/Leaf.gbapal.lz"
	.globl gTrainerFrontPic_RubySapphireBrendan
gTrainerFrontPic_RubySapphireBrendan: @ 0x8D65EC0
	.incbin "graphics/trainers/front_pics/RubySapphireBrendan.4bpp.lz"
	.globl gTrainerPalette_RubySapphireBrendan
gTrainerPalette_RubySapphireBrendan: @ 0x8D661D4
	.incbin "graphics/trainers/front_pics/RubySapphireBrendan.gbapal.lz"
	.globl gTrainerFrontPic_RubySapphireMay
gTrainerFrontPic_RubySapphireMay: @ 0x8D661FC
	.incbin "graphics/trainers/front_pics/RubySapphireMay.4bpp.lz"
	.globl gTrainerPalette_RubySapphireMay
gTrainerPalette_RubySapphireMay: @ 0x8D664FC
	.incbin "graphics/trainers/front_pics/RubySapphireMay.gbapal.lz"
	.globl gTrainerBackPic_Brendan
gTrainerBackPic_Brendan: @ 0x8D66524
	.incbin "graphics/trainers/back_pics/Brendan.4bpp"
	.globl gTrainerBackPic_May
gTrainerBackPic_May: @ 0x8D68524
	.incbin "graphics/trainers/back_pics/May.4bpp"
	.globl gTrainerBackPic_Red
gTrainerBackPic_Red: @ 0x8D6A524
	.incbin "graphics/trainers/back_pics/Red.4bpp"
	.globl gTrainerBackPic_Leaf
gTrainerBackPic_Leaf: @ 0x8D6CD24
	.incbin "graphics/trainers/back_pics/Leaf.4bpp"
	.globl gTrainerBackPic_RubySapphireBrendan
gTrainerBackPic_RubySapphireBrendan: @ 0x8D6F524
	.incbin "graphics/trainers/back_pics/RubySapphireBrendan.4bpp"
	.globl gTrainerBackPic_RubySapphireMay
gTrainerBackPic_RubySapphireMay: @ 0x8D71524
	.incbin "graphics/trainers/back_pics/RubySapphireMay.4bpp"
	.globl gTrainerBackPic_Wally
gTrainerBackPic_Wally: @ 0x8D73524
	.incbin "graphics/trainers/back_pics/Wally.4bpp"
	.globl gTrainerBackPic_Steven
gTrainerBackPic_Steven: @ 0x8D75524
	.incbin "graphics/trainers/back_pics/Steven.4bpp"
	.incbin "baserom_jp.gba", 0xD77524, 0x470
