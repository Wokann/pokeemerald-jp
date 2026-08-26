@ SlateportCity_OceanicMuseum_2F scripts (JP map g9 m8 @ 0x081FD309)

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern:: @ 0x081FD30A
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch:: @ 0x081FD496
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts:: @ 0x081FD49C
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts:: @ 0x081FD4A7
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth:: @ 0x081FD4B2
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest:: @ 0x081FD4BD
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1:: @ 0x081FD514
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2:: @ 0x081FD51D
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment:: @ 0x081FD526
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel:: @ 0x081FD52F
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay:: @ 0x081FD538
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay:: @ 0x081FD541
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica:: @ 0x081FD54A
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica:: @ 0x081FD553
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica:: @ 0x081FD55C
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica:: @ 0x081FD565
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1:: @ 0x081FD56E
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2:: @ 0x081FD577
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3:: @ 0x081FD580
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts: @ 0x081FD597
	.string "はい？　クスノキは　わたし　だが⋯⋯？\p"
	.string "おお！　それは　デボンの　ツワブキさんに\n"
	.string "たのんで　おいた　パーツだね！\p"
	.string "いやー　どうも　ごくろうさま！\n"
	.string "おかげで　しゅっぱつ　できそうだ⋯⋯$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts: @ 0x081FD5F3
	.string "へへへ　その　パーツ\n"
	.string "おれたちが　いただくぜ！$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou: @ 0x081FD60B
	.string "クスノキ“だ　だれだ　きみたちは！$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua: @ 0x081FD61D
	.string "おれたち　アクアだん！\p"
	.string "リーダーが　そのパーツを　ほしがってるんだ！\n"
	.string "なにも　いわずに　よこせ！$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat: @ 0x081FD64E
	.string "うわー！\n"
	.string "こどもに　やられちまった！$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious: @ 0x081FD661
	.string "やばい⋯⋯\n"
	.string "リーダーに　おこられちまうぞ⋯⋯$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis: @ 0x081FD678
	.string "ふん！　だらしない　やつめ！\n"
	.string "ここは　おれに　まかせてもらうぜ！$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat: @ 0x081FD699
	.string "なんだと！\n"
	.string "おれも　まけてしまった！$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid: @ 0x081FD6AC
	.string "ど　どうしよう⋯⋯\n"
	.string "パーツを　うばえないと　まずくないか？\p"
	.string "うむ⋯⋯\n"
	.string "まさか　こどもに　じゃま　されるなんて\l"
	.string "これっぽっちも　おもってなかったぜ$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong: @ 0x081FD6F5
	.string "パーツを　うばうのに\n"
	.string "いつまで　かかっているのかと　おもえば\l"
	.string "こんな　こどもに　じゃま　されていたのか？$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning: @ 0x081FD72A
	.string "われわれは\n"
	.string "うみを　あいする　アクアだん！\p"
	.string "そして　おれは\n"
	.string "アクアだんの　リーダー　アオギリだ\p"
	.string "われわれの　じゃまをする　おまえは⋯⋯\n"
	.string "ま　まさか！\l"
	.string "マグマだんの　なかま　なのか！？\p"
	.string "いや　それにしては\n"
	.string "みにつけている　ふくが　ちがうな\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ポケモンも　ひとも　すべての　いのちは\n"
	.string "うみから　うまれた⋯⋯\p"
	.string "だから　アクアだんは\n"
	.string "うみを　ふやそうと　しているのだよ\p"
	.string "どうだい？\n"
	.string "とても　すばらしい　ことだろう？\p"
	.string "まあ　いい⋯⋯\n"
	.string "まだ　わかい　おまえに\l"
	.string "われわれの　りそうなど　わかるまい⋯⋯\p"
	.string "だが　このさきも　われわれの\n"
	.string "かつどうを　じゃまする　つもりなら\l"
	.string "ただでは　すまさない　からな！\p"
	.string "それだけは　おぼえて　おくのだ！$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs: @ 0x081FD871
	.string "クスノキ“きみは⋯⋯\n"
	.string "そうか　{PLAYER}{KUN}　というのか⋯⋯\p"
	.string "いやあ　あぶない　ところ　だった！\n"
	.string "たすけてくれて　ありがとうよ！\p"
	.string "おっと　そうだった！\n"
	.string "デボンに　たのんでおいた　パーツを\l"
	.string "もってきて　くれたの　わすれていたよ！$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo: @ 0x081FD8E0
	.string "クスノキ“おっと！\n"
	.string "こうしちゃ　いられない！\p"
	.string "そろそろ　かいてい　ちょうさに\n"
	.string "しゅっぱつ　する　じかんだ！\p"
	.string "わたしは　これで　しつれい　するけど\n"
	.string "きみは　ゆっくり　かんないを\l"
	.string "けんぶつ　していって　くれたまえ！$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip: @ 0x081FD94A
	.string "ふねの　もけいを　みておると\n"
	.string "ムロの　ちかくに　ある\l"
	.string "すてられぶねを　おもいだすのう⋯⋯$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum: @ 0x081FD977
	.string "はくぶつかんの　なかを\n"
	.string "はしり　まわるんじゃ　ありませんよッ！$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine: @ 0x081FD997
	.string "せんすいてい　かっこいー！\n"
	.string "おれも　のりてーよ！$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1: @ 0x081FD9B0
	.string "‘すいしつ　サンプル　1’\n"
	.string "と　かかれた　ラベルが　はってある！\p"
	.string "うみは　みんな　つながって　いるのに\n"
	.string "ちいきに　よって　すこし　ちがうらしい$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2: @ 0x081FD9F8
	.string "‘すいしつ　サンプル　2’\n"
	.string "と　かかれた　ラベルが　はってある！\p"
	.string "ちいきが　ちがえば　うみの　みずの\n"
	.string "しょっぱさも　ちがったり　するのかな？$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment: @ 0x081FDA3F
	.string "ゴムで　できた　ボールが\n"
	.string "ふくらんだり　しぼんだり　している！\p"
	.string "‘うみの　そこには　すいあつ　といって\n"
	.string "　みずじたいの　おもさが　かかります’\p"
	.string "‘あさい　ところでは　すいあつも　かるく\n"
	.string "　ふかい　ところでは　なんまんトン　もの\l"
	.string "　すいあつが　かかるのです’$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel: @ 0x081FDAC0
	.string "‘ホウエン　ちほうの　もけい’\p"
	.string "ホウエンちほう　ぜんたいの　ミニチュアだ！\n"
	.string "ミシロタウンは　どのへん　だろう？$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay: @ 0x081FDAF8
	.string "かいすいの　ながれに　ついての　てんじだ！\p"
	.string "‘うみの　そこに　ちかい　ところ　では\n"
	.string "　みずの　おんどや　えんぶんの　ちがいで\l"
	.string "　うみの　みずが　ながれて　いきます’$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay: @ 0x081FDB4B
	.string "かいすいの　ながれに　ついての　てんじだ！\p"
	.string "‘うみの　ひょうめん　あたり　では\n"
	.string "　かぜの　ちからに　よって\l"
	.string "　うみの　みずが　ながれて　いきます’$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica: @ 0x081FDB95
	.string "‘れんらくせん　タイドリップごう’\p"
	.string "これは　げんざい　クスノキ　ぞうせんじょで\n"
	.string "つくられている　ふねの　もけい　です！$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica: @ 0x081FDBD1
	.string "‘せんすいてい　かいえん　1ごう’\p"
	.string "うみの　そこを　ちょうさ　するための\n"
	.string "こうせいのう　せんすいていの　もけい　です！$"

SlateportCity_OceanicMuseum_2F_Text_SubmersibleReplica: @ 0x081FDC0D
	.string "‘せんすい　ポッド’\p"
	.string "かいていで　さぎょうを　するための\n"
	.string "むじん　こがたポッドの　もけい　です！$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica: @ 0x081FDC3E
	.string "‘サント·アンヌ　ごう’\p"
	.string "せかいを　いっしゅう　している\n"
	.string "ごうか　きゃくせんの　もけい　です！$"
