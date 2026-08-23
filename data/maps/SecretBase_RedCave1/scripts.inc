@ SecretBase_RedCave1 scripts (JP map g25 m0 @ 0x0821D372)

SecretBase_RedCave1_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SecretBase_RedCave1_MapScriptTable_0021D387
	map_script MAP_SCRIPT_ON_TRANSITION, SecretBase_RedCave1_EventScript_0021D391
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SecretBase_RedCave1_MapScriptTable_0021D39D
	map_script MAP_SCRIPT_ON_RESUME, SecretBase_RedCave1_EventScript_0021D3A7
	.byte 0

SecretBase_RedCave1_MapScriptTable_0021D387::
	map_script_2 0x4089, 0x0, 0x08245DBB
	.2byte 0

SecretBase_RedCave1_EventScript_0021D391::
	call 0x08245D90
	special SetSecretBaseOwnerGfxId
	special sub_080EBD4C
	end

SecretBase_RedCave1_MapScriptTable_0021D39D::
	map_script_2 0x4097, 0x0, 0x08245C30
	.2byte 0

SecretBase_RedCave1_EventScript_0021D3A7::
	setstepcallback 0x6
	end

SecretBase_EventScript_PC:: @ 0x0821D3AA
	.incbin "baserom_jp.gba", 0x21d3aa, 0x269
	.globl gJPText_0021D613
gJPText_0021D613: @ 0x0821D613
	.string "ここに　ひみつきちを　つくりますか？$"
