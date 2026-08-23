@ PacifidlogTown_House2 scripts (JP map g7 m3 @ 0x081F79FF)

PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_001F7A00::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_001F7A4C
	checkflag 0x12B
	goto_if 0x1, PacifidlogTown_House2_EventScript_001F7AEC
	checkflag 0x12C
	call_if 0x1, PacifidlogTown_House2_EventScript_001F7A66
	checkflag 0x12C
	call_if 0x0, PacifidlogTown_House2_EventScript_001F7A6F
	setflag 0x12C
	specialvar 0x800D, GetLeadMonFriendshipScore
	compare_var_to_value 0x800D, 0x4
	goto_if 0x4, PacifidlogTown_House2_EventScript_001F7A84
	specialvar 0x800D, GetLeadMonFriendshipScore
	compare_var_to_value 0x800D, 0x2
	goto_if 0x4, PacifidlogTown_House2_EventScript_001F7AB3
	goto PacifidlogTown_House2_EventScript_001F7ABD
	end

PacifidlogTown_House2_EventScript_001F7A4C::
	checkflag 0x12B
	goto_if 0x0, 0x08244178
	specialvar 0x800D, GetDaysUntilPacifidlogTMAvailable
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, PacifidlogTown_House2_EventScript_001F7A80
	return

PacifidlogTown_House2_EventScript_001F7A66::
	loadword 0x0, gJPText_001F7B93
	callstd 0x4
	return

PacifidlogTown_House2_EventScript_001F7A6F::
	loadword 0x0, gJPText_001F7B35
	callstd 0x4
	loadword 0x0, gJPText_001F7B93
	callstd 0x4
	return

PacifidlogTown_House2_EventScript_001F7A80::
	clearflag 0x12B
	return

PacifidlogTown_House2_EventScript_001F7A84::
	loadword 0x0, gJPText_001F7BA2
	callstd 0x4
	setorcopyvar 0x8000, 0x13B
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x12B
	special SetPacifidlogTMReceivedDay
	loadword 0x0, gJPText_001F7C43
	callstd 0x4
	release
	end

PacifidlogTown_House2_EventScript_001F7AB3::
	loadword 0x0, gJPText_001F7BD5
	callstd 0x4
	release
	end

PacifidlogTown_House2_EventScript_001F7ABD::
	loadword 0x0, gJPText_001F7C0F
	callstd 0x4
	setorcopyvar 0x8000, 0x135
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setflag 0x12B
	special SetPacifidlogTMReceivedDay
	loadword 0x0, gJPText_001F7C43
	callstd 0x4
	release
	end

PacifidlogTown_House2_EventScript_001F7AEC::
	specialvar 0x800D, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring 0x0, 0x800D
	loadword 0x0, gJPText_001F7C8C
	callstd 0x4
	release
	end

PacifidlogTown_House2_EventScript_001F7AFF::
	lock
	faceplayer
	waitse
	playmoncry 0x15E, 0x0
	loadword 0x0, gJPText_001F7CE4
	callstd 0x4
	waitdooranim
	loadword 0x0, gJPText_001F7CEC
	callstd 0x4
	release
	end

PacifidlogTown_House2_EventScript_001F7B1A::
	lock
	faceplayer
	waitse
	playmoncry 0x15E, 0x2
	loadword 0x0, gJPText_001F7CFC
	callstd 0x4
	waitdooranim
	loadword 0x0, gJPText_001F7D07
	callstd 0x4
	release
	end

	.globl gJPText_001F7B35
gJPText_001F7B35: @ 0x081F7B35
	.string "ウォッホン！！\p"
	.string "わしが　ポケモン　だいすきクラブで\n"
	.string "いちばーん　えらい　かいちょうの⋯⋯\p"
	.string "おとうと　ですぞ！\p"
	.string "まあ　ここで　ポケモンと　いっしょに\n"
	.string "バカンスを　たのしんで　おるのですな！$"

	.globl gJPText_001F7B93
gJPText_001F7B93: @ 0x081F7B93
	.string "ほう！\n"
	.string "きみの　ポケモン⋯⋯$"

	.globl gJPText_001F7BA2
gJPText_001F7BA2: @ 0x081F7BA2
	.string "とっても　なついて　いますなあ\p"
	.string "そんな　かわいらしい　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

	.globl gJPText_001F7BD5
gJPText_001F7BD5: @ 0x081F7BD5
	.string "ふむう⋯⋯\n"
	.string "わるくは　ないんだが　よくもない⋯⋯\p"
	.string "おやの　トレーナーである　きみの\n"
	.string "どりょくが　ひつよう　ですな！$"

	.globl gJPText_001F7C0F
gJPText_001F7C0F: @ 0x081F7C0F
	.string "なんだか　めつきが　わるいですのう\p"
	.string "そんな　こわそうな　ポケモンには\n"
	.string "この　わざマシン　どうですかな？$"

	.globl gJPText_001F7C43
gJPText_001F7C43: @ 0x081F7C43
	.string "ポケモンの　なつきぐあいが　たかいと\n"
	.string "おんがえしの　いりょくも　たかくなる\p"
	.string "なつきぐあいが　ひくいと\n"
	.string "やつあたりの　いりょくが　つよまるんだよ！$"

	.globl gJPText_001F7C8C
gJPText_001F7C8C: @ 0x081F7C8C
	.string "そうそう　あと{STRING 0x02}にち　たてば\n"
	.string "いい　わざマシンが　てに　はいるんだよ！\p"
	.string "そのとき　また　あそびに　きたまえ！\n"
	.string "きみの　ポケモンに　あった\l"
	.string "すてきな　わざマシンを　あげるから$"

	.globl gJPText_001F7CE4
gJPText_001F7CE4: @ 0x081F7CE4
	.string "ルリリ“るりー$"

	.globl gJPText_001F7CEC
gJPText_001F7CEC: @ 0x081F7CEC
	.string "とっても　なついて　いるようだ$"

	.globl gJPText_001F7CFC
gJPText_001F7CFC: @ 0x081F7CFC
	.string "ルリリ“ルルリッ！！$"

	.globl gJPText_001F7D07
gJPText_001F7D07: @ 0x081F7D07
	.string "あんまり　なついて　いないようだ⋯⋯$"
