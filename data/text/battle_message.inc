@ JP Battle Strings payload (0x085A9628-0x085A9D15).
@ Pointer-table ownership remains in data/data_b2d_rest.s until all 369 entries
@ can be moved as one byte-exact battle-message table.
@ Every string below is decoded from the JP ROM and round-trips through preproc.
@ STRINGID_EMPTYSTRING4 is a JP EXP grammar particle, not an empty string.

sText_Trainer1LoseText: @ 0x085A9628
	.string "{STRING 0x24}$"

sText_PkmnGainedEXP: @ 0x085A962B
	.string "{STRING 0x00}{STRING 0x01}　けいけんちを　もらった！\p$"

sText_ExpGainedNoBonus: @ 0x085A963E
	.string "は\n$"

sText_ABoosted: @ 0x085A9641
	.string "は　おおめに\n$"

sText_PkmnGrewToLv: @ 0x085A9649
	.string "{STRING 0x00}は\nレベル{STRING 0x01}　に　あがった！{WAIT_SE}\p$"

sText_PkmnLearnedMove: @ 0x085A965E
	.string "{STRING 0x00}は\n{STRING 0x01}を　おぼえた！{WAIT_SE}\p$"

sText_TryToLearnMove1: @ 0x085A966F
	.string "{STRING 0x00}は　あたらしく\n{STRING 0x01}を　おぼえたい⋯⋯⋯！\p$"

sText_TryToLearnMove2: @ 0x085A9688
	.string "しかし　{STRING 0x00}は　わざを　4つ\nおぼえるので　せいいっぱいだ！\p$"

sText_TryToLearnMove3: @ 0x085A96A8
	.string "{STRING 0x01}の　かわりに\nほかの　わざを　わすれさせますか？$"

sText_PkmnForgotMove: @ 0x085A96C3
	.string "{STRING 0x00}は　{STRING 0x01}の\nつかいかたを　きれいに　わすれた！\p$"

sText_StopLearningMove: @ 0x085A96DE
	.string "{PAUSE 0x20}それでは⋯⋯　{STRING 0x01}を\nおぼえるのを　あきらめますか？$"

sText_DidNotLearnMove: @ 0x085A96FC
	.string "{STRING 0x00}は　{STRING 0x01}を\nおぼえずに　おわった！\p$"

sText_UseNextPkmn: @ 0x085A9711
	.string "つぎの　ポケモンを　つかいますか？$"

sText_AttackMissed: @ 0x085A9723
	.string "しかし　{STRING 0x0F}の\nこうげきは　はずれた！$"

sText_PkmnProtectedItself: @ 0x085A9737
	.string "{STRING 0x10}は　こうげきから\nみを　まもった！$"

sText_AvoidedDamage: @ 0x085A974B
	.string "{STRING 0x10}は　{STRING 0x19}で\nダメージを　うけない！$"

sText_PkmnMakesGroundMiss: @ 0x085A975F
	.string "{STRING 0x10}は　{STRING 0x19}で\nじめんタイプの　わざが　あたらない！$"

sText_PkmnAvoidedAttack: @ 0x085A977A
	.string "{STRING 0x10}には\nあたらなかった！$"

sText_ItDoesntAffect: @ 0x085A9788
	.string "{STRING 0x10}には\nこうかが　ない　みたいだ⋯⋯$"

sText_AttackerFainted: @ 0x085A979C
	.string "{STRING 0x0F}は　たおれた！\p$"

sText_TargetFainted: @ 0x085A97A7
	.string "{STRING 0x10}は　たおれた！\p$"

sText_PlayerGotMoney: @ 0x085A97B2
	.string "{STRING 0x23}は　しょうきんとして\n{STRING 0x00}¥　てにいれた！\p$"

sText_PlayerWhiteout: @ 0x085A97CB
	.string "{STRING 0x23}の　てもとには\nたたかえる　ポケモンが　いない！\p$"

sText_PlayerWhiteout2: @ 0x085A97E7
	.string "{STRING 0x23}は\nめのまえが　まっくらに　なった！{PAUSE_UNTIL_PRESS}$"

sText_PreventsEscape: @ 0x085A97FE
	.string "{STRING 0x13}の　{STRING 0x1A}で\nにげられない！\p$"

sText_CantEscape2: @ 0x085A980F
	.string "にげられない！\p$"

sText_AttackerCantEscape: @ 0x085A9818
	.string "{STRING 0x0F}は　にげられない！$"

sText_HitXTimes: @ 0x085A9824
	.string "{STRING 0x00}かい　あたった！$"

sText_PkmnFellAsleep: @ 0x085A982F
	.string "{STRING 0x11}は\nねむってしまった！$"

sText_PkmnMadeSleep: @ 0x085A983D
	.string "{STRING 0x13}の　{STRING 0x1A}で\n{STRING 0x11}は　ねむってしまった！$"

sText_PkmnAlreadyAsleep: @ 0x085A9853
	.string "{STRING 0x10}は　すでに\nねむっている$"

sText_PkmnAlreadyAsleep2: @ 0x085A9862
	.string "{STRING 0x0F}は　すでに\nねむっている$"

sText_PkmnWasntAffected: @ 0x085A9871
	.string "しかし　{STRING 0x10}には\nきかなかった！$"

sText_PkmnWasPoisoned: @ 0x085A9882
	.string "{STRING 0x11}は　どくをあびた！$"

sText_PkmnPoisonedBy: @ 0x085A988E
	.string "{STRING 0x13}の　{STRING 0x1A}で\n{STRING 0x11}は　どくをあびた！$"

sText_PkmnHurtByPoison: @ 0x085A98A2
	.string "{STRING 0x0F}は\nどくの　ダメージを　うけている！$"

sText_PkmnAlreadyPoisoned: @ 0x085A98B7
	.string "{STRING 0x10}は　すでに\nどくを　あびている$"

sText_PkmnBadlyPoisoned: @ 0x085A98C9
	.string "{STRING 0x11}は\nもうどくをあびた！$"

sText_PkmnEnergyDrained: @ 0x085A98D7
	.string "{STRING 0x10}から\nたいりょくを　すいとった！$"

sText_PkmnWasBurned: @ 0x085A98EA
	.string "{STRING 0x11}は\nやけどをおった！$"

sText_PkmnBurnedBy: @ 0x085A98F7
	.string "{STRING 0x13}の　{STRING 0x1A}で\n{STRING 0x11}は　やけどをおった！$"

sText_PkmnHurtByBurn: @ 0x085A990C
	.string "{STRING 0x0F}は\nやけどの　ダメージを　うけている！$"

sText_PkmnAlreadyHasBurn: @ 0x085A9922
	.string "{STRING 0x10}は　すでに\nやけどを　おっている$"

sText_PkmnWasFrozen: @ 0x085A9935
	.string "{STRING 0x11}は\nこおりづけになった！$"

sText_PkmnFrozenBy: @ 0x085A9944
	.string "{STRING 0x13}の　{STRING 0x1A}で\n{STRING 0x11}は　こおりづけになった！$"

sText_PkmnIsFrozen: @ 0x085A995B
	.string "{STRING 0x0F}は\nこおって　しまって　うごかない！$"

sText_PkmnWasDefrosted: @ 0x085A9970
	.string "{STRING 0x10}の\nこおりが　とけた！$"

sText_PkmnWasDefrosted2: @ 0x085A997E
	.string "{STRING 0x0F}の\nこおりが　とけた！$"

sText_PkmnWasDefrostedBy: @ 0x085A998C
	.string "{STRING 0x0F}の　こおりが\n{STRING 0x14}で　とけた！$"

sText_PkmnWasParalyzed: @ 0x085A999E
	.string "{STRING 0x11}は　まひして\nわざが　でにくくなった！$"

sText_PkmnWasParalyzedBy: @ 0x085A99B4
	.string "{STRING 0x11}は\n{STRING 0x13}の　{STRING 0x1A}で\lまひして　わざが　でにくくなった！$"

sText_PkmnIsParalyzed: @ 0x085A99D2
	.string "{STRING 0x0F}は\nからだが　しびれて　うごけない$"

sText_PkmnIsAlreadyParalyzed: @ 0x085A99E6
	.string "{STRING 0x10}は　すでに\nまひしている$"

sText_PkmnHealedParalysis: @ 0x085A99F5
	.string "{STRING 0x10}の\nまひが　なおった！$"

sText_PkmnDreamEaten: @ 0x085A9A03
	.string "{STRING 0x10}の\nゆめを　くった！$"

sText_StatsWontIncrease: @ 0x085A9A10
	.string "{STRING 0x0F}の\n{STRING 0x00}は　もうあがらない！$"

sText_StatsWontDecrease: @ 0x085A9A21
	.string "{STRING 0x10}の\n{STRING 0x00}は　もうさがらない！$"

sText_TeamStoppedWorking: @ 0x085A9A32
	.string "みかたの　{STRING 0x00}の\nこうかが　きれた！$"

sText_FoeStoppedWorking: @ 0x085A9A45
	.string "あいての　{STRING 0x00}の\nこうかが　きれた！$"

sText_PkmnIsConfused: @ 0x085A9A58
	.string "{STRING 0x0F}は\nこんらんしている！$"

sText_PkmnHealedConfusion: @ 0x085A9A66
	.string "{STRING 0x0F}の\nこんらんが　とけた！$"

sText_PkmnWasConfused: @ 0x085A9A75
	.string "{STRING 0x11}は\nこんらんした！$"

sText_PkmnAlreadyConfused: @ 0x085A9A81
	.string "{STRING 0x10}は\nすでに　こんらん　している$"

sText_PkmnFellInLove: @ 0x085A9A93
	.string "{STRING 0x10}は\nメロメロに　なった！$"

sText_PkmnInLove: @ 0x085A9AA2
	.string "{STRING 0x0F}は\n{STRING 0x13}に　メロメロだ！$"

sText_PkmnImmobilizedByLove: @ 0x085A9AB1
	.string "{STRING 0x0F}は　メロメロで\nわざが　だせなかった！$"

sText_PkmnBlownAway: @ 0x085A9AC7
	.string "{STRING 0x10}は\nふきとばされた！$"

sText_PkmnChangedType: @ 0x085A9AD4
	.string "{STRING 0x0F}は\n{STRING 0x00}タイプに　なった！$"

sText_PkmnFlinched: @ 0x085A9AE4
	.string "{STRING 0x0F}は　ひるんで\nうごけなかった！$"

sText_PkmnRegainedHealth: @ 0x085A9AF6
	.string "{STRING 0x10}は　たいりょくを\nかいふくした！$"

sText_PkmnHPFull: @ 0x085A9B09
	.string "しかし　{STRING 0x10}の\nたいりょくは　まんたんだ！$"

sText_PkmnRaisedSpDef: @ 0x085A9B1F
	.string "{STRING 0x2A}　{STRING 0x14}で\nとくこうに　つよくなった！$"

sText_PkmnRaisedSpDefALittle: @ 0x085A9B34
	.string "{STRING 0x2A}　{STRING 0x14}で\nとくこうに　すこし　つよくなった！$"

sText_PkmnRaisedDef: @ 0x085A9B4D
	.string "{STRING 0x2A}　{STRING 0x14}で\nだげきこうげきに　つよくなった！$"

sText_PkmnRaisedDefALittle: @ 0x085A9B65
	.string "{STRING 0x2A}　{STRING 0x14}で\nだげきこうげきに　すこし　つよくなった！$"

sText_PkmnCoveredByVeil: @ 0x085A9B81
	.string "{STRING 0x2A}\nしんぴのベールに　つつまれた！$"

sText_PkmnUsedSafeguard: @ 0x085A9B94
	.string "{STRING 0x10}は\nしんぴのベールに　まもられている！$"

sText_PkmnSafeguardExpired: @ 0x085A9BAA
	.string "{STRING 0x2C}　つつんでいた\nしんぴの　ベールが　なくなった！$"

sText_PkmnWentToSleep: @ 0x085A9BC5
	.string "{STRING 0x0F}は\nねむりはじめた！$"

sText_PkmnSleptHealthy: @ 0x085A9BD2
	.string "{STRING 0x0F}は\nけんこうになって　ねむりはじめた！$"

sText_PkmnWhippedWhirlwind: @ 0x085A9BE8
	.string "{STRING 0x0F}の　まわりで\nくうきが　うずを　まく！$"

sText_PkmnTookSunlight: @ 0x085A9BFE
	.string "{STRING 0x0F}は\nひかりを　きゅうしゅうした！$"

sText_PkmnLoweredHead: @ 0x085A9C11
	.string "{STRING 0x0F}は\nくびを　ひっこめた！$"

sText_PkmnIsGlowing: @ 0x085A9C20
	.string "{STRING 0x0F}を\nはげしい　ひかりが　つつむ！$"

sText_PkmnFlewHigh: @ 0x085A9C33
	.string "{STRING 0x0F}は\nそらたかく　とびあがった！$"

sText_PkmnDugHole: @ 0x085A9C45
	.string "{STRING 0x0F}は\nあなをほって　ちちゅうに　もぐった！$"

sText_PkmnHidUnderwater: @ 0x085A9C5C
	.string "{STRING 0x0F}は\nすいちゅうに　みをひそめた！$"

sText_PkmnSprangUp: @ 0x085A9C6F
	.string "{STRING 0x0F}は\nとびはねた！$"

sText_PkmnSqueezedByBind: @ 0x085A9C7A
	.string "{STRING 0x10}は　{STRING 0x0F}に\nしめつけられた！$"

sText_PkmnTrappedInVortex: @ 0x085A9C8B
	.string "{STRING 0x10}は　うずの　なかに\nとじこめられた！$"

sText_PkmnTrappedBySandTomb: @ 0x085A9CA0
	.string "{STRING 0x10}は　すなじごくに\nとらわれた！$"

sText_PkmnWrappedBy: @ 0x085A9CB2
	.string "{STRING 0x10}は　{STRING 0x0F}に\nまきつかれた！$"

sText_PkmnClamped: @ 0x085A9CC2
	.string "{STRING 0x10}は　{STRING 0x0F}の\nからに　はさまれた！$"

sText_PkmnHurtBy: @ 0x085A9CD5
	.string "{STRING 0x0F}は　{STRING 0x00}の\nダメージを　うけている$"

sText_PkmnFreedFrom: @ 0x085A9CE9
	.string "{STRING 0x0F}は\n{STRING 0x00}から　かいほうされた！$"

sText_PkmnCrashed: @ 0x085A9CFB
	.string "いきおい　あまって\n{STRING 0x0F}は　じめんに　ぶつかった！$"
