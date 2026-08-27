@ SealedChamber_OuterRoom scripts (JP map g24 m71 @ 0x0821BA4B)

SealedChamber_OuterRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
	.byte 0

SealedChamber_OuterRoom_OnResume: @ 0x0821BA5B
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	end

SealedChamber_OuterRoom_OnTransition: @ 0x0821BA6C
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_OnLoad: @ 0x0821BA70
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
	end

SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance:: @ 0x0821BA7A
	setmetatile 9, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 10, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 11, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

SealedChamber_OuterRoom_EventScript_BrailleABC:: @ 0x0821BAB1
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_ABC
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleGHI:: @ 0x0821BABB
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_GHI
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleMNO:: @ 0x0821BAC5
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_MNO
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleTUV:: @ 0x0821BACF
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_TUV
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDEF:: @ 0x0821BAD9
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DEF
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleJKL:: @ 0x0821BAE3
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_JKL
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePQRS:: @ 0x0821BAED
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_PQRS
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BraillePeriod:: @ 0x0821BAF7
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Period
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleWXYZ:: @ 0x0821BB01
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_WXYZ
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleComma:: @ 0x0821BB0B
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Comma
	releaseall
	end

SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall:: @ 0x0821BB15
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	releaseall
	end

SealedChamber_OuterRoom_EventScript_HoleInWall:: @ 0x0821BB28
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDigHere:: @ 0x0821BB32
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	releaseall
	end
