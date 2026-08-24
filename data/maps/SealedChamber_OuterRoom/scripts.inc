@ SealedChamber_OuterRoom scripts (JP map g24 m71 @ 0x0821BA4B)

SealedChamber_OuterRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_EventScript_0021BA5B
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_EventScript_0021BA6C
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_EventScript_0021BA70
	.byte 0

SealedChamber_OuterRoom_EventScript_0021BA5B::
	setdivewarp 0x1846, 0xFF, 0xC, 0x2C
	setescapewarp 0x1846, 0xFF, 0xC, 0x2C
	end

SealedChamber_OuterRoom_EventScript_0021BA6C::
	setflag 0x8BC
	end

SealedChamber_OuterRoom_EventScript_0021BA70::
	checkflag 0x8AF
	call_if 0x0, SealedChamber_OuterRoom_EventScript_0021BA7A
	end

SealedChamber_OuterRoom_EventScript_0021BA7A::
	setmetatile 0x9, 0x1, 0x229, 0x1
	setmetatile 0xA, 0x1, 0x229, 0x1
	setmetatile 0xB, 0x1, 0x229, 0x1
	setmetatile 0x9, 0x2, 0x235, 0x1
	setmetatile 0xA, 0x2, 0x235, 0x1
	setmetatile 0xB, 0x2, 0x235, 0x1
	return

SealedChamber_OuterRoom_EventScript_0021BAB1::
	lockall
	braillemessage 0x082635E2
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BABB::
	lockall
	braillemessage 0x082635EE
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BAC5::
	lockall
	braillemessage 0x082635FA
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BACF::
	lockall
	braillemessage 0x08263606
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BAD9::
	lockall
	braillemessage 0x08263612
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BAE3::
	lockall
	braillemessage 0x0826361E
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BAED::
	lockall
	braillemessage 0x0826362A
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BAF7::
	lockall
	braillemessage 0x08263636
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BB01::
	lockall
	braillemessage 0x08263640
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BB0B::
	lockall
	braillemessage 0x0826364C
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BB15::
	lockall
	checkflag 0x8AF
	goto_if 0x1, SealedChamber_OuterRoom_EventScript_0021BB28
	braillemessage 0x08263656
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BB28::
	loadword 0x0, 0x08243CDA
	callstd 0x4
	releaseall
	end

SealedChamber_OuterRoom_EventScript_0021BB32::
	lockall
	braillemessage 0x08263656
	waitbuttonpress
	mossdeepgym4
	releaseall
	end
