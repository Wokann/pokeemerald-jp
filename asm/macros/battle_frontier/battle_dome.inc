	@ Battle Dome EventScript helpers.
	@ The JP special table retains CallBattleDomeFunction as this dispatcher's actual entry.

	@ Initialize the Battle Dome challenge.
	.macro dome_init
	setvar VAR_0x8004, BATTLE_DOME_FUNC_INIT
	special CallBattleDomeFunction
	.endm

	@ Get the value of a DOME_DATA_* entry into VAR_RESULT.
	.macro dome_get data:req
	setvar VAR_0x8004, BATTLE_DOME_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special CallBattleDomeFunction
	.endm

	@ Set a DOME_DATA_* entry.
	.macro dome_set data:req, val=0xFFFF
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	.if \val != 0xFFFF
	setvar VAR_0x8006, \val
	.endif
	special CallBattleDomeFunction
	.endm

	@ Buffer the name of the current round to gStringVar1.
	.macro dome_getroundtext
	setvar VAR_0x8004, BATTLE_DOME_FUNC_GET_ROUND_TEXT
	special CallBattleDomeFunction
	.endm

	@ Buffer the opponent name to gStringVar2 and round name to gStringVar1.
	.macro dome_getopponentname
	setvar VAR_0x8004, BATTLE_DOME_FUNC_GET_OPPONENT_NAME
	special CallBattleDomeFunction
	.endm

	@ Choose the opponent's mons and load them into the enemy party.
	.macro dome_initopponentparty
	setvar VAR_0x8004, BATTLE_DOME_FUNC_INIT_OPPONENT_PARTY
	special CallBattleDomeFunction
	.endm

	@ Show the page with information about the next opponent.
	.macro dome_showopponentinfo
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SHOW_OPPONENT_INFO
	special CallBattleDomeFunction
	.endm

	@ Display the current tournament tree.
	.macro dome_showtourneytree
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SHOW_TOURNEY_TREE
	special CallBattleDomeFunction
	.endm

	@ Display the previous tournament tree.
	.macro dome_showprevtourneytree
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SHOW_PREV_TOURNEY_TREE
	special CallBattleDomeFunction
	.endm

	@ Set gTrainerBattleOpponent_A to the next opponent's trainer id.
	.macro dome_setopponent
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SET_OPPONENT_ID
	special CallBattleDomeFunction
	.endm

	@ Set the object-event graphics id for the opponent.
	.macro dome_setopponentgfx
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SET_OPPONENT_GFX
	special CallBattleDomeFunction
	.endm

	@ Display the non-interactive tournament tree after a round completes.
	.macro dome_showstatictourneytree
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SHOW_STATIC_TOURNEY_TREE
	special CallBattleDomeFunction
	.endm

	@ Resolve NPC matches and eliminate a player or opponent as appropriate.
	.macro dome_resolvewinners playerStatus:req
	setvar VAR_0x8004, BATTLE_DOME_FUNC_RESOLVE_WINNERS
	setvar VAR_0x8005, \playerStatus
	special CallBattleDomeFunction
	.endm

	@ Save the game and set the challenge status.
	.macro dome_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special CallBattleDomeFunction
	.endm

	@ Increment the current challenge win streaks.
	.macro dome_incrementstreaks
	setvar VAR_0x8004, BATTLE_DOME_FUNC_INCREMENT_STREAK
	special CallBattleDomeFunction
	.endm

	@ Set the facility trainer and mon-set pointers.
	.macro dome_settrainers
	setvar VAR_0x8004, BATTLE_DOME_FUNC_SET_TRAINERS
	special CallBattleDomeFunction
	.endm

	@ Restore moves changed by Sketch during the challenge.
	.macro dome_resetsketch
	setvar VAR_0x8004, BATTLE_DOME_FUNC_RESET_SKETCH
	special CallBattleDomeFunction
	.endm

	@ Restore held items that were present before the battle.
	.macro dome_restorehelditems
	setvar VAR_0x8004, BATTLE_DOME_FUNC_RESTORE_HELD_ITEMS
	special CallBattleDomeFunction
	.endm

	@ Reduce the player's party to the selected mons.
	.macro dome_reduceparty
	setvar VAR_0x8004, BATTLE_DOME_FUNC_REDUCE_PARTY
	special CallBattleDomeFunction
	.endm

	@ Compare the player's tournament seed with the opponent's.
	.macro dome_compareseeds
	setvar VAR_0x8004, BATTLE_DOME_FUNC_COMPARE_SEEDS
	special CallBattleDomeFunction
	.endm

	@ Buffer the previous Battle Dome winner's name to STR_VAR_1.
	.macro dome_getwinnersname
	setvar VAR_0x8004, BATTLE_DOME_FUNC_GET_WINNER_NAME
	special CallBattleDomeFunction
	.endm

	@ Initialize the result tree before the first Battle Dome challenge.
	.macro dome_initresultstree
	setvar VAR_0x8004, BATTLE_DOME_FUNC_INIT_RESULTS_TREE
	special CallBattleDomeFunction
	.endm

	@ Generate, seed, and prepare the tournament trainers.
	.macro dome_inittrainers
	setvar VAR_0x8004, BATTLE_DOME_FUNC_INIT_TRAINERS
	special CallBattleDomeFunction
	.endm
