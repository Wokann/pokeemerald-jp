@ JaggedPass scripts (JP map g24 m13 @ 0x08215AF2)

JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_EventScript_00215B02
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_EventScript_00215B27
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_EventScript_00215B38
	.byte 0

JaggedPass_EventScript_00215B02::
	setstepcallback 0x1
	compare_var_to_value 0x40C8, 0x0
	call_if 0x1, JaggedPass_EventScript_00215B10
	end

JaggedPass_EventScript_00215B10::
	checkitem 0x177, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, JaggedPass_EventScript_00215B21
	return

JaggedPass_EventScript_00215B21::
	setvar 0x40C8, 0x1
	return

JaggedPass_EventScript_00215B27::
	compare_var_to_value 0x40BD, 0x1
	call_if 0x1, JaggedPass_EventScript_00215B33
	end

JaggedPass_EventScript_00215B33::
	setweather 0x7
	resetweather
	return

JaggedPass_EventScript_00215B38::
	compare_var_to_value 0x40C8, 0x1
	goto_if 0x3, JaggedPass_EventScript_00215B44
	end

JaggedPass_EventScript_00215B44::
	setmetatile 0x10, 0x11, 0x274, 0x1
	setmetatile 0x10, 0x12, 0x274, 0x1
	end

JaggedPass_EventScript_00215B57::
	lockall
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special ShakeCamera
	waitstate
	loadword 0x0, 0x08216039
	callstd 0x4
	closemessage
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x10
	setvar 0x8007, 0x3
	special ShakeCamera
	waitstate
	playse 0xD
	setmetatile 0x10, 0x11, 0x256, 0x1
	setmetatile 0x10, 0x12, 0x25E, 0x0
	special DrawWholeMapView
	delay 0x1E
	setvar 0x40C8, 0x2
	waitse
	releaseall
	end

	.incbin "baserom_jp.gba", 0x215bb4, 0x54b
