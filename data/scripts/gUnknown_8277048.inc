	giveegg 0xAE9F
	moveobjectoffscreen 0x37
	goto_if 0x9, 0x442E0E1F
	returnram 
	loadbyte 0xFB, 0x96
	checkplayergender 
	showobject_at 0xA051, 0x9D56
	waitmoncry 
	moveobjectoffscreen 0xA078
	choosecontestmon 
	dotimebasedevents 
	.byte 0xFE
	gotostd_if 0x3, 0x6
	gettime 
	returnram 
	setptrbyte 0x8, 0xAB020B41
	.byte 0xFF
