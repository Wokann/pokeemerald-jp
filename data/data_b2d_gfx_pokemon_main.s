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
	.incbin "baserom_jp.gba", 0xc2faac, 0x298

	.globl gMonPalette_Bulbasaur
gMonPalette_Bulbasaur: @ 0x8C2FD44
	.incbin "baserom_jp.gba", 0xc2fd44, 0x28

	.globl gMonBackPic_Bulbasaur
gMonBackPic_Bulbasaur: @ 0x8C2FD6C
	.incbin "baserom_jp.gba", 0xc2fd6c, 0x2b0

	.globl gMonShinyPalette_Bulbasaur
gMonShinyPalette_Bulbasaur: @ 0x8C3001C
	.incbin "baserom_jp.gba", 0xc3001c, 0x448

	.globl gMonStillFrontPic_Ivysaur
gMonStillFrontPic_Ivysaur: @ 0x8C30464
	.incbin "baserom_jp.gba", 0xc30464, 0x374

	.globl gMonPalette_Ivysaur
gMonPalette_Ivysaur: @ 0x8C307D8
	.incbin "baserom_jp.gba", 0xc307d8, 0x28

	.globl gMonBackPic_Ivysaur
gMonBackPic_Ivysaur: @ 0x8C30800
	.incbin "baserom_jp.gba", 0xc30800, 0x38c

	.globl gMonShinyPalette_Ivysaur
gMonShinyPalette_Ivysaur: @ 0x8C30B8C
	.incbin "baserom_jp.gba", 0xc30b8c, 0x448

	.globl gMonStillFrontPic_Venusaur
gMonStillFrontPic_Venusaur: @ 0x8C30FD4
	.incbin "baserom_jp.gba", 0xc30fd4, 0x58c

	.globl gMonPalette_Venusaur
gMonPalette_Venusaur: @ 0x8C31560
	.incbin "baserom_jp.gba", 0xc31560, 0x28

	.globl gMonBackPic_Venusaur
gMonBackPic_Venusaur: @ 0x8C31588
	.incbin "baserom_jp.gba", 0xc31588, 0x4d0

	.globl gMonShinyPalette_Venusaur
gMonShinyPalette_Venusaur: @ 0x8C31A58
	.incbin "baserom_jp.gba", 0xc31a58, 0x448

	.globl gMonStillFrontPic_Charmander
gMonStillFrontPic_Charmander: @ 0x8C31EA0
	.incbin "baserom_jp.gba", 0xc31ea0, 0x2b0

	.globl gMonPalette_Charmander
gMonPalette_Charmander: @ 0x8C32150
	.incbin "baserom_jp.gba", 0xc32150, 0x28

	.globl gMonBackPic_Charmander
gMonBackPic_Charmander: @ 0x8C32178
	.incbin "baserom_jp.gba", 0xc32178, 0x294

	.globl gMonShinyPalette_Charmander
gMonShinyPalette_Charmander: @ 0x8C3240C
	.incbin "baserom_jp.gba", 0xc3240c, 0x448

	.globl gMonStillFrontPic_Charmeleon
gMonStillFrontPic_Charmeleon: @ 0x8C32854
	.incbin "baserom_jp.gba", 0xc32854, 0x3a8

	.globl gMonPalette_Charmeleon
gMonPalette_Charmeleon: @ 0x8C32BFC
	.incbin "baserom_jp.gba", 0xc32bfc, 0x28

	.globl gMonBackPic_Charmeleon
gMonBackPic_Charmeleon: @ 0x8C32C24
	.incbin "baserom_jp.gba", 0xc32c24, 0x2e0

	.globl gMonShinyPalette_Charmeleon
gMonShinyPalette_Charmeleon: @ 0x8C32F04
	.incbin "baserom_jp.gba", 0xc32f04, 0x448

	.globl gMonStillFrontPic_Charizard
gMonStillFrontPic_Charizard: @ 0x8C3334C
	.incbin "baserom_jp.gba", 0xc3334c, 0x550

	.globl gMonPalette_Charizard
gMonPalette_Charizard: @ 0x8C3389C
	.incbin "baserom_jp.gba", 0xc3389c, 0x28

	.globl gMonBackPic_Charizard
gMonBackPic_Charizard: @ 0x8C338C4
	.incbin "baserom_jp.gba", 0xc338c4, 0x41c

	.globl gMonShinyPalette_Charizard
gMonShinyPalette_Charizard: @ 0x8C33CE0
	.incbin "baserom_jp.gba", 0xc33ce0, 0x448

	.globl gMonStillFrontPic_Squirtle
gMonStillFrontPic_Squirtle: @ 0x8C34128
	.incbin "baserom_jp.gba", 0xc34128, 0x2dc

	.globl gMonPalette_Squirtle
gMonPalette_Squirtle: @ 0x8C34404
	.incbin "baserom_jp.gba", 0xc34404, 0x28

	.globl gMonBackPic_Squirtle
gMonBackPic_Squirtle: @ 0x8C3442C
	.incbin "baserom_jp.gba", 0xc3442c, 0x280

	.globl gMonShinyPalette_Squirtle
gMonShinyPalette_Squirtle: @ 0x8C346AC
	.incbin "baserom_jp.gba", 0xc346ac, 0x448

	.globl gMonStillFrontPic_Wartortle
gMonStillFrontPic_Wartortle: @ 0x8C34AF4
	.incbin "baserom_jp.gba", 0xc34af4, 0x37c

	.globl gMonPalette_Wartortle
gMonPalette_Wartortle: @ 0x8C34E70
	.incbin "baserom_jp.gba", 0xc34e70, 0x28

	.globl gMonBackPic_Wartortle
gMonBackPic_Wartortle: @ 0x8C34E98
	.incbin "baserom_jp.gba", 0xc34e98, 0x334

	.globl gMonShinyPalette_Wartortle
gMonShinyPalette_Wartortle: @ 0x8C351CC
	.incbin "baserom_jp.gba", 0xc351cc, 0x448

	.globl gMonStillFrontPic_Blastoise
gMonStillFrontPic_Blastoise: @ 0x8C35614
	.incbin "baserom_jp.gba", 0xc35614, 0x504

	.globl gMonPalette_Blastoise
gMonPalette_Blastoise: @ 0x8C35B18
	.incbin "baserom_jp.gba", 0xc35b18, 0x28

	.globl gMonBackPic_Blastoise
gMonBackPic_Blastoise: @ 0x8C35B40
	.incbin "baserom_jp.gba", 0xc35b40, 0x41c

	.globl gMonShinyPalette_Blastoise
gMonShinyPalette_Blastoise: @ 0x8C35F5C
	.incbin "baserom_jp.gba", 0xc35f5c, 0x448

	.globl gMonStillFrontPic_Caterpie
gMonStillFrontPic_Caterpie: @ 0x8C363A4
	.incbin "baserom_jp.gba", 0xc363a4, 0x260

	.globl gMonPalette_Caterpie
gMonPalette_Caterpie: @ 0x8C36604
	.incbin "baserom_jp.gba", 0xc36604, 0x28

	.globl gMonBackPic_Caterpie
gMonBackPic_Caterpie: @ 0x8C3662C
	.incbin "baserom_jp.gba", 0xc3662c, 0x288

	.globl gMonShinyPalette_Caterpie
gMonShinyPalette_Caterpie: @ 0x8C368B4
	.incbin "baserom_jp.gba", 0xc368b4, 0x448

	.globl gMonStillFrontPic_Metapod
gMonStillFrontPic_Metapod: @ 0x8C36CFC
	.incbin "baserom_jp.gba", 0xc36cfc, 0x218

	.globl gMonPalette_Metapod
gMonPalette_Metapod: @ 0x8C36F14
	.incbin "baserom_jp.gba", 0xc36f14, 0x20

	.globl gMonBackPic_Metapod
gMonBackPic_Metapod: @ 0x8C36F34
	.incbin "baserom_jp.gba", 0xc36f34, 0x240

	.globl gMonShinyPalette_Metapod
gMonShinyPalette_Metapod: @ 0x8C37174
	.incbin "baserom_jp.gba", 0xc37174, 0x440

	.globl gMonStillFrontPic_Butterfree
gMonStillFrontPic_Butterfree: @ 0x8C375B4
	.incbin "baserom_jp.gba", 0xc375b4, 0x360

	.globl gMonPalette_Butterfree
gMonPalette_Butterfree: @ 0x8C37914
	.incbin "baserom_jp.gba", 0xc37914, 0x28

	.globl gMonBackPic_Butterfree
gMonBackPic_Butterfree: @ 0x8C3793C
	.incbin "baserom_jp.gba", 0xc3793c, 0x410

	.globl gMonShinyPalette_Butterfree
gMonShinyPalette_Butterfree: @ 0x8C37D4C
	.incbin "baserom_jp.gba", 0xc37d4c, 0x448

	.globl gMonStillFrontPic_Weedle
gMonStillFrontPic_Weedle: @ 0x8C38194
	.incbin "baserom_jp.gba", 0xc38194, 0x240

	.globl gMonPalette_Weedle
gMonPalette_Weedle: @ 0x8C383D4
	.incbin "baserom_jp.gba", 0xc383d4, 0x28

	.globl gMonBackPic_Weedle
gMonBackPic_Weedle: @ 0x8C383FC
	.incbin "baserom_jp.gba", 0xc383fc, 0x268

	.globl gMonShinyPalette_Weedle
gMonShinyPalette_Weedle: @ 0x8C38664
	.incbin "baserom_jp.gba", 0xc38664, 0x448

	.globl gMonStillFrontPic_Kakuna
gMonStillFrontPic_Kakuna: @ 0x8C38AAC
	.incbin "baserom_jp.gba", 0xc38aac, 0x24c

	.globl gMonPalette_Kakuna
gMonPalette_Kakuna: @ 0x8C38CF8
	.incbin "baserom_jp.gba", 0xc38cf8, 0x24

	.globl gMonBackPic_Kakuna
gMonBackPic_Kakuna: @ 0x8C38D1C
	.incbin "baserom_jp.gba", 0xc38d1c, 0x284

	.globl gMonShinyPalette_Kakuna
gMonShinyPalette_Kakuna: @ 0x8C38FA0
	.incbin "baserom_jp.gba", 0xc38fa0, 0x444

	.globl gMonStillFrontPic_Beedrill
gMonStillFrontPic_Beedrill: @ 0x8C393E4
	.incbin "baserom_jp.gba", 0xc393e4, 0x410

	.globl gMonPalette_Beedrill
gMonPalette_Beedrill: @ 0x8C397F4
	.incbin "baserom_jp.gba", 0xc397f4, 0x28

	.globl gMonBackPic_Beedrill
gMonBackPic_Beedrill: @ 0x8C3981C
	.incbin "baserom_jp.gba", 0xc3981c, 0x374

	.globl gMonShinyPalette_Beedrill
gMonShinyPalette_Beedrill: @ 0x8C39B90
	.incbin "baserom_jp.gba", 0xc39b90, 0x448

	.globl gMonStillFrontPic_Pidgey
gMonStillFrontPic_Pidgey: @ 0x8C39FD8
	.incbin "baserom_jp.gba", 0xc39fd8, 0x2ec

	.globl gMonPalette_Pidgey
gMonPalette_Pidgey: @ 0x8C3A2C4
	.incbin "baserom_jp.gba", 0xc3a2c4, 0x28

	.globl gMonBackPic_Pidgey
gMonBackPic_Pidgey: @ 0x8C3A2EC
	.incbin "baserom_jp.gba", 0xc3a2ec, 0x354

	.globl gMonShinyPalette_Pidgey
gMonShinyPalette_Pidgey: @ 0x8C3A640
	.incbin "baserom_jp.gba", 0xc3a640, 0x448

	.globl gMonStillFrontPic_Pidgeotto
gMonStillFrontPic_Pidgeotto: @ 0x8C3AA88
	.incbin "baserom_jp.gba", 0xc3aa88, 0x374

	.globl gMonPalette_Pidgeotto
gMonPalette_Pidgeotto: @ 0x8C3ADFC
	.incbin "baserom_jp.gba", 0xc3adfc, 0x28

	.globl gMonBackPic_Pidgeotto
gMonBackPic_Pidgeotto: @ 0x8C3AE24
	.incbin "baserom_jp.gba", 0xc3ae24, 0x34c

	.globl gMonShinyPalette_Pidgeotto
gMonShinyPalette_Pidgeotto: @ 0x8C3B170
	.incbin "baserom_jp.gba", 0xc3b170, 0x448

	.globl gMonStillFrontPic_Pidgeot
gMonStillFrontPic_Pidgeot: @ 0x8C3B5B8
	.incbin "baserom_jp.gba", 0xc3b5b8, 0x4fc

	.globl gMonPalette_Pidgeot
gMonPalette_Pidgeot: @ 0x8C3BAB4
	.incbin "baserom_jp.gba", 0xc3bab4, 0x28

	.globl gMonBackPic_Pidgeot
gMonBackPic_Pidgeot: @ 0x8C3BADC
	.incbin "baserom_jp.gba", 0xc3badc, 0x388

	.globl gMonShinyPalette_Pidgeot
gMonShinyPalette_Pidgeot: @ 0x8C3BE64
	.incbin "baserom_jp.gba", 0xc3be64, 0x448

	.globl gMonStillFrontPic_Rattata
gMonStillFrontPic_Rattata: @ 0x8C3C2AC
	.incbin "baserom_jp.gba", 0xc3c2ac, 0x24c

	.globl gMonPalette_Rattata
gMonPalette_Rattata: @ 0x8C3C4F8
	.incbin "baserom_jp.gba", 0xc3c4f8, 0x28

	.globl gMonBackPic_Rattata
gMonBackPic_Rattata: @ 0x8C3C520
	.incbin "baserom_jp.gba", 0xc3c520, 0x2dc

	.globl gMonShinyPalette_Rattata
gMonShinyPalette_Rattata: @ 0x8C3C7FC
	.incbin "baserom_jp.gba", 0xc3c7fc, 0x448

	.globl gMonStillFrontPic_Raticate
gMonStillFrontPic_Raticate: @ 0x8C3CC44
	.incbin "baserom_jp.gba", 0xc3cc44, 0x388

	.globl gMonPalette_Raticate
gMonPalette_Raticate: @ 0x8C3CFCC
	.incbin "baserom_jp.gba", 0xc3cfcc, 0x28

	.globl gMonBackPic_Raticate
gMonBackPic_Raticate: @ 0x8C3CFF4
	.incbin "baserom_jp.gba", 0xc3cff4, 0x330

	.globl gMonShinyPalette_Raticate
gMonShinyPalette_Raticate: @ 0x8C3D324
	.incbin "baserom_jp.gba", 0xc3d324, 0x448

	.globl gMonStillFrontPic_Spearow
gMonStillFrontPic_Spearow: @ 0x8C3D76C
	.incbin "baserom_jp.gba", 0xc3d76c, 0x288

	.globl gMonPalette_Spearow
gMonPalette_Spearow: @ 0x8C3D9F4
	.incbin "baserom_jp.gba", 0xc3d9f4, 0x28

	.globl gMonBackPic_Spearow
gMonBackPic_Spearow: @ 0x8C3DA1C
	.incbin "baserom_jp.gba", 0xc3da1c, 0x2dc

	.globl gMonShinyPalette_Spearow
gMonShinyPalette_Spearow: @ 0x8C3DCF8
	.incbin "baserom_jp.gba", 0xc3dcf8, 0x448

	.globl gMonStillFrontPic_Fearow
gMonStillFrontPic_Fearow: @ 0x8C3E140
	.incbin "baserom_jp.gba", 0xc3e140, 0x494

	.globl gMonPalette_Fearow
gMonPalette_Fearow: @ 0x8C3E5D4
	.incbin "baserom_jp.gba", 0xc3e5d4, 0x28

	.globl gMonBackPic_Fearow
gMonBackPic_Fearow: @ 0x8C3E5FC
	.incbin "baserom_jp.gba", 0xc3e5fc, 0x2f8

	.globl gMonShinyPalette_Fearow
gMonShinyPalette_Fearow: @ 0x8C3E8F4
	.incbin "baserom_jp.gba", 0xc3e8f4, 0x448

	.globl gMonStillFrontPic_Ekans
gMonStillFrontPic_Ekans: @ 0x8C3ED3C
	.incbin "baserom_jp.gba", 0xc3ed3c, 0x300

	.globl gMonPalette_Ekans
gMonPalette_Ekans: @ 0x8C3F03C
	.incbin "baserom_jp.gba", 0xc3f03c, 0x28

	.globl gMonBackPic_Ekans
gMonBackPic_Ekans: @ 0x8C3F064
	.incbin "baserom_jp.gba", 0xc3f064, 0x2f0

	.globl gMonShinyPalette_Ekans
gMonShinyPalette_Ekans: @ 0x8C3F354
	.incbin "baserom_jp.gba", 0xc3f354, 0x448

	.globl gMonStillFrontPic_Arbok
gMonStillFrontPic_Arbok: @ 0x8C3F79C
	.incbin "baserom_jp.gba", 0xc3f79c, 0x44c

	.globl gMonPalette_Arbok
gMonPalette_Arbok: @ 0x8C3FBE8
	.incbin "baserom_jp.gba", 0xc3fbe8, 0x28

	.globl gMonBackPic_Arbok
gMonBackPic_Arbok: @ 0x8C3FC10
	.incbin "baserom_jp.gba", 0xc3fc10, 0x2a0

	.globl gMonShinyPalette_Arbok
gMonShinyPalette_Arbok: @ 0x8C3FEB0
	.incbin "baserom_jp.gba", 0xc3feb0, 0x448

	.globl gMonStillFrontPic_Pikachu
gMonStillFrontPic_Pikachu: @ 0x8C402F8
	.incbin "baserom_jp.gba", 0xc402f8, 0x2d0

	.globl gMonPalette_Pikachu
gMonPalette_Pikachu: @ 0x8C405C8
	.incbin "baserom_jp.gba", 0xc405c8, 0x28

	.globl gMonBackPic_Pikachu
gMonBackPic_Pikachu: @ 0x8C405F0
	.incbin "baserom_jp.gba", 0xc405f0, 0x2d8

	.globl gMonShinyPalette_Pikachu
gMonShinyPalette_Pikachu: @ 0x8C408C8
	.incbin "baserom_jp.gba", 0xc408c8, 0x448

	.globl gMonStillFrontPic_Raichu
gMonStillFrontPic_Raichu: @ 0x8C40D10
	.incbin "baserom_jp.gba", 0xc40d10, 0x3ac

	.globl gMonPalette_Raichu
gMonPalette_Raichu: @ 0x8C410BC
	.incbin "baserom_jp.gba", 0xc410bc, 0x28

	.globl gMonBackPic_Raichu
gMonBackPic_Raichu: @ 0x8C410E4
	.incbin "baserom_jp.gba", 0xc410e4, 0x320

	.globl gMonShinyPalette_Raichu
gMonShinyPalette_Raichu: @ 0x8C41404
	.incbin "baserom_jp.gba", 0xc41404, 0x448

	.globl gMonStillFrontPic_Sandshrew
gMonStillFrontPic_Sandshrew: @ 0x8C4184C
	.incbin "baserom_jp.gba", 0xc4184c, 0x2c0

	.globl gMonPalette_Sandshrew
gMonPalette_Sandshrew: @ 0x8C41B0C
	.incbin "baserom_jp.gba", 0xc41b0c, 0x28

	.globl gMonBackPic_Sandshrew
gMonBackPic_Sandshrew: @ 0x8C41B34
	.incbin "baserom_jp.gba", 0xc41b34, 0x328

	.globl gMonShinyPalette_Sandshrew
gMonShinyPalette_Sandshrew: @ 0x8C41E5C
	.incbin "baserom_jp.gba", 0xc41e5c, 0x448

	.globl gMonStillFrontPic_Sandslash
gMonStillFrontPic_Sandslash: @ 0x8C422A4
	.incbin "baserom_jp.gba", 0xc422a4, 0x3ec

	.globl gMonPalette_Sandslash
gMonPalette_Sandslash: @ 0x8C42690
	.incbin "baserom_jp.gba", 0xc42690, 0x28

	.globl gMonBackPic_Sandslash
gMonBackPic_Sandslash: @ 0x8C426B8
	.incbin "baserom_jp.gba", 0xc426b8, 0x41c

	.globl gMonShinyPalette_Sandslash
gMonShinyPalette_Sandslash: @ 0x8C42AD4
	.incbin "baserom_jp.gba", 0xc42ad4, 0x448

	.globl gMonStillFrontPic_NidoranF
gMonStillFrontPic_NidoranF: @ 0x8C42F1C
	.incbin "baserom_jp.gba", 0xc42f1c, 0x278

	.globl gMonPalette_NidoranF
gMonPalette_NidoranF: @ 0x8C43194
	.incbin "baserom_jp.gba", 0xc43194, 0x28

	.globl gMonBackPic_NidoranF
gMonBackPic_NidoranF: @ 0x8C431BC
	.incbin "baserom_jp.gba", 0xc431bc, 0x2d8

	.globl gMonShinyPalette_NidoranF
gMonShinyPalette_NidoranF: @ 0x8C43494
	.incbin "baserom_jp.gba", 0xc43494, 0x448

	.globl gMonStillFrontPic_Nidorina
gMonStillFrontPic_Nidorina: @ 0x8C438DC
	.incbin "baserom_jp.gba", 0xc438dc, 0x32c

	.globl gMonPalette_Nidorina
gMonPalette_Nidorina: @ 0x8C43C08
	.incbin "baserom_jp.gba", 0xc43c08, 0x28

	.globl gMonBackPic_Nidorina
gMonBackPic_Nidorina: @ 0x8C43C30
	.incbin "baserom_jp.gba", 0xc43c30, 0x394

	.globl gMonShinyPalette_Nidorina
gMonShinyPalette_Nidorina: @ 0x8C43FC4
	.incbin "baserom_jp.gba", 0xc43fc4, 0x448

	.globl gMonStillFrontPic_Nidoqueen
gMonStillFrontPic_Nidoqueen: @ 0x8C4440C
	.incbin "baserom_jp.gba", 0xc4440c, 0x48c

	.globl gMonPalette_Nidoqueen
gMonPalette_Nidoqueen: @ 0x8C44898
	.incbin "baserom_jp.gba", 0xc44898, 0x28

	.globl gMonBackPic_Nidoqueen
gMonBackPic_Nidoqueen: @ 0x8C448C0
	.incbin "baserom_jp.gba", 0xc448c0, 0x3c4

	.globl gMonShinyPalette_Nidoqueen
gMonShinyPalette_Nidoqueen: @ 0x8C44C84
	.incbin "baserom_jp.gba", 0xc44c84, 0x448

	.globl gMonStillFrontPic_NidoranM
gMonStillFrontPic_NidoranM: @ 0x8C450CC
	.incbin "baserom_jp.gba", 0xc450cc, 0x2d0

	.globl gMonPalette_NidoranM
gMonPalette_NidoranM: @ 0x8C4539C
	.incbin "baserom_jp.gba", 0xc4539c, 0x28

	.globl gMonBackPic_NidoranM
gMonBackPic_NidoranM: @ 0x8C453C4
	.incbin "baserom_jp.gba", 0xc453c4, 0x334

	.globl gMonShinyPalette_NidoranM
gMonShinyPalette_NidoranM: @ 0x8C456F8
	.incbin "baserom_jp.gba", 0xc456f8, 0x448

	.globl gMonStillFrontPic_Nidorino
gMonStillFrontPic_Nidorino: @ 0x8C45B40
	.incbin "baserom_jp.gba", 0xc45b40, 0x394

	.globl gMonPalette_Nidorino
gMonPalette_Nidorino: @ 0x8C45ED4
	.incbin "baserom_jp.gba", 0xc45ed4, 0x28

	.globl gMonBackPic_Nidorino
gMonBackPic_Nidorino: @ 0x8C45EFC
	.incbin "baserom_jp.gba", 0xc45efc, 0x3bc

	.globl gMonShinyPalette_Nidorino
gMonShinyPalette_Nidorino: @ 0x8C462B8
	.incbin "baserom_jp.gba", 0xc462b8, 0x448

	.globl gMonStillFrontPic_Nidoking
gMonStillFrontPic_Nidoking: @ 0x8C46700
	.incbin "baserom_jp.gba", 0xc46700, 0x4f8

	.globl gMonPalette_Nidoking
gMonPalette_Nidoking: @ 0x8C46BF8
	.incbin "baserom_jp.gba", 0xc46bf8, 0x28

	.globl gMonBackPic_Nidoking
gMonBackPic_Nidoking: @ 0x8C46C20
	.incbin "baserom_jp.gba", 0xc46c20, 0x43c

	.globl gMonShinyPalette_Nidoking
gMonShinyPalette_Nidoking: @ 0x8C4705C
	.incbin "baserom_jp.gba", 0xc4705c, 0x448

	.globl gMonStillFrontPic_Clefairy
gMonStillFrontPic_Clefairy: @ 0x8C474A4
	.incbin "baserom_jp.gba", 0xc474a4, 0x288

	.globl gMonPalette_Clefairy
gMonPalette_Clefairy: @ 0x8C4772C
	.incbin "baserom_jp.gba", 0xc4772c, 0x28

	.globl gMonBackPic_Clefairy
gMonBackPic_Clefairy: @ 0x8C47754
	.incbin "baserom_jp.gba", 0xc47754, 0x2d0

	.globl gMonShinyPalette_Clefairy
gMonShinyPalette_Clefairy: @ 0x8C47A24
	.incbin "baserom_jp.gba", 0xc47a24, 0x448

	.globl gMonStillFrontPic_Clefable
gMonStillFrontPic_Clefable: @ 0x8C47E6C
	.incbin "baserom_jp.gba", 0xc47e6c, 0x33c

	.globl gMonPalette_Clefable
gMonPalette_Clefable: @ 0x8C481A8
	.incbin "baserom_jp.gba", 0xc481a8, 0x28

	.globl gMonBackPic_Clefable
gMonBackPic_Clefable: @ 0x8C481D0
	.incbin "baserom_jp.gba", 0xc481d0, 0x338

	.globl gMonShinyPalette_Clefable
gMonShinyPalette_Clefable: @ 0x8C48508
	.incbin "baserom_jp.gba", 0xc48508, 0x448

	.globl gMonStillFrontPic_Vulpix
gMonStillFrontPic_Vulpix: @ 0x8C48950
	.incbin "baserom_jp.gba", 0xc48950, 0x33c

	.globl gMonPalette_Vulpix
gMonPalette_Vulpix: @ 0x8C48C8C
	.incbin "baserom_jp.gba", 0xc48c8c, 0x28

	.globl gMonBackPic_Vulpix
gMonBackPic_Vulpix: @ 0x8C48CB4
	.incbin "baserom_jp.gba", 0xc48cb4, 0x2fc

	.globl gMonShinyPalette_Vulpix
gMonShinyPalette_Vulpix: @ 0x8C48FB0
	.incbin "baserom_jp.gba", 0xc48fb0, 0x448

	.globl gMonStillFrontPic_Ninetales
gMonStillFrontPic_Ninetales: @ 0x8C493F8
	.incbin "baserom_jp.gba", 0xc493f8, 0x43c

	.globl gMonPalette_Ninetales
gMonPalette_Ninetales: @ 0x8C49834
	.incbin "baserom_jp.gba", 0xc49834, 0x20

	.globl gMonBackPic_Ninetales
gMonBackPic_Ninetales: @ 0x8C49854
	.incbin "baserom_jp.gba", 0xc49854, 0x380

	.globl gMonShinyPalette_Ninetales
gMonShinyPalette_Ninetales: @ 0x8C49BD4
	.incbin "baserom_jp.gba", 0xc49bd4, 0x440

	.globl gMonStillFrontPic_Jigglypuff
gMonStillFrontPic_Jigglypuff: @ 0x8C4A014
	.incbin "baserom_jp.gba", 0xc4a014, 0x278

	.globl gMonPalette_Jigglypuff
gMonPalette_Jigglypuff: @ 0x8C4A28C
	.incbin "baserom_jp.gba", 0xc4a28c, 0x28

	.globl gMonBackPic_Jigglypuff
gMonBackPic_Jigglypuff: @ 0x8C4A2B4
	.incbin "baserom_jp.gba", 0xc4a2b4, 0x25c

	.globl gMonShinyPalette_Jigglypuff
gMonShinyPalette_Jigglypuff: @ 0x8C4A510
	.incbin "baserom_jp.gba", 0xc4a510, 0x448

	.globl gMonStillFrontPic_Wigglytuff
gMonStillFrontPic_Wigglytuff: @ 0x8C4A958
	.incbin "baserom_jp.gba", 0xc4a958, 0x354

	.globl gMonPalette_Wigglytuff
gMonPalette_Wigglytuff: @ 0x8C4ACAC
	.incbin "baserom_jp.gba", 0xc4acac, 0x28

	.globl gMonBackPic_Wigglytuff
gMonBackPic_Wigglytuff: @ 0x8C4ACD4
	.incbin "baserom_jp.gba", 0xc4acd4, 0x2a8

	.globl gMonShinyPalette_Wigglytuff
gMonShinyPalette_Wigglytuff: @ 0x8C4AF7C
	.incbin "baserom_jp.gba", 0xc4af7c, 0x448

	.globl gMonStillFrontPic_Zubat
gMonStillFrontPic_Zubat: @ 0x8C4B3C4
	.incbin "baserom_jp.gba", 0xc4b3c4, 0x2d8

	.globl gMonPalette_Zubat
gMonPalette_Zubat: @ 0x8C4B69C
	.incbin "baserom_jp.gba", 0xc4b69c, 0x28

	.globl gMonBackPic_Zubat
gMonBackPic_Zubat: @ 0x8C4B6C4
	.incbin "baserom_jp.gba", 0xc4b6c4, 0x2bc

	.globl gMonShinyPalette_Zubat
gMonShinyPalette_Zubat: @ 0x8C4B980
	.incbin "baserom_jp.gba", 0xc4b980, 0x448

	.globl gMonStillFrontPic_Golbat
gMonStillFrontPic_Golbat: @ 0x8C4BDC8
	.incbin "baserom_jp.gba", 0xc4bdc8, 0x39c

	.globl gMonPalette_Golbat
gMonPalette_Golbat: @ 0x8C4C164
	.incbin "baserom_jp.gba", 0xc4c164, 0x28

	.globl gMonBackPic_Golbat
gMonBackPic_Golbat: @ 0x8C4C18C
	.incbin "baserom_jp.gba", 0xc4c18c, 0x2bc

	.globl gMonShinyPalette_Golbat
gMonShinyPalette_Golbat: @ 0x8C4C448
	.incbin "baserom_jp.gba", 0xc4c448, 0x448

	.globl gMonStillFrontPic_Oddish
gMonStillFrontPic_Oddish: @ 0x8C4C890
	.incbin "baserom_jp.gba", 0xc4c890, 0x234

	.globl gMonPalette_Oddish
gMonPalette_Oddish: @ 0x8C4CAC4
	.incbin "baserom_jp.gba", 0xc4cac4, 0x28

	.globl gMonBackPic_Oddish
gMonBackPic_Oddish: @ 0x8C4CAEC
	.incbin "baserom_jp.gba", 0xc4caec, 0x278

	.globl gMonShinyPalette_Oddish
gMonShinyPalette_Oddish: @ 0x8C4CD64
	.incbin "baserom_jp.gba", 0xc4cd64, 0x448

	.globl gMonStillFrontPic_Gloom
gMonStillFrontPic_Gloom: @ 0x8C4D1AC
	.incbin "baserom_jp.gba", 0xc4d1ac, 0x378

	.globl gMonPalette_Gloom
gMonPalette_Gloom: @ 0x8C4D524
	.incbin "baserom_jp.gba", 0xc4d524, 0x28

	.globl gMonBackPic_Gloom
gMonBackPic_Gloom: @ 0x8C4D54C
	.incbin "baserom_jp.gba", 0xc4d54c, 0x368

	.globl gMonShinyPalette_Gloom
gMonShinyPalette_Gloom: @ 0x8C4D8B4
	.incbin "baserom_jp.gba", 0xc4d8b4, 0x448

	.globl gMonStillFrontPic_Vileplume
gMonStillFrontPic_Vileplume: @ 0x8C4DCFC
	.incbin "baserom_jp.gba", 0xc4dcfc, 0x37c

	.globl gMonPalette_Vileplume
gMonPalette_Vileplume: @ 0x8C4E078
	.incbin "baserom_jp.gba", 0xc4e078, 0x28

	.globl gMonBackPic_Vileplume
gMonBackPic_Vileplume: @ 0x8C4E0A0
	.incbin "baserom_jp.gba", 0xc4e0a0, 0x418

	.globl gMonShinyPalette_Vileplume
gMonShinyPalette_Vileplume: @ 0x8C4E4B8
	.incbin "baserom_jp.gba", 0xc4e4b8, 0x448

	.globl gMonStillFrontPic_Paras
gMonStillFrontPic_Paras: @ 0x8C4E900
	.incbin "baserom_jp.gba", 0xc4e900, 0x26c

	.globl gMonPalette_Paras
gMonPalette_Paras: @ 0x8C4EB6C
	.incbin "baserom_jp.gba", 0xc4eb6c, 0x28

	.globl gMonBackPic_Paras
gMonBackPic_Paras: @ 0x8C4EB94
	.incbin "baserom_jp.gba", 0xc4eb94, 0x2a0

	.globl gMonShinyPalette_Paras
gMonShinyPalette_Paras: @ 0x8C4EE34
	.incbin "baserom_jp.gba", 0xc4ee34, 0x448

	.globl gMonStillFrontPic_Parasect
gMonStillFrontPic_Parasect: @ 0x8C4F27C
	.incbin "baserom_jp.gba", 0xc4f27c, 0x3c4

	.globl gMonPalette_Parasect
gMonPalette_Parasect: @ 0x8C4F640
	.incbin "baserom_jp.gba", 0xc4f640, 0x28

	.globl gMonBackPic_Parasect
gMonBackPic_Parasect: @ 0x8C4F668
	.incbin "baserom_jp.gba", 0xc4f668, 0x2fc

	.globl gMonShinyPalette_Parasect
gMonShinyPalette_Parasect: @ 0x8C4F964
	.incbin "baserom_jp.gba", 0xc4f964, 0x448

	.globl gMonStillFrontPic_Venonat
gMonStillFrontPic_Venonat: @ 0x8C4FDAC
	.incbin "baserom_jp.gba", 0xc4fdac, 0x378

	.globl gMonPalette_Venonat
gMonPalette_Venonat: @ 0x8C50124
	.incbin "baserom_jp.gba", 0xc50124, 0x28

	.globl gMonBackPic_Venonat
gMonBackPic_Venonat: @ 0x8C5014C
	.incbin "baserom_jp.gba", 0xc5014c, 0x330

	.globl gMonShinyPalette_Venonat
gMonShinyPalette_Venonat: @ 0x8C5047C
	.incbin "baserom_jp.gba", 0xc5047c, 0x448

	.globl gMonStillFrontPic_Venomoth
gMonStillFrontPic_Venomoth: @ 0x8C508C4
	.incbin "baserom_jp.gba", 0xc508c4, 0x4a4

	.globl gMonPalette_Venomoth
gMonPalette_Venomoth: @ 0x8C50D68
	.incbin "baserom_jp.gba", 0xc50d68, 0x28

	.globl gMonBackPic_Venomoth
gMonBackPic_Venomoth: @ 0x8C50D90
	.incbin "baserom_jp.gba", 0xc50d90, 0x3c4

	.globl gMonShinyPalette_Venomoth
gMonShinyPalette_Venomoth: @ 0x8C51154
	.incbin "baserom_jp.gba", 0xc51154, 0x448

	.globl gMonStillFrontPic_Diglett
gMonStillFrontPic_Diglett: @ 0x8C5159C
	.incbin "baserom_jp.gba", 0xc5159c, 0x20c

	.globl gMonPalette_Diglett
gMonPalette_Diglett: @ 0x8C517A8
	.incbin "baserom_jp.gba", 0xc517a8, 0x28

	.globl gMonBackPic_Diglett
gMonBackPic_Diglett: @ 0x8C517D0
	.incbin "baserom_jp.gba", 0xc517d0, 0x20c

	.globl gMonShinyPalette_Diglett
gMonShinyPalette_Diglett: @ 0x8C519DC
	.incbin "baserom_jp.gba", 0xc519dc, 0x448

	.globl gMonStillFrontPic_Dugtrio
gMonStillFrontPic_Dugtrio: @ 0x8C51E24
	.incbin "baserom_jp.gba", 0xc51e24, 0x324

	.globl gMonPalette_Dugtrio
gMonPalette_Dugtrio: @ 0x8C52148
	.incbin "baserom_jp.gba", 0xc52148, 0x28

	.globl gMonBackPic_Dugtrio
gMonBackPic_Dugtrio: @ 0x8C52170
	.incbin "baserom_jp.gba", 0xc52170, 0x2ac

	.globl gMonShinyPalette_Dugtrio
gMonShinyPalette_Dugtrio: @ 0x8C5241C
	.incbin "baserom_jp.gba", 0xc5241c, 0x448

	.globl gMonStillFrontPic_Meowth
gMonStillFrontPic_Meowth: @ 0x8C52864
	.incbin "baserom_jp.gba", 0xc52864, 0x2ec

	.globl gMonPalette_Meowth
gMonPalette_Meowth: @ 0x8C52B50
	.incbin "baserom_jp.gba", 0xc52b50, 0x28

	.globl gMonBackPic_Meowth
gMonBackPic_Meowth: @ 0x8C52B78
	.incbin "baserom_jp.gba", 0xc52b78, 0x2e4

	.globl gMonShinyPalette_Meowth
gMonShinyPalette_Meowth: @ 0x8C52E5C
	.incbin "baserom_jp.gba", 0xc52e5c, 0x448

	.globl gMonStillFrontPic_Persian
gMonStillFrontPic_Persian: @ 0x8C532A4
	.incbin "baserom_jp.gba", 0xc532a4, 0x3b4

	.globl gMonPalette_Persian
gMonPalette_Persian: @ 0x8C53658
	.incbin "baserom_jp.gba", 0xc53658, 0x28

	.globl gMonBackPic_Persian
gMonBackPic_Persian: @ 0x8C53680
	.incbin "baserom_jp.gba", 0xc53680, 0x364

	.globl gMonShinyPalette_Persian
gMonShinyPalette_Persian: @ 0x8C539E4
	.incbin "baserom_jp.gba", 0xc539e4, 0x448

	.globl gMonStillFrontPic_Psyduck
gMonStillFrontPic_Psyduck: @ 0x8C53E2C
	.incbin "baserom_jp.gba", 0xc53e2c, 0x2d8

	.globl gMonPalette_Psyduck
gMonPalette_Psyduck: @ 0x8C54104
	.incbin "baserom_jp.gba", 0xc54104, 0x28

	.globl gMonBackPic_Psyduck
gMonBackPic_Psyduck: @ 0x8C5412C
	.incbin "baserom_jp.gba", 0xc5412c, 0x29c

	.globl gMonShinyPalette_Psyduck
gMonShinyPalette_Psyduck: @ 0x8C543C8
	.incbin "baserom_jp.gba", 0xc543c8, 0x448

	.globl gMonStillFrontPic_Golduck
gMonStillFrontPic_Golduck: @ 0x8C54810
	.incbin "baserom_jp.gba", 0xc54810, 0x3d8

	.globl gMonPalette_Golduck
gMonPalette_Golduck: @ 0x8C54BE8
	.incbin "baserom_jp.gba", 0xc54be8, 0x28

	.globl gMonBackPic_Golduck
gMonBackPic_Golduck: @ 0x8C54C10
	.incbin "baserom_jp.gba", 0xc54c10, 0x32c

	.globl gMonShinyPalette_Golduck
gMonShinyPalette_Golduck: @ 0x8C54F3C
	.incbin "baserom_jp.gba", 0xc54f3c, 0x448

	.globl gMonStillFrontPic_Mankey
gMonStillFrontPic_Mankey: @ 0x8C55384
	.incbin "baserom_jp.gba", 0xc55384, 0x318

	.globl gMonPalette_Mankey
gMonPalette_Mankey: @ 0x8C5569C
	.incbin "baserom_jp.gba", 0xc5569c, 0x28

	.globl gMonBackPic_Mankey
gMonBackPic_Mankey: @ 0x8C556C4
	.incbin "baserom_jp.gba", 0xc556c4, 0x368

	.globl gMonShinyPalette_Mankey
gMonShinyPalette_Mankey: @ 0x8C55A2C
	.incbin "baserom_jp.gba", 0xc55a2c, 0x448

	.globl gMonStillFrontPic_Primeape
gMonStillFrontPic_Primeape: @ 0x8C55E74
	.incbin "baserom_jp.gba", 0xc55e74, 0x3b0

	.globl gMonPalette_Primeape
gMonPalette_Primeape: @ 0x8C56224
	.incbin "baserom_jp.gba", 0xc56224, 0x28

	.globl gMonBackPic_Primeape
gMonBackPic_Primeape: @ 0x8C5624C
	.incbin "baserom_jp.gba", 0xc5624c, 0x370

	.globl gMonShinyPalette_Primeape
gMonShinyPalette_Primeape: @ 0x8C565BC
	.incbin "baserom_jp.gba", 0xc565bc, 0x448

	.globl gMonStillFrontPic_Growlithe
gMonStillFrontPic_Growlithe: @ 0x8C56A04
	.incbin "baserom_jp.gba", 0xc56a04, 0x358

	.globl gMonPalette_Growlithe
gMonPalette_Growlithe: @ 0x8C56D5C
	.incbin "baserom_jp.gba", 0xc56d5c, 0x28

	.globl gMonBackPic_Growlithe
gMonBackPic_Growlithe: @ 0x8C56D84
	.incbin "baserom_jp.gba", 0xc56d84, 0x33c

	.globl gMonShinyPalette_Growlithe
gMonShinyPalette_Growlithe: @ 0x8C570C0
	.incbin "baserom_jp.gba", 0xc570c0, 0x448

	.globl gMonStillFrontPic_Arcanine
gMonStillFrontPic_Arcanine: @ 0x8C57508
	.incbin "baserom_jp.gba", 0xc57508, 0x534

	.globl gMonPalette_Arcanine
gMonPalette_Arcanine: @ 0x8C57A3C
	.incbin "baserom_jp.gba", 0xc57a3c, 0x28

	.globl gMonBackPic_Arcanine
gMonBackPic_Arcanine: @ 0x8C57A64
	.incbin "baserom_jp.gba", 0xc57a64, 0x3e0

	.globl gMonShinyPalette_Arcanine
gMonShinyPalette_Arcanine: @ 0x8C57E44
	.incbin "baserom_jp.gba", 0xc57e44, 0x448

	.globl gMonStillFrontPic_Poliwag
gMonStillFrontPic_Poliwag: @ 0x8C5828C
	.incbin "baserom_jp.gba", 0xc5828c, 0x288

	.globl gMonPalette_Poliwag
gMonPalette_Poliwag: @ 0x8C58514
	.incbin "baserom_jp.gba", 0xc58514, 0x28

	.globl gMonBackPic_Poliwag
gMonBackPic_Poliwag: @ 0x8C5853C
	.incbin "baserom_jp.gba", 0xc5853c, 0x270

	.globl gMonShinyPalette_Poliwag
gMonShinyPalette_Poliwag: @ 0x8C587AC
	.incbin "baserom_jp.gba", 0xc587ac, 0x448

	.globl gMonStillFrontPic_Poliwhirl
gMonStillFrontPic_Poliwhirl: @ 0x8C58BF4
	.incbin "baserom_jp.gba", 0xc58bf4, 0x3c4

	.globl gMonPalette_Poliwhirl
gMonPalette_Poliwhirl: @ 0x8C58FB8
	.incbin "baserom_jp.gba", 0xc58fb8, 0x28

	.globl gMonBackPic_Poliwhirl
gMonBackPic_Poliwhirl: @ 0x8C58FE0
	.incbin "baserom_jp.gba", 0xc58fe0, 0x2c0

	.globl gMonShinyPalette_Poliwhirl
gMonShinyPalette_Poliwhirl: @ 0x8C592A0
	.incbin "baserom_jp.gba", 0xc592a0, 0x448

	.globl gMonStillFrontPic_Poliwrath
gMonStillFrontPic_Poliwrath: @ 0x8C596E8
	.incbin "baserom_jp.gba", 0xc596e8, 0x3c8

	.globl gMonPalette_Poliwrath
gMonPalette_Poliwrath: @ 0x8C59AB0
	.incbin "baserom_jp.gba", 0xc59ab0, 0x28

	.globl gMonBackPic_Poliwrath
gMonBackPic_Poliwrath: @ 0x8C59AD8
	.incbin "baserom_jp.gba", 0xc59ad8, 0x320

	.globl gMonShinyPalette_Poliwrath
gMonShinyPalette_Poliwrath: @ 0x8C59DF8
	.incbin "baserom_jp.gba", 0xc59df8, 0x448

	.globl gMonStillFrontPic_Abra
gMonStillFrontPic_Abra: @ 0x8C5A240
	.incbin "baserom_jp.gba", 0xc5a240, 0x2e4

	.globl gMonPalette_Abra
gMonPalette_Abra: @ 0x8C5A524
	.incbin "baserom_jp.gba", 0xc5a524, 0x24

	.globl gMonBackPic_Abra
gMonBackPic_Abra: @ 0x8C5A548
	.incbin "baserom_jp.gba", 0xc5a548, 0x314

	.globl gMonShinyPalette_Abra
gMonShinyPalette_Abra: @ 0x8C5A85C
	.incbin "baserom_jp.gba", 0xc5a85c, 0x444

	.globl gMonStillFrontPic_Kadabra
gMonStillFrontPic_Kadabra: @ 0x8C5ACA0
	.incbin "baserom_jp.gba", 0xc5aca0, 0x464

	.globl gMonPalette_Kadabra
gMonPalette_Kadabra: @ 0x8C5B104
	.incbin "baserom_jp.gba", 0xc5b104, 0x28

	.globl gMonBackPic_Kadabra
gMonBackPic_Kadabra: @ 0x8C5B12C
	.incbin "baserom_jp.gba", 0xc5b12c, 0x3dc

	.globl gMonShinyPalette_Kadabra
gMonShinyPalette_Kadabra: @ 0x8C5B508
	.incbin "baserom_jp.gba", 0xc5b508, 0x448

	.globl gMonStillFrontPic_Alakazam
gMonStillFrontPic_Alakazam: @ 0x8C5B950
	.incbin "baserom_jp.gba", 0xc5b950, 0x3fc

	.globl gMonPalette_Alakazam
gMonPalette_Alakazam: @ 0x8C5BD4C
	.incbin "baserom_jp.gba", 0xc5bd4c, 0x28

	.globl gMonBackPic_Alakazam
gMonBackPic_Alakazam: @ 0x8C5BD74
	.incbin "baserom_jp.gba", 0xc5bd74, 0x444

	.globl gMonShinyPalette_Alakazam
gMonShinyPalette_Alakazam: @ 0x8C5C1B8
	.incbin "baserom_jp.gba", 0xc5c1b8, 0x448

	.globl gMonStillFrontPic_Machop
gMonStillFrontPic_Machop: @ 0x8C5C600
	.incbin "baserom_jp.gba", 0xc5c600, 0x2a4

	.globl gMonPalette_Machop
gMonPalette_Machop: @ 0x8C5C8A4
	.incbin "baserom_jp.gba", 0xc5c8a4, 0x28

	.globl gMonBackPic_Machop
gMonBackPic_Machop: @ 0x8C5C8CC
	.incbin "baserom_jp.gba", 0xc5c8cc, 0x2e0

	.globl gMonShinyPalette_Machop
gMonShinyPalette_Machop: @ 0x8C5CBAC
	.incbin "baserom_jp.gba", 0xc5cbac, 0x448

	.globl gMonStillFrontPic_Machoke
gMonStillFrontPic_Machoke: @ 0x8C5CFF4
	.incbin "baserom_jp.gba", 0xc5cff4, 0x3b0

	.globl gMonPalette_Machoke
gMonPalette_Machoke: @ 0x8C5D3A4
	.incbin "baserom_jp.gba", 0xc5d3a4, 0x28

	.globl gMonBackPic_Machoke
gMonBackPic_Machoke: @ 0x8C5D3CC
	.incbin "baserom_jp.gba", 0xc5d3cc, 0x350

	.globl gMonShinyPalette_Machoke
gMonShinyPalette_Machoke: @ 0x8C5D71C
	.incbin "baserom_jp.gba", 0xc5d71c, 0x448

	.globl gMonStillFrontPic_Machamp
gMonStillFrontPic_Machamp: @ 0x8C5DB64
	.incbin "baserom_jp.gba", 0xc5db64, 0x550

	.globl gMonPalette_Machamp
gMonPalette_Machamp: @ 0x8C5E0B4
	.incbin "baserom_jp.gba", 0xc5e0b4, 0x28

	.globl gMonBackPic_Machamp
gMonBackPic_Machamp: @ 0x8C5E0DC
	.incbin "baserom_jp.gba", 0xc5e0dc, 0x45c

	.globl gMonShinyPalette_Machamp
gMonShinyPalette_Machamp: @ 0x8C5E538
	.incbin "baserom_jp.gba", 0xc5e538, 0x448

	.globl gMonStillFrontPic_Bellsprout
gMonStillFrontPic_Bellsprout: @ 0x8C5E980
	.incbin "baserom_jp.gba", 0xc5e980, 0x280

	.globl gMonPalette_Bellsprout
gMonPalette_Bellsprout: @ 0x8C5EC00
	.incbin "baserom_jp.gba", 0xc5ec00, 0x28

	.globl gMonBackPic_Bellsprout
gMonBackPic_Bellsprout: @ 0x8C5EC28
	.incbin "baserom_jp.gba", 0xc5ec28, 0x29c

	.globl gMonShinyPalette_Bellsprout
gMonShinyPalette_Bellsprout: @ 0x8C5EEC4
	.incbin "baserom_jp.gba", 0xc5eec4, 0x448

	.globl gMonStillFrontPic_Weepinbell
gMonStillFrontPic_Weepinbell: @ 0x8C5F30C
	.incbin "baserom_jp.gba", 0xc5f30c, 0x324

	.globl gMonPalette_Weepinbell
gMonPalette_Weepinbell: @ 0x8C5F630
	.incbin "baserom_jp.gba", 0xc5f630, 0x28

	.globl gMonBackPic_Weepinbell
gMonBackPic_Weepinbell: @ 0x8C5F658
	.incbin "baserom_jp.gba", 0xc5f658, 0x2fc

	.globl gMonShinyPalette_Weepinbell
gMonShinyPalette_Weepinbell: @ 0x8C5F954
	.incbin "baserom_jp.gba", 0xc5f954, 0x448

	.globl gMonStillFrontPic_Victreebel
gMonStillFrontPic_Victreebel: @ 0x8C5FD9C
	.incbin "baserom_jp.gba", 0xc5fd9c, 0x42c

	.globl gMonPalette_Victreebel
gMonPalette_Victreebel: @ 0x8C601C8
	.incbin "baserom_jp.gba", 0xc601c8, 0x28

	.globl gMonBackPic_Victreebel
gMonBackPic_Victreebel: @ 0x8C601F0
	.incbin "baserom_jp.gba", 0xc601f0, 0x398

	.globl gMonShinyPalette_Victreebel
gMonShinyPalette_Victreebel: @ 0x8C60588
	.incbin "baserom_jp.gba", 0xc60588, 0x448

	.globl gMonStillFrontPic_Tentacool
gMonStillFrontPic_Tentacool: @ 0x8C609D0
	.incbin "baserom_jp.gba", 0xc609d0, 0x2a0

	.globl gMonPalette_Tentacool
gMonPalette_Tentacool: @ 0x8C60C70
	.incbin "baserom_jp.gba", 0xc60c70, 0x28

	.globl gMonBackPic_Tentacool
gMonBackPic_Tentacool: @ 0x8C60C98
	.incbin "baserom_jp.gba", 0xc60c98, 0x2cc

	.globl gMonShinyPalette_Tentacool
gMonShinyPalette_Tentacool: @ 0x8C60F64
	.incbin "baserom_jp.gba", 0xc60f64, 0x448

	.globl gMonStillFrontPic_Tentacruel
gMonStillFrontPic_Tentacruel: @ 0x8C613AC
	.incbin "baserom_jp.gba", 0xc613ac, 0x49c

	.globl gMonPalette_Tentacruel
gMonPalette_Tentacruel: @ 0x8C61848
	.incbin "baserom_jp.gba", 0xc61848, 0x28

	.globl gMonBackPic_Tentacruel
gMonBackPic_Tentacruel: @ 0x8C61870
	.incbin "baserom_jp.gba", 0xc61870, 0x39c

	.globl gMonShinyPalette_Tentacruel
gMonShinyPalette_Tentacruel: @ 0x8C61C0C
	.incbin "baserom_jp.gba", 0xc61c0c, 0x448

	.globl gMonStillFrontPic_Geodude
gMonStillFrontPic_Geodude: @ 0x8C62054
	.incbin "baserom_jp.gba", 0xc62054, 0x26c

	.globl gMonPalette_Geodude
gMonPalette_Geodude: @ 0x8C622C0
	.incbin "baserom_jp.gba", 0xc622c0, 0x1c

	.globl gMonBackPic_Geodude
gMonBackPic_Geodude: @ 0x8C622DC
	.incbin "baserom_jp.gba", 0xc622dc, 0x294

	.globl gMonShinyPalette_Geodude
gMonShinyPalette_Geodude: @ 0x8C62570
	.incbin "baserom_jp.gba", 0xc62570, 0x43c

	.globl gMonStillFrontPic_Graveler
gMonStillFrontPic_Graveler: @ 0x8C629AC
	.incbin "baserom_jp.gba", 0xc629ac, 0x408

	.globl gMonPalette_Graveler
gMonPalette_Graveler: @ 0x8C62DB4
	.incbin "baserom_jp.gba", 0xc62db4, 0x20

	.globl gMonBackPic_Graveler
gMonBackPic_Graveler: @ 0x8C62DD4
	.incbin "baserom_jp.gba", 0xc62dd4, 0x27c

	.globl gMonShinyPalette_Graveler
gMonShinyPalette_Graveler: @ 0x8C63050
	.incbin "baserom_jp.gba", 0xc63050, 0x440

	.globl gMonStillFrontPic_Golem
gMonStillFrontPic_Golem: @ 0x8C63490
	.incbin "baserom_jp.gba", 0xc63490, 0x47c

	.globl gMonPalette_Golem
gMonPalette_Golem: @ 0x8C6390C
	.incbin "baserom_jp.gba", 0xc6390c, 0x28

	.globl gMonBackPic_Golem
gMonBackPic_Golem: @ 0x8C63934
	.incbin "baserom_jp.gba", 0xc63934, 0x2c0

	.globl gMonShinyPalette_Golem
gMonShinyPalette_Golem: @ 0x8C63BF4
	.incbin "baserom_jp.gba", 0xc63bf4, 0x448

	.globl gMonStillFrontPic_Ponyta
gMonStillFrontPic_Ponyta: @ 0x8C6403C
	.incbin "baserom_jp.gba", 0xc6403c, 0x3a8

	.globl gMonPalette_Ponyta
gMonPalette_Ponyta: @ 0x8C643E4
	.incbin "baserom_jp.gba", 0xc643e4, 0x28

	.globl gMonBackPic_Ponyta
gMonBackPic_Ponyta: @ 0x8C6440C
	.incbin "baserom_jp.gba", 0xc6440c, 0x33c

	.globl gMonShinyPalette_Ponyta
gMonShinyPalette_Ponyta: @ 0x8C64748
	.incbin "baserom_jp.gba", 0xc64748, 0x448

	.globl gMonStillFrontPic_Rapidash
gMonStillFrontPic_Rapidash: @ 0x8C64B90
	.incbin "baserom_jp.gba", 0xc64b90, 0x4d0

	.globl gMonPalette_Rapidash
gMonPalette_Rapidash: @ 0x8C65060
	.incbin "baserom_jp.gba", 0xc65060, 0x28

	.globl gMonBackPic_Rapidash
gMonBackPic_Rapidash: @ 0x8C65088
	.incbin "baserom_jp.gba", 0xc65088, 0x410

	.globl gMonShinyPalette_Rapidash
gMonShinyPalette_Rapidash: @ 0x8C65498
	.incbin "baserom_jp.gba", 0xc65498, 0x448

	.globl gMonStillFrontPic_Slowpoke
gMonStillFrontPic_Slowpoke: @ 0x8C658E0
	.incbin "baserom_jp.gba", 0xc658e0, 0x30c

	.globl gMonPalette_Slowpoke
gMonPalette_Slowpoke: @ 0x8C65BEC
	.incbin "baserom_jp.gba", 0xc65bec, 0x28

	.globl gMonBackPic_Slowpoke
gMonBackPic_Slowpoke: @ 0x8C65C14
	.incbin "baserom_jp.gba", 0xc65c14, 0x264

	.globl gMonShinyPalette_Slowpoke
gMonShinyPalette_Slowpoke: @ 0x8C65E78
	.incbin "baserom_jp.gba", 0xc65e78, 0x448

	.globl gMonStillFrontPic_Slowbro
gMonStillFrontPic_Slowbro: @ 0x8C662C0
	.incbin "baserom_jp.gba", 0xc662c0, 0x4c0

	.globl gMonPalette_Slowbro
gMonPalette_Slowbro: @ 0x8C66780
	.incbin "baserom_jp.gba", 0xc66780, 0x28

	.globl gMonBackPic_Slowbro
gMonBackPic_Slowbro: @ 0x8C667A8
	.incbin "baserom_jp.gba", 0xc667a8, 0x39c

	.globl gMonShinyPalette_Slowbro
gMonShinyPalette_Slowbro: @ 0x8C66B44
	.incbin "baserom_jp.gba", 0xc66b44, 0x448

	.globl gMonStillFrontPic_Magnemite
gMonStillFrontPic_Magnemite: @ 0x8C66F8C
	.incbin "baserom_jp.gba", 0xc66f8c, 0x1d8

	.globl gMonPalette_Magnemite
gMonPalette_Magnemite: @ 0x8C67164
	.incbin "baserom_jp.gba", 0xc67164, 0x28

	.globl gMonBackPic_Magnemite
gMonBackPic_Magnemite: @ 0x8C6718C
	.incbin "baserom_jp.gba", 0xc6718c, 0x1e8

	.globl gMonShinyPalette_Magnemite
gMonShinyPalette_Magnemite: @ 0x8C67374
	.incbin "baserom_jp.gba", 0xc67374, 0x444

	.globl gMonStillFrontPic_Magneton
gMonStillFrontPic_Magneton: @ 0x8C677B8
	.incbin "baserom_jp.gba", 0xc677b8, 0x404

	.globl gMonPalette_Magneton
gMonPalette_Magneton: @ 0x8C67BBC
	.incbin "baserom_jp.gba", 0xc67bbc, 0x28

	.globl gMonBackPic_Magneton
gMonBackPic_Magneton: @ 0x8C67BE4
	.incbin "baserom_jp.gba", 0xc67be4, 0x380

	.globl gMonShinyPalette_Magneton
gMonShinyPalette_Magneton: @ 0x8C67F64
	.incbin "baserom_jp.gba", 0xc67f64, 0x448

	.globl gMonStillFrontPic_Farfetchd
gMonStillFrontPic_Farfetchd: @ 0x8C683AC
	.incbin "baserom_jp.gba", 0xc683ac, 0x37c

	.globl gMonPalette_Farfetchd
gMonPalette_Farfetchd: @ 0x8C68728
	.incbin "baserom_jp.gba", 0xc68728, 0x28

	.globl gMonBackPic_Farfetchd
gMonBackPic_Farfetchd: @ 0x8C68750
	.incbin "baserom_jp.gba", 0xc68750, 0x36c

	.globl gMonShinyPalette_Farfetchd
gMonShinyPalette_Farfetchd: @ 0x8C68ABC
	.incbin "baserom_jp.gba", 0xc68abc, 0x448

	.globl gMonStillFrontPic_Doduo
gMonStillFrontPic_Doduo: @ 0x8C68F04
	.incbin "baserom_jp.gba", 0xc68f04, 0x354

	.globl gMonPalette_Doduo
gMonPalette_Doduo: @ 0x8C69258
	.incbin "baserom_jp.gba", 0xc69258, 0x24

	.globl gMonBackPic_Doduo
gMonBackPic_Doduo: @ 0x8C6927C
	.incbin "baserom_jp.gba", 0xc6927c, 0x318

	.globl gMonShinyPalette_Doduo
gMonShinyPalette_Doduo: @ 0x8C69594
	.incbin "baserom_jp.gba", 0xc69594, 0x444

	.globl gMonStillFrontPic_Dodrio
gMonStillFrontPic_Dodrio: @ 0x8C699D8
	.incbin "baserom_jp.gba", 0xc699d8, 0x4dc

	.globl gMonPalette_Dodrio
gMonPalette_Dodrio: @ 0x8C69EB4
	.incbin "baserom_jp.gba", 0xc69eb4, 0x28

	.globl gMonBackPic_Dodrio
gMonBackPic_Dodrio: @ 0x8C69EDC
	.incbin "baserom_jp.gba", 0xc69edc, 0x464

	.globl gMonShinyPalette_Dodrio
gMonShinyPalette_Dodrio: @ 0x8C6A340
	.incbin "baserom_jp.gba", 0xc6a340, 0x448

	.globl gMonStillFrontPic_Seel
gMonStillFrontPic_Seel: @ 0x8C6A788
	.incbin "baserom_jp.gba", 0xc6a788, 0x308

	.globl gMonPalette_Seel
gMonPalette_Seel: @ 0x8C6AA90
	.incbin "baserom_jp.gba", 0xc6aa90, 0x28

	.globl gMonBackPic_Seel
gMonBackPic_Seel: @ 0x8C6AAB8
	.incbin "baserom_jp.gba", 0xc6aab8, 0x2ec

	.globl gMonShinyPalette_Seel
gMonShinyPalette_Seel: @ 0x8C6ADA4
	.incbin "baserom_jp.gba", 0xc6ada4, 0x448

	.globl gMonStillFrontPic_Dewgong
gMonStillFrontPic_Dewgong: @ 0x8C6B1EC
	.incbin "baserom_jp.gba", 0xc6b1ec, 0x3c8

	.globl gMonPalette_Dewgong
gMonPalette_Dewgong: @ 0x8C6B5B4
	.incbin "baserom_jp.gba", 0xc6b5b4, 0x20

	.globl gMonBackPic_Dewgong
gMonBackPic_Dewgong: @ 0x8C6B5D4
	.incbin "baserom_jp.gba", 0xc6b5d4, 0x294

	.globl gMonShinyPalette_Dewgong
gMonShinyPalette_Dewgong: @ 0x8C6B868
	.incbin "baserom_jp.gba", 0xc6b868, 0x440

	.globl gMonStillFrontPic_Grimer
gMonStillFrontPic_Grimer: @ 0x8C6BCA8
	.incbin "baserom_jp.gba", 0xc6bca8, 0x31c

	.globl gMonPalette_Grimer
gMonPalette_Grimer: @ 0x8C6BFC4
	.incbin "baserom_jp.gba", 0xc6bfc4, 0x24

	.globl gMonBackPic_Grimer
gMonBackPic_Grimer: @ 0x8C6BFE8
	.incbin "baserom_jp.gba", 0xc6bfe8, 0x2e4

	.globl gMonShinyPalette_Grimer
gMonShinyPalette_Grimer: @ 0x8C6C2CC
	.incbin "baserom_jp.gba", 0xc6c2cc, 0x444

	.globl gMonStillFrontPic_Muk
gMonStillFrontPic_Muk: @ 0x8C6C710
	.incbin "baserom_jp.gba", 0xc6c710, 0x44c

	.globl gMonPalette_Muk
gMonPalette_Muk: @ 0x8C6CB5C
	.incbin "baserom_jp.gba", 0xc6cb5c, 0x24

	.globl gMonBackPic_Muk
gMonBackPic_Muk: @ 0x8C6CB80
	.incbin "baserom_jp.gba", 0xc6cb80, 0x358

	.globl gMonShinyPalette_Muk
gMonShinyPalette_Muk: @ 0x8C6CED8
	.incbin "baserom_jp.gba", 0xc6ced8, 0x444

	.globl gMonStillFrontPic_Shellder
gMonStillFrontPic_Shellder: @ 0x8C6D31C
	.incbin "baserom_jp.gba", 0xc6d31c, 0x268

	.globl gMonPalette_Shellder
gMonPalette_Shellder: @ 0x8C6D584
	.incbin "baserom_jp.gba", 0xc6d584, 0x24

	.globl gMonBackPic_Shellder
gMonBackPic_Shellder: @ 0x8C6D5A8
	.incbin "baserom_jp.gba", 0xc6d5a8, 0x314

	.globl gMonShinyPalette_Shellder
gMonShinyPalette_Shellder: @ 0x8C6D8BC
	.incbin "baserom_jp.gba", 0xc6d8bc, 0x444

	.globl gMonStillFrontPic_Cloyster
gMonStillFrontPic_Cloyster: @ 0x8C6DD00
	.incbin "baserom_jp.gba", 0xc6dd00, 0x438

	.globl gMonPalette_Cloyster
gMonPalette_Cloyster: @ 0x8C6E138
	.incbin "baserom_jp.gba", 0xc6e138, 0x24

	.globl gMonBackPic_Cloyster
gMonBackPic_Cloyster: @ 0x8C6E15C
	.incbin "baserom_jp.gba", 0xc6e15c, 0x40c

	.globl gMonShinyPalette_Cloyster
gMonShinyPalette_Cloyster: @ 0x8C6E568
	.incbin "baserom_jp.gba", 0xc6e568, 0x444

	.globl gMonStillFrontPic_Gastly
gMonStillFrontPic_Gastly: @ 0x8C6E9AC
	.incbin "baserom_jp.gba", 0xc6e9ac, 0x3b8

	.globl gMonPalette_Gastly
gMonPalette_Gastly: @ 0x8C6ED64
	.incbin "baserom_jp.gba", 0xc6ed64, 0x28

	.globl gMonBackPic_Gastly
gMonBackPic_Gastly: @ 0x8C6ED8C
	.incbin "baserom_jp.gba", 0xc6ed8c, 0x324

	.globl gMonShinyPalette_Gastly
gMonShinyPalette_Gastly: @ 0x8C6F0B0
	.incbin "baserom_jp.gba", 0xc6f0b0, 0x448

	.globl gMonStillFrontPic_Haunter
gMonStillFrontPic_Haunter: @ 0x8C6F4F8
	.incbin "baserom_jp.gba", 0xc6f4f8, 0x400

	.globl gMonPalette_Haunter
gMonPalette_Haunter: @ 0x8C6F8F8
	.incbin "baserom_jp.gba", 0xc6f8f8, 0x24

	.globl gMonBackPic_Haunter
gMonBackPic_Haunter: @ 0x8C6F91C
	.incbin "baserom_jp.gba", 0xc6f91c, 0x328

	.globl gMonShinyPalette_Haunter
gMonShinyPalette_Haunter: @ 0x8C6FC44
	.incbin "baserom_jp.gba", 0xc6fc44, 0x444

	.globl gMonStillFrontPic_Gengar
gMonStillFrontPic_Gengar: @ 0x8C70088
	.incbin "baserom_jp.gba", 0xc70088, 0x39c

	.globl gMonPalette_Gengar
gMonPalette_Gengar: @ 0x8C70424
	.incbin "baserom_jp.gba", 0xc70424, 0x24

	.globl gMonBackPic_Gengar
gMonBackPic_Gengar: @ 0x8C70448
	.incbin "baserom_jp.gba", 0xc70448, 0x2e8

	.globl gMonShinyPalette_Gengar
gMonShinyPalette_Gengar: @ 0x8C70730
	.incbin "baserom_jp.gba", 0xc70730, 0x444

	.globl gMonStillFrontPic_Onix
gMonStillFrontPic_Onix: @ 0x8C70B74
	.incbin "baserom_jp.gba", 0xc70b74, 0x478

	.globl gMonPalette_Onix
gMonPalette_Onix: @ 0x8C70FEC
	.incbin "baserom_jp.gba", 0xc70fec, 0x1c

	.globl gMonBackPic_Onix
gMonBackPic_Onix: @ 0x8C71008
	.incbin "baserom_jp.gba", 0xc71008, 0x37c

	.globl gMonShinyPalette_Onix
gMonShinyPalette_Onix: @ 0x8C71384
	.incbin "baserom_jp.gba", 0xc71384, 0x43c

	.globl gMonStillFrontPic_Drowzee
gMonStillFrontPic_Drowzee: @ 0x8C717C0
	.incbin "baserom_jp.gba", 0xc717c0, 0x378

	.globl gMonPalette_Drowzee
gMonPalette_Drowzee: @ 0x8C71B38
	.incbin "baserom_jp.gba", 0xc71b38, 0x24

	.globl gMonBackPic_Drowzee
gMonBackPic_Drowzee: @ 0x8C71B5C
	.incbin "baserom_jp.gba", 0xc71b5c, 0x25c

	.globl gMonShinyPalette_Drowzee
gMonShinyPalette_Drowzee: @ 0x8C71DB8
	.incbin "baserom_jp.gba", 0xc71db8, 0x444

	.globl gMonStillFrontPic_Hypno
gMonStillFrontPic_Hypno: @ 0x8C721FC
	.incbin "baserom_jp.gba", 0xc721fc, 0x3ec

	.globl gMonPalette_Hypno
gMonPalette_Hypno: @ 0x8C725E8
	.incbin "baserom_jp.gba", 0xc725e8, 0x24

	.globl gMonBackPic_Hypno
gMonBackPic_Hypno: @ 0x8C7260C
	.incbin "baserom_jp.gba", 0xc7260c, 0x330

	.globl gMonShinyPalette_Hypno
gMonShinyPalette_Hypno: @ 0x8C7293C
	.incbin "baserom_jp.gba", 0xc7293c, 0x444

	.globl gMonStillFrontPic_Krabby
gMonStillFrontPic_Krabby: @ 0x8C72D80
	.incbin "baserom_jp.gba", 0xc72d80, 0x2b8

	.globl gMonPalette_Krabby
gMonPalette_Krabby: @ 0x8C73038
	.incbin "baserom_jp.gba", 0xc73038, 0x28

	.globl gMonBackPic_Krabby
gMonBackPic_Krabby: @ 0x8C73060
	.incbin "baserom_jp.gba", 0xc73060, 0x38c

	.globl gMonShinyPalette_Krabby
gMonShinyPalette_Krabby: @ 0x8C733EC
	.incbin "baserom_jp.gba", 0xc733ec, 0x448

	.globl gMonStillFrontPic_Kingler
gMonStillFrontPic_Kingler: @ 0x8C73834
	.incbin "baserom_jp.gba", 0xc73834, 0x534

	.globl gMonPalette_Kingler
gMonPalette_Kingler: @ 0x8C73D68
	.incbin "baserom_jp.gba", 0xc73d68, 0x24

	.globl gMonBackPic_Kingler
gMonBackPic_Kingler: @ 0x8C73D8C
	.incbin "baserom_jp.gba", 0xc73d8c, 0x384

	.globl gMonShinyPalette_Kingler
gMonShinyPalette_Kingler: @ 0x8C74110
	.incbin "baserom_jp.gba", 0xc74110, 0x444

	.globl gMonStillFrontPic_Voltorb
gMonStillFrontPic_Voltorb: @ 0x8C74554
	.incbin "baserom_jp.gba", 0xc74554, 0x208

	.globl gMonPalette_Voltorb
gMonPalette_Voltorb: @ 0x8C7475C
	.incbin "baserom_jp.gba", 0xc7475c, 0x24

	.globl gMonBackPic_Voltorb
gMonBackPic_Voltorb: @ 0x8C74780
	.incbin "baserom_jp.gba", 0xc74780, 0x274

	.globl gMonShinyPalette_Voltorb
gMonShinyPalette_Voltorb: @ 0x8C749F4
	.incbin "baserom_jp.gba", 0xc749f4, 0x444

	.globl gMonStillFrontPic_Electrode
gMonStillFrontPic_Electrode: @ 0x8C74E38
	.incbin "baserom_jp.gba", 0xc74e38, 0x26c

	.globl gMonPalette_Electrode
gMonPalette_Electrode: @ 0x8C750A4
	.incbin "baserom_jp.gba", 0xc750a4, 0x24

	.globl gMonBackPic_Electrode
gMonBackPic_Electrode: @ 0x8C750C8
	.incbin "baserom_jp.gba", 0xc750c8, 0x270

	.globl gMonShinyPalette_Electrode
gMonShinyPalette_Electrode: @ 0x8C75338
	.incbin "baserom_jp.gba", 0xc75338, 0x444

	.globl gMonStillFrontPic_Exeggcute
gMonStillFrontPic_Exeggcute: @ 0x8C7577C
	.incbin "baserom_jp.gba", 0xc7577c, 0x404

	.globl gMonPalette_Exeggcute
gMonPalette_Exeggcute: @ 0x8C75B80
	.incbin "baserom_jp.gba", 0xc75b80, 0x24

	.globl gMonBackPic_Exeggcute
gMonBackPic_Exeggcute: @ 0x8C75BA4
	.incbin "baserom_jp.gba", 0xc75ba4, 0x308

	.globl gMonShinyPalette_Exeggcute
gMonShinyPalette_Exeggcute: @ 0x8C75EAC
	.incbin "baserom_jp.gba", 0xc75eac, 0x444

	.globl gMonStillFrontPic_Exeggutor
gMonStillFrontPic_Exeggutor: @ 0x8C762F0
	.incbin "baserom_jp.gba", 0xc762f0, 0x500

	.globl gMonPalette_Exeggutor
gMonPalette_Exeggutor: @ 0x8C767F0
	.incbin "baserom_jp.gba", 0xc767f0, 0x28

	.globl gMonBackPic_Exeggutor
gMonBackPic_Exeggutor: @ 0x8C76818
	.incbin "baserom_jp.gba", 0xc76818, 0x4a0

	.globl gMonShinyPalette_Exeggutor
gMonShinyPalette_Exeggutor: @ 0x8C76CB8
	.incbin "baserom_jp.gba", 0xc76cb8, 0x448

	.globl gMonStillFrontPic_Cubone
gMonStillFrontPic_Cubone: @ 0x8C77100
	.incbin "baserom_jp.gba", 0xc77100, 0x2d0

	.globl gMonPalette_Cubone
gMonPalette_Cubone: @ 0x8C773D0
	.incbin "baserom_jp.gba", 0xc773d0, 0x28

	.globl gMonBackPic_Cubone
gMonBackPic_Cubone: @ 0x8C773F8
	.incbin "baserom_jp.gba", 0xc773f8, 0x340

	.globl gMonShinyPalette_Cubone
gMonShinyPalette_Cubone: @ 0x8C77738
	.incbin "baserom_jp.gba", 0xc77738, 0x448

	.globl gMonStillFrontPic_Marowak
gMonStillFrontPic_Marowak: @ 0x8C77B80
	.incbin "baserom_jp.gba", 0xc77b80, 0x388

	.globl gMonPalette_Marowak
gMonPalette_Marowak: @ 0x8C77F08
	.incbin "baserom_jp.gba", 0xc77f08, 0x28

	.globl gMonBackPic_Marowak
gMonBackPic_Marowak: @ 0x8C77F30
	.incbin "baserom_jp.gba", 0xc77f30, 0x348

	.globl gMonShinyPalette_Marowak
gMonShinyPalette_Marowak: @ 0x8C78278
	.incbin "baserom_jp.gba", 0xc78278, 0x448

	.globl gMonStillFrontPic_Hitmonlee
gMonStillFrontPic_Hitmonlee: @ 0x8C786C0
	.incbin "baserom_jp.gba", 0xc786c0, 0x400

	.globl gMonPalette_Hitmonlee
gMonPalette_Hitmonlee: @ 0x8C78AC0
	.incbin "baserom_jp.gba", 0xc78ac0, 0x28

	.globl gMonBackPic_Hitmonlee
gMonBackPic_Hitmonlee: @ 0x8C78AE8
	.incbin "baserom_jp.gba", 0xc78ae8, 0x2a4

	.globl gMonShinyPalette_Hitmonlee
gMonShinyPalette_Hitmonlee: @ 0x8C78D8C
	.incbin "baserom_jp.gba", 0xc78d8c, 0x448

	.globl gMonStillFrontPic_Hitmonchan
gMonStillFrontPic_Hitmonchan: @ 0x8C791D4
	.incbin "baserom_jp.gba", 0xc791d4, 0x340

	.globl gMonPalette_Hitmonchan
gMonPalette_Hitmonchan: @ 0x8C79514
	.incbin "baserom_jp.gba", 0xc79514, 0x28

	.globl gMonBackPic_Hitmonchan
gMonBackPic_Hitmonchan: @ 0x8C7953C
	.incbin "baserom_jp.gba", 0xc7953c, 0x344

	.globl gMonShinyPalette_Hitmonchan
gMonShinyPalette_Hitmonchan: @ 0x8C79880
	.incbin "baserom_jp.gba", 0xc79880, 0x448

	.globl gMonStillFrontPic_Lickitung
gMonStillFrontPic_Lickitung: @ 0x8C79CC8
	.incbin "baserom_jp.gba", 0xc79cc8, 0x3b8

	.globl gMonPalette_Lickitung
gMonPalette_Lickitung: @ 0x8C7A080
	.incbin "baserom_jp.gba", 0xc7a080, 0x28

	.globl gMonBackPic_Lickitung
gMonBackPic_Lickitung: @ 0x8C7A0A8
	.incbin "baserom_jp.gba", 0xc7a0a8, 0x2c0

	.globl gMonShinyPalette_Lickitung
gMonShinyPalette_Lickitung: @ 0x8C7A368
	.incbin "baserom_jp.gba", 0xc7a368, 0x448

	.globl gMonStillFrontPic_Koffing
gMonStillFrontPic_Koffing: @ 0x8C7A7B0
	.incbin "baserom_jp.gba", 0xc7a7b0, 0x35c

	.globl gMonPalette_Koffing
gMonPalette_Koffing: @ 0x8C7AB0C
	.incbin "baserom_jp.gba", 0xc7ab0c, 0x28

	.globl gMonBackPic_Koffing
gMonBackPic_Koffing: @ 0x8C7AB34
	.incbin "baserom_jp.gba", 0xc7ab34, 0x300

	.globl gMonShinyPalette_Koffing
gMonShinyPalette_Koffing: @ 0x8C7AE34
	.incbin "baserom_jp.gba", 0xc7ae34, 0x448

	.globl gMonStillFrontPic_Weezing
gMonStillFrontPic_Weezing: @ 0x8C7B27C
	.incbin "baserom_jp.gba", 0xc7b27c, 0x488

	.globl gMonPalette_Weezing
gMonPalette_Weezing: @ 0x8C7B704
	.incbin "baserom_jp.gba", 0xc7b704, 0x28

	.globl gMonBackPic_Weezing
gMonBackPic_Weezing: @ 0x8C7B72C
	.incbin "baserom_jp.gba", 0xc7b72c, 0x330

	.globl gMonShinyPalette_Weezing
gMonShinyPalette_Weezing: @ 0x8C7BA5C
	.incbin "baserom_jp.gba", 0xc7ba5c, 0x448

	.globl gMonStillFrontPic_Rhyhorn
gMonStillFrontPic_Rhyhorn: @ 0x8C7BEA4
	.incbin "baserom_jp.gba", 0xc7bea4, 0x404

	.globl gMonPalette_Rhyhorn
gMonPalette_Rhyhorn: @ 0x8C7C2A8
	.incbin "baserom_jp.gba", 0xc7c2a8, 0x20

	.globl gMonBackPic_Rhyhorn
gMonBackPic_Rhyhorn: @ 0x8C7C2C8
	.incbin "baserom_jp.gba", 0xc7c2c8, 0x348

	.globl gMonShinyPalette_Rhyhorn
gMonShinyPalette_Rhyhorn: @ 0x8C7C610
	.incbin "baserom_jp.gba", 0xc7c610, 0x440

	.globl gMonStillFrontPic_Rhydon
gMonStillFrontPic_Rhydon: @ 0x8C7CA50
	.incbin "baserom_jp.gba", 0xc7ca50, 0x508

	.globl gMonPalette_Rhydon
gMonPalette_Rhydon: @ 0x8C7CF58
	.incbin "baserom_jp.gba", 0xc7cf58, 0x28

	.globl gMonBackPic_Rhydon
gMonBackPic_Rhydon: @ 0x8C7CF80
	.incbin "baserom_jp.gba", 0xc7cf80, 0x450

	.globl gMonShinyPalette_Rhydon
gMonShinyPalette_Rhydon: @ 0x8C7D3D0
	.incbin "baserom_jp.gba", 0xc7d3d0, 0x448

	.globl gMonStillFrontPic_Chansey
gMonStillFrontPic_Chansey: @ 0x8C7D818
	.incbin "baserom_jp.gba", 0xc7d818, 0x354

	.globl gMonPalette_Chansey
gMonPalette_Chansey: @ 0x8C7DB6C
	.incbin "baserom_jp.gba", 0xc7db6c, 0x24

	.globl gMonBackPic_Chansey
gMonBackPic_Chansey: @ 0x8C7DB90
	.incbin "baserom_jp.gba", 0xc7db90, 0x2d4

	.globl gMonShinyPalette_Chansey
gMonShinyPalette_Chansey: @ 0x8C7DE64
	.incbin "baserom_jp.gba", 0xc7de64, 0x444

	.globl gMonStillFrontPic_Tangela
gMonStillFrontPic_Tangela: @ 0x8C7E2A8
	.incbin "baserom_jp.gba", 0xc7e2a8, 0x3d4

	.globl gMonPalette_Tangela
gMonPalette_Tangela: @ 0x8C7E67C
	.incbin "baserom_jp.gba", 0xc7e67c, 0x24

	.globl gMonBackPic_Tangela
gMonBackPic_Tangela: @ 0x8C7E6A0
	.incbin "baserom_jp.gba", 0xc7e6a0, 0x3ac

	.globl gMonShinyPalette_Tangela
gMonShinyPalette_Tangela: @ 0x8C7EA4C
	.incbin "baserom_jp.gba", 0xc7ea4c, 0x444

	.globl gMonStillFrontPic_Kangaskhan
gMonStillFrontPic_Kangaskhan: @ 0x8C7EE90
	.incbin "baserom_jp.gba", 0xc7ee90, 0x4f8

	.globl gMonPalette_Kangaskhan
gMonPalette_Kangaskhan: @ 0x8C7F388
	.incbin "baserom_jp.gba", 0xc7f388, 0x28

	.globl gMonBackPic_Kangaskhan
gMonBackPic_Kangaskhan: @ 0x8C7F3B0
	.incbin "baserom_jp.gba", 0xc7f3b0, 0x430

	.globl gMonShinyPalette_Kangaskhan
gMonShinyPalette_Kangaskhan: @ 0x8C7F7E0
	.incbin "baserom_jp.gba", 0xc7f7e0, 0x448

	.globl gMonStillFrontPic_Horsea
gMonStillFrontPic_Horsea: @ 0x8C7FC28
	.incbin "baserom_jp.gba", 0xc7fc28, 0x278

	.globl gMonPalette_Horsea
gMonPalette_Horsea: @ 0x8C7FEA0
	.incbin "baserom_jp.gba", 0xc7fea0, 0x28

	.globl gMonBackPic_Horsea
gMonBackPic_Horsea: @ 0x8C7FEC8
	.incbin "baserom_jp.gba", 0xc7fec8, 0x2e0

	.globl gMonShinyPalette_Horsea
gMonShinyPalette_Horsea: @ 0x8C801A8
	.incbin "baserom_jp.gba", 0xc801a8, 0x448

	.globl gMonStillFrontPic_Seadra
gMonStillFrontPic_Seadra: @ 0x8C805F0
	.incbin "baserom_jp.gba", 0xc805f0, 0x3c0

	.globl gMonPalette_Seadra
gMonPalette_Seadra: @ 0x8C809B0
	.incbin "baserom_jp.gba", 0xc809b0, 0x28

	.globl gMonBackPic_Seadra
gMonBackPic_Seadra: @ 0x8C809D8
	.incbin "baserom_jp.gba", 0xc809d8, 0x3a0

	.globl gMonShinyPalette_Seadra
gMonShinyPalette_Seadra: @ 0x8C80D78
	.incbin "baserom_jp.gba", 0xc80d78, 0x448

	.globl gMonStillFrontPic_Goldeen
gMonStillFrontPic_Goldeen: @ 0x8C811C0
	.incbin "baserom_jp.gba", 0xc811c0, 0x368

	.globl gMonPalette_Goldeen
gMonPalette_Goldeen: @ 0x8C81528
	.incbin "baserom_jp.gba", 0xc81528, 0x28

	.globl gMonBackPic_Goldeen
gMonBackPic_Goldeen: @ 0x8C81550
	.incbin "baserom_jp.gba", 0xc81550, 0x370

	.globl gMonShinyPalette_Goldeen
gMonShinyPalette_Goldeen: @ 0x8C818C0
	.incbin "baserom_jp.gba", 0xc818c0, 0x448

	.globl gMonStillFrontPic_Seaking
gMonStillFrontPic_Seaking: @ 0x8C81D08
	.incbin "baserom_jp.gba", 0xc81d08, 0x474

	.globl gMonPalette_Seaking
gMonPalette_Seaking: @ 0x8C8217C
	.incbin "baserom_jp.gba", 0xc8217c, 0x28

	.globl gMonBackPic_Seaking
gMonBackPic_Seaking: @ 0x8C821A4
	.incbin "baserom_jp.gba", 0xc821a4, 0x350

	.globl gMonShinyPalette_Seaking
gMonShinyPalette_Seaking: @ 0x8C824F4
	.incbin "baserom_jp.gba", 0xc824f4, 0x448

	.globl gMonStillFrontPic_Staryu
gMonStillFrontPic_Staryu: @ 0x8C8293C
	.incbin "baserom_jp.gba", 0xc8293c, 0x2e4

	.globl gMonPalette_Staryu
gMonPalette_Staryu: @ 0x8C82C20
	.incbin "baserom_jp.gba", 0xc82c20, 0x28

	.globl gMonBackPic_Staryu
gMonBackPic_Staryu: @ 0x8C82C48
	.incbin "baserom_jp.gba", 0xc82c48, 0x28c

	.globl gMonShinyPalette_Staryu
gMonShinyPalette_Staryu: @ 0x8C82ED4
	.incbin "baserom_jp.gba", 0xc82ed4, 0x448

	.globl gMonStillFrontPic_Starmie
gMonStillFrontPic_Starmie: @ 0x8C8331C
	.incbin "baserom_jp.gba", 0xc8331c, 0x428

	.globl gMonPalette_Starmie
gMonPalette_Starmie: @ 0x8C83744
	.incbin "baserom_jp.gba", 0xc83744, 0x28

	.globl gMonBackPic_Starmie
gMonBackPic_Starmie: @ 0x8C8376C
	.incbin "baserom_jp.gba", 0xc8376c, 0x2a4

	.globl gMonShinyPalette_Starmie
gMonShinyPalette_Starmie: @ 0x8C83A10
	.incbin "baserom_jp.gba", 0xc83a10, 0x448

	.globl gMonStillFrontPic_MrMime
gMonStillFrontPic_MrMime: @ 0x8C83E58
	.incbin "baserom_jp.gba", 0xc83e58, 0x3b0

	.globl gMonPalette_MrMime
gMonPalette_MrMime: @ 0x8C84208
	.incbin "baserom_jp.gba", 0xc84208, 0x28

	.globl gMonBackPic_MrMime
gMonBackPic_MrMime: @ 0x8C84230
	.incbin "baserom_jp.gba", 0xc84230, 0x334

	.globl gMonShinyPalette_MrMime
gMonShinyPalette_MrMime: @ 0x8C84564
	.incbin "baserom_jp.gba", 0xc84564, 0x448

	.globl gMonStillFrontPic_Scyther
gMonStillFrontPic_Scyther: @ 0x8C849AC
	.incbin "baserom_jp.gba", 0xc849ac, 0x4ac

	.globl gMonPalette_Scyther
gMonPalette_Scyther: @ 0x8C84E58
	.incbin "baserom_jp.gba", 0xc84e58, 0x28

	.globl gMonBackPic_Scyther
gMonBackPic_Scyther: @ 0x8C84E80
	.incbin "baserom_jp.gba", 0xc84e80, 0x3a8

	.globl gMonShinyPalette_Scyther
gMonShinyPalette_Scyther: @ 0x8C85228
	.incbin "baserom_jp.gba", 0xc85228, 0x448

	.globl gMonStillFrontPic_Jynx
gMonStillFrontPic_Jynx: @ 0x8C85670
	.incbin "baserom_jp.gba", 0xc85670, 0x49c

	.globl gMonPalette_Jynx
gMonPalette_Jynx: @ 0x8C85B0C
	.incbin "baserom_jp.gba", 0xc85b0c, 0x28

	.globl gMonBackPic_Jynx
gMonBackPic_Jynx: @ 0x8C85B34
	.incbin "baserom_jp.gba", 0xc85b34, 0x2f8

	.globl gMonShinyPalette_Jynx
gMonShinyPalette_Jynx: @ 0x8C85E2C
	.incbin "baserom_jp.gba", 0xc85e2c, 0x448

	.globl gMonStillFrontPic_Electabuzz
gMonStillFrontPic_Electabuzz: @ 0x8C86274
	.incbin "baserom_jp.gba", 0xc86274, 0x47c

	.globl gMonPalette_Electabuzz
gMonPalette_Electabuzz: @ 0x8C866F0
	.incbin "baserom_jp.gba", 0xc866f0, 0x28

	.globl gMonBackPic_Electabuzz
gMonBackPic_Electabuzz: @ 0x8C86718
	.incbin "baserom_jp.gba", 0xc86718, 0x310

	.globl gMonShinyPalette_Electabuzz
gMonShinyPalette_Electabuzz: @ 0x8C86A28
	.incbin "baserom_jp.gba", 0xc86a28, 0x448

	.globl gMonStillFrontPic_Magmar
gMonStillFrontPic_Magmar: @ 0x8C86E70
	.incbin "baserom_jp.gba", 0xc86e70, 0x4a8

	.globl gMonPalette_Magmar
gMonPalette_Magmar: @ 0x8C87318
	.incbin "baserom_jp.gba", 0xc87318, 0x28

	.globl gMonBackPic_Magmar
gMonBackPic_Magmar: @ 0x8C87340
	.incbin "baserom_jp.gba", 0xc87340, 0x348

	.globl gMonShinyPalette_Magmar
gMonShinyPalette_Magmar: @ 0x8C87688
	.incbin "baserom_jp.gba", 0xc87688, 0x448

	.globl gMonStillFrontPic_Pinsir
gMonStillFrontPic_Pinsir: @ 0x8C87AD0
	.incbin "baserom_jp.gba", 0xc87ad0, 0x428

	.globl gMonPalette_Pinsir
gMonPalette_Pinsir: @ 0x8C87EF8
	.incbin "baserom_jp.gba", 0xc87ef8, 0x24

	.globl gMonBackPic_Pinsir
gMonBackPic_Pinsir: @ 0x8C87F1C
	.incbin "baserom_jp.gba", 0xc87f1c, 0x354

	.globl gMonShinyPalette_Pinsir
gMonShinyPalette_Pinsir: @ 0x8C88270
	.incbin "baserom_jp.gba", 0xc88270, 0x444

	.globl gMonStillFrontPic_Tauros
gMonStillFrontPic_Tauros: @ 0x8C886B4
	.incbin "baserom_jp.gba", 0xc886b4, 0x4d0

	.globl gMonPalette_Tauros
gMonPalette_Tauros: @ 0x8C88B84
	.incbin "baserom_jp.gba", 0xc88b84, 0x28

	.globl gMonBackPic_Tauros
gMonBackPic_Tauros: @ 0x8C88BAC
	.incbin "baserom_jp.gba", 0xc88bac, 0x2b4

	.globl gMonShinyPalette_Tauros
gMonShinyPalette_Tauros: @ 0x8C88E60
	.incbin "baserom_jp.gba", 0xc88e60, 0x448

	.globl gMonStillFrontPic_Magikarp
gMonStillFrontPic_Magikarp: @ 0x8C892A8
	.incbin "baserom_jp.gba", 0xc892a8, 0x350

	.globl gMonPalette_Magikarp
gMonPalette_Magikarp: @ 0x8C895F8
	.incbin "baserom_jp.gba", 0xc895f8, 0x28

	.globl gMonBackPic_Magikarp
gMonBackPic_Magikarp: @ 0x8C89620
	.incbin "baserom_jp.gba", 0xc89620, 0x330

	.globl gMonShinyPalette_Magikarp
gMonShinyPalette_Magikarp: @ 0x8C89950
	.incbin "baserom_jp.gba", 0xc89950, 0x448

	.globl gMonStillFrontPic_Gyarados
gMonStillFrontPic_Gyarados: @ 0x8C89D98
	.incbin "baserom_jp.gba", 0xc89d98, 0x568

	.globl gMonPalette_Gyarados
gMonPalette_Gyarados: @ 0x8C8A300
	.incbin "baserom_jp.gba", 0xc8a300, 0x28

	.globl gMonBackPic_Gyarados
gMonBackPic_Gyarados: @ 0x8C8A328
	.incbin "baserom_jp.gba", 0xc8a328, 0x4d4

	.globl gMonShinyPalette_Gyarados
gMonShinyPalette_Gyarados: @ 0x8C8A7FC
	.incbin "baserom_jp.gba", 0xc8a7fc, 0x448

	.globl gMonStillFrontPic_Lapras
gMonStillFrontPic_Lapras: @ 0x8C8AC44
	.incbin "baserom_jp.gba", 0xc8ac44, 0x3c0

	.globl gMonPalette_Lapras
gMonPalette_Lapras: @ 0x8C8B004
	.incbin "baserom_jp.gba", 0xc8b004, 0x28

	.globl gMonBackPic_Lapras
gMonBackPic_Lapras: @ 0x8C8B02C
	.incbin "baserom_jp.gba", 0xc8b02c, 0x344

	.globl gMonShinyPalette_Lapras
gMonShinyPalette_Lapras: @ 0x8C8B370
	.incbin "baserom_jp.gba", 0xc8b370, 0x448

	.globl gMonStillFrontPic_Ditto
gMonStillFrontPic_Ditto: @ 0x8C8B7B8
	.incbin "baserom_jp.gba", 0xc8b7b8, 0x1f0

	.globl gMonPalette_Ditto
gMonPalette_Ditto: @ 0x8C8B9A8
	.incbin "baserom_jp.gba", 0xc8b9a8, 0x20

	.globl gMonBackPic_Ditto
gMonBackPic_Ditto: @ 0x8C8B9C8
	.incbin "baserom_jp.gba", 0xc8b9c8, 0x200

	.globl gMonShinyPalette_Ditto
gMonShinyPalette_Ditto: @ 0x8C8BBC8
	.incbin "baserom_jp.gba", 0xc8bbc8, 0x440

	.globl gMonStillFrontPic_Eevee
gMonStillFrontPic_Eevee: @ 0x8C8C008
	.incbin "baserom_jp.gba", 0xc8c008, 0x2a4

	.globl gMonPalette_Eevee
gMonPalette_Eevee: @ 0x8C8C2AC
	.incbin "baserom_jp.gba", 0xc8c2ac, 0x24

	.globl gMonBackPic_Eevee
gMonBackPic_Eevee: @ 0x8C8C2D0
	.incbin "baserom_jp.gba", 0xc8c2d0, 0x328

	.globl gMonShinyPalette_Eevee
gMonShinyPalette_Eevee: @ 0x8C8C5F8
	.incbin "baserom_jp.gba", 0xc8c5f8, 0x444

	.globl gMonStillFrontPic_Vaporeon
gMonStillFrontPic_Vaporeon: @ 0x8C8CA3C
	.incbin "baserom_jp.gba", 0xc8ca3c, 0x394

	.globl gMonPalette_Vaporeon
gMonPalette_Vaporeon: @ 0x8C8CDD0
	.incbin "baserom_jp.gba", 0xc8cdd0, 0x28

	.globl gMonBackPic_Vaporeon
gMonBackPic_Vaporeon: @ 0x8C8CDF8
	.incbin "baserom_jp.gba", 0xc8cdf8, 0x2c8

	.globl gMonShinyPalette_Vaporeon
gMonShinyPalette_Vaporeon: @ 0x8C8D0C0
	.incbin "baserom_jp.gba", 0xc8d0c0, 0x448

	.globl gMonStillFrontPic_Jolteon
gMonStillFrontPic_Jolteon: @ 0x8C8D508
	.incbin "baserom_jp.gba", 0xc8d508, 0x3a0

	.globl gMonPalette_Jolteon
gMonPalette_Jolteon: @ 0x8C8D8A8
	.incbin "baserom_jp.gba", 0xc8d8a8, 0x28

	.globl gMonBackPic_Jolteon
gMonBackPic_Jolteon: @ 0x8C8D8D0
	.incbin "baserom_jp.gba", 0xc8d8d0, 0x390

	.globl gMonShinyPalette_Jolteon
gMonShinyPalette_Jolteon: @ 0x8C8DC60
	.incbin "baserom_jp.gba", 0xc8dc60, 0x448

	.globl gMonStillFrontPic_Flareon
gMonStillFrontPic_Flareon: @ 0x8C8E0A8
	.incbin "baserom_jp.gba", 0xc8e0a8, 0x37c

	.globl gMonPalette_Flareon
gMonPalette_Flareon: @ 0x8C8E424
	.incbin "baserom_jp.gba", 0xc8e424, 0x28

	.globl gMonBackPic_Flareon
gMonBackPic_Flareon: @ 0x8C8E44C
	.incbin "baserom_jp.gba", 0xc8e44c, 0x390

	.globl gMonShinyPalette_Flareon
gMonShinyPalette_Flareon: @ 0x8C8E7DC
	.incbin "baserom_jp.gba", 0xc8e7dc, 0x448

	.globl gMonStillFrontPic_Porygon
gMonStillFrontPic_Porygon: @ 0x8C8EC24
	.incbin "baserom_jp.gba", 0xc8ec24, 0x2bc

	.globl gMonPalette_Porygon
gMonPalette_Porygon: @ 0x8C8EEE0
	.incbin "baserom_jp.gba", 0xc8eee0, 0x24

	.globl gMonBackPic_Porygon
gMonBackPic_Porygon: @ 0x8C8EF04
	.incbin "baserom_jp.gba", 0xc8ef04, 0x2b8

	.globl gMonShinyPalette_Porygon
gMonShinyPalette_Porygon: @ 0x8C8F1BC
	.incbin "baserom_jp.gba", 0xc8f1bc, 0x444

	.globl gMonStillFrontPic_Omanyte
gMonStillFrontPic_Omanyte: @ 0x8C8F600
	.incbin "baserom_jp.gba", 0xc8f600, 0x2a8

	.globl gMonPalette_Omanyte
gMonPalette_Omanyte: @ 0x8C8F8A8
	.incbin "baserom_jp.gba", 0xc8f8a8, 0x28

	.globl gMonBackPic_Omanyte
gMonBackPic_Omanyte: @ 0x8C8F8D0
	.incbin "baserom_jp.gba", 0xc8f8d0, 0x34c

	.globl gMonShinyPalette_Omanyte
gMonShinyPalette_Omanyte: @ 0x8C8FC1C
	.incbin "baserom_jp.gba", 0xc8fc1c, 0x448

	.globl gMonStillFrontPic_Omastar
gMonStillFrontPic_Omastar: @ 0x8C90064
	.incbin "baserom_jp.gba", 0xc90064, 0x3c0

	.globl gMonPalette_Omastar
gMonPalette_Omastar: @ 0x8C90424
	.incbin "baserom_jp.gba", 0xc90424, 0x28

	.globl gMonBackPic_Omastar
gMonBackPic_Omastar: @ 0x8C9044C
	.incbin "baserom_jp.gba", 0xc9044c, 0x340

	.globl gMonShinyPalette_Omastar
gMonShinyPalette_Omastar: @ 0x8C9078C
	.incbin "baserom_jp.gba", 0xc9078c, 0x448

	.globl gMonStillFrontPic_Kabuto
gMonStillFrontPic_Kabuto: @ 0x8C90BD4
	.incbin "baserom_jp.gba", 0xc90bd4, 0x270

	.globl gMonPalette_Kabuto
gMonPalette_Kabuto: @ 0x8C90E44
	.incbin "baserom_jp.gba", 0xc90e44, 0x28

	.globl gMonBackPic_Kabuto
gMonBackPic_Kabuto: @ 0x8C90E6C
	.incbin "baserom_jp.gba", 0xc90e6c, 0x298

	.globl gMonShinyPalette_Kabuto
gMonShinyPalette_Kabuto: @ 0x8C91104
	.incbin "baserom_jp.gba", 0xc91104, 0x448

	.globl gMonStillFrontPic_Kabutops
gMonStillFrontPic_Kabutops: @ 0x8C9154C
	.incbin "baserom_jp.gba", 0xc9154c, 0x400

	.globl gMonPalette_Kabutops
gMonPalette_Kabutops: @ 0x8C9194C
	.incbin "baserom_jp.gba", 0xc9194c, 0x24

	.globl gMonBackPic_Kabutops
gMonBackPic_Kabutops: @ 0x8C91970
	.incbin "baserom_jp.gba", 0xc91970, 0x3a4

	.globl gMonShinyPalette_Kabutops
gMonShinyPalette_Kabutops: @ 0x8C91D14
	.incbin "baserom_jp.gba", 0xc91d14, 0x444

	.globl gMonStillFrontPic_Aerodactyl
gMonStillFrontPic_Aerodactyl: @ 0x8C92158
	.incbin "baserom_jp.gba", 0xc92158, 0x480

	.globl gMonPalette_Aerodactyl
gMonPalette_Aerodactyl: @ 0x8C925D8
	.incbin "baserom_jp.gba", 0xc925d8, 0x28

	.globl gMonBackPic_Aerodactyl
gMonBackPic_Aerodactyl: @ 0x8C92600
	.incbin "baserom_jp.gba", 0xc92600, 0x304

	.globl gMonShinyPalette_Aerodactyl
gMonShinyPalette_Aerodactyl: @ 0x8C92904
	.incbin "baserom_jp.gba", 0xc92904, 0x448

	.globl gMonStillFrontPic_Snorlax
gMonStillFrontPic_Snorlax: @ 0x8C92D4C
	.incbin "baserom_jp.gba", 0xc92d4c, 0x444

	.globl gMonPalette_Snorlax
gMonPalette_Snorlax: @ 0x8C93190
	.incbin "baserom_jp.gba", 0xc93190, 0x28

	.globl gMonBackPic_Snorlax
gMonBackPic_Snorlax: @ 0x8C931B8
	.incbin "baserom_jp.gba", 0xc931b8, 0x21c

	.globl gMonShinyPalette_Snorlax
gMonShinyPalette_Snorlax: @ 0x8C933D4
	.incbin "baserom_jp.gba", 0xc933d4, 0x448

	.globl gMonStillFrontPic_Articuno
gMonStillFrontPic_Articuno: @ 0x8C9381C
	.incbin "baserom_jp.gba", 0xc9381c, 0x4f8

	.globl gMonPalette_Articuno
gMonPalette_Articuno: @ 0x8C93D14
	.incbin "baserom_jp.gba", 0xc93d14, 0x28

	.globl gMonBackPic_Articuno
gMonBackPic_Articuno: @ 0x8C93D3C
	.incbin "baserom_jp.gba", 0xc93d3c, 0x25c

	.globl gMonShinyPalette_Articuno
gMonShinyPalette_Articuno: @ 0x8C93F98
	.incbin "baserom_jp.gba", 0xc93f98, 0x448

	.globl gMonStillFrontPic_Zapdos
gMonStillFrontPic_Zapdos: @ 0x8C943E0
	.incbin "baserom_jp.gba", 0xc943e0, 0x474

	.globl gMonPalette_Zapdos
gMonPalette_Zapdos: @ 0x8C94854
	.incbin "baserom_jp.gba", 0xc94854, 0x28

	.globl gMonBackPic_Zapdos
gMonBackPic_Zapdos: @ 0x8C9487C
	.incbin "baserom_jp.gba", 0xc9487c, 0x33c

	.globl gMonShinyPalette_Zapdos
gMonShinyPalette_Zapdos: @ 0x8C94BB8
	.incbin "baserom_jp.gba", 0xc94bb8, 0x448

	.globl gMonStillFrontPic_Moltres
gMonStillFrontPic_Moltres: @ 0x8C95000
	.incbin "baserom_jp.gba", 0xc95000, 0x5b0

	.globl gMonPalette_Moltres
gMonPalette_Moltres: @ 0x8C955B0
	.incbin "baserom_jp.gba", 0xc955b0, 0x28

	.globl gMonBackPic_Moltres
gMonBackPic_Moltres: @ 0x8C955D8
	.incbin "baserom_jp.gba", 0xc955d8, 0x33c

	.globl gMonShinyPalette_Moltres
gMonShinyPalette_Moltres: @ 0x8C95914
	.incbin "baserom_jp.gba", 0xc95914, 0x448

	.globl gMonStillFrontPic_Dratini
gMonStillFrontPic_Dratini: @ 0x8C95D5C
	.incbin "baserom_jp.gba", 0xc95d5c, 0x2b8

	.globl gMonPalette_Dratini
gMonPalette_Dratini: @ 0x8C96014
	.incbin "baserom_jp.gba", 0xc96014, 0x24

	.globl gMonBackPic_Dratini
gMonBackPic_Dratini: @ 0x8C96038
	.incbin "baserom_jp.gba", 0xc96038, 0x290

	.globl gMonShinyPalette_Dratini
gMonShinyPalette_Dratini: @ 0x8C962C8
	.incbin "baserom_jp.gba", 0xc962c8, 0x444

	.globl gMonStillFrontPic_Dragonair
gMonStillFrontPic_Dragonair: @ 0x8C9670C
	.incbin "baserom_jp.gba", 0xc9670c, 0x360

	.globl gMonPalette_Dragonair
gMonPalette_Dragonair: @ 0x8C96A6C
	.incbin "baserom_jp.gba", 0xc96a6c, 0x28

	.globl gMonBackPic_Dragonair
gMonBackPic_Dragonair: @ 0x8C96A94
	.incbin "baserom_jp.gba", 0xc96a94, 0x310

	.globl gMonShinyPalette_Dragonair
gMonShinyPalette_Dragonair: @ 0x8C96DA4
	.incbin "baserom_jp.gba", 0xc96da4, 0x448

	.globl gMonStillFrontPic_Dragonite
gMonStillFrontPic_Dragonite: @ 0x8C971EC
	.incbin "baserom_jp.gba", 0xc971ec, 0x570

	.globl gMonPalette_Dragonite
gMonPalette_Dragonite: @ 0x8C9775C
	.incbin "baserom_jp.gba", 0xc9775c, 0x28

	.globl gMonBackPic_Dragonite
gMonBackPic_Dragonite: @ 0x8C97784
	.incbin "baserom_jp.gba", 0xc97784, 0x2fc

	.globl gMonShinyPalette_Dragonite
gMonShinyPalette_Dragonite: @ 0x8C97A80
	.incbin "baserom_jp.gba", 0xc97a80, 0x448

	.globl gMonStillFrontPic_Mewtwo
gMonStillFrontPic_Mewtwo: @ 0x8C97EC8
	.incbin "baserom_jp.gba", 0xc97ec8, 0x43c

	.globl gMonPalette_Mewtwo
gMonPalette_Mewtwo: @ 0x8C98304
	.incbin "baserom_jp.gba", 0xc98304, 0x24

	.globl gMonBackPic_Mewtwo
gMonBackPic_Mewtwo: @ 0x8C98328
	.incbin "baserom_jp.gba", 0xc98328, 0x3cc

	.globl gMonShinyPalette_Mewtwo
gMonShinyPalette_Mewtwo: @ 0x8C986F4
	.incbin "baserom_jp.gba", 0xc986f4, 0x444

	.globl gMonStillFrontPic_Mew
gMonStillFrontPic_Mew: @ 0x8C98B38
	.incbin "baserom_jp.gba", 0xc98b38, 0x280

	.globl gMonPalette_Mew
gMonPalette_Mew: @ 0x8C98DB8
	.incbin "baserom_jp.gba", 0xc98db8, 0x24

	.globl gMonBackPic_Mew
gMonBackPic_Mew: @ 0x8C98DDC
	.incbin "baserom_jp.gba", 0xc98ddc, 0x2cc

	.globl gMonShinyPalette_Mew
gMonShinyPalette_Mew: @ 0x8C990A8
	.incbin "baserom_jp.gba", 0xc990a8, 0x444

	.globl gMonStillFrontPic_Chikorita
gMonStillFrontPic_Chikorita: @ 0x8C994EC
	.incbin "baserom_jp.gba", 0xc994ec, 0x268

	.globl gMonPalette_Chikorita
gMonPalette_Chikorita: @ 0x8C99754
	.incbin "baserom_jp.gba", 0xc99754, 0x28

	.globl gMonBackPic_Chikorita
gMonBackPic_Chikorita: @ 0x8C9977C
	.incbin "baserom_jp.gba", 0xc9977c, 0x2c4

	.globl gMonShinyPalette_Chikorita
gMonShinyPalette_Chikorita: @ 0x8C99A40
	.incbin "baserom_jp.gba", 0xc99a40, 0x448

	.globl gMonStillFrontPic_Bayleef
gMonStillFrontPic_Bayleef: @ 0x8C99E88
	.incbin "baserom_jp.gba", 0xc99e88, 0x3d4

	.globl gMonPalette_Bayleef
gMonPalette_Bayleef: @ 0x8C9A25C
	.incbin "baserom_jp.gba", 0xc9a25c, 0x28

	.globl gMonBackPic_Bayleef
gMonBackPic_Bayleef: @ 0x8C9A284
	.incbin "baserom_jp.gba", 0xc9a284, 0x390

	.globl gMonShinyPalette_Bayleef
gMonShinyPalette_Bayleef: @ 0x8C9A614
	.incbin "baserom_jp.gba", 0xc9a614, 0x448

	.globl gMonStillFrontPic_Meganium
gMonStillFrontPic_Meganium: @ 0x8C9AA5C
	.incbin "baserom_jp.gba", 0xc9aa5c, 0x55c

	.globl gMonPalette_Meganium
gMonPalette_Meganium: @ 0x8C9AFB8
	.incbin "baserom_jp.gba", 0xc9afb8, 0x28

	.globl gMonBackPic_Meganium
gMonBackPic_Meganium: @ 0x8C9AFE0
	.incbin "baserom_jp.gba", 0xc9afe0, 0x350

	.globl gMonShinyPalette_Meganium
gMonShinyPalette_Meganium: @ 0x8C9B330
	.incbin "baserom_jp.gba", 0xc9b330, 0x448

	.globl gMonStillFrontPic_Cyndaquil
gMonStillFrontPic_Cyndaquil: @ 0x8C9B778
	.incbin "baserom_jp.gba", 0xc9b778, 0x28c

	.globl gMonPalette_Cyndaquil
gMonPalette_Cyndaquil: @ 0x8C9BA04
	.incbin "baserom_jp.gba", 0xc9ba04, 0x28

	.globl gMonBackPic_Cyndaquil
gMonBackPic_Cyndaquil: @ 0x8C9BA2C
	.incbin "baserom_jp.gba", 0xc9ba2c, 0x32c

	.globl gMonShinyPalette_Cyndaquil
gMonShinyPalette_Cyndaquil: @ 0x8C9BD58
	.incbin "baserom_jp.gba", 0xc9bd58, 0x448

	.globl gMonStillFrontPic_Quilava
gMonStillFrontPic_Quilava: @ 0x8C9C1A0
	.incbin "baserom_jp.gba", 0xc9c1a0, 0x31c

	.globl gMonPalette_Quilava
gMonPalette_Quilava: @ 0x8C9C4BC
	.incbin "baserom_jp.gba", 0xc9c4bc, 0x28

	.globl gMonBackPic_Quilava
gMonBackPic_Quilava: @ 0x8C9C4E4
	.incbin "baserom_jp.gba", 0xc9c4e4, 0x374

	.globl gMonShinyPalette_Quilava
gMonShinyPalette_Quilava: @ 0x8C9C858
	.incbin "baserom_jp.gba", 0xc9c858, 0x448

	.globl gMonStillFrontPic_Typhlosion
gMonStillFrontPic_Typhlosion: @ 0x8C9CCA0
	.incbin "baserom_jp.gba", 0xc9cca0, 0x428

	.globl gMonPalette_Typhlosion
gMonPalette_Typhlosion: @ 0x8C9D0C8
	.incbin "baserom_jp.gba", 0xc9d0c8, 0x28

	.globl gMonBackPic_Typhlosion
gMonBackPic_Typhlosion: @ 0x8C9D0F0
	.incbin "baserom_jp.gba", 0xc9d0f0, 0x404

	.globl gMonShinyPalette_Typhlosion
gMonShinyPalette_Typhlosion: @ 0x8C9D4F4
	.incbin "baserom_jp.gba", 0xc9d4f4, 0x448

	.globl gMonStillFrontPic_Totodile
gMonStillFrontPic_Totodile: @ 0x8C9D93C
	.incbin "baserom_jp.gba", 0xc9d93c, 0x2a4

	.globl gMonPalette_Totodile
gMonPalette_Totodile: @ 0x8C9DBE0
	.incbin "baserom_jp.gba", 0xc9dbe0, 0x28

	.globl gMonBackPic_Totodile
gMonBackPic_Totodile: @ 0x8C9DC08
	.incbin "baserom_jp.gba", 0xc9dc08, 0x2e0

	.globl gMonShinyPalette_Totodile
gMonShinyPalette_Totodile: @ 0x8C9DEE8
	.incbin "baserom_jp.gba", 0xc9dee8, 0x448

	.globl gMonStillFrontPic_Croconaw
gMonStillFrontPic_Croconaw: @ 0x8C9E330
	.incbin "baserom_jp.gba", 0xc9e330, 0x368

	.globl gMonPalette_Croconaw
gMonPalette_Croconaw: @ 0x8C9E698
	.incbin "baserom_jp.gba", 0xc9e698, 0x28

	.globl gMonBackPic_Croconaw
gMonBackPic_Croconaw: @ 0x8C9E6C0
	.incbin "baserom_jp.gba", 0xc9e6c0, 0x350

	.globl gMonShinyPalette_Croconaw
gMonShinyPalette_Croconaw: @ 0x8C9EA10
	.incbin "baserom_jp.gba", 0xc9ea10, 0x448

	.globl gMonStillFrontPic_Feraligatr
gMonStillFrontPic_Feraligatr: @ 0x8C9EE58
	.incbin "baserom_jp.gba", 0xc9ee58, 0x56c

	.globl gMonPalette_Feraligatr
gMonPalette_Feraligatr: @ 0x8C9F3C4
	.incbin "baserom_jp.gba", 0xc9f3c4, 0x28

	.globl gMonBackPic_Feraligatr
gMonBackPic_Feraligatr: @ 0x8C9F3EC
	.incbin "baserom_jp.gba", 0xc9f3ec, 0x4cc

	.globl gMonShinyPalette_Feraligatr
gMonShinyPalette_Feraligatr: @ 0x8C9F8B8
	.incbin "baserom_jp.gba", 0xc9f8b8, 0x448

	.globl gMonStillFrontPic_Sentret
gMonStillFrontPic_Sentret: @ 0x8C9FD00
	.incbin "baserom_jp.gba", 0xc9fd00, 0x2dc

	.globl gMonPalette_Sentret
gMonPalette_Sentret: @ 0x8C9FFDC
	.incbin "baserom_jp.gba", 0xc9ffdc, 0x28

	.globl gMonBackPic_Sentret
gMonBackPic_Sentret: @ 0x8CA0004
	.incbin "baserom_jp.gba", 0xca0004, 0x2a4

	.globl gMonShinyPalette_Sentret
gMonShinyPalette_Sentret: @ 0x8CA02A8
	.incbin "baserom_jp.gba", 0xca02a8, 0x448

	.globl gMonStillFrontPic_Furret
gMonStillFrontPic_Furret: @ 0x8CA06F0
	.incbin "baserom_jp.gba", 0xca06f0, 0x334

	.globl gMonPalette_Furret
gMonPalette_Furret: @ 0x8CA0A24
	.incbin "baserom_jp.gba", 0xca0a24, 0x28

	.globl gMonBackPic_Furret
gMonBackPic_Furret: @ 0x8CA0A4C
	.incbin "baserom_jp.gba", 0xca0a4c, 0x328

	.globl gMonShinyPalette_Furret
gMonShinyPalette_Furret: @ 0x8CA0D74
	.incbin "baserom_jp.gba", 0xca0d74, 0x448

	.globl gMonStillFrontPic_Hoothoot
gMonStillFrontPic_Hoothoot: @ 0x8CA11BC
	.incbin "baserom_jp.gba", 0xca11bc, 0x284

	.globl gMonPalette_Hoothoot
gMonPalette_Hoothoot: @ 0x8CA1440
	.incbin "baserom_jp.gba", 0xca1440, 0x28

	.globl gMonBackPic_Hoothoot
gMonBackPic_Hoothoot: @ 0x8CA1468
	.incbin "baserom_jp.gba", 0xca1468, 0x308

	.globl gMonShinyPalette_Hoothoot
gMonShinyPalette_Hoothoot: @ 0x8CA1770
	.incbin "baserom_jp.gba", 0xca1770, 0x448

	.globl gMonStillFrontPic_Noctowl
gMonStillFrontPic_Noctowl: @ 0x8CA1BB8
	.incbin "baserom_jp.gba", 0xca1bb8, 0x354

	.globl gMonPalette_Noctowl
gMonPalette_Noctowl: @ 0x8CA1F0C
	.incbin "baserom_jp.gba", 0xca1f0c, 0x28

	.globl gMonBackPic_Noctowl
gMonBackPic_Noctowl: @ 0x8CA1F34
	.incbin "baserom_jp.gba", 0xca1f34, 0x35c

	.globl gMonShinyPalette_Noctowl
gMonShinyPalette_Noctowl: @ 0x8CA2290
	.incbin "baserom_jp.gba", 0xca2290, 0x448

	.globl gMonStillFrontPic_Ledyba
gMonStillFrontPic_Ledyba: @ 0x8CA26D8
	.incbin "baserom_jp.gba", 0xca26d8, 0x2f4

	.globl gMonPalette_Ledyba
gMonPalette_Ledyba: @ 0x8CA29CC
	.incbin "baserom_jp.gba", 0xca29cc, 0x28

	.globl gMonBackPic_Ledyba
gMonBackPic_Ledyba: @ 0x8CA29F4
	.incbin "baserom_jp.gba", 0xca29f4, 0x330

	.globl gMonShinyPalette_Ledyba
gMonShinyPalette_Ledyba: @ 0x8CA2D24
	.incbin "baserom_jp.gba", 0xca2d24, 0x448

	.globl gMonStillFrontPic_Ledian
gMonStillFrontPic_Ledian: @ 0x8CA316C
	.incbin "baserom_jp.gba", 0xca316c, 0x388

	.globl gMonPalette_Ledian
gMonPalette_Ledian: @ 0x8CA34F4
	.incbin "baserom_jp.gba", 0xca34f4, 0x28

	.globl gMonBackPic_Ledian
gMonBackPic_Ledian: @ 0x8CA351C
	.incbin "baserom_jp.gba", 0xca351c, 0x358

	.globl gMonShinyPalette_Ledian
gMonShinyPalette_Ledian: @ 0x8CA3874
	.incbin "baserom_jp.gba", 0xca3874, 0x448

	.globl gMonStillFrontPic_Spinarak
gMonStillFrontPic_Spinarak: @ 0x8CA3CBC
	.incbin "baserom_jp.gba", 0xca3cbc, 0x274

	.globl gMonPalette_Spinarak
gMonPalette_Spinarak: @ 0x8CA3F30
	.incbin "baserom_jp.gba", 0xca3f30, 0x28

	.globl gMonBackPic_Spinarak
gMonBackPic_Spinarak: @ 0x8CA3F58
	.incbin "baserom_jp.gba", 0xca3f58, 0x264

	.globl gMonShinyPalette_Spinarak
gMonShinyPalette_Spinarak: @ 0x8CA41BC
	.incbin "baserom_jp.gba", 0xca41bc, 0x448

	.globl gMonStillFrontPic_Ariados
gMonStillFrontPic_Ariados: @ 0x8CA4604
	.incbin "baserom_jp.gba", 0xca4604, 0x3c0

	.globl gMonPalette_Ariados
gMonPalette_Ariados: @ 0x8CA49C4
	.incbin "baserom_jp.gba", 0xca49c4, 0x28

	.globl gMonBackPic_Ariados
gMonBackPic_Ariados: @ 0x8CA49EC
	.incbin "baserom_jp.gba", 0xca49ec, 0x378

	.globl gMonShinyPalette_Ariados
gMonShinyPalette_Ariados: @ 0x8CA4D64
	.incbin "baserom_jp.gba", 0xca4d64, 0x448

	.globl gMonStillFrontPic_Crobat
gMonStillFrontPic_Crobat: @ 0x8CA51AC
	.incbin "baserom_jp.gba", 0xca51ac, 0x3b0

	.globl gMonPalette_Crobat
gMonPalette_Crobat: @ 0x8CA555C
	.incbin "baserom_jp.gba", 0xca555c, 0x28

	.globl gMonBackPic_Crobat
gMonBackPic_Crobat: @ 0x8CA5584
	.incbin "baserom_jp.gba", 0xca5584, 0x308

	.globl gMonShinyPalette_Crobat
gMonShinyPalette_Crobat: @ 0x8CA588C
	.incbin "baserom_jp.gba", 0xca588c, 0x448

	.globl gMonStillFrontPic_Chinchou
gMonStillFrontPic_Chinchou: @ 0x8CA5CD4
	.incbin "baserom_jp.gba", 0xca5cd4, 0x2d8

	.globl gMonPalette_Chinchou
gMonPalette_Chinchou: @ 0x8CA5FAC
	.incbin "baserom_jp.gba", 0xca5fac, 0x28

	.globl gMonBackPic_Chinchou
gMonBackPic_Chinchou: @ 0x8CA5FD4
	.incbin "baserom_jp.gba", 0xca5fd4, 0x2f8

	.globl gMonShinyPalette_Chinchou
gMonShinyPalette_Chinchou: @ 0x8CA62CC
	.incbin "baserom_jp.gba", 0xca62cc, 0x448

	.globl gMonStillFrontPic_Lanturn
gMonStillFrontPic_Lanturn: @ 0x8CA6714
	.incbin "baserom_jp.gba", 0xca6714, 0x370

	.globl gMonPalette_Lanturn
gMonPalette_Lanturn: @ 0x8CA6A84
	.incbin "baserom_jp.gba", 0xca6a84, 0x28

	.globl gMonBackPic_Lanturn
gMonBackPic_Lanturn: @ 0x8CA6AAC
	.incbin "baserom_jp.gba", 0xca6aac, 0x300

	.globl gMonShinyPalette_Lanturn
gMonShinyPalette_Lanturn: @ 0x8CA6DAC
	.incbin "baserom_jp.gba", 0xca6dac, 0x448

	.globl gMonStillFrontPic_Pichu
gMonStillFrontPic_Pichu: @ 0x8CA71F4
	.incbin "baserom_jp.gba", 0xca71f4, 0x21c

	.globl gMonPalette_Pichu
gMonPalette_Pichu: @ 0x8CA7410
	.incbin "baserom_jp.gba", 0xca7410, 0x28

	.globl gMonBackPic_Pichu
gMonBackPic_Pichu: @ 0x8CA7438
	.incbin "baserom_jp.gba", 0xca7438, 0x25c

	.globl gMonShinyPalette_Pichu
gMonShinyPalette_Pichu: @ 0x8CA7694
	.incbin "baserom_jp.gba", 0xca7694, 0x448

	.globl gMonStillFrontPic_Cleffa
gMonStillFrontPic_Cleffa: @ 0x8CA7ADC
	.incbin "baserom_jp.gba", 0xca7adc, 0x1e0

	.globl gMonPalette_Cleffa
gMonPalette_Cleffa: @ 0x8CA7CBC
	.incbin "baserom_jp.gba", 0xca7cbc, 0x28

	.globl gMonBackPic_Cleffa
gMonBackPic_Cleffa: @ 0x8CA7CE4
	.incbin "baserom_jp.gba", 0xca7ce4, 0x23c

	.globl gMonShinyPalette_Cleffa
gMonShinyPalette_Cleffa: @ 0x8CA7F20
	.incbin "baserom_jp.gba", 0xca7f20, 0x448

	.globl gMonStillFrontPic_Igglybuff
gMonStillFrontPic_Igglybuff: @ 0x8CA8368
	.incbin "baserom_jp.gba", 0xca8368, 0x1e8

	.globl gMonPalette_Igglybuff
gMonPalette_Igglybuff: @ 0x8CA8550
	.incbin "baserom_jp.gba", 0xca8550, 0x28

	.globl gMonBackPic_Igglybuff
gMonBackPic_Igglybuff: @ 0x8CA8578
	.incbin "baserom_jp.gba", 0xca8578, 0x23c

	.globl gMonShinyPalette_Igglybuff
gMonShinyPalette_Igglybuff: @ 0x8CA87B4
	.incbin "baserom_jp.gba", 0xca87b4, 0x448

	.globl gMonStillFrontPic_Togepi
gMonStillFrontPic_Togepi: @ 0x8CA8BFC
	.incbin "baserom_jp.gba", 0xca8bfc, 0x1d4

	.globl gMonPalette_Togepi
gMonPalette_Togepi: @ 0x8CA8DD0
	.incbin "baserom_jp.gba", 0xca8dd0, 0x28

	.globl gMonBackPic_Togepi
gMonBackPic_Togepi: @ 0x8CA8DF8
	.incbin "baserom_jp.gba", 0xca8df8, 0x274

	.globl gMonShinyPalette_Togepi
gMonShinyPalette_Togepi: @ 0x8CA906C
	.incbin "baserom_jp.gba", 0xca906c, 0x448

	.globl gMonStillFrontPic_Togetic
gMonStillFrontPic_Togetic: @ 0x8CA94B4
	.incbin "baserom_jp.gba", 0xca94b4, 0x274

	.globl gMonPalette_Togetic
gMonPalette_Togetic: @ 0x8CA9728
	.incbin "baserom_jp.gba", 0xca9728, 0x28

	.globl gMonBackPic_Togetic
gMonBackPic_Togetic: @ 0x8CA9750
	.incbin "baserom_jp.gba", 0xca9750, 0x32c

	.globl gMonShinyPalette_Togetic
gMonShinyPalette_Togetic: @ 0x8CA9A7C
	.incbin "baserom_jp.gba", 0xca9a7c, 0x448

	.globl gMonStillFrontPic_Natu
gMonStillFrontPic_Natu: @ 0x8CA9EC4
	.incbin "baserom_jp.gba", 0xca9ec4, 0x1cc

	.globl gMonPalette_Natu
gMonPalette_Natu: @ 0x8CAA090
	.incbin "baserom_jp.gba", 0xcaa090, 0x28

	.globl gMonBackPic_Natu
gMonBackPic_Natu: @ 0x8CAA0B8
	.incbin "baserom_jp.gba", 0xcaa0b8, 0x214

	.globl gMonShinyPalette_Natu
gMonShinyPalette_Natu: @ 0x8CAA2CC
	.incbin "baserom_jp.gba", 0xcaa2cc, 0x448

	.globl gMonStillFrontPic_Xatu
gMonStillFrontPic_Xatu: @ 0x8CAA714
	.incbin "baserom_jp.gba", 0xcaa714, 0x2dc

	.globl gMonPalette_Xatu
gMonPalette_Xatu: @ 0x8CAA9F0
	.incbin "baserom_jp.gba", 0xcaa9f0, 0x28

	.globl gMonBackPic_Xatu
gMonBackPic_Xatu: @ 0x8CAAA18
	.incbin "baserom_jp.gba", 0xcaaa18, 0x378

	.globl gMonShinyPalette_Xatu
gMonShinyPalette_Xatu: @ 0x8CAAD90
	.incbin "baserom_jp.gba", 0xcaad90, 0x448

	.globl gMonStillFrontPic_Mareep
gMonStillFrontPic_Mareep: @ 0x8CAB1D8
	.incbin "baserom_jp.gba", 0xcab1d8, 0x2b4

	.globl gMonPalette_Mareep
gMonPalette_Mareep: @ 0x8CAB48C
	.incbin "baserom_jp.gba", 0xcab48c, 0x28

	.globl gMonBackPic_Mareep
gMonBackPic_Mareep: @ 0x8CAB4B4
	.incbin "baserom_jp.gba", 0xcab4b4, 0x2f4

	.globl gMonShinyPalette_Mareep
gMonShinyPalette_Mareep: @ 0x8CAB7A8
	.incbin "baserom_jp.gba", 0xcab7a8, 0x448

	.globl gMonStillFrontPic_Flaaffy
gMonStillFrontPic_Flaaffy: @ 0x8CABBF0
	.incbin "baserom_jp.gba", 0xcabbf0, 0x300

	.globl gMonPalette_Flaaffy
gMonPalette_Flaaffy: @ 0x8CABEF0
	.incbin "baserom_jp.gba", 0xcabef0, 0x28

	.globl gMonBackPic_Flaaffy
gMonBackPic_Flaaffy: @ 0x8CABF18
	.incbin "baserom_jp.gba", 0xcabf18, 0x31c

	.globl gMonShinyPalette_Flaaffy
gMonShinyPalette_Flaaffy: @ 0x8CAC234
	.incbin "baserom_jp.gba", 0xcac234, 0x448

	.globl gMonStillFrontPic_Ampharos
gMonStillFrontPic_Ampharos: @ 0x8CAC67C
	.incbin "baserom_jp.gba", 0xcac67c, 0x35c

	.globl gMonPalette_Ampharos
gMonPalette_Ampharos: @ 0x8CAC9D8
	.incbin "baserom_jp.gba", 0xcac9d8, 0x28

	.globl gMonBackPic_Ampharos
gMonBackPic_Ampharos: @ 0x8CACA00
	.incbin "baserom_jp.gba", 0xcaca00, 0x378

	.globl gMonShinyPalette_Ampharos
gMonShinyPalette_Ampharos: @ 0x8CACD78
	.incbin "baserom_jp.gba", 0xcacd78, 0x448

	.globl gMonStillFrontPic_Bellossom
gMonStillFrontPic_Bellossom: @ 0x8CAD1C0
	.incbin "baserom_jp.gba", 0xcad1c0, 0x270

	.globl gMonPalette_Bellossom
gMonPalette_Bellossom: @ 0x8CAD430
	.incbin "baserom_jp.gba", 0xcad430, 0x28

	.globl gMonBackPic_Bellossom
gMonBackPic_Bellossom: @ 0x8CAD458
	.incbin "baserom_jp.gba", 0xcad458, 0x324

	.globl gMonShinyPalette_Bellossom
gMonShinyPalette_Bellossom: @ 0x8CAD77C
	.incbin "baserom_jp.gba", 0xcad77c, 0x448

	.globl gMonStillFrontPic_Marill
gMonStillFrontPic_Marill: @ 0x8CADBC4
	.incbin "baserom_jp.gba", 0xcadbc4, 0x2c4

	.globl gMonPalette_Marill
gMonPalette_Marill: @ 0x8CADE88
	.incbin "baserom_jp.gba", 0xcade88, 0x28

	.globl gMonBackPic_Marill
gMonBackPic_Marill: @ 0x8CADEB0
	.incbin "baserom_jp.gba", 0xcadeb0, 0x2ac

	.globl gMonShinyPalette_Marill
gMonShinyPalette_Marill: @ 0x8CAE15C
	.incbin "baserom_jp.gba", 0xcae15c, 0x448

	.globl gMonStillFrontPic_Azumarill
gMonStillFrontPic_Azumarill: @ 0x8CAE5A4
	.incbin "baserom_jp.gba", 0xcae5a4, 0x300

	.globl gMonPalette_Azumarill
gMonPalette_Azumarill: @ 0x8CAE8A4
	.incbin "baserom_jp.gba", 0xcae8a4, 0x28

	.globl gMonBackPic_Azumarill
gMonBackPic_Azumarill: @ 0x8CAE8CC
	.incbin "baserom_jp.gba", 0xcae8cc, 0x2bc

	.globl gMonShinyPalette_Azumarill
gMonShinyPalette_Azumarill: @ 0x8CAEB88
	.incbin "baserom_jp.gba", 0xcaeb88, 0x448

	.globl gMonStillFrontPic_Sudowoodo
gMonStillFrontPic_Sudowoodo: @ 0x8CAEFD0
	.incbin "baserom_jp.gba", 0xcaefd0, 0x318

	.globl gMonPalette_Sudowoodo
gMonPalette_Sudowoodo: @ 0x8CAF2E8
	.incbin "baserom_jp.gba", 0xcaf2e8, 0x28

	.globl gMonBackPic_Sudowoodo
gMonBackPic_Sudowoodo: @ 0x8CAF310
	.incbin "baserom_jp.gba", 0xcaf310, 0x35c

	.globl gMonShinyPalette_Sudowoodo
gMonShinyPalette_Sudowoodo: @ 0x8CAF66C
	.incbin "baserom_jp.gba", 0xcaf66c, 0x448

	.globl gMonStillFrontPic_Politoed
gMonStillFrontPic_Politoed: @ 0x8CAFAB4
	.incbin "baserom_jp.gba", 0xcafab4, 0x33c

	.globl gMonPalette_Politoed
gMonPalette_Politoed: @ 0x8CAFDF0
	.incbin "baserom_jp.gba", 0xcafdf0, 0x28

	.globl gMonBackPic_Politoed
gMonBackPic_Politoed: @ 0x8CAFE18
	.incbin "baserom_jp.gba", 0xcafe18, 0x2bc

	.globl gMonShinyPalette_Politoed
gMonShinyPalette_Politoed: @ 0x8CB00D4
	.incbin "baserom_jp.gba", 0xcb00d4, 0x448

	.globl gMonStillFrontPic_Hoppip
gMonStillFrontPic_Hoppip: @ 0x8CB051C
	.incbin "baserom_jp.gba", 0xcb051c, 0x2b4

	.globl gMonPalette_Hoppip
gMonPalette_Hoppip: @ 0x8CB07D0
	.incbin "baserom_jp.gba", 0xcb07d0, 0x28

	.globl gMonBackPic_Hoppip
gMonBackPic_Hoppip: @ 0x8CB07F8
	.incbin "baserom_jp.gba", 0xcb07f8, 0x2e0

	.globl gMonShinyPalette_Hoppip
gMonShinyPalette_Hoppip: @ 0x8CB0AD8
	.incbin "baserom_jp.gba", 0xcb0ad8, 0x448

	.globl gMonStillFrontPic_Skiploom
gMonStillFrontPic_Skiploom: @ 0x8CB0F20
	.incbin "baserom_jp.gba", 0xcb0f20, 0x288

	.globl gMonPalette_Skiploom
gMonPalette_Skiploom: @ 0x8CB11A8
	.incbin "baserom_jp.gba", 0xcb11a8, 0x28

	.globl gMonBackPic_Skiploom
gMonBackPic_Skiploom: @ 0x8CB11D0
	.incbin "baserom_jp.gba", 0xcb11d0, 0x2e0

	.globl gMonShinyPalette_Skiploom
gMonShinyPalette_Skiploom: @ 0x8CB14B0
	.incbin "baserom_jp.gba", 0xcb14b0, 0x448

	.globl gMonStillFrontPic_Jumpluff
gMonStillFrontPic_Jumpluff: @ 0x8CB18F8
	.incbin "baserom_jp.gba", 0xcb18f8, 0x36c

	.globl gMonPalette_Jumpluff
gMonPalette_Jumpluff: @ 0x8CB1C64
	.incbin "baserom_jp.gba", 0xcb1c64, 0x28

	.globl gMonBackPic_Jumpluff
gMonBackPic_Jumpluff: @ 0x8CB1C8C
	.incbin "baserom_jp.gba", 0xcb1c8c, 0x3f8

	.globl gMonShinyPalette_Jumpluff
gMonShinyPalette_Jumpluff: @ 0x8CB2084
	.incbin "baserom_jp.gba", 0xcb2084, 0x448

	.globl gMonStillFrontPic_Aipom
gMonStillFrontPic_Aipom: @ 0x8CB24CC
	.incbin "baserom_jp.gba", 0xcb24cc, 0x2fc

	.globl gMonPalette_Aipom
gMonPalette_Aipom: @ 0x8CB27C8
	.incbin "baserom_jp.gba", 0xcb27c8, 0x28

	.globl gMonBackPic_Aipom
gMonBackPic_Aipom: @ 0x8CB27F0
	.incbin "baserom_jp.gba", 0xcb27f0, 0x2f4

	.globl gMonShinyPalette_Aipom
gMonShinyPalette_Aipom: @ 0x8CB2AE4
	.incbin "baserom_jp.gba", 0xcb2ae4, 0x448

	.globl gMonStillFrontPic_Sunkern
gMonStillFrontPic_Sunkern: @ 0x8CB2F2C
	.incbin "baserom_jp.gba", 0xcb2f2c, 0x238

	.globl gMonPalette_Sunkern
gMonPalette_Sunkern: @ 0x8CB3164
	.incbin "baserom_jp.gba", 0xcb3164, 0x28

	.globl gMonBackPic_Sunkern
gMonBackPic_Sunkern: @ 0x8CB318C
	.incbin "baserom_jp.gba", 0xcb318c, 0x2c4

	.globl gMonShinyPalette_Sunkern
gMonShinyPalette_Sunkern: @ 0x8CB3450
	.incbin "baserom_jp.gba", 0xcb3450, 0x448

	.globl gMonStillFrontPic_Sunflora
gMonStillFrontPic_Sunflora: @ 0x8CB3898
	.incbin "baserom_jp.gba", 0xcb3898, 0x358

	.globl gMonPalette_Sunflora
gMonPalette_Sunflora: @ 0x8CB3BF0
	.incbin "baserom_jp.gba", 0xcb3bf0, 0x28

	.globl gMonBackPic_Sunflora
gMonBackPic_Sunflora: @ 0x8CB3C18
	.incbin "baserom_jp.gba", 0xcb3c18, 0x3a0

	.globl gMonShinyPalette_Sunflora
gMonShinyPalette_Sunflora: @ 0x8CB3FB8
	.incbin "baserom_jp.gba", 0xcb3fb8, 0x448

	.globl gMonStillFrontPic_Yanma
gMonStillFrontPic_Yanma: @ 0x8CB4400
	.incbin "baserom_jp.gba", 0xcb4400, 0x384

	.globl gMonPalette_Yanma
gMonPalette_Yanma: @ 0x8CB4784
	.incbin "baserom_jp.gba", 0xcb4784, 0x28

	.globl gMonBackPic_Yanma
gMonBackPic_Yanma: @ 0x8CB47AC
	.incbin "baserom_jp.gba", 0xcb47ac, 0x3b4

	.globl gMonShinyPalette_Yanma
gMonShinyPalette_Yanma: @ 0x8CB4B60
	.incbin "baserom_jp.gba", 0xcb4b60, 0x448

	.globl gMonStillFrontPic_Wooper
gMonStillFrontPic_Wooper: @ 0x8CB4FA8
	.incbin "baserom_jp.gba", 0xcb4fa8, 0x240

	.globl gMonPalette_Wooper
gMonPalette_Wooper: @ 0x8CB51E8
	.incbin "baserom_jp.gba", 0xcb51e8, 0x28

	.globl gMonBackPic_Wooper
gMonBackPic_Wooper: @ 0x8CB5210
	.incbin "baserom_jp.gba", 0xcb5210, 0x28c

	.globl gMonShinyPalette_Wooper
gMonShinyPalette_Wooper: @ 0x8CB549C
	.incbin "baserom_jp.gba", 0xcb549c, 0x448

	.globl gMonStillFrontPic_Quagsire
gMonStillFrontPic_Quagsire: @ 0x8CB58E4
	.incbin "baserom_jp.gba", 0xcb58e4, 0x374

	.globl gMonPalette_Quagsire
gMonPalette_Quagsire: @ 0x8CB5C58
	.incbin "baserom_jp.gba", 0xcb5c58, 0x28

	.globl gMonBackPic_Quagsire
gMonBackPic_Quagsire: @ 0x8CB5C80
	.incbin "baserom_jp.gba", 0xcb5c80, 0x2fc

	.globl gMonShinyPalette_Quagsire
gMonShinyPalette_Quagsire: @ 0x8CB5F7C
	.incbin "baserom_jp.gba", 0xcb5f7c, 0x448

	.globl gMonStillFrontPic_Espeon
gMonStillFrontPic_Espeon: @ 0x8CB63C4
	.incbin "baserom_jp.gba", 0xcb63c4, 0x340

	.globl gMonPalette_Espeon
gMonPalette_Espeon: @ 0x8CB6704
	.incbin "baserom_jp.gba", 0xcb6704, 0x24

	.globl gMonBackPic_Espeon
gMonBackPic_Espeon: @ 0x8CB6728
	.incbin "baserom_jp.gba", 0xcb6728, 0x2dc

	.globl gMonShinyPalette_Espeon
gMonShinyPalette_Espeon: @ 0x8CB6A04
	.incbin "baserom_jp.gba", 0xcb6a04, 0x444

	.globl gMonStillFrontPic_Umbreon
gMonStillFrontPic_Umbreon: @ 0x8CB6E48
	.incbin "baserom_jp.gba", 0xcb6e48, 0x314

	.globl gMonPalette_Umbreon
gMonPalette_Umbreon: @ 0x8CB715C
	.incbin "baserom_jp.gba", 0xcb715c, 0x28

	.globl gMonBackPic_Umbreon
gMonBackPic_Umbreon: @ 0x8CB7184
	.incbin "baserom_jp.gba", 0xcb7184, 0x314

	.globl gMonShinyPalette_Umbreon
gMonShinyPalette_Umbreon: @ 0x8CB7498
	.incbin "baserom_jp.gba", 0xcb7498, 0x448

	.globl gMonStillFrontPic_Murkrow
gMonStillFrontPic_Murkrow: @ 0x8CB78E0
	.incbin "baserom_jp.gba", 0xcb78e0, 0x2e0

	.globl gMonPalette_Murkrow
gMonPalette_Murkrow: @ 0x8CB7BC0
	.incbin "baserom_jp.gba", 0xcb7bc0, 0x28

	.globl gMonBackPic_Murkrow
gMonBackPic_Murkrow: @ 0x8CB7BE8
	.incbin "baserom_jp.gba", 0xcb7be8, 0x318

	.globl gMonShinyPalette_Murkrow
gMonShinyPalette_Murkrow: @ 0x8CB7F00
	.incbin "baserom_jp.gba", 0xcb7f00, 0x448

	.globl gMonStillFrontPic_Slowking
gMonStillFrontPic_Slowking: @ 0x8CB8348
	.incbin "baserom_jp.gba", 0xcb8348, 0x3b4

	.globl gMonPalette_Slowking
gMonPalette_Slowking: @ 0x8CB86FC
	.incbin "baserom_jp.gba", 0xcb86fc, 0x28

	.globl gMonBackPic_Slowking
gMonBackPic_Slowking: @ 0x8CB8724
	.incbin "baserom_jp.gba", 0xcb8724, 0x38c

	.globl gMonShinyPalette_Slowking
gMonShinyPalette_Slowking: @ 0x8CB8AB0
	.incbin "baserom_jp.gba", 0xcb8ab0, 0x448

	.globl gMonStillFrontPic_Misdreavus
gMonStillFrontPic_Misdreavus: @ 0x8CB8EF8
	.incbin "baserom_jp.gba", 0xcb8ef8, 0x2c0

	.globl gMonPalette_Misdreavus
gMonPalette_Misdreavus: @ 0x8CB91B8
	.incbin "baserom_jp.gba", 0xcb91b8, 0x28

	.globl gMonBackPic_Misdreavus
gMonBackPic_Misdreavus: @ 0x8CB91E0
	.incbin "baserom_jp.gba", 0xcb91e0, 0x324

	.globl gMonShinyPalette_Misdreavus
gMonShinyPalette_Misdreavus: @ 0x8CB9504
	.incbin "baserom_jp.gba", 0xcb9504, 0x448

	.globl gMonStillFrontPic_UnownA
gMonStillFrontPic_UnownA: @ 0x8CB994C
	.incbin "baserom_jp.gba", 0xcb994c, 0x1d4

	.globl gMonPalette_Unown
gMonPalette_Unown: @ 0x8CB9B20
	.incbin "baserom_jp.gba", 0xcb9b20, 0x20

	.globl gMonBackPic_UnownA
gMonBackPic_UnownA: @ 0x8CB9B40
	.incbin "baserom_jp.gba", 0xcb9b40, 0x200

	.globl gMonShinyPalette_Unown
gMonShinyPalette_Unown: @ 0x8CB9D40
	.incbin "baserom_jp.gba", 0xcb9d40, 0x440

	.globl gMonStillFrontPic_Wobbuffet
gMonStillFrontPic_Wobbuffet: @ 0x8CBA180
	.incbin "baserom_jp.gba", 0xcba180, 0x350

	.globl gMonPalette_Wobbuffet
gMonPalette_Wobbuffet: @ 0x8CBA4D0
	.incbin "baserom_jp.gba", 0xcba4d0, 0x28

	.globl gMonBackPic_Wobbuffet
gMonBackPic_Wobbuffet: @ 0x8CBA4F8
	.incbin "baserom_jp.gba", 0xcba4f8, 0x244

	.globl gMonShinyPalette_Wobbuffet
gMonShinyPalette_Wobbuffet: @ 0x8CBA73C
	.incbin "baserom_jp.gba", 0xcba73c, 0x448

	.globl gMonStillFrontPic_Girafarig
gMonStillFrontPic_Girafarig: @ 0x8CBAB84
	.incbin "baserom_jp.gba", 0xcbab84, 0x404

	.globl gMonPalette_Girafarig
gMonPalette_Girafarig: @ 0x8CBAF88
	.incbin "baserom_jp.gba", 0xcbaf88, 0x28

	.globl gMonBackPic_Girafarig
gMonBackPic_Girafarig: @ 0x8CBAFB0
	.incbin "baserom_jp.gba", 0xcbafb0, 0x3ac

	.globl gMonShinyPalette_Girafarig
gMonShinyPalette_Girafarig: @ 0x8CBB35C
	.incbin "baserom_jp.gba", 0xcbb35c, 0x448

	.globl gMonStillFrontPic_Pineco
gMonStillFrontPic_Pineco: @ 0x8CBB7A4
	.incbin "baserom_jp.gba", 0xcbb7a4, 0x340

	.globl gMonPalette_Pineco
gMonPalette_Pineco: @ 0x8CBBAE4
	.incbin "baserom_jp.gba", 0xcbbae4, 0x24

	.globl gMonBackPic_Pineco
gMonBackPic_Pineco: @ 0x8CBBB08
	.incbin "baserom_jp.gba", 0xcbbb08, 0x2d8

	.globl gMonShinyPalette_Pineco
gMonShinyPalette_Pineco: @ 0x8CBBDE0
	.incbin "baserom_jp.gba", 0xcbbde0, 0x444

	.globl gMonStillFrontPic_Forretress
gMonStillFrontPic_Forretress: @ 0x8CBC224
	.incbin "baserom_jp.gba", 0xcbc224, 0x41c

	.globl gMonPalette_Forretress
gMonPalette_Forretress: @ 0x8CBC640
	.incbin "baserom_jp.gba", 0xcbc640, 0x28

	.globl gMonBackPic_Forretress
gMonBackPic_Forretress: @ 0x8CBC668
	.incbin "baserom_jp.gba", 0xcbc668, 0x2c0

	.globl gMonShinyPalette_Forretress
gMonShinyPalette_Forretress: @ 0x8CBC928
	.incbin "baserom_jp.gba", 0xcbc928, 0x448

	.globl gMonStillFrontPic_Dunsparce
gMonStillFrontPic_Dunsparce: @ 0x8CBCD70
	.incbin "baserom_jp.gba", 0xcbcd70, 0x310

	.globl gMonPalette_Dunsparce
gMonPalette_Dunsparce: @ 0x8CBD080
	.incbin "baserom_jp.gba", 0xcbd080, 0x28

	.globl gMonBackPic_Dunsparce
gMonBackPic_Dunsparce: @ 0x8CBD0A8
	.incbin "baserom_jp.gba", 0xcbd0a8, 0x2fc

	.globl gMonShinyPalette_Dunsparce
gMonShinyPalette_Dunsparce: @ 0x8CBD3A4
	.incbin "baserom_jp.gba", 0xcbd3a4, 0x448

	.globl gMonStillFrontPic_Gligar
gMonStillFrontPic_Gligar: @ 0x8CBD7EC
	.incbin "baserom_jp.gba", 0xcbd7ec, 0x428

	.globl gMonPalette_Gligar
gMonPalette_Gligar: @ 0x8CBDC14
	.incbin "baserom_jp.gba", 0xcbdc14, 0x28

	.globl gMonBackPic_Gligar
gMonBackPic_Gligar: @ 0x8CBDC3C
	.incbin "baserom_jp.gba", 0xcbdc3c, 0x3d8

	.globl gMonShinyPalette_Gligar
gMonShinyPalette_Gligar: @ 0x8CBE014
	.incbin "baserom_jp.gba", 0xcbe014, 0x448

	.globl gMonStillFrontPic_Steelix
gMonStillFrontPic_Steelix: @ 0x8CBE45C
	.incbin "baserom_jp.gba", 0xcbe45c, 0x4c8

	.globl gMonPalette_Steelix
gMonPalette_Steelix: @ 0x8CBE924
	.incbin "baserom_jp.gba", 0xcbe924, 0x24

	.globl gMonBackPic_Steelix
gMonBackPic_Steelix: @ 0x8CBE948
	.incbin "baserom_jp.gba", 0xcbe948, 0x40c

	.globl gMonShinyPalette_Steelix
gMonShinyPalette_Steelix: @ 0x8CBED54
	.incbin "baserom_jp.gba", 0xcbed54, 0x444

	.globl gMonStillFrontPic_Snubbull
gMonStillFrontPic_Snubbull: @ 0x8CBF198
	.incbin "baserom_jp.gba", 0xcbf198, 0x2d4

	.globl gMonPalette_Snubbull
gMonPalette_Snubbull: @ 0x8CBF46C
	.incbin "baserom_jp.gba", 0xcbf46c, 0x28

	.globl gMonBackPic_Snubbull
gMonBackPic_Snubbull: @ 0x8CBF494
	.incbin "baserom_jp.gba", 0xcbf494, 0x328

	.globl gMonShinyPalette_Snubbull
gMonShinyPalette_Snubbull: @ 0x8CBF7BC
	.incbin "baserom_jp.gba", 0xcbf7bc, 0x448

	.globl gMonStillFrontPic_Granbull
gMonStillFrontPic_Granbull: @ 0x8CBFC04
	.incbin "baserom_jp.gba", 0xcbfc04, 0x38c

	.globl gMonPalette_Granbull
gMonPalette_Granbull: @ 0x8CBFF90
	.incbin "baserom_jp.gba", 0xcbff90, 0x28

	.globl gMonBackPic_Granbull
gMonBackPic_Granbull: @ 0x8CBFFB8
	.incbin "baserom_jp.gba", 0xcbffb8, 0x324

	.globl gMonShinyPalette_Granbull
gMonShinyPalette_Granbull: @ 0x8CC02DC
	.incbin "baserom_jp.gba", 0xcc02dc, 0x448

	.globl gMonStillFrontPic_Qwilfish
gMonStillFrontPic_Qwilfish: @ 0x8CC0724
	.incbin "baserom_jp.gba", 0xcc0724, 0x2c0

	.globl gMonPalette_Qwilfish
gMonPalette_Qwilfish: @ 0x8CC09E4
	.incbin "baserom_jp.gba", 0xcc09e4, 0x28

	.globl gMonBackPic_Qwilfish
gMonBackPic_Qwilfish: @ 0x8CC0A0C
	.incbin "baserom_jp.gba", 0xcc0a0c, 0x2e0

	.globl gMonShinyPalette_Qwilfish
gMonShinyPalette_Qwilfish: @ 0x8CC0CEC
	.incbin "baserom_jp.gba", 0xcc0cec, 0x448

	.globl gMonStillFrontPic_Scizor
gMonStillFrontPic_Scizor: @ 0x8CC1134
	.incbin "baserom_jp.gba", 0xcc1134, 0x4e8

	.globl gMonPalette_Scizor
gMonPalette_Scizor: @ 0x8CC161C
	.incbin "baserom_jp.gba", 0xcc161c, 0x28

	.globl gMonBackPic_Scizor
gMonBackPic_Scizor: @ 0x8CC1644
	.incbin "baserom_jp.gba", 0xcc1644, 0x380

	.globl gMonShinyPalette_Scizor
gMonShinyPalette_Scizor: @ 0x8CC19C4
	.incbin "baserom_jp.gba", 0xcc19c4, 0x448

	.globl gMonStillFrontPic_Shuckle
gMonStillFrontPic_Shuckle: @ 0x8CC1E0C
	.incbin "baserom_jp.gba", 0xcc1e0c, 0x2c8

	.globl gMonPalette_Shuckle
gMonPalette_Shuckle: @ 0x8CC20D4
	.incbin "baserom_jp.gba", 0xcc20d4, 0x28

	.globl gMonBackPic_Shuckle
gMonBackPic_Shuckle: @ 0x8CC20FC
	.incbin "baserom_jp.gba", 0xcc20fc, 0x258

	.globl gMonShinyPalette_Shuckle
gMonShinyPalette_Shuckle: @ 0x8CC2354
	.incbin "baserom_jp.gba", 0xcc2354, 0x448

	.globl gMonStillFrontPic_Heracross
gMonStillFrontPic_Heracross: @ 0x8CC279C
	.incbin "baserom_jp.gba", 0xcc279c, 0x3f0

	.globl gMonPalette_Heracross
gMonPalette_Heracross: @ 0x8CC2B8C
	.incbin "baserom_jp.gba", 0xcc2b8c, 0x28

	.globl gMonBackPic_Heracross
gMonBackPic_Heracross: @ 0x8CC2BB4
	.incbin "baserom_jp.gba", 0xcc2bb4, 0x370

	.globl gMonShinyPalette_Heracross
gMonShinyPalette_Heracross: @ 0x8CC2F24
	.incbin "baserom_jp.gba", 0xcc2f24, 0x448

	.globl gMonStillFrontPic_Sneasel
gMonStillFrontPic_Sneasel: @ 0x8CC336C
	.incbin "baserom_jp.gba", 0xcc336c, 0x344

	.globl gMonPalette_Sneasel
gMonPalette_Sneasel: @ 0x8CC36B0
	.incbin "baserom_jp.gba", 0xcc36b0, 0x28

	.globl gMonBackPic_Sneasel
gMonBackPic_Sneasel: @ 0x8CC36D8
	.incbin "baserom_jp.gba", 0xcc36d8, 0x324

	.globl gMonShinyPalette_Sneasel
gMonShinyPalette_Sneasel: @ 0x8CC39FC
	.incbin "baserom_jp.gba", 0xcc39fc, 0x448

	.globl gMonStillFrontPic_Teddiursa
gMonStillFrontPic_Teddiursa: @ 0x8CC3E44
	.incbin "baserom_jp.gba", 0xcc3e44, 0x26c

	.globl gMonPalette_Teddiursa
gMonPalette_Teddiursa: @ 0x8CC40B0
	.incbin "baserom_jp.gba", 0xcc40b0, 0x28

	.globl gMonBackPic_Teddiursa
gMonBackPic_Teddiursa: @ 0x8CC40D8
	.incbin "baserom_jp.gba", 0xcc40d8, 0x278

	.globl gMonShinyPalette_Teddiursa
gMonShinyPalette_Teddiursa: @ 0x8CC4350
	.incbin "baserom_jp.gba", 0xcc4350, 0x448

	.globl gMonStillFrontPic_Ursaring
gMonStillFrontPic_Ursaring: @ 0x8CC4798
	.incbin "baserom_jp.gba", 0xcc4798, 0x438

	.globl gMonPalette_Ursaring
gMonPalette_Ursaring: @ 0x8CC4BD0
	.incbin "baserom_jp.gba", 0xcc4bd0, 0x28

	.globl gMonBackPic_Ursaring
gMonBackPic_Ursaring: @ 0x8CC4BF8
	.incbin "baserom_jp.gba", 0xcc4bf8, 0x388

	.globl gMonShinyPalette_Ursaring
gMonShinyPalette_Ursaring: @ 0x8CC4F80
	.incbin "baserom_jp.gba", 0xcc4f80, 0x448

	.globl gMonStillFrontPic_Slugma
gMonStillFrontPic_Slugma: @ 0x8CC53C8
	.incbin "baserom_jp.gba", 0xcc53c8, 0x274

	.globl gMonPalette_Slugma
gMonPalette_Slugma: @ 0x8CC563C
	.incbin "baserom_jp.gba", 0xcc563c, 0x24

	.globl gMonBackPic_Slugma
gMonBackPic_Slugma: @ 0x8CC5660
	.incbin "baserom_jp.gba", 0xcc5660, 0x2e8

	.globl gMonShinyPalette_Slugma
gMonShinyPalette_Slugma: @ 0x8CC5948
	.incbin "baserom_jp.gba", 0xcc5948, 0x444

	.globl gMonStillFrontPic_Magcargo
gMonStillFrontPic_Magcargo: @ 0x8CC5D8C
	.incbin "baserom_jp.gba", 0xcc5d8c, 0x348

	.globl gMonPalette_Magcargo
gMonPalette_Magcargo: @ 0x8CC60D4
	.incbin "baserom_jp.gba", 0xcc60d4, 0x28

	.globl gMonBackPic_Magcargo
gMonBackPic_Magcargo: @ 0x8CC60FC
	.incbin "baserom_jp.gba", 0xcc60fc, 0x418

	.globl gMonShinyPalette_Magcargo
gMonShinyPalette_Magcargo: @ 0x8CC6514
	.incbin "baserom_jp.gba", 0xcc6514, 0x448

	.globl gMonStillFrontPic_Swinub
gMonStillFrontPic_Swinub: @ 0x8CC695C
	.incbin "baserom_jp.gba", 0xcc695c, 0x1fc

	.globl gMonPalette_Swinub
gMonPalette_Swinub: @ 0x8CC6B58
	.incbin "baserom_jp.gba", 0xcc6b58, 0x28

	.globl gMonBackPic_Swinub
gMonBackPic_Swinub: @ 0x8CC6B80
	.incbin "baserom_jp.gba", 0xcc6b80, 0x23c

	.globl gMonShinyPalette_Swinub
gMonShinyPalette_Swinub: @ 0x8CC6DBC
	.incbin "baserom_jp.gba", 0xcc6dbc, 0x448

	.globl gMonStillFrontPic_Piloswine
gMonStillFrontPic_Piloswine: @ 0x8CC7204
	.incbin "baserom_jp.gba", 0xcc7204, 0x328

	.globl gMonPalette_Piloswine
gMonPalette_Piloswine: @ 0x8CC752C
	.incbin "baserom_jp.gba", 0xcc752c, 0x28

	.globl gMonBackPic_Piloswine
gMonBackPic_Piloswine: @ 0x8CC7554
	.incbin "baserom_jp.gba", 0xcc7554, 0x24c

	.globl gMonShinyPalette_Piloswine
gMonShinyPalette_Piloswine: @ 0x8CC77A0
	.incbin "baserom_jp.gba", 0xcc77a0, 0x448

	.globl gMonStillFrontPic_Corsola
gMonStillFrontPic_Corsola: @ 0x8CC7BE8
	.incbin "baserom_jp.gba", 0xcc7be8, 0x2e8

	.globl gMonPalette_Corsola
gMonPalette_Corsola: @ 0x8CC7ED0
	.incbin "baserom_jp.gba", 0xcc7ed0, 0x28

	.globl gMonBackPic_Corsola
gMonBackPic_Corsola: @ 0x8CC7EF8
	.incbin "baserom_jp.gba", 0xcc7ef8, 0x2c0

	.globl gMonShinyPalette_Corsola
gMonShinyPalette_Corsola: @ 0x8CC81B8
	.incbin "baserom_jp.gba", 0xcc81b8, 0x448

	.globl gMonStillFrontPic_Remoraid
gMonStillFrontPic_Remoraid: @ 0x8CC8600
	.incbin "baserom_jp.gba", 0xcc8600, 0x268

	.globl gMonPalette_Remoraid
gMonPalette_Remoraid: @ 0x8CC8868
	.incbin "baserom_jp.gba", 0xcc8868, 0x28

	.globl gMonBackPic_Remoraid
gMonBackPic_Remoraid: @ 0x8CC8890
	.incbin "baserom_jp.gba", 0xcc8890, 0x314

	.globl gMonShinyPalette_Remoraid
gMonShinyPalette_Remoraid: @ 0x8CC8BA4
	.incbin "baserom_jp.gba", 0xcc8ba4, 0x448

	.globl gMonStillFrontPic_Octillery
gMonStillFrontPic_Octillery: @ 0x8CC8FEC
	.incbin "baserom_jp.gba", 0xcc8fec, 0x334

	.globl gMonPalette_Octillery
gMonPalette_Octillery: @ 0x8CC9320
	.incbin "baserom_jp.gba", 0xcc9320, 0x28

	.globl gMonBackPic_Octillery
gMonBackPic_Octillery: @ 0x8CC9348
	.incbin "baserom_jp.gba", 0xcc9348, 0x2b8

	.globl gMonShinyPalette_Octillery
gMonShinyPalette_Octillery: @ 0x8CC9600
	.incbin "baserom_jp.gba", 0xcc9600, 0x448

	.globl gMonStillFrontPic_Delibird
gMonStillFrontPic_Delibird: @ 0x8CC9A48
	.incbin "baserom_jp.gba", 0xcc9a48, 0x370

	.globl gMonPalette_Delibird
gMonPalette_Delibird: @ 0x8CC9DB8
	.incbin "baserom_jp.gba", 0xcc9db8, 0x28

	.globl gMonBackPic_Delibird
gMonBackPic_Delibird: @ 0x8CC9DE0
	.incbin "baserom_jp.gba", 0xcc9de0, 0x3c0

	.globl gMonShinyPalette_Delibird
gMonShinyPalette_Delibird: @ 0x8CCA1A0
	.incbin "baserom_jp.gba", 0xcca1a0, 0x448

	.globl gMonStillFrontPic_Mantine
gMonStillFrontPic_Mantine: @ 0x8CCA5E8
	.incbin "baserom_jp.gba", 0xcca5e8, 0x49c

	.globl gMonPalette_Mantine
gMonPalette_Mantine: @ 0x8CCAA84
	.incbin "baserom_jp.gba", 0xccaa84, 0x28

	.globl gMonBackPic_Mantine
gMonBackPic_Mantine: @ 0x8CCAAAC
	.incbin "baserom_jp.gba", 0xccaaac, 0x2a0

	.globl gMonShinyPalette_Mantine
gMonShinyPalette_Mantine: @ 0x8CCAD4C
	.incbin "baserom_jp.gba", 0xccad4c, 0x448

	.globl gMonStillFrontPic_Skarmory
gMonStillFrontPic_Skarmory: @ 0x8CCB194
	.incbin "baserom_jp.gba", 0xccb194, 0x4e0

	.globl gMonPalette_Skarmory
gMonPalette_Skarmory: @ 0x8CCB674
	.incbin "baserom_jp.gba", 0xccb674, 0x28

	.globl gMonBackPic_Skarmory
gMonBackPic_Skarmory: @ 0x8CCB69C
	.incbin "baserom_jp.gba", 0xccb69c, 0x304

	.globl gMonShinyPalette_Skarmory
gMonShinyPalette_Skarmory: @ 0x8CCB9A0
	.incbin "baserom_jp.gba", 0xccb9a0, 0x448

	.globl gMonStillFrontPic_Houndour
gMonStillFrontPic_Houndour: @ 0x8CCBDE8
	.incbin "baserom_jp.gba", 0xccbde8, 0x2b8

	.globl gMonPalette_Houndour
gMonPalette_Houndour: @ 0x8CCC0A0
	.incbin "baserom_jp.gba", 0xccc0a0, 0x28

	.globl gMonBackPic_Houndour
gMonBackPic_Houndour: @ 0x8CCC0C8
	.incbin "baserom_jp.gba", 0xccc0c8, 0x280

	.globl gMonShinyPalette_Houndour
gMonShinyPalette_Houndour: @ 0x8CCC348
	.incbin "baserom_jp.gba", 0xccc348, 0x448

	.globl gMonStillFrontPic_Houndoom
gMonStillFrontPic_Houndoom: @ 0x8CCC790
	.incbin "baserom_jp.gba", 0xccc790, 0x400

	.globl gMonPalette_Houndoom
gMonPalette_Houndoom: @ 0x8CCCB90
	.incbin "baserom_jp.gba", 0xcccb90, 0x28

	.globl gMonBackPic_Houndoom
gMonBackPic_Houndoom: @ 0x8CCCBB8
	.incbin "baserom_jp.gba", 0xcccbb8, 0x324

	.globl gMonShinyPalette_Houndoom
gMonShinyPalette_Houndoom: @ 0x8CCCEDC
	.incbin "baserom_jp.gba", 0xcccedc, 0x448

	.globl gMonStillFrontPic_Kingdra
gMonStillFrontPic_Kingdra: @ 0x8CCD324
	.incbin "baserom_jp.gba", 0xccd324, 0x420

	.globl gMonPalette_Kingdra
gMonPalette_Kingdra: @ 0x8CCD744
	.incbin "baserom_jp.gba", 0xccd744, 0x28

	.globl gMonBackPic_Kingdra
gMonBackPic_Kingdra: @ 0x8CCD76C
	.incbin "baserom_jp.gba", 0xccd76c, 0x3b4

	.globl gMonShinyPalette_Kingdra
gMonShinyPalette_Kingdra: @ 0x8CCDB20
	.incbin "baserom_jp.gba", 0xccdb20, 0x448

	.globl gMonStillFrontPic_Phanpy
gMonStillFrontPic_Phanpy: @ 0x8CCDF68
	.incbin "baserom_jp.gba", 0xccdf68, 0x25c

	.globl gMonPalette_Phanpy
gMonPalette_Phanpy: @ 0x8CCE1C4
	.incbin "baserom_jp.gba", 0xcce1c4, 0x28

	.globl gMonBackPic_Phanpy
gMonBackPic_Phanpy: @ 0x8CCE1EC
	.incbin "baserom_jp.gba", 0xcce1ec, 0x2c4

	.globl gMonShinyPalette_Phanpy
gMonShinyPalette_Phanpy: @ 0x8CCE4B0
	.incbin "baserom_jp.gba", 0xcce4b0, 0x448

	.globl gMonStillFrontPic_Donphan
gMonStillFrontPic_Donphan: @ 0x8CCE8F8
	.incbin "baserom_jp.gba", 0xcce8f8, 0x474

	.globl gMonPalette_Donphan
gMonPalette_Donphan: @ 0x8CCED6C
	.incbin "baserom_jp.gba", 0xcced6c, 0x28

	.globl gMonBackPic_Donphan
gMonBackPic_Donphan: @ 0x8CCED94
	.incbin "baserom_jp.gba", 0xcced94, 0x2fc

	.globl gMonShinyPalette_Donphan
gMonShinyPalette_Donphan: @ 0x8CCF090
	.incbin "baserom_jp.gba", 0xccf090, 0x448

	.globl gMonStillFrontPic_Porygon2
gMonStillFrontPic_Porygon2: @ 0x8CCF4D8
	.incbin "baserom_jp.gba", 0xccf4d8, 0x288

	.globl gMonPalette_Porygon2
gMonPalette_Porygon2: @ 0x8CCF760
	.incbin "baserom_jp.gba", 0xccf760, 0x28

	.globl gMonBackPic_Porygon2
gMonBackPic_Porygon2: @ 0x8CCF788
	.incbin "baserom_jp.gba", 0xccf788, 0x31c

	.globl gMonShinyPalette_Porygon2
gMonShinyPalette_Porygon2: @ 0x8CCFAA4
	.incbin "baserom_jp.gba", 0xccfaa4, 0x448

	.globl gMonStillFrontPic_Stantler
gMonStillFrontPic_Stantler: @ 0x8CCFEEC
	.incbin "baserom_jp.gba", 0xccfeec, 0x414

	.globl gMonPalette_Stantler
gMonPalette_Stantler: @ 0x8CD0300
	.incbin "baserom_jp.gba", 0xcd0300, 0x28

	.globl gMonBackPic_Stantler
gMonBackPic_Stantler: @ 0x8CD0328
	.incbin "baserom_jp.gba", 0xcd0328, 0x34c

	.globl gMonShinyPalette_Stantler
gMonShinyPalette_Stantler: @ 0x8CD0674
	.incbin "baserom_jp.gba", 0xcd0674, 0x448

	.globl gMonStillFrontPic_Smeargle
gMonStillFrontPic_Smeargle: @ 0x8CD0ABC
	.incbin "baserom_jp.gba", 0xcd0abc, 0x394

	.globl gMonPalette_Smeargle
gMonPalette_Smeargle: @ 0x8CD0E50
	.incbin "baserom_jp.gba", 0xcd0e50, 0x28

	.globl gMonBackPic_Smeargle
gMonBackPic_Smeargle: @ 0x8CD0E78
	.incbin "baserom_jp.gba", 0xcd0e78, 0x324

	.globl gMonShinyPalette_Smeargle
gMonShinyPalette_Smeargle: @ 0x8CD119C
	.incbin "baserom_jp.gba", 0xcd119c, 0x448

	.globl gMonStillFrontPic_Tyrogue
gMonStillFrontPic_Tyrogue: @ 0x8CD15E4
	.incbin "baserom_jp.gba", 0xcd15e4, 0x28c

	.globl gMonPalette_Tyrogue
gMonPalette_Tyrogue: @ 0x8CD1870
	.incbin "baserom_jp.gba", 0xcd1870, 0x28

	.globl gMonBackPic_Tyrogue
gMonBackPic_Tyrogue: @ 0x8CD1898
	.incbin "baserom_jp.gba", 0xcd1898, 0x31c

	.globl gMonShinyPalette_Tyrogue
gMonShinyPalette_Tyrogue: @ 0x8CD1BB4
	.incbin "baserom_jp.gba", 0xcd1bb4, 0x448

	.globl gMonStillFrontPic_Hitmontop
gMonStillFrontPic_Hitmontop: @ 0x8CD1FFC
	.incbin "baserom_jp.gba", 0xcd1ffc, 0x38c

	.globl gMonPalette_Hitmontop
gMonPalette_Hitmontop: @ 0x8CD2388
	.incbin "baserom_jp.gba", 0xcd2388, 0x28

	.globl gMonBackPic_Hitmontop
gMonBackPic_Hitmontop: @ 0x8CD23B0
	.incbin "baserom_jp.gba", 0xcd23b0, 0x428

	.globl gMonShinyPalette_Hitmontop
gMonShinyPalette_Hitmontop: @ 0x8CD27D8
	.incbin "baserom_jp.gba", 0xcd27d8, 0x448

	.globl gMonStillFrontPic_Smoochum
gMonStillFrontPic_Smoochum: @ 0x8CD2C20
	.incbin "baserom_jp.gba", 0xcd2c20, 0x258

	.globl gMonPalette_Smoochum
gMonPalette_Smoochum: @ 0x8CD2E78
	.incbin "baserom_jp.gba", 0xcd2e78, 0x28

	.globl gMonBackPic_Smoochum
gMonBackPic_Smoochum: @ 0x8CD2EA0
	.incbin "baserom_jp.gba", 0xcd2ea0, 0x278

	.globl gMonShinyPalette_Smoochum
gMonShinyPalette_Smoochum: @ 0x8CD3118
	.incbin "baserom_jp.gba", 0xcd3118, 0x448

	.globl gMonStillFrontPic_Elekid
gMonStillFrontPic_Elekid: @ 0x8CD3560
	.incbin "baserom_jp.gba", 0xcd3560, 0x308

	.globl gMonPalette_Elekid
gMonPalette_Elekid: @ 0x8CD3868
	.incbin "baserom_jp.gba", 0xcd3868, 0x28

	.globl gMonBackPic_Elekid
gMonBackPic_Elekid: @ 0x8CD3890
	.incbin "baserom_jp.gba", 0xcd3890, 0x358

	.globl gMonShinyPalette_Elekid
gMonShinyPalette_Elekid: @ 0x8CD3BE8
	.incbin "baserom_jp.gba", 0xcd3be8, 0x448

	.globl gMonStillFrontPic_Magby
gMonStillFrontPic_Magby: @ 0x8CD4030
	.incbin "baserom_jp.gba", 0xcd4030, 0x284

	.globl gMonPalette_Magby
gMonPalette_Magby: @ 0x8CD42B4
	.incbin "baserom_jp.gba", 0xcd42b4, 0x28

	.globl gMonBackPic_Magby
gMonBackPic_Magby: @ 0x8CD42DC
	.incbin "baserom_jp.gba", 0xcd42dc, 0x2ac

	.globl gMonShinyPalette_Magby
gMonShinyPalette_Magby: @ 0x8CD4588
	.incbin "baserom_jp.gba", 0xcd4588, 0x448

	.globl gMonStillFrontPic_Miltank
gMonStillFrontPic_Miltank: @ 0x8CD49D0
	.incbin "baserom_jp.gba", 0xcd49d0, 0x3b0

	.globl gMonPalette_Miltank
gMonPalette_Miltank: @ 0x8CD4D80
	.incbin "baserom_jp.gba", 0xcd4d80, 0x28

	.globl gMonBackPic_Miltank
gMonBackPic_Miltank: @ 0x8CD4DA8
	.incbin "baserom_jp.gba", 0xcd4da8, 0x39c

	.globl gMonShinyPalette_Miltank
gMonShinyPalette_Miltank: @ 0x8CD5144
	.incbin "baserom_jp.gba", 0xcd5144, 0x448

	.globl gMonStillFrontPic_Blissey
gMonStillFrontPic_Blissey: @ 0x8CD558C
	.incbin "baserom_jp.gba", 0xcd558c, 0x3e8

	.globl gMonPalette_Blissey
gMonPalette_Blissey: @ 0x8CD5974
	.incbin "baserom_jp.gba", 0xcd5974, 0x28

	.globl gMonBackPic_Blissey
gMonBackPic_Blissey: @ 0x8CD599C
	.incbin "baserom_jp.gba", 0xcd599c, 0x2cc

	.globl gMonShinyPalette_Blissey
gMonShinyPalette_Blissey: @ 0x8CD5C68
	.incbin "baserom_jp.gba", 0xcd5c68, 0x448

	.globl gMonStillFrontPic_Raikou
gMonStillFrontPic_Raikou: @ 0x8CD60B0
	.incbin "baserom_jp.gba", 0xcd60b0, 0x57c

	.globl gMonPalette_Raikou
gMonPalette_Raikou: @ 0x8CD662C
	.incbin "baserom_jp.gba", 0xcd662c, 0x28

	.globl gMonBackPic_Raikou
gMonBackPic_Raikou: @ 0x8CD6654
	.incbin "baserom_jp.gba", 0xcd6654, 0x3a8

	.globl gMonShinyPalette_Raikou
gMonShinyPalette_Raikou: @ 0x8CD69FC
	.incbin "baserom_jp.gba", 0xcd69fc, 0x448

	.globl gMonStillFrontPic_Entei
gMonStillFrontPic_Entei: @ 0x8CD6E44
	.incbin "baserom_jp.gba", 0xcd6e44, 0x5fc

	.globl gMonPalette_Entei
gMonPalette_Entei: @ 0x8CD7440
	.incbin "baserom_jp.gba", 0xcd7440, 0x28

	.globl gMonBackPic_Entei
gMonBackPic_Entei: @ 0x8CD7468
	.incbin "baserom_jp.gba", 0xcd7468, 0x424

	.globl gMonShinyPalette_Entei
gMonShinyPalette_Entei: @ 0x8CD788C
	.incbin "baserom_jp.gba", 0xcd788c, 0x448

	.globl gMonStillFrontPic_Suicune
gMonStillFrontPic_Suicune: @ 0x8CD7CD4
	.incbin "baserom_jp.gba", 0xcd7cd4, 0x584

	.globl gMonPalette_Suicune
gMonPalette_Suicune: @ 0x8CD8258
	.incbin "baserom_jp.gba", 0xcd8258, 0x28

	.globl gMonBackPic_Suicune
gMonBackPic_Suicune: @ 0x8CD8280
	.incbin "baserom_jp.gba", 0xcd8280, 0x4dc

	.globl gMonShinyPalette_Suicune
gMonShinyPalette_Suicune: @ 0x8CD875C
	.incbin "baserom_jp.gba", 0xcd875c, 0x448

	.globl gMonStillFrontPic_Larvitar
gMonStillFrontPic_Larvitar: @ 0x8CD8BA4
	.incbin "baserom_jp.gba", 0xcd8ba4, 0x25c

	.globl gMonPalette_Larvitar
gMonPalette_Larvitar: @ 0x8CD8E00
	.incbin "baserom_jp.gba", 0xcd8e00, 0x28

	.globl gMonBackPic_Larvitar
gMonBackPic_Larvitar: @ 0x8CD8E28
	.incbin "baserom_jp.gba", 0xcd8e28, 0x2ac

	.globl gMonShinyPalette_Larvitar
gMonShinyPalette_Larvitar: @ 0x8CD90D4
	.incbin "baserom_jp.gba", 0xcd90d4, 0x448

	.globl gMonStillFrontPic_Pupitar
gMonStillFrontPic_Pupitar: @ 0x8CD951C
	.incbin "baserom_jp.gba", 0xcd951c, 0x2f0

	.globl gMonPalette_Pupitar
gMonPalette_Pupitar: @ 0x8CD980C
	.incbin "baserom_jp.gba", 0xcd980c, 0x28

	.globl gMonBackPic_Pupitar
gMonBackPic_Pupitar: @ 0x8CD9834
	.incbin "baserom_jp.gba", 0xcd9834, 0x338

	.globl gMonShinyPalette_Pupitar
gMonShinyPalette_Pupitar: @ 0x8CD9B6C
	.incbin "baserom_jp.gba", 0xcd9b6c, 0x448

	.globl gMonStillFrontPic_Tyranitar
gMonStillFrontPic_Tyranitar: @ 0x8CD9FB4
	.incbin "baserom_jp.gba", 0xcd9fb4, 0x53c

	.globl gMonPalette_Tyranitar
gMonPalette_Tyranitar: @ 0x8CDA4F0
	.incbin "baserom_jp.gba", 0xcda4f0, 0x28

	.globl gMonBackPic_Tyranitar
gMonBackPic_Tyranitar: @ 0x8CDA518
	.incbin "baserom_jp.gba", 0xcda518, 0x3ec

	.globl gMonShinyPalette_Tyranitar
gMonShinyPalette_Tyranitar: @ 0x8CDA904
	.incbin "baserom_jp.gba", 0xcda904, 0x448

	.globl gMonStillFrontPic_Lugia
gMonStillFrontPic_Lugia: @ 0x8CDAD4C
	.incbin "baserom_jp.gba", 0xcdad4c, 0x4c4

	.globl gMonPalette_Lugia
gMonPalette_Lugia: @ 0x8CDB210
	.incbin "baserom_jp.gba", 0xcdb210, 0x28

	.globl gMonBackPic_Lugia
gMonBackPic_Lugia: @ 0x8CDB238
	.incbin "baserom_jp.gba", 0xcdb238, 0x3d4

	.globl gMonShinyPalette_Lugia
gMonShinyPalette_Lugia: @ 0x8CDB60C
	.incbin "baserom_jp.gba", 0xcdb60c, 0x448

	.globl gMonStillFrontPic_HoOh
gMonStillFrontPic_HoOh: @ 0x8CDBA54
	.incbin "baserom_jp.gba", 0xcdba54, 0x654

	.globl gMonPalette_HoOh
gMonPalette_HoOh: @ 0x8CDC0A8
	.incbin "baserom_jp.gba", 0xcdc0a8, 0x28

	.globl gMonBackPic_HoOh
gMonBackPic_HoOh: @ 0x8CDC0D0
	.incbin "baserom_jp.gba", 0xcdc0d0, 0x410

	.globl gMonShinyPalette_HoOh
gMonShinyPalette_HoOh: @ 0x8CDC4E0
	.incbin "baserom_jp.gba", 0xcdc4e0, 0x448

	.globl gMonStillFrontPic_Celebi
gMonStillFrontPic_Celebi: @ 0x8CDC928
	.incbin "baserom_jp.gba", 0xcdc928, 0x278

	.globl gMonPalette_Celebi
gMonPalette_Celebi: @ 0x8CDCBA0
	.incbin "baserom_jp.gba", 0xcdcba0, 0x28

	.globl gMonBackPic_Celebi
gMonBackPic_Celebi: @ 0x8CDCBC8
	.incbin "baserom_jp.gba", 0xcdcbc8, 0x3ac

	.globl gMonShinyPalette_Celebi
gMonShinyPalette_Celebi: @ 0x8CDCF74
	.incbin "baserom_jp.gba", 0xcdcf74, 0x448

	.globl gMonStillFrontPic_DoubleQuestionMark
gMonStillFrontPic_DoubleQuestionMark: @ 0x8CDD3BC
	.incbin "baserom_jp.gba", 0xcdd3bc, 0x180

	.globl gMonPalette_DoubleQuestionMark
gMonPalette_DoubleQuestionMark: @ 0x8CDD53C
	.incbin "baserom_jp.gba", 0xcdd53c, 0x14

	.globl gMonBackPic_DoubleQuestionMark
gMonBackPic_DoubleQuestionMark: @ 0x8CDD550
	.incbin "baserom_jp.gba", 0xcdd550, 0x184

	.globl gMonShinyPalette_DoubleQuestionMark
gMonShinyPalette_DoubleQuestionMark: @ 0x8CDD6D4
	.incbin "baserom_jp.gba", 0xcdd6d4, 0x14

	.globl gMonStillFrontPic_Treecko
gMonStillFrontPic_Treecko: @ 0x8CDD6E8
	.incbin "baserom_jp.gba", 0xcdd6e8, 0x308

	.globl gMonPalette_Treecko
gMonPalette_Treecko: @ 0x8CDD9F0
	.incbin "baserom_jp.gba", 0xcdd9f0, 0x28

	.globl gMonBackPic_Treecko
gMonBackPic_Treecko: @ 0x8CDDA18
	.incbin "baserom_jp.gba", 0xcdda18, 0x300

	.globl gMonShinyPalette_Treecko
gMonShinyPalette_Treecko: @ 0x8CDDD18
	.incbin "baserom_jp.gba", 0xcddd18, 0x448

	.globl gMonStillFrontPic_Grovyle
gMonStillFrontPic_Grovyle: @ 0x8CDE160
	.incbin "baserom_jp.gba", 0xcde160, 0x48c

	.globl gMonPalette_Grovyle
gMonPalette_Grovyle: @ 0x8CDE5EC
	.incbin "baserom_jp.gba", 0xcde5ec, 0x28

	.globl gMonBackPic_Grovyle
gMonBackPic_Grovyle: @ 0x8CDE614
	.incbin "baserom_jp.gba", 0xcde614, 0x33c

	.globl gMonShinyPalette_Grovyle
gMonShinyPalette_Grovyle: @ 0x8CDE950
	.incbin "baserom_jp.gba", 0xcde950, 0x448

	.globl gMonStillFrontPic_Sceptile
gMonStillFrontPic_Sceptile: @ 0x8CDED98
	.incbin "baserom_jp.gba", 0xcded98, 0x504

	.globl gMonPalette_Sceptile
gMonPalette_Sceptile: @ 0x8CDF29C
	.incbin "baserom_jp.gba", 0xcdf29c, 0x28

	.globl gMonBackPic_Sceptile
gMonBackPic_Sceptile: @ 0x8CDF2C4
	.incbin "baserom_jp.gba", 0xcdf2c4, 0x3fc

	.globl gMonShinyPalette_Sceptile
gMonShinyPalette_Sceptile: @ 0x8CDF6C0
	.incbin "baserom_jp.gba", 0xcdf6c0, 0x448

	.globl gMonStillFrontPic_Torchic
gMonStillFrontPic_Torchic: @ 0x8CDFB08
	.incbin "baserom_jp.gba", 0xcdfb08, 0x29c

	.globl gMonPalette_Torchic
gMonPalette_Torchic: @ 0x8CDFDA4
	.incbin "baserom_jp.gba", 0xcdfda4, 0x28

	.globl gMonBackPic_Torchic
gMonBackPic_Torchic: @ 0x8CDFDCC
	.incbin "baserom_jp.gba", 0xcdfdcc, 0x2d8

	.globl gMonShinyPalette_Torchic
gMonShinyPalette_Torchic: @ 0x8CE00A4
	.incbin "baserom_jp.gba", 0xce00a4, 0x448

	.globl gMonStillFrontPic_Combusken
gMonStillFrontPic_Combusken: @ 0x8CE04EC
	.incbin "baserom_jp.gba", 0xce04ec, 0x3ec

	.globl gMonPalette_Combusken
gMonPalette_Combusken: @ 0x8CE08D8
	.incbin "baserom_jp.gba", 0xce08d8, 0x28

	.globl gMonBackPic_Combusken
gMonBackPic_Combusken: @ 0x8CE0900
	.incbin "baserom_jp.gba", 0xce0900, 0x3d0

	.globl gMonShinyPalette_Combusken
gMonShinyPalette_Combusken: @ 0x8CE0CD0
	.incbin "baserom_jp.gba", 0xce0cd0, 0x448

	.globl gMonStillFrontPic_Blaziken
gMonStillFrontPic_Blaziken: @ 0x8CE1118
	.incbin "baserom_jp.gba", 0xce1118, 0x750

	.globl gMonPalette_Blaziken
gMonPalette_Blaziken: @ 0x8CE1868
	.incbin "baserom_jp.gba", 0xce1868, 0x28

	.globl gMonBackPic_Blaziken
gMonBackPic_Blaziken: @ 0x8CE1890
	.incbin "baserom_jp.gba", 0xce1890, 0x3dc

	.globl gMonShinyPalette_Blaziken
gMonShinyPalette_Blaziken: @ 0x8CE1C6C
	.incbin "baserom_jp.gba", 0xce1c6c, 0x448

	.globl gMonStillFrontPic_Mudkip
gMonStillFrontPic_Mudkip: @ 0x8CE20B4
	.incbin "baserom_jp.gba", 0xce20b4, 0x2b8

	.globl gMonPalette_Mudkip
gMonPalette_Mudkip: @ 0x8CE236C
	.incbin "baserom_jp.gba", 0xce236c, 0x28

	.globl gMonBackPic_Mudkip
gMonBackPic_Mudkip: @ 0x8CE2394
	.incbin "baserom_jp.gba", 0xce2394, 0x2e0

	.globl gMonShinyPalette_Mudkip
gMonShinyPalette_Mudkip: @ 0x8CE2674
	.incbin "baserom_jp.gba", 0xce2674, 0x448

	.globl gMonStillFrontPic_Marshtomp
gMonStillFrontPic_Marshtomp: @ 0x8CE2ABC
	.incbin "baserom_jp.gba", 0xce2abc, 0x660

	.globl gMonPalette_Marshtomp
gMonPalette_Marshtomp: @ 0x8CE311C
	.incbin "baserom_jp.gba", 0xce311c, 0x28

	.globl gMonBackPic_Marshtomp
gMonBackPic_Marshtomp: @ 0x8CE3144
	.incbin "baserom_jp.gba", 0xce3144, 0x3b0

	.globl gMonShinyPalette_Marshtomp
gMonShinyPalette_Marshtomp: @ 0x8CE34F4
	.incbin "baserom_jp.gba", 0xce34f4, 0x448

	.globl gMonStillFrontPic_Swampert
gMonStillFrontPic_Swampert: @ 0x8CE393C
	.incbin "baserom_jp.gba", 0xce393c, 0x57c

	.globl gMonPalette_Swampert
gMonPalette_Swampert: @ 0x8CE3EB8
	.incbin "baserom_jp.gba", 0xce3eb8, 0x28

	.globl gMonBackPic_Swampert
gMonBackPic_Swampert: @ 0x8CE3EE0
	.incbin "baserom_jp.gba", 0xce3ee0, 0x3b4

	.globl gMonShinyPalette_Swampert
gMonShinyPalette_Swampert: @ 0x8CE4294
	.incbin "baserom_jp.gba", 0xce4294, 0x448

	.globl gMonStillFrontPic_Poochyena
gMonStillFrontPic_Poochyena: @ 0x8CE46DC
	.incbin "baserom_jp.gba", 0xce46dc, 0x5a4

	.globl gMonPalette_Poochyena
gMonPalette_Poochyena: @ 0x8CE4C80
	.incbin "baserom_jp.gba", 0xce4c80, 0x28

	.globl gMonBackPic_Poochyena
gMonBackPic_Poochyena: @ 0x8CE4CA8
	.incbin "baserom_jp.gba", 0xce4ca8, 0x32c

	.globl gMonShinyPalette_Poochyena
gMonShinyPalette_Poochyena: @ 0x8CE4FD4
	.incbin "baserom_jp.gba", 0xce4fd4, 0x448

	.globl gMonStillFrontPic_Mightyena
gMonStillFrontPic_Mightyena: @ 0x8CE541C
	.incbin "baserom_jp.gba", 0xce541c, 0x438

	.globl gMonPalette_Mightyena
gMonPalette_Mightyena: @ 0x8CE5854
	.incbin "baserom_jp.gba", 0xce5854, 0x28

	.globl gMonBackPic_Mightyena
gMonBackPic_Mightyena: @ 0x8CE587C
	.incbin "baserom_jp.gba", 0xce587c, 0x378

	.globl gMonShinyPalette_Mightyena
gMonShinyPalette_Mightyena: @ 0x8CE5BF4
	.incbin "baserom_jp.gba", 0xce5bf4, 0x448

	.globl gMonStillFrontPic_Zigzagoon
gMonStillFrontPic_Zigzagoon: @ 0x8CE603C
	.incbin "baserom_jp.gba", 0xce603c, 0x3d0

	.globl gMonPalette_Zigzagoon
gMonPalette_Zigzagoon: @ 0x8CE640C
	.incbin "baserom_jp.gba", 0xce640c, 0x28

	.globl gMonBackPic_Zigzagoon
gMonBackPic_Zigzagoon: @ 0x8CE6434
	.incbin "baserom_jp.gba", 0xce6434, 0x340

	.globl gMonShinyPalette_Zigzagoon
gMonShinyPalette_Zigzagoon: @ 0x8CE6774
	.incbin "baserom_jp.gba", 0xce6774, 0x448

	.globl gMonStillFrontPic_Linoone
gMonStillFrontPic_Linoone: @ 0x8CE6BBC
	.incbin "baserom_jp.gba", 0xce6bbc, 0x370

	.globl gMonPalette_Linoone
gMonPalette_Linoone: @ 0x8CE6F2C
	.incbin "baserom_jp.gba", 0xce6f2c, 0x28

	.globl gMonBackPic_Linoone
gMonBackPic_Linoone: @ 0x8CE6F54
	.incbin "baserom_jp.gba", 0xce6f54, 0x2d4

	.globl gMonShinyPalette_Linoone
gMonShinyPalette_Linoone: @ 0x8CE7228
	.incbin "baserom_jp.gba", 0xce7228, 0x448

	.globl gMonStillFrontPic_Wurmple
gMonStillFrontPic_Wurmple: @ 0x8CE7670
	.incbin "baserom_jp.gba", 0xce7670, 0x288

	.globl gMonPalette_Wurmple
gMonPalette_Wurmple: @ 0x8CE78F8
	.incbin "baserom_jp.gba", 0xce78f8, 0x28

	.globl gMonBackPic_Wurmple
gMonBackPic_Wurmple: @ 0x8CE7920
	.incbin "baserom_jp.gba", 0xce7920, 0x24c

	.globl gMonShinyPalette_Wurmple
gMonShinyPalette_Wurmple: @ 0x8CE7B6C
	.incbin "baserom_jp.gba", 0xce7b6c, 0x448

	.globl gMonStillFrontPic_Silcoon
gMonStillFrontPic_Silcoon: @ 0x8CE7FB4
	.incbin "baserom_jp.gba", 0xce7fb4, 0x280

	.globl gMonPalette_Silcoon
gMonPalette_Silcoon: @ 0x8CE8234
	.incbin "baserom_jp.gba", 0xce8234, 0x28

	.globl gMonBackPic_Silcoon
gMonBackPic_Silcoon: @ 0x8CE825C
	.incbin "baserom_jp.gba", 0xce825c, 0x21c

	.globl gMonShinyPalette_Silcoon
gMonShinyPalette_Silcoon: @ 0x8CE8478
	.incbin "baserom_jp.gba", 0xce8478, 0x448

	.globl gMonStillFrontPic_Beautifly
gMonStillFrontPic_Beautifly: @ 0x8CE88C0
	.incbin "baserom_jp.gba", 0xce88c0, 0x358

	.globl gMonPalette_Beautifly
gMonPalette_Beautifly: @ 0x8CE8C18
	.incbin "baserom_jp.gba", 0xce8c18, 0x28

	.globl gMonBackPic_Beautifly
gMonBackPic_Beautifly: @ 0x8CE8C40
	.incbin "baserom_jp.gba", 0xce8c40, 0x3b0

	.globl gMonShinyPalette_Beautifly
gMonShinyPalette_Beautifly: @ 0x8CE8FF0
	.incbin "baserom_jp.gba", 0xce8ff0, 0x448

	.globl gMonStillFrontPic_Cascoon
gMonStillFrontPic_Cascoon: @ 0x8CE9438
	.incbin "baserom_jp.gba", 0xce9438, 0x26c

	.globl gMonPalette_Cascoon
gMonPalette_Cascoon: @ 0x8CE96A4
	.incbin "baserom_jp.gba", 0xce96a4, 0x28

	.globl gMonBackPic_Cascoon
gMonBackPic_Cascoon: @ 0x8CE96CC
	.incbin "baserom_jp.gba", 0xce96cc, 0x210

	.globl gMonShinyPalette_Cascoon
gMonShinyPalette_Cascoon: @ 0x8CE98DC
	.incbin "baserom_jp.gba", 0xce98dc, 0x448

	.globl gMonStillFrontPic_Dustox
gMonStillFrontPic_Dustox: @ 0x8CE9D24
	.incbin "baserom_jp.gba", 0xce9d24, 0x368

	.globl gMonPalette_Dustox
gMonPalette_Dustox: @ 0x8CEA08C
	.incbin "baserom_jp.gba", 0xcea08c, 0x28

	.globl gMonBackPic_Dustox
gMonBackPic_Dustox: @ 0x8CEA0B4
	.incbin "baserom_jp.gba", 0xcea0b4, 0x258

	.globl gMonShinyPalette_Dustox
gMonShinyPalette_Dustox: @ 0x8CEA30C
	.incbin "baserom_jp.gba", 0xcea30c, 0x448

	.globl gMonStillFrontPic_Lotad
gMonStillFrontPic_Lotad: @ 0x8CEA754
	.incbin "baserom_jp.gba", 0xcea754, 0x260

	.globl gMonPalette_Lotad
gMonPalette_Lotad: @ 0x8CEA9B4
	.incbin "baserom_jp.gba", 0xcea9b4, 0x28

	.globl gMonBackPic_Lotad
gMonBackPic_Lotad: @ 0x8CEA9DC
	.incbin "baserom_jp.gba", 0xcea9dc, 0x2e8

	.globl gMonShinyPalette_Lotad
gMonShinyPalette_Lotad: @ 0x8CEACC4
	.incbin "baserom_jp.gba", 0xceacc4, 0x448

	.globl gMonStillFrontPic_Lombre
gMonStillFrontPic_Lombre: @ 0x8CEB10C
	.incbin "baserom_jp.gba", 0xceb10c, 0x318

	.globl gMonPalette_Lombre
gMonPalette_Lombre: @ 0x8CEB424
	.incbin "baserom_jp.gba", 0xceb424, 0x28

	.globl gMonBackPic_Lombre
gMonBackPic_Lombre: @ 0x8CEB44C
	.incbin "baserom_jp.gba", 0xceb44c, 0x2fc

	.globl gMonShinyPalette_Lombre
gMonShinyPalette_Lombre: @ 0x8CEB748
	.incbin "baserom_jp.gba", 0xceb748, 0x448

	.globl gMonStillFrontPic_Ludicolo
gMonStillFrontPic_Ludicolo: @ 0x8CEBB90
	.incbin "baserom_jp.gba", 0xcebb90, 0x4e4

	.globl gMonPalette_Ludicolo
gMonPalette_Ludicolo: @ 0x8CEC074
	.incbin "baserom_jp.gba", 0xcec074, 0x28

	.globl gMonBackPic_Ludicolo
gMonBackPic_Ludicolo: @ 0x8CEC09C
	.incbin "baserom_jp.gba", 0xcec09c, 0x2fc

	.globl gMonShinyPalette_Ludicolo
gMonShinyPalette_Ludicolo: @ 0x8CEC398
	.incbin "baserom_jp.gba", 0xcec398, 0x448

	.globl gMonStillFrontPic_Seedot
gMonStillFrontPic_Seedot: @ 0x8CEC7E0
	.incbin "baserom_jp.gba", 0xcec7e0, 0x294

	.globl gMonPalette_Seedot
gMonPalette_Seedot: @ 0x8CECA74
	.incbin "baserom_jp.gba", 0xceca74, 0x28

	.globl gMonBackPic_Seedot
gMonBackPic_Seedot: @ 0x8CECA9C
	.incbin "baserom_jp.gba", 0xceca9c, 0x2e0

	.globl gMonShinyPalette_Seedot
gMonShinyPalette_Seedot: @ 0x8CECD7C
	.incbin "baserom_jp.gba", 0xcecd7c, 0x448

	.globl gMonStillFrontPic_Nuzleaf
gMonStillFrontPic_Nuzleaf: @ 0x8CED1C4
	.incbin "baserom_jp.gba", 0xced1c4, 0x2ec

	.globl gMonPalette_Nuzleaf
gMonPalette_Nuzleaf: @ 0x8CED4B0
	.incbin "baserom_jp.gba", 0xced4b0, 0x28

	.globl gMonBackPic_Nuzleaf
gMonBackPic_Nuzleaf: @ 0x8CED4D8
	.incbin "baserom_jp.gba", 0xced4d8, 0x2c8

	.globl gMonShinyPalette_Nuzleaf
gMonShinyPalette_Nuzleaf: @ 0x8CED7A0
	.incbin "baserom_jp.gba", 0xced7a0, 0x448

	.globl gMonStillFrontPic_Shiftry
gMonStillFrontPic_Shiftry: @ 0x8CEDBE8
	.incbin "baserom_jp.gba", 0xcedbe8, 0x4bc

	.globl gMonPalette_Shiftry
gMonPalette_Shiftry: @ 0x8CEE0A4
	.incbin "baserom_jp.gba", 0xcee0a4, 0x28

	.globl gMonBackPic_Shiftry
gMonBackPic_Shiftry: @ 0x8CEE0CC
	.incbin "baserom_jp.gba", 0xcee0cc, 0x2c4

	.globl gMonShinyPalette_Shiftry
gMonShinyPalette_Shiftry: @ 0x8CEE390
	.incbin "baserom_jp.gba", 0xcee390, 0x448

	.globl gMonStillFrontPic_Nincada
gMonStillFrontPic_Nincada: @ 0x8CEE7D8
	.incbin "baserom_jp.gba", 0xcee7d8, 0x2a0

	.globl gMonPalette_Nincada
gMonPalette_Nincada: @ 0x8CEEA78
	.incbin "baserom_jp.gba", 0xceea78, 0x28

	.globl gMonBackPic_Nincada
gMonBackPic_Nincada: @ 0x8CEEAA0
	.incbin "baserom_jp.gba", 0xceeaa0, 0x2b8

	.globl gMonShinyPalette_Nincada
gMonShinyPalette_Nincada: @ 0x8CEED58
	.incbin "baserom_jp.gba", 0xceed58, 0x448

	.globl gMonStillFrontPic_Ninjask
gMonStillFrontPic_Ninjask: @ 0x8CEF1A0
	.incbin "baserom_jp.gba", 0xcef1a0, 0x370

	.globl gMonPalette_Ninjask
gMonPalette_Ninjask: @ 0x8CEF510
	.incbin "baserom_jp.gba", 0xcef510, 0x28

	.globl gMonBackPic_Ninjask
gMonBackPic_Ninjask: @ 0x8CEF538
	.incbin "baserom_jp.gba", 0xcef538, 0x3cc

	.globl gMonShinyPalette_Ninjask
gMonShinyPalette_Ninjask: @ 0x8CEF904
	.incbin "baserom_jp.gba", 0xcef904, 0x448

	.globl gMonStillFrontPic_Shedinja
gMonStillFrontPic_Shedinja: @ 0x8CEFD4C
	.incbin "baserom_jp.gba", 0xcefd4c, 0x320

	.globl gMonPalette_Shedinja
gMonPalette_Shedinja: @ 0x8CF006C
	.incbin "baserom_jp.gba", 0xcf006c, 0x28

	.globl gMonBackPic_Shedinja
gMonBackPic_Shedinja: @ 0x8CF0094
	.incbin "baserom_jp.gba", 0xcf0094, 0x3a0

	.globl gMonShinyPalette_Shedinja
gMonShinyPalette_Shedinja: @ 0x8CF0434
	.incbin "baserom_jp.gba", 0xcf0434, 0x448

	.globl gMonStillFrontPic_Taillow
gMonStillFrontPic_Taillow: @ 0x8CF087C
	.incbin "baserom_jp.gba", 0xcf087c, 0x258

	.globl gMonPalette_Taillow
gMonPalette_Taillow: @ 0x8CF0AD4
	.incbin "baserom_jp.gba", 0xcf0ad4, 0x28

	.globl gMonBackPic_Taillow
gMonBackPic_Taillow: @ 0x8CF0AFC
	.incbin "baserom_jp.gba", 0xcf0afc, 0x220

	.globl gMonShinyPalette_Taillow
gMonShinyPalette_Taillow: @ 0x8CF0D1C
	.incbin "baserom_jp.gba", 0xcf0d1c, 0x448

	.globl gMonStillFrontPic_Swellow
gMonStillFrontPic_Swellow: @ 0x8CF1164
	.incbin "baserom_jp.gba", 0xcf1164, 0x3c4

	.globl gMonPalette_Swellow
gMonPalette_Swellow: @ 0x8CF1528
	.incbin "baserom_jp.gba", 0xcf1528, 0x28

	.globl gMonBackPic_Swellow
gMonBackPic_Swellow: @ 0x8CF1550
	.incbin "baserom_jp.gba", 0xcf1550, 0x338

	.globl gMonShinyPalette_Swellow
gMonShinyPalette_Swellow: @ 0x8CF1888
	.incbin "baserom_jp.gba", 0xcf1888, 0x448

	.globl gMonStillFrontPic_Shroomish
gMonStillFrontPic_Shroomish: @ 0x8CF1CD0
	.incbin "baserom_jp.gba", 0xcf1cd0, 0x268

	.globl gMonPalette_Shroomish
gMonPalette_Shroomish: @ 0x8CF1F38
	.incbin "baserom_jp.gba", 0xcf1f38, 0x28

	.globl gMonBackPic_Shroomish
gMonBackPic_Shroomish: @ 0x8CF1F60
	.incbin "baserom_jp.gba", 0xcf1f60, 0x2e0

	.globl gMonShinyPalette_Shroomish
gMonShinyPalette_Shroomish: @ 0x8CF2240
	.incbin "baserom_jp.gba", 0xcf2240, 0x448

	.globl gMonStillFrontPic_Breloom
gMonStillFrontPic_Breloom: @ 0x8CF2688
	.incbin "baserom_jp.gba", 0xcf2688, 0x3e8

	.globl gMonPalette_Breloom
gMonPalette_Breloom: @ 0x8CF2A70
	.incbin "baserom_jp.gba", 0xcf2a70, 0x28

	.globl gMonBackPic_Breloom
gMonBackPic_Breloom: @ 0x8CF2A98
	.incbin "baserom_jp.gba", 0xcf2a98, 0x3e0

	.globl gMonShinyPalette_Breloom
gMonShinyPalette_Breloom: @ 0x8CF2E78
	.incbin "baserom_jp.gba", 0xcf2e78, 0x448

	.globl gMonStillFrontPic_Spinda
gMonStillFrontPic_Spinda: @ 0x8CF32C0
	.incbin "baserom_jp.gba", 0xcf32c0, 0x2f4

	.globl gMonPalette_Spinda
gMonPalette_Spinda: @ 0x8CF35B4
	.incbin "baserom_jp.gba", 0xcf35b4, 0x28

	.globl gMonBackPic_Spinda
gMonBackPic_Spinda: @ 0x8CF35DC
	.incbin "baserom_jp.gba", 0xcf35dc, 0x33c

	.globl gMonShinyPalette_Spinda
gMonShinyPalette_Spinda: @ 0x8CF3918
	.incbin "baserom_jp.gba", 0xcf3918, 0x448

	.globl gMonStillFrontPic_Wingull
gMonStillFrontPic_Wingull: @ 0x8CF3D60
	.incbin "baserom_jp.gba", 0xcf3d60, 0x23c

	.globl gMonPalette_Wingull
gMonPalette_Wingull: @ 0x8CF3F9C
	.incbin "baserom_jp.gba", 0xcf3f9c, 0x28

	.globl gMonBackPic_Wingull
gMonBackPic_Wingull: @ 0x8CF3FC4
	.incbin "baserom_jp.gba", 0xcf3fc4, 0x350

	.globl gMonShinyPalette_Wingull
gMonShinyPalette_Wingull: @ 0x8CF4314
	.incbin "baserom_jp.gba", 0xcf4314, 0x448

	.globl gMonStillFrontPic_Pelipper
gMonStillFrontPic_Pelipper: @ 0x8CF475C
	.incbin "baserom_jp.gba", 0xcf475c, 0x398

	.globl gMonPalette_Pelipper
gMonPalette_Pelipper: @ 0x8CF4AF4
	.incbin "baserom_jp.gba", 0xcf4af4, 0x28

	.globl gMonBackPic_Pelipper
gMonBackPic_Pelipper: @ 0x8CF4B1C
	.incbin "baserom_jp.gba", 0xcf4b1c, 0x380

	.globl gMonShinyPalette_Pelipper
gMonShinyPalette_Pelipper: @ 0x8CF4E9C
	.incbin "baserom_jp.gba", 0xcf4e9c, 0x448

	.globl gMonStillFrontPic_Surskit
gMonStillFrontPic_Surskit: @ 0x8CF52E4
	.incbin "baserom_jp.gba", 0xcf52e4, 0x20c

	.globl gMonPalette_Surskit
gMonPalette_Surskit: @ 0x8CF54F0
	.incbin "baserom_jp.gba", 0xcf54f0, 0x28

	.globl gMonBackPic_Surskit
gMonBackPic_Surskit: @ 0x8CF5518
	.incbin "baserom_jp.gba", 0xcf5518, 0x238

	.globl gMonShinyPalette_Surskit
gMonShinyPalette_Surskit: @ 0x8CF5750
	.incbin "baserom_jp.gba", 0xcf5750, 0x448

	.globl gMonStillFrontPic_Masquerain
gMonStillFrontPic_Masquerain: @ 0x8CF5B98
	.incbin "baserom_jp.gba", 0xcf5b98, 0x39c

	.globl gMonPalette_Masquerain
gMonPalette_Masquerain: @ 0x8CF5F34
	.incbin "baserom_jp.gba", 0xcf5f34, 0x28

	.globl gMonBackPic_Masquerain
gMonBackPic_Masquerain: @ 0x8CF5F5C
	.incbin "baserom_jp.gba", 0xcf5f5c, 0x358

	.globl gMonShinyPalette_Masquerain
gMonShinyPalette_Masquerain: @ 0x8CF62B4
	.incbin "baserom_jp.gba", 0xcf62b4, 0x448

	.globl gMonStillFrontPic_Wailmer
gMonStillFrontPic_Wailmer: @ 0x8CF66FC
	.incbin "baserom_jp.gba", 0xcf66fc, 0x2e0

	.globl gMonPalette_Wailmer
gMonPalette_Wailmer: @ 0x8CF69DC
	.incbin "baserom_jp.gba", 0xcf69dc, 0x28

	.globl gMonBackPic_Wailmer
gMonBackPic_Wailmer: @ 0x8CF6A04
	.incbin "baserom_jp.gba", 0xcf6a04, 0x1e4

	.globl gMonShinyPalette_Wailmer
gMonShinyPalette_Wailmer: @ 0x8CF6BE8
	.incbin "baserom_jp.gba", 0xcf6be8, 0x448

	.globl gMonStillFrontPic_Wailord
gMonStillFrontPic_Wailord: @ 0x8CF7030
	.incbin "baserom_jp.gba", 0xcf7030, 0x3c4

	.globl gMonPalette_Wailord
gMonPalette_Wailord: @ 0x8CF73F4
	.incbin "baserom_jp.gba", 0xcf73f4, 0x28

	.globl gMonBackPic_Wailord
gMonBackPic_Wailord: @ 0x8CF741C
	.incbin "baserom_jp.gba", 0xcf741c, 0x218

	.globl gMonShinyPalette_Wailord
gMonShinyPalette_Wailord: @ 0x8CF7634
	.incbin "baserom_jp.gba", 0xcf7634, 0x448

	.globl gMonStillFrontPic_Skitty
gMonStillFrontPic_Skitty: @ 0x8CF7A7C
	.incbin "baserom_jp.gba", 0xcf7a7c, 0x300

	.globl gMonPalette_Skitty
gMonPalette_Skitty: @ 0x8CF7D7C
	.incbin "baserom_jp.gba", 0xcf7d7c, 0x28

	.globl gMonBackPic_Skitty
gMonBackPic_Skitty: @ 0x8CF7DA4
	.incbin "baserom_jp.gba", 0xcf7da4, 0x348

	.globl gMonShinyPalette_Skitty
gMonShinyPalette_Skitty: @ 0x8CF80EC
	.incbin "baserom_jp.gba", 0xcf80ec, 0x448

	.globl gMonStillFrontPic_Delcatty
gMonStillFrontPic_Delcatty: @ 0x8CF8534
	.incbin "baserom_jp.gba", 0xcf8534, 0x38c

	.globl gMonPalette_Delcatty
gMonPalette_Delcatty: @ 0x8CF88C0
	.incbin "baserom_jp.gba", 0xcf88c0, 0x28

	.globl gMonBackPic_Delcatty
gMonBackPic_Delcatty: @ 0x8CF88E8
	.incbin "baserom_jp.gba", 0xcf88e8, 0x39c

	.globl gMonShinyPalette_Delcatty
gMonShinyPalette_Delcatty: @ 0x8CF8C84
	.incbin "baserom_jp.gba", 0xcf8c84, 0x448

	.globl gMonStillFrontPic_Kecleon
gMonStillFrontPic_Kecleon: @ 0x8CF90CC
	.incbin "baserom_jp.gba", 0xcf90cc, 0x380

	.globl gMonPalette_Kecleon
gMonPalette_Kecleon: @ 0x8CF944C
	.incbin "baserom_jp.gba", 0xcf944c, 0x28

	.globl gMonBackPic_Kecleon
gMonBackPic_Kecleon: @ 0x8CF9474
	.incbin "baserom_jp.gba", 0xcf9474, 0x3d8

	.globl gMonShinyPalette_Kecleon
gMonShinyPalette_Kecleon: @ 0x8CF984C
	.incbin "baserom_jp.gba", 0xcf984c, 0x448

	.globl gMonStillFrontPic_Baltoy
gMonStillFrontPic_Baltoy: @ 0x8CF9C94
	.incbin "baserom_jp.gba", 0xcf9c94, 0x224

	.globl gMonPalette_Baltoy
gMonPalette_Baltoy: @ 0x8CF9EB8
	.incbin "baserom_jp.gba", 0xcf9eb8, 0x20

	.globl gMonBackPic_Baltoy
gMonBackPic_Baltoy: @ 0x8CF9ED8
	.incbin "baserom_jp.gba", 0xcf9ed8, 0x2a8

	.globl gMonShinyPalette_Baltoy
gMonShinyPalette_Baltoy: @ 0x8CFA180
	.incbin "baserom_jp.gba", 0xcfa180, 0x440

	.globl gMonStillFrontPic_Claydol
gMonStillFrontPic_Claydol: @ 0x8CFA5C0
	.incbin "baserom_jp.gba", 0xcfa5c0, 0x3b8

	.globl gMonPalette_Claydol
gMonPalette_Claydol: @ 0x8CFA978
	.incbin "baserom_jp.gba", 0xcfa978, 0x28

	.globl gMonBackPic_Claydol
gMonBackPic_Claydol: @ 0x8CFA9A0
	.incbin "baserom_jp.gba", 0xcfa9a0, 0x3d4

	.globl gMonShinyPalette_Claydol
gMonShinyPalette_Claydol: @ 0x8CFAD74
	.incbin "baserom_jp.gba", 0xcfad74, 0x448

	.globl gMonStillFrontPic_Nosepass
gMonStillFrontPic_Nosepass: @ 0x8CFB1BC
	.incbin "baserom_jp.gba", 0xcfb1bc, 0x2cc

	.globl gMonPalette_Nosepass
gMonPalette_Nosepass: @ 0x8CFB488
	.incbin "baserom_jp.gba", 0xcfb488, 0x28

	.globl gMonBackPic_Nosepass
gMonBackPic_Nosepass: @ 0x8CFB4B0
	.incbin "baserom_jp.gba", 0xcfb4b0, 0x2a0

	.globl gMonShinyPalette_Nosepass
gMonShinyPalette_Nosepass: @ 0x8CFB750
	.incbin "baserom_jp.gba", 0xcfb750, 0x448

	.globl gMonStillFrontPic_Torkoal
gMonStillFrontPic_Torkoal: @ 0x8CFBB98
	.incbin "baserom_jp.gba", 0xcfbb98, 0x4ac

	.globl gMonPalette_Torkoal
gMonPalette_Torkoal: @ 0x8CFC044
	.incbin "baserom_jp.gba", 0xcfc044, 0x28

	.globl gMonBackPic_Torkoal
gMonBackPic_Torkoal: @ 0x8CFC06C
	.incbin "baserom_jp.gba", 0xcfc06c, 0x2c8

	.globl gMonShinyPalette_Torkoal
gMonShinyPalette_Torkoal: @ 0x8CFC334
	.incbin "baserom_jp.gba", 0xcfc334, 0x448

	.globl gMonStillFrontPic_Sableye
gMonStillFrontPic_Sableye: @ 0x8CFC77C
	.incbin "baserom_jp.gba", 0xcfc77c, 0x2d4

	.globl gMonPalette_Sableye
gMonPalette_Sableye: @ 0x8CFCA50
	.incbin "baserom_jp.gba", 0xcfca50, 0x28

	.globl gMonBackPic_Sableye
gMonBackPic_Sableye: @ 0x8CFCA78
	.incbin "baserom_jp.gba", 0xcfca78, 0x328

	.globl gMonShinyPalette_Sableye
gMonShinyPalette_Sableye: @ 0x8CFCDA0
	.incbin "baserom_jp.gba", 0xcfcda0, 0x448

	.globl gMonStillFrontPic_Barboach
gMonStillFrontPic_Barboach: @ 0x8CFD1E8
	.incbin "baserom_jp.gba", 0xcfd1e8, 0x290

	.globl gMonPalette_Barboach
gMonPalette_Barboach: @ 0x8CFD478
	.incbin "baserom_jp.gba", 0xcfd478, 0x28

	.globl gMonBackPic_Barboach
gMonBackPic_Barboach: @ 0x8CFD4A0
	.incbin "baserom_jp.gba", 0xcfd4a0, 0x290

	.globl gMonShinyPalette_Barboach
gMonShinyPalette_Barboach: @ 0x8CFD730
	.incbin "baserom_jp.gba", 0xcfd730, 0x448

	.globl gMonStillFrontPic_Whiscash
gMonStillFrontPic_Whiscash: @ 0x8CFDB78
	.incbin "baserom_jp.gba", 0xcfdb78, 0x378

	.globl gMonPalette_Whiscash
gMonPalette_Whiscash: @ 0x8CFDEF0
	.incbin "baserom_jp.gba", 0xcfdef0, 0x28

	.globl gMonBackPic_Whiscash
gMonBackPic_Whiscash: @ 0x8CFDF18
	.incbin "baserom_jp.gba", 0xcfdf18, 0x34c

	.globl gMonShinyPalette_Whiscash
gMonShinyPalette_Whiscash: @ 0x8CFE264
	.incbin "baserom_jp.gba", 0xcfe264, 0x448

	.globl gMonStillFrontPic_Luvdisc
gMonStillFrontPic_Luvdisc: @ 0x8CFE6AC
	.incbin "baserom_jp.gba", 0xcfe6ac, 0x1c0

	.globl gMonPalette_Luvdisc
gMonPalette_Luvdisc: @ 0x8CFE86C
	.incbin "baserom_jp.gba", 0xcfe86c, 0x24

	.globl gMonBackPic_Luvdisc
gMonBackPic_Luvdisc: @ 0x8CFE890
	.incbin "baserom_jp.gba", 0xcfe890, 0x1d4

	.globl gMonShinyPalette_Luvdisc
gMonShinyPalette_Luvdisc: @ 0x8CFEA64
	.incbin "baserom_jp.gba", 0xcfea64, 0x444

	.globl gMonStillFrontPic_Corphish
gMonStillFrontPic_Corphish: @ 0x8CFEEA8
	.incbin "baserom_jp.gba", 0xcfeea8, 0x35c

	.globl gMonPalette_Corphish
gMonPalette_Corphish: @ 0x8CFF204
	.incbin "baserom_jp.gba", 0xcff204, 0x28

	.globl gMonBackPic_Corphish
gMonBackPic_Corphish: @ 0x8CFF22C
	.incbin "baserom_jp.gba", 0xcff22c, 0x31c

	.globl gMonShinyPalette_Corphish
gMonShinyPalette_Corphish: @ 0x8CFF548
	.incbin "baserom_jp.gba", 0xcff548, 0x448

	.globl gMonStillFrontPic_Crawdaunt
gMonStillFrontPic_Crawdaunt: @ 0x8CFF990
	.incbin "baserom_jp.gba", 0xcff990, 0x490

	.globl gMonPalette_Crawdaunt
gMonPalette_Crawdaunt: @ 0x8CFFE20
	.incbin "baserom_jp.gba", 0xcffe20, 0x28

	.globl gMonBackPic_Crawdaunt
gMonBackPic_Crawdaunt: @ 0x8CFFE48
	.incbin "baserom_jp.gba", 0xcffe48, 0x3e4

	.globl gMonShinyPalette_Crawdaunt
gMonShinyPalette_Crawdaunt: @ 0x8D0022C
	.incbin "baserom_jp.gba", 0xd0022c, 0x448

	.globl gMonStillFrontPic_Feebas
gMonStillFrontPic_Feebas: @ 0x8D00674
	.incbin "baserom_jp.gba", 0xd00674, 0x28c

	.globl gMonPalette_Feebas
gMonPalette_Feebas: @ 0x8D00900
	.incbin "baserom_jp.gba", 0xd00900, 0x28

	.globl gMonBackPic_Feebas
gMonBackPic_Feebas: @ 0x8D00928
	.incbin "baserom_jp.gba", 0xd00928, 0x338

	.globl gMonShinyPalette_Feebas
gMonShinyPalette_Feebas: @ 0x8D00C60
	.incbin "baserom_jp.gba", 0xd00c60, 0x448

	.globl gMonStillFrontPic_Milotic
gMonStillFrontPic_Milotic: @ 0x8D010A8
	.incbin "baserom_jp.gba", 0xd010a8, 0x490

	.globl gMonPalette_Milotic
gMonPalette_Milotic: @ 0x8D01538
	.incbin "baserom_jp.gba", 0xd01538, 0x28

	.globl gMonBackPic_Milotic
gMonBackPic_Milotic: @ 0x8D01560
	.incbin "baserom_jp.gba", 0xd01560, 0x2f4

	.globl gMonShinyPalette_Milotic
gMonShinyPalette_Milotic: @ 0x8D01854
	.incbin "baserom_jp.gba", 0xd01854, 0x448

	.globl gMonStillFrontPic_Carvanha
gMonStillFrontPic_Carvanha: @ 0x8D01C9C
	.incbin "baserom_jp.gba", 0xd01c9c, 0x32c

	.globl gMonPalette_Carvanha
gMonPalette_Carvanha: @ 0x8D01FC8
	.incbin "baserom_jp.gba", 0xd01fc8, 0x28

	.globl gMonBackPic_Carvanha
gMonBackPic_Carvanha: @ 0x8D01FF0
	.incbin "baserom_jp.gba", 0xd01ff0, 0x310

	.globl gMonShinyPalette_Carvanha
gMonShinyPalette_Carvanha: @ 0x8D02300
	.incbin "baserom_jp.gba", 0xd02300, 0x448

	.globl gMonStillFrontPic_Sharpedo
gMonStillFrontPic_Sharpedo: @ 0x8D02748
	.incbin "baserom_jp.gba", 0xd02748, 0x390

	.globl gMonPalette_Sharpedo
gMonPalette_Sharpedo: @ 0x8D02AD8
	.incbin "baserom_jp.gba", 0xd02ad8, 0x28

	.globl gMonBackPic_Sharpedo
gMonBackPic_Sharpedo: @ 0x8D02B00
	.incbin "baserom_jp.gba", 0xd02b00, 0x358

	.globl gMonShinyPalette_Sharpedo
gMonShinyPalette_Sharpedo: @ 0x8D02E58
	.incbin "baserom_jp.gba", 0xd02e58, 0x448

	.globl gMonStillFrontPic_Trapinch
gMonStillFrontPic_Trapinch: @ 0x8D032A0
	.incbin "baserom_jp.gba", 0xd032a0, 0x21c

	.globl gMonPalette_Trapinch
gMonPalette_Trapinch: @ 0x8D034BC
	.incbin "baserom_jp.gba", 0xd034bc, 0x28

	.globl gMonBackPic_Trapinch
gMonBackPic_Trapinch: @ 0x8D034E4
	.incbin "baserom_jp.gba", 0xd034e4, 0x220

	.globl gMonShinyPalette_Trapinch
gMonShinyPalette_Trapinch: @ 0x8D03704
	.incbin "baserom_jp.gba", 0xd03704, 0x448

	.globl gMonStillFrontPic_Vibrava
gMonStillFrontPic_Vibrava: @ 0x8D03B4C
	.incbin "baserom_jp.gba", 0xd03b4c, 0x370

	.globl gMonPalette_Vibrava
gMonPalette_Vibrava: @ 0x8D03EBC
	.incbin "baserom_jp.gba", 0xd03ebc, 0x28

	.globl gMonBackPic_Vibrava
gMonBackPic_Vibrava: @ 0x8D03EE4
	.incbin "baserom_jp.gba", 0xd03ee4, 0x278

	.globl gMonShinyPalette_Vibrava
gMonShinyPalette_Vibrava: @ 0x8D0415C
	.incbin "baserom_jp.gba", 0xd0415c, 0x448

	.globl gMonStillFrontPic_Flygon
gMonStillFrontPic_Flygon: @ 0x8D045A4
	.incbin "baserom_jp.gba", 0xd045a4, 0x4f0

	.globl gMonPalette_Flygon
gMonPalette_Flygon: @ 0x8D04A94
	.incbin "baserom_jp.gba", 0xd04a94, 0x28

	.globl gMonBackPic_Flygon
gMonBackPic_Flygon: @ 0x8D04ABC
	.incbin "baserom_jp.gba", 0xd04abc, 0x43c

	.globl gMonShinyPalette_Flygon
gMonShinyPalette_Flygon: @ 0x8D04EF8
	.incbin "baserom_jp.gba", 0xd04ef8, 0x448

	.globl gMonStillFrontPic_Makuhita
gMonStillFrontPic_Makuhita: @ 0x8D05340
	.incbin "baserom_jp.gba", 0xd05340, 0x318

	.globl gMonPalette_Makuhita
gMonPalette_Makuhita: @ 0x8D05658
	.incbin "baserom_jp.gba", 0xd05658, 0x28

	.globl gMonBackPic_Makuhita
gMonBackPic_Makuhita: @ 0x8D05680
	.incbin "baserom_jp.gba", 0xd05680, 0x2f0

	.globl gMonShinyPalette_Makuhita
gMonShinyPalette_Makuhita: @ 0x8D05970
	.incbin "baserom_jp.gba", 0xd05970, 0x444

	.globl gMonStillFrontPic_Hariyama
gMonStillFrontPic_Hariyama: @ 0x8D05DB4
	.incbin "baserom_jp.gba", 0xd05db4, 0x4b0

	.globl gMonPalette_Hariyama
gMonPalette_Hariyama: @ 0x8D06264
	.incbin "baserom_jp.gba", 0xd06264, 0x28

	.globl gMonBackPic_Hariyama
gMonBackPic_Hariyama: @ 0x8D0628C
	.incbin "baserom_jp.gba", 0xd0628c, 0x3e0

	.globl gMonShinyPalette_Hariyama
gMonShinyPalette_Hariyama: @ 0x8D0666C
	.incbin "baserom_jp.gba", 0xd0666c, 0x448

	.globl gMonStillFrontPic_Electrike
gMonStillFrontPic_Electrike: @ 0x8D06AB4
	.incbin "baserom_jp.gba", 0xd06ab4, 0x290

	.globl gMonPalette_Electrike
gMonPalette_Electrike: @ 0x8D06D44
	.incbin "baserom_jp.gba", 0xd06d44, 0x28

	.globl gMonBackPic_Electrike
gMonBackPic_Electrike: @ 0x8D06D6C
	.incbin "baserom_jp.gba", 0xd06d6c, 0x28c

	.globl gMonShinyPalette_Electrike
gMonShinyPalette_Electrike: @ 0x8D06FF8
	.incbin "baserom_jp.gba", 0xd06ff8, 0x448

	.globl gMonStillFrontPic_Manectric
gMonStillFrontPic_Manectric: @ 0x8D07440
	.incbin "baserom_jp.gba", 0xd07440, 0x330

	.globl gMonPalette_Manectric
gMonPalette_Manectric: @ 0x8D07770
	.incbin "baserom_jp.gba", 0xd07770, 0x28

	.globl gMonBackPic_Manectric
gMonBackPic_Manectric: @ 0x8D07798
	.incbin "baserom_jp.gba", 0xd07798, 0x22c

	.globl gMonShinyPalette_Manectric
gMonShinyPalette_Manectric: @ 0x8D079C4
	.incbin "baserom_jp.gba", 0xd079c4, 0x448

	.globl gMonStillFrontPic_Numel
gMonStillFrontPic_Numel: @ 0x8D07E0C
	.incbin "baserom_jp.gba", 0xd07e0c, 0x2d0

	.globl gMonPalette_Numel
gMonPalette_Numel: @ 0x8D080DC
	.incbin "baserom_jp.gba", 0xd080dc, 0x28

	.globl gMonBackPic_Numel
gMonBackPic_Numel: @ 0x8D08104
	.incbin "baserom_jp.gba", 0xd08104, 0x2bc

	.globl gMonShinyPalette_Numel
gMonShinyPalette_Numel: @ 0x8D083C0
	.incbin "baserom_jp.gba", 0xd083c0, 0x448

	.globl gMonStillFrontPic_Camerupt
gMonStillFrontPic_Camerupt: @ 0x8D08808
	.incbin "baserom_jp.gba", 0xd08808, 0x418

	.globl gMonPalette_Camerupt
gMonPalette_Camerupt: @ 0x8D08C20
	.incbin "baserom_jp.gba", 0xd08c20, 0x28

	.globl gMonBackPic_Camerupt
gMonBackPic_Camerupt: @ 0x8D08C48
	.incbin "baserom_jp.gba", 0xd08c48, 0x2c4

	.globl gMonShinyPalette_Camerupt
gMonShinyPalette_Camerupt: @ 0x8D08F0C
	.incbin "baserom_jp.gba", 0xd08f0c, 0x448

	.globl gMonStillFrontPic_Spheal
gMonStillFrontPic_Spheal: @ 0x8D09354
	.incbin "baserom_jp.gba", 0xd09354, 0x274

	.globl gMonPalette_Spheal
gMonPalette_Spheal: @ 0x8D095C8
	.incbin "baserom_jp.gba", 0xd095c8, 0x28

	.globl gMonBackPic_Spheal
gMonBackPic_Spheal: @ 0x8D095F0
	.incbin "baserom_jp.gba", 0xd095f0, 0x1fc

	.globl gMonShinyPalette_Spheal
gMonShinyPalette_Spheal: @ 0x8D097EC
	.incbin "baserom_jp.gba", 0xd097ec, 0x448

	.globl gMonStillFrontPic_Sealeo
gMonStillFrontPic_Sealeo: @ 0x8D09C34
	.incbin "baserom_jp.gba", 0xd09c34, 0x380

	.globl gMonPalette_Sealeo
gMonPalette_Sealeo: @ 0x8D09FB4
	.incbin "baserom_jp.gba", 0xd09fb4, 0x28

	.globl gMonBackPic_Sealeo
gMonBackPic_Sealeo: @ 0x8D09FDC
	.incbin "baserom_jp.gba", 0xd09fdc, 0x27c

	.globl gMonShinyPalette_Sealeo
gMonShinyPalette_Sealeo: @ 0x8D0A258
	.incbin "baserom_jp.gba", 0xd0a258, 0x448

	.globl gMonStillFrontPic_Walrein
gMonStillFrontPic_Walrein: @ 0x8D0A6A0
	.incbin "baserom_jp.gba", 0xd0a6a0, 0x774

	.globl gMonPalette_Walrein
gMonPalette_Walrein: @ 0x8D0AE14
	.incbin "baserom_jp.gba", 0xd0ae14, 0x28

	.globl gMonBackPic_Walrein
gMonBackPic_Walrein: @ 0x8D0AE3C
	.incbin "baserom_jp.gba", 0xd0ae3c, 0x388

	.globl gMonShinyPalette_Walrein
gMonShinyPalette_Walrein: @ 0x8D0B1C4
	.incbin "baserom_jp.gba", 0xd0b1c4, 0x448

	.globl gMonStillFrontPic_Cacnea
gMonStillFrontPic_Cacnea: @ 0x8D0B60C
	.incbin "baserom_jp.gba", 0xd0b60c, 0x310

	.globl gMonPalette_Cacnea
gMonPalette_Cacnea: @ 0x8D0B91C
	.incbin "baserom_jp.gba", 0xd0b91c, 0x28

	.globl gMonBackPic_Cacnea
gMonBackPic_Cacnea: @ 0x8D0B944
	.incbin "baserom_jp.gba", 0xd0b944, 0x360

	.globl gMonShinyPalette_Cacnea
gMonShinyPalette_Cacnea: @ 0x8D0BCA4
	.incbin "baserom_jp.gba", 0xd0bca4, 0x448

	.globl gMonStillFrontPic_Cacturne
gMonStillFrontPic_Cacturne: @ 0x8D0C0EC
	.incbin "baserom_jp.gba", 0xd0c0ec, 0x438

	.globl gMonPalette_Cacturne
gMonPalette_Cacturne: @ 0x8D0C524
	.incbin "baserom_jp.gba", 0xd0c524, 0x28

	.globl gMonBackPic_Cacturne
gMonBackPic_Cacturne: @ 0x8D0C54C
	.incbin "baserom_jp.gba", 0xd0c54c, 0x300

	.globl gMonShinyPalette_Cacturne
gMonShinyPalette_Cacturne: @ 0x8D0C84C
	.incbin "baserom_jp.gba", 0xd0c84c, 0x448

	.globl gMonStillFrontPic_Snorunt
gMonStillFrontPic_Snorunt: @ 0x8D0CC94
	.incbin "baserom_jp.gba", 0xd0cc94, 0x2c4

	.globl gMonPalette_Snorunt
gMonPalette_Snorunt: @ 0x8D0CF58
	.incbin "baserom_jp.gba", 0xd0cf58, 0x28

	.globl gMonBackPic_Snorunt
gMonBackPic_Snorunt: @ 0x8D0CF80
	.incbin "baserom_jp.gba", 0xd0cf80, 0x2e4

	.globl gMonShinyPalette_Snorunt
gMonShinyPalette_Snorunt: @ 0x8D0D264
	.incbin "baserom_jp.gba", 0xd0d264, 0x448

	.globl gMonStillFrontPic_Glalie
gMonStillFrontPic_Glalie: @ 0x8D0D6AC
	.incbin "baserom_jp.gba", 0xd0d6ac, 0x3c8

	.globl gMonPalette_Glalie
gMonPalette_Glalie: @ 0x8D0DA74
	.incbin "baserom_jp.gba", 0xd0da74, 0x28

	.globl gMonBackPic_Glalie
gMonBackPic_Glalie: @ 0x8D0DA9C
	.incbin "baserom_jp.gba", 0xd0da9c, 0x3b0

	.globl gMonShinyPalette_Glalie
gMonShinyPalette_Glalie: @ 0x8D0DE4C
	.incbin "baserom_jp.gba", 0xd0de4c, 0x448

	.globl gMonStillFrontPic_Lunatone
gMonStillFrontPic_Lunatone: @ 0x8D0E294
	.incbin "baserom_jp.gba", 0xd0e294, 0x328

	.globl gMonPalette_Lunatone
gMonPalette_Lunatone: @ 0x8D0E5BC
	.incbin "baserom_jp.gba", 0xd0e5bc, 0x28

	.globl gMonBackPic_Lunatone
gMonBackPic_Lunatone: @ 0x8D0E5E4
	.incbin "baserom_jp.gba", 0xd0e5e4, 0x358

	.globl gMonShinyPalette_Lunatone
gMonShinyPalette_Lunatone: @ 0x8D0E93C
	.incbin "baserom_jp.gba", 0xd0e93c, 0x448

	.globl gMonStillFrontPic_Solrock
gMonStillFrontPic_Solrock: @ 0x8D0ED84
	.incbin "baserom_jp.gba", 0xd0ed84, 0x44c

	.globl gMonPalette_Solrock
gMonPalette_Solrock: @ 0x8D0F1D0
	.incbin "baserom_jp.gba", 0xd0f1d0, 0x28

	.globl gMonBackPic_Solrock
gMonBackPic_Solrock: @ 0x8D0F1F8
	.incbin "baserom_jp.gba", 0xd0f1f8, 0x3ec

	.globl gMonShinyPalette_Solrock
gMonShinyPalette_Solrock: @ 0x8D0F5E4
	.incbin "baserom_jp.gba", 0xd0f5e4, 0x448

	.globl gMonStillFrontPic_Azurill
gMonStillFrontPic_Azurill: @ 0x8D0FA2C
	.incbin "baserom_jp.gba", 0xd0fa2c, 0x2c8

	.globl gMonPalette_Azurill
gMonPalette_Azurill: @ 0x8D0FCF4
	.incbin "baserom_jp.gba", 0xd0fcf4, 0x28

	.globl gMonBackPic_Azurill
gMonBackPic_Azurill: @ 0x8D0FD1C
	.incbin "baserom_jp.gba", 0xd0fd1c, 0x318

	.globl gMonShinyPalette_Azurill
gMonShinyPalette_Azurill: @ 0x8D10034
	.incbin "baserom_jp.gba", 0xd10034, 0x448

	.globl gMonStillFrontPic_Spoink
gMonStillFrontPic_Spoink: @ 0x8D1047C
	.incbin "baserom_jp.gba", 0xd1047c, 0x26c

	.globl gMonPalette_Spoink
gMonPalette_Spoink: @ 0x8D106E8
	.incbin "baserom_jp.gba", 0xd106e8, 0x28

	.globl gMonBackPic_Spoink
gMonBackPic_Spoink: @ 0x8D10710
	.incbin "baserom_jp.gba", 0xd10710, 0x240

	.globl gMonShinyPalette_Spoink
gMonShinyPalette_Spoink: @ 0x8D10950
	.incbin "baserom_jp.gba", 0xd10950, 0x448

	.globl gMonStillFrontPic_Grumpig
gMonStillFrontPic_Grumpig: @ 0x8D10D98
	.incbin "baserom_jp.gba", 0xd10d98, 0x3bc

	.globl gMonPalette_Grumpig
gMonPalette_Grumpig: @ 0x8D11154
	.incbin "baserom_jp.gba", 0xd11154, 0x28

	.globl gMonBackPic_Grumpig
gMonBackPic_Grumpig: @ 0x8D1117C
	.incbin "baserom_jp.gba", 0xd1117c, 0x360

	.globl gMonShinyPalette_Grumpig
gMonShinyPalette_Grumpig: @ 0x8D114DC
	.incbin "baserom_jp.gba", 0xd114dc, 0x448

	.globl gMonStillFrontPic_Plusle
gMonStillFrontPic_Plusle: @ 0x8D11924
	.incbin "baserom_jp.gba", 0xd11924, 0x28c

	.globl gMonPalette_Plusle
gMonPalette_Plusle: @ 0x8D11BB0
	.incbin "baserom_jp.gba", 0xd11bb0, 0x28

	.globl gMonBackPic_Plusle
gMonBackPic_Plusle: @ 0x8D11BD8
	.incbin "baserom_jp.gba", 0xd11bd8, 0x2b8

	.globl gMonShinyPalette_Plusle
gMonShinyPalette_Plusle: @ 0x8D11E90
	.incbin "baserom_jp.gba", 0xd11e90, 0x448

	.globl gMonStillFrontPic_Minun
gMonStillFrontPic_Minun: @ 0x8D122D8
	.incbin "baserom_jp.gba", 0xd122d8, 0x268

	.globl gMonPalette_Minun
gMonPalette_Minun: @ 0x8D12540
	.incbin "baserom_jp.gba", 0xd12540, 0x28

	.globl gMonBackPic_Minun
gMonBackPic_Minun: @ 0x8D12568
	.incbin "baserom_jp.gba", 0xd12568, 0x2c8

	.globl gMonShinyPalette_Minun
gMonShinyPalette_Minun: @ 0x8D12830
	.incbin "baserom_jp.gba", 0xd12830, 0x448

	.globl gMonStillFrontPic_Mawile
gMonStillFrontPic_Mawile: @ 0x8D12C78
	.incbin "baserom_jp.gba", 0xd12c78, 0x3bc

	.globl gMonPalette_Mawile
gMonPalette_Mawile: @ 0x8D13034
	.incbin "baserom_jp.gba", 0xd13034, 0x28

	.globl gMonBackPic_Mawile
gMonBackPic_Mawile: @ 0x8D1305C
	.incbin "baserom_jp.gba", 0xd1305c, 0x400

	.globl gMonShinyPalette_Mawile
gMonShinyPalette_Mawile: @ 0x8D1345C
	.incbin "baserom_jp.gba", 0xd1345c, 0x448

	.globl gMonStillFrontPic_Meditite
gMonStillFrontPic_Meditite: @ 0x8D138A4
	.incbin "baserom_jp.gba", 0xd138a4, 0x2b8

	.globl gMonPalette_Meditite
gMonPalette_Meditite: @ 0x8D13B5C
	.incbin "baserom_jp.gba", 0xd13b5c, 0x28

	.globl gMonBackPic_Meditite
gMonBackPic_Meditite: @ 0x8D13B84
	.incbin "baserom_jp.gba", 0xd13b84, 0x2c8

	.globl gMonShinyPalette_Meditite
gMonShinyPalette_Meditite: @ 0x8D13E4C
	.incbin "baserom_jp.gba", 0xd13e4c, 0x444

	.globl gMonStillFrontPic_Medicham
gMonStillFrontPic_Medicham: @ 0x8D14290
	.incbin "baserom_jp.gba", 0xd14290, 0x330

	.globl gMonPalette_Medicham
gMonPalette_Medicham: @ 0x8D145C0
	.incbin "baserom_jp.gba", 0xd145c0, 0x28

	.globl gMonBackPic_Medicham
gMonBackPic_Medicham: @ 0x8D145E8
	.incbin "baserom_jp.gba", 0xd145e8, 0x338

	.globl gMonShinyPalette_Medicham
gMonShinyPalette_Medicham: @ 0x8D14920
	.incbin "baserom_jp.gba", 0xd14920, 0x448

	.globl gMonStillFrontPic_Swablu
gMonStillFrontPic_Swablu: @ 0x8D14D68
	.incbin "baserom_jp.gba", 0xd14d68, 0x5b0

	.globl gMonPalette_Swablu
gMonPalette_Swablu: @ 0x8D15318
	.incbin "baserom_jp.gba", 0xd15318, 0x28

	.globl gMonBackPic_Swablu
gMonBackPic_Swablu: @ 0x8D15340
	.incbin "baserom_jp.gba", 0xd15340, 0x3b8

	.globl gMonShinyPalette_Swablu
gMonShinyPalette_Swablu: @ 0x8D156F8
	.incbin "baserom_jp.gba", 0xd156f8, 0x448

	.globl gMonStillFrontPic_Altaria
gMonStillFrontPic_Altaria: @ 0x8D15B40
	.incbin "baserom_jp.gba", 0xd15b40, 0x3dc

	.globl gMonPalette_Altaria
gMonPalette_Altaria: @ 0x8D15F1C
	.incbin "baserom_jp.gba", 0xd15f1c, 0x28

	.globl gMonBackPic_Altaria
gMonBackPic_Altaria: @ 0x8D15F44
	.incbin "baserom_jp.gba", 0xd15f44, 0x378

	.globl gMonShinyPalette_Altaria
gMonShinyPalette_Altaria: @ 0x8D162BC
	.incbin "baserom_jp.gba", 0xd162bc, 0x448

	.globl gMonStillFrontPic_Wynaut
gMonStillFrontPic_Wynaut: @ 0x8D16704
	.incbin "baserom_jp.gba", 0xd16704, 0x298

	.globl gMonPalette_Wynaut
gMonPalette_Wynaut: @ 0x8D1699C
	.incbin "baserom_jp.gba", 0xd1699c, 0x28

	.globl gMonBackPic_Wynaut
gMonBackPic_Wynaut: @ 0x8D169C4
	.incbin "baserom_jp.gba", 0xd169c4, 0x290

	.globl gMonShinyPalette_Wynaut
gMonShinyPalette_Wynaut: @ 0x8D16C54
	.incbin "baserom_jp.gba", 0xd16c54, 0x448

	.globl gMonStillFrontPic_Duskull
gMonStillFrontPic_Duskull: @ 0x8D1709C
	.incbin "baserom_jp.gba", 0xd1709c, 0x2f0

	.globl gMonPalette_Duskull
gMonPalette_Duskull: @ 0x8D1738C
	.incbin "baserom_jp.gba", 0xd1738c, 0x28

	.globl gMonBackPic_Duskull
gMonBackPic_Duskull: @ 0x8D173B4
	.incbin "baserom_jp.gba", 0xd173b4, 0x2b0

	.globl gMonShinyPalette_Duskull
gMonShinyPalette_Duskull: @ 0x8D17664
	.incbin "baserom_jp.gba", 0xd17664, 0x448

	.globl gMonStillFrontPic_Dusclops
gMonStillFrontPic_Dusclops: @ 0x8D17AAC
	.incbin "baserom_jp.gba", 0xd17aac, 0x3a0

	.globl gMonPalette_Dusclops
gMonPalette_Dusclops: @ 0x8D17E4C
	.incbin "baserom_jp.gba", 0xd17e4c, 0x28

	.globl gMonBackPic_Dusclops
gMonBackPic_Dusclops: @ 0x8D17E74
	.incbin "baserom_jp.gba", 0xd17e74, 0x2ec

	.globl gMonShinyPalette_Dusclops
gMonShinyPalette_Dusclops: @ 0x8D18160
	.incbin "baserom_jp.gba", 0xd18160, 0x448

	.globl gMonStillFrontPic_Roselia
gMonStillFrontPic_Roselia: @ 0x8D185A8
	.incbin "baserom_jp.gba", 0xd185a8, 0x36c

	.globl gMonPalette_Roselia
gMonPalette_Roselia: @ 0x8D18914
	.incbin "baserom_jp.gba", 0xd18914, 0x28

	.globl gMonBackPic_Roselia
gMonBackPic_Roselia: @ 0x8D1893C
	.incbin "baserom_jp.gba", 0xd1893c, 0x3c8

	.globl gMonShinyPalette_Roselia
gMonShinyPalette_Roselia: @ 0x8D18D04
	.incbin "baserom_jp.gba", 0xd18d04, 0x448

	.globl gMonStillFrontPic_Slakoth
gMonStillFrontPic_Slakoth: @ 0x8D1914C
	.incbin "baserom_jp.gba", 0xd1914c, 0x2e8

	.globl gMonPalette_Slakoth
gMonPalette_Slakoth: @ 0x8D19434
	.incbin "baserom_jp.gba", 0xd19434, 0x28

	.globl gMonBackPic_Slakoth
gMonBackPic_Slakoth: @ 0x8D1945C
	.incbin "baserom_jp.gba", 0xd1945c, 0x2e8

	.globl gMonShinyPalette_Slakoth
gMonShinyPalette_Slakoth: @ 0x8D19744
	.incbin "baserom_jp.gba", 0xd19744, 0x448

	.globl gMonStillFrontPic_Vigoroth
gMonStillFrontPic_Vigoroth: @ 0x8D19B8C
	.incbin "baserom_jp.gba", 0xd19b8c, 0x3fc

	.globl gMonPalette_Vigoroth
gMonPalette_Vigoroth: @ 0x8D19F88
	.incbin "baserom_jp.gba", 0xd19f88, 0x28

	.globl gMonBackPic_Vigoroth
gMonBackPic_Vigoroth: @ 0x8D19FB0
	.incbin "baserom_jp.gba", 0xd19fb0, 0x2c8

	.globl gMonShinyPalette_Vigoroth
gMonShinyPalette_Vigoroth: @ 0x8D1A278
	.incbin "baserom_jp.gba", 0xd1a278, 0x448

	.globl gMonStillFrontPic_Slaking
gMonStillFrontPic_Slaking: @ 0x8D1A6C0
	.incbin "baserom_jp.gba", 0xd1a6c0, 0x4d4

	.globl gMonPalette_Slaking
gMonPalette_Slaking: @ 0x8D1AB94
	.incbin "baserom_jp.gba", 0xd1ab94, 0x28

	.globl gMonBackPic_Slaking
gMonBackPic_Slaking: @ 0x8D1ABBC
	.incbin "baserom_jp.gba", 0xd1abbc, 0x3c4

	.globl gMonShinyPalette_Slaking
gMonShinyPalette_Slaking: @ 0x8D1AF80
	.incbin "baserom_jp.gba", 0xd1af80, 0x448

	.globl gMonStillFrontPic_Gulpin
gMonStillFrontPic_Gulpin: @ 0x8D1B3C8
	.incbin "baserom_jp.gba", 0xd1b3c8, 0x218

	.globl gMonPalette_Gulpin
gMonPalette_Gulpin: @ 0x8D1B5E0
	.incbin "baserom_jp.gba", 0xd1b5e0, 0x28

	.globl gMonBackPic_Gulpin
gMonBackPic_Gulpin: @ 0x8D1B608
	.incbin "baserom_jp.gba", 0xd1b608, 0x284

	.globl gMonShinyPalette_Gulpin
gMonShinyPalette_Gulpin: @ 0x8D1B88C
	.incbin "baserom_jp.gba", 0xd1b88c, 0x448

	.globl gMonStillFrontPic_Swalot
gMonStillFrontPic_Swalot: @ 0x8D1BCD4
	.incbin "baserom_jp.gba", 0xd1bcd4, 0x344

	.globl gMonPalette_Swalot
gMonPalette_Swalot: @ 0x8D1C018
	.incbin "baserom_jp.gba", 0xd1c018, 0x28

	.globl gMonBackPic_Swalot
gMonBackPic_Swalot: @ 0x8D1C040
	.incbin "baserom_jp.gba", 0xd1c040, 0x348

	.globl gMonShinyPalette_Swalot
gMonShinyPalette_Swalot: @ 0x8D1C388
	.incbin "baserom_jp.gba", 0xd1c388, 0x448

	.globl gMonStillFrontPic_Tropius
gMonStillFrontPic_Tropius: @ 0x8D1C7D0
	.incbin "baserom_jp.gba", 0xd1c7d0, 0x578

	.globl gMonPalette_Tropius
gMonPalette_Tropius: @ 0x8D1CD48
	.incbin "baserom_jp.gba", 0xd1cd48, 0x28

	.globl gMonBackPic_Tropius
gMonBackPic_Tropius: @ 0x8D1CD70
	.incbin "baserom_jp.gba", 0xd1cd70, 0x324

	.globl gMonShinyPalette_Tropius
gMonShinyPalette_Tropius: @ 0x8D1D094
	.incbin "baserom_jp.gba", 0xd1d094, 0x448

	.globl gMonStillFrontPic_Whismur
gMonStillFrontPic_Whismur: @ 0x8D1D4DC
	.incbin "baserom_jp.gba", 0xd1d4dc, 0x294

	.globl gMonPalette_Whismur
gMonPalette_Whismur: @ 0x8D1D770
	.incbin "baserom_jp.gba", 0xd1d770, 0x28

	.globl gMonBackPic_Whismur
gMonBackPic_Whismur: @ 0x8D1D798
	.incbin "baserom_jp.gba", 0xd1d798, 0x270

	.globl gMonShinyPalette_Whismur
gMonShinyPalette_Whismur: @ 0x8D1DA08
	.incbin "baserom_jp.gba", 0xd1da08, 0x448

	.globl gMonStillFrontPic_Loudred
gMonStillFrontPic_Loudred: @ 0x8D1DE50
	.incbin "baserom_jp.gba", 0xd1de50, 0x478

	.globl gMonPalette_Loudred
gMonPalette_Loudred: @ 0x8D1E2C8
	.incbin "baserom_jp.gba", 0xd1e2c8, 0x28

	.globl gMonBackPic_Loudred
gMonBackPic_Loudred: @ 0x8D1E2F0
	.incbin "baserom_jp.gba", 0xd1e2f0, 0x370

	.globl gMonShinyPalette_Loudred
gMonShinyPalette_Loudred: @ 0x8D1E660
	.incbin "baserom_jp.gba", 0xd1e660, 0x448

	.globl gMonStillFrontPic_Exploud
gMonStillFrontPic_Exploud: @ 0x8D1EAA8
	.incbin "baserom_jp.gba", 0xd1eaa8, 0x568

	.globl gMonPalette_Exploud
gMonPalette_Exploud: @ 0x8D1F010
	.incbin "baserom_jp.gba", 0xd1f010, 0x28

	.globl gMonBackPic_Exploud
gMonBackPic_Exploud: @ 0x8D1F038
	.incbin "baserom_jp.gba", 0xd1f038, 0x40c

	.globl gMonShinyPalette_Exploud
gMonShinyPalette_Exploud: @ 0x8D1F444
	.incbin "baserom_jp.gba", 0xd1f444, 0x448

	.globl gMonStillFrontPic_Clamperl
gMonStillFrontPic_Clamperl: @ 0x8D1F88C
	.incbin "baserom_jp.gba", 0xd1f88c, 0x2d8

	.globl gMonPalette_Clamperl
gMonPalette_Clamperl: @ 0x8D1FB64
	.incbin "baserom_jp.gba", 0xd1fb64, 0x28

	.globl gMonBackPic_Clamperl
gMonBackPic_Clamperl: @ 0x8D1FB8C
	.incbin "baserom_jp.gba", 0xd1fb8c, 0x294

	.globl gMonShinyPalette_Clamperl
gMonShinyPalette_Clamperl: @ 0x8D1FE20
	.incbin "baserom_jp.gba", 0xd1fe20, 0x448

	.globl gMonStillFrontPic_Huntail
gMonStillFrontPic_Huntail: @ 0x8D20268
	.incbin "baserom_jp.gba", 0xd20268, 0x3cc

	.globl gMonPalette_Huntail
gMonPalette_Huntail: @ 0x8D20634
	.incbin "baserom_jp.gba", 0xd20634, 0x28

	.globl gMonBackPic_Huntail
gMonBackPic_Huntail: @ 0x8D2065C
	.incbin "baserom_jp.gba", 0xd2065c, 0x354

	.globl gMonShinyPalette_Huntail
gMonShinyPalette_Huntail: @ 0x8D209B0
	.incbin "baserom_jp.gba", 0xd209b0, 0x448

	.globl gMonStillFrontPic_Gorebyss
gMonStillFrontPic_Gorebyss: @ 0x8D20DF8
	.incbin "baserom_jp.gba", 0xd20df8, 0x310

	.globl gMonPalette_Gorebyss
gMonPalette_Gorebyss: @ 0x8D21108
	.incbin "baserom_jp.gba", 0xd21108, 0x28

	.globl gMonBackPic_Gorebyss
gMonBackPic_Gorebyss: @ 0x8D21130
	.incbin "baserom_jp.gba", 0xd21130, 0x2e8

	.globl gMonShinyPalette_Gorebyss
gMonShinyPalette_Gorebyss: @ 0x8D21418
	.incbin "baserom_jp.gba", 0xd21418, 0x448

	.globl gMonStillFrontPic_Absol
gMonStillFrontPic_Absol: @ 0x8D21860
	.incbin "baserom_jp.gba", 0xd21860, 0x430

	.globl gMonPalette_Absol
gMonPalette_Absol: @ 0x8D21C90
	.incbin "baserom_jp.gba", 0xd21c90, 0x28

	.globl gMonBackPic_Absol
gMonBackPic_Absol: @ 0x8D21CB8
	.incbin "baserom_jp.gba", 0xd21cb8, 0x360

	.globl gMonShinyPalette_Absol
gMonShinyPalette_Absol: @ 0x8D22018
	.incbin "baserom_jp.gba", 0xd22018, 0x448

	.globl gMonStillFrontPic_Shuppet
gMonStillFrontPic_Shuppet: @ 0x8D22460
	.incbin "baserom_jp.gba", 0xd22460, 0x238

	.globl gMonPalette_Shuppet
gMonPalette_Shuppet: @ 0x8D22698
	.incbin "baserom_jp.gba", 0xd22698, 0x28

	.globl gMonBackPic_Shuppet
gMonBackPic_Shuppet: @ 0x8D226C0
	.incbin "baserom_jp.gba", 0xd226c0, 0x298

	.globl gMonShinyPalette_Shuppet
gMonShinyPalette_Shuppet: @ 0x8D22958
	.incbin "baserom_jp.gba", 0xd22958, 0x448

	.globl gMonStillFrontPic_Banette
gMonStillFrontPic_Banette: @ 0x8D22DA0
	.incbin "baserom_jp.gba", 0xd22da0, 0x2b4

	.globl gMonPalette_Banette
gMonPalette_Banette: @ 0x8D23054
	.incbin "baserom_jp.gba", 0xd23054, 0x28

	.globl gMonBackPic_Banette
gMonBackPic_Banette: @ 0x8D2307C
	.incbin "baserom_jp.gba", 0xd2307c, 0x27c

	.globl gMonShinyPalette_Banette
gMonShinyPalette_Banette: @ 0x8D232F8
	.incbin "baserom_jp.gba", 0xd232f8, 0x448

	.globl gMonStillFrontPic_Seviper
gMonStillFrontPic_Seviper: @ 0x8D23740
	.incbin "baserom_jp.gba", 0xd23740, 0x420

	.globl gMonPalette_Seviper
gMonPalette_Seviper: @ 0x8D23B60
	.incbin "baserom_jp.gba", 0xd23b60, 0x28

	.globl gMonBackPic_Seviper
gMonBackPic_Seviper: @ 0x8D23B88
	.incbin "baserom_jp.gba", 0xd23b88, 0x48c

	.globl gMonShinyPalette_Seviper
gMonShinyPalette_Seviper: @ 0x8D24014
	.incbin "baserom_jp.gba", 0xd24014, 0x448

	.globl gMonStillFrontPic_Zangoose
gMonStillFrontPic_Zangoose: @ 0x8D2445C
	.incbin "baserom_jp.gba", 0xd2445c, 0x3cc

	.globl gMonPalette_Zangoose
gMonPalette_Zangoose: @ 0x8D24828
	.incbin "baserom_jp.gba", 0xd24828, 0x28

	.globl gMonBackPic_Zangoose
gMonBackPic_Zangoose: @ 0x8D24850
	.incbin "baserom_jp.gba", 0xd24850, 0x374

	.globl gMonShinyPalette_Zangoose
gMonShinyPalette_Zangoose: @ 0x8D24BC4
	.incbin "baserom_jp.gba", 0xd24bc4, 0x448

	.globl gMonStillFrontPic_Relicanth
gMonStillFrontPic_Relicanth: @ 0x8D2500C
	.incbin "baserom_jp.gba", 0xd2500c, 0x394

	.globl gMonPalette_Relicanth
gMonPalette_Relicanth: @ 0x8D253A0
	.incbin "baserom_jp.gba", 0xd253a0, 0x28

	.globl gMonBackPic_Relicanth
gMonBackPic_Relicanth: @ 0x8D253C8
	.incbin "baserom_jp.gba", 0xd253c8, 0x358

	.globl gMonShinyPalette_Relicanth
gMonShinyPalette_Relicanth: @ 0x8D25720
	.incbin "baserom_jp.gba", 0xd25720, 0x448

	.globl gMonStillFrontPic_Aron
gMonStillFrontPic_Aron: @ 0x8D25B68
	.incbin "baserom_jp.gba", 0xd25b68, 0x1e8

	.globl gMonPalette_Aron
gMonPalette_Aron: @ 0x8D25D50
	.incbin "baserom_jp.gba", 0xd25d50, 0x28

	.globl gMonBackPic_Aron
gMonBackPic_Aron: @ 0x8D25D78
	.incbin "baserom_jp.gba", 0xd25d78, 0x228

	.globl gMonShinyPalette_Aron
gMonShinyPalette_Aron: @ 0x8D25FA0
	.incbin "baserom_jp.gba", 0xd25fa0, 0x448

	.globl gMonStillFrontPic_Lairon
gMonStillFrontPic_Lairon: @ 0x8D263E8
	.incbin "baserom_jp.gba", 0xd263e8, 0x3cc

	.globl gMonPalette_Lairon
gMonPalette_Lairon: @ 0x8D267B4
	.incbin "baserom_jp.gba", 0xd267b4, 0x28

	.globl gMonBackPic_Lairon
gMonBackPic_Lairon: @ 0x8D267DC
	.incbin "baserom_jp.gba", 0xd267dc, 0x2ec

	.globl gMonShinyPalette_Lairon
gMonShinyPalette_Lairon: @ 0x8D26AC8
	.incbin "baserom_jp.gba", 0xd26ac8, 0x448

	.globl gMonStillFrontPic_Aggron
gMonStillFrontPic_Aggron: @ 0x8D26F10
	.incbin "baserom_jp.gba", 0xd26f10, 0x57c

	.globl gMonPalette_Aggron
gMonPalette_Aggron: @ 0x8D2748C
	.incbin "baserom_jp.gba", 0xd2748c, 0x28

	.globl gMonBackPic_Aggron
gMonBackPic_Aggron: @ 0x8D274B4
	.incbin "baserom_jp.gba", 0xd274b4, 0x428

	.globl gMonShinyPalette_Aggron
gMonShinyPalette_Aggron: @ 0x8D278DC
	.incbin "baserom_jp.gba", 0xd278dc, 0x448

	.globl gMonStillFrontPic_Castform
gMonStillFrontPic_Castform: @ 0x8D27D24
	.incbin "baserom_jp.gba", 0xd27d24, 0xa88

	.globl gMonPalette_Castform
gMonPalette_Castform: @ 0x8D287AC
	.incbin "baserom_jp.gba", 0xd287ac, 0x80

	.globl gMonBackPic_Castform
gMonBackPic_Castform: @ 0x8D2882C
	.incbin "baserom_jp.gba", 0xd2882c, 0x9bc

	.globl gMonShinyPalette_Castform
gMonShinyPalette_Castform: @ 0x8D291E8
	.incbin "baserom_jp.gba", 0xd291e8, 0x49c

	.globl gMonStillFrontPic_Volbeat
gMonStillFrontPic_Volbeat: @ 0x8D29684
	.incbin "baserom_jp.gba", 0xd29684, 0x390

	.globl gMonPalette_Volbeat
gMonPalette_Volbeat: @ 0x8D29A14
	.incbin "baserom_jp.gba", 0xd29a14, 0x28

	.globl gMonBackPic_Volbeat
gMonBackPic_Volbeat: @ 0x8D29A3C
	.incbin "baserom_jp.gba", 0xd29a3c, 0x360

	.globl gMonShinyPalette_Volbeat
gMonShinyPalette_Volbeat: @ 0x8D29D9C
	.incbin "baserom_jp.gba", 0xd29d9c, 0x448

	.globl gMonStillFrontPic_Illumise
gMonStillFrontPic_Illumise: @ 0x8D2A1E4
	.incbin "baserom_jp.gba", 0xd2a1e4, 0x374

	.globl gMonPalette_Illumise
gMonPalette_Illumise: @ 0x8D2A558
	.incbin "baserom_jp.gba", 0xd2a558, 0x28

	.globl gMonBackPic_Illumise
gMonBackPic_Illumise: @ 0x8D2A580
	.incbin "baserom_jp.gba", 0xd2a580, 0x31c

	.globl gMonShinyPalette_Illumise
gMonShinyPalette_Illumise: @ 0x8D2A89C
	.incbin "baserom_jp.gba", 0xd2a89c, 0x448

	.globl gMonStillFrontPic_Lileep
gMonStillFrontPic_Lileep: @ 0x8D2ACE4
	.incbin "baserom_jp.gba", 0xd2ace4, 0x344

	.globl gMonPalette_Lileep
gMonPalette_Lileep: @ 0x8D2B028
	.incbin "baserom_jp.gba", 0xd2b028, 0x28

	.globl gMonBackPic_Lileep
gMonBackPic_Lileep: @ 0x8D2B050
	.incbin "baserom_jp.gba", 0xd2b050, 0x344

	.globl gMonShinyPalette_Lileep
gMonShinyPalette_Lileep: @ 0x8D2B394
	.incbin "baserom_jp.gba", 0xd2b394, 0x448

	.globl gMonStillFrontPic_Cradily
gMonStillFrontPic_Cradily: @ 0x8D2B7DC
	.incbin "baserom_jp.gba", 0xd2b7dc, 0x41c

	.globl gMonPalette_Cradily
gMonPalette_Cradily: @ 0x8D2BBF8
	.incbin "baserom_jp.gba", 0xd2bbf8, 0x28

	.globl gMonBackPic_Cradily
gMonBackPic_Cradily: @ 0x8D2BC20
	.incbin "baserom_jp.gba", 0xd2bc20, 0x3fc

	.globl gMonShinyPalette_Cradily
gMonShinyPalette_Cradily: @ 0x8D2C01C
	.incbin "baserom_jp.gba", 0xd2c01c, 0x448

	.globl gMonStillFrontPic_Anorith
gMonStillFrontPic_Anorith: @ 0x8D2C464
	.incbin "baserom_jp.gba", 0xd2c464, 0x324

	.globl gMonPalette_Anorith
gMonPalette_Anorith: @ 0x8D2C788
	.incbin "baserom_jp.gba", 0xd2c788, 0x28

	.globl gMonBackPic_Anorith
gMonBackPic_Anorith: @ 0x8D2C7B0
	.incbin "baserom_jp.gba", 0xd2c7b0, 0x248

	.globl gMonShinyPalette_Anorith
gMonShinyPalette_Anorith: @ 0x8D2C9F8
	.incbin "baserom_jp.gba", 0xd2c9f8, 0x448

	.globl gMonStillFrontPic_Armaldo
gMonStillFrontPic_Armaldo: @ 0x8D2CE40
	.incbin "baserom_jp.gba", 0xd2ce40, 0x580

	.globl gMonPalette_Armaldo
gMonPalette_Armaldo: @ 0x8D2D3C0
	.incbin "baserom_jp.gba", 0xd2d3c0, 0x28

	.globl gMonBackPic_Armaldo
gMonBackPic_Armaldo: @ 0x8D2D3E8
	.incbin "baserom_jp.gba", 0xd2d3e8, 0x438

	.globl gMonShinyPalette_Armaldo
gMonShinyPalette_Armaldo: @ 0x8D2D820
	.incbin "baserom_jp.gba", 0xd2d820, 0x448

	.globl gMonStillFrontPic_Ralts
gMonStillFrontPic_Ralts: @ 0x8D2DC68
	.incbin "baserom_jp.gba", 0xd2dc68, 0x230

	.globl gMonPalette_Ralts
gMonPalette_Ralts: @ 0x8D2DE98
	.incbin "baserom_jp.gba", 0xd2de98, 0x28

	.globl gMonBackPic_Ralts
gMonBackPic_Ralts: @ 0x8D2DEC0
	.incbin "baserom_jp.gba", 0xd2dec0, 0x23c

	.globl gMonShinyPalette_Ralts
gMonShinyPalette_Ralts: @ 0x8D2E0FC
	.incbin "baserom_jp.gba", 0xd2e0fc, 0x448

	.globl gMonStillFrontPic_Kirlia
gMonStillFrontPic_Kirlia: @ 0x8D2E544
	.incbin "baserom_jp.gba", 0xd2e544, 0x2fc

	.globl gMonPalette_Kirlia
gMonPalette_Kirlia: @ 0x8D2E840
	.incbin "baserom_jp.gba", 0xd2e840, 0x28

	.globl gMonBackPic_Kirlia
gMonBackPic_Kirlia: @ 0x8D2E868
	.incbin "baserom_jp.gba", 0xd2e868, 0x374

	.globl gMonShinyPalette_Kirlia
gMonShinyPalette_Kirlia: @ 0x8D2EBDC
	.incbin "baserom_jp.gba", 0xd2ebdc, 0x448

	.globl gMonStillFrontPic_Gardevoir
gMonStillFrontPic_Gardevoir: @ 0x8D2F024
	.incbin "baserom_jp.gba", 0xd2f024, 0x37c

	.globl gMonPalette_Gardevoir
gMonPalette_Gardevoir: @ 0x8D2F3A0
	.incbin "baserom_jp.gba", 0xd2f3a0, 0x28

	.globl gMonBackPic_Gardevoir
gMonBackPic_Gardevoir: @ 0x8D2F3C8
	.incbin "baserom_jp.gba", 0xd2f3c8, 0x334

	.globl gMonShinyPalette_Gardevoir
gMonShinyPalette_Gardevoir: @ 0x8D2F6FC
	.incbin "baserom_jp.gba", 0xd2f6fc, 0x448

	.globl gMonStillFrontPic_Bagon
gMonStillFrontPic_Bagon: @ 0x8D2FB44
	.incbin "baserom_jp.gba", 0xd2fb44, 0x278

	.globl gMonPalette_Bagon
gMonPalette_Bagon: @ 0x8D2FDBC
	.incbin "baserom_jp.gba", 0xd2fdbc, 0x28

	.globl gMonBackPic_Bagon
gMonBackPic_Bagon: @ 0x8D2FDE4
	.incbin "baserom_jp.gba", 0xd2fde4, 0x2e8

	.globl gMonShinyPalette_Bagon
gMonShinyPalette_Bagon: @ 0x8D300CC
	.incbin "baserom_jp.gba", 0xd300cc, 0x448

	.globl gMonStillFrontPic_Shelgon
gMonStillFrontPic_Shelgon: @ 0x8D30514
	.incbin "baserom_jp.gba", 0xd30514, 0x304

	.globl gMonPalette_Shelgon
gMonPalette_Shelgon: @ 0x8D30818
	.incbin "baserom_jp.gba", 0xd30818, 0x28

	.globl gMonBackPic_Shelgon
gMonBackPic_Shelgon: @ 0x8D30840
	.incbin "baserom_jp.gba", 0xd30840, 0x2e8

	.globl gMonShinyPalette_Shelgon
gMonShinyPalette_Shelgon: @ 0x8D30B28
	.incbin "baserom_jp.gba", 0xd30b28, 0x448

	.globl gMonStillFrontPic_Salamence
gMonStillFrontPic_Salamence: @ 0x8D30F70
	.incbin "baserom_jp.gba", 0xd30f70, 0x464

	.globl gMonPalette_Salamence
gMonPalette_Salamence: @ 0x8D313D4
	.incbin "baserom_jp.gba", 0xd313d4, 0x28

	.globl gMonBackPic_Salamence
gMonBackPic_Salamence: @ 0x8D313FC
	.incbin "baserom_jp.gba", 0xd313fc, 0x2e4

	.globl gMonShinyPalette_Salamence
gMonShinyPalette_Salamence: @ 0x8D316E0
	.incbin "baserom_jp.gba", 0xd316e0, 0x448

	.globl gMonStillFrontPic_Beldum
gMonStillFrontPic_Beldum: @ 0x8D31B28
	.incbin "baserom_jp.gba", 0xd31b28, 0x270

	.globl gMonPalette_Beldum
gMonPalette_Beldum: @ 0x8D31D98
	.incbin "baserom_jp.gba", 0xd31d98, 0x28

	.globl gMonBackPic_Beldum
gMonBackPic_Beldum: @ 0x8D31DC0
	.incbin "baserom_jp.gba", 0xd31dc0, 0x2f0

	.globl gMonShinyPalette_Beldum
gMonShinyPalette_Beldum: @ 0x8D320B0
	.incbin "baserom_jp.gba", 0xd320b0, 0x448

	.globl gMonStillFrontPic_Metang
gMonStillFrontPic_Metang: @ 0x8D324F8
	.incbin "baserom_jp.gba", 0xd324f8, 0x45c

	.globl gMonPalette_Metang
gMonPalette_Metang: @ 0x8D32954
	.incbin "baserom_jp.gba", 0xd32954, 0x28

	.globl gMonBackPic_Metang
gMonBackPic_Metang: @ 0x8D3297C
	.incbin "baserom_jp.gba", 0xd3297c, 0x324

	.globl gMonShinyPalette_Metang
gMonShinyPalette_Metang: @ 0x8D32CA0
	.incbin "baserom_jp.gba", 0xd32ca0, 0x448

	.globl gMonStillFrontPic_Metagross
gMonStillFrontPic_Metagross: @ 0x8D330E8
	.incbin "baserom_jp.gba", 0xd330e8, 0x464

	.globl gMonPalette_Metagross
gMonPalette_Metagross: @ 0x8D3354C
	.incbin "baserom_jp.gba", 0xd3354c, 0x28

	.globl gMonBackPic_Metagross
gMonBackPic_Metagross: @ 0x8D33574
	.incbin "baserom_jp.gba", 0xd33574, 0x2cc

	.globl gMonShinyPalette_Metagross
gMonShinyPalette_Metagross: @ 0x8D33840
	.incbin "baserom_jp.gba", 0xd33840, 0x448

	.globl gMonStillFrontPic_Regirock
gMonStillFrontPic_Regirock: @ 0x8D33C88
	.incbin "baserom_jp.gba", 0xd33c88, 0x4bc

	.globl gMonPalette_Regirock
gMonPalette_Regirock: @ 0x8D34144
	.incbin "baserom_jp.gba", 0xd34144, 0x28

	.globl gMonBackPic_Regirock
gMonBackPic_Regirock: @ 0x8D3416C
	.incbin "baserom_jp.gba", 0xd3416c, 0x44c

	.globl gMonShinyPalette_Regirock
gMonShinyPalette_Regirock: @ 0x8D345B8
	.incbin "baserom_jp.gba", 0xd345b8, 0x448

	.globl gMonStillFrontPic_Regice
gMonStillFrontPic_Regice: @ 0x8D34A00
	.incbin "baserom_jp.gba", 0xd34a00, 0x448

	.globl gMonPalette_Regice
gMonPalette_Regice: @ 0x8D34E48
	.incbin "baserom_jp.gba", 0xd34e48, 0x28

	.globl gMonBackPic_Regice
gMonBackPic_Regice: @ 0x8D34E70
	.incbin "baserom_jp.gba", 0xd34e70, 0x2f0

	.globl gMonShinyPalette_Regice
gMonShinyPalette_Regice: @ 0x8D35160
	.incbin "baserom_jp.gba", 0xd35160, 0x448

	.globl gMonStillFrontPic_Registeel
gMonStillFrontPic_Registeel: @ 0x8D355A8
	.incbin "baserom_jp.gba", 0xd355a8, 0x488

	.globl gMonPalette_Registeel
gMonPalette_Registeel: @ 0x8D35A30
	.incbin "baserom_jp.gba", 0xd35a30, 0x28

	.globl gMonBackPic_Registeel
gMonBackPic_Registeel: @ 0x8D35A58
	.incbin "baserom_jp.gba", 0xd35a58, 0x338

	.globl gMonShinyPalette_Registeel
gMonShinyPalette_Registeel: @ 0x8D35D90
	.incbin "baserom_jp.gba", 0xd35d90, 0x448

	.globl gMonStillFrontPic_Kyogre
gMonStillFrontPic_Kyogre: @ 0x8D361D8
	.incbin "baserom_jp.gba", 0xd361d8, 0x470

	.globl gMonPalette_Kyogre
gMonPalette_Kyogre: @ 0x8D36648
	.incbin "baserom_jp.gba", 0xd36648, 0x28

	.globl gMonBackPic_Kyogre
gMonBackPic_Kyogre: @ 0x8D36670
	.incbin "baserom_jp.gba", 0xd36670, 0x278

	.globl gMonShinyPalette_Kyogre
gMonShinyPalette_Kyogre: @ 0x8D368E8
	.incbin "baserom_jp.gba", 0xd368e8, 0x448

	.globl gMonStillFrontPic_Groudon
gMonStillFrontPic_Groudon: @ 0x8D36D30
	.incbin "baserom_jp.gba", 0xd36d30, 0x594

	.globl gMonPalette_Groudon
gMonPalette_Groudon: @ 0x8D372C4
	.incbin "baserom_jp.gba", 0xd372c4, 0x28

	.globl gMonBackPic_Groudon
gMonBackPic_Groudon: @ 0x8D372EC
	.incbin "baserom_jp.gba", 0xd372ec, 0x468

	.globl gMonShinyPalette_Groudon
gMonShinyPalette_Groudon: @ 0x8D37754
	.incbin "baserom_jp.gba", 0xd37754, 0x448

	.globl gMonStillFrontPic_Rayquaza
gMonStillFrontPic_Rayquaza: @ 0x8D37B9C
	.incbin "baserom_jp.gba", 0xd37b9c, 0x7ec

	.globl gMonPalette_Rayquaza
gMonPalette_Rayquaza: @ 0x8D38388
	.incbin "baserom_jp.gba", 0xd38388, 0x28

	.globl gMonBackPic_Rayquaza
gMonBackPic_Rayquaza: @ 0x8D383B0
	.incbin "baserom_jp.gba", 0xd383b0, 0x338

	.globl gMonShinyPalette_Rayquaza
gMonShinyPalette_Rayquaza: @ 0x8D386E8
	.incbin "baserom_jp.gba", 0xd386e8, 0x448

	.globl gMonStillFrontPic_Latias
gMonStillFrontPic_Latias: @ 0x8D38B30
	.incbin "baserom_jp.gba", 0xd38b30, 0x424

	.globl gMonPalette_Latias
gMonPalette_Latias: @ 0x8D38F54
	.incbin "baserom_jp.gba", 0xd38f54, 0x28

	.globl gMonBackPic_Latias
gMonBackPic_Latias: @ 0x8D38F7C
	.incbin "baserom_jp.gba", 0xd38f7c, 0x2fc

	.globl gMonShinyPalette_Latias
gMonShinyPalette_Latias: @ 0x8D39278
	.incbin "baserom_jp.gba", 0xd39278, 0x448

	.globl gMonStillFrontPic_Latios
gMonStillFrontPic_Latios: @ 0x8D396C0
	.incbin "baserom_jp.gba", 0xd396c0, 0x454

	.globl gMonPalette_Latios
gMonPalette_Latios: @ 0x8D39B14
	.incbin "baserom_jp.gba", 0xd39b14, 0x28

	.globl gMonBackPic_Latios
gMonBackPic_Latios: @ 0x8D39B3C
	.incbin "baserom_jp.gba", 0xd39b3c, 0x360

	.globl gMonShinyPalette_Latios
gMonShinyPalette_Latios: @ 0x8D39E9C
	.incbin "baserom_jp.gba", 0xd39e9c, 0x448

	.globl gMonStillFrontPic_Jirachi
gMonStillFrontPic_Jirachi: @ 0x8D3A2E4
	.incbin "baserom_jp.gba", 0xd3a2e4, 0x30c

	.globl gMonPalette_Jirachi
gMonPalette_Jirachi: @ 0x8D3A5F0
	.incbin "baserom_jp.gba", 0xd3a5f0, 0x28

	.globl gMonBackPic_Jirachi
gMonBackPic_Jirachi: @ 0x8D3A618
	.incbin "baserom_jp.gba", 0xd3a618, 0x3a0

	.globl gMonShinyPalette_Jirachi
gMonShinyPalette_Jirachi: @ 0x8D3A9B8
	.incbin "baserom_jp.gba", 0xd3a9b8, 0x448

	.globl gMonStillFrontPic_Deoxys
gMonStillFrontPic_Deoxys: @ 0x8D3AE00
	.incbin "baserom_jp.gba", 0xd3ae00, 0x3dc

	.globl gMonPalette_Deoxys
gMonPalette_Deoxys: @ 0x8D3B1DC
	.incbin "baserom_jp.gba", 0xd3b1dc, 0x28

	.globl gMonBackPic_Deoxys
gMonBackPic_Deoxys: @ 0x8D3B204
	.incbin "baserom_jp.gba", 0xd3b204, 0x670

	.globl gMonShinyPalette_Deoxys
gMonShinyPalette_Deoxys: @ 0x8D3B874
	.incbin "baserom_jp.gba", 0xd3b874, 0x8448

	.globl gMonStillFrontPic_Chimecho
gMonStillFrontPic_Chimecho: @ 0x8D43CBC
	.incbin "baserom_jp.gba", 0xd43cbc, 0x24c

	.globl gMonPalette_Chimecho
gMonPalette_Chimecho: @ 0x8D43F08
	.incbin "baserom_jp.gba", 0xd43f08, 0x28

	.globl gMonBackPic_Chimecho
gMonBackPic_Chimecho: @ 0x8D43F30
	.incbin "baserom_jp.gba", 0xd43f30, 0x274

	.globl gMonShinyPalette_Chimecho
gMonShinyPalette_Chimecho: @ 0x8D441A4
	.incbin "baserom_jp.gba", 0xd441a4, 0x448

	.globl gMonStillFrontPic_Egg
gMonStillFrontPic_Egg: @ 0x8D445EC
	.incbin "baserom_jp.gba", 0xd445ec, 0x1b4

	.globl gMonPalette_Egg
gMonPalette_Egg: @ 0x8D447A0
	.incbin "baserom_jp.gba", 0xd447a0, 0x20

	.globl gMonStillFrontPic_UnownB
gMonStillFrontPic_UnownB: @ 0x8D447C0
	.incbin "baserom_jp.gba", 0xd447c0, 0x1d8

	.globl gMonBackPic_UnownB
gMonBackPic_UnownB: @ 0x8D44998
	.incbin "baserom_jp.gba", 0xd44998, 0x604

	.globl gMonStillFrontPic_UnownC
gMonStillFrontPic_UnownC: @ 0x8D44F9C
	.incbin "baserom_jp.gba", 0xd44f9c, 0x214

	.globl gMonBackPic_UnownC
gMonBackPic_UnownC: @ 0x8D451B0
	.incbin "baserom_jp.gba", 0xd451b0, 0x6ac

	.globl gMonStillFrontPic_UnownD
gMonStillFrontPic_UnownD: @ 0x8D4585C
	.incbin "baserom_jp.gba", 0xd4585c, 0x1f8

	.globl gMonBackPic_UnownD
gMonBackPic_UnownD: @ 0x8D45A54
	.incbin "baserom_jp.gba", 0xd45a54, 0x658

	.globl gMonStillFrontPic_UnownE
gMonStillFrontPic_UnownE: @ 0x8D460AC
	.incbin "baserom_jp.gba", 0xd460ac, 0x1b8

	.globl gMonBackPic_UnownE
gMonBackPic_UnownE: @ 0x8D46264
	.incbin "baserom_jp.gba", 0xd46264, 0x600

	.globl gMonStillFrontPic_UnownF
gMonStillFrontPic_UnownF: @ 0x8D46864
	.incbin "baserom_jp.gba", 0xd46864, 0x1f4

	.globl gMonBackPic_UnownF
gMonBackPic_UnownF: @ 0x8D46A58
	.incbin "baserom_jp.gba", 0xd46a58, 0x61c

	.globl gMonStillFrontPic_UnownG
gMonStillFrontPic_UnownG: @ 0x8D47074
	.incbin "baserom_jp.gba", 0xd47074, 0x1dc

	.globl gMonBackPic_UnownG
gMonBackPic_UnownG: @ 0x8D47250
	.incbin "baserom_jp.gba", 0xd47250, 0x64c

	.globl gMonStillFrontPic_UnownH
gMonStillFrontPic_UnownH: @ 0x8D4789C
	.incbin "baserom_jp.gba", 0xd4789c, 0x244

	.globl gMonBackPic_UnownH
gMonBackPic_UnownH: @ 0x8D47AE0
	.incbin "baserom_jp.gba", 0xd47ae0, 0x6c4

	.globl gMonStillFrontPic_UnownI
gMonStillFrontPic_UnownI: @ 0x8D481A4
	.incbin "baserom_jp.gba", 0xd481a4, 0x198

	.globl gMonBackPic_UnownI
gMonBackPic_UnownI: @ 0x8D4833C
	.incbin "baserom_jp.gba", 0xd4833c, 0x5a8

	.globl gMonStillFrontPic_UnownJ
gMonStillFrontPic_UnownJ: @ 0x8D488E4
	.incbin "baserom_jp.gba", 0xd488e4, 0x1c4

	.globl gMonBackPic_UnownJ
gMonBackPic_UnownJ: @ 0x8D48AA8
	.incbin "baserom_jp.gba", 0xd48aa8, 0x5e8

	.globl gMonStillFrontPic_UnownK
gMonStillFrontPic_UnownK: @ 0x8D49090
	.incbin "baserom_jp.gba", 0xd49090, 0x1d0

	.globl gMonBackPic_UnownK
gMonBackPic_UnownK: @ 0x8D49260
	.incbin "baserom_jp.gba", 0xd49260, 0x5f8

	.globl gMonStillFrontPic_UnownL
gMonStillFrontPic_UnownL: @ 0x8D49858
	.incbin "baserom_jp.gba", 0xd49858, 0x1b0

	.globl gMonBackPic_UnownL
gMonBackPic_UnownL: @ 0x8D49A08
	.incbin "baserom_jp.gba", 0xd49a08, 0x5d4

	.globl gMonStillFrontPic_UnownM
gMonStillFrontPic_UnownM: @ 0x8D49FDC
	.incbin "baserom_jp.gba", 0xd49fdc, 0x224

	.globl gMonBackPic_UnownM
gMonBackPic_UnownM: @ 0x8D4A200
	.incbin "baserom_jp.gba", 0xd4a200, 0x6a8

	.globl gMonStillFrontPic_UnownN
gMonStillFrontPic_UnownN: @ 0x8D4A8A8
	.incbin "baserom_jp.gba", 0xd4a8a8, 0x1f8

	.globl gMonBackPic_UnownN
gMonBackPic_UnownN: @ 0x8D4AAA0
	.incbin "baserom_jp.gba", 0xd4aaa0, 0x66c

	.globl gMonStillFrontPic_UnownO
gMonStillFrontPic_UnownO: @ 0x8D4B10C
	.incbin "baserom_jp.gba", 0xd4b10c, 0x238

	.globl gMonBackPic_UnownO
gMonBackPic_UnownO: @ 0x8D4B344
	.incbin "baserom_jp.gba", 0xd4b344, 0x6c0

	.globl gMonStillFrontPic_UnownP
gMonStillFrontPic_UnownP: @ 0x8D4BA04
	.incbin "baserom_jp.gba", 0xd4ba04, 0x1a0

	.globl gMonBackPic_UnownP
gMonBackPic_UnownP: @ 0x8D4BBA4
	.incbin "baserom_jp.gba", 0xd4bba4, 0x5c4

	.globl gMonStillFrontPic_UnownQ
gMonStillFrontPic_UnownQ: @ 0x8D4C168
	.incbin "baserom_jp.gba", 0xd4c168, 0x1b4

	.globl gMonBackPic_UnownQ
gMonBackPic_UnownQ: @ 0x8D4C31C
	.incbin "baserom_jp.gba", 0xd4c31c, 0x5cc

	.globl gMonStillFrontPic_UnownR
gMonStillFrontPic_UnownR: @ 0x8D4C8E8
	.incbin "baserom_jp.gba", 0xd4c8e8, 0x1a4

	.globl gMonBackPic_UnownR
gMonBackPic_UnownR: @ 0x8D4CA8C
	.incbin "baserom_jp.gba", 0xd4ca8c, 0x5c8

	.globl gMonStillFrontPic_UnownS
gMonStillFrontPic_UnownS: @ 0x8D4D054
	.incbin "baserom_jp.gba", 0xd4d054, 0x1e8

	.globl gMonBackPic_UnownS
gMonBackPic_UnownS: @ 0x8D4D23C
	.incbin "baserom_jp.gba", 0xd4d23c, 0x654

	.globl gMonStillFrontPic_UnownT
gMonStillFrontPic_UnownT: @ 0x8D4D890
	.incbin "baserom_jp.gba", 0xd4d890, 0x1b0

	.globl gMonBackPic_UnownT
gMonBackPic_UnownT: @ 0x8D4DA40
	.incbin "baserom_jp.gba", 0xd4da40, 0x5b4

	.globl gMonStillFrontPic_UnownU
gMonStillFrontPic_UnownU: @ 0x8D4DFF4
	.incbin "baserom_jp.gba", 0xd4dff4, 0x218

	.globl gMonBackPic_UnownU
gMonBackPic_UnownU: @ 0x8D4E20C
	.incbin "baserom_jp.gba", 0xd4e20c, 0x654

	.globl gMonStillFrontPic_UnownV
gMonStillFrontPic_UnownV: @ 0x8D4E860
	.incbin "baserom_jp.gba", 0xd4e860, 0x1e4

	.globl gMonBackPic_UnownV
gMonBackPic_UnownV: @ 0x8D4EA44
	.incbin "baserom_jp.gba", 0xd4ea44, 0x630

	.globl gMonStillFrontPic_UnownW
gMonStillFrontPic_UnownW: @ 0x8D4F074
	.incbin "baserom_jp.gba", 0xd4f074, 0x1d4

	.globl gMonBackPic_UnownW
gMonBackPic_UnownW: @ 0x8D4F248
	.incbin "baserom_jp.gba", 0xd4f248, 0x604

	.globl gMonStillFrontPic_UnownX
gMonStillFrontPic_UnownX: @ 0x8D4F84C
	.incbin "baserom_jp.gba", 0xd4f84c, 0x1c4

	.globl gMonBackPic_UnownX
gMonBackPic_UnownX: @ 0x8D4FA10
	.incbin "baserom_jp.gba", 0xd4fa10, 0x5f0

	.globl gMonStillFrontPic_UnownY
gMonStillFrontPic_UnownY: @ 0x8D50000
	.incbin "baserom_jp.gba", 0xd50000, 0x1d8

	.globl gMonBackPic_UnownY
gMonBackPic_UnownY: @ 0x8D501D8
	.incbin "baserom_jp.gba", 0xd501d8, 0x5f4

	.globl gMonStillFrontPic_UnownZ
gMonStillFrontPic_UnownZ: @ 0x8D507CC
	.incbin "baserom_jp.gba", 0xd507cc, 0x1b0

	.globl gMonBackPic_UnownZ
gMonBackPic_UnownZ: @ 0x8D5097C
	.incbin "baserom_jp.gba", 0xd5097c, 0x5dc

	.globl gMonStillFrontPic_UnownExclamationMark
gMonStillFrontPic_UnownExclamationMark: @ 0x8D50F58
	.incbin "baserom_jp.gba", 0xd50f58, 0x190

	.globl gMonBackPic_UnownExclamationMark
gMonBackPic_UnownExclamationMark: @ 0x8D510E8
	.incbin "baserom_jp.gba", 0xd510e8, 0x5c8

	.globl gMonStillFrontPic_UnownQuestionMark
gMonStillFrontPic_UnownQuestionMark: @ 0x8D516B0
	.incbin "baserom_jp.gba", 0xd516b0, 0x1bc

	.globl gMonBackPic_UnownQuestionMark
gMonBackPic_UnownQuestionMark: @ 0x8D5186C
	.incbin "baserom_jp.gba", 0xd5186c, 0x26128
