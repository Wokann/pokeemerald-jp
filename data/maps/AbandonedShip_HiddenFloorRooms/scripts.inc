@ AbandonedShip_HiddenFloorRooms scripts (JP map g24 m66 @ 0x0821B5A3)

AbandonedShip_HiddenFloorRooms_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_MapScriptTable_0021B5A9
	.byte 0

AbandonedShip_HiddenFloorRooms_MapScriptTable_0021B5A9::
	map_script_2 0x4001, 0x0, AbandonedShip_HiddenFloorRooms_EventScript_0021B5B3
	.2byte 0

AbandonedShip_HiddenFloorRooms_EventScript_0021B5B3::
	setvar 0x4001, 0x1
	getplayerxy 0x4002, 0x4003
	setvar 0x4004, 0x1
	compare_var_to_value 0x4002, 0x15
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B62B
	compare_var_to_value 0x4002, 0x24
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B631
	compare_var_to_value 0x4003, 0x2
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B637
	copyvar 0x8000, 0x4004
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B63D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B666
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B667
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B68D
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B6C5
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B70C
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B62B::
	addvar 0x4004, 0x1
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B631::
	addvar 0x4004, 0x2
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B637::
	addvar 0x4004, 0x3
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B63D::
	delay 0x14
	setfieldeffectarg 0x0, 0xA
	setfieldeffectarg 0x1, 0xA
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	specialvar 0x800D, FoundAbandonedShipRoom4Key
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B72D
	waitfieldeffect 0x36
	delay 0xA
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B666::
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B667::
	specialvar 0x800D, FoundAbandonedShipRoom1Key
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B68C
	delay 0x14
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B70D
	waitfieldeffect 0x36
	delay 0xA
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B68C::
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B68D::
	delay 0x14
	setfieldeffectarg 0x0, 0x8
	setfieldeffectarg 0x1, 0x5
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	setfieldeffectarg 0x0, 0xB
	setfieldeffectarg 0x1, 0x3
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	specialvar 0x800D, FoundAbandonedShipRoom6Key
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B73D
	waitfieldeffect 0x36
	delay 0xA
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B6C5::
	delay 0x14
	setfieldeffectarg 0x0, 0x10
	setfieldeffectarg 0x1, 0x3
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	setfieldeffectarg 0x0, 0x19
	setfieldeffectarg 0x1, 0x2
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	setfieldeffectarg 0x0, 0x18
	setfieldeffectarg 0x1, 0x6
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	specialvar 0x800D, FoundAbandonedShipRoom2Key
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, AbandonedShip_HiddenFloorRooms_EventScript_0021B71D
	waitfieldeffect 0x36
	delay 0xA
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B70C::
	end

AbandonedShip_HiddenFloorRooms_EventScript_0021B70D::
	setfieldeffectarg 0x0, 0x2A
	setfieldeffectarg 0x1, 0xA
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B71D::
	setfieldeffectarg 0x0, 0x14
	setfieldeffectarg 0x1, 0x5
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B72D::
	setfieldeffectarg 0x0, 0x1
	setfieldeffectarg 0x1, 0xC
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B73D::
	setfieldeffectarg 0x0, 0x1
	setfieldeffectarg 0x1, 0x2
	setfieldeffectarg 0x2, 0x0
	dofieldeffect 0x36
	return

AbandonedShip_HiddenFloorRooms_EventScript_0021B74D::
	lockall
	loadword 0x0, 0x0821B758
	callstd 0x4
	releaseall
	end
