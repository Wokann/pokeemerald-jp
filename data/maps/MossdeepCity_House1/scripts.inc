@ MossdeepCity_House1 scripts (JP map g14 m1 @ 0x0820C332)

MossdeepCity_House1_MapScripts::
	.byte 0

MossdeepCity_House1_EventScript_BlackBelt:: @ 0x0820C333
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetPokeblockNameByMonNature
	goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature
	msgbox MossdeepCity_House1_Text_ItLikesXPokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_NeutralNature:: @ 0x0820C359
	msgbox MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House1_EventScript_Woman:: @ 0x0820C363
	msgbox MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes, MSGBOX_NPC
	end

MossdeepCity_House1_Text_HmmYourPokemon: @ 0x0820C36C
	.string "ムムムッ！\n"
	.string "きみの　{STR_VAR_1}⋯⋯$"

MossdeepCity_House1_Text_ItLikesXPokeblocks: @ 0x0820C37B
	.string "{STR_VAR_1}　が　すきだろう！\p"
	.string "いや　まちがいなく\n"
	.string "{STR_VAR_1}　が　すきだ！$"

MossdeepCity_House1_Text_DoesntLikeOrDislikePokeblocks: @ 0x0820C39B
	.string "ポロックの　すききらいは　ないみたいだな$"

MossdeepCity_House1_Text_HusbandCanTellPokeblockMonLikes: @ 0x0820C3B0
	.string "だんなったら　みただけで\n"
	.string "ポケモンが　すきな　ポロック　わかるのよ$"
