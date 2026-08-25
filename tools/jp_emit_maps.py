#!/usr/bin/env python3
"""Emit per-map script files following the US data/maps/<Map>/scripts.inc
layout, decoded with the strict JP script parser."""

import json
import re
import sys
from pathlib import Path
import collections

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_script_parser as sp
import jp_map_script_metadata as map_metadata
from jp_script_text import JapaneseScriptTextCodec, TextDecodeError, TextRoundTripError

ROM = sp.ROM
_MAP_HEADERS, _MAP_TABLES = map_metadata.build_metadata()
MAP_HEADERS = map_metadata.legacy_map_headers(_MAP_HEADERS)
MAP_TABLES = map_metadata.legacy_map_tables(_MAP_TABLES)
US_JSON = Path('/home/kenny/pokeemerald/data/maps/map_groups.json')
US_MAPS = US_JSON.parent

# A map source file can end before the next map-script table when the JP ROM
# packs shared contest/link data between the two owners.  Keep these physical
# source boundaries explicit so ``--write`` never absorbs the next raw owner.
MAP_SOURCE_REGION_ENDS = {
    'LilycoveCity_ContestLobby': 0x08207640,
}

# These maps have had their JP and US map-local script entry sequences checked
# one-to-one.  The emitter derives only their reviewed semantic label names
# from the matching US source; JP bytes, parser output, and the ROM boundary
# remain authoritative.  The count is a guard against a stale or mismatched
# reference file silently renaming an unrelated entry.
MAP_US_LABEL_SEQUENCE_COUNTS = {
    'LilycoveCity_ContestLobby': 105,
    'LilycoveCity_ContestHall': 35,
    'LilycoveCity_PokemonCenter_1F': 8,
    'LilycoveCity_PokemonCenter_2F': 3,
    'LilycoveCity_PokemonTrainerFanClub': 65,
    'LilycoveCity_Harbor': 56,
    'LilycoveCity_MoveDeletersHouse': 7,
    'LilycoveCity_House1': 2,
    'LilycoveCity_House2': 2,
    'LilycoveCity_House3': 12,
    'LilycoveCity_DepartmentStore_2F': 5,
    'LilycoveCity_DepartmentStore_3F': 5,
    'LilycoveCity_DepartmentStore_4F': 5,
    'LilycoveCity_DepartmentStore_5F': 10,
    'LilycoveCity_DepartmentStoreRooftop': 23,
    'MossdeepCity_Gym': 45,
    'MossdeepCity_House1': 3,
    'MossdeepCity_House2': 5,
    'MossdeepCity_PokemonCenter_1F': 4,
    'MossdeepCity_PokemonCenter_2F': 4,
    'MossdeepCity_Mart': 4,
    'MossdeepCity_House3': 3,
    'MossdeepCity_StevensHouse': 17,
    'MossdeepCity_House4': 5,
    'MossdeepCity_SpaceCenter_1F': 34,
    'MossdeepCity_SpaceCenter_2F': 34,
}

# This map's complete, physical JP script sequence includes both entry points.
# Most older reviewed ranges predate semantic OnLoad labels, so retain their
# existing matcher behavior and opt only this audited sequence into OnLoad.
MAP_US_LABEL_SEQUENCE_INCLUDE_ONLOAD = {
    'MossdeepCity_SpaceCenter_1F',
}

# Text labels use the same reviewed physical ordering rule.  JP generic text
# labels are accepted only as an input form; regenerated map sources use the
# semantic pokeemerald names directly.
MAP_US_TEXT_LABEL_SEQUENCE_COUNTS = {
    'LilycoveCity_ContestHall': 36,
    'LilycoveCity_PokemonCenter_1F': 3,
    'LilycoveCity_PokemonTrainerFanClub': 38,
    'LilycoveCity_Harbor': 11,
    'LilycoveCity_MoveDeletersHouse': 9,
    'LilycoveCity_House1': 2,
    'LilycoveCity_House2': 2,
    'LilycoveCity_House3': 8,
    'LilycoveCity_DepartmentStore_2F': 3,
    'LilycoveCity_DepartmentStore_3F': 3,
    'LilycoveCity_DepartmentStore_4F': 3,
    'LilycoveCity_DepartmentStore_5F': 4,
    'LilycoveCity_DepartmentStoreRooftop': 8,
    'MossdeepCity_Gym': 52,
    'MossdeepCity_House1': 4,
    'MossdeepCity_House2': 3,
    'MossdeepCity_PokemonCenter_1F': 2,
    'MossdeepCity_PokemonCenter_2F': 1,
    'MossdeepCity_Mart': 3,
    'MossdeepCity_House3': 5,
    'MossdeepCity_StevensHouse': 9,
    'MossdeepCity_House4': 5,
    'MossdeepCity_SpaceCenter_1F': 28,
    'MossdeepCity_SpaceCenter_2F': 27,
}

MAP_SCRIPT_NAMES = {
    1: 'MAP_SCRIPT_ON_LOAD',
    2: 'MAP_SCRIPT_ON_FRAME_TABLE',
    3: 'MAP_SCRIPT_ON_TRANSITION',
    4: 'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE',
    5: 'MAP_SCRIPT_ON_RESUME',
    6: 'MAP_SCRIPT_ON_DIVE_WARP',
    7: 'MAP_SCRIPT_ON_RETURN_TO_FIELD',
}

# Confirmed JP script entries which are owned by a map in the US source tree
# but are invoked indirectly rather than through that map's event table.
MAP_AUXILIARY_SCRIPT_ADDRESSES = {
    # The Route104 music selector is intentionally unused by its local
    # control flow, but remains map-owned in the matching US source.
    'Route104': (0x081E720D,),
    # A one-byte ``end`` between Timmy and Kaleb is intentionally unused but
    # remains a named Route110 script in the matching US source.
    'Route110': (0x081E91FB,),
    # The field-control progression code dispatches Wally's registration call
    # directly, rather than through a Mauville City event-table pointer.
    'MauvilleCity': (0x081DDDF3,),
    # These branch-office and Devon employee records are intentionally unused
    # but remain named, map-owned source blocks in the matching US file.
    'RustboroCity': (
        0x081DE937,
        0x081DEA74,
        0x081DEA7D,
        0x081DEA86,
        0x081DEA91,
        0x081DEA9C,
        0x081DEAA7,
        0x081DEAB2,
    ),
    # The up/right sandstorm guards have no live JP map-event pointer, but the
    # four adjacent direction variants are retained together in the US owner.
    'Route111': (0x081EA3A4, 0x081EA3C8),
    # Scott's post-Fortree phone call is dispatched from global progression
    # logic, not from a Route119 map event, but remains in the Route119 owner.
    'Route119': (0x081ED2AD,),
    'RustboroCity_Gym': (0x08202410,),  # EventScript_RegisterRoxanne
    # These unused RS-era Cable Club entry points remain named immediately
    # after the Rustboro Pokemon Center 2F map-script table in the matching
    # US source, despite having no event-table pointer.
    'RustboroCity_PokemonCenter_2F': (
        0x082035CE,
        0x082035D4,
        0x082035DA,
    ),
    # The two player-PC shutdown handlers are exported entry points in the US
    # map sources, but no local event pointer calls them directly.
    'LittlerootTown_BrendansHouse_2F': (0x081F01EE,),
    'LittlerootTown_MaysHouse_2F': (0x081F0DDB,),
    # Scott's postgame Pokenav call is dispatched by global progression logic
    # rather than a local map event, but is owned by Birch's lab in the US
    # source and sits inside the lab's exact JP script range.
    'LittlerootTown_ProfessorBirchsLab': (0x081F1A71,),
    # These unused RS-era Cable Club entry points remain named in the matching
    # Dewford Pokemon Center 2F US source, but have no local event pointer.
    'DewfordTown_PokemonCenter_2F': (
        0x081F2D75,
        0x081F2D7B,
        0x081F2D81,
    ),
    # These unused RS-era Cable Club entry points are likewise map-owned in
    # the matching Fortree Pokemon Center 2F source but have no event-table
    # pointer in the JP ROM.
    'FortreeCity_PokemonCenter_2F': (
        0x08204DAB,
        0x08204DB1,
        0x08204DB7,
    ),
    # Lilycove has the same three unused RS-era Cable Club wrappers directly
    # after its 2F map-script table. They are source-owned despite having no
    # event-table pointer.
    'LilycoveCity_PokemonCenter_2F': (
        0x0820838B,
        0x08208391,
        0x08208397,
    ),
    # Three complete Ferry-attendant branches sit in the Harbor's physical
    # script span but are not reached through the local map-event graph.
    'LilycoveCity_Harbor': (
        0x08209A3F,
        0x08209A49,
        0x08209A71,
    ),
    # The four RS-era switch pairs and the forced entrance warp are locally
    # owned complete scripts, but the Emerald event table reaches them only
    # through indirect/coordinate dispatch. Keep their physical boundaries
    # explicit instead of leaving the span as an opaque incbin.
    'MossdeepCity_Gym': (
        0x0820B502,
        0x0820B531,
        0x0820B539,
        0x0820B55E,
        0x0820B58D,
        0x0820B5B2,
        0x0820B5E1,
        0x0820B606,
        0x0820B635,
        0x0820B65A,
    ),
    # These three RS-era Cable Club wrappers are unused in Emerald but remain
    # map-owned named entries immediately after the 2F table in the US source.
    'MossdeepCity_PokemonCenter_2F': (
        0x0820C55F,
        0x0820C565,
        0x0820C56B,
    ),
    # The RS-era Dive item ball is unused in Emerald but remains an explicit
    # named script in the matching Stevens House source.
    'MossdeepCity_StevensHouse': (0x0820C9B8,),
    # Maxie/Tabitha battle entries and the post-battle Match Call branch are
    # physically map-owned by Space Center 2F despite having no local event
    # pointer that reaches them.
    'MossdeepCity_SpaceCenter_2F': (
        0x0820DA81,
        0x0820DA90,
        0x0820DA9F,
        0x0820DABD,
        0x0820DAC4,
    ),
}

# Verified map-local text that has no JP script pointer (for example an
# intentionally unused US-source string) and therefore is not discovered by
# the script graph.
MAP_AUXILIARY_TEXT_ADDRESSES = {
    # The second locked-door message is intentionally unused, but remains a
    # complete EOS-terminated map-local text record in the JP ROM.
    'PetalburgCity_Gym': (0x081FA342,),
    'RustboroCity_DevonCorp_2F': (0x08201B83,),
    # The movie and Running Shoes manual strings are map-owned but reached
    # through shared/global handlers rather than the local script graph.
    'LittlerootTown_BrendansHouse_1F': (
        0x081EFD18,
        0x081EFD5A,
    ),
    # The region-map description is shared and has no pointer in this map's
    # directly reachable script graph.
    'LittlerootTown_BrendansHouse_2F': (0x081F0308,),
    # These three lab strings are intentionally unused in the US source, so
    # no live JP script pointer discovers them during graph traversal.
    'LittlerootTown_ProfessorBirchsLab': (
        0x081F2609,
        0x081F263D,
        0x081F26DC,
    ),
    # This no-space message is unreachable in the final Beldum flow, but the
    # complete JP string remains map-owned and is named in the US source.
    'MossdeepCity_StevensHouse': (0x0820CB4A,),
}

# Map-owned movement scripts confirmed by their JP addresses and the matching
# US map source.  They are referenced by ``applymovement`` rather than being
# event scripts, so the event-script parser deliberately does not follow them.
MAP_MOVEMENT_SCRIPT_LABELS = {
    'PetalburgCity_Gym': {
        0x081F8683: 'PetalburgCity_Gym_Movement_WallyExitGym',
        0x081F8D15: 'PetalburgCity_Gym_Movement_WallysDadExitNorth',
        0x081F8D20: 'PetalburgCity_Gym_Movement_WallysDadExitEast',
        0x081F8D2B: 'PetalburgCity_Gym_Movement_WallysDadExitWest',
        0x081F8D38: 'PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth',
        0x081F8D40: 'PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast',
        0x081F8D48: 'PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest',
        0x081F8D52: 'PetalburgCity_Gym_Movement_WallysDadEnterGym',
        0x081F8D5A: 'PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth',
        0x081F8D61: 'PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast',
        0x081F8D67: 'PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest',
        0x081F8D6F: 'PetalburgCity_Gym_Movement_Unused',
        0x081F8D78: 'PetalburgCity_Gym_Movement_WallyArriveNorth',
        0x081F8D82: 'PetalburgCity_Gym_Movement_WallyArrive',
        0x081F8D89: 'PetalburgCity_Gym_Movement_WallyExitNorth',
        0x081F8D91: 'PetalburgCity_Gym_Movement_WallyExitEast',
        0x081F8D99: 'PetalburgCity_Gym_Movement_WallyExitSouthWest',
        0x081F8DA0: 'PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth',
        0x081F8DA8: 'PetalburgCity_Gym_Movement_PlayerExitWithWallySouth',
        0x081F8DB2: 'PetalburgCity_Gym_Movement_PlayerExitWithWallyWest',
        0x081F8DBA: 'PetalburgCity_Gym_Movement_PlayerExitWithWallyEast',
    },
    'LittlerootTown_BrendansHouse_1F': {
        0x081EF86A: 'LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs',
        0x081EF8CC: 'LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach',
        0x081EF9DD: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0',
        0x081EF9E5: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1',
        0x081EF9E9: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2',
        0x081EFA27: 'LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0',
        0x081EFA2B: 'LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1',
        0x081EFA32: 'LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2',
        0x081EFA36: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0',
        0x081EFA3C: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1',
        0x081EFA46: 'LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2',
    },
    'LittlerootTown_BrendansHouse_2F': {
        0x081F016B: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters',
        0x081F016F: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth',
        0x081F0175: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth',
        0x081F017E: 'LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth',
        0x081F0186: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth',
        0x081F018A: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth',
        0x081F0191: 'LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth',
        0x081F0197: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest',
        0x081F019C: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest',
        0x081F01A5: 'LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest',
        0x081F01AC: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast',
        0x081F01B3: 'LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast',
        0x081F01B8: 'LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast',
    },
    'LittlerootTown_MaysHouse_1F': {
        0x081F043D: 'LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs',
        0x081F049F: 'LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach',
        0x081F0609: 'LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer0',
        0x081F0611: 'LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer1',
        0x081F0615: 'LittlerootTown_MaysHouse_1F_Movement_MayApproachPlayer2',
        0x081F0653: 'LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0',
        0x081F0657: 'LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1',
        0x081F065E: 'LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2',
        0x081F0662: 'LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0',
        0x081F0668: 'LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1',
        0x081F0672: 'LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2',
    },
    'LittlerootTown_MaysHouse_2F': {
        0x081F0CBB: 'LittlerootTown_MaysHouse_2F_Movement_MayEnters',
        0x081F0CBF: 'LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth',
        0x081F0CC5: 'LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth',
        0x081F0CCF: 'LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth',
        0x081F0CD7: 'LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth',
        0x081F0CDB: 'LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth',
        0x081F0CE3: 'LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth',
        0x081F0CE9: 'LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest',
        0x081F0CF0: 'LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest',
        0x081F0CF5: 'LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest',
        0x081F0CF9: 'LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast',
        0x081F0CFE: 'LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast',
        0x081F0D07: 'LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast',
    },
    'LittlerootTown_ProfessorBirchsLab': {
        0x081F1413: 'LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex',
        0x081F14E1: 'LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes',
        0x081F14F3: 'LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex',
        0x081F1517: 'LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter',
        0x081F197B: 'LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer',
    },
    'FallarborTown_BattleTentLobby': {
        0x081F551D: 'FallarborTown_BattleTentLobby_Movement_AttendantWalkToDoor',
        0x081F5521: 'FallarborTown_BattleTentLobby_Movement_AttendantEnterDoor',
        0x081F5524: 'FallarborTown_BattleTentLobby_Movement_PlayerWalkToDoor',
        0x081F5528: 'FallarborTown_BattleTentLobby_Movement_PlayerEnterDoor',
    },
    'OldaleTown': {
        0x081E48CB: 'OldaleTown_Movement_Unknown1',
        0x081E48F3: 'OldaleTown_Movement_Unknown2',
    },
    # This four-byte local delay is unused by the final script flow but is
    # retained as a named movement in the matching US Petalburg City source.
    'PetalburgCity': {
        0x081DBB2D: 'PetalburgCity_Movement_Delay48',
    },
    'SlateportCity': {
        0x081DC6A8: 'SlateportCity_Movement_Unused',
    },
    'RustboroCity': {
        0x081DE887: 'RustboroCity_Movement_ScientistWalkInPlaceDown',
        0x081DE889: 'RustboroCity_Movement_PlayerWalkDown',
        0x081DE88B: 'RustboroCity_Movement_ScientistApproachPlayer',
        0x081DE88E: 'RustboroCity_Movement_ScientistWalkAroundPlayer',
        0x081DE896: 'RustboroCity_Movement_ScientistLeave',
        0x081DEAC7: 'RustboroCity_Movement_GruntEscapeExtended',
        0x081DEAD9: 'RustboroCity_Movement_GruntEscape',
        0x081DEAEA: 'RustboroCity_Movement_EmployeeChaseGrunt1',
        0x081DEAF2: 'RustboroCity_Movement_EmployeeChaseGrunt2',
        0x081DEAFA: 'RustboroCity_Movement_EmployeeApproachUp',
        0x081DEAFE: 'RustboroCity_Movement_EmployeeApproachLeft',
        0x081DEB03: 'RustboroCity_Movement_EmployeeApproachRight',
        0x081DEB08: 'RustboroCity_Movement_EmployeeApproachDown',
        0x081DEB0E: 'RustboroCity_Movement_EmployeeApproachPlayerFar',
        0x081DEC62: 'RustboroCity_Movement_EmployeeApproachPlayerDown',
        0x081DF247: 'RustboroCity_Movement_RivalApproachPlayer0',
        0x081DF24E: 'RustboroCity_Movement_RivalApproachPlayer1',
        0x081DF254: 'RustboroCity_Movement_RivalApproachPlayer2',
        0x081DF259: 'RustboroCity_Movement_RivalApproachPlayer3',
        0x081DF25D: 'RustboroCity_Movement_RivalApproachPlayer4',
        0x081DF260: 'RustboroCity_Movement_RivalApproachPlayer5',
        0x081DF264: 'RustboroCity_Movement_RivalApproachPlayer6',
        0x081DF269: 'RustboroCity_Movement_RivalApproachPlayer7',
    },
    'Route128': {
        0x081EEEAA: 'Route128_Movement_Unused1',
        0x081EEEAC: 'Route128_Movement_Unused2',
        0x081EEEB9: 'Route128_Movement_StevenWalkUp',
        0x081EEEBB: 'Route128_Movement_StevenApproachPlayer',
        0x081EEEBD: 'Route128_Movement_ArchieLookAround',
        0x081EEEC5: 'Route128_Movement_ArchieBackUp',
        0x081EEECA: 'Route128_Movement_ArchieRunLeft',
        0x081EEECF: 'Route128_Movement_ArchieExit',
        0x081EEEDC: 'Route128_Movement_MaxieWalkLeft',
        0x081EEEE1: 'Route128_Movement_MaxieApproachArchie',
        0x081EEEE4: 'Route128_Movement_MaxieExit',
        0x081EEEEF: 'Route128_Movement_MaxieApproachPlayer',
    },
    'Route104': {
        0x081E72C4: 'Route104_Movement_RivalWalkSlowLeft',
        0x081E72C6: 'Route104_Movement_RivalApproachPlayer',
        0x081E72C9: 'Route104_Movement_PlayerFaceRival',
        0x081E7482: 'Route104_Movement_PlayerBackUp',
        0x081E7486: 'Route104_Movement_RivalExitBrineysCottage',
        0x081E76C4: 'Route104_Movement_SailToDewfordBeforeDadCalls',
        0x081E7726: 'Route104_Movement_SailToDewfordAfterDadCalls',
        0x081E7788: 'Route104_Movement_SailToDewford',
        0x081E784B: 'Route104_Movement_PlayerBoardBoat',
        0x081E784F: 'Route104_Movement_PlayerExitBoat',
        0x081E7851: 'Route104_Movement_PlayerMoveForBriney',
        0x081E7855: 'Route104_Movement_BrineyBoardBoat',
        0x081E7858: 'Route104_Movement_BrineyExitBoat',
    },
    'Route116': {
        0x081EBBEC: 'Route116_Movement_DevonEmployeeExit',
        0x081EBBF5: 'Route116_Movement_DevonEmployeeExitEast',
        0x081EBD1D: 'Route116_Movement_GlassesManExit',
        0x081EBD27: 'Route116_Movement_GlassesManExitEast',
    },
    'RusturfTunnel': {
        0x082137E0: 'RusturfTunnel_Movement_WandaExit1',
        0x082137EC: 'RusturfTunnel_Movement_WandaExit',
        0x082137F8: 'RusturfTunnel_Movement_PlayerWatchWandaExit',
        0x082137FE: 'RusturfTunnel_Movement_Unused1',
        0x08213801: 'RusturfTunnel_Movement_Unused2',
        0x08213806: 'RusturfTunnel_Movement_Unused3',
        0x0821380B: 'RusturfTunnel_Movement_PlayerWatchBoyfriend1',
        0x0821380E: 'RusturfTunnel_Movement_PlayerWatchBoyfriend',
        0x08213811: 'RusturfTunnel_Movement_BoyfriendFaceRight',
        0x08213814: 'RusturfTunnel_Movement_WandasBoyfriendExit1',
        0x08213821: 'RusturfTunnel_Movement_WandasBoyfriendExit',
        0x0821382E: 'RusturfTunnel_Movement_WandasBoyfriendApproachPlayer',
        0x08213830: 'RusturfTunnel_Movement_BoyfriendApproachWanda1',
        0x08213835: 'RusturfTunnel_Movement_BoyfriendApproachWanda',
        0x08213874: 'RusturfTunnel_Movement_GruntAndPeekoBackUp',
        0x08213941: 'RusturfTunnel_Movement_PushPlayerAsideForGrunt',
        0x08213947: 'RusturfTunnel_Movement_PlayerMoveAsideForBriney',
        0x0821394A: 'RusturfTunnel_Movement_GruntEscape',
        0x08213954: 'RusturfTunnel_Movement_BrineyApproachPeeko1',
        0x0821395C: 'RusturfTunnel_Movement_BrineyExit',
        0x08213968: 'RusturfTunnel_Movement_PlayerWatchBrineyExit',
        0x0821396D: 'RusturfTunnel_Movement_BrineyApproachPeeko2',
        0x08213970: 'RusturfTunnel_Movement_PeekoExit',
    },
    'RustboroCity_DevonCorp_3F': {
        0x08201D2B: 'RustboroCity_DevonCorp_3F_Movement_Unused',
        0x08201D30: 'RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident',
        0x08201D3F: 'RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk',
        0x08201D42: 'RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen',
        0x08201D4B: 'RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer',
        0x08201D54: 'RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident',
        0x08201D62: 'RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk',
    },
    'RustboroCity_PokemonSchool': {
        0x08202D82: 'RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest',
        0x08202D99: 'RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast',
    },
    'SlateportCity_OceanicMuseum_1F': {
        0x081FCAF4: 'SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter',
        0x081FCC68: 'SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth',
        0x081FCC6D: 'SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast',
        0x081FCC70: 'SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit',
        0x081FCC77: 'SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth',
    },
    'SlateportCity_OceanicMuseum_2F': {
        0x081FD4C8: 'SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth',
        0x081FD4CC: 'SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest',
        0x081FD4D2: 'SlateportCity_OceanicMuseum_2F_Movement_Unused',
        0x081FD4E0: 'SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer',
        0x081FD4E2: 'SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter',
        0x081FD4EC: 'SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle',
        0x081FD4EE: 'SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter',
        0x081FD4F2: 'SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach',
        0x081FD4F9: 'SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated',
        0x081FD4FD: 'SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter',
        0x081FD4FF: 'SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach',
        0x081FD508: 'SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie',
    },
    'GraniteCave_StevensRoom': {
        0x082140F2: 'GraniteCave_StevensRoom_Movement_StevenExit',
        0x082140F9: 'GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit',
        0x082140FE: 'GraniteCave_StevensRoom_Movement_StevenExitSouth',
    },
    'PetalburgWoods': {
        0x08214453: 'PetalburgWoods_Movement_DevonResearcherLookAround',
        0x08214464: 'PetalburgWoods_Movement_DevonResearcherExitLeft',
        0x0821446D: 'PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft',
        0x08214472: 'PetalburgWoods_Movement_DevonResearcherApproachPlayerRight',
        0x08214479: 'PetalburgWoods_Movement_DevonResearcherExitRight',
        0x08214482: 'PetalburgWoods_Movement_WatchResearcherLeave',
        0x08214486: 'PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft',
        0x0821448C: 'PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight',
        0x08214490: 'PetalburgWoods_Movement_DevonResearcherStartExit',
        0x08214498: 'PetalburgWoods_Movement_AquaApproachResearcherLeft',
        0x0821449B: 'PetalburgWoods_Movement_AquaBackOff',
        0x0821449F: 'PetalburgWoods_Movement_AquaRunAway',
        0x082144A7: 'PetalburgWoods_Movement_AquaApproachResearcherRight',
        0x082144AB: 'PetalburgWoods_Movement_AquaEntrance',
        0x082144B0: 'PetalburgWoods_Movement_AquaApproachPlayer',
    },
}

# Map-owned shop lists require a four-byte boundary before their product data.
# Each record gives the raw span start (including any alignment padding), the
# reviewed source label, and the symbolic products in the matching US source.
# The emitter verifies the padding and pokemartlistend trailer directly against
# the JP ROM before it renders a list as source.
MAP_POKEMART_LISTS = {
    'SlateportCity': (
        (0x081DC146, 'SlateportCity_Pokemart_EnergyGuru', (
            'ITEM_PROTEIN',
            'ITEM_IRON',
            'ITEM_CARBOS',
            'ITEM_ZINC',
            'ITEM_CALCIUM',
            'ITEM_HP_UP',
        )),
        (0x081DC4F5, 'SlateportCity_PokemartDecor_Dolls', (
            'DECOR_AZURILL_DOLL',
            'DECOR_MARILL_DOLL',
            'DECOR_SKITTY_DOLL',
        )),
        (0x081DC52C, 'SlateportCity_PokemartDecor', (
            'DECOR_RED_BRICK',
            'DECOR_BLUE_BRICK',
            'DECOR_YELLOW_BRICK',
            'DECOR_RED_BALLOON',
            'DECOR_BLUE_BALLOON',
            'DECOR_YELLOW_BALLOON',
            'DECOR_C_LOW_NOTE_MAT',
            'DECOR_D_NOTE_MAT',
            'DECOR_E_NOTE_MAT',
            'DECOR_F_NOTE_MAT',
            'DECOR_G_NOTE_MAT',
            'DECOR_A_NOTE_MAT',
            'DECOR_B_NOTE_MAT',
            'DECOR_C_HIGH_NOTE_MAT',
        )),
        (0x081DC563, 'SlateportCity_Pokemart_PowerTMs', (
            'ITEM_TM_HIDDEN_POWER',
            'ITEM_TM_SECRET_POWER',
        )),
    ),
    'RustboroCity_Mart': (
        (0x0820360B, 'RustboroCity_Mart_Pokemart_Basic', (
            'ITEM_POKE_BALL',
            'ITEM_POTION',
            'ITEM_SUPER_POTION',
            'ITEM_ANTIDOTE',
            'ITEM_PARALYZE_HEAL',
            'ITEM_ESCAPE_ROPE',
            'ITEM_REPEL',
            'ITEM_X_SPEED',
            'ITEM_X_ATTACK',
            'ITEM_X_DEFEND',
        )),
        (0x08203633, 'RustboroCity_Mart_Pokemart_Expanded', (
            'ITEM_POKE_BALL',
            'ITEM_TIMER_BALL',
            'ITEM_REPEAT_BALL',
            'ITEM_POTION',
            'ITEM_SUPER_POTION',
            'ITEM_ANTIDOTE',
            'ITEM_PARALYZE_HEAL',
            'ITEM_ESCAPE_ROPE',
            'ITEM_REPEL',
            'ITEM_X_SPEED',
            'ITEM_X_ATTACK',
            'ITEM_X_DEFEND',
        )),
    ),
}

# Shared text is stored separately from map script-data.  A block enters this
# allowlist only after its raw owner, every EOS boundary, every caller, and
# the matching US text order have been checked.  jp_text_blocks.py reads this
# same mapping, so source labels and map references cannot drift apart.
VERIFIED_SHARED_TEXT_BLOCKS = {
    # Petalburg Gym's Enigma Berry message lives in the shared berry-text
    # owner.  Its sole dynamic field is the player name, as in the matching
    # US Gym source, rather than a generic {STRING 0x01} placeholder.
    'PetalburgCity_Gym_EnigmaBerry': {
        'source': 'data/scripts/gUnknown_826316A.inc',
        'start': 0x082637C2,
        'end': 0x082637EB,
        'labels': {
            0x082637C2: 'PetalburgCity_Gym_Text_GiveEnigmaBerry',
        },
        'field_placeholders': {
            0x082637C2: {0x01: 'PLAYER'},
        },
    },
    # Route104's berry-giver text is physically stored in the shared text
    # owner rather than beside its map scripts. The two EOS-terminated strings
    # and their callers were checked against the Route104 US script order.
    'Route104_BerryMaster': {
        'source': 'data/scripts/gUnknown_826316A.inc',
        'start': 0x082637EB,
        'end': 0x0826388C,
        'labels': {
            0x082637EB: 'Route104_Text_PlantBerriesInSoilTakeThis',
            0x08263847: 'Route104_Text_TrainersOftenMakeMonHoldBerries',
        },
    },
    'LilycoveCity_BerryGentleman': {
        'source': 'data/scripts/gUnknown_826316A.inc',
        'start': 0x08263A58,
        'end': 0x08263AE4,
        'labels': {
            0x08263A58: 'LilycoveCity_Text_BerrySuitsYou',
            0x08263A9E: 'LilycoveCity_Text_BecauseYoureTrainer',
            0x08263ABA: 'LilycoveCity_Text_PokeblocksSuitPokemon',
        },
    },
    'SootopolisCity_Kiri': {
        'source': 'data/scripts/gUnknown_826316A.inc',
        'start': 0x08263F33,
        'end': 0x0826406F,
        'labels': {
            0x08263F33: 'SootopolisCity_Text_NameIsKiriHaveOneOfThese',
            0x08263FB4: 'SootopolisCity_Text_GiveYouThisBerryToo',
            0x08263FD5: 'SootopolisCity_Text_WhatKindOfWishInYourName',
            0x08263FF1: 'SootopolisCity_Text_LikeSeasonBornIn',
            0x08264025: 'SootopolisCity_Text_ThenILoveAutumn',
            0x0826404E: 'SootopolisCity_Text_OhDoesntMatter',
        },
    },
    'Route134': {
        'source': 'data/text/trainers.inc',
        'start': 0x08262069,
        'end': 0x08262393,
        'labels': {
            0x08262069: 'Route134_Text_JackIntro',
            0x0826208B: 'Route134_Text_JackDefeat',
            0x08262091: 'Route134_Text_JackPostBattle',
            0x082620AF: 'Route134_Text_LaurelIntro',
            0x082620CE: 'Route134_Text_LaurelDefeat',
            0x082620D7: 'Route134_Text_LaurelPostBattle',
            0x082620F6: 'Route134_Text_AlexIntro',
            0x08262116: 'Route134_Text_AlexDefeat',
            0x0826211F: 'Route134_Text_AlexPostBattle',
            0x08262143: 'Route134_Text_HitoshiIntro',
            0x0826215E: 'Route134_Text_HitoshiDefeat',
            0x08262170: 'Route134_Text_HitoshiPostBattle',
            0x08262196: 'Route134_Text_AaronIntro',
            0x082621C0: 'Route134_Text_AaronDefeat',
            0x082621CF: 'Route134_Text_AaronPostBattle',
            0x0826220B: 'Route134_Text_KelvinIntro',
            0x0826221F: 'Route134_Text_KelvinDefeat',
            0x08262237: 'Route134_Text_KelvinPostBattle',
            0x08262281: 'Route134_Text_MarleyIntro',
            0x08262295: 'Route134_Text_MarleyDefeat',
            0x082622AE: 'Route134_Text_MarleyPostBattle',
            0x082622D3: 'Route134_Text_ReynaIntro',
            0x082622F2: 'Route134_Text_ReynaDefeat',
            0x08262306: 'Route134_Text_ReynaPostBattle',
            0x0826233C: 'Route134_Text_HudsonIntro',
            0x08262358: 'Route134_Text_HudsonDefeat',
            0x08262360: 'Route134_Text_HudsonPostBattle',
        },
    },
    'Route133': {
        'source': 'data/text/trainers.inc',
        'start': 0x08261E19,
        'end': 0x08262069,
        'labels': {
            0x08261E19: 'Route133_Text_FranklinIntro',
            0x08261E45: 'Route133_Text_FranklinDefeat',
            0x08261E51: 'Route133_Text_FranklinPostBattle',
            0x08261E80: 'Route133_Text_DebraIntro',
            0x08261EA4: 'Route133_Text_DebraDefeat',
            0x08261EAB: 'Route133_Text_DebraPostBattle',
            0x08261EC8: 'Route133_Text_LindaIntro',
            0x08261EDD: 'Route133_Text_LindaDefeat',
            0x08261EE3: 'Route133_Text_LindaPostBattle',
            0x08261F06: 'Route133_Text_WarrenIntro',
            0x08261F26: 'Route133_Text_WarrenDefeat',
            0x08261F3F: 'Route133_Text_WarrenPostBattle',
            0x08261F6E: 'Route133_Text_BeckIntro',
            0x08261F8B: 'Route133_Text_BeckDefeat',
            0x08261F9D: 'Route133_Text_BeckPostBattle',
            0x08261FC7: 'Route133_Text_MollieIntro',
            0x08261FE5: 'Route133_Text_MollieDefeat',
            0x08262001: 'Route133_Text_MolliePostBattle',
            0x08262022: 'Route133_Text_ConorIntro',
            0x0826203E: 'Route133_Text_ConorDefeat',
            0x0826204B: 'Route133_Text_ConorPostBattle',
        },
    },
    'Route132': {
        'source': 'data/text/trainers.inc',
        'start': 0x08261B3C,
        'end': 0x08261E19,
        'labels': {
            0x08261B3C: 'Route132_Text_GilbertIntro',
            0x08261B68: 'Route132_Text_GilbertDefeat',
            0x08261B77: 'Route132_Text_GilbertPostBattle',
            0x08261BA4: 'Route132_Text_DanaIntro',
            0x08261BC3: 'Route132_Text_DanaDefeat',
            0x08261BCD: 'Route132_Text_DanaPostBattle',
            0x08261BF1: 'Route132_Text_RonaldIntro',
            0x08261C07: 'Route132_Text_RonaldDefeat',
            0x08261C14: 'Route132_Text_RonaldPostBattle',
            0x08261C45: 'Route132_Text_KiyoIntro',
            0x08261C6E: 'Route132_Text_KiyoDefeat',
            0x08261C7F: 'Route132_Text_KiyoPostBattle',
            0x08261CB3: 'Route132_Text_MakaylaIntro',
            0x08261CD0: 'Route132_Text_MakaylaDefeat',
            0x08261CDD: 'Route132_Text_MakaylaPostBattle',
            0x08261D04: 'Route132_Text_JonathanIntro',
            0x08261D25: 'Route132_Text_JonathanDefeat',
            0x08261D2F: 'Route132_Text_JonathanPostBattle',
            0x08261D4F: 'Route132_Text_PaxtonIntro',
            0x08261D72: 'Route132_Text_PaxtonDefeat',
            0x08261D7F: 'Route132_Text_PaxtonPostBattle',
            0x08261DA0: 'Route132_Text_DarcyIntro',
            0x08261DD6: 'Route132_Text_DarcyDefeat',
            0x08261DEE: 'Route132_Text_DarcyPostBattle',
        },
    },
    'Route131': {
        'source': 'data/text/trainers.inc',
        'start': 0x08261799,
        'end': 0x08261B3C,
        'labels': {
            0x08261799: 'Route131_Text_RichardIntro',
            0x082617C3: 'Route131_Text_RichardDefeat',
            0x082617E2: 'Route131_Text_RichardPostBattle',
            0x0826181A: 'Route131_Text_HermanIntro',
            0x08261842: 'Route131_Text_HermanDefeat',
            0x0826184C: 'Route131_Text_HermanPostBattle',
            0x0826187A: 'Route131_Text_SusieIntro',
            0x08261893: 'Route131_Text_SusieDefeat',
            0x082618A5: 'Route131_Text_SusiePostBattle',
            0x082618E8: 'Route131_Text_KaraIntro',
            0x08261919: 'Route131_Text_KaraDefeat',
            0x0826192C: 'Route131_Text_KaraPostBattle',
            0x08261955: 'Route131_Text_ReliIntro',
            0x08261975: 'Route131_Text_ReliDefeat',
            0x08261992: 'Route131_Text_ReliPostBattle',
            0x082619BD: 'Route131_Text_ReliNotEnoughMons',
            0x082619E1: 'Route131_Text_IanIntro',
            0x082619FE: 'Route131_Text_IanDefeat',
            0x08261A18: 'Route131_Text_IanPostBattle',
            0x08261A53: 'Route131_Text_IanNotEnoughMons',
            0x08261A73: 'Route131_Text_TaliaIntro',
            0x08261A90: 'Route131_Text_TaliaDefeat',
            0x08261A9C: 'Route131_Text_TaliaPostBattle',
            0x08261AD0: 'Route131_Text_KevinIntro',
            0x08261B01: 'Route131_Text_KevinDefeat',
            0x08261B06: 'Route131_Text_KevinPostBattle',
        },
    },
    'Route130': {
        'source': 'data/text/trainers.inc',
        'start': 0x0826169F,
        'end': 0x08261799,
        'labels': {
            0x0826169F: 'Route130_Text_RodneyIntro',
            0x082616CE: 'Route130_Text_RodneyDefeat',
            0x082616DD: 'Route130_Text_RodneyPostBattle',
            0x082616FE: 'Route130_Text_KatieIntro',
            0x08261716: 'Route130_Text_KatieDefeat',
            0x0826172F: 'Route130_Text_KatiePostBattle',
            0x08261747: 'Route130_Text_SantiagoIntro',
            0x08261765: 'Route130_Text_SantiagoDefeat',
            0x08261776: 'Route130_Text_SantiagoPostBattle',
        },
    },
    'Route129': {
        'source': 'data/text/trainers.inc',
        'start': 0x08261517,
        'end': 0x0826169F,
        'labels': {
            0x08261517: 'Route129_Text_ChaseIntro',
            0x0826153D: 'Route129_Text_ChaseDefeat',
            0x0826154D: 'Route129_Text_ChasePostBattle',
            0x08261568: 'Route129_Text_AllisonIntro',
            0x0826158C: 'Route129_Text_AllisonDefeat',
            0x0826159B: 'Route129_Text_AllisonPostBattle',
            0x082615C8: 'Route129_Text_ReedIntro',
            0x082615DE: 'Route129_Text_ReedDefeat',
            0x082615F3: 'Route129_Text_ReedPostBattle',
            0x0826160F: 'Route129_Text_TishaIntro',
            0x08261624: 'Route129_Text_TishaDefeat',
            0x08261639: 'Route129_Text_TishaPostBattle',
            0x08261660: 'Route129_Text_ClarenceIntro',
            0x08261673: 'Route129_Text_ClarenceDefeat',
            0x08261681: 'Route129_Text_ClarencePostBattle',
        },
    },
    'Route128': {
        'source': 'data/text/trainers.inc',
        'start': 0x08261197,
        'end': 0x08261517,
        'labels': {
            0x08261197: 'Route128_Text_IsaiahIntro',
            0x082611A9: 'Route128_Text_IsaiahDefeat',
            0x082611BB: 'Route128_Text_IsaiahPostBattle',
            0x082611DE: 'Route128_Text_IsaiahRegister',
            0x08261211: 'Route128_Text_IsaiahRematchIntro',
            0x08261235: 'Route128_Text_IsaiahRematchDefeat',
            0x08261245: 'Route128_Text_IsaiahPostRematch',
            0x08261269: 'Route128_Text_KatelynIntro',
            0x082612A1: 'Route128_Text_KatelynDefeat',
            0x082612B4: 'Route128_Text_KatelynPostBattle',
            0x082612CE: 'Route128_Text_KatelynRegister',
            0x082612ED: 'Route128_Text_KatelynRematchIntro',
            0x0826131D: 'Route128_Text_KatelynRematchDefeat',
            0x08261335: 'Route128_Text_KatelynPostRematch',
            0x08261359: 'Route128_Text_AlexaIntro',
            0x08261390: 'Route128_Text_AlexaDefeat',
            0x0826139B: 'Route128_Text_AlexaPostBattle',
            0x082613BB: 'Route128_Text_RubenIntro',
            0x082613DC: 'Route128_Text_RubenDefeat',
            0x082613E7: 'Route128_Text_RubenPostBattle',
            0x0826140A: 'Route128_Text_WayneIntro',
            0x08261435: 'Route128_Text_WayneDefeat',
            0x08261448: 'Route128_Text_WaynePostBattle',
            0x08261475: 'Route128_Text_HarrisonIntro',
            0x08261490: 'Route128_Text_HarrisonDefeat',
            0x0826149F: 'Route128_Text_HarrisonPostBattle',
            0x082614D2: 'Route128_Text_CarleeIntro',
            0x082614EC: 'Route128_Text_CarleeDefeat',
            0x082614FE: 'Route128_Text_CarleePostBattle',
        },
    },
    'Route127': {
        'source': 'data/text/trainers.inc',
        'start': 0x08260E57,
        'end': 0x08261197,
        'labels': {
            0x08260E57: 'Route127_Text_CamdenIntro',
            0x08260E72: 'Route127_Text_CamdenDefeat',
            0x08260E7A: 'Route127_Text_CamdenPostBattle',
            0x08260E9B: 'Route127_Text_DonnyIntro',
            0x08260EBA: 'Route127_Text_DonnyDefeat',
            0x08260EC8: 'Route127_Text_DonnyPostBattle',
            0x08260EF1: 'Route127_Text_JonahIntro',
            0x08260F1E: 'Route127_Text_JonahDefeat',
            0x08260F32: 'Route127_Text_JonahPostBattle',
            0x08260F54: 'Route127_Text_HenryIntro',
            0x08260F77: 'Route127_Text_HenryDefeat',
            0x08260F7D: 'Route127_Text_HenryPostBattle',
            0x08260FA5: 'Route127_Text_RogerIntro',
            0x08260FBF: 'Route127_Text_RogerDefeat',
            0x08260FDA: 'Route127_Text_RogerPostBattle',
            0x08260FF7: 'Route127_Text_AidanIntro',
            0x08261021: 'Route127_Text_AidanDefeat',
            0x0826102C: 'Route127_Text_AidanPostBattle',
            0x0826106A: 'Route127_Text_KojiIntro',
            0x08261087: 'Route127_Text_KojiDefeat',
            0x0826109D: 'Route127_Text_KojiPostBattle',
            0x082610BC: 'Route127_Text_KojiRegister',
            0x082610E2: 'Route127_Text_KojiRematchIntro',
            0x08261104: 'Route127_Text_KojiRematchDefeat',
            0x08261118: 'Route127_Text_KojiPostRematch',
            0x0826113C: 'Route127_Text_AthenaIntro',
            0x08261157: 'Route127_Text_AthenaDefeat',
            0x0826116B: 'Route127_Text_AthenaPostBattle',
        },
    },
    'Route126': {
        'source': 'data/text/trainers.inc',
        'start': 0x08260B67,
        'end': 0x08260E57,
        'labels': {
            0x08260B67: 'Route126_Text_BarryIntro',
            0x08260B85: 'Route126_Text_BarryDefeat',
            0x08260B8E: 'Route126_Text_BarryPostBattle',
            0x08260BAD: 'Route126_Text_DeanIntro',
            0x08260BCC: 'Route126_Text_DeanDefeat',
            0x08260BD4: 'Route126_Text_DeanPostBattle',
            0x08260BF2: 'Route126_Text_NikkiIntro',
            0x08260C03: 'Route126_Text_NikkiDefeat',
            0x08260C1C: 'Route126_Text_NikkiPostBattle',
            0x08260C40: 'Route126_Text_BrendaIntro',
            0x08260C57: 'Route126_Text_BrendaDefeat',
            0x08260C5E: 'Route126_Text_BrendaPostBattle',
            0x08260C7B: 'Route126_Text_PabloIntro',
            0x08260C98: 'Route126_Text_PabloDefeat',
            0x08260CAB: 'Route126_Text_PabloPostBattle',
            0x08260CD2: 'Route126_Text_PabloRegister',
            0x08260CF1: 'Route126_Text_PabloRematchIntro',
            0x08260D12: 'Route126_Text_PabloRematchDefeat',
            0x08260D29: 'Route126_Text_PabloPostRematch',
            0x08260D55: 'Route126_Text_LeonardoIntro',
            0x08260D8C: 'Route126_Text_LeonardoDefeat',
            0x08260D9F: 'Route126_Text_LeonardoPostBattle',
            0x08260DD2: 'Route126_Text_IsobelIntro',
            0x08260DED: 'Route126_Text_IsobelDefeat',
            0x08260DFE: 'Route126_Text_IsobelPostBattle',
            0x08260E20: 'Route126_Text_SiennaIntro',
            0x08260E31: 'Route126_Text_SiennaDefeat',
            0x08260E3C: 'Route126_Text_SiennaPostBattle',
        },
    },
    'Route125': {
        'source': 'data/text/trainers.inc',
        'start': 0x08260724,
        'end': 0x08260B67,
        'labels': {
            0x08260724: 'Route125_Text_NolenIntro',
            0x08260743: 'Route125_Text_NolenDefeat',
            0x0826074D: 'Route125_Text_NolenPostBattle',
            0x0826077A: 'Route125_Text_StanIntro',
            0x08260793: 'Route125_Text_StanDefeat',
            0x0826079C: 'Route125_Text_StanPostBattle',
            0x082607C0: 'Route125_Text_TanyaIntro',
            0x082607DD: 'Route125_Text_TanyaDefeat',
            0x082607E7: 'Route125_Text_TanyaPostBattle',
            0x08260803: 'Route125_Text_SharonIntro',
            0x08260820: 'Route125_Text_SharonDefeat',
            0x08260826: 'Route125_Text_SharonPostBattle',
            0x0826083F: 'Route125_Text_ErnestIntro',
            0x08260866: 'Route125_Text_ErnestDefeat',
            0x08260876: 'Route125_Text_ErnestPostBattle',
            0x082608C6: 'Route125_Text_ErnestRegister',
            0x082608E8: 'Route125_Text_ErnestRematchIntro',
            0x0826090F: 'Route125_Text_ErnestRematchDefeat',
            0x08260920: 'Route125_Text_ErnestRematchPostBattle',
            0x0826097F: 'Route125_Text_KimIntro',
            0x082609AF: 'Route125_Text_KimDefeat',
            0x082609BE: 'Route125_Text_KimPostBattle',
            0x082609EF: 'Route125_Text_KimNotEnoughMons',
            0x08260A0E: 'Route125_Text_IrisIntro',
            0x08260A2C: 'Route125_Text_IrisDefeat',
            0x08260A41: 'Route125_Text_IrisPostBattle',
            0x08260A6D: 'Route125_Text_IrisNotEnoughMons',
            0x08260A93: 'Route125_Text_PresleyIntro',
            0x08260AB4: 'Route125_Text_PresleyDefeat',
            0x08260ACD: 'Route125_Text_PresleyPostBattle',
            0x08260B0C: 'Route125_Text_AuronIntro',
            0x08260B27: 'Route125_Text_AuronDefeat',
            0x08260B33: 'Route125_Text_AuronPostBattle',
        },
    },
    'Route124': {
        'source': 'data/text/trainers.inc',
        'start': 0x082600D9,
        'end': 0x08260724,
        'labels': {
            0x082600D9: 'Route124_Text_SpencerIntro',
            0x08260110: 'Route124_Text_SpencerDefeat',
            0x08260123: 'Route124_Text_SpencerPostBattle',
            0x0826015C: 'Route124_Text_RolandIntro',
            0x08260187: 'Route124_Text_RolandDefeat',
            0x08260192: 'Route124_Text_RolandPostBattle',
            0x082601C6: 'Route124_Text_JennyIntro',
            0x082601EA: 'Route124_Text_JennyDefeat',
            0x082601F7: 'Route124_Text_JennyPostBattle',
            0x08260237: 'Route124_Text_JennyRegister',
            0x08260256: 'Route124_Text_JennyRematchIntro',
            0x0826027A: 'Route124_Text_JennyRematchDefeat',
            0x0826028D: 'Route124_Text_JennyPostRematch',
            0x082602AB: 'Route124_Text_GraceIntro',
            0x082602CE: 'Route124_Text_GraceDefeat',
            0x082602E7: 'Route124_Text_GracePostBattle',
            0x08260306: 'Route124_Text_ChadIntro',
            0x0826032E: 'Route124_Text_ChadDefeat',
            0x08260340: 'Route124_Text_ChadPostBattle',
            0x08260374: 'Route124_Text_LilaIntro',
            0x082603B4: 'Route124_Text_LilaDefeat',
            0x082603D6: 'Route124_Text_LilaPostBattle',
            0x08260407: 'Route124_Text_LilaNotEnoughMons',
            0x0826042D: 'Route124_Text_RoyIntro',
            0x08260454: 'Route124_Text_RoyDefeat',
            0x08260470: 'Route124_Text_RoyPostBattle',
            0x082604A3: 'Route124_Text_LilaRoyRegister',
            0x082604C9: 'Route124_Text_RoyNotEnoughMons',
            0x082604EC: 'Route124_Text_LilaRematchIntro',
            0x08260536: 'Route124_Text_LilaRematchDefeat',
            0x08260564: 'Route124_Text_LilaPostRematch',
            0x082605A2: 'Route124_Text_LilaRematchNotEnoughMons',
            0x082605C8: 'Route124_Text_RoyRematchIntro',
            0x082605EF: 'Route124_Text_RoyRematchDefeat',
            0x0826060A: 'Route124_Text_RoyPostRematch',
            0x08260644: 'Route124_Text_RoyRematchNotEnoughMons',
            0x08260667: 'Route124_Text_DeclanIntro',
            0x08260695: 'Route124_Text_DeclanDefeat',
            0x082606A8: 'Route124_Text_DeclanPostBattle',
            0x082606CC: 'Route124_Text_IsabellaIntro',
            0x082606E2: 'Route124_Text_IsabellaDefeat',
            0x08260701: 'Route124_Text_IsabellaPostBattle',
        },
    },
    'Route123': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825F985,
        'end': 0x082600D9,
        'labels': {
            0x0825F985: 'Route123_Text_WendyIntro',
            0x0825F9AD: 'Route123_Text_WendyDefeat',
            0x0825F9B7: 'Route123_Text_WendyPostBattle',
            0x0825F9DA: 'Route123_Text_BraxtonIntro',
            0x0825FA18: 'Route123_Text_BraxtonDefeat',
            0x0825FA26: 'Route123_Text_BraxtonPostBattle',
            0x0825FA3D: 'Route123_Text_VioletIntro',
            0x0825FA63: 'Route123_Text_VioletDefeat',
            0x0825FA75: 'Route123_Text_VioletPostBattle',
            0x0825FA9C: 'Route123_Text_CameronIntro',
            0x0825FAD0: 'Route123_Text_CameronDefeat',
            0x0825FAD8: 'Route123_Text_CameronPostBattle',
            0x0825FAFF: 'Route123_Text_CameronRegister',
            0x0825FB38: 'Route123_Text_CameronRematchIntro',
            0x0825FB5A: 'Route123_Text_CameronRematchDefeat',
            0x0825FB62: 'Route123_Text_CameronPostRematch',
            0x0825FB8D: 'Route123_Text_JackiIntro',
            0x0825FBBF: 'Route123_Text_JackiDefeat',
            0x0825FBC4: 'Route123_Text_JackiPostBattle',
            0x0825FBEF: 'Route123_Text_JackiRegister',
            0x0825FC0A: 'Route123_Text_JackiRematchIntro',
            0x0825FC2A: 'Route123_Text_JackiRematchDefeat',
            0x0825FC30: 'Route123_Text_JackiPostRematch',
            0x0825FC4A: 'Route123_Text_MiuIntro',
            0x0825FC6D: 'Route123_Text_MiuDefeat',
            0x0825FC7A: 'Route123_Text_MiuPostBattle',
            0x0825FC9D: 'Route123_Text_MiuNotEnoughMons',
            0x0825FCC1: 'Route123_Text_YukiIntro',
            0x0825FCDF: 'Route123_Text_YukiDefeat',
            0x0825FCEC: 'Route123_Text_YukiPostBattle',
            0x0825FD16: 'Route123_Text_YukiNotEnoughMons',
            0x0825FD3A: 'Route123_Text_KindraIntro',
            0x0825FD6B: 'Route123_Text_KindraDefeat',
            0x0825FD77: 'Route123_Text_KindraPostBattle',
            0x0825FDB5: 'Route123_Text_FernandoIntro',
            0x0825FDD2: 'Route123_Text_FernandoDefeat',
            0x0825FDE2: 'Route123_Text_FernandoPostBattle',
            0x0825FDFE: 'Route123_Text_FernandoRegister',
            0x0825FE1B: 'Route123_Text_FernandoRematchIntro',
            0x0825FE43: 'Route123_Text_FernandoRematchDefeat',
            0x0825FE58: 'Route123_Text_FernandoPostRematch',
            0x0825FE79: 'Route123_Text_DavisIntro',
            0x0825FE9C: 'Route123_Text_DavisDefeat',
            0x0825FEA6: 'Route123_Text_DavisPostBattle',
            0x0825FEC5: 'Route123_Text_JazmynIntro',
            0x0825FEE6: 'Route123_Text_JazmynDefeat',
            0x0825FEF3: 'Route123_Text_JazmynPostBattle',
            0x0825FF1E: 'Route123_Text_FrederickIntro',
            0x0825FF38: 'Route123_Text_FrederickDefeat',
            0x0825FF4B: 'Route123_Text_FrederickPostBattle',
            0x0825FF68: 'Route123_Text_AlbertoIntro',
            0x0825FF89: 'Route123_Text_AlbertoDefeat',
            0x0825FF9A: 'Route123_Text_AlbertoPostBattle',
            0x0825FFCD: 'Route123_Text_EdIntro',
            0x0825FFFB: 'Route123_Text_EdDefeat',
            0x0826000A: 'Route123_Text_EdPostBattle',
            0x08260033: 'Route123_Text_JonasIntro',
            0x08260050: 'Route123_Text_JonasDefeat',
            0x08260068: 'Route123_Text_JonasPostBattle',
            0x0826008D: 'Route123_Text_KayleyIntro',
            0x082600B1: 'Route123_Text_KayleyDefeat',
            0x082600C4: 'Route123_Text_KayleyPostBattle',
        },
    },
    'Route121': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825F3DF,
        'end': 0x0825F985,
        'labels': {
            0x0825F3DF: 'Route121_Text_VanessaIntro',
            0x0825F3FE: 'Route121_Text_VanessaDefeat',
            0x0825F40F: 'Route121_Text_VanessaPostBattle',
            0x0825F43F: 'Route121_Text_WalterIntro',
            0x0825F471: 'Route121_Text_WalterDefeat',
            0x0825F47A: 'Route121_Text_WalterPostBattle',
            0x0825F49B: 'Route121_Text_WalterRegister',
            0x0825F4BE: 'Route121_Text_WalterRematchIntro',
            0x0825F4F0: 'Route121_Text_WalterRematchDefeat',
            0x0825F4FA: 'Route121_Text_WalterPostRematch',
            0x0825F51F: 'Route121_Text_TammyIntro',
            0x0825F53C: 'Route121_Text_TammyDefeat',
            0x0825F548: 'Route121_Text_TammyPostBattle',
            0x0825F566: 'Route121_Text_KateIntro',
            0x0825F592: 'Route121_Text_KateDefeat',
            0x0825F5A9: 'Route121_Text_KatePostBattle',
            0x0825F5D8: 'Route121_Text_KateNotEnoughMons',
            0x0825F612: 'Route121_Text_JoyIntro',
            0x0825F63E: 'Route121_Text_JoyDefeat',
            0x0825F64E: 'Route121_Text_JoyPostBattle',
            0x0825F66C: 'Route121_Text_JoyNotEnoughMons',
            0x0825F697: 'Route121_Text_JessicaIntro',
            0x0825F6B3: 'Route121_Text_JessicaDefeat',
            0x0825F6C9: 'Route121_Text_JessicaPostBattle',
            0x0825F6E4: 'Route121_Text_JessicaRegister',
            0x0825F707: 'Route121_Text_JessicaRematchIntro',
            0x0825F728: 'Route121_Text_JessicaRematchDefeat',
            0x0825F740: 'Route121_Text_JessicaPostRematch',
            0x0825F75B: 'Route121_Text_CristinIntro',
            0x0825F782: 'Route121_Text_CristinDefeat',
            0x0825F78C: 'Route121_Text_CristinPostBattle',
            0x0825F7AE: 'Route121_Text_CristinRegister',
            0x0825F7DC: 'Route121_Text_CristinRematchIntro',
            0x0825F805: 'Route121_Text_CristinRematchDefeat',
            0x0825F818: 'Route121_Text_CristinPostRematch',
            0x0825F83B: 'Route121_Text_CaleIntro',
            0x0825F862: 'Route121_Text_CaleDefeat',
            0x0825F87D: 'Route121_Text_CalePostBattle',
            0x0825F8AD: 'Route121_Text_MylesIntro',
            0x0825F8C6: 'Route121_Text_MylesDefeat',
            0x0825F8CD: 'Route121_Text_MylesPostBattle',
            0x0825F8ED: 'Route121_Text_PatIntro',
            0x0825F90B: 'Route121_Text_PatDefeat',
            0x0825F912: 'Route121_Text_PatPostBattle',
            0x0825F934: 'Route121_Text_MarcelIntro',
            0x0825F95B: 'Route121_Text_MarcelDefeat',
            0x0825F968: 'Route121_Text_MarcelPostBattle',
        },
    },
    'Route120': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825EDBE,
        'end': 0x0825F3DF,
        'labels': {
            0x0825EDBE: 'Route120_Text_ColinIntro',
            0x0825EDE3: 'Route120_Text_ColinDefeat',
            0x0825EDF9: 'Route120_Text_ColinPostBattle',
            0x0825EE2F: 'Route120_Text_RobertIntro',
            0x0825EE4F: 'Route120_Text_RobertDefeat',
            0x0825EE66: 'Route120_Text_RobertPostBattle',
            0x0825EE87: 'Route120_Text_RobertRegister',
            0x0825EEAC: 'Route120_Text_RobertRematchIntro',
            0x0825EECD: 'Route120_Text_RobertRematchDefeat',
            0x0825EEE5: 'Route120_Text_RobertPostRematch',
            0x0825EF09: 'Route120_Text_LorenzoIntro',
            0x0825EF24: 'Route120_Text_LorenzoDefeat',
            0x0825EF4A: 'Route120_Text_LorenzoPostBattle',
            0x0825EF73: 'Route120_Text_JennaIntro',
            0x0825EF9E: 'Route120_Text_JennaDefeat',
            0x0825EFB0: 'Route120_Text_JennaPostBattle',
            0x0825EFD7: 'Route120_Text_JeffreyIntro',
            0x0825EFF4: 'Route120_Text_JeffreyDefeat',
            0x0825F003: 'Route120_Text_JeffreyPostBattle',
            0x0825F01D: 'Route120_Text_JeffreyRegister',
            0x0825F03C: 'Route120_Text_JeffreyRematchIntro',
            0x0825F05C: 'Route120_Text_JeffreyRematchDefeat',
            0x0825F06E: 'Route120_Text_JeffreyPostRematch',
            0x0825F09E: 'Route120_Text_JenniferIntro',
            0x0825F0D4: 'Route120_Text_JenniferDefeat',
            0x0825F0E2: 'Route120_Text_JenniferPostBattle',
            0x0825F10B: 'Route120_Text_ChipIntro',
            0x0825F149: 'Route120_Text_ChipDefeat',
            0x0825F153: 'Route120_Text_ChipPostBattle',
            0x0825F184: 'Route120_Text_ClarissaIntro',
            0x0825F1B7: 'Route120_Text_ClarissaDefeat',
            0x0825F1D3: 'Route120_Text_ClarissaPostBattle',
            0x0825F20A: 'Route120_Text_AngelicaIntro',
            0x0825F23A: 'Route120_Text_AngelicaDefeat',
            0x0825F24F: 'Route120_Text_AngelicaPostBattle',
            0x0825F287: 'Route120_Text_KeigoIntro',
            0x0825F2AC: 'Route120_Text_KeigoDefeat',
            0x0825F2CA: 'Route120_Text_KeigoPostBattle',
            0x0825F2E7: 'Route120_Text_RileyIntro',
            0x0825F310: 'Route120_Text_RileyDefeat',
            0x0825F323: 'Route120_Text_RileyPostBattle',
            0x0825F348: 'Route120_Text_CallieIntro',
            0x0825F358: 'Route120_Text_CallieDefeat',
            0x0825F36C: 'Route120_Text_CalliePostBattle',
            0x0825F38C: 'Route120_Text_LeonelIntro',
            0x0825F3AD: 'Route120_Text_LeonelDefeat',
            0x0825F3C0: 'Route120_Text_LeonelPostBattle',
        },
    },
    'Route119': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825E688,
        'end': 0x0825EDBE,
        'labels': {
            0x0825E688: 'Route119_Text_BrentIntro',
            0x0825E6A7: 'Route119_Text_BrentDefeat',
            0x0825E6B2: 'Route119_Text_BrentPostBattle',
            0x0825E6DB: 'Route119_Text_DonaldIntro',
            0x0825E6FC: 'Route119_Text_DonaldDefeat',
            0x0825E70B: 'Route119_Text_DonaldPostBattle',
            0x0825E72A: 'Route119_Text_TaylorIntro',
            0x0825E759: 'Route119_Text_TaylorDefeat',
            0x0825E76C: 'Route119_Text_TaylorPostBattle',
            0x0825E798: 'Route119_Text_DougIntro',
            0x0825E7BE: 'Route119_Text_DougDefeat',
            0x0825E7CF: 'Route119_Text_DougPostBattle',
            0x0825E7EC: 'Route119_Text_GregIntro',
            0x0825E826: 'Route119_Text_GregDefeat',
            0x0825E835: 'Route119_Text_GregPostBattle',
            0x0825E853: 'Route119_Text_KentIntro',
            0x0825E88D: 'Route119_Text_KentDefeat',
            0x0825E897: 'Route119_Text_KentPostBattle',
            0x0825E8AC: 'Route119_Text_JacksonIntro',
            0x0825E8DB: 'Route119_Text_JacksonDefeat',
            0x0825E8EF: 'Route119_Text_JacksonPostBattle',
            0x0825E91F: 'Route119_Text_JacksonRegister',
            0x0825E943: 'Route119_Text_JacksonRematchIntro',
            0x0825E95D: 'Route119_Text_JacksonRematchDefeat',
            0x0825E96A: 'Route119_Text_JacksonPostRematch',
            0x0825E996: 'Route119_Text_CatherineIntro',
            0x0825E9C0: 'Route119_Text_CatherineDefeat',
            0x0825E9D3: 'Route119_Text_CatherinePostBattle',
            0x0825EA0A: 'Route119_Text_CatherineRegister',
            0x0825EA3D: 'Route119_Text_CatherineRematchIntro',
            0x0825EA5C: 'Route119_Text_CatherineRematchDefeat',
            0x0825EA6F: 'Route119_Text_CatherinePostRematch',
            0x0825EAA1: 'Route119_Text_HughIntro',
            0x0825EAD2: 'Route119_Text_HughDefeat',
            0x0825EAD9: 'Route119_Text_HughPostBattle',
            0x0825EAFD: 'Route119_Text_PhilIntro',
            0x0825EB1A: 'Route119_Text_PhilDefeat',
            0x0825EB2A: 'Route119_Text_PhilPostBattle',
            0x0825EB4C: 'Route119_Text_YasuIntro',
            0x0825EB78: 'Route119_Text_YasuDefeat',
            0x0825EB80: 'Route119_Text_YasuPostBattle',
            0x0825EBA9: 'Route119_Text_TakashiIntro',
            0x0825EBBE: 'Route119_Text_TakashiDefeat',
            0x0825EBC9: 'Route119_Text_TakashiPostBattle',
            0x0825EBDE: 'Route119_Text_HideoIntro',
            0x0825EBEE: 'Route119_Text_HideoDefeat',
            0x0825EBF9: 'Route119_Text_HideoPostBattle',
            0x0825EC2D: 'Route119_Text_ChrisIntro',
            0x0825EC72: 'Route119_Text_ChrisDefeat',
            0x0825EC89: 'Route119_Text_ChrisPostBattle',
            0x0825ECC0: 'Route119_Text_FabianIntro',
            0x0825ECDC: 'Route119_Text_FabianDefeat',
            0x0825ECF1: 'Route119_Text_FabianPostBattle',
            0x0825ED0E: 'Route119_Text_DaytonIntro',
            0x0825ED38: 'Route119_Text_DaytonDefeat',
            0x0825ED44: 'Route119_Text_DaytonPostBattle',
            0x0825ED6F: 'Route119_Text_RachelIntro',
            0x0825ED88: 'Route119_Text_RachelDefeat',
            0x0825ED91: 'Route119_Text_RachelPostBattle',
        },
    },
    'Route103': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825975C,
        'end': 0x08259CCA,
        'labels': {
            0x0825975C: 'Route103_Text_DaisyIntro',
            0x0825977B: 'Route103_Text_DaisyDefeated',
            0x08259795: 'Route103_Text_DaisyPostBattle',
            0x082597BA: 'Route103_Text_AmyIntro',
            0x082597E8: 'Route103_Text_AmyDefeated',
            0x082597F7: 'Route103_Text_AmyPostBattle',
            0x0825981C: 'Route103_Text_AmyNotEnoughPokemon',
            0x0825984E: 'Route103_Text_LivIntro',
            0x08259870: 'Route103_Text_LivDefeated',
            0x08259886: 'Route103_Text_LivPostBattle',
            0x082598B3: 'Route103_Text_AmyLivRegister',
            0x082598E3: 'Route103_Text_LivNotEnoughPokemon',
            0x08259922: 'Route103_Text_AmyRematchIntro',
            0x08259950: 'Route103_Text_AmyRematchDefeated',
            0x08259968: 'Route103_Text_AmyRematchPostBattle',
            0x0825998D: 'Route103_Text_AmyRematchNotEnoughPokemon',
            0x082599BF: 'Route103_Text_LivRematchIntro',
            0x082599E5: 'Route103_Text_LivRematchDefeated',
            0x082599FE: 'Route103_Text_LivRematchPostBattle',
            0x08259A31: 'Route103_Text_LivRematchNotEnoughPokemon',
            0x08259A70: 'Route103_Text_AndrewIntro',
            0x08259A93: 'Route103_Text_AndrewDefeated',
            0x08259AA9: 'Route103_Text_AndrewPostBattle',
            0x08259AC2: 'Route103_Text_MiguelIntro',
            0x08259AE3: 'Route103_Text_MiguelDefeated',
            0x08259AF7: 'Route103_Text_MiguelPostBattle',
            0x08259B17: 'Route103_Text_MiguelRegister',
            0x08259B3A: 'Route103_Text_MiguelRematchIntro',
            0x08259B5B: 'Route103_Text_MiguelRematchDefeated',
            0x08259B6D: 'Route103_Text_MiguelRematchPostBattle',
            0x08259B90: 'Route103_Text_PeteIntro',
            0x08259BAD: 'Route103_Text_PeteDefeated',
            0x08259BB6: 'Route103_Text_PetePostBattle',
            0x08259BE4: 'Route103_Text_IsabelleIntro',
            0x08259BF6: 'Route103_Text_IsabelleDefeated',
            0x08259BFB: 'Route103_Text_IsabellePostBattle',
            0x08259C27: 'Route103_Text_RhettIntro',
            0x08259C3D: 'Route103_Text_RhettDefeated',
            0x08259C46: 'Route103_Text_RhettPostBattle',
            0x08259C5C: 'Route103_Text_MarcosIntro',
            0x08259C79: 'Route103_Text_MarcosDefeated',
            0x08259C8E: 'Route103_Text_MarcosPostBattle',
        },
    },
    # Route104's trainer text is physically contiguous with the remaining
    # retained trainer-text owner.  Its start/end, every EOS boundary, and
    # caller order were checked against the Route104/Route105 US sources.
    'Route104': {
        'source': 'data/text/trainers.inc',
        'start': 0x08259CCA,
        'end': 0x0825A2BA,
        'labels': {
            0x08259CCA: 'Route104_Text_GinaIntro',
            0x08259CE7: 'Route104_Text_GinaDefeat',
            0x08259CF9: 'Route104_Text_GinaPostBattle',
            0x08259D1F: 'Route104_Text_GinaNotEnoughMons',
            0x08259D74: 'Route104_Text_MiaIntro',
            0x08259D9B: 'Route104_Text_MiaDefeat',
            0x08259DB8: 'Route104_Text_MiaPostBattle',
            0x08259DDB: 'Route104_Text_MiaNotEnoughMons',
            0x08259E1B: 'Route104_Text_IvanIntro',
            0x08259E48: 'Route104_Text_IvanDefeat',
            0x08259E6D: 'Route104_Text_IvanPostBattle',
            0x08259E91: 'Route104_Text_BillyIntro',
            0x08259EAC: 'Route104_Text_BillyDefeat',
            0x08259EC9: 'Route104_Text_BillyPostBattle',
            0x08259EF6: 'Route104_Text_HaleyIntro',
            0x08259F1B: 'Route104_Text_HaleyDefeat',
            0x08259F2D: 'Route104_Text_HaleyPostBattle',
            0x08259F6A: 'Route104_Text_HaleyRegister1',
            0x08259FA0: 'Route104_Text_HaleyRegister2',
            0x08259FD6: 'Route104_Text_HaleyRematchIntro',
            0x08259FE9: 'Route104_Text_HaleyRematchDefeat',
            0x08259FFC: 'Route104_Text_HaleyPostRematch',
            0x0825A031: 'Route104_Text_WinstonIntro',
            0x0825A04F: 'Route104_Text_WinstonDefeat',
            0x0825A05F: 'Route104_Text_WinstonPostBattle',
            0x0825A082: 'Route104_Text_WinstonRegister1',
            0x0825A0B5: 'Route104_Text_WinstonRegister2',
            0x0825A0E8: 'Route104_Text_WinstonRematchIntro',
            0x0825A10B: 'Route104_Text_WinstonRematchDefeat',
            0x0825A124: 'Route104_Text_WinstonPostRematch',
            0x0825A15D: 'Route104_Text_CindyIntro',
            0x0825A185: 'Route104_Text_CindyDefeat',
            0x0825A189: 'Route104_Text_CindyPostBattle',
            0x0825A1AB: 'Route104_Text_CindyRegister1',
            0x0825A1E5: 'Route104_Text_CindyRegister2',
            0x0825A208: 'Route104_Text_CindyRematchIntro',
            0x0825A228: 'Route104_Text_CindyRematchDefeat',
            0x0825A242: 'Route104_Text_CindyPostRematch',
            0x0825A264: 'Route104_Text_DarianIntro',
            0x0825A296: 'Route104_Text_DarianDefeat',
            0x0825A29B: 'Route104_Text_DarianPostBattle',
        },
    },
    # Route105's trainer text immediately follows the Route104 block in the
    # same physical owner.  Every EOS boundary and trainerbattle pointer was
    # checked against the JP ROM and the US Route105 source.
    'Route105': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825A2BA,
        'end': 0x0825A5D9,
        'labels': {
            0x0825A2BA: 'Route105_Text_FosterIntro',
            0x0825A2DD: 'Route105_Text_FosterDefeated',
            0x0825A2FF: 'Route105_Text_FosterPostBattle',
            0x0825A320: 'Route105_Text_LuisIntro',
            0x0825A355: 'Route105_Text_LuisDefeated',
            0x0825A35C: 'Route105_Text_LuisPostBattle',
            0x0825A380: 'Route105_Text_DominikIntro',
            0x0825A39E: 'Route105_Text_DominikDefeated',
            0x0825A3AF: 'Route105_Text_DominikPostBattle',
            0x0825A3DF: 'Route105_Text_BeverlyIntro',
            0x0825A407: 'Route105_Text_BeverlyDefeated',
            0x0825A40E: 'Route105_Text_PostBattle',
            0x0825A454: 'Route105_Text_ImaniIntro',
            0x0825A470: 'Route105_Text_ImaniDefeated',
            0x0825A486: 'Route105_Text_ImaniPostBattle',
            0x0825A4A3: 'Route105_Text_AndresIntro',
            0x0825A4BD: 'Route105_Text_AndresDefeated',
            0x0825A4D2: 'Route105_Text_AndresPostBattle',
            0x0825A4FD: 'Route105_Text_AndresRegister',
            0x0825A520: 'Route105_Text_AndresRematchIntro',
            0x0825A543: 'Route105_Text_AndresRematchDefeated',
            0x0825A553: 'Route105_Text_AndresRematchPostBattle',
            0x0825A585: 'Route105_Text_JosueIntro',
            0x0825A5A9: 'Route105_Text_JosueDefeated',
            0x0825A5BC: 'Route105_Text_JosuePostBattle',
        },
    },
    # Route106 starts immediately after Route105 in the same physical trainer
    # text owner.  Its 16 EOS-terminated messages end immediately before the
    # Route107 Darrin block at 0x0825A7CD.
    'Route106': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825A5D9,
        'end': 0x0825A7CD,
        'labels': {
            0x0825A5D9: 'Route106_Text_ElliotIntro',
            0x0825A5F1: 'Route106_Text_ElliotDefeated',
            0x0825A60D: 'Route106_Text_ElliotPostBattle',
            0x0825A631: 'Route106_Text_ElliotRegister',
            0x0825A657: 'Route106_Text_ElliotRematchIntro',
            0x0825A679: 'Route106_Text_ElliotRematchDefeated',
            0x0825A68A: 'Route106_Text_ElliotRematchPostBattle',
            0x0825A6B0: 'Route106_Text_NedIntro',
            0x0825A6F8: 'Route106_Text_NedDefeated',
            0x0825A714: 'Route106_Text_NedPostBattle',
            0x0825A72C: 'Route106_Text_DouglasIntro',
            0x0825A754: 'Route106_Text_DouglasDefeated',
            0x0825A75E: 'Route106_Text_DouglasPostBattle',
            0x0825A775: 'Route106_Text_KylaIntro',
            0x0825A797: 'Route106_Text_KylaDefeated',
            0x0825A7AB: 'Route106_Text_KylaPostBattle',
        },
    },
    # Route107 follows Route106 in the same trainer-text owner.  The next
    # EOS object is Route108 Jerome at 0x0825AB71, so this block is closed.
    'Route107': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825A7CD,
        'end': 0x0825AB71,
        'labels': {
            0x0825A7CD: 'Route107_Text_DarrinIntro',
            0x0825A7F7: 'Route107_Text_DarrinDefeated',
            0x0825A80B: 'Route107_Text_DarrinPostBattle',
            0x0825A835: 'Route107_Text_TonyIntro',
            0x0825A854: 'Route107_Text_TonyDefeated',
            0x0825A86A: 'Route107_Text_TonyPostBattle',
            0x0825A89D: 'Route107_Text_TonyRegister',
            0x0825A8BB: 'Route107_Text_TonyRematchIntro',
            0x0825A8E1: 'Route107_Text_TonyRematchDefeated',
            0x0825A909: 'Route107_Text_TonyRematchPostBattle',
            0x0825A945: 'Route107_Text_DeniseIntro',
            0x0825A95F: 'Route107_Text_DeniseDefeated',
            0x0825A967: 'Route107_Text_DenisePostBattle',
            0x0825A98C: 'Route107_Text_BethIntro',
            0x0825A9B0: 'Route107_Text_BethDefeated',
            0x0825A9C4: 'Route107_Text_BethPostBattle',
            0x0825A9E5: 'Route107_Text_LisaIntro',
            0x0825AA08: 'Route107_Text_LisaDefeated',
            0x0825AA20: 'Route107_Text_LisaPostBattle',
            0x0825AA4B: 'Route107_Text_LisaNotEnoughPokemon',
            0x0825AA6E: 'Route107_Text_RayIntro',
            0x0825AAAE: 'Route107_Text_RayDefeated',
            0x0825AAC7: 'Route107_Text_RayPostBattle',
            0x0825AAF5: 'Route107_Text_RayNotEnoughPokemon',
            0x0825AB15: 'Route107_Text_CamronIntro',
            0x0825AB36: 'Route107_Text_CamronDefeated',
            0x0825AB45: 'Route107_Text_CamronPostBattle',
        },
    },
    # Route108 follows Route107 in the same trainer-text owner.  Its final
    # Carolina message ends immediately before Route109 David at 0x0825ADE1.
    'Route108': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825AB71,
        'end': 0x0825ADE1,
        'labels': {
            0x0825AB71: 'Route108_Text_JeromeIntro',
            0x0825AB93: 'Route108_Text_JeromeDefeated',
            0x0825ABAB: 'Route108_Text_JeromePostBattle',
            0x0825ABCF: 'Route108_Text_MatthewIntro',
            0x0825ABEB: 'Route108_Text_MatthewDefeated',
            0x0825ABFF: 'Route108_Text_MatthewPostBattle',
            0x0825AC1E: 'Route108_Text_TaraIntro',
            0x0825AC43: 'Route108_Text_TaraDefeated',
            0x0825AC4F: 'Route108_Text_TaraPostBattle',
            0x0825AC75: 'Route108_Text_MissyIntro',
            0x0825AC96: 'Route108_Text_MissyDefeated',
            0x0825ACAE: 'Route108_Text_MissyPostBattle',
            0x0825ACCB: 'Route108_Text_CoryIntro',
            0x0825ACED: 'Route108_Text_CoryDefeated',
            0x0825ACFC: 'Route108_Text_CoryPostBattle',
            0x0825AD14: 'Route108_Text_CoryRegister',
            0x0825AD3A: 'Route108_Text_CoryRematchIntro',
            0x0825AD58: 'Route108_Text_CoryRematchDefeated',
            0x0825AD6B: 'Route108_Text_CoryRematchPostBattle',
            0x0825AD8F: 'Route108_Text_CarolinaIntro',
            0x0825ADAB: 'Route108_Text_CarolinaDefeated',
            0x0825ADB8: 'Route108_Text_CarolinaPostBattle',
        },
    },
    # Route109's trainer family follows Route108 in the same physical owner.
    # Its 52 EOS objects stop before Route110 Jacob at 0x0825B380.
    'Route109': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825ADE1,
        'end': 0x0825B380,
        'labels': {
            0x0825ADE1: 'Route109_Text_DavidIntro',
            0x0825ADFF: 'Route109_Text_DavidDefeated',
            0x0825AE0F: 'Route109_Text_DavidPostBattle',
            0x0825AE36: 'Route109_Text_AliceIntro',
            0x0825AE49: 'Route109_Text_AliceDefeated',
            0x0825AE51: 'Route109_Text_AlicePostBattle',
            0x0825AE72: 'Route109_Text_HueyIntro',
            0x0825AE9B: 'Route109_Text_HueyDefeated',
            0x0825AEA9: 'Route109_Text_HueyPostBattle',
            0x0825AECA: 'Route109_Text_EdmondIntro',
            0x0825AEDF: 'Route109_Text_EdmondDefeated',
            0x0825AEE6: 'Route109_Text_EdmondPostBattle',
            0x0825AF16: 'Route109_Text_RickyIntro',
            0x0825AF38: 'Route109_Text_RickyDefeated',
            0x0825AF3E: 'Route109_Text_RickyPostBattle',
            0x0825AF61: 'Route109_Text_RickyRegister',
            0x0825AF87: 'Route109_Text_RickyRematchIntro',
            0x0825AFA4: 'Route109_Text_RickyRematchDefeated',
            0x0825AFB7: 'Route109_Text_RickyRematchPostBattle',
            0x0825AFD3: 'Route109_Text_LolaIntro',
            0x0825AFEE: 'Route109_Text_LolaDefeated',
            0x0825AFF4: 'Route109_Text_LolaPostBattle',
            0x0825B01B: 'Route109_Text_LolaRegister',
            0x0825B034: 'Route109_Text_LolaRematchIntro',
            0x0825B057: 'Route109_Text_LolaRematchDefeated',
            0x0825B05D: 'Route109_Text_LolaRematchPostBattle',
            0x0825B086: 'Route109_Text_AustinaIntro',
            0x0825B0AA: 'Route109_Text_AustinaDefeated',
            0x0825B0BF: 'Route109_Text_AustinaPostBattle',
            0x0825B0D8: 'Route109_Text_GwenIntro',
            0x0825B0F3: 'Route109_Text_GwenDefeated',
            0x0825B0FD: 'Route109_Text_GwenPostBattle',
            0x0825B117: 'Route109_Text_CarterIntro',
            0x0825B12E: 'Route109_Text_CarterDefeated',
            0x0825B13D: 'Route109_Text_CarterPostBattle',
            0x0825B161: 'Route109_Text_PaulIntro',
            0x0825B189: 'Route109_Text_PaulDefeated',
            0x0825B197: 'Route109_Text_PaulPostBattle',
            0x0825B1D0: 'Route109_Text_PaulNotEnoughPokemon',
            0x0825B202: 'Route109_Text_MelIntro',
            0x0825B223: 'Route109_Text_MelDefeated',
            0x0825B24C: 'Route109_Text_MelPostBattle',
            0x0825B26E: 'Route109_Text_MelNotEnoughPokemon',
            0x0825B2A2: 'Route109_Text_ChandlerIntro',
            0x0825B2BA: 'Route109_Text_ChandlerDefeated',
            0x0825B2C4: 'Route109_Text_ChandlerPostBattle',
            0x0825B2DD: 'Route109_Text_HaileyIntro',
            0x0825B2F4: 'Route109_Text_HaileyDefeated',
            0x0825B309: 'Route109_Text_HaileyPostBattle',
            0x0825B329: 'Route109_Text_ElijahIntro',
            0x0825B347: 'Route109_Text_ElijahDefeated',
            0x0825B356: 'Route109_Text_ElijahPostBattle',
        },
    },
    # Route110's trainer family follows Route109 in the same physical owner.
    # Its 58 EOS objects stop before Route111 Drew at 0x0825BA68.
    'Route110': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825B380,
        'end': 0x0825BA68,
        'labels': {
            0x0825B380: 'Route110_Text_JacobIntro',
            0x0825B39F: 'Route110_Text_JacobDefeated',
            0x0825B3B3: 'Route110_Text_JacobPostBattle',
            0x0825B3DF: 'Route110_Text_AnthonyIntro',
            0x0825B3FC: 'Route110_Text_AnthonyDefeated',
            0x0825B406: 'Route110_Text_AnthonyPostBattle',
            0x0825B42A: 'Route110_Text_BenjaminIntro',
            0x0825B447: 'Route110_Text_BenjaminDefeated',
            0x0825B45F: 'Route110_Text_BenjaminPostBattle',
            0x0825B47F: 'Route110_Text_BenjaminRegister',
            0x0825B4A0: 'Route110_Text_BenjaminRematchIntro',
            0x0825B4C9: 'Route110_Text_BenjaminRematchDefeated',
            0x0825B4E6: 'Route110_Text_BenjaminRematchPostBattle',
            0x0825B506: 'Route110_Text_AbigailIntro',
            0x0825B538: 'Route110_Text_AbigailDefeated',
            0x0825B54A: 'Route110_Text_AbigailPostBattle',
            0x0825B567: 'Route110_Text_AbigailRegister',
            0x0825B589: 'Route110_Text_AbigailRematchIntro',
            0x0825B5AC: 'Route110_Text_AbigailRematchDefeated',
            0x0825B5C0: 'Route110_Text_AbigailRematchPostBattle',
            0x0825B5ED: 'Route110_Text_JasmineIntro',
            0x0825B60E: 'Route110_Text_JasmineDefeated',
            0x0825B61F: 'Route110_Text_JasminePostBattle',
            0x0825B63E: 'Route110_Text_EdwardIntro',
            0x0825B661: 'Route110_Text_EdwardDefeated',
            0x0825B676: 'Route110_Text_EdwardPostBattle',
            0x0825B69E: 'Route110_Text_JaclynIntro',
            0x0825B6BB: 'Route110_Text_JaclynDefeated',
            0x0825B6C8: 'Route110_Text_JaclynPostBattle',
            0x0825B6FE: 'Route110_Text_EdwinIntro',
            0x0825B720: 'Route110_Text_EdwinDefeated',
            0x0825B730: 'Route110_Text_EdwinPostBattle',
            0x0825B759: 'Route110_Text_EdwinRegister',
            0x0825B776: 'Route110_Text_EdwinRematchIntro',
            0x0825B7B2: 'Route110_Text_EdwinRematchDefeated',
            0x0825B7C5: 'Route110_Text_EdwinRematchPostBattle',
            0x0825B7EC: 'Route110_Text_DaleIntro',
            0x0825B802: 'Route110_Text_DaleDefeated',
            0x0825B810: 'Route110_Text_DalePostBattle',
            0x0825B83B: 'Route110_Text_IsabelIntro',
            0x0825B862: 'Route110_Text_IsabelDefeated',
            0x0825B86E: 'Route110_Text_IsabelPostBattle',
            0x0825B890: 'Route110_Text_IsabelRegister',
            0x0825B8BF: 'Route110_Text_IsabelRematchIntro',
            0x0825B8E1: 'Route110_Text_IsabelRematchDefeated',
            0x0825B8ED: 'Route110_Text_IsabelRematchPostBattle',
            0x0825B910: 'Route110_Text_TimmyIntro',
            0x0825B932: 'Route110_Text_TimmyDefeated',
            0x0825B944: 'Route110_Text_TimmyPostBattle',
            0x0825B963: 'Route110_Text_AlyssaIntro',
            0x0825B98E: 'Route110_Text_AlyssaDefeated',
            0x0825B99C: 'Route110_Text_AlyssaPostBattle',
            0x0825B9B9: 'Route110_Text_JosephIntro',
            0x0825B9DD: 'Route110_Text_JosephDefeated',
            0x0825B9EB: 'Route110_Text_JosephPostBattle',
            0x0825BA1A: 'Route110_Text_KalebIntro',
            0x0825BA3C: 'Route110_Text_KalebDefeated',
            0x0825BA4E: 'Route110_Text_KalebPostBattle',
        },
    },
    # Route111 immediately follows Route110.  All 63 script-referenced EOS
    # objects end exactly where the first Route112 trainer text begins.
    'Route111': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825BA68,
        'end': 0x0825C2CD,
        'labels': {
            0x0825BA68: 'Route111_Text_DrewIntro',
            0x0825BAA3: 'Route111_Text_DrewDefeat',
            0x0825BABE: 'Route111_Text_DrewPostBattle',
            0x0825BAEF: 'Route111_Text_HeidiIntro',
            0x0825BB23: 'Route111_Text_HeidiDefeat',
            0x0825BB2F: 'Route111_Text_HeidiPostBattle',
            0x0825BB67: 'Route111_Text_BeauIntro',
            0x0825BB9C: 'Route111_Text_BeauDefeat',
            0x0825BBAD: 'Route111_Text_BeauPostBattle',
            0x0825BBE6: 'Route111_Text_BeckyIntro',
            0x0825BC09: 'Route111_Text_BeckyDefeat',
            0x0825BC13: 'Route111_Text_BeckyPostBattle',
            0x0825BC3B: 'Route111_Text_DustyIntro',
            0x0825BC5D: 'Route111_Text_DustyDefeat',
            0x0825BC7D: 'Route111_Text_DustyPostBattle',
            0x0825BCAD: 'Route111_Text_DustyRegister',
            0x0825BCD6: 'Route111_Text_DustyRematchIntro',
            0x0825BD0B: 'Route111_Text_DustyRematchDefeat',
            0x0825BD28: 'Route111_Text_DustyPostRematch',
            0x0825BD6C: 'Route111_Text_TravisIntro',
            0x0825BD8D: 'Route111_Text_TravisDefeat',
            0x0825BD9E: 'Route111_Text_TravisPostBattle',
            0x0825BDCA: 'Route111_Text_IreneIntro',
            0x0825BDEB: 'Route111_Text_IreneDefeat',
            0x0825BDFA: 'Route111_Text_IrenePostBattle',
            0x0825BE2B: 'Route111_Text_DaisukeIntro',
            0x0825BE56: 'Route111_Text_DaisukeDefeat',
            0x0825BE60: 'Route111_Text_DaisukePostBattle',
            0x0825BE88: 'Route111_Text_WiltonIntro',
            0x0825BEA9: 'Route111_Text_WiltonDefeat',
            0x0825BEBA: 'Route111_Text_WiltonPostBattle',
            0x0825BEF4: 'Route111_Text_WiltonRegister',
            0x0825BF1E: 'Route111_Text_WiltonRematchIntro',
            0x0825BF59: 'Route111_Text_WiltonRematchDefeat',
            0x0825BF63: 'Route111_Text_WiltonPostRematch',
            0x0825BF81: 'Route111_Text_BrookeIntro',
            0x0825BFAB: 'Route111_Text_BrookeDefeat',
            0x0825BFBD: 'Route111_Text_BrookePostBattle',
            0x0825BFEC: 'Route111_Text_BrookeRegister',
            0x0825C00A: 'Route111_Text_BrookeRematchIntro',
            0x0825C04C: 'Route111_Text_BrookeRematchDefeat',
            0x0825C05D: 'Route111_Text_BrookePostRematch',
            0x0825C092: 'Route111_Text_CeliaIntro',
            0x0825C0AE: 'Route111_Text_CeliaDefeat',
            0x0825C0C2: 'Route111_Text_CeliaPostBattle',
            0x0825C0F5: 'Route111_Text_BryanIntro',
            0x0825C115: 'Route111_Text_BryanDefeat',
            0x0825C129: 'Route111_Text_BryanPostBattle',
            0x0825C141: 'Route111_Text_BrandenIntro',
            0x0825C15F: 'Route111_Text_BrandenDefeat',
            0x0825C179: 'Route111_Text_BrandenPostBattle',
            0x0825C192: 'Route111_Text_TyronIntro',
            0x0825C1A7: 'Route111_Text_TyronDefeat',
            0x0825C1C4: 'Route111_Text_TyronPostBattle',
            0x0825C1F5: 'Route111_Text_CelinaIntro',
            0x0825C20C: 'Route111_Text_CelinaDefeat',
            0x0825C21C: 'Route111_Text_CelinaPostBattle',
            0x0825C240: 'Route111_Text_HaydenIntro',
            0x0825C262: 'Route111_Text_HaydenDefeat',
            0x0825C268: 'Route111_Text_HaydenPostBattle',
            0x0825C283: 'Route111_Text_BiancaIntro',
            0x0825C2A9: 'Route111_Text_BiancaDefeat',
            0x0825C2B4: 'Route111_Text_BiancaPostBattle',
        },
    },
    'Route112': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825C2CD,
        'end': 0x0825C5C8,
        'labels': {
            0x0825C2CD: 'Route112_Text_BriceIntro',
            0x0825C2F1: 'Route112_Text_BriceDefeat',
            0x0825C2FF: 'Route112_Text_BricePostBattle',
            0x0825C329: 'Route112_Text_TrentIntro',
            0x0825C352: 'Route112_Text_TrentDefeat',
            0x0825C360: 'Route112_Text_TrentPostBattle',
            0x0825C397: 'Route112_Text_TrentRegister',
            0x0825C3E5: 'Route112_Text_TrentRematchIntro',
            0x0825C401: 'Route112_Text_TrentRematchDefeat',
            0x0825C40C: 'Route112_Text_TrentRematchPostBattle',
            0x0825C43E: 'Route112_Text_LarryIntro',
            0x0825C45C: 'Route112_Text_LarryDefeat',
            0x0825C464: 'Route112_Text_LarryPostBattle',
            0x0825C48B: 'Route112_Text_CarolIntro',
            0x0825C4AB: 'Route112_Text_CarolDefeat',
            0x0825C4BA: 'Route112_Text_CarolPostBattle',
            0x0825C4EF: 'Route112_Text_BryantIntro',
            0x0825C513: 'Route112_Text_BryantDefeat',
            0x0825C51C: 'Route112_Text_BryantPostBattle',
            0x0825C538: 'Route112_Text_ShaylaIntro',
            0x0825C56E: 'Route112_Text_ShaylaDefeat',
            0x0825C58A: 'Route112_Text_ShaylaPostBattle',
        },
    },
    'Route113': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825C5C8,
        'end': 0x0825CAE3,
        'labels': {
            0x0825C5C8: 'Route113_Text_JaylenIntro',
            0x0825C5E7: 'Route113_Text_JaylenDefeat',
            0x0825C5F4: 'Route113_Text_JaylenPostBattle',
            0x0825C629: 'Route113_Text_DillonIntro',
            0x0825C644: 'Route113_Text_DillonDefeat',
            0x0825C650: 'Route113_Text_DillonPostBattle',
            0x0825C67D: 'Route113_Text_MadelineIntro',
            0x0825C6A8: 'Route113_Text_MadelineDefeat',
            0x0825C6BA: 'Route113_Text_MadelinePostBattle',
            0x0825C6D7: 'Route113_Text_MadelineRegister',
            0x0825C6FB: 'Route113_Text_MadelineRematchIntro',
            0x0825C716: 'Route113_Text_MadelineRematchDefeat',
            0x0825C71F: 'Route113_Text_MadelinePostRematch',
            0x0825C73F: 'Route113_Text_LaoIntro',
            0x0825C75B: 'Route113_Text_LaoDefeat',
            0x0825C765: 'Route113_Text_LaoPostBattle',
            0x0825C78B: 'Route113_Text_LaoRegister',
            0x0825C7A8: 'Route113_Text_LaoRematchIntro',
            0x0825C7C5: 'Route113_Text_LaoRematchDefeat',
            0x0825C7CF: 'Route113_Text_LaoPostRematch',
            0x0825C7FE: 'Route113_Text_LungIntro',
            0x0825C81C: 'Route113_Text_LungDefeat',
            0x0825C83A: 'Route113_Text_LungPostBattle',
            0x0825C860: 'Route113_Text_ToriIntro',
            0x0825C889: 'Route113_Text_ToriDefeat',
            0x0825C8A7: 'Route113_Text_ToriPostBattle',
            0x0825C8D3: 'Route113_Text_ToriNotEnoughMons',
            0x0825C8FA: 'Route113_Text_TiaIntro',
            0x0825C923: 'Route113_Text_TiaDefeat',
            0x0825C941: 'Route113_Text_TiaPostBattle',
            0x0825C96C: 'Route113_Text_TiaNotEnoughMons',
            0x0825C992: 'Route113_Text_CobyIntro',
            0x0825C9AF: 'Route113_Text_CobyDefeat',
            0x0825C9B5: 'Route113_Text_CobyPostBattle',
            0x0825C9D9: 'Route113_Text_SophieIntro',
            0x0825C9FD: 'Route113_Text_SophieDefeat',
            0x0825CA0D: 'Route113_Text_SophiePostBattle',
            0x0825CA30: 'Route113_Text_LawrenceIntro',
            0x0825CA4B: 'Route113_Text_LawrenceDefeat',
            0x0825CA57: 'Route113_Text_LawrencePostBattle',
            0x0825CA6B: 'Route113_Text_WyattIntro',
            0x0825CA91: 'Route113_Text_WyattDefeat',
            0x0825CAB6: 'Route113_Text_WyattPostBattle',
        },
    },
    'Route114': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825CAE3,
        'end': 0x0825D0DE,
        'labels': {
            0x0825CAE3: 'Route114_Text_LennyIntro',
            0x0825CB08: 'Route114_Text_LennyDefeat',
            0x0825CB0F: 'Route114_Text_LennyPostBattle',
            0x0825CB45: 'Route114_Text_LucasIntro',
            0x0825CB60: 'Route114_Text_LucasDefeat',
            0x0825CB6F: 'Route114_Text_LucasPostBattle',
            0x0825CB93: 'Route114_Text_ShaneIntro',
            0x0825CBCA: 'Route114_Text_ShaneDefeat',
            0x0825CBD3: 'Route114_Text_ShanePostBattle',
            0x0825CBF7: 'Route114_Text_NancyIntro',
            0x0825CC15: 'Route114_Text_NancyDefeat',
            0x0825CC1E: 'Route114_Text_NancyPostBattle',
            0x0825CC3F: 'Route114_Text_SteveIntro',
            0x0825CC5B: 'Route114_Text_SteveDefeat',
            0x0825CC68: 'Route114_Text_StevePostBattle',
            0x0825CCAA: 'Route114_Text_SteveRegister',
            0x0825CCCD: 'Route114_Text_SteveRematchIntro',
            0x0825CCEA: 'Route114_Text_SteveRematchDefeat',
            0x0825CD05: 'Route114_Text_StevePostRematch',
            0x0825CD2E: 'Route114_Text_BernieIntro',
            0x0825CD56: 'Route114_Text_BernieDefeat',
            0x0825CD6B: 'Route114_Text_BerniePostBattle',
            0x0825CD92: 'Route114_Text_BernieRegister',
            0x0825CDB2: 'Route114_Text_BernieRematchIntro',
            0x0825CDE0: 'Route114_Text_BernieRematchDefeat',
            0x0825CDF4: 'Route114_Text_BerniePostRematch',
            0x0825CE1B: 'Route114_Text_ClaudeIntro',
            0x0825CE48: 'Route114_Text_ClaudeDefeat',
            0x0825CE5A: 'Route114_Text_ClaudePostBattle',
            0x0825CE8B: 'Route114_Text_NolanIntro',
            0x0825CEC1: 'Route114_Text_NolanDefeat',
            0x0825CEDD: 'Route114_Text_NolanPostBattle',
            0x0825CF00: 'Route114_Text_TyraIntro',
            0x0825CF2D: 'Route114_Text_TyraDefeat',
            0x0825CF3C: 'Route114_Text_TyraPostBattle',
            0x0825CF5F: 'Route114_Text_TyraNotEnoughMons',
            0x0825CF8B: 'Route114_Text_IvyIntro',
            0x0825CFA3: 'Route114_Text_IvyDefeat',
            0x0825CFB2: 'Route114_Text_IvyPostBattle',
            0x0825CFDE: 'Route114_Text_IvyNotEnoughMons',
            0x0825D005: 'Route114_Text_KaiIntro',
            0x0825D017: 'Route114_Text_KaiDefeat',
            0x0825D028: 'Route114_Text_KaiPostBattle',
            0x0825D040: 'Route114_Text_CharlotteIntro',
            0x0825D057: 'Route114_Text_CharlotteDefeat',
            0x0825D062: 'Route114_Text_CharlottePostBattle',
            0x0825D08B: 'Route114_Text_AngelinaIntro',
            0x0825D0A8: 'Route114_Text_AngelinaDefeat',
            0x0825D0B2: 'Route114_Text_AngelinaPostBattle',
        },
    },
    'Route115': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825D0DE,
        'end': 0x0825D5E4,
        'labels': {
            0x0825D0DE: 'Route115_Text_TimothyIntro',
            0x0825D103: 'Route115_Text_TimothyDefeat',
            0x0825D116: 'Route115_Text_TimothyPostBattle',
            0x0825D13E: 'Route115_Text_TimothyRegister',
            0x0825D168: 'Route115_Text_TimothyRematchIntro',
            0x0825D18D: 'Route115_Text_TimothyRematchDefeat',
            0x0825D19D: 'Route115_Text_TimothyPostRematch',
            0x0825D1C2: 'Route115_Text_KoichiIntro',
            0x0825D1E0: 'Route115_Text_KoichiDefeat',
            0x0825D1E8: 'Route115_Text_KoichiPostBattle',
            0x0825D219: 'Route115_Text_NobIntro',
            0x0825D237: 'Route115_Text_NobDefeat',
            0x0825D24A: 'Route115_Text_NobPostBattle',
            0x0825D27C: 'Route115_Text_NobRegister',
            0x0825D29B: 'Route115_Text_NobRematchIntro',
            0x0825D2CF: 'Route115_Text_NobRematchDefeat',
            0x0825D2DF: 'Route115_Text_NobPostRematch',
            0x0825D302: 'Route115_Text_CyndyIntro',
            0x0825D331: 'Route115_Text_CyndyDefeat',
            0x0825D341: 'Route115_Text_CyndyPostBattle',
            0x0825D36F: 'Route115_Text_CyndyRegister',
            0x0825D39F: 'Route115_Text_CyndyRematchIntro',
            0x0825D3B1: 'Route115_Text_CyndyRematchDefeat',
            0x0825D3C6: 'Route115_Text_CyndyPostRematch',
            0x0825D3ED: 'Route115_Text_HectorIntro',
            0x0825D413: 'Route115_Text_HectorDefeat',
            0x0825D429: 'Route115_Text_HectorPostBattle',
            0x0825D454: 'Route115_Text_KyraIntro',
            0x0825D478: 'Route115_Text_KyraDefeat',
            0x0825D480: 'Route115_Text_KyraPostBattle',
            0x0825D4B3: 'Route115_Text_JaidenIntro',
            0x0825D4CB: 'Route115_Text_JaidenDefeat',
            0x0825D4D6: 'Route115_Text_JaidenPostBattle',
            0x0825D4F2: 'Route115_Text_HeleneIntro',
            0x0825D513: 'Route115_Text_HeleneDefeat',
            0x0825D51C: 'Route115_Text_HelenePostBattle',
            0x0825D550: 'Route115_Text_AlixIntro',
            0x0825D564: 'Route115_Text_AlixDefeat',
            0x0825D56F: 'Route115_Text_AlixPostBattle',
            0x0825D588: 'Route115_Text_MarleneIntro',
            0x0825D5A9: 'Route115_Text_MarleneDefeat',
            0x0825D5B8: 'Route115_Text_MarlenePostBattle',
        },
    },
    'Route116': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825D5E4,
        'end': 0x0825DB1F,
        'labels': {
            0x0825D5E4: 'Route116_Text_ClarkIntro',
            0x0825D607: 'Route116_Text_ClarkDefeat',
            0x0825D61F: 'Route116_Text_ClarkPostBattle',
            0x0825D643: 'Route116_Text_JoeyIntro',
            0x0825D65E: 'Route116_Text_JoeyDefeat',
            0x0825D67E: 'Route116_Text_JoeyPostBattle',
            0x0825D69F: 'Route116_Text_JoseIntro',
            0x0825D6BC: 'Route116_Text_JoseDefeat',
            0x0825D6D2: 'Route116_Text_JosePostBattle',
            0x0825D6F3: 'Route116_Text_JaniceIntro',
            0x0825D718: 'Route116_Text_JaniceDefeat',
            0x0825D72C: 'Route116_Text_JanicePostBattle',
            0x0825D753: 'Route116_Text_JerryIntro',
            0x0825D77F: 'Route116_Text_JerryDefeat',
            0x0825D795: 'Route116_Text_JerryPostBattle',
            0x0825D7C6: 'Route116_Text_JerryRegister1',
            0x0825D80A: 'Route116_Text_JerryRegister2',
            0x0825D84E: 'Route116_Text_JerryRematchIntro',
            0x0825D885: 'Route116_Text_JerryRematchDefeat',
            0x0825D89A: 'Route116_Text_JerryPostRematch',
            0x0825D8CB: 'Route116_Text_KarenIntro',
            0x0825D8E9: 'Route116_Text_KarenDefeat',
            0x0825D8F6: 'Route116_Text_KarenPostBattle',
            0x0825D91F: 'Route116_Text_KarenRegister1',
            0x0825D941: 'Route116_Text_KarenRegister2',
            0x0825D963: 'Route116_Text_KarenRematchIntro',
            0x0825D98B: 'Route116_Text_KarenRematchDefeat',
            0x0825D99B: 'Route116_Text_KarenPostRematch',
            0x0825D9C3: 'Route116_Text_SarahIntro',
            0x0825D9E7: 'Route116_Text_SarahDefeat',
            0x0825D9F8: 'Route116_Text_SarahPostBattle',
            0x0825DA28: 'Route116_Text_DawsonIntro',
            0x0825DA50: 'Route116_Text_DawsonDefeat',
            0x0825DA5C: 'Route116_Text_DawsonPostBattle',
            0x0825DA89: 'Route116_Text_DevanIntro',
            0x0825DA98: 'Route116_Text_DevanDefeat',
            0x0825DAAB: 'Route116_Text_DevanPostBattle',
            0x0825DACB: 'Route116_Text_JohnsonIntro',
            0x0825DAEE: 'Route116_Text_JohnsonDefeat',
            0x0825DAFF: 'Route116_Text_JohnsonPostBattle',
        },
    },
    'Route117': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825DB1F,
        'end': 0x0825E321,
        'labels': {
            0x0825DB1F: 'Route117_Text_IsaacIntro',
            0x0825DB3E: 'Route117_Text_IsaacDefeat',
            0x0825DB4C: 'Route117_Text_IsaacPostBattle',
            0x0825DB83: 'Route117_Text_IsaacRegister',
            0x0825DBAD: 'Route117_Text_IsaacRematchIntro',
            0x0825DBCF: 'Route117_Text_IsaacRematchDefeat',
            0x0825DBF4: 'Route117_Text_IsaacPostRematch',
            0x0825DC27: 'Route117_Text_LydiaIntro',
            0x0825DC4A: 'Route117_Text_LydiaDefeat',
            0x0825DC57: 'Route117_Text_LydiaPostBattle',
            0x0825DC78: 'Route117_Text_LydiaRegister',
            0x0825DCA2: 'Route117_Text_LydiaRematchIntro',
            0x0825DCC8: 'Route117_Text_LydiaRematchDefeat',
            0x0825DCD5: 'Route117_Text_LydiaPostRematch',
            0x0825DCF7: 'Route117_Text_DylanIntro',
            0x0825DD21: 'Route117_Text_DylanDefeat',
            0x0825DD2E: 'Route117_Text_DylanPostBattle',
            0x0825DD55: 'Route117_Text_DylanRegister',
            0x0825DD7C: 'Route117_Text_DylanRematchIntro',
            0x0825DDB6: 'Route117_Text_DylanRematchDefeat',
            0x0825DDC6: 'Route117_Text_DylanPostRematch',
            0x0825DDF0: 'Route117_Text_MariaIntro',
            0x0825DE21: 'Route117_Text_MariaDefeat',
            0x0825DE32: 'Route117_Text_MariaPostBattle',
            0x0825DE60: 'Route117_Text_MariaRegister',
            0x0825DE84: 'Route117_Text_MariaRematchIntro',
            0x0825DEB6: 'Route117_Text_MariaRematchDefeat',
            0x0825DEC7: 'Route117_Text_MariaPostRematch',
            0x0825DEEE: 'Route117_Text_DerekIntro',
            0x0825DF2B: 'Route117_Text_DerekDefeat',
            0x0825DF3E: 'Route117_Text_DerekPostBattle',
            0x0825DF8B: 'Route117_Text_AnnaIntro',
            0x0825DFB1: 'Route117_Text_AnnaDefeat',
            0x0825DFCC: 'Route117_Text_AnnaPostBattle',
            0x0825E00A: 'Route117_Text_AnnaAndMegRegister',
            0x0825E033: 'Route117_Text_AnnaNotEnoughMons',
            0x0825E05B: 'Route117_Text_MegIntro',
            0x0825E07E: 'Route117_Text_MegDefeat',
            0x0825E092: 'Route117_Text_MegPostBattle',
            0x0825E0C4: 'Route117_Text_MegNotEnoughMons',
            0x0825E105: 'Route117_Text_AnnaRematchIntro',
            0x0825E122: 'Route117_Text_AnnaRematchDefeat',
            0x0825E133: 'Route117_Text_AnnaPostRematch',
            0x0825E170: 'Route117_Text_AnnaRematchNotEnoughMons',
            0x0825E198: 'Route117_Text_MegRematchIntro',
            0x0825E1BC: 'Route117_Text_MegRematchDefeat',
            0x0825E1C6: 'Route117_Text_MegPostRematch',
            0x0825E1F0: 'Route117_Text_MegRematchNotEnoughMons',
            0x0825E231: 'Route117_Text_MelinaIntro',
            0x0825E252: 'Route117_Text_MelinaDefeat',
            0x0825E262: 'Route117_Text_MelinaPostBattle',
            0x0825E27A: 'Route117_Text_BrandiIntro',
            0x0825E297: 'Route117_Text_BrandiDefeat',
            0x0825E29E: 'Route117_Text_BrandiPostBattle',
            0x0825E2C3: 'Route117_Text_AishaIntro',
            0x0825E2D9: 'Route117_Text_AishaDefeat',
            0x0825E2FD: 'Route117_Text_AishaPostBattle',
        },
    },
    'Route118': {
        'source': 'data/text/trainers.inc',
        'start': 0x0825E321,
        'end': 0x0825E688,
        'labels': {
            0x0825E321: 'Route118_Text_RoseIntro',
            0x0825E346: 'Route118_Text_RoseDefeat',
            0x0825E353: 'Route118_Text_RosePostBattle',
            0x0825E37F: 'Route118_Text_RoseRegister',
            0x0825E3A3: 'Route118_Text_RoseRematchIntro',
            0x0825E3BB: 'Route118_Text_RoseRematchDefeat',
            0x0825E3D4: 'Route118_Text_RosePostRematch',
            0x0825E3F9: 'Route118_Text_PerryIntro',
            0x0825E418: 'Route118_Text_PerryDefeat',
            0x0825E423: 'Route118_Text_PerryPostBattle',
            0x0825E448: 'Route118_Text_ChesterIntro',
            0x0825E45B: 'Route118_Text_ChesterDefeat',
            0x0825E465: 'Route118_Text_ChesterPostBattle',
            0x0825E483: 'Route118_Text_BarnyIntro',
            0x0825E4AF: 'Route118_Text_BarnyDefeat',
            0x0825E4BE: 'Route118_Text_BarnyPostBattle',
            0x0825E4EC: 'Route118_Text_WadeIntro',
            0x0825E520: 'Route118_Text_WadeDefeat',
            0x0825E532: 'Route118_Text_WadePostBattle',
            0x0825E554: 'Route118_Text_DaltonIntro',
            0x0825E56D: 'Route118_Text_DaltonDefeat',
            0x0825E575: 'Route118_Text_DaltonPostBattle',
            0x0825E5B1: 'Route118_Text_DaltonRegister',
            0x0825E5CC: 'Route118_Text_DaltonRematchIntro',
            0x0825E5EB: 'Route118_Text_DaltonRematchDefeat',
            0x0825E5F3: 'Route118_Text_DaltonPostRematch',
            0x0825E622: 'Route118_Text_DeandreIntro',
            0x0825E63F: 'Route118_Text_DeandreDefeat',
            0x0825E662: 'Route118_Text_DeandrePostBattle',
        },
    },
}

# Reviewed JP-to-US names for maps whose event positions, control-flow shape,
# and text/movement ordering have all been checked against the US source.  This
# is intentionally an allowlist: unreviewed addresses keep deterministic
# address labels instead of receiving a plausible-but-unproven semantic name.
MAP_VERIFIED_SEMANTIC_LABELS = {
    # These unreferenced Rustboro entries retain the corresponding US names
    # instead of being emitted as address-only scripts or text.
    'RustboroCity': {
        'scripts': {
            0x081DE937: 'RustboroCity_EventScript_DevonCorpBranchOfficeSign',
            0x081DEA74: 'RustboroCity_EventScript_ShadyCharacterTookOff',
            0x081DEA7D: 'RustboroCity_EventScript_YouGotItThankYou',
            0x081DEA86: 'RustboroCity_EventScript_EmployeeApproachUp',
            0x081DEA91: 'RustboroCity_EventScript_EmployeeApproachLeft',
            0x081DEA9C: 'RustboroCity_EventScript_EmployeeApproachRight',
            0x081DEAA7: 'RustboroCity_EventScript_EmployeeApproachDown',
            0x081DEAB2: 'RustboroCity_EventScript_EmployeeApproachPlayerFar',
        },
        'texts': {
            0x081DFB7E: 'RustboroCity_Text_DevonCorpBranchOfficeSign',
        },
    },
    # Wally's Pokenav registration is entered from field_control_avatar.c.
    # Its two text records are still map-owned and use the same names and
    # player placeholder convention as the matching US Mauville source.
    'MauvilleCity': {
        'scripts': {
            0x081DDDF3: 'MauvilleCity_EventScript_RegisterWallyCall',
        },
        'texts': {
            0x081DE1A8: 'MauvilleCity_Text_WallyPokenavCall',
            0x081DE221: 'MauvilleCity_Text_RegisteredWally',
        },
        'field_placeholders': {
            0x081DE1A8: {0x01: 'PLAYER'},
        },
    },
    # Fallarbor's complete Battle Tent lobby was aligned by control flow,
    # event-table order, and each shared text pointer with the matching US
    # source. Keep the reviewed names here so a fresh map-script emission
    # retains the same semantic ownership rather than falling back to addresses.
    'FallarborTown_BattleTentLobby': {
        'scripts': {
            0x081F519A: 'FallarborTown_BattleTentLobby_EventScript_TurnPlayerNorth',
            0x081F51CE: 'FallarborTown_BattleTentLobby_EventScript_GetChallengeStatus',
            0x081F51D7: 'FallarborTown_BattleTentLobby_EventScript_QuitWithoutSaving',
            0x081F520C: 'FallarborTown_BattleTentLobby_EventScript_WonChallenge',
            0x081F5246: 'FallarborTown_BattleTentLobby_EventScript_GivePrize',
            0x081F5292: 'FallarborTown_BattleTentLobby_EventScript_NoRoomForPrize',
            0x081F52A3: 'FallarborTown_BattleTentLobby_EventScript_PrizeWaiting',
            0x081F52B2: 'FallarborTown_BattleTentLobby_EventScript_LostChallenge',
            0x081F52EC: 'FallarborTown_BattleTentLobby_EventScript_ResumeChallenge',
            0x081F5320: 'FallarborTown_BattleTentLobby_EventScript_Attendant',
            0x081F5340: 'FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge',
            0x081F537C: 'FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge',
            0x081F5401: 'FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge',
            0x081F545B: 'FallarborTown_BattleTentLobby_EventScript_EnterChallenge',
            0x081F5488: 'FallarborTown_BattleTentLobby_EventScript_ExplainChallenge',
            0x081F5495: 'FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons',
            0x081F54B0: 'FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50',
            0x081F54BD: 'FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen',
            0x081F54CA: 'FallarborTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed',
            0x081F54E1: 'FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge',
            0x081F54E4: 'FallarborTown_BattleTentLobby_EventScript_CancelChallenge',
            0x081F54EC: 'FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge',
            0x081F54EE: 'FallarborTown_BattleTentLobby_EventScript_WalkToDoor',
            0x081F552C: 'FallarborTown_BattleTentLobby_EventScript_Hiker',
            0x081F5535: 'FallarborTown_BattleTentLobby_EventScript_LittleBoy',
            0x081F553E: 'FallarborTown_BattleTentLobby_EventScript_Lass',
            0x081F5547: 'FallarborTown_BattleTentLobby_EventScript_Scott',
            0x081F5564: 'FallarborTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo',
            0x081F556E: 'FallarborTown_BattleTentLobby_EventScript_RulesBoard',
            0x081F557D: 'FallarborTown_BattleTentLobby_EventScript_ReadRulesBoard',
            0x081F55DB: 'FallarborTown_BattleTentLobby_EventScript_RulesLevel',
            0x081F55E9: 'FallarborTown_BattleTentLobby_EventScript_RulesBattle',
            0x081F55F7: 'FallarborTown_BattleTentLobby_EventScript_RulesMind',
            0x081F5605: 'FallarborTown_BattleTentLobby_EventScript_RulesSkill',
            0x081F5613: 'FallarborTown_BattleTentLobby_EventScript_RulesBody',
            0x081F5621: 'FallarborTown_BattleTentLobby_EventScript_ExitRules',
        },
        'tables': {
            0x081F5190: 'FallarborTown_BattleTentLobby_OnWarp',
            0x081F51A4: 'FallarborTown_BattleTentLobby_OnFrame',
        },
        'texts': {
            0x081F5623: 'FallarborTown_BattleTentLobby_Text_MakeThinkImJustKid',
            0x081F5657: 'FallarborTown_BattleTentLobby_Text_FallarborTentMyFavorite',
            0x081F56C2: 'FallarborTown_BattleTentLobby_Text_CameToCampOut',
            0x081F5708: 'FallarborTown_BattleTentLobby_Text_ScottLookingForSomeone',
            0x081F57A2: 'FallarborTown_BattleTentLobby_Text_ScottMakeChallenge',
        },
        'field_placeholders': {
            0x081F5708: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_texts': {
            0x08274A30: 'FallarborTown_BattleTentLobby_Text_WelcomeToBattleTent',
            0x08274A71: 'FallarborTown_BattleTentLobby_Text_TakeChallenge',
            0x08274A8B: 'FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge',
            0x08274AA3: 'FallarborTown_BattleTentLobby_Text_ExplainFallarborTent',
            0x08274C14: 'FallarborTown_BattleTentLobby_Text_SaveBeforeChallenge',
            0x08274C64: 'FallarborTown_BattleTentLobby_Text_SelectThreeMons',
            0x08274C84: 'FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLv50',
            0x08274CFD: 'FallarborTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen',
            0x08274DA3: 'FallarborTown_BattleTentLobby_Text_GuideYouToBattleTent',
            0x08274DB9: 'FallarborTown_BattleTentLobby_Text_DidntSaveBeforeQuitting',
            0x08274E1B: 'FallarborTown_BattleTentLobby_Text_BeatThreeTrainers',
            0x08274E34: 'FallarborTown_BattleTentLobby_Text_WaitWhileSaveGame',
            0x08274E4A: 'FallarborTown_BattleTentLobby_Text_PresentYouWithPrize',
            0x08274E74: 'FallarborTown_BattleTentLobby_Text_ReceivedPrize',
            0x08274E82: 'FallarborTown_BattleTentLobby_Text_BagFullReturnForPrize',
            0x08274EB4: 'FallarborTown_BattleTentLobby_Text_ThankYouWaitWhileSaving',
            0x08274ED5: 'FallarborTown_BattleTentLobby_Text_AwaitAnotherChallenge2',
            0x08274EED: 'FallarborTown_BattleTentLobby_Text_LookingForwardToArrival',
            0x08275BCD: 'BattleTentLobby_Text_ExplainLevelRules',
            0x0822FD87: 'BattleFrontier_BattleArenaLobby_Text_RulesAreListed',
            0x0822FDA0: 'BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading',
            0x0822FDB0: 'BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules',
            0x0822FE72: 'BattleFrontier_BattleArenaLobby_Text_ExplainMindRules',
            0x0822FECB: 'BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules',
            0x0822FFB6: 'BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules',
        },
        'external_labels': {
            0x082423E9: 'Common_EventScript_SaveGame',
        },
        'specials': {
            0x080F9D20: 'ChoosePartyForBattleFrontier',
        },
        'symbols': {
            'vars': {
                0x4000: 'VAR_TEMP_CHALLENGE_STATUS',
                0x4001: 'VAR_TEMP_1',
                0x40CE: 'VAR_FRONTIER_BATTLE_MODE',
                0x40CF: 'VAR_FRONTIER_FACILITY',
                0x40D1: 'VAR_SCOTT_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8006: 'VAR_0x8006',
                0x800D: 'VAR_RESULT',
            },
            'script_var_values': {
                0x081F5246: {0x8000: {0x0: 'FALSE'}},
                0x081F5320: {0x800D: {0x0: 'ITEM_NONE'}},
                0x081F537C: {0x8004: {0x1: 'TRUE'}},
                0x081F5401: {0x800D: {0x0: 'FALSE'}},
                0x081F5495: {
                    0x8000: {
                        0x0: 'FRONTIER_LVL_50',
                        0x1: 'FRONTIER_LVL_OPEN',
                    },
                },
            },
            'maps': {0x0502: 'MAP_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR'},
            'local_ids': {
                0x0001: 'LOCALID_FALLARBOR_TENT_ATTENDANT',
                0x00FF: 'LOCALID_PLAYER',
            },
            'directions': {0x02: 'DIR_NORTH'},
            'songs': {0x0172: 'MUS_OBTAIN_ITEM'},
            'sounds': {0x37: 'SE_SAVE'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'multichoices': {
                0x17: 'MULTI_CHALLENGEINFO',
                0x70: 'MULTI_FALLARBOR_TENT_RULES',
            },
            'fade_modes': {0x1: 'FADE_TO_BLACK'},
        },
    },
    # The two mirrored houses share PlayersHouse/RivalsHouse handlers, but
    # their rival roles are gender-dependent.  These names follow the actual
    # JP control flow and the corresponding US map sources, not address order.
    'LittlerootTown_BrendansHouse_1F': {
        'scripts': {
            0x081EF795: 'LittlerootTown_BrendansHouse_1F_OnLoad',
            0x081EF7AA: 'LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes',
            0x081EF7BD: 'LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual',
            0x081EF7CA: 'LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual',
            0x081EF7D4: 'LittlerootTown_BrendansHouse_1F_OnTransition',
            0x081EF7F6: 'LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs',
            0x081EF802: 'LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV',
            0x081EF80E: 'LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor',
            0x081EF844: 'LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock',
            0x081EF86C: 'LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn',
            0x081EF87D: 'LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport',
            0x081EF88E: 'LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor',
            0x081EF8D3: 'LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom',
            0x081EF8EE: 'LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0',
            0x081EF8FA: 'LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1',
            0x081EF906: 'LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2',
            0x081EF912: 'LittlerootTown_BrendansHouse_1F_EventScript_MeetRival',
            0x081EF9B1: 'LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan',
            0x081EF9BC: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0',
            0x081EF9C7: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1',
            0x081EF9D2: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2',
            0x081EF9F1: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0',
            0x081EFA03: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1',
            0x081EFA15: 'LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2',
        },
        'tables': {
            0x081EF81A: 'LittlerootTown_BrendansHouse_1F_OnFrame',
        },
        'texts': {
            0x081EFA4C: 'PlayersHouse_1F_Text_IsntItNiceInHere',
            0x081EFA68: 'PlayersHouse_1F_Text_MoversPokemonGoSetClock',
            0x081EFAE5: 'PlayersHouse_1F_Text_ArentYouInterestedInRoom',
            0x081EFAFC: 'PlayersHouse_1F_Text_GoSetTheClock',
            0x081EFB12: 'PlayersHouse_1F_Text_OhComeQuickly',
            0x081EFB33: 'PlayersHouse_1F_Text_MaybeDadWillBeOn',
            0x081EFB52: 'PlayersHouse_1F_Text_ItsOverWeMissedHim',
            0x081EFB7A: 'PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor',
            0x081EFBCF: 'PlayersHouse_1F_Text_SeeYouHoney',
            0x081EFBDC: 'PlayersHouse_1F_Text_DidYouMeetProfBirch',
            0x081EFBF0: 'PlayersHouse_1F_Text_YouShouldRestABit',
            0x081EFC1E: 'PlayersHouse_1F_Text_TakeCareHoney',
            0x081EFC2D: 'PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom',
            0x081EFC59: 'PlayersHouse_1F_Text_DontPushYourselfTooHard',
            0x081EFC89: 'PlayersHouse_1F_Text_IsThatAPokenav',
            0x081EFCD3: 'PlayersHouse_1F_Text_RegisteredMom',
            0x081EFCE6: 'PlayersHouse_1F_Text_Vigoroth1',
            0x081EFCEB: 'PlayersHouse_1F_Text_Vigoroth2',
            0x081EFCF7: 'PlayersHouse_1F_Text_ReportFromPetalburgGym',
            0x081EFD18: 'PlayersHouse_1F_Text_TheresAMovieOnTV',
            0x081EFD5A: 'PlayersHouse_1F_Text_RunningShoesManual',
            0x081EFDC8: 'PlayersHouse_1F_Text_TicketFromBrineyCameForYou',
            0x081EFE2F: 'PlayersHouse_1F_Text_PortsInSlateportLilycove',
            0x081EFE5D: 'PlayersHouse_1F_Text_BetterGetBackToGym',
            0x081EFE82: 'PlayersHouse_1F_Text_DadShouldStayLonger',
            0x081EFEC0: 'PlayersHouse_1F_Text_IsThatABreakingStory',
            0x081EFED2: 'PlayersHouse_1F_Text_LatiEmergencyNewsFlash',
            0x081EFF49: 'PlayersHouse_1F_Text_WhatColorDidTheySay',
            0x081EFF72: 'PlayersHouse_1F_Text_StillUnknownPokemon',
        },
        'external_texts': {
            0x081F0678: 'RivalsHouse_1F_Text_OhYoureTheNewNeighbor',
            0x081F0994: 'RivalsHouse_1F_Text_BrendanWhoAreYou',
        },
        'field_placeholders': {
            0x081EFA4C: {0x01: 'PLAYER'},
            0x081EFA68: {0x01: 'PLAYER'},
            0x081EFAE5: {0x01: 'PLAYER'},
            0x081EFAFC: {0x01: 'PLAYER'},
            0x081EFB12: {0x01: 'PLAYER'},
            0x081EFBF0: {0x01: 'PLAYER'},
            0x081EFDC8: {0x01: 'PLAYER'},
            0x081EFF49: {0x01: 'PLAYER'},
        },
        'external_labels': {
            0x08257EEE: 'PlayersHouse_1F_EventScript_EnterHouseMovingIn',
            0x08257F4F: 'PlayersHouse_1F_EventScript_MomGoSeeRoom',
            0x08258057: 'PlayersHouse_1F_EventScript_PetalburgGymReportMale',
            0x082582DC: 'PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
            0x082581AF: 'PlayersHouse_1F_EventScript_Mom',
            0x082582A4: 'PlayersHouse_1F_EventScript_Vigoroth1',
            0x082582B7: 'PlayersHouse_1F_EventScript_Vigoroth2',
            0x081F04A6: 'RivalsHouse_1F_EventScript_RivalMom',
            0x081F04F0: 'RivalsHouse_1F_EventScript_RivalSibling',
        },
        'symbols': {
            'vars': {
                0x4050: 'VAR_LITTLEROOT_TOWN_STATE',
                0x4082: 'VAR_LITTLEROOT_HOUSES_STATE_MAY',
                0x408D: 'VAR_LITTLEROOT_RIVAL_STATE',
                0x4092: 'VAR_LITTLEROOT_INTRO_STATE',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {0x800D: {0: 'MALE', 1: 'FEMALE'}},
            'script_var_values': {
                0x081EF86C: {
                    0x8004: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                    0x8005: {0x00: 'MALE'},
                },
                0x081EF87D: {
                    0x8004: {0x00: 'MALE'},
                    0x8005: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                },
                0x081EF8D3: {
                    0x8004: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                    0x8005: {0x00: 'MALE'},
                },
            },
            'flags': {
                0x0057: 'FLAG_MET_RIVAL_MOM',
                0x0112: 'FLAG_RECEIVED_RUNNING_SHOES',
                0x02E9: 'FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN',
                0x02F8: 'FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM',
                0x0331: 'FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL',
            },
            'songs': {0x0000: 'MUS_DUMMY', 0x01A5: 'MUS_ENCOUNTER_BRENDAN'},
            'sounds': {0x0009: 'SE_EXIT', 0x0015: 'SE_PIN'},
            'maps': {0x0101: 'MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F'},
            'local_ids': {
                0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM',
                0x04: 'LOCALID_RIVALS_HOUSE_1F_MOM',
                0x07: 'LOCALID_RIVALS_HOUSE_1F_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
            'movement_types': {0x07: 'MOVEMENT_TYPE_FACE_UP'},
            'metatiles': {
                0x0268: 'METATILE_BrendansMaysHouse_MovingBox_Closed',
                0x0270: 'METATILE_BrendansMaysHouse_MovingBox_Open',
                0x0293: 'METATILE_BrendansMaysHouse_BookOnTable',
            },
            'booleans': {0x01: 'TRUE'},
        },
    },
    'LittlerootTown_MaysHouse_1F': {
        'scripts': {
            0x081F0368: 'LittlerootTown_MaysHouse_1F_OnLoad',
            0x081F037D: 'LittlerootTown_MaysHouse_1F_EventScript_SetMovingBoxes',
            0x081F0390: 'LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual',
            0x081F039D: 'LittlerootTown_MaysHouse_1F_EventScript_ShowRunningShoesManual',
            0x081F03A7: 'LittlerootTown_MaysHouse_1F_OnTransition',
            0x081F03C9: 'LittlerootTown_MaysHouse_1F_EventScript_MoveMomToStairs',
            0x081F03D5: 'LittlerootTown_MaysHouse_1F_EventScript_MoveMomToTV',
            0x081F03E1: 'LittlerootTown_MaysHouse_1F_EventScript_MoveMomToDoor',
            0x081F0417: 'LittlerootTown_MaysHouse_1F_EventScript_GoUpstairsToSetClock',
            0x081F043F: 'LittlerootTown_MaysHouse_1F_EventScript_EnterHouseMovingIn',
            0x081F0450: 'LittlerootTown_MaysHouse_1F_EventScript_PetalburgGymReport',
            0x081F0461: 'LittlerootTown_MaysHouse_1F_EventScript_YoureNewNeighbor',
            0x081F04A6: 'RivalsHouse_1F_EventScript_RivalMom',
            0x081F04D2: 'RivalsHouse_1F_EventScript_RivalTooBusy',
            0x081F04DC: 'RivalsHouse_1F_EventScript_RivalIsOnRoute103',
            0x081F04E6: 'RivalsHouse_1F_EventScript_GoHomeEverySoOften',
            0x081F04F0: 'RivalsHouse_1F_EventScript_RivalSibling',
            0x081F04FF: 'LittlerootTown_MaysHouse_1F_EventScript_GoSeeRoom',
            0x081F051A: 'LittlerootTown_MaysHouse_1F_EventScript_MeetRival0',
            0x081F0526: 'LittlerootTown_MaysHouse_1F_EventScript_MeetRival1',
            0x081F0532: 'LittlerootTown_MaysHouse_1F_EventScript_MeetRival2',
            0x081F053E: 'LittlerootTown_MaysHouse_1F_EventScript_MeetRival',
            0x081F05DD: 'LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay',
            0x081F05E8: 'LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer0',
            0x081F05F3: 'LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer1',
            0x081F05FE: 'LittlerootTown_MaysHouse_1F_EventScript_MayApproachPlayer2',
            0x081F061D: 'LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0',
            0x081F062F: 'LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1',
            0x081F0641: 'LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2',
        },
        'tables': {0x081F03ED: 'LittlerootTown_MaysHouse_1F_OnFrame'},
        'texts': {
            0x081F0678: 'RivalsHouse_1F_Text_OhYoureTheNewNeighbor',
            0x081F0701: 'RivalsHouse_1F_Text_LikeChildLikeFather',
            0x081F0755: 'RivalsHouse_1F_Text_TooBusyToNoticeVisit',
            0x081F078A: 'RivalsHouse_1F_Text_WentOutToRoute103',
            0x081F07D8: 'RivalsHouse_1F_Text_ShouldGoHomeEverySoOften',
            0x081F0843: 'RivalsHouse_1F_Text_MayWhoAreYou',
            0x081F0994: 'RivalsHouse_1F_Text_BrendanWhoAreYou',
            0x081F0ABD: 'RivalsHouse_1F_Text_DoYouHavePokemon',
        },
        'external_texts': {
            0x081EFAFC: 'PlayersHouse_1F_Text_GoSetTheClock',
        },
        'field_placeholders': {
            0x081F0678: {0x01: 'PLAYER', 0x02: 'STR_VAR_1', 0x05: 'KUN'},
            0x081F0755: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
            0x081F078A: {0x06: 'RIVAL'},
            0x081F07D8: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F0843: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F0994: {0x01: 'PLAYER'},
            0x081F0ABD: {0x02: 'STR_VAR_1'},
        },
        'external_labels': {
            0x08257EEE: 'PlayersHouse_1F_EventScript_EnterHouseMovingIn',
            0x08257F4F: 'PlayersHouse_1F_EventScript_MomGoSeeRoom',
            0x082580C6: 'PlayersHouse_1F_EventScript_PetalburgGymReportFemale',
            0x082582DC: 'PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
            0x082581AF: 'PlayersHouse_1F_EventScript_Mom',
            0x082582A4: 'PlayersHouse_1F_EventScript_Vigoroth1',
            0x082582B7: 'PlayersHouse_1F_EventScript_Vigoroth2',
        },
        'symbols': {
            'vars': {
                0x4050: 'VAR_LITTLEROOT_TOWN_STATE',
                0x4082: 'VAR_LITTLEROOT_HOUSES_STATE_MAY',
                0x408C: 'VAR_LITTLEROOT_HOUSES_STATE_BRENDAN',
                0x408D: 'VAR_LITTLEROOT_RIVAL_STATE',
                0x4092: 'VAR_LITTLEROOT_INTRO_STATE',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {0x800D: {0: 'MALE', 1: 'FEMALE'}},
            'script_var_values': {
                0x081F043F: {
                    0x8004: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                    0x8005: {0x01: 'FEMALE'},
                },
                0x081F0450: {
                    0x8004: {0x01: 'FEMALE'},
                    0x8005: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                },
                0x081F04FF: {
                    0x8004: {0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM'},
                    0x8005: {0x01: 'FEMALE'},
                },
            },
            'flags': {
                0x0057: 'FLAG_MET_RIVAL_MOM',
                0x0082: 'FLAG_DEFEATED_RIVAL_ROUTE103',
                0x0112: 'FLAG_RECEIVED_RUNNING_SHOES',
                0x02D2: 'FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM',
                0x02EA: 'FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY',
                0x0332: 'FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL',
                0x0860: 'FLAG_SYS_POKEMON_GET',
            },
            'songs': {0x0000: 'MUS_DUMMY', 0x019F: 'MUS_ENCOUNTER_MAY'},
            'sounds': {0x0009: 'SE_EXIT', 0x0015: 'SE_PIN'},
            'maps': {0x0103: 'MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F'},
            'local_ids': {
                0x01: 'LOCALID_PLAYERS_HOUSE_1F_MOM',
                0x04: 'LOCALID_RIVALS_HOUSE_1F_MOM',
                0x07: 'LOCALID_RIVALS_HOUSE_1F_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
            'movement_types': {0x07: 'MOVEMENT_TYPE_FACE_UP'},
            'metatiles': {
                0x0268: 'METATILE_BrendansMaysHouse_MovingBox_Closed',
                0x0270: 'METATILE_BrendansMaysHouse_MovingBox_Open',
                0x0293: 'METATILE_BrendansMaysHouse_BookOnTable',
            },
            'booleans': {0x01: 'TRUE'},
        },
    },
    'LittlerootTown_BrendansHouse_2F': {
        'scripts': {
            0x081EFF9D: 'LittlerootTown_BrendansHouse_2F_OnTransition',
            0x081EFFC9: 'LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos',
            0x081EFFE2: 'LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos',
            0x081F0005: 'LittlerootTown_BrendansHouse_2F_EventScript_Ret',
            0x081F0006: 'LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan',
            0x081F0013: 'LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan',
            0x081F0023: 'LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor',
            0x081F0030: 'LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall',
            0x081F0046: 'LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan',
            0x081F00B6: 'LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth',
            0x081F00E5: 'LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth',
            0x081F0114: 'LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest',
            0x081F0143: 'LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast',
            0x081F01BC: 'LittlerootTown_BrendansHouse_2F_EventScript_PC',
            0x081F01D5: 'LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC',
            0x081F01EE: 'LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC',
            0x081F01FB: 'LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC',
            0x081F0205: 'PlayersHouse_2F_EventScript_Notebook',
            0x081F020E: 'PlayersHouse_2F_EventScript_GameCube',
        },
        'tables': {
            0x081F0019: 'LittlerootTown_BrendansHouse_2F_OnWarp',
        },
        'texts': {
            0x081F0217: 'PlayersHouse_2F_Text_ClockIsStopped',
            0x081F023B: 'PlayersHouse_2F_Text_HowDoYouLikeYourRoom',
            0x081F02A6: 'PlayersHouse_2F_Text_Notebook',
            0x081F0308: 'Common_Text_LookCloserAtMap',
            0x081F0328: 'PlayersHouse_2F_Text_ItsAGameCube',
        },
        'external_texts': {
            0x081F0F62: 'RivalsHouse_2F_Text_BrendanWhoAreYou',
            0x081F10B0: 'RivalsHouse_2F_Text_ItsRivalsPokeBall',
            0x08243AA2: 'gText_PokemonTrainerSchoolEmail',
            0x08243B10: 'gText_PlayerHouseBootPC',
        },
        'field_placeholders': {
            0x081F023B: {0x01: 'PLAYER'},
            0x081F02A6: {0x01: 'PLAYER'},
            0x081F0308: {0x01: 'PLAYER'},
        },
        'external_labels': {
            # The cross-house Ret target is also present in the US source.
            0x081F0B55: 'LittlerootTown_MaysHouse_2F_EventScript_Ret',
            0x081F0D0D: 'RivalsHouse_2F_EventScript_Rival',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x08245D90: 'SecretBase_EventScript_SetDecorationFlags',
            0x08245DBB: 'SecretBase_EventScript_InitDecorations',
            0x08257EE8: 'PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet',
            0x08257F6B: 'LittlerootTown_BrendansHouse_2F_EventScript_WallClock',
        },
        'symbols': {
            'vars': {
                0x4050: 'VAR_LITTLEROOT_TOWN_STATE',
                0x4084: 'VAR_BIRCH_LAB_STATE',
                0x4089: 'VAR_SECRET_BASE_INITIALIZED',
                0x408D: 'VAR_LITTLEROOT_RIVAL_STATE',
                0x4092: 'VAR_LITTLEROOT_INTRO_STATE',
                0x40D3: 'VAR_DEX_UPGRADE_JOHTO_STARTER_STATE',
                0x8004: 'VAR_0x8004',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x8004: {1: 'PC_LOCATION_BRENDANS_HOUSE'},
                0x800C: {
                    1: 'DIR_SOUTH',
                    2: 'DIR_NORTH',
                    3: 'DIR_WEST',
                    4: 'DIR_EAST',
                },
                0x800D: {0: 'MALE', 1: 'FEMALE'},
            },
            'flags': {
                0x0124: 'FLAG_MET_RIVAL_LILYCOVE',
                0x02F8: 'FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM',
                0x0331: 'FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL',
            },
            'songs': {0x0000: 'MUS_DUMMY', 0x01A5: 'MUS_ENCOUNTER_BRENDAN'},
            'sounds': {
                0x0003: 'SE_PC_OFF',
                0x0004: 'SE_PC_ON',
                0x0015: 'SE_PIN',
            },
            'local_ids': {
                0x01: 'LOCALID_RIVALS_HOUSE_2F_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
            'movement_types': {0x07: 'MOVEMENT_TYPE_FACE_UP'},
            'booleans': {0x01: 'TRUE'},
        },
    },
    'LittlerootTown_MaysHouse_2F': {
        'scripts': {
            0x081F0AED: 'LittlerootTown_MaysHouse_2F_OnTransition',
            0x081F0B19: 'LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos',
            0x081F0B32: 'LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos',
            0x081F0B55: 'LittlerootTown_MaysHouse_2F_EventScript_Ret',
            0x081F0B56: 'LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay',
            0x081F0B63: 'LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay',
            0x081F0B73: 'LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor',
            0x081F0B80: 'LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall',
            0x081F0B96: 'LittlerootTown_MaysHouse_2F_EventScript_MeetMay',
            0x081F0C06: 'LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth',
            0x081F0C35: 'LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth',
            0x081F0C64: 'LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest',
            0x081F0C8C: 'LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast',
            0x081F0D0D: 'RivalsHouse_2F_EventScript_Rival',
            0x081F0D2F: 'RivalsHouse_2F_EventScript_May',
            0x081F0D39: 'RivalsHouse_2F_EventScript_Brendan',
            0x081F0D43: 'RivalsHouse_2F_EventScript_RivalPostLilycove',
            0x081F0D69: 'RivalsHouse_2F_EventScript_MayPostLilycove',
            0x081F0D7B: 'RivalsHouse_2F_EventScript_BrendanPostLilycove',
            0x081F0D8D: 'RivalsHouse_2F_EventScript_MayWhereShouldIGoNext',
            0x081F0D96: 'RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext',
            0x081F0D9F: 'LittlerootTown_MaysHouse_2F_EventScript_PC',
            0x081F0DB8: 'LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC',
            0x081F0DC2: 'LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC',
            0x081F0DDB: 'LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC',
        },
        'tables': {
            0x081F0B69: 'LittlerootTown_MaysHouse_2F_OnWarp',
        },
        'texts': {
            0x081F0DE8: 'RivalsHouse_2F_Text_MayWhoAreYou',
            0x081F0F40: 'RivalsHouse_2F_Text_MayGettingReady',
            0x081F0F62: 'RivalsHouse_2F_Text_BrendanWhoAreYou',
            0x081F108B: 'RivalsHouse_2F_Text_BrendanGettingReady',
            0x081F10B0: 'RivalsHouse_2F_Text_ItsRivalsPokeBall',
            0x081F10CD: 'RivalsHouse_2F_Text_MayJustCheckingMyPokedex',
            0x081F1142: 'RivalsHouse_2F_Text_MayWhereShouldIGoNext',
            0x081F117C: 'RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex',
            0x081F11E3: 'RivalsHouse_2F_Text_BrendanWhereShouldIGoNext',
        },
        'external_texts': {
            0x08243AA2: 'gText_PokemonTrainerSchoolEmail',
            0x08243B10: 'gText_PlayerHouseBootPC',
        },
        'field_placeholders': {
            0x081F0DE8: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F0F62: {0x01: 'PLAYER'},
            0x081F10B0: {0x06: 'RIVAL'},
            0x081F10CD: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F1142: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F117C: {0x01: 'PLAYER'},
            0x081F11E3: {0x01: 'PLAYER'},
        },
        'external_labels': {
            0x081F0205: 'PlayersHouse_2F_EventScript_Notebook',
            0x081F020E: 'PlayersHouse_2F_EventScript_GameCube',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x08245D90: 'SecretBase_EventScript_SetDecorationFlags',
            0x08245DBB: 'SecretBase_EventScript_InitDecorations',
            0x08257EE8: 'PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet',
            0x08257F77: 'LittlerootTown_MaysHouse_2F_EventScript_WallClock',
        },
        'symbols': {
            'vars': {
                0x4050: 'VAR_LITTLEROOT_TOWN_STATE',
                0x4084: 'VAR_BIRCH_LAB_STATE',
                0x4089: 'VAR_SECRET_BASE_INITIALIZED',
                0x408D: 'VAR_LITTLEROOT_RIVAL_STATE',
                0x4092: 'VAR_LITTLEROOT_INTRO_STATE',
                0x40D3: 'VAR_DEX_UPGRADE_JOHTO_STARTER_STATE',
                0x8004: 'VAR_0x8004',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'var_values': {
                0x8004: {2: 'PC_LOCATION_MAYS_HOUSE'},
                0x800C: {
                    1: 'DIR_SOUTH',
                    2: 'DIR_NORTH',
                    3: 'DIR_WEST',
                    4: 'DIR_EAST',
                },
                0x800D: {0: 'MALE', 1: 'FEMALE'},
            },
            'flags': {
                0x0124: 'FLAG_MET_RIVAL_LILYCOVE',
                0x0125: 'FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE',
                0x02D2: 'FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM',
                0x0332: 'FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL',
            },
            'songs': {0x0000: 'MUS_DUMMY', 0x019F: 'MUS_ENCOUNTER_MAY'},
            'sounds': {
                0x0003: 'SE_PC_OFF',
                0x0004: 'SE_PC_ON',
                0x0015: 'SE_PIN',
            },
            'local_ids': {
                0x01: 'LOCALID_RIVALS_HOUSE_2F_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
            'movement_types': {0x07: 'MOVEMENT_TYPE_FACE_UP'},
            'booleans': {0x01: 'TRUE'},
        },
    },
    'LittlerootTown_ProfessorBirchsLab': {
        'scripts': {
            0x081F123C: 'LittlerootTown_ProfessorBirchsLab_OnTransition',
            0x081F1268: 'LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter',
            0x081F1284: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter',
            0x081F128E: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout',
            0x081F1292: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout',
            0x081F12DB: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter',
            0x081F12E0: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade',
            0x081F130C: 'LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject',
            0x081F1310: 'LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters',
            0x081F1376: 'LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent',
            0x081F13A2: 'LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter',
            0x081F13B2: 'LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival',
            0x081F13D1: 'LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival',
            0x081F13E3: 'LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival',
            0x081F1402: 'LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent',
            0x081F141B: 'LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex',
            0x081F14CD: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment',
            0x081F14D7: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment',
            0x081F14FD: 'LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter',
            0x081F151F: 'LittlerootTown_ProfessorBirchsLab_EventScript_Aide',
            0x081F1542: 'LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet',
            0x081F154C: 'LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter',
            0x081F1556: 'LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil',
            0x081F158A: 'LittlerootTown_ProfessorBirchsLab_EventScript_Totodile',
            0x081F15BE: 'LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita',
            0x081F15F2: 'LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter',
            0x081F15FC: 'LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime',
            0x081F1607: 'LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil',
            0x081F163C: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty',
            0x081F1667: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC',
            0x081F168D: 'LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC',
            0x081F1698: 'LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil',
            0x081F16A8: 'LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile',
            0x081F16DD: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty',
            0x081F1708: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC',
            0x081F172E: 'LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC',
            0x081F1739: 'LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile',
            0x081F1749: 'LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita',
            0x081F177E: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty',
            0x081F17A9: 'LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC',
            0x081F17CF: 'LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC',
            0x081F17DA: 'LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita',
            0x081F17EA: 'LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter',
            0x081F17F5: 'LittlerootTown_ProfessorBirchsLab_EventScript_Birch',
            0x081F1825: 'LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon',
            0x081F182F: 'LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting',
            0x081F1839: 'LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister',
            0x081F186D: 'EventScript_RegisterProfBirch',
            0x081F1893: 'LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex',
            0x081F18ED: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls',
            0x081F191A: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls',
            0x081F1947: 'LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex',
            0x081F195F: 'LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait',
            0x081F1969: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls',
            0x081F1972: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls',
            0x081F197E: 'LittlerootTown_ProfessorBirchsLab_EventScript_Machine',
            0x081F1987: 'LittlerootTown_ProfessorBirchsLab_EventScript_Rival',
            0x081F19C3: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext',
            0x081F19CC: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext',
            0x081F19D5: 'LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans',
            0x081F19EE: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere',
            0x081F19F7: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly',
            0x081F1A00: 'LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier',
            0x081F1A19: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier',
            0x081F1A22: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier',
            0x081F1A2B: 'LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork',
            0x081F1A44: 'LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork',
            0x081F1A4D: 'LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork',
            0x081F1A56: 'LittlerootTown_ProfessorBirchsLab_EventScript_PC',
            0x081F1A5F: 'LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf',
            0x081F1A68: 'LittlerootTown_ProfessorBirchsLab_EventScript_Book',
            0x081F1A71: 'LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall',
        },
        'tables': {
            0x081F12A1: 'LittlerootTown_ProfessorBirchsLab_OnWarp',
            0x081F1354: 'LittlerootTown_ProfessorBirchsLab_OnFrame',
        },
        'texts': {
            0x081F1A7D: 'LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork',
            0x081F1B1D: 'LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork',
            0x081F1B5B: 'LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo',
            0x081F1BAD: 'LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon',
            0x081F1C81: 'LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon',
            0x081F1CA8: 'LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival',
            0x081F1D1C: 'LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou',
            0x081F1D52: 'LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay',
            0x081F1D72: 'LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome',
            0x081F1DDC: 'LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex',
            0x081F1E6C: 'LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex',
            0x081F1E7F: 'LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex',
            0x081F1F31: 'LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait',
            0x081F1F72: 'LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese',
            0x081F1FB3: 'LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls',
            0x081F2019: 'LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull',
            0x081F2028: 'LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext',
            0x081F2048: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese',
            0x081F2072: 'LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls',
            0x081F20D5: 'LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull',
            0x081F20E4: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext',
            0x081F2103: 'LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine',
            0x081F2127: 'LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch',
            0x081F214D: 'LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon',
            0x081F2169: 'LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead',
            0x081F217C: 'LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational',
            0x081F226E: 'LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool',
            0x081F22B6: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe',
            0x081F22FE: 'LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone',
            0x081F230C: 'LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational',
            0x081F232E: 'LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2',
            0x081F2388: 'LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork',
            0x081F23C6: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork',
            0x081F2402: 'LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon',
            0x081F24F0: 'LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon',
            0x081F2532: 'LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil',
            0x081F256E: 'LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile',
            0x081F25A6: 'LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita',
            0x081F25DC: 'LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable',
            0x081F2609: 'LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon',
            0x081F2624: 'LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter',
            0x081F263D: 'LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter',
            0x081F2655: 'LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting',
            0x081F26B5: 'LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone',
            0x081F26DC: 'LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon',
            0x081F26F8: 'LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere',
            0x081F275E: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly',
            0x081F2796: 'LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier',
            0x081F27C2: 'LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier',
            0x081F27EC: 'LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall',
        },
        'field_placeholders': {
            0x081F1B5B: {0x06: 'RIVAL'},
            0x081F1BAD: {0x01: 'PLAYER', 0x02: 'STR_VAR_1', 0x05: 'KUN'},
            0x081F1C81: {0x02: 'STR_VAR_1'},
            0x081F1CA8: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
            0x081F1D1C: {0x06: 'RIVAL'},
            0x081F1D72: {0x06: 'RIVAL'},
            0x081F1DDC: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
            0x081F1E6C: {0x01: 'PLAYER'},
            0x081F1E7F: {0x06: 'RIVAL'},
            0x081F1F72: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F2048: {0x01: 'PLAYER'},
            0x081F217C: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
            0x081F226E: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F22B6: {0x01: 'PLAYER'},
            0x081F230C: {0x01: 'PLAYER'},
            0x081F2402: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F2624: {0x01: 'PLAYER', 0x02: 'STR_VAR_1'},
            0x081F263D: {0x02: 'STR_VAR_1'},
            0x081F2655: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F26F8: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F2796: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F27C2: {0x01: 'PLAYER'},
            0x081F27EC: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_labels': {
            0x08242F63: 'Common_EventScript_SetupRivalGfxId',
            0x08243139: 'ProfBirch_EventScript_UpdateLocation',
            0x082431CD: 'ProfBirch_EventScript_RatePokedexOrRegister',
            0x08243460: 'Common_EventScript_NameReceivedPartyMon',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x082441B5: 'Common_EventScript_GetGiftMonPartySlot',
            0x082441C1: 'Common_EventScript_NameReceivedBoxMon',
            0x082441CA: 'Common_EventScript_TransferredToPC',
            0x0824423B: 'Common_EventScript_NoMoreRoomForPokemon',
        },
        'external_texts': {
            0x08243EDB: 'gText_NicknameThisPokemon',
            0x0826C1AF: 'MatchCall_Text_BirchRegisterCall',
            0x0826C23E: 'MatchCall_Text_RegisteredBirch',
        },
        'symbols': {
            'vars': {
                0x4001: 'VAR_TEMP_TRANSFERRED_SPECIES',
                0x4050: 'VAR_LITTLEROOT_TOWN_STATE',
                0x4051: 'VAR_OLDALE_TOWN_STATE',
                0x4084: 'VAR_BIRCH_LAB_STATE',
                0x408D: 'VAR_LITTLEROOT_RIVAL_STATE',
                0x40CD: 'VAR_CABLE_CLUB_TUTORIAL_STATE',
                0x40D3: 'VAR_DEX_UPGRADE_JOHTO_STARTER_STATE',
                0x40DA: 'VAR_REGISTER_BIRCH_STATE',
                0x40F5: 'VAR_SCOTT_BF_CALL_STEP_COUNTER',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4001: {
                    0x0098: 'SPECIES_CHIKORITA',
                    0x009B: 'SPECIES_CYNDAQUIL',
                    0x009E: 'SPECIES_TOTODILE',
                },
            },
            'script_var_values': {
                0x081F1268: {0x800D: {0x01: 'TRUE'}},
            },
            'flags': {
                0x0058: 'FLAG_BIRCH_AIDE_MET',
                0x0072: 'FLAG_SCOTT_CALL_BATTLE_FRONTIER',
                0x0074: 'FLAG_ADVENTURE_STARTED',
                0x0119: 'FLAG_ENABLE_PROF_BIRCH_MATCH_CALL',
                0x012F: 'FLAG_HAS_MATCH_CALL',
                0x031A: 'FLAG_HIDE_LITTLEROOT_TOWN_RIVAL',
                0x031B: 'FLAG_HIDE_LITTLEROOT_TOWN_BIRCH',
                0x0380: 'FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380',
                0x03DF: 'FLAG_HIDE_ROUTE_101_BOY',
                0x0861: 'FLAG_SYS_POKEDEX_GET',
                0x0896: 'FLAG_SYS_NATIONAL_DEX',
                0x08E4: 'FLAG_RECEIVED_POKEDEX_FROM_BIRCH',
            },
            'items': {0x0004: 'ITEM_POKE_BALL'},
            'songs': {
                0x0172: 'MUS_OBTAIN_ITEM',
                0x01CC: 'MUS_REGISTER_MATCH_CALL',
            },
            'sounds': {
                0x0004: 'SE_PC_ON',
                0x0024: 'SE_CLICK',
            },
            'species': {
                0x0098: 'SPECIES_CHIKORITA',
                0x009B: 'SPECIES_CYNDAQUIL',
                0x009E: 'SPECIES_TOTODILE',
            },
            'layouts': {
                0x01B0: 'LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE',
            },
            'local_ids': {
                0x01: 'LOCALID_BIRCHS_LAB_AIDE',
                0x02: 'LOCALID_BIRCHS_LAB_BIRCH',
                0x03: 'LOCALID_BIRCHS_LAB_RIVAL',
                0x04: 'LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL',
                0x05: 'LOCALID_BIRCHS_LAB_TOTODILE_BALL',
                0x06: 'LOCALID_BIRCHS_LAB_CHIKORITA_BALL',
                0xFF: 'LOCALID_PLAYER',
            },
            'directions': {
                0x01: 'DIR_SOUTH',
                0x02: 'DIR_NORTH',
                0x04: 'DIR_EAST',
            },
            'movement_types': {
                0x03: 'MOVEMENT_TYPE_WANDER_UP_AND_DOWN',
            },
        },
    },
    'Underwater_Route105': {
        'scripts': {
            0x081EF773: 'Underwater_Route105_OnResume',
        },
        'external_labels': {
            0x08244C4D: 'AbnormalWeather_Underwater_SetupEscapeWarp',
        },
    },
    'Underwater_Route124': {},
    'Underwater_Route125': {
        'scripts': {
            0x081EF77F: 'Underwater_Route125_OnResume',
        },
        'external_labels': {
            0x08244C4D: 'AbnormalWeather_Underwater_SetupEscapeWarp',
        },
    },
    'Underwater_Route126': {},
    'Underwater_Route127': {
        'scripts': {
            0x081EF75A: 'Underwater_Route127_OnResume',
        },
        'external_labels': {
            0x08244C4D: 'AbnormalWeather_Underwater_SetupEscapeWarp',
        },
    },
    'Underwater_Route128': {},
    'Underwater_Route129': {
        'scripts': {
            0x081EF767: 'Underwater_Route129_OnResume',
        },
        'external_labels': {
            0x08244C4D: 'AbnormalWeather_Underwater_SetupEscapeWarp',
        },
    },
    'Underwater_Route134': {
        'scripts': {
            0x0821BA00: 'Underwater_Route134_OnResume',
        },
        'symbols': {
            'maps': {0x0031: 'MAP_ROUTE134'},
        },
    },
    'RustboroCity_DevonCorp_3F': {
        'scripts': {
            0x08201C39: 'RustboroCity_DevonCorp_3F_OnTransition',
            0x08201C45: 'RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos',
            0x08201C5B: 'RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast',
            0x08201C6A: 'RustboroCity_DevonCorp_3F_EventScript_MeetPresident',
            0x08201D68: 'RustboroCity_DevonCorp_3F_EventScript_MrStone',
            0x08201D91: 'RustboroCity_DevonCorp_3F_EventScript_GiveExpShare',
            0x08201DC8: 'RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor',
            0x08201DDD: 'RustboroCity_DevonCorp_3F_EventScript_Employee',
            0x08201DF2: 'RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls',
            0x08201DFC: 'RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay',
        },
        'tables': {
            0x08201C51: 'RustboroCity_DevonCorp_3F_OnWarp',
            0x08201C60: 'RustboroCity_DevonCorp_3F_OnFrame',
        },
        'texts': {
            0x08201E05: 'RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor',
            0x08201EE9: 'RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis',
            0x08201F3E: 'RustboroCity_DevonCorp_3F_Text_ReceivedPokenav',
            0x08201F4F: 'RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp',
            0x08202015: 'RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare',
            0x08202037: 'RustboroCity_DevonCorp_3F_Text_CountingOnYou',
            0x08202047: 'RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter',
            0x0820208A: 'RustboroCity_DevonCorp_3F_Text_ExplainExpShare',
            0x082020E6: 'RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends',
            0x0820213E: 'RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere',
            0x08202212: 'RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe',
            0x08202239: 'RustboroCity_DevonCorp_3F_Text_PleaseGoAhead',
            0x08202241: 'RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard',
            0x08202277: 'RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular',
            0x082022A7: 'RustboroCity_DevonCorp_3F_Text_RareRocksDisplay',
        },
        # FD nn is context-sensitive.  These two are field messages whose
        # exact US counterparts establish the intended field placeholders.
        'field_placeholders': {
            0x08201F3E: {0x01: 'PLAYER'},
            0x08202015: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        # These constants are emitted only in argument positions whose US
        # counterpart proves the type (flag, variable, item, song, etc.).
        'symbols': {
            'vars': {
                0x405A: 'VAR_RUSTBORO_CITY_STATE',
                0x408F: 'VAR_DEVON_CORP_3F_STATE',
                0x4096: 'VAR_BRINEY_LOCATION',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'flags': {
                0x00BC: 'FLAG_RECEIVED_POKENAV',
                0x00BD: 'FLAG_DELIVERED_STEVEN_LETTER',
                0x0100: 'FLAG_RECEIVED_REPEAT_BALL',
                0x0110: 'FLAG_RECEIVED_EXP_SHARE',
                0x02E3: 'FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY',
                0x0327: 'FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND',
                0x032E: 'FLAG_HIDE_RUSTBORO_CITY_RIVAL',
                0x0371: 'FLAG_HIDE_BRINEYS_HOUSE_PEEKO',
                0x037E: 'FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND',
                0x03D7: 'FLAG_HIDE_RUSTURF_TUNNEL_WANDA',
                0x03E7: 'FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT',
                0x0862: 'FLAG_SYS_POKENAV_GET',
            },
            'items': {
                0x00B6: 'ITEM_EXP_SHARE',
                0x0112: 'ITEM_LETTER',
            },
            'songs': {
                0x0172: 'MUS_OBTAIN_ITEM',
                0x01A4: 'MUS_FOLLOW_ME',
            },
            'local_ids': {
                0x02: 'LOCALID_DEVON_CORP_3F_EMPLOYEE',
                0xFF: 'LOCALID_PLAYER',
            },
            'directions': {0x04: 'DIR_EAST'},
            'movement_types': {0x09: 'MOVEMENT_TYPE_FACE_LEFT'},
        },
    },
    # Seafloor Cavern Room1-4 and Room9 are a contiguous, fully reviewed
    # script region.  The JP instruction, text, and movement ordering is
    # checked one-for-one against the corresponding US map sources.  Keep
    # this an explicit allowlist: other maps continue to use address labels
    # until their semantic ownership is independently established.
    'SeafloorCavern_Room1': {
        'scripts': {
            0x0821865F: 'SeafloorCavern_Room1_EventScript_Grunt1',
            0x08218676: 'SeafloorCavern_Room1_EventScript_Grunt2',
        },
        'texts': {
            0x0821868D: 'SeafloorCavern_Room1_Text_Grunt1Intro',
            0x082186A9: 'SeafloorCavern_Room1_Text_Grunt1Defeat',
            0x082186B6: 'SeafloorCavern_Room1_Text_Grunt1PostBattle',
            0x082186D5: 'SeafloorCavern_Room1_Text_Grunt2Intro',
            0x082186FC: 'SeafloorCavern_Room1_Text_Grunt2Defeat',
            0x0821870C: 'SeafloorCavern_Room1_Text_Grunt2PostBattle',
        },
        'symbols': {
            'trainers': {
                0x0006: 'TRAINER_GRUNT_SEAFLOOR_CAVERN_1',
                0x0007: 'TRAINER_GRUNT_SEAFLOOR_CAVERN_2',
            },
        },
    },
    'SeafloorCavern_Room3': {
        'scripts': {
            0x0821873F: 'SeafloorCavern_Room3_EventScript_Shelly',
            0x08218756: 'SeafloorCavern_Room3_EventScript_Grunt5',
        },
        'texts': {
            0x0821876D: 'SeafloorCavern_Room3_Text_ShellyIntro',
            0x082187F9: 'SeafloorCavern_Room3_Text_ShellyDefeat',
            0x08218808: 'SeafloorCavern_Room3_Text_ShellyPostBattle',
            0x0821886E: 'SeafloorCavern_Room3_Text_Grunt5Intro',
            0x082188D1: 'SeafloorCavern_Room3_Text_Grunt5Defeat',
            0x082188D6: 'SeafloorCavern_Room3_Text_Grunt5PostBattle',
        },
        'symbols': {
            'trainers': {
                0x0021: 'TRAINER_SHELLY_SEAFLOOR_CAVERN',
                0x0237: 'TRAINER_GRUNT_SEAFLOOR_CAVERN_5',
            },
        },
    },
    'SeafloorCavern_Room4': {
        'scripts': {
            0x0821892F: 'SeafloorCavern_Room4_EventScript_Grunt3',
            0x08218946: 'SeafloorCavern_Room4_EventScript_Grunt4',
        },
        'texts': {
            0x0821895D: 'SeafloorCavern_Room4_Text_Grunt3Intro',
            0x08218973: 'SeafloorCavern_Room4_Text_Grunt3Defeat',
            0x0821897A: 'SeafloorCavern_Room4_Text_Grunt3PostBattle',
            0x082189A4: 'SeafloorCavern_Room4_Text_Grunt4Intro',
            0x082189BA: 'SeafloorCavern_Room4_Text_Grunt4Defeat',
            0x082189C4: 'SeafloorCavern_Room4_Text_Grunt4PostBattle',
        },
        'symbols': {
            'trainers': {
                0x0008: 'TRAINER_GRUNT_SEAFLOOR_CAVERN_3',
                0x000E: 'TRAINER_GRUNT_SEAFLOOR_CAVERN_4',
            },
        },
    },
    'SeafloorCavern_Room9': {
        'scripts': {
            0x082189FE: 'SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre',
        },
        'texts': {
            0x08218C94: 'SeafloorCavern_Room9_Text_ArchieHoldItRightThere',
            0x08218CA1: 'SeafloorCavern_Room9_Text_ArchieSoItWasYou',
            0x08218CB9: 'SeafloorCavern_Room9_Text_ArchieBeholdKyogre',
            0x08218D0F: 'SeafloorCavern_Room9_Text_ArchieYouMustDisappear',
            0x08218D63: 'SeafloorCavern_Room9_Text_ArchieDefeat',
            0x08218D79: 'SeafloorCavern_Room9_Text_ArchieWithThisRedOrb',
            0x08218DD1: 'SeafloorCavern_Room9_Text_RedOrbShinesByItself',
            0x08218DEF: 'SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo',
            0x08218E28: 'SeafloorCavern_Room9_Text_ArchieAMessageFromOutside',
            0x08218E43: 'SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard',
            0x08218EEB: 'SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear',
            0x08218F44: 'SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought',
            0x08218FB7: 'SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty',
            0x08219035: 'SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue',
            0x08219092: 'SeafloorCavern_Room9_Text_MaxieComeOnPlayer',
        },
        'field_placeholders': {
            0x08219092: {0x01: 'PLAYER'},
        },
        'symbols': {
            'vars': {
                0x405E: 'VAR_SOOTOPOLIS_CITY_STATE',
                0x407B: 'VAR_ROUTE128_STATE',
                0x40A2: 'VAR_SEAFLOOR_CAVERN_STATE',
                0x40C6: 'VAR_STEVENS_HOUSE_STATE',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8006: 'VAR_0x8006',
                0x8007: 'VAR_0x8007',
                0x800D: 'VAR_RESULT',
            },
            'flags': {
                0x0053: 'FLAG_LEGENDARIES_IN_SOOTOPOLIS',
                0x0081: 'FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN',
                0x0347: 'FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1',
                0x033A: 'FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE',
                0x033B: 'FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE',
                0x033C: 'FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE',
                0x033D: 'FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE',
                0x033F: 'FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS',
                0x0356: 'FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS',
                0x035B: 'FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE',
                0x03B0: 'FLAG_HIDE_ROUTE_128_ARCHIE',
                0x03B1: 'FLAG_HIDE_ROUTE_128_MAXIE',
                0x03B2: 'FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS',
                0x03C7: 'FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN',
                0x03CD: 'FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN',
                0x03E5: 'FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE',
                0x03E6: 'FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON',
                0x088A: 'FLAG_SYS_WEATHER_CTRL',
                0x4000: 'FLAG_HIDE_MAP_NAME_POPUP',
            },
            'trainers': {0x0022: 'TRAINER_ARCHIE'},
            'songs': {
                0x0184: 'MUS_AWAKEN_LEGEND',
                0x01A3: 'MUS_ENCOUNTER_AQUA',
            },
            'sounds': {
                0x0002: 'SE_PC_LOGIN',
                0x0003: 'SE_PC_OFF',
                0x0015: 'SE_PIN',
                0x006B: 'SE_ORB',
                0x00D1: 'SE_M_DETECT',
            },
            'weather': {0x0000: 'WEATHER_NONE'},
            'field_effects': {0x0036: 'FLDEFF_SPARKLE'},
            'maps': {0x002B: 'MAP_ROUTE128'},
            'local_ids': {
                0x0001: 'LOCALID_SEAFLOOR_CAVERN_KYOGRE',
                0x0002: 'LOCALID_SEAFLOOR_CAVERN_ARCHIE',
                0x0003: 'LOCALID_SEAFLOOR_CAVERN_MAXIE',
                0x0004: 'LOCALID_SEAFLOOR_CAVERN_GRUNT_1',
                0x0005: 'LOCALID_SEAFLOOR_CAVERN_GRUNT_2',
                0x0007: 'LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING',
                0x00FF: 'LOCALID_PLAYER',
            },
        },
    },
    # Route106-109 are one contiguous JP raw owner.  Their event entry order,
    # trainer IDs, and locally-owned text/movement data have been checked
    # one-for-one against the corresponding US map sources.
    'Route106': {
        'scripts': {
            0x081E83CB: 'Route106_EventScript_TrainerTipsSign',
            0x081E83D4: 'Route106_EventScript_Douglas',
            0x081E83EB: 'Route106_EventScript_Kyla',
            0x081E8402: 'Route106_EventScript_Elliot',
            0x081E842E: 'Route106_EventScript_ElliotRegisterMatchCallAfterBattle',
            0x081E844D: 'Route106_EventScript_ElliotRematch',
            0x081E8464: 'Route106_EventScript_Ned',
        },
        'texts': {0x081E847B: 'Route106_Text_TrainerTips'},
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route106']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'trainers': {
                0x0099: 'TRAINER_DOUGLAS',
                0x01BB: 'TRAINER_KYLA',
                0x0153: 'TRAINER_ELLIOT_1',
                0x0154: 'TRAINER_NED',
            },
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
        },
    },
    'Route107': {
        'scripts': {
            0x081E84AC: 'Route107_EventScript_Darrin',
            0x081E84C3: 'Route107_EventScript_Tony',
            0x081E84EF: 'Route107_EventScript_TonyRegisterMatchCallAfterBattle',
            0x081E850E: 'Route107_EventScript_TonyRematch',
            0x081E8525: 'Route107_EventScript_Denise',
            0x081E853C: 'Route107_EventScript_Beth',
            0x081E8553: 'Route107_EventScript_Lisa',
            0x081E856E: 'Route107_EventScript_Ray',
            0x081E8589: 'Route107_EventScript_Camron',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route107']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'trainers': {
                0x009A: 'TRAINER_DARRIN',
                0x009B: 'TRAINER_TONY_1',
                0x01BC: 'TRAINER_DENISE',
                0x01BD: 'TRAINER_BETH',
                0x02B4: 'TRAINER_LISA_AND_RAY',
                0x02E3: 'TRAINER_CAMRON',
            },
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
        },
    },
    'Route108': {
        'scripts': {
            0x081E85A1: 'Route108_EventScript_Jerome',
            0x081E85B8: 'Route108_EventScript_Matthew',
            0x081E85CF: 'Route108_EventScript_Tara',
            0x081E85E6: 'Route108_EventScript_Missy',
            0x081E85FD: 'Route108_EventScript_Carolina',
            0x081E8614: 'Route108_EventScript_Cory',
            0x081E8640: 'Route108_EventScript_CoryRegisterMatchCallAfterBattle',
            0x081E865F: 'Route108_EventScript_CoryRematch',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route108']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'trainers': {
                0x009C: 'TRAINER_JEROME',
                0x009D: 'TRAINER_MATTHEW',
                0x01BE: 'TRAINER_TARA',
                0x01BF: 'TRAINER_MISSY',
                0x02E5: 'TRAINER_CAROLINA',
                0x02E4: 'TRAINER_CORY_1',
            },
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
        },
    },
    'Route109': {
        'scripts': {
            0x081E8677: 'Route109_EventScript_StartDepartForDewford',
            0x081E86BC: 'Route109_EventScript_EnterBoatSouth',
            0x081E86CC: 'Route109_EventScript_EnterBoatEast',
            0x081E86DC: 'Route109_EventScript_EnterBoatWest',
            0x081E86EC: 'Route109_EventScript_DoSailToDewford',
            0x081E8827: 'Route109_EventScript_MrBriney',
            0x081E8838: 'Route109_EventScript_HaveNotDeliveredDevonGood',
            0x081E8856: 'Route109_EventScript_DeliveredDevonGoods',
            0x081E8889: 'Route109_EventScript_SailToDewford',
            0x081E8898: 'Route109_EventScript_StayHere',
            0x081E88A2: 'Route109_EventScript_ChoseNotToSail',
            0x081E88AC: 'Route109_EventScript_SeashoreHouseGirl',
            0x081E88B5: 'Route109_EventScript_SandCastleBoy',
            0x081E88CC: 'Route109_EventScript_SoftSandGirl',
            0x081E8909: 'Route109_EventScript_AlreadyReceivedSoftSand',
            0x081E891D: 'Route109_EventScript_Woman',
            0x081E8926: 'Route109_EventScript_OldMan',
            0x081E892F: 'Route109_EventScript_Zigzagoon',
            0x081E8942: 'Route109_EventScript_SeashoreHouseSign',
            0x081E894B: 'Route109_EventScript_TrainerTipsSign',
            0x081E8954: 'Route109_EventScript_David',
            0x081E896B: 'Route109_EventScript_Alice',
            0x081E8982: 'Route109_EventScript_Huey',
            0x081E8999: 'Route109_EventScript_Edmond',
            0x081E89B0: 'Route109_EventScript_Ricky',
            0x081E89DC: 'Route109_EventScript_RickyRegisterMatchCallAfterBattle',
            0x081E89FB: 'Route109_EventScript_RickyRematch',
            0x081E8A12: 'Route109_EventScript_Lola',
            0x081E8A3E: 'Route109_EventScript_LolaRegisterMatchCallAfterBattle',
            0x081E8A5D: 'Route109_EventScript_LolaRematch',
            0x081E8A74: 'Route109_EventScript_Austina',
            0x081E8A8B: 'Route109_EventScript_Gwen',
            0x081E8AA2: 'Route109_EventScript_Carter',
            0x081E8AB9: 'Route109_EventScript_Paul',
            0x081E8AD4: 'Route109_EventScript_Mel',
            0x081E8AEF: 'Route109_EventScript_Chandler',
            0x081E8B06: 'Route109_EventScript_Hailey',
            0x081E8B1D: 'Route109_EventScript_Elijah',
        },
        'texts': {
            0x081E8B34: 'DewfordTown_Text_BrineyLandedInSlateportDeliverGoods',
            0x081E8B67: 'Route109_Text_BrineySailToDewfordQuestion',
            0x081E8B8A: 'Route109_Text_BrineyDewfordItIs',
            0x081E8BA7: 'Route109_Text_BrineyDeliverDevonGoods',
            0x081E8BC7: 'DewfordTown_Text_BrineyLandedInSlateport',
            0x081E8BFA: 'Route109_Text_BrineyWhereAreWeBound',
            0x081E8C2A: 'Route109_Text_BrineyTellMeWhenYouNeedToSail',
            0x081E8C50: 'Route109_Text_ChillAtMyPapasSpot',
            0x081E8C80: 'Route109_Text_LittleKidsDartAround',
            0x081E8CC7: 'Route109_Text_SandCastleTakingLongTime',
            0x081E8CDA: 'Route109_Text_YouCanHaveThis',
            0x081E8CE5: 'Route109_Text_WereGoingToMakeBigCastle',
            0x081E8D34: 'Route109_Text_ZigzagoonPicksUpLitter',
            0x081E8DB1: 'Route109_Text_ZigzagoonCry',
            0x081E8DBB: 'Route109_Text_SeashoreHouseSign',
            0x081E8DEB: 'Route109_Text_TrainerTipsSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route109']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x0095: 'FLAG_DELIVERED_DEVON_GOODS',
                0x0118: 'FLAG_RECEIVED_SOFT_SAND',
                0x02E4: 'FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN',
                0x02E7: 'FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN',
                0x02E8: 'FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT',
            },
            'trainers': {
                0x009E: 'TRAINER_DAVID',
                0x01C0: 'TRAINER_ALICE',
                0x01EA: 'TRAINER_HUEY',
                0x01EB: 'TRAINER_EDMOND',
                0x0040: 'TRAINER_RICKY_1',
                0x0039: 'TRAINER_LOLA_1',
                0x003A: 'TRAINER_AUSTINA',
                0x003B: 'TRAINER_GWEN',
                0x0159: 'TRAINER_CARTER',
                0x02A8: 'TRAINER_MEL_AND_PAUL',
                0x02BA: 'TRAINER_CHANDLER',
                0x02B9: 'TRAINER_HAILEY',
                0x02E6: 'TRAINER_ELIJAH',
            },
            'vars': {
                0x4096: 'VAR_BRINEY_LOCATION',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'items': {0x00CB: 'ITEM_SOFT_SAND'},
            'species': {0x0120: 'SPECIES_ZIGZAGOON'},
            'multichoices': {0x000E: 'MULTI_BRINEY_OFF_DEWFORD'},
        },
    },
    # Route110's trainer sequence is a closed, byte-verified subrange inside
    # the larger mixed cycling-road/rival map owner.  Keep the still-unreviewed
    # map fragments raw while naming only these US-matched trainer scripts.
    'Route110': {
        'scripts': {
            0x081E8E59: 'Route110_OnResume',
            0x081E8E5D: 'Route110_OnTransition',
            0x081E8E73: 'Route110_EventScript_SaveCyclingMusic',
            0x081E8E81: 'Route110_EventScript_BeginCylcingRoadChallenge',
            0x081E8E8A: 'Route110_EventScript_AquaGrunt1',
            0x081E8EA0: 'Route110_EventScript_AquaGrunt2',
            0x081E8EB6: 'Route110_EventScript_AquaGrunt3',
            0x081E8ECC: 'Route110_EventScript_AquaGrunt4',
            0x081E8EE2: 'Route110_EventScript_Boy1',
            0x081E8EEB: 'Route110_EventScript_CyclingGirl1',
            0x081E8EF4: 'Route110_EventScript_CyclingGuy1',
            0x081E8EFD: 'Route110_EventScript_OldMan',
            0x081E8F06: 'Route110_EventScript_OldWoman',
            0x081E8F0F: 'Route110_EventScript_CyclingGuy2',
            0x081E8F18: 'Route110_EventScript_Boy2',
            0x081E8F21: 'Route110_EventScript_SlateportCitySign',
            0x081E8F2A: 'Route110_EventScript_CyclingRoadSign',
            0x081E8F33: 'Route110_EventScript_VandalizedSign',
            0x081E8F3C: 'Route110_EventScript_Route103Sign',
            0x081E8F45: 'Route110_EventScript_SeasideParkingSign',
            0x081E8F4E: 'Route110_EventScript_MauvilleCitySign',
            0x081E8F57: 'Route110_EventScript_TrainerTipsPrlzSleep',
            0x081E8F60: 'Route110_EventScript_TrainerTipsRegisterItems',
            0x081E8F69: 'Route110_EventScript_TrickHouseSign',
            0x081E8F72: 'Route110_EventScript_CyclingRoadResultsSign',
            0x081E8F8D: 'Route110_EventScript_NoRecordSet',
            0x081E8F97: 'Route110_EventScript_ChallengeGuy',
            0x081E8FBE: 'Route110_EventScript_PlayerNotRidingBike',
            0x081E8FC8: 'Route110_EventScript_PlayerRidingAcroBike',
            0x081E8FD2: 'Route110_EventScript_Edward',
            0x081E8FE9: 'Route110_EventScript_Jaclyn',
            0x081E9000: 'Route110_EventScript_Edwin',
            0x081E902C: 'Route110_EventScript_EdwinRegisterMatchCallAfterBattle',
            0x081E904B: 'Route110_EventScript_EdwinRematch',
            0x081E9062: 'Route110_EventScript_Dale',
            0x081E9079: 'Route110_EventScript_Jacob',
            0x081E9090: 'Route110_EventScript_Anthony',
            0x081E90A7: 'Route110_EventScript_Benjamin',
            0x081E90D3: 'Route110_EventScript_BenjaminRegisterMatchCallAfterBattle',
            0x081E90F2: 'Route110_EventScript_BenjaminRematch',
            0x081E9109: 'Route110_EventScript_Jasmine',
            0x081E9120: 'Route110_EventScript_Abigail',
            0x081E914C: 'Route110_EventScript_AbigailRegisterMatchCallAfterBattle',
            0x081E916B: 'Route110_EventScript_AbigailRematch',
            0x081E9182: 'Route110_EventScript_Isabel',
            0x081E91AE: 'Route110_EventScript_IsabelRegisterMatchCallAfterBattle',
            0x081E91CD: 'Route110_EventScript_IsabelRematch',
            0x081E91E4: 'Route110_EventScript_Timmy',
            0x081E91FB: 'Route110_EventScript_Unused',
            0x081E91FC: 'Route110_EventScript_Kaleb',
            0x081E9213: 'Route110_EventScript_Joseph',
            0x081E922A: 'Route110_EventScript_Alyssa',
            0x081E9241: 'Route110_EventScript_CyclingChallengeEnd',
            0x081E9253: 'Route110_EventScript_CyclingChallengeResults',
            0x081E92DD: 'Route110_EventScript_ChallengeReactionBest',
            0x081E92EB: 'Route110_EventScript_ChallengeReactionGood',
            0x081E92F9: 'Route110_EventScript_ChallengeReactionOk',
            0x081E9307: 'Route110_EventScript_ChallengeReactionBad',
            0x081E9315: 'Route110_EventScript_ChallengeReactionWorst',
            0x081E9323: 'Route110_EventScript_EndChallenge',
            0x081E932D: 'Route110_EventScript_RivalTrigger1',
            0x081E9338: 'Route110_EventScript_RivalTrigger2',
            0x081E9343: 'Route110_EventScript_RivalTrigger3',
            0x081E934E: 'Route110_EventScript_RivalScene',
            0x081E93C1: 'Route110_EventScript_PlayMayMusic',
            0x081E93C6: 'Route110_EventScript_PlayBrendanMusic',
            0x081E93CB: 'Route110_EventScript_MayBattle',
            0x081E93FA: 'Route110_EventScript_MayBattleTreecko',
            0x081E940A: 'Route110_EventScript_MayBattleTorchic',
            0x081E941A: 'Route110_EventScript_MayBattleMudkip',
            0x081E942A: 'Route110_EventScript_MayDefeated',
            0x081E9445: 'Route110_EventScript_BrendanBattle',
            0x081E9474: 'Route110_EventScript_BrendanBattleTreecko',
            0x081E9484: 'Route110_EventScript_BrendanBattleTorchic',
            0x081E9494: 'Route110_EventScript_BrendanBattleMudkip',
            0x081E94A4: 'Route110_EventScript_BrendanDefeated',
            0x081E94BF: 'Route110_EventScript_GiveItemfinder',
            0x081E94CC: 'Route110_EventScript_RivalExit',
            0x081E952E: 'Route110_EventScript_RivalApproachPlayer1',
            0x081E9539: 'Route110_EventScript_RivalApproachPlayer2',
            0x081E9544: 'Route110_EventScript_RivalApproachPlayer3',
            0x081E954F: 'Route110_EventScript_RivalExit1',
            0x081E955A: 'Route110_EventScript_RivalExit2',
            0x081E9565: 'Route110_EventScript_RivalExit3',
            0x081E9570: 'Route110_EventScript_MoveRival1',
            0x081E9578: 'Route110_EventScript_MoveRival2',
            0x081E9580: 'Route110_EventScript_MoveRival3',
            0x081E95AB: 'Route110_EventScript_BirchScene1',
            0x081E95B6: 'Route110_EventScript_BirchScene2',
            0x081E95C1: 'Route110_EventScript_BirchScene3',
            0x081E95CC: 'Route110_EventScript_BirchScene4',
            0x081E95D7: 'Route110_EventScript_BirchScene',
            0x081E96B8: 'Route110_EventScript_BirchApproachPlayer1',
            0x081E96C3: 'Route110_EventScript_BirchApproachPlayer2',
            0x081E96CE: 'Route110_EventScript_BirchApproachPlayer3',
            0x081E96D9: 'Route110_EventScript_BirchApproachPlayer4',
            0x081E96E4: 'Route110_EventScript_BirchExit1',
            0x081E96EF: 'Route110_EventScript_BirchExit2',
            0x081E96FA: 'Route110_EventScript_BirchExit3',
            0x081E9705: 'Route110_EventScript_BirchExit4',
        },
        'tables': {0x081E8E77: 'Route110_OnFrame'},
        'texts': {
            0x081E973D: 'Route110_Text_WeCantTalkAboutAquaActivities',
            0x081E975D: 'Route110_Text_KickUpARuckus',
            0x081E9778: 'Route110_Text_MyFirstJobInAqua',
            0x081E9798: 'Route110_Text_AquaActionsBringSmiles',
            0x081E97B9: 'Route110_Text_MayLetsBattle',
            0x081E9809: 'Route110_Text_MayDefeated',
            0x081E981E: 'Route110_Text_MayTakeThis',
            0x081E9851: 'Route110_Text_MayExplainItemfinder',
            0x081E98F4: 'Route110_Text_BrendanLetsBattle',
            0x081E9931: 'Route110_Text_BrendanDefeated',
            0x081E9940: 'Route110_Text_BrendanTakeThis',
            0x081E996A: 'Route110_Text_BrendanExplainItemfinder',
            0x081E99CB: 'Route110_Text_RideBikeAtFullSpeed',
            0x081E99FA: 'Route110_Text_HairStreamsBehindMe',
            0x081E9A24: 'Route110_Text_YouGotBikeFromRydel',
            0x081E9B41: 'Route110_Text_TwoRoads',
            0x081E9B80: 'Route110_Text_WalkOnTheLowRoad',
            0x081E9BAC: 'Route110_Text_BikeTechniques',
            0x081E9BF1: 'Route110_Text_WhichShouldIChoose',
            0x081E9C26: 'Route110_Text_CyclingChallengeResultSummary',
            0x081E9C4A: 'Route110_Text_ChallengeReactionBest',
            0x081E9C81: 'Route110_Text_ChallengeReactionGood',
            0x081E9CBA: 'Route110_Text_ChallengeReactionOk',
            0x081E9CF1: 'Route110_Text_ChallengeReactionBad',
            0x081E9D1D: 'Route110_Text_ChallengeReactionWorst',
            0x081E9D56: 'Route110_Text_RatedForNumberOfCollisions',
            0x081E9DAD: 'Route110_Text_AlwaysAimHigher',
            0x081E9DD5: 'Route110_Text_AcroBikesDoNotQualify',
            0x081E9E44: 'Route110_Text_SlateportCitySign',
            0x081E9E5D: 'Route110_Text_CyclingRoadSign',
            0x081E9E70: 'Route110_Text_AquaWasHere',
            0x081E9EC1: 'Route110_Text_Route103Sign',
            0x081E9EDD: 'Route110_Text_SeasideParkingSign',
            0x081E9EEB: 'Route110_Text_MauvilleCitySign',
            0x081E9F05: 'Route110_Text_TrainerTipsPrlzSleep',
            0x081E9F56: 'Route110_Text_TrainerTipsRegisterItems',
            0x081E9F95: 'Route110_Text_TrickHouseSign',
            0x081E9FC0: 'Route110_Text_BestRecord',
            0x081E9FF5: 'Route110_Text_ThereIsNoRecord',
            0x081EA02B: 'Route110_Text_ImagineSeeingYouHere',
            0x081EA057: 'Route110_Text_HeardYouInstallMatchCall',
            0x081EA0F2: 'Route110_Text_RegisteredBirchInPokenav',
            0x081EA10A: 'Route110_Text_KeepAnEyeOutForRival',
        },
        # These field messages are paired one-for-one with the matching US
        # Route110 text.  Use the proven placeholder meanings instead of
        # exposing their raw FD indices in regenerated source.
        'field_placeholders': {
            0x081E97B9: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E981E: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E9851: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E98F4: {0x01: 'PLAYER'},
            0x081E9940: {0x01: 'PLAYER'},
            0x081E9C26: {0x02: 'STR_VAR_1', 0x03: 'STR_VAR_2'},
            0x081E9FC0: {0x02: 'STR_VAR_1', 0x03: 'STR_VAR_2'},
            0x081EA02B: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
            0x081EA10A: {0x01: 'PLAYER', 0x05: 'KUN', 0x06: 'RIVAL'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route110']['labels'],
        'external_labels': {
            0x08242F63: 'Common_EventScript_SetupRivalGfxId',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'trainers': {
                0x00E8: 'TRAINER_EDWARD',
                0x00F3: 'TRAINER_JACLYN',
                0x0200: 'TRAINER_EDWIN_1',
                0x0155: 'TRAINER_DALE',
                0x015F: 'TRAINER_JACOB',
                0x0160: 'TRAINER_ANTHONY',
                0x0161: 'TRAINER_BENJAMIN_1',
                0x0167: 'TRAINER_JASMINE',
                0x0166: 'TRAINER_ABIGAIL_1',
                0x012E: 'TRAINER_ISABEL_1',
                0x014E: 'TRAINER_TIMMY',
                0x02BB: 'TRAINER_KALEB',
                0x02BC: 'TRAINER_JOSEPH',
                0x02BD: 'TRAINER_ALYSSA',
                0x0209: 'TRAINER_BRENDAN_ROUTE_110_MUDKIP',
                0x020C: 'TRAINER_BRENDAN_ROUTE_110_TREECKO',
                0x020F: 'TRAINER_BRENDAN_ROUTE_110_TORCHIC',
                0x0212: 'TRAINER_MAY_ROUTE_110_MUDKIP',
                0x0215: 'TRAINER_MAY_ROUTE_110_TREECKO',
                0x0218: 'TRAINER_MAY_ROUTE_110_TORCHIC',
            },
            'vars': {
                0x4023: 'VAR_STARTER_MON',
                0x4069: 'VAR_ROUTE110_STATE',
                0x40A9: 'VAR_CYCLING_CHALLENGE_STATE',
                0x40DA: 'VAR_REGISTER_BIRCH_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'flags': {0x0119: 'FLAG_ENABLE_PROF_BIRCH_MATCH_CALL'},
            'items': {0x0105: 'ITEM_ITEMFINDER'},
            'songs': {
                0x0000: 'MUS_DUMMY',
                0x0193: 'MUS_CYCLING',
                0x019F: 'MUS_ENCOUNTER_MAY',
                0x01A5: 'MUS_ENCOUNTER_BRENDAN',
                0x01CC: 'MUS_REGISTER_MATCH_CALL',
            },
            'sounds': {0x0015: 'SE_PIN'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'local_ids': {
                0x15: 'LOCALID_CHALLENGE_BIKER',
                0x1C: 'LOCALID_ROUTE110_RIVAL',
                0x1D: 'LOCALID_ROUTE110_RIVAL_ON_BIKE',
                0x24: 'LOCALID_ROUTE110_BIRCH',
            },
            'movement_types': {0x0A: 'MOVEMENT_TYPE_FACE_RIGHT'},
        },
    },
    # Route111 has the same script/movement/text ordering as the US owner.
    # Addresses below were checked against the JP control-flow graph and the
    # complete 0x081EA14D-0x081EAE8C reassembly, rather than paired by name
    # alone.
    'Route111': {
        'scripts': {
            0x081EA162: 'Route111_OnLoad',
            0x081EA177: 'Route111_EventScript_CloseDesertRuins',
            0x081EA18A: 'Route111_EventScript_ShowTemporaryMirageTower',
            0x081EA22D: 'Route111_OnTransition',
            0x081EA268: 'Route111_EventScript_SetFallingPlayerGfx',
            0x081EA280: 'Route111_EventScript_SetFallingPlayerGfxMale',
            0x081EA286: 'Route111_EventScript_SetFallingPlayerGfxFemale',
            0x081EA28C: 'Route111_EventScript_CheckSetSandstorm',
            0x081EA2C8: 'Route111_EventScript_SetSandstorm',
            0x081EA2CB: 'Route111_EventScript_EndCheckSetSandstorm',
            0x081EA2CC: 'Route111_EventScript_SetWinstratesNotDefeated',
            0x081EA2E2: 'Route111_EventScript_SetLayoutNoMirageTower',
            0x081EA2E6: 'Route111_EventScript_SetMirageTowerGone',
            0x081EA2F6: 'Route111_EventScript_HidePlayerForMirageTower',
            0x081EA306: 'Route111_EventScript_MirageTowerDisappear',
            0x081EA34D: 'Route111_EventScript_RootFossilDisappeared',
            0x081EA35F: 'Route111_EventScript_Girl',
            0x081EA39A: 'Route111_EventScript_ReceivedBerry',
            0x081EA3A4: 'Route111_EventScript_ViciousSandstormTriggerUp',
            0x081EA3B0: 'Route111_EventScript_ViciousSandstormTriggerDown',
            0x081EA3BC: 'Route111_EventScript_ViciousSandstormTriggerLeft',
            0x081EA3C8: 'Route111_EventScript_ViciousSandstormTriggerRight',
            0x081EA3D4: 'Route111_EventScript_ViciousSandstormTrigger',
            0x081EA3EB: 'Route111_EventScript_PreventRouteAccess',
            0x081EA422: 'Route111_EventScript_PushUpFromRoute',
            0x081EA42D: 'Route111_EventScript_PushDownFromRoute',
            0x081EA438: 'Route111_EventScript_PushLeftFromRoute',
            0x081EA443: 'Route111_EventScript_PushRightFromRoute',
            0x081EA456: 'Route111_EventScript_SunTrigger',
            0x081EA463: 'Route111_EventScript_SandstormTrigger',
            0x081EA46B: 'Route111_EventScript_Victor',
            0x081EA48D: 'Route111_EventScript_BattleWinstrates',
            0x081EA5E2: 'Route111_EventScript_OpenWinstrateDoor',
            0x081EA5E9: 'Route111_EventScript_CloseWinstrateDoor',
            0x081EA5F9: 'Route111_EventScript_RouteSignMauville',
            0x081EA602: 'Route111_EventScript_WinstrateHouseSign',
            0x081EA60B: 'Route111_EventScript_RouteSign112',
            0x081EA614: 'Route111_EventScript_RouteSign113',
            0x081EA61D: 'Route111_EventScript_OldLadysRestStopSign',
            0x081EA626: 'Route111_EventScript_TrainerTipsSpAtkSpDef',
            0x081EA62F: 'Route111_EventScript_Man1',
            0x081EA638: 'Route111_EventScript_Man2',
            0x081EA641: 'Route111_EventScript_Hiker',
            0x081EA66C: 'Route111_EventScript_HikerMirageTowerGone',
            0x081EA676: 'Route111_EventScript_HikerMirageTowerDisintegrated',
            0x081EA680: 'Route111_EventScript_HikerMirageTowerVisible',
            0x081EA68A: 'Route111_EventScript_RockSmashTipFatMan',
            0x081EA6AA: 'Route111_EventScript_Drew',
            0x081EA6C1: 'Route111_EventScript_Heidi',
            0x081EA6D8: 'Route111_EventScript_Beau',
            0x081EA6EF: 'Route111_EventScript_Becky',
            0x081EA706: 'Route111_EventScript_Dusty',
            0x081EA732: 'Route111_EventScript_RegisterDusty',
            0x081EA751: 'Route111_EventScript_RematchDusty',
            0x081EA768: 'Route111_EventScript_Travis',
            0x081EA77F: 'Route111_EventScript_Irene',
            0x081EA796: 'Route111_EventScript_Daisuke',
            0x081EA7AD: 'Route111_EventScript_Wilton',
            0x081EA7D9: 'Route111_EventScript_RegisterWilton',
            0x081EA7F8: 'Route111_EventScript_RematchWilton',
            0x081EA80F: 'Route111_EventScript_Brooke',
            0x081EA83B: 'Route111_EventScript_RegisterBrooke',
            0x081EA85A: 'Route111_EventScript_RematchBrooke',
            0x081EA871: 'Route111_EventScript_Hayden',
            0x081EA888: 'Route111_EventScript_Bianca',
            0x081EA89F: 'Route111_EventScript_Tyron',
            0x081EA8B6: 'Route111_EventScript_Celina',
            0x081EA8CD: 'Route111_EventScript_Celia',
            0x081EA8E4: 'Route111_EventScript_Bryan',
            0x081EA8FB: 'Route111_EventScript_Branden',
            0x081EA912: 'Route111_EventScript_TrainerHillSign',
        },
        'tables': {
            0x081EA2EC: 'Route111_OnWarp',
            0x081EA2FC: 'Route111_OnFrame',
        },
        'texts': {
            0x081EA91B: 'Route111_Text_BattleOurFamily',
            0x081EA95E: 'Route111_Text_IsThatSo',
            0x081EA973: 'Route111_Text_VictorIntro',
            0x081EA985: 'Route111_Text_VictorDefeat',
            0x081EA9A0: 'Route111_Text_VictorPostBattle',
            0x081EA9BB: 'Route111_Text_VictoriaIntro',
            0x081EAA09: 'Route111_Text_VictoriaDefeat',
            0x081EAA22: 'Route111_Text_VictoriaPostBattle',
            0x081EAA3C: 'Route111_Text_ViviIntro',
            0x081EAA6E: 'Route111_Text_ViviDefeat',
            0x081EAA80: 'Route111_Text_ViviPostBattle',
            0x081EAA9A: 'Route111_Text_VickyIntro',
            0x081EAADB: 'Route111_Text_VickyDefeat',
            0x081EAAFC: 'Route111_Text_VickyPostBattle',
            0x081EAB21: 'Route111_Text_ToughToKeepWinningUpTheRanks',
            0x081EAB71: 'Route111_Text_WinstrateFamilyDestroyedMe',
            0x081EABA8: 'Route111_Text_RouteSignMauville',
            0x081EABC2: 'Route111_Text_WinstrateHouseSign',
            0x081EABE5: 'Route111_Text_RouteSign112',
            0x081EAC01: 'Route111_Text_RouteSign113',
            0x081EAC1D: 'Route111_Text_OldLadysRestStopSign',
            0x081EAC42: 'Route111_Text_TrainerTipsSpAtkSpDef',
            0x081EAC9B: 'Route111_Text_ShouldBeMirageTowerAroundHere',
            0x081EACF8: 'Route111_Text_MirageTowerClearlyVisible',
            0x081EAD65: 'Route111_Text_ThatWasShockingSandRainedDown',
            0x081EADB1: 'Route111_Text_MirageTowerHasntBeenSeenSince',
            0x081EADDB: 'Route111_Text_ClawFossilDisappeared',
            0x081EADF3: 'Route111_Text_RootFossilDisappeared',
            0x081EAE0C: 'Route111_Text_MauvilleUncleToldMeToTakeRockSmash',
            0x081EAE67: 'Route111_Text_TrainerHillSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route111']['labels'],
    },
    'Route112': {
        'scripts': {
            0x081EAE92: 'Route112_OnTransition',
            0x081EAE9B: 'Route112_EventScript_MagmaGrunts',
            0x081EAF2A: 'Route112_EventScript_MtChimneyCableCarSign',
            0x081EAF33: 'Route112_EventScript_MtChimneySign',
            0x081EAF3C: 'Route112_EventScript_RouteSignLavaridge',
            0x081EAF45: 'Route112_EventScript_Hiker',
            0x081EAF4E: 'Route112_EventScript_Brice',
            0x081EAF65: 'Route112_EventScript_Trent',
            0x081EAF91: 'Route112_EventScript_RegisterTrent',
            0x081EAFB0: 'Route112_EventScript_RematchTrent',
            0x081EAFC7: 'Route112_EventScript_Larry',
            0x081EAFDE: 'Route112_EventScript_Carol',
            0x081EAFF5: 'Route112_EventScript_Bryant',
            0x081EB00C: 'Route112_EventScript_Shayla',
        },
        'texts': {
            0x081EB023: 'Route112_Text_LeaderGoingToAwakenThing',
            0x081EB047: 'Route112_Text_YeahWeNeedMeteorite',
            0x081EB06C: 'Route112_Text_OhThatsWhyCrewWentToFallarbor',
            0x081EB08B: 'Route112_Text_CantLetAnyonePassUntilTheyreBack',
            0x081EB0B0: 'Route112_Text_NotEasyToGetBackToLavaridge',
            0x081EB0EC: 'Route112_Text_MtChimneyCableCarSign',
            0x081EB10D: 'Route112_Text_MtChimneySign',
            0x081EB13A: 'Route112_Text_RouteSignLavaridge',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route112']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x009D: 'FLAG_FORCE_MIRAGE_TOWER_VISIBLE'},
            'vars': {
                0x40BD: 'VAR_JAGGED_PASS_ASH_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'trainers': {
                0x0272: 'TRAINER_BRICE',
                0x0273: 'TRAINER_TRENT_1',
                0x00D5: 'TRAINER_LARRY',
                0x01D7: 'TRAINER_CAROL',
                0x02EA: 'TRAINER_BRYANT',
                0x02EB: 'TRAINER_SHAYLA',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'local_ids': {
                0x01: 'LOCALID_ROUTE112_GRUNT_1',
                0x06: 'LOCALID_ROUTE112_GRUNT_2',
            },
        },
    },
    'Route113': {
        'scripts': {
            0x081EB15E: 'Route113_OnResume',
            0x081EB161: 'Route113_OnTransition',
            0x081EB16A: 'Route113_EventScript_CheckSetAshWeather',
            0x081EB189: 'Route113_EventScript_DontSetAshWeather',
            0x081EB18A: 'Route113_EventScript_Gentleman',
            0x081EB193: 'Route113_EventScript_NinjaBoy',
            0x081EB19C: 'Route113_EventScript_RouteSign111',
            0x081EB1A5: 'Route113_EventScript_RouteSignFallarbor',
            0x081EB1AE: 'Route113_EventScript_GlassWorkshopSign',
            0x081EB1B7: 'Route113_EventScript_TrainerTipsRegisterKeyItems',
            0x081EB1C0: 'Route113_EventScript_Jaylen',
            0x081EB1D7: 'Route113_EventScript_Dillon',
            0x081EB1EE: 'Route113_EventScript_Madeline',
            0x081EB21A: 'Route113_EventScript_RegisterMadeline',
            0x081EB239: 'Route113_EventScript_RematchMadeline',
            0x081EB250: 'Route113_EventScript_Lao',
            0x081EB27C: 'Route113_EventScript_RegisterLao',
            0x081EB29B: 'Route113_EventScript_RematchLao',
            0x081EB2B2: 'Route113_EventScript_Lung',
            0x081EB2C9: 'Route113_EventScript_Tori',
            0x081EB2E4: 'Route113_EventScript_Tia',
            0x081EB2FF: 'Route113_EventScript_Sophie',
            0x081EB316: 'Route113_EventScript_Coby',
            0x081EB32D: 'Route113_EventScript_Lawrence',
            0x081EB344: 'Route113_EventScript_Wyatt',
        },
        'texts': {
            0x081EB35B: 'Route113_Text_AshCanBeFashionedIntoGlass',
            0x081EB397: 'Route113_Text_FunWalkingThroughAsh',
            0x081EB3CC: 'Route113_Text_RouteSign111',
            0x081EB3E8: 'Route113_Text_RouteSignFallarbor',
            0x081EB402: 'Route113_Text_TrainerTipsRegisterKeyItems',
            0x081EB454: 'Route113_Text_GlassWorkshopSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route113']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x009D: 'FLAG_FORCE_MIRAGE_TOWER_VISIBLE'},
            'vars': {
                0x4000: 'VAR_TEMP_0',
                0x4001: 'VAR_TEMP_1',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'trainers': {
                0x0146: 'TRAINER_JAYLEN',
                0x0147: 'TRAINER_DILLON',
                0x01B2: 'TRAINER_MADELINE_1',
                0x01A3: 'TRAINER_LAO_1',
                0x01A4: 'TRAINER_LUNG',
                0x02A5: 'TRAINER_TORI_AND_TIA',
                0x02C4: 'TRAINER_SOPHIE',
                0x02C5: 'TRAINER_COBY',
                0x02C6: 'TRAINER_LAWRENCE',
                0x02C7: 'TRAINER_WYATT',
            },
            'weather': {0x07: 'WEATHER_VOLCANIC_ASH'},
            'step_callbacks': {0x01: 'STEP_CB_ASH'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route114': {
        'scripts': {
            0x081EB484: 'Route114_OnTransition',
            0x081EB4A6: 'Route114_OnLoad',
            0x081EB4C7: 'Route114_EventScript_Man',
            0x081EB50C: 'Route114_EventScript_ReceivedBerry',
            0x081EB516: 'Route114_EventScript_RoarGentleman',
            0x081EB54D: 'Route114_EventScript_ReceivedRoar',
            0x081EB557: 'Route114_EventScript_Poochyena',
            0x081EB56A: 'Route114_EventScript_MeteorFallsSign',
            0x081EB573: 'Route114_EventScript_FossilManiacsHouseSign',
            0x081EB57C: 'Route114_EventScript_LanettesHouseSign',
            0x081EB585: 'Route114_EventScript_Lenny',
            0x081EB59C: 'Route114_EventScript_Lucas',
            0x081EB5B3: 'Route114_EventScript_Shane',
            0x081EB5CA: 'Route114_EventScript_Nancy',
            0x081EB5E1: 'Route114_EventScript_Steve',
            0x081EB60D: 'Route114_EventScript_RegisterSteve',
            0x081EB62C: 'Route114_EventScript_RematchSteve',
            0x081EB643: 'Route114_EventScript_Bernie',
            0x081EB66F: 'Route114_EventScript_RegisterBernie',
            0x081EB68E: 'Route114_EventScript_RematchBernie',
            0x081EB6A5: 'Route114_EventScript_Claude',
            0x081EB6BC: 'Route114_EventScript_Nolan',
            0x081EB6D3: 'Route114_EventScript_Tyra',
            0x081EB6EE: 'Route114_EventScript_Ivy',
            0x081EB709: 'Route114_EventScript_Angelina',
            0x081EB720: 'Route114_EventScript_Charlotte',
            0x081EB737: 'Route114_EventScript_Kai',
        },
        'tables': {0x081EB4BD: 'Route114_OnFrame'},
        'texts': {
            0x081EB74E: 'Route114_Text_AllMyMonDoesIsRoarTakeThis',
            0x081EB78B: 'Route114_Text_ExplainRoar',
            0x081EB7B3: 'Route114_Text_Poochyena',
            0x081EB7C0: 'Route114_Text_MeteorFallsSign',
            0x081EB7DD: 'Route114_Text_FossilManiacsHouseSign',
            0x081EB7FA: 'Route114_Text_LanettesHouse',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route114']['labels'],
        'external_labels': {
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x00E7: 'FLAG_RECEIVED_TM_ROAR',
                0x092B: 'FLAG_DAILY_ROUTE_114_RECEIVED_BERRY',
            },
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0x1: 'ABNORMAL_WEATHER_ROUTE_114_NORTH',
                    0x2: 'ABNORMAL_WEATHER_ROUTE_114_SOUTH',
                },
            },
            # JP constants retain numeric TM names; ITEM_TM05 is Roar.
            'items': {0x0125: 'ITEM_TM05'},
            'species': {0x011E: 'SPECIES_POOCHYENA'},
            'trainers': {
                0x0274: 'TRAINER_LENNY',
                0x0275: 'TRAINER_LUCAS_1',
                0x00D6: 'TRAINER_SHANE',
                0x01D8: 'TRAINER_NANCY',
                0x008F: 'TRAINER_STEVE_1',
                0x00CE: 'TRAINER_BERNIE_1',
                0x0152: 'TRAINER_CLAUDE',
                0x0156: 'TRAINER_NOLAN',
                0x02A7: 'TRAINER_TYRA_AND_IVY',
                0x02C8: 'TRAINER_ANGELINA',
                0x02CA: 'TRAINER_CHARLOTTE',
                0x02C9: 'TRAINER_KAI',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route115': {
        'scripts': {
            0x081EB814: 'Route115_OnLoad',
            0x081EB82B: 'Route115_OnTransition',
            0x081EB857: 'Route115_EventScript_Woman',
            0x081EB860: 'Route115_EventScript_RouteSignRustboro',
            0x081EB869: 'Route115_EventScript_MeteorFallsSign',
            0x081EB872: 'Route115_EventScript_Timothy',
            0x081EB89E: 'Route115_EventScript_RegisterTimothy',
            0x081EB8BD: 'Route115_EventScript_RematchTimothy',
            0x081EB8D4: 'Route115_EventScript_Koichi',
            0x081EB8EB: 'Route115_EventScript_Nob',
            0x081EB917: 'Route115_EventScript_RegisterNob',
            0x081EB936: 'Route115_EventScript_RematchNob',
            0x081EB94D: 'Route115_EventScript_Cyndy',
            0x081EB979: 'Route115_EventScript_RegisterCyndy',
            0x081EB998: 'Route115_EventScript_RematchCyndy',
            0x081EB9AF: 'Route115_EventScript_Hector',
            0x081EB9C6: 'Route115_EventScript_Kyra',
            0x081EB9DD: 'Route115_EventScript_Jaiden',
            0x081EB9F4: 'Route115_EventScript_Alix',
            0x081EBA0B: 'Route115_EventScript_Helene',
            0x081EBA22: 'Route115_EventScript_Marlene',
        },
        'tables': {0x081EB84D: 'Route115_OnFrame'},
        'texts': {
            0x081EBA39: 'Route115_Text_NeverKnowWhenCavePokemonWillAppear',
            0x081EBA7E: 'Route115_Text_RouteSignRustboro',
            0x081EBA98: 'Route115_Text_MeteorFallsSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route115']['labels'],
        'external_labels': {
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0x3: 'ABNORMAL_WEATHER_ROUTE_115_WEST',
                    0x4: 'ABNORMAL_WEATHER_ROUTE_115_EAST',
                },
            },
            'trainers': {
                0x0133: 'TRAINER_TIMOTHY_1',
                0x00B6: 'TRAINER_KOICHI',
                0x00B7: 'TRAINER_NOB_1',
                0x01AB: 'TRAINER_CYNDY_1',
                0x0201: 'TRAINER_HECTOR',
                0x02EC: 'TRAINER_KYRA',
                0x02ED: 'TRAINER_JAIDEN',
                0x02EE: 'TRAINER_ALIX',
                0x02EF: 'TRAINER_HELENE',
                0x02F0: 'TRAINER_MARLENE',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route116': {
        'scripts': {
            0x081EBAC5: 'Route116_OnTransition',
            0x081EBAF0: 'Route116_EventScript_SetWandasBoyfriendPos',
            0x081EBAF8: 'Route116_OnLoad',
            0x081EBB19: 'Route116_EventScript_WandasBoyfriend',
            0x081EBB37: 'Route116_EventScript_BoyfriendGruntLeftTunnel',
            0x081EBB41: 'Route116_EventScript_BoyfriendGruntInTunnel',
            0x081EBB4B: 'Route116_EventScript_DevonEmployee',
            0x081EBB64: 'Route116_EventScript_GiveRepeatBall',
            0x081EBBBE: 'Route116_EventScript_DevonEmployeeExit',
            0x081EBBC9: 'Route116_EventScript_DevonEmployeeExitEast',
            0x081EBBD4: 'Route116_EventScript_TryGiveRepeatBallAgain',
            0x081EBBE2: 'Route116_EventScript_NoRoomForRepeatBall',
            0x081EBC00: 'Route116_EventScript_RouteSignRustboro',
            0x081EBC09: 'Route116_EventScript_RusturfTunnelSign',
            0x081EBC12: 'Route116_EventScript_TunnelersRestHouseSign',
            0x081EBC1B: 'Route116_EventScript_TrainerTipsBToStopEvolution',
            0x081EBC24: 'Route116_EventScript_TrainerTipsBagHasPockets',
            0x081EBC2D: 'Route116_EventScript_Briney',
            0x081EBC3E: 'Route116_EventScript_BrineyTrigger',
            0x081EBC5F: 'Route116_EventScript_GlassesMan',
            0x081EBC8B: 'Route116_EventScript_FoundGlassesNotOnPlayer',
            0x081EBC9A: 'Route116_EventScript_PlayerHasGlasses',
            0x081EBCC4: 'Route116_EventScript_FoundGlassesOnPlayer',
            0x081EBCD3: 'Route116_EventScript_GlassesManExit',
            0x081EBD07: 'Route116_EventScript_GlassesManExitNormal',
            0x081EBD12: 'Route116_EventScript_GlassesManExitEast',
            0x081EBD32: 'Route116_EventScript_Joey',
            0x081EBD49: 'Route116_EventScript_Jose',
            0x081EBD60: 'Route116_EventScript_Jerry',
            0x081EBDA1: 'Route116_EventScript_TryRegisterJerryAfterBattle',
            0x081EBDAC: 'Route116_EventScript_RegisterJerryAfterBattle',
            0x081EBDCB: 'Route116_EventScript_TryRegisterJerry',
            0x081EBDDE: 'Route116_EventScript_RegisterJerry',
            0x081EBDF7: 'Route116_EventScript_RematchJerry',
            0x081EBE0E: 'Route116_EventScript_Clark',
            0x081EBE25: 'Route116_EventScript_Janice',
            0x081EBE3C: 'Route116_EventScript_Karen',
            0x081EBE7D: 'Route116_EventScript_TryRegisterKarenAfterBattle',
            0x081EBE88: 'Route116_EventScript_RegisterKarenAfterBattle',
            0x081EBEA7: 'Route116_EventScript_TryRegisterKaren',
            0x081EBEBA: 'Route116_EventScript_RegisterKaren',
            0x081EBED3: 'Route116_EventScript_RematchKaren',
            0x081EBEEA: 'Route116_EventScript_Sarah',
            0x081EBF01: 'Route116_EventScript_Dawson',
            0x081EBF18: 'Route116_EventScript_Devan',
            0x081EBF2F: 'Route116_EventScript_Johnson',
        },
        'tables': {0x081EBB0F: 'Route116_OnFrame'},
        'texts': {
            0x081EBF46: 'Route116_Text_ScoundrelMadeOffWithPeeko',
            0x081EBFAA: 'Route116_Text_WantToDigTunnel',
            0x081EBFBC: 'Route116_Text_DiggingTunnelWhenGoonOrderedMeOut',
            0x081EC06B: 'Route116_Text_GoonHightailedItOutOfTunnel',
            0x081EC094: 'Route116_Text_ThankYouTokenOfAppreciation',
            0x081EC1A8: 'Route116_Text_NewBallAvailableAtMart',
            0x081EC1EC: 'Route116_Text_BagIsJamPacked',
            0x081EC206: 'Route116_Text_TokenOfAppreciation',
            0x081EC24C: 'Route116_Text_CanYouHelpMeFindGlasses',
            0x081EC26A: 'Route116_Text_MayISeeThoseGlasses',
            0x081EC27F: 'Route116_Text_NotWhatImLookingForMaybeTheyArentHere',
            0x081EC2BC: 'Route116_Text_CantFindGlassesNotHere',
            0x081EC2E9: 'Route116_Text_NotWhatImLookingFor',
            0x081EC312: 'Route116_Text_RouteSignRustboro',
            0x081EC32C: 'Route116_Text_RusturfTunnelSign',
            0x081EC35D: 'Route116_Text_TunnelersRestHouse',
            0x081EC371: 'Route116_Text_TrainerTipsBToStopEvolution',
            0x081EC3BD: 'Route116_Text_TrainerTipsBagHasPockets',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route116']['labels'],
        'external_labels': {
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x008E: 'FLAG_DEVON_GOODS_STOLEN',
                0x008F: 'FLAG_RECOVERED_DEVON_GOODS',
                0x0100: 'FLAG_RECEIVED_REPEAT_BALL',
                0x011F: 'FLAG_MET_DEVON_EMPLOYEE',
                0x012F: 'FLAG_HAS_MATCH_CALL',
                0x03B5: 'FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE',
            },
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x406F: 'VAR_ROUTE116_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'var_values': {
                0x4037: {
                    0x5: 'ABNORMAL_WEATHER_ROUTE_116_NORTH',
                    0x6: 'ABNORMAL_WEATHER_ROUTE_116_SOUTH',
                },
            },
            'local_ids': {
                0x0B: 'LOCALID_ROUTE116_BRINEY',
                0x15: 'LOCALID_ROUTE116_WANDAS_BF',
                0xFF: 'LOCALID_PLAYER',
            },
            'items': {
                0x0009: 'ITEM_REPEAT_BALL',
                0x00CE: 'ITEM_BLACK_GLASSES',
            },
            'directions': {
                0x1: 'DIR_SOUTH',
                0x2: 'DIR_NORTH',
                0x3: 'DIR_WEST',
                0x4: 'DIR_EAST',
            },
            'trainers': {
                0x0111: 'TRAINER_JERRY_1',
                0x0118: 'TRAINER_KAREN_1',
                0x0142: 'TRAINER_JOEY',
                0x025D: 'TRAINER_JANICE',
                0x0269: 'TRAINER_JOSE',
                0x0277: 'TRAINER_CLARK',
                0x02B6: 'TRAINER_DAWSON',
                0x02B7: 'TRAINER_SARAH',
                0x02F1: 'TRAINER_DEVAN',
                0x02F2: 'TRAINER_JOHNSON',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route117': {
        'scripts': {
            0x081EC429: 'Route117_OnTransition',
            0x081EC42F: 'Route117_EventScript_TryMoveDayCareMan',
            0x081EC43F: 'Route117_EventScript_StopMoveDayCareMan',
            0x081EC440: 'Route117_EventScript_Woman',
            0x081EC449: 'Route117_EventScript_LittleBoy',
            0x081EC452: 'Route117_EventScript_Girl',
            0x081EC45B: 'Route117_EventScript_RouteSignVerdanturf',
            0x081EC464: 'Route117_EventScript_RouteSignMauville',
            0x081EC46D: 'Route117_EventScript_DayCareSign',
            0x081EC476: 'Route117_EventScript_Isaac',
            0x081EC4A2: 'Route117_EventScript_RegisterIsaac',
            0x081EC4C1: 'Route117_EventScript_RematchIsaac',
            0x081EC4D8: 'Route117_EventScript_Lydia',
            0x081EC504: 'Route117_EventScript_RegisterLydia',
            0x081EC523: 'Route117_EventScript_RematchLydia',
            0x081EC53A: 'Route117_EventScript_Dylan',
            0x081EC566: 'Route117_EventScript_RegisterDylan',
            0x081EC585: 'Route117_EventScript_RematchDylan',
            0x081EC59C: 'Route117_EventScript_Maria',
            0x081EC5C8: 'Route117_EventScript_RegisterMaria',
            0x081EC5E7: 'Route117_EventScript_RematchMaria',
            0x081EC5FE: 'Route117_EventScript_Derek',
            0x081EC615: 'Route117_EventScript_Anna',
            0x081EC645: 'Route117_EventScript_RegisterAnna',
            0x081EC65E: 'Route117_EventScript_RematchAnna',
            0x081EC679: 'Route117_EventScript_Meg',
            0x081EC6A9: 'Route117_EventScript_RegisterMeg',
            0x081EC6C2: 'Route117_EventScript_RematchMeg',
            0x081EC6DD: 'Route117_EventScript_Melina',
            0x081EC6F4: 'Route117_EventScript_Brandi',
            0x081EC70B: 'Route117_EventScript_Aisha',
        },
        'texts': {
            0x081EC722: 'Route117_Text_DayCarePokemonHadNewMove',
            0x081EC769: 'Route117_Text_ArentTheseFlowersPretty',
            0x081EC78F: 'Route117_Text_AirIsTastyHere',
            0x081EC79A: 'Route117_Text_RouteSignVerdanturf',
            0x081EC7B3: 'Route117_Text_RouteSignMauville',
            0x081EC7CD: 'Route117_Text_DayCareSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route117']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x0086: 'FLAG_PENDING_DAYCARE_EGG'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {0x03: 'LOCALID_DAYCARE_MAN'},
            'trainers': {
                0x00E3: 'TRAINER_DEREK',
                0x011F: 'TRAINER_ANNA_AND_MEG_1',
                0x016C: 'TRAINER_DYLAN_1',
                0x0171: 'TRAINER_MARIA_1',
                0x021A: 'TRAINER_ISAAC_1',
                0x0221: 'TRAINER_LYDIA_1',
                0x02F3: 'TRAINER_MELINA',
                0x02F4: 'TRAINER_BRANDI',
                0x02F5: 'TRAINER_AISHA',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route118': {
        'scripts': {
            0x081EC7F9: 'Route118_OnTransition',
            0x081EC820: 'Route118_OnLoad',
            0x081EC841: 'Route118_EventScript_GoodRodFisherman',
            0x081EC86B: 'Route118_EventScript_ReceiveGoodRod',
            0x081EC88C: 'Route118_EventScript_DeclineGoodRod',
            0x081EC896: 'Route118_EventScript_ReceivedGoodRod',
            0x081EC8A0: 'Route118_EventScript_Girl',
            0x081EC8A9: 'Route118_EventScript_RouteSignMauville',
            0x081EC8B2: 'Route118_EventScript_RouteSign119',
            0x081EC8BB: 'Route118_EventScript_StevenTrigger0',
            0x081EC8DB: 'Route118_EventScript_StevenTrigger1',
            0x081EC8F1: 'Route118_EventScript_StevenTrigger2',
            0x081EC911: 'Route118_EventScript_StevenTrigger',
            0x081EC955: 'Route118_EventScript_StevenExit0',
            0x081EC967: 'Route118_EventScript_StevenExit1',
            0x081EC979: 'Route118_EventScript_StevenExit2',
            0x081EC9B4: 'Route118_EventScript_Rose',
            0x081EC9E0: 'Route118_EventScript_RegisterRose',
            0x081EC9FF: 'Route118_EventScript_RematchRose',
            0x081ECA16: 'Route118_EventScript_Barny',
            0x081ECA2D: 'Route118_EventScript_Wade',
            0x081ECA44: 'Route118_EventScript_Dalton',
            0x081ECA70: 'Route118_EventScript_RegisterDalton',
            0x081ECA8F: 'Route118_EventScript_RematchDalton',
            0x081ECAA6: 'Route118_EventScript_Perry',
            0x081ECABD: 'Route118_EventScript_Chester',
            0x081ECAD4: 'Route118_EventScript_Deandre',
        },
        'tables': {0x081EC837: 'Route118_OnFrame'},
        'texts': {
            0x081ECAEB: 'Route118_Text_StevenQuestions',
            0x081ECBD8: 'Route118_Text_YouAgreeGoodRodIsGood',
            0x081ECBFE: 'Route118_Text_IdenticalMindsTakeThis',
            0x081ECC21: 'Route118_Text_TryYourLuckFishing',
            0x081ECC40: 'Route118_Text_DontYouLikeToFish',
            0x081ECC4C: 'Route118_Text_TryCatchingMonWithGoodRod',
            0x081ECC68: 'Route118_Text_CanCrossRiversWithSurf',
            0x081ECCAF: 'Route118_Text_RouteSignMauville',
            0x081ECCC9: 'Route118_Text_RouteSign119',
        },
        # The matching US Steven scene identifies both FD placeholders.
        'field_placeholders': {
            0x081ECAEB: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route118']['labels'],
        'external_labels': {
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x00E3: 'FLAG_RECEIVED_GOOD_ROD'},
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x4071: 'VAR_ROUTE118_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0x7: 'ABNORMAL_WEATHER_ROUTE_118_EAST',
                    0x8: 'ABNORMAL_WEATHER_ROUTE_118_WEST',
                },
            },
            'local_ids': {
                0x13: 'LOCALID_ROUTE118_STEVEN',
                0xFF: 'LOCALID_PLAYER',
            },
            'items': {0x0107: 'ITEM_GOOD_ROD'},
            'sounds': {0x000A: 'SE_LEDGE'},
            'trainers': {
                0x0025: 'TRAINER_ROSE_1',
                0x00C4: 'TRAINER_DALTON_1',
                0x0157: 'TRAINER_BARNY',
                0x0158: 'TRAINER_WADE',
                0x018E: 'TRAINER_PERRY',
                0x0198: 'TRAINER_CHESTER',
                0x02CB: 'TRAINER_DEANDRE',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route119': {
        'scripts': {
            0x081ECCF0: 'Route119_OnResume',
            0x081ECCFA: 'Route119_EventScript_TryRemoveKecleon',
            0x081ECD0E: 'Route119_OnTransition',
            0x081ECD27: 'Route119_EventScript_MoveInstituteWorkersDownstairs',
            0x081ECD33: 'Route119_EventScript_RivalTrigger1',
            0x081ECD3E: 'Route119_EventScript_RivalTrigger2',
            0x081ECD49: 'Route119_EventScript_RivalEncounter',
            0x081ECDC2: 'Route119_EventScript_PlayMayMusic',
            0x081ECDC7: 'Route119_EventScript_PlayBrendanMusic',
            0x081ECDCC: 'Route119_EventScript_BattleMay',
            0x081ECDFB: 'Route119_EventScript_BattleMayTreecko',
            0x081ECE0B: 'Route119_EventScript_BattleMayTorchic',
            0x081ECE1B: 'Route119_EventScript_BattleMayMudkip',
            0x081ECE2B: 'Route119_EventScript_DefeatedMay',
            0x081ECE46: 'Route119_EventScript_BattleBrendan',
            0x081ECE75: 'Route119_EventScript_BattleBrendanTreecko',
            0x081ECE85: 'Route119_EventScript_BattleBrendanTorchic',
            0x081ECE95: 'Route119_EventScript_BattleBrendanMudkip',
            0x081ECEA5: 'Route119_EventScript_DefeatedBrendan',
            0x081ECEC0: 'Route119_EventScript_GiveFlyHM',
            0x081ECED0: 'Route119_EventScript_RivalExitScottArrive',
            0x081ECF61: 'Route119_EventScript_SetScottPos1',
            0x081ECF69: 'Route119_EventScript_SetScottPos2',
            0x081ECF71: 'Route119_EventScript_ScottExit1',
            0x081ECF7C: 'Route119_EventScript_ScottExit2',
            0x081ECF87: 'Route119_EventScript_RivalEnter1',
            0x081ECF92: 'Route119_EventScript_RivalEnter2',
            0x081ECF9D: 'Route119_EventScript_RivalExit1',
            0x081ECFAF: 'Route119_EventScript_RivalExit2',
            0x081ECFC1: 'Route119_EventScript_SetRivalPos1',
            0x081ECFD0: 'Route119_EventScript_SetRivalPos2',
            0x081ED02C: 'Route119_EventScript_CyclingTriathleteM',
            0x081ED035: 'Route119_EventScript_RouteSignFortree',
            0x081ED03E: 'Route119_EventScript_WeatherInstituteSign',
            0x081ED047: 'Route119_EventScript_Brent',
            0x081ED05E: 'Route119_EventScript_Donald',
            0x081ED075: 'Route119_EventScript_Taylor',
            0x081ED08C: 'Route119_EventScript_Doug',
            0x081ED0A3: 'Route119_EventScript_Greg',
            0x081ED0BA: 'Route119_EventScript_Kent',
            0x081ED0D1: 'Route119_EventScript_Jackson',
            0x081ED0FD: 'Route119_EventScript_RegisterJackson',
            0x081ED11C: 'Route119_EventScript_RematchJackson',
            0x081ED133: 'Route119_EventScript_Catherine',
            0x081ED15F: 'Route119_EventScript_RegisterCatherine',
            0x081ED17E: 'Route119_EventScript_RematchCatherine',
            0x081ED195: 'Route119_EventScript_Hugh',
            0x081ED1AC: 'Route119_EventScript_Phil',
            0x081ED1C3: 'Route119_EventScript_Yasu',
            0x081ED1DA: 'Route119_EventScript_Takashi',
            0x081ED1F1: 'Route119_EventScript_Hideo',
            0x081ED208: 'Route119_EventScript_Chris',
            0x081ED21F: 'Route119_EventScript_Fabian',
            0x081ED236: 'Route119_EventScript_Dayton',
            0x081ED24D: 'Route119_EventScript_Rachel',
            0x081ED264: 'Route119_EventScript_BridgeAquaGrunt1',
            0x081ED27B: 'Route119_EventScript_BridgeAquaGrunt2',
            0x081ED292: 'Route119_EventScript_Boy1',
            0x081ED29B: 'Route119_EventScript_Boy2',
            0x081ED2A4: 'Route119_EventScript_TrainerTipsDecoration',
            0x081ED2AD: 'Route119_EventScript_ScottWonAtFortreeGymCall',
        },
        'texts': {
            0x081ED2BE: 'Route119_Text_MayIntro',
            0x081ED318: 'Route119_Text_MayDefeat',
            0x081ED351: 'Route119_Text_MayPresentForYou',
            0x081ED387: 'Route119_Text_MayExplainFly',
            0x081ED441: 'Route119_Text_BrendanIntro',
            0x081ED485: 'Route119_Text_BrendanDefeat',
            0x081ED49C: 'Route119_Text_BrendanIllGiveYouThis',
            0x081ED4CF: 'Route119_Text_BrendanExplainFly',
            0x081ED524: 'Route119_Text_ScottWayToGoBeSeeingYou',
            0x081ED5EB: 'Route119_Text_ScottYouWonAtFortreeGym',
            0x081ED6B1: 'Route119_Text_StayAwayFromWeatherInstitute',
            0x081ED6EB: 'Route119_Text_DontGoNearWeatherInstitute',
            0x081ED724: 'Route119_Text_ThoughtFlyByCatchingBirdMons',
            0x081ED788: 'Route119_Text_TallGrassSnaresBikeTires',
            0x081ED7B3: 'Route119_Text_CanYourMonMakeSecretBase',
            0x081ED7E7: 'Route119_Text_RouteSignFortree',
            0x081ED801: 'Route119_Text_WeatherInstitute',
            0x081ED80F: 'Route119_Text_TrainerTipsDecoration',
        },
        # The paired US rival and Scott messages establish these field
        # placeholders without relying on raw FD indices.
        'field_placeholders': {
            0x081ED2BE: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081ED318: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081ED387: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081ED441: {0x01: 'PLAYER'},
            0x081ED524: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081ED5EB: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route119']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x006E: 'FLAG_RECEIVED_HM_FLY',
                0x008A: 'FLAG_SCOTT_CALL_FORTREE_GYM',
                0x037C: 'FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS',
                0x037D: 'FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS',
                0x08C1: 'FLAG_SYS_CTRL_OBJ_DELETE',
            },
            'vars': {
                0x4001: 'VAR_TEMP_1',
                0x4023: 'VAR_STARTER_MON',
                0x4072: 'VAR_ROUTE119_STATE',
                0x40B3: 'VAR_WEATHER_INSTITUTE_STATE',
                0x40D1: 'VAR_SCOTT_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'var_values': {
                0x800D: {0x7: 'B_OUTCOME_CAUGHT'},
            },
            'local_ids': {
                0x10: 'LOCALID_ROUTE119_RIVAL',
                0x19: 'LOCALID_ROUTE119_RIVAL_ON_BIKE',
                0x2B: 'LOCALID_ROUTE119_SCOTT',
                0xFF: 'LOCALID_PLAYER',
            },
            # The current JP constants still use the numeric HM identifiers;
            # ITEM_HM_FLY in newer US sources is ITEM_HM02 (340).
            'items': {0x0154: 'ITEM_HM02'},
            'songs': {
                0x0000: 'MUS_DUMMY',
                0x019F: 'MUS_ENCOUNTER_MAY',
                0x01A5: 'MUS_ENCOUNTER_BRENDAN',
            },
            'trainers': {
                0x00DF: 'TRAINER_BRENT',
                0x00E0: 'TRAINER_DONALD',
                0x00E1: 'TRAINER_TAYLOR',
                0x018F: 'TRAINER_HUGH',
                0x0190: 'TRAINER_PHIL',
                0x019F: 'TRAINER_YASU',
                0x01A0: 'TRAINER_TAKASHI',
                0x020A: 'TRAINER_BRENDAN_ROUTE_119_MUDKIP',
                0x020D: 'TRAINER_BRENDAN_ROUTE_119_TREECKO',
                0x0210: 'TRAINER_BRENDAN_ROUTE_119_TORCHIC',
                0x0213: 'TRAINER_MAY_ROUTE_119_MUDKIP',
                0x0216: 'TRAINER_MAY_ROUTE_119_TREECKO',
                0x0219: 'TRAINER_MAY_ROUTE_119_TORCHIC',
                0x0228: 'TRAINER_JACKSON_1',
                0x022F: 'TRAINER_CATHERINE_1',
                0x026A: 'TRAINER_DOUG',
                0x026B: 'TRAINER_GREG',
                0x026C: 'TRAINER_KENT',
                0x028B: 'TRAINER_HIDEO',
                0x02B5: 'TRAINER_CHRIS',
                0x02F7: 'TRAINER_FABIAN',
                0x02F8: 'TRAINER_DAYTON',
                0x02F9: 'TRAINER_RACHEL',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route120': {
        'scripts': {
            0x081ED874: 'Route120_OnResume',
            0x081ED87E: 'Route120_EventScript_RemoveKecleonObject',
            0x081ED8C1: 'Route120_EventScript_RemoveBridgeKecleon',
            0x081ED8D8: 'Route120_EventScript_RemoveKecleon',
            0x081ED8EC: 'Route120_OnLoad',
            0x081ED908: 'Route120_EventScript_CloseAncientTomb',
            0x081ED91B: 'Route120_EventScript_SetBridgeClearMetatiles',
            0x081ED940: 'Route120_EventScript_SetBridgeKecleonMovement',
            0x081ED945: 'Route120_OnTransition',
            0x081ED950: 'Route120_EventScript_SetWeather',
            0x081ED977: 'Route120_EventScript_SetCloudyWeather',
            0x081ED97B: 'Route120_EventScript_SetSunnyWeather',
            0x081ED97F: 'Route120_EventScript_TrySetRainyWeather',
            0x081ED99B: 'Route120_EventScript_SetRainyWeather',
            0x081ED99F: 'Route120_EventScript_BerryBeauty',
            0x081EDA42: 'Route120_EventScript_GiveFigyBerry',
            0x081EDA4D: 'Route120_EventScript_GiveWikiBerry',
            0x081EDA58: 'Route120_EventScript_GiveMagoBerry',
            0x081EDA63: 'Route120_EventScript_GiveAguavBerry',
            0x081EDA6E: 'Route120_EventScript_GiveIapapaBerry',
            0x081EDA79: 'Route120_EventScript_GiveBerry',
            0x081EDA9D: 'Route120_EventScript_ReceivedBerry',
            0x081EDAA7: 'Route120_EventScript_BerryLove',
            0x081EDAB0: 'Route120_EventScript_BerryNotLove',
            0x081EDAB9: 'Route120_EventScript_Steven',
            0x081EDADD: 'Route120_EventScript_StevenNotReady',
            0x081EDAEA: 'Route120_EventScript_StevenAskReadyForBattle',
            0x081EDB03: 'Route120_EventScript_StevenBattleKecleon',
            0x081EDB94: 'Route120_EventScript_RemoveBridgeKecleonPostBattle',
            0x081EDBA4: 'Route120_EventScript_StevenGiveDeconScope',
            0x081EDC1B: 'Route120_EventScript_PlayerApproachKecleonNorth',
            0x081EDC26: 'Route120_EventScript_PlayerApproachKecleonWest',
            0x081EDC34: 'Route120_EventScript_BridgeKecleon',
            0x081EDC3D: 'Route120_EventScript_RouteSignFortree',
            0x081EDC46: 'Route120_EventScript_RouteSign121',
            0x081EDC4F: 'Route120_EventScript_Colin',
            0x081EDC66: 'Route120_EventScript_Robert',
            0x081EDC92: 'Route120_EventScript_RegisterRobert',
            0x081EDCB1: 'Route120_EventScript_RematchRobert',
            0x081EDCC8: 'Route120_EventScript_Lorenzo',
            0x081EDCDF: 'Route120_EventScript_Jenna',
            0x081EDCF6: 'Route120_EventScript_Jeffrey',
            0x081EDD22: 'Route120_EventScript_RegisterJeffrey',
            0x081EDD41: 'Route120_EventScript_RematchJeffrey',
            0x081EDD58: 'Route120_EventScript_Jennifer',
            0x081EDD6F: 'Route120_EventScript_Chip',
            0x081EDD86: 'Route120_EventScript_Clarissa',
            0x081EDD9D: 'Route120_EventScript_Angelica',
            0x081EDDB4: 'Route120_EventScript_Keigo',
            0x081EDDCB: 'Route120_EventScript_Riley',
            0x081EDDE2: 'Route120_EventScript_Leonel',
            0x081EDDF9: 'Route120_EventScript_Callie',
        },
        'texts': {
            0x081EDE10: 'Route120_Text_StevenGreeting',
            0x081EDEA6: 'Route120_Text_StevenIllWaitHere',
            0x081EDECC: 'Route120_Text_StevenReadyForBattle',
            0x081EDEF4: 'Route120_Text_StevenShowMeYourPower',
            0x081EDF1B: 'Route120_Text_StevenUsedDevonScope',
            0x081EDF65: 'Route120_Text_StevenGiveDevonScope',
            0x081EDFE1: 'Route120_Text_StevenGoodbye',
            0x081EE029: 'Kecleon_Text_SomethingUnseeable',
            0x081EE039: 'Kecleon_Text_WantToUseDevonScope',
            0x081EE05A: 'Kecleon_Text_UseDevonScopeMonAttacked',
            0x081EE0A3: 'Route120_Text_RouteSignFortree',
            0x081EE0BD: 'Route120_Text_RouteSign121',
        },
        # The matching US Steven and Kecleon messages prove the field
        # placeholder meanings for these JP text objects.
        'field_placeholders': {
            0x081EDE10: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081EDECC: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081EDEF4: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081EDFE1: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081EE05A: {0x01: 'PLAYER'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route120']['labels'],
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x00E4: 'FLAG_REGI_DOORS_OPENED',
                0x011D: 'FLAG_RECEIVED_DEVON_SCOPE',
                0x0122: 'FLAG_NOT_READY_FOR_BATTLE_ROUTE_120',
                0x08C1: 'FLAG_SYS_CTRL_OBJ_DELETE',
                0x092E: 'FLAG_DAILY_ROUTE_120_RECEIVED_BERRY',
            },
            'vars': {
                0x4000: 'VAR_TEMP_0',
                0x4001: 'VAR_TEMP_1',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x8009: 'VAR_0x8009',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'var_values': {
                0x8004: {
                    0x008F: 'ITEM_FIGY_BERRY',
                    0x0090: 'ITEM_WIKI_BERRY',
                    0x0091: 'ITEM_MAGO_BERRY',
                    0x0092: 'ITEM_AGUAV_BERRY',
                    0x0093: 'ITEM_IAPAPA_BERRY',
                },
                0x800C: {
                    0x2: 'DIR_NORTH',
                    0x3: 'DIR_WEST',
                },
                0x800D: {
                    0x4: 'B_OUTCOME_RAN',
                    0x5: 'B_OUTCOME_PLAYER_TELEPORTED',
                    0x7: 'B_OUTCOME_CAUGHT',
                },
            },
            'local_ids': {
                0x1E: 'LOCALID_BRIDGE_KECLEON',
                0x1F: 'LOCALID_ROUTE120_STEVEN',
                0x24: 'LOCALID_BRIDGE_KECLEON_SHADOW',
                0xFF: 'LOCALID_PLAYER',
            },
            'items': {0x0120: 'ITEM_DEVON_SCOPE'},
            'weather': {
                0x1: 'WEATHER_SUNNY_CLOUDS',
                0x2: 'WEATHER_SUNNY',
                0x3: 'WEATHER_RAIN',
            },
            'metatiles': {
                0x007C: 'METATILE_General_RockWall_RockBase',
                0x0091: 'METATILE_General_RockWall_SandBase',
                0x00A1: 'METATILE_General_ReflectiveWater',
                0x0297: 'METATILE_Fortree_WoodBridge1_Top',
                0x029F: 'METATILE_Fortree_WoodBridge1_Bottom',
            },
            'movement_types': {0x0A: 'MOVEMENT_TYPE_FACE_RIGHT'},
            'field_effects': {0x1E: 'FLDEFF_NPCFLY_OUT'},
            'species': {0x013D: 'SPECIES_KECLEON'},
            'cry_modes': {0x2: 'CRY_MODE_ENCOUNTER'},
            'trainers': {
                0x002D: 'TRAINER_CHIP',
                0x005F: 'TRAINER_JENNIFER',
                0x00E2: 'TRAINER_JEFFREY_1',
                0x0195: 'TRAINER_COLIN',
                0x0196: 'TRAINER_ROBERT_1',
                0x01B3: 'TRAINER_CLARISSA',
                0x01B4: 'TRAINER_ANGELICA',
                0x0229: 'TRAINER_LORENZO',
                0x0230: 'TRAINER_JENNA',
                0x028C: 'TRAINER_KEIGO',
                0x028D: 'TRAINER_RILEY',
                0x02FA: 'TRAINER_LEONEL',
                0x02FB: 'TRAINER_CALLIE',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route121': {
        'scripts': {
            0x081EE0DA: 'Route121_EventScript_Woman',
            0x081EE0E3: 'Route121_EventScript_MtPyrePierSign',
            0x081EE0EC: 'Route121_EventScript_SafariZoneSign',
            0x081EE0F5: 'Route121_EventScript_AquaGruntsMoveOut',
            0x081EE151: 'Route121_EventScript_Vanessa',
            0x081EE168: 'Route121_EventScript_Walter',
            0x081EE194: 'Route121_EventScript_RegisterWalter',
            0x081EE1B3: 'Route121_EventScript_RematchWalter',
            0x081EE1CA: 'Route121_EventScript_Tammy',
            0x081EE1E1: 'Route121_EventScript_Kate',
            0x081EE1FC: 'Route121_EventScript_Joy',
            0x081EE217: 'Route121_EventScript_Jessica',
            0x081EE243: 'Route121_EventScript_RegisterJessica',
            0x081EE262: 'Route121_EventScript_RematchJessica',
            0x081EE279: 'Route121_EventScript_Cale',
            0x081EE290: 'Route121_EventScript_Myles',
            0x081EE2A7: 'Route121_EventScript_Pat',
            0x081EE2BE: 'Route121_EventScript_Marcel',
            0x081EE2D5: 'Route121_EventScript_Cristin',
            0x081EE301: 'Route121_EventScript_RegisterCristin',
            0x081EE320: 'Route121_EventScript_RematchCristin',
        },
        'texts': {
            0x081EE337: 'Route121_Text_OkayMoveOutToMtPyre',
            0x081EE34F: 'Route121_Text_AheadLoomsMtPyre',
            0x081EE388: 'Route121_Text_MtPyrePierSign',
            0x081EE3BA: 'Route121_Text_SafariZoneSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route121']['labels'],
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'vars': {
                0x4074: 'VAR_ROUTE121_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {
                0x0C: 'LOCALID_ROUTE121_GRUNT_1',
                0x0D: 'LOCALID_ROUTE121_GRUNT_2',
                0x0E: 'LOCALID_ROUTE121_GRUNT_3',
            },
            'songs': {0x01A3: 'MUS_ENCOUNTER_AQUA'},
            'trainers': {
                0x000B: 'TRAINER_MARCEL',
                0x006B: 'TRAINER_TAMMY',
                0x007F: 'TRAINER_JESSICA_1',
                0x00FE: 'TRAINER_WALTER_1',
                0x011E: 'TRAINER_KATE_AND_JOY',
                0x012C: 'TRAINER_VANESSA',
                0x02FC: 'TRAINER_CALE',
                0x02FD: 'TRAINER_MYLES',
                0x02FE: 'TRAINER_PAT',
                0x02FF: 'TRAINER_CRISTIN_1',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route123': {
        'scripts': {
            0x081EE3DC: 'Route123_OnTransition',
            0x081EE3E0: 'Route123_EventScript_GigaDrainGirl',
            0x081EE42D: 'Route123_EventScript_NoGrassMons',
            0x081EE42F: 'Route123_EventScript_ReceivedGigaDrain',
            0x081EE439: 'Route123_EventScript_RouteSign',
            0x081EE442: 'Route123_EventScript_RouteSignMtPyre',
            0x081EE44B: 'Route123_EventScript_BerryMastersHouseSign',
            0x081EE454: 'Route123_EventScript_Wendy',
            0x081EE46B: 'Route123_EventScript_Braxton',
            0x081EE482: 'Route123_EventScript_Violet',
            0x081EE499: 'Route123_EventScript_Cameron',
            0x081EE4C5: 'Route123_EventScript_RegisterCameron',
            0x081EE4E4: 'Route123_EventScript_RematchCameron',
            0x081EE4FB: 'Route123_EventScript_Jacki',
            0x081EE527: 'Route123_EventScript_RegisterJacki',
            0x081EE546: 'Route123_EventScript_RematchJacki',
            0x081EE55D: 'Route123_EventScript_Miu',
            0x081EE578: 'Route123_EventScript_Yuki',
            0x081EE593: 'Route123_EventScript_Kindra',
            0x081EE5AA: 'Route123_EventScript_Frederick',
            0x081EE5C1: 'Route123_EventScript_Alberto',
            0x081EE5D8: 'Route123_EventScript_Ed',
            0x081EE5EF: 'Route123_EventScript_Kayley',
            0x081EE606: 'Route123_EventScript_Jonas',
            0x081EE61D: 'Route123_EventScript_Jazmyn',
            0x081EE634: 'Route123_EventScript_Davis',
            0x081EE64B: 'Route123_EventScript_Fernando',
            0x081EE677: 'Route123_EventScript_RegisterFernando',
            0x081EE696: 'Route123_EventScript_RematchFernando',
        },
        'texts': {
            0x081EE6AD: 'Route123_Text_LoveGrassMonsHaveAny',
            0x081EE6E3: 'Route123_Text_YouLikeGrassMonsTooHaveThis',
            0x081EE722: 'Route123_Text_CheckTreesWithMyGrassMon',
            0x081EE753: 'Route123_Text_RouteSign',
            0x081EE76F: 'Route123_Text_RouteSignMtPyre',
            0x081EE790: 'Route123_Text_BerryMastersHouse',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route123']['labels'],
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x00E8: 'FLAG_RECEIVED_TM_GIGA_DRAIN'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'items': {0x0133: 'ITEM_TM19'},
            'trainers': {
                0x000C: 'TRAINER_ALBERTO',
                0x000D: 'TRAINER_ED',
                0x001D: 'TRAINER_FREDRICK',
                0x0027: 'TRAINER_VIOLET',
                0x004B: 'TRAINER_BRAXTON',
                0x005C: 'TRAINER_WENDY',
                0x006A: 'TRAINER_KINDRA',
                0x00C3: 'TRAINER_FERNANDO_1',
                0x00EE: 'TRAINER_CAMERON_1',
                0x00F9: 'TRAINER_JACKI_1',
                0x01E4: 'TRAINER_MIU_AND_YUKI',
                0x01F7: 'TRAINER_JAZMYN',
                0x01F8: 'TRAINER_JONAS',
                0x01F9: 'TRAINER_KAYLEY',
                0x021B: 'TRAINER_DAVIS',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route124': {
        'scripts': {
            0x081EE7A5: 'Route124_OnTransition',
            0x081EE7AF: 'Route124_EventScript_HuntersHouseSign',
            0x081EE7B8: 'Route124_EventScript_Spencer',
            0x081EE7CF: 'Route124_EventScript_Roland',
            0x081EE7E6: 'Route124_EventScript_Jenny',
            0x081EE812: 'Route124_EventScript_RegisterJenny',
            0x081EE831: 'Route124_EventScript_RematchJenny',
            0x081EE848: 'Route124_EventScript_Grace',
            0x081EE85F: 'Route124_EventScript_Chad',
            0x081EE876: 'Route124_EventScript_Lila',
            0x081EE8A6: 'Route124_EventScript_RegisterLila',
            0x081EE8BF: 'Route124_EventScript_RematchLila',
            0x081EE8DA: 'Route124_EventScript_Roy',
            0x081EE90A: 'Route124_EventScript_RegisterRoy',
            0x081EE923: 'Route124_EventScript_RematchRoy',
            0x081EE93E: 'Route124_EventScript_Declan',
            0x081EE955: 'Route124_EventScript_Isabella',
        },
        'texts': {
            0x081EE96C: 'Route124_Text_HuntersHouse',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route124']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'trainers': {
                0x000F: 'TRAINER_DECLAN',
                0x009F: 'TRAINER_SPENCER',
                0x00A0: 'TRAINER_ROLAND',
                0x00AE: 'TRAINER_CHAD',
                0x01C1: 'TRAINER_JENNY_1',
                0x01C2: 'TRAINER_GRACE',
                0x0253: 'TRAINER_ISABELLA',
                0x02AF: 'TRAINER_LILA_AND_ROY_1',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route125': {
        'scripts': {
            0x081EE98C: 'Route125_OnTransition',
            0x081EE9B7: 'Route125_OnLoad',
            0x081EE9D8: 'Route125_EventScript_Nolen',
            0x081EE9EF: 'Route125_EventScript_Stan',
            0x081EEA06: 'Route125_EventScript_Tanya',
            0x081EEA1D: 'Route125_EventScript_Sharon',
            0x081EEA34: 'Route125_EventScript_Ernest',
            0x081EEA60: 'Route125_EventScript_RegisterErnest',
            0x081EEA7F: 'Route125_EventScript_RematchErnest',
            0x081EEA96: 'Route125_EventScript_Kim',
            0x081EEAB1: 'Route125_EventScript_Iris',
            0x081EEACC: 'Route125_EventScript_Presley',
            0x081EEAE3: 'Route125_EventScript_Auron',
        },
        'tables': {0x081EE9CE: 'Route125_OnFrame'},
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route125']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
            0x082444AF: 'AbnormalWeather_EventScript_PlaceTilesRoute125West',
            0x0824451C: 'AbnormalWeather_EventScript_PlaceTilesRoute125East',
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244741: 'AbnormalWeather_StartKyogreWeather',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0xB: 'ABNORMAL_WEATHER_ROUTE_125_WEST',
                    0xC: 'ABNORMAL_WEATHER_ROUTE_125_EAST',
                },
            },
            'trainers': {
                0x00A1: 'TRAINER_NOLEN',
                0x00A2: 'TRAINER_STAN',
                0x01C3: 'TRAINER_TANYA',
                0x01C4: 'TRAINER_SHARON',
                0x01EC: 'TRAINER_ERNEST_1',
                0x02A6: 'TRAINER_KIM_AND_IRIS',
                0x0193: 'TRAINER_PRESLEY',
                0x01FA: 'TRAINER_AURON',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route126': {
        'scripts': {
            0x081EEB00: 'Route126_OnTransition',
            0x081EEB0A: 'Route126_EventScript_Barry',
            0x081EEB21: 'Route126_EventScript_Dean',
            0x081EEB38: 'Route126_EventScript_Nikki',
            0x081EEB4F: 'Route126_EventScript_Brenda',
            0x081EEB66: 'Route126_EventScript_Leonardo',
            0x081EEB7D: 'Route126_EventScript_Isobel',
            0x081EEB94: 'Route126_EventScript_Sienna',
            0x081EEBAB: 'Route126_EventScript_Pablo',
            0x081EEBD7: 'Route126_EventScript_RegisterPablo',
            0x081EEBF6: 'Route126_EventScript_RematchPablo',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route126']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'trainers': {
                0x00A3: 'TRAINER_BARRY',
                0x00A4: 'TRAINER_DEAN',
                0x01C5: 'TRAINER_NIKKI',
                0x01C6: 'TRAINER_BRENDA',
                0x0240: 'TRAINER_LEONARDO',
                0x017F: 'TRAINER_ISOBEL',
                0x01CB: 'TRAINER_SIENNA',
                0x0179: 'TRAINER_PABLO_1',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route127': {
        'scripts': {
            0x081EEC1D: 'Route127_OnTransition',
            0x081EEC48: 'Route127_OnLoad',
            0x081EEC69: 'Route127_EventScript_Camden',
            0x081EEC80: 'Route127_EventScript_Donny',
            0x081EEC97: 'Route127_EventScript_Jonah',
            0x081EECAE: 'Route127_EventScript_Henry',
            0x081EECC5: 'Route127_EventScript_Roger',
            0x081EECDC: 'Route127_EventScript_Aidan',
            0x081EECF3: 'Route127_EventScript_Athena',
            0x081EED0A: 'Route127_EventScript_Koji',
            0x081EED36: 'Route127_EventScript_RegisterKoji',
            0x081EED55: 'Route127_EventScript_RematchKoji',
        },
        'tables': {0x081EEC5F: 'Route127_OnFrame'},
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route127']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
            0x08244589: 'AbnormalWeather_EventScript_PlaceTilesRoute127North',
            0x082445F6: 'AbnormalWeather_EventScript_PlaceTilesRoute127South',
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244741: 'AbnormalWeather_StartKyogreWeather',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0xD: 'ABNORMAL_WEATHER_ROUTE_127_NORTH',
                    0xE: 'ABNORMAL_WEATHER_ROUTE_127_SOUTH',
                },
            },
            'trainers': {
                0x0176: 'TRAINER_CAMDEN',
                0x0180: 'TRAINER_DONNY',
                0x029B: 'TRAINER_JONAH',
                0x029C: 'TRAINER_HENRY',
                0x029D: 'TRAINER_ROGER',
                0x02A2: 'TRAINER_AIDAN',
                0x0241: 'TRAINER_ATHENA',
                0x02A0: 'TRAINER_KOJI_1',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route128': {
        'scripts': {
            0x081EED77: 'Route128_OnTransition',
            0x081EED8B: 'Route128_EventScript_KyogreAwakenedScene',
            0x081EEEF2: 'Route128_EventScript_Isaiah',
            0x081EEF1E: 'Route128_EventScript_RegisterIsaiah',
            0x081EEF3D: 'Route128_EventScript_RematchIsaiah',
            0x081EEF54: 'Route128_EventScript_Katelyn',
            0x081EEF80: 'Route128_EventScript_RegisterKatelyn',
            0x081EEF9F: 'Route128_EventScript_RematchKatelyn',
            0x081EEFB6: 'Route128_EventScript_Alexa',
            0x081EEFCD: 'Route128_EventScript_Ruben',
            0x081EEFE4: 'Route128_EventScript_Wayne',
            0x081EEFFB: 'Route128_EventScript_Harrison',
            0x081EF012: 'Route128_EventScript_Carlee',
        },
        'tables': {0x081EED81: 'Route128_OnFrame'},
        'texts': {
            0x081EF029: 'Route128_Text_ArchieWhatHappened',
            0x081EF059: 'Route128_Text_ArchieIOnlyWanted',
            0x081EF064: 'Route128_Text_MaxieDoYouUnderstandNow',
            0x081EF0C6: 'Route128_Text_MaxieResposibilityFallsToArchieAndMe',
            0x081EF171: 'Route128_Text_MaxieThisDefiesBelief',
            0x081EF1AB: 'Route128_Text_StevenWhatIsHappening',
            0x081EF1C1: 'Route128_Text_StevenWholeWorldWillDrown',
            0x081EF277: 'Route128_Text_StevenImGoingToSootopolis',
        },
        'field_placeholders': {
            0x081EF0C6: {0x01: 'PLAYER'},
            0x081EF1AB: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081EF277: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route128']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'specials': {'sub_080B3F60': 'PlayerFaceTrainerAfterBattle'},
        'symbols': {
            'flags': {
                0x088A: 'FLAG_SYS_WEATHER_CTRL',
                0x4000: 'FLAG_HIDE_MAP_NAME_POPUP',
            },
            'vars': {
                0x407B: 'VAR_ROUTE128_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {
                0x3: 'LOCALID_ROUTE128_STEVEN',
                0x4: 'LOCALID_ROUTE128_ARCHIE',
                0x5: 'LOCALID_ROUTE128_MAXIE',
                0xFF: 'LOCALID_PLAYER',
            },
            'field_effects': {0x1E: 'FLDEFF_NPCFLY_OUT'},
            'trainers': {
                0x0178: 'TRAINER_ISAIAH_1',
                0x0182: 'TRAINER_KATELYN_1',
                0x029E: 'TRAINER_ALEXA',
                0x029F: 'TRAINER_RUBEN',
                0x02A1: 'TRAINER_WAYNE',
                0x0242: 'TRAINER_HARRISON',
                0x01D0: 'TRAINER_CARLEE',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route129': {
        'scripts': {
            0x081EF2C4: 'Route129_OnLoad',
            0x081EF2DB: 'Route129_OnTransition',
            0x081EF308: 'Route129_EventScript_CheckSetAbnormalWeather',
            0x081EF31C: 'Route129_EventScript_Chase',
            0x081EF333: 'Route129_EventScript_Allison',
            0x081EF34A: 'Route129_EventScript_Reed',
            0x081EF361: 'Route129_EventScript_Tisha',
            0x081EF378: 'Route129_EventScript_Clarence',
        },
        'tables': {0x081EF312: 'Route129_OnFrame'},
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route129']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
            0x08244663: 'AbnormalWeather_EventScript_PlaceTilesRoute129West',
            0x082446D0: 'AbnormalWeather_EventScript_PlaceTilesRoute129East',
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244741: 'AbnormalWeather_StartKyogreWeather',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x405E: 'VAR_SOOTOPOLIS_CITY_STATE',
            },
            'var_values': {
                0x4037: {
                    0xF: 'ABNORMAL_WEATHER_ROUTE_129_WEST',
                    0x10: 'ABNORMAL_WEATHER_ROUTE_129_EAST',
                },
            },
            'trainers': {
                0x017A: 'TRAINER_CHASE',
                0x0183: 'TRAINER_ALLISON',
                0x02A3: 'TRAINER_REED',
                0x02A4: 'TRAINER_TISHA',
                0x0244: 'TRAINER_CLARENCE',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route130': {
        'scripts': {
            0x081EF395: 'Route130_OnTransition',
            0x081EF3E1: 'Route130_EventScript_SetMirageIslandLayout',
            0x081EF3E5: 'Route130_EventScript_CheckSetAbnormalWeather',
            0x081EF3EF: 'Route130_EventScript_Rodney',
            0x081EF406: 'Route130_EventScript_Katie',
            0x081EF41D: 'Route130_EventScript_Santiago',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route130']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
        },
        'symbols': {
            'flags': {
                0x0011: 'FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE',
                0x0012: 'FLAG_TEMP_12',
                0x0013: 'FLAG_TEMP_13',
                0x0014: 'FLAG_TEMP_14',
                0x0015: 'FLAG_TEMP_15',
                0x0016: 'FLAG_TEMP_16',
                0x0017: 'FLAG_TEMP_17',
                0x0018: 'FLAG_TEMP_18',
                0x0019: 'FLAG_TEMP_19',
                0x001A: 'FLAG_TEMP_1A',
                0x001B: 'FLAG_TEMP_1B',
                0x001C: 'FLAG_TEMP_1C',
                0x001D: 'FLAG_TEMP_1D',
                0x001E: 'FLAG_TEMP_1E',
                0x001F: 'FLAG_TEMP_1F',
                0x088A: 'FLAG_SYS_WEATHER_CTRL',
            },
            'vars': {
                0x405E: 'VAR_SOOTOPOLIS_CITY_STATE',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {0x800D: {0x1: 'TRUE'}},
            'layouts': {
                0x002E: 'LAYOUT_ROUTE130_MIRAGE_ISLAND',
                0x0107: 'LAYOUT_ROUTE130',
            },
            'trainers': {
                0x00A5: 'TRAINER_RODNEY',
                0x01C7: 'TRAINER_KATIE',
                0x00A8: 'TRAINER_SANTIAGO',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route131': {
        'scripts': {
            0x081EF43A: 'Route131_OnTransition',
            0x081EF44B: 'Route131_EventScript_SetLayout',
            0x081EF44F: 'Route131_EventScript_CheckSetAbnormalWeather',
            0x081EF459: 'Route131_EventScript_Richard',
            0x081EF470: 'Route131_EventScript_Herman',
            0x081EF487: 'Route131_EventScript_Susie',
            0x081EF49E: 'Route131_EventScript_Kara',
            0x081EF4B5: 'Route131_EventScript_Reli',
            0x081EF4D0: 'Route131_EventScript_Ian',
            0x081EF4EB: 'Route131_EventScript_Talia',
            0x081EF502: 'Route131_EventScript_Kevin',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route131']['labels'],
        'external_labels': {
            0x08243106: 'Common_EventScript_SetAbnormalWeather',
        },
        'symbols': {
            'flags': {0x088A: 'FLAG_SYS_WEATHER_CTRL'},
            'vars': {0x405E: 'VAR_SOOTOPOLIS_CITY_STATE'},
            'layouts': {0x013F: 'LAYOUT_ROUTE131_SKY_PILLAR'},
            'trainers': {
                0x00A6: 'TRAINER_RICHARD',
                0x00A7: 'TRAINER_HERMAN',
                0x01C8: 'TRAINER_SUSIE',
                0x01C9: 'TRAINER_KARA',
                0x02AE: 'TRAINER_RELI_AND_IAN',
                0x0181: 'TRAINER_TALIA',
                0x00AB: 'TRAINER_KEVIN',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    # Route102 is the Wally/tutorial and early-trainer map.  Its JP scripts,
    # object-event order, local text, and the first trainer-text block were
    # checked one-for-one against the US Route102 sources.
    'Route102': {
        'scripts': {
            0x081E6825: 'Route102_EventScript_LittleBoy',
            0x081E682E: 'Route102_EventScript_RouteSignOldale',
            0x081E6837: 'Route102_EventScript_RouteSignPetalburg',
            0x081E6840: 'Route102_EventScript_Boy',
            0x081E6849: 'Route102_EventScript_Calvin',
            0x081E688A: 'Route102_EventScript_CalvinRegisterMatchCallAfterBattle',
            0x081E689B: 'Route102_EventScript_CalvinRegisterMatchCall',
            0x081E68B4: 'Route102_EventScript_CalvinTryRegister',
            0x081E68C7: 'Route102_EventScript_CalvinRegister',
            0x081E68E0: 'Route102_EventScript_CalvinRematch',
            0x081E68F7: 'Route102_EventScript_Rick',
            0x081E690E: 'Route102_EventScript_Tiana',
            0x081E6925: 'Route102_EventScript_Allen',
        },
        'texts': {
            0x081E693C: 'Route102_Text_WatchMeCatchPokemon',
            0x081E6992: 'Route102_Text_WallyIDidIt',
            0x081E69B0: 'Route102_Text_LetsGoBack',
            0x081E69C7: 'Route102_Text_ImNotVeryTall',
            0x081E6A13: 'Route102_Text_CatchWholeBunchOfPokemon',
            0x081E6A27: 'Route102_Text_RouteSignOldale',
            0x081E6A40: 'Route102_Text_RouteSignPetalburg',
        },
        'external_texts': {
            0x08259517: 'Route102_Text_CalvinIntro',
            0x08259548: 'Route102_Text_CalvinDefeated',
            0x08259563: 'Route102_Text_CalvinPostBattle',
            0x08259583: 'Route102_Text_CalvinRegister',
            0x082595B1: 'Route102_Text_CalvinRegisterShort',
            0x082595D1: 'Route102_Text_CalvinRematchIntro',
            0x08259603: 'Route102_Text_CalvinRematchDefeated',
            0x08259619: 'Route102_Text_CalvinRematchPostBattle',
            0x0825963A: 'Route102_Text_AllenIntro',
            0x0825965C: 'Route102_Text_AllenDefeated',
            0x08259673: 'Route102_Text_AllenPostBattle',
            0x08259690: 'Route102_Text_RickIntro',
            0x082596B0: 'Route102_Text_RickDefeated',
            0x082596B9: 'Route102_Text_RickPostBattle',
            0x082596DA: 'Route102_Text_TianaIntro',
            0x08259710: 'Route102_Text_TianaDefeated',
            0x0825972E: 'Route102_Text_TianaPostBattle',
        },
        # FD 01 is context-sensitive.  These two field messages match the
        # US {PLAYER} fields exactly, so retain the proven semantic token.
        'field_placeholders': {
            0x081E693C: {0x01: 'PLAYER'},
            0x081E69B0: {0x01: 'PLAYER'},
        },
        'symbols': {
            'flags': {0x012F: 'FLAG_HAS_MATCH_CALL'},
            'trainers': {
                0x013E: 'TRAINER_CALVIN_1',
                0x0267: 'TRAINER_RICK',
                0x025B: 'TRAINER_TIANA',
                0x014D: 'TRAINER_ALLEN',
            },
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    # Route103 was checked against the US map source from its MapScripts table
    # through the rival scene, six local movements, eleven local texts, and
    # the contiguous Route103 trainer-text family in data/text/trainers.inc.
    'Route103': {
        'scripts': {
            0x081E6A64: 'Route103_OnTransition',
            0x081E6A6F: 'Route103_OnLoad',
            0x081E6A79: 'Route103_EventScript_OpenAlteringCave',
            0x081E6A8C: 'Route103_EventScript_Rival',
            0x081E6AA5: 'Route103_EventScript_RivalMay',
            0x081E6AFF: 'Route103_EventScript_RivalBrendan',
            0x081E6B59: 'Route103_EventScript_StartMayBattleTreecko',
            0x081E6B69: 'Route103_EventScript_StartMayBattleTorchic',
            0x081E6B79: 'Route103_EventScript_StartMayBattleMudkip',
            0x081E6B89: 'Route103_EventScript_StartBrendanBattleTreecko',
            0x081E6B99: 'Route103_EventScript_StartBrendanBattleTorchic',
            0x081E6BA9: 'Route103_EventScript_StartBrendanBattleMudkip',
            0x081E6BB9: 'Route103_EventScript_AfterMayBattle',
            0x081E6BC7: 'Route103_EventScript_AfterBrendanBattle',
            0x081E6BD5: 'Route103_EventScript_RivalExit',
            0x081E6C08: 'Route103_EventScript_RivalExitFacingNorth',
            0x081E6C2C: 'Route103_EventScript_RivalExitFacingEastOrWest',
            0x081E6C50: 'Route103_EventScript_RivalExitFacingSouth',
            0x081E6C6D: 'Route103_EventScript_RivalEnd',
            0x081E6CA4: 'Route103_EventScript_Boy',
            0x081E6CAD: 'Route103_EventScript_Man',
            0x081E6CB6: 'Route103_EventScript_RouteSign',
            0x081E6CBF: 'Route103_EventScript_Daisy',
            0x081E6CD6: 'Route103_EventScript_Amy',
            0x081E6D05: 'Route102_EventScript_AmyRegisterMatchCallAfterBattle',
            0x081E6D1E: 'Route102_EventScript_AmyRematch',
            0x081E6D39: 'Route103_EventScript_Liv',
            0x081E6D68: 'Route102_EventScript_LivRegisterMatchCallAfterBattle',
            0x081E6D81: 'Route102_EventScript_LivRematch',
            0x081E6D9C: 'Route103_EventScript_Andrew',
            0x081E6DB3: 'Route103_EventScript_Miguel',
            0x081E6DDF: 'Route102_EventScript_MiguelRegisterMatchCallAfterBattle',
            0x081E6DFE: 'Route103_EventScript_MiguelRematch',
            0x081E6E15: 'Route103_EventScript_Marcos',
            0x081E6E2C: 'Route103_EventScript_Rhett',
            0x081E6E43: 'Route103_EventScript_Pete',
            0x081E6E5A: 'Route103_EventScript_Isabelle',
        },
        'texts': {
            0x081E6E71: 'Route103_Text_MayRoute103Pokemon',
            0x081E6E97: 'Route103_Text_MayLetsBattle',
            0x081E6F03: 'Route103_Text_MayDefeated',
            0x081E6F20: 'Route103_Text_MayTimeToHeadBack',
            0x081E6FA8: 'Route103_Text_BrendanRoute103Pokemon',
            0x081E6FD0: 'Route103_Text_BrendanLetsBattle',
            0x081E702A: 'Route103_Text_BrendanDefeated',
            0x081E703A: 'Route103_Text_BrendanTimeToHeadBack',
            0x081E70B5: 'Route103_Text_ShouldHaveBroughtPotion',
            0x081E70DC: 'Route103_Text_ShortcutToOldale',
            0x081E7115: 'Route103_Text_RouteSign',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route103']['labels'],
        # These symbols are owned by existing common-script sources, not by
        # Route103. Their JP entry addresses and movement bytes were matched
        # one-for-one with the corresponding US common definitions.
        'external_labels': {
            0x08242F63: 'Common_EventScript_SetupRivalGfxId',
            0x08243139: 'ProfBirch_EventScript_UpdateLocation',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
        },
        # Each FD field control is mapped only where the corresponding US
        # field message proves the same PLAYER/KUN placeholder semantics.
        'field_placeholders': {
            0x081E6E97: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E6F03: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E6FD0: {0x01: 'PLAYER'},
            0x081E702A: {0x01: 'PLAYER'},
            0x081E703A: {0x01: 'PLAYER'},
        },
        'symbols': {
            'flags': {
                0x0082: 'FLAG_DEFEATED_RIVAL_ROUTE103',
                0x0379: 'FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL',
                0x03D3: 'FLAG_HIDE_OLDALE_TOWN_RIVAL',
                0x0864: 'FLAG_SYS_GAME_CLEAR',
            },
            'trainers': {
                0x0024: 'TRAINER_DAISY',
                0x0125: 'TRAINER_MIGUEL_1',
                0x0150: 'TRAINER_ANDREW',
                0x01E1: 'TRAINER_AMY_AND_LIV_1',
                0x0208: 'TRAINER_BRENDAN_ROUTE_103_MUDKIP',
                0x020B: 'TRAINER_BRENDAN_ROUTE_103_TREECKO',
                0x020E: 'TRAINER_BRENDAN_ROUTE_103_TORCHIC',
                0x0211: 'TRAINER_MAY_ROUTE_103_MUDKIP',
                0x0214: 'TRAINER_MAY_ROUTE_103_TREECKO',
                0x0217: 'TRAINER_MAY_ROUTE_103_TORCHIC',
                0x02BE: 'TRAINER_MARCOS',
                0x02BF: 'TRAINER_RHETT',
                0x02DF: 'TRAINER_PETE',
                0x02E0: 'TRAINER_ISABELLE',
            },
            'vars': {
                0x4023: 'VAR_STARTER_MON',
                0x4084: 'VAR_BIRCH_LAB_STATE',
                0x40C7: 'VAR_OLDALE_RIVAL_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'songs': {
                0x0000: 'MUS_DUMMY',
                0x019F: 'MUS_ENCOUNTER_MAY',
                0x01A5: 'MUS_ENCOUNTER_BRENDAN',
            },
            'sounds': {0x000A: 'SE_LEDGE'},
            'metatiles': {
                0x009F: 'METATILE_General_CaveEntrance_Top',
                0x00A7: 'METATILE_General_CaveEntrance_Bottom',
            },
            'local_ids': {
                0x02: 'LOCALID_ROUTE103_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
        },
    },
    # Route104 has matching map-event counts and a one-for-one US script,
    # movement, text, and trainer-text control-flow audit.  Its four text
    # objects in adjacent physical map ranges remain explicit external
    # owners; the labels still follow the US Route104/Dewford names.
    'Route104': {
        'scripts': {
            0x081E7143: 'Route104_EventScript_StartSailToDewford',
            0x081E714A: 'Route104_OnTransition',
            0x081E715A: 'Route104_EventScript_ShowOrHideWhiteHerbFlorist',
            0x081E7170: 'Route104_EventScript_HideWhiteHerbFlorist',
            0x081E7174: 'Route104_EventScript_TrySetRivalPos',
            0x081E7199: 'Route104_EventScript_DontSetRivalPos',
            0x081E719A: 'Route104_EventScript_Rival',
            0x081E71AF: 'Route104_EventScript_RivalTrigger',
            0x081E720D: 'Route104_EventScript_PlayRivalMusic',
            0x081E7225: 'Route104_EventScript_PlayMayMusic',
            0x081E722A: 'Route104_EventScript_PlayBrendanMusic',
            0x081E722F: 'Route104_EventScript_RivalEncounter',
            0x081E7247: 'Route104_EventScript_MayEncounter',
            0x081E72CC: 'Route104_EventScript_MayAskToBattle',
            0x081E72E9: 'Route104_EventScript_BattleMay',
            0x081E7318: 'Route104_EventScript_MayDefeated',
            0x081E732D: 'Route104_EventScript_RestoreMusic',
            0x081E7332: 'Route104_EventScript_BattleMayTreecko',
            0x081E7345: 'Route104_EventScript_BattleMayTorchic',
            0x081E7358: 'Route104_EventScript_BattleMayMudkip',
            0x081E736B: 'Route104_EventScript_BrendanEncounter',
            0x081E73E8: 'Route104_EventScript_BrendanAskToBattle',
            0x081E7405: 'Route104_EventScript_BattleBrendan',
            0x081E7434: 'Route104_EventScript_BrendanDefeated',
            0x081E7449: 'Route104_EventScript_BattleBrendanTreecko',
            0x081E745C: 'Route104_EventScript_BattleBrendanTorchic',
            0x081E746F: 'Route104_EventScript_BattleBrendanMudkip',
            0x081E7488: 'Route104_EventScript_ExpertF',
            0x081E74BF: 'Route104_EventScript_ReceivedBerry',
            0x081E74C9: 'Route104_EventScript_WhiteHerbFlorist',
            0x081E74F8: 'Route104_EventScript_ReceivedWhiteHerb',
            0x081E7502: 'Route104_EventScript_Girl1',
            0x081E750B: 'Route104_EventScript_BugCatcher',
            0x081E7514: 'Route104_EventScript_BrineysCottageSign',
            0x081E751D: 'Route104_EventScript_RouteSignPetalburg',
            0x081E7526: 'Route104_EventScript_RouteSignRustboro',
            0x081E752F: 'Route104_EventScript_FlowerShopSign',
            0x081E7538: 'Route104_EventScript_TrainerTipsDoubleBattles',
            0x081E7541: 'Route104_EventScript_Boy1',
            0x081E754A: 'Route104_EventScript_Woman',
            0x081E7553: 'Route104_EventScript_Boy2',
            0x081E7582: 'Route104_EventScript_ReceivedBulletSeed',
            0x081E758C: 'Route104_EventScript_Girl2',
            0x081E7595: 'Route104_EventScript_SailToDewford',
            0x081E75D5: 'Route104_EventScript_SailToDewfordNoCall',
            0x081E75EB: 'Route104_EventScript_SailToDewfordDadCalls',
            0x081E7635: 'Route104_EventScript_ArriveInDewford',
            0x081E76B0: 'Route104_EventScript_DeliverLetterReminder',
            0x081E76BA: 'Route104_EventScript_LandedInDewford',
            0x081E785B: 'Route104_EventScript_Ivan',
            0x081E7872: 'Route104_EventScript_Billy',
            0x081E7889: 'Route104_EventScript_Haley',
            0x081E78CA: 'Route104_EventScript_TryRegisterHaleyAfterBattle',
            0x081E78DB: 'Route104_EventScript_RegisterHaleyAfterBattle',
            0x081E78F4: 'Route104_EventScript_TryRegisterHaley',
            0x081E7907: 'Route104_EventScript_RegisterHaley',
            0x081E7920: 'Route104_EventScript_RematchHaley',
            0x081E7937: 'Route104_EventScript_Winston',
            0x081E7978: 'Route104_EventScript_TryRegisterWinstonAfterBattle',
            0x081E7989: 'Route104_EventScript_RegisterWinstonAfterBattle',
            0x081E79A2: 'Route104_EventScript_TryRegisterWinston',
            0x081E79B5: 'Route104_EventScript_RegisterWinston',
            0x081E79CE: 'Route104_EventScript_RematchWinston',
            0x081E79E5: 'Route104_EventScript_Cindy',
            0x081E7A26: 'Route104_EventScript_TryRegisterCindyAfterBattle',
            0x081E7A37: 'Route104_EventScript_RegisterCindyAfterBattle',
            0x081E7A50: 'Route104_EventScript_TryRegisterCindy',
            0x081E7A63: 'Route104_EventScript_RegisterCindy',
            0x081E7A7C: 'Route104_EventScript_RematchCindy',
            0x081E7A93: 'Route104_EventScript_Gina',
            0x081E7AB2: 'Route104_EventScript_Mia',
            0x081E7AD1: 'Route104_EventScript_Darian',
        },
        'tables': {0x081E7139: 'Route104_OnFrame'},
        'texts': {
            0x081E7AE8: 'Route104_Text_BrineyLivesInSeasideCottage',
            0x081E7B35: 'Route104_Text_WhatsItLikeAtBottomOfSea',
            0x081E7B5C: 'Route104_Text_ThrowBallAtWeakenedPokemon',
            0x081E7B96: 'Route104_Text_OnlyThrowBallAtWildPokemon',
            0x081E7BCB: 'Route104_Text_ImNotATrainer',
            0x081E7C2A: 'Route104_Text_LikeFillingMouthWithSeedsTakeThis',
            0x081E7C88: 'Route104_Text_TMsAreOneTimeUse',
            0x081E7CC1: 'Route104_Text_DontNeedThisTakeIt',
            0x081E7D17: 'Route104_Text_FlowerShopSellingSaplings',
            0x081E7D58: 'Route104_Text_MrBrineysCottage',
            0x081E7D65: 'Route104_Text_RouteSignPetalburg',
            0x081E7D7E: 'Route104_Text_RouteSignRustboro',
            0x081E7D98: 'Route104_Text_PrettyPetalFlowShop',
            0x081E7DAA: 'Route104_Text_TrainerTipsDoubleBattles',
            0x081E7E3B: 'Route104_Text_MayWeShouldRegister',
            0x081E7E9E: 'Route104_Text_RegisteredMay',
            0x081E7EB6: 'Route104_Text_MayHowsYourPokedex',
            0x081E7ED8: 'Route104_Text_MayMinesDecentLetsBattle',
            0x081E7EFD: 'Route104_Text_MayHaventRaisedPokemon',
            0x081E7F41: 'Route104_Text_MayLetsBattle',
            0x081E7F62: 'Route104_Text_MayIntro',
            0x081E7F84: 'Route104_Text_MayDefeat',
            0x081E7F9B: 'Route104_Text_MayPostBattle',
            0x081E8001: 'Route104_Text_BrendanWeShouldRegister',
            0x081E805F: 'Route104_Text_RegisteredBrendan',
            0x081E8077: 'Route104_Text_BrendanHowsYourPokedex',
            0x081E80A2: 'Route104_Text_BrendanDoingGreatLetsBattle',
            0x081E80CD: 'Route104_Text_BrendanNoConfidence',
            0x081E80EC: 'Route104_Text_BrendanLetsBattle',
            0x081E8109: 'Route104_Text_BrendanIntro',
            0x081E812B: 'Route104_Text_BrendanDefeat',
            0x081E813D: 'Route104_Text_BrendanPostBattle',
        },
        'external_texts': {
            **VERIFIED_SHARED_TEXT_BLOCKS['Route104']['labels'],
            0x081E5191: 'Route104_Text_LandedInDewfordDeliverLetter',
            0x081E522C: 'DewfordTown_Text_BrineyLandedInDewford',
            0x081E82F9: 'Route104_Text_DadPokenavCall',
            0x081E83B3: 'Route104_Text_RegisteredDadInPokenav',
        },
        'external_labels': {
            0x081DEE0A: 'RustboroCity_EventScript_PlayRivalMusic',
            0x08242F63: 'Common_EventScript_SetupRivalGfxId',
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x0824312C: 'Common_EventScript_PlayBrineysBoatMusic',
            0x08243134: 'Common_EventScript_StopBrineysBoatMusic',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
        },
        'field_placeholders': {
            0x081E7E3B: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E7E9E: {0x01: 'PLAYER'},
            0x081E7EB6: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E7F62: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081E8001: {0x01: 'PLAYER'},
            0x081E805F: {0x01: 'PLAYER'},
            0x081E8077: {0x01: 'PLAYER'},
        },
        'symbols': {
            'flags': {
                0x007C: 'FLAG_REGISTER_RIVAL_POKENAV',
                0x007D: 'FLAG_DEFEATED_RIVAL_ROUTE_104',
                0x007F: 'FLAG_MET_PRETTY_PETAL_SHOP_OWNER',
                0x00BD: 'FLAG_DELIVERED_STEVEN_LETTER',
                0x00F6: 'FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104',
                0x00FD: 'FLAG_ENABLE_RIVAL_MATCH_CALL',
                0x0106: 'FLAG_RECEIVED_TM_BULLET_SEED',
                0x0117: 'FLAG_RECEIVED_WHITE_HERB',
                0x0120: 'FLAG_MET_RIVAL_RUSTBORO',
                0x0132: 'FLAG_ENABLE_NORMAN_MATCH_CALL',
                0x02CF: 'FLAG_HIDE_ROUTE_104_RIVAL',
                0x02E4: 'FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN',
                0x02E6: 'FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT',
                0x02E7: 'FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN',
                0x032E: 'FLAG_HIDE_RUSTBORO_CITY_RIVAL',
                0x038A: 'FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST',
                0x0869: 'FLAG_BADGE03_GET',
            },
            'trainers': {
                0x0072: 'TRAINER_CINDY_1',
                0x0088: 'TRAINER_WINSTON_1',
                0x013F: 'TRAINER_BILLY',
                0x0151: 'TRAINER_IVAN',
                0x01E3: 'TRAINER_GINA_AND_MIA_1',
                0x0250: 'TRAINER_BRENDAN_RUSTBORO_TREECKO',
                0x0251: 'TRAINER_BRENDAN_RUSTBORO_MUDKIP',
                0x0257: 'TRAINER_BRENDAN_RUSTBORO_TORCHIC',
                0x0258: 'TRAINER_MAY_RUSTBORO_MUDKIP',
                0x025C: 'TRAINER_HALEY_1',
                0x02B8: 'TRAINER_DARIAN',
                0x0300: 'TRAINER_MAY_RUSTBORO_TREECKO',
                0x0301: 'TRAINER_MAY_RUSTBORO_TORCHIC',
            },
            'items': {
                0x0086: 'ITEM_CHESTO_BERRY',
                0x00B4: 'ITEM_WHITE_HERB',
                0x0129: 'ITEM_TM09',
            },
            'vars': {
                0x4023: 'VAR_STARTER_MON',
                0x405A: 'VAR_RUSTBORO_CITY_STATE',
                0x4063: 'VAR_ROUTE104_STATE',
                0x408E: 'VAR_BOARD_BRINEY_BOAT_STATE',
                0x4096: 'VAR_BRINEY_LOCATION',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'songs': {
                0x0000: 'MUS_DUMMY',
                0x019F: 'MUS_ENCOUNTER_MAY',
                0x01A5: 'MUS_ENCOUNTER_BRENDAN',
                0x01CC: 'MUS_REGISTER_MATCH_CALL',
            },
            'sounds': {0x0015: 'SE_PIN'},
            'maps': {
                0x000B: 'MAP_DEWFORD_TOWN',
                0x0013: 'MAP_ROUTE104',
            },
            'local_ids': {
                0x02: 'LOCALID_DEWFORD_BRINEY',
                0x04: 'LOCALID_DEWFORD_BOAT',
                0x07: 'LOCALID_ROUTE104_BOAT',
                0x08: 'LOCALID_ROUTE104_BRINEY',
                0x22: 'LOCALID_ROUTE104_RIVAL',
                0xFF: 'LOCALID_PLAYER',
            },
        },
    },
    # Route105 is a closed trainer-map range.  The map-events count, script
    # entry order, all trainerbattle operands and the contiguous trainer-text
    # family match the US Route105 sources one-for-one.
    'Route105': {
        'scripts': {
            0x081E81AE: 'Route105_OnLoad',
            0x081E81CE: 'Route105_CloseRegiEntrance',
            0x081E81E1: 'Route105_OnTransition',
            0x081E820D: 'Route105_EventScript_Foster',
            0x081E8224: 'Route105_EventScript_Luis',
            0x081E823B: 'Route105_EventScript_Dominik',
            0x081E8252: 'Route105_EventScript_Beverly',
            0x081E8269: 'Route105_EventScript_Imani',
            0x081E8280: 'Route105_EventScript_Josue',
            0x081E8297: 'Route105_EventScript_Andres',
            0x081E82C3: 'Route105_EventScript_AndresRegisterMatchCallAfterBattle',
            0x081E82E2: 'Route105_EventScript_AndresRematch',
        },
        'tables': {0x081E8203: 'Route105_OnFrame'},
        # These two messages are physically owned by Route105's ROM region,
        # but their callers and US names belong to Route104.
        'texts': {
            0x081E82F9: 'Route104_Text_DadPokenavCall',
            0x081E83B3: 'Route104_Text_RegisteredDadInPokenav',
        },
        'field_placeholders': {0x081E82F9: {0x01: 'PLAYER'}},
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route105']['labels'],
        'external_labels': {
            0x082443D5: 'AbnormalWeather_EventScript_PlaceTilesRoute105North',
            0x08244442: 'AbnormalWeather_EventScript_PlaceTilesRoute105South',
            0x0824473D: 'AbnormalWeather_EventScript_HideMapNamePopup',
            0x08244741: 'AbnormalWeather_StartKyogreWeather',
            0x08244749: 'AbnormalWeather_EventScript_EndEventAndCleanup_1',
        },
        'symbols': {
            'flags': {0x00E4: 'FLAG_REGI_DOORS_OPENED'},
            'trainers': {
                0x002E: 'TRAINER_FOSTER',
                0x0097: 'TRAINER_LUIS',
                0x0098: 'TRAINER_DOMINIK',
                0x01B9: 'TRAINER_BEVERLY',
                0x01BA: 'TRAINER_IMANI',
                0x02E1: 'TRAINER_ANDRES_1',
                0x02E2: 'TRAINER_JOSUE',
            },
            'vars': {
                0x4037: 'VAR_ABNORMAL_WEATHER_LOCATION',
                0x4039: 'VAR_SHOULD_END_ABNORMAL_WEATHER',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x4037: {
                    0x09: 'ABNORMAL_WEATHER_ROUTE_105_NORTH',
                    0x0A: 'ABNORMAL_WEATHER_ROUTE_105_SOUTH',
                },
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'metatiles': {
                0x007C: 'METATILE_General_RockWall_RockBase',
                0x0091: 'METATILE_General_RockWall_SandBase',
            },
        },
    },
    # These two routes are a compact, contiguous trainer-only tail.  The
    # event order and each trainer ID are identical to the US map sources;
    # their battle text remains in the existing shared text owner.
    'Route132': {
        'scripts': {
            0x081EF51A: 'Route132_EventScript_Gilbert',
            0x081EF531: 'Route132_EventScript_Dana',
            0x081EF548: 'Route132_EventScript_Ronald',
            0x081EF55F: 'Route132_EventScript_Kiyo',
            0x081EF576: 'Route132_EventScript_Paxton',
            0x081EF58D: 'Route132_EventScript_Darcy',
            0x081EF5A4: 'Route132_EventScript_Jonathan',
            0x081EF5BB: 'Route132_EventScript_Makayla',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route132']['labels'],
        'external_labels': {
            0x08256DB0: 'Route132_EventScript_ItemRareCandy',
            0x08256DBD: 'Route132_EventScript_ItemProtein',
        },
        'symbols': {
            'trainers': {
                0x00A9: 'TRAINER_GILBERT',
                0x01CA: 'TRAINER_DANA',
                0x015E: 'TRAINER_RONALD',
                0x00B5: 'TRAINER_KIYO',
                0x0252: 'TRAINER_PAXTON',
                0x02DD: 'TRAINER_DARCY',
                0x0256: 'TRAINER_JONATHAN',
                0x02F6: 'TRAINER_MAKAYLA',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route133': {
        'scripts': {
            0x081EF5D3: 'Route133_EventScript_Franklin',
            0x081EF5EA: 'Route133_EventScript_Debra',
            0x081EF601: 'Route133_EventScript_Linda',
            0x081EF618: 'Route133_EventScript_Warren',
            0x081EF62F: 'Route133_EventScript_Beck',
            0x081EF646: 'Route133_EventScript_Mollie',
            0x081EF65D: 'Route133_EventScript_Conor',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route133']['labels'],
        'external_labels': {
            0x08256DCA: 'Route133_EventScript_ItemBigPearl',
            0x08256DD7: 'Route133_EventScript_ItemStarPiece',
            0x08256DE4: 'Route133_EventScript_ItemMaxRevive',
        },
        'symbols': {
            'trainers': {
                0x00AA: 'TRAINER_FRANKLIN',
                0x01CC: 'TRAINER_DEBRA',
                0x01CD: 'TRAINER_LINDA',
                0x0058: 'TRAINER_WARREN',
                0x019E: 'TRAINER_BECK',
                0x0089: 'TRAINER_MOLLIE',
                0x01FF: 'TRAINER_CONOR',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    'Route134': {
        'scripts': {
            0x081EF67A: 'Route134_OnResume',
            0x081EF683: 'Route134_EventScript_Jack',
            0x081EF69A: 'Route134_EventScript_Laurel',
            0x081EF6B1: 'Route134_EventScript_Alex',
            0x081EF6C8: 'Route134_EventScript_Aaron',
            0x081EF6DF: 'Route134_EventScript_Hitoshi',
            0x081EF6F6: 'Route134_EventScript_Hudson',
            0x081EF70D: 'Route134_EventScript_Reyna',
            0x081EF724: 'Route134_EventScript_Marley',
            0x081EF73B: 'Route134_EventScript_Kelvin',
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS['Route134']['labels'],
        'external_labels': {
            0x08256DF1: 'Route134_EventScript_ItemCarbos',
            0x08256DFE: 'Route134_EventScript_ItemStarPiece',
        },
        'symbols': {
            'trainers': {
                0x00AC: 'TRAINER_JACK',
                0x01CF: 'TRAINER_LAUREL',
                0x019D: 'TRAINER_ALEX',
                0x018D: 'TRAINER_AARON',
                0x00B4: 'TRAINER_HITOSHI',
                0x01FE: 'TRAINER_HUDSON',
                0x01FD: 'TRAINER_REYNA',
                0x01FC: 'TRAINER_MARLEY',
                0x01FB: 'TRAINER_KELVIN',
            },
            'maps': {0x1845: 'MAP_UNDERWATER_ROUTE134'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
    # Petalburg Gym's JP layout follows the US script graph in address order.
    # Two unreferenced records (the unused movement at 0x081F8D6F and the
    # unused locked-door text at 0x081FA342) are listed separately below so
    # the emitter can retain every map-owned byte without a raw gap.
    'PetalburgCity_Gym': {
        'scripts': {
            0x081F8535: 'PetalburgCity_Gym_OnLoad',
            0x081F854C: 'PetalburgCity_Gym_EventScript_OpenUnlockedDoors',
            0x081F8596: 'PetalburgCity_Gym_EventScript_UnlockAllDoors',
            0x081F85C4: 'PetalburgCity_Gym_OnTransition',
            0x081F85E4: 'PetalburgCity_Gym_EventScript_MoveWallyToEntrance',
            0x081F85EC: 'PetalburgCity_Gym_EventScript_MoveNormanToEntrance',
            0x081F85F4: 'PetalburgCity_Gym_EventScript_CheckNormanForRematch',
            0x081F861C: 'PetalburgCity_Gym_EventScript_DontMoveNormanToFront',
            0x081F862C: 'PetalburgCity_Gym_EventScript_TurnPlayerNorth',
            0x081F863B: 'PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial',
            0x081F8688: 'PetalburgCity_Gym_EventScript_Norman',
            0x081F8717: 'PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth',
            0x081F8722: 'PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth',
            0x081F872D: 'PetalburgCity_Gym_EventScript_BeginWallyTutorialWest',
            0x081F8738: 'PetalburgCity_Gym_EventScript_BeginWallyTutorialEast',
            0x081F8743: 'PetalburgCity_Gym_EventScript_BeginWallyTutorial',
            0x081F88C8: 'PetalburgCity_Gym_EventScript_WallyArriveSouth',
            0x081F88DA: 'PetalburgCity_Gym_EventScript_WallyArriveNorth',
            0x081F88F6: 'PetalburgCity_Gym_EventScript_WallyArriveWestEast',
            0x081F890F: 'PetalburgCity_Gym_EventScript_ExitGymWithWallySouth',
            0x081F8928: 'PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth',
            0x081F893A: 'PetalburgCity_Gym_EventScript_ExitGymWithWallyWest',
            0x081F894C: 'PetalburgCity_Gym_EventScript_ExitGymWithWallyEast',
            0x081F895E: 'PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth',
            0x081F8969: 'PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth',
            0x081F897B: 'PetalburgCity_Gym_EventScript_NormanAddressPlayerWest',
            0x081F898D: 'PetalburgCity_Gym_EventScript_NormanAddressPlayerEast',
            0x081F899F: 'PetalburgCity_Gym_EventScript_NormanAddressWallySouth',
            0x081F89AA: 'PetalburgCity_Gym_EventScript_NormanAddressWallyNorth',
            0x081F89B5: 'PetalburgCity_Gym_EventScript_NormanAddressWallyWest',
            0x081F89C0: 'PetalburgCity_Gym_EventScript_NormanAddressWallyEast',
            0x081F89CB: 'PetalburgCity_Gym_EventScript_WallyFacePlayer',
            0x081F89D6: 'PetalburgCity_Gym_EventScript_WallyFaceDown',
            0x081F89E1: 'PetalburgCity_Gym_EventScript_NormanNoBadges',
            0x081F89EB: 'PetalburgCity_Gym_EventScript_NormanOneBadge',
            0x081F89F5: 'PetalburgCity_Gym_EventScript_NormanTwoBadges',
            0x081F89FF: 'PetalburgCity_Gym_EventScript_NormanThreeBadges',
            0x081F8A09: 'PetalburgCity_Gym_EventScript_NormanFaceDoorSouth',
            0x081F8A0A: 'PetalburgCity_Gym_EventScript_NormanFaceDoorNorth',
            0x081F8A15: 'PetalburgCity_Gym_EventScript_NormanFaceDoorWest',
            0x081F8A16: 'PetalburgCity_Gym_EventScript_NormanFaceDoorEast',
            0x081F8A17: 'PetalburgCity_Gym_EventScript_NormanPostBattle',
            0x081F8A43: 'PetalburgCity_Gym_EventScript_GiveFacade2',
            0x081F8A4A: 'PetalburgCity_Gym_EventScript_NormanRematch',
            0x081F8A65: 'PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry',
            0x081F8AAE: 'PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry',
            0x081F8AB4: 'PetalburgCity_Gym_EventScript_GiveEnigmaBerry',
            0x081F8AD2: 'PetalburgCity_Gym_EventScript_NormanBattle',
            0x081F8B69: 'PetalburgCity_Gym_EventScript_GiveFacade',
            0x081F8B8C: 'PetalburgCity_Gym_EventScript_WallysDadArrivesNorth',
            0x081F8B96: 'PetalburgCity_Gym_EventScript_WallysDadArrivesEast',
            0x081F8BA0: 'PetalburgCity_Gym_EventScript_WallysDadArrivesWest',
            0x081F8BAA: 'PetalburgCity_Gym_EventScript_WallysDadArrives',
            0x081F8C63: 'PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth',
            0x081F8C6E: 'PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast',
            0x081F8C79: 'PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest',
            0x081F8C84: 'PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth',
            0x081F8CA0: 'PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast',
            0x081F8CBC: 'PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest',
            0x081F8CD8: 'PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth',
            0x081F8CF1: 'PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast',
            0x081F8D03: 'PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest',
            0x081F8DC4: 'PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough',
            0x081F8DCE: 'PetalburgCity_Gym_EventScript_SpeedRoomDoor',
            0x081F8E03: 'PetalburgCity_Gym_EventScript_EnterRoom',
            0x081F8E12: 'PetalburgCity_Gym_EventScript_DontEnterRoom',
            0x081F8E14: 'PetalburgCity_Gym_EventScript_DoorLocked',
            0x081F8E1E: 'PetalburgCity_Gym_EventScript_AccuracyRoomDoor',
            0x081F8E53: 'PetalburgCity_Gym_EventScript_ConfusionRoomDoor',
            0x081F8E86: 'PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor',
            0x081F8EB9: 'PetalburgCity_Gym_EventScript_RightDefenseRoomDoor',
            0x081F8EEC: 'PetalburgCity_Gym_EventScript_RecoveryRoomDoor',
            0x081F8F1F: 'PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor',
            0x081F8F52: 'PetalburgCity_Gym_EventScript_RightStrengthRoomDoor',
            0x081F8F85: 'PetalburgCity_Gym_EventScript_LeftOHKORoomDoor',
            0x081F8FB8: 'PetalburgCity_Gym_EventScript_RightOHKORoomDoor',
            0x081F8FEB: 'PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor',
            0x081F901E: 'PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor',
            0x081F9051: 'PetalburgCity_Gym_EventScript_Randall',
            0x081F9075: 'PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors',
            0x081F9084: 'PetalburgCity_Gym_EventScript_RandallPostBadge',
            0x081F908D: 'PetalburgCity_Gym_EventScript_Parker',
            0x081F90B1: 'PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors',
            0x081F90C0: 'PetalburgCity_Gym_EventScript_ParkerPostBadge',
            0x081F90C9: 'PetalburgCity_Gym_EventScript_George',
            0x081F90ED: 'PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors',
            0x081F90FC: 'PetalburgCity_Gym_EventScript_GeorgePostBadge',
            0x081F9105: 'PetalburgCity_Gym_EventScript_Berke',
            0x081F9129: 'PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors',
            0x081F9138: 'PetalburgCity_Gym_EventScript_BerkePostBadge',
            0x081F9141: 'PetalburgCity_Gym_EventScript_Mary',
            0x081F9165: 'PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors',
            0x081F9174: 'PetalburgCity_Gym_EventScript_MaryPostBadge',
            0x081F917D: 'PetalburgCity_Gym_EventScript_Alexia',
            0x081F91A1: 'PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors',
            0x081F91B0: 'PetalburgCity_Gym_EventScript_AlexiaPostBadge',
            0x081F91B9: 'PetalburgCity_Gym_EventScript_Jody',
            0x081F91DD: 'PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors',
            0x081F91EC: 'PetalburgCity_Gym_EventScript_JodyPostBadge',
            0x081F91F5: 'PetalburgCity_Gym_EventScript_OpenGymEntranceDoors',
            0x081F9216: 'PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors',
            0x081F9237: 'PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors',
            0x081F9258: 'PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors',
            0x081F9279: 'PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors',
            0x081F929A: 'PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors',
            0x081F92BB: 'PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors',
            0x081F92DC: 'PetalburgCity_Gym_EventScript_OpenOHKORoomDoors',
            0x081F92FD: 'PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles',
            0x081F9322: 'PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles',
            0x081F9347: 'PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles',
            0x081F936C: 'PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles',
            0x081F937F: 'PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles',
            0x081F93A4: 'PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles',
            0x081F93B7: 'PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles',
            0x081F93CA: 'PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles',
            0x081F93DD: 'PetalburgCity_Gym_EventScript_SlideOpenRoomDoors',
            0x081F93E2: 'PetalburgCity_Gym_EventScript_UnlockRoomDoors',
            0x081F93E6: 'PetalburgCity_Gym_EventScript_GymGuide',
            0x081F93FB: 'PetalburgCity_Gym_EventScript_GymGuidePostVictory',
            0x081F9405: 'PetalburgCity_Gym_EventScript_LeftGymStatue',
            0x081F9415: 'PetalburgCity_Gym_EventScript_RightGymStatue',
            0x081F9425: 'PetalburgCity_Gym_EventScript_GymStatueCertified',
            0x081F942F: 'PetalburgCity_Gym_EventScript_GymStatue',
        },
        'tables': {
            0x081F8622: 'PetalburgCity_Gym_OnWarp',
            0x081F8631: 'PetalburgCity_Gym_OnFrame',
        },
        'texts': {
            0x081F9439: 'PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon',
            0x081F94BD: 'PetalburgCity_Gym_Text_WallyIdLikeAPokemon',
            0x081F94D9: 'PetalburgCity_Gym_Text_DadOhYoureWallyRight',
            0x081F94F6: 'PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon',
            0x081F9572: 'PetalburgCity_Gym_Text_DadHmISee',
            0x081F957F: 'PetalburgCity_Gym_Text_DadPlayerGoWithWally',
            0x081F95B6: 'PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon',
            0x081F95E4: 'PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall',
            0x081F9630: 'PetalburgCity_Gym_Text_WallyOhWowThankYou',
            0x081F9640: 'PetalburgCity_Gym_Text_WouldYouReallyComeWithMe',
            0x081F965A: 'PetalburgCity_Gym_Text_DadSoDidItWorkOut',
            0x081F9668: 'PetalburgCity_Gym_Text_WallyThankYouBye',
            0x081F9705: 'PetalburgCity_Gym_Text_DadGoCollectBadges',
            0x081F97E8: 'PetalburgCity_Gym_Text_NormanGoToRustboro',
            0x081F987A: 'PetalburgCity_Gym_Text_NormanGoToDewford',
            0x081F98EE: 'PetalburgCity_Gym_Text_YouHaveGottenStronger',
            0x081F991A: 'PetalburgCity_Gym_Text_NormanIntro',
            0x081F99C5: 'PetalburgCity_Gym_Text_NormanDefeat',
            0x081F9A02: 'PetalburgCity_Gym_Text_ReceivedBalanceBadge',
            0x081F9A1A: 'PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis',
            0x081F9A94: 'PetalburgCity_Gym_Text_ExplainFacade',
            0x081F9AE6: 'PetalburgCity_Gym_Text_DadHappyAndSad',
            0x081F9B2E: 'PetalburgCity_Gym_Text_PleaseComeWithMe',
            0x081F9B5D: 'PetalburgCity_Gym_Text_LetMeBorrowPlayer',
            0x081F9B88: 'PetalburgCity_Gym_Text_DadGoingToKeepTraining',
            0x081F9BE0: 'PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough',
            0x081F9C26: 'PetalburgCity_Gym_Text_GymGuideAdvice',
            0x081F9D34: 'PetalburgCity_Gym_Text_GymGuidePostVictory',
            0x081F9D63: 'PetalburgCity_Gym_Text_RandallIntro',
            0x081F9D95: 'PetalburgCity_Gym_Text_RandallDefeat',
            0x081F9DA7: 'PetalburgCity_Gym_Text_RandallPostBattle',
            0x081F9DE9: 'PetalburgCity_Gym_Text_RandallPostBadge',
            0x081F9E22: 'PetalburgCity_Gym_Text_ParkerIntro',
            0x081F9E48: 'PetalburgCity_Gym_Text_ParkerDefeat',
            0x081F9E68: 'PetalburgCity_Gym_Text_ParkerPostBattle',
            0x081F9E8A: 'PetalburgCity_Gym_Text_ParkerPostBadge',
            0x081F9EB1: 'PetalburgCity_Gym_Text_GeorgeIntro',
            0x081F9EFE: 'PetalburgCity_Gym_Text_GeorgeDefeat',
            0x081F9F1D: 'PetalburgCity_Gym_Text_GeorgePostBattle',
            0x081F9F8B: 'PetalburgCity_Gym_Text_GeorgePostBadge',
            0x081F9FB3: 'PetalburgCity_Gym_Text_BerkeIntro',
            0x081F9FEF: 'PetalburgCity_Gym_Text_BerkeDefeat',
            0x081FA001: 'PetalburgCity_Gym_Text_BerkePostBattle',
            0x081FA072: 'PetalburgCity_Gym_Text_BerkePostBadge',
            0x081FA09D: 'PetalburgCity_Gym_Text_MaryIntro',
            0x081FA0D1: 'PetalburgCity_Gym_Text_MaryDefeat',
            0x081FA0E6: 'PetalburgCity_Gym_Text_MaryPostBattle',
            0x081FA13B: 'PetalburgCity_Gym_Text_MaryPostBadge',
            0x081FA17E: 'PetalburgCity_Gym_Text_AlexiaIntro',
            0x081FA1A2: 'PetalburgCity_Gym_Text_AlexiaDefeat',
            0x081FA1AE: 'PetalburgCity_Gym_Text_AlexiaPostBattle',
            0x081FA20C: 'PetalburgCity_Gym_Text_AlexiaPostBadge',
            0x081FA21D: 'PetalburgCity_Gym_Text_JodyIntro',
            0x081FA25D: 'PetalburgCity_Gym_Text_JodyDefeat',
            0x081FA26D: 'PetalburgCity_Gym_Text_JodyPostBattle',
            0x081FA2BA: 'PetalburgCity_Gym_Text_JodyPostBadge',
            0x081FA300: 'PetalburgCity_Gym_Text_DoorAppearsLocked',
            0x081FA31E: 'PetalburgCity_Gym_Text_EnterSpeedRoom',
            0x081FA342: 'PetalburgCity_Gym_Text_DoorAppearsLocked2',
            0x081FA360: 'PetalburgCity_Gym_Text_EnterAccuracyRoom',
            0x081FA385: 'PetalburgCity_Gym_Text_EnterConfusionRoom',
            0x081FA3A9: 'PetalburgCity_Gym_Text_EnterDefenseRoom',
            0x081FA3CC: 'PetalburgCity_Gym_Text_EnterRecoveryRoom',
            0x081FA3F0: 'PetalburgCity_Gym_Text_EnterStrengthRoom',
            0x081FA413: 'PetalburgCity_Gym_Text_EnterOHKORoom',
            0x081FA437: 'PetalburgCity_Gym_Text_EnterGymLeadersRoom',
            0x081FA47B: 'PetalburgCity_Gym_Text_GymStatue',
            0x081FA489: 'PetalburgCity_Gym_Text_GymStatueCertified',
            0x081FA4AA: 'PetalburgCity_Gym_Text_NormanPreRematch',
            0x081FA535: 'PetalburgCity_Gym_Text_NormanRematchDefeat',
            0x081FA550: 'PetalburgCity_Gym_Text_NormanPostRematch',
            0x081FA586: 'PetalburgCity_Gym_Text_NormanRematchNeedTwoMons',
        },
        'field_placeholders': {
            0x081F9439: {0x01: 'PLAYER'},
            0x081F957F: {0x01: 'PLAYER'},
            0x081F9640: {0x01: 'PLAYER'},
            0x081F9668: {0x01: 'PLAYER'},
            0x081F9705: {0x01: 'PLAYER'},
            0x081F97E8: {0x01: 'PLAYER'},
            0x081F987A: {0x01: 'PLAYER'},
            0x081F98EE: {0x01: 'PLAYER'},
            0x081F991A: {0x01: 'PLAYER'},
            0x081F99C5: {0x01: 'PLAYER'},
            0x081F9A02: {0x01: 'PLAYER'},
            0x081F9A1A: {0x01: 'PLAYER'},
            0x081F9B2E: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F9B5D: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x081F9B88: {0x01: 'PLAYER'},
            0x081F9BE0: {0x01: 'PLAYER'},
            0x081F9C26: {0x01: 'PLAYER'},
            0x081F9D34: {0x01: 'PLAYER'},
            0x081FA489: {0x01: 'PLAYER'},
            0x081FA4AA: {0x01: 'PLAYER'},
            0x081FA550: {0x01: 'PLAYER'},
            0x081FA586: {0x01: 'PLAYER'},
        },
        'external_texts': VERIFIED_SHARED_TEXT_BLOCKS[
            'PetalburgCity_Gym_EnigmaBerry']['labels'],
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x082430EA: 'Common_EventScript_BagIsFull',
            0x0824310A: 'Common_EventScript_PlayGymBadgeFanfare',
            0x08242FCF: 'Common_EventScript_SetGymTrainers',
            0x0824327B: 'EventScript_HideMrBriney',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'specials': {
            'sub_0813B9D8': 'ResetHealLocationFromDewford',
        },
        # data_b2d_mid26.s now uses the canonical map labels directly.
        # Do not retain address-derived aliases when this source is regenerated.
        'preserve_region_script_aliases': False,
        'implicit_waitstate_specials': ('PetalburgGymSlideOpenRoomDoors',),
        'symbols': {
            'vars': {
                0x402D: 'VAR_ENIGMA_BERRY_AVAILABLE',
                0x4057: 'VAR_PETALBURG_CITY_STATE',
                0x4085: 'VAR_PETALBURG_GYM_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8008: 'VAR_0x8008',
                0x8009: 'VAR_0x8009',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x8015: 'VAR_TRAINER_BATTLE_OPPONENT_A',
            },
            'flags': {
                0x00A9: 'FLAG_RECEIVED_TM_FACADE',
                0x02D6: 'FLAG_HIDE_PETALBURG_CITY_WALLY',
                0x02D8: 'FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM',
                0x033E: 'FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD',
                0x0362: 'FLAG_HIDE_PETALBURG_GYM_WALLY',
                0x0379: 'FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL',
                0x0390: 'FLAG_HIDE_MAUVILLE_CITY_WATTSON',
                0x0391: 'FLAG_HIDE_MAUVILLE_GYM_WATTSON',
                0x03AC: 'FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN',
                0x04F4: 'FLAG_DEFEATED_PETALBURG_GYM',
                0x0864: 'FLAG_SYS_GAME_CLEAR',
                0x086B: 'FLAG_BADGE05_GET',
                0x4001: 'FLAG_DONT_TRANSITION_MUSIC',
            },
            'trainers': {
                0x0047: 'TRAINER_RANDALL',
                0x0048: 'TRAINER_PARKER',
                0x0049: 'TRAINER_GEORGE',
                0x004A: 'TRAINER_BERKE',
                0x0059: 'TRAINER_MARY',
                0x005A: 'TRAINER_ALEXIA',
                0x005B: 'TRAINER_JODY',
                0x010D: 'TRAINER_NORMAN_1',
            },
            'items': {
                0x00AF: 'ITEM_ENIGMA_BERRY',
                0x014A: 'ITEM_TM_FACADE',
            },
            'metatiles': {
                0x0210: 'METATILE_PetalburgGym_RoomEntrance_Left',
                0x0211: 'METATILE_PetalburgGym_RoomEntrance_Right',
            },
            'maps': {
                0x0000: 'MAP_PETALBURG_CITY',
                0x0801: 'MAP_PETALBURG_CITY_GYM',
            },
            'local_ids': {
                0x0001: 'LOCALID_PETALBURG_GYM_NORMAN',
                0x000A: 'LOCALID_PETALBURG_GYM_WALLY',
                0x000B: 'LOCALID_PETALBURG_GYM_WALLYS_DAD',
                0x00FF: 'LOCALID_PLAYER',
            },
            'directions': {
                0x01: 'DIR_SOUTH',
                0x02: 'DIR_NORTH',
                0x03: 'DIR_WEST',
                0x04: 'DIR_EAST',
            },
            'switch_values': {
                'VAR_FACING': {
                    0x01: 'DIR_SOUTH',
                    0x02: 'DIR_NORTH',
                    0x03: 'DIR_WEST',
                    0x04: 'DIR_EAST',
                },
            },
            'songs': {0x01A4: 'MUS_FOLLOW_ME'},
            'sounds': {0x08: 'SE_DOOR', 0x09: 'SE_EXIT', 0x15: 'SE_PIN'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
}

# Petalburg's two residential houses immediately follow the Gym in the
# physical event-script owner. Their four NPC scripts and four text objects
# were aligned with the matching US map sources before directory migration.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'PetalburgCity_House1': {
        'scripts': {
            0x081FA63E: 'PetalburgCity_House1_EventScript_Man',
            0x081FA647: 'PetalburgCity_House1_EventScript_Woman',
        },
        'texts': {
            0x081FA650: 'PetalburgCity_House1_Text_TravelingIsWonderful',
            0x081FA67F: 'PetalburgCity_House1_Text_GoOnAdventure',
        },
        'preserve_region_script_aliases': False,
    },
    'PetalburgCity_House2': {
        'scripts': {
            0x081FA721: 'PetalburgCity_House2_EventScript_Woman',
            0x081FA72A: 'PetalburgCity_House2_EventScript_SchoolKid',
        },
        'texts': {
            0x081FA733: 'PetalburgCity_House2_Text_NormanBecameGymLeader',
            0x081FA775: 'PetalburgCity_House2_Text_BattledNormanOnce',
        },
        'preserve_region_script_aliases': False,
    },
})

# Rustboro Devon Corp 2F is a complete, contiguous JP map-script owner.
# Every local script/text address below was aligned with the matching US map
# by event position, control-flow shape, and text order before enabling names.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'RustboroCity_DevonCorp_2F': {
        'scripts': {
            0x0820142F: 'RustboroCity_DevonCorp_2F_OnTransition',
            0x0820143B: 'RustboroCity_DevonCorp_2F_EventScript_SetFossilReady',
            0x08201441: 'RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist',
            0x08201458: 'RustboroCity_DevonCorp_2F_EventScript_BallScientist',
            0x08201478: 'RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls',
            0x08201482: 'RustboroCity_DevonCorp_2F_EventScript_PokenavScientist',
            0x082014A2: 'RustboroCity_DevonCorp_2F_EventScript_HasPokenav',
            0x082014AC: 'RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist',
            0x082014C3: 'RustboroCity_DevonCorp_2F_EventScript_FossilScientist',
            0x08201505: 'RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil',
            0x08201546: 'RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil',
            0x08201563: 'RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil',
            0x082015A4: 'RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil',
            0x082015C1: 'RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil',
            0x082015CB: 'RustboroCity_DevonCorp_2F_EventScript_StillRegenerating',
            0x082015D5: 'RustboroCity_DevonCorp_2F_EventScript_FossilMonReady',
            0x082015EC: 'RustboroCity_DevonCorp_2F_EventScript_LileepReady',
            0x082015FE: 'RustboroCity_DevonCorp_2F_EventScript_AnorithReady',
            0x08201610: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep',
            0x08201640: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty',
            0x08201668: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC',
            0x0820168B: 'RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC',
            0x08201696: 'RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare',
            0x082016A9: 'RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep',
            0x082016B3: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith',
            0x082016E3: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty',
            0x0820170B: 'RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC',
            0x0820172E: 'RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC',
            0x08201739: 'RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare',
            0x0820174C: 'RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith',
            0x08201756: 'RustboroCity_DevonCorp_2F_EventScript_ChooseFossil',
            0x08201793: 'RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil',
            0x08201799: 'RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil',
            0x0820179F: 'RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect',
            0x082017A1: 'RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist',
            0x082017C3: 'RustboroCity_DevonCorp_2F_EventScript_WorkOnNext',
        },
        'texts': {
            0x082017CD: 'RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon',
            0x082017FF: 'RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls',
            0x08201831: 'RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls',
            0x082018CD: 'RustboroCity_DevonCorp_2F_Text_IMadePokenav',
            0x08201908: 'RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav',
            0x08201983: 'RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams',
            0x082019BF: 'RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils',
            0x082019FB: 'RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife',
            0x08201A42: 'RustboroCity_DevonCorp_2F_Text_OhIsThatSo',
            0x08201A5F: 'RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne',
            0x08201AB1: 'RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher',
            0x08201ADF: 'RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime',
            0x08201B2F: 'RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife',
            0x08201B65: 'RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher',
            0x08201B83: 'RustboroCity_DevonCorp_2F_Text_TooManyPokemon',
            0x08201B99: 'RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature',
            0x08201BCC: 'RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext',
        },
        'field_placeholders': {
            0x08201AB1: {0x01: 'PLAYER', 0x02: 'STR_VAR_1'},
            0x08201B2F: {0x03: 'STR_VAR_2'},
            0x08201B65: {0x01: 'PLAYER', 0x03: 'STR_VAR_2'},
        },
        'external_texts': {
            0x08243EDB: 'gText_NicknameThisPokemon',
        },
        'external_labels': {
            0x08243460: 'Common_EventScript_NameReceivedPartyMon',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x082441B5: 'Common_EventScript_GetGiftMonPartySlot',
            0x082441C1: 'Common_EventScript_NameReceivedBoxMon',
            0x082441CA: 'Common_EventScript_TransferredToPC',
            0x0824423B: 'Common_EventScript_NoMoreRoomForPokemon',
        },
        'symbols': {
            'vars': {
                0x4001: 'VAR_TEMP_TRANSFERRED_SPECIES',
                0x405A: 'VAR_RUSTBORO_CITY_STATE',
                0x40C4: 'VAR_FOSSIL_RESURRECTION_STATE',
                0x40C5: 'VAR_WHICH_FOSSIL_REVIVED',
                0x8000: 'VAR_0x8000',
                0x800D: 'VAR_RESULT',
            },
            'flags': {
                0x00BC: 'FLAG_RECEIVED_POKENAV',
                0x010B: 'FLAG_RECEIVED_REVIVED_FOSSIL_MON',
                0x011F: 'FLAG_MET_DEVON_EMPLOYEE',
            },
            'items': {
                0x011E: 'ITEM_ROOT_FOSSIL',
                0x011F: 'ITEM_CLAW_FOSSIL',
            },
            'species': {
                0x0184: 'SPECIES_LILEEP',
                0x0186: 'SPECIES_ANORITH',
            },
            'local_ids': {0x05: 'LOCALID_FOSSIL_SCIENTIST'},
            'songs': {0x0172: 'MUS_OBTAIN_ITEM'},
            'sounds': {0x15: 'SE_PIN'},
            'multichoices': {0x5D: 'MULTI_FOSSIL'},
            'switch_values': {
                'VAR_RESULT': {0x7F: 'MULTI_B_PRESSED'},
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Rustboro Gym is a complete, contiguous JP map-script owner.  The entries
# below are aligned with the matching US map by event position, script flow,
# and text order before enabling source-level names.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'RustboroCity_Gym': {
        'scripts': {
            0x082022C6: 'RustboroCity_Gym_EventScript_Roxanne',
            0x082022FB: 'RustboroCity_Gym_EventScript_RoxanneDefeated',
            0x08202339: 'RustboroCity_Gym_EventScript_GiveRockTomb',
            0x0820235D: 'RustboroCity_Gym_EventScript_RoxanneRematch',
            0x08202378: 'RustboroCity_Gym_EventScript_Josh',
            0x0820238F: 'RustboroCity_Gym_EventScript_Tommy',
            0x082023A6: 'RustboroCity_Gym_EventScript_Marc',
            0x082023BD: 'RustboroCity_Gym_EventScript_GymGuide',
            0x082023D2: 'RustboroCity_Gym_EventScript_GymGuidePostVictory',
            0x082023DC: 'RustboroCity_Gym_EventScript_LeftGymStatue',
            0x082023EC: 'RustboroCity_Gym_EventScript_RightGymStatue',
            0x082023FC: 'RustboroCity_Gym_EventScript_GymStatueCertified',
            0x08202406: 'RustboroCity_Gym_EventScript_GymStatue',
            0x08202410: 'RustboroCity_Gym_EventScript_RegisterRoxanne',
        },
        'texts': {
            0x08202432: 'RustboroCity_Gym_Text_GymGuideAdvice',
            0x08202581: 'RustboroCity_Gym_Text_GymGuidePostVictory',
            0x08202612: 'RustboroCity_Gym_Text_JoshIntro',
            0x08202636: 'RustboroCity_Gym_Text_JoshDefeat',
            0x08202647: 'RustboroCity_Gym_Text_JoshPostBattle',
            0x08202665: 'RustboroCity_Gym_Text_TommyIntro',
            0x0820268E: 'RustboroCity_Gym_Text_TommyDefeat',
            0x0820269A: 'RustboroCity_Gym_Text_TommyPostBattle',
            0x082026C0: 'RustboroCity_Gym_Text_MarcIntro',
            0x082026DB: 'RustboroCity_Gym_Text_MarcDefeat',
            0x082026F4: 'RustboroCity_Gym_Text_MarcPostBattle',
            0x08202722: 'RustboroCity_Gym_Text_RoxanneIntro',
            0x082027A3: 'RustboroCity_Gym_Text_RoxanneDefeat',
            0x08202830: 'RustboroCity_Gym_Text_ReceivedStoneBadge',
            0x08202849: 'RustboroCity_Gym_Text_StoneBadgeInfoTakeThis',
            0x082028BA: 'RustboroCity_Gym_Text_ExplainRockTomb',
            0x0820295A: 'RustboroCity_Gym_Text_RoxannePostBattle',
            0x082029AB: 'RustboroCity_Gym_Text_GymStatue',
            0x082029BA: 'RustboroCity_Gym_Text_GymStatueCertified',
            0x082029DC: 'RustboroCity_Gym_Text_RoxanneRegisterCall',
            0x08202AB0: 'RustboroCity_Gym_Text_RegisteredRoxanne',
            0x08202ACB: 'RustboroCity_Gym_Text_RoxannePreRematch',
            0x08202B2A: 'RustboroCity_Gym_Text_RoxanneRematchDefeat',
            0x08202B41: 'RustboroCity_Gym_Text_RoxannePostRematch',
            0x08202B8B: 'RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons',
        },
        'field_placeholders': {
            0x08202830: {0x01: 'PLAYER'},
            0x082029BA: {0x01: 'PLAYER'},
            0x082029DC: {0x01: 'PLAYER'},
        },
        'external_labels': {
            0x08242F10: 'Common_EventScript_ReadyPetalburgGymForBattle',
            0x08242FCF: 'Common_EventScript_SetGymTrainers',
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x0824310A: 'Common_EventScript_PlayGymBadgeFanfare',
        },
        'symbols': {
            'vars': {
                0x405A: 'VAR_RUSTBORO_CITY_STATE',
                0x4085: 'VAR_PETALBURG_GYM_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'flags': {
                0x0080: 'FLAG_ENABLE_ROXANNE_FIRST_CALL',
                0x00A5: 'FLAG_RECEIVED_TM_ROCK_TOMB',
                0x01D3: 'FLAG_ENABLE_ROXANNE_MATCH_CALL',
                0x04F0: 'FLAG_DEFEATED_RUSTBORO_GYM',
                0x0867: 'FLAG_BADGE01_GET',
            },
            'items': {0x0147: 'ITEM_TM_ROCK_TOMB'},
            'trainers': {
                0x0109: 'TRAINER_ROXANNE_1',
                0x0140: 'TRAINER_JOSH',
                0x0141: 'TRAINER_TOMMY',
                0x023B: 'TRAINER_MARC',
            },
            'songs': {0x01CC: 'MUS_REGISTER_MATCH_CALL'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Rustboro's Pokemon School follows the same contiguous ownership model. Its
# blackboard dispatch, teacher gift, and Scott progression paths were matched
# to US source by event position, control flow, movement targets, and text
# order before source-level names were enabled.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'RustboroCity_PokemonSchool': {
        'scripts': {
            0x08202C1B: 'RustboroCity_PokemonSchool_EventScript_Blackboard',
            0x08202C2A: 'RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic',
            0x08202C89: 'RustboroCity_PokemonSchool_EventScript_Poison',
            0x08202C97: 'RustboroCity_PokemonSchool_EventScript_Paralysis',
            0x08202CA5: 'RustboroCity_PokemonSchool_EventScript_Sleep',
            0x08202CB3: 'RustboroCity_PokemonSchool_EventScript_Burn',
            0x08202CC1: 'RustboroCity_PokemonSchool_EventScript_Freeze',
            0x08202CCF: 'RustboroCity_PokemonSchool_EventScript_ExitTopicSelect',
            0x08202CD1: 'RustboroCity_PokemonSchool_EventScript_GameboyKid1',
            0x08202CDA: 'RustboroCity_PokemonSchool_EventScript_GameboyKid2',
            0x08202CE3: 'RustboroCity_PokemonSchool_EventScript_RichBoy',
            0x08202CEC: 'RustboroCity_PokemonSchool_EventScript_Lass',
            0x08202CF5: 'RustboroCity_PokemonSchool_EventScript_SchoolKidM',
            0x08202CFE: 'RustboroCity_PokemonSchool_EventScript_StudentNotebook',
            0x08202D07: 'RustboroCity_PokemonSchool_EventScript_Teacher',
            0x08202D57: 'RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast',
            0x08202D62: 'RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest',
            0x08202D6D: 'RustboroCity_PokemonSchool_EventScript_GaveQuickClaw',
            0x08202DB2: 'RustboroCity_PokemonSchool_EventScript_Scott',
            0x08202DE1: 'RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready',
            0x08202DF4: 'RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge',
            0x08202E02: 'RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge',
            0x08202E10: 'RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge',
            0x08202E1A: 'RustboroCity_PokemonSchool_EventScript_ScottWatchStudents',
        },
        'texts': {
            0x08202E24: 'RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges',
            0x08202E54: 'RustboroCity_PokemonSchool_Text_ReadWhichTopic',
            0x08202E63: 'RustboroCity_PokemonSchool_Text_ExplainPoison',
            0x08202EAF: 'RustboroCity_PokemonSchool_Text_ExplainParalysis',
            0x08202EF5: 'RustboroCity_PokemonSchool_Text_ExplainSleep',
            0x08202F56: 'RustboroCity_PokemonSchool_Text_ExplainBurn',
            0x08202FA7: 'RustboroCity_PokemonSchool_Text_ExplainFreeze',
            0x08202FE5: 'RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw',
            0x08203045: 'RustboroCity_PokemonSchool_Text_ExplainQuickClaw',
            0x082030B2: 'RustboroCity_PokemonSchool_Text_TradingRightNow',
            0x082030CD: 'RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot',
            0x082030EA: 'RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems',
            0x08203128: 'RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself',
            0x0820318A: 'RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry',
            0x082031E4: 'RustboroCity_PokemonSchool_Text_StudentsNotes',
            0x08203274: 'RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut',
            0x08203339: 'RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown',
            0x0820336D: 'RustboroCity_PokemonSchool_Text_ScottStoneBadge',
            0x082033DD: 'RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge',
        },
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'symbols': {
            'vars': {
                0x40D1: 'VAR_SCOTT_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'var_values': {
                0x8000: {0x7F: 'MULTI_B_PRESSED'},
                0x800C: {0x03: 'DIR_WEST', 0x04: 'DIR_EAST'},
            },
            'flags': {
                0x0113: 'FLAG_RECEIVED_QUICK_CLAW',
                0x0136: 'FLAG_MET_SCOTT_RUSTBORO',
                0x01CB: 'FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE',
                0x0867: 'FLAG_BADGE01_GET',
            },
            'items': {0x00B7: 'ITEM_QUICK_CLAW'},
            'multichoices': {0x0D: 'MULTI_STATUS_INFO'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Rustboro Flat1 2F is the next physical map-script owner after Flat1 1F.
# The Walda phrase flow, object events, and every text record were aligned to
# the matching US map before enabling semantic labels and placeholders.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'RustboroCity_Flat1_2F': {
        'scripts': {
            0x08203771: 'RustboroCity_Flat1_2F_EventScript_WaldasDad',
            0x0820378E: 'RustboroCity_Flat1_2F_EventScript_GivePhrase',
            0x082037C4: 'RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase',
            0x082037E4: 'RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase',
            0x08203804: 'RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase',
            0x0820380E: 'RustboroCity_Flat1_2F_EventScript_CancelGivePhrase',
            0x08203818: 'RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase',
            0x0820382F: 'RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase',
            0x08203858: 'RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase',
            0x0820386F: 'RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda',
            0x08203874: 'RustboroCity_Flat1_2F_EventScript_WaldasMom',
            0x0820387D: 'RustboroCity_Flat1_2F_EventScript_PokeDoll',
        },
        'texts': {
            0x08203886: 'RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard',
            0x082038E4: 'RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase',
            0x0820398A: 'RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase',
            0x082039B9: 'RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion',
            0x082039D3: 'RustboroCity_Flat1_2F_Text_OhIsThatRight',
            0x082039FB: 'RustboroCity_Flat1_2F_Text_LetsGiveItATry2',
            0x08203A10: 'RustboroCity_Flat1_2F_Text_OhShesLaughing',
            0x08203A2F: 'RustboroCity_Flat1_2F_Text_LetsGiveItATry',
            0x08203A44: 'RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll',
            0x08203A63: 'RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase',
            0x08203A9D: 'RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2',
            0x08203ABC: 'RustboroCity_Flat1_2F_Text_OhYouDontKnowAny',
            0x08203B01: 'RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper',
            0x08203BB9: 'RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll',
        },
        'field_placeholders': {
            0x0820398A: {0x02: 'STR_VAR_1'},
            0x08203A10: {0x02: 'STR_VAR_1'},
            0x08203A44: {0x02: 'STR_VAR_1'},
            0x08203A63: {0x02: 'STR_VAR_1'},
            0x08203A9D: {0x02: 'STR_VAR_1'},
        },
        'external_labels': {
            0x08243621: 'Common_Movement_FacePlayer',
        },
        'symbols': {
            'vars': {
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'script_var_values': {
                0x08203771: {0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
                0x0820378E: {0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
            },
            'local_ids': {0x06: 'LOCALID_WALDAS_DAD'},
            'directions': {0x04: 'DIR_EAST'},
        },
    },
})

# Fortree Gym occupies one contiguous physical script range. The rotating-gate
# setup, every trainer and statue event, and the Winona reward/rematch flow
# were aligned with the US map before the two remaining raw spans were opened.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'FortreeCity_Gym': {
        'scripts': {
            0x082043A9: 'FortreeCity_Gym_OnTransition',
            0x082043B7: 'FortreeCity_Gym_EventScript_InitRotatingGates',
            0x082043BB: 'FortreeCity_Gym_EventScript_Winona',
            0x082043F0: 'FortreeCity_Gym_EventScript_WinonaDefeated',
            0x08204439: 'FortreeCity_Gym_EventScript_GiveAerialAce2',
            0x0820445D: 'FortreeCity_Gym_EventScript_GiveAerialAce',
            0x08204480: 'FortreeCity_Gym_EventScript_WinonaRematch',
            0x0820449B: 'FortreeCity_Gym_EventScript_Jared',
            0x082044B2: 'FortreeCity_Gym_EventScript_Edwardo',
            0x082044C9: 'FortreeCity_Gym_EventScript_Flint',
            0x082044E0: 'FortreeCity_Gym_EventScript_Ashley',
            0x082044F7: 'FortreeCity_Gym_EventScript_Humberto',
            0x0820450E: 'FortreeCity_Gym_EventScript_Darius',
            0x08204525: 'FortreeCity_Gym_EventScript_GymGuide',
            0x0820453A: 'FortreeCity_Gym_EventScript_GymGuidePostVictory',
            0x08204544: 'FortreeCity_Gym_EventScript_LeftGymStatue',
            0x08204554: 'FortreeCity_Gym_EventScript_RightGymStatue',
            0x08204564: 'FortreeCity_Gym_EventScript_GymStatueCertified',
            0x0820456E: 'FortreeCity_Gym_EventScript_GymStatue',
        },
        'tables': {0x082043AD: 'FortreeCity_Gym_OnWarp'},
        'texts': {
            0x08204578: 'FortreeCity_Gym_Text_GymGuideAdvice',
            0x08204609: 'FortreeCity_Gym_Text_GymGuidePostVictory',
            0x0820461B: 'FortreeCity_Gym_Text_JaredIntro',
            0x08204638: 'FortreeCity_Gym_Text_JaredDefeat',
            0x08204646: 'FortreeCity_Gym_Text_JaredPostBattle',
            0x08204690: 'FortreeCity_Gym_Text_EdwardoIntro',
            0x082046D8: 'FortreeCity_Gym_Text_EdwardoDefeat',
            0x082046EA: 'FortreeCity_Gym_Text_EdwardoPostBattle',
            0x08204727: 'FortreeCity_Gym_Text_FlintIntro',
            0x0820475A: 'FortreeCity_Gym_Text_FlintDefeat',
            0x0820476A: 'FortreeCity_Gym_Text_FlintPostBattle',
            0x08204793: 'FortreeCity_Gym_Text_AshleyIntro',
            0x082047B9: 'FortreeCity_Gym_Text_AshleyDefeat',
            0x082047C5: 'FortreeCity_Gym_Text_AshleyPostBattle',
            0x082047EA: 'FortreeCity_Gym_Text_HumbertoIntro',
            0x0820481C: 'FortreeCity_Gym_Text_HumbertoDefeat',
            0x0820482F: 'FortreeCity_Gym_Text_HumbertoPostBattle',
            0x08204851: 'FortreeCity_Gym_Text_DariusIntro',
            0x08204880: 'FortreeCity_Gym_Text_DariusDefeat',
            0x0820488D: 'FortreeCity_Gym_Text_DariusPostBattle',
            0x082048B1: 'FortreeCity_Gym_Text_WinonaIntro',
            0x08204936: 'FortreeCity_Gym_Text_WinonaDefeat',
            0x08204982: 'FortreeCity_Gym_Text_ReceivedFeatherBadge',
            0x0820499A: 'FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis',
            0x08204A14: 'FortreeCity_Gym_Text_ExplainAerialAce',
            0x08204A59: 'FortreeCity_Gym_Text_RegisteredWinona',
            0x08204A73: 'FortreeCity_Gym_Text_WinonaPostBattle',
            0x08204AA0: 'FortreeCity_Gym_Text_GymStatue',
            0x08204AAF: 'FortreeCity_Gym_Text_GymStatueCertified',
            0x08204AD0: 'FortreeCity_Gym_Text_WinonaPreRematch',
            0x08204B49: 'FortreeCity_Gym_Text_WinonaRematchDefeat',
            0x08204B57: 'FortreeCity_Gym_Text_WinonaPostRematch',
            0x08204BA1: 'FortreeCity_Gym_Text_WinonaRematchNeedTwoMons',
        },
        'field_placeholders': {
            0x08204578: {0x01: 'PLAYER'},
            0x08204982: {0x01: 'PLAYER'},
            0x08204AAF: {0x01: 'PLAYER'},
        },
        'external_labels': {
            0x08242FCF: 'Common_EventScript_SetGymTrainers',
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x082430EA: 'Common_EventScript_BagIsFull',
            0x0824310A: 'Common_EventScript_PlayGymBadgeFanfare',
        },
        'symbols': {
            'vars': {
                0x4000: 'VAR_TEMP_0',
                0x40F3: 'VAR_SCOTT_FORTREE_CALL_STEP_COUNTER',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'flags': {
                0x008A: 'FLAG_SCOTT_CALL_FORTREE_GYM',
                0x00AA: 'FLAG_RECEIVED_TM_AERIAL_ACE',
                0x01D7: 'FLAG_ENABLE_WINONA_MATCH_CALL',
                0x04F5: 'FLAG_DEFEATED_FORTREE_GYM',
                0x086C: 'FLAG_BADGE06_GET',
            },
            'trainers': {
                0x010E: 'TRAINER_WINONA_1',
                0x0191: 'TRAINER_JARED',
                0x0192: 'TRAINER_HUMBERTO',
                0x0194: 'TRAINER_EDWARDO',
                0x028E: 'TRAINER_FLINT',
                0x028F: 'TRAINER_ASHLEY',
                0x0323: 'TRAINER_DARIUS',
            },
            'items': {0x0148: 'ITEM_TM_AERIAL_ACE'},
            'songs': {0x01CC: 'MUS_REGISTER_MATCH_CALL'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Fortree Pokemon Center 1F follows Fortree Gym in physical script order.
# Its map hooks, nurse, three NPCs, and text order were checked against the
# matching US source before naming the complete map range.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'FortreeCity_PokemonCenter_1F': {
        'scripts': {
            0x08204C68: 'FortreeCity_PokemonCenter_1F_OnTransition',
            0x08204C6C: 'FortreeCity_PokemonCenter_1F_EventScript_Nurse',
            0x08204C7A: 'FortreeCity_PokemonCenter_1F_EventScript_Gentleman',
            0x08204C83: 'FortreeCity_PokemonCenter_1F_EventScript_Man',
            0x08204C8C: 'FortreeCity_PokemonCenter_1F_EventScript_Boy',
        },
        'texts': {
            0x08204C95: 'FortreeCity_PokemonCenter_1F_Text_GoToSafariZone',
            0x08204CCE: 'FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat',
            0x08204D21: 'FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav',
        },
        'external_labels': {
            0x082429B8: 'Common_EventScript_PkmnCenterNurse',
            0x0824790F: 'CableClub_OnResume',
        },
        'symbols': {
            'vars': {0x800B: 'VAR_0x800B'},
            'local_ids': {0x01: 'LOCALID_FORTREE_NURSE'},
            'heal_locations': {0x07: 'HEAL_LOCATION_FORTREE_CITY'},
        },
    },
})

# The three RS-era Cable Club entries sit immediately after the 2F map-script
# table.  They are not reached by its event table, but the matching US source
# retains them as named map-local scripts.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'FortreeCity_PokemonCenter_2F': {
        'scripts': {
            0x08204DAB: 'FortreeCity_PokemonCenter_2F_EventScript_Colosseum',
            0x08204DB1: 'FortreeCity_PokemonCenter_2F_EventScript_TradeCenter',
            0x08204DB7: 'FortreeCity_PokemonCenter_2F_EventScript_RecordCorner',
        },
        'external_labels': {
            0x082467CD: 'CableClub_OnTransition',
            0x0824686A: 'CableClub_OnWarp',
            0x082468BC: 'CableClub_OnLoad',
            0x08246939: 'CableClub_OnFrame',
            0x08246BB2: 'CableClub_EventScript_Colosseum',
            0x08246DAD: 'CableClub_EventScript_TradeCenter',
            0x08246ED6: 'CableClub_EventScript_RecordCorner',
        },
    },
})

# Rustboro's adjacent Pokemon Center 2F and Mart ranges have the same source
# ownership as the US maps. The Cable Club leftovers are intentionally unused,
# while the two shop lists follow their clerk scripts with one-byte alignment.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'RustboroCity_PokemonCenter_2F': {
        'scripts': {
            0x082035CE: 'RustboroCity_PokemonCenter_2F_EventScript_Colosseum',
            0x082035D4: 'RustboroCity_PokemonCenter_2F_EventScript_TradeCenter',
            0x082035DA: 'RustboroCity_PokemonCenter_2F_EventScript_RecordCorner',
        },
        'external_labels': {
            0x082467CD: 'CableClub_OnTransition',
            0x0824686A: 'CableClub_OnWarp',
            0x082468BC: 'CableClub_OnLoad',
            0x08246939: 'CableClub_OnFrame',
            0x08246BB2: 'CableClub_EventScript_Colosseum',
            0x08246DAD: 'CableClub_EventScript_TradeCenter',
            0x08246ED6: 'CableClub_EventScript_RecordCorner',
        },
    },
    'RustboroCity_Mart': {
        'scripts': {
            0x082035E1: 'RustboroCity_Mart_EventScript_Clerk',
            0x082035FC: 'RustboroCity_Mart_EventScript_PokemartBasic',
            0x08203624: 'RustboroCity_Mart_EventScript_PokemartExpanded',
            0x08203650: 'RustboroCity_Mart_EventScript_PokefanF',
            0x08203659: 'RustboroCity_Mart_EventScript_Boy',
            0x08203662: 'RustboroCity_Mart_EventScript_BugCatcher',
        },
        'texts': {
            0x0820366B: 'RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish',
            0x0820369D: 'RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead',
            0x082036D4: 'RustboroCity_Mart_Text_GettingEscapeRopeJustInCase',
        },
        'symbols': {
            'flags': {0x011F: 'FLAG_MET_DEVON_EMPLOYEE'},
        },
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
        },
    },
})

# Lilycove Museum 2F is one contiguous JP map-owned range.  The flags,
# painting metatiles, movement records, and all display text were checked
# against the matching US map source before replacing its remaining raw tail.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_LilycoveMuseum_2F': {
        'scripts': {
            0x082061F1: 'LilycoveCity_LilycoveMuseum_2F_OnLoad',
            0x08206200: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting',
            0x0820620F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting',
            0x0820621E: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting',
            0x0820622D: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting',
            0x08206237: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting',
            0x0820624F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting',
            0x08206267: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting',
            0x0820627F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting',
            0x08206297: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting',
            0x082062B4: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall',
            0x08206312: 'LilycoveCity_LilycoveMuseum_2F_EventScript_Curator',
            0x08206366: 'LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting',
            0x0820636F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer',
            0x08206396: 'LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament',
            0x082063BD: 'LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament',
            0x082063CD: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament',
            0x082063D7: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting',
            0x082063EA: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting',
            0x082063FD: 'LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting',
            0x08206410: 'LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting',
            0x08206423: 'LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting',
            0x08206436: 'LilycoveCity_LilycoveMuseum_2F_EventScript_Girl',
            0x0820643F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM',
            0x08206448: 'LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy',
            0x08206451: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting',
            0x0820645F: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting',
            0x0820646D: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting',
            0x0820647B: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting',
            0x08206489: 'LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting',
        },
        'tables': {
            0x082062AA: 'LilycoveCity_LilycoveMuseum_2F_OnFrame',
        },
        'texts': {
            0x08206497: 'LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall',
            0x082064A9: 'LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall',
            0x0820655D: 'LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit',
            0x08206607: 'LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit',
            0x08206636: 'LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting',
            0x08206681: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer',
            0x0820668E: 'LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests',
            0x0820670F: 'LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude',
            0x08206729: 'LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou',
            0x08206743: 'LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit',
            0x08206788: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame',
            0x0820679E: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame',
            0x082067B3: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame',
            0x082067C7: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame',
            0x082067DB: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame',
            0x082067F2: 'LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon',
            0x08206803: 'LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe',
            0x0820684E: 'LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing',
            0x08206898: 'LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon',
        },
        'external_labels': {
            0x082430FD: 'Common_EventScript_NoRoomForDecor',
            0x08243621: 'Common_Movement_FacePlayer',
        },
        # The paired US curator messages prove that FD 01 is the player name
        # in these three JP text records; do not expose raw control indices.
        'field_placeholders': {
            0x08206681: {0x01: 'PLAYER'},
            0x0820668E: {0x01: 'PLAYER'},
            0x08206743: {0x01: 'PLAYER'},
        },
        'symbols': {
            'flags': {
                0x00A0: 'FLAG_COOL_PAINTING_MADE',
                0x00A1: 'FLAG_BEAUTY_PAINTING_MADE',
                0x00A2: 'FLAG_CUTE_PAINTING_MADE',
                0x00A3: 'FLAG_SMART_PAINTING_MADE',
                0x00A4: 'FLAG_TOUGH_PAINTING_MADE',
                0x00EC: 'FLAG_RECEIVED_GLASS_ORNAMENT',
            },
            'vars': {
                0x4094: 'VAR_LILYCOVE_MUSEUM_2F_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800D: 'VAR_RESULT',
            },
            'script_var_values': {
                # The following callstd is the decoration-giving wrapper, so
                # this VAR_0x8000 value is a decoration rather than an item.
                0x08206396: {0x8000: {0x002C: 'DECOR_GLASS_ORNAMENT'}},
            },
            'local_ids': {
                0x01: 'LOCALID_MUSEUM_2F_CURATOR',
                0xFF: 'LOCALID_PLAYER',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'metatiles': {
                0x025A: 'METATILE_LilycoveMuseum_Painting0_Left',
                0x025B: 'METATILE_LilycoveMuseum_Painting0_Right',
                0x025C: 'METATILE_LilycoveMuseum_Painting1_Left',
                0x025D: 'METATILE_LilycoveMuseum_Painting1_Right',
                0x025E: 'METATILE_LilycoveMuseum_Painting2_Left',
                0x025F: 'METATILE_LilycoveMuseum_Painting2_Right',
                0x0260: 'METATILE_LilycoveMuseum_Painting3_Left',
                0x0261: 'METATILE_LilycoveMuseum_Painting3_Right',
                0x0262: 'METATILE_LilycoveMuseum_Painting4_Left',
                0x0263: 'METATILE_LilycoveMuseum_Painting4_Right',
            },
            'decorations': {0x002C: 'DECOR_GLASS_ORNAMENT'},
            'contest_winners': {
                0x09: 'CONTEST_WINNER_MUSEUM_COOL',
                0x0A: 'CONTEST_WINNER_MUSEUM_BEAUTY',
                0x0B: 'CONTEST_WINNER_MUSEUM_CUTE',
                0x0C: 'CONTEST_WINNER_MUSEUM_SMART',
                0x0D: 'CONTEST_WINNER_MUSEUM_TOUGH',
            },
            'fade_modes': {0x1: 'FADE_TO_BLACK'},
        },
    },
})

# Contest Lobby's 105 script/table entry points are populated from its
# reviewed US sequence above.  These local text and movement address maps are
# intentionally explicit because the JP source ends at 0x08207640, before the
# following raw owner contains the remaining NPC text records.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_ContestLobby': {
        'texts': {
            0x082073D0: 'LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase',
            0x082073F8: 'LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries',
            0x08207435: 'LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint',
            0x082074A1: 'LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum',
            0x08207519: 'LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum',
            0x0820757C: 'LilycoveCity_ContestLobby_Text_TakeMementoOfPainting',
            0x082075A5: 'LilycoveCity_ContestLobby_Text_ReceivedARibbon',
            0x082075B4: 'LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon',
            0x082075CA: 'LilycoveCity_ContestLobby_Text_OkaySeeYou',
            0x082075D1: 'LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum',
            0x0820760A: 'LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs',
        },
        # All old gJPText_* labels are local-only address placeholders.  The
        # semantic names above replace them rather than retaining aliases.
        'preserve_region_text_aliases': False,
        'field_placeholders': {
            # The paired US ribbon messages prove FD 01 is the player and FD
            # 02 is STR_VAR_1 here; do not retain the ambiguous STRING form.
            0x082075A5: {0x01: 'PLAYER'},
            0x082075B4: {0x01: 'PLAYER', 0x02: 'STR_VAR_1'},
        },
        'external_labels': {
            0x0821DD5F: 'LilycoveCity_ContestLobby_EventScript_SetPlayerGfx',
            0x082423E9: 'Common_EventScript_SaveGame',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x08243625: 'Common_Movement_FaceOriginalDirection',
            0x08248AF4: 'LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist',
            0x08249BC1: 'LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer',
            0x08253F43: 'LilycoveCity_ContestLobby_EventScript_TryShowContestReporter',
        },
        # These map-owned NPC strings and shared contest/blender strings live
        # outside the physical Contest Lobby owner.  Their semantic aliases
        # are exported by the following top-level raw owner until it is
        # structured in its own address-order pass.
        'external_texts': {
            0x08207640: 'LilycoveCity_ContestLobby_Text_MasterRankHereICome',
            0x08207692: 'LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere',
            0x082076BA: 'LilycoveCity_ContestLobby_Text_ContestFeastForEyes',
            0x082076E6: 'LilycoveCity_ContestLobby_Text_ToughContestIsExtreme',
            0x0820771C: 'LilycoveCity_ContestLobby_Text_LavishedCareOnMon',
            0x0820775B: 'LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily',
            0x08247D67: 'Text_LinkErrorPleaseReset',
            0x08249FDD: 'LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank',
            0x0824A10A: 'LilycoveCity_ContestLobby_Text_ComeThroughHere',
            0x0824A50F: 'LilycoveCity_ContestLobby_Text_ProgressWillBeSaved',
            0x0824A52D: 'LilycoveCity_ContestLobby_Text_ParticipateAnotherTime',
            0x0824A60C: 'LilycoveCity_ContestLobby_Text_Transmitting',
            0x0824A619: 'LilycoveCity_ContestLobby_Text_TransmissionError',
            0x0824A629: 'LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest',
            0x0824A646: 'LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice',
            0x0824A65D: 'LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel',
            0x0824A6AA: 'LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX',
            0x0824A6E8: 'LilycoveCity_ContestLobby_Text_ContestBeginShortly',
            0x0824A6FB: 'LilycoveCity_ContestLobby_Text_LinkContestReception',
            0x0824A734: 'LilycoveCity_ContestLobby_Text_WhichTopic2',
            0x0824A744: 'LilycoveCity_ContestLobby_Text_EnterContest3',
            0x0824A755: 'LilycoveCity_ContestLobby_Text_EnterWhichContest3',
            0x0824A769: 'LilycoveCity_ContestLobby_Text_MonInNoCondition2',
            0x0824A790: 'LilycoveCity_ContestLobby_Text_EggCannotTakePart2',
            0x0824A7AE: 'LilycoveCity_ContestLobby_Text_EnterWhichPokemon3',
            0x0824A7C2: 'LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader',
            0x0824A801: 'LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode',
            0x0824A86C: 'LilycoveCity_ContestLobby_Text_ExplainLinkContest',
            0x0824A9B5: 'LilycoveCity_ContestLobby_Text_ExplainEMode',
            0x0824AA8A: 'LilycoveCity_ContestLobby_Text_ExplainGMode',
            0x0824AB11: 'LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode',
            0x0824AB68: 'LilycoveCity_ContestLobby_Text_WhichContestMode',
            0x082587AE: 'BerryBlender_Text_LetsGetBlendingAlready',
            0x082587BA: 'BerryBlender_Text_WhatKindOfPokeblockWillIGet',
            0x08274705: 'BerryBlender_Text_BlendWithTheBlendMaster',
            0x0827495B: 'BerryBlender_Text_WhoaAwesome',
            0x08274961: 'BerryBlender_Text_WickedlyFast',
            0x08274966: 'BerryBlender_Text_WhatAnExpert',
            0x0827496C: 'BerryBlender_Text_MadeAmazingPokeblocksWithMaster',
            0x08274990: 'BerryBlender_Text_QualitiesOfBlendMaster',
            0x082749E1: 'BerryBlender_Text_MasterWorksOnSkillsInMountains',
        },
        'specials': {
            'sub_080F8C14': 'BufferContestWinnerMonName',
            'sub_080F8D34': 'GetContestPlayerId',
            'sub_080F916C': 'SaveMuseumContestPainting',
            'sub_080F938C': 'SetLinkContestPlayerGfx',
            'sub_080F95B4': 'IsContestDebugActive',
            'sub_080F99E4': 'ClearLinkContestFlags',
            'sub_080F87C0': 'TryEnterContestMon',
            'CountPlayerContestPaintings': 'CountPlayerMuseumPaintings',
            'BerryBlenderLinkBecomeLeader': 'TryBecomeLinkLeader',
            'BerryBlenderLinkJoinGroup': 'TryJoinLinkGroup',
        },
        'symbols': {
            'flags': {
                0x005F: 'FLAG_RECEIVED_POKEBLOCK_CASE',
                0x00A0: 'FLAG_COOL_PAINTING_MADE',
                0x00A1: 'FLAG_BEAUTY_PAINTING_MADE',
                0x00A2: 'FLAG_CUTE_PAINTING_MADE',
                0x00A3: 'FLAG_SMART_PAINTING_MADE',
                0x00A4: 'FLAG_TOUGH_PAINTING_MADE',
                0x0155: 'FLAG_ENTERED_CONTEST',
                0x0307: 'FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR',
                0x0308: 'FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1',
                0x0309: 'FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2',
                0x030A: 'FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3',
                0x030B: 'FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4',
                0x030C: 'FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS',
                0x0340: 'FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER',
                0x0369: 'FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT',
                0x089B: 'FLAG_SYS_RIBBON_GET',
            },
            'vars': {
                0x400C: 'VAR_TEMP_C',
                0x400D: 'VAR_TEMP_D',
                0x4086: 'VAR_CONTEST_HALL_STATE',
                0x4088: 'VAR_CONTEST_TYPE',
                0x4094: 'VAR_LILYCOVE_MUSEUM_2F_STATE',
                0x4099: 'VAR_LILYCOVE_CONTEST_LOBBY_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8008: 'VAR_0x8008',
                0x800B: 'VAR_0x800B',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
                0x8010: 'VAR_CONTEST_RANK',
                0x8011: 'VAR_CONTEST_CATEGORY',
            },
            'local_ids': {
                0x01: 'LOCALID_CONTEST_LOBBY_RECEPTIONIST',
                0x02: 'LOCALID_CONTEST_LOBBY_LINK_RECEPTIONIST',
                0x04: 'LOCALID_CONTEST_LOBBY_ARTIST',
                0x0B: 'LOCALID_CONTEST_LOBBY_LINK_ARTIST',
                0xFF: 'LOCALID_PLAYER',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'pokenews': {0x4: 'POKENEWS_BLENDMASTER'},
            'items': {0x010A: 'ITEM_CONTEST_PASS'},
            'songs': {0x0172: 'MUS_OBTAIN_ITEM'},
            'sounds': {0x0015: 'SE_PIN', 0x0047: 'SE_BRIDGE_WALK'},
            'game_stats': {0x2A: 'GAME_STAT_RECEIVED_RIBBONS'},
            'fade_modes': {0x1: 'FADE_TO_BLACK'},
            'contest_winners': {
                0x0: 'CONTEST_WINNER_ARTIST',
                0x1: 'CONTEST_WINNER_HALL_1',
                0x2: 'CONTEST_WINNER_HALL_2',
                0x3: 'CONTEST_WINNER_HALL_3',
                0x4: 'CONTEST_WINNER_HALL_4',
                0x5: 'CONTEST_WINNER_HALL_5',
                0x6: 'CONTEST_WINNER_HALL_6',
            },
            'maps': {
                0x1923: 'MAP_CONTEST_HALL_BEAUTY',
                0x1924: 'MAP_CONTEST_HALL_TOUGH',
                0x1925: 'MAP_CONTEST_HALL_COOL',
                0x1926: 'MAP_CONTEST_HALL_SMART',
                0x1927: 'MAP_CONTEST_HALL_CUTE',
            },
            'metatiles': {
                0x0221: 'METATILE_Contest_WallShadow',
                0x0261: 'METATILE_Contest_FloorShadow',
                0x02D1: 'METATILE_Contest_CounterFlap_Top',
                0x02D9: 'METATILE_Contest_CounterFlap_Bottom',
            },
            'multichoices': {
                0x02: 'MULTI_ENTERINFO',
                0x04: 'MULTI_CONTEST_TYPE',
                0x51: 'MULTI_LINK_LEADER',
                0x54: 'MULTI_LINK_CONTEST_INFO',
                0x55: 'MULTI_LINK_CONTEST_MODE',
            },
            'frontier_results': {
                # The reviewed Link Contest result sequence is the exact
                # frontier_results FACILITY_LINK_CONTEST macro expansion.
                (0x7, 0x7): 'FACILITY_LINK_CONTEST',
            },
            'var_values': {
                0x4088: {
                    0x1: 'CONTEST_TYPE_NPC_NORMAL',
                    0x2: 'CONTEST_TYPE_NPC_SUPER',
                    0x3: 'CONTEST_TYPE_NPC_HYPER',
                    0x4: 'CONTEST_TYPE_NPC_MASTER',
                    0x5: 'CONTEST_TYPE_LINK',
                },
                0x8010: {
                    0x0: 'CONTEST_RANK_NORMAL',
                    0x1: 'CONTEST_RANK_SUPER',
                    0x2: 'CONTEST_RANK_HYPER',
                    0x3: 'CONTEST_RANK_MASTER',
                },
                0x8011: {
                    0x0: 'CONTEST_CATEGORY_COOL',
                    0x1: 'CONTEST_CATEGORY_BEAUTY',
                    0x2: 'CONTEST_CATEGORY_CUTE',
                    0x3: 'CONTEST_CATEGORY_SMART',
                    0x4: 'CONTEST_CATEGORY_TOUGH',
                },
            },
            'switch_values': {
                'VAR_RESULT': {
                    0x5: 'CONTEST_CATEGORIES_COUNT',
                    0x7F: 'MULTI_B_PRESSED',
                },
            },
            'script_var_values': {
                0x0820704C: {
                    0x800D: {
                        0x0: 'CANT_ENTER_CONTEST',
                        0x1: 'CAN_ENTER_CONTEST_EQUAL_RANK',
                        0x2: 'CAN_ENTER_CONTEST_HIGH_RANK',
                        0x3: 'CANT_ENTER_CONTEST_EGG',
                        0x4: 'CANT_ENTER_CONTEST_FAINTED',
                    },
                },
                0x082070D5: {
                    0x800D: {
                        0x3: 'LINKUP_DIFF_SELECTIONS',
                        0x4: 'LINKUP_WRONG_NUM_PLAYERS',
                        0x5: 'LINKUP_FAILED',
                        0x6: 'LINKUP_CONNECTION_ERROR',
                        0xA: 'LINKUP_FAILED_CONTEST_GMODE',
                    },
                },
                0x082072A3: {
                    0x800D: {
                        0x1: 'LINKUP_SUCCESS',
                        0x5: 'LINKUP_FAILED',
                        0x8: 'LINKUP_RETRY_ROLE_ASSIGN',
                    },
                },
                0x082072CB: {
                    0x800D: {
                        0x1: 'LINKUP_SUCCESS',
                        0x5: 'LINKUP_FAILED',
                        0x8: 'LINKUP_RETRY_ROLE_ASSIGN',
                    },
                },
            },
        },
    },
})

# Contest Hall is the next physical map owner after the six shared Contest
# Lobby strings at 0x08207640-0x082077B9.  Its labels are populated by the
# guarded US script/text sequences above; only its JP-local object and common
# movement references need explicit metadata here.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_ContestHall': {
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243625: 'Common_Movement_FaceOriginalDirection',
        },
        'symbols': {
            'local_ids': {
                0x04: 'LOCALID_SMART_MC',
                0x05: 'LOCALID_SMART_JUDGE',
                0x06: 'LOCALID_SMART_CONTESTANT_1',
                0x07: 'LOCALID_SMART_CONTESTANT_2',
                0x08: 'LOCALID_SMART_CONTESTANT_3',
                0x09: 'LOCALID_SMART_CONTESTANT_4',
                0x0B: 'LOCALID_SMART_AUDIENCE_4',
                0x0C: 'LOCALID_SMART_AUDIENCE_2',
                0x0D: 'LOCALID_BEAUTY_MC',
                0x0E: 'LOCALID_BEAUTY_JUDGE',
                0x0F: 'LOCALID_BEAUTY_CONTESTANT_1',
                0x10: 'LOCALID_BEAUTY_CONTESTANT_2',
                0x11: 'LOCALID_BEAUTY_CONTESTANT_3',
                0x12: 'LOCALID_BEAUTY_CONTESTANT_4',
                0x13: 'LOCALID_BEAUTY_AUDIENCE_1',
                0x14: 'LOCALID_BEAUTY_AUDIENCE_3',
                0x15: 'LOCALID_BEAUTY_AUDIENCE_2',
                0x16: 'LOCALID_SMART_AUDIENCE_3',
                0x17: 'LOCALID_CUTE_MC',
                0x18: 'LOCALID_CUTE_JUDGE',
                0x19: 'LOCALID_CUTE_CONTESTANT_1',
                0x1A: 'LOCALID_CUTE_CONTESTANT_2',
                0x1B: 'LOCALID_CUTE_CONTESTANT_3',
                0x1C: 'LOCALID_CUTE_CONTESTANT_4',
                0x1D: 'LOCALID_CUTE_AUDIENCE_1',
                0x1E: 'LOCALID_CUTE_AUDIENCE_3',
                0x1F: 'LOCALID_CUTE_AUDIENCE_2',
            },
        },
    },
})

# Pokemon Center 1F directly follows Contest Hall in physical EventScript
# order. Its eight local script entries and three text records are guarded by
# the reviewed US sequences above; these entries name only the JP-specific
# external calls and numeric operands needed to render that source faithfully.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_PokemonCenter_1F': {
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x082429B8: 'Common_EventScript_PkmnCenterNurse',
            0x0824790F: 'CableClub_OnResume',
            0x08264373: 'LilycoveCity_PokemonCenter_1F_EventScript_LilycoveLady',
            0x082649CF: 'LilycoveCity_PokemonCenter_1F_EventScript_ContestLadyMon',
        },
        'specials': {
            'sub_0818D6EC': 'SetLilycoveLadyGfx',
        },
        'symbols': {
            'flags': {
                0x03E1: 'FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON',
                0x086D: 'FLAG_BADGE07_GET',
            },
            'vars': {
                0x800B: 'VAR_0x800B',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {0x01: 'LOCALID_LILYCOVE_NURSE'},
            'heal_locations': {0x08: 'HEAL_LOCATION_LILYCOVE_CITY'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# The following 2F map owner contains four Cable Club hooks and three
# RS-era wrappers. The wrappers exactly fill the raw 0x0820838B-0x0820839D
# suffix and use the matching US names guarded by the sequence above.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_PokemonCenter_2F': {
        'external_labels': {
            0x082467CD: 'CableClub_OnTransition',
            0x0824686A: 'CableClub_OnWarp',
            0x082468BC: 'CableClub_OnLoad',
            0x08246939: 'CableClub_OnFrame',
            0x08246BB2: 'CableClub_EventScript_Colosseum',
            0x08246DAD: 'CableClub_EventScript_TradeCenter',
            0x08246ED6: 'CableClub_EventScript_RecordCorner',
        },
    },
})

# Lilycove's Trainer Fan Club is the next full EventScript owner after the
# unused Mart. Its JP and US entry/text sequences were audited one-to-one;
# this metadata only supplies contextual constants and references that the
# JP bytes alone cannot name safely.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_PokemonTrainerFanClub': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08242F08: 'Common_ShowEasyChatScreen',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'external_texts': {
            0x0824DE14: 'LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer',
            0x0824DE37: 'LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink',
            0x0824DE51: 'LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer',
            0x0824DE64: 'LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2',
            0x0824DE82: 'LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer',
            0x0824DEA3: 'LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2',
            0x0824DEB6: 'LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer',
            0x0824DEE0: 'LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo',
            0x0824DF29: 'LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial',
        },
        'specials': {
            'ShouldMoveLilycoveFanClubMember': 'IsFanClubMemberFanOfPlayer',
            'GetNumMovedLilycoveFanClubMembers': 'GetNumFansOfPlayerInTrainerFanClub',
            'BufferStreakTrainerText': 'BufferFanClubTrainerName',
            'UpdateMovedLilycoveFanClubMembers': 'TryLoseFansFromPlayTime',
            'sub_080EF244': 'TryPutTrainerFanClubOnAir',
            'sub_080EF2D8': 'ShouldHideFanClubInterviewer',
            'sub_0813A164': 'ShowScrollableMultichoice',
        },
        'field_placeholders': {
            0x08208B19: {0x01: 'PLAYER'},
            0x08208B22: {0x01: 'PLAYER'},
            0x08208BEC: {0x01: 'PLAYER'},
            0x08208C00: {0x01: 'PLAYER'},
            0x08208C38: {0x02: 'STR_VAR_1'},
            0x08208C7A: {0x02: 'STR_VAR_1'},
            0x08208CE8: {0x01: 'PLAYER'},
            0x08208FA5: {0x01: 'PLAYER'},
            0x08208FC6: {0x01: 'PLAYER'},
            0x08209015: {0x02: 'STR_VAR_1'},
            0x08209039: {0x02: 'STR_VAR_1'},
            0x082090AC: {0x01: 'PLAYER'},
            0x082090DB: {0x01: 'PLAYER'},
            0x08209116: {0x02: 'STR_VAR_1'},
            0x08209134: {0x02: 'STR_VAR_1'},
            0x0820917D: {0x01: 'PLAYER'},
            0x08209216: {0x02: 'STR_VAR_1'},
            0x0820926D: {0x02: 'STR_VAR_1'},
            0x08209340: {0x02: 'STR_VAR_1'},
            0x0820938D: {0x02: 'STR_VAR_1'},
        },
        'symbols': {
            'flags': {
                0x00D2: 'FLAG_FAN_CLUB_STRENGTH_SHARED',
                0x02DA: 'FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER',
            },
            'vars': {
                0x4095: 'VAR_LILYCOVE_FAN_CLUB_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8006: 'VAR_0x8006',
                0x800A: 'VAR_0x800A',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {
                0x01: 'LOCALID_TRAINER_FAN_CLUB_LASS',
                0x02: 'LOCALID_TRAINER_FAN_CLUB_MAN',
                0x03: 'LOCALID_TRAINER_FAN_CLUB_POKEFAN_M',
                0x04: 'LOCALID_TRAINER_FAN_CLUB_LITTLE_GIRL',
                0x05: 'LOCALID_TRAINER_FAN_CLUB_NINJA_BOY',
                0x06: 'LOCALID_TRAINER_FAN_CLUB_BOY',
                0x07: 'LOCALID_TRAINER_FAN_CLUB_WOMAN',
                0x08: 'LOCALID_TRAINER_FAN_CLUB_EXPERT_F',
                0xFF: 'LOCALID_PLAYER',
            },
            'script_var_values': {
                0x08208442: {
                    0x8004: {0x8: 'FANCLUB_MEMBER1', 0x9: 'FANCLUB_MEMBER2', 0xA: 'FANCLUB_MEMBER3', 0xB: 'FANCLUB_MEMBER4', 0xC: 'FANCLUB_MEMBER5', 0xD: 'FANCLUB_MEMBER6', 0xE: 'FANCLUB_MEMBER7', 0xF: 'FANCLUB_MEMBER8'},
                    0x800D: {0x0: 'FALSE'},
                },
                0x082084F3: {0x800D: {0x1: 'TRUE'}},
                0x0820850E: {
                    0x8005: {0x8: 'NUM_TRAINER_FAN_CLUB_MEMBERS'},
                    0x8004: {0x8: 'FANCLUB_MEMBER1', 0x9: 'FANCLUB_MEMBER2', 0xA: 'FANCLUB_MEMBER3', 0xB: 'FANCLUB_MEMBER4', 0xC: 'FANCLUB_MEMBER5', 0xD: 'FANCLUB_MEMBER6', 0xE: 'FANCLUB_MEMBER7', 0xF: 'FANCLUB_MEMBER8'},
                    0x800D: {0x0: 'FALSE'},
                },
                0x08208630: {0x8004: {0xD: 'FANCLUB_MEMBER6'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x082086A7: {0x8004: {0x8: 'FANCLUB_MEMBER1'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x0820871E: {0x8004: {0x9: 'FANCLUB_MEMBER2'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x08208795: {0x8004: {0xA: 'FANCLUB_MEMBER3'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x0820880C: {0x8004: {0xB: 'FANCLUB_MEMBER4'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x0820886E: {0x8004: {0xC: 'FANCLUB_MEMBER5'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x082088D0: {0x8004: {0xE: 'FANCLUB_MEMBER7'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x08208932: {0x8004: {0xF: 'FANCLUB_MEMBER8'}, 0x800D: {0x1: 'TRUE', 0x7: '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'}},
                0x082089A9: {0x8005: {0xB: 'TVSHOW_FAN_CLUB_SPECIAL'}, 0x8004: {0x8: 'FANCLUB_MEMBER1', 0xE: 'EASY_CHAT_TYPE_FAN_QUESTION'}, 0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
                0x08208A07: {0x8004: {0x8: 'FANCLUB_MEMBER1'}, 0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
                0x08208A2E: {0x8004: {0x8: 'FANCLUB_MEMBER1', 0xE: 'EASY_CHAT_TYPE_FAN_QUESTION'}, 0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
                0x08208A66: {0x8004: {0x2: 'SCROLL_MULTI_POKEMON_FAN_CLUB_RATER', 0x8: 'FANCLUB_MEMBER1'}},
                0x08208AB8: {0x8004: {0x8: 'FANCLUB_MEMBER1'}, 0x800D: {0x0: 'FALSE', 0x1: 'TRUE'}},
                0x08208ADF: {0x8004: {0x8: 'FANCLUB_MEMBER1'}},
                0x08208AF1: {0x8004: {0x8: 'FANCLUB_MEMBER1'}},
                0x08208B06: {0x8004: {0x8: 'FANCLUB_MEMBER1'}},
            },
            'switch_values': {
                'VAR_RESULT': {0xB: '11', 0x7F: 'MULTI_B_PRESSED'},
            },
        },
    },
})

# Harbor directly follows the Trainer Fan Club in physical EventScript order.
# Its local control flow, the three otherwise-unreferenced RS scripts, all ten
# movement records, and each local/shared text pointer were checked against
# the matching US Harbor source before these names were allowlisted.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_Harbor': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08243265: 'Common_EventScript_FerryDepart',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
            0x08244178: 'Common_EventScript_NopReturn',
        },
        'external_texts': {
            0x08263476: 'EventTicket_Text_ShowOldSeaMap',
            0x082634B6: 'EventTicket_Text_ThatPass',
            0x082634D5: 'EventTicket_Text_ShowEonTicket',
            0x08263578: 'EventTicket_Text_AsYouLike',
            0x08275C60: 'EventTicket_Text_OldSeaMapTooFar',
            0x08275CB6: 'EventTicket_Text_BrineyHoldOnASecond',
            0x08275CDA: 'EventTicket_Text_BrineyLetsSail',
            0x08275D2A: 'EventTicket_Text_OddTicketGetOnBoard',
            0x08275DF2: 'EventTicket_Text_OddTicketsWhereTo',
        },
        'specials': {
            'display_text_and_get_width_internal': 'ScriptMenu_CreateLilycoveSSTidalMultichoice',
            'sub_080E1D6C': 'GetLilycoveSSTidalSelection',
        },
        'implicit_waitstate_specials': (
            'ScriptMenu_CreateLilycoveSSTidalMultichoice',
        ),
        'field_placeholders': {
            0x08209C16: {0x01: 'PLAYER'},
            0x08209C52: {0x01: 'PLAYER'},
        },
        'symbols': {
            'flags': {
                0x01AE: 'FLAG_SHOWN_EON_TICKET',
                0x01AF: 'FLAG_SHOWN_AURORA_TICKET',
                0x01B0: 'FLAG_SHOWN_OLD_SEA_MAP',
                0x01DB: 'FLAG_SHOWN_MYSTIC_TICKET',
                0x0864: 'FLAG_SYS_GAME_CLEAR',
                0x08B3: 'FLAG_ENABLE_SHIP_SOUTHERN_ISLAND',
                0x08D5: 'FLAG_ENABLE_SHIP_BIRTH_ISLAND',
                0x08D6: 'FLAG_ENABLE_SHIP_FARAWAY_ISLAND',
                0x08E0: 'FLAG_ENABLE_SHIP_NAVEL_ROCK',
            },
            'vars': {
                0x4009: 'VAR_TEMP_9',
                0x400A: 'VAR_TEMP_A',
                0x400B: 'VAR_TEMP_B',
                0x400C: 'VAR_TEMP_C',
                0x400D: 'VAR_TEMP_D',
                0x400E: 'VAR_TEMP_E',
                0x40B4: 'VAR_SS_TIDAL_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'items': {
                0x0113: 'ITEM_EON_TICKET',
                0x0172: 'ITEM_MYSTIC_TICKET',
                0x0173: 'ITEM_AURORA_TICKET',
                0x0178: 'ITEM_OLD_SEA_MAP',
            },
            'maps': {
                0x0005: 'MAP_LILYCOVE_CITY',
                0x0D0A: 'MAP_LILYCOVE_CITY_HARBOR',
                0x1929: 'MAP_SS_TIDAL_CORRIDOR',
                0x1A04: 'MAP_BATTLE_FRONTIER_OUTSIDE_WEST',
                0x1A09: 'MAP_SOUTHERN_ISLAND_EXTERIOR',
                0x1A38: 'MAP_FARAWAY_ISLAND_ENTRANCE',
                0x1A3B: 'MAP_BIRTH_ISLAND_HARBOR',
                0x1A43: 'MAP_NAVEL_ROCK_HARBOR',
            },
            'local_ids': {
                0x01: 'LOCALID_LILYCOVE_HARBOR_ATTENDANT',
                0x02: 'LOCALID_LILYCOVE_HARBOR_SS_TIDAL',
                0x04: 'LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR',
                0x05: 'LOCALID_LILYCOVE_HARBOR_BRINEY',
                0xFF: 'LOCALID_PLAYER',
            },
            'sounds': {0x15: 'SE_PIN'},
            'var_values': {
                0x40B4: {0x5: 'SS_TIDAL_BOARD_LILYCOVE'},
                0x8004: {0x2: 'LOCALID_LILYCOVE_HARBOR_SS_TIDAL'},
                0x800C: {0x2: 'DIR_NORTH', 0x4: 'DIR_EAST'},
            },
            'switch_values': {
                'VAR_RESULT': {0x7F: 'MULTI_B_PRESSED'},
            },
        },
    },
})

# Move Deleter's House is the immediate next map owner after Harbor. Its
# seven scripts and nine text records were checked in physical order against
# the matching US source; only contextual operands need map-local metadata.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_MoveDeletersHouse': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08243621: 'Common_Movement_FacePlayer',
        },
        'field_placeholders': {
            0x08209EC8: {0x02: 'STR_VAR_1'},
            0x08209EE2: {0x02: 'STR_VAR_1', 0x03: 'STR_VAR_2'},
            0x08209EF1: {0x02: 'STR_VAR_1', 0x03: 'STR_VAR_2'},
            0x08209F4A: {0x02: 'STR_VAR_1'},
        },
        'symbols': {
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x800D: 'VAR_RESULT',
            },
            'local_ids': {0x01: 'LOCALID_MOVE_DELETER'},
            'songs': {0x017A: 'MUS_MOVE_DELETED'},
            'fade_modes': {0x0: 'FADE_FROM_BLACK', 0x1: 'FADE_TO_BLACK'},
            'var_values': {
                0x8004: {0xFF: 'PARTY_NOTHING_CHOSEN'},
                0x8005: {0x4: 'MAX_MON_MOVES'},
            },
            'switch_values': {
                'VAR_RESULT': {0x0: 'NO', 0x1: 'YES'},
            },
        },
    },
})

# House1 immediately follows Move Deleter's House. Its two scripts and two
# text records match the US source in physical order. The JP command-table
# slots for waitdooranim/waitmoncry are swapped, so only the audited Kecleon
# cry site uses the dedicated byte-exact semantic macro.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_House1': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'command_aliases': {
            0x08209F70: {'waitdooranim': 'waitmoncry_jp'},
        },
        'symbols': {
            'species': {0x013D: 'SPECIES_KECLEON'},
            'cry_modes': {0x0: 'CRY_MODE_NORMAL'},
        },
    },
})

# House2 follows House1 in physical EventScript order. Its item gift, flag,
# and text sequence match the corresponding US map source one-to-one.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_House2': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
        },
        'symbols': {
            'flags': {0x00EA: 'FLAG_RECEIVED_TM_REST'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800D: 'VAR_RESULT',
            },
            'items': {0x014C: 'ITEM_TM_REST'},
        },
    },
})

# House3 follows House2 in physical EventScript order. Its transition handler,
# six object handlers, shared result branches, and eight text records are
# checked one-to-one against the matching US map source.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_House3': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08243625: 'Common_Movement_FaceOriginalDirection',
        },
        'symbols': {
            'vars': {
                0x4001: 'VAR_TEMP_1',
                0x8000: 'VAR_0x8000',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'switch_values': {
                'VAR_RESULT': {0x0: 'NO', 0x1: 'YES'},
            },
        },
    },
})

# Department Store 2F is the first owner in the still-visible 0x20A920 raw
# range. Its five entry scripts, two shop lists, and three local texts match
# the US map source in physical order.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStore_2F': {
        'scripts': {
            0x0820A921: 'LilycoveCity_DepartmentStore_2F_EventScript_Cook',
            0x0820A92A: 'LilycoveCity_DepartmentStore_2F_EventScript_PokefanF',
            0x0820A933: 'LilycoveCity_DepartmentStore_2F_EventScript_Sailor',
            0x0820A93C: 'LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft',
            0x0820A96E: 'LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight',
        },
        'texts': {
            0x0820A9A0: 'LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly',
            0x0820A9C7: 'LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband',
            0x0820A9EB: 'LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
        },
    },
})

# Department Store 3F immediately follows 2F in the same raw owner. Its two
# clerks, three NPCs, two shop lists, and three texts match the US map source
# in physical order.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStore_3F': {
        'scripts': {
            0x0820AA1A: 'LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft',
            0x0820AA44: 'LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight',
            0x0820AA6E: 'LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM',
            0x0820AA77: 'LilycoveCity_DepartmentStore_3F_EventScript_PokefanM',
            0x0820AA80: 'LilycoveCity_DepartmentStore_3F_EventScript_Woman',
        },
        'texts': {
            0x0820AA89: 'LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon',
            0x0820AADA: 'LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance',
            0x0820AB2C: 'LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
        },
    },
})

# Department Store 4F immediately follows 3F. Its two clerks, three NPCs,
# two TM shop lists, and three texts match the US map source in physical order.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStore_4F': {
        'scripts': {
            0x0820AB4F: 'LilycoveCity_DepartmentStore_4F_EventScript_Gentleman',
            0x0820AB58: 'LilycoveCity_DepartmentStore_4F_EventScript_Woman',
            0x0820AB61: 'LilycoveCity_DepartmentStore_4F_EventScript_Youngster',
            0x0820AB6A: 'LilycoveCity_DepartmentStore_4F_EventScript_ClerkLeft',
            0x0820AB90: 'LilycoveCity_DepartmentStore_4F_EventScript_ClerkRight',
        },
        'texts': {
            0x0820ABB4: 'LilycoveCity_DepartmentStore_4F_Text_AttackOrDefenseTM',
            0x0820ABF1: 'LilycoveCity_DepartmentStore_4F_Text_FiftyDifferentTMs',
            0x0820AC28: 'LilycoveCity_DepartmentStore_4F_Text_PokemonOnlyHaveFourMoves',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
        },
    },
})

# Department Store 5F follows 4F in the physical EventScript stream. Its
# weather gate, four decoration clerks, two NPCs, four decoration lists, and
# four local texts match the US map source in physical order.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStore_5F': {
        'scripts': {
            0x0820AC6E: 'LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs',
            0x0820AC7A: 'LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft',
            0x0820ACB0: 'LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft',
            0x0820ACDE: 'LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight',
            0x0820AD0E: 'LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight',
            0x0820AD40: 'LilycoveCity_DepartmentStore_5F_EventScript_PokefanF',
            0x0820AD49: 'LilycoveCity_DepartmentStore_5F_EventScript_Woman',
            0x0820AD70: 'LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal',
            0x0820AD7B: 'LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather',
            0x0820AD90: 'LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl',
        },
        'tables': {
            0x0820AC54: 'LilycoveCity_DepartmentStore_5F_OnWarp',
        },
        'texts': {
            0x0820AD99: 'LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls',
            0x0820ADD5: 'LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon',
            0x0820ADFE: 'LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere',
            0x0820AE30: 'LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
        },
        'symbols': {
            'vars': {0x405E: 'VAR_SOOTOPOLIS_CITY_STATE'},
            'local_ids': {0x7: 'LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN'},
            'directions': {0x2: 'DIR_NORTH'},
        },
    },
})

# The Rooftop follows Department Store 5F in the physical EventScript stream.
# Its sale, vending machine, and local text records were checked against the
# matching US map in physical order; its source boundary stops before the
# separate Department Store Elevator owner at 0x0820B18C.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStoreRooftop': {
        'scripts': {
            0x0820AE59: 'LilycoveCity_DepartmentStoreRooftop_OnTransition',
            0x0820AE73: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman',
            0x0820AE77: 'LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman',
            0x0820AE7B: 'LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman',
            0x0820AEB4: 'LilycoveCity_DepartmentStoreRooftop_EventScript_Man',
            0x0820AECE: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale',
            0x0820AED8: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan',
            0x0820AEE1: 'LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine',
            0x0820AEF2: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink',
            0x0820AF30: 'LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater',
            0x0820AF3B: 'LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop',
            0x0820AF46: 'LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade',
            0x0820AF51: 'LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater',
            0x0820AF58: 'LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop',
            0x0820AF5F: 'LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade',
            0x0820AF66: 'LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater',
            0x0820AF6D: 'LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop',
            0x0820AF74: 'LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade',
            0x0820AF7B: 'LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink',
            0x0820B082: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink',
            0x0820B08E: 'LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink',
            0x0820B09C: 'LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink',
            0x0820B0AA: 'LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine',
        },
        'texts': {
            0x0820B0AF: 'LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales',
            0x0820B0EA: 'LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale',
            0x0820B120: 'LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty',
            0x0820B12E: 'LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike',
            0x0820B14A: 'LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown',
            0x0820B159: 'LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown',
            0x0820B175: 'LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney',
            0x0820B180: 'LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink',
        },
        # The vending sequence writes the selected drink into STR_VAR_1
        # before each message.  The JP byte 0x02 therefore has the same
        # concrete meaning as the matching US text's {STR_VAR_1} control.
        'field_placeholders': {
            0x0820B14A: {0x02: 'STR_VAR_1'},
            0x0820B159: {0x02: 'STR_VAR_1'},
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
            0x08243947: 'gText_TheBagIsFull',
            0x08243953: 'gText_PutItemInPocket',
            0x08276AA2: 'LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor',
        },
        'symbols': {
            'flags': {
                0x03C2: 'FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN',
            },
            'vars': {
                0x4000: 'VAR_TEMP_0',
                0x4001: 'VAR_TEMP_1',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x800D: {0x0: 'FALSE', 0x1: 'TRUE'},
            },
            'items': {
                0x001A: 'ITEM_FRESH_WATER',
                0x001B: 'ITEM_SODA_POP',
                0x001C: 'ITEM_LEMONADE',
            },
            'pokenews': {0x3: 'POKENEWS_LILYCOVE'},
            'multichoices': {0x2A: 'MULTI_VENDING_MACHINE'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'sounds': {0x006A: 'SE_VEND'},
            'stdstrings': {0xE: 'STDSTRING_ITEMS'},
        },
    },
})

# The Elevator begins at the next physical owner after the Rooftop.  Its
# branch sequence, dynamic map IDs, and floor variables match the matching
# pokeemerald source in physical 1F-to-5F order.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'LilycoveCity_DepartmentStoreElevator': {
        'scripts': {
            0x0820B18D: 'LilycoveCity_DepartmentStoreElevator_EventScript_Attendant',
            0x0820B1F2: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom5th',
            0x0820B1FE: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom4th',
            0x0820B20A: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom3rd',
            0x0820B216: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom2nd',
            0x0820B222: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloorFrom1st',
            0x0820B22E: 'LilycoveCity_DepartmentStoreElevator_EventScript_ChooseFloor',
            0x0820B281: 'LilycoveCity_DepartmentStoreElevator_EventScript_1stFloor',
            0x0820B2A9: 'LilycoveCity_DepartmentStoreElevator_EventScript_2ndFloor',
            0x0820B2D1: 'LilycoveCity_DepartmentStoreElevator_EventScript_3rdFloor',
            0x0820B2F9: 'LilycoveCity_DepartmentStoreElevator_EventScript_4thFloor',
            0x0820B321: 'LilycoveCity_DepartmentStoreElevator_EventScript_5thFloor',
            0x0820B349: 'LilycoveCity_DepartmentStoreElevator_EventScript_ExitFloorSelect',
            0x0820B34E: 'LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator',
            0x0820B365: 'LilycoveCity_DepartmentStoreElevator_EventScript_SetFloor',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x08243A47: 'gText_WhichFloorWouldYouLike',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'specials': {
            'sub_08139BD4': 'ShowDeptStoreElevatorFloorSelect',
            'sub_08139A68': 'GetDeptStoreDefaultFloorChoice',
            'sub_08139C4C': 'CloseDeptStoreElevatorWindow',
            'ShakeScreenInElevator': 'MoveElevator',
            'SetDepartmentStoreFloorVar': 'SetDeptStoreFloor',
        },
        'symbols': {
            'flags': {0x0002: 'FLAG_TEMP_2'},
            'vars': {
                0x4043: 'VAR_DEPT_STORE_FLOOR',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x8006: 'VAR_0x8006',
                0x800D: 'VAR_RESULT',
            },
            'maps': {
                0x0D10: 'MAP_LILYCOVE_CITY_DEPARTMENT_STORE_1F',
                0x0D11: 'MAP_LILYCOVE_CITY_DEPARTMENT_STORE_2F',
                0x0D12: 'MAP_LILYCOVE_CITY_DEPARTMENT_STORE_3F',
                0x0D13: 'MAP_LILYCOVE_CITY_DEPARTMENT_STORE_4F',
                0x0D14: 'MAP_LILYCOVE_CITY_DEPARTMENT_STORE_5F',
            },
            'local_ids': {0x800F: 'VAR_LAST_TALKED'},
            'multichoices': {0x0039: 'MULTI_FLOORS'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
            'switch_values': {
                'VAR_RESULT': {0x7F: 'MULTI_B_PRESSED'},
            },
            'script_var_values': {
                0x0820B281: {
                    0x8006: {0x4: 'DEPT_STORE_FLOORNUM_1F'},
                    0x4043: {0x4: 'DEPT_STORE_FLOORNUM_1F'},
                },
                0x0820B2A9: {
                    0x8006: {0x5: 'DEPT_STORE_FLOORNUM_2F'},
                    0x4043: {0x5: 'DEPT_STORE_FLOORNUM_2F'},
                },
                0x0820B2D1: {
                    0x8006: {0x6: 'DEPT_STORE_FLOORNUM_3F'},
                    0x4043: {0x6: 'DEPT_STORE_FLOORNUM_3F'},
                },
                0x0820B2F9: {
                    0x8006: {0x7: 'DEPT_STORE_FLOORNUM_4F'},
                    0x4043: {0x7: 'DEPT_STORE_FLOORNUM_4F'},
                },
                0x0820B321: {
                    0x8006: {0x8: 'DEPT_STORE_FLOORNUM_5F'},
                    0x4043: {0x8: 'DEPT_STORE_FLOORNUM_5F'},
                },
            },
        },
    },
})

# Mossdeep Gym immediately follows the Department Store Elevator in the JP
# event-script stream. The map's RS-era switch scripts remain byte-exact but
# are named after the matching US source; its one player field placeholder is
# checked against the corresponding US text rather than retained generically.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_Gym': {
        'scripts': {
            0x0820B36F: 'MossdeepCity_Gym_OnLoad',
        },
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'field_placeholders': {
            0x0820B83E: {0x01: 'PLAYER'},
            0x0820BF61: {0x01: 'PLAYER'},
            0x0820C162: {0x01: 'PLAYER'},
        },
        'external_labels': {
            0x08242FCF: 'Common_EventScript_SetGymTrainers',
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x082430EA: 'Common_EventScript_BagIsFull',
            0x0824310A: 'Common_EventScript_PlayGymBadgeFanfare',
        },
        'symbols': {
            'flags': {
                0x0064: 'FLAG_MOSSDEEP_GYM_SWITCH_1',
                0x0065: 'FLAG_MOSSDEEP_GYM_SWITCH_2',
                0x0066: 'FLAG_MOSSDEEP_GYM_SWITCH_3',
                0x0067: 'FLAG_MOSSDEEP_GYM_SWITCH_4',
                0x00AB: 'FLAG_RECEIVED_TM_CALM_MIND',
                0x01D8: 'FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL',
                0x02F1: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN',
                0x02F4: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA',
                0x0337: 'FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA',
                0x035E: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA',
                0x035F: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN',
                0x0365: 'FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY',
                0x0389: 'FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS',
                0x0393: 'FLAG_UNKNOWN_0x393',
                0x039C: 'FLAG_HIDE_AQUA_HIDEOUT_GRUNTS',
                0x04F6: 'FLAG_DEFEATED_MOSSDEEP_GYM',
                0x086D: 'FLAG_BADGE07_GET',
            },
            'vars': {
                0x405D: 'VAR_MOSSDEEP_CITY_STATE',
                0x409F: 'VAR_MOSSDEEP_SPACE_CENTER_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x8008: 'VAR_0x8008',
                0x800D: 'VAR_RESULT',
            },
            'var_values': {
                0x800D: {0x0: 'FALSE', 0x1: 'TRUE'},
            },
            'items': {0x0124: 'ITEM_TM_CALM_MIND'},
            'trainers': {
                0x00E9: 'TRAINER_PRESTON',
                0x00EA: 'TRAINER_VIRGIL',
                0x00EB: 'TRAINER_BLAKE',
                0x00F4: 'TRAINER_HANNAH',
                0x00F5: 'TRAINER_SAMANTHA',
                0x00F6: 'TRAINER_MAURA',
                0x010F: 'TRAINER_TATE_AND_LIZA_1',
                0x023F: 'TRAINER_SYLVIA',
                0x0246: 'TRAINER_NATE',
                0x0247: 'TRAINER_KATHLEEN',
                0x0248: 'TRAINER_CLIFFORD',
                0x0249: 'TRAINER_NICHOLAS',
                0x024F: 'TRAINER_MACEY',
            },
            'maps': {0x0E00: 'MAP_MOSSDEEP_CITY_GYM'},
            'local_ids': {0x00FF: 'LOCALID_PLAYER'},
            'songs': {0x01CC: 'MUS_REGISTER_MATCH_CALL'},
            'sounds': {
                0x0023: 'SE_SWITCH',
                0x0024: 'SE_CLICK',
                0x002F: 'SE_REPEL',
            },
            'metatiles': {
                0x0204: 'METATILE_RSMossdeepGym_RedArrow_Right',
                0x0205: 'METATILE_RSMossdeepGym_RedArrow_Down',
                0x020C: 'METATILE_RSMossdeepGym_RedArrow_Left',
                0x020D: 'METATILE_RSMossdeepGym_RedArrow_Up',
                0x0238: 'METATILE_RSMossdeepGym_Switch_Up',
                0x0239: 'METATILE_RSMossdeepGym_Switch_Down',
            },
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Mossdeep House 1 follows the Gym range directly. Its two Pokéblock lines
# use the same STR_VAR_1 field control that the matching US source names.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_House1': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'field_placeholders': {
            0x0820C36C: {0x02: 'STR_VAR_1'},
            0x0820C37B: {0x02: 'STR_VAR_1'},
        },
        'symbols': {
            'vars': {0x800D: 'VAR_RESULT'},
            'script_var_values': {
                0x0820C333: {0x800D: {0x0: '0'}},
            },
        },
    },
})

# Mossdeep House 2 follows House 1 directly. The cry wait is emitted through
# the JP byte-exact semantic alias because the JP command-table slots for cry
# and door waits are swapped while the matching US source is waitmoncry.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_House2': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'command_aliases': {
            0x0820C3E5: {'waitdooranim': 'waitmoncry_jp'},
        },
        'symbols': {
            'flags': {
                0x00E0: 'FLAG_WINGULL_DELIVERED_MAIL',
                0x03A5: 'FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL',
            },
            'vars': {0x800C: 'VAR_FACING'},
            'script_var_values': {
                0x0820C3E5: {
                    0x800C: {0x02: 'DIR_NORTH', 0x03: 'DIR_WEST'},
                },
            },
            'species': {0x0135: 'SPECIES_WINGULL'},
            'cry_modes': {0x0: 'CRY_MODE_NORMAL'},
            'local_ids': {0x03: 'LOCALID_MOSSDEEP_HOUSE_WINGULL'},
        },
    },
})

# Mossdeep Pokemon Center 1F is already split, but its pre-existing source
# still uses address labels and raw loadword/callstd text forms.  Keep its
# common scripts explicit so a regenerated map uses the matching US names.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_PokemonCenter_1F': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x082429B8: 'Common_EventScript_PkmnCenterNurse',
            0x0824790F: 'CableClub_OnResume',
        },
        'symbols': {
            'heal_locations': {0x09: 'HEAL_LOCATION_MOSSDEEP_CITY'},
            'vars': {0x800B: 'VAR_0x800B'},
            'local_ids': {0x01: 'LOCALID_MOSSDEEP_NURSE'},
        },
    },
})

# Mossdeep Pokemon Center 2F owns three unused RS Cable Club wrappers and one
# NPC message.  The local JP bytes use the same semantic entry points as the
# matching US source, so retain them as names rather than a map-local incbin.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_PokemonCenter_2F': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x082467CD: 'CableClub_OnTransition',
            0x0824686A: 'CableClub_OnWarp',
            0x082468BC: 'CableClub_OnLoad',
            0x08246939: 'CableClub_OnFrame',
            0x08246BB2: 'CableClub_EventScript_Colosseum',
            0x08246DAD: 'CableClub_EventScript_TradeCenter',
            0x08246ED6: 'CableClub_EventScript_RecordCorner',
        },
    },
})

# Mossdeep Mart uses the shared clerk dialogue around its local product list.
# Retain those cross-map text symbols and give the local scripts and text the
# reviewed US names when regenerating the byte-exact JP source.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_Mart': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'external_labels': {
            0x0824390F: 'gText_HowMayIServeYou',
            0x08243920: 'gText_PleaseComeAgain',
        },
    },
})

# Mossdeep House 3 is the Super Rod gift sequence. The result branch follows
# a local YES/NO message, and the obtaining wrapper is the standard byte-exact
# giveitem macro used by the matching US map source.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_House3': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'symbols': {
            'flags': {0x0098: 'FLAG_RECEIVED_SUPER_ROD'},
            'vars': {
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800D: 'VAR_RESULT',
            },
            'items': {0x0108: 'ITEM_SUPER_ROD'},
        },
    },
})

# Stevens House immediately follows House 3 in the physical EventScript
# stream.  Its 18 script/table records and nine strings align one-to-one with
# the US map source; keep the semantic names and control codes reproducible
# from the JP ROM instead of accepting address-only labels.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_StevensHouse': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        # OnLoad is intentionally excluded from the sequence matcher because
        # existing reviewed maps may already carry that label; retain this
        # direct, ROM-addressed association across fresh emissions.
        'scripts': {
            0x0820C826: 'MossdeepCity_StevensHouse_OnLoad',
        },
        'field_placeholders': {
            0x0820C9C8: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x0820CAF7: {0x01: 'PLAYER'},
            0x0820CB39: {0x01: 'PLAYER'},
            0x0820CB5D: {0x01: 'PLAYER'},
            0x0820CB77: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_labels': {
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x0824423B: 'Common_EventScript_NoMoreRoomForPokemon',
            0x08243EDB: 'gText_NicknameThisPokemon',
            0x082441B5: 'Common_EventScript_GetGiftMonPartySlot',
            0x08243460: 'Common_EventScript_NameReceivedPartyMon',
            0x082441C1: 'Common_EventScript_NameReceivedBoxMon',
            0x082441CA: 'Common_EventScript_TransferredToPC',
        },
        'symbols': {
            'flags': {
                0x0864: 'FLAG_SYS_GAME_CLEAR',
                0x007B: 'FLAG_RECEIVED_HM_DIVE',
                0x012E: 'FLAG_OMIT_DIVE_FROM_STEVEN_LETTER',
                0x0314: 'FLAG_HIDE_MOSSDEEP_CITY_SCOTT',
                0x03AD: 'FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT',
                0x03C8: 'FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL',
                0x012A: 'FLAG_RECEIVED_BELDUM',
            },
            'vars': {
                0x40C6: 'VAR_STEVENS_HOUSE_STATE',
                0x4001: 'VAR_TEMP_TRANSFERRED_SPECIES',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800D: 'VAR_RESULT',
            },
            'script_var_values': {
                0x0820C8F7: {
                    0x4001: {0x018E: 'SPECIES_BELDUM'},
                },
            },
            'items': {0x015A: 'ITEM_HM_DIVE'},
            'species': {0x018E: 'SPECIES_BELDUM'},
            'local_ids': {
                0x01: 'LOCALID_STEVENS_HOUSE_STEVEN',
                0x02: 'LOCALID_STEVENS_HOUSE_BALL',
            },
            'movement_types': {0x07: 'MOVEMENT_TYPE_FACE_UP'},
            'metatiles': {0x02F1: 'METATILE_GenericBuilding_TableEdge'},
            'booleans': {0x00: 'FALSE', 0x01: 'TRUE'},
            'sounds': {0x0015: 'SE_PIN'},
            'songs': {0x0172: 'MUS_OBTAIN_ITEM'},
        },
    },
})

# House 4 starts immediately at the byte following Stevens House. Its five
# scripts and five messages align one-to-one with the US source; the JP cry
# wait uses the existing byte-exact command alias documented for House 2.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_House4': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'command_aliases': {
            0x0820CCA2: {'waitdooranim': 'waitmoncry_jp'},
        },
        'field_placeholders': {
            0x0820CD10: {0x02: 'STR_VAR_1'},
        },
        'symbols': {
            'flags': {0x0864: 'FLAG_SYS_GAME_CLEAR'},
            'vars': {0x800D: 'VAR_RESULT'},
            'var_values': {0x800D: {0x0: 'FALSE'}},
            'species': {0x013B: 'SPECIES_SKITTY'},
            'cry_modes': {0x0: 'CRY_MODE_NORMAL'},
            'booleans': {0x0: 'FALSE'},
        },
    },
})

# Space Center 1F is one complete JP source range from its map-script table
# through the final Team Magma notice. The 34 script entries and 28 texts are
# matched in physical order against the US map source. JP text control bytes
# are mapped only where the surrounding script and matching US text prove the
# placeholder meaning.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_SpaceCenter_1F': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'field_placeholders': {
            0x0820D0D8: {0x02: 'STR_VAR_1'},
            0x0820D126: {0x02: 'STR_VAR_1'},
            0x0820D3DA: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'external_labels': {
            0x082430E0: 'Common_EventScript_ShowBagIsFull',
            0x08243625: 'Common_Movement_FaceOriginalDirection',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
        },
        'symbols': {
            'flags': {
                0x00BF: 'FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F',
                0x00C0: 'FLAG_RECEIVED_SUN_STONE_MOSSDEEP',
                0x0864: 'FLAG_SYS_GAME_CLEAR',
            },
            'vars': {
                0x405D: 'VAR_MOSSDEEP_CITY_STATE',
                0x409E: 'VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE',
                0x8000: 'VAR_0x8000',
                0x8001: 'VAR_0x8001',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'script_var_values': {
                0x0820CDF4: {0x800D: {0x0: '0', 0x1: '1'}},
                0x0820CE40: {0x800D: {0x0: '0', 0x1: '1'}},
                0x0820CEAA: {0x800D: {0x0: 'FALSE'}},
                0x0820CEF6: {0x800D: {0x0: 'FALSE'}},
            },
            'switch_values': {
                'VAR_FACING': {0x3: 'DIR_WEST'},
            },
            'items': {0x005D: 'ITEM_SUN_STONE'},
            'trainers': {
                0x0016: 'TRAINER_GRUNT_SPACE_CENTER_1',
                0x0074: 'TRAINER_GRUNT_SPACE_CENTER_2',
                0x024A: 'TRAINER_GRUNT_SPACE_CENTER_3',
                0x024B: 'TRAINER_GRUNT_SPACE_CENTER_4',
            },
            'local_ids': {
                0x01: 'LOCALID_SPACE_CENTER_1F_SCIENTIST_1',
                0x02: 'LOCALID_SPACE_CENTER_1F_SCIENTIST_2',
                0x03: 'LOCALID_SPACE_CENTER_1F_SAILOR',
                0x04: 'LOCALID_SPACE_CENTER_1F_OLD_MAN',
                0x05: 'LOCALID_SPACE_CENTER_1F_WOMAN',
                0x09: 'LOCALID_SPACE_CENTER_1F_STAIR_GRUNT',
            },
            'movement_types': {0x0A: 'MOVEMENT_TYPE_FACE_RIGHT'},
            'directions': {0x03: 'DIR_WEST'},
            'metatiles': {0x03E4: 'METATILE_Facility_DataPad'},
            'booleans': {0x0: 'FALSE', 0x1: 'TRUE'},
        },
    },
})

# Space Center 2F is one continuous JP source range from its map-script table
# through the final Steven text.  Its 34 executable entries and 27 map-local
# text records were matched in physical order against the US map source; the
# Tabitha defeat text retains its shared US owner name.  Constants and text
# placeholders below are limited to values proved by the JP bytes and the
# surrounding US script context.
MAP_VERIFIED_SEMANTIC_LABELS.update({
    'MossdeepCity_SpaceCenter_2F': {
        'preserve_region_script_aliases': False,
        'preserve_region_text_aliases': False,
        'allow_single_case_switch': True,
        'frontier_macros': True,
        'field_placeholders': {
            0x0820DE3B: {0x01: 'PLAYER', 0x05: 'KUN'},
            0x0820DFB6: {0x01: 'PLAYER', 0x05: 'KUN'},
        },
        'texts': {
            0x0820DEAF: 'MossdeepCity_SpaceCenter_Text_TabithaDefeat',
        },
        'external_texts': {
            0x0826AB1B: 'MatchCall_Text_MayRayquazaCall',
            0x0826ABC8: 'MatchCall_Text_BrendanRayquazaCall',
        },
        'external_labels': {
            0x0824361B: 'Common_Movement_ExclamationMark',
            0x0824361D: 'Common_Movement_Delay48',
            0x08243621: 'Common_Movement_FacePlayer',
            0x08243625: 'Common_Movement_FaceOriginalDirection',
            0x08243627: 'Common_Movement_WalkInPlaceFasterLeft',
            0x08243629: 'Common_Movement_WalkInPlaceFasterUp',
            0x0824362B: 'Common_Movement_WalkInPlaceFasterRight',
            0x0824362D: 'Common_Movement_WalkInPlaceFasterDown',
        },
        'symbols': {
            'flags': {
                0x0075: 'FLAG_DEFEATED_MAGMA_SPACE_CENTER',
                0x00CD: 'FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER',
                0x0864: 'FLAG_SYS_GAME_CLEAR',
                0x02E1: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE',
                0x02F4: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA',
                0x0314: 'FLAG_HIDE_MOSSDEEP_CITY_SCOTT',
                0x0337: 'FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA',
                0x035E: 'FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA',
                0x03C7: 'FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN',
            },
            'vars': {
                0x405D: 'VAR_MOSSDEEP_CITY_STATE',
                0x409F: 'VAR_MOSSDEEP_SPACE_CENTER_STATE',
                0x40C6: 'VAR_STEVENS_HOUSE_STATE',
                0x8000: 'VAR_0x8000',
                0x8004: 'VAR_0x8004',
                0x8005: 'VAR_0x8005',
                0x800C: 'VAR_FACING',
                0x800D: 'VAR_RESULT',
                0x800F: 'VAR_LAST_TALKED',
            },
            'script_var_values': {
                0x0820D6E9: {0x800D: {0x1: 'YES'}},
                0x0820D904: {0x800D: {0x1: 'YES'}},
                0x0820D95C: {
                    0x8004: {
                        0x2: 'FRONTIER_UTIL_FUNC_SET_DATA',
                        0x6: 'FRONTIER_UTIL_FUNC_SAVE_PARTY',
                        0x8: 'SPECIAL_BATTLE_STEVEN',
                    },
                    0x8005: {0x4: 'FRONTIER_DATA_SELECTED_MON_ORDER'},
                },
                0x0820DA9F: {0x800D: {0x0: 'MALE', 0x1: 'FEMALE'}},
            },
            'switch_values': {
                'VAR_FACING': {0x1: 'DIR_SOUTH', 0x3: 'DIR_WEST'},
            },
            'trainers': {
                0x0202: 'TRAINER_TABITHA_MOSSDEEP',
                0x024C: 'TRAINER_GRUNT_SPACE_CENTER_5',
                0x024D: 'TRAINER_GRUNT_SPACE_CENTER_6',
                0x024E: 'TRAINER_GRUNT_SPACE_CENTER_7',
                0x02DE: 'TRAINER_MAXIE_MOSSDEEP',
            },
            'local_ids': {
                0x01: 'LOCALID_SPACE_CENTER_2F_RICH_BOY',
                0x02: 'LOCALID_SPACE_CENTER_2F_GENTLEMAN',
                0x03: 'LOCALID_SPACE_CENTER_2F_SCIENTIST',
                0x04: 'LOCALID_SPACE_CENTER_2F_STEVEN',
                0x05: 'LOCALID_SPACE_CENTER_GRUNT_6',
                0x06: 'LOCALID_SPACE_CENTER_GRUNT_5',
                0x07: 'LOCALID_SPACE_CENTER_GRUNT_7',
                0x08: 'LOCALID_SPACE_CENTER_TABITHA',
                0x09: 'LOCALID_SPACE_CENTER_MAXIE',
                0xFF: 'LOCALID_PLAYER',
            },
            'movement_types': {
                0x02: 'MOVEMENT_TYPE_WANDER_AROUND',
                0x0A: 'MOVEMENT_TYPE_FACE_RIGHT',
            },
            'directions': {
                0x01: 'DIR_SOUTH',
                0x02: 'DIR_NORTH',
                0x03: 'DIR_WEST',
                0x04: 'DIR_EAST',
            },
            'fade_modes': {0x0: 'FADE_FROM_BLACK', 0x1: 'FADE_TO_BLACK'},
            'sounds': {0x0C: 'SE_NOT_EFFECTIVE', 0x15: 'SE_PIN'},
            'maps': {0x0E09: 'MAP_MOSSDEEP_CITY_SPACE_CENTER_1F'},
        },
    },
})

MAP_POKEMART_LISTS.update({
    'MossdeepCity_Mart': (
        (0x0820C5CA, 'MossdeepCity_Mart_Pokemart', (
            'ITEM_ULTRA_BALL',
            'ITEM_NET_BALL',
            'ITEM_DIVE_BALL',
            'ITEM_HYPER_POTION',
            'ITEM_FULL_HEAL',
            'ITEM_REVIVE',
            'ITEM_MAX_REPEL',
            'ITEM_X_ATTACK',
            'ITEM_X_DEFEND',
        )),
    ),
})

MAP_POKEMART_LISTS.update({
    'LilycoveCity_DepartmentStore_2F': (
        (0x0820A953, 'LilycoveCity_DepartmentStore_2F_Pokemart1', (
            'ITEM_POKE_BALL',
            'ITEM_GREAT_BALL',
            'ITEM_ULTRA_BALL',
            'ITEM_ESCAPE_ROPE',
            'ITEM_FULL_HEAL',
            'ITEM_ANTIDOTE',
            'ITEM_PARALYZE_HEAL',
            'ITEM_BURN_HEAL',
            'ITEM_ICE_HEAL',
            'ITEM_AWAKENING',
            'ITEM_FLUFFY_TAIL',
        )),
        (0x0820A985, 'LilycoveCity_DepartmentStore_2F_Pokemart2', (
            'ITEM_POTION',
            'ITEM_SUPER_POTION',
            'ITEM_HYPER_POTION',
            'ITEM_MAX_POTION',
            'ITEM_REVIVE',
            'ITEM_REPEL',
            'ITEM_SUPER_REPEL',
            'ITEM_MAX_REPEL',
            'ITEM_WAVE_MAIL',
            'ITEM_MECH_MAIL',
        )),
    ),
})

MAP_POKEMART_LISTS.update({
    'LilycoveCity_DepartmentStore_3F': (
        (0x0820AA31, 'LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins', (
            'ITEM_PROTEIN',
            'ITEM_CALCIUM',
            'ITEM_IRON',
            'ITEM_ZINC',
            'ITEM_CARBOS',
            'ITEM_HP_UP',
        )),
        (0x0820AA5B, 'LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters', (
            'ITEM_X_SPEED',
            'ITEM_X_SPECIAL',
            'ITEM_X_ATTACK',
            'ITEM_X_DEFEND',
            'ITEM_DIRE_HIT',
            'ITEM_GUARD_SPEC',
            'ITEM_X_ACCURACY',
        )),
    ),
})

MAP_POKEMART_LISTS.update({
    'LilycoveCity_DepartmentStore_4F': (
        (0x0820AB84, 'LilycoveCity_DepartmentStore_4F_Pokemart_AttackTMs', (
            'ITEM_TM_FIRE_BLAST',
            'ITEM_TM_THUNDER',
            'ITEM_TM_BLIZZARD',
            'ITEM_TM_HYPER_BEAM',
        )),
        (0x0820ABA8, 'LilycoveCity_DepartmentStore_4F_Pokemart_DefenseTMs', (
            'ITEM_TM_PROTECT',
            'ITEM_TM_SAFEGUARD',
            'ITEM_TM_REFLECT',
            'ITEM_TM_LIGHT_SCREEN',
        )),
    ),
})

MAP_POKEMART_LISTS.update({
    'LilycoveCity_DepartmentStore_5F': (
        (0x0820AC91, 'LilycoveCity_DepartmentStore_5F_Pokemart_Dolls', (
            'DECOR_PICHU_DOLL',
            'DECOR_PIKACHU_DOLL',
            'DECOR_MARILL_DOLL',
            'DECOR_JIGGLYPUFF_DOLL',
            'DECOR_DUSKULL_DOLL',
            'DECOR_WYNAUT_DOLL',
            'DECOR_BALTOY_DOLL',
            'DECOR_KECLEON_DOLL',
            'DECOR_AZURILL_DOLL',
            'DECOR_SKITTY_DOLL',
            'DECOR_SWABLU_DOLL',
            'DECOR_GULPIN_DOLL',
        )),
        (0x0820ACC7, 'LilycoveCity_DepartmentStore_5F_Pokemart_Cushions', (
            'DECOR_PIKA_CUSHION',
            'DECOR_ROUND_CUSHION',
            'DECOR_ZIGZAG_CUSHION',
            'DECOR_SPIN_CUSHION',
            'DECOR_DIAMOND_CUSHION',
            'DECOR_BALL_CUSHION',
            'DECOR_GRASS_CUSHION',
            'DECOR_FIRE_CUSHION',
            'DECOR_WATER_CUSHION',
        )),
        (0x0820ACF5, 'LilycoveCity_DepartmentStore_5F_Pokemart_Posters', (
            'DECOR_BALL_POSTER',
            'DECOR_GREEN_POSTER',
            'DECOR_RED_POSTER',
            'DECOR_BLUE_POSTER',
            'DECOR_CUTE_POSTER',
            'DECOR_PIKA_POSTER',
            'DECOR_LONG_POSTER',
            'DECOR_SEA_POSTER',
            'DECOR_SKY_POSTER',
        )),
        (0x0820AD25, 'LilycoveCity_DepartmentStore_5F_Pokemart_Mats', (
            'DECOR_SURF_MAT',
            'DECOR_THUNDER_MAT',
            'DECOR_FIRE_BLAST_MAT',
            'DECOR_POWDER_SNOW_MAT',
            'DECOR_ATTRACT_MAT',
            'DECOR_FISSURE_MAT',
            'DECOR_SPIKES_MAT',
            'DECOR_GLITTER_MAT',
            'DECOR_JUMP_MAT',
            'DECOR_SPIN_MAT',
        )),
    ),
})

MAP_POKEMART_LISTS.update({
    'LilycoveCity_DepartmentStoreRooftop': (
        (0x0820AE92, 'LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale', (
            'DECOR_MUD_BALL',
            'DECOR_FENCE_LENGTH',
            'DECOR_FENCE_WIDTH',
            'DECOR_TIRE',
            'DECOR_BREAKABLE_DOOR',
            'DECOR_SOLID_BOARD',
            'DECOR_SAND_ORNAMENT',
            'DECOR_STAND',
            'DECOR_SLIDE',
            'DECOR_TV',
            'DECOR_ROUND_TV',
            'DECOR_CUTE_TV',
            'DECOR_WAILMER_DOLL',
            'DECOR_RHYDON_DOLL',
        )),
    ),
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'LilycoveCity_LilycoveMuseum_2F': {
        0x0820630D: 'LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft',
        0x0820630F: 'LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'LilycoveCity_PokemonTrainerFanClub': {
        0x0820840E: 'LilycoveCity_PokemonTrainerFanClub_Movement_FanApproachPlayer',
        0x08208416: 'LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlWatchPlayer',
        0x0820841D: 'LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlMoveCloserToPlayer',
        0x08208420: 'LilycoveCity_PokemonTrainerFanClub_Movement_LittleGirlHideFromPlayer',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'LilycoveCity_Harbor': {
        0x08209B04: 'LilycoveCity_Harbor_Movement_PlayerBoardFerryEast',
        0x08209B07: 'LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth',
        0x08209B09: 'LilycoveCity_Harbor_Movement_UnusedBoardFerry',
        0x08209B40: 'LilycoveCity_Harbor_Movement_SailorOutOfWayNorth',
        0x08209B45: 'LilycoveCity_Harbor_Movement_SailorOutOfWayEast',
        0x08209BA7: 'LilycoveCity_Harbor_Movement_BrineyBoardFerry',
        0x08209BAB: 'LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth',
        0x08209BB0: 'LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth',
        0x08209BB8: 'LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast',
        0x08209BBE: 'LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'LilycoveCity_ContestLobby': {
        0x08206AC7: 'LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer',
        0x08206ACF: 'LilycoveCity_ContestLobby_Movement_ArtistExit',
        0x08206AD8: 'LilycoveCity_ContestLobby_Movement_PlayerFaceArtist',
        0x08206ADA: 'LilycoveCity_ContestLobby_Movement_ArtistBeginToExit',
        0x08206ADE: 'LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer',
        0x08206BF3: 'LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer',
        0x08206BFC: 'LilycoveCity_ContestLobby_Movement_LinkArtistExit',
        0x08206C05: 'LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist',
        0x08206C07: 'LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit',
        0x08206C0B: 'LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer',
        0x08206DA8: 'LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall',
        0x08206DB2: 'LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist',
        0x08206DB5: 'LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter',
        0x08206DB9: 'LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter',
        0x08206DBD: 'LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall',
        0x08206DC6: 'LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer',
        0x08207390: 'LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall',
        0x0820739B: 'LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist',
        0x0820739D: 'LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter',
        0x082073A1: 'LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter',
        0x082073A5: 'LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall',
        0x082073AF: 'LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    # Route101 retains four unreferenced movement records between the Birch
    # rescue scene and its local NPC scripts.  JP ROM bytes and boundaries are
    # 0x081E65B8 (FE), 0x081E65EA (FE), 0x081E65F0 (09 09 FE), and
    # 0x081E65F3 (09 0A 09 FE); expose them so the generator does not hide
    # byte-exact data behind raw spans.
    'Route101': {
        0x081E65B8: 'Route101_Movement_UnusedStepEnd1',
        0x081E65EA: 'Route101_Movement_UnusedStepEnd2',
        0x081E65F0: 'Route101_Movement_Unused1',
        0x081E65F3: 'Route101_Movement_Unused2',
    },
    'SeafloorCavern_Room9': {
        0x08218C5F: 'SeafloorCavern_Room9_Movement_ArchieApproachPlayer',
        0x08218C67: 'SeafloorCavern_Room9_Movement_Unused1',
        0x08218C6A: 'SeafloorCavern_Room9_Movement_ArchieListenMessage',
        0x08218C6D: 'SeafloorCavern_Room9_Movement_Unused2',
        0x08218C6F: 'SeafloorCavern_Room9_Movement_ArchieExit',
        0x08218C75: 'SeafloorCavern_Room9_Movement_KyogreApproach',
        0x08218C80: 'SeafloorCavern_Room9_Movement_KyogreExit',
        0x08218C83: 'SeafloorCavern_Room9_Movement_MaxieArrive',
        0x08218C89: 'SeafloorCavern_Room9_Movement_MaxieExit',
        0x08218C8C: 'SeafloorCavern_Room9_Movement_MagmaGruntArrive',
        0x08218C91: 'SeafloorCavern_Room9_Movement_Delay32',
    },
    'Route109': {
        0x081E8766: 'Route109_Movement_SailToDewford',
        0x081E8814: 'Route109_Movement_PlayerEnterBoatSouth',
        0x081E8817: 'Route109_Movement_PlayerExitBoat',
        0x081E881C: 'Route109_Movement_PlayerEnterBoatEast',
        0x081E881F: 'Route109_Movement_PlayerEnterBoatWest',
        0x081E8822: 'Route109_Movement_BrineyEnterBoat',
        0x081E8824: 'Route109_Movement_BrineyExitBoat',
    },
    'Route110': {
        0x081E9588: 'Route110_Movement_RivalApproachPlayer1',
        0x081E958C: 'Route110_Movement_RivalApproachPlayer2',
        0x081E958E: 'Route110_Movement_RivalApproachPlayer3',
        0x081E9592: 'Route110_Movement_RivalExit1',
        0x081E959A: 'Route110_Movement_RivalExit2',
        0x081E95A3: 'Route110_Movement_RivalExit3',
        0x081E9710: 'Route110_Movement_BirchEntrance',
        0x081E9714: 'Route110_Movement_BirchApproachPlayer1',
        0x081E9719: 'Route110_Movement_BirchApproachPlayer2',
        0x081E971D: 'Route110_Movement_BirchApproachPlayer3',
        0x081E9720: 'Route110_Movement_BirchApproachPlayer4',
        0x081E9724: 'Route110_Movement_BirchExit1',
        0x081E972B: 'Route110_Movement_BirchExit2',
        0x081E9731: 'Route110_Movement_BirchExit3',
        0x081E9737: 'Route110_Movement_BirchExit4',
    },
    'Route111': {
        0x081EA357: 'Route111_Movement_PlayerFall',
        0x081EA44E: 'Route111_Movement_PushUpFromRoute',
        0x081EA450: 'Route111_Movement_PushDownFromRoute',
        0x081EA452: 'Route111_Movement_PushLeftFromRoute',
        0x081EA454: 'Route111_Movement_PushRightFromRoute',
        0x081EA5F0: 'Route111_Movement_WinstrateEnterHouse',
        0x081EA5F3: 'Route111_Movement_WinstrateExitHouse',
        0x081EA5F5: 'Route111_Movement_WaitForNextWinstrate',
    },
    # Route118's seven Steven-scene movement streams exactly fill the only
    # otherwise raw owner interval.  Their step_end boundaries and action
    # order match the US source one-for-one.
    'Route118': {
        0x081EC98B: 'Route118_Movement_PlayerWatchStevenExit',
        0x081EC98E: 'Route118_Movement_StevenApproachLedge0',
        0x081EC990: 'Route118_Movement_StevenApproachLedge2',
        0x081EC992: 'Route118_Movement_StevenJumpLedge',
        0x081EC996: 'Route118_Movement_StevenExit0',
        0x081EC9A1: 'Route118_Movement_StevenExit1',
        0x081EC9AB: 'Route118_Movement_StevenExit2',
    },
    'Route119': {
        0x081ECFDF: 'Route119_Movement_PlayerWatchRivalExit1',
        0x081ECFE4: 'Route119_Movement_PlayerWatchRivalExit2',
        0x081ECFE9: 'Route119_Movement_RivalEnter1',
        0x081ECFF3: 'Route119_Movement_RivalEnter2',
        0x081ECFFE: 'Route119_Movement_RivalExit1',
        0x081ED008: 'Route119_Movement_RivalExit2',
        0x081ED013: 'Route119_Movement_ScottEnter',
        0x081ED01B: 'Route119_Movement_ScottExit1',
        0x081ED024: 'Route119_Movement_ScottExit2',
    },
    'Route120': {
        0x081EDC31: 'Route120_Movement_ApproachKecleonWest',
    },
    'Route121': {
        0x081EE136: 'Route121_Movement_Grunt1Exit',
        0x081EE13F: 'Route121_Movement_Grunt2Exit',
        0x081EE148: 'Route121_Movement_Grunt3Exit',
    },
    # Route103's rival-exit movements occupy the otherwise raw 0x1E6C89
    # region.  Each target and step_end boundary matches the US map source.
    'Route103': {
        0x081E6C89: 'Route103_Movement_RivalExitFacingNorth1',
        0x081E6C8C: 'Route103_Movement_RivalExitFacingNorth2',
        0x081E6C93: 'Route103_Movement_WatchRivalExitFacingNorth',
        0x081E6C99: 'Route103_Movement_RivalExit1',
        0x081E6C9B: 'Route103_Movement_RivalExit2',
        0x081E6CA1: 'Route103_Movement_WatchRivalExitFacingEastOrWest',
    },
    # This unused RS switch delay sits between the Gym Guide and statue
    # scripts. It is referenced only by applymovement in the old switch flow.
    'MossdeepCity_Gym': {
        0x0820B799: 'MossdeepCity_Gym_Movement_WaitAfterSwitchUse',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'MossdeepCity_House2': {
        0x0820C42E: 'MossdeepCity_House2_Movement_WingullExitNorth',
        0x0820C435: 'MossdeepCity_House2_Movement_WingullExitEast',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'MossdeepCity_StevensHouse': {
        0x0820C8C5: 'MossdeepCity_StevensHouse_Movement_StevenApproachPlayer',
        0x0820C8CD: 'MossdeepCity_StevensHouse_Movement_StevenReturn',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'MossdeepCity_SpaceCenter_1F': {
        0x0820D0B6: 'MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsWest',
        0x0820D0BA: 'MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairsEast',
        0x0820D0BE: 'MossdeepCity_SpaceCenter_1F_Movement_MoveGruntFromStairs',
    },
})

MAP_MOVEMENT_SCRIPT_LABELS.update({
    'MossdeepCity_SpaceCenter_2F': {
        0x0820D731: 'MossdeepCity_SpaceCenter_2F_Movement_PlayerExit',
        0x0820D7AB: 'MossdeepCity_SpaceCenter_2F_Movement_Grunt6Defeated',
        0x0820D7AF: 'MossdeepCity_SpaceCenter_2F_Movement_Grunt5Defeated',
        0x0820D7B3: 'MossdeepCity_SpaceCenter_2F_Movement_Grunt7Defeated',
        0x0820D8F0: 'MossdeepCity_SpaceCenter_2F_Movement_StevenFight',
        0x0820D8F9: 'MossdeepCity_SpaceCenter_2F_Movement_StevenFightSouth',
    },
})

MSGBOX_TYPES = {
    2: 'MSGBOX_NPC',
    3: 'MSGBOX_SIGN',
    4: 'MSGBOX_DEFAULT',
    5: 'MSGBOX_YESNO',
    6: 'MSGBOX_AUTOCLOSE',
    9: 'MSGBOX_GETPOINTS',
    10: 'MSGBOX_POKENAV',
}

TEXT_POINTER_ARGUMENTS = sp.TEXT_POINTER_ARGUMENTS


def toi(x):
    return int(x, 16) if isinstance(x, str) else int(x)


def build_map_names():
    us = json.loads(US_JSON.read_text())
    order = us['group_order']
    names = {}
    for gi, gkey in enumerate(order[:34]):
        for mi, name in enumerate(us[gkey]):
            names[(gi, mi)] = name
    return names


MAP_NAMES = build_map_names()
TEXT_CODEC = JapaneseScriptTextCodec()

# The JP command table still exposes three RS-era handler names, while the
# byte-identical Emerald macro names describe their actual script semantics.
# Keep the parser's raw names for ROM decoding, then canonicalize only source
# output through the shared opcode constants.
CANONICAL_SCRIPT_COMMAND_NAMES = {
    'cmdDB': 'messageinstant',
    'getpricereduction': 'getpokenewsactive',
    'mossdeepgym1': 'moverotatingtileobjects',
    'mossdeepgym3': 'initrotatingtilepuzzle',
    'buffercontesttype': 'freerotatingtilepuzzle',
    'showcontestwinner': 'showcontestpainting',
}


def build_movement_action_names():
    """Read the JP movement macro table as its authoritative byte mapping."""
    names = {}
    value = None
    macro_file = ROOT / 'asm' / 'macros' / 'movement.inc'
    for raw_line in macro_file.read_text(encoding='utf-8').splitlines():
        line = raw_line.strip()
        match = re.fullmatch(r'enum_start(?:\s+(0x[0-9A-Fa-f]+))?', line)
        if match:
            value = int(match.group(1), 0) if match.group(1) else 0
            continue
        match = re.fullmatch(
            r'create_movement_action\s+([A-Za-z_][A-Za-z0-9_]*)', line)
        if match and value is not None:
            names[value] = match.group(1)
            value += 1
    return names


MOVEMENT_ACTION_NAMES = build_movement_action_names()
if MOVEMENT_ACTION_NAMES.get(0xFE) != 'step_end':
    raise RuntimeError('movement macro table does not define step_end as 0xFE')


def decode_movement_script(addr, region_end):
    """Decode a proved one-byte movement sequence through its step_end byte."""
    actions = []
    pos = addr
    while pos < region_end:
        action = ROM[pos - 0x08000000]
        name = MOVEMENT_ACTION_NAMES.get(action)
        if name is None:
            return None
        actions.append(name)
        pos += 1
        if action == 0xFE:
            return actions, pos
    return None


def referenced_movement_addresses(scripts, region_start, region_end):
    """Return in-owner movement streams named by decoded script operands.

    These are not heuristic pointers: both movement opcodes define argument 1
    as a movement-script address.  Restricting targets to the current owner
    prevents this map from taking ownership of shared movement data.
    """
    addresses = set()
    for script in scripts.values():
        for _off, name, args, _refs in script:
            if name not in ('applymovement', 'applymovement_at') or len(args) < 2:
                continue
            target = args[1]
            if region_start <= target < region_end:
                addresses.add(target)
    return addresses

def decode_text(data, placeholder_names=None):
    """Return safe source text, or None when a byte sequence is not proved."""
    try:
        return TEXT_CODEC.verify(data, placeholder_names)
    except (TextDecodeError, TextRoundTripError):
        return None


def collapse_msgbox_macros(lines):
    """Restore the source-level ``msgbox`` macro for a proven two-op sequence."""
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        if name == 'loadword' and index + 1 < len(lines):
            next_name, next_argstr = lines[index + 1]
            parts = [part.strip() for part in argstr.split(',', 1)]
            try:
                message_type = int(next_argstr, 0)
            except ValueError:
                message_type = None
            if (next_name == 'callstd' and len(parts) == 2
                    and parts[0] in ('0', '0x0')
                    and message_type in MSGBOX_TYPES):
                out.append(('msgbox', '%s, %s' % (parts[1], MSGBOX_TYPES[message_type])))
                index += 2
                continue
        out.append((name, argstr))
        index += 1
    return out


def collapse_trainerbattle_macros(lines):
    """Restore the standard trainer-battle wrappers when their bytes prove them."""
    out = []
    for name, argstr in lines:
        if name != 'trainerbattle':
            out.append((name, argstr))
            continue
        parts = [part.strip() for part in argstr.split(',')]
        if len(parts) < 4 or parts[2] not in ('0', '0x0', 'LOCALID_NONE'):
            out.append((name, argstr))
            continue
        battle_type, trainer = parts[0], parts[1]
        if battle_type == 'TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT' and len(parts) == 4:
            out.append(('trainerbattle_no_intro', ', '.join((trainer, parts[3]))))
        elif battle_type == 'TRAINER_BATTLE_SINGLE' and len(parts) == 5:
            out.append(('trainerbattle_single', ', '.join((trainer, parts[3], parts[4]))))
        elif battle_type == 'TRAINER_BATTLE_CONTINUE_SCRIPT' and len(parts) == 6:
            out.append(('trainerbattle_single', ', '.join((trainer, parts[3], parts[4], parts[5]))))
        elif (battle_type == 'TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC'
              and len(parts) == 6):
            out.append(('trainerbattle_single', ', '.join(
                (trainer, parts[3], parts[4], parts[5], 'NO_MUSIC'))))
        elif battle_type == 'TRAINER_BATTLE_DOUBLE' and len(parts) == 6:
            out.append(('trainerbattle_double', ', '.join((trainer, parts[3], parts[4], parts[5]))))
        elif battle_type == 'TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE' and len(parts) == 7:
            out.append(('trainerbattle_double', ', '.join((trainer, parts[3], parts[4], parts[5], parts[6]))))
        elif (battle_type == 'TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC'
              and len(parts) == 7):
            out.append(('trainerbattle_double', ', '.join(
                (trainer, parts[3], parts[4], parts[5], parts[6], 'NO_MUSIC'))))
        elif battle_type == 'TRAINER_BATTLE_REMATCH' and len(parts) == 5:
            out.append(('trainerbattle_rematch', ', '.join((trainer, parts[3], parts[4]))))
        elif battle_type == 'TRAINER_BATTLE_REMATCH_DOUBLE' and len(parts) == 6:
            out.append(('trainerbattle_rematch_double', ', '.join((trainer, parts[3], parts[4], parts[5]))))
        else:
            out.append((name, argstr))
    return out


def collapse_register_matchcall_macros(lines):
    """Restore ``register_matchcall`` only for its exact four-op expansion."""
    out = []
    index = 0
    while index < len(lines):
        if index + 3 < len(lines):
            first, second, third, fourth = lines[index:index + 4]
            if (
                first[0] == 'setvar'
                and second == ('special', 'SetMatchCallRegisteredFlag')
                and third[0] == 'setorcopyvar'
                and fourth[0] == 'callstd'
            ):
                first_args = [part.strip() for part in first[1].split(',')]
                third_args = [part.strip() for part in third[1].split(',')]
                if (
                    len(first_args) == 2
                    and len(third_args) == 2
                    and first_args[0] == 'VAR_0x8004'
                    and third_args[0] == 'VAR_0x8000'
                    and first_args[1] == third_args[1]
                    and fourth[1] in ('8', '0x8', 'STD_REGISTER_MATCH_CALL')
                ):
                    out.append(('register_matchcall', first_args[1]))
                    index += 4
                    continue
        out.append(lines[index])
        index += 1
    return out


def collapse_condition_macros(lines):
    """Restore exact two-instruction comparison and flag-test macros."""
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        if index + 1 < len(lines):
            next_name, next_argstr = lines[index + 1]
            parts = [part.strip() for part in argstr.split(',', 1)]
            next_parts = [part.strip() for part in next_argstr.split(',', 1)]
            try:
                condition = int(next_parts[0], 0)
            except (IndexError, ValueError):
                condition = None
            if (name == 'checkflag' and next_name in ('goto_if', 'call_if')
                    and len(next_parts) == 2):
                suffix = {0: 'unset', 1: 'set'}.get(condition)
                if suffix is not None:
                    out.append(('%s_if_%s' % (next_name[:-3], suffix),
                                '%s, %s' % (argstr, next_parts[1])))
                    index += 2
                    continue
            if (name == 'checktrainerflag' and next_name in ('goto_if', 'call_if')
                    and len(next_parts) == 2):
                suffix = {0: 'not_defeated', 1: 'defeated'}.get(condition)
                if suffix is not None:
                    out.append(('%s_if_%s' % (next_name[:-3], suffix),
                                '%s, %s' % (argstr, next_parts[1])))
                    index += 2
                    continue
            if (name in ('compare_var_to_value', 'compare_var_to_var')
                    and next_name in ('goto_if', 'call_if')
                    and len(parts) == 2 and len(next_parts) == 2):
                suffix = {
                    0: 'lt',
                    1: 'eq',
                    2: 'gt',
                    3: 'le',
                    4: 'ge',
                    5: 'ne',
                }.get(condition)
                if suffix is not None:
                    out.append(('%s_if_%s' % (next_name[:-3], suffix),
                                '%s, %s, %s' % (parts[0], parts[1], next_parts[1])))
                    index += 2
                    continue
        out.append((name, argstr))
        index += 1
    return out


def collapse_switch_macros(lines, value_names=None, minimum_cases=2):
    """Restore byte-proven ``switch``/``case`` dispatch tables.

    The script macros expand to a copy into VAR_0x8000 followed by one
    goto_if_eq per case. The default requires at least two consecutive cases
    so ordinary one-off comparisons retain their direct conditional form;
    maps whose checked US source uses a one-case switch may opt in explicitly.
    """
    value_names = value_names or {}
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        args = [arg.strip() for arg in argstr.split(',')]
        copy_args = args
        if len(args) == 3 and args[2] == 'warn=FALSE':
            copy_args = args[:2]
        if (name == 'copyvar' and len(copy_args) == 2
                and copy_args[0] == 'VAR_0x8000'):
            cases = []
            cursor = index + 1
            while cursor < len(lines):
                case_name, case_argstr = lines[cursor]
                case_args = [arg.strip() for arg in case_argstr.split(',')]
                if (case_name != 'goto_if_eq' or len(case_args) != 3
                        or case_args[0] != 'VAR_0x8000'):
                    break
                value = case_args[1]
                try:
                    numeric = int(value, 0)
                except ValueError:
                    numeric = None
                if numeric is not None:
                    value = value_names.get(copy_args[1], {}).get(numeric, value)
                    if value == case_args[1] and 0 <= numeric <= 9:
                        value = str(numeric)
                cases.append((value, case_args[2]))
                cursor += 1
            if len(cases) >= minimum_cases:
                out.append(('switch', copy_args[1]))
                out.extend(('case', '%s, %s' % case) for case in cases)
                index = cursor
                continue
        out.append(lines[index])
        index += 1
    return out


def name_contextual_result_conditions(lines):
    """Name result values only when their producing command proves the type.

    ``VAR_RESULT`` carries many unrelated result families.  In particular,
    checkplayergender returns MALE/FEMALE rather than FALSE/TRUE.  Preserve a
    literal unless the immediately preceding command establishes one of these
    two precise meanings.
    """
    out = list(lines)

    def replace_condition(index, names):
        if index >= len(out):
            return
        name, argstr = out[index]
        parts = [part.strip() for part in argstr.split(',')]
        if name not in ('goto_if_eq', 'goto_if_ne', 'call_if_eq', 'call_if_ne'):
            return
        if len(parts) != 3 or parts[0] != 'VAR_RESULT':
            return
        try:
            value = int(parts[1], 0)
        except ValueError:
            return
        replacement = names.get(value)
        if replacement is not None:
            out[index] = (name, ', '.join((parts[0], replacement, parts[2])))

    for index, (name, argstr) in enumerate(out):
        if name == 'checkplayergender':
            replace_condition(index + 1, {0: 'MALE'})
            replace_condition(index + 2, {1: 'FEMALE'})
        elif name == 'specialvar' and argstr == 'VAR_RESULT, ShouldTryRematchBattle':
            replace_condition(index + 1, {0: 'FALSE', 1: 'TRUE'})
        elif name == 'special' and argstr == 'SetLilycoveLadyGfx':
            # This special returns whether the selected Lilycove Lady is the
            # Contest Lady; the adjacent branch pair therefore has the same
            # FALSE/TRUE meaning as the matching US map source.
            replace_condition(index + 1, {0: 'FALSE'})
            replace_condition(index + 2, {1: 'TRUE'})
        elif name == 'special' and argstr in (
                'IsSelectedMonEgg', 'IsLastMonThatKnowsSurf'):
            # Both special calls return a byte boolean. Keep the following
            # branch readable without naming unrelated numeric VAR_RESULT
            # values such as a selected mon's move count.
            replace_condition(index + 1, {1: 'TRUE'})
        elif name == 'msgbox' and argstr.endswith(', MSGBOX_YESNO'):
            replace_condition(index + 1, {0: 'NO', 1: 'YES'})
            replace_condition(index + 2, {0: 'NO', 1: 'YES'})
        elif name == 'givemon':
            result_names = {
                0: 'MON_GIVEN_TO_PARTY',
                1: 'MON_GIVEN_TO_PC',
                2: 'MON_CANT_GIVE',
            }
            replace_condition(index + 1, result_names)
            replace_condition(index + 2, result_names)
            replace_condition(index + 3, result_names)
        elif name in ('checkitem', 'checkpcitem'):
            replace_condition(index + 1, {0: 'FALSE', 1: 'TRUE'})
        elif name == 'specialvar' and argstr == 'VAR_RESULT, IsEnigmaBerryValid':
            replace_condition(index + 1, {0: 'FALSE', 1: 'TRUE'})
        elif name == 'giveitem':
            replace_condition(index + 1, {0: 'FALSE', 1: 'TRUE'})
        elif name == 'givedecoration':
            replace_condition(index + 1, {0: 'FALSE', 1: 'TRUE'})
    return out


VARIABLE_ARGUMENTS = {
    'compare_var_to_value': {0},
    'compare_var_to_var': {0, 1},
    'goto_if_eq': {0},
    'goto_if_ne': {0},
    'goto_if_lt': {0},
    'goto_if_gt': {0},
    'setvar': {0},
    'addvar': {0},
    'subvar': {0},
    'copyvar': {0, 1},
    'setorcopyvar': {0},
    'specialvar': {0},
}
FLAG_ARGUMENTS = {
    'setflag', 'clearflag', 'checkflag', 'goto_if_set', 'goto_if_unset',
}
LOCAL_ID_ARGUMENTS = {
    'applymovement': {0},
    'applymovement_at': {0},
    'addobject': {0},
    'addobject_at': {0},
    'copyobjectxytoperm': {0},
    'hideobject_at': {0},
    'moveobjectoffscreen': {0},
    'removeobject': {0},
    'removeobject_at': {0},
    'resetobjectsubpriority': {0},
    'setobjectxyperm': {0},
    'setobjectxy': {0},
    'setobjectmovementtype': {0},
    'setobjectsubpriority': {0},
    'showobject_at': {0},
    'turnobject': {0},
    'waitmovement': {0},
    'waitmovement_at': {0},
}
MAP_ARGUMENTS = {
    'setdynamicwarp': {0},
    'setdivewarp': {0},
    'warpdoor': {0},
    'warpmossdeepgym': {0},
    'addobject_at': {1},
    'applymovement_at': {2},
    'hideobject_at': {1},
    'removeobject_at': {1},
    'resetobjectsubpriority': {1},
    'setobjectsubpriority': {1},
    'showobject_at': {1},
    'waitmovement_at': {1},
}


def collapse_coordinate_warp_macros(lines):
    """Use the canonical three-argument form for coordinate-only warps."""
    out = []
    for name, argstr in lines:
        if name in ('setdivewarp', 'setdynamicwarp', 'setescapewarp', 'setwarp', 'warp', 'warpdoor', 'warpmossdeepgym'):
            args = [arg.strip() for arg in argstr.split(',')]
            if len(args) == 4 and args[1].lower() in ('0xff', '0xffff', '-1'):
                argstr = ', '.join((args[0], args[2], args[3]))
        out.append((name, argstr))
    return out


def collapse_frontier_results_macros(lines, facilities):
    """Restore reviewed ``frontier_results`` macro expansions conservatively."""
    if not facilities:
        return lines

    out = []
    index = 0
    while index < len(lines):
        if index + 2 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            third_name, third_args = lines[index + 2]
            first = [part.strip() for part in first_args.split(',', 1)]
            second = [part.strip() for part in second_args.split(',', 1)]
            if (first_name == 'setvar' and second_name == 'setvar'
                    and third_name == 'special'
                    and first[:1] == ['VAR_0x8004']
                    and second[:1] == ['VAR_0x8005']
                    and len(first) == 2 and len(second) == 2
                    and third_args == 'CallFrontierUtilFunc'):
                try:
                    key = (int(first[1], 0), int(second[1], 0))
                except ValueError:
                    key = None
                facility = facilities.get(key)
                if facility is not None:
                    out.append(('frontier_results', facility))
                    index += 3
                    continue
        out.append(lines[index])
        index += 1
    return out


def collapse_frontier_utility_macros(lines, enabled=False):
    """Restore reviewed Frontier utility wrappers for an opted-in map.

    These macros are only presentation wrappers around byte-exact command
    sequences.  Keep the transformation opt-in because FRONTIER_UTIL values
    have context-dependent meanings outside a reviewed map script.
    """
    if not enabled:
        return lines

    out = []
    index = 0
    while index < len(lines):
        if index + 2 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            third_name, third_args = lines[index + 2]
            first = [part.strip() for part in first_args.split(',', 1)]
            second = [part.strip() for part in second_args.split(',', 1)]
            if (first_name == 'setvar' and second_name == 'setvar'
                    and third_name == 'special'
                    and first == ['VAR_0x8004', 'FRONTIER_UTIL_FUNC_SET_DATA']
                    and second == ['VAR_0x8005', 'FRONTIER_DATA_SELECTED_MON_ORDER']
                    and third_args == 'CallFrontierUtilFunc'):
                out.append(('frontier_set', 'FRONTIER_DATA_SELECTED_MON_ORDER'))
                index += 3
                continue
        if index + 1 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            first = [part.strip() for part in first_args.split(',', 1)]
            if (first_name == 'setvar' and second_name == 'special'
                    and first == ['VAR_0x8004', 'FRONTIER_UTIL_FUNC_SAVE_PARTY']
                    and second_args == 'CallFrontierUtilFunc'):
                out.append(('frontier_saveparty', ''))
                index += 2
                continue
        out.append(lines[index])
        index += 1
    return out


def annotate_literal_copyvars(lines):
    """Suppress the macro's diagnostic for byte-accurate literal copyvars."""
    out = []
    for name, argstr in lines:
        args = [part.strip() for part in argstr.split(',')]
        if (name == 'copyvar' and len(args) == 2
                and not args[1].startswith('VAR_')):
            argstr = '%s, warn=FALSE' % argstr
        out.append((name, argstr))
    return out


def collapse_giveitem_macros(lines):
    """Restore the canonical US-style giveitem wrapper when byte-exact.

    The macro expands to these same three JP commands, so this is a source
    presentation change only; the candidate assembler remains the byte gate.
    """
    out = []
    index = 0
    while index < len(lines):
        if index + 2 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            third_name, third_args = lines[index + 2]
            first = [part.strip() for part in first_args.split(',', 1)]
            second = [part.strip() for part in second_args.split(',', 1)]
            if (first_name == 'setorcopyvar'
                    and second_name == 'setorcopyvar'
                    and third_name == 'callstd'
                    and first[:1] == ['VAR_0x8000']
                    and second[:1] == ['VAR_0x8001']
                    and len(first) == 2 and len(second) == 2
                    and third_args in ('0x0', 'STD_OBTAIN_ITEM')):
                out.append(('giveitem', '%s, %s' % (first[1], second[1])))
                index += 3
                continue
        out.append(lines[index])
        index += 1
    return out


def collapse_finditem_macros(lines):
    """Restore the byte-exact ``finditem`` wrapper used by item balls."""
    out = []
    index = 0
    while index < len(lines):
        if index + 2 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            third_name, third_args = lines[index + 2]
            first = [part.strip() for part in first_args.split(',', 1)]
            second = [part.strip() for part in second_args.split(',', 1)]
            if (first_name == 'setorcopyvar'
                    and second_name == 'setorcopyvar'
                    and third_name == 'callstd'
                    and first[:1] == ['VAR_0x8000']
                    and second[:1] == ['VAR_0x8001']
                    and len(first) == 2 and len(second) == 2
                    and third_args in ('0x1', 'STD_FIND_ITEM')):
                out.append(('finditem', '%s, %s' % (first[1], second[1])))
                index += 3
                continue
        out.append(lines[index])
        index += 1
    return out


def collapse_givedecoration_macros(lines):
    """Restore the byte-exact ``givedecoration`` wrapper where reviewed."""
    out = []
    index = 0
    while index < len(lines):
        if index + 1 < len(lines):
            first_name, first_args = lines[index]
            second_name, second_args = lines[index + 1]
            first = [part.strip() for part in first_args.split(',', 1)]
            if (first_name == 'setorcopyvar'
                    and second_name == 'callstd'
                    and first[:1] == ['VAR_0x8000']
                    and len(first) == 2
                    and second_args in ('0x7', 'STD_OBTAIN_DECORATION')):
                out.append(('givedecoration', first[1]))
                index += 2
                continue
        out.append(lines[index])
        index += 1
    return out


def omit_default_macro_arguments(lines):
    """Drop explicit defaults only where the canonical macro proves them."""
    out = []
    for name, argstr in lines:
        args = [part.strip() for part in argstr.split(',')]
        if name == 'givemon' and len(args) == 3 and args[2] in ('0x0', 'ITEM_NONE'):
            argstr = ', '.join(args[:2])
        elif name in ('giveitem', 'finditem', 'checkitem', 'checkpcitem', 'removeitem') and len(args) == 2 and args[1] in ('1', '0x1'):
            argstr = args[0]
        out.append((name, argstr))
    return out


ITEM_ARGUMENTS = {
    'giveitem': {0},
    'finditem': {0},
    'checkitem': {0},
    'checkpcitem': {0},
    'removeitem': {0},
    'bufferitemname': {1},
}


def semantic_symbol_formatter(mname, script_addr=None):
    """Return a conservative formatter for reviewed map-script constants."""
    symbols = MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {}).get('symbols', {})
    if not symbols:
        return None

    def format_symbol(name, index, value, args):
        if name in FLAG_ARGUMENTS and index == 0:
            return symbols.get('flags', {}).get(value)
        if name == 'trainerbattle' and index == 1:
            return symbols.get('trainers', {}).get(value)
        if name == 'trainerbattle' and index == 2 and value == 0:
            return 'LOCALID_NONE'
        if name == 'checktrainerflag' and index == 0:
            return symbols.get('trainers', {}).get(value)
        if name == 'warpdoor' and index in (1, 2, 3):
            return symbols.get('vars', {}).get(value)
        if index in VARIABLE_ARGUMENTS.get(name, ()):
            return symbols.get('vars', {}).get(value)
        # The meaning of a comparison value is defined by the variable it is
        # compared against.  Keep this strictly map-local and allowlisted so
        # an unrelated numeric result is never assigned a plausible name.
        if name == 'compare_var_to_value' and index == 1 and args:
            reviewed = (symbols.get('script_var_values', {})
                        .get(script_addr, {}).get(args[0], {}).get(value))
            if reviewed is not None:
                return reviewed
            return symbols.get('var_values', {}).get(args[0], {}).get(value)
        if name == 'setvar' and index == 1 and args:
            reviewed = (symbols.get('script_var_values', {})
                        .get(script_addr, {}).get(args[0], {}).get(value))
            if reviewed is None:
                reviewed = symbols.get('var_values', {}).get(args[0], {}).get(value)
            if reviewed is not None:
                return reviewed
        if (name == 'setvar' and index == 1 and args
                and args[0] == 0x8004):
            return symbols.get('trainers', {}).get(value)
        # VAR_0x800B is the map-local recipient used by the Pokémon Center
        # nurse helper.  Render a local ID only where the map's reviewed
        # semantic table explicitly supplies one.
        if (name == 'setvar' and index == 1 and args
                and args[0] == 0x800B):
            return symbols.get('local_ids', {}).get(value)
        if name == 'setorcopyvar' and index == 1 and args and args[0] == 0x8000:
            reviewed = (symbols.get('script_var_values', {})
                        .get(script_addr, {}).get(args[0], {}).get(value))
            return (reviewed
                    or symbols.get('items', {}).get(value)
                    or symbols.get('trainers', {}).get(value)
                    or symbols.get('decorations', {}).get(value))
        if name == 'givedecoration' and index == 0:
            return symbols.get('decorations', {}).get(value)
        if index in ITEM_ARGUMENTS.get(name, ()):
            return symbols.get('items', {}).get(value)
        if name.startswith('buffer') and index == 0:
            return {0: 'STR_VAR_1', 1: 'STR_VAR_2', 2: 'STR_VAR_3'}.get(value)
        if name == 'buffernumberstring' and index == 1:
            return symbols.get('vars', {}).get(value)
        if name == 'bufferstdstring' and index == 1:
            return symbols.get('stdstrings', {}).get(value)
        if name in ('playbgm', 'playfanfare', 'savebgm', 'fadenewbgm') and index == 0:
            return symbols.get('songs', {}).get(value)
        if name == 'playbgm' and index == 1:
            return symbols.get('booleans', {}).get(value)
        if name in ('getpokenewsactive', 'getpricereduction') and index == 0:
            return symbols.get('pokenews', {}).get(value)
        if name == 'playse' and index == 0:
            return symbols.get('sounds', {}).get(value)
        if name == 'incrementgamestat' and index == 0:
            return symbols.get('game_stats', {}).get(value)
        if name == 'setrespawn' and index == 0:
            return symbols.get('heal_locations', {}).get(value)
        if name == 'fadescreen' and index == 0:
            return symbols.get('fade_modes', {}).get(value)
        if name in ('showcontestwinner', 'showcontestpainting') and index == 0:
            return symbols.get('contest_winners', {}).get(value)
        if name == 'setmetatile' and index == 2:
            return symbols.get('metatiles', {}).get(value)
        if name == 'setmetatile' and index == 3:
            return symbols.get('booleans', {}).get(value)
        if name in ('initrotatingtilepuzzle', 'mossdeepgym3') and index == 0:
            return symbols.get('booleans', {}).get(value)
        if name in ('playmoncry', 'showmonpic', 'setwildbattle'):
            if index == 0:
                return symbols.get('species', {}).get(value)
            if name == 'playmoncry' and index == 1:
                return symbols.get('cry_modes', {}).get(value)
        if name in ('bufferspeciesname', 'givemon') and index in ({1} if name == 'bufferspeciesname' else {0}):
            return symbols.get('species', {}).get(value)
        if name in ('multichoice', 'multichoicedefault', 'multichoicegrid') and index == 2:
            return symbols.get('multichoices', {}).get(value)
        if name == 'multichoice' and index == 3:
            return symbols.get('booleans', {}).get(value)
        if name == 'multichoicedefault' and index == 4:
            return symbols.get('booleans', {}).get(value)
        if name == 'multichoicegrid' and index == 4:
            return symbols.get('booleans', {}).get(value)
        if name == 'setweather' and index == 0:
            return symbols.get('weather', {}).get(value)
        if name == 'setmaplayoutindex' and index == 0:
            return symbols.get('layouts', {}).get(value)
        if name == 'setstepcallback' and index == 0:
            return symbols.get('step_callbacks', {}).get(value)
        if name in ('dofieldeffect', 'waitfieldeffect') and index == 0:
            return symbols.get('field_effects', {}).get(value)
        if name in ('setescapewarp', 'warp', 'setwarp') and index == 0:
            return symbols.get('maps', {}).get(value)
        if (name in ('call_if_eq', 'call_if_ne', 'call_if_lt', 'call_if_gt',
                     'call_if_le', 'call_if_ge', 'goto_if_eq', 'goto_if_ne',
                     'goto_if_lt', 'goto_if_gt', 'goto_if_le', 'goto_if_ge')
                and index == 1 and args):
            reviewed = (symbols.get('script_var_values', {})
                        .get(script_addr, {}).get(args[0], {}).get(value))
            if reviewed is not None:
                return reviewed
            return symbols.get('var_values', {}).get(args[0], {}).get(value)
        if index in MAP_ARGUMENTS.get(name, ()):
            return symbols.get('maps', {}).get(value)
        if index in LOCAL_ID_ARGUMENTS.get(name, ()):
            if name == 'waitmovement' and value == 0:
                return '0'
            local = symbols.get('local_ids', {}).get(value)
            if local is not None:
                return local
            return symbols.get('vars', {}).get(value)
        if name == 'turnobject' and index == 1:
            return symbols.get('directions', {}).get(value)
        if name == 'setobjectmovementtype' and index == 1:
            return symbols.get('movement_types', {}).get(value)
        return None

    return format_symbol


def omit_implicit_special_waitstates(lines, implicit_specials):
    """Do not re-emit a waitstate already supplied by a reviewed special.

    ``special`` injects its own waitstate when the matching ``def_special``
    entry says so.  Keeping the decoded explicit byte would assemble exactly,
    but leaves a warning-only redundant line and diverges from the US source.
    This map-local allowlist is used only after the special table itself has
    been checked against the JP byte stream.
    """
    implicit_specials = set(implicit_specials)
    if not implicit_specials:
        return lines
    out = []
    index = 0
    while index < len(lines):
        name, argstr = lines[index]
        if (name in ('special', 'specialvar')
                and argstr.rsplit(',', 1)[-1].strip() in implicit_specials
                and index + 1 < len(lines)
                and lines[index + 1][0] == 'waitstate'):
            out.append((name, argstr))
            index += 2
            continue
        out.append((name, argstr))
        index += 1
    return out


def semantic_map_variable(mname, value):
    """Render a reviewed map-script table variable, if one is available."""
    return (MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {})
            .get('symbols', {}).get('vars', {}).get(value))


def map_entries(include_empty=False):
    """Return sorted [(table_addr, map_name, gi, mi, entries, events)].

    ``include_empty`` retains maps whose table is a single zero terminator.
    Those tables are the missing structural owners behind many US
    ``data/maps/<Map>/scripts.inc`` paths.
    """
    out = []
    for entry in MAP_HEADERS:
        gi, mi, h, layout, events, ms, wild, name_hex = entry
        mname = MAP_NAMES.get((gi, mi))
        if mname is None:
            continue
        ms = toi(ms)
        if ms == 0:
            continue
        tables = MAP_TABLES.get(hex(ms))
        if tables is None:
            tables = MAP_TABLES.get('%x' % ms)
        if tables is None:
            continue
        if not tables and not include_empty:
            continue
        entries = [(toi(t), toi(p)) for t, p in tables]
        out.append((ms, mname, gi, mi, entries, toi(events)))
    out.sort(key=lambda x: x[0])
    return out


def map_events_scripts(events_addr):
    """Script pointers from a MapEvents structure (obj/coord/bg)."""
    rom = sp.ROM
    obj_count = rom[events_addr - 0x08000000]
    coord_count = rom[events_addr - 0x08000000 + 2]
    bg_count = rom[events_addr - 0x08000000 + 3]
    objs = sp.rd32(events_addr + 4)
    coords = sp.rd32(events_addr + 12)
    bgs = sp.rd32(events_addr + 16)
    scripts = []
    for i in range(obj_count):
        s = sp.rd32(objs + i * 0x18 + 0x10)
        if s and s != 0xFFFFFFFF:
            scripts.append(('obj%d' % i, s))
    for i in range(coord_count):
        s = sp.rd32(coords + i * 0x10 + 0xC)
        if s and s != 0xFFFFFFFF:
            scripts.append(('coord%d' % i, s))
    for i in range(bg_count):
        kind = rom[bgs + i * 0xC - 0x08000000 + 0x5]
        s = sp.rd32(bgs + i * 0xC + 0x8)
        if kind <= 4 and s and s != 0xFFFFFFFF:
            scripts.append(('bg%d' % i, s))
    return scripts


def parse_frame_table(addr):
    """tag 2/4 table: (u16 var, u16 compare, .4byte script) until var==0."""
    items = []
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            break
        cmp = sp.rd16(pos + 2)
        script = sp.rd32(pos + 4)
        items.append((var, cmp, script))
        pos += 8
    return items


def collect_map_scripts(map_addr, map_name, extra_addrs=None, events_addr=None,
                        region_end=None):
    """Parse all scripts reachable from the map-script table."""
    extra_addrs = extra_addrs or []
    tables = MAP_TABLES.get(hex(map_addr))
    if tables is None:
        tables = MAP_TABLES.get('%x' % map_addr)
    if tables is None:
        return {}, set()
    scripts = {}   # addr -> script instr list
    text_ptrs = set()
    queue = []
    for tag, ptr in tables:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            for var, cmp, sptr in parse_frame_table(p):
                if sptr not in scripts and \
                        (region_end is None or map_addr <= sptr < region_end):
                    queue.append(sptr)
        else:
            if p not in scripts and (region_end is None or map_addr <= p < region_end):
                queue.append(p)
    for a in extra_addrs:
        if a not in scripts and (region_end is None or map_addr <= a < region_end):
            queue.append(a)
    if events_addr:
        for name, s in map_events_scripts(events_addr):
            if s not in scripts and (region_end is None or map_addr <= s < region_end):
                queue.append(s)
    while queue:
        addr = queue.pop()
        script = sp.parse_script(addr)
        if script is None:
            continue
        scripts[addr] = script
        for off, name, args, refs in script:
            if name in TEXT_POINTER_ARGUMENTS:
                for idx in TEXT_POINTER_ARGUMENTS[name]:
                    if len(args) > idx and 0x08000000 <= args[idx] < 0x0A000000:
                        text_ptrs.add(args[idx])
            elif name == 'trainerbattle':
                for idx in sp.trainerbattle_text_arg_indexes(args):
                    if 0x08000000 <= args[idx] < 0x0A000000:
                        text_ptrs.add(args[idx])
            for r in refs:
                if r not in scripts and r not in queue and \
                        (region_end is None or map_addr <= r < region_end):
                    queue.append(r)
    # de-overlap: truncate scripts that extend into another script entry
    entries = set(scripts)
    for addr in sorted(scripts):
        inner = [e for e in entries if addr < e]
        if not inner:
            continue
        cut = min(inner)
        new_script = []
        pos = addr
        for instr in scripts[addr]:
            d = sp.decode_instruction(pos)
            if d is None or pos >= cut:
                break
            new_script.append(instr)
            pos += d[0]
        if len(new_script) != len(scripts[addr]):
            scripts[addr] = new_script
    return scripts, text_ptrs


def script_ranges(scripts):
    """Covered byte ranges of script instructions."""
    ranges = []
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            # size unknown here; recompute via decode at pos
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            ranges.append((pos, pos + size))
            pos += size
    return ranges


def map_table_bytes(ms, entries):
    """Mark bytes of the map-script table (5-byte entries until tag 0)."""
    covered = set()
    pos = ms
    while True:
        tag = sp.rd8(pos)
        if tag == 0:
            covered.add(pos)
            break
        covered.update(range(pos, pos + 5))
        pos += 5
    return covered


def frame_table_bytes(addr):
    covered = set()
    pos = addr
    while True:
        var = sp.rd16(pos)
        if var == 0:
            covered.update(range(pos, pos + 2))
            break
        covered.update(range(pos, pos + 8))
        pos += 8
    return covered


def text_range(tp, region_end):
    """Return one verified EOS-terminated text span, or None if uncertain."""
    raw = ROM[tp - 0x08000000:region_end - 0x08000000]
    try:
        decoded = TEXT_CODEC.verify_one(raw)
    except (TextDecodeError, TextRoundTripError):
        return None
    return tp, tp + decoded.consumed


def emit_map(ms, mname, gi, mi, entries, region_end, global_text_ptrs,
             text_label_map, region_labels=None, std_addrs=None, events_addr=None):
    std_addrs = std_addrs or set()
    semantic = MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {})
    verified_script_labels = semantic.get('scripts', {})
    verified_table_labels = semantic.get('tables', {})
    verified_text_labels = semantic.get('texts', {})
    external_text_labels = semantic.get('external_texts', {})
    external_labels = semantic.get('external_labels', {})
    field_placeholders = semantic.get('field_placeholders', {})
    special_aliases = semantic.get('specials', {})
    script_aliases = semantic.get('script_aliases', {})
    preserve_region_script_aliases = semantic.get('preserve_region_script_aliases', True)
    preserve_region_text_aliases = semantic.get('preserve_region_text_aliases', True)
    implicit_waitstate_specials = semantic.get('implicit_waitstate_specials', ())
    shop_lists = {}
    for raw_start, label, products in MAP_POKEMART_LISTS.get(mname, ()):
        data_start = (raw_start + 3) & ~3
        end = data_start + len(products) * 2 + 4
        if not (ms <= raw_start <= data_start < end <= region_end):
            raise RuntimeError(
                'shop list %s is outside %s script range' % (label, mname))
        padding = ROM[raw_start - 0x08000000:data_start - 0x08000000]
        trailer = ROM[end - 4 - 0x08000000:end - 0x08000000]
        if any(padding) or trailer != b'\0\0\x6c\x02':
            raise RuntimeError(
                'shop list %s does not match JP padding or terminator' % label)
        shop_lists[raw_start] = (label, products, data_start, end)
    extra = [
        a
        for a in (*std_addrs, *MAP_AUXILIARY_SCRIPT_ADDRESSES.get(mname, ()))
        if ms <= a < region_end
    ]
    scripts, text_ptrs = collect_map_scripts(ms, mname, extra, events_addr, region_end)
    missing_scripts = set(verified_script_labels) - set(scripts)
    if missing_scripts:
        raise RuntimeError(
            'verified semantic script labels are not reachable for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_scripts))))
    text_ptrs.update(
        addr for addr in MAP_AUXILIARY_TEXT_ADDRESSES.get(mname, ())
        if ms <= addr < region_end)
    reviewed_movement_labels = {
        addr: label
        for addr, label in MAP_MOVEMENT_SCRIPT_LABELS.get(mname, {}).items()
        if ms <= addr < region_end
    }
    auto_movement_targets = (
        referenced_movement_addresses(scripts, ms, region_end)
        - set(reviewed_movement_labels)
    )
    # Some maps intentionally point at suffixes inside another movement
    # stream.  Emitting both as independent objects would duplicate bytes;
    # leave every overlapping auto candidate raw until the source emitter can
    # represent an interior label.  Reviewed entries retain the existing
    # strict overlap check below.
    auto_ranges = {}
    for addr in auto_movement_targets:
        decoded = decode_movement_script(addr, region_end)
        if decoded is not None:
            auto_ranges[addr] = (addr, decoded[1])
    overlapping_auto_targets = set()
    for left_addr, left_range in auto_ranges.items():
        for right_addr, right_range in auto_ranges.items():
            if left_addr >= right_addr:
                continue
            if max(left_range[0], right_range[0]) < min(left_range[1], right_range[1]):
                overlapping_auto_targets.update((left_addr, right_addr))
    auto_movement_targets = set(auto_ranges) - overlapping_auto_targets
    movement_labels = {
        addr: reviewed_movement_labels.get(
            addr, '%s_Movement_%08X' % (mname, addr & 0xFFFFFF))
        for addr in (
            set(reviewed_movement_labels)
            | auto_movement_targets
        )
    }
    movements = {}
    for addr, label in movement_labels.items():
        decoded = decode_movement_script(addr, region_end)
        if decoded is None:
            raise RuntimeError(
                'cannot prove movement script %s at 0x%08X' % (label, addr))
        actions, end = decoded
        movements[addr] = (label, actions, end)
    region_labels = region_labels or {}
    label_map = {}
    for addr in sorted(scripts):
        if addr in std_addrs:
            label_map[addr] = region_labels.get(addr, 'gUnknown_%08X' % (addr & 0xFFFFFF))
        else:
            label_map[addr] = verified_script_labels.get(
                addr, '%s_EventScript_%08X' % (mname, addr & 0xFFFFFF))
    label_map.update(movement_labels)
    label_map.update({
        data_start: label
        for label, _products, data_start, _end in shop_lists.values()
    })
    # byte coverage
    covered = collections.defaultdict(str)
    for a in range(ms, region_end):
        covered[a] = 'raw'
    for addr, script in scripts.items():
        pos = addr
        for off, name, args, refs in script:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size = r[0]
            for b in range(pos, pos + size):
                covered[b] = 'script'
            pos += size
    for addr, (_label, _actions, end) in movements.items():
        if any(covered[b] != 'raw' for b in range(addr, end)):
            raise RuntimeError('movement script overlaps decoded data at 0x%08X' % addr)
        for b in range(addr, end):
            covered[b] = 'movement'
    table_addrs = {ms: 'map'}
    for tag, ptr in entries:
        t, p = toi(tag), toi(ptr)
        if t in (2, 4):
            table_addrs[p] = 'frame'
    for ta, kind in table_addrs.items():
        if kind == 'map':
            for b in map_table_bytes(ms, entries):
                covered[b] = 'table'
        else:
            if ms <= ta < region_end:
                for b in frame_table_bytes(ta):
                    covered[b] = 'table'
    missing_tables = set(verified_table_labels) - set(table_addrs)
    if missing_tables:
        raise RuntimeError(
            'verified semantic map-table labels are absent for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_tables))))
    text_ranges = []
    for tp in sorted(global_text_ptrs | text_ptrs):
        if not (ms <= tp < region_end):
            continue
        result = text_range(tp, region_end)
        if result is None:
            # It remains in the surrounding raw segment.  Do not emit source
            # text unless its terminator and every control byte are proved.
            continue
        a, b = result
        text_ranges.append((a, b))
        for x in range(a, b):
            covered[x] = 'text'
    for raw_start, (label, _products, _data_start, end) in shop_lists.items():
        if any(covered[b] != 'raw' for b in range(raw_start, end)):
            raise RuntimeError('shop list overlaps decoded data: %s' % label)
        for b in range(raw_start, end):
            covered[b] = 'shop_list'
    # A pointer found through another map's script graph is not necessarily
    # defined by a checked-in gJPText_* label yet.  Render only labels emitted
    # by this map; leave external text pointers numeric until their owning
    # source range has been converted and defines the symbol.
    emitted_text_label_map = {}
    for tp, _ in text_ranges:
        emitted_text_label_map[tp] = verified_text_labels.get(
            tp, 'gJPText_%08X' % (tp & 0xFFFFFF))
    missing_texts = set(verified_text_labels) - set(emitted_text_label_map)
    if missing_texts:
        raise RuntimeError(
            'verified semantic text labels are not emitted for %s: %s' % (
                mname, ', '.join('0x%08X' % addr for addr in sorted(missing_texts))))
    missing_placeholder_texts = set(field_placeholders) - set(emitted_text_label_map)
    if missing_placeholder_texts:
        raise RuntimeError(
            'field placeholder metadata has no emitted text for %s: %s' % (
                mname,
                ', '.join('0x%08X' % addr for addr in sorted(missing_placeholder_texts))))
    reference_text_label_map = dict(emitted_text_label_map)
    reference_text_label_map.update(external_text_labels)
    reference_label_map = dict(label_map)
    reference_label_map.update(external_labels)
    # build segments in address order
    segs = []
    segs.append((ms, 'map_table', 0))
    for ta in sorted(table_addrs):
        if table_addrs[ta] == 'frame' and ms <= ta < region_end:
            segs.append((ta, 'frame_table', 0))
    for addr in scripts:
        pos = addr
        size = 0
        for off, name, args, refs in scripts[addr]:
            r = sp.decode_instruction(pos)
            if r is None:
                break
            size += r[0]
            pos += r[0]
        segs.append((addr, 'script', addr))
    for addr in movements:
        segs.append((addr, 'movement', addr))
    for raw_start in shop_lists:
        segs.append((raw_start, 'shop_list', raw_start))
    for tp, end in text_ranges:
        segs.append((tp, 'text', tp))
    # raw gaps
    raw_start = None
    for a in range(ms, region_end):
        if covered[a] == 'raw' and raw_start is None:
            raw_start = a
        elif covered[a] != 'raw' and raw_start is not None:
            segs.append((raw_start, 'raw', raw_start))
            raw_start = None
    if raw_start is not None:
        segs.append((raw_start, 'raw', raw_start))
    segs.sort(key=lambda x: x[0])
    # emit in address order
    lines = ['@ %s scripts (JP map g%d m%d @ 0x%08X)' % (mname, gi, mi, ms), '']
    nraw = 0
    for start, kind, payload in segs:
        if kind == 'map_table':
            old = region_labels.get(ms)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, ms))
            lines.append('%s_MapScripts::' % mname)
            for tag, ptr in entries:
                t, p = toi(tag), toi(ptr)
                if t in (2, 4):
                    if ms <= p < region_end:
                        tbl = verified_table_labels.get(
                            p, '%s_MapScriptTable_%08X' % (mname, p & 0xFFFFFF))
                        lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), tbl))
                    elif p in external_labels:
                        lines.append('\tmap_script %s, %s' % (
                            MAP_SCRIPT_NAMES.get(t, str(t)), external_labels[p]))
                    else:
                        lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
                elif p in label_map or p in external_labels:
                    lines.append('\tmap_script %s, %s' % (
                        MAP_SCRIPT_NAMES.get(t, str(t)),
                        label_map.get(p) or external_labels[p]))
                else:
                    lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
            lines.append('\t.byte 0')
            lines.append('')
        elif kind == 'frame_table':
            table_label = verified_table_labels.get(
                start, '%s_MapScriptTable_%08X' % (mname, start & 0xFFFFFF))
            lines.append('%s:: @ 0x%08X' % (table_label, start))
            for var, cmp, sptr in parse_frame_table(start):
                rendered_var = semantic_map_variable(mname, var) or '0x%X' % var
                rendered_cmp = semantic_map_variable(mname, cmp) or '0x%X' % cmp
                script_label = label_map.get(sptr) or external_labels.get(sptr)
                if script_label is not None:
                    lines.append('\tmap_script_2 %s, %s, %s' % (
                        rendered_var, rendered_cmp, script_label))
                else:
                    lines.append('\tmap_script_2 %s, %s, 0x%08X' % (
                        rendered_var, rendered_cmp, sptr))
            lines.append('\t.2byte 0')
            lines.append('')
        elif kind == 'script':
            addr = payload
            old = region_labels.get(addr) if addr not in std_addrs else None
            aliases = []
            if (preserve_region_script_aliases
                    and old and old != label_map[addr]):
                aliases.append(old)
            aliases.extend(script_aliases.get(addr, ()))
            for alias in dict.fromkeys(aliases):
                if alias != label_map[addr]:
                    lines.append('\t.globl %s' % alias)
                    lines.append('%s: @ 0x%08X' % (alias, addr))
            lines.append('%s:: @ 0x%08X' % (label_map[addr], addr))
            symbol_formatter = semantic_symbol_formatter(mname, addr)
            decoded_lines = sp.decode_script_lines(
                scripts[addr], reference_label_map, reference_text_label_map, symbol_formatter)
            command_aliases = semantic.get('command_aliases', {}).get(addr, {})
            decoded_lines = [
                (command_aliases.get(
                    name, CANONICAL_SCRIPT_COMMAND_NAMES.get(name, name)), argstr)
                for name, argstr in decoded_lines
            ]
            remapped_specials = []
            for name, argstr in decoded_lines:
                if name == 'special':
                    argstr = special_aliases.get(argstr, argstr)
                elif name == 'specialvar':
                    # A specialvar carries the destination followed by the
                    # special. Rename only that latter operand so semantic
                    # aliases remain byte-exact for both command forms.
                    parts = [part.strip() for part in argstr.split(',', 1)]
                    if len(parts) == 2:
                        argstr = '%s, %s' % (
                            parts[0], special_aliases.get(parts[1], parts[1]))
                remapped_specials.append((name, argstr))
            decoded_lines = remapped_specials
            decoded_lines = collapse_msgbox_macros(decoded_lines)
            decoded_lines = collapse_trainerbattle_macros(decoded_lines)
            decoded_lines = collapse_register_matchcall_macros(decoded_lines)
            decoded_lines = collapse_condition_macros(decoded_lines)
            decoded_lines = collapse_switch_macros(
                decoded_lines,
                semantic.get('symbols', {}).get('switch_values', {}),
                1 if semantic.get('allow_single_case_switch') else 2)
            decoded_lines = collapse_coordinate_warp_macros(decoded_lines)
            decoded_lines = collapse_frontier_utility_macros(
                decoded_lines, semantic.get('frontier_macros', False))
            decoded_lines = collapse_frontier_results_macros(
                decoded_lines,
                semantic.get('symbols', {}).get('frontier_results', {}))
            decoded_lines = collapse_giveitem_macros(decoded_lines)
            decoded_lines = collapse_finditem_macros(decoded_lines)
            decoded_lines = collapse_givedecoration_macros(decoded_lines)
            decoded_lines = omit_implicit_special_waitstates(
                decoded_lines, implicit_waitstate_specials)
            decoded_lines = omit_default_macro_arguments(decoded_lines)
            decoded_lines = annotate_literal_copyvars(decoded_lines)
            decoded_lines = name_contextual_result_conditions(decoded_lines)
            for name, argstr in decoded_lines:
                if argstr:
                    lines.append('\t%s %s' % (name, argstr))
                else:
                    lines.append('\t%s' % name)
            lines.append('')
        elif kind == 'movement':
            label, actions, _end = movements[payload]
            lines.append('%s:' % label)
            for action in actions:
                lines.append('\t%s' % action)
            lines.append('')
        elif kind == 'shop_list':
            label, products, _data_start, _end = shop_lists[payload]
            lines.append('\t.align 2')
            lines.append('%s:' % label)
            for product in products:
                lines.append('\t.2byte %s' % product)
            lines.append('\tpokemartlistend')
            lines.append('')
        elif kind == 'text':
            tp = payload
            end = text_ranges[[x[0] for x in text_ranges].index(tp)][1]
            raw = ROM[tp - 0x08000000:end - 0x08000000]
            dec = decode_text(raw, field_placeholders.get(tp))
            if dec is None:
                lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                    tp - 0x08000000, end - tp))
                nraw += 1
                continue
            label = emitted_text_label_map[tp]
            if label.startswith('gJPText_'):
                lines.append('\t.globl %s' % label)
            lines.append('%s: @ 0x%08X' % (label, tp))
            aliases = []
            old = region_labels.get(tp)
            if preserve_region_text_aliases and old and old != label:
                aliases.append(old)
            aliases.extend(semantic.get('text_aliases', {}).get(tp, ()))
            for alias in dict.fromkeys(aliases):
                if alias != label:
                    lines.append('\t.globl %s' % alias)
                    lines.append('%s:' % alias)
            parts = [p for p in re.split(r'(?<=\\l|\\p|\\n)', dec) if p]
            for k, part in enumerate(parts):
                if k == len(parts) - 1 and dec.endswith('$'):
                    lines.append('\t.string "%s$"' % part.rstrip('$'))
                else:
                    lines.append('\t.string "%s"' % part)
            lines.append('')
        elif kind == 'raw':
            a = start
            b = region_end
            next_kind = None
            for s2, k2, p2 in segs:
                if k2 != 'raw' and s2 > a:
                    if s2 < b:
                        b = s2
                        next_kind = k2
            # A Pokemart list emits its own four-byte alignment.  Preserve a
            # zero-only alignment gap by letting that directive generate the
            # bytes, rather than concealing a trivial padding fragment inside
            # a map-local scripts.inc incbin.
            raw = ROM[a - 0x08000000:b - 0x08000000]
            if (next_kind == 'shop_list'
                    and b == ((a + 3) & ~3)
                    and raw == b'\0' * (b - a)):
                continue
            old = region_labels.get(a)
            if old:
                lines.append('%s:: @ 0x%08X' % (old, a))
            lines.append('\t.incbin "baserom_jp.gba", 0x%x, 0x%x' % (
                a - 0x08000000, b - a))
            nraw += 1
    return '\n'.join(lines).rstrip() + '\n', len(text_ranges), nraw


def collect_all_text_ptrs(entries):
    """Global set of text pointers reachable from map scripts."""
    all_ptrs = set()
    for ms, mname, gi, mi, ents, events_addr in entries:
        _, tptrs = collect_map_scripts(
            ms,
            mname,
            MAP_AUXILIARY_SCRIPT_ADDRESSES.get(mname, ()),
            events_addr,
        )
        all_ptrs |= tptrs
    return all_ptrs


def apply_us_label_sequence_metadata():
    """Populate reviewed script/table names from a checked US label sequence.

    This is deliberately narrower than a generic text replacement: only maps
    named in ``MAP_US_LABEL_SEQUENCE_COUNTS`` participate, every JP entry must
    expose a ROM address, and the exact expected entry count is checked before
    an address is associated with a US semantic label.
    """
    for mname, expected_count in MAP_US_LABEL_SEQUENCE_COUNTS.items():
        jp_path = ROOT / 'data' / 'maps' / mname / 'scripts.inc'
        us_path = US_MAPS / mname / 'scripts.inc'
        if not jp_path.is_file() or not us_path.is_file():
            raise RuntimeError('missing reviewed map source for %s' % mname)

        entry_pattern = (
            r'EventScript(?:_[A-Za-z0-9_]+)?|OnTransition|OnFrame|'
            r'MapScriptTable(?:_[A-Za-z0-9_]+)?')
        if mname in MAP_US_LABEL_SEQUENCE_INCLUDE_ONLOAD:
            entry_pattern += r'|OnLoad'
        label_re = re.compile(
            r'^(%s_(?:%s)):{1,2}' % (re.escape(mname), entry_pattern))
        address_re = re.compile(r'@\s*(0x08[0-9A-Fa-f]{6})\b')
        suffix_re = re.compile(r'_([0-9A-Fa-f]{8})$')

        jp_entries = []
        for line in jp_path.read_text(encoding='utf-8').splitlines():
            match = label_re.match(line)
            if match is None:
                continue
            label = match.group(1)
            address_match = address_re.search(line)
            if address_match is not None:
                address = int(address_match.group(1), 16)
            else:
                suffix_match = suffix_re.search(label)
                if suffix_match is None:
                    raise RuntimeError(
                        'reviewed JP label %s lacks a ROM address' % label)
                address = 0x08000000 | int(suffix_match.group(1), 16)
            jp_entries.append((label, address, 'MapScriptTable_' in label))

        us_entries = []
        for line in us_path.read_text(encoding='utf-8').splitlines():
            match = label_re.match(line)
            if match is not None:
                us_entries.append(match.group(1))

        if len(jp_entries) != expected_count or len(us_entries) != expected_count:
            raise RuntimeError(
                'reviewed label sequence count mismatch for %s: JP=%d US=%d expected=%d'
                % (mname, len(jp_entries), len(us_entries), expected_count))
        if len({address for _label, address, _is_table in jp_entries}) != len(jp_entries):
            raise RuntimeError('duplicate JP map-script address in %s' % mname)

        table_addresses = {
            pointer
            for _map_addr, map_name, _gi, _mi, entries, _events_addr
            in map_entries(include_empty=True)
            if map_name == mname
            for tag, pointer in entries
            if tag in (2, 4)
        }
        semantic = MAP_VERIFIED_SEMANTIC_LABELS.setdefault(mname, {})
        scripts = semantic.setdefault('scripts', {})
        tables = semantic.setdefault('tables', {})
        # A regenerated source already has names such as ``OnFrame`` rather
        # than the old ``MapScriptTable_xxxxxxxx`` spelling, so classify by
        # the ROM's actual map-script-table pointers instead of label text.
        for address in table_addresses:
            scripts.pop(address, None)
        for (_jp_label, address, _is_table), us_label in zip(jp_entries, us_entries):
            is_table = address in table_addresses
            target = tables if is_table else scripts
            previous = target.get(address)
            if previous is not None and previous != us_label:
                raise RuntimeError(
                    'reviewed label mismatch for %s at 0x%08X: %s != %s'
                    % (mname, address, previous, us_label))
            target[address] = us_label

    for mname, expected_count in MAP_US_TEXT_LABEL_SEQUENCE_COUNTS.items():
        jp_path = ROOT / 'data' / 'maps' / mname / 'scripts.inc'
        us_path = US_MAPS / mname / 'scripts.inc'
        if not jp_path.is_file() or not us_path.is_file():
            raise RuntimeError('missing reviewed map text source for %s' % mname)

        address_re = re.compile(r'@\s*(0x08[0-9A-Fa-f]{6})\b')
        generic_re = re.compile(r'^gJPText_[0-9A-Fa-f]+:{1,2}')
        semantic_re = re.compile(
            r'^(%s_Text_[A-Za-z0-9_]+):{1,2}' % re.escape(mname))
        generic_entries = []
        semantic_entries = []
        for line in jp_path.read_text(encoding='utf-8').splitlines():
            address_match = address_re.search(line)
            if address_match is None:
                continue
            address = int(address_match.group(1), 16)
            if generic_re.match(line):
                generic_entries.append(address)
            elif semantic_re.match(line):
                semantic_entries.append(address)
        # The initial JP source has generic gJPText labels.  Once regenerated
        # with preserve_region_text_aliases=False it instead has the semantic
        # labels, so support both states while enforcing one exact sequence.
        jp_entries = (generic_entries if len(generic_entries) == expected_count
                      else semantic_entries)
        us_entries = []
        for line in us_path.read_text(encoding='utf-8').splitlines():
            match = semantic_re.match(line)
            if match is not None:
                us_entries.append(match.group(1))
        if len(jp_entries) != expected_count or len(us_entries) != expected_count:
            raise RuntimeError(
                'reviewed text sequence count mismatch for %s: JP=%d US=%d expected=%d'
                % (mname, len(jp_entries), len(us_entries), expected_count))
        if len(set(jp_entries)) != len(jp_entries):
            raise RuntimeError('duplicate JP text address in %s' % mname)

        semantic = MAP_VERIFIED_SEMANTIC_LABELS.setdefault(mname, {})
        texts = semantic.setdefault('texts', {})
        for address, us_label in zip(jp_entries, us_entries):
            previous = texts.get(address)
            if previous is not None and previous != us_label:
                raise RuntimeError(
                    'reviewed text mismatch for %s at 0x%08X: %s != %s'
                    % (mname, address, previous, us_label))
            texts[address] = us_label


def event_script_symbol_addresses():
    """Return every source label that has a known JP ROM address."""
    apply_us_label_sequence_metadata()
    labels = {}

    def add_reviewed(name, address):
        previous = labels.get(name)
        if previous is not None and previous != address:
            raise RuntimeError(
                'reviewed event symbol %s has conflicting addresses '
                '0x%08X and 0x%08X' % (name, previous, address))
        labels[name] = address

    # A newly structured group can contain circular cross-map references.
    # Make every reviewed semantic name available to the temporary assembler
    # before any one member has been written to disk; this keeps verification
    # independent of migration order without accepting guessed addresses.
    for semantic in MAP_VERIFIED_SEMANTIC_LABELS.values():
        for category in ('scripts', 'tables', 'texts',
                         'external_labels', 'external_texts'):
            for address, name in semantic.get(category, {}).items():
                add_reviewed(name, address)
        for address, aliases in semantic.get('text_aliases', {}).items():
            for name in aliases:
                add_reviewed(name, address)
    for movements in MAP_MOVEMENT_SCRIPT_LABELS.values():
        for address, name in movements.items():
            add_reviewed(name, address)
    for shop_lists in MAP_POKEMART_LISTS.values():
        for raw_start, name, _products in shop_lists:
            add_reviewed(name, (raw_start + 3) & ~3)

    for p in (ROOT / 'data' / 'scripts').glob('gUnknown_*.inc'):
        add_reviewed(p.stem, int(p.stem[len('gUnknown_'):], 16))
    sources = [ROOT / 'data' / 'event_scripts.s']
    sources.extend(sorted((ROOT / 'data' / 'scripts').rglob('*.inc')))
    sources.extend(sorted((ROOT / 'data' / 'text').rglob('*.inc')))
    # Map-local labels can be valid external references when the original JP
    # ROM packs one map's text into the next map's physical interval.
    sources.extend(sorted((ROOT / 'data' / 'maps').rglob('scripts.inc')))
    for source in sources:
        for line in source.read_text(encoding='utf-8').splitlines():
            m = re.match(r'^([A-Za-z_][A-Za-z0-9_]*):{1,2}\s*@\s*0x([0-9A-Fa-f]+)', line)
            if m:
                labels.setdefault(m.group(1), int(m.group(2), 16))
                continue
            # Transitional source may expose a reviewed semantic name for a
            # script that still lives inside a larger raw owner block.  Only
            # accept literal ROM-address aliases; symbolic expressions remain
            # unresolved until their physical owner is structured.
            m = re.match(
                r'^\s*\.set\s+([A-Za-z_][A-Za-z0-9_]*),\s*'
                r'(0x08[0-9A-Fa-f]{6})\s*(?:@.*)?$',
                line,
            )
            if m:
                labels.setdefault(m.group(1), int(m.group(2), 16))
    return labels


def event_script_labels():
    """Return one stable primary label for each known JP ROM address."""
    labels = {}
    for name, address in event_script_symbol_addresses().items():
        labels.setdefault(address, name)
    return labels


def main():
    do_write = '--write' in sys.argv
    include_empty = '--include-empty' in sys.argv
    args = [a for a in sys.argv[1:] if a not in ('--write', '--include-empty')]
    m = args[0] if args else None
    entries = map_entries(include_empty=include_empty or m is not None)
    print('maps:', len(entries))
    global_text_ptrs = collect_all_text_ptrs(entries)
    print('global text ptrs:', len(global_text_ptrs))
    text_label_map = {p: 'gJPText_%08X' % (p & 0xFFFFFF) for p in global_text_ptrs}
    all_labels = event_script_labels()
    map_starts = {e[0] for e in entries}
    nonmap = sorted(a for a in all_labels if a not in map_starts)
    last_map_end = next((a for a in nonmap if a > entries[-1][0]), 0x0828F000)
    print('last map region end:', hex(last_map_end))
    total_raw = 0
    total_text = 0
    for i, (ms, mname, gi, mi, ents, events_addr) in enumerate(entries):
        if m and mname != m:
            continue
        if i > 0 and ms == entries[i - 1][0]:
            if not m:
                continue  # shared map-script table; emitted with the first map
        j = i + 1
        while j < len(entries) and entries[j][0] == ms:
            j += 1
        natural_region_end = entries[j][0] if j < len(entries) else last_map_end
        region_end = MAP_SOURCE_REGION_ENDS.get(mname, natural_region_end)
        if not ms < region_end <= natural_region_end:
            raise RuntimeError(
                'invalid physical source end for %s: 0x%08X (natural 0x%08X)'
                % (mname, region_end, natural_region_end))
        region_labels = {a: n for a, n in all_labels.items() if ms <= a < region_end}
        if m and mname == m:
            print('region_labels for', mname, ':', len(region_labels),
                  list(region_labels.items())[:8])
        out, ntext, nraw = emit_map(ms, mname, gi, mi, ents, region_end,
                                    global_text_ptrs, text_label_map,
                                    region_labels, set(), events_addr)
        total_raw += nraw
        total_text += ntext
        if do_write:
            outdir = ROOT / 'data' / 'maps' / mname
            outdir.mkdir(parents=True, exist_ok=True)
            (outdir / 'scripts.inc').write_text(out, encoding='utf-8')
        if m:
            print('=== %s @ %08X region 0x%X texts=%d rawinc=%d ===' % (
                mname, ms, region_end - ms, ntext, nraw))
            print(out[:2500])
            return
    print('total raw incbin lines:', total_raw, 'text ranges:', total_text)


if __name__ == '__main__':
    main()
