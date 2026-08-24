@ Route114_FossilManiacsTunnel scripts (JP map g20 m1 @ 0x0821228D)

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_EventScript_00212298
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_EventScript_002122AE
	.byte 0

Route114_FossilManiacsTunnel_EventScript_00212298::
	checkflag 0x864
	call_if 0x1, Route114_FossilManiacsTunnel_EventScript_002122A2
	end

Route114_FossilManiacsTunnel_EventScript_002122A2::
	setobjectxyperm 0x1, 0x6, 0x5
	setobjectmovementtype 0x1, 0x8
	return

Route114_FossilManiacsTunnel_EventScript_002122AE::
	checkflag 0x864
	call_if 0x0, Route114_FossilManiacsTunnel_EventScript_002122B8
	end

Route114_FossilManiacsTunnel_EventScript_002122B8::
	setmetatile 0x6, 0x1, 0x269, 0x1
	setmetatile 0x6, 0x2, 0x269, 0x1
	return

Route114_FossilManiacsTunnel_EventScript_002122CB::
	lockall
	applymovement 0x1, 0x08243629
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	loadword 0x0, 0x08212467
	callstd 0x4
	setvar 0x40CC, 0x2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_002122EC::
	lock
	faceplayer
	checkflag 0x10B
	goto_if 0x1, Route114_FossilManiacsTunnel_EventScript_0021232B
	checkitem 0x11E, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route114_FossilManiacsTunnel_EventScript_00212321
	checkitem 0x11F, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route114_FossilManiacsTunnel_EventScript_00212321
	loadword 0x0, 0x08212335
	callstd 0x4
	release
	end

Route114_FossilManiacsTunnel_EventScript_00212321::
	loadword 0x0, 0x082123BF
	callstd 0x4
	release
	end

Route114_FossilManiacsTunnel_EventScript_0021232B::
	loadword 0x0, 0x0821244C
	callstd 0x4
	release
	end
