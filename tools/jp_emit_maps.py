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
    # The up/right sandstorm guards have no live JP map-event pointer, but the
    # four adjacent direction variants are retained together in the US owner.
    'Route111': (0x081EA3A4, 0x081EA3C8),
    'RustboroCity_Gym': (0x08202410,),  # EventScript_RegisterRoxanne
}

# Verified map-local text that has no JP script pointer (for example an
# intentionally unused US-source string) and therefore is not discovered by
# the script graph.
MAP_AUXILIARY_TEXT_ADDRESSES = {
    'RustboroCity_DevonCorp_2F': (0x08201B83,),
}

# Map-owned movement scripts confirmed by their JP addresses and the matching
# US map source.  They are referenced by ``applymovement`` rather than being
# event scripts, so the event-script parser deliberately does not follow them.
MAP_MOVEMENT_SCRIPT_LABELS = {
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

# Shared text is stored separately from map script-data.  A block enters this
# allowlist only after its raw owner, every EOS boundary, every caller, and
# the matching US text order have been checked.  jp_text_blocks.py reads this
# same mapping, so source labels and map references cannot drift apart.
VERIFIED_SHARED_TEXT_BLOCKS = {
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
}

# Reviewed JP-to-US names for maps whose event positions, control-flow shape,
# and text/movement ordering have all been checked against the US source.  This
# is intentionally an allowlist: unreviewed addresses keep deterministic
# address labels instead of receiving a plausible-but-unproven semantic name.
MAP_VERIFIED_SEMANTIC_LABELS = {
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
    # one-for-one against the corresponding US map sources.  One additional
    # JP-only arrival text at 0x081E8B34 intentionally stays address-named.
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
        'text_aliases': {0x081E83B3: ('gJPText_001E83B3',)},
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
        },
    },
}

MAP_MOVEMENT_SCRIPT_LABELS.update({
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
        elif battle_type == 'TRAINER_BATTLE_DOUBLE' and len(parts) == 6:
            out.append(('trainerbattle_double', ', '.join((trainer, parts[3], parts[4], parts[5]))))
        elif battle_type == 'TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE' and len(parts) == 7:
            out.append(('trainerbattle_double', ', '.join((trainer, parts[3], parts[4], parts[5], parts[6]))))
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
    'setobjectmovementtype': {0},
    'setobjectsubpriority': {0},
    'showobject_at': {0},
    'turnobject': {0},
    'waitmovement_at': {0},
}
MAP_ARGUMENTS = {
    'addobject_at': {1},
    'applymovement_at': {2},
    'hideobject_at': {1},
    'removeobject_at': {1},
    'resetobjectsubpriority': {1},
    'setobjectsubpriority': {1},
    'showobject_at': {1},
    'waitmovement_at': {1},
}
ITEM_ARGUMENTS = {
    'giveitem': {0},
}


def semantic_symbol_formatter(mname):
    """Return a conservative formatter for reviewed map-script constants."""
    symbols = MAP_VERIFIED_SEMANTIC_LABELS.get(mname, {}).get('symbols', {})
    if not symbols:
        return None

    def format_symbol(name, index, value, args):
        if name in FLAG_ARGUMENTS and index == 0:
            return symbols.get('flags', {}).get(value)
        if name == 'trainerbattle' and index == 1:
            return symbols.get('trainers', {}).get(value)
        if index in VARIABLE_ARGUMENTS.get(name, ()):
            return symbols.get('vars', {}).get(value)
        # The meaning of a comparison value is defined by the variable it is
        # compared against.  Keep this strictly map-local and allowlisted so
        # an unrelated numeric result is never assigned a plausible name.
        if name == 'compare_var_to_value' and index == 1 and args:
            return symbols.get('var_values', {}).get(args[0], {}).get(value)
        if (name == 'setvar' and index == 1 and args
                and args[0] == 0x8004):
            return symbols.get('trainers', {}).get(value)
        if name == 'setorcopyvar' and index == 1 and args and args[0] == 0x8000:
            return (symbols.get('items', {}).get(value)
                    or symbols.get('trainers', {}).get(value))
        if index in ITEM_ARGUMENTS.get(name, ()):
            return symbols.get('items', {}).get(value)
        if name in ('playbgm', 'playfanfare', 'savebgm', 'fadenewbgm') and index == 0:
            return symbols.get('songs', {}).get(value)
        if name == 'playbgm' and index == 1:
            return symbols.get('booleans', {}).get(value)
        if name == 'playse' and index == 0:
            return symbols.get('sounds', {}).get(value)
        if name == 'setmetatile' and index == 2:
            return symbols.get('metatiles', {}).get(value)
        if name == 'setmetatile' and index == 3:
            return symbols.get('booleans', {}).get(value)
        if name == 'playmoncry' and index == 0:
            return symbols.get('species', {}).get(value)
        if name == 'multichoicedefault' and index == 2:
            return symbols.get('multichoices', {}).get(value)
        if name == 'setweather' and index == 0:
            return symbols.get('weather', {}).get(value)
        if name == 'setstepcallback' and index == 0:
            return symbols.get('step_callbacks', {}).get(value)
        if name in ('dofieldeffect', 'waitfieldeffect') and index == 0:
            return symbols.get('field_effects', {}).get(value)
        if name == 'warp' and index == 0:
            return symbols.get('maps', {}).get(value)
        if index in MAP_ARGUMENTS.get(name, ()):
            return symbols.get('maps', {}).get(value)
        if index in LOCAL_ID_ARGUMENTS.get(name, ()):
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
    symbol_formatter = semantic_symbol_formatter(mname)
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
    movement_labels = {
        addr: label
        for addr, label in MAP_MOVEMENT_SCRIPT_LABELS.get(mname, {}).items()
        if ms <= addr < region_end
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
                    else:
                        lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
                elif p in label_map:
                    lines.append('\tmap_script %s, %s' % (MAP_SCRIPT_NAMES.get(t, str(t)), label_map[p]))
                else:
                    lines.append('\tmap_script %s, 0x%08X' % (MAP_SCRIPT_NAMES.get(t, str(t)), p))
            lines.append('\t.byte 0')
            lines.append('')
        elif kind == 'frame_table':
            table_label = verified_table_labels.get(
                start, '%s_MapScriptTable_%08X' % (mname, start & 0xFFFFFF))
            lines.append('%s::' % table_label)
            for var, cmp, sptr in parse_frame_table(start):
                rendered_var = semantic_map_variable(mname, var) or '0x%X' % var
                script_label = label_map.get(sptr) or external_labels.get(sptr)
                if script_label is not None:
                    lines.append('\tmap_script_2 %s, 0x%X, %s' % (
                        rendered_var, cmp, script_label))
                else:
                    lines.append('\tmap_script_2 %s, 0x%X, 0x%08X' % (
                        rendered_var, cmp, sptr))
            lines.append('\t.2byte 0')
            lines.append('')
        elif kind == 'script':
            addr = payload
            old = region_labels.get(addr) if addr not in std_addrs else None
            if old:
                lines.append('%s:: @ 0x%08X' % (old, addr))
            lines.append('%s::' % label_map[addr])
            decoded_lines = sp.decode_script_lines(
                scripts[addr], reference_label_map, reference_text_label_map, symbol_formatter)
            decoded_lines = [
                (name, special_aliases.get(argstr, argstr) if name == 'special' else argstr)
                for name, argstr in decoded_lines
            ]
            decoded_lines = collapse_msgbox_macros(decoded_lines)
            decoded_lines = collapse_trainerbattle_macros(decoded_lines)
            decoded_lines = collapse_register_matchcall_macros(decoded_lines)
            decoded_lines = collapse_condition_macros(decoded_lines)
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
            if old and old != label:
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
            for s2, k2, p2 in segs:
                if k2 != 'raw' and s2 > a:
                    b = min(b, s2)
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


def event_script_symbol_addresses():
    """Return every source label that has a known JP ROM address."""
    labels = {}
    for p in (ROOT / 'data' / 'scripts').glob('gUnknown_*.inc'):
        labels[p.stem] = int(p.stem[len('gUnknown_'):], 16)
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
        region_end = entries[j][0] if j < len(entries) else last_map_end
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
