	nop 
	returnram 
	delay 0xC02
	buffercontesttype 
	faceplayer 
	gotostd 0x32
	goto 0xFFF00070
	startcontest 
	nop 
	bufferitemname 0x0, 0x24
	call 0xD60C0202
	faceplayer 
	gotostd 0x32
	goto 0x8000D0
	.byte 0xF0
	.byte 0xFF
	waitse 
	nop 
	gotonative 0x9B1900
	nop 
	call 0xD60C0202
	faceplayer 
	gotostd 0x32
	goto 0x70FFF0
	nop 
	setworldmapflag 0xFFF0
	gotonative 0x9B1900
	nop 
	call 0xD60C0202
	faceplayer 
	gotostd 0x32
	goto 0x80006C
	removeobject_at 0xF000, 0xFF24
	nop 
	copyvar 0x9B, 0x400
	end 
	end 
	returnram 
	buffercontesttype 
	faceplayer 
	gotostd 0x32
	goto 0x38FFF0
	nop 
	setworldmapflag 0x38
	gotonative 0x9B1900
	nop 
	.byte 0x08
