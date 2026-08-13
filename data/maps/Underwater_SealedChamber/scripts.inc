@ Underwater_SealedChamber scripts (JP map g24 m70 @ 0x0821BA09)

Underwater_SealedChamber_MapScripts::
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_EventScript_0021BA0F
	.byte 0

Underwater_SealedChamber_EventScript_0021BA0F::
	getplayerxy 0x8004, 0x8005
	compare_var_to_value 0x8004, 0xC
	goto_if 0x5, Underwater_SealedChamber_EventScript_0021BA2F
	compare_var_to_value 0x8005, 0x2C
	goto_if 0x5, Underwater_SealedChamber_EventScript_0021BA2F
	goto Underwater_SealedChamber_EventScript_0021BA38

Underwater_SealedChamber_EventScript_0021BA2F::
	setdivewarp 0x31, 0xFF, 0x3C, 0x1F
	end

Underwater_SealedChamber_EventScript_0021BA38::
	setdivewarp 0x1847, 0xFF, 0xA, 0x13
	end

Underwater_SealedChamber_EventScript_0021BA41::
	lockall
	braillemessage 0x082635D2
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

