	.include "constants/gba_constants.inc"
	.include "constants/global.inc"

	@ Mirrors include/constants/battle_setup.h for event.inc's trainerbattle
	@ assembler conditionals.  JP event scripts are assembled directly rather
	@ than through the US C-preprocessor pipeline, so these must be visible to
	@ GAS as well.
	.set TRAINER_BATTLE_SINGLE,                           0
	.set TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC,         1
	.set TRAINER_BATTLE_CONTINUE_SCRIPT,                  2
	.set TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT,             3
	.set TRAINER_BATTLE_DOUBLE,                           4
	.set TRAINER_BATTLE_REMATCH,                          5
	.set TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE,           6
	.set TRAINER_BATTLE_REMATCH_DOUBLE,                   7
	.set TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC,  8
	.set TRAINER_BATTLE_PYRAMID,                          9
	.set TRAINER_BATTLE_SET_TRAINER_A,                   10
	.set TRAINER_BATTLE_SET_TRAINER_B,                   11
	.set TRAINER_BATTLE_HILL,                            12

	.include "constants/contest_constants.inc"
	.include "constants/pokemon_data_constants.inc"
	.include "constants/berry_constants.inc"
	.include "constants/contest_move_effects.inc"
	.include "constants/vars_constants.inc"
