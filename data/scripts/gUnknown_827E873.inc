	nop 
	faceplayer 
	waitstate 
	gotostd_if 0x2, 0x28
	nop 
	returnram 
	returnram 
	gotostd 0x19
	setrespawn 0xC000
	end 
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0xFFF60000
	nop 
	nop 
	nop 
	nop 
	return 
	nop 
	goto 0x55A98802
	gotostd 0x2
	return 
	nop 
	nop 
	nop 
	nop 
	end 
	nop 
	setmysteryeventstatus 0xC3
	.byte 0xE8
	waitstate 
	gotostd 0xE
	incrementgamestat 0xE8
	waitstate 
	gotostd 0xE
	incrementgamestat 0xE8
	waitstate 
	gotostd 0xE
	incrementgamestat 0xE8
	waitstate 
	gotostd 0xE
	incrementgamestat 0xE8
	waitstate 
	gotostd 0xE
	incrementgamestat 0xE8
	waitstate 
	gotostd 0x5
	callstd_if 0x2, 0xD
	gotostd 0x2
	startcontest 
	dotimebasedevents 
	setobjectxy 0x8208, 0xF05, 0xF00
	nop 
	copylocal 0x0, 0x0
	nop 
	nop 
	nop 
	end 
	startcontest 
	dotimebasedevents 
	setobjectxy 0x8208, 0xF05, 0xF00
	nop 
	copylocal 0x0, 0xA
	nop 
	gotostd_if 0x0, 0x2
	startcontest 
	dotimebasedevents 
	setobjectxy 0x8208, 0xF05, 0xF00
	nop 
	copylocal 0x0, 0xF6
	.byte 0xFF
	.byte 0xF6
	.byte 0xFF
	end 
	startcontest 
	dotimebasedevents 
	setobjectxy 0x8208, 0xF05, 0xF00
	nop 
	copylocal 0x0, 0x14
	nop 
	goto 0x2D8C0200
	setobjectxy 0x8208, 0xF05, 0xF00
	nop 
	copylocal 0x0, 0xEC
	.byte 0xFF
	.byte 0xFB
	.byte 0xFF
	.byte 0x04
	end 
	.byte 0x0F
