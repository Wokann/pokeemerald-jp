	nop 
	showobject_at 0xA27, 0x303
	warp 0x3410, 0x8, 0x2, 0x1B05
	opendoor 0xC000, 0x23F
	nop 
	end 
	.byte 0xEC
	.byte 0xEB
	addobject_at 0x8208, 0x307
	nop 
	nop 
	nop 
	returnram 
	nop 
	call 0xEBEC0205
	addobject_at 0x8208, 0x306
	nop 
	setworldmapflag 0xC00
	nop 
	call 0xEBEC0205
	addobject_at 0x8208, 0x301
	nop 
	end 
	nop 
	returnram 
	nop 
	call 0xEBEC0205
	addobject_at 0x8208, 0x302
	nop 
	return 
	nop 
	returnram 
	nop 
	call 0xEBEC0205
	addobject_at 0x8208, 0x303
	nop 
	nop 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x302
	nop 
	setworldmapflag 0xC00
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x305
	nop 
	end 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x306
	nop 
	return 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x302
	nop 
	nop 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x302
	nop 
	setworldmapflag 0xC00
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x301
	nop 
	end 
	nop 
	returnram 
	nop 
	call 0xEBEC0204
	addobject_at 0x8208, 0x305
	nop 
	return 
	nop 
	returnram 
	nop 
	call 0x30B0504
	return 
	.byte 0xF1
	savebgm 0x810
	end 
	nop 
	.byte 0x05
	.byte 0x08
