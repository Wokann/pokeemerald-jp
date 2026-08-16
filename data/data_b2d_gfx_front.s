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

	.globl gMonFrontPic_CircledQuestionMark
gMonFrontPic_CircledQuestionMark: @ 0x8B00000
	.incbin "baserom_jp.gba", 0xb00000, 0x338

	.globl gMonFrontPic_Bulbasaur
gMonFrontPic_Bulbasaur: @ 0x8B00338
	.incbin "baserom_jp.gba", 0xb00338, 0x478

	.globl gMonFrontPic_Ivysaur
gMonFrontPic_Ivysaur: @ 0x8B007B0
	.incbin "baserom_jp.gba", 0xb007b0, 0x660

	.globl gMonFrontPic_Venusaur
gMonFrontPic_Venusaur: @ 0x8B00E10
	.incbin "baserom_jp.gba", 0xb00e10, 0x9bc

	.globl gMonFrontPic_Charmander
gMonFrontPic_Charmander: @ 0x8B017CC
	.incbin "baserom_jp.gba", 0xb017cc, 0x4b0

	.globl gMonFrontPic_Charmeleon
gMonFrontPic_Charmeleon: @ 0x8B01C7C
	.incbin "baserom_jp.gba", 0xb01c7c, 0x6ec

	.globl gMonFrontPic_Charizard
gMonFrontPic_Charizard: @ 0x8B02368
	.incbin "baserom_jp.gba", 0xb02368, 0xa00

	.globl gMonFrontPic_Squirtle
gMonFrontPic_Squirtle: @ 0x8B02D68
	.incbin "baserom_jp.gba", 0xb02d68, 0x4f8

	.globl gMonFrontPic_Wartortle
gMonFrontPic_Wartortle: @ 0x8B03260
	.incbin "baserom_jp.gba", 0xb03260, 0x6e4

	.globl gMonFrontPic_Blastoise
gMonFrontPic_Blastoise: @ 0x8B03944
	.incbin "baserom_jp.gba", 0xb03944, 0x93c

	.globl gMonFrontPic_Caterpie
gMonFrontPic_Caterpie: @ 0x8B04280
	.incbin "baserom_jp.gba", 0xb04280, 0x47c

	.globl gMonFrontPic_Metapod
gMonFrontPic_Metapod: @ 0x8B046FC
	.incbin "baserom_jp.gba", 0xb046fc, 0x3ac

	.globl gMonFrontPic_Butterfree
gMonFrontPic_Butterfree: @ 0x8B04AA8
	.incbin "baserom_jp.gba", 0xb04aa8, 0x5d8

	.globl gMonFrontPic_Weedle
gMonFrontPic_Weedle: @ 0x8B05080
	.incbin "baserom_jp.gba", 0xb05080, 0x3c4

	.globl gMonFrontPic_Kakuna
gMonFrontPic_Kakuna: @ 0x8B05444
	.incbin "baserom_jp.gba", 0xb05444, 0x3dc

	.globl gMonFrontPic_Beedrill
gMonFrontPic_Beedrill: @ 0x8B05820
	.incbin "baserom_jp.gba", 0xb05820, 0x718

	.globl gMonFrontPic_Pidgey
gMonFrontPic_Pidgey: @ 0x8B05F38
	.incbin "baserom_jp.gba", 0xb05f38, 0x514

	.globl gMonFrontPic_Pidgeotto
gMonFrontPic_Pidgeotto: @ 0x8B0644C
	.incbin "baserom_jp.gba", 0xb0644c, 0x6d8

	.globl gMonFrontPic_Pidgeot
gMonFrontPic_Pidgeot: @ 0x8B06B24
	.incbin "baserom_jp.gba", 0xb06b24, 0x8b8

	.globl gMonFrontPic_Rattata
gMonFrontPic_Rattata: @ 0x8B073DC
	.incbin "baserom_jp.gba", 0xb073dc, 0x44c

	.globl gMonFrontPic_Raticate
gMonFrontPic_Raticate: @ 0x8B07828
	.incbin "baserom_jp.gba", 0xb07828, 0x67c

	.globl gMonFrontPic_Spearow
gMonFrontPic_Spearow: @ 0x8B07EA4
	.incbin "baserom_jp.gba", 0xb07ea4, 0x4e4

	.globl gMonFrontPic_Fearow
gMonFrontPic_Fearow: @ 0x8B08388
	.incbin "baserom_jp.gba", 0xb08388, 0x83c

	.globl gMonFrontPic_Ekans
gMonFrontPic_Ekans: @ 0x8B08BC4
	.incbin "baserom_jp.gba", 0xb08bc4, 0x5c8

	.globl gMonFrontPic_Arbok
gMonFrontPic_Arbok: @ 0x8B0918C
	.incbin "baserom_jp.gba", 0xb0918c, 0x7d8

	.globl gMonFrontPic_Pikachu
gMonFrontPic_Pikachu: @ 0x8B09964
	.incbin "baserom_jp.gba", 0xb09964, 0x4d8

	.globl gMonFrontPic_Raichu
gMonFrontPic_Raichu: @ 0x8B09E3C
	.incbin "baserom_jp.gba", 0xb09e3c, 0x718

	.globl gMonFrontPic_Sandshrew
gMonFrontPic_Sandshrew: @ 0x8B0A554
	.incbin "baserom_jp.gba", 0xb0a554, 0x518

	.globl gMonFrontPic_Sandslash
gMonFrontPic_Sandslash: @ 0x8B0AA6C
	.incbin "baserom_jp.gba", 0xb0aa6c, 0x758

	.globl gMonFrontPic_NidoranF
gMonFrontPic_NidoranF: @ 0x8B0B1C4
	.incbin "baserom_jp.gba", 0xb0b1c4, 0x464

	.globl gMonFrontPic_Nidorina
gMonFrontPic_Nidorina: @ 0x8B0B628
	.incbin "baserom_jp.gba", 0xb0b628, 0x634

	.globl gMonFrontPic_Nidoqueen
gMonFrontPic_Nidoqueen: @ 0x8B0BC5C
	.incbin "baserom_jp.gba", 0xb0bc5c, 0x88c

	.globl gMonFrontPic_NidoranM
gMonFrontPic_NidoranM: @ 0x8B0C4E8
	.incbin "baserom_jp.gba", 0xb0c4e8, 0x56c

	.globl gMonFrontPic_Nidorino
gMonFrontPic_Nidorino: @ 0x8B0CA54
	.incbin "baserom_jp.gba", 0xb0ca54, 0x6b8

	.globl gMonFrontPic_Nidoking
gMonFrontPic_Nidoking: @ 0x8B0D10C
	.incbin "baserom_jp.gba", 0xb0d10c, 0x89c

	.globl gMonFrontPic_Clefairy
gMonFrontPic_Clefairy: @ 0x8B0D9A8
	.incbin "baserom_jp.gba", 0xb0d9a8, 0x47c

	.globl gMonFrontPic_Clefable
gMonFrontPic_Clefable: @ 0x8B0DE24
	.incbin "baserom_jp.gba", 0xb0de24, 0x580

	.globl gMonFrontPic_Vulpix
gMonFrontPic_Vulpix: @ 0x8B0E3A4
	.incbin "baserom_jp.gba", 0xb0e3a4, 0x664

	.globl gMonFrontPic_Ninetales
gMonFrontPic_Ninetales: @ 0x8B0EA08
	.incbin "baserom_jp.gba", 0xb0ea08, 0x7c4

	.globl gMonFrontPic_Jigglypuff
gMonFrontPic_Jigglypuff: @ 0x8B0F1CC
	.incbin "baserom_jp.gba", 0xb0f1cc, 0x4b0

	.globl gMonFrontPic_Wigglytuff
gMonFrontPic_Wigglytuff: @ 0x8B0F67C
	.incbin "baserom_jp.gba", 0xb0f67c, 0x654

	.globl gMonFrontPic_Zubat
gMonFrontPic_Zubat: @ 0x8B0FCD0
	.incbin "baserom_jp.gba", 0xb0fcd0, 0x4b8

	.globl gMonFrontPic_Golbat
gMonFrontPic_Golbat: @ 0x8B10188
	.incbin "baserom_jp.gba", 0xb10188, 0x5f8

	.globl gMonFrontPic_Oddish
gMonFrontPic_Oddish: @ 0x8B10780
	.incbin "baserom_jp.gba", 0xb10780, 0x3f8

	.globl gMonFrontPic_Gloom
gMonFrontPic_Gloom: @ 0x8B10B78
	.incbin "baserom_jp.gba", 0xb10b78, 0x638

	.globl gMonFrontPic_Vileplume
gMonFrontPic_Vileplume: @ 0x8B111B0
	.incbin "baserom_jp.gba", 0xb111b0, 0x5a0

	.globl gMonFrontPic_Paras
gMonFrontPic_Paras: @ 0x8B11750
	.incbin "baserom_jp.gba", 0xb11750, 0x45c

	.globl gMonFrontPic_Parasect
gMonFrontPic_Parasect: @ 0x8B11BAC
	.incbin "baserom_jp.gba", 0xb11bac, 0x610

	.globl gMonFrontPic_Venonat
gMonFrontPic_Venonat: @ 0x8B121BC
	.incbin "baserom_jp.gba", 0xb121bc, 0x5ec

	.globl gMonFrontPic_Venomoth
gMonFrontPic_Venomoth: @ 0x8B127A8
	.incbin "baserom_jp.gba", 0xb127a8, 0x7cc

	.globl gMonFrontPic_Diglett
gMonFrontPic_Diglett: @ 0x8B12F74
	.incbin "baserom_jp.gba", 0xb12f74, 0x3c4

	.globl gMonFrontPic_Dugtrio
gMonFrontPic_Dugtrio: @ 0x8B13338
	.incbin "baserom_jp.gba", 0xb13338, 0x494

	.globl gMonFrontPic_Meowth
gMonFrontPic_Meowth: @ 0x8B137CC
	.incbin "baserom_jp.gba", 0xb137cc, 0x4e8

	.globl gMonFrontPic_Persian
gMonFrontPic_Persian: @ 0x8B13CB4
	.incbin "baserom_jp.gba", 0xb13cb4, 0x6e8

	.globl gMonFrontPic_Psyduck
gMonFrontPic_Psyduck: @ 0x8B1439C
	.incbin "baserom_jp.gba", 0xb1439c, 0x568

	.globl gMonFrontPic_Golduck
gMonFrontPic_Golduck: @ 0x8B14904
	.incbin "baserom_jp.gba", 0xb14904, 0x698

	.globl gMonFrontPic_Mankey
gMonFrontPic_Mankey: @ 0x8B14F9C
	.incbin "baserom_jp.gba", 0xb14f9c, 0x5b4

	.globl gMonFrontPic_Primeape
gMonFrontPic_Primeape: @ 0x8B15550
	.incbin "baserom_jp.gba", 0xb15550, 0x6ac

	.globl gMonFrontPic_Growlithe
gMonFrontPic_Growlithe: @ 0x8B15BFC
	.incbin "baserom_jp.gba", 0xb15bfc, 0x5ec

	.globl gMonFrontPic_Arcanine
gMonFrontPic_Arcanine: @ 0x8B161E8
	.incbin "baserom_jp.gba", 0xb161e8, 0xa0c

	.globl gMonFrontPic_Poliwag
gMonFrontPic_Poliwag: @ 0x8B16BF4
	.incbin "baserom_jp.gba", 0xb16bf4, 0x4d4

	.globl gMonFrontPic_Poliwhirl
gMonFrontPic_Poliwhirl: @ 0x8B170C8
	.incbin "baserom_jp.gba", 0xb170c8, 0x5ec

	.globl gMonFrontPic_Poliwrath
gMonFrontPic_Poliwrath: @ 0x8B176B4
	.incbin "baserom_jp.gba", 0xb176b4, 0x684

	.globl gMonFrontPic_Abra
gMonFrontPic_Abra: @ 0x8B17D38
	.incbin "baserom_jp.gba", 0xb17d38, 0x40c

	.globl gMonFrontPic_Kadabra
gMonFrontPic_Kadabra: @ 0x8B18144
	.incbin "baserom_jp.gba", 0xb18144, 0x7cc

	.globl gMonFrontPic_Alakazam
gMonFrontPic_Alakazam: @ 0x8B18910
	.incbin "baserom_jp.gba", 0xb18910, 0x7bc

	.globl gMonFrontPic_Machop
gMonFrontPic_Machop: @ 0x8B190CC
	.incbin "baserom_jp.gba", 0xb190cc, 0x430

	.globl gMonFrontPic_Machoke
gMonFrontPic_Machoke: @ 0x8B194FC
	.incbin "baserom_jp.gba", 0xb194fc, 0x6b8

	.globl gMonFrontPic_Machamp
gMonFrontPic_Machamp: @ 0x8B19BB4
	.incbin "baserom_jp.gba", 0xb19bb4, 0x70c

	.globl gMonFrontPic_Bellsprout
gMonFrontPic_Bellsprout: @ 0x8B1A2C0
	.incbin "baserom_jp.gba", 0xb1a2c0, 0x4d8

	.globl gMonFrontPic_Weepinbell
gMonFrontPic_Weepinbell: @ 0x8B1A798
	.incbin "baserom_jp.gba", 0xb1a798, 0x588

	.globl gMonFrontPic_Victreebel
gMonFrontPic_Victreebel: @ 0x8B1AD20
	.incbin "baserom_jp.gba", 0xb1ad20, 0x754

	.globl gMonFrontPic_Tentacool
gMonFrontPic_Tentacool: @ 0x8B1B474
	.incbin "baserom_jp.gba", 0xb1b474, 0x480

	.globl gMonFrontPic_Tentacruel
gMonFrontPic_Tentacruel: @ 0x8B1B8F4
	.incbin "baserom_jp.gba", 0xb1b8f4, 0x724

	.globl gMonFrontPic_Geodude
gMonFrontPic_Geodude: @ 0x8B1C018
	.incbin "baserom_jp.gba", 0xb1c018, 0x490

	.globl gMonFrontPic_Graveler
gMonFrontPic_Graveler: @ 0x8B1C4A8
	.incbin "baserom_jp.gba", 0xb1c4a8, 0x5d4

	.globl gMonFrontPic_Golem
gMonFrontPic_Golem: @ 0x8B1CA7C
	.incbin "baserom_jp.gba", 0xb1ca7c, 0x6e4

	.globl gMonFrontPic_Ponyta
gMonFrontPic_Ponyta: @ 0x8B1D160
	.incbin "baserom_jp.gba", 0xb1d160, 0x6c0

	.globl gMonFrontPic_Rapidash
gMonFrontPic_Rapidash: @ 0x8B1D820
	.incbin "baserom_jp.gba", 0xb1d820, 0x968

	.globl gMonFrontPic_Slowpoke
gMonFrontPic_Slowpoke: @ 0x8B1E188
	.incbin "baserom_jp.gba", 0xb1e188, 0x4c8

	.globl gMonFrontPic_Slowbro
gMonFrontPic_Slowbro: @ 0x8B1E650
	.incbin "baserom_jp.gba", 0xb1e650, 0x778

	.globl gMonFrontPic_Magnemite
gMonFrontPic_Magnemite: @ 0x8B1EDC8
	.incbin "baserom_jp.gba", 0xb1edc8, 0x398

	.globl gMonFrontPic_Magneton
gMonFrontPic_Magneton: @ 0x8B1F160
	.incbin "baserom_jp.gba", 0xb1f160, 0x6b4

	.globl gMonFrontPic_Farfetchd
gMonFrontPic_Farfetchd: @ 0x8B1F814
	.incbin "baserom_jp.gba", 0xb1f814, 0x588

	.globl gMonFrontPic_Doduo
gMonFrontPic_Doduo: @ 0x8B1FD9C
	.incbin "baserom_jp.gba", 0xb1fd9c, 0x5fc

	.globl gMonFrontPic_Dodrio
gMonFrontPic_Dodrio: @ 0x8B20398
	.incbin "baserom_jp.gba", 0xb20398, 0x914

	.globl gMonFrontPic_Seel
gMonFrontPic_Seel: @ 0x8B20CAC
	.incbin "baserom_jp.gba", 0xb20cac, 0x548

	.globl gMonFrontPic_Dewgong
gMonFrontPic_Dewgong: @ 0x8B211F4
	.incbin "baserom_jp.gba", 0xb211f4, 0x6a0

	.globl gMonFrontPic_Grimer
gMonFrontPic_Grimer: @ 0x8B21894
	.incbin "baserom_jp.gba", 0xb21894, 0x588

	.globl gMonFrontPic_Muk
gMonFrontPic_Muk: @ 0x8B21E1C
	.incbin "baserom_jp.gba", 0xb21e1c, 0x71c

	.globl gMonFrontPic_Shellder
gMonFrontPic_Shellder: @ 0x8B22538
	.incbin "baserom_jp.gba", 0xb22538, 0x454

	.globl gMonFrontPic_Cloyster
gMonFrontPic_Cloyster: @ 0x8B2298C
	.incbin "baserom_jp.gba", 0xb2298c, 0x7ac

	.globl gMonFrontPic_Gastly
gMonFrontPic_Gastly: @ 0x8B23138
	.incbin "baserom_jp.gba", 0xb23138, 0x6a4

	.globl gMonFrontPic_Haunter
gMonFrontPic_Haunter: @ 0x8B237DC
	.incbin "baserom_jp.gba", 0xb237dc, 0x6f4

	.globl gMonFrontPic_Gengar
gMonFrontPic_Gengar: @ 0x8B23ED0
	.incbin "baserom_jp.gba", 0xb23ed0, 0x69c

	.globl gMonFrontPic_Onix
gMonFrontPic_Onix: @ 0x8B2456C
	.incbin "baserom_jp.gba", 0xb2456c, 0x880

	.globl gMonFrontPic_Drowzee
gMonFrontPic_Drowzee: @ 0x8B24DEC
	.incbin "baserom_jp.gba", 0xb24dec, 0x5e8

	.globl gMonFrontPic_Hypno
gMonFrontPic_Hypno: @ 0x8B253D4
	.incbin "baserom_jp.gba", 0xb253d4, 0x64c

	.globl gMonFrontPic_Krabby
gMonFrontPic_Krabby: @ 0x8B25A20
	.incbin "baserom_jp.gba", 0xb25a20, 0x4c4

	.globl gMonFrontPic_Kingler
gMonFrontPic_Kingler: @ 0x8B25EE4
	.incbin "baserom_jp.gba", 0xb25ee4, 0x910

	.globl gMonFrontPic_Voltorb
gMonFrontPic_Voltorb: @ 0x8B267F4
	.incbin "baserom_jp.gba", 0xb267f4, 0x374

	.globl gMonFrontPic_Electrode
gMonFrontPic_Electrode: @ 0x8B26B68
	.incbin "baserom_jp.gba", 0xb26b68, 0x414

	.globl gMonFrontPic_Exeggcute
gMonFrontPic_Exeggcute: @ 0x8B26F7C
	.incbin "baserom_jp.gba", 0xb26f7c, 0x698

	.globl gMonFrontPic_Exeggutor
gMonFrontPic_Exeggutor: @ 0x8B27614
	.incbin "baserom_jp.gba", 0xb27614, 0x810

	.globl gMonFrontPic_Cubone
gMonFrontPic_Cubone: @ 0x8B27E24
	.incbin "baserom_jp.gba", 0xb27e24, 0x484

	.globl gMonFrontPic_Marowak
gMonFrontPic_Marowak: @ 0x8B282A8
	.incbin "baserom_jp.gba", 0xb282a8, 0x6a0

	.globl gMonFrontPic_Hitmonlee
gMonFrontPic_Hitmonlee: @ 0x8B28948
	.incbin "baserom_jp.gba", 0xb28948, 0x720

	.globl gMonFrontPic_Hitmonchan
gMonFrontPic_Hitmonchan: @ 0x8B29068
	.incbin "baserom_jp.gba", 0xb29068, 0x610

	.globl gMonFrontPic_Lickitung
gMonFrontPic_Lickitung: @ 0x8B29678
	.incbin "baserom_jp.gba", 0xb29678, 0x6d8

	.globl gMonFrontPic_Koffing
gMonFrontPic_Koffing: @ 0x8B29D50
	.incbin "baserom_jp.gba", 0xb29d50, 0x618

	.globl gMonFrontPic_Weezing
gMonFrontPic_Weezing: @ 0x8B2A368
	.incbin "baserom_jp.gba", 0xb2a368, 0x860

	.globl gMonFrontPic_Rhyhorn
gMonFrontPic_Rhyhorn: @ 0x8B2ABC8
	.incbin "baserom_jp.gba", 0xb2abc8, 0x6dc

	.globl gMonFrontPic_Rhydon
gMonFrontPic_Rhydon: @ 0x8B2B2A4
	.incbin "baserom_jp.gba", 0xb2b2a4, 0x900

	.globl gMonFrontPic_Chansey
gMonFrontPic_Chansey: @ 0x8B2BBA4
	.incbin "baserom_jp.gba", 0xb2bba4, 0x584

	.globl gMonFrontPic_Tangela
gMonFrontPic_Tangela: @ 0x8B2C128
	.incbin "baserom_jp.gba", 0xb2c128, 0x6d8

	.globl gMonFrontPic_Kangaskhan
gMonFrontPic_Kangaskhan: @ 0x8B2C800
	.incbin "baserom_jp.gba", 0xb2c800, 0x8b4

	.globl gMonFrontPic_Horsea
gMonFrontPic_Horsea: @ 0x8B2D0B4
	.incbin "baserom_jp.gba", 0xb2d0b4, 0x41c

	.globl gMonFrontPic_Seadra
gMonFrontPic_Seadra: @ 0x8B2D4D0
	.incbin "baserom_jp.gba", 0xb2d4d0, 0x6e4

	.globl gMonFrontPic_Goldeen
gMonFrontPic_Goldeen: @ 0x8B2DBB4
	.incbin "baserom_jp.gba", 0xb2dbb4, 0x5d8

	.globl gMonFrontPic_Seaking
gMonFrontPic_Seaking: @ 0x8B2E18C
	.incbin "baserom_jp.gba", 0xb2e18c, 0x7a4

	.globl gMonFrontPic_Staryu
gMonFrontPic_Staryu: @ 0x8B2E930
	.incbin "baserom_jp.gba", 0xb2e930, 0x534

	.globl gMonFrontPic_Starmie
gMonFrontPic_Starmie: @ 0x8B2EE64
	.incbin "baserom_jp.gba", 0xb2ee64, 0x66c

	.globl gMonFrontPic_MrMime
gMonFrontPic_MrMime: @ 0x8B2F4D0
	.incbin "baserom_jp.gba", 0xb2f4d0, 0x63c

	.globl gMonFrontPic_Scyther
gMonFrontPic_Scyther: @ 0x8B2FB0C
	.incbin "baserom_jp.gba", 0xb2fb0c, 0x840

	.globl gMonFrontPic_Jynx
gMonFrontPic_Jynx: @ 0x8B3034C
	.incbin "baserom_jp.gba", 0xb3034c, 0x894

	.globl gMonFrontPic_Electabuzz
gMonFrontPic_Electabuzz: @ 0x8B30BE0
	.incbin "baserom_jp.gba", 0xb30be0, 0x7e8

	.globl gMonFrontPic_Magmar
gMonFrontPic_Magmar: @ 0x8B313C8
	.incbin "baserom_jp.gba", 0xb313c8, 0x878

	.globl gMonFrontPic_Pinsir
gMonFrontPic_Pinsir: @ 0x8B31C40
	.incbin "baserom_jp.gba", 0xb31c40, 0x798

	.globl gMonFrontPic_Tauros
gMonFrontPic_Tauros: @ 0x8B323D8
	.incbin "baserom_jp.gba", 0xb323d8, 0x8a4

	.globl gMonFrontPic_Magikarp
gMonFrontPic_Magikarp: @ 0x8B32C7C
	.incbin "baserom_jp.gba", 0xb32c7c, 0x628

	.globl gMonFrontPic_Gyarados
gMonFrontPic_Gyarados: @ 0x8B332A4
	.incbin "baserom_jp.gba", 0xb332a4, 0x8d0

	.globl gMonFrontPic_Lapras
gMonFrontPic_Lapras: @ 0x8B33B74
	.incbin "baserom_jp.gba", 0xb33b74, 0x660

	.globl gMonFrontPic_Ditto
gMonFrontPic_Ditto: @ 0x8B341D4
	.incbin "baserom_jp.gba", 0xb341d4, 0x374

	.globl gMonFrontPic_Eevee
gMonFrontPic_Eevee: @ 0x8B34548
	.incbin "baserom_jp.gba", 0xb34548, 0x520

	.globl gMonFrontPic_Vaporeon
gMonFrontPic_Vaporeon: @ 0x8B34A68
	.incbin "baserom_jp.gba", 0xb34a68, 0x630

	.globl gMonFrontPic_Jolteon
gMonFrontPic_Jolteon: @ 0x8B35098
	.incbin "baserom_jp.gba", 0xb35098, 0x6dc

	.globl gMonFrontPic_Flareon
gMonFrontPic_Flareon: @ 0x8B35774
	.incbin "baserom_jp.gba", 0xb35774, 0x644

	.globl gMonFrontPic_Porygon
gMonFrontPic_Porygon: @ 0x8B35DB8
	.incbin "baserom_jp.gba", 0xb35db8, 0x490

	.globl gMonFrontPic_Omanyte
gMonFrontPic_Omanyte: @ 0x8B36248
	.incbin "baserom_jp.gba", 0xb36248, 0x428

	.globl gMonFrontPic_Omastar
gMonFrontPic_Omastar: @ 0x8B36670
	.incbin "baserom_jp.gba", 0xb36670, 0x644

	.globl gMonFrontPic_Kabuto
gMonFrontPic_Kabuto: @ 0x8B36CB4
	.incbin "baserom_jp.gba", 0xb36cb4, 0x3d4

	.globl gMonFrontPic_Kabutops
gMonFrontPic_Kabutops: @ 0x8B37088
	.incbin "baserom_jp.gba", 0xb37088, 0x754

	.globl gMonFrontPic_Aerodactyl
gMonFrontPic_Aerodactyl: @ 0x8B377DC
	.incbin "baserom_jp.gba", 0xb377dc, 0x788

	.globl gMonFrontPic_Snorlax
gMonFrontPic_Snorlax: @ 0x8B37F64
	.incbin "baserom_jp.gba", 0xb37f64, 0x728

	.globl gMonFrontPic_Articuno
gMonFrontPic_Articuno: @ 0x8B3868C
	.incbin "baserom_jp.gba", 0xb3868c, 0x978

	.globl gMonFrontPic_Zapdos
gMonFrontPic_Zapdos: @ 0x8B39004
	.incbin "baserom_jp.gba", 0xb39004, 0x7fc

	.globl gMonFrontPic_Moltres
gMonFrontPic_Moltres: @ 0x8B39800
	.incbin "baserom_jp.gba", 0xb39800, 0x8a8

	.globl gMonFrontPic_Dratini
gMonFrontPic_Dratini: @ 0x8B3A0A8
	.incbin "baserom_jp.gba", 0xb3a0a8, 0x50c

	.globl gMonFrontPic_Dragonair
gMonFrontPic_Dragonair: @ 0x8B3A5B4
	.incbin "baserom_jp.gba", 0xb3a5b4, 0x690

	.globl gMonFrontPic_Dragonite
gMonFrontPic_Dragonite: @ 0x8B3AC44
	.incbin "baserom_jp.gba", 0xb3ac44, 0x928

	.globl gMonFrontPic_Mewtwo
gMonFrontPic_Mewtwo: @ 0x8B3B56C
	.incbin "baserom_jp.gba", 0xb3b56c, 0x7a8

	.globl gMonFrontPic_Mew
gMonFrontPic_Mew: @ 0x8B3BD14
	.incbin "baserom_jp.gba", 0xb3bd14, 0x4e0

	.globl gMonFrontPic_Chikorita
gMonFrontPic_Chikorita: @ 0x8B3C1F4
	.incbin "baserom_jp.gba", 0xb3c1f4, 0x498

	.globl gMonFrontPic_Bayleef
gMonFrontPic_Bayleef: @ 0x8B3C68C
	.incbin "baserom_jp.gba", 0xb3c68c, 0x614

	.globl gMonFrontPic_Meganium
gMonFrontPic_Meganium: @ 0x8B3CCA0
	.incbin "baserom_jp.gba", 0xb3cca0, 0x934

	.globl gMonFrontPic_Cyndaquil
gMonFrontPic_Cyndaquil: @ 0x8B3D5D4
	.incbin "baserom_jp.gba", 0xb3d5d4, 0x4c0

	.globl gMonFrontPic_Quilava
gMonFrontPic_Quilava: @ 0x8B3DA94
	.incbin "baserom_jp.gba", 0xb3da94, 0x5ec

	.globl gMonFrontPic_Typhlosion
gMonFrontPic_Typhlosion: @ 0x8B3E080
	.incbin "baserom_jp.gba", 0xb3e080, 0x718

	.globl gMonFrontPic_Totodile
gMonFrontPic_Totodile: @ 0x8B3E798
	.incbin "baserom_jp.gba", 0xb3e798, 0x4c8

	.globl gMonFrontPic_Croconaw
gMonFrontPic_Croconaw: @ 0x8B3EC60
	.incbin "baserom_jp.gba", 0xb3ec60, 0x65c

	.globl gMonFrontPic_Feraligatr
gMonFrontPic_Feraligatr: @ 0x8B3F2BC
	.incbin "baserom_jp.gba", 0xb3f2bc, 0x8d4

	.globl gMonFrontPic_Sentret
gMonFrontPic_Sentret: @ 0x8B3FB90
	.incbin "baserom_jp.gba", 0xb3fb90, 0x4cc

	.globl gMonFrontPic_Furret
gMonFrontPic_Furret: @ 0x8B4005C
	.incbin "baserom_jp.gba", 0xb4005c, 0x5f4

	.globl gMonFrontPic_Hoothoot
gMonFrontPic_Hoothoot: @ 0x8B40650
	.incbin "baserom_jp.gba", 0xb40650, 0x3fc

	.globl gMonFrontPic_Noctowl
gMonFrontPic_Noctowl: @ 0x8B40A4C
	.incbin "baserom_jp.gba", 0xb40a4c, 0x6b4

	.globl gMonFrontPic_Ledyba
gMonFrontPic_Ledyba: @ 0x8B41100
	.incbin "baserom_jp.gba", 0xb41100, 0x51c

	.globl gMonFrontPic_Ledian
gMonFrontPic_Ledian: @ 0x8B4161C
	.incbin "baserom_jp.gba", 0xb4161c, 0x4d0

	.globl gMonFrontPic_Spinarak
gMonFrontPic_Spinarak: @ 0x8B41AEC
	.incbin "baserom_jp.gba", 0xb41aec, 0x448

	.globl gMonFrontPic_Ariados
gMonFrontPic_Ariados: @ 0x8B41F34
	.incbin "baserom_jp.gba", 0xb41f34, 0x6f4

	.globl gMonFrontPic_Crobat
gMonFrontPic_Crobat: @ 0x8B42628
	.incbin "baserom_jp.gba", 0xb42628, 0x5d4

	.globl gMonFrontPic_Chinchou
gMonFrontPic_Chinchou: @ 0x8B42BFC
	.incbin "baserom_jp.gba", 0xb42bfc, 0x504

	.globl gMonFrontPic_Lanturn
gMonFrontPic_Lanturn: @ 0x8B43100
	.incbin "baserom_jp.gba", 0xb43100, 0x648

	.globl gMonFrontPic_Pichu
gMonFrontPic_Pichu: @ 0x8B43748
	.incbin "baserom_jp.gba", 0xb43748, 0x3b8

	.globl gMonFrontPic_Cleffa
gMonFrontPic_Cleffa: @ 0x8B43B00
	.incbin "baserom_jp.gba", 0xb43b00, 0x3bc

	.globl gMonFrontPic_Igglybuff
gMonFrontPic_Igglybuff: @ 0x8B43EBC
	.incbin "baserom_jp.gba", 0xb43ebc, 0x36c

	.globl gMonFrontPic_Togepi
gMonFrontPic_Togepi: @ 0x8B44228
	.incbin "baserom_jp.gba", 0xb44228, 0x324

	.globl gMonFrontPic_Togetic
gMonFrontPic_Togetic: @ 0x8B4454C
	.incbin "baserom_jp.gba", 0xb4454c, 0x490

	.globl gMonFrontPic_Natu
gMonFrontPic_Natu: @ 0x8B449DC
	.incbin "baserom_jp.gba", 0xb449dc, 0x32c

	.globl gMonFrontPic_Xatu
gMonFrontPic_Xatu: @ 0x8B44D08
	.incbin "baserom_jp.gba", 0xb44d08, 0x594

	.globl gMonFrontPic_Mareep
gMonFrontPic_Mareep: @ 0x8B4529C
	.incbin "baserom_jp.gba", 0xb4529c, 0x4a8

	.globl gMonFrontPic_Flaaffy
gMonFrontPic_Flaaffy: @ 0x8B45744
	.incbin "baserom_jp.gba", 0xb45744, 0x4f0

	.globl gMonFrontPic_Ampharos
gMonFrontPic_Ampharos: @ 0x8B45C34
	.incbin "baserom_jp.gba", 0xb45c34, 0x68c

	.globl gMonFrontPic_Bellossom
gMonFrontPic_Bellossom: @ 0x8B462C0
	.incbin "baserom_jp.gba", 0xb462c0, 0x498

	.globl gMonFrontPic_Marill
gMonFrontPic_Marill: @ 0x8B46758
	.incbin "baserom_jp.gba", 0xb46758, 0x52c

	.globl gMonFrontPic_Azumarill
gMonFrontPic_Azumarill: @ 0x8B46C84
	.incbin "baserom_jp.gba", 0xb46c84, 0x5a4

	.globl gMonFrontPic_Sudowoodo
gMonFrontPic_Sudowoodo: @ 0x8B47228
	.incbin "baserom_jp.gba", 0xb47228, 0x5bc

	.globl gMonFrontPic_Politoed
gMonFrontPic_Politoed: @ 0x8B477E4
	.incbin "baserom_jp.gba", 0xb477e4, 0x608

	.globl gMonFrontPic_Hoppip
gMonFrontPic_Hoppip: @ 0x8B47DEC
	.incbin "baserom_jp.gba", 0xb47dec, 0x4c8

	.globl gMonFrontPic_Skiploom
gMonFrontPic_Skiploom: @ 0x8B482B4
	.incbin "baserom_jp.gba", 0xb482b4, 0x444

	.globl gMonFrontPic_Jumpluff
gMonFrontPic_Jumpluff: @ 0x8B486F8
	.incbin "baserom_jp.gba", 0xb486f8, 0x580

	.globl gMonFrontPic_Aipom
gMonFrontPic_Aipom: @ 0x8B48C78
	.incbin "baserom_jp.gba", 0xb48c78, 0x500

	.globl gMonFrontPic_Sunkern
gMonFrontPic_Sunkern: @ 0x8B49178
	.incbin "baserom_jp.gba", 0xb49178, 0x3a0

	.globl gMonFrontPic_Sunflora
gMonFrontPic_Sunflora: @ 0x8B49518
	.incbin "baserom_jp.gba", 0xb49518, 0x598

	.globl gMonFrontPic_Yanma
gMonFrontPic_Yanma: @ 0x8B49AB0
	.incbin "baserom_jp.gba", 0xb49ab0, 0x58c

	.globl gMonFrontPic_Wooper
gMonFrontPic_Wooper: @ 0x8B4A03C
	.incbin "baserom_jp.gba", 0xb4a03c, 0x3c0

	.globl gMonFrontPic_Quagsire
gMonFrontPic_Quagsire: @ 0x8B4A3FC
	.incbin "baserom_jp.gba", 0xb4a3fc, 0x684

	.globl gMonFrontPic_Espeon
gMonFrontPic_Espeon: @ 0x8B4AA80
	.incbin "baserom_jp.gba", 0xb4aa80, 0x5e0

	.globl gMonFrontPic_Umbreon
gMonFrontPic_Umbreon: @ 0x8B4B060
	.incbin "baserom_jp.gba", 0xb4b060, 0x5b0

	.globl gMonFrontPic_Murkrow
gMonFrontPic_Murkrow: @ 0x8B4B610
	.incbin "baserom_jp.gba", 0xb4b610, 0x55c

	.globl gMonFrontPic_Slowking
gMonFrontPic_Slowking: @ 0x8B4BB6C
	.incbin "baserom_jp.gba", 0xb4bb6c, 0x6c8

	.globl gMonFrontPic_Misdreavus
gMonFrontPic_Misdreavus: @ 0x8B4C234
	.incbin "baserom_jp.gba", 0xb4c234, 0x4fc

	.globl gMonFrontPic_UnownA
gMonFrontPic_UnownA: @ 0x8B4C730
	.incbin "baserom_jp.gba", 0xb4c730, 0x2c4

	.globl gMonFrontPic_Wobbuffet
gMonFrontPic_Wobbuffet: @ 0x8B4C9F4
	.incbin "baserom_jp.gba", 0xb4c9f4, 0x5d0

	.globl gMonFrontPic_Girafarig
gMonFrontPic_Girafarig: @ 0x8B4CFC4
	.incbin "baserom_jp.gba", 0xb4cfc4, 0x798

	.globl gMonFrontPic_Pineco
gMonFrontPic_Pineco: @ 0x8B4D75C
	.incbin "baserom_jp.gba", 0xb4d75c, 0x488

	.globl gMonFrontPic_Forretress
gMonFrontPic_Forretress: @ 0x8B4DBE4
	.incbin "baserom_jp.gba", 0xb4dbe4, 0x604

	.globl gMonFrontPic_Dunsparce
gMonFrontPic_Dunsparce: @ 0x8B4E1E8
	.incbin "baserom_jp.gba", 0xb4e1e8, 0x554

	.globl gMonFrontPic_Gligar
gMonFrontPic_Gligar: @ 0x8B4E73C
	.incbin "baserom_jp.gba", 0xb4e73c, 0x730

	.globl gMonFrontPic_Steelix
gMonFrontPic_Steelix: @ 0x8B4EE6C
	.incbin "baserom_jp.gba", 0xb4ee6c, 0x8d0

	.globl gMonFrontPic_Snubbull
gMonFrontPic_Snubbull: @ 0x8B4F73C
	.incbin "baserom_jp.gba", 0xb4f73c, 0x4f0

	.globl gMonFrontPic_Granbull
gMonFrontPic_Granbull: @ 0x8B4FC2C
	.incbin "baserom_jp.gba", 0xb4fc2c, 0x6a0

	.globl gMonFrontPic_Qwilfish
gMonFrontPic_Qwilfish: @ 0x8B502CC
	.incbin "baserom_jp.gba", 0xb502cc, 0x4b4

	.globl gMonFrontPic_Scizor
gMonFrontPic_Scizor: @ 0x8B50780
	.incbin "baserom_jp.gba", 0xb50780, 0x88c

	.globl gMonFrontPic_Shuckle
gMonFrontPic_Shuckle: @ 0x8B5100C
	.incbin "baserom_jp.gba", 0xb5100c, 0x464

	.globl gMonFrontPic_Heracross
gMonFrontPic_Heracross: @ 0x8B51470
	.incbin "baserom_jp.gba", 0xb51470, 0x694

	.globl gMonFrontPic_Sneasel
gMonFrontPic_Sneasel: @ 0x8B51B04
	.incbin "baserom_jp.gba", 0xb51b04, 0x610

	.globl gMonFrontPic_Teddiursa
gMonFrontPic_Teddiursa: @ 0x8B52114
	.incbin "baserom_jp.gba", 0xb52114, 0x3ac

	.globl gMonFrontPic_Ursaring
gMonFrontPic_Ursaring: @ 0x8B524C0
	.incbin "baserom_jp.gba", 0xb524c0, 0x78c

	.globl gMonFrontPic_Slugma
gMonFrontPic_Slugma: @ 0x8B52C4C
	.incbin "baserom_jp.gba", 0xb52c4c, 0x430

	.globl gMonFrontPic_Magcargo
gMonFrontPic_Magcargo: @ 0x8B5307C
	.incbin "baserom_jp.gba", 0xb5307c, 0x660

	.globl gMonFrontPic_Swinub
gMonFrontPic_Swinub: @ 0x8B536DC
	.incbin "baserom_jp.gba", 0xb536dc, 0x3a0

	.globl gMonFrontPic_Piloswine
gMonFrontPic_Piloswine: @ 0x8B53A7C
	.incbin "baserom_jp.gba", 0xb53a7c, 0x53c

	.globl gMonFrontPic_Corsola
gMonFrontPic_Corsola: @ 0x8B53FB8
	.incbin "baserom_jp.gba", 0xb53fb8, 0x554

	.globl gMonFrontPic_Remoraid
gMonFrontPic_Remoraid: @ 0x8B5450C
	.incbin "baserom_jp.gba", 0xb5450c, 0x454

	.globl gMonFrontPic_Octillery
gMonFrontPic_Octillery: @ 0x8B54960
	.incbin "baserom_jp.gba", 0xb54960, 0x584

	.globl gMonFrontPic_Delibird
gMonFrontPic_Delibird: @ 0x8B54EE4
	.incbin "baserom_jp.gba", 0xb54ee4, 0x630

	.globl gMonFrontPic_Mantine
gMonFrontPic_Mantine: @ 0x8B55514
	.incbin "baserom_jp.gba", 0xb55514, 0x84c

	.globl gMonFrontPic_Skarmory
gMonFrontPic_Skarmory: @ 0x8B55D60
	.incbin "baserom_jp.gba", 0xb55d60, 0x80c

	.globl gMonFrontPic_Houndour
gMonFrontPic_Houndour: @ 0x8B5656C
	.incbin "baserom_jp.gba", 0xb5656c, 0x504

	.globl gMonFrontPic_Houndoom
gMonFrontPic_Houndoom: @ 0x8B56A70
	.incbin "baserom_jp.gba", 0xb56a70, 0x6f4

	.globl gMonFrontPic_Kingdra
gMonFrontPic_Kingdra: @ 0x8B57164
	.incbin "baserom_jp.gba", 0xb57164, 0x79c

	.globl gMonFrontPic_Phanpy
gMonFrontPic_Phanpy: @ 0x8B57900
	.incbin "baserom_jp.gba", 0xb57900, 0x474

	.globl gMonFrontPic_Donphan
gMonFrontPic_Donphan: @ 0x8B57D74
	.incbin "baserom_jp.gba", 0xb57d74, 0x6f8

	.globl gMonFrontPic_Porygon2
gMonFrontPic_Porygon2: @ 0x8B5846C
	.incbin "baserom_jp.gba", 0xb5846c, 0x47c

	.globl gMonFrontPic_Stantler
gMonFrontPic_Stantler: @ 0x8B588E8
	.incbin "baserom_jp.gba", 0xb588e8, 0x774

	.globl gMonFrontPic_Smeargle
gMonFrontPic_Smeargle: @ 0x8B5905C
	.incbin "baserom_jp.gba", 0xb5905c, 0x6b0

	.globl gMonFrontPic_Tyrogue
gMonFrontPic_Tyrogue: @ 0x8B5970C
	.incbin "baserom_jp.gba", 0xb5970c, 0x4c8

	.globl gMonFrontPic_Hitmontop
gMonFrontPic_Hitmontop: @ 0x8B59BD4
	.incbin "baserom_jp.gba", 0xb59bd4, 0x5e0

	.globl gMonFrontPic_Smoochum
gMonFrontPic_Smoochum: @ 0x8B5A1B4
	.incbin "baserom_jp.gba", 0xb5a1b4, 0x3f0

	.globl gMonFrontPic_Elekid
gMonFrontPic_Elekid: @ 0x8B5A5A4
	.incbin "baserom_jp.gba", 0xb5a5a4, 0x5b4

	.globl gMonFrontPic_Magby
gMonFrontPic_Magby: @ 0x8B5AB58
	.incbin "baserom_jp.gba", 0xb5ab58, 0x4ac

	.globl gMonFrontPic_Miltank
gMonFrontPic_Miltank: @ 0x8B5B004
	.incbin "baserom_jp.gba", 0xb5b004, 0x6bc

	.globl gMonFrontPic_Blissey
gMonFrontPic_Blissey: @ 0x8B5B6C0
	.incbin "baserom_jp.gba", 0xb5b6c0, 0x66c

	.globl gMonFrontPic_Raikou
gMonFrontPic_Raikou: @ 0x8B5BD2C
	.incbin "baserom_jp.gba", 0xb5bd2c, 0xa0c

	.globl gMonFrontPic_Entei
gMonFrontPic_Entei: @ 0x8B5C738
	.incbin "baserom_jp.gba", 0xb5c738, 0x894

	.globl gMonFrontPic_Suicune
gMonFrontPic_Suicune: @ 0x8B5CFCC
	.incbin "baserom_jp.gba", 0xb5cfcc, 0xa68

	.globl gMonFrontPic_Larvitar
gMonFrontPic_Larvitar: @ 0x8B5DA34
	.incbin "baserom_jp.gba", 0xb5da34, 0x48c

	.globl gMonFrontPic_Pupitar
gMonFrontPic_Pupitar: @ 0x8B5DEC0
	.incbin "baserom_jp.gba", 0xb5dec0, 0x448

	.globl gMonFrontPic_Tyranitar
gMonFrontPic_Tyranitar: @ 0x8B5E308
	.incbin "baserom_jp.gba", 0xb5e308, 0x960

	.globl gMonFrontPic_Lugia
gMonFrontPic_Lugia: @ 0x8B5EC68
	.incbin "baserom_jp.gba", 0xb5ec68, 0x894

	.globl gMonFrontPic_HoOh
gMonFrontPic_HoOh: @ 0x8B5F4FC
	.incbin "baserom_jp.gba", 0xb5f4fc, 0xb94

	.globl gMonFrontPic_Celebi
gMonFrontPic_Celebi: @ 0x8B60090
	.incbin "baserom_jp.gba", 0xb60090, 0x4b4

	.globl gMonFrontPic_DoubleQuestionMark
gMonFrontPic_DoubleQuestionMark: @ 0x8B60544
	.incbin "baserom_jp.gba", 0xb60544, 0x270

	.globl gMonFrontPic_Treecko
gMonFrontPic_Treecko: @ 0x8B607B4
	.incbin "baserom_jp.gba", 0xb607b4, 0x574

	.globl gMonFrontPic_Grovyle
gMonFrontPic_Grovyle: @ 0x8B60D28
	.incbin "baserom_jp.gba", 0xb60d28, 0x854

	.globl gMonFrontPic_Sceptile
gMonFrontPic_Sceptile: @ 0x8B6157C
	.incbin "baserom_jp.gba", 0xb6157c, 0x720

	.globl gMonFrontPic_Torchic
gMonFrontPic_Torchic: @ 0x8B61C9C
	.incbin "baserom_jp.gba", 0xb61c9c, 0x4f0

	.globl gMonFrontPic_Combusken
gMonFrontPic_Combusken: @ 0x8B6218C
	.incbin "baserom_jp.gba", 0xb6218c, 0x7d8

	.globl gMonFrontPic_Blaziken
gMonFrontPic_Blaziken: @ 0x8B62964
	.incbin "baserom_jp.gba", 0xb62964, 0x74c

	.globl gMonFrontPic_Mudkip
gMonFrontPic_Mudkip: @ 0x8B630B0
	.incbin "baserom_jp.gba", 0xb630b0, 0x534

	.globl gMonFrontPic_Marshtomp
gMonFrontPic_Marshtomp: @ 0x8B635E4
	.incbin "baserom_jp.gba", 0xb635e4, 0x610

	.globl gMonFrontPic_Swampert
gMonFrontPic_Swampert: @ 0x8B63BF4
	.incbin "baserom_jp.gba", 0xb63bf4, 0x970

	.globl gMonFrontPic_Poochyena
gMonFrontPic_Poochyena: @ 0x8B64564
	.incbin "baserom_jp.gba", 0xb64564, 0x55c

	.globl gMonFrontPic_Mightyena
gMonFrontPic_Mightyena: @ 0x8B64AC0
	.incbin "baserom_jp.gba", 0xb64ac0, 0x7d4

	.globl gMonFrontPic_Zigzagoon
gMonFrontPic_Zigzagoon: @ 0x8B65294
	.incbin "baserom_jp.gba", 0xb65294, 0x71c

	.globl gMonFrontPic_Linoone
gMonFrontPic_Linoone: @ 0x8B659B0
	.incbin "baserom_jp.gba", 0xb659b0, 0x5ec

	.globl gMonFrontPic_Wurmple
gMonFrontPic_Wurmple: @ 0x8B65F9C
	.incbin "baserom_jp.gba", 0xb65f9c, 0x4fc

	.globl gMonFrontPic_Silcoon
gMonFrontPic_Silcoon: @ 0x8B66498
	.incbin "baserom_jp.gba", 0xb66498, 0x398

	.globl gMonFrontPic_Beautifly
gMonFrontPic_Beautifly: @ 0x8B66830
	.incbin "baserom_jp.gba", 0xb66830, 0x58c

	.globl gMonFrontPic_Cascoon
gMonFrontPic_Cascoon: @ 0x8B66DBC
	.incbin "baserom_jp.gba", 0xb66dbc, 0x374

	.globl gMonFrontPic_Dustox
gMonFrontPic_Dustox: @ 0x8B67130
	.incbin "baserom_jp.gba", 0xb67130, 0x604

	.globl gMonFrontPic_Lotad
gMonFrontPic_Lotad: @ 0x8B67734
	.incbin "baserom_jp.gba", 0xb67734, 0x448

	.globl gMonFrontPic_Lombre
gMonFrontPic_Lombre: @ 0x8B67B7C
	.incbin "baserom_jp.gba", 0xb67b7c, 0x5a4

	.globl gMonFrontPic_Ludicolo
gMonFrontPic_Ludicolo: @ 0x8B68120
	.incbin "baserom_jp.gba", 0xb68120, 0x7d0

	.globl gMonFrontPic_Seedot
gMonFrontPic_Seedot: @ 0x8B688F0
	.incbin "baserom_jp.gba", 0xb688f0, 0x4c4

	.globl gMonFrontPic_Nuzleaf
gMonFrontPic_Nuzleaf: @ 0x8B68DB4
	.incbin "baserom_jp.gba", 0xb68db4, 0x4c4

	.globl gMonFrontPic_Shiftry
gMonFrontPic_Shiftry: @ 0x8B69278
	.incbin "baserom_jp.gba", 0xb69278, 0x600

	.globl gMonFrontPic_Nincada
gMonFrontPic_Nincada: @ 0x8B69878
	.incbin "baserom_jp.gba", 0xb69878, 0x48c

	.globl gMonFrontPic_Ninjask
gMonFrontPic_Ninjask: @ 0x8B69D04
	.incbin "baserom_jp.gba", 0xb69d04, 0x538

	.globl gMonFrontPic_Shedinja
gMonFrontPic_Shedinja: @ 0x8B6A23C
	.incbin "baserom_jp.gba", 0xb6a23c, 0x5e0

	.globl gMonFrontPic_Taillow
gMonFrontPic_Taillow: @ 0x8B6A81C
	.incbin "baserom_jp.gba", 0xb6a81c, 0x540

	.globl gMonFrontPic_Swellow
gMonFrontPic_Swellow: @ 0x8B6AD5C
	.incbin "baserom_jp.gba", 0xb6ad5c, 0x56c

	.globl gMonFrontPic_Shroomish
gMonFrontPic_Shroomish: @ 0x8B6B2C8
	.incbin "baserom_jp.gba", 0xb6b2c8, 0x3c8

	.globl gMonFrontPic_Breloom
gMonFrontPic_Breloom: @ 0x8B6B690
	.incbin "baserom_jp.gba", 0xb6b690, 0x6ac

	.globl gMonFrontPic_Spinda
gMonFrontPic_Spinda: @ 0x8B6BD3C
	.incbin "baserom_jp.gba", 0xb6bd3c, 0x3f4

	.globl gMonFrontPic_Wingull
gMonFrontPic_Wingull: @ 0x8B6C130
	.incbin "baserom_jp.gba", 0xb6c130, 0x3e4

	.globl gMonFrontPic_Pelipper
gMonFrontPic_Pelipper: @ 0x8B6C514
	.incbin "baserom_jp.gba", 0xb6c514, 0x5f8

	.globl gMonFrontPic_Surskit
gMonFrontPic_Surskit: @ 0x8B6CB0C
	.incbin "baserom_jp.gba", 0xb6cb0c, 0x3a4

	.globl gMonFrontPic_Masquerain
gMonFrontPic_Masquerain: @ 0x8B6CEB0
	.incbin "baserom_jp.gba", 0xb6ceb0, 0x640

	.globl gMonFrontPic_Wailmer
gMonFrontPic_Wailmer: @ 0x8B6D4F0
	.incbin "baserom_jp.gba", 0xb6d4f0, 0x4b4

	.globl gMonFrontPic_Wailord
gMonFrontPic_Wailord: @ 0x8B6D9A4
	.incbin "baserom_jp.gba", 0xb6d9a4, 0x678

	.globl gMonFrontPic_Skitty
gMonFrontPic_Skitty: @ 0x8B6E01C
	.incbin "baserom_jp.gba", 0xb6e01c, 0x56c

	.globl gMonFrontPic_Delcatty
gMonFrontPic_Delcatty: @ 0x8B6E588
	.incbin "baserom_jp.gba", 0xb6e588, 0x658

	.globl gMonFrontPic_Kecleon
gMonFrontPic_Kecleon: @ 0x8B6EBE0
	.incbin "baserom_jp.gba", 0xb6ebe0, 0x694

	.globl gMonFrontPic_Baltoy
gMonFrontPic_Baltoy: @ 0x8B6F274
	.incbin "baserom_jp.gba", 0xb6f274, 0x3b8

	.globl gMonFrontPic_Claydol
gMonFrontPic_Claydol: @ 0x8B6F62C
	.incbin "baserom_jp.gba", 0xb6f62c, 0x6dc

	.globl gMonFrontPic_Nosepass
gMonFrontPic_Nosepass: @ 0x8B6FD08
	.incbin "baserom_jp.gba", 0xb6fd08, 0x560

	.globl gMonFrontPic_Torkoal
gMonFrontPic_Torkoal: @ 0x8B70268
	.incbin "baserom_jp.gba", 0xb70268, 0x7f0

	.globl gMonFrontPic_Sableye
gMonFrontPic_Sableye: @ 0x8B70A58
	.incbin "baserom_jp.gba", 0xb70a58, 0x4a0

	.globl gMonFrontPic_Barboach
gMonFrontPic_Barboach: @ 0x8B70EF8
	.incbin "baserom_jp.gba", 0xb70ef8, 0x508

	.globl gMonFrontPic_Whiscash
gMonFrontPic_Whiscash: @ 0x8B71400
	.incbin "baserom_jp.gba", 0xb71400, 0x57c

	.globl gMonFrontPic_Luvdisc
gMonFrontPic_Luvdisc: @ 0x8B7197C
	.incbin "baserom_jp.gba", 0xb7197c, 0x334

	.globl gMonFrontPic_Corphish
gMonFrontPic_Corphish: @ 0x8B71CB0
	.incbin "baserom_jp.gba", 0xb71cb0, 0x534

	.globl gMonFrontPic_Crawdaunt
gMonFrontPic_Crawdaunt: @ 0x8B721E4
	.incbin "baserom_jp.gba", 0xb721e4, 0x73c

	.globl gMonFrontPic_Feebas
gMonFrontPic_Feebas: @ 0x8B72920
	.incbin "baserom_jp.gba", 0xb72920, 0x510

	.globl gMonFrontPic_Milotic
gMonFrontPic_Milotic: @ 0x8B72E30
	.incbin "baserom_jp.gba", 0xb72e30, 0x8cc

	.globl gMonFrontPic_Carvanha
gMonFrontPic_Carvanha: @ 0x8B736FC
	.incbin "baserom_jp.gba", 0xb736fc, 0x620

	.globl gMonFrontPic_Sharpedo
gMonFrontPic_Sharpedo: @ 0x8B73D1C
	.incbin "baserom_jp.gba", 0xb73d1c, 0x630

	.globl gMonFrontPic_Trapinch
gMonFrontPic_Trapinch: @ 0x8B7434C
	.incbin "baserom_jp.gba", 0xb7434c, 0x3d4

	.globl gMonFrontPic_Vibrava
gMonFrontPic_Vibrava: @ 0x8B74720
	.incbin "baserom_jp.gba", 0xb74720, 0x690

	.globl gMonFrontPic_Flygon
gMonFrontPic_Flygon: @ 0x8B74DB0
	.incbin "baserom_jp.gba", 0xb74db0, 0x864

	.globl gMonFrontPic_Makuhita
gMonFrontPic_Makuhita: @ 0x8B75614
	.incbin "baserom_jp.gba", 0xb75614, 0x4bc

	.globl gMonFrontPic_Hariyama
gMonFrontPic_Hariyama: @ 0x8B75AD0
	.incbin "baserom_jp.gba", 0xb75ad0, 0x900

	.globl gMonFrontPic_Electrike
gMonFrontPic_Electrike: @ 0x8B763D0
	.incbin "baserom_jp.gba", 0xb763d0, 0x4d0

	.globl gMonFrontPic_Manectric
gMonFrontPic_Manectric: @ 0x8B768A0
	.incbin "baserom_jp.gba", 0xb768a0, 0x5fc

	.globl gMonFrontPic_Numel
gMonFrontPic_Numel: @ 0x8B76E9C
	.incbin "baserom_jp.gba", 0xb76e9c, 0x51c

	.globl gMonFrontPic_Camerupt
gMonFrontPic_Camerupt: @ 0x8B773B8
	.incbin "baserom_jp.gba", 0xb773b8, 0x624

	.globl gMonFrontPic_Spheal
gMonFrontPic_Spheal: @ 0x8B779DC
	.incbin "baserom_jp.gba", 0xb779dc, 0x430

	.globl gMonFrontPic_Sealeo
gMonFrontPic_Sealeo: @ 0x8B77E0C
	.incbin "baserom_jp.gba", 0xb77e0c, 0x678

	.globl gMonFrontPic_Walrein
gMonFrontPic_Walrein: @ 0x8B78484
	.incbin "baserom_jp.gba", 0xb78484, 0x7d0

	.globl gMonFrontPic_Cacnea
gMonFrontPic_Cacnea: @ 0x8B78C54
	.incbin "baserom_jp.gba", 0xb78c54, 0x518

	.globl gMonFrontPic_Cacturne
gMonFrontPic_Cacturne: @ 0x8B7916C
	.incbin "baserom_jp.gba", 0xb7916c, 0x7bc

	.globl gMonFrontPic_Snorunt
gMonFrontPic_Snorunt: @ 0x8B79928
	.incbin "baserom_jp.gba", 0xb79928, 0x51c

	.globl gMonFrontPic_Glalie
gMonFrontPic_Glalie: @ 0x8B79E44
	.incbin "baserom_jp.gba", 0xb79e44, 0x724

	.globl gMonFrontPic_Lunatone
gMonFrontPic_Lunatone: @ 0x8B7A568
	.incbin "baserom_jp.gba", 0xb7a568, 0x528

	.globl gMonFrontPic_Solrock
gMonFrontPic_Solrock: @ 0x8B7AA90
	.incbin "baserom_jp.gba", 0xb7aa90, 0x7d4

	.globl gMonFrontPic_Azurill
gMonFrontPic_Azurill: @ 0x8B7B264
	.incbin "baserom_jp.gba", 0xb7b264, 0x550

	.globl gMonFrontPic_Spoink
gMonFrontPic_Spoink: @ 0x8B7B7B4
	.incbin "baserom_jp.gba", 0xb7b7b4, 0x3ec

	.globl gMonFrontPic_Grumpig
gMonFrontPic_Grumpig: @ 0x8B7BBA0
	.incbin "baserom_jp.gba", 0xb7bba0, 0x6b8

	.globl gMonFrontPic_Plusle
gMonFrontPic_Plusle: @ 0x8B7C258
	.incbin "baserom_jp.gba", 0xb7c258, 0x49c

	.globl gMonFrontPic_Minun
gMonFrontPic_Minun: @ 0x8B7C6F4
	.incbin "baserom_jp.gba", 0xb7c6f4, 0x420

	.globl gMonFrontPic_Mawile
gMonFrontPic_Mawile: @ 0x8B7CB14
	.incbin "baserom_jp.gba", 0xb7cb14, 0x790

	.globl gMonFrontPic_Meditite
gMonFrontPic_Meditite: @ 0x8B7D2A4
	.incbin "baserom_jp.gba", 0xb7d2a4, 0x440

	.globl gMonFrontPic_Medicham
gMonFrontPic_Medicham: @ 0x8B7D6E4
	.incbin "baserom_jp.gba", 0xb7d6e4, 0x558

	.globl gMonFrontPic_Swablu
gMonFrontPic_Swablu: @ 0x8B7DC3C
	.incbin "baserom_jp.gba", 0xb7dc3c, 0x4ec

	.globl gMonFrontPic_Altaria
gMonFrontPic_Altaria: @ 0x8B7E128
	.incbin "baserom_jp.gba", 0xb7e128, 0x71c

	.globl gMonFrontPic_Wynaut
gMonFrontPic_Wynaut: @ 0x8B7E844
	.incbin "baserom_jp.gba", 0xb7e844, 0x474

	.globl gMonFrontPic_Duskull
gMonFrontPic_Duskull: @ 0x8B7ECB8
	.incbin "baserom_jp.gba", 0xb7ecb8, 0x570

	.globl gMonFrontPic_Dusclops
gMonFrontPic_Dusclops: @ 0x8B7F228
	.incbin "baserom_jp.gba", 0xb7f228, 0x6b0

	.globl gMonFrontPic_Roselia
gMonFrontPic_Roselia: @ 0x8B7F8D8
	.incbin "baserom_jp.gba", 0xb7f8d8, 0x610

	.globl gMonFrontPic_Slakoth
gMonFrontPic_Slakoth: @ 0x8B7FEE8
	.incbin "baserom_jp.gba", 0xb7fee8, 0x3f0

	.globl gMonFrontPic_Vigoroth
gMonFrontPic_Vigoroth: @ 0x8B802D8
	.incbin "baserom_jp.gba", 0xb802d8, 0x7b0

	.globl gMonFrontPic_Slaking
gMonFrontPic_Slaking: @ 0x8B80A88
	.incbin "baserom_jp.gba", 0xb80a88, 0x6ac

	.globl gMonFrontPic_Gulpin
gMonFrontPic_Gulpin: @ 0x8B81134
	.incbin "baserom_jp.gba", 0xb81134, 0x3b0

	.globl gMonFrontPic_Swalot
gMonFrontPic_Swalot: @ 0x8B814E4
	.incbin "baserom_jp.gba", 0xb814e4, 0x594

	.globl gMonFrontPic_Tropius
gMonFrontPic_Tropius: @ 0x8B81A78
	.incbin "baserom_jp.gba", 0xb81a78, 0x924

	.globl gMonFrontPic_Whismur
gMonFrontPic_Whismur: @ 0x8B8239C
	.incbin "baserom_jp.gba", 0xb8239c, 0x46c

	.globl gMonFrontPic_Loudred
gMonFrontPic_Loudred: @ 0x8B82808
	.incbin "baserom_jp.gba", 0xb82808, 0x6f8

	.globl gMonFrontPic_Exploud
gMonFrontPic_Exploud: @ 0x8B82F00
	.incbin "baserom_jp.gba", 0xb82f00, 0xa08

	.globl gMonFrontPic_Clamperl
gMonFrontPic_Clamperl: @ 0x8B83908
	.incbin "baserom_jp.gba", 0xb83908, 0x4ac

	.globl gMonFrontPic_Huntail
gMonFrontPic_Huntail: @ 0x8B83DB4
	.incbin "baserom_jp.gba", 0xb83db4, 0x6f4

	.globl gMonFrontPic_Gorebyss
gMonFrontPic_Gorebyss: @ 0x8B844A8
	.incbin "baserom_jp.gba", 0xb844a8, 0x5a8

	.globl gMonFrontPic_Absol
gMonFrontPic_Absol: @ 0x8B84A50
	.incbin "baserom_jp.gba", 0xb84a50, 0x770

	.globl gMonFrontPic_Shuppet
gMonFrontPic_Shuppet: @ 0x8B851C0
	.incbin "baserom_jp.gba", 0xb851c0, 0x400

	.globl gMonFrontPic_Banette
gMonFrontPic_Banette: @ 0x8B855C0
	.incbin "baserom_jp.gba", 0xb855c0, 0x50c

	.globl gMonFrontPic_Seviper
gMonFrontPic_Seviper: @ 0x8B85ACC
	.incbin "baserom_jp.gba", 0xb85acc, 0x790

	.globl gMonFrontPic_Zangoose
gMonFrontPic_Zangoose: @ 0x8B8625C
	.incbin "baserom_jp.gba", 0xb8625c, 0x71c

	.globl gMonFrontPic_Relicanth
gMonFrontPic_Relicanth: @ 0x8B86978
	.incbin "baserom_jp.gba", 0xb86978, 0x544

	.globl gMonFrontPic_Aron
gMonFrontPic_Aron: @ 0x8B86EBC
	.incbin "baserom_jp.gba", 0xb86ebc, 0x3a4

	.globl gMonFrontPic_Lairon
gMonFrontPic_Lairon: @ 0x8B87260
	.incbin "baserom_jp.gba", 0xb87260, 0x618

	.globl gMonFrontPic_Aggron
gMonFrontPic_Aggron: @ 0x8B87878
	.incbin "baserom_jp.gba", 0xb87878, 0x9d4

	.globl gMonFrontPic_Castform
gMonFrontPic_Castform: @ 0x8B8824C
	.incbin "baserom_jp.gba", 0xb8824c, 0xa88

	.globl gMonFrontPic_Volbeat
gMonFrontPic_Volbeat: @ 0x8B88CD4
	.incbin "baserom_jp.gba", 0xb88cd4, 0x618

	.globl gMonFrontPic_Illumise
gMonFrontPic_Illumise: @ 0x8B892EC
	.incbin "baserom_jp.gba", 0xb892ec, 0x680

	.globl gMonFrontPic_Lileep
gMonFrontPic_Lileep: @ 0x8B8996C
	.incbin "baserom_jp.gba", 0xb8996c, 0x5f8

	.globl gMonFrontPic_Cradily
gMonFrontPic_Cradily: @ 0x8B89F64
	.incbin "baserom_jp.gba", 0xb89f64, 0x750

	.globl gMonFrontPic_Anorith
gMonFrontPic_Anorith: @ 0x8B8A6B4
	.incbin "baserom_jp.gba", 0xb8a6b4, 0x5ec

	.globl gMonFrontPic_Armaldo
gMonFrontPic_Armaldo: @ 0x8B8ACA0
	.incbin "baserom_jp.gba", 0xb8aca0, 0x978

	.globl gMonFrontPic_Ralts
gMonFrontPic_Ralts: @ 0x8B8B618
	.incbin "baserom_jp.gba", 0xb8b618, 0x40c

	.globl gMonFrontPic_Kirlia
gMonFrontPic_Kirlia: @ 0x8B8BA24
	.incbin "baserom_jp.gba", 0xb8ba24, 0x550

	.globl gMonFrontPic_Gardevoir
gMonFrontPic_Gardevoir: @ 0x8B8BF74
	.incbin "baserom_jp.gba", 0xb8bf74, 0x534

	.globl gMonFrontPic_Bagon
gMonFrontPic_Bagon: @ 0x8B8C4A8
	.incbin "baserom_jp.gba", 0xb8c4a8, 0x494

	.globl gMonFrontPic_Shelgon
gMonFrontPic_Shelgon: @ 0x8B8C93C
	.incbin "baserom_jp.gba", 0xb8c93c, 0x56c

	.globl gMonFrontPic_Salamence
gMonFrontPic_Salamence: @ 0x8B8CEA8
	.incbin "baserom_jp.gba", 0xb8cea8, 0x760

	.globl gMonFrontPic_Beldum
gMonFrontPic_Beldum: @ 0x8B8D608
	.incbin "baserom_jp.gba", 0xb8d608, 0x464

	.globl gMonFrontPic_Metang
gMonFrontPic_Metang: @ 0x8B8DA6C
	.incbin "baserom_jp.gba", 0xb8da6c, 0x7d0

	.globl gMonFrontPic_Metagross
gMonFrontPic_Metagross: @ 0x8B8E23C
	.incbin "baserom_jp.gba", 0xb8e23c, 0x6e4

	.globl gMonFrontPic_Regirock
gMonFrontPic_Regirock: @ 0x8B8E920
	.incbin "baserom_jp.gba", 0xb8e920, 0x8c8

	.globl gMonFrontPic_Regice
gMonFrontPic_Regice: @ 0x8B8F1E8
	.incbin "baserom_jp.gba", 0xb8f1e8, 0x7ac

	.globl gMonFrontPic_Registeel
gMonFrontPic_Registeel: @ 0x8B8F994
	.incbin "baserom_jp.gba", 0xb8f994, 0x7dc

	.globl gMonFrontPic_Kyogre
gMonFrontPic_Kyogre: @ 0x8B90170
	.incbin "baserom_jp.gba", 0xb90170, 0x7d8

	.globl gMonFrontPic_Groudon
gMonFrontPic_Groudon: @ 0x8B90948
	.incbin "baserom_jp.gba", 0xb90948, 0xa14

	.globl gMonFrontPic_Rayquaza
gMonFrontPic_Rayquaza: @ 0x8B9135C
	.incbin "baserom_jp.gba", 0xb9135c, 0x994

	.globl gMonFrontPic_Latias
gMonFrontPic_Latias: @ 0x8B91CF0
	.incbin "baserom_jp.gba", 0xb91cf0, 0x688

	.globl gMonFrontPic_Latios
gMonFrontPic_Latios: @ 0x8B92378
	.incbin "baserom_jp.gba", 0xb92378, 0x830

	.globl gMonFrontPic_Jirachi
gMonFrontPic_Jirachi: @ 0x8B92BA8
	.incbin "baserom_jp.gba", 0xb92ba8, 0x5ac

	.globl gMonFrontPic_Deoxys
gMonFrontPic_Deoxys: @ 0x8B93154
	.incbin "baserom_jp.gba", 0xb93154, 0x76c

	.globl gMonFrontPic_Chimecho
gMonFrontPic_Chimecho: @ 0x8B938C0
	.incbin "baserom_jp.gba", 0xb938c0, 0x448

	.globl gMonFrontPic_Egg
gMonFrontPic_Egg: @ 0x8B93D08
	.incbin "baserom_jp.gba", 0xb93d08, 0x2bc

	.globl gMonFrontPic_UnownB
gMonFrontPic_UnownB: @ 0x8B93FC4
	.incbin "baserom_jp.gba", 0xb93fc4, 0x2c8

	.globl gMonFrontPic_UnownC
gMonFrontPic_UnownC: @ 0x8B9428C
	.incbin "baserom_jp.gba", 0xb9428c, 0x304

	.globl gMonFrontPic_UnownD
gMonFrontPic_UnownD: @ 0x8B94590
	.incbin "baserom_jp.gba", 0xb94590, 0x2e8

	.globl gMonFrontPic_UnownE
gMonFrontPic_UnownE: @ 0x8B94878
	.incbin "baserom_jp.gba", 0xb94878, 0x2a8

	.globl gMonFrontPic_UnownF
gMonFrontPic_UnownF: @ 0x8B94B20
	.incbin "baserom_jp.gba", 0xb94b20, 0x2e8

	.globl gMonFrontPic_UnownG
gMonFrontPic_UnownG: @ 0x8B94E08
	.incbin "baserom_jp.gba", 0xb94e08, 0x2cc

	.globl gMonFrontPic_UnownH
gMonFrontPic_UnownH: @ 0x8B950D4
	.incbin "baserom_jp.gba", 0xb950d4, 0x338

	.globl gMonFrontPic_UnownI
gMonFrontPic_UnownI: @ 0x8B9540C
	.incbin "baserom_jp.gba", 0xb9540c, 0x28c

	.globl gMonFrontPic_UnownJ
gMonFrontPic_UnownJ: @ 0x8B95698
	.incbin "baserom_jp.gba", 0xb95698, 0x2b8

	.globl gMonFrontPic_UnownK
gMonFrontPic_UnownK: @ 0x8B95950
	.incbin "baserom_jp.gba", 0xb95950, 0x2c0

	.globl gMonFrontPic_UnownL
gMonFrontPic_UnownL: @ 0x8B95C10
	.incbin "baserom_jp.gba", 0xb95c10, 0x2a4

	.globl gMonFrontPic_UnownM
gMonFrontPic_UnownM: @ 0x8B95EB4
	.incbin "baserom_jp.gba", 0xb95eb4, 0x314

	.globl gMonFrontPic_UnownN
gMonFrontPic_UnownN: @ 0x8B961C8
	.incbin "baserom_jp.gba", 0xb961c8, 0x2e8

	.globl gMonFrontPic_UnownO
gMonFrontPic_UnownO: @ 0x8B964B0
	.incbin "baserom_jp.gba", 0xb964b0, 0x32c

	.globl gMonFrontPic_UnownP
gMonFrontPic_UnownP: @ 0x8B967DC
	.incbin "baserom_jp.gba", 0xb967dc, 0x290

	.globl gMonFrontPic_UnownQ
gMonFrontPic_UnownQ: @ 0x8B96A6C
	.incbin "baserom_jp.gba", 0xb96a6c, 0x2a8

	.globl gMonFrontPic_UnownR
gMonFrontPic_UnownR: @ 0x8B96D14
	.incbin "baserom_jp.gba", 0xb96d14, 0x294

	.globl gMonFrontPic_UnownS
gMonFrontPic_UnownS: @ 0x8B96FA8
	.incbin "baserom_jp.gba", 0xb96fa8, 0x2dc

	.globl gMonFrontPic_UnownT
gMonFrontPic_UnownT: @ 0x8B97284
	.incbin "baserom_jp.gba", 0xb97284, 0x2a4

	.globl gMonFrontPic_UnownU
gMonFrontPic_UnownU: @ 0x8B97528
	.incbin "baserom_jp.gba", 0xb97528, 0x30c

	.globl gMonFrontPic_UnownV
gMonFrontPic_UnownV: @ 0x8B97834
	.incbin "baserom_jp.gba", 0xb97834, 0x2d8

	.globl gMonFrontPic_UnownW
gMonFrontPic_UnownW: @ 0x8B97B0C
	.incbin "baserom_jp.gba", 0xb97b0c, 0x2c8

	.globl gMonFrontPic_UnownX
gMonFrontPic_UnownX: @ 0x8B97DD4
	.incbin "baserom_jp.gba", 0xb97dd4, 0x2b4

	.globl gMonFrontPic_UnownY
gMonFrontPic_UnownY: @ 0x8B98088
	.incbin "baserom_jp.gba", 0xb98088, 0x2c8

	.globl gMonFrontPic_UnownZ
gMonFrontPic_UnownZ: @ 0x8B98350
	.incbin "baserom_jp.gba", 0xb98350, 0x2a4

	.globl gMonFrontPic_UnownExclamationMark
gMonFrontPic_UnownExclamationMark: @ 0x8B985F4
	.incbin "baserom_jp.gba", 0xb985f4, 0x284

	.globl gMonFrontPic_UnownQuestionMark
gMonFrontPic_UnownQuestionMark: @ 0x8B98878
	.incbin "baserom_jp.gba", 0xb98878, 0x67788
