	@ Battle Tower/Battle Tent EventScript helpers.

	@ Choose and set the next opponent's graphics. JP's special table names this
	@ entry sub_08161E88, while the US project calls it CallBattleTowerFunc.
	.macro tower_setopponent
	setvar VAR_0x8004, BATTLE_TOWER_FUNC_SET_OPPONENT
	special sub_08161E88
	.endm
