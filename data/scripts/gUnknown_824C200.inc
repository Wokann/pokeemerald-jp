	faceplayer 
	bufferleadmonspeciesname 0x63
	dotrainerbattle 
	moveobjectoffscreen 0x69FF
	waitmoncry 
	multichoice 0x79, 0x77, 0x7E, 0x58
	.byte 0xFF
	dotrainerbattle 
	waitmoncry 
	messageautoscroll 0x587E77AE
	.byte 0xFF
	lock 
	waitmovement_at 0xAE9B, 0x777E
	showobject_at 0x6FFF, 0x5D60
	waitmoncry 
	showcontestwinner 0x7E
	showobject_at 0x12FF, 0x30C
	gettime 
	.byte 0xFF
	goto_if 0x50, 0xFF0B260A
	return 
	.string "つ{BLUE}{DYNAMIC_COLOR3}{DYNAMIC_COLOR2}$"
	.string "{GREEN}{MUS_RG_TRAINER_TOWER}{DYNAMIC_COLOR2}$"
	.string "{GREEN}{DYNAMIC_COLOR3}{DYNAMIC_COLOR1}{DYNAMIC_COLOR2}$"
	.string "た{BLUE}ま{DYNAMIC_COLOR3}{DYNAMIC_COLOR2}$"
	.string "スーパ{SE_M_PAY_DAY}クール\n"
	.string "ノンストッ{SE_M_WING_ATTACK}{B_COPY_VAR_1}$"
	.string "グッドルッキ{SE_M_BUBBLE3}ポケモ{SE_M_BUBBLE3}{B_COPY_VAR_1}$"
	.string "マーベラ{SE_ROULETTE_BALL2}ワンダフル\n"
	.string "グレー{SE_CONTEST_ICON_CLEAR}{B_COPY_VAR_1}$"
	.string "{DYNAMIC_COLOR1}ん{MUS_RG_PEWTER}{SE_WALL_HIT}{MUS_RG_VICTORY_WILD}ご{SE_A}ビーナス\n"
	.string "ビューティ{SE_M_PAY_DAY}{B_COPY_VAR_1}$"
	.string "{B_COPY_VAR_1}{TRANSPARENT}クン{SE_A}マブシイ\n"
	.string "キラキ{SE_M_THUNDERBOLT2}スマイル$"
	.string "ポケモンセンタ{SE_M_PAY_DAY}の\n"
	.string "スーパ{SE_M_PAY_DAY}アイド{SE_M_NIGHTMARE}{B_COPY_VAR_1}$"
	.string "ラブリ{SE_M_PAY_DAY}スウィー{SE_CONTEST_ICON_CLEAR}{B_COPY_VAR_1}{TRANSPARENT}ちゃん$"
	.string "プリティ{SE_M_PAY_DAY}{B_COPY_VAR_1}たんの\n"
	.string "{LIGHT_RED}{DYNAMIC_COLOR4}ま{SE_NOT_EFFECTIVE}ショット$"
	.string "{DYNAMIC_COLOR1}っ{SE_FLEE}{MUS_RG_SEVII_ROUTE}て！\n"
	.string "キュー{SE_CONTEST_ICON_CLEAR}ポケモ{SE_M_BUBBLE3}{B_COPY_VAR_1}{TRANSPARENT}ちゃん$"
	.string "{GREEN}{DYNAMIC_COLOR3}{DYNAMIC_COLOR1}{SE_BIKE_BELL}マエストロ\n"
	.string "ワイ{SE_M_CRABHAMMER}ポケモ{SE_M_BUBBLE3}{B_COPY_VAR_1}$"
	.string "{RED}らばれ{SE_FAINT}ポケモン⋯\n"
	.string "ポケモン{SE_A}な{GREEN}{SE_A}ポケモ{SE_M_BUBBLE3}{B_COPY_VAR_1}$"
	.string "エクセレン{SE_CONTEST_ICON_CLEAR}{B_COPY_VAR_1}{TRANSPARENT}の\n"
	.string "ゆ{LIGHT_GRAY}が{SE_PIN}ひとと{LIGHT_GREEN}$"
	.string "パワフ{SE_M_NIGHTMARE}マッスル\n"
	.string "ハッス{SE_M_NIGHTMARE}{B_COPY_VAR_1}$"
	.string "ストロン{SE_M_ICY_WIND}ストロンガー\n"
	.string "ストロンゲス{SE_CONTEST_ICON_CLEAR}{B_COPY_VAR_1}$"
	.string "タフネ{SE_ROULETTE_BALL2}マイティー\n"
	.string "ハイパーポケモ{SE_M_BUBBLE3}{B_COPY_VAR_1}！$"
	.string "ナゾノクサ$"
	.string "ポチエナ$"
	.string "スバメ$"
	.string "ルリリ$"
	.string "ハスボー$"
	.string "キャモメ$"
	.string "ドクケイル$"
	.string "ズバット$"
	.string "ツチニン$"
	.string "ラルトス$"
	.string "ジグザグマ$"
	.string "ナマケロ$"
	.string "ポチエナ$"
	.string "キノココ$"
	.string "ジグザグマ$"
	.string "ポチエナ$"
	.string "ズバット$"
	.string "キバニア$"
	.string "や{LIGHT_BLUE}どな{LIGHT_RED}{DYNAMIC_COLOR3}$"
	.string "ハーバーメール$"
	.string "{LIGHT_RED}なじねだん$"
	.string "60{RED}ん$"
	.string "55{RED}ん$"
	.string "の{DYNAMIC_COLOR1}ら{MUS_RG_GAME_FREAK}$"
	.string "た{GREEN}{BLUE}なる$"
	.string "や{DYNAMIC_COLOR4}{BLUE}なる$"
	.string "{LIGHT_RED}なじねだん$"
	.string "だん{MUS_RG_PEWTER}$"
	.string "じょ{MUS_RG_PEWTER}$"
	.string "どっちでも{MUS_RG_GAME_FREAK}$"
	.string "{LIGHT_RED}{PH_FLEECE_SOLO}{DYNAMIC_COLOR2}ん$"
	.string "{LIGHT_RED}ば{WHITE}{DYNAMIC_COLOR2}ん$"
	.string "{LIGHT_RED}なじ{GREEN}ず$"
	.string "{DARK_GRAY}{MUS_RG_GAME_FREAK}$"
	.string "ひとり$"
	.string "ふたり$"
	.string "2ひ{LIGHT_GREEN}$"
	.string "3ひ{LIGHT_GREEN}$"
	.string "4ひ{LIGHT_GREEN}$"
	.string "6つ$"
	.string "7つ$"
	.string "8つ$"
	.string "6にん$"
	.string "7にん$"
	.string "8にん$"
