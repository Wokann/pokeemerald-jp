.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/map_header.inc"
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
	.incbin "graphics/misc/sContestWinnerPicDummy.bin"

	.globl gUnknown_830FC88
gUnknown_830FC88: @ 0x830FC88
	.incbin "baserom_jp.gba", 0x30fc88, 0x28
	.globl sDummyWarpData
	.set sDummyWarpData, gUnknown_830FC88

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

	.globl sLinkPlayerMovementModes
sLinkPlayerMovementModes: @ 0x830FD14
	.4byte MovementEventModeCB_Normal + 1, MovementEventModeCB_Ignored + 1, MovementEventModeCB_Scripted + 1

	.globl sLinkPlayerFacingHandlers
sLinkPlayerFacingHandlers: @ 0x830FD20
	.4byte FacingHandler_DoNothing + 1, FacingHandler_DpadMovement + 1, FacingHandler_DpadMovement + 1, FacingHandler_DpadMovement + 1, FacingHandler_DpadMovement + 1, FacingHandler_DoNothing + 1, FacingHandler_DoNothing + 1, FacingHandler_ForcedFacingChange + 1
	.4byte FacingHandler_ForcedFacingChange + 1, FacingHandler_ForcedFacingChange + 1, FacingHandler_ForcedFacingChange + 1

	.globl sMovementStatusHandler
sMovementStatusHandler: @ 0x830FD4C
	.4byte MovementStatusHandler_EnterFreeMode + 1, MovementStatusHandler_TryAdvanceScript + 1
gTileset_PETALBURG_CITY_PRIMARY_Tiles:
	.incbin "data/tilesets/primary/general/tiles.4bpp.lz"
gTileset_PETALBURG_CITY_PRIMARY_Palettes:
	.incbin "data/tilesets/primary/general/palettes/00.gbapal"
	.incbin "data/tilesets/primary/general/palettes/01.gbapal"
	.incbin "data/tilesets/primary/general/palettes/02.gbapal"
	.incbin "data/tilesets/primary/general/palettes/03.gbapal"
	.incbin "data/tilesets/primary/general/palettes/04.gbapal"
	.incbin "data/tilesets/primary/general/palettes/05.gbapal"
	.incbin "data/tilesets/primary/general/palettes/06.gbapal"
	.incbin "data/tilesets/primary/general/palettes/07.gbapal"
	.incbin "data/tilesets/primary/general/palettes/08.gbapal"
	.incbin "data/tilesets/primary/general/palettes/09.gbapal"
	.incbin "data/tilesets/primary/general/palettes/10.gbapal"
	.incbin "data/tilesets/primary/general/palettes/11.gbapal"
	.incbin "data/tilesets/primary/general/palettes/12.gbapal"
	.incbin "data/tilesets/primary/general/palettes/13.gbapal"
	.incbin "data/tilesets/primary/general/palettes/14.gbapal"
	.incbin "data/tilesets/primary/general/palettes/15.gbapal"
gTileset_PETALBURG_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/petalburg/tiles.4bpp.lz"
gTileset_PETALBURG_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/petalburg/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/petalburg/palettes/15.gbapal"
gTileset_RUSTBORO_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/rustboro/tiles.4bpp.lz"
gTileset_RUSTBORO_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/rustboro/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/rustboro/palettes/15.gbapal"
gTileset_DEWFORD_TOWN_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/dewford/tiles.4bpp.lz"
gTileset_DEWFORD_TOWN_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/dewford/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/dewford/palettes/15.gbapal"
gTileset_SLATEPORT_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/slateport/tiles.4bpp.lz"
gTileset_SLATEPORT_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/slateport/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/slateport/palettes/15.gbapal"
gTileset_MAUVILLE_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mauville/tiles.4bpp.lz"
gTileset_MAUVILLE_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mauville/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mauville/palettes/15.gbapal"
gTileset_LAVARIDGE_TOWN_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/lavaridge/tiles.4bpp.lz"
gTileset_LAVARIDGE_TOWN_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/lavaridge/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/lavaridge/palettes/15.gbapal"
gTileset_FALLARBOR_TOWN_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/fallarbor/tiles.4bpp.lz"
gTileset_FALLARBOR_TOWN_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/fallarbor/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/fallarbor/palettes/15.gbapal"
gTileset_FORTREE_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/fortree/tiles.4bpp.lz"
gTileset_FORTREE_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/fortree/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/fortree/palettes/15.gbapal"
gTileset_LILYCOVE_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/lilycove/tiles.4bpp.lz"
gTileset_LILYCOVE_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/lilycove/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/lilycove/palettes/15.gbapal"
gTileset_MOSSDEEP_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mossdeep/tiles.4bpp.lz"
gTileset_MOSSDEEP_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mossdeep/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mossdeep/palettes/15.gbapal"
gTileset_EVER_GRANDE_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/ever_grande/tiles.4bpp.lz"
gTileset_EVER_GRANDE_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/ever_grande/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/ever_grande/palettes/15.gbapal"
gTileset_PACIFIDLOG_TOWN_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pacifidlog/tiles.4bpp.lz"
gTileset_PACIFIDLOG_TOWN_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pacifidlog/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pacifidlog/palettes/15.gbapal"
gTileset_SOOTOPOLIS_CITY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/sootopolis/tiles.4bpp.lz"
gTileset_SOOTOPOLIS_CITY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/sootopolis/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/sootopolis/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x324CD4, 0x32D0
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Tiles:
	.incbin "data/tilesets/primary/building/tiles.4bpp.lz"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Palettes:
	.incbin "data/tilesets/primary/building/palettes/00.gbapal"
	.incbin "data/tilesets/primary/building/palettes/01.gbapal"
	.incbin "data/tilesets/primary/building/palettes/02.gbapal"
	.incbin "data/tilesets/primary/building/palettes/03.gbapal"
	.incbin "data/tilesets/primary/building/palettes/04.gbapal"
	.incbin "data/tilesets/primary/building/palettes/05.gbapal"
	.incbin "data/tilesets/primary/building/palettes/06.gbapal"
	.incbin "data/tilesets/primary/building/palettes/07.gbapal"
	.incbin "data/tilesets/primary/building/palettes/08.gbapal"
	.incbin "data/tilesets/primary/building/palettes/09.gbapal"
	.incbin "data/tilesets/primary/building/palettes/10.gbapal"
	.incbin "data/tilesets/primary/building/palettes/11.gbapal"
	.incbin "data/tilesets/primary/building/palettes/12.gbapal"
	.incbin "data/tilesets/primary/building/palettes/13.gbapal"
	.incbin "data/tilesets/primary/building/palettes/14.gbapal"
	.incbin "data/tilesets/primary/building/palettes/15.gbapal"
gTileset_OLDALE_TOWN_MART_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/shop/tiles.4bpp.lz"
gTileset_OLDALE_TOWN_MART_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/shop/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/shop/palettes/15.gbapal"
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pokemon_center/tiles.4bpp.lz"
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pokemon_center/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pokemon_center/palettes/15.gbapal"
gTileset_DESERT_RUINS_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/cave/tiles.4bpp.lz"
gTileset_DESERT_RUINS_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/cave/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/cave/palettes/15.gbapal"
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pokemon_school/tiles.4bpp.lz"
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pokemon_school/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pokemon_school/palettes/15.gbapal"
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pokemon_fan_club/tiles.4bpp.lz"
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pokemon_fan_club/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x32ECF4, 0x24C
gTileset_METEOR_FALLS_1F_1R_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/meteor_falls/tiles.4bpp.lz"
gTileset_METEOR_FALLS_1F_1R_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/meteor_falls/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/meteor_falls/palettes/15.gbapal"
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/oceanic_museum/tiles.4bpp.lz"
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/oceanic_museum/palettes/15.gbapal"
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/cable_club/tiles.4bpp.lz"
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/cable_club/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/cable_club/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x3370EC, 0xADC
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/tiles.4bpp.lz"
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/palettes/15.gbapal"
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/pokemon_day_care/tiles.4bpp.lz"
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/pokemon_day_care/palettes/15.gbapal"
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/facility/tiles.4bpp.lz"
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/facility/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/facility/palettes/15.gbapal"
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/bike_shop/tiles.4bpp.lz"
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/bike_shop/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/bike_shop/palettes/15.gbapal"
gTileset_RUSTURF_TUNNEL_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/rusturf_tunnel/tiles.4bpp.lz"
gTileset_RUSTURF_TUNNEL_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/rusturf_tunnel/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x33D628, 0x6C34
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/contest/tiles.4bpp.lz"
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/contest/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/contest/palettes/15.gbapal"
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/lilycove_museum/tiles.4bpp.lz"
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/lilycove_museum/palettes/15.gbapal"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/brendans_mays_house/tiles.4bpp.lz"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/brendans_mays_house/palettes/15.gbapal"
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/lab/tiles.4bpp.lz"
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/lab/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/lab/palettes/15.gbapal"
gTileset_UNDERWATER_ROUTE126_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/underwater/tiles.4bpp.lz"
gTileset_UNDERWATER_ROUTE126_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/underwater/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/underwater/palettes/15.gbapal"
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/generic_building/tiles.4bpp.lz"
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/generic_building/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/generic_building/palettes/15.gbapal"
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mauville_game_corner/tiles.4bpp.lz"
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mauville_game_corner/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x34C8A8, 0x728
gTileset_RUSTBORO_CITY_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/rustboro_gym/tiles.4bpp.lz"
gTileset_RUSTBORO_CITY_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/rustboro_gym/palettes/15.gbapal"
gTileset_DEWFORD_TOWN_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/dewford_gym/tiles.4bpp.lz"
gTileset_DEWFORD_TOWN_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/dewford_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/dewford_gym/palettes/15.gbapal"
gTileset_MAUVILLE_CITY_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mauville_gym/tiles.4bpp.lz"
gTileset_MAUVILLE_CITY_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mauville_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mauville_gym/palettes/15.gbapal"
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/lavaridge_gym/tiles.4bpp.lz"
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/lavaridge_gym/palettes/15.gbapal"
gTileset_PETALBURG_CITY_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/petalburg_gym/tiles.4bpp.lz"
gTileset_PETALBURG_CITY_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/petalburg_gym/palettes/15.gbapal"
gTileset_FORTREE_CITY_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/fortree_gym/tiles.4bpp.lz"
gTileset_FORTREE_CITY_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/fortree_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/fortree_gym/palettes/15.gbapal"
gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mossdeep_gym/tiles.4bpp.lz"
gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_gym/palettes/15.gbapal"
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/sootopolis_gym/tiles.4bpp.lz"
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/sootopolis_gym/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x3510E4, 0x9F84
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/elite_four/tiles.4bpp.lz"
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/elite_four/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/elite_four/palettes/15.gbapal"
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/battle_frontier/tiles.4bpp.lz"
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/battle_frontier/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/battle_frontier/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x35D1E8, 0x841C
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mossdeep_game_corner/tiles.4bpp.lz"
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mossdeep_game_corner/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x365C24, 0x56A8
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/battle_tent/tiles.4bpp.lz"
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/battle_tent/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/battle_tent/palettes/15.gbapal"
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Tiles:
	.incbin "data/tilesets/secondary/mystery_events_house/tiles.4bpp.lz"
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Palettes:
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/00.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/01.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/02.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/03.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/04.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/05.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/06.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/07.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/08.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/09.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/10.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/11.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/12.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/13.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/14.gbapal"
	.incbin "data/tilesets/secondary/mystery_events_house/palettes/15.gbapal"
	.incbin "baserom_jp.gba", 0x36DA98, 0xA78
gTileset_PETALBURG_CITY_PRIMARY_Metatiles:
	.incbin "data/tilesets/primary/general/metatiles.bin"
gTileset_PETALBURG_CITY_PRIMARY_MetatileAttributes:
	.incbin "data/tilesets/primary/general/metatile_attributes.bin"
gTileset_PETALBURG_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/petalburg/metatiles.bin"
gTileset_PETALBURG_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/petalburg/metatile_attributes.bin"
gTileset_RUSTBORO_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/rustboro/metatiles.bin"
gTileset_RUSTBORO_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/rustboro/metatile_attributes.bin"
gTileset_DEWFORD_TOWN_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/dewford/metatiles.bin"
gTileset_DEWFORD_TOWN_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/dewford/metatile_attributes.bin"
gTileset_SLATEPORT_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/slateport/metatiles.bin"
gTileset_SLATEPORT_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/slateport/metatile_attributes.bin"
gTileset_MAUVILLE_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mauville/metatiles.bin"
gTileset_MAUVILLE_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mauville/metatile_attributes.bin"
gTileset_LAVARIDGE_TOWN_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/lavaridge/metatiles.bin"
gTileset_LAVARIDGE_TOWN_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/lavaridge/metatile_attributes.bin"
gTileset_FALLARBOR_TOWN_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/fallarbor/metatiles.bin"
gTileset_FALLARBOR_TOWN_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/fallarbor/metatile_attributes.bin"
gTileset_FORTREE_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/fortree/metatiles.bin"
gTileset_FORTREE_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/fortree/metatile_attributes.bin"
gTileset_LILYCOVE_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/lilycove/metatiles.bin"
gTileset_LILYCOVE_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/lilycove/metatile_attributes.bin"
gTileset_MOSSDEEP_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mossdeep/metatiles.bin"
gTileset_MOSSDEEP_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mossdeep/metatile_attributes.bin"
gTileset_EVER_GRANDE_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/ever_grande/metatiles.bin"
gTileset_EVER_GRANDE_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/ever_grande/metatile_attributes.bin"
gTileset_PACIFIDLOG_TOWN_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pacifidlog/metatiles.bin"
gTileset_PACIFIDLOG_TOWN_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pacifidlog/metatile_attributes.bin"
gTileset_SOOTOPOLIS_CITY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/sootopolis/metatiles.bin"
gTileset_SOOTOPOLIS_CITY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/sootopolis/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x3837E6, 0x47B8
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Metatiles:
	.incbin "data/tilesets/primary/building/metatiles.bin"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_MetatileAttributes:
	.incbin "data/tilesets/primary/building/metatile_attributes.bin"
gTileset_OLDALE_TOWN_MART_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/shop/metatiles.bin"
gTileset_OLDALE_TOWN_MART_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/shop/metatile_attributes.bin"
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pokemon_center/metatiles.bin"
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pokemon_center/metatile_attributes.bin"
gTileset_DESERT_RUINS_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/cave/metatiles.bin"
gTileset_DESERT_RUINS_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/cave/metatile_attributes.bin"
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pokemon_school/metatiles.bin"
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pokemon_school/metatile_attributes.bin"
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pokemon_fan_club/metatiles.bin"
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pokemon_fan_club/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x38CD50, 0x24
gTileset_METEOR_FALLS_1F_1R_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/meteor_falls/metatiles.bin"
gTileset_METEOR_FALLS_1F_1R_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/meteor_falls/metatile_attributes.bin"
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/oceanic_museum/metatiles.bin"
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/oceanic_museum/metatile_attributes.bin"
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/cable_club/metatiles.bin"
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/cable_club/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x38F336, 0x3F0
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/metatiles.bin"
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pretty_petal_flower_shop/metatile_attributes.bin"
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/pokemon_day_care/metatiles.bin"
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/pokemon_day_care/metatile_attributes.bin"
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/facility/metatiles.bin"
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/facility/metatile_attributes.bin"
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/bike_shop/metatiles.bin"
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/bike_shop/metatile_attributes.bin"
gTileset_RUSTURF_TUNNEL_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/rusturf_tunnel/metatiles.bin"
gTileset_RUSTURF_TUNNEL_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/rusturf_tunnel/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x393C32, 0x1974
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/contest/metatiles.bin"
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/contest/metatile_attributes.bin"
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/lilycove_museum/metatiles.bin"
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/lilycove_museum/metatile_attributes.bin"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/brendans_mays_house/metatiles.bin"
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/brendans_mays_house/metatile_attributes.bin"
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/lab/metatiles.bin"
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/lab/metatile_attributes.bin"
gTileset_UNDERWATER_ROUTE126_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/underwater/metatiles.bin"
gTileset_UNDERWATER_ROUTE126_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/underwater/metatile_attributes.bin"
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/generic_building/metatiles.bin"
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/generic_building/metatile_attributes.bin"
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mauville_game_corner/metatiles.bin"
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mauville_game_corner/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x39C452, 0x414
gTileset_RUSTBORO_CITY_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/rustboro_gym/metatiles.bin"
gTileset_RUSTBORO_CITY_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/rustboro_gym/metatile_attributes.bin"
gTileset_DEWFORD_TOWN_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/dewford_gym/metatiles.bin"
gTileset_DEWFORD_TOWN_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/dewford_gym/metatile_attributes.bin"
gTileset_MAUVILLE_CITY_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mauville_gym/metatiles.bin"
gTileset_MAUVILLE_CITY_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mauville_gym/metatile_attributes.bin"
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/lavaridge_gym/metatiles.bin"
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/lavaridge_gym/metatile_attributes.bin"
gTileset_PETALBURG_CITY_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/petalburg_gym/metatiles.bin"
gTileset_PETALBURG_CITY_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/petalburg_gym/metatile_attributes.bin"
gTileset_FORTREE_CITY_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/fortree_gym/metatiles.bin"
gTileset_FORTREE_CITY_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/fortree_gym/metatile_attributes.bin"
gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mossdeep_gym/metatiles.bin"
gTileset_MOSSDEEP_CITY_GYM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mossdeep_gym/metatile_attributes.bin"
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/sootopolis_gym/metatiles.bin"
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/sootopolis_gym/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x3A03E2, 0x1F26
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/elite_four/metatiles.bin"
gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/elite_four/metatile_attributes.bin"
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/battle_frontier/metatiles.bin"
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/battle_frontier/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x3A5E2A, 0x94A4
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mossdeep_game_corner/metatiles.bin"
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mossdeep_game_corner/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x3AF688, 0x698A
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/battle_tent/metatiles.bin"
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/battle_tent/metatile_attributes.bin"
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Metatiles:
	.incbin "data/tilesets/secondary/mystery_events_house/metatiles.bin"
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_MetatileAttributes:
	.incbin "data/tilesets/secondary/mystery_events_house/metatile_attributes.bin"
	.incbin "baserom_jp.gba", 0x3B77B2, 0x372
	.globl gTileset_PETALBURG_CITY_PRIMARY
gTileset_PETALBURG_CITY_PRIMARY: @ 0x083B7B24
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_PETALBURG_CITY_PRIMARY_Tiles  @ tiles
	.4byte gTileset_PETALBURG_CITY_PRIMARY_Palettes  @ palettes
	.4byte gTileset_PETALBURG_CITY_PRIMARY_Metatiles  @ metatiles
	.4byte gTileset_PETALBURG_CITY_PRIMARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A03E9  @ callback
	.globl gTileset_PETALBURG_CITY_SECONDARY
gTileset_PETALBURG_CITY_SECONDARY: @ 0x083B7B3C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_PETALBURG_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_PETALBURG_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_PETALBURG_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_PETALBURG_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0535  @ callback
	.globl gTileset_RUSTBORO_CITY_SECONDARY
gTileset_RUSTBORO_CITY_SECONDARY: @ 0x083B7B54
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_RUSTBORO_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_RUSTBORO_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_RUSTBORO_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_RUSTBORO_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A055D  @ callback
	.globl gTileset_DEWFORD_TOWN_SECONDARY
gTileset_DEWFORD_TOWN_SECONDARY: @ 0x083B7B6C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_DEWFORD_TOWN_SECONDARY_Tiles  @ tiles
	.4byte gTileset_DEWFORD_TOWN_SECONDARY_Palettes  @ palettes
	.4byte gTileset_DEWFORD_TOWN_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_DEWFORD_TOWN_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0589  @ callback
	.globl gTileset_SLATEPORT_CITY_SECONDARY
gTileset_SLATEPORT_CITY_SECONDARY: @ 0x083B7B84
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SLATEPORT_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SLATEPORT_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SLATEPORT_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SLATEPORT_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A05B5  @ callback
	.globl gTileset_MAUVILLE_CITY_SECONDARY
gTileset_MAUVILLE_CITY_SECONDARY: @ 0x083B7B9C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MAUVILLE_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MAUVILLE_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MAUVILLE_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MAUVILLE_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A05E1  @ callback
	.globl gTileset_LAVARIDGE_TOWN_SECONDARY
gTileset_LAVARIDGE_TOWN_SECONDARY: @ 0x083B7BB4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0611  @ callback
	.globl gTileset_FALLARBOR_TOWN_SECONDARY
gTileset_FALLARBOR_TOWN_SECONDARY: @ 0x083B7BCC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY_Tiles  @ tiles
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY_Palettes  @ palettes
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A063D  @ callback
	.globl gTileset_FORTREE_CITY_SECONDARY
gTileset_FORTREE_CITY_SECONDARY: @ 0x083B7BE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_FORTREE_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_FORTREE_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_FORTREE_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_FORTREE_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0665  @ callback
	.globl gTileset_LILYCOVE_CITY_SECONDARY
gTileset_LILYCOVE_CITY_SECONDARY: @ 0x083B7BFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LILYCOVE_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LILYCOVE_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LILYCOVE_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LILYCOVE_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A068D  @ callback
	.globl gTileset_MOSSDEEP_CITY_SECONDARY
gTileset_MOSSDEEP_CITY_SECONDARY: @ 0x083B7C14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A06B5  @ callback
	.globl gTileset_EVER_GRANDE_CITY_SECONDARY
gTileset_EVER_GRANDE_CITY_SECONDARY: @ 0x083B7C2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A06DD  @ callback
	.globl gTileset_PACIFIDLOG_TOWN_SECONDARY
gTileset_PACIFIDLOG_TOWN_SECONDARY: @ 0x083B7C44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY_Tiles  @ tiles
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY_Palettes  @ palettes
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0709  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_SECONDARY
gTileset_SOOTOPOLIS_CITY_SECONDARY: @ 0x083B7C5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0739  @ callback
	.incbin "baserom_jp.gba", 0x3B7C74, 0x30
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY: @ 0x083B7CA4
	.byte 0x01, 0x00, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Tiles  @ tiles
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Palettes  @ palettes
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_Metatiles  @ metatiles
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0411  @ callback
	.globl gTileset_OLDALE_TOWN_MART_SECONDARY
gTileset_OLDALE_TOWN_MART_SECONDARY: @ 0x083B7CBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY_Tiles  @ tiles
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY_Palettes  @ palettes
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY
gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY: @ 0x083B7CD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DESERT_RUINS_SECONDARY
gTileset_DESERT_RUINS_SECONDARY: @ 0x083B7CEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_DESERT_RUINS_SECONDARY_Tiles  @ tiles
	.4byte gTileset_DESERT_RUINS_SECONDARY_Palettes  @ palettes
	.4byte gTileset_DESERT_RUINS_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_DESERT_RUINS_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0805  @ callback
	.globl gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY
gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY: @ 0x083B7D04
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Tiles  @ tiles
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Palettes  @ palettes
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY
gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY: @ 0x083B7D1C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D34, 0x18
	.globl gTileset_METEOR_FALLS_1F_1R_SECONDARY
gTileset_METEOR_FALLS_1F_1R_SECONDARY: @ 0x083B7D4C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY_Tiles  @ tiles
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY_Palettes  @ palettes
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY
gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY: @ 0x083B7D64
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY
gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY: @ 0x083B7D7C
	.byte 0x00, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Tiles  @ tiles
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Palettes  @ palettes
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7D94, 0x18
	.globl gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY
gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY: @ 0x083B7DAC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Tiles  @ tiles
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Palettes  @ palettes
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY
gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY: @ 0x083B7DC4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Tiles  @ tiles
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Palettes  @ palettes
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY
gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY: @ 0x083B7DDC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY
gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY: @ 0x083B7DF4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0881  @ callback
	.globl gTileset_RUSTURF_TUNNEL_SECONDARY
gTileset_RUSTURF_TUNNEL_SECONDARY: @ 0x083B7E0C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY_Tiles  @ tiles
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY_Palettes  @ palettes
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B7E24, 0xC0
	.globl gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY
gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY: @ 0x083B7EE4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY
gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY: @ 0x083B7EFC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY
gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY: @ 0x083B7F14
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY
gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY: @ 0x083B7F2C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_UNDERWATER_ROUTE126_SECONDARY
gTileset_UNDERWATER_ROUTE126_SECONDARY: @ 0x083B7F44
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY_Tiles  @ tiles
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY_Palettes  @ palettes
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A07BD  @ callback
	.globl gTileset_PETALBURG_CITY_GYM_SECONDARY
gTileset_PETALBURG_CITY_GYM_SECONDARY: @ 0x083B7F5C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY: @ 0x083B7F74
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A07E1  @ callback
	.globl gTileset_OLDALE_TOWN_HOUSE1_SECONDARY
gTileset_OLDALE_TOWN_HOUSE1_SECONDARY: @ 0x083B7F8C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Tiles  @ tiles
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Palettes  @ palettes
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY
gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY: @ 0x083B7FA4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_RUSTBORO_CITY_GYM_SECONDARY
gTileset_RUSTBORO_CITY_GYM_SECONDARY: @ 0x083B7FBC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_DEWFORD_TOWN_GYM_SECONDARY
gTileset_DEWFORD_TOWN_GYM_SECONDARY: @ 0x083B7FD4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MAUVILLE_CITY_GYM_SECONDARY
gTileset_MAUVILLE_CITY_GYM_SECONDARY: @ 0x083B7FEC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0855  @ callback
	.globl gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY
gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY: @ 0x083B8004
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B801C, 0x18
	.globl gTileset_FORTREE_CITY_GYM_SECONDARY
gTileset_FORTREE_CITY_GYM_SECONDARY: @ 0x083B8034
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_MOSSDEEP_CITY_GYM_SECONDARY
gTileset_MOSSDEEP_CITY_GYM_SECONDARY: @ 0x083B804C
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY_MetatileAttributes  @ metatileAttributes
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
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Tiles  @ tiles
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Palettes  @ palettes
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x080A0831  @ callback
	.globl gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY
gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY: @ 0x083B80B4
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Tiles  @ tiles
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Palettes  @ palettes
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B80CC, 0xA8
	.globl gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY
gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY: @ 0x083B8174
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B818C, 0x60
	.globl gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY
gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY: @ 0x083B81EC
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Tiles  @ tiles
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Palettes  @ palettes
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.globl gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY
gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY: @ 0x083B8204
	.byte 0x01, 0x01, 0x00, 0x00  @ isCompressed, isSecondary
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Tiles  @ tiles
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Palettes  @ palettes
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_Metatiles  @ metatiles
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY_MetatileAttributes  @ metatileAttributes
	.4byte 0x00000000  @ callback
	.incbin "baserom_jp.gba", 0x3B821C, 0x18
gMapLayout_PETALBURG_CITY_Border:
	.incbin "data/layouts/PetalburgCity/border.bin"
gMapLayout_PETALBURG_CITY_Blockdata:
	.incbin "data/layouts/PetalburgCity/map.bin"
	.globl gMapLayout_PETALBURG_CITY
gMapLayout_PETALBURG_CITY: @ 0x083B8944
	.4byte 30  @ width
	.4byte 30  @ height
	.4byte gMapLayout_PETALBURG_CITY_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_Border:
	.incbin "data/layouts/SlateportCity/border.bin"
gMapLayout_SLATEPORT_CITY_Blockdata:
	.incbin "data/layouts/SlateportCity/map.bin"
	.globl gMapLayout_SLATEPORT_CITY
gMapLayout_SLATEPORT_CITY: @ 0x083B9C24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_SLATEPORT_CITY_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_Border:
	.incbin "data/layouts/MauvilleCity/border.bin"
gMapLayout_MAUVILLE_CITY_Blockdata:
	.incbin "data/layouts/MauvilleCity/map.bin"
	.globl gMapLayout_MAUVILLE_CITY
gMapLayout_MAUVILLE_CITY: @ 0x083BA284
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte gMapLayout_MAUVILLE_CITY_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_Border:
	.incbin "data/layouts/RustboroCity/border.bin"
gMapLayout_RUSTBORO_CITY_Blockdata:
	.incbin "data/layouts/RustboroCity/map.bin"
	.globl gMapLayout_RUSTBORO_CITY
gMapLayout_RUSTBORO_CITY: @ 0x083BB564
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_RUSTBORO_CITY_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_Border:
	.incbin "data/layouts/FortreeCity/border.bin"
gMapLayout_FORTREE_CITY_Blockdata:
	.incbin "data/layouts/FortreeCity/map.bin"
	.globl gMapLayout_FORTREE_CITY
gMapLayout_FORTREE_CITY: @ 0x083BBBC4
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte gMapLayout_FORTREE_CITY_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_Border:
	.incbin "data/layouts/LilycoveCity/border.bin"
gMapLayout_LILYCOVE_CITY_Blockdata:
	.incbin "data/layouts/LilycoveCity/map.bin"
	.globl gMapLayout_LILYCOVE_CITY
gMapLayout_LILYCOVE_CITY: @ 0x083BD4E4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_LILYCOVE_CITY_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_Border:
	.incbin "data/layouts/MossdeepCity/border.bin"
gMapLayout_MOSSDEEP_CITY_Blockdata:
	.incbin "data/layouts/MossdeepCity/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY
gMapLayout_MOSSDEEP_CITY: @ 0x083BEE04
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_Border:
	.incbin "data/layouts/SootopolisCity/border.bin"
gMapLayout_SOOTOPOLIS_CITY_Blockdata:
	.incbin "data/layouts/SootopolisCity/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY
gMapLayout_SOOTOPOLIS_CITY: @ 0x083C0A44
	.4byte 60  @ width
	.4byte 60  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_Border:
	.incbin "data/layouts/EverGrandeCity/border.bin"
gMapLayout_EVER_GRANDE_CITY_Blockdata:
	.incbin "data/layouts/EverGrandeCity/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY
gMapLayout_EVER_GRANDE_CITY: @ 0x083C2364
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_Border:
	.incbin "data/layouts/LittlerootTown/border.bin"
gMapLayout_LITTLEROOT_TOWN_Blockdata:
	.incbin "data/layouts/LittlerootTown/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN
gMapLayout_LITTLEROOT_TOWN: @ 0x083C26A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_Border:
	.incbin "data/layouts/OldaleTown/border.bin"
gMapLayout_OLDALE_TOWN_Blockdata:
	.incbin "data/layouts/OldaleTown/map.bin"
	.globl gMapLayout_OLDALE_TOWN
gMapLayout_OLDALE_TOWN: @ 0x083C29E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_OLDALE_TOWN_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_Border:
	.incbin "data/layouts/DewfordTown/border.bin"
gMapLayout_DEWFORD_TOWN_Blockdata:
	.incbin "data/layouts/DewfordTown/map.bin"
	.globl gMapLayout_DEWFORD_TOWN
gMapLayout_DEWFORD_TOWN: @ 0x083C2D24
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_DEWFORD_TOWN_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_Border:
	.incbin "data/layouts/LavaridgeTown/border.bin"
gMapLayout_LAVARIDGE_TOWN_Blockdata:
	.incbin "data/layouts/LavaridgeTown/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN
gMapLayout_LAVARIDGE_TOWN: @ 0x083C3064
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_Border:
	.incbin "data/layouts/FallarborTown/border.bin"
gMapLayout_FALLARBOR_TOWN_Blockdata:
	.incbin "data/layouts/FallarborTown/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN
gMapLayout_FALLARBOR_TOWN: @ 0x083C33A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_VERDANTURF_TOWN_Border:
	.incbin "data/layouts/VerdanturfTown/border.bin"
gMapLayout_VERDANTURF_TOWN_Blockdata:
	.incbin "data/layouts/VerdanturfTown/map.bin"
	.globl gMapLayout_VERDANTURF_TOWN
gMapLayout_VERDANTURF_TOWN: @ 0x083C36E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_Border:
	.incbin "data/layouts/PacifidlogTown/border.bin"
gMapLayout_PACIFIDLOG_TOWN_Blockdata:
	.incbin "data/layouts/PacifidlogTown/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN
gMapLayout_PACIFIDLOG_TOWN: @ 0x083C3D44
	.4byte 20  @ width
	.4byte 40  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE101_Border:
	.incbin "data/layouts/Route101/border.bin"
gMapLayout_ROUTE101_Blockdata:
	.incbin "data/layouts/Route101/map.bin"
	.globl gMapLayout_ROUTE101
gMapLayout_ROUTE101: @ 0x083C4084
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE101_Border  @ border
	.4byte gMapLayout_ROUTE101_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE102_Border:
	.incbin "data/layouts/Route102/border.bin"
gMapLayout_ROUTE102_Blockdata:
	.incbin "data/layouts/Route102/map.bin"
	.globl gMapLayout_ROUTE102
gMapLayout_ROUTE102: @ 0x083C4874
	.4byte 50  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE102_Border  @ border
	.4byte gMapLayout_ROUTE102_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE103_Border:
	.incbin "data/layouts/Route103/border.bin"
gMapLayout_ROUTE103_Blockdata:
	.incbin "data/layouts/Route103/map.bin"
	.globl gMapLayout_ROUTE103
gMapLayout_ROUTE103: @ 0x083C5654
	.4byte 80  @ width
	.4byte 22  @ height
	.4byte gMapLayout_ROUTE103_Border  @ border
	.4byte gMapLayout_ROUTE103_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_Border:
	.incbin "data/layouts/Route104/border.bin"
gMapLayout_ROUTE104_Blockdata:
	.incbin "data/layouts/Route104/map.bin"
	.globl gMapLayout_ROUTE104
gMapLayout_ROUTE104: @ 0x083C6F74
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE104_Border  @ border
	.4byte gMapLayout_ROUTE104_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE105_Border:
	.incbin "data/layouts/Route105/border.bin"
gMapLayout_ROUTE105_Blockdata:
	.incbin "data/layouts/Route105/map.bin"
	.globl gMapLayout_ROUTE105
gMapLayout_ROUTE105: @ 0x083C8894
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE105_Border  @ border
	.4byte gMapLayout_ROUTE105_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE106_Border:
	.incbin "data/layouts/Route106/border.bin"
gMapLayout_ROUTE106_Blockdata:
	.incbin "data/layouts/Route106/map.bin"
	.globl gMapLayout_ROUTE106
gMapLayout_ROUTE106: @ 0x083C9534
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE106_Border  @ border
	.4byte gMapLayout_ROUTE106_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE107_Border:
	.incbin "data/layouts/Route107/border.bin"
gMapLayout_ROUTE107_Blockdata:
	.incbin "data/layouts/Route107/map.bin"
	.globl gMapLayout_ROUTE107
gMapLayout_ROUTE107: @ 0x083C9EB4
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE107_Border  @ border
	.4byte gMapLayout_ROUTE107_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE108_Border:
	.incbin "data/layouts/Route108/border.bin"
gMapLayout_ROUTE108_Blockdata:
	.incbin "data/layouts/Route108/map.bin"
	.globl gMapLayout_ROUTE108
gMapLayout_ROUTE108: @ 0x083CA834
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE108_Border  @ border
	.4byte gMapLayout_ROUTE108_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE109_Border:
	.incbin "data/layouts/Route109/border.bin"
gMapLayout_ROUTE109_Blockdata:
	.incbin "data/layouts/Route109/map.bin"
	.globl gMapLayout_ROUTE109
gMapLayout_ROUTE109: @ 0x083CBC04
	.4byte 40  @ width
	.4byte 63  @ height
	.4byte gMapLayout_ROUTE109_Border  @ border
	.4byte gMapLayout_ROUTE109_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE110_Border:
	.incbin "data/layouts/Route110/border.bin"
gMapLayout_ROUTE110_Blockdata:
	.incbin "data/layouts/Route110/map.bin"
	.globl gMapLayout_ROUTE110
gMapLayout_ROUTE110: @ 0x083CDB64
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte gMapLayout_ROUTE110_Border  @ border
	.4byte gMapLayout_ROUTE110_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE111_Border:
	.incbin "data/layouts/Route111/border.bin"
gMapLayout_ROUTE111_Blockdata:
	.incbin "data/layouts/Route111/map.bin"
	.globl gMapLayout_ROUTE111
gMapLayout_ROUTE111: @ 0x083D0744
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte gMapLayout_ROUTE111_Border  @ border
	.4byte gMapLayout_ROUTE111_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE112_Border:
	.incbin "data/layouts/Route112/border.bin"
gMapLayout_ROUTE112_Blockdata:
	.incbin "data/layouts/Route112/map.bin"
	.globl gMapLayout_ROUTE112
gMapLayout_ROUTE112: @ 0x083D1A24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_ROUTE112_Border  @ border
	.4byte gMapLayout_ROUTE112_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE113_Border:
	.incbin "data/layouts/Route113/border.bin"
gMapLayout_ROUTE113_Blockdata:
	.incbin "data/layouts/Route113/map.bin"
	.globl gMapLayout_ROUTE113
gMapLayout_ROUTE113: @ 0x083D29E4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE113_Border  @ border
	.4byte gMapLayout_ROUTE113_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_Border:
	.incbin "data/layouts/Route114/border.bin"
gMapLayout_ROUTE114_Blockdata:
	.incbin "data/layouts/Route114/map.bin"
	.globl gMapLayout_ROUTE114
gMapLayout_ROUTE114: @ 0x083D4304
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE114_Border  @ border
	.4byte gMapLayout_ROUTE114_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE115_Border:
	.incbin "data/layouts/Route115/border.bin"
gMapLayout_ROUTE115_Blockdata:
	.incbin "data/layouts/Route115/map.bin"
	.globl gMapLayout_ROUTE115
gMapLayout_ROUTE115: @ 0x083D5C24
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE115_Border  @ border
	.4byte gMapLayout_ROUTE115_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE116_Border:
	.incbin "data/layouts/Route116/border.bin"
gMapLayout_ROUTE116_Blockdata:
	.incbin "data/layouts/Route116/map.bin"
	.globl gMapLayout_ROUTE116
gMapLayout_ROUTE116: @ 0x083D6BE4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE116_Border  @ border
	.4byte gMapLayout_ROUTE116_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE117_Border:
	.incbin "data/layouts/Route117/border.bin"
gMapLayout_ROUTE117_Blockdata:
	.incbin "data/layouts/Route117/map.bin"
	.globl gMapLayout_ROUTE117
gMapLayout_ROUTE117: @ 0x083D7564
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE117_Border  @ border
	.4byte gMapLayout_ROUTE117_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE118_Border:
	.incbin "data/layouts/Route118/border.bin"
gMapLayout_ROUTE118_Blockdata:
	.incbin "data/layouts/Route118/map.bin"
	.globl gMapLayout_ROUTE118
gMapLayout_ROUTE118: @ 0x083D8204
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE118_Border  @ border
	.4byte gMapLayout_ROUTE118_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE119_Border:
	.incbin "data/layouts/Route119/border.bin"
gMapLayout_ROUTE119_Blockdata:
	.incbin "data/layouts/Route119/map.bin"
	.globl gMapLayout_ROUTE119
gMapLayout_ROUTE119: @ 0x083DADE4
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte gMapLayout_ROUTE119_Border  @ border
	.4byte gMapLayout_ROUTE119_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE120_Border:
	.incbin "data/layouts/Route120/border.bin"
gMapLayout_ROUTE120_Blockdata:
	.incbin "data/layouts/Route120/map.bin"
	.globl gMapLayout_ROUTE120
gMapLayout_ROUTE120: @ 0x083DCD44
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte gMapLayout_ROUTE120_Border  @ border
	.4byte gMapLayout_ROUTE120_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE121_Border:
	.incbin "data/layouts/Route121/border.bin"
gMapLayout_ROUTE121_Blockdata:
	.incbin "data/layouts/Route121/map.bin"
	.globl gMapLayout_ROUTE121
gMapLayout_ROUTE121: @ 0x083DD9E4
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE121_Border  @ border
	.4byte gMapLayout_ROUTE121_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE122_Border:
	.incbin "data/layouts/Route122/border.bin"
gMapLayout_ROUTE122_Blockdata:
	.incbin "data/layouts/Route122/map.bin"
	.globl gMapLayout_ROUTE122
gMapLayout_ROUTE122: @ 0x083DE684
	.4byte 40  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE122_Border  @ border
	.4byte gMapLayout_ROUTE122_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE123_Border:
	.incbin "data/layouts/Route123/border.bin"
gMapLayout_ROUTE123_Blockdata:
	.incbin "data/layouts/Route123/map.bin"
	.globl gMapLayout_ROUTE123
gMapLayout_ROUTE123: @ 0x083DFC84
	.4byte 140  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE123_Border  @ border
	.4byte gMapLayout_ROUTE123_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE124_Border:
	.incbin "data/layouts/Route124/border.bin"
gMapLayout_ROUTE124_Blockdata:
	.incbin "data/layouts/Route124/map.bin"
	.globl gMapLayout_ROUTE124
gMapLayout_ROUTE124: @ 0x083E2EA4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE124_Border  @ border
	.4byte gMapLayout_ROUTE124_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE125_Border:
	.incbin "data/layouts/Route125/border.bin"
gMapLayout_ROUTE125_Blockdata:
	.incbin "data/layouts/Route125/map.bin"
	.globl gMapLayout_ROUTE125
gMapLayout_ROUTE125: @ 0x083E47C4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE125_Border  @ border
	.4byte gMapLayout_ROUTE125_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE126_Border:
	.incbin "data/layouts/Route126/border.bin"
gMapLayout_ROUTE126_Blockdata:
	.incbin "data/layouts/Route126/map.bin"
	.globl gMapLayout_ROUTE126
gMapLayout_ROUTE126: @ 0x083E79E4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE126_Border  @ border
	.4byte gMapLayout_ROUTE126_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE127_Border:
	.incbin "data/layouts/Route127/border.bin"
gMapLayout_ROUTE127_Blockdata:
	.incbin "data/layouts/Route127/map.bin"
	.globl gMapLayout_ROUTE127
gMapLayout_ROUTE127: @ 0x083EAC04
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE127_Border  @ border
	.4byte gMapLayout_ROUTE127_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE128_Border:
	.incbin "data/layouts/Route128/border.bin"
gMapLayout_ROUTE128_Blockdata:
	.incbin "data/layouts/Route128/map.bin"
	.globl gMapLayout_ROUTE128
gMapLayout_ROUTE128: @ 0x083ED1A4
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE128_Border  @ border
	.4byte gMapLayout_ROUTE128_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE129_Border:
	.incbin "data/layouts/Route129/border.bin"
gMapLayout_ROUTE129_Blockdata:
	.incbin "data/layouts/Route129/map.bin"
	.globl gMapLayout_ROUTE129
gMapLayout_ROUTE129: @ 0x083EEAC4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE129_Border  @ border
	.4byte gMapLayout_ROUTE129_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3eeadc, 0x1920
gMapLayout_ROUTE131_Border:
	.incbin "data/layouts/Route131/border.bin"
gMapLayout_ROUTE131_Blockdata:
	.incbin "data/layouts/Route131/map.bin"
	.globl gMapLayout_ROUTE131
gMapLayout_ROUTE131: @ 0x083F16C4
	.4byte 60  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE131_Border  @ border
	.4byte gMapLayout_ROUTE131_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE132_Border:
	.incbin "data/layouts/Route132/border.bin"
gMapLayout_ROUTE132_Blockdata:
	.incbin "data/layouts/Route132/map.bin"
	.globl gMapLayout_ROUTE132
gMapLayout_ROUTE132: @ 0x083F2FE4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE132_Border  @ border
	.4byte gMapLayout_ROUTE132_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE133_Border:
	.incbin "data/layouts/Route133/border.bin"
gMapLayout_ROUTE133_Blockdata:
	.incbin "data/layouts/Route133/map.bin"
	.globl gMapLayout_ROUTE133
gMapLayout_ROUTE133: @ 0x083F4904
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE133_Border  @ border
	.4byte gMapLayout_ROUTE133_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE134_Border:
	.incbin "data/layouts/Route134/border.bin"
gMapLayout_ROUTE134_Blockdata:
	.incbin "data/layouts/Route134/map.bin"
	.globl gMapLayout_ROUTE134
gMapLayout_ROUTE134: @ 0x083F6224
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE134_Border  @ border
	.4byte gMapLayout_ROUTE134_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE126_Border:
	.incbin "data/layouts/Underwater_Route126/border.bin"
gMapLayout_UNDERWATER_ROUTE126_Blockdata:
	.incbin "data/layouts/Underwater_Route126/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE126
gMapLayout_UNDERWATER_ROUTE126: @ 0x083F9444
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE126_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE126_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE127_Border:
	.incbin "data/layouts/Underwater_Route127/border.bin"
gMapLayout_UNDERWATER_ROUTE127_Blockdata:
	.incbin "data/layouts/Underwater_Route127/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE127
gMapLayout_UNDERWATER_ROUTE127: @ 0x083FC664
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE127_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE127_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE128_Border:
	.incbin "data/layouts/Underwater_Route128/border.bin"
gMapLayout_UNDERWATER_ROUTE128_Blockdata:
	.incbin "data/layouts/Underwater_Route128/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE128
gMapLayout_UNDERWATER_ROUTE128: @ 0x083FEC04
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE128_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE128_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Border:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_1F/border.bin"
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F: @ 0x083FECEC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Border:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_2F/border.bin"
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Blockdata:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_2F/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F: @ 0x083FED9C
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Border:
	.incbin "data/layouts/LittlerootTown_MaysHouse_1F/border.bin"
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/LittlerootTown_MaysHouse_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F: @ 0x083FEE84
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Border:
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/border.bin"
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Blockdata:
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F: @ 0x083FEF34
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Border:
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/border.bin"
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Blockdata:
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB: @ 0x083FF0A8
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_HOUSE1_Border:
	.incbin "data/layouts/OldaleTownHouse1/border.bin"
gMapLayout_OLDALE_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/OldaleTownHouse1/map.bin"
	.globl gMapLayout_OLDALE_TOWN_HOUSE1
gMapLayout_OLDALE_TOWN_HOUSE1: @ 0x083FF17C
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_HOUSE2_Border:
	.incbin "data/layouts/OldaleTownHouse2/border.bin"
gMapLayout_OLDALE_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/OldaleTownHouse2/map.bin"
	.globl gMapLayout_OLDALE_TOWN_HOUSE2
gMapLayout_OLDALE_TOWN_HOUSE2: @ 0x083FF24C
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Border:
	.incbin "data/layouts/OldaleTownPokemonCenter1f/border.bin"
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Blockdata:
	.incbin "data/layouts/OldaleTownPokemonCenter1f/map.bin"
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F: @ 0x083FF368
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Border:
	.incbin "data/layouts/OldaleTownPokemonCenter2f/border.bin"
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Blockdata:
	.incbin "data/layouts/OldaleTownPokemonCenter2f/map.bin"
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F: @ 0x083FF4A0
	.4byte 14  @ width
	.4byte 10  @ height
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_MART_Border:
	.incbin "data/layouts/OldaleTownMart/border.bin"
gMapLayout_OLDALE_TOWN_MART_Blockdata:
	.incbin "data/layouts/OldaleTownMart/map.bin"
	.globl gMapLayout_OLDALE_TOWN_MART
gMapLayout_OLDALE_TOWN_MART: @ 0x083FF570
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_OLDALE_TOWN_MART_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_MART_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HOUSE1_Border:
	.incbin "data/layouts/DewfordTownHouse1/border.bin"
gMapLayout_DEWFORD_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/DewfordTownHouse1/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_HOUSE1
gMapLayout_DEWFORD_TOWN_HOUSE1: @ 0x083FF630
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_GYM_Border:
	.incbin "data/layouts/DewfordTown_Gym/border.bin"
gMapLayout_DEWFORD_TOWN_GYM_Blockdata:
	.incbin "data/layouts/DewfordTown_Gym/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_GYM
gMapLayout_DEWFORD_TOWN_GYM: @ 0x083FFA40
	.4byte 18  @ width
	.4byte 28  @ height
	.4byte gMapLayout_DEWFORD_TOWN_GYM_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HALL_Border:
	.incbin "data/layouts/DewfordTown_Hall/border.bin"
gMapLayout_DEWFORD_TOWN_HALL_Blockdata:
	.incbin "data/layouts/DewfordTown_Hall/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_DEWFORD_TOWN_HALL
gMapLayout_DEWFORD_TOWN_HALL: @ 0x083FFB94
	.4byte 17  @ width
	.4byte 9  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HALL_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HALL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HOUSE2_Border:
	.incbin "data/layouts/DewfordTownHouse2/border.bin"
gMapLayout_DEWFORD_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/DewfordTownHouse2/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_HOUSE2
gMapLayout_DEWFORD_TOWN_HOUSE2: @ 0x083FFC68
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Border:
	.incbin "data/layouts/LavaridgeTown_HerbShop/border.bin"
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Blockdata:
	.incbin "data/layouts/LavaridgeTown_HerbShop/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN_HERB_SHOP
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP: @ 0x083FFD38
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_GYM_1F_Border:
	.incbin "data/layouts/LavaridgeTown_Gym_1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_GYM_1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_Gym_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_1F
gMapLayout_LAVARIDGE_TOWN_GYM_1F: @ 0x083FFFE0
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Border:
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_B1F
gMapLayout_LAVARIDGE_TOWN_GYM_B1F: @ 0x08400288
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Border:
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F: @ 0x084003A4
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4003bc, 0x408
gMapLayout_LILYCOVE_CITY_HOUSE2_Border:
	.incbin "data/layouts/LilycoveCity_House2/border.bin"
gMapLayout_LILYCOVE_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/LilycoveCity_House2/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_HOUSE2
gMapLayout_LILYCOVE_CITY_HOUSE2: @ 0x0840084C
	.4byte 8  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400864, 0x24
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Border:
	.incbin "data/layouts/VerdanturfTown_WandasHouse/border.bin"
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Blockdata:
	.incbin "data/layouts/VerdanturfTown_WandasHouse/map.bin"
	.globl gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE: @ 0x084009A0
	.4byte 17  @ width
	.4byte 8  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Border:
	.incbin "data/layouts/PacifidlogTown_House1/border.bin"
gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/PacifidlogTown_House1/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE1
gMapLayout_PACIFIDLOG_TOWN_HOUSE1: @ 0x08400A74
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Border:
	.incbin "data/layouts/PacifidlogTown_House2/border.bin"
gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/PacifidlogTown_House2/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE2
gMapLayout_PACIFIDLOG_TOWN_HOUSE2: @ 0x08400B48
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_CITY_GYM_Border:
	.incbin "data/layouts/PetalburgCity_Gym/border.bin"
gMapLayout_PETALBURG_CITY_GYM_Blockdata:
	.incbin "data/layouts/PetalburgCity_Gym/map.bin"
	.globl gMapLayout_PETALBURG_CITY_GYM
gMapLayout_PETALBURG_CITY_GYM: @ 0x08401348
	.4byte 9  @ width
	.4byte 112  @ height
	.4byte gMapLayout_PETALBURG_CITY_GYM_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_CITY_HOUSE2_Border:
	.incbin "data/layouts/PetalburgCityHouse2/border.bin"
gMapLayout_PETALBURG_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/PetalburgCityHouse2/map.bin"
	.globl gMapLayout_PETALBURG_CITY_HOUSE2
gMapLayout_PETALBURG_CITY_HOUSE2: @ 0x08401408
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Border:
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/border.bin"
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Blockdata:
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x084016A0
	.4byte 21  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Border:
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/border.bin"
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Blockdata:
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x084018C0
	.4byte 17  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4018d8, 0x48
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Border:
	.incbin "data/layouts/SlateportCity_PokemonFanClub/border.bin"
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Blockdata:
	.incbin "data/layouts/SlateportCity_PokemonFanClub/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08401A5C
	.4byte 14  @ width
	.4byte 11  @ height
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Border:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/border.bin"
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Blockdata:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08401BE4
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Border:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_2F/border.bin"
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Blockdata:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_2F/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08401D6C
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_HARBOR_Border:
	.incbin "data/layouts/SlateportCityHarbor/border.bin"
gMapLayout_SLATEPORT_CITY_HARBOR_Blockdata:
	.incbin "data/layouts/SlateportCityHarbor/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_HARBOR
gMapLayout_SLATEPORT_CITY_HARBOR: @ 0x0840205C
	.4byte 24  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_GYM_Border:
	.incbin "data/layouts/MauvilleCity_Gym/border.bin"
gMapLayout_MAUVILLE_CITY_GYM_Blockdata:
	.incbin "data/layouts/MauvilleCity_Gym/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_GYM
gMapLayout_MAUVILLE_CITY_GYM: @ 0x08402220
	.4byte 10  @ width
	.4byte 21  @ height
	.4byte gMapLayout_MAUVILLE_CITY_GYM_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Border:
	.incbin "data/layouts/MauvilleCity_BikeShop/border.bin"
gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Blockdata:
	.incbin "data/layouts/MauvilleCity_BikeShop/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_BIKE_SHOP
gMapLayout_MAUVILLE_CITY_BIKE_SHOP: @ 0x08402318
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_GAME_CORNER_Border:
	.incbin "data/layouts/MauvilleCity_GameCorner/border.bin"
gMapLayout_MAUVILLE_CITY_GAME_CORNER_Blockdata:
	.incbin "data/layouts/MauvilleCity_GameCorner/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_GAME_CORNER
gMapLayout_MAUVILLE_CITY_GAME_CORNER: @ 0x0840251C
	.4byte 22  @ width
	.4byte 11  @ height
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_1F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08402694
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_2F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x0840280C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_GYM_Border:
	.incbin "data/layouts/RustboroCity_Gym/border.bin"
gMapLayout_RUSTBORO_CITY_GYM_Blockdata:
	.incbin "data/layouts/RustboroCity_Gym/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_GYM
gMapLayout_RUSTBORO_CITY_GYM: @ 0x084029E4
	.4byte 11  @ width
	.4byte 20  @ height
	.4byte gMapLayout_RUSTBORO_CITY_GYM_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Border:
	.incbin "data/layouts/RustboroCity_PokemonSchool/border.bin"
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Blockdata:
	.incbin "data/layouts/RustboroCity_PokemonSchool/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08402B0C
	.4byte 12  @ width
	.4byte 11  @ height
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_HOUSE2_Border:
	.incbin "data/layouts/RustboroCityHouse2/border.bin"
gMapLayout_RUSTBORO_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/RustboroCityHouse2/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_HOUSE2
gMapLayout_RUSTBORO_CITY_HOUSE2: @ 0x08402C04
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_HOUSE1_Border:
	.incbin "data/layouts/RustboroCity_House1/border.bin"
gMapLayout_RUSTBORO_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/RustboroCity_House1/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_HOUSE1
gMapLayout_RUSTBORO_CITY_HOUSE1: @ 0x08402CF4
	.4byte 13  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Border:
	.incbin "data/layouts/RustboroCity_CuttersHouse/border.bin"
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Blockdata:
	.incbin "data/layouts/RustboroCity_CuttersHouse/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08402DDC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_HOUSE1_Border:
	.incbin "data/layouts/FortreeCity_House1/border.bin"
gMapLayout_FORTREE_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/FortreeCity_House1/map.bin"
	.globl gMapLayout_FORTREE_CITY_HOUSE1
gMapLayout_FORTREE_CITY_HOUSE1: @ 0x08402E5C
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_GYM_Border:
	.incbin "data/layouts/FortreeCity_Gym/border.bin"
gMapLayout_FORTREE_CITY_GYM_Blockdata:
	.incbin "data/layouts/FortreeCity_Gym/map.bin"
	.globl gMapLayout_FORTREE_CITY_GYM
gMapLayout_FORTREE_CITY_GYM: @ 0x08403264
	.4byte 20  @ width
	.4byte 25  @ height
	.4byte gMapLayout_FORTREE_CITY_GYM_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_HOUSE2_Border:
	.incbin "data/layouts/FortreeCity_House2/border.bin"
gMapLayout_FORTREE_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/FortreeCity_House2/map.bin"
	.globl gMapLayout_FORTREE_CITY_HOUSE2
gMapLayout_FORTREE_CITY_HOUSE2: @ 0x084032E4
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Border:
	.incbin "data/layouts/Route104_MrBrineysHouse/border.bin"
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Blockdata:
	.incbin "data/layouts/Route104_MrBrineysHouse/map.bin"
	.globl gMapLayout_ROUTE104_MR_BRINEYS_HOUSE
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE: @ 0x084033DC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Border:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/border.bin"
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08403648
	.4byte 21  @ width
	.4byte 14  @ height
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Border:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_2F/border.bin"
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x084038A4
	.4byte 22  @ width
	.4byte 13  @ height
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Border:
	.incbin "data/layouts/LilycoveCity_ContestLobby/border.bin"
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Blockdata:
	.incbin "data/layouts/LilycoveCity_ContestLobby/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08403BAC
	.4byte 31  @ width
	.4byte 12  @ height
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Border:
	.incbin "data/layouts/LilycoveCity_ContestHall/border.bin"
gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Blockdata:
	.incbin "data/layouts/LilycoveCity_ContestHall/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_HALL
gMapLayout_LILYCOVE_CITY_CONTEST_HALL: @ 0x084048F4
	.4byte 51  @ width
	.4byte 33  @ height
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Border:
	.incbin "data/layouts/LilycoveCity_PokemonTrainerFanClub/border.bin"
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Blockdata:
	.incbin "data/layouts/LilycoveCity_PokemonTrainerFanClub/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x08404A64
	.4byte 12  @ width
	.4byte 14  @ height
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_GYM_Border:
	.incbin "data/layouts/MossdeepCity_Gym/border.bin"
gMapLayout_MOSSDEEP_CITY_GYM_Blockdata:
	.incbin "data/layouts/MossdeepCity_Gym/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GYM
gMapLayout_MOSSDEEP_CITY_GYM: @ 0x084051D4
	.4byte 26  @ width
	.4byte 36  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GYM_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Border:
	.incbin "data/layouts/SootopolisCity_Gym_1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_Gym_1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_1F
gMapLayout_SOOTOPOLIS_CITY_GYM_1F: @ 0x08405568
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Border:
	.incbin "data/layouts/SootopolisCity_Gym_B1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_Gym_B1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_B1F
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F: @ 0x084058FC
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x08405A88
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_PhoebesRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_PhoebesRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x08405C14
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x08405DA0
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x08405F2C
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x084060A0
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL1_Border:
	.incbin "data/layouts/EverGrandeCityHall1/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL1_Blockdata:
	.incbin "data/layouts/EverGrandeCityHall1/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_HALL1
gMapLayout_EVER_GRANDE_CITY_HALL1: @ 0x084061E0
	.4byte 11  @ width
	.4byte 13  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Border:
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/border.bin"
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Blockdata:
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x08406310
	.4byte 15  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Border  @ border
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE112_CABLE_CAR_STATION_Border:
	.incbin "data/layouts/Route112CableCarStation/border.bin"
gMapLayout_ROUTE112_CABLE_CAR_STATION_Blockdata:
	.incbin "data/layouts/Route112CableCarStation/map.bin"
	.globl gMapLayout_ROUTE112_CABLE_CAR_STATION
gMapLayout_ROUTE112_CABLE_CAR_STATION: @ 0x08406468
	.4byte 13  @ width
	.4byte 12  @ height
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION_Border  @ border
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Border:
	.incbin "data/layouts/Route114_FossilManiacsHouse/border.bin"
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Blockdata:
	.incbin "data/layouts/Route114_FossilManiacsHouse/map.bin"
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x08406528
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Border:
	.incbin "data/layouts/Route114_FossilManiacsTunnel/border.bin"
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Blockdata:
	.incbin "data/layouts/Route114_FossilManiacsTunnel/map.bin"
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x084067EC
	.4byte 13  @ width
	.4byte 26  @ height
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Border  @ border
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_LANETTES_HOUSE_Border:
	.incbin "data/layouts/Route114_LanettesHouse/border.bin"
gMapLayout_ROUTE114_LANETTES_HOUSE_Blockdata:
	.incbin "data/layouts/Route114_LanettesHouse/map.bin"
	.globl gMapLayout_ROUTE114_LANETTES_HOUSE
gMapLayout_ROUTE114_LANETTES_HOUSE: @ 0x084068BC
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Border:
	.incbin "data/layouts/Route116_TunnelersRestHouse/border.bin"
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Blockdata:
	.incbin "data/layouts/Route116_TunnelersRestHouse/map.bin"
	.globl gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x08406990
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE117_POKEMON_DAY_CARE_Border:
	.incbin "data/layouts/Route117_PokemonDayCare/border.bin"
gMapLayout_ROUTE117_POKEMON_DAY_CARE_Blockdata:
	.incbin "data/layouts/Route117_PokemonDayCare/map.bin"
	.globl gMapLayout_ROUTE117_POKEMON_DAY_CARE
gMapLayout_ROUTE117_POKEMON_DAY_CARE: @ 0x08406A88
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE_Border  @ border
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Border:
	.incbin "data/layouts/Route121_SafariZoneEntrance/border.bin"
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Blockdata:
	.incbin "data/layouts/Route121_SafariZoneEntrance/map.bin"
	.globl gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x08406CA0
	.4byte 18  @ width
	.4byte 14  @ height
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Border  @ border
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_1F_1R_Border:
	.incbin "data/layouts/MeteorFalls_1F_1R/border.bin"
gMapLayout_METEOR_FALLS_1F_1R_Blockdata:
	.incbin "data/layouts/MeteorFalls_1F_1R/map.bin"
	.globl gMapLayout_METEOR_FALLS_1F_1R
gMapLayout_METEOR_FALLS_1F_1R: @ 0x08407698
	.4byte 30  @ width
	.4byte 42  @ height
	.4byte gMapLayout_METEOR_FALLS_1F_1R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_1F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_1F_2R_Border:
	.incbin "data/layouts/MeteorFalls_1F_2R/border.bin"
gMapLayout_METEOR_FALLS_1F_2R_Blockdata:
	.incbin "data/layouts/MeteorFalls_1F_2R/map.bin"
	.globl gMapLayout_METEOR_FALLS_1F_2R
gMapLayout_METEOR_FALLS_1F_2R: @ 0x08407E38
	.4byte 30  @ width
	.4byte 32  @ height
	.4byte gMapLayout_METEOR_FALLS_1F_2R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_1F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_B1F_1R_Border:
	.incbin "data/layouts/MeteorFalls_B1F_1R/border.bin"
gMapLayout_METEOR_FALLS_B1F_1R_Blockdata:
	.incbin "data/layouts/MeteorFalls_B1F_1R/map.bin"
	.globl gMapLayout_METEOR_FALLS_B1F_1R
gMapLayout_METEOR_FALLS_B1F_1R: @ 0x084086F4
	.4byte 29  @ width
	.4byte 38  @ height
	.4byte gMapLayout_METEOR_FALLS_B1F_1R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_B1F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_B1F_2R_Border:
	.incbin "data/layouts/MeteorFalls_B1F_2R/border.bin"
gMapLayout_METEOR_FALLS_B1F_2R_Blockdata:
	.incbin "data/layouts/MeteorFalls_B1F_2R/map.bin"
	.globl gMapLayout_METEOR_FALLS_B1F_2R
gMapLayout_METEOR_FALLS_B1F_2R: @ 0x084088A0
	.4byte 11  @ width
	.4byte 18  @ height
	.4byte gMapLayout_METEOR_FALLS_B1F_2R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_B1F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_RUSTURF_TUNNEL_Border:
	.incbin "data/layouts/RusturfTunnel/border.bin"
gMapLayout_RUSTURF_TUNNEL_Blockdata:
	.incbin "data/layouts/RusturfTunnel/map.bin"
	.globl gMapLayout_RUSTURF_TUNNEL
gMapLayout_RUSTURF_TUNNEL: @ 0x08408F80
	.4byte 36  @ width
	.4byte 24  @ height
	.4byte gMapLayout_RUSTURF_TUNNEL_Border  @ border
	.4byte gMapLayout_RUSTURF_TUNNEL_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Border:
	.incbin "data/layouts/Underwater_SootopolisCity/border.bin"
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Blockdata:
	.incbin "data/layouts/Underwater_SootopolisCity/map.bin"
	.globl gMapLayout_UNDERWATER_SOOTOPOLIS_CITY
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY: @ 0x08409130
	.4byte 20  @ width
	.4byte 10  @ height
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Border  @ border
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_DESERT_RUINS_Border:
	.incbin "data/layouts/DesertRuins/border.bin"
gMapLayout_DESERT_RUINS_Blockdata:
	.incbin "data/layouts/DesertRuins/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_DESERT_RUINS
gMapLayout_DESERT_RUINS: @ 0x084095B4
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte gMapLayout_DESERT_RUINS_Border  @ border
	.4byte gMapLayout_DESERT_RUINS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_1F_Border:
	.incbin "data/layouts/GraniteCave_1F/border.bin"
gMapLayout_GRANITE_CAVE_1F_Blockdata:
	.incbin "data/layouts/GraniteCave_1F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_1F
gMapLayout_GRANITE_CAVE_1F: @ 0x08409AC0
	.4byte 42  @ width
	.4byte 15  @ height
	.4byte gMapLayout_GRANITE_CAVE_1F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_B1F_Border:
	.incbin "data/layouts/GraniteCave_B1F/border.bin"
gMapLayout_GRANITE_CAVE_B1F_Blockdata:
	.incbin "data/layouts/GraniteCave_B1F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_B1F
gMapLayout_GRANITE_CAVE_B1F: @ 0x0840A160
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte gMapLayout_GRANITE_CAVE_B1F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_B2F_Border:
	.incbin "data/layouts/GraniteCave_B2F/border.bin"
gMapLayout_GRANITE_CAVE_B2F_Blockdata:
	.incbin "data/layouts/GraniteCave_B2F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_B2F
gMapLayout_GRANITE_CAVE_B2F: @ 0x0840A800
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte gMapLayout_GRANITE_CAVE_B2F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_B2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_WOODS_Border:
	.incbin "data/layouts/PetalburgWoods/border.bin"
gMapLayout_PETALBURG_WOODS_Blockdata:
	.incbin "data/layouts/PetalburgWoods/map.bin"
	.globl gMapLayout_PETALBURG_WOODS
gMapLayout_PETALBURG_WOODS: @ 0x0840B8A0
	.4byte 48  @ width
	.4byte 44  @ height
	.4byte gMapLayout_PETALBURG_WOODS_Border  @ border
	.4byte gMapLayout_PETALBURG_WOODS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MT_CHIMNEY_Border:
	.incbin "data/layouts/MtChimney/border.bin"
gMapLayout_MT_CHIMNEY_Blockdata:
	.incbin "data/layouts/MtChimney/map.bin"
	.globl gMapLayout_MT_CHIMNEY
gMapLayout_MT_CHIMNEY: @ 0x0840C770
	.4byte 40  @ width
	.4byte 47  @ height
	.4byte gMapLayout_MT_CHIMNEY_Border  @ border
	.4byte gMapLayout_MT_CHIMNEY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_1F_Border:
	.incbin "data/layouts/MtPyre_1F/border.bin"
gMapLayout_MT_PYRE_1F_Blockdata:
	.incbin "data/layouts/MtPyre_1F/map.bin"
	.globl gMapLayout_MT_PYRE_1F
gMapLayout_MT_PYRE_1F: @ 0x0840CAD4
	.4byte 22  @ width
	.4byte 19  @ height
	.4byte gMapLayout_MT_PYRE_1F_Border  @ border
	.4byte gMapLayout_MT_PYRE_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_2F_Border:
	.incbin "data/layouts/MtPyre_2F/border.bin"
gMapLayout_MT_PYRE_2F_Blockdata:
	.incbin "data/layouts/MtPyre_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_2F
gMapLayout_MT_PYRE_2F: @ 0x0840CC48
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_2F_Border  @ border
	.4byte gMapLayout_MT_PYRE_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_3F_Border:
	.incbin "data/layouts/MtPyre_3F/border.bin"
gMapLayout_MT_PYRE_3F_Blockdata:
	.incbin "data/layouts/MtPyre_3F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_3F
gMapLayout_MT_PYRE_3F: @ 0x0840CDBC
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_3F_Border  @ border
	.4byte gMapLayout_MT_PYRE_3F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_4F_Border:
	.incbin "data/layouts/MtPyre_4F/border.bin"
gMapLayout_MT_PYRE_4F_Blockdata:
	.incbin "data/layouts/MtPyre_4F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_4F
gMapLayout_MT_PYRE_4F: @ 0x0840CF30
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_4F_Border  @ border
	.4byte gMapLayout_MT_PYRE_4F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_5F_Border:
	.incbin "data/layouts/MtPyre_5F/border.bin"
gMapLayout_MT_PYRE_5F_Blockdata:
	.incbin "data/layouts/MtPyre_5F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_5F
gMapLayout_MT_PYRE_5F: @ 0x0840D0A4
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_5F_Border  @ border
	.4byte gMapLayout_MT_PYRE_5F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_6F_Border:
	.incbin "data/layouts/MtPyre_6F/border.bin"
gMapLayout_MT_PYRE_6F_Blockdata:
	.incbin "data/layouts/MtPyre_6F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_6F
gMapLayout_MT_PYRE_6F: @ 0x0840D218
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_6F_Border  @ border
	.4byte gMapLayout_MT_PYRE_6F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_1F_Border:
	.incbin "data/layouts/AquaHideout_1F/border.bin"
gMapLayout_AQUA_HIDEOUT_1F_Blockdata:
	.incbin "data/layouts/AquaHideout_1F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_1F
gMapLayout_AQUA_HIDEOUT_1F: @ 0x0840D8C8
	.4byte 28  @ width
	.4byte 30  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_1F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_B1F_Border:
	.incbin "data/layouts/AquaHideout_B1F/border.bin"
gMapLayout_AQUA_HIDEOUT_B1F_Blockdata:
	.incbin "data/layouts/AquaHideout_B1F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_B1F
gMapLayout_AQUA_HIDEOUT_B1F: @ 0x0840E278
	.4byte 51  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_B1F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_B2F_Border:
	.incbin "data/layouts/AquaHideout_B2F/border.bin"
gMapLayout_AQUA_HIDEOUT_B2F_Blockdata:
	.incbin "data/layouts/AquaHideout_B2F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_B2F
gMapLayout_AQUA_HIDEOUT_B2F: @ 0x0840E8F8
	.4byte 34  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_B2F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_B2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Border:
	.incbin "data/layouts/Underwater_SeafloorCavern/border.bin"
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Blockdata:
	.incbin "data/layouts/Underwater_SeafloorCavern/map.bin"
	.globl gMapLayout_UNDERWATER_SEAFLOOR_CAVERN
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0840EA14
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Border  @ border
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Border:
	.incbin "data/layouts/SeafloorCavern_Entrance/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Entrance/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ENTRANCE
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0840ED54
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM1_Border:
	.incbin "data/layouts/SeafloorCavern_Room1/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM1_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room1/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM1
gMapLayout_SEAFLOOR_CAVERN_ROOM1: @ 0x0840F0BC
	.4byte 20  @ width
	.4byte 21  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM2_Border:
	.incbin "data/layouts/SeafloorCavern_Room2/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM2_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room2/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM2
gMapLayout_SEAFLOOR_CAVERN_ROOM2: @ 0x0840F28C
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM3_Border:
	.incbin "data/layouts/SeafloorCavern_Room3/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM3_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room3/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM3
gMapLayout_SEAFLOOR_CAVERN_ROOM3: @ 0x0840F4CC
	.4byte 16  @ width
	.4byte 17  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM4_Border:
	.incbin "data/layouts/SeafloorCavern_Room4/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM4_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room4/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM4
gMapLayout_SEAFLOOR_CAVERN_ROOM4: @ 0x0840F798
	.4byte 18  @ width
	.4byte 19  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x40f7b0, 0x1184c
gMapLayout_FORTREE_CITY_DECORATION_SHOP_Border:
	.incbin "data/layouts/FortreeCity_DecorationShop/border.bin"
gMapLayout_FORTREE_CITY_DECORATION_SHOP_Blockdata:
	.incbin "data/layouts/FortreeCity_DecorationShop/map.bin"
	.globl gMapLayout_FORTREE_CITY_DECORATION_SHOP
gMapLayout_FORTREE_CITY_DECORATION_SHOP: @ 0x08421064
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42107c, 0xd4
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_1F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x08421278
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x084213B8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_3F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_3F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x084214F8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_4F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_4F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x08421638
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_5F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_5F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x08421778
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x08421948
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE130_Border:
	.incbin "data/layouts/Route130/border.bin"
gMapLayout_ROUTE130_Blockdata:
	.incbin "data/layouts/Route130/map.bin"
	.globl gMapLayout_ROUTE130
gMapLayout_ROUTE130: @ 0x08423268
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE130_Border  @ border
	.4byte gMapLayout_ROUTE130_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x423280, 0x23bc
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x0842579C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Border:
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/border.bin"
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Blockdata:
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x08425984
	.4byte 19  @ width
	.4byte 12  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42599c, 0x400
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x08425DE0
	.4byte 5  @ width
	.4byte 6  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE124_Border:
	.incbin "data/layouts/Underwater_Route124/border.bin"
gMapLayout_UNDERWATER_ROUTE124_Blockdata:
	.incbin "data/layouts/Underwater_Route124/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE124
gMapLayout_UNDERWATER_ROUTE124: @ 0x08429000
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE124_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE124_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Border:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_1F/border.bin"
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x08429160
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Border:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/border.bin"
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Blockdata:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x084292C0
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4292d8, 0x3684
gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Border:
	.incbin "data/layouts/GraniteCave_StevensRoom/border.bin"
gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Blockdata:
	.incbin "data/layouts/GraniteCave_StevensRoom/map.bin"
	.globl gMapLayout_GRANITE_CAVE_STEVENS_ROOM
gMapLayout_GRANITE_CAVE_STEVENS_ROOM: @ 0x0842CB08
	.4byte 15  @ width
	.4byte 14  @ height
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42cb20, 0xe4c
gMapLayout_JAGGED_PASS_Border:
	.incbin "data/layouts/JaggedPass/border.bin"
gMapLayout_JAGGED_PASS_Blockdata:
	.incbin "data/layouts/JaggedPass/map.bin"
	.globl gMapLayout_JAGGED_PASS
gMapLayout_JAGGED_PASS: @ 0x0842E43C
	.4byte 30  @ width
	.4byte 46  @ height
	.4byte gMapLayout_JAGGED_PASS_Border  @ border
	.4byte gMapLayout_JAGGED_PASS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_FIERY_PATH_Border:
	.incbin "data/layouts/FieryPath/border.bin"
gMapLayout_FIERY_PATH_Blockdata:
	.incbin "data/layouts/FieryPath/map.bin"
	.globl gMapLayout_FIERY_PATH
gMapLayout_FIERY_PATH: @ 0x0842EEC0
	.4byte 35  @ width
	.4byte 38  @ height
	.4byte gMapLayout_FIERY_PATH_Border  @ border
	.4byte gMapLayout_FIERY_PATH_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_1F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_1F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_1F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_1F
gMapLayout_RUSTBORO_CITY_FLAT2_1F: @ 0x0842EFDC
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_2F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_2F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_2F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_2F
gMapLayout_RUSTBORO_CITY_FLAT2_2F: @ 0x0842F0F8
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_3F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_3F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_3F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_3F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_3F
gMapLayout_RUSTBORO_CITY_FLAT2_3F: @ 0x0842F214
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Border:
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/border.bin"
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Blockdata:
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0842F2A4
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Border:
	.incbin "data/layouts/EverGrandeCity_HallOfFame/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Blockdata:
	.incbin "data/layouts/EverGrandeCity_HallOfFame/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0842F4C4
	.4byte 15  @ width
	.4byte 17  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Border:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_1F/border.bin"
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x0842F5BC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Border:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_2F/border.bin"
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x0842F6B4
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42f6cc, 0xd4
gMapLayout_MT_PYRE_EXTERIOR_Border:
	.incbin "data/layouts/MtPyre_Exterior/border.bin"
gMapLayout_MT_PYRE_EXTERIOR_Blockdata:
	.incbin "data/layouts/MtPyre_Exterior/map.bin"
	.globl gMapLayout_MT_PYRE_EXTERIOR
gMapLayout_MT_PYRE_EXTERIOR: @ 0x084306CC
	.4byte 38  @ width
	.4byte 51  @ height
	.4byte gMapLayout_MT_PYRE_EXTERIOR_Border  @ border
	.4byte gMapLayout_MT_PYRE_EXTERIOR_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_SUMMIT_Border:
	.incbin "data/layouts/MtPyre_Summit/border.bin"
gMapLayout_MT_PYRE_SUMMIT_Blockdata:
	.incbin "data/layouts/MtPyre_Summit/map.bin"
	.globl gMapLayout_MT_PYRE_SUMMIT
gMapLayout_MT_PYRE_SUMMIT: @ 0x08431560
	.4byte 50  @ width
	.4byte 37  @ height
	.4byte gMapLayout_MT_PYRE_SUMMIT_Border  @ border
	.4byte gMapLayout_MT_PYRE_SUMMIT_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431578, 0x3e8
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Border:
	.incbin "data/layouts/MossdeepCity_GameCorner_1F/border.bin"
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_GameCorner_1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x08431A58
	.4byte 12  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Border:
	.incbin "data/layouts/MossdeepCity_GameCorner_B1F/border.bin"
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_GameCorner_B1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x08431B50
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Border:
	.incbin "data/layouts/SootopolisCity_House1/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/SootopolisCity_House1/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE1
gMapLayout_SOOTOPOLIS_CITY_HOUSE1: @ 0x08431BE0
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Border:
	.incbin "data/layouts/SootopolisCity_House2/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/SootopolisCity_House2/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE2
gMapLayout_SOOTOPOLIS_CITY_HOUSE2: @ 0x08431C70
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Border:
	.incbin "data/layouts/SootopolisCity_House3/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Blockdata:
	.incbin "data/layouts/SootopolisCity_House3/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE3
gMapLayout_SOOTOPOLIS_CITY_HOUSE3: @ 0x08431D00
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x431d18, 0xab4
gMapLayout_RUSTBORO_CITY_FLAT1_1F_Border:
	.incbin "data/layouts/RustboroCity_Flat1_1F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT1_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat1_1F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_1F
gMapLayout_RUSTBORO_CITY_FLAT1_1F: @ 0x084328B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT1_2F_Border:
	.incbin "data/layouts/RustboroCity_Flat1_2F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT1_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat1_2F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_2F
gMapLayout_RUSTBORO_CITY_FLAT1_2F: @ 0x084329B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL4_Border:
	.incbin "data/layouts/EverGrandeCity_Hall4/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL4_Blockdata:
	.incbin "data/layouts/EverGrandeCity_Hall4/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_HALL4
gMapLayout_EVER_GRANDE_CITY_HALL4: @ 0x08432CC0
	.4byte 11  @ width
	.4byte 34  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x432cd8, 0x4414
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Border:
	.incbin "data/layouts/MossdeepCity_StevensHouse/border.bin"
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Blockdata:
	.incbin "data/layouts/MossdeepCity_StevensHouse/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x084371A4
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4371bc, 0xd15c
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Border:
	.incbin "data/layouts/FallarborTownBattleTentLobby/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentLobby/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08444424
	.4byte 13  @ width
	.4byte 10  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Border:
	.incbin "data/layouts/FallarborTownBattleTentCorridor/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentCorridor/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08444494
	.4byte 5  @ width
	.4byte 8  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Border:
	.incbin "data/layouts/FallarborTownBattleTentBattleRoom/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentBattleRoom/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444568
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Border:
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/border.bin"
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata:
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444674
	.4byte 13  @ width
	.4byte 9  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44468c, 0xaf64
gMapLayout_UNDERWATER_ROUTE105_Border:
	.incbin "data/layouts/Underwater_Route105/border.bin"
gMapLayout_UNDERWATER_ROUTE105_Blockdata:
	.incbin "data/layouts/Underwater_Route105/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE105
gMapLayout_UNDERWATER_ROUTE105: @ 0x08450EF8
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE105_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE105_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE125_Border:
	.incbin "data/layouts/Underwater_Route125/border.bin"
gMapLayout_UNDERWATER_ROUTE125_Blockdata:
	.incbin "data/layouts/Underwater_Route125/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE125
gMapLayout_UNDERWATER_ROUTE125: @ 0x08452818
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE125_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE125_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE129_Border:
	.incbin "data/layouts/Underwater_Route129/border.bin"
gMapLayout_UNDERWATER_ROUTE129_Blockdata:
	.incbin "data/layouts/Underwater_Route129/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE129
gMapLayout_UNDERWATER_ROUTE129: @ 0x08454138
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE129_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE129_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x454150, 0x5e0c
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Border:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0845A014
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Border:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0845A10C
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Blockdata  @ map
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
	.4byte Route110_MapEvents  @ events
	.4byte Route110_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE110  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001A  @ mapLayoutId
	.byte 0x19, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE111 (g0 m26)
	.4byte gMapLayout_ROUTE111  @ mapLayout
	.4byte Route111_MapEvents  @ events
	.4byte Route111_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE111  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001B  @ mapLayoutId
	.byte 0x1A, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE112 (g0 m27)
	.4byte gMapLayout_ROUTE112  @ mapLayout
	.4byte Route112_MapEvents  @ events
	.4byte Route112_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE112  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001C  @ mapLayoutId
	.byte 0x1B, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE113 (g0 m28)
	.4byte gMapLayout_ROUTE113  @ mapLayout
	.4byte Route113_MapEvents  @ events
	.4byte Route113_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE113  @ connections
	.2byte 0x01A2  @ music
	.2byte 0x001D  @ mapLayoutId
	.byte 0x1C, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE114 (g0 m29)
	.4byte gMapLayout_ROUTE114  @ mapLayout
	.4byte Route114_MapEvents  @ events
	.4byte Route114_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE114  @ connections
	.2byte 0x0168  @ music
	.2byte 0x001E  @ mapLayoutId
	.byte 0x1D, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE115 (g0 m30)
	.4byte gMapLayout_ROUTE115  @ mapLayout
	.4byte Route115_MapEvents  @ events
	.4byte Route115_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE115  @ connections
	.2byte 0x0191  @ music
	.2byte 0x001F  @ mapLayoutId
	.byte 0x1E, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE116 (g0 m31)
	.4byte gMapLayout_ROUTE116  @ mapLayout
	.4byte Route116_MapEvents  @ events
	.4byte Route116_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE116  @ connections
	.2byte 0x0191  @ music
	.2byte 0x0020  @ mapLayoutId
	.byte 0x1F, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE117 (g0 m32)
	.4byte gMapLayout_ROUTE117  @ mapLayout
	.4byte Route117_MapEvents  @ events
	.4byte Route117_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE117  @ connections
	.2byte 0x0168  @ music
	.2byte 0x0021  @ mapLayoutId
	.byte 0x20, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE118 (g0 m33)
	.4byte gMapLayout_ROUTE118  @ mapLayout
	.4byte Route118_MapEvents  @ events
	.4byte Route118_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE118  @ connections
	.2byte 0x7FFF  @ music
	.2byte 0x0022  @ mapLayoutId
	.byte 0x21, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE119 (g0 m34)
	.4byte gMapLayout_ROUTE119  @ mapLayout
	.4byte Route119_MapEvents  @ events
	.4byte Route119_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE119  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0023  @ mapLayoutId
	.byte 0x22, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE120 (g0 m35)
	.4byte gMapLayout_ROUTE120  @ mapLayout
	.4byte Route120_MapEvents  @ events
	.4byte Route120_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE120  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0024  @ mapLayoutId
	.byte 0x23, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE121 (g0 m36)
	.4byte gMapLayout_ROUTE121  @ mapLayout
	.4byte Route121_MapEvents  @ events
	.4byte Route121_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE121  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0025  @ mapLayoutId
	.byte 0x24, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE122 (g0 m37)
	.4byte gMapLayout_ROUTE122  @ mapLayout
	.4byte Route122_MapEvents  @ events
	.4byte Route122_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE122  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0026  @ mapLayoutId
	.byte 0x25, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE123 (g0 m38)
	.4byte gMapLayout_ROUTE123  @ mapLayout
	.4byte Route123_MapEvents  @ events
	.4byte Route123_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE123  @ connections
	.2byte 0x0176  @ music
	.2byte 0x0027  @ mapLayoutId
	.byte 0x26, 0x00, 0x02, 0x03, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE124 (g0 m39)
	.4byte gMapLayout_ROUTE124  @ mapLayout
	.4byte Route124_MapEvents  @ events
	.4byte Route124_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE124  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0028  @ mapLayoutId
	.byte 0x27, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE125 (g0 m40)
	.4byte gMapLayout_ROUTE125  @ mapLayout
	.4byte Route125_MapEvents  @ events
	.4byte Route125_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE125  @ connections
	.2byte 0x0169  @ music
	.2byte 0x0029  @ mapLayoutId
	.byte 0x28, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE126 (g0 m41)
	.4byte gMapLayout_ROUTE126  @ mapLayout
	.4byte Route126_MapEvents  @ events
	.4byte Route126_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE126  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002A  @ mapLayoutId
	.byte 0x29, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE127 (g0 m42)
	.4byte gMapLayout_ROUTE127  @ mapLayout
	.4byte Route127_MapEvents  @ events
	.4byte Route127_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE127  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002B  @ mapLayoutId
	.byte 0x2A, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE128 (g0 m43)
	.4byte gMapLayout_ROUTE128  @ mapLayout
	.4byte Route128_MapEvents  @ events
	.4byte Route128_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE128  @ connections
	.2byte 0x0169  @ music
	.2byte 0x002C  @ mapLayoutId
	.byte 0x2B, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE129 (g0 m44)
	.4byte gMapLayout_ROUTE129  @ mapLayout
	.4byte Route129_MapEvents  @ events
	.4byte Route129_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE129  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002D  @ mapLayoutId
	.byte 0x2C, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE130 (g0 m45)
	.4byte gMapLayout_ROUTE130  @ mapLayout
	.4byte Route130_MapEvents  @ events
	.4byte Route130_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE130  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0107  @ mapLayoutId
	.byte 0x2D, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE131 (g0 m46)
	.4byte gMapLayout_ROUTE131  @ mapLayout
	.4byte Route131_MapEvents  @ events
	.4byte Route131_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE131  @ connections
	.2byte 0x0192  @ music
	.2byte 0x002F  @ mapLayoutId
	.byte 0x2E, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE132 (g0 m47)
	.4byte gMapLayout_ROUTE132  @ mapLayout
	.4byte Route132_MapEvents  @ events
	.4byte Route132_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE132  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0030  @ mapLayoutId
	.byte 0x2F, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE133 (g0 m48)
	.4byte gMapLayout_ROUTE133  @ mapLayout
	.4byte Route133_MapEvents  @ events
	.4byte Route133_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE133  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0031  @ mapLayoutId
	.byte 0x30, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_ROUTE134 (g0 m49)
	.4byte gMapLayout_ROUTE134  @ mapLayout
	.4byte Route134_MapEvents  @ events
	.4byte Route134_MapScripts  @ mapScripts
	.4byte gMapConnections_ROUTE134  @ connections
	.2byte 0x0192  @ music
	.2byte 0x0032  @ mapLayoutId
	.byte 0x31, 0x00, 0x02, 0x06, 0x00, 0x00, 0x0D, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_UNDERWATER_ROUTE124 (g0 m50)
	.include "data/maps/Underwater_Route124/header.inc"
	@ MAP_UNDERWATER_ROUTE126 (g0 m51)
	.include "data/maps/Underwater_Route126/header.inc"
	@ MAP_UNDERWATER_ROUTE127 (g0 m52)
	.include "data/maps/Underwater_Route127/header.inc"
	@ MAP_UNDERWATER_ROUTE128 (g0 m53)
	.include "data/maps/Underwater_Route128/header.inc"
	@ MAP_UNDERWATER_ROUTE129 (g0 m54)
	.include "data/maps/Underwater_Route129/header.inc"
	@ MAP_UNDERWATER_ROUTE105 (g0 m55)
	.include "data/maps/Underwater_Route105/header.inc"
	@ MAP_UNDERWATER_ROUTE125 (g0 m56)
	.include "data/maps/Underwater_Route125/header.inc"
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F (g1 m0)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F  @ mapLayout
	.4byte LittlerootTown_BrendansHouse_1F_MapEvents  @ events
	.4byte LittlerootTown_BrendansHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0036  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F (g1 m1)
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F  @ mapLayout
	.4byte LittlerootTown_BrendansHouse_2F_MapEvents  @ events
	.4byte LittlerootTown_BrendansHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0037  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F (g1 m2)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F  @ mapLayout
	.4byte LittlerootTown_MaysHouse_1F_MapEvents  @ events
	.4byte LittlerootTown_MaysHouse_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0038  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F (g1 m3)
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F  @ mapLayout
	.4byte LittlerootTown_MaysHouse_2F_MapEvents  @ events
	.4byte LittlerootTown_MaysHouse_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0195  @ music
	.2byte 0x0039  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB (g1 m4)
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB  @ mapLayout
	.4byte LittlerootTown_ProfessorBirchsLab_MapEvents  @ events
	.4byte LittlerootTown_ProfessorBirchsLab_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x017F  @ music
	.2byte 0x003A  @ mapLayoutId
	.byte 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE1 (g2 m0)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte OldaleTown_House1_MapEvents  @ events
	.4byte 0x081F28D3  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003B  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_HOUSE2 (g2 m1)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte OldaleTown_House2_MapEvents  @ events
	.4byte 0x081F2949  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x016B  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_1F (g2 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte OldaleTown_PokemonCenter_1F_MapEvents  @ events
	.4byte OldaleTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_POKEMON_CENTER_2F (g2 m3)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte OldaleTown_PokemonCenter_2F_MapEvents  @ events
	.4byte OldaleTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_OLDALE_TOWN_MART (g2 m4)
	.4byte gMapLayout_OLDALE_TOWN_MART  @ mapLayout
	.4byte OldaleTown_Mart_MapEvents  @ events
	.4byte OldaleTown_Mart_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0194  @ music
	.2byte 0x003F  @ mapLayoutId
	.byte 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_HOUSE1 (g3 m0)
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1  @ mapLayout
	.4byte DewfordTown_House1_MapEvents  @ events
	.4byte DewfordTown_House1_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AB  @ music
	.2byte 0x0040  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_1F (g3 m1)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F  @ mapLayout
	.4byte DewfordTown_PokemonCenter_1F_MapEvents  @ events
	.4byte DewfordTown_PokemonCenter_1F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003D  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_POKEMON_CENTER_2F (g3 m2)
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F  @ mapLayout
	.4byte DewfordTown_PokemonCenter_2F_MapEvents  @ events
	.4byte DewfordTown_PokemonCenter_2F_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x0190  @ music
	.2byte 0x003E  @ mapLayoutId
	.byte 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_DEWFORD_TOWN_GYM (g3 m3)
	.4byte gMapLayout_DEWFORD_TOWN_GYM  @ mapLayout
	.4byte DewfordTown_Gym_MapEvents  @ events
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
	.4byte SlateportCity_House_MapScripts  @ mapScripts
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
	.4byte SlateportCity_Mart_MapScripts  @ mapScripts
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
	.4byte MauvilleCity_BikeShop_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x005A  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE1 (g10 m2)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE1  @ events
	.4byte MauvilleCity_House1_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x018F  @ music
	.2byte 0x003C  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_GAME_CORNER (g10 m3)
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_GAME_CORNER  @ events
	.4byte MauvilleCity_GameCorner_MapScripts  @ mapScripts
	.4byte 0x00000000  @ connections
	.2byte 0x01AA  @ music
	.2byte 0x005B  @ mapLayoutId
	.byte 0x09, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00  @ regionMapSectionId, cave, weather, mapType, filler[2], flags, battleType
	@ MAP_MAUVILLE_CITY_HOUSE2 (g10 m4)
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1  @ mapLayout
	.4byte gMapEvents_MAUVILLE_CITY_HOUSE2  @ events
	.4byte MauvilleCity_House2_MapScripts  @ mapScripts
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
	.globl gMapGroups
	.set gMapGroups, gUnknown_845E998
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
	@ 0x0845F144: Underwater_Route105 connection list and header.
	.include "data/maps/Underwater_Route105/connections.inc"
	@ 0x0845F158: Underwater_Route124 connection list and header.
	.include "data/maps/Underwater_Route124/connections.inc"
	@ 0x0845F178: Underwater_Route125 connection list and header.
	.include "data/maps/Underwater_Route125/connections.inc"
	@ 0x0845F18C: Underwater_Route126 connection list and header.
	.include "data/maps/Underwater_Route126/connections.inc"
	@ 0x0845F1B8: Underwater_Route127 connection list and header.
	.include "data/maps/Underwater_Route127/connections.inc"
	@ 0x0845F1E4: Underwater_Route128 connection list and header.
	.include "data/maps/Underwater_Route128/connections.inc"
	@ 0x0845F204: Underwater_Route129 connection list and header.
	.include "data/maps/Underwater_Route129/connections.inc"
	.incbin "baserom_jp.gba", 0x45F218, 0x100

	.globl sDummyConnectionFlags
sDummyConnectionFlags: @ 0x845F318
	.incbin "baserom_jp.gba", 0x45f318, 0x4

	.globl sTileBitAttributes
sTileBitAttributes: @ 0x845F31C
	.incbin "graphics/misc/sTileBitAttributes.bin"

	.globl sDoorOpenAnimFrames
sDoorOpenAnimFrames: @ 0x846F3AC
	.incbin "graphics/misc/sDoorOpenAnimFrames.bin"

	.globl sDoorCloseAnimFrames
sDoorCloseAnimFrames: @ 0x846F3C0
	.incbin "graphics/misc/sDoorCloseAnimFrames.bin"

	.globl sBigDoorOpenAnimFrames
sBigDoorOpenAnimFrames: @ 0x846F3D4
	.incbin "graphics/misc/sBigDoorOpenAnimFrames.bin"

	.globl sDoorAnimGraphicsTable
sDoorAnimGraphicsTable: @ 0x846F594
	.hword 0x0021
	.byte 0x00, 0x01
	.4byte 0x084603AC, 0x0846F3FC
	.hword 0x0061
	.byte 0x01, 0x01
	.4byte 0x084606CC, 0x0846F404
	.hword 0x01CD
	.byte 0x01, 0x01
	.4byte 0x084609CC, 0x0846F40C
	.hword 0x0041
	.byte 0x01, 0x01
	.4byte 0x08460CCC, 0x0846F414
	.hword 0x0248
	.byte 0x00, 0x01
	.4byte 0x0845F40C, 0x0846F41C
	.hword 0x0249
	.byte 0x00, 0x01
	.4byte 0x0845F72C, 0x0846F424
	.hword 0x022F
	.byte 0x00, 0x01
	.4byte 0x08460FCC, 0x0846F42C
	.hword 0x021F
	.byte 0x00, 0x01
	.4byte 0x084612EC, 0x0846F434
	.hword 0x02A5
	.byte 0x00, 0x01
	.4byte 0x0845FA4C, 0x0846F43C
	.hword 0x0287
	.byte 0x00, 0x01
	.4byte 0x0846160C, 0x0846F44C
	.hword 0x02AC
	.byte 0x00, 0x01
	.4byte 0x084674EC, 0x0846F48C
	.hword 0x03A1
	.byte 0x00, 0x01
	.4byte 0x0846780C, 0x0846F494
	.hword 0x02DC
	.byte 0x00, 0x01
	.4byte 0x08467B2C, 0x0846F484
	.hword 0x0225
	.byte 0x00, 0x01
	.4byte 0x08467E4C, 0x0846F47C
	.hword 0x01DB
	.byte 0x01, 0x01
	.4byte 0x0846816C, 0x0846F4A4
	.hword 0x0246
	.byte 0x00, 0x01
	.4byte 0x0845FD6C, 0x0846F444
	.hword 0x028E
	.byte 0x00, 0x01
	.4byte 0x0846008C, 0x0846F49C
	.hword 0x02A1
	.byte 0x00, 0x01
	.4byte 0x0846848C, 0x0846F454
	.hword 0x021C
	.byte 0x00, 0x01
	.4byte 0x084687AC, 0x0846F46C
	.hword 0x021E
	.byte 0x00, 0x01
	.4byte 0x08468ACC, 0x0846F474
	.hword 0x021D
	.byte 0x01, 0x01
	.4byte 0x08468DEC, 0x0846F45C
	.hword 0x021A
	.byte 0x00, 0x01
	.4byte 0x0846910C, 0x0846F464
	.hword 0x0224
	.byte 0x00, 0x01
	.4byte 0x0846942C, 0x0846F4AC
	.hword 0x0289
	.byte 0x00, 0x01
	.4byte 0x0846974C, 0x0846F4B4
	.hword 0x030C
	.byte 0x01, 0x01
	.4byte 0x08469A6C, 0x0846F4BC
	.hword 0x032D
	.byte 0x01, 0x01
	.4byte 0x08469D8C, 0x0846F4C4
	.hword 0x02ED
	.byte 0x01, 0x01
	.4byte 0x0846A0AC, 0x0846F4CC
	.hword 0x0264
	.byte 0x01, 0x01
	.4byte 0x0846A3CC, 0x0846F4D4
	.hword 0x022B
	.byte 0x00, 0x01
	.4byte 0x0846A6EC, 0x0846F4DC
	.hword 0x02F7
	.byte 0x00, 0x01
	.4byte 0x0846AA0C, 0x0846F4E4
	.hword 0x0297
	.byte 0x00, 0x01
	.4byte 0x0846AD2C, 0x0846F4EC
	.hword 0x0285
	.byte 0x01, 0x01
	.4byte 0x0846B04C, 0x0846F4F4
	.hword 0x025D
	.byte 0x01, 0x01
	.4byte 0x0846B36C, 0x0846F4FC
	.hword 0x020E
	.byte 0x01, 0x01
	.4byte 0x0846B68C, 0x0846F504
	.hword 0x03B0
	.byte 0x01, 0x01
	.4byte 0x0846B9AC, 0x0846F50C
	.hword 0x028A
	.byte 0x01, 0x01
	.4byte 0x0846BCCC, 0x0846F514
	.hword 0x0263
	.byte 0x01, 0x01
	.4byte 0x0846BFEC, 0x0846F51C
	.hword 0x0329
	.byte 0x01, 0x01
	.4byte 0x0846C30C, 0x0846F524
	.hword 0x0291
	.byte 0x00, 0x01
	.4byte 0x0846C62C, 0x0846F52C
	.hword 0x021B
	.byte 0x02, 0x01
	.4byte 0x0846C94C, 0x0846F534
	.hword 0x0209
	.byte 0x01, 0x01
	.4byte 0x0846CC6C, 0x0846F53C
	.hword 0x0219
	.byte 0x00, 0x01
	.4byte 0x0846CF8C, 0x0846F544
	.hword 0x0393
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x03D4
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x036C
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x025E
	.byte 0x01, 0x01
	.4byte 0x0846D6AC, 0x0846F554
	.hword 0x02AD
	.byte 0x01, 0x02
	.4byte 0x0846D9CC, 0x0846F55C
	.hword 0x03FC
	.byte 0x00, 0x01
	.4byte 0x0846DFEC, 0x0846F56C
	.hword 0x0396
	.byte 0x01, 0x01
	.4byte 0x0846E30C, 0x0846F56C
	.hword 0x020A
	.byte 0x01, 0x01
	.4byte 0x0846E62C, 0x0846F574
	.hword 0x026B
	.byte 0x01, 0x01
	.4byte 0x0846E94C, 0x0846F57C
	.hword 0x032C
	.byte 0x01, 0x01
	.4byte 0x0846ED6C, 0x0846F584
	.hword 0x0383
	.byte 0x01, 0x01
	.4byte 0x0846F08C, 0x0846F58C
	.hword 0x0000
	.byte 0x00, 0x00
	.4byte 0x00000000, 0x00000000

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.4byte MetatileBehavior_IsTrickHouseSlipperyFloor + 1, MetatileBehavior_IsIce + 1, MetatileBehavior_IsWalkSouth + 1, MetatileBehavior_IsWalkNorth + 1
	.4byte MetatileBehavior_IsWalkWest + 1, MetatileBehavior_IsWalkEast + 1, MetatileBehavior_IsSouthwardCurrent + 1, MetatileBehavior_IsNorthwardCurrent + 1
	.4byte MetatileBehavior_IsWestwardCurrent + 1, MetatileBehavior_IsEastwardCurrent + 1, MetatileBehavior_IsSlideSouth + 1, MetatileBehavior_IsSlideNorth + 1
	.4byte MetatileBehavior_IsSlideWest + 1, MetatileBehavior_IsSlideEast + 1, MetatileBehavior_IsWaterfall + 1, MetatileBehavior_IsSecretBaseJumpMat + 1
	.4byte MetatileBehavior_IsSecretBaseSpinMat + 1, MetatileBehavior_IsMuddySlope + 1

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.4byte ForcedMovement_None + 1, ForcedMovement_Slip + 1, ForcedMovement_Slip + 1, ForcedMovement_WalkSouth + 1
	.4byte ForcedMovement_WalkNorth + 1, ForcedMovement_WalkWest + 1, ForcedMovement_WalkEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_PushedNorthByCurrent + 1, ForcedMovement_PushedWestByCurrent + 1, ForcedMovement_PushedEastByCurrent + 1, ForcedMovement_SlideSouth + 1
	.4byte ForcedMovement_SlideNorth + 1, ForcedMovement_SlideWest + 1, ForcedMovement_SlideEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_MatJump + 1, ForcedMovement_MatSpin + 1, ForcedMovement_MuddySlope + 1

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.4byte PlayerNotOnBikeNotMoving + 1, PlayerNotOnBikeTurningInPlace + 1, PlayerNotOnBikeMoving + 1

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.4byte MetatileBehavior_IsBumpySlope + 1, MetatileBehavior_IsIsolatedVerticalRail + 1, MetatileBehavior_IsIsolatedHorizontalRail + 1, MetatileBehavior_IsVerticalRail + 1, MetatileBehavior_IsHorizontalRail + 1

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.4byte PlayerAvatarTransition_Normal + 1, PlayerAvatarTransition_MachBike + 1, PlayerAvatarTransition_AcroBike + 1, PlayerAvatarTransition_Surfing + 1
	.4byte PlayerAvatarTransition_Underwater + 1, PlayerAvatarTransition_ReturnToField + 1, PlayerAvatarTransition_Dummy + 1, PlayerAvatarTransition_Dummy + 1

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

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

	.globl sArrowWarpMetatileBehaviorChecks2
sArrowWarpMetatileBehaviorChecks2: @ 0x846F940
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl gUnknown_846F950
gUnknown_846F950: @ 0x846F950
	.incbin "baserom_jp.gba", 0x46f950, 0xc

	.globl gUnknown_846F95C
gUnknown_846F95C: @ 0x846F95C
	.incbin "baserom_jp.gba", 0x46f95c, 0x4

	.globl sPlayerAvatarSecretBaseMatSpin
sPlayerAvatarSecretBaseMatSpin: @ 0x846F960
	.4byte PlayerAvatar_SecretBaseMatSpinStep0 + 1, PlayerAvatar_SecretBaseMatSpinStep1 + 1, PlayerAvatar_SecretBaseMatSpinStep2 + 1, PlayerAvatar_SecretBaseMatSpinStep3 + 1

	.globl gUnknown_846F970
gUnknown_846F970: @ 0x846F970
	.incbin "baserom_jp.gba", 0x46f970, 0x4

	.globl gUnknown_846F974
gUnknown_846F974: @ 0x846F974
	.incbin "baserom_jp.gba", 0x46f974, 0x8

	.globl sFishingStateFuncs
sFishingStateFuncs: @ 0x846F97C
	.4byte Fishing_Init + 1, Fishing_GetRodOut + 1, Fishing_WaitBeforeDots + 1, Fishing_InitDots + 1, Fishing_ShowDots + 1, Fishing_CheckForBite + 1, Fishing_GotBite + 1, Fishing_WaitForA + 1
	.4byte Fishing_CheckMoreDots + 1, Fishing_MonOnHook + 1, Fishing_StartEncounter + 1, Fishing_NotEvenNibble + 1, Fishing_GotAway + 1, Fishing_NoMon + 1, Fishing_PutRodAway + 1, Fishing_EndNoMon + 1

	.globl gUnknown_846F9BC
gUnknown_846F9BC: @ 0x846F9BC
	.incbin "baserom_jp.gba", 0x46f9bc, 0x6

	.globl gUnknown_846F9C2
gUnknown_846F9C2: @ 0x846F9C2
	.incbin "baserom_jp.gba", 0x46f9c2, 0x6
