	lockall 
	special TryFieldPoisonWhiteOut
	waitstate 
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244103
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x8244122
	releaseall 
	end 
	message 0x8243B4E
	waitmessage 
	waitbuttonpress 
	special Script_FadeOutMapMusic
	waitstate 
	fadescreen 0x1
	checkflag 0x6C
	call_if 0x1, 0x824411E
	special SetCB2WhiteOut
	waitstate 
	end 
	setrespawn 0x10
	return 
	message 0x8243B4E
	waitmessage 
	waitbuttonpress 
	setvar 0x8004, 0x10
	special CallBattlePikeFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x82746AB
	setvar 0x8004, 0xC
	special CallBattlePyramidFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x822D60B
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x822D60B
	setvar 0x8004, 0xA
	special CallTrainerHillFunction
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8276CE5
	special Script_FadeOutMapMusic
	waitstate 
	fadescreen 0x1
	special SetCB2WhiteOut
	waitstate 
	end 
	return 
	setvar 0x800D, 0x1
	return 
	setvar 0x800D, 0x0
	return 
	call 0x82471FA
	end 
	call 0x8247351
	end 
	call 0x8247383
	end 
	fadescreenswapbuffers 0x1
	removeobject 0x800F
	fadescreenswapbuffers 0x0
	release 
	end 
	fadescreenswapbuffers 0x1
	removeobject 0x800F
	fadescreenswapbuffers 0x0
	buffermovename 0x0, 0x8004
	loadword 0x0, 0x8243DF4
	callstd 0x4
	release 
	end 
	getpartysize 
	subvar 0x800D, 0x1
	copyvar 0x8004, 0x800D
	return 
	fadescreen 0x1
	special ChangeBoxPokemonNickname
	lock 
	faceplayer 
	return 
	bufferboxname 0x0, 0x4036
	buffermovename 0x1, 0x4001
	checkflag 0x8AB
	call_if 0x0, 0x82441E5
	checkflag 0x8AB
	call_if 0x1, 0x8244210
	return 
	specialvar 0x800D, sub_0813B254
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x82441FE
	loadword 0x0, 0x8243E08
	callstd 0x4
	return 
	specialvar 0x800D, get_unknown_box_id
	bufferboxname 0x2, 0x800D
	loadword 0x0, 0x8243E4C
	callstd 0x4
	return 
	specialvar 0x800D, sub_0813B254
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244229
	loadword 0x0, 0x8243E2A
	callstd 0x4
	return 
	specialvar 0x800D, get_unknown_box_id
	bufferboxname 0x2, 0x800D
	loadword 0x0, 0x8243E80
	callstd 0x4
	return 
	loadword 0x0, 0x8243EB4
	callstd 0x4
	release 
	end 
