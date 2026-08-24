@ LilycoveCity_PokemonTrainerFanClub scripts (JP map g13 m9 @ 0x0820839E)

LilycoveCity_PokemonTrainerFanClub_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_PokemonTrainerFanClub_MapScriptTable_002083A9
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonTrainerFanClub_EventScript_00208426
	.byte 0

LilycoveCity_PokemonTrainerFanClub_MapScriptTable_002083A9::
	map_script_2 0x4095, 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002083B3
	.2byte 0

LilycoveCity_PokemonTrainerFanClub_EventScript_002083B3::
	lockall
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	loadword 0x0, gJPText_00208B19
	callstd 0x4
	applymovement 0x4, 0x08208416
	applymovement 0x2, 0x0820840E
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, gJPText_00208B22
	callstd 0x4
	applymovement 0x4, 0x0820841D
	waitmovement 0x0
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	applymovement 0x4, 0x08208420
	waitmovement 0x0
	setvar 0x4095, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20840e, 0x18
LilycoveCity_PokemonTrainerFanClub_EventScript_00208426::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_002084F3
	compare_var_to_value 0x4095, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208611
	compare_var_to_value 0x4095, 0x2
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208442
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208442::
	special UpdateMovedLilycoveFanClubMembers
	call LilycoveCity_PokemonTrainerFanClub_EventScript_0020850E
	setvar 0x8004, 0x8
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085D1
	setvar 0x8004, 0x9
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085D9
	setvar 0x8004, 0xA
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085E1
	setvar 0x8004, 0xB
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085E9
	setvar 0x8004, 0xC
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085F1
	setvar 0x8004, 0xD
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085F9
	setvar 0x8004, 0xE
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208601
	setvar 0x8004, 0xF
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208609
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002084F3::
	specialvar 0x800D, sub_080EF2D8
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020850A
	clearflag 0x2DA
	clearflag 0xD2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_0020850A::
	setflag 0x2DA
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_0020850E::
	setvar 0x8005, 0x8
	setvar 0x8004, 0x8
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0x9
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xA
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xB
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xC
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xD
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xE
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	setvar 0x8004, 0xF
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7
	compare_var_to_value 0x8005, 0x5
	goto_if 0x4, LilycoveCity_PokemonTrainerFanClub_EventScript_002085CD
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085C7::
	subvar 0x8005, 0x1
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085CD::
	special sub_080EF244
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085D1::
	setobjectxyperm 0x1, 0x7, 0x5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085D9::
	setobjectxyperm 0x3, 0x3, 0x4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085E1::
	setobjectxyperm 0x4, 0x7, 0x2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085E9::
	setobjectxyperm 0x5, 0x5, 0x5
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085F1::
	setobjectxyperm 0x6, 0x5, 0x2
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_002085F9::
	setobjectxyperm 0x2, 0x8, 0x4
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_00208601::
	setobjectxyperm 0x7, 0x3, 0x3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_00208609::
	setobjectxyperm 0x8, 0x8, 0x3
	return

LilycoveCity_PokemonTrainerFanClub_EventScript_00208611::
	call LilycoveCity_PokemonTrainerFanClub_EventScript_0020850E
	call LilycoveCity_PokemonTrainerFanClub_EventScript_002085D9
	call LilycoveCity_PokemonTrainerFanClub_EventScript_002085E9
	call LilycoveCity_PokemonTrainerFanClub_EventScript_002085F1
	call LilycoveCity_PokemonTrainerFanClub_EventScript_00208601
	call LilycoveCity_PokemonTrainerFanClub_EventScript_00208609
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208630::
	lock
	faceplayer
	setvar 0x8004, 0xD
	special BufferStreakTrainerText
	compare_var_to_value 0x4095, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020869D
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020866F
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208693
	loadword 0x0, 0x08208C38
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020866F::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208689
	loadword 0x0, 0x08208BEC
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208689::
	loadword 0x0, 0x08208C00
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208693::
	loadword 0x0, 0x08208C7A
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020869D::
	loadword 0x0, 0x08208CA7
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002086A7::
	lock
	faceplayer
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	compare_var_to_value 0x4095, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208714
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002086E6
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020870A
	loadword 0x0, 0x08208D47
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002086E6::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208700
	loadword 0x0, 0x08208CE8
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208700::
	loadword 0x0, 0x08208D03
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020870A::
	loadword 0x0, 0x08208D67
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208714::
	loadword 0x0, 0x08208DAD
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020871E::
	lock
	faceplayer
	setvar 0x8004, 0x9
	special BufferStreakTrainerText
	compare_var_to_value 0x4095, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020878B
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020875D
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208781
	loadword 0x0, 0x08208E7C
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020875D::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208777
	loadword 0x0, 0x08208DDE
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208777::
	loadword 0x0, 0x08208E1A
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208781::
	loadword 0x0, 0x08208EE0
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020878B::
	loadword 0x0, 0x08208F49
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208795::
	lock
	faceplayer
	setvar 0x8004, 0xA
	special BufferStreakTrainerText
	compare_var_to_value 0x4095, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208802
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002087D4
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002087F8
	loadword 0x0, 0x08209015
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002087D4::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002087EE
	loadword 0x0, 0x08208FA5
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002087EE::
	loadword 0x0, 0x08208FC6
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002087F8::
	loadword 0x0, 0x08209039
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208802::
	loadword 0x0, 0x08209072
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020880C::
	lock
	faceplayer
	setvar 0x8004, 0xB
	special BufferStreakTrainerText
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208840
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208864
	loadword 0x0, 0x08209116
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208840::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020885A
	loadword 0x0, 0x082090AC
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020885A::
	loadword 0x0, 0x082090DB
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208864::
	loadword 0x0, 0x08209134
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020886E::
	lock
	faceplayer
	setvar 0x8004, 0xC
	special BufferStreakTrainerText
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002088A2
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002088C6
	loadword 0x0, 0x08209216
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002088A2::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002088BC
	loadword 0x0, 0x0820917D
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002088BC::
	loadword 0x0, 0x082091CB
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002088C6::
	loadword 0x0, 0x0820926D
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002088D0::
	lock
	faceplayer
	setvar 0x8004, 0xE
	special BufferStreakTrainerText
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208904
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208928
	loadword 0x0, 0x08209340
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208904::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020891E
	loadword 0x0, 0x082092CA
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020891E::
	loadword 0x0, 0x08209306
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208928::
	loadword 0x0, 0x0820938D
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208932::
	lock
	faceplayer
	setvar 0x8004, 0xF
	special BufferStreakTrainerText
	specialvar 0x800D, ShouldMoveLilycoveFanClubMember
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208966
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x7
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_0020898A
	loadword 0x0, 0x0820943E
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208966::
	specialvar 0x800D, GetNumMovedLilycoveFanClubMembers
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208980
	loadword 0x0, 0x082093F5
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208980::
	loadword 0x0, 0x08209400
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_0020898A::
	loadword 0x0, 0x0820946B
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208994::
	lock
	faceplayer
	checkflag 0xD2
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208B06
	checkflag 0xD2
	goto_if 0x0, LilycoveCity_PokemonTrainerFanClub_EventScript_002089A9
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002089A9::
	setvar 0x8005, 0xB
	special InterviewBefore
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208B18
	copyvar 0x800A, 0x8006
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DE14
	callstd 0x4
	setvar 0x8004, 0xE
	copyvar 0x8005, 0x800A
	call 0x08242F08
	lock
	faceplayer
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002089F9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208A07
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_002089F9::
	loadword 0x0, 0x0824DE37
	callstd 0x4
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_00208A66
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208A07::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DE51
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208ADF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208A2E
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208A2E::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DE64
	callstd 0x4
	setvar 0x8004, 0xE
	copyvar 0x8005, 0x800A
	call 0x08242F08
	lock
	faceplayer
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_002089F9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208A07
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208A66::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	message 0x0824DE82
	waitmessage
	setvar 0x8004, 0x2
	special sub_0813A164
	waitstate
	setvar 0x8004, 0x8
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208AB8
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208AB8
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	copyvar 0x8006, 0x800A
	copyvar 0x8005, 0x800D
	special PutFanClubSpecialOnTheAir
	goto LilycoveCity_PokemonTrainerFanClub_EventScript_00208AF1
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208AB8::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DEA3
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208ADF
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_PokemonTrainerFanClub_EventScript_00208A66
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208ADF::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DEB6
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208AF1::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DEE0
	callstd 0x4
	setflag 0xD2
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208B06::
	setvar 0x8004, 0x8
	special BufferStreakTrainerText
	loadword 0x0, 0x0824DF29
	callstd 0x4
	release
	end

LilycoveCity_PokemonTrainerFanClub_EventScript_00208B18::
	end

	.globl gJPText_00208B19
gJPText_00208B19: @ 0x08208B19
	.string "あ！\n"
	.string "{MUS_RG_VS_TRAINER}だ！！$"

	.globl gJPText_00208B22
gJPText_00208B22: @ 0x08208B22
	.string "きいたよ！\n"
	.string "きみ　つよいんだってな\p"
	.string "ここでは　みんな\n"
	.string "だれが　いちばん　つよい　トレーナーか\l"
	.string "はなしを　してるんだけど\p"
	.string "おれ　きみの　うわさを　きいて\n"
	.string "きみの　ファンに　なることに　したよ！\p"
	.string "これからも　つよい　トレーナーと\n"
	.string "バンバン　たたかって\p"
	.string "おれたちに　あつい\n"
	.string "たたかいを　みせてくれよ！\p"
	.string "そうすれば　きっと　みんなも\n"
	.string "きみの　ことを　みなおすと　おもうんだ\p"
	.string "じゃあ　きたい　してるよ！\n"
	.string "{MUS_RG_VS_TRAINER}！！$"
