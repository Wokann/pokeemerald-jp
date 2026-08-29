
#include "config.h"
#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_setup.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/comparison_operators.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/pokemon_size_record.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"

	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "asm/macros/event.inc"
	.include "constants/gba_constants.inc"
	.include "constants/global.inc"

@ This JP-located owner mirrors pokeemerald data/battle_scripts_2.s.
	.globl gBattlescriptsForBallThrow
gBattlescriptsForBallThrow: @ 0x828A290
	.4byte gUnknown_828A2F0                  @ 000
	.4byte gUnknown_828A2F0                  @ 001
	.4byte gUnknown_828A2F0                  @ 002
	.4byte gUnknown_828A2F0                  @ 003
	.4byte gUnknown_828A2F0                  @ 004
	.4byte gUnknown_828A306                  @ 005
	.4byte gUnknown_828A2F0                  @ 006
	.4byte gUnknown_828A2F0                  @ 007
	.4byte gUnknown_828A2F0                  @ 008
	.4byte gUnknown_828A2F0                  @ 009
	.4byte gUnknown_828A2F0                  @ 010
	.4byte gUnknown_828A2F0                  @ 011
	.4byte gUnknown_828A2F0                  @ 012

	.globl gBattlescriptsForUsingItem
gBattlescriptsForUsingItem: @ 0x828A2C4
	.4byte gUnknown_828A39A                  @ 000
	.4byte gUnknown_828A3A4                  @ 001
	.4byte gUnknown_828A3A4                  @ 002
	.4byte gUnknown_828A3D3                  @ 003
	.4byte gUnknown_828A3F7                  @ 004
	.4byte gUnknown_828A419                  @ 005

	.globl gBattlescriptsForRunningByItem
gBattlescriptsForRunningByItem: @ 0x828A2DC
	.4byte gUnknown_828A43B                  @ 000

	.globl gBattlescriptsForSafariActions
gBattlescriptsForSafariActions: @ 0x828A2E0
	.4byte gUnknown_828A445 @ BattleScript_ActionWatchesCarefully
	.4byte gUnknown_828A44C @ BattleScript_ActionGetNear
	.4byte gUnknown_828A455 @ BattleScript_ActionThrowPokeblock
	.4byte gUnknown_828A46B @ BattleScript_ActionWallyThrow
gUnknown_828A2F0: @ 0x828A2F0
	.include "data/scripts/gUnknown_828A2F0.inc"
gUnknown_828A306: @ 0x828A306
	.include "data/scripts/gUnknown_828A306.inc"

	.globl BattleScript_SuccessBallThrow
BattleScript_SuccessBallThrow: @ 0x828A30C
	.include "data/scripts/gUnknown_828A30C.inc"

	.globl BattleScript_WallyBallThrow
BattleScript_WallyBallThrow: @ 0x828A352
	.include "data/scripts/gUnknown_828A352.inc"

	.globl BattleScript_ShakeBallThrow
BattleScript_ShakeBallThrow: @ 0x828A35C
	.include "data/scripts/gUnknown_828A35C.inc"

	.globl BattleScript_TrainerBallBlock
BattleScript_TrainerBallBlock: @ 0x828A38A
	.include "data/scripts/gUnknown_828A38A.inc"
gUnknown_828A39A: @ 0x828A39A
	.include "data/scripts/gUnknown_828A39A.inc"
gUnknown_828A3A4: @ 0x828A3A4
	.include "data/scripts/gUnknown_828A3A4.inc"
gUnknown_828A3D3: @ 0x828A3D3
	.include "data/scripts/gUnknown_828A3D3.inc"
gUnknown_828A3F7: @ 0x828A3F7
	.include "data/scripts/gUnknown_828A3F7.inc"
gUnknown_828A419: @ 0x828A419
	.include "data/scripts/gUnknown_828A419.inc"
gUnknown_828A43B: @ 0x828A43B @ running-by-item script
	.byte 0x54, 0x11, 0x00, 0x2E, 0xDE, 0x3F, 0x02, 0x02, 0x04, 0xF7
gUnknown_828A445: @ 0x828A445 @ BattleScript_ActionWatchesCarefully
	.byte 0x10, 0x1D, 0x01 @ printstring STRINGID_PKMNWATCHINGCAREFULLY
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A44C: @ 0x828A44C @ BattleScript_ActionGetNear
	.byte 0x13, 0xB0, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAB0
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A455: @ 0x828A455 @ BattleScript_ActionThrowPokeblock
	.byte 0x10, 0x21, 0x01 @ printstring STRINGID_THREWPOKEBLOCKATPKMN
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x45, 0x01, 0x04, 0x00, 0x00, 0x00, 0x00 @ playanimation 0x01, 0x04, 0x00000000
	.byte 0x13, 0xB4, 0xBA, 0x5A, 0x08 @ printfromtable 0x085ABAB4
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
gUnknown_828A46B: @ 0x828A46B @ BattleScript_ActionWallyThrow
	.byte 0x10, 0x02, 0x00 @ printstring STRINGID_RETURNMON
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x4B @ returnatktoball
	.byte 0x3A @ waitstate
	.byte 0x53, 0x00 @ trainerslidein 0x00
	.byte 0x3A @ waitstate
	.byte 0x10, 0x4D, 0x01 @ printstring STRINGID_YOUTHROWABALLNOWRIGHT
	.byte 0x12, 0x40, 0x00 @ waitmessage 0x0040
	.byte 0x3E @ end2
	.byte 0x00 @ attackcanceler
	.byte 0x00 @ attackcanceler
	.byte 0x00 @ attackcanceler
