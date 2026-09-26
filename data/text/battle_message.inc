@ JP Battle Strings payload (0x085A9628-0x085A9D15).
@ Pointer-table ownership remains in data/data_b2d_rest.s until all 369 entries
@ can be moved as one byte-exact battle-message table.
@ Every string below is decoded from the JP ROM and round-trips through preproc.
@ STRINGID_EMPTYSTRING4 is a JP EXP grammar particle, not an empty string.

sText_Trainer1LoseText: @ 0x085A9628
	.string "{B_TRAINER1_LOSE_TEXT}$"

sText_PkmnGainedEXP: @ 0x085A962B
	.string "{B_BUFF1}{B_BUFF2}　けいけんちを　もらった！\p$"

sText_ExpGainedNoBonus: @ 0x085A963E
	.string "は\n$"

sText_ABoosted: @ 0x085A9641
	.string "は　おおめに\n$"

sText_PkmnGrewToLv: @ 0x085A9649
	.string "{B_BUFF1}は\nレベル{B_BUFF2}　に　あがった！{WAIT_SE}\p$"

sText_PkmnLearnedMove: @ 0x085A965E
	.string "{B_BUFF1}は\n{B_BUFF2}を　おぼえた！{WAIT_SE}\p$"

sText_TryToLearnMove1: @ 0x085A966F
	.string "{B_BUFF1}は　あたらしく\n{B_BUFF2}を　おぼえたい⋯⋯⋯！\p$"

sText_TryToLearnMove2: @ 0x085A9688
	.string "しかし　{B_BUFF1}は　わざを　4つ\nおぼえるので　せいいっぱいだ！\p$"

sText_TryToLearnMove3: @ 0x085A96A8
	.string "{B_BUFF2}の　かわりに\nほかの　わざを　わすれさせますか？$"

sText_PkmnForgotMove: @ 0x085A96C3
	.string "{B_BUFF1}は　{B_BUFF2}の\nつかいかたを　きれいに　わすれた！\p$"

sText_StopLearningMove: @ 0x085A96DE
	.string "{PAUSE 0x20}それでは⋯⋯　{B_BUFF2}を\nおぼえるのを　あきらめますか？$"

sText_DidNotLearnMove: @ 0x085A96FC
	.string "{B_BUFF1}は　{B_BUFF2}を\nおぼえずに　おわった！\p$"

sText_UseNextPkmn: @ 0x085A9711
	.string "つぎの　ポケモンを　つかいますか？$"

sText_AttackMissed: @ 0x085A9723
	.string "しかし　{B_ATK_NAME_WITH_PREFIX}の\nこうげきは　はずれた！$"

sText_PkmnProtectedItself: @ 0x085A9737
	.string "{B_DEF_NAME_WITH_PREFIX}は　こうげきから\nみを　まもった！$"

sText_AvoidedDamage: @ 0x085A974B
	.string "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\nダメージを　うけない！$"

sText_PkmnMakesGroundMiss: @ 0x085A975F
	.string "{B_DEF_NAME_WITH_PREFIX}は　{B_DEF_ABILITY}で\nじめんタイプの　わざが　あたらない！$"

sText_PkmnAvoidedAttack: @ 0x085A977A
	.string "{B_DEF_NAME_WITH_PREFIX}には\nあたらなかった！$"

sText_ItDoesntAffect: @ 0x085A9788
	.string "{B_DEF_NAME_WITH_PREFIX}には\nこうかが　ない　みたいだ⋯⋯$"

sText_AttackerFainted: @ 0x085A979C
	.string "{B_ATK_NAME_WITH_PREFIX}は　たおれた！\p$"

sText_TargetFainted: @ 0x085A97A7
	.string "{B_DEF_NAME_WITH_PREFIX}は　たおれた！\p$"

sText_PlayerGotMoney: @ 0x085A97B2
	.string "{B_PLAYER_NAME}は　しょうきんとして\n{B_BUFF1}¥　てにいれた！\p$"

sText_PlayerWhiteout: @ 0x085A97CB
	.string "{B_PLAYER_NAME}の　てもとには\nたたかえる　ポケモンが　いない！\p$"

sText_PlayerWhiteout2: @ 0x085A97E7
	.string "{B_PLAYER_NAME}は\nめのまえが　まっくらに　なった！{PAUSE_UNTIL_PRESS}$"

sText_PreventsEscape: @ 0x085A97FE
	.string "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\nにげられない！\p$"

sText_CantEscape2: @ 0x085A980F
	.string "にげられない！\p$"

sText_AttackerCantEscape: @ 0x085A9818
	.string "{B_ATK_NAME_WITH_PREFIX}は　にげられない！$"

sText_HitXTimes: @ 0x085A9824
	.string "{B_BUFF1}かい　あたった！$"

sText_PkmnFellAsleep: @ 0x085A982F
	.string "{B_EFF_NAME_WITH_PREFIX}は\nねむってしまった！$"

sText_PkmnMadeSleep: @ 0x085A983D
	.string "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　ねむってしまった！$"

sText_PkmnAlreadyAsleep: @ 0x085A9853
	.string "{B_DEF_NAME_WITH_PREFIX}は　すでに\nねむっている$"

sText_PkmnAlreadyAsleep2: @ 0x085A9862
	.string "{B_ATK_NAME_WITH_PREFIX}は　すでに\nねむっている$"

sText_PkmnWasntAffected: @ 0x085A9871
	.string "しかし　{B_DEF_NAME_WITH_PREFIX}には\nきかなかった！$"

sText_PkmnWasPoisoned: @ 0x085A9882
	.string "{B_EFF_NAME_WITH_PREFIX}は　どくをあびた！$"

sText_PkmnPoisonedBy: @ 0x085A988E
	.string "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　どくをあびた！$"

sText_PkmnHurtByPoison: @ 0x085A98A2
	.string "{B_ATK_NAME_WITH_PREFIX}は\nどくの　ダメージを　うけている！$"

sText_PkmnAlreadyPoisoned: @ 0x085A98B7
	.string "{B_DEF_NAME_WITH_PREFIX}は　すでに\nどくを　あびている$"

sText_PkmnBadlyPoisoned: @ 0x085A98C9
	.string "{B_EFF_NAME_WITH_PREFIX}は\nもうどくをあびた！$"

sText_PkmnEnergyDrained: @ 0x085A98D7
	.string "{B_DEF_NAME_WITH_PREFIX}から\nたいりょくを　すいとった！$"

sText_PkmnWasBurned: @ 0x085A98EA
	.string "{B_EFF_NAME_WITH_PREFIX}は\nやけどをおった！$"

sText_PkmnBurnedBy: @ 0x085A98F7
	.string "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　やけどをおった！$"

sText_PkmnHurtByBurn: @ 0x085A990C
	.string "{B_ATK_NAME_WITH_PREFIX}は\nやけどの　ダメージを　うけている！$"

sText_PkmnAlreadyHasBurn: @ 0x085A9922
	.string "{B_DEF_NAME_WITH_PREFIX}は　すでに\nやけどを　おっている$"

sText_PkmnWasFrozen: @ 0x085A9935
	.string "{B_EFF_NAME_WITH_PREFIX}は\nこおりづけになった！$"

sText_PkmnFrozenBy: @ 0x085A9944
	.string "{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\n{B_EFF_NAME_WITH_PREFIX}は　こおりづけになった！$"

sText_PkmnIsFrozen: @ 0x085A995B
	.string "{B_ATK_NAME_WITH_PREFIX}は\nこおって　しまって　うごかない！$"

sText_PkmnWasDefrosted: @ 0x085A9970
	.string "{B_DEF_NAME_WITH_PREFIX}の\nこおりが　とけた！$"

sText_PkmnWasDefrosted2: @ 0x085A997E
	.string "{B_ATK_NAME_WITH_PREFIX}の\nこおりが　とけた！$"

sText_PkmnWasDefrostedBy: @ 0x085A998C
	.string "{B_ATK_NAME_WITH_PREFIX}の　こおりが\n{B_CURRENT_MOVE}で　とけた！$"

sText_PkmnWasParalyzed: @ 0x085A999E
	.string "{B_EFF_NAME_WITH_PREFIX}は　まひして\nわざが　でにくくなった！$"

sText_PkmnWasParalyzedBy: @ 0x085A99B4
	.string "{B_EFF_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}の　{B_SCR_ACTIVE_ABILITY}で\lまひして　わざが　でにくくなった！$"

sText_PkmnIsParalyzed: @ 0x085A99D2
	.string "{B_ATK_NAME_WITH_PREFIX}は\nからだが　しびれて　うごけない$"

sText_PkmnIsAlreadyParalyzed: @ 0x085A99E6
	.string "{B_DEF_NAME_WITH_PREFIX}は　すでに\nまひしている$"

sText_PkmnHealedParalysis: @ 0x085A99F5
	.string "{B_DEF_NAME_WITH_PREFIX}の\nまひが　なおった！$"

sText_PkmnDreamEaten: @ 0x085A9A03
	.string "{B_DEF_NAME_WITH_PREFIX}の\nゆめを　くった！$"

sText_StatsWontIncrease: @ 0x085A9A10
	.string "{B_ATK_NAME_WITH_PREFIX}の\n{B_BUFF1}は　もうあがらない！$"

sText_StatsWontDecrease: @ 0x085A9A21
	.string "{B_DEF_NAME_WITH_PREFIX}の\n{B_BUFF1}は　もうさがらない！$"

sText_TeamStoppedWorking: @ 0x085A9A32
	.string "みかたの　{B_BUFF1}の\nこうかが　きれた！$"

sText_FoeStoppedWorking: @ 0x085A9A45
	.string "あいての　{B_BUFF1}の\nこうかが　きれた！$"

sText_PkmnIsConfused: @ 0x085A9A58
	.string "{B_ATK_NAME_WITH_PREFIX}は\nこんらんしている！$"

sText_PkmnHealedConfusion: @ 0x085A9A66
	.string "{B_ATK_NAME_WITH_PREFIX}の\nこんらんが　とけた！$"

sText_PkmnWasConfused: @ 0x085A9A75
	.string "{B_EFF_NAME_WITH_PREFIX}は\nこんらんした！$"

sText_PkmnAlreadyConfused: @ 0x085A9A81
	.string "{B_DEF_NAME_WITH_PREFIX}は\nすでに　こんらん　している$"

sText_PkmnFellInLove: @ 0x085A9A93
	.string "{B_DEF_NAME_WITH_PREFIX}は\nメロメロに　なった！$"

sText_PkmnInLove: @ 0x085A9AA2
	.string "{B_ATK_NAME_WITH_PREFIX}は\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}に　メロメロだ！$"

sText_PkmnImmobilizedByLove: @ 0x085A9AB1
	.string "{B_ATK_NAME_WITH_PREFIX}は　メロメロで\nわざが　だせなかった！$"

sText_PkmnBlownAway: @ 0x085A9AC7
	.string "{B_DEF_NAME_WITH_PREFIX}は\nふきとばされた！$"

sText_PkmnChangedType: @ 0x085A9AD4
	.string "{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}タイプに　なった！$"

sText_PkmnFlinched: @ 0x085A9AE4
	.string "{B_ATK_NAME_WITH_PREFIX}は　ひるんで\nうごけなかった！$"

sText_PkmnRegainedHealth: @ 0x085A9AF6
	.string "{B_DEF_NAME_WITH_PREFIX}は　たいりょくを\nかいふくした！$"

sText_PkmnHPFull: @ 0x085A9B09
	.string "しかし　{B_DEF_NAME_WITH_PREFIX}の\nたいりょくは　まんたんだ！$"

sText_PkmnRaisedSpDef: @ 0x085A9B1F
	.string "{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nとくこうに　つよくなった！$"

sText_PkmnRaisedSpDefALittle: @ 0x085A9B34
	.string "{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nとくこうに　すこし　つよくなった！$"

sText_PkmnRaisedDef: @ 0x085A9B4D
	.string "{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nだげきこうげきに　つよくなった！$"

sText_PkmnRaisedDefALittle: @ 0x085A9B65
	.string "{B_ATK_PREFIX2}　{B_CURRENT_MOVE}で\nだげきこうげきに　すこし　つよくなった！$"

sText_PkmnCoveredByVeil: @ 0x085A9B81
	.string "{B_ATK_PREFIX2}\nしんぴのベールに　つつまれた！$"

sText_PkmnUsedSafeguard: @ 0x085A9B94
	.string "{B_DEF_NAME_WITH_PREFIX}は\nしんぴのベールに　まもられている！$"

sText_PkmnSafeguardExpired: @ 0x085A9BAA
	.string "{B_ATK_PREFIX3}　つつんでいた\nしんぴの　ベールが　なくなった！$"

sText_PkmnWentToSleep: @ 0x085A9BC5
	.string "{B_ATK_NAME_WITH_PREFIX}は\nねむりはじめた！$"

sText_PkmnSleptHealthy: @ 0x085A9BD2
	.string "{B_ATK_NAME_WITH_PREFIX}は\nけんこうになって　ねむりはじめた！$"

sText_PkmnWhippedWhirlwind: @ 0x085A9BE8
	.string "{B_ATK_NAME_WITH_PREFIX}の　まわりで\nくうきが　うずを　まく！$"

sText_PkmnTookSunlight: @ 0x085A9BFE
	.string "{B_ATK_NAME_WITH_PREFIX}は\nひかりを　きゅうしゅうした！$"

sText_PkmnLoweredHead: @ 0x085A9C11
	.string "{B_ATK_NAME_WITH_PREFIX}は\nくびを　ひっこめた！$"

sText_PkmnIsGlowing: @ 0x085A9C20
	.string "{B_ATK_NAME_WITH_PREFIX}を\nはげしい　ひかりが　つつむ！$"

sText_PkmnFlewHigh: @ 0x085A9C33
	.string "{B_ATK_NAME_WITH_PREFIX}は\nそらたかく　とびあがった！$"

sText_PkmnDugHole: @ 0x085A9C45
	.string "{B_ATK_NAME_WITH_PREFIX}は\nあなをほって　ちちゅうに　もぐった！$"

sText_PkmnHidUnderwater: @ 0x085A9C5C
	.string "{B_ATK_NAME_WITH_PREFIX}は\nすいちゅうに　みをひそめた！$"

sText_PkmnSprangUp: @ 0x085A9C6F
	.string "{B_ATK_NAME_WITH_PREFIX}は\nとびはねた！$"

sText_PkmnSqueezedByBind: @ 0x085A9C7A
	.string "{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}に\nしめつけられた！$"

sText_PkmnTrappedInVortex: @ 0x085A9C8B
	.string "{B_DEF_NAME_WITH_PREFIX}は　うずの　なかに\nとじこめられた！$"

sText_PkmnTrappedBySandTomb: @ 0x085A9CA0
	.string "{B_DEF_NAME_WITH_PREFIX}は　すなじごくに\nとらわれた！$"

sText_PkmnWrappedBy: @ 0x085A9CB2
	.string "{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}に\nまきつかれた！$"

sText_PkmnClamped: @ 0x085A9CC2
	.string "{B_DEF_NAME_WITH_PREFIX}は　{B_ATK_NAME_WITH_PREFIX}の\nからに　はさまれた！$"

sText_PkmnHurtBy: @ 0x085A9CD5
	.string "{B_ATK_NAME_WITH_PREFIX}は　{B_BUFF1}の\nダメージを　うけている$"

sText_PkmnFreedFrom: @ 0x085A9CE9
	.string "{B_ATK_NAME_WITH_PREFIX}は\n{B_BUFF1}から　かいほうされた！$"

sText_PkmnCrashed: @ 0x085A9CFB
	.string "いきおい　あまって\n{B_ATK_NAME_WITH_PREFIX}は　じめんに　ぶつかった！$"
