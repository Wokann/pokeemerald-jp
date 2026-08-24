	nop 
	dotimebasedevents 
	waitstate 
	gotostd_if 0x3, 0x28
	setworldmapflag 0x901C
	nop 
	showcoinsbox 0x7, 0x7
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	return 
	multichoicegrid 0x6E, 0x11, 0x8, 0xA, 0x5
	call 0x100
	nop 
	callstd 0x0
	compare_addr_to_value 0x2AD80200, 0x57
	gotostd 0x82
	goto 0x0
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	return 
	addobject 0xD4B
	gotostd 0x2
	goto 0x20001
	nop 
	nop 
	copybyte 0x2000100, 0x8572AD8
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x4
	end 
	end 
	cmdD8 
	clearflag 0x857
	buffermovename 0x5, 0x0
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x5
	return 
	multichoicegrid 0x6E, 0x11, 0x8, 0xA, 0x5
	call 0x9000100
	nop 
	nop 
	nop 
	compare_addr_to_value 0x30B0500, 0x8
