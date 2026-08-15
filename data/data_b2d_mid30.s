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

	.globl gUnknown_830FC29
gUnknown_830FC29: @ 0x830FC29
	.incbin "baserom_jp.gba", 0x30fc29, 0x5

	.globl gUnknown_830FC2E
gUnknown_830FC2E: @ 0x830FC2E
	.incbin "baserom_jp.gba", 0x30fc2e, 0x5

	.globl gUnknown_830FC33
gUnknown_830FC33: @ 0x830FC33
	.incbin "baserom_jp.gba", 0x30fc33, 0x5

	.globl gUnknown_830FC38
gUnknown_830FC38: @ 0x830FC38
	.string "きのみブレンダー\n"
	.string "さいこうそくど　ランキング！$"
	.globl gUnknown_830FC50
gUnknown_830FC50: @ 0x830FC50
	.incbin "baserom_jp.gba", 0x30fc50, 0x10

	.globl gUnknown_830FC60
gUnknown_830FC60: @ 0x830FC60
	.incbin "baserom_jp.gba", 0x30fc60, 0x8

	.globl sContestWinnerPicDummy
sContestWinnerPicDummy: @ 0x830FC68
	.incbin "graphics/jp/sContestWinnerPicDummy.bin"

	.globl gUnknown_830FC88
gUnknown_830FC88: @ 0x830FC88
	.incbin "baserom_jp.gba", 0x30fc88, 0x28

	.globl gDirectionToVectors
gDirectionToVectors: @ 0x830FCB0
	.4byte 0 @ DIR_NONE.x
	.4byte 0 @ DIR_NONE.y
	.4byte 0 @ DIR_SOUTH.x
	.4byte 1 @ DIR_SOUTH.y
	.4byte 0 @ DIR_NORTH.x
	.4byte -1 @ DIR_NORTH.y
	.4byte -1 @ DIR_WEST.x
	.4byte 0 @ DIR_WEST.y
	.4byte 1 @ DIR_EAST.x
	.4byte 0 @ DIR_EAST.y
	.4byte -1 @ DIR_SOUTHWEST.x
	.4byte 1 @ DIR_SOUTHWEST.y
	.4byte 1 @ DIR_SOUTHEAST.x
	.4byte 1 @ DIR_SOUTHEAST.y
	.4byte -1 @ DIR_NORTHWEST.x
	.4byte -1 @ DIR_NORTHWEST.y
	.4byte 1 @ DIR_NORTHEAST.x
	.4byte -1 @ DIR_NORTHEAST.y
	.globl gUnknown_830FCF8
gUnknown_830FCF8: @ 0x830FCF8
	.incbin "baserom_jp.gba", 0x30fcf8, 0x10

	.globl gUnknown_830FD08
gUnknown_830FD08: @ 0x830FD08
	.incbin "baserom_jp.gba", 0x30fd08, 0xc

	.globl gUnknown_830FD14
gUnknown_830FD14: @ 0x830FD14
	.incbin "baserom_jp.gba", 0x30fd14, 0xc

	.globl gUnknown_830FD20
gUnknown_830FD20: @ 0x830FD20
	.incbin "baserom_jp.gba", 0x30fd20, 0x2c

	.globl gUnknown_830FD4C
gUnknown_830FD4C: @ 0x830FD4C
	.globl gUnknown_830FD4C
gUnknown_830FD4C: @ 0x0830FD4C
	.incbin "baserom_jp.gba", 0x30FD4C, 0xA7DD8
	.globl gTileset_PETALBURG_CITY_PRIMARY
gTileset_PETALBURG_CITY_PRIMARY: @ 0x083B7B24
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0830FD54  @ tiles
	.4byte 0x08312028  @ palettes
	.4byte 0x0836E510  @ metatiles
	.4byte 0x08370510  @ metatileAttributes
	.4byte 0x080A03E9  @ callback
	.globl gTileset_PETALBURG_CITY_SECONDARY
gTileset_PETALBURG_CITY_SECONDARY: @ 0x083B7B3C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08312228  @ tiles
	.4byte 0x08312B24  @ palettes
	.4byte 0x08370910  @ metatiles
	.4byte 0x08371210  @ metatileAttributes
	.4byte 0x080A0535  @ callback
	.globl gTileset_RUSTBORO_CITY_SECONDARY
gTileset_RUSTBORO_CITY_SECONDARY: @ 0x083B7B54
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08312D24  @ tiles
	.4byte 0x083142E0  @ palettes
	.4byte 0x08371330  @ metatiles
	.4byte 0x08372910  @ metatileAttributes
	.4byte 0x080A055D  @ callback
	.globl gTileset_DEWFORD_TOWN_SECONDARY
gTileset_DEWFORD_TOWN_SECONDARY: @ 0x083B7B6C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083144E0  @ tiles
	.4byte 0x08315960  @ palettes
	.4byte 0x08372BCC  @ metatiles
	.4byte 0x0837437C  @ metatileAttributes
	.4byte 0x080A0589  @ callback
	.globl gTileset_SLATEPORT_CITY_SECONDARY
gTileset_SLATEPORT_CITY_SECONDARY: @ 0x083B7B84
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08315B60  @ tiles
	.4byte 0x08317B28  @ palettes
	.4byte 0x08374672  @ metatiles
	.4byte 0x08375FD2  @ metatileAttributes
	.4byte 0x080A05B5  @ callback
	.globl gTileset_MAUVILLE_CITY_SECONDARY
gTileset_MAUVILLE_CITY_SECONDARY: @ 0x083B7B9C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08317D28  @ tiles
	.4byte 0x08319B4C  @ palettes
	.4byte 0x083762FE  @ metatiles
	.4byte 0x083782DE  @ metatileAttributes
	.4byte 0x080A05E1  @ callback
	.globl gTileset_LAVARIDGE_TOWN_SECONDARY
gTileset_LAVARIDGE_TOWN_SECONDARY: @ 0x083B7BB4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08319D4C  @ tiles
	.4byte 0x0831B248  @ palettes
	.4byte 0x083786DA  @ metatiles
	.4byte 0x0837A26A  @ metatileAttributes
	.4byte 0x080A0611  @ callback
	.globl gTileset_FALLARBOR_TOWN_SECONDARY
gTileset_FALLARBOR_TOWN_SECONDARY: @ 0x083B7BCC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831B448  @ tiles
	.4byte 0x0831CBC0  @ palettes
	.4byte 0x0837A5DC  @ metatiles
	.4byte 0x0837BCCC  @ metatileAttributes
	.4byte 0x080A063D  @ callback
	.globl gTileset_FORTREE_CITY_SECONDARY
gTileset_FORTREE_CITY_SECONDARY: @ 0x083B7BE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831CDC0  @ tiles
	.4byte 0x0831E440  @ palettes
	.4byte 0x0837BFAA  @ metatiles
	.4byte 0x0837D12A  @ metatileAttributes
	.4byte 0x080A0665  @ callback
	.globl gTileset_LILYCOVE_CITY_SECONDARY
gTileset_LILYCOVE_CITY_SECONDARY: @ 0x083B7BFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831E640  @ tiles
	.4byte 0x0831F9E0  @ palettes
	.4byte 0x0837D35A  @ metatiles
	.4byte 0x0837E94A  @ metatileAttributes
	.4byte 0x080A068D  @ callback
	.globl gTileset_MOSSDEEP_CITY_SECONDARY
gTileset_MOSSDEEP_CITY_SECONDARY: @ 0x083B7C14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0831FBE0  @ tiles
	.4byte 0x08321230  @ palettes
	.4byte 0x0837EC08  @ metatiles
	.4byte 0x08380868  @ metatileAttributes
	.4byte 0x080A06B5  @ callback
	.globl gTileset_EVER_GRANDE_CITY_SECONDARY
gTileset_EVER_GRANDE_CITY_SECONDARY: @ 0x083B7C2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08321430  @ tiles
	.4byte 0x08322048  @ palettes
	.4byte 0x08380BF4  @ metatiles
	.4byte 0x08381674  @ metatileAttributes
	.4byte 0x080A06DD  @ callback
	.globl gTileset_PACIFIDLOG_TOWN_SECONDARY
gTileset_PACIFIDLOG_TOWN_SECONDARY: @ 0x083B7C44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08322248  @ tiles
	.4byte 0x083239D4  @ palettes
	.4byte 0x083817C4  @ metatiles
	.4byte 0x08382474  @ metatileAttributes
	.4byte 0x080A0709  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_SECONDARY
gTileset_SOOTOPOLIS_CITY_SECONDARY: @ 0x083B7C5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08323BD4  @ tiles
	.4byte 0x08324AD4  @ palettes
	.4byte 0x0838260A  @ metatiles
	.4byte 0x083835EA  @ metatileAttributes
	.4byte 0x080A0739  @ callback
	.incbin "baserom_jp.gba", 0x3B7C74, 0x30
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY: @ 0x083B7CA4
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08327FA4  @ tiles
	.4byte 0x08328CDC  @ palettes
	.4byte 0x08387F9E  @ metatiles
	.4byte 0x0838801E  @ metatileAttributes
	.4byte 0x080A0411  @ callback
	.globl gTileset_OLDALE_TOWN_MART_SECONDARY
gTileset_OLDALE_TOWN_MART_SECONDARY: @ 0x083B7CBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08328EDC  @ tiles
	.4byte 0x0832A4FC  @ palettes
	.4byte 0x0838802E  @ metatiles
	.4byte 0x0838923E  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY: @ 0x083B7CD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832A6FC  @ tiles
	.4byte 0x0832B994  @ palettes
	.4byte 0x08389480  @ metatiles
	.4byte 0x0838A300  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DESERT_RUINS_SECONDARY
gTileset_DESERT_RUINS_SECONDARY: @ 0x083B7CEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832BB94  @ tiles
	.4byte 0x0832D680  @ palettes
	.4byte 0x0838A4D0  @ metatiles
	.4byte 0x0838BEB0  @ metatileAttributes
	.4byte 0x080A0805  @ callback
	.globl gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY: @ 0x083B7D04
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832D880  @ tiles
	.4byte 0x0832DFC8  @ palettes
	.4byte 0x0838C1EC  @ metatiles
	.4byte 0x0838C58C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY: @ 0x083B7D1C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832E1C8  @ tiles
	.4byte 0x0832EAF4  @ palettes
	.4byte 0x0838C600  @ metatiles
	.4byte 0x0838CC80  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D34, 0x18
	.globl gTileset_METEOR_FALLS_1F_1R_SECONDARY
gTileset_METEOR_FALLS_1F_1R_SECONDARY: @ 0x083B7D4C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0832EF40  @ tiles
	.4byte 0x08330C60  @ palettes
	.4byte 0x0838CD74  @ metatiles
	.4byte 0x0838D764  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY: @ 0x083B7D64
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08330E60  @ tiles
	.4byte 0x08331DEC  @ palettes
	.4byte 0x0838D8A2  @ metatiles
	.4byte 0x0838E042  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY: @ 0x083B7D7C
	.byte 0x00, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08331FEC  @ tiles
	.4byte 0x08336EEC  @ palettes
	.4byte 0x0838E136  @ metatiles
	.4byte 0x0838F136  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D94, 0x18
	.globl gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY: @ 0x083B7DAC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08337BC8  @ tiles
	.4byte 0x083387C0  @ palettes
	.4byte 0x0838F726  @ metatiles
	.4byte 0x0838FBA6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY: @ 0x083B7DC4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083389C0  @ tiles
	.4byte 0x083393FC  @ palettes
	.4byte 0x0838FC36  @ metatiles
	.4byte 0x08390076  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY: @ 0x083B7DDC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083395FC  @ tiles
	.4byte 0x0833B2B0  @ palettes
	.4byte 0x083900FE  @ metatiles
	.4byte 0x083920EE  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY: @ 0x083B7DF4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0833B4B0  @ tiles
	.4byte 0x0833C7E0  @ palettes
	.4byte 0x083924EC  @ metatiles
	.4byte 0x0839346C  @ metatileAttributes
	.4byte 0x080A0881  @ callback
	.globl gTileset_RUSTURF_TUNNEL_SECONDARY
gTileset_RUSTURF_TUNNEL_SECONDARY: @ 0x083B7E0C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0833C9E0  @ tiles
	.4byte 0x0833D428  @ palettes
	.4byte 0x0839365C  @ metatiles
	.4byte 0x08393B8C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7E24, 0xC0
	.globl gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY: @ 0x083B7EE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834425C  @ tiles
	.4byte 0x08344DB0  @ palettes
	.4byte 0x083955A6  @ metatiles
	.4byte 0x08396436  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY: @ 0x083B7EFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08344FB0  @ tiles
	.4byte 0x083462CC  @ palettes
	.4byte 0x08396608  @ metatiles
	.4byte 0x08396EF8  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY: @ 0x083B7F14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083464CC  @ tiles
	.4byte 0x08347598  @ palettes
	.4byte 0x08397016  @ metatiles
	.4byte 0x08397C56  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY: @ 0x083B7F2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08347798  @ tiles
	.4byte 0x083487FC  @ palettes
	.4byte 0x08397DDE  @ metatiles
	.4byte 0x083987BE  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_UNDERWATER_ROUTE126_SECONDARY
gTileset_UNDERWATER_ROUTE126_SECONDARY: @ 0x083B7F44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x083489FC  @ tiles
	.4byte 0x08349BB8  @ palettes
	.4byte 0x083988FA  @ metatiles
	.4byte 0x083997BA  @ metatileAttributes
	.4byte 0x080A07BD  @ callback
	.globl gTileset_PETALBURG_CITY_GYM_SECONDARY
gTileset_PETALBURG_CITY_GYM_SECONDARY: @ 0x083B7F5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834E8CC  @ tiles
	.4byte 0x0834EF70  @ palettes
	.4byte 0x0839DDB4  @ metatiles
	.4byte 0x0839EBB4  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY: @ 0x083B7F74
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834FD50  @ tiles
	.4byte 0x08350EE4  @ palettes
	.4byte 0x0839FB4E  @ metatiles
	.4byte 0x083A02EE  @ metatileAttributes
	.4byte 0x080A07E1  @ callback
	.globl gTileset_OLDALE_TOWN_HOUSE1_SECONDARY
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY: @ 0x083B7F8C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08349DB8  @ tiles
	.4byte 0x0834B7E4  @ palettes
	.4byte 0x08399992  @ metatiles
	.4byte 0x0839B992  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY: @ 0x083B7FA4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834B9E4  @ tiles
	.4byte 0x0834C6A8  @ palettes
	.4byte 0x0839BD92  @ metatiles
	.4byte 0x0839C392  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_RUSTBORO_CITY_GYM_SECONDARY
gTileset_RUSTBORO_CITY_GYM_SECONDARY: @ 0x083B7FBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834CFD0  @ tiles
	.4byte 0x0834D354  @ palettes
	.4byte 0x0839C866  @ metatiles
	.4byte 0x0839CBE6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DEWFORD_TOWN_GYM_SECONDARY
gTileset_DEWFORD_TOWN_GYM_SECONDARY: @ 0x083B7FD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834D554  @ tiles
	.4byte 0x0834D820  @ palettes
	.4byte 0x0839CC56  @ metatiles
	.4byte 0x0839D0A6  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GYM_SECONDARY
gTileset_MAUVILLE_CITY_GYM_SECONDARY: @ 0x083B7FEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834DA20  @ tiles
	.4byte 0x0834E1A4  @ palettes
	.4byte 0x0839D130  @ metatiles
	.4byte 0x0839D880  @ metatileAttributes
	.4byte 0x080A0855  @ callback
	.globl gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY: @ 0x083B8004
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834E3A4  @ tiles
	.4byte 0x0834E6CC  @ palettes
	.4byte 0x0839D96A  @ metatiles
	.4byte 0x0839DD3A  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B801C, 0x18
	.globl gTileset_FORTREE_CITY_GYM_SECONDARY
gTileset_FORTREE_CITY_GYM_SECONDARY: @ 0x083B8034
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834F170  @ tiles
	.4byte 0x0834F4E4  @ palettes
	.4byte 0x0839ED74  @ metatiles
	.4byte 0x0839F274  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MOSSDEEP_CITY_GYM_SECONDARY
gTileset_MOSSDEEP_CITY_GYM_SECONDARY: @ 0x083B804C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0834F6E4  @ tiles
	.4byte 0x0834FB50  @ palettes
	.4byte 0x0839F314  @ metatiles
	.4byte 0x0839FA64  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B8064, 0x30

	.globl gUnknown_83B8094
gUnknown_83B8094: @ 0x83B8094
	.incbin "baserom_jp.gba", 0x3b8094, 0x4

	.globl gUnknown_83B8098
gUnknown_83B8098: @ 0x83B8098
	.globl gUnknown_83B8098
gUnknown_83B8098: @ 0x083B8098
	.incbin "baserom_jp.gba", 0x3B8098, 0x4
	.globl gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY: @ 0x083B809C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0835B068  @ tiles
	.4byte 0x0835C0E4  @ palettes
	.4byte 0x083A2308  @ metatiles
	.4byte 0x083A37C8  @ metatileAttributes
	.4byte 0x080A0831  @ callback
	.globl gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY: @ 0x083B80B4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0835C2E4  @ tiles
	.4byte 0x0835CFE8  @ palettes
	.4byte 0x083A3A60  @ metatiles
	.4byte 0x083A5A30  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B80CC, 0xA8
	.globl gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY: @ 0x083B8174
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x08365604  @ tiles
	.4byte 0x08365A24  @ palettes
	.4byte 0x083AF2CE  @ metatiles
	.4byte 0x083AF61E  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B818C, 0x60
	.globl gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY: @ 0x083B81EC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0836B2CC  @ tiles
	.4byte 0x0836BD30  @ palettes
	.4byte 0x083B6012  @ metatiles
	.4byte 0x083B70E2  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY: @ 0x083B8204
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte 0x0836BF30  @ tiles
	.4byte 0x0836D898  @ palettes
	.4byte 0x083B72FC  @ metatiles
	.4byte 0x083B772C  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B821C, 0x728
	.globl gMapLayout_PETALBURG_CITY
gMapLayout_PETALBURG_CITY: @ 0x083B8944
	.4byte 30  @ width
	.4byte 30  @ height
	.4byte 0x083B8234  @ border
	.4byte 0x083B823C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3B895C, 0x12C8
	.globl gMapLayout_SLATEPORT_CITY
gMapLayout_SLATEPORT_CITY: @ 0x083B9C24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083B895C  @ border
	.4byte 0x083B8964  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3B9C3C, 0x648
	.globl gMapLayout_MAUVILLE_CITY
gMapLayout_MAUVILLE_CITY: @ 0x083BA284
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte 0x083B9C3C  @ border
	.4byte 0x083B9C44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BA29C, 0x12C8
	.globl gMapLayout_RUSTBORO_CITY
gMapLayout_RUSTBORO_CITY: @ 0x083BB564
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083BA29C  @ border
	.4byte 0x083BA2A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BB57C, 0x648
	.globl gMapLayout_FORTREE_CITY
gMapLayout_FORTREE_CITY: @ 0x083BBBC4
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte 0x083BB57C  @ border
	.4byte 0x083BB584  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BBBDC, 0x1908
	.globl gMapLayout_LILYCOVE_CITY
gMapLayout_LILYCOVE_CITY: @ 0x083BD4E4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083BBBDC  @ border
	.4byte 0x083BBBE4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BD4FC, 0x1908
	.globl gMapLayout_MOSSDEEP_CITY
gMapLayout_MOSSDEEP_CITY: @ 0x083BEE04
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083BD4FC  @ border
	.4byte 0x083BD504  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3BEE1C, 0x1C28
	.globl gMapLayout_SOOTOPOLIS_CITY
gMapLayout_SOOTOPOLIS_CITY: @ 0x083C0A44
	.4byte 60  @ width
	.4byte 60  @ height
	.4byte 0x083BEE1C  @ border
	.4byte 0x083BEE24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C0A5C, 0x1908
	.globl gMapLayout_EVER_GRANDE_CITY
gMapLayout_EVER_GRANDE_CITY: @ 0x083C2364
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C0A5C  @ border
	.4byte 0x083C0A64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C237C, 0x328
	.globl gMapLayout_LITTLEROOT_TOWN
gMapLayout_LITTLEROOT_TOWN: @ 0x083C26A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C237C  @ border
	.4byte 0x083C2384  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C26BC, 0x328
	.globl gMapLayout_OLDALE_TOWN
gMapLayout_OLDALE_TOWN: @ 0x083C29E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C26BC  @ border
	.4byte 0x083C26C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C29FC, 0x328
	.globl gMapLayout_DEWFORD_TOWN
gMapLayout_DEWFORD_TOWN: @ 0x083C2D24
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C29FC  @ border
	.4byte 0x083C2A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C2D3C, 0x328
	.globl gMapLayout_LAVARIDGE_TOWN
gMapLayout_LAVARIDGE_TOWN: @ 0x083C3064
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C2D3C  @ border
	.4byte 0x083C2D44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C307C, 0x328
	.globl gMapLayout_FALLARBOR_TOWN
gMapLayout_FALLARBOR_TOWN: @ 0x083C33A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C307C  @ border
	.4byte 0x083C3084  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C33BC, 0x328
	.globl gMapLayout_VERDANTURF_TOWN
gMapLayout_VERDANTURF_TOWN: @ 0x083C36E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C33BC  @ border
	.4byte 0x083C33C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C36FC, 0x648
	.globl gMapLayout_PACIFIDLOG_TOWN
gMapLayout_PACIFIDLOG_TOWN: @ 0x083C3D44
	.4byte 20  @ width
	.4byte 40  @ height
	.4byte 0x083C36FC  @ border
	.4byte 0x083C3704  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C3D5C, 0x328
	.globl gMapLayout_ROUTE101
gMapLayout_ROUTE101: @ 0x083C4084
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x083C3D5C  @ border
	.4byte 0x083C3D64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C409C, 0x7D8
	.globl gMapLayout_ROUTE102
gMapLayout_ROUTE102: @ 0x083C4874
	.4byte 50  @ width
	.4byte 20  @ height
	.4byte 0x083C409C  @ border
	.4byte 0x083C40A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C488C, 0xDC8
	.globl gMapLayout_ROUTE103
gMapLayout_ROUTE103: @ 0x083C5654
	.4byte 80  @ width
	.4byte 22  @ height
	.4byte 0x083C488C  @ border
	.4byte 0x083C4894  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C566C, 0x1908
	.globl gMapLayout_ROUTE104
gMapLayout_ROUTE104: @ 0x083C6F74
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C566C  @ border
	.4byte 0x083C5674  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C6F8C, 0x1908
	.globl gMapLayout_ROUTE105
gMapLayout_ROUTE105: @ 0x083C8894
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083C6F8C  @ border
	.4byte 0x083C6F94  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C88AC, 0xC88
	.globl gMapLayout_ROUTE106
gMapLayout_ROUTE106: @ 0x083C9534
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083C88AC  @ border
	.4byte 0x083C88B4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C954C, 0x968
	.globl gMapLayout_ROUTE107
gMapLayout_ROUTE107: @ 0x083C9EB4
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083C954C  @ border
	.4byte 0x083C9554  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3C9ECC, 0x968
	.globl gMapLayout_ROUTE108
gMapLayout_ROUTE108: @ 0x083CA834
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083C9ECC  @ border
	.4byte 0x083C9ED4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CA84C, 0x13B8
	.globl gMapLayout_ROUTE109
gMapLayout_ROUTE109: @ 0x083CBC04
	.4byte 40  @ width
	.4byte 63  @ height
	.4byte 0x083CA84C  @ border
	.4byte 0x083CA854  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CBC1C, 0x1F48
	.globl gMapLayout_ROUTE110
gMapLayout_ROUTE110: @ 0x083CDB64
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte 0x083CBC1C  @ border
	.4byte 0x083CBC24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3CDB7C, 0x2BC8
	.globl gMapLayout_ROUTE111
gMapLayout_ROUTE111: @ 0x083D0744
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte 0x083CDB7C  @ border
	.4byte 0x083CDB84  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D075C, 0x12C8
	.globl gMapLayout_ROUTE112
gMapLayout_ROUTE112: @ 0x083D1A24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte 0x083D075C  @ border
	.4byte 0x083D0764  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D1A3C, 0xFA8
	.globl gMapLayout_ROUTE113
gMapLayout_ROUTE113: @ 0x083D29E4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte 0x083D1A3C  @ border
	.4byte 0x083D1A44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D29FC, 0x1908
	.globl gMapLayout_ROUTE114
gMapLayout_ROUTE114: @ 0x083D4304
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083D29FC  @ border
	.4byte 0x083D2A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D431C, 0x1908
	.globl gMapLayout_ROUTE115
gMapLayout_ROUTE115: @ 0x083D5C24
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x083D431C  @ border
	.4byte 0x083D4324  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D5C3C, 0xFA8
	.globl gMapLayout_ROUTE116
gMapLayout_ROUTE116: @ 0x083D6BE4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte 0x083D5C3C  @ border
	.4byte 0x083D5C44  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D6BFC, 0x968
	.globl gMapLayout_ROUTE117
gMapLayout_ROUTE117: @ 0x083D7564
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte 0x083D6BFC  @ border
	.4byte 0x083D6C04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D757C, 0xC88
	.globl gMapLayout_ROUTE118
gMapLayout_ROUTE118: @ 0x083D8204
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083D757C  @ border
	.4byte 0x083D7584  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3D821C, 0x2BC8
	.globl gMapLayout_ROUTE119
gMapLayout_ROUTE119: @ 0x083DADE4
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte 0x083D821C  @ border
	.4byte 0x083D8224  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DADFC, 0x1F48
	.globl gMapLayout_ROUTE120
gMapLayout_ROUTE120: @ 0x083DCD44
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte 0x083DADFC  @ border
	.4byte 0x083DAE04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DCD5C, 0xC88
	.globl gMapLayout_ROUTE121
gMapLayout_ROUTE121: @ 0x083DD9E4
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte 0x083DCD5C  @ border
	.4byte 0x083DCD64  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DD9FC, 0xC88
	.globl gMapLayout_ROUTE122
gMapLayout_ROUTE122: @ 0x083DE684
	.4byte 40  @ width
	.4byte 40  @ height
	.4byte 0x083DD9FC  @ border
	.4byte 0x083DDA04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DE69C, 0x15E8
	.globl gMapLayout_ROUTE123
gMapLayout_ROUTE123: @ 0x083DFC84
	.4byte 140  @ width
	.4byte 20  @ height
	.4byte 0x083DE69C  @ border
	.4byte 0x083DE6A4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3DFC9C, 0x3208
	.globl gMapLayout_ROUTE124
gMapLayout_ROUTE124: @ 0x083E2EA4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083DFC9C  @ border
	.4byte 0x083DFCA4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E2EBC, 0x1908
	.globl gMapLayout_ROUTE125
gMapLayout_ROUTE125: @ 0x083E47C4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083E2EBC  @ border
	.4byte 0x083E2EC4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E47DC, 0x3208
	.globl gMapLayout_ROUTE126
gMapLayout_ROUTE126: @ 0x083E79E4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083E47DC  @ border
	.4byte 0x083E47E4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3E79FC, 0x3208
	.globl gMapLayout_ROUTE127
gMapLayout_ROUTE127: @ 0x083EAC04
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083E79FC  @ border
	.4byte 0x083E7A04  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3EAC1C, 0x2588
	.globl gMapLayout_ROUTE128
gMapLayout_ROUTE128: @ 0x083ED1A4
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte 0x083EAC1C  @ border
	.4byte 0x083EAC24  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3ED1BC, 0x1908
	.globl gMapLayout_ROUTE129
gMapLayout_ROUTE129: @ 0x083EEAC4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083ED1BC  @ border
	.4byte 0x083ED1C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3EEADC, 0x2BE8
	.globl gMapLayout_ROUTE131
gMapLayout_ROUTE131: @ 0x083F16C4
	.4byte 60  @ width
	.4byte 40  @ height
	.4byte 0x083F03FC  @ border
	.4byte 0x083F0404  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F16DC, 0x1908
	.globl gMapLayout_ROUTE132
gMapLayout_ROUTE132: @ 0x083F2FE4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F16DC  @ border
	.4byte 0x083F16E4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F2FFC, 0x1908
	.globl gMapLayout_ROUTE133
gMapLayout_ROUTE133: @ 0x083F4904
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F2FFC  @ border
	.4byte 0x083F3004  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F491C, 0x1908
	.globl gMapLayout_ROUTE134
gMapLayout_ROUTE134: @ 0x083F6224
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x083F491C  @ border
	.4byte 0x083F4924  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F623C, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE126
gMapLayout_UNDERWATER_ROUTE126: @ 0x083F9444
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083F623C  @ border
	.4byte 0x083F6244  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3F945C, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE127
gMapLayout_UNDERWATER_ROUTE127: @ 0x083FC664
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x083F945C  @ border
	.4byte 0x083F9464  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FC67C, 0x2588
	.globl gMapLayout_UNDERWATER_ROUTE128
gMapLayout_UNDERWATER_ROUTE128: @ 0x083FEC04
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte 0x083FC67C  @ border
	.4byte 0x083FC684  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEC1C, 0xD0
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F: @ 0x083FECEC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x083FEC1C  @ border
	.4byte 0x083FEC24  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FED04, 0x98
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F: @ 0x083FED9C
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte 0x083FED04  @ border
	.4byte 0x083FED0C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEDB4, 0xD0
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F: @ 0x083FEE84
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x083FEDB4  @ border
	.4byte 0x083FEDBC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEE9C, 0x98
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F: @ 0x083FEF34
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte 0x083FEE9C  @ border
	.4byte 0x083FEEA4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FEF4C, 0x15C
	.globl gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB: @ 0x083FF0A8
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x083FEF4C  @ border
	.4byte 0x083FEF54  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF0C0, 0xBC
	.globl gMapLayout_OLDALE_TOWN_HOUSE1
gMapLayout_OLDALE_TOWN_HOUSE1: @ 0x083FF17C
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x083FF0C0  @ border
	.4byte 0x083FF0C8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF194, 0xB8
	.globl gMapLayout_OLDALE_TOWN_HOUSE2
gMapLayout_OLDALE_TOWN_HOUSE2: @ 0x083FF24C
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FF194  @ border
	.4byte 0x083FF19C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF264, 0x104
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F: @ 0x083FF368
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x083FF264  @ border
	.4byte 0x083FF26C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF380, 0x120
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F: @ 0x083FF4A0
	.4byte 14  @ width
	.4byte 10  @ height
	.4byte 0x083FF380  @ border
	.4byte 0x083FF388  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF4B8, 0xB8
	.globl gMapLayout_OLDALE_TOWN_MART
gMapLayout_OLDALE_TOWN_MART: @ 0x083FF570
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FF4B8  @ border
	.4byte 0x083FF4C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF588, 0xA8
	.globl gMapLayout_DEWFORD_TOWN_HOUSE1
gMapLayout_DEWFORD_TOWN_HOUSE1: @ 0x083FF630
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x083FF588  @ border
	.4byte 0x083FF590  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FF648, 0x3F8
	.globl gMapLayout_DEWFORD_TOWN_GYM
gMapLayout_DEWFORD_TOWN_GYM: @ 0x083FFA40
	.4byte 18  @ width
	.4byte 28  @ height
	.4byte 0x083FF648  @ border
	.4byte 0x083FF650  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFA58, 0x13C
	.globl gMapLayout_DEWFORD_TOWN_HALL
gMapLayout_DEWFORD_TOWN_HALL: @ 0x083FFB94
	.4byte 17  @ width
	.4byte 9  @ height
	.4byte 0x083FFA58  @ border
	.4byte 0x083FFA60  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFBAC, 0xBC
	.globl gMapLayout_DEWFORD_TOWN_HOUSE2
gMapLayout_DEWFORD_TOWN_HOUSE2: @ 0x083FFC68
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x083FFBAC  @ border
	.4byte 0x083FFBB4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFC80, 0xB8
	.globl gMapLayout_LAVARIDGE_TOWN_HERB_SHOP
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP: @ 0x083FFD38
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x083FFC80  @ border
	.4byte 0x083FFC88  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFD50, 0x290
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_1F
gMapLayout_LAVARIDGE_TOWN_GYM_1F: @ 0x083FFFE0
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte 0x083FFD50  @ border
	.4byte 0x083FFD58  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3FFFF8, 0x290
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_B1F
gMapLayout_LAVARIDGE_TOWN_GYM_B1F: @ 0x08400288
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte 0x083FFFF8  @ border
	.4byte 0x08400000  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4002A0, 0x104
	.globl gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F: @ 0x084003A4
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x084002A0  @ border
	.4byte 0x084002A8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4003BC, 0x490
	.globl gMapLayout_LILYCOVE_CITY_HOUSE2
gMapLayout_LILYCOVE_CITY_HOUSE2: @ 0x0840084C
	.4byte 8  @ width
	.4byte 8  @ height
	.4byte 0x084007C4  @ border
	.4byte 0x084007CC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400864, 0x13C
	.globl gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE: @ 0x084009A0
	.4byte 17  @ width
	.4byte 8  @ height
	.4byte 0x08400888  @ border
	.4byte 0x08400890  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4009B8, 0xBC
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE1
gMapLayout_PACIFIDLOG_TOWN_HOUSE1: @ 0x08400A74
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084009B8  @ border
	.4byte 0x084009C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400A8C, 0xBC
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE2
gMapLayout_PACIFIDLOG_TOWN_HOUSE2: @ 0x08400B48
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x08400A8C  @ border
	.4byte 0x08400A94  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400B60, 0x7E8
	.globl gMapLayout_PETALBURG_CITY_GYM
gMapLayout_PETALBURG_CITY_GYM: @ 0x08401348
	.4byte 9  @ width
	.4byte 112  @ height
	.4byte 0x08400B60  @ border
	.4byte 0x08400B68  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401360, 0xA8
	.globl gMapLayout_PETALBURG_CITY_HOUSE2
gMapLayout_PETALBURG_CITY_HOUSE2: @ 0x08401408
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x08401360  @ border
	.4byte 0x08401368  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401420, 0x280
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x084016A0
	.4byte 21  @ width
	.4byte 15  @ height
	.4byte 0x08401420  @ border
	.4byte 0x08401428  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4016B8, 0x208
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x084018C0
	.4byte 17  @ width
	.4byte 15  @ height
	.4byte 0x084016B8  @ border
	.4byte 0x084016C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4018D8, 0x184
	.globl gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08401A5C
	.4byte 14  @ width
	.4byte 11  @ height
	.4byte 0x08401920  @ border
	.4byte 0x08401928  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401A74, 0x170
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08401BE4
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte 0x08401A74  @ border
	.4byte 0x08401A7C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401BFC, 0x170
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08401D6C
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte 0x08401BFC  @ border
	.4byte 0x08401C04  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x401D84, 0x2D8
	.globl gMapLayout_SLATEPORT_CITY_HARBOR
gMapLayout_SLATEPORT_CITY_HARBOR: @ 0x0840205C
	.4byte 24  @ width
	.4byte 15  @ height
	.4byte 0x08401D84  @ border
	.4byte 0x08401D8C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402074, 0x1AC
	.globl gMapLayout_MAUVILLE_CITY_GYM
gMapLayout_MAUVILLE_CITY_GYM: @ 0x08402220
	.4byte 10  @ width
	.4byte 21  @ height
	.4byte 0x08402074  @ border
	.4byte 0x0840207C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402238, 0xE0
	.globl gMapLayout_MAUVILLE_CITY_BIKE_SHOP
gMapLayout_MAUVILLE_CITY_BIKE_SHOP: @ 0x08402318
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08402238  @ border
	.4byte 0x08402240  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402330, 0x1EC
	.globl gMapLayout_MAUVILLE_CITY_GAME_CORNER
gMapLayout_MAUVILLE_CITY_GAME_CORNER: @ 0x0840251C
	.4byte 22  @ width
	.4byte 11  @ height
	.4byte 0x08402330  @ border
	.4byte 0x08402338  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402534, 0x160
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08402694
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x08402534  @ border
	.4byte 0x0840253C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4026AC, 0x160
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x0840280C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x084026AC  @ border
	.4byte 0x084026B4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402824, 0x1C0
	.globl gMapLayout_RUSTBORO_CITY_GYM
gMapLayout_RUSTBORO_CITY_GYM: @ 0x084029E4
	.4byte 11  @ width
	.4byte 20  @ height
	.4byte 0x08402824  @ border
	.4byte 0x0840282C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4029FC, 0x110
	.globl gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08402B0C
	.4byte 12  @ width
	.4byte 11  @ height
	.4byte 0x084029FC  @ border
	.4byte 0x08402A04  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402B24, 0xE0
	.globl gMapLayout_RUSTBORO_CITY_HOUSE2
gMapLayout_RUSTBORO_CITY_HOUSE2: @ 0x08402C04
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08402B24  @ border
	.4byte 0x08402B2C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402C1C, 0xD8
	.globl gMapLayout_RUSTBORO_CITY_HOUSE1
gMapLayout_RUSTBORO_CITY_HOUSE1: @ 0x08402CF4
	.4byte 13  @ width
	.4byte 8  @ height
	.4byte 0x08402C1C  @ border
	.4byte 0x08402C24  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402D0C, 0xD0
	.globl gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08402DDC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte 0x08402D0C  @ border
	.4byte 0x08402D14  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402DF4, 0x68
	.globl gMapLayout_FORTREE_CITY_HOUSE1
gMapLayout_FORTREE_CITY_HOUSE1: @ 0x08402E5C
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x08402DF4  @ border
	.4byte 0x08402DFC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x402E74, 0x3F0
	.globl gMapLayout_FORTREE_CITY_GYM
gMapLayout_FORTREE_CITY_GYM: @ 0x08403264
	.4byte 20  @ width
	.4byte 25  @ height
	.4byte 0x08402E74  @ border
	.4byte 0x08402E7C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40327C, 0x68
	.globl gMapLayout_FORTREE_CITY_HOUSE2
gMapLayout_FORTREE_CITY_HOUSE2: @ 0x084032E4
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x0840327C  @ border
	.4byte 0x08403284  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4032FC, 0xE0
	.globl gMapLayout_ROUTE104_MR_BRINEYS_HOUSE
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE: @ 0x084033DC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x084032FC  @ border
	.4byte 0x08403304  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4033F4, 0x254
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08403648
	.4byte 21  @ width
	.4byte 14  @ height
	.4byte 0x084033F4  @ border
	.4byte 0x084033FC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x403660, 0x244
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x084038A4
	.4byte 22  @ width
	.4byte 13  @ height
	.4byte 0x08403660  @ border
	.4byte 0x08403668  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4038BC, 0x2F0
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08403BAC
	.4byte 31  @ width
	.4byte 12  @ height
	.4byte 0x084038BC  @ border
	.4byte 0x084038C4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x403BC4, 0xD30
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_HALL
gMapLayout_LILYCOVE_CITY_CONTEST_HALL: @ 0x084048F4
	.4byte 51  @ width
	.4byte 33  @ height
	.4byte 0x08403BC4  @ border
	.4byte 0x08403BCC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40490C, 0x158
	.globl gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x08404A64
	.4byte 12  @ width
	.4byte 14  @ height
	.4byte 0x0840490C  @ border
	.4byte 0x08404914  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x404A7C, 0x758
	.globl gMapLayout_MOSSDEEP_CITY_GYM
gMapLayout_MOSSDEEP_CITY_GYM: @ 0x084051D4
	.4byte 26  @ width
	.4byte 36  @ height
	.4byte 0x08404A7C  @ border
	.4byte 0x08404A84  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4051EC, 0x37C
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_1F
gMapLayout_SOOTOPOLIS_CITY_GYM_1F: @ 0x08405568
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte 0x084051EC  @ border
	.4byte 0x084051F4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405580, 0x37C
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_B1F
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F: @ 0x084058FC
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte 0x08405580  @ border
	.4byte 0x08405588  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405914, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x08405A88
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405914  @ border
	.4byte 0x0840591C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405AA0, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x08405C14
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405AA0  @ border
	.4byte 0x08405AA8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405C2C, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x08405DA0
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405C2C  @ border
	.4byte 0x08405C34  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405DB8, 0x174
	.globl gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x08405F2C
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte 0x08405DB8  @ border
	.4byte 0x08405DC0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x405F44, 0x15C
	.globl gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x084060A0
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x08405F44  @ border
	.4byte 0x08405F4C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4060B8, 0x128
	.globl gMapLayout_EVER_GRANDE_CITY_HALL1
gMapLayout_EVER_GRANDE_CITY_HALL1: @ 0x084061E0
	.4byte 11  @ width
	.4byte 13  @ height
	.4byte 0x084060B8  @ border
	.4byte 0x084060C0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4061F8, 0x118
	.globl gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x08406310
	.4byte 15  @ width
	.4byte 9  @ height
	.4byte 0x084061F8  @ border
	.4byte 0x08406200  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406328, 0x140
	.globl gMapLayout_ROUTE112_CABLE_CAR_STATION
gMapLayout_ROUTE112_CABLE_CAR_STATION: @ 0x08406468
	.4byte 13  @ width
	.4byte 12  @ height
	.4byte 0x08406328  @ border
	.4byte 0x08406330  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406480, 0xA8
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x08406528
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte 0x08406480  @ border
	.4byte 0x08406488  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406540, 0x2AC
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x084067EC
	.4byte 13  @ width
	.4byte 26  @ height
	.4byte 0x08406540  @ border
	.4byte 0x08406548  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406804, 0xB8
	.globl gMapLayout_ROUTE114_LANETTES_HOUSE
gMapLayout_ROUTE114_LANETTES_HOUSE: @ 0x084068BC
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x08406804  @ border
	.4byte 0x0840680C  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4068D4, 0xBC
	.globl gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x08406990
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084068D4  @ border
	.4byte 0x084068DC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4069A8, 0xE0
	.globl gMapLayout_ROUTE117_POKEMON_DAY_CARE
gMapLayout_ROUTE117_POKEMON_DAY_CARE: @ 0x08406A88
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x084069A8  @ border
	.4byte 0x084069B0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406AA0, 0x200
	.globl gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x08406CA0
	.4byte 18  @ width
	.4byte 14  @ height
	.4byte 0x08406AA0  @ border
	.4byte 0x08406AA8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x406CB8, 0x9E0
	.globl gMapLayout_METEOR_FALLS_1F_1R
gMapLayout_METEOR_FALLS_1F_1R: @ 0x08407698
	.4byte 30  @ width
	.4byte 42  @ height
	.4byte 0x08406CB8  @ border
	.4byte 0x08406CC0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4076B0, 0x788
	.globl gMapLayout_METEOR_FALLS_1F_2R
gMapLayout_METEOR_FALLS_1F_2R: @ 0x08407E38
	.4byte 30  @ width
	.4byte 32  @ height
	.4byte 0x084076B0  @ border
	.4byte 0x084076B8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x407E50, 0x8A4
	.globl gMapLayout_METEOR_FALLS_B1F_1R
gMapLayout_METEOR_FALLS_B1F_1R: @ 0x084086F4
	.4byte 29  @ width
	.4byte 38  @ height
	.4byte 0x08407E50  @ border
	.4byte 0x08407E58  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40870C, 0x194
	.globl gMapLayout_METEOR_FALLS_B1F_2R
gMapLayout_METEOR_FALLS_B1F_2R: @ 0x084088A0
	.4byte 11  @ width
	.4byte 18  @ height
	.4byte 0x0840870C  @ border
	.4byte 0x08408714  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4088B8, 0x6C8
	.globl gMapLayout_RUSTURF_TUNNEL
gMapLayout_RUSTURF_TUNNEL: @ 0x08408F80
	.4byte 36  @ width
	.4byte 24  @ height
	.4byte 0x084088B8  @ border
	.4byte 0x084088C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x408F98, 0x198
	.globl gMapLayout_UNDERWATER_SOOTOPOLIS_CITY
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY: @ 0x08409130
	.4byte 20  @ width
	.4byte 10  @ height
	.4byte 0x08408F98  @ border
	.4byte 0x08408FA0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x409148, 0x46C
	.globl gMapLayout_DESERT_RUINS
gMapLayout_DESERT_RUINS: @ 0x084095B4
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte 0x08409148  @ border
	.4byte 0x08409150  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4095CC, 0x4F4
	.globl gMapLayout_GRANITE_CAVE_1F
gMapLayout_GRANITE_CAVE_1F: @ 0x08409AC0
	.4byte 42  @ width
	.4byte 15  @ height
	.4byte 0x084095CC  @ border
	.4byte 0x084095D4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x409AD8, 0x688
	.globl gMapLayout_GRANITE_CAVE_B1F
gMapLayout_GRANITE_CAVE_B1F: @ 0x0840A160
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte 0x08409AD8  @ border
	.4byte 0x08409AE0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40A178, 0x688
	.globl gMapLayout_GRANITE_CAVE_B2F
gMapLayout_GRANITE_CAVE_B2F: @ 0x0840A800
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte 0x0840A178  @ border
	.4byte 0x0840A180  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40A818, 0x1088
	.globl gMapLayout_PETALBURG_WOODS
gMapLayout_PETALBURG_WOODS: @ 0x0840B8A0
	.4byte 48  @ width
	.4byte 44  @ height
	.4byte 0x0840A818  @ border
	.4byte 0x0840A820  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40B8B8, 0xEB8
	.globl gMapLayout_MT_CHIMNEY
gMapLayout_MT_CHIMNEY: @ 0x0840C770
	.4byte 40  @ width
	.4byte 47  @ height
	.4byte 0x0840B8B8  @ border
	.4byte 0x0840B8C0  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40C788, 0x34C
	.globl gMapLayout_MT_PYRE_1F
gMapLayout_MT_PYRE_1F: @ 0x0840CAD4
	.4byte 22  @ width
	.4byte 19  @ height
	.4byte 0x0840C788  @ border
	.4byte 0x0840C790  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CAEC, 0x15C
	.globl gMapLayout_MT_PYRE_2F
gMapLayout_MT_PYRE_2F: @ 0x0840CC48
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CAEC  @ border
	.4byte 0x0840CAF4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CC60, 0x15C
	.globl gMapLayout_MT_PYRE_3F
gMapLayout_MT_PYRE_3F: @ 0x0840CDBC
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CC60  @ border
	.4byte 0x0840CC68  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CDD4, 0x15C
	.globl gMapLayout_MT_PYRE_4F
gMapLayout_MT_PYRE_4F: @ 0x0840CF30
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CDD4  @ border
	.4byte 0x0840CDDC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40CF48, 0x15C
	.globl gMapLayout_MT_PYRE_5F
gMapLayout_MT_PYRE_5F: @ 0x0840D0A4
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840CF48  @ border
	.4byte 0x0840CF50  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D0BC, 0x15C
	.globl gMapLayout_MT_PYRE_6F
gMapLayout_MT_PYRE_6F: @ 0x0840D218
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte 0x0840D0BC  @ border
	.4byte 0x0840D0C4  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D230, 0x698
	.globl gMapLayout_AQUA_HIDEOUT_1F
gMapLayout_AQUA_HIDEOUT_1F: @ 0x0840D8C8
	.4byte 28  @ width
	.4byte 30  @ height
	.4byte 0x0840D230  @ border
	.4byte 0x0840D238  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40D8E0, 0x998
	.globl gMapLayout_AQUA_HIDEOUT_B1F
gMapLayout_AQUA_HIDEOUT_B1F: @ 0x0840E278
	.4byte 51  @ width
	.4byte 24  @ height
	.4byte 0x0840D8E0  @ border
	.4byte 0x0840D8E8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40E290, 0x668
	.globl gMapLayout_AQUA_HIDEOUT_B2F
gMapLayout_AQUA_HIDEOUT_B2F: @ 0x0840E8F8
	.4byte 34  @ width
	.4byte 24  @ height
	.4byte 0x0840E290  @ border
	.4byte 0x0840E298  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40E910, 0x104
	.globl gMapLayout_UNDERWATER_SEAFLOOR_CAVERN
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0840EA14
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0840E910  @ border
	.4byte 0x0840E918  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40EA2C, 0x328
	.globl gMapLayout_SEAFLOOR_CAVERN_ENTRANCE
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0840ED54
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte 0x0840EA2C  @ border
	.4byte 0x0840EA34  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40ED6C, 0x350
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM1
gMapLayout_SEAFLOOR_CAVERN_ROOM1: @ 0x0840F0BC
	.4byte 20  @ width
	.4byte 21  @ height
	.4byte 0x0840ED6C  @ border
	.4byte 0x0840ED74  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F0D4, 0x1B8
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM2
gMapLayout_SEAFLOOR_CAVERN_ROOM2: @ 0x0840F28C
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte 0x0840F0D4  @ border
	.4byte 0x0840F0DC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F2A4, 0x228
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM3
gMapLayout_SEAFLOOR_CAVERN_ROOM3: @ 0x0840F4CC
	.4byte 16  @ width
	.4byte 17  @ height
	.4byte 0x0840F2A4  @ border
	.4byte 0x0840F2AC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F4E4, 0x2B4
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM4
gMapLayout_SEAFLOOR_CAVERN_ROOM4: @ 0x0840F798
	.4byte 18  @ width
	.4byte 19  @ height
	.4byte 0x0840F4E4  @ border
	.4byte 0x0840F4EC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40F7B0, 0x118B4
	.globl gMapLayout_FORTREE_CITY_DECORATION_SHOP
gMapLayout_FORTREE_CITY_DECORATION_SHOP: @ 0x08421064
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte 0x08420FFC  @ border
	.4byte 0x08421004  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42107C, 0x1FC
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x08421278
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421150  @ border
	.4byte 0x08421158  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421290, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x084213B8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421290  @ border
	.4byte 0x08421298  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4213D0, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x084214F8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x084213D0  @ border
	.4byte 0x084213D8  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421510, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x08421638
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421510  @ border
	.4byte 0x08421518  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421650, 0x128
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x08421778
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte 0x08421650  @ border
	.4byte 0x08421658  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421790, 0x1B8
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x08421948
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte 0x08421790  @ border
	.4byte 0x08421798  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x421960, 0x1908
	.globl gMapLayout_ROUTE130
gMapLayout_ROUTE130: @ 0x08423268
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08421960  @ border
	.4byte 0x08421968  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x423280, 0x251C
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x0842579C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte 0x0842563C  @ border
	.4byte 0x08425644  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4257B4, 0x1D0
	.globl gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x08425984
	.4byte 19  @ width
	.4byte 12  @ height
	.4byte 0x084257B4  @ border
	.4byte 0x084257BC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42599C, 0x444
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x08425DE0
	.4byte 5  @ width
	.4byte 6  @ height
	.4byte 0x08425D9C  @ border
	.4byte 0x08425DA4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x425DF8, 0x3208
	.globl gMapLayout_UNDERWATER_ROUTE124
gMapLayout_UNDERWATER_ROUTE124: @ 0x08429000
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte 0x08425DF8  @ border
	.4byte 0x08425E00  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x429018, 0x148
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x08429160
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte 0x08429018  @ border
	.4byte 0x08429020  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x429178, 0x148
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x084292C0
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte 0x08429178  @ border
	.4byte 0x08429180  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4292D8, 0x3830
	.globl gMapLayout_GRANITE_CAVE_STEVENS_ROOM
gMapLayout_GRANITE_CAVE_STEVENS_ROOM: @ 0x0842CB08
	.4byte 15  @ width
	.4byte 14  @ height
	.4byte 0x0842C95C  @ border
	.4byte 0x0842C964  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42CB20, 0x191C
	.globl gMapLayout_JAGGED_PASS
gMapLayout_JAGGED_PASS: @ 0x0842E43C
	.4byte 30  @ width
	.4byte 46  @ height
	.4byte 0x0842D96C  @ border
	.4byte 0x0842D974  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42E454, 0xA6C
	.globl gMapLayout_FIERY_PATH
gMapLayout_FIERY_PATH: @ 0x0842EEC0
	.4byte 35  @ width
	.4byte 38  @ height
	.4byte 0x0842E454  @ border
	.4byte 0x0842E45C  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42EED8, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_1F
gMapLayout_RUSTBORO_CITY_FLAT2_1F: @ 0x0842EFDC
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842EED8  @ border
	.4byte 0x0842EEE0  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42EFF4, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_2F
gMapLayout_RUSTBORO_CITY_FLAT2_2F: @ 0x0842F0F8
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842EFF4  @ border
	.4byte 0x0842EFFC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F110, 0x104
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_3F
gMapLayout_RUSTBORO_CITY_FLAT2_3F: @ 0x0842F214
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte 0x0842F110  @ border
	.4byte 0x0842F118  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F22C, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0842F2A4
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x0842F22C  @ border
	.4byte 0x0842F234  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F2BC, 0x208
	.globl gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0842F4C4
	.4byte 15  @ width
	.4byte 17  @ height
	.4byte 0x0842F2BC  @ border
	.4byte 0x0842F2C4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F4DC, 0xE0
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x0842F5BC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0842F4DC  @ border
	.4byte 0x0842F4E4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F5D4, 0xE0
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x0842F6B4
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0842F5D4  @ border
	.4byte 0x0842F5DC  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42F6CC, 0x1000
	.globl gMapLayout_MT_PYRE_EXTERIOR
gMapLayout_MT_PYRE_EXTERIOR: @ 0x084306CC
	.4byte 38  @ width
	.4byte 51  @ height
	.4byte 0x0842F7A0  @ border
	.4byte 0x0842F7A8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4306E4, 0xE7C
	.globl gMapLayout_MT_PYRE_SUMMIT
gMapLayout_MT_PYRE_SUMMIT: @ 0x08431560
	.4byte 50  @ width
	.4byte 37  @ height
	.4byte 0x084306E4  @ border
	.4byte 0x084306EC  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431578, 0x4E0
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x08431A58
	.4byte 12  @ width
	.4byte 10  @ height
	.4byte 0x08431960  @ border
	.4byte 0x08431968  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431A70, 0xE0
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x08431B50
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x08431A70  @ border
	.4byte 0x08431A78  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431B68, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE1
gMapLayout_SOOTOPOLIS_CITY_HOUSE1: @ 0x08431BE0
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431B68  @ border
	.4byte 0x08431B70  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431BF8, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE2
gMapLayout_SOOTOPOLIS_CITY_HOUSE2: @ 0x08431C70
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431BF8  @ border
	.4byte 0x08431C00  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431C88, 0x78
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE3
gMapLayout_SOOTOPOLIS_CITY_HOUSE3: @ 0x08431D00
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte 0x08431C88  @ border
	.4byte 0x08431C90  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431D18, 0xB9C
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_1F
gMapLayout_RUSTBORO_CITY_FLAT1_1F: @ 0x084328B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte 0x084327CC  @ border
	.4byte 0x084327D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4328CC, 0xE8
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_2F
gMapLayout_RUSTBORO_CITY_FLAT1_2F: @ 0x084329B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte 0x084328CC  @ border
	.4byte 0x084328D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4329CC, 0x2F4
	.globl gMapLayout_EVER_GRANDE_CITY_HALL4
gMapLayout_EVER_GRANDE_CITY_HALL4: @ 0x08432CC0
	.4byte 11  @ width
	.4byte 34  @ height
	.4byte 0x084329CC  @ border
	.4byte 0x084329D4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x432CD8, 0x44CC
	.globl gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x084371A4
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x084370EC  @ border
	.4byte 0x084370F4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4371BC, 0xD268
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08444424
	.4byte 13  @ width
	.4byte 10  @ height
	.4byte 0x08444318  @ border
	.4byte 0x08444320  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44443C, 0x58
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08444494
	.4byte 5  @ width
	.4byte 8  @ height
	.4byte 0x0844443C  @ border
	.4byte 0x08444444  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4444AC, 0xBC
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444568
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte 0x084444AC  @ border
	.4byte 0x084444B4  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x444580, 0xF4
	.globl gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444674
	.4byte 13  @ width
	.4byte 9  @ height
	.4byte 0x08444580  @ border
	.4byte 0x08444588  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44468C, 0xC86C
	.globl gMapLayout_UNDERWATER_ROUTE105
gMapLayout_UNDERWATER_ROUTE105: @ 0x08450EF8
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte 0x0844F5F0  @ border
	.4byte 0x0844F5F8  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x450F10, 0x1908
	.globl gMapLayout_UNDERWATER_ROUTE125
gMapLayout_UNDERWATER_ROUTE125: @ 0x08452818
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08450F10  @ border
	.4byte 0x08450F18  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x452830, 0x1908
	.globl gMapLayout_UNDERWATER_ROUTE129
gMapLayout_UNDERWATER_ROUTE129: @ 0x08454138
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte 0x08452830  @ border
	.4byte 0x08452838  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x454150, 0x5EC4
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0845A014
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte 0x08459F5C  @ border
	.4byte 0x08459F64  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x45A02C, 0xE0
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0845A10C
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte 0x0845A02C  @ border
	.4byte 0x0845A034  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x45A124, 0xD0

	.globl gUnknown_845A1F4
gUnknown_845A1F4: @ 0x845A1F4
	.incbin "baserom_jp.gba", 0x45a1f4, 0x6e4
	.globl gMapHeaders
gMapHeaders: @ 0x0845A8D8
	@ struct MapHeader { mapLayout, events, mapScripts, connections, music, mapLayoutId, regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType }
	@ MAP_PETALBURG_CITY (g0 m0)
	.4byte gMapLayout_PETALBURG_CITY  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY  @ events
	.4byte PetalburgCity_MapScripts  @ mapScripts
	.4byte gMapConnections_PETALBURG_CITY  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0001  @ mapLayoutId
	.byte 0x07, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY (g0 m1)
	.4byte gMapLayout_SLATEPORT_CITY  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY  @ events
	.4byte SlateportCity_MapScripts  @ mapScripts
	.4byte gMapConnections_SLATEPORT_CITY  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0002  @ mapLayoutId
	.byte 0x08, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY (g0 m2)
	.4byte gMapLayout_MAUVILLE_CITY  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY  @ events
	.4byte MauvilleCity_MapScripts  @ mapScripts
	.4byte gMapConnections_MAUVILLE_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0003  @ mapLayoutId
	.byte 0x09, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY (g0 m3)
	.4byte gMapLayout_RUSTBORO_CITY  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY  @ events
	.4byte RustboroCity_MapScripts  @ mapScripts
	.4byte gMapConnections_RUSTBORO_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0004  @ mapLayoutId
	.byte 0x0A, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY (g0 m4)
	.4byte gMapLayout_FORTREE_CITY  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY  @ events
	.4byte FortreeCity_MapScripts  @ mapScripts
	.4byte gMapConnections_FORTREE_CITY  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0005  @ mapLayoutId
	.byte 0x0B, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY (g0 m5)
	.4byte gMapLayout_LILYCOVE_CITY  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY  @ events
	.4byte LilycoveCity_MapScripts  @ mapScripts
	.4byte gMapConnections_LILYCOVE_CITY  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0006  @ mapLayoutId
	.byte 0x0C, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY (g0 m6)
	.4byte gMapLayout_MOSSDEEP_CITY  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY  @ events
	.4byte MossdeepCity_MapScripts  @ mapScripts
	.4byte gMapConnections_MOSSDEEP_CITY  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0007  @ mapLayoutId
	.byte 0x0D, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY (g0 m7)
	.4byte gMapLayout_SOOTOPOLIS_CITY  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY  @ events
	.4byte SootopolisCity_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0008  @ mapLayoutId
	.byte 0x0E, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY (g0 m8)
	.4byte gMapLayout_EVER_GRANDE_CITY  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY  @ events
	.4byte EverGrandeCity_MapScripts  @ mapScripts
	.4byte gMapConnections_EVER_GRANDE_CITY  @ connections
	.2byte 0x01A6  @ music
	.2byte 0x0009  @ mapLayoutId
	.byte 0x0F, 0x00, 0x02, 0x02, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN (g0 m9)
	.4byte gMapLayout_LITTLEROOT_TOWN  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN  @ events
	.4byte LittlerootTown_MapScripts  @ mapScripts
	.4byte gMapConnections_LITTLEROOT_TOWN  @ connections
	.2byte 0x0195  @ music
	.2byte 0x000A  @ mapLayoutId
	.byte 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN (g0 m10)
	.4byte gMapLayout_OLDALE_TOWN  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN  @ events
	.4byte OldaleTown_MapScripts  @ mapScripts
	.4byte gMapConnections_OLDALE_TOWN  @ connections
	.2byte 0x016B  @ music
	.2byte 0x000B  @ mapLayoutId
	.byte 0x01, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN (g0 m11)
	.4byte gMapLayout_DEWFORD_TOWN  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN  @ events
	.4byte DewfordTown_MapScripts  @ mapScripts
	.4byte gMapConnections_DEWFORD_TOWN  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x000C  @ mapLayoutId
	.byte 0x02, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN (g0 m12)
	.4byte gMapLayout_LAVARIDGE_TOWN  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN  @ events
	.4byte LavaridgeTown_MapScripts  @ mapScripts
	.4byte gMapConnections_LAVARIDGE_TOWN  @ connections
	.2byte 0x016B  @ music
	.2byte 0x000D  @ mapLayoutId
	.byte 0x03, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN (g0 m13)
	.4byte gMapLayout_FALLARBOR_TOWN  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN  @ events
	.4byte FallarborTown_MapScripts  @ mapScripts
	.4byte gMapConnections_FALLARBOR_TOWN  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x000E  @ mapLayoutId
	.byte 0x04, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN (g0 m14)
	.4byte gMapLayout_VERDANTURF_TOWN  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN  @ events
	.4byte VerdanturfTown_MapScripts  @ mapScripts
	.4byte gMapConnections_VERDANTURF_TOWN  @ connections
	.2byte 0x018E  @ music
	.2byte 0x000F  @ mapLayoutId
	.byte 0x05, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN (g0 m15)
	.4byte gMapLayout_PACIFIDLOG_TOWN  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN  @ events
	.4byte PacifidlogTown_MapScripts  @ mapScripts
	.4byte gMapConnections_PACIFIDLOG_TOWN  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0010  @ mapLayoutId
	.byte 0x06, 0x00, 0x02, 0x01, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE101 (g0 m16)
	.4byte gMapLayout_ROUTE101  @ mapLayout
	.4byte gMapEvents_ROUTE101  @ events
	.4byte Route101_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE101  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0011  @ mapLayoutId
	.byte 0x10, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE102 (g0 m17)
	.4byte gMapLayout_ROUTE102  @ mapLayout
	.4byte gMapEvents_ROUTE102  @ events
	.4byte 0x081E6824  @ mapScripts
	.4byte gMapConnections_ROUTE102  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0012  @ mapLayoutId
	.byte 0x11, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE103 (g0 m18)
	.4byte gMapLayout_ROUTE103  @ mapLayout
	.4byte gMapEvents_ROUTE103  @ events
	.4byte Route103_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE103  @ connections
	.2byte 0x0167  @ music
	.2byte 0x0013  @ mapLayoutId
	.byte 0x12, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104 (g0 m19)
	.4byte gMapLayout_ROUTE104  @ mapLayout
	.4byte gMapEvents_ROUTE104  @ events
	.4byte Route104_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE104  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0014  @ mapLayoutId
	.byte 0x13, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE105 (g0 m20)
	.4byte gMapLayout_ROUTE105  @ mapLayout
	.4byte gMapEvents_ROUTE105  @ events
	.4byte Route105_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE105  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0015  @ mapLayoutId
	.byte 0x14, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE106 (g0 m21)
	.4byte gMapLayout_ROUTE106  @ mapLayout
	.4byte gMapEvents_ROUTE106  @ events
	.4byte 0x081E83CA  @ mapScripts
	.4byte gMapConnections_ROUTE106  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0016  @ mapLayoutId
	.byte 0x15, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE107 (g0 m22)
	.4byte gMapLayout_ROUTE107  @ mapLayout
	.4byte gMapEvents_ROUTE107  @ events
	.4byte 0x081E84AB  @ mapScripts
	.4byte gMapConnections_ROUTE107  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0017  @ mapLayoutId
	.byte 0x16, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE108 (g0 m23)
	.4byte gMapLayout_ROUTE108  @ mapLayout
	.4byte gMapEvents_ROUTE108  @ events
	.4byte 0x081E85A0  @ mapScripts
	.4byte gMapConnections_ROUTE108  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0018  @ mapLayoutId
	.byte 0x17, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE109 (g0 m24)
	.4byte gMapLayout_ROUTE109  @ mapLayout
	.4byte gMapEvents_ROUTE109  @ events
	.4byte 0x081E8676  @ mapScripts
	.4byte gMapConnections_ROUTE109  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0019  @ mapLayoutId
	.byte 0x18, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE110 (g0 m25)
	.4byte gMapLayout_ROUTE110  @ mapLayout
	.4byte gMapEvents_ROUTE110  @ events
	.4byte Route110_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE110  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001A  @ mapLayoutId
	.byte 0x19, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111 (g0 m26)
	.4byte gMapLayout_ROUTE111  @ mapLayout
	.4byte gMapEvents_ROUTE111  @ events
	.4byte Route111_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE111  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001B  @ mapLayoutId
	.byte 0x1A, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE112 (g0 m27)
	.4byte gMapLayout_ROUTE112  @ mapLayout
	.4byte gMapEvents_ROUTE112  @ events
	.4byte Route112_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE112  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001C  @ mapLayoutId
	.byte 0x1B, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE113 (g0 m28)
	.4byte gMapLayout_ROUTE113  @ mapLayout
	.4byte gMapEvents_ROUTE113  @ events
	.4byte Route113_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE113  @ connections
	.2byte 0x01A2  @ music
	.2byte 0x001D  @ mapLayoutId
	.byte 0x1C, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114 (g0 m29)
	.4byte gMapLayout_ROUTE114  @ mapLayout
	.4byte gMapEvents_ROUTE114  @ events
	.4byte Route114_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE114  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001E  @ mapLayoutId
	.byte 0x1D, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE115 (g0 m30)
	.4byte gMapLayout_ROUTE115  @ mapLayout
	.4byte gMapEvents_ROUTE115  @ events
	.4byte Route115_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE115  @ connections
	.2byte 0x0191  @ music
	.2byte 0x001F  @ mapLayoutId
	.byte 0x1E, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE116 (g0 m31)
	.4byte gMapLayout_ROUTE116  @ mapLayout
	.4byte gMapEvents_ROUTE116  @ events
	.4byte Route116_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE116  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0020  @ mapLayoutId
	.byte 0x1F, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE117 (g0 m32)
	.4byte gMapLayout_ROUTE117  @ mapLayout
	.4byte gMapEvents_ROUTE117  @ events
	.4byte Route117_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE117  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0021  @ mapLayoutId
	.byte 0x20, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE118 (g0 m33)
	.4byte gMapLayout_ROUTE118  @ mapLayout
	.4byte gMapEvents_ROUTE118  @ events
	.4byte Route118_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE118  @ connections
	.2byte 0x7FFF  @ music
	.2byte 0x0022  @ mapLayoutId
	.byte 0x21, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE119 (g0 m34)
	.4byte gMapLayout_ROUTE119  @ mapLayout
	.4byte gMapEvents_ROUTE119  @ events
	.4byte Route119_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE119  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0023  @ mapLayoutId
	.byte 0x22, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE120 (g0 m35)
	.4byte gMapLayout_ROUTE120  @ mapLayout
	.4byte gMapEvents_ROUTE120  @ events
	.4byte Route120_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE120  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0024  @ mapLayoutId
	.byte 0x23, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE121 (g0 m36)
	.4byte gMapLayout_ROUTE121  @ mapLayout
	.4byte gMapEvents_ROUTE121  @ events
	.4byte 0x081EE0D9  @ mapScripts
	.4byte gMapConnections_ROUTE121  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0025  @ mapLayoutId
	.byte 0x24, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE122 (g0 m37)
	.4byte gMapLayout_ROUTE122  @ mapLayout
	.4byte gMapEvents_ROUTE122  @ events
	.4byte 0x081EE3D5  @ mapScripts
	.4byte gMapConnections_ROUTE122  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0026  @ mapLayoutId
	.byte 0x25, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE123 (g0 m38)
	.4byte gMapLayout_ROUTE123  @ mapLayout
	.4byte gMapEvents_ROUTE123  @ events
	.4byte Route123_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE123  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0027  @ mapLayoutId
	.byte 0x26, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE124 (g0 m39)
	.4byte gMapLayout_ROUTE124  @ mapLayout
	.4byte gMapEvents_ROUTE124  @ events
	.4byte Route124_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE124  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0028  @ mapLayoutId
	.byte 0x27, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE125 (g0 m40)
	.4byte gMapLayout_ROUTE125  @ mapLayout
	.4byte gMapEvents_ROUTE125  @ events
	.4byte Route125_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE125  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0029  @ mapLayoutId
	.byte 0x28, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE126 (g0 m41)
	.4byte gMapLayout_ROUTE126  @ mapLayout
	.4byte gMapEvents_ROUTE126  @ events
	.4byte Route126_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE126  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002A  @ mapLayoutId
	.byte 0x29, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE127 (g0 m42)
	.4byte gMapLayout_ROUTE127  @ mapLayout
	.4byte gMapEvents_ROUTE127  @ events
	.4byte Route127_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE127  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002B  @ mapLayoutId
	.byte 0x2A, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE128 (g0 m43)
	.4byte gMapLayout_ROUTE128  @ mapLayout
	.4byte gMapEvents_ROUTE128  @ events
	.4byte Route128_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE128  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002C  @ mapLayoutId
	.byte 0x2B, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE129 (g0 m44)
	.4byte gMapLayout_ROUTE129  @ mapLayout
	.4byte gMapEvents_ROUTE129  @ events
	.4byte Route129_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE129  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002D  @ mapLayoutId
	.byte 0x2C, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE130 (g0 m45)
	.4byte gMapLayout_ROUTE130  @ mapLayout
	.4byte gMapEvents_ROUTE130  @ events
	.4byte Route130_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE130  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0107  @ mapLayoutId
	.byte 0x2D, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE131 (g0 m46)
	.4byte gMapLayout_ROUTE131  @ mapLayout
	.4byte gMapEvents_ROUTE131  @ events
	.4byte Route131_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE131  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002F  @ mapLayoutId
	.byte 0x2E, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE132 (g0 m47)
	.4byte gMapLayout_ROUTE132  @ mapLayout
	.4byte gMapEvents_ROUTE132  @ events
	.4byte 0x081EF519  @ mapScripts
	.4byte gMapConnections_ROUTE132  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0030  @ mapLayoutId
	.byte 0x2F, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE133 (g0 m48)
	.4byte gMapLayout_ROUTE133  @ mapLayout
	.4byte gMapEvents_ROUTE133  @ events
	.4byte 0x081EF5D2  @ mapScripts
	.4byte gMapConnections_ROUTE133  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0031  @ mapLayoutId
	.byte 0x30, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE134 (g0 m49)
	.4byte gMapLayout_ROUTE134  @ mapLayout
	.4byte gMapEvents_ROUTE134  @ events
	.4byte Route134_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE134  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0032  @ mapLayoutId
	.byte 0x31, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE124 (g0 m50)
	.4byte gMapLayout_UNDERWATER_ROUTE124  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE124  @ events
	.4byte 0x081EF752  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE124  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0112  @ mapLayoutId
	.byte 0x32, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE126 (g0 m51)
	.4byte gMapLayout_UNDERWATER_ROUTE126  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE126  @ events
	.4byte 0x081EF753  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE126  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0033  @ mapLayoutId
	.byte 0x33, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE127 (g0 m52)
	.4byte gMapLayout_UNDERWATER_ROUTE127  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE127  @ events
	.4byte Underwater_Route127_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE127  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0034  @ mapLayoutId
	.byte 0x34, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE128 (g0 m53)
	.4byte gMapLayout_UNDERWATER_ROUTE128  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE128  @ events
	.4byte 0x081EF760  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE128  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0035  @ mapLayoutId
	.byte 0x35, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE129 (g0 m54)
	.4byte gMapLayout_UNDERWATER_ROUTE129  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE129  @ events
	.4byte Underwater_Route129_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE129  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019C  @ mapLayoutId
	.byte 0xD0, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE105 (g0 m55)
	.4byte gMapLayout_UNDERWATER_ROUTE105  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE105  @ events
	.4byte Underwater_Route105_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE105  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019A  @ mapLayoutId
	.byte 0xCE, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE125 (g0 m56)
	.4byte gMapLayout_UNDERWATER_ROUTE125  @ mapLayout
	.4byte gMapEvents_UNDERWATER_ROUTE125  @ events
	.4byte Underwater_Route125_MapScripts  @ mapScripts
	.4byte gMapConnections_UNDERWATER_ROUTE125  @ connections
	.2byte 0x019B  @ music
	.2byte 0x019B  @ mapLayoutId
	.byte 0xCF, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F (g1 m0)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F  @ events
	.4byte LittlerootTown_BrendansHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0036  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F (g1 m1)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F  @ events
	.4byte LittlerootTown_BrendansHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0037  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F (g1 m2)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_1F  @ events
	.4byte LittlerootTown_MaysHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0038  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F (g1 m3)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_MAYS_HOUSE_2F  @ events
	.4byte LittlerootTown_MaysHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0039  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB (g1 m4)
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB  @ mapLayout
	.4byte gMapEvents_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB  @ events
	.4byte LittlerootTown_ProfessorBirchsLab_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017F  @ music
	.2byte 0x003A  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE1 (g2 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_HOUSE1  @ events
	.4byte 0x081F28D3  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE2 (g2 m1)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_HOUSE2  @ events
	.4byte 0x081F2949  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_1F (g2 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_POKEMON_CENTER_1F  @ events
	.4byte OldaleTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_2F (g2 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_POKEMON_CENTER_2F  @ events
	.4byte OldaleTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_MART (g2 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_OLDALE_TOWN_MART  @ events
	.4byte 0x081F2B0B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HOUSE1 (g3 m0)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HOUSE1  @ events
	.4byte 0x081F2C10  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_1F (g3 m1)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_1F  @ events
	.4byte DewfordTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_2F (g3 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_POKEMON_CENTER_2F  @ events
	.4byte DewfordTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_GYM (g3 m3)
	.4byte gMapLayout_DEWFORD_TOWN_GYM  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_GYM  @ events
	.4byte DewfordTown_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0041  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HALL (g3 m4)
	.4byte gMapLayout_DEWFORD_TOWN_HALL  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HALL  @ events
	.4byte 0x081F3788  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0042  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HOUSE2 (g3 m5)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_DEWFORD_TOWN_HOUSE2  @ events
	.4byte 0x081F4008  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0043  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_HERB_SHOP (g4 m0)
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_HERB_SHOP  @ events
	.4byte 0x081F4185  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x0044  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_GYM_1F (g4 m1)
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_GYM_1F  @ events
	.4byte LavaridgeTown_Gym_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0045  @ mapLayoutId
	.byte 0x03, 0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_GYM_B1F (g4 m2)
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_GYM_B1F  @ events
	.4byte LavaridgeTown_Gym_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0046  @ mapLayoutId
	.byte 0x03, 0x00, 0x06, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_HOUSE (g4 m3)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_HOUSE  @ events
	.4byte 0x081F4E4D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_MART (g4 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_MART  @ events
	.4byte 0x081F4ECC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F (g4 m5)
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_1F  @ events
	.4byte LavaridgeTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x0047  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LAVARIDGE_TOWN_POKEMON_CENTER_2F (g4 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_LAVARIDGE_TOWN_POKEMON_CENTER_2F  @ events
	.4byte LavaridgeTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x03, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_MART (g5 m0)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_MART  @ events
	.4byte 0x081F5098  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_LOBBY (g5 m1)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ events
	.4byte FallarborTown_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR (g5 m2)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ events
	.4byte FallarborTown_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM (g5 m3)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte FallarborTown_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0182  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F (g5 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_1F  @ events
	.4byte FallarborTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_POKEMON_CENTER_2F (g5 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_POKEMON_CENTER_2F  @ events
	.4byte FallarborTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_COZMOS_HOUSE (g5 m6)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_COZMOS_HOUSE  @ events
	.4byte 0x081F5E78  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE (g5 m7)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_FALLARBOR_TOWN_MOVE_RELEARNERS_HOUSE  @ events
	.4byte 0x081F6155  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_LOBBY (g6 m0)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_LOBBY  @ events
	.4byte VerdanturfTown_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR (g6 m1)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR  @ events
	.4byte VerdanturfTown_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM (g6 m2)
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte VerdanturfTown_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0183  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_MART (g6 m3)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_MART  @ events
	.4byte 0x081F6F27  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F (g6 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_1F  @ events
	.4byte VerdanturfTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_POKEMON_CENTER_2F (g6 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_POKEMON_CENTER_2F  @ events
	.4byte VerdanturfTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_WANDAS_HOUSE (g6 m6)
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_WANDAS_HOUSE  @ events
	.4byte 0x081F7105  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x004C  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE (g6 m7)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_FRIENDSHIP_RATERS_HOUSE  @ events
	.4byte 0x081F7556  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_VERDANTURF_TOWN_HOUSE (g6 m8)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_VERDANTURF_TOWN_HOUSE  @ events
	.4byte 0x081F777F  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018E  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x05, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F (g7 m0)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_1F  @ events
	.4byte PacifidlogTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_2F (g7 m1)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_POKEMON_CENTER_2F  @ events
	.4byte PacifidlogTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE1 (g7 m2)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE1  @ events
	.4byte 0x081F793E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE2 (g7 m3)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE2  @ events
	.4byte 0x081F79FF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE3 (g7 m4)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE3  @ events
	.4byte 0x081F7D1A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE4 (g7 m5)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE4  @ events
	.4byte 0x081F7F3D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004E  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PACIFIDLOG_TOWN_HOUSE5 (g7 m6)
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PACIFIDLOG_TOWN_HOUSE5  @ events
	.4byte 0x081F8055  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004D  @ mapLayoutId
	.byte 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_WALLYS_HOUSE (g8 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_WALLYS_HOUSE  @ events
	.4byte PetalburgCity_WallysHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_GYM (g8 m1)
	.4byte gMapLayout_PETALBURG_CITY_GYM  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_GYM  @ events
	.4byte PetalburgCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x004F  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_HOUSE1 (g8 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_HOUSE1  @ events
	.4byte 0x081FA63D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_HOUSE2 (g8 m3)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_HOUSE2  @ events
	.4byte 0x081FA720  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_1F (g8 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_POKEMON_CENTER_1F  @ events
	.4byte PetalburgCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_POKEMON_CENTER_2F (g8 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_POKEMON_CENTER_2F  @ events
	.4byte PetalburgCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_CITY_MART (g8 m6)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_PETALBURG_CITY_MART  @ events
	.4byte 0x081FA9E9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F (g9 m0)
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_1F  @ events
	.4byte 0x081FAB28  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0051  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F (g9 m1)
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_STERNS_SHIPYARD_2F  @ events
	.4byte 0x081FAFA2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0052  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY (g9 m2)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_LOBBY  @ events
	.4byte SlateportCity_BattleTentLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0180  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR (g9 m3)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR  @ events
	.4byte SlateportCity_BattleTentCorridor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0181  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM (g9 m4)
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM  @ events
	.4byte SlateportCity_BattleTentBattleRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0180  @ music
	.2byte 0x0182  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_NAME_RATERS_HOUSE (g9 m5)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_NAME_RATERS_HOUSE  @ events
	.4byte 0x081FBD9D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_FAN_CLUB (g9 m6)
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_FAN_CLUB  @ events
	.4byte 0x081FC027  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0055  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F (g9 m7)
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_1F  @ events
	.4byte 0x081FCA3E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0177  @ music
	.2byte 0x0056  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F (g9 m8)
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_OCEANIC_MUSEUM_2F  @ events
	.4byte 0x081FD309  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0177  @ music
	.2byte 0x0057  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_HARBOR (g9 m9)
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_HARBOR  @ events
	.4byte SlateportCity_Harbor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x0058  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_HOUSE (g9 m10)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_HOUSE  @ events
	.4byte 0x081FE772  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B1  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_1F (g9 m11)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_1F  @ events
	.4byte SlateportCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_POKEMON_CENTER_2F (g9 m12)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_POKEMON_CENTER_2F  @ events
	.4byte SlateportCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SLATEPORT_CITY_MART (g9 m13)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_SLATEPORT_CITY_MART  @ events
	.4byte 0x081FE8F9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_GYM (g10 m0)
	.4byte gMapLayout_MAUVILLE_CITY_GYM  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_GYM  @ events
	.4byte MauvilleCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0059  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_BIKE_SHOP (g10 m1)
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_BIKE_SHOP  @ events
	.4byte 0x081FF3EB  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005A  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE1 (g10 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE1  @ events
	.4byte 0x081FFD77  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_GAME_CORNER (g10 m3)
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_GAME_CORNER  @ events
	.4byte 0x081FFEE7  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AA  @ music
	.2byte 0x005B  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE2 (g10 m4)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE2  @ events
	.4byte 0x08200C5A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_1F (g10 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_1F  @ events
	.4byte MauvilleCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_POKEMON_CENTER_2F (g10 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_POKEMON_CENTER_2F  @ events
	.4byte MauvilleCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_MART (g10 m7)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_MART  @ events
	.4byte 0x08200F4F  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_1F (g11 m0)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_1F  @ events
	.4byte RustboroCity_DevonCorp_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005C  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_2F (g11 m1)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_2F  @ events
	.4byte RustboroCity_DevonCorp_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_DEVON_CORP_3F (g11 m2)
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_DEVON_CORP_3F  @ events
	.4byte RustboroCity_DevonCorp_3F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x010D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_GYM (g11 m3)
	.4byte gMapLayout_RUSTBORO_CITY_GYM  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_GYM  @ events
	.4byte 0x082022C5  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x005E  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_SCHOOL (g11 m4)
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_SCHOOL  @ events
	.4byte 0x08202C1A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B3  @ music
	.2byte 0x005F  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_1F (g11 m5)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_1F  @ events
	.4byte RustboroCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_POKEMON_CENTER_2F (g11 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_POKEMON_CENTER_2F  @ events
	.4byte RustboroCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_MART (g11 m7)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_MART  @ events
	.4byte 0x082035E0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT1_1F (g11 m8)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT1_1F  @ events
	.4byte 0x08203714  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0139  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT1_2F (g11 m9)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT1_2F  @ events
	.4byte 0x08203770  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x013A  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE1 (g11 m10)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE1  @ events
	.4byte 0x08203BC8  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0061  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_CUTTERS_HOUSE (g11 m11)
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_CUTTERS_HOUSE  @ events
	.4byte 0x08203D7C  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0062  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE2 (g11 m12)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE2  @ events
	.4byte 0x08203F15  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0060  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_1F (g11 m13)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_1F  @ events
	.4byte 0x08203F99  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0126  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_2F (g11 m14)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_2F  @ events
	.4byte 0x08203FE8  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0127  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_FLAT2_3F (g11 m15)
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_FLAT2_3F  @ events
	.4byte 0x082040B5  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0128  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTBORO_CITY_HOUSE3 (g11 m16)
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_RUSTBORO_CITY_HOUSE3  @ events
	.4byte 0x08204117  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0060  @ mapLayoutId
	.byte 0x0A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE1 (g12 m0)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE1  @ events
	.4byte 0x082041CA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_GYM (g12 m1)
	.4byte gMapLayout_FORTREE_CITY_GYM  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_GYM  @ events
	.4byte FortreeCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x0064  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_POKEMON_CENTER_1F (g12 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_POKEMON_CENTER_1F  @ events
	.4byte FortreeCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_POKEMON_CENTER_2F (g12 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_POKEMON_CENTER_2F  @ events
	.4byte FortreeCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_MART (g12 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_MART  @ events
	.4byte 0x08204DBD  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE2 (g12 m5)
	.4byte gMapLayout_FORTREE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE2  @ events
	.4byte 0x08204E9B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0065  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE3 (g12 m6)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE3  @ events
	.4byte 0x082050D0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE4 (g12 m7)
	.4byte gMapLayout_FORTREE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE4  @ events
	.4byte 0x082051A2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0065  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_HOUSE5 (g12 m8)
	.4byte gMapLayout_FORTREE_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_HOUSE5  @ events
	.4byte 0x08205343  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x0063  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FORTREE_CITY_DECORATION_SHOP (g12 m9)
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP  @ mapLayout
	.4byte gMapEvents_FORTREE_CITY_DECORATION_SHOP  @ events
	.4byte 0x082053F0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x00FF  @ mapLayoutId
	.byte 0x0B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_1F (g13 m0)
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_1F  @ events
	.4byte 0x082054FC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x012B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F (g13 m1)
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_COVE_LILY_MOTEL_2F  @ events
	.4byte 0x08205887  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x012C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F (g13 m2)
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F  @ events
	.4byte 0x08205BE2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0175  @ music
	.2byte 0x0067  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F (g13 m3)
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F  @ events
	.4byte LilycoveCity_LilycoveMuseum_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0175  @ music
	.2byte 0x0068  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_CONTEST_LOBBY (g13 m4)
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_CONTEST_LOBBY  @ events
	.4byte LilycoveCity_ContestLobby_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01C4  @ music
	.2byte 0x0069  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_CONTEST_HALL (g13 m5)
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_CONTEST_HALL  @ events
	.4byte 0x082077B9  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01C4  @ music
	.2byte 0x006A  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_1F (g13 m6)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_1F  @ events
	.4byte LilycoveCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_CENTER_2F (g13 m7)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_CENTER_2F  @ events
	.4byte LilycoveCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_UNUSED_MART (g13 m8)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_UNUSED_MART  @ events
	.4byte 0x0820839D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB (g13 m9)
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB  @ events
	.4byte LilycoveCity_PokemonTrainerFanClub_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x006B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HARBOR (g13 m10)
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HARBOR  @ events
	.4byte LilycoveCity_Harbor_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0058  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_MOVE_DELETERS_HOUSE (g13 m11)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_MOVE_DELETERS_HOUSE  @ events
	.4byte 0x08209D70  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE1 (g13 m12)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE1  @ events
	.4byte 0x08209F66  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE2 (g13 m13)
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE2  @ events
	.4byte 0x08209FDC  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x004A  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE3 (g13 m14)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE3  @ events
	.4byte LilycoveCity_House3_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_HOUSE4 (g13 m15)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_HOUSE4  @ events
	.4byte 0x0820A51A  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F (g13 m16)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_1F  @ events
	.4byte 0x0820A5AF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0101  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F (g13 m17)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_2F  @ events
	.4byte 0x0820A920  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0102  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F (g13 m18)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_3F  @ events
	.4byte 0x0820AA19  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0103  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F (g13 m19)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_4F  @ events
	.4byte 0x0820AB4E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0104  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F (g13 m20)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_5F  @ events
	.4byte LilycoveCity_DepartmentStore_5F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x0105  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP (g13 m21)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP  @ events
	.4byte LilycoveCity_DepartmentStoreRooftop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0106  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR (g13 m22)
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR  @ mapLayout
	.4byte gMapEvents_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR  @ events
	.4byte 0x0820B18C  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0198  @ music
	.2byte 0x0111  @ mapLayoutId
	.byte 0x0C, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GYM (g14 m0)
	.4byte gMapLayout_MOSSDEEP_CITY_GYM  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GYM  @ events
	.4byte MossdeepCity_Gym_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE1 (g14 m1)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE1  @ events
	.4byte 0x0820C332  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE2 (g14 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE2  @ events
	.4byte 0x0820C3D2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F (g14 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_1F  @ events
	.4byte MossdeepCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_POKEMON_CENTER_2F (g14 m4)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_POKEMON_CENTER_2F  @ events
	.4byte MossdeepCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_MART (g14 m5)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_MART  @ events
	.4byte 0x0820C5B2  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE3 (g14 m6)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE3  @ events
	.4byte 0x0820C6FA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_STEVENS_HOUSE (g14 m7)
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_STEVENS_HOUSE  @ events
	.4byte MossdeepCity_StevensHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0147  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_HOUSE4 (g14 m8)
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_HOUSE4  @ events
	.4byte 0x0820CC5B  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0050  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_1F (g14 m9)
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_1F  @ events
	.4byte MossdeepCity_SpaceCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0113  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_SPACE_CENTER_2F (g14 m10)
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_SPACE_CENTER_2F  @ events
	.4byte MossdeepCity_SpaceCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0114  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_1F (g14 m11)
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GAME_CORNER_1F  @ events
	.4byte MossdeepCity_GameCorner_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0131  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MOSSDEEP_CITY_GAME_CORNER_B1F (g14 m12)
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F  @ mapLayout
	.4byte gMapEvents_MOSSDEEP_CITY_GAME_CORNER_B1F  @ events
	.4byte 0x0820E223  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0132  @ mapLayoutId
	.byte 0x0D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_GYM_1F (g15 m0)
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_GYM_1F  @ events
	.4byte SootopolisCity_Gym_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006D  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_GYM_B1F (g15 m1)
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_GYM_B1F  @ events
	.4byte 0x0820EAC6  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016C  @ music
	.2byte 0x006E  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x01  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F (g15 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_1F  @ events
	.4byte SootopolisCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_2F (g15 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_POKEMON_CENTER_2F  @ events
	.4byte SootopolisCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MART (g15 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MART  @ events
	.4byte 0x0820F1B7  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE1 (g15 m5)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE1  @ events
	.4byte 0x0820F300  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE2 (g15 m6)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE2  @ events
	.4byte 0x0820F3C6  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0134  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE3 (g15 m7)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE3  @ events
	.4byte 0x0820F479  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0135  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE4 (g15 m8)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE4  @ events
	.4byte 0x0820F593  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE5 (g15 m9)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE5  @ events
	.4byte 0x0820F657  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0134  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE6 (g15 m10)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE6  @ events
	.4byte 0x0820F6D0  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0135  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_HOUSE7 (g15 m11)
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_HOUSE7  @ events
	.4byte 0x0820F7BA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0133  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE (g15 m12)
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE  @ events
	.4byte 0x0820F861  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x0129  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F (g15 m13)
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F  @ events
	.4byte SootopolisCity_MysteryEventsHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x01B7  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F (g15 m14)
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F  @ mapLayout
	.4byte gMapEvents_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F  @ events
	.4byte SootopolisCity_MysteryEventsHouse_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BD  @ music
	.2byte 0x01B8  @ mapLayoutId
	.byte 0x0E, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM (g16 m0)
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_SIDNEYS_ROOM  @ events
	.4byte EverGrandeCity_SidneysRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x006F  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_PHOEBES_ROOM (g16 m1)
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_PHOEBES_ROOM  @ events
	.4byte EverGrandeCity_PhoebesRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0070  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x05  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_GLACIAS_ROOM (g16 m2)
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_GLACIAS_ROOM  @ events
	.4byte EverGrandeCity_GlaciasRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0071  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x06  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_DRAKES_ROOM (g16 m3)
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_DRAKES_ROOM  @ events
	.4byte EverGrandeCity_DrakesRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0072  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM (g16 m4)
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_CHAMPIONS_ROOM  @ events
	.4byte EverGrandeCity_ChampionsRoom_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0073  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL1 (g16 m5)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL1  @ events
	.4byte EverGrandeCity_Hall1_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL2 (g16 m6)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL2  @ events
	.4byte EverGrandeCity_Hall2_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL3 (g16 m7)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL3  @ events
	.4byte EverGrandeCity_Hall3_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL4 (g16 m8)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL4  @ events
	.4byte EverGrandeCity_Hall4_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x013B  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL5 (g16 m9)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL5  @ events
	.4byte EverGrandeCity_Hall5_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AD  @ music
	.2byte 0x0074  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F (g16 m10)
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F  @ events
	.4byte EverGrandeCity_PokemonLeague_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x010E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_HALL_OF_FAME (g16 m11)
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_HALL_OF_FAME  @ events
	.4byte EverGrandeCity_HallOfFame_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01BF  @ music
	.2byte 0x012A  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F (g16 m12)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_1F  @ events
	.4byte EverGrandeCity_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_CENTER_2F (g16 m13)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_CENTER_2F  @ events
	.4byte EverGrandeCity_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F (g16 m14)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte gMapEvents_EVER_GRANDE_CITY_POKEMON_LEAGUE_2F  @ events
	.4byte EverGrandeCity_PokemonLeague_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x0F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104_MR_BRINEYS_HOUSE (g17 m0)
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE104_MR_BRINEYS_HOUSE  @ events
	.4byte Route104_MrBrineysHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0066  @ mapLayoutId
	.byte 0x13, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE104_PRETTY_PETAL_FLOWER_SHOP (g17 m1)
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP  @ mapLayout
	.4byte gMapEvents_ROUTE104_PRETTY_PETAL_FLOWER_SHOP  @ events
	.4byte Route104_PrettyPetalFlowerShop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016A  @ music
	.2byte 0x0075  @ mapLayoutId
	.byte 0x13, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111_WINSTRATE_FAMILYS_HOUSE (g18 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_ROUTE111_WINSTRATE_FAMILYS_HOUSE  @ events
	.4byte 0x08211AF4  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x1A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111_OLD_LADYS_REST_STOP (g18 m1)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_ROUTE111_OLD_LADYS_REST_STOP  @ events
	.4byte Route111_OldLadysRestStop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x1A, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE112_CABLE_CAR_STATION (g19 m0)
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION  @ mapLayout
	.4byte gMapEvents_ROUTE112_CABLE_CAR_STATION  @ events
	.4byte Route112_CableCarStation_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0076  @ mapLayoutId
	.byte 0x1B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_CHIMNEY_CABLE_CAR_STATION (g19 m1)
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION  @ mapLayout
	.4byte gMapEvents_MT_CHIMNEY_CABLE_CAR_STATION  @ events
	.4byte MtChimney_CableCarStation_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0076  @ mapLayoutId
	.byte 0x38, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_FOSSIL_MANIACS_HOUSE (g20 m0)
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE114_FOSSIL_MANIACS_HOUSE  @ events
	.4byte Route114_FossilManiacsHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0077  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_FOSSIL_MANIACS_TUNNEL (g20 m1)
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL  @ mapLayout
	.4byte gMapEvents_ROUTE114_FOSSIL_MANIACS_TUNNEL  @ events
	.4byte Route114_FossilManiacsTunnel_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0078  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114_LANETTES_HOUSE (g20 m2)
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE114_LANETTES_HOUSE  @ events
	.4byte Route114_LanettesHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B5  @ music
	.2byte 0x0079  @ mapLayoutId
	.byte 0x1D, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE116_TUNNELERS_REST_HOUSE (g21 m0)
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE  @ mapLayout
	.4byte gMapEvents_ROUTE116_TUNNELERS_REST_HOUSE  @ events
	.4byte Route116_TunnelersRestHouse_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x007A  @ mapLayoutId
	.byte 0x1F, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE117_POKEMON_DAY_CARE (g22 m0)
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE  @ mapLayout
	.4byte gMapEvents_ROUTE117_POKEMON_DAY_CARE  @ events
	.4byte Route117_PokemonDayCare_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x007B  @ mapLayoutId
	.byte 0x20, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE121_SAFARI_ZONE_ENTRANCE (g23 m0)
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE  @ mapLayout
	.4byte gMapEvents_ROUTE121_SAFARI_ZONE_ENTRANCE  @ events
	.4byte Route121_SafariZoneEntrance_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017E  @ music
	.2byte 0x007C  @ mapLayoutId
	.byte 0x24, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_1F_1R (g24 m0)
	.4byte gMapLayout_METEOR_FALLS_1F_1R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_1F_1R  @ events
	.4byte MeteorFalls_1F_1R_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007D  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_1F_2R (g24 m1)
	.4byte gMapLayout_METEOR_FALLS_1F_2R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_1F_2R  @ events
	.4byte 0x08213079  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007E  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_B1F_1R (g24 m2)
	.4byte gMapLayout_METEOR_FALLS_B1F_1R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_B1F_1R  @ events
	.4byte 0x082135EE  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x007F  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_METEOR_FALLS_B1F_2R (g24 m3)
	.4byte gMapLayout_METEOR_FALLS_B1F_2R  @ mapLayout
	.4byte gMapEvents_METEOR_FALLS_B1F_2R  @ events
	.4byte 0x082135EF  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0182  @ music
	.2byte 0x0080  @ mapLayoutId
	.byte 0x3F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_RUSTURF_TUNNEL (g24 m4)
	.4byte gMapLayout_RUSTURF_TUNNEL  @ mapLayout
	.4byte gMapEvents_RUSTURF_TUNNEL  @ events
	.4byte RusturfTunnel_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0081  @ mapLayoutId
	.byte 0x3C, 0x00, 0x06, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_SOOTOPOLIS_CITY (g24 m5)
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY  @ mapLayout
	.4byte gMapEvents_UNDERWATER_SOOTOPOLIS_CITY  @ events
	.4byte Underwater_SootopolisCity_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0082  @ mapLayoutId
	.byte 0x36, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DESERT_RUINS (g24 m6)
	.4byte gMapLayout_DESERT_RUINS  @ mapLayout
	.4byte gMapEvents_DESERT_RUINS  @ events
	.4byte DesertRuins_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B6  @ music
	.2byte 0x0083  @ mapLayoutId
	.byte 0x52, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_1F (g24 m7)
	.4byte gMapLayout_GRANITE_CAVE_1F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_1F  @ events
	.4byte 0x08213EE1  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0084  @ mapLayoutId
	.byte 0x37, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_B1F (g24 m8)
	.4byte gMapLayout_GRANITE_CAVE_B1F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_B1F  @ events
	.4byte GraniteCave_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0085  @ mapLayoutId
	.byte 0x37, 0x01, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_B2F (g24 m9)
	.4byte gMapLayout_GRANITE_CAVE_B2F  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_B2F  @ events
	.4byte 0x08214026  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0086  @ mapLayoutId
	.byte 0x37, 0x01, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_GRANITE_CAVE_STEVENS_ROOM (g24 m10)
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM  @ mapLayout
	.4byte gMapEvents_GRANITE_CAVE_STEVENS_ROOM  @ events
	.4byte 0x08214027  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0120  @ mapLayoutId
	.byte 0x37, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_PETALBURG_WOODS (g24 m11)
	.4byte gMapLayout_PETALBURG_WOODS  @ mapLayout
	.4byte gMapEvents_PETALBURG_WOODS  @ events
	.4byte 0x08214278  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0087  @ mapLayoutId
	.byte 0x3B, 0x00, 0x0B, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_CHIMNEY (g24 m12)
	.4byte gMapLayout_MT_CHIMNEY  @ mapLayout
	.4byte gMapEvents_MT_CHIMNEY  @ events
	.4byte MtChimney_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0088  @ mapLayoutId
	.byte 0x38, 0x00, 0x07, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_JAGGED_PASS (g24 m13)
	.4byte gMapLayout_JAGGED_PASS  @ mapLayout
	.4byte gMapEvents_JAGGED_PASS  @ events
	.4byte JaggedPass_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0124  @ mapLayoutId
	.byte 0x4C, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_FIERY_PATH (g24 m14)
	.4byte gMapLayout_FIERY_PATH  @ mapLayout
	.4byte gMapEvents_FIERY_PATH  @ events
	.4byte FieryPath_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016E  @ music
	.2byte 0x0125  @ mapLayoutId
	.byte 0x4A, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_1F (g24 m15)
	.4byte gMapLayout_MT_PYRE_1F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_1F  @ events
	.4byte 0x08216119  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x0089  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_2F (g24 m16)
	.4byte gMapLayout_MT_PYRE_2F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_2F  @ events
	.4byte MtPyre_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008A  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_3F (g24 m17)
	.4byte gMapLayout_MT_PYRE_3F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_3F  @ events
	.4byte 0x082165F1  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008B  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_4F (g24 m18)
	.4byte gMapLayout_MT_PYRE_4F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_4F  @ events
	.4byte 0x08216880  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008C  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_5F (g24 m19)
	.4byte gMapLayout_MT_PYRE_5F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_5F  @ events
	.4byte 0x082168FA  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008D  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_6F (g24 m20)
	.4byte gMapLayout_MT_PYRE_6F  @ mapLayout
	.4byte gMapEvents_MT_PYRE_6F  @ events
	.4byte 0x08216986  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B0  @ music
	.2byte 0x008E  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_EXTERIOR (g24 m21)
	.4byte gMapLayout_MT_PYRE_EXTERIOR  @ mapLayout
	.4byte gMapEvents_MT_PYRE_EXTERIOR  @ events
	.4byte MtPyre_Exterior_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B2  @ music
	.2byte 0x012E  @ mapLayoutId
	.byte 0x41, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MT_PYRE_SUMMIT (g24 m22)
	.4byte gMapLayout_MT_PYRE_SUMMIT  @ mapLayout
	.4byte gMapEvents_MT_PYRE_SUMMIT  @ events
	.4byte MtPyre_Summit_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01B2  @ music
	.2byte 0x012F  @ mapLayoutId
	.byte 0x41, 0x00, 0x06, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_1F (g24 m23)
	.4byte gMapLayout_AQUA_HIDEOUT_1F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_1F  @ events
	.4byte 0x08217935  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x008F  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_B1F (g24 m24)
	.4byte gMapLayout_AQUA_HIDEOUT_B1F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_B1F  @ events
	.4byte AquaHideout_B1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x0090  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_AQUA_HIDEOUT_B2F (g24 m25)
	.4byte gMapLayout_AQUA_HIDEOUT_B2F  @ mapLayout
	.4byte gMapEvents_AQUA_HIDEOUT_B2F  @ events
	.4byte AquaHideout_B2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AE  @ music
	.2byte 0x0091  @ mapLayoutId
	.byte 0xC5, 0x00, 0x00, 0x08, 0x00, 0x00, 0x08, 0x03  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_SEAFLOOR_CAVERN (g24 m26)
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN  @ mapLayout
	.4byte gMapEvents_UNDERWATER_SEAFLOOR_CAVERN  @ events
	.4byte Underwater_SeafloorCavern_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x019B  @ music
	.2byte 0x0092  @ mapLayoutId
	.byte 0x45, 0x00, 0x0E, 0x05, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ENTRANCE (g24 m27)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ENTRANCE  @ events
	.4byte SeafloorCavern_Entrance_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0093  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM1 (g24 m28)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM1  @ events
	.4byte 0x0821865E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0094  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM2 (g24 m29)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM2  @ events
	.4byte 0x0821873D  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0095  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM3 (g24 m30)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM3  @ events
	.4byte 0x0821873E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0096  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_SEAFLOOR_CAVERN_ROOM4 (g24 m31)
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4  @ mapLayout
	.4byte gMapEvents_SEAFLOOR_CAVERN_ROOM4  @ events
	.4byte 0x0821892E  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0196  @ music
	.2byte 0x0097  @ mapLayoutId
	.byte 0x44, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0F, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	.globl gUnknown_845C660
gUnknown_845C660: @ 0x0845C660
	.incbin "baserom_jp.gba", 0x45c660, 0x2338

	.globl gUnknown_845E998
gUnknown_845E998: @ 0x845E998
	.globl gUnknown_845E998
gUnknown_845E998: @ 0x0845E998
	.incbin "baserom_jp.gba", 0x45E998, 0x88
	.globl LITTLEROOT_TOWN_MapConnections
LITTLEROOT_TOWN_MapConnections: @ 0x0845EA20
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 16, 0x00, 0x00  @ mapGroup, mapNum (0x0010)
	.globl gMapConnections_LITTLEROOT_TOWN
gMapConnections_LITTLEROOT_TOWN: @ 0x0845EA2C
	.4byte 1  @ count
	.4byte LITTLEROOT_TOWN_MapConnections  @ connections
	.globl OLDALE_TOWN_MapConnections
OLDALE_TOWN_MapConnections: @ 0x0845EA34
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 18, 0x00, 0x00  @ mapGroup, mapNum (0x0012)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 16, 0x00, 0x00  @ mapGroup, mapNum (0x0010)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 17, 0x00, 0x00  @ mapGroup, mapNum (0x0011)
	.globl gMapConnections_OLDALE_TOWN
gMapConnections_OLDALE_TOWN: @ 0x0845EA58
	.4byte 3  @ count
	.4byte OLDALE_TOWN_MapConnections  @ connections
	.globl DEWFORD_TOWN_MapConnections
DEWFORD_TOWN_MapConnections: @ 0x0845EA60
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 21, 0x00, 0x00  @ mapGroup, mapNum (0x0015)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 22, 0x00, 0x00  @ mapGroup, mapNum (0x0016)
	.globl gMapConnections_DEWFORD_TOWN
gMapConnections_DEWFORD_TOWN: @ 0x0845EA78
	.4byte 2  @ count
	.4byte DEWFORD_TOWN_MapConnections  @ connections
	.globl LAVARIDGE_TOWN_MapConnections
LAVARIDGE_TOWN_MapConnections: @ 0x0845EA80
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.globl gMapConnections_LAVARIDGE_TOWN
gMapConnections_LAVARIDGE_TOWN: @ 0x0845EA8C
	.4byte 1  @ count
	.4byte LAVARIDGE_TOWN_MapConnections  @ connections
	.globl FALLARBOR_TOWN_MapConnections
FALLARBOR_TOWN_MapConnections: @ 0x0845EA94
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 29, 0x00, 0x00  @ mapGroup, mapNum (0x001D)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.globl gMapConnections_FALLARBOR_TOWN
gMapConnections_FALLARBOR_TOWN: @ 0x0845EAAC
	.4byte 2  @ count
	.4byte FALLARBOR_TOWN_MapConnections  @ connections
	.globl VERDANTURF_TOWN_MapConnections
VERDANTURF_TOWN_MapConnections: @ 0x0845EAB4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -80  @ offset
	.byte 0, 31, 0x00, 0x00  @ mapGroup, mapNum (0x001F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 32, 0x00, 0x00  @ mapGroup, mapNum (0x0020)
	.globl gMapConnections_VERDANTURF_TOWN
gMapConnections_VERDANTURF_TOWN: @ 0x0845EACC
	.4byte 2  @ count
	.4byte VERDANTURF_TOWN_MapConnections  @ connections
	.globl PACIFIDLOG_TOWN_MapConnections
PACIFIDLOG_TOWN_MapConnections: @ 0x0845EAD4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 47, 0x00, 0x00  @ mapGroup, mapNum (0x002F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 46, 0x00, 0x00  @ mapGroup, mapNum (0x002E)
	.globl gMapConnections_PACIFIDLOG_TOWN
gMapConnections_PACIFIDLOG_TOWN: @ 0x0845EAEC
	.4byte 2  @ count
	.4byte PACIFIDLOG_TOWN_MapConnections  @ connections
	.globl PETALBURG_CITY_MapConnections
PETALBURG_CITY_MapConnections: @ 0x0845EAF4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -50  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 17, 0x00, 0x00  @ mapGroup, mapNum (0x0011)
	.globl gMapConnections_PETALBURG_CITY
gMapConnections_PETALBURG_CITY: @ 0x0845EB0C
	.4byte 2  @ count
	.4byte PETALBURG_CITY_MapConnections  @ connections
	.globl SLATEPORT_CITY_MapConnections
SLATEPORT_CITY_MapConnections: @ 0x0845EB14
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 24, 0x00, 0x00  @ mapGroup, mapNum (0x0018)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 49, 0x00, 0x00  @ mapGroup, mapNum (0x0031)
	.globl gMapConnections_SLATEPORT_CITY
gMapConnections_SLATEPORT_CITY: @ 0x0845EB38
	.4byte 3  @ count
	.4byte SLATEPORT_CITY_MapConnections  @ connections
	.globl MAUVILLE_CITY_MapConnections
MAUVILLE_CITY_MapConnections: @ 0x0845EB40
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 32, 0x00, 0x00  @ mapGroup, mapNum (0x0020)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.globl gMapConnections_MAUVILLE_CITY
gMapConnections_MAUVILLE_CITY: @ 0x0845EB70
	.4byte 4  @ count
	.4byte MAUVILLE_CITY_MapConnections  @ connections
	.globl RUSTBORO_CITY_MapConnections
RUSTBORO_CITY_MapConnections: @ 0x0845EB78
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 30, 0x00, 0x00  @ mapGroup, mapNum (0x001E)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 31, 0x00, 0x00  @ mapGroup, mapNum (0x001F)
	.globl gMapConnections_RUSTBORO_CITY
gMapConnections_RUSTBORO_CITY: @ 0x0845EB9C
	.4byte 3  @ count
	.4byte RUSTBORO_CITY_MapConnections  @ connections
	.globl FORTREE_CITY_MapConnections
FORTREE_CITY_MapConnections: @ 0x0845EBA4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 34, 0x00, 0x00  @ mapGroup, mapNum (0x0022)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 35, 0x00, 0x00  @ mapGroup, mapNum (0x0023)
	.globl gMapConnections_FORTREE_CITY
gMapConnections_FORTREE_CITY: @ 0x0845EBBC
	.4byte 2  @ count
	.4byte FORTREE_CITY_MapConnections  @ connections
	.globl LILYCOVE_CITY_MapConnections
LILYCOVE_CITY_MapConnections: @ 0x0845EBC4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_LILYCOVE_CITY
gMapConnections_LILYCOVE_CITY: @ 0x0845EBDC
	.4byte 2  @ count
	.4byte LILYCOVE_CITY_MapConnections  @ connections
	.globl MOSSDEEP_CITY_MapConnections
MOSSDEEP_CITY_MapConnections: @ 0x0845EBE4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_MOSSDEEP_CITY
gMapConnections_MOSSDEEP_CITY: @ 0x0845EC08
	.4byte 3  @ count
	.4byte MOSSDEEP_CITY_MapConnections  @ connections
	.incbin "baserom_jp.gba", 0x45EC10, 0x8
	.globl EVER_GRANDE_CITY_MapConnections
EVER_GRANDE_CITY_MapConnections: @ 0x0845EC18
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.globl gMapConnections_EVER_GRANDE_CITY
gMapConnections_EVER_GRANDE_CITY: @ 0x0845EC24
	.4byte 1  @ count
	.4byte EVER_GRANDE_CITY_MapConnections  @ connections
	.globl ROUTE101_MapConnections
ROUTE101_MapConnections: @ 0x0845EC2C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 9, 0x00, 0x00  @ mapGroup, mapNum (0x0009)
	.globl gMapConnections_ROUTE101
gMapConnections_ROUTE101: @ 0x0845EC44
	.4byte 2  @ count
	.4byte ROUTE101_MapConnections  @ connections
	.globl ROUTE102_MapConnections
ROUTE102_MapConnections: @ 0x0845EC4C
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 0, 0x00, 0x00  @ mapGroup, mapNum (0x0000)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.globl gMapConnections_ROUTE102
gMapConnections_ROUTE102: @ 0x0845EC64
	.4byte 2  @ count
	.4byte ROUTE102_MapConnections  @ connections
	.globl ROUTE103_MapConnections
ROUTE103_MapConnections: @ 0x0845EC6C
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 10, 0x00, 0x00  @ mapGroup, mapNum (0x000A)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 25, 0x00, 0x00  @ mapGroup, mapNum (0x0019)
	.globl gMapConnections_ROUTE103
gMapConnections_ROUTE103: @ 0x0845EC84
	.4byte 2  @ count
	.4byte ROUTE103_MapConnections  @ connections
	.globl ROUTE104_MapConnections
ROUTE104_MapConnections: @ 0x0845EC8C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 50  @ offset
	.byte 0, 0, 0x00, 0x00  @ mapGroup, mapNum (0x0000)
	.globl gMapConnections_ROUTE104
gMapConnections_ROUTE104: @ 0x0845ECB0
	.4byte 3  @ count
	.4byte ROUTE104_MapConnections  @ connections
	.globl ROUTE105_MapConnections
ROUTE105_MapConnections: @ 0x0845ECB8
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 19, 0x00, 0x00  @ mapGroup, mapNum (0x0013)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 21, 0x00, 0x00  @ mapGroup, mapNum (0x0015)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 55, 0x00, 0x00  @ mapGroup, mapNum (0x0037)
	.globl gMapConnections_ROUTE105
gMapConnections_ROUTE105: @ 0x0845ECDC
	.4byte 3  @ count
	.4byte ROUTE105_MapConnections  @ connections
	.globl ROUTE106_MapConnections
ROUTE106_MapConnections: @ 0x0845ECE4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 11, 0x00, 0x00  @ mapGroup, mapNum (0x000B)
	.globl gMapConnections_ROUTE106
gMapConnections_ROUTE106: @ 0x0845ECFC
	.4byte 2  @ count
	.4byte ROUTE106_MapConnections  @ connections
	.globl ROUTE107_MapConnections
ROUTE107_MapConnections: @ 0x0845ED04
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 11, 0x00, 0x00  @ mapGroup, mapNum (0x000B)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 23, 0x00, 0x00  @ mapGroup, mapNum (0x0017)
	.globl gMapConnections_ROUTE107
gMapConnections_ROUTE107: @ 0x0845ED1C
	.4byte 2  @ count
	.4byte ROUTE107_MapConnections  @ connections
	.globl ROUTE108_MapConnections
ROUTE108_MapConnections: @ 0x0845ED24
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 22, 0x00, 0x00  @ mapGroup, mapNum (0x0016)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 24, 0x00, 0x00  @ mapGroup, mapNum (0x0018)
	.globl gMapConnections_ROUTE108
gMapConnections_ROUTE108: @ 0x0845ED3C
	.4byte 2  @ count
	.4byte ROUTE108_MapConnections  @ connections
	.globl ROUTE109_MapConnections
ROUTE109_MapConnections: @ 0x0845ED44
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 23, 0x00, 0x00  @ mapGroup, mapNum (0x0017)
	.globl gMapConnections_ROUTE109
gMapConnections_ROUTE109: @ 0x0845ED5C
	.4byte 2  @ count
	.4byte ROUTE109_MapConnections  @ connections
	.globl ROUTE110_MapConnections
ROUTE110_MapConnections: @ 0x0845ED64
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 18, 0x00, 0x00  @ mapGroup, mapNum (0x0012)
	.globl gMapConnections_ROUTE110
gMapConnections_ROUTE110: @ 0x0845ED88
	.4byte 3  @ count
	.4byte ROUTE110_MapConnections  @ connections
	.globl ROUTE111_MapConnections
ROUTE111_MapConnections: @ 0x0845ED90
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 20  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.globl gMapConnections_ROUTE111
gMapConnections_ROUTE111: @ 0x0845EDB4
	.4byte 3  @ count
	.4byte ROUTE111_MapConnections  @ connections
	.globl ROUTE112_MapConnections
ROUTE112_MapConnections: @ 0x0845EDBC
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -60  @ offset
	.byte 0, 28, 0x00, 0x00  @ mapGroup, mapNum (0x001C)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 12, 0x00, 0x00  @ mapGroup, mapNum (0x000C)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -20  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.globl gMapConnections_ROUTE112
gMapConnections_ROUTE112: @ 0x0845EDE0
	.4byte 3  @ count
	.4byte ROUTE112_MapConnections  @ connections
	.globl ROUTE113_MapConnections
ROUTE113_MapConnections: @ 0x0845EDE8
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 60  @ offset
	.byte 0, 27, 0x00, 0x00  @ mapGroup, mapNum (0x001B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 13, 0x00, 0x00  @ mapGroup, mapNum (0x000D)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 26, 0x00, 0x00  @ mapGroup, mapNum (0x001A)
	.globl gMapConnections_ROUTE113
gMapConnections_ROUTE113: @ 0x0845EE0C
	.4byte 3  @ count
	.4byte ROUTE113_MapConnections  @ connections
	.globl ROUTE114_MapConnections
ROUTE114_MapConnections: @ 0x0845EE14
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 30, 0x00, 0x00  @ mapGroup, mapNum (0x001E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 13, 0x00, 0x00  @ mapGroup, mapNum (0x000D)
	.globl gMapConnections_ROUTE114
gMapConnections_ROUTE114: @ 0x0845EE2C
	.4byte 2  @ count
	.4byte ROUTE114_MapConnections  @ connections
	.globl ROUTE115_MapConnections
ROUTE115_MapConnections: @ 0x0845EE34
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 29, 0x00, 0x00  @ mapGroup, mapNum (0x001D)
	.globl gMapConnections_ROUTE115
gMapConnections_ROUTE115: @ 0x0845EE4C
	.4byte 2  @ count
	.4byte ROUTE115_MapConnections  @ connections
	.globl ROUTE116_MapConnections
ROUTE116_MapConnections: @ 0x0845EE54
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 80  @ offset
	.byte 0, 14, 0x00, 0x00  @ mapGroup, mapNum (0x000E)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 3, 0x00, 0x00  @ mapGroup, mapNum (0x0003)
	.globl gMapConnections_ROUTE116
gMapConnections_ROUTE116: @ 0x0845EE6C
	.4byte 2  @ count
	.4byte ROUTE116_MapConnections  @ connections
	.globl ROUTE117_MapConnections
ROUTE117_MapConnections: @ 0x0845EE74
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 14, 0x00, 0x00  @ mapGroup, mapNum (0x000E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.globl gMapConnections_ROUTE117
gMapConnections_ROUTE117: @ 0x0845EE8C
	.4byte 2  @ count
	.4byte ROUTE117_MapConnections  @ connections
	.globl ROUTE118_MapConnections
ROUTE118_MapConnections: @ 0x0845EE94
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 34, 0x00, 0x00  @ mapGroup, mapNum (0x0022)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 2, 0x00, 0x00  @ mapGroup, mapNum (0x0002)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 38, 0x00, 0x00  @ mapGroup, mapNum (0x0026)
	.globl gMapConnections_ROUTE118
gMapConnections_ROUTE118: @ 0x0845EEB8
	.4byte 3  @ count
	.4byte ROUTE118_MapConnections  @ connections
	.globl ROUTE119_MapConnections
ROUTE119_MapConnections: @ 0x0845EEC0
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 4, 0x00, 0x00  @ mapGroup, mapNum (0x0004)
	.globl gMapConnections_ROUTE119
gMapConnections_ROUTE119: @ 0x0845EED8
	.4byte 2  @ count
	.4byte ROUTE119_MapConnections  @ connections
	.globl ROUTE120_MapConnections
ROUTE120_MapConnections: @ 0x0845EEE0
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 4, 0x00, 0x00  @ mapGroup, mapNum (0x0004)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 80  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.globl gMapConnections_ROUTE120
gMapConnections_ROUTE120: @ 0x0845EEF8
	.4byte 2  @ count
	.4byte ROUTE120_MapConnections  @ connections
	.globl ROUTE121_MapConnections
ROUTE121_MapConnections: @ 0x0845EF00
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 20  @ offset
	.byte 0, 37, 0x00, 0x00  @ mapGroup, mapNum (0x0025)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte -80  @ offset
	.byte 0, 35, 0x00, 0x00  @ mapGroup, mapNum (0x0023)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -10  @ offset
	.byte 0, 5, 0x00, 0x00  @ mapGroup, mapNum (0x0005)
	.globl gMapConnections_ROUTE121
gMapConnections_ROUTE121: @ 0x0845EF24
	.4byte 3  @ count
	.4byte ROUTE121_MapConnections  @ connections
	.globl ROUTE122_MapConnections
ROUTE122_MapConnections: @ 0x0845EF2C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte -20  @ offset
	.byte 0, 36, 0x00, 0x00  @ mapGroup, mapNum (0x0024)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte -100  @ offset
	.byte 0, 38, 0x00, 0x00  @ mapGroup, mapNum (0x0026)
	.globl gMapConnections_ROUTE122
gMapConnections_ROUTE122: @ 0x0845EF44
	.4byte 2  @ count
	.4byte ROUTE122_MapConnections  @ connections
	.globl ROUTE123_MapConnections
ROUTE123_MapConnections: @ 0x0845EF4C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 100  @ offset
	.byte 0, 37, 0x00, 0x00  @ mapGroup, mapNum (0x0025)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 33, 0x00, 0x00  @ mapGroup, mapNum (0x0021)
	.globl gMapConnections_ROUTE123
gMapConnections_ROUTE123: @ 0x0845EF64
	.4byte 2  @ count
	.4byte ROUTE123_MapConnections  @ connections
	.globl ROUTE124_MapConnections
ROUTE124_MapConnections: @ 0x0845EF6C
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 10  @ offset
	.byte 0, 5, 0x00, 0x00  @ mapGroup, mapNum (0x0005)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 40  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 50, 0x00, 0x00  @ mapGroup, mapNum (0x0032)
	.globl gMapConnections_ROUTE124
gMapConnections_ROUTE124: @ 0x0845EFA8
	.4byte 5  @ count
	.4byte ROUTE124_MapConnections  @ connections
	.globl ROUTE125_MapConnections
ROUTE125_MapConnections: @ 0x0845EFB0
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 56, 0x00, 0x00  @ mapGroup, mapNum (0x0038)
	.globl gMapConnections_ROUTE125
gMapConnections_ROUTE125: @ 0x0845EFD4
	.4byte 3  @ count
	.4byte ROUTE125_MapConnections  @ connections
	.globl ROUTE126_MapConnections
ROUTE126_MapConnections: @ 0x0845EFDC
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.globl gMapConnections_ROUTE126
gMapConnections_ROUTE126: @ 0x0845F000
	.4byte 3  @ count
	.4byte ROUTE126_MapConnections  @ connections
	.globl ROUTE127_MapConnections
ROUTE127_MapConnections: @ 0x0845F008
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 6, 0x00, 0x00  @ mapGroup, mapNum (0x0006)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.globl gMapConnections_ROUTE127
gMapConnections_ROUTE127: @ 0x0845F038
	.4byte 4  @ count
	.4byte ROUTE127_MapConnections  @ connections
	.globl ROUTE128_MapConnections
ROUTE128_MapConnections: @ 0x0845F040
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte -40  @ offset
	.byte 0, 8, 0x00, 0x00  @ mapGroup, mapNum (0x0008)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 53, 0x00, 0x00  @ mapGroup, mapNum (0x0035)
	.globl gMapConnections_ROUTE128
gMapConnections_ROUTE128: @ 0x0845F070
	.4byte 4  @ count
	.4byte ROUTE128_MapConnections  @ connections
	.globl ROUTE129_MapConnections
ROUTE129_MapConnections: @ 0x0845F078
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 45, 0x00, 0x00  @ mapGroup, mapNum (0x002D)
	.byte 0x05, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 54, 0x00, 0x00  @ mapGroup, mapNum (0x0036)
	.globl gMapConnections_ROUTE129
gMapConnections_ROUTE129: @ 0x0845F09C
	.4byte 3  @ count
	.4byte ROUTE129_MapConnections  @ connections
	.globl ROUTE130_MapConnections
ROUTE130_MapConnections: @ 0x0845F0A4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 46, 0x00, 0x00  @ mapGroup, mapNum (0x002E)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.globl gMapConnections_ROUTE130
gMapConnections_ROUTE130: @ 0x0845F0BC
	.4byte 2  @ count
	.4byte ROUTE130_MapConnections  @ connections
	.globl ROUTE131_MapConnections
ROUTE131_MapConnections: @ 0x0845F0C4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 15, 0x00, 0x00  @ mapGroup, mapNum (0x000F)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 45, 0x00, 0x00  @ mapGroup, mapNum (0x002D)
	.globl gMapConnections_ROUTE131
gMapConnections_ROUTE131: @ 0x0845F0DC
	.4byte 2  @ count
	.4byte ROUTE131_MapConnections  @ connections
	.globl ROUTE132_MapConnections
ROUTE132_MapConnections: @ 0x0845F0E4
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 48, 0x00, 0x00  @ mapGroup, mapNum (0x0030)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 15, 0x00, 0x00  @ mapGroup, mapNum (0x000F)
	.globl gMapConnections_ROUTE132
gMapConnections_ROUTE132: @ 0x0845F0FC
	.4byte 2  @ count
	.4byte ROUTE132_MapConnections  @ connections
	.globl ROUTE133_MapConnections
ROUTE133_MapConnections: @ 0x0845F104
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 49, 0x00, 0x00  @ mapGroup, mapNum (0x0031)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 47, 0x00, 0x00  @ mapGroup, mapNum (0x002F)
	.globl gMapConnections_ROUTE133
gMapConnections_ROUTE133: @ 0x0845F11C
	.4byte 2  @ count
	.4byte ROUTE133_MapConnections  @ connections
	.globl ROUTE134_MapConnections
ROUTE134_MapConnections: @ 0x0845F124
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 1, 0x00, 0x00  @ mapGroup, mapNum (0x0001)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 48, 0x00, 0x00  @ mapGroup, mapNum (0x0030)
	.globl gMapConnections_ROUTE134
gMapConnections_ROUTE134: @ 0x0845F13C
	.4byte 2  @ count
	.4byte ROUTE134_MapConnections  @ connections
	.globl UNDERWATER_ROUTE105_MapConnections
UNDERWATER_ROUTE105_MapConnections: @ 0x0845F144
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 20, 0x00, 0x00  @ mapGroup, mapNum (0x0014)
	.globl gMapConnections_UNDERWATER_ROUTE105
gMapConnections_UNDERWATER_ROUTE105: @ 0x0845F150
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE105_MapConnections  @ connections
	.globl UNDERWATER_ROUTE124_MapConnections
UNDERWATER_ROUTE124_MapConnections: @ 0x0845F158
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 39, 0x00, 0x00  @ mapGroup, mapNum (0x0027)
	.globl gMapConnections_UNDERWATER_ROUTE124
gMapConnections_UNDERWATER_ROUTE124: @ 0x0845F170
	.4byte 2  @ count
	.4byte UNDERWATER_ROUTE124_MapConnections  @ connections
	.globl UNDERWATER_ROUTE125_MapConnections
UNDERWATER_ROUTE125_MapConnections: @ 0x0845F178
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 40, 0x00, 0x00  @ mapGroup, mapNum (0x0028)
	.globl gMapConnections_UNDERWATER_ROUTE125
gMapConnections_UNDERWATER_ROUTE125: @ 0x0845F184
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE125_MapConnections  @ connections
	.globl UNDERWATER_ROUTE126_MapConnections
UNDERWATER_ROUTE126_MapConnections: @ 0x0845F18C
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 50, 0x00, 0x00  @ mapGroup, mapNum (0x0032)
	.byte 0x04, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 41, 0x00, 0x00  @ mapGroup, mapNum (0x0029)
	.globl gMapConnections_UNDERWATER_ROUTE126
gMapConnections_UNDERWATER_ROUTE126: @ 0x0845F1B0
	.4byte 3  @ count
	.4byte UNDERWATER_ROUTE126_MapConnections  @ connections
	.globl UNDERWATER_ROUTE127_MapConnections
UNDERWATER_ROUTE127_MapConnections: @ 0x0845F1B8
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 42, 0x00, 0x00  @ mapGroup, mapNum (0x002A)
	.byte 0x03, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 51, 0x00, 0x00  @ mapGroup, mapNum (0x0033)
	.byte 0x01, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 53, 0x00, 0x00  @ mapGroup, mapNum (0x0035)
	.globl gMapConnections_UNDERWATER_ROUTE127
gMapConnections_UNDERWATER_ROUTE127: @ 0x0845F1DC
	.4byte 3  @ count
	.4byte UNDERWATER_ROUTE127_MapConnections  @ connections
	.globl UNDERWATER_ROUTE128_MapConnections
UNDERWATER_ROUTE128_MapConnections: @ 0x0845F1E4
	.byte 0x02, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 52, 0x00, 0x00  @ mapGroup, mapNum (0x0034)
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 43, 0x00, 0x00  @ mapGroup, mapNum (0x002B)
	.globl gMapConnections_UNDERWATER_ROUTE128
gMapConnections_UNDERWATER_ROUTE128: @ 0x0845F1FC
	.4byte 2  @ count
	.4byte UNDERWATER_ROUTE128_MapConnections  @ connections
	.globl UNDERWATER_ROUTE129_MapConnections
UNDERWATER_ROUTE129_MapConnections: @ 0x0845F204
	.byte 0x06, 0x00, 0x00, 0x00  @ direction
	.4byte 0  @ offset
	.byte 0, 44, 0x00, 0x00  @ mapGroup, mapNum (0x002C)
	.globl gMapConnections_UNDERWATER_ROUTE129
gMapConnections_UNDERWATER_ROUTE129: @ 0x0845F210
	.4byte 1  @ count
	.4byte UNDERWATER_ROUTE129_MapConnections  @ connections
	.incbin "baserom_jp.gba", 0x45F218, 0x100

	.globl sDummyConnectionFlags
sDummyConnectionFlags: @ 0x845F318
	.incbin "baserom_jp.gba", 0x45f318, 0x4

	.globl sTileBitAttributes
sTileBitAttributes: @ 0x845F31C
	.incbin "baserom_jp.gba", 0x45f31c, 0x10090

	.globl sDoorOpenAnimFrames
sDoorOpenAnimFrames: @ 0x846F3AC
	.incbin "baserom_jp.gba", 0x46f3ac, 0x14

	.globl sDoorCloseAnimFrames
sDoorCloseAnimFrames: @ 0x846F3C0
	.incbin "baserom_jp.gba", 0x46f3c0, 0x14

	.globl sBigDoorOpenAnimFrames
sBigDoorOpenAnimFrames: @ 0x846F3D4
	.incbin "baserom_jp.gba", 0x46f3d4, 0x1c0

	.globl sDoorAnimGraphicsTable
sDoorAnimGraphicsTable: @ 0x846F594
	.incbin "baserom_jp.gba", 0x46f594, 0x288

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.incbin "baserom_jp.gba", 0x46f81c, 0x48

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.incbin "baserom_jp.gba", 0x46f864, 0x4c

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.incbin "baserom_jp.gba", 0x46f8b0, 0xc

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.incbin "baserom_jp.gba", 0x46f8bc, 0x14

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.incbin "baserom_jp.gba", 0x46f8d8, 0x20

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.incbin "baserom_jp.gba", 0x46f8f8, 0x10

	.globl gUnknown_846F908
gUnknown_846F908: @ 0x846F908
	.incbin "baserom_jp.gba", 0x46f908, 0x10

	.globl gUnknown_846F918
gUnknown_846F918: @ 0x846F918
	.incbin "baserom_jp.gba", 0x46f918, 0x10

	.globl gUnknown_846F928
gUnknown_846F928: @ 0x846F928
	.incbin "baserom_jp.gba", 0x46f928, 0x2

	.globl gUnknown_846F92A
gUnknown_846F92A: @ 0x846F92A
	.incbin "baserom_jp.gba", 0x46f92a, 0x2

	.globl gUnknown_846F92C
gUnknown_846F92C: @ 0x846F92C
	.incbin "baserom_jp.gba", 0x46f92c, 0x14

	.globl gUnknown_846F940
gUnknown_846F940: @ 0x846F940
	.incbin "baserom_jp.gba", 0x46f940, 0x10

	.globl gUnknown_846F950
gUnknown_846F950: @ 0x846F950
	.incbin "baserom_jp.gba", 0x46f950, 0xc

	.globl gUnknown_846F95C
gUnknown_846F95C: @ 0x846F95C
	.incbin "baserom_jp.gba", 0x46f95c, 0x4

	.globl gUnknown_846F960
gUnknown_846F960: @ 0x846F960
	.incbin "baserom_jp.gba", 0x46f960, 0x10

	.globl gUnknown_846F970
gUnknown_846F970: @ 0x846F970
	.incbin "baserom_jp.gba", 0x46f970, 0x4

	.globl gUnknown_846F974
gUnknown_846F974: @ 0x846F974
	.incbin "baserom_jp.gba", 0x46f974, 0x8

	.globl gUnknown_846F97C
gUnknown_846F97C: @ 0x846F97C
	.incbin "baserom_jp.gba", 0x46f97c, 0x40

	.globl gUnknown_846F9BC
gUnknown_846F9BC: @ 0x846F9BC
	.incbin "baserom_jp.gba", 0x46f9bc, 0x6

	.globl gUnknown_846F9C2
gUnknown_846F9C2: @ 0x846F9C2
	.incbin "baserom_jp.gba", 0x46f9c2, 0x6
