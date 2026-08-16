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
	.incbin "graphics/pokemon/question_mark/circled/anim_front.4bpp.lz"

	.globl gMonFrontPic_Bulbasaur
gMonFrontPic_Bulbasaur: @ 0x8B00338
	.incbin "graphics/pokemon/bulbasaur/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ivysaur
gMonFrontPic_Ivysaur: @ 0x8B007B0
	.incbin "graphics/pokemon/ivysaur/anim_front.4bpp.lz"

	.globl gMonFrontPic_Venusaur
gMonFrontPic_Venusaur: @ 0x8B00E10
	.incbin "graphics/pokemon/venusaur/anim_front.4bpp.lz"

	.globl gMonFrontPic_Charmander
gMonFrontPic_Charmander: @ 0x8B017CC
	.incbin "graphics/pokemon/charmander/anim_front.4bpp.lz"

	.globl gMonFrontPic_Charmeleon
gMonFrontPic_Charmeleon: @ 0x8B01C7C
	.incbin "graphics/pokemon/charmeleon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Charizard
gMonFrontPic_Charizard: @ 0x8B02368
	.incbin "graphics/pokemon/charizard/anim_front.4bpp.lz"

	.globl gMonFrontPic_Squirtle
gMonFrontPic_Squirtle: @ 0x8B02D68
	.incbin "graphics/pokemon/squirtle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wartortle
gMonFrontPic_Wartortle: @ 0x8B03260
	.incbin "graphics/pokemon/wartortle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Blastoise
gMonFrontPic_Blastoise: @ 0x8B03944
	.incbin "graphics/pokemon/blastoise/anim_front.4bpp.lz"

	.globl gMonFrontPic_Caterpie
gMonFrontPic_Caterpie: @ 0x8B04280
	.incbin "graphics/pokemon/caterpie/anim_front.4bpp.lz"

	.globl gMonFrontPic_Metapod
gMonFrontPic_Metapod: @ 0x8B046FC
	.incbin "graphics/pokemon/metapod/anim_front.4bpp.lz"

	.globl gMonFrontPic_Butterfree
gMonFrontPic_Butterfree: @ 0x8B04AA8
	.incbin "graphics/pokemon/butterfree/anim_front.4bpp.lz"

	.globl gMonFrontPic_Weedle
gMonFrontPic_Weedle: @ 0x8B05080
	.incbin "graphics/pokemon/weedle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kakuna
gMonFrontPic_Kakuna: @ 0x8B05444
	.incbin "graphics/pokemon/kakuna/anim_front.4bpp.lz"

	.globl gMonFrontPic_Beedrill
gMonFrontPic_Beedrill: @ 0x8B05820
	.incbin "graphics/pokemon/beedrill/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pidgey
gMonFrontPic_Pidgey: @ 0x8B05F38
	.incbin "graphics/pokemon/pidgey/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pidgeotto
gMonFrontPic_Pidgeotto: @ 0x8B0644C
	.incbin "graphics/pokemon/pidgeotto/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pidgeot
gMonFrontPic_Pidgeot: @ 0x8B06B24
	.incbin "graphics/pokemon/pidgeot/anim_front.4bpp.lz"

	.globl gMonFrontPic_Rattata
gMonFrontPic_Rattata: @ 0x8B073DC
	.incbin "graphics/pokemon/rattata/anim_front.4bpp.lz"

	.globl gMonFrontPic_Raticate
gMonFrontPic_Raticate: @ 0x8B07828
	.incbin "graphics/pokemon/raticate/anim_front.4bpp.lz"

	.globl gMonFrontPic_Spearow
gMonFrontPic_Spearow: @ 0x8B07EA4
	.incbin "graphics/pokemon/spearow/anim_front.4bpp.lz"

	.globl gMonFrontPic_Fearow
gMonFrontPic_Fearow: @ 0x8B08388
	.incbin "graphics/pokemon/fearow/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ekans
gMonFrontPic_Ekans: @ 0x8B08BC4
	.incbin "graphics/pokemon/ekans/anim_front.4bpp.lz"

	.globl gMonFrontPic_Arbok
gMonFrontPic_Arbok: @ 0x8B0918C
	.incbin "graphics/pokemon/arbok/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pikachu
gMonFrontPic_Pikachu: @ 0x8B09964
	.incbin "graphics/pokemon/pikachu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Raichu
gMonFrontPic_Raichu: @ 0x8B09E3C
	.incbin "graphics/pokemon/raichu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sandshrew
gMonFrontPic_Sandshrew: @ 0x8B0A554
	.incbin "graphics/pokemon/sandshrew/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sandslash
gMonFrontPic_Sandslash: @ 0x8B0AA6C
	.incbin "graphics/pokemon/sandslash/anim_front.4bpp.lz"

	.globl gMonFrontPic_NidoranF
gMonFrontPic_NidoranF: @ 0x8B0B1C4
	.incbin "graphics/pokemon/nidoran_f/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nidorina
gMonFrontPic_Nidorina: @ 0x8B0B628
	.incbin "graphics/pokemon/nidorina/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nidoqueen
gMonFrontPic_Nidoqueen: @ 0x8B0BC5C
	.incbin "graphics/pokemon/nidoqueen/anim_front.4bpp.lz"

	.globl gMonFrontPic_NidoranM
gMonFrontPic_NidoranM: @ 0x8B0C4E8
	.incbin "graphics/pokemon/nidoran_m/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nidorino
gMonFrontPic_Nidorino: @ 0x8B0CA54
	.incbin "graphics/pokemon/nidorino/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nidoking
gMonFrontPic_Nidoking: @ 0x8B0D10C
	.incbin "graphics/pokemon/nidoking/anim_front.4bpp.lz"

	.globl gMonFrontPic_Clefairy
gMonFrontPic_Clefairy: @ 0x8B0D9A8
	.incbin "graphics/pokemon/clefairy/anim_front.4bpp.lz"

	.globl gMonFrontPic_Clefable
gMonFrontPic_Clefable: @ 0x8B0DE24
	.incbin "graphics/pokemon/clefable/anim_front.4bpp.lz"

	.globl gMonFrontPic_Vulpix
gMonFrontPic_Vulpix: @ 0x8B0E3A4
	.incbin "graphics/pokemon/vulpix/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ninetales
gMonFrontPic_Ninetales: @ 0x8B0EA08
	.incbin "graphics/pokemon/ninetales/anim_front.4bpp.lz"

	.globl gMonFrontPic_Jigglypuff
gMonFrontPic_Jigglypuff: @ 0x8B0F1CC
	.incbin "graphics/pokemon/jigglypuff/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wigglytuff
gMonFrontPic_Wigglytuff: @ 0x8B0F67C
	.incbin "graphics/pokemon/wigglytuff/anim_front.4bpp.lz"

	.globl gMonFrontPic_Zubat
gMonFrontPic_Zubat: @ 0x8B0FCD0
	.incbin "graphics/pokemon/zubat/anim_front.4bpp.lz"

	.globl gMonFrontPic_Golbat
gMonFrontPic_Golbat: @ 0x8B10188
	.incbin "graphics/pokemon/golbat/anim_front.4bpp.lz"

	.globl gMonFrontPic_Oddish
gMonFrontPic_Oddish: @ 0x8B10780
	.incbin "graphics/pokemon/oddish/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gloom
gMonFrontPic_Gloom: @ 0x8B10B78
	.incbin "graphics/pokemon/gloom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Vileplume
gMonFrontPic_Vileplume: @ 0x8B111B0
	.incbin "graphics/pokemon/vileplume/anim_front.4bpp.lz"

	.globl gMonFrontPic_Paras
gMonFrontPic_Paras: @ 0x8B11750
	.incbin "graphics/pokemon/paras/anim_front.4bpp.lz"

	.globl gMonFrontPic_Parasect
gMonFrontPic_Parasect: @ 0x8B11BAC
	.incbin "graphics/pokemon/parasect/anim_front.4bpp.lz"

	.globl gMonFrontPic_Venonat
gMonFrontPic_Venonat: @ 0x8B121BC
	.incbin "graphics/pokemon/venonat/anim_front.4bpp.lz"

	.globl gMonFrontPic_Venomoth
gMonFrontPic_Venomoth: @ 0x8B127A8
	.incbin "graphics/pokemon/venomoth/anim_front.4bpp.lz"

	.globl gMonFrontPic_Diglett
gMonFrontPic_Diglett: @ 0x8B12F74
	.incbin "graphics/pokemon/diglett/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dugtrio
gMonFrontPic_Dugtrio: @ 0x8B13338
	.incbin "graphics/pokemon/dugtrio/anim_front.4bpp.lz"

	.globl gMonFrontPic_Meowth
gMonFrontPic_Meowth: @ 0x8B137CC
	.incbin "graphics/pokemon/meowth/anim_front.4bpp.lz"

	.globl gMonFrontPic_Persian
gMonFrontPic_Persian: @ 0x8B13CB4
	.incbin "graphics/pokemon/persian/anim_front.4bpp.lz"

	.globl gMonFrontPic_Psyduck
gMonFrontPic_Psyduck: @ 0x8B1439C
	.incbin "graphics/pokemon/psyduck/anim_front.4bpp.lz"

	.globl gMonFrontPic_Golduck
gMonFrontPic_Golduck: @ 0x8B14904
	.incbin "graphics/pokemon/golduck/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mankey
gMonFrontPic_Mankey: @ 0x8B14F9C
	.incbin "graphics/pokemon/mankey/anim_front.4bpp.lz"

	.globl gMonFrontPic_Primeape
gMonFrontPic_Primeape: @ 0x8B15550
	.incbin "graphics/pokemon/primeape/anim_front.4bpp.lz"

	.globl gMonFrontPic_Growlithe
gMonFrontPic_Growlithe: @ 0x8B15BFC
	.incbin "graphics/pokemon/growlithe/anim_front.4bpp.lz"

	.globl gMonFrontPic_Arcanine
gMonFrontPic_Arcanine: @ 0x8B161E8
	.incbin "graphics/pokemon/arcanine/anim_front.4bpp.lz"

	.globl gMonFrontPic_Poliwag
gMonFrontPic_Poliwag: @ 0x8B16BF4
	.incbin "graphics/pokemon/poliwag/anim_front.4bpp.lz"

	.globl gMonFrontPic_Poliwhirl
gMonFrontPic_Poliwhirl: @ 0x8B170C8
	.incbin "graphics/pokemon/poliwhirl/anim_front.4bpp.lz"

	.globl gMonFrontPic_Poliwrath
gMonFrontPic_Poliwrath: @ 0x8B176B4
	.incbin "graphics/pokemon/poliwrath/anim_front.4bpp.lz"

	.globl gMonFrontPic_Abra
gMonFrontPic_Abra: @ 0x8B17D38
	.incbin "graphics/pokemon/abra/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kadabra
gMonFrontPic_Kadabra: @ 0x8B18144
	.incbin "graphics/pokemon/kadabra/anim_front.4bpp.lz"

	.globl gMonFrontPic_Alakazam
gMonFrontPic_Alakazam: @ 0x8B18910
	.incbin "graphics/pokemon/alakazam/anim_front.4bpp.lz"

	.globl gMonFrontPic_Machop
gMonFrontPic_Machop: @ 0x8B190CC
	.incbin "graphics/pokemon/machop/anim_front.4bpp.lz"

	.globl gMonFrontPic_Machoke
gMonFrontPic_Machoke: @ 0x8B194FC
	.incbin "graphics/pokemon/machoke/anim_front.4bpp.lz"

	.globl gMonFrontPic_Machamp
gMonFrontPic_Machamp: @ 0x8B19BB4
	.incbin "graphics/pokemon/machamp/anim_front.4bpp.lz"

	.globl gMonFrontPic_Bellsprout
gMonFrontPic_Bellsprout: @ 0x8B1A2C0
	.incbin "graphics/pokemon/bellsprout/anim_front.4bpp.lz"

	.globl gMonFrontPic_Weepinbell
gMonFrontPic_Weepinbell: @ 0x8B1A798
	.incbin "graphics/pokemon/weepinbell/anim_front.4bpp.lz"

	.globl gMonFrontPic_Victreebel
gMonFrontPic_Victreebel: @ 0x8B1AD20
	.incbin "graphics/pokemon/victreebel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tentacool
gMonFrontPic_Tentacool: @ 0x8B1B474
	.incbin "graphics/pokemon/tentacool/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tentacruel
gMonFrontPic_Tentacruel: @ 0x8B1B8F4
	.incbin "graphics/pokemon/tentacruel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Geodude
gMonFrontPic_Geodude: @ 0x8B1C018
	.incbin "graphics/pokemon/geodude/anim_front.4bpp.lz"

	.globl gMonFrontPic_Graveler
gMonFrontPic_Graveler: @ 0x8B1C4A8
	.incbin "graphics/pokemon/graveler/anim_front.4bpp.lz"

	.globl gMonFrontPic_Golem
gMonFrontPic_Golem: @ 0x8B1CA7C
	.incbin "graphics/pokemon/golem/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ponyta
gMonFrontPic_Ponyta: @ 0x8B1D160
	.incbin "graphics/pokemon/ponyta/anim_front.4bpp.lz"

	.globl gMonFrontPic_Rapidash
gMonFrontPic_Rapidash: @ 0x8B1D820
	.incbin "graphics/pokemon/rapidash/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slowpoke
gMonFrontPic_Slowpoke: @ 0x8B1E188
	.incbin "graphics/pokemon/slowpoke/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slowbro
gMonFrontPic_Slowbro: @ 0x8B1E650
	.incbin "graphics/pokemon/slowbro/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magnemite
gMonFrontPic_Magnemite: @ 0x8B1EDC8
	.incbin "graphics/pokemon/magnemite/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magneton
gMonFrontPic_Magneton: @ 0x8B1F160
	.incbin "graphics/pokemon/magneton/anim_front.4bpp.lz"

	.globl gMonFrontPic_Farfetchd
gMonFrontPic_Farfetchd: @ 0x8B1F814
	.incbin "graphics/pokemon/farfetchd/anim_front.4bpp.lz"

	.globl gMonFrontPic_Doduo
gMonFrontPic_Doduo: @ 0x8B1FD9C
	.incbin "graphics/pokemon/doduo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dodrio
gMonFrontPic_Dodrio: @ 0x8B20398
	.incbin "graphics/pokemon/dodrio/anim_front.4bpp.lz"

	.globl gMonFrontPic_Seel
gMonFrontPic_Seel: @ 0x8B20CAC
	.incbin "graphics/pokemon/seel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dewgong
gMonFrontPic_Dewgong: @ 0x8B211F4
	.incbin "graphics/pokemon/dewgong/anim_front.4bpp.lz"

	.globl gMonFrontPic_Grimer
gMonFrontPic_Grimer: @ 0x8B21894
	.incbin "graphics/pokemon/grimer/anim_front.4bpp.lz"

	.globl gMonFrontPic_Muk
gMonFrontPic_Muk: @ 0x8B21E1C
	.incbin "graphics/pokemon/muk/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shellder
gMonFrontPic_Shellder: @ 0x8B22538
	.incbin "graphics/pokemon/shellder/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cloyster
gMonFrontPic_Cloyster: @ 0x8B2298C
	.incbin "graphics/pokemon/cloyster/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gastly
gMonFrontPic_Gastly: @ 0x8B23138
	.incbin "graphics/pokemon/gastly/anim_front.4bpp.lz"

	.globl gMonFrontPic_Haunter
gMonFrontPic_Haunter: @ 0x8B237DC
	.incbin "graphics/pokemon/haunter/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gengar
gMonFrontPic_Gengar: @ 0x8B23ED0
	.incbin "graphics/pokemon/gengar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Onix
gMonFrontPic_Onix: @ 0x8B2456C
	.incbin "graphics/pokemon/onix/anim_front.4bpp.lz"

	.globl gMonFrontPic_Drowzee
gMonFrontPic_Drowzee: @ 0x8B24DEC
	.incbin "graphics/pokemon/drowzee/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hypno
gMonFrontPic_Hypno: @ 0x8B253D4
	.incbin "graphics/pokemon/hypno/anim_front.4bpp.lz"

	.globl gMonFrontPic_Krabby
gMonFrontPic_Krabby: @ 0x8B25A20
	.incbin "graphics/pokemon/krabby/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kingler
gMonFrontPic_Kingler: @ 0x8B25EE4
	.incbin "graphics/pokemon/kingler/anim_front.4bpp.lz"

	.globl gMonFrontPic_Voltorb
gMonFrontPic_Voltorb: @ 0x8B267F4
	.incbin "graphics/pokemon/voltorb/anim_front.4bpp.lz"

	.globl gMonFrontPic_Electrode
gMonFrontPic_Electrode: @ 0x8B26B68
	.incbin "graphics/pokemon/electrode/anim_front.4bpp.lz"

	.globl gMonFrontPic_Exeggcute
gMonFrontPic_Exeggcute: @ 0x8B26F7C
	.incbin "graphics/pokemon/exeggcute/anim_front.4bpp.lz"

	.globl gMonFrontPic_Exeggutor
gMonFrontPic_Exeggutor: @ 0x8B27614
	.incbin "graphics/pokemon/exeggutor/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cubone
gMonFrontPic_Cubone: @ 0x8B27E24
	.incbin "graphics/pokemon/cubone/anim_front.4bpp.lz"

	.globl gMonFrontPic_Marowak
gMonFrontPic_Marowak: @ 0x8B282A8
	.incbin "graphics/pokemon/marowak/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hitmonlee
gMonFrontPic_Hitmonlee: @ 0x8B28948
	.incbin "graphics/pokemon/hitmonlee/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hitmonchan
gMonFrontPic_Hitmonchan: @ 0x8B29068
	.incbin "graphics/pokemon/hitmonchan/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lickitung
gMonFrontPic_Lickitung: @ 0x8B29678
	.incbin "graphics/pokemon/lickitung/anim_front.4bpp.lz"

	.globl gMonFrontPic_Koffing
gMonFrontPic_Koffing: @ 0x8B29D50
	.incbin "graphics/pokemon/koffing/anim_front.4bpp.lz"

	.globl gMonFrontPic_Weezing
gMonFrontPic_Weezing: @ 0x8B2A368
	.incbin "graphics/pokemon/weezing/anim_front.4bpp.lz"

	.globl gMonFrontPic_Rhyhorn
gMonFrontPic_Rhyhorn: @ 0x8B2ABC8
	.incbin "graphics/pokemon/rhyhorn/anim_front.4bpp.lz"

	.globl gMonFrontPic_Rhydon
gMonFrontPic_Rhydon: @ 0x8B2B2A4
	.incbin "graphics/pokemon/rhydon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Chansey
gMonFrontPic_Chansey: @ 0x8B2BBA4
	.incbin "graphics/pokemon/chansey/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tangela
gMonFrontPic_Tangela: @ 0x8B2C128
	.incbin "graphics/pokemon/tangela/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kangaskhan
gMonFrontPic_Kangaskhan: @ 0x8B2C800
	.incbin "graphics/pokemon/kangaskhan/anim_front.4bpp.lz"

	.globl gMonFrontPic_Horsea
gMonFrontPic_Horsea: @ 0x8B2D0B4
	.incbin "graphics/pokemon/horsea/anim_front.4bpp.lz"

	.globl gMonFrontPic_Seadra
gMonFrontPic_Seadra: @ 0x8B2D4D0
	.incbin "graphics/pokemon/seadra/anim_front.4bpp.lz"

	.globl gMonFrontPic_Goldeen
gMonFrontPic_Goldeen: @ 0x8B2DBB4
	.incbin "graphics/pokemon/goldeen/anim_front.4bpp.lz"

	.globl gMonFrontPic_Seaking
gMonFrontPic_Seaking: @ 0x8B2E18C
	.incbin "graphics/pokemon/seaking/anim_front.4bpp.lz"

	.globl gMonFrontPic_Staryu
gMonFrontPic_Staryu: @ 0x8B2E930
	.incbin "graphics/pokemon/staryu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Starmie
gMonFrontPic_Starmie: @ 0x8B2EE64
	.incbin "graphics/pokemon/starmie/anim_front.4bpp.lz"

	.globl gMonFrontPic_MrMime
gMonFrontPic_MrMime: @ 0x8B2F4D0
	.incbin "graphics/pokemon/mr_mime/anim_front.4bpp.lz"

	.globl gMonFrontPic_Scyther
gMonFrontPic_Scyther: @ 0x8B2FB0C
	.incbin "graphics/pokemon/scyther/anim_front.4bpp.lz"

	.globl gMonFrontPic_Jynx
gMonFrontPic_Jynx: @ 0x8B3034C
	.incbin "graphics/pokemon/jynx/anim_front.4bpp.lz"

	.globl gMonFrontPic_Electabuzz
gMonFrontPic_Electabuzz: @ 0x8B30BE0
	.incbin "graphics/pokemon/electabuzz/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magmar
gMonFrontPic_Magmar: @ 0x8B313C8
	.incbin "graphics/pokemon/magmar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pinsir
gMonFrontPic_Pinsir: @ 0x8B31C40
	.incbin "graphics/pokemon/pinsir/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tauros
gMonFrontPic_Tauros: @ 0x8B323D8
	.incbin "graphics/pokemon/tauros/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magikarp
gMonFrontPic_Magikarp: @ 0x8B32C7C
	.incbin "graphics/pokemon/magikarp/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gyarados
gMonFrontPic_Gyarados: @ 0x8B332A4
	.incbin "graphics/pokemon/gyarados/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lapras
gMonFrontPic_Lapras: @ 0x8B33B74
	.incbin "graphics/pokemon/lapras/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ditto
gMonFrontPic_Ditto: @ 0x8B341D4
	.incbin "graphics/pokemon/ditto/anim_front.4bpp.lz"

	.globl gMonFrontPic_Eevee
gMonFrontPic_Eevee: @ 0x8B34548
	.incbin "graphics/pokemon/eevee/anim_front.4bpp.lz"

	.globl gMonFrontPic_Vaporeon
gMonFrontPic_Vaporeon: @ 0x8B34A68
	.incbin "graphics/pokemon/vaporeon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Jolteon
gMonFrontPic_Jolteon: @ 0x8B35098
	.incbin "graphics/pokemon/jolteon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Flareon
gMonFrontPic_Flareon: @ 0x8B35774
	.incbin "graphics/pokemon/flareon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Porygon
gMonFrontPic_Porygon: @ 0x8B35DB8
	.incbin "graphics/pokemon/porygon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Omanyte
gMonFrontPic_Omanyte: @ 0x8B36248
	.incbin "graphics/pokemon/omanyte/anim_front.4bpp.lz"

	.globl gMonFrontPic_Omastar
gMonFrontPic_Omastar: @ 0x8B36670
	.incbin "graphics/pokemon/omastar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kabuto
gMonFrontPic_Kabuto: @ 0x8B36CB4
	.incbin "graphics/pokemon/kabuto/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kabutops
gMonFrontPic_Kabutops: @ 0x8B37088
	.incbin "graphics/pokemon/kabutops/anim_front.4bpp.lz"

	.globl gMonFrontPic_Aerodactyl
gMonFrontPic_Aerodactyl: @ 0x8B377DC
	.incbin "graphics/pokemon/aerodactyl/anim_front.4bpp.lz"

	.globl gMonFrontPic_Snorlax
gMonFrontPic_Snorlax: @ 0x8B37F64
	.incbin "graphics/pokemon/snorlax/anim_front.4bpp.lz"

	.globl gMonFrontPic_Articuno
gMonFrontPic_Articuno: @ 0x8B3868C
	.incbin "graphics/pokemon/articuno/anim_front.4bpp.lz"

	.globl gMonFrontPic_Zapdos
gMonFrontPic_Zapdos: @ 0x8B39004
	.incbin "graphics/pokemon/zapdos/anim_front.4bpp.lz"

	.globl gMonFrontPic_Moltres
gMonFrontPic_Moltres: @ 0x8B39800
	.incbin "graphics/pokemon/moltres/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dratini
gMonFrontPic_Dratini: @ 0x8B3A0A8
	.incbin "graphics/pokemon/dratini/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dragonair
gMonFrontPic_Dragonair: @ 0x8B3A5B4
	.incbin "graphics/pokemon/dragonair/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dragonite
gMonFrontPic_Dragonite: @ 0x8B3AC44
	.incbin "graphics/pokemon/dragonite/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mewtwo
gMonFrontPic_Mewtwo: @ 0x8B3B56C
	.incbin "graphics/pokemon/mewtwo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mew
gMonFrontPic_Mew: @ 0x8B3BD14
	.incbin "graphics/pokemon/mew/anim_front.4bpp.lz"

	.globl gMonFrontPic_Chikorita
gMonFrontPic_Chikorita: @ 0x8B3C1F4
	.incbin "graphics/pokemon/chikorita/anim_front.4bpp.lz"

	.globl gMonFrontPic_Bayleef
gMonFrontPic_Bayleef: @ 0x8B3C68C
	.incbin "graphics/pokemon/bayleef/anim_front.4bpp.lz"

	.globl gMonFrontPic_Meganium
gMonFrontPic_Meganium: @ 0x8B3CCA0
	.incbin "graphics/pokemon/meganium/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cyndaquil
gMonFrontPic_Cyndaquil: @ 0x8B3D5D4
	.incbin "graphics/pokemon/cyndaquil/anim_front.4bpp.lz"

	.globl gMonFrontPic_Quilava
gMonFrontPic_Quilava: @ 0x8B3DA94
	.incbin "graphics/pokemon/quilava/anim_front.4bpp.lz"

	.globl gMonFrontPic_Typhlosion
gMonFrontPic_Typhlosion: @ 0x8B3E080
	.incbin "graphics/pokemon/typhlosion/anim_front.4bpp.lz"

	.globl gMonFrontPic_Totodile
gMonFrontPic_Totodile: @ 0x8B3E798
	.incbin "graphics/pokemon/totodile/anim_front.4bpp.lz"

	.globl gMonFrontPic_Croconaw
gMonFrontPic_Croconaw: @ 0x8B3EC60
	.incbin "graphics/pokemon/croconaw/anim_front.4bpp.lz"

	.globl gMonFrontPic_Feraligatr
gMonFrontPic_Feraligatr: @ 0x8B3F2BC
	.incbin "graphics/pokemon/feraligatr/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sentret
gMonFrontPic_Sentret: @ 0x8B3FB90
	.incbin "graphics/pokemon/sentret/anim_front.4bpp.lz"

	.globl gMonFrontPic_Furret
gMonFrontPic_Furret: @ 0x8B4005C
	.incbin "graphics/pokemon/furret/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hoothoot
gMonFrontPic_Hoothoot: @ 0x8B40650
	.incbin "graphics/pokemon/hoothoot/anim_front.4bpp.lz"

	.globl gMonFrontPic_Noctowl
gMonFrontPic_Noctowl: @ 0x8B40A4C
	.incbin "graphics/pokemon/noctowl/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ledyba
gMonFrontPic_Ledyba: @ 0x8B41100
	.incbin "graphics/pokemon/ledyba/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ledian
gMonFrontPic_Ledian: @ 0x8B4161C
	.incbin "graphics/pokemon/ledian/anim_front.4bpp.lz"

	.globl gMonFrontPic_Spinarak
gMonFrontPic_Spinarak: @ 0x8B41AEC
	.incbin "graphics/pokemon/spinarak/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ariados
gMonFrontPic_Ariados: @ 0x8B41F34
	.incbin "graphics/pokemon/ariados/anim_front.4bpp.lz"

	.globl gMonFrontPic_Crobat
gMonFrontPic_Crobat: @ 0x8B42628
	.incbin "graphics/pokemon/crobat/anim_front.4bpp.lz"

	.globl gMonFrontPic_Chinchou
gMonFrontPic_Chinchou: @ 0x8B42BFC
	.incbin "graphics/pokemon/chinchou/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lanturn
gMonFrontPic_Lanturn: @ 0x8B43100
	.incbin "graphics/pokemon/lanturn/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pichu
gMonFrontPic_Pichu: @ 0x8B43748
	.incbin "graphics/pokemon/pichu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cleffa
gMonFrontPic_Cleffa: @ 0x8B43B00
	.incbin "graphics/pokemon/cleffa/anim_front.4bpp.lz"

	.globl gMonFrontPic_Igglybuff
gMonFrontPic_Igglybuff: @ 0x8B43EBC
	.incbin "graphics/pokemon/igglybuff/anim_front.4bpp.lz"

	.globl gMonFrontPic_Togepi
gMonFrontPic_Togepi: @ 0x8B44228
	.incbin "graphics/pokemon/togepi/anim_front.4bpp.lz"

	.globl gMonFrontPic_Togetic
gMonFrontPic_Togetic: @ 0x8B4454C
	.incbin "graphics/pokemon/togetic/anim_front.4bpp.lz"

	.globl gMonFrontPic_Natu
gMonFrontPic_Natu: @ 0x8B449DC
	.incbin "graphics/pokemon/natu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Xatu
gMonFrontPic_Xatu: @ 0x8B44D08
	.incbin "graphics/pokemon/xatu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mareep
gMonFrontPic_Mareep: @ 0x8B4529C
	.incbin "graphics/pokemon/mareep/anim_front.4bpp.lz"

	.globl gMonFrontPic_Flaaffy
gMonFrontPic_Flaaffy: @ 0x8B45744
	.incbin "graphics/pokemon/flaaffy/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ampharos
gMonFrontPic_Ampharos: @ 0x8B45C34
	.incbin "graphics/pokemon/ampharos/anim_front.4bpp.lz"

	.globl gMonFrontPic_Bellossom
gMonFrontPic_Bellossom: @ 0x8B462C0
	.incbin "graphics/pokemon/bellossom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Marill
gMonFrontPic_Marill: @ 0x8B46758
	.incbin "graphics/pokemon/marill/anim_front.4bpp.lz"

	.globl gMonFrontPic_Azumarill
gMonFrontPic_Azumarill: @ 0x8B46C84
	.incbin "graphics/pokemon/azumarill/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sudowoodo
gMonFrontPic_Sudowoodo: @ 0x8B47228
	.incbin "graphics/pokemon/sudowoodo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Politoed
gMonFrontPic_Politoed: @ 0x8B477E4
	.incbin "graphics/pokemon/politoed/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hoppip
gMonFrontPic_Hoppip: @ 0x8B47DEC
	.incbin "graphics/pokemon/hoppip/anim_front.4bpp.lz"

	.globl gMonFrontPic_Skiploom
gMonFrontPic_Skiploom: @ 0x8B482B4
	.incbin "graphics/pokemon/skiploom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Jumpluff
gMonFrontPic_Jumpluff: @ 0x8B486F8
	.incbin "graphics/pokemon/jumpluff/anim_front.4bpp.lz"

	.globl gMonFrontPic_Aipom
gMonFrontPic_Aipom: @ 0x8B48C78
	.incbin "graphics/pokemon/aipom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sunkern
gMonFrontPic_Sunkern: @ 0x8B49178
	.incbin "graphics/pokemon/sunkern/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sunflora
gMonFrontPic_Sunflora: @ 0x8B49518
	.incbin "graphics/pokemon/sunflora/anim_front.4bpp.lz"

	.globl gMonFrontPic_Yanma
gMonFrontPic_Yanma: @ 0x8B49AB0
	.incbin "graphics/pokemon/yanma/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wooper
gMonFrontPic_Wooper: @ 0x8B4A03C
	.incbin "graphics/pokemon/wooper/anim_front.4bpp.lz"

	.globl gMonFrontPic_Quagsire
gMonFrontPic_Quagsire: @ 0x8B4A3FC
	.incbin "graphics/pokemon/quagsire/anim_front.4bpp.lz"

	.globl gMonFrontPic_Espeon
gMonFrontPic_Espeon: @ 0x8B4AA80
	.incbin "graphics/pokemon/espeon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Umbreon
gMonFrontPic_Umbreon: @ 0x8B4B060
	.incbin "graphics/pokemon/umbreon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Murkrow
gMonFrontPic_Murkrow: @ 0x8B4B610
	.incbin "graphics/pokemon/murkrow/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slowking
gMonFrontPic_Slowking: @ 0x8B4BB6C
	.incbin "graphics/pokemon/slowking/anim_front.4bpp.lz"

	.globl gMonFrontPic_Misdreavus
gMonFrontPic_Misdreavus: @ 0x8B4C234
	.incbin "graphics/pokemon/misdreavus/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownA
gMonFrontPic_UnownA: @ 0x8B4C730
	.incbin "graphics/pokemon/unown/a/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wobbuffet
gMonFrontPic_Wobbuffet: @ 0x8B4C9F4
	.incbin "graphics/pokemon/wobbuffet/anim_front.4bpp.lz"

	.globl gMonFrontPic_Girafarig
gMonFrontPic_Girafarig: @ 0x8B4CFC4
	.incbin "graphics/pokemon/girafarig/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pineco
gMonFrontPic_Pineco: @ 0x8B4D75C
	.incbin "graphics/pokemon/pineco/anim_front.4bpp.lz"

	.globl gMonFrontPic_Forretress
gMonFrontPic_Forretress: @ 0x8B4DBE4
	.incbin "graphics/pokemon/forretress/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dunsparce
gMonFrontPic_Dunsparce: @ 0x8B4E1E8
	.incbin "graphics/pokemon/dunsparce/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gligar
gMonFrontPic_Gligar: @ 0x8B4E73C
	.incbin "graphics/pokemon/gligar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Steelix
gMonFrontPic_Steelix: @ 0x8B4EE6C
	.incbin "graphics/pokemon/steelix/anim_front.4bpp.lz"

	.globl gMonFrontPic_Snubbull
gMonFrontPic_Snubbull: @ 0x8B4F73C
	.incbin "graphics/pokemon/snubbull/anim_front.4bpp.lz"

	.globl gMonFrontPic_Granbull
gMonFrontPic_Granbull: @ 0x8B4FC2C
	.incbin "graphics/pokemon/granbull/anim_front.4bpp.lz"

	.globl gMonFrontPic_Qwilfish
gMonFrontPic_Qwilfish: @ 0x8B502CC
	.incbin "graphics/pokemon/qwilfish/anim_front.4bpp.lz"

	.globl gMonFrontPic_Scizor
gMonFrontPic_Scizor: @ 0x8B50780
	.incbin "graphics/pokemon/scizor/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shuckle
gMonFrontPic_Shuckle: @ 0x8B5100C
	.incbin "graphics/pokemon/shuckle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Heracross
gMonFrontPic_Heracross: @ 0x8B51470
	.incbin "graphics/pokemon/heracross/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sneasel
gMonFrontPic_Sneasel: @ 0x8B51B04
	.incbin "graphics/pokemon/sneasel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Teddiursa
gMonFrontPic_Teddiursa: @ 0x8B52114
	.incbin "graphics/pokemon/teddiursa/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ursaring
gMonFrontPic_Ursaring: @ 0x8B524C0
	.incbin "graphics/pokemon/ursaring/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slugma
gMonFrontPic_Slugma: @ 0x8B52C4C
	.incbin "graphics/pokemon/slugma/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magcargo
gMonFrontPic_Magcargo: @ 0x8B5307C
	.incbin "graphics/pokemon/magcargo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Swinub
gMonFrontPic_Swinub: @ 0x8B536DC
	.incbin "graphics/pokemon/swinub/anim_front.4bpp.lz"

	.globl gMonFrontPic_Piloswine
gMonFrontPic_Piloswine: @ 0x8B53A7C
	.incbin "graphics/pokemon/piloswine/anim_front.4bpp.lz"

	.globl gMonFrontPic_Corsola
gMonFrontPic_Corsola: @ 0x8B53FB8
	.incbin "graphics/pokemon/corsola/anim_front.4bpp.lz"

	.globl gMonFrontPic_Remoraid
gMonFrontPic_Remoraid: @ 0x8B5450C
	.incbin "graphics/pokemon/remoraid/anim_front.4bpp.lz"

	.globl gMonFrontPic_Octillery
gMonFrontPic_Octillery: @ 0x8B54960
	.incbin "graphics/pokemon/octillery/anim_front.4bpp.lz"

	.globl gMonFrontPic_Delibird
gMonFrontPic_Delibird: @ 0x8B54EE4
	.incbin "graphics/pokemon/delibird/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mantine
gMonFrontPic_Mantine: @ 0x8B55514
	.incbin "graphics/pokemon/mantine/anim_front.4bpp.lz"

	.globl gMonFrontPic_Skarmory
gMonFrontPic_Skarmory: @ 0x8B55D60
	.incbin "graphics/pokemon/skarmory/anim_front.4bpp.lz"

	.globl gMonFrontPic_Houndour
gMonFrontPic_Houndour: @ 0x8B5656C
	.incbin "graphics/pokemon/houndour/anim_front.4bpp.lz"

	.globl gMonFrontPic_Houndoom
gMonFrontPic_Houndoom: @ 0x8B56A70
	.incbin "graphics/pokemon/houndoom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kingdra
gMonFrontPic_Kingdra: @ 0x8B57164
	.incbin "graphics/pokemon/kingdra/anim_front.4bpp.lz"

	.globl gMonFrontPic_Phanpy
gMonFrontPic_Phanpy: @ 0x8B57900
	.incbin "graphics/pokemon/phanpy/anim_front.4bpp.lz"

	.globl gMonFrontPic_Donphan
gMonFrontPic_Donphan: @ 0x8B57D74
	.incbin "graphics/pokemon/donphan/anim_front.4bpp.lz"

	.globl gMonFrontPic_Porygon2
gMonFrontPic_Porygon2: @ 0x8B5846C
	.incbin "graphics/pokemon/porygon2/anim_front.4bpp.lz"

	.globl gMonFrontPic_Stantler
gMonFrontPic_Stantler: @ 0x8B588E8
	.incbin "graphics/pokemon/stantler/anim_front.4bpp.lz"

	.globl gMonFrontPic_Smeargle
gMonFrontPic_Smeargle: @ 0x8B5905C
	.incbin "graphics/pokemon/smeargle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tyrogue
gMonFrontPic_Tyrogue: @ 0x8B5970C
	.incbin "graphics/pokemon/tyrogue/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hitmontop
gMonFrontPic_Hitmontop: @ 0x8B59BD4
	.incbin "graphics/pokemon/hitmontop/anim_front.4bpp.lz"

	.globl gMonFrontPic_Smoochum
gMonFrontPic_Smoochum: @ 0x8B5A1B4
	.incbin "graphics/pokemon/smoochum/anim_front.4bpp.lz"

	.globl gMonFrontPic_Elekid
gMonFrontPic_Elekid: @ 0x8B5A5A4
	.incbin "graphics/pokemon/elekid/anim_front.4bpp.lz"

	.globl gMonFrontPic_Magby
gMonFrontPic_Magby: @ 0x8B5AB58
	.incbin "graphics/pokemon/magby/anim_front.4bpp.lz"

	.globl gMonFrontPic_Miltank
gMonFrontPic_Miltank: @ 0x8B5B004
	.incbin "graphics/pokemon/miltank/anim_front.4bpp.lz"

	.globl gMonFrontPic_Blissey
gMonFrontPic_Blissey: @ 0x8B5B6C0
	.incbin "graphics/pokemon/blissey/anim_front.4bpp.lz"

	.globl gMonFrontPic_Raikou
gMonFrontPic_Raikou: @ 0x8B5BD2C
	.incbin "graphics/pokemon/raikou/anim_front.4bpp.lz"

	.globl gMonFrontPic_Entei
gMonFrontPic_Entei: @ 0x8B5C738
	.incbin "graphics/pokemon/entei/anim_front.4bpp.lz"

	.globl gMonFrontPic_Suicune
gMonFrontPic_Suicune: @ 0x8B5CFCC
	.incbin "graphics/pokemon/suicune/anim_front.4bpp.lz"

	.globl gMonFrontPic_Larvitar
gMonFrontPic_Larvitar: @ 0x8B5DA34
	.incbin "graphics/pokemon/larvitar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pupitar
gMonFrontPic_Pupitar: @ 0x8B5DEC0
	.incbin "graphics/pokemon/pupitar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tyranitar
gMonFrontPic_Tyranitar: @ 0x8B5E308
	.incbin "graphics/pokemon/tyranitar/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lugia
gMonFrontPic_Lugia: @ 0x8B5EC68
	.incbin "graphics/pokemon/lugia/anim_front.4bpp.lz"

	.globl gMonFrontPic_HoOh
gMonFrontPic_HoOh: @ 0x8B5F4FC
	.incbin "graphics/pokemon/ho_oh/anim_front.4bpp.lz"

	.globl gMonFrontPic_Celebi
gMonFrontPic_Celebi: @ 0x8B60090
	.incbin "graphics/pokemon/celebi/anim_front.4bpp.lz"

	.globl gMonFrontPic_DoubleQuestionMark
gMonFrontPic_DoubleQuestionMark: @ 0x8B60544
	.incbin "graphics/pokemon/question_mark/double/anim_front.4bpp.lz"

	.globl gMonFrontPic_Treecko
gMonFrontPic_Treecko: @ 0x8B607B4
	.incbin "graphics/pokemon/treecko/anim_front.4bpp.lz"

	.globl gMonFrontPic_Grovyle
gMonFrontPic_Grovyle: @ 0x8B60D28
	.incbin "graphics/pokemon/grovyle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sceptile
gMonFrontPic_Sceptile: @ 0x8B6157C
	.incbin "graphics/pokemon/sceptile/anim_front.4bpp.lz"

	.globl gMonFrontPic_Torchic
gMonFrontPic_Torchic: @ 0x8B61C9C
	.incbin "graphics/pokemon/torchic/anim_front.4bpp.lz"

	.globl gMonFrontPic_Combusken
gMonFrontPic_Combusken: @ 0x8B6218C
	.incbin "graphics/pokemon/combusken/anim_front.4bpp.lz"

	.globl gMonFrontPic_Blaziken
gMonFrontPic_Blaziken: @ 0x8B62964
	.incbin "graphics/pokemon/blaziken/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mudkip
gMonFrontPic_Mudkip: @ 0x8B630B0
	.incbin "graphics/pokemon/mudkip/anim_front.4bpp.lz"

	.globl gMonFrontPic_Marshtomp
gMonFrontPic_Marshtomp: @ 0x8B635E4
	.incbin "graphics/pokemon/marshtomp/anim_front.4bpp.lz"

	.globl gMonFrontPic_Swampert
gMonFrontPic_Swampert: @ 0x8B63BF4
	.incbin "graphics/pokemon/swampert/anim_front.4bpp.lz"

	.globl gMonFrontPic_Poochyena
gMonFrontPic_Poochyena: @ 0x8B64564
	.incbin "graphics/pokemon/poochyena/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mightyena
gMonFrontPic_Mightyena: @ 0x8B64AC0
	.incbin "graphics/pokemon/mightyena/anim_front.4bpp.lz"

	.globl gMonFrontPic_Zigzagoon
gMonFrontPic_Zigzagoon: @ 0x8B65294
	.incbin "graphics/pokemon/zigzagoon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Linoone
gMonFrontPic_Linoone: @ 0x8B659B0
	.incbin "graphics/pokemon/linoone/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wurmple
gMonFrontPic_Wurmple: @ 0x8B65F9C
	.incbin "graphics/pokemon/wurmple/anim_front.4bpp.lz"

	.globl gMonFrontPic_Silcoon
gMonFrontPic_Silcoon: @ 0x8B66498
	.incbin "graphics/pokemon/silcoon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Beautifly
gMonFrontPic_Beautifly: @ 0x8B66830
	.incbin "graphics/pokemon/beautifly/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cascoon
gMonFrontPic_Cascoon: @ 0x8B66DBC
	.incbin "graphics/pokemon/cascoon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dustox
gMonFrontPic_Dustox: @ 0x8B67130
	.incbin "graphics/pokemon/dustox/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lotad
gMonFrontPic_Lotad: @ 0x8B67734
	.incbin "graphics/pokemon/lotad/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lombre
gMonFrontPic_Lombre: @ 0x8B67B7C
	.incbin "graphics/pokemon/lombre/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ludicolo
gMonFrontPic_Ludicolo: @ 0x8B68120
	.incbin "graphics/pokemon/ludicolo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Seedot
gMonFrontPic_Seedot: @ 0x8B688F0
	.incbin "graphics/pokemon/seedot/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nuzleaf
gMonFrontPic_Nuzleaf: @ 0x8B68DB4
	.incbin "graphics/pokemon/nuzleaf/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shiftry
gMonFrontPic_Shiftry: @ 0x8B69278
	.incbin "graphics/pokemon/shiftry/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nincada
gMonFrontPic_Nincada: @ 0x8B69878
	.incbin "graphics/pokemon/nincada/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ninjask
gMonFrontPic_Ninjask: @ 0x8B69D04
	.incbin "graphics/pokemon/ninjask/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shedinja
gMonFrontPic_Shedinja: @ 0x8B6A23C
	.incbin "graphics/pokemon/shedinja/anim_front.4bpp.lz"

	.globl gMonFrontPic_Taillow
gMonFrontPic_Taillow: @ 0x8B6A81C
	.incbin "graphics/pokemon/taillow/anim_front.4bpp.lz"

	.globl gMonFrontPic_Swellow
gMonFrontPic_Swellow: @ 0x8B6AD5C
	.incbin "graphics/pokemon/swellow/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shroomish
gMonFrontPic_Shroomish: @ 0x8B6B2C8
	.incbin "graphics/pokemon/shroomish/anim_front.4bpp.lz"

	.globl gMonFrontPic_Breloom
gMonFrontPic_Breloom: @ 0x8B6B690
	.incbin "graphics/pokemon/breloom/anim_front.4bpp.lz"

	.globl gMonFrontPic_Spinda
gMonFrontPic_Spinda: @ 0x8B6BD3C
	.incbin "graphics/pokemon/spinda/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wingull
gMonFrontPic_Wingull: @ 0x8B6C130
	.incbin "graphics/pokemon/wingull/anim_front.4bpp.lz"

	.globl gMonFrontPic_Pelipper
gMonFrontPic_Pelipper: @ 0x8B6C514
	.incbin "graphics/pokemon/pelipper/anim_front.4bpp.lz"

	.globl gMonFrontPic_Surskit
gMonFrontPic_Surskit: @ 0x8B6CB0C
	.incbin "graphics/pokemon/surskit/anim_front.4bpp.lz"

	.globl gMonFrontPic_Masquerain
gMonFrontPic_Masquerain: @ 0x8B6CEB0
	.incbin "graphics/pokemon/masquerain/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wailmer
gMonFrontPic_Wailmer: @ 0x8B6D4F0
	.incbin "graphics/pokemon/wailmer/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wailord
gMonFrontPic_Wailord: @ 0x8B6D9A4
	.incbin "graphics/pokemon/wailord/anim_front.4bpp.lz"

	.globl gMonFrontPic_Skitty
gMonFrontPic_Skitty: @ 0x8B6E01C
	.incbin "graphics/pokemon/skitty/anim_front.4bpp.lz"

	.globl gMonFrontPic_Delcatty
gMonFrontPic_Delcatty: @ 0x8B6E588
	.incbin "graphics/pokemon/delcatty/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kecleon
gMonFrontPic_Kecleon: @ 0x8B6EBE0
	.incbin "graphics/pokemon/kecleon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Baltoy
gMonFrontPic_Baltoy: @ 0x8B6F274
	.incbin "graphics/pokemon/baltoy/anim_front.4bpp.lz"

	.globl gMonFrontPic_Claydol
gMonFrontPic_Claydol: @ 0x8B6F62C
	.incbin "graphics/pokemon/claydol/anim_front.4bpp.lz"

	.globl gMonFrontPic_Nosepass
gMonFrontPic_Nosepass: @ 0x8B6FD08
	.incbin "graphics/pokemon/nosepass/anim_front.4bpp.lz"

	.globl gMonFrontPic_Torkoal
gMonFrontPic_Torkoal: @ 0x8B70268
	.incbin "graphics/pokemon/torkoal/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sableye
gMonFrontPic_Sableye: @ 0x8B70A58
	.incbin "graphics/pokemon/sableye/anim_front.4bpp.lz"

	.globl gMonFrontPic_Barboach
gMonFrontPic_Barboach: @ 0x8B70EF8
	.incbin "graphics/pokemon/barboach/anim_front.4bpp.lz"

	.globl gMonFrontPic_Whiscash
gMonFrontPic_Whiscash: @ 0x8B71400
	.incbin "graphics/pokemon/whiscash/anim_front.4bpp.lz"

	.globl gMonFrontPic_Luvdisc
gMonFrontPic_Luvdisc: @ 0x8B7197C
	.incbin "graphics/pokemon/luvdisc/anim_front.4bpp.lz"

	.globl gMonFrontPic_Corphish
gMonFrontPic_Corphish: @ 0x8B71CB0
	.incbin "graphics/pokemon/corphish/anim_front.4bpp.lz"

	.globl gMonFrontPic_Crawdaunt
gMonFrontPic_Crawdaunt: @ 0x8B721E4
	.incbin "graphics/pokemon/crawdaunt/anim_front.4bpp.lz"

	.globl gMonFrontPic_Feebas
gMonFrontPic_Feebas: @ 0x8B72920
	.incbin "graphics/pokemon/feebas/anim_front.4bpp.lz"

	.globl gMonFrontPic_Milotic
gMonFrontPic_Milotic: @ 0x8B72E30
	.incbin "graphics/pokemon/milotic/anim_front.4bpp.lz"

	.globl gMonFrontPic_Carvanha
gMonFrontPic_Carvanha: @ 0x8B736FC
	.incbin "graphics/pokemon/carvanha/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sharpedo
gMonFrontPic_Sharpedo: @ 0x8B73D1C
	.incbin "graphics/pokemon/sharpedo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Trapinch
gMonFrontPic_Trapinch: @ 0x8B7434C
	.incbin "graphics/pokemon/trapinch/anim_front.4bpp.lz"

	.globl gMonFrontPic_Vibrava
gMonFrontPic_Vibrava: @ 0x8B74720
	.incbin "graphics/pokemon/vibrava/anim_front.4bpp.lz"

	.globl gMonFrontPic_Flygon
gMonFrontPic_Flygon: @ 0x8B74DB0
	.incbin "graphics/pokemon/flygon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Makuhita
gMonFrontPic_Makuhita: @ 0x8B75614
	.incbin "graphics/pokemon/makuhita/anim_front.4bpp.lz"

	.globl gMonFrontPic_Hariyama
gMonFrontPic_Hariyama: @ 0x8B75AD0
	.incbin "graphics/pokemon/hariyama/anim_front.4bpp.lz"

	.globl gMonFrontPic_Electrike
gMonFrontPic_Electrike: @ 0x8B763D0
	.incbin "graphics/pokemon/electrike/anim_front.4bpp.lz"

	.globl gMonFrontPic_Manectric
gMonFrontPic_Manectric: @ 0x8B768A0
	.incbin "graphics/pokemon/manectric/anim_front.4bpp.lz"

	.globl gMonFrontPic_Numel
gMonFrontPic_Numel: @ 0x8B76E9C
	.incbin "graphics/pokemon/numel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Camerupt
gMonFrontPic_Camerupt: @ 0x8B773B8
	.incbin "graphics/pokemon/camerupt/anim_front.4bpp.lz"

	.globl gMonFrontPic_Spheal
gMonFrontPic_Spheal: @ 0x8B779DC
	.incbin "graphics/pokemon/spheal/anim_front.4bpp.lz"

	.globl gMonFrontPic_Sealeo
gMonFrontPic_Sealeo: @ 0x8B77E0C
	.incbin "graphics/pokemon/sealeo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Walrein
gMonFrontPic_Walrein: @ 0x8B78484
	.incbin "graphics/pokemon/walrein/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cacnea
gMonFrontPic_Cacnea: @ 0x8B78C54
	.incbin "graphics/pokemon/cacnea/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cacturne
gMonFrontPic_Cacturne: @ 0x8B7916C
	.incbin "graphics/pokemon/cacturne/anim_front.4bpp.lz"

	.globl gMonFrontPic_Snorunt
gMonFrontPic_Snorunt: @ 0x8B79928
	.incbin "graphics/pokemon/snorunt/anim_front.4bpp.lz"

	.globl gMonFrontPic_Glalie
gMonFrontPic_Glalie: @ 0x8B79E44
	.incbin "graphics/pokemon/glalie/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lunatone
gMonFrontPic_Lunatone: @ 0x8B7A568
	.incbin "graphics/pokemon/lunatone/anim_front.4bpp.lz"

	.globl gMonFrontPic_Solrock
gMonFrontPic_Solrock: @ 0x8B7AA90
	.incbin "graphics/pokemon/solrock/anim_front.4bpp.lz"

	.globl gMonFrontPic_Azurill
gMonFrontPic_Azurill: @ 0x8B7B264
	.incbin "graphics/pokemon/azurill/anim_front.4bpp.lz"

	.globl gMonFrontPic_Spoink
gMonFrontPic_Spoink: @ 0x8B7B7B4
	.incbin "graphics/pokemon/spoink/anim_front.4bpp.lz"

	.globl gMonFrontPic_Grumpig
gMonFrontPic_Grumpig: @ 0x8B7BBA0
	.incbin "graphics/pokemon/grumpig/anim_front.4bpp.lz"

	.globl gMonFrontPic_Plusle
gMonFrontPic_Plusle: @ 0x8B7C258
	.incbin "graphics/pokemon/plusle/anim_front.4bpp.lz"

	.globl gMonFrontPic_Minun
gMonFrontPic_Minun: @ 0x8B7C6F4
	.incbin "graphics/pokemon/minun/anim_front.4bpp.lz"

	.globl gMonFrontPic_Mawile
gMonFrontPic_Mawile: @ 0x8B7CB14
	.incbin "graphics/pokemon/mawile/anim_front.4bpp.lz"

	.globl gMonFrontPic_Meditite
gMonFrontPic_Meditite: @ 0x8B7D2A4
	.incbin "graphics/pokemon/meditite/anim_front.4bpp.lz"

	.globl gMonFrontPic_Medicham
gMonFrontPic_Medicham: @ 0x8B7D6E4
	.incbin "graphics/pokemon/medicham/anim_front.4bpp.lz"

	.globl gMonFrontPic_Swablu
gMonFrontPic_Swablu: @ 0x8B7DC3C
	.incbin "graphics/pokemon/swablu/anim_front.4bpp.lz"

	.globl gMonFrontPic_Altaria
gMonFrontPic_Altaria: @ 0x8B7E128
	.incbin "graphics/pokemon/altaria/anim_front.4bpp.lz"

	.globl gMonFrontPic_Wynaut
gMonFrontPic_Wynaut: @ 0x8B7E844
	.incbin "graphics/pokemon/wynaut/anim_front.4bpp.lz"

	.globl gMonFrontPic_Duskull
gMonFrontPic_Duskull: @ 0x8B7ECB8
	.incbin "graphics/pokemon/duskull/anim_front.4bpp.lz"

	.globl gMonFrontPic_Dusclops
gMonFrontPic_Dusclops: @ 0x8B7F228
	.incbin "graphics/pokemon/dusclops/anim_front.4bpp.lz"

	.globl gMonFrontPic_Roselia
gMonFrontPic_Roselia: @ 0x8B7F8D8
	.incbin "graphics/pokemon/roselia/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slakoth
gMonFrontPic_Slakoth: @ 0x8B7FEE8
	.incbin "graphics/pokemon/slakoth/anim_front.4bpp.lz"

	.globl gMonFrontPic_Vigoroth
gMonFrontPic_Vigoroth: @ 0x8B802D8
	.incbin "graphics/pokemon/vigoroth/anim_front.4bpp.lz"

	.globl gMonFrontPic_Slaking
gMonFrontPic_Slaking: @ 0x8B80A88
	.incbin "graphics/pokemon/slaking/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gulpin
gMonFrontPic_Gulpin: @ 0x8B81134
	.incbin "graphics/pokemon/gulpin/anim_front.4bpp.lz"

	.globl gMonFrontPic_Swalot
gMonFrontPic_Swalot: @ 0x8B814E4
	.incbin "graphics/pokemon/swalot/anim_front.4bpp.lz"

	.globl gMonFrontPic_Tropius
gMonFrontPic_Tropius: @ 0x8B81A78
	.incbin "graphics/pokemon/tropius/anim_front.4bpp.lz"

	.globl gMonFrontPic_Whismur
gMonFrontPic_Whismur: @ 0x8B8239C
	.incbin "graphics/pokemon/whismur/anim_front.4bpp.lz"

	.globl gMonFrontPic_Loudred
gMonFrontPic_Loudred: @ 0x8B82808
	.incbin "graphics/pokemon/loudred/anim_front.4bpp.lz"

	.globl gMonFrontPic_Exploud
gMonFrontPic_Exploud: @ 0x8B82F00
	.incbin "graphics/pokemon/exploud/anim_front.4bpp.lz"

	.globl gMonFrontPic_Clamperl
gMonFrontPic_Clamperl: @ 0x8B83908
	.incbin "graphics/pokemon/clamperl/anim_front.4bpp.lz"

	.globl gMonFrontPic_Huntail
gMonFrontPic_Huntail: @ 0x8B83DB4
	.incbin "graphics/pokemon/huntail/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gorebyss
gMonFrontPic_Gorebyss: @ 0x8B844A8
	.incbin "graphics/pokemon/gorebyss/anim_front.4bpp.lz"

	.globl gMonFrontPic_Absol
gMonFrontPic_Absol: @ 0x8B84A50
	.incbin "graphics/pokemon/absol/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shuppet
gMonFrontPic_Shuppet: @ 0x8B851C0
	.incbin "graphics/pokemon/shuppet/anim_front.4bpp.lz"

	.globl gMonFrontPic_Banette
gMonFrontPic_Banette: @ 0x8B855C0
	.incbin "graphics/pokemon/banette/anim_front.4bpp.lz"

	.globl gMonFrontPic_Seviper
gMonFrontPic_Seviper: @ 0x8B85ACC
	.incbin "graphics/pokemon/seviper/anim_front.4bpp.lz"

	.globl gMonFrontPic_Zangoose
gMonFrontPic_Zangoose: @ 0x8B8625C
	.incbin "graphics/pokemon/zangoose/anim_front.4bpp.lz"

	.globl gMonFrontPic_Relicanth
gMonFrontPic_Relicanth: @ 0x8B86978
	.incbin "graphics/pokemon/relicanth/anim_front.4bpp.lz"

	.globl gMonFrontPic_Aron
gMonFrontPic_Aron: @ 0x8B86EBC
	.incbin "graphics/pokemon/aron/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lairon
gMonFrontPic_Lairon: @ 0x8B87260
	.incbin "graphics/pokemon/lairon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Aggron
gMonFrontPic_Aggron: @ 0x8B87878
	.incbin "graphics/pokemon/aggron/anim_front.4bpp.lz"

	.globl gMonFrontPic_Castform
gMonFrontPic_Castform: @ 0x8B8824C
	.incbin "graphics/pokemon/castform/anim_front.4bpp.lz"

	.globl gMonFrontPic_Volbeat
gMonFrontPic_Volbeat: @ 0x8B88CD4
	.incbin "graphics/pokemon/volbeat/anim_front.4bpp.lz"

	.globl gMonFrontPic_Illumise
gMonFrontPic_Illumise: @ 0x8B892EC
	.incbin "graphics/pokemon/illumise/anim_front.4bpp.lz"

	.globl gMonFrontPic_Lileep
gMonFrontPic_Lileep: @ 0x8B8996C
	.incbin "graphics/pokemon/lileep/anim_front.4bpp.lz"

	.globl gMonFrontPic_Cradily
gMonFrontPic_Cradily: @ 0x8B89F64
	.incbin "graphics/pokemon/cradily/anim_front.4bpp.lz"

	.globl gMonFrontPic_Anorith
gMonFrontPic_Anorith: @ 0x8B8A6B4
	.incbin "graphics/pokemon/anorith/anim_front.4bpp.lz"

	.globl gMonFrontPic_Armaldo
gMonFrontPic_Armaldo: @ 0x8B8ACA0
	.incbin "graphics/pokemon/armaldo/anim_front.4bpp.lz"

	.globl gMonFrontPic_Ralts
gMonFrontPic_Ralts: @ 0x8B8B618
	.incbin "graphics/pokemon/ralts/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kirlia
gMonFrontPic_Kirlia: @ 0x8B8BA24
	.incbin "graphics/pokemon/kirlia/anim_front.4bpp.lz"

	.globl gMonFrontPic_Gardevoir
gMonFrontPic_Gardevoir: @ 0x8B8BF74
	.incbin "graphics/pokemon/gardevoir/anim_front.4bpp.lz"

	.globl gMonFrontPic_Bagon
gMonFrontPic_Bagon: @ 0x8B8C4A8
	.incbin "graphics/pokemon/bagon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Shelgon
gMonFrontPic_Shelgon: @ 0x8B8C93C
	.incbin "graphics/pokemon/shelgon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Salamence
gMonFrontPic_Salamence: @ 0x8B8CEA8
	.incbin "graphics/pokemon/salamence/anim_front.4bpp.lz"

	.globl gMonFrontPic_Beldum
gMonFrontPic_Beldum: @ 0x8B8D608
	.incbin "graphics/pokemon/beldum/anim_front.4bpp.lz"

	.globl gMonFrontPic_Metang
gMonFrontPic_Metang: @ 0x8B8DA6C
	.incbin "graphics/pokemon/metang/anim_front.4bpp.lz"

	.globl gMonFrontPic_Metagross
gMonFrontPic_Metagross: @ 0x8B8E23C
	.incbin "graphics/pokemon/metagross/anim_front.4bpp.lz"

	.globl gMonFrontPic_Regirock
gMonFrontPic_Regirock: @ 0x8B8E920
	.incbin "graphics/pokemon/regirock/anim_front.4bpp.lz"

	.globl gMonFrontPic_Regice
gMonFrontPic_Regice: @ 0x8B8F1E8
	.incbin "graphics/pokemon/regice/anim_front.4bpp.lz"

	.globl gMonFrontPic_Registeel
gMonFrontPic_Registeel: @ 0x8B8F994
	.incbin "graphics/pokemon/registeel/anim_front.4bpp.lz"

	.globl gMonFrontPic_Kyogre
gMonFrontPic_Kyogre: @ 0x8B90170
	.incbin "graphics/pokemon/kyogre/anim_front.4bpp.lz"

	.globl gMonFrontPic_Groudon
gMonFrontPic_Groudon: @ 0x8B90948
	.incbin "graphics/pokemon/groudon/anim_front.4bpp.lz"

	.globl gMonFrontPic_Rayquaza
gMonFrontPic_Rayquaza: @ 0x8B9135C
	.incbin "graphics/pokemon/rayquaza/anim_front.4bpp.lz"

	.globl gMonFrontPic_Latias
gMonFrontPic_Latias: @ 0x8B91CF0
	.incbin "graphics/pokemon/latias/anim_front.4bpp.lz"

	.globl gMonFrontPic_Latios
gMonFrontPic_Latios: @ 0x8B92378
	.incbin "graphics/pokemon/latios/anim_front.4bpp.lz"

	.globl gMonFrontPic_Jirachi
gMonFrontPic_Jirachi: @ 0x8B92BA8
	.incbin "graphics/pokemon/jirachi/anim_front.4bpp.lz"

	.globl gMonFrontPic_Deoxys
gMonFrontPic_Deoxys: @ 0x8B93154
	.incbin "graphics/pokemon/deoxys/anim_front.4bpp.lz"

	.globl gMonFrontPic_Chimecho
gMonFrontPic_Chimecho: @ 0x8B938C0
	.incbin "graphics/pokemon/chimecho/anim_front.4bpp.lz"

	.globl gMonFrontPic_Egg
gMonFrontPic_Egg: @ 0x8B93D08
	.incbin "graphics/pokemon/egg/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownB
gMonFrontPic_UnownB: @ 0x8B93FC4
	.incbin "graphics/pokemon/unown/b/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownC
gMonFrontPic_UnownC: @ 0x8B9428C
	.incbin "graphics/pokemon/unown/c/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownD
gMonFrontPic_UnownD: @ 0x8B94590
	.incbin "graphics/pokemon/unown/d/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownE
gMonFrontPic_UnownE: @ 0x8B94878
	.incbin "graphics/pokemon/unown/e/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownF
gMonFrontPic_UnownF: @ 0x8B94B20
	.incbin "graphics/pokemon/unown/f/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownG
gMonFrontPic_UnownG: @ 0x8B94E08
	.incbin "graphics/pokemon/unown/g/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownH
gMonFrontPic_UnownH: @ 0x8B950D4
	.incbin "graphics/pokemon/unown/h/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownI
gMonFrontPic_UnownI: @ 0x8B9540C
	.incbin "graphics/pokemon/unown/i/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownJ
gMonFrontPic_UnownJ: @ 0x8B95698
	.incbin "graphics/pokemon/unown/j/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownK
gMonFrontPic_UnownK: @ 0x8B95950
	.incbin "graphics/pokemon/unown/k/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownL
gMonFrontPic_UnownL: @ 0x8B95C10
	.incbin "graphics/pokemon/unown/l/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownM
gMonFrontPic_UnownM: @ 0x8B95EB4
	.incbin "graphics/pokemon/unown/m/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownN
gMonFrontPic_UnownN: @ 0x8B961C8
	.incbin "graphics/pokemon/unown/n/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownO
gMonFrontPic_UnownO: @ 0x8B964B0
	.incbin "graphics/pokemon/unown/o/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownP
gMonFrontPic_UnownP: @ 0x8B967DC
	.incbin "graphics/pokemon/unown/p/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownQ
gMonFrontPic_UnownQ: @ 0x8B96A6C
	.incbin "graphics/pokemon/unown/q/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownR
gMonFrontPic_UnownR: @ 0x8B96D14
	.incbin "graphics/pokemon/unown/r/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownS
gMonFrontPic_UnownS: @ 0x8B96FA8
	.incbin "graphics/pokemon/unown/s/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownT
gMonFrontPic_UnownT: @ 0x8B97284
	.incbin "graphics/pokemon/unown/t/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownU
gMonFrontPic_UnownU: @ 0x8B97528
	.incbin "graphics/pokemon/unown/u/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownV
gMonFrontPic_UnownV: @ 0x8B97834
	.incbin "graphics/pokemon/unown/v/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownW
gMonFrontPic_UnownW: @ 0x8B97B0C
	.incbin "graphics/pokemon/unown/w/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownX
gMonFrontPic_UnownX: @ 0x8B97DD4
	.incbin "graphics/pokemon/unown/x/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownY
gMonFrontPic_UnownY: @ 0x8B98088
	.incbin "graphics/pokemon/unown/y/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownZ
gMonFrontPic_UnownZ: @ 0x8B98350
	.incbin "graphics/pokemon/unown/z/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownExclamationMark
gMonFrontPic_UnownExclamationMark: @ 0x8B985F4
	.incbin "graphics/pokemon/unown/exclamation_mark/anim_front.4bpp.lz"

	.globl gMonFrontPic_UnownQuestionMark
gMonFrontPic_UnownQuestionMark: @ 0x8B98878
	.incbin "graphics/pokemon/unown/question_mark/anim_front.4bpp.lz"
	.incbin "baserom_jp.gba", 0xb98b26, 0x674da
