	nop 
	checkcoins 0x1927
	vmessage 0x580EC000
	cleartrainerflag 0x828
	compare_addr_to_value 0x8158B95, 0x7
	.byte 0xC8
	nop 
	showcoinsbox 0xFF, 0x3F
	nop 
	return 
	nop 
	call 0xF000000
	nop 
	setmysteryeventstatus 0x23
	addvar 0x828, 0x230E
	addvar 0x828, 0x3D03
	setobjectxy 0x80D, 0x505, 0x0
	goto_if 0x0, 0x40800
	setworldmapflag 0x300
	addobject 0x1162
	gotostd 0x2
	goto_if 0x4, 0x2000200
	nop 
	nop 
	nop 
	returnram 
	nop 
	gotopostbattlescript 
	bufferleadmonspeciesname 0xE
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0xE082817
	callnative 0x5082817
	call 0x62640E01
	delay 0x808
	end 
	compare_addr_to_addr 0x82085722, 0x1006
	nop 
	nop 
	nop 
	nop 
	nop 
	killscript 
	nop 
	nop 
	nop 
	.byte 0x04
	.byte 0x04
	.byte 0x0F
