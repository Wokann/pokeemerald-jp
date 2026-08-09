	.byte 0x16
	goto 0x25000380
	compare_local_to_local 0x0, 0x27
	compare_var_to_value 0x4001, 0x0
	goto_if 0x5, 0x8247150
	end 
	.byte 0x80
	setworldmapflag 0x4001
	message 0x8247FB9
	waitmessage 
	waitbuttonpress 
	releaseall 
	end 
