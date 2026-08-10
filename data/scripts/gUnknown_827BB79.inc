	nop 
	loadbytefromaddr 0x28030A28
	setworldmapflag 0x100C
	nop 
	end 
	.byte 0xCC
	buffercontesttype 
	faceplayer 
	gotostd 0x82
	setworldmapflag 0x1
	call 0xCD1C11
	setdynamicwarp 0x1004, 0x4, 0x430, 0x1918
	setmonobedient 0x3F00
	call 0x7461030A
	gotostd_if 0x8, 0x5
	goto 0x7FFF0001
	returnram 
	nop 
	end 
	nop 
	setworldmapflag 0x1900
	.byte 0xD1
	nop 
	.byte 0x3F
	goto 0x8030B0D
