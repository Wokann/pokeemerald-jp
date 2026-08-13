	special EventObjectInteractionGetBerryTreeData
	lockall
	message 0x8245047
	waitmessage
	special EventObjectInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	message 0x8245058
	waitmessage
	waitbuttonpress
	releaseall
	end
	special EventObjectInteractionPlantBerryTree
	incrementgamestat 0x3
	special sub_080EF814
	message 0x8244F24
	waitmessage
	waitbuttonpress
	return
	compare_local_to_value 0x6, 0x1C
	.incbin "baserom_jp.gba", 0x244F05, 0x142
	.globl gJPText_00245047
gJPText_00245047: @ 0x08245047
	.string "{MUS_RG_VS_TRAINER}は　{B_COPY_VAR_1}に　みずを　あげた！$"

	.globl gJPText_00245058
gJPText_00245058: @ 0x08245058
	.string "とっても　よろこんでる　みたい！$"

	.incbin "baserom_jp.gba", 0x245069, 0x106
