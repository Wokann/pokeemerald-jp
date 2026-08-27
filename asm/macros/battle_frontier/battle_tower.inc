	@ Battle Tower/Battle Tent EventScript helpers.

	@ Initialize the Battle Tower challenge.
	.macro tower_init
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_INIT
	special sub_08161E88
	.endm

	@ Get the value of a TOWER_DATA_* entry into VAR_RESULT.
	.macro tower_get data:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GET_DATA
	setvar VAR_0x8005, \data
	special sub_08161E88
	.endm

	@ Set a TOWER_DATA_* entry to a literal value.
	.macro tower_set data:req, val:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_DATA
	setvar VAR_0x8005, \data
	setvar VAR_0x8006, \val
	special sub_08161E88
	.endm

	@ Choose and set the next opponent's graphics. JP's special table names this
	@ entry sub_08161E88, while the US project calls it CallBattleTowerFunc.
	.macro tower_setopponent
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT
	special sub_08161E88
	.endm

	@ Try to award ribbons for the Battle Tower streak. VAR_RESULT is TRUE on success.
	.macro tower_giveribbons
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_GIVE_RIBBONS
	special sub_08161E88
	.endm

	@ Save the game and set the Battle Tower challenge status.
	.macro tower_save challengeStatus:req
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SAVE
	setvar VAR_0x8005, \challengeStatus
	special sub_08161E88
	.endm

	@ Load the opponent data for a Link Multi Battle. VAR_RESULT is 6 when complete.
	.macro tower_loadlinkopponents
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_LOAD_LINK_OPPONENTS
	special sub_08161E88
	.endm
