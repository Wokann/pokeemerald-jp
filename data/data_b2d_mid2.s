.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"


	.globl gUnknown_82F3E80
gUnknown_82F3E80: @ 0x82F3E80
	.incbin "baserom_jp.gba", 0x2f3e80, 0x14
	.globl gUnknown_82F3E94
gUnknown_82F3E94: @ 0x82F3E94
	.incbin "baserom_jp.gba", 0x2f3e94, 0x16
	.globl gUnknown_82F3EAA
gUnknown_82F3EAA: @ 0x82F3EAA
	.string "コうこいらこぇとスみヌんäずボっぎト$$"
	.globl gUnknown_82F3EBE
gUnknown_82F3EBE: @ 0x82F3EBE
	.string "コうこいらいぇいらこぇとスみヌんäずボクぎヤ$$"
	.globl gUnknown_82F3ED6
gUnknown_82F3ED6: @ 0x82F3ED6
	.string "こいろいづついほボれヤょどぢzぺヌコゆニ$$"
	.globl gUnknown_82F3EEC
gUnknown_82F3EEC: @ 0x82F3EEC
	.string "こいろいづいテいづついほボれヤょテぎどぶzコヌフゆン$$"
	.globl gUnknown_82F3F08
gUnknown_82F3F08: @ 0x82F3F08
	.string "わいんいゃせろはざらやぇ？ずせぱチカゅツ$$"
	.globl gUnknown_82F3F1E
gUnknown_82F3F1E: @ 0x82F3F1E
	.string "わいんいゃいざうöツ$$"
	.globl gUnknown_82F3F2A
gUnknown_82F3F2A: @ 0x82F3F2A
	.string "ダいソせがはうよ:ぇめずAぼぎカ$$"
	.globl gUnknown_82F3F3C
gUnknown_82F3F3C: @ 0x82F3F3C
	.string "ダいソいがいソせがはうよ:ょめばAカぎニ$$"
	.globl gUnknown_82F3F52
gUnknown_82F3F52: @ 0x82F3F52
	.string "がいソいういぢいぢば9ニ$$"
	.globl gUnknown_82F3F60
gUnknown_82F3F60: @ 0x82F3F60
	.string "トい$$"
	.globl gUnknown_82F3F64
gUnknown_82F3F64: @ 0x82F3F64
	.incbin "baserom_jp.gba", 0x2f3f64, 0x1a
	.globl gUnknown_82F3F7E
gUnknown_82F3F7E: @ 0x82F3F7E
	.incbin "baserom_jp.gba", 0x2f3f7e, 0x1a
	.globl gUnknown_82F3F98
gUnknown_82F3F98: @ 0x82F3F98
	.string "づいろいヤせいはどよGわぬぉuずぢぼzっ,カkツ$$"
	.globl gUnknown_82F3FB2
gUnknown_82F3FB2: @ 0x82F3FB2
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FCE
gUnknown_82F3FCE: @ 0x82F3FCE
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FEA
gUnknown_82F3FEA: @ 0x82F3FEA
	.string "にいぼしもにぽほぷめぺよぉんrざぱぼなコ$$"
	.globl gUnknown_82F4000
gUnknown_82F4000: @ 0x82F4000
	.string "にいぼいもいぼしもにぽほぷめぺよぉぃrぢぱエなフ$$"
	.globl gUnknown_82F401A
gUnknown_82F401A: @ 0x82F401A
	.string "にいぽいrいぱい$$"
	.globl gUnknown_82F4024
gUnknown_82F4024: @ 0x82F4024
	.string "りいぃしャねぉよじぇもざミぶヌカぎツ$$"
	.globl gUnknown_82F4038
gUnknown_82F4038: @ 0x82F4038
	.string "りいぃいャいぃしャねぉよじぇもざミぴヌセぎホ$$"
	.globl gUnknown_82F4050
gUnknown_82F4050: @ 0x82F4050
	.string "むいマいわすクにjみリれSゃセぜケぶベイよシ$$"
	.globl gUnknown_82F4068
gUnknown_82F4068: @ 0x82F4068
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F4084
gUnknown_82F4084: @ 0x82F4084
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F40A0
gUnknown_82F40A0: @ 0x82F40A0
	.string "むいをこらつゃふぬよウぇやずチぴエサンハ$$"
	.globl gUnknown_82F40B6
gUnknown_82F40B6: @ 0x82F40B6
	.string "むいをいらいゃいをこらつゃふぬよウぇやずチぴまっエナンン$$"
	.globl gUnknown_82F40D4
gUnknown_82F40D4: @ 0x82F40D4
	.string "ーいのうむいをしがほスりぇげへでュカセタ$$"
	.globl gUnknown_82F40EA
gUnknown_82F40EA: @ 0x82F40EA
	.string "ーいのうむいをいをしがほスりぇげへでホぼュシセフ$$"
	.globl gUnknown_82F4104
gUnknown_82F4104: @ 0x82F4104
	.string "ぜうむいエしぃにぅみカれWゃMぞゥぴヌクFト$$"
	.globl gUnknown_82F411C
gUnknown_82F411C: @ 0x82F411C
	.string "ぜうむいエいぃいエしぃにぅみカれWゃMば0クヌハFワ$$"
	.globl gUnknown_82F4138
gUnknown_82F4138: @ 0x82F4138
	.string "ぞいふしろにまみはろXゃせずチぶ2イTシ$$"
	.globl gUnknown_82F414E
gUnknown_82F414E: @ 0x82F414E
	.incbin "baserom_jp.gba", 0x2f414e, 0x14
	.globl gUnknown_82F4162
gUnknown_82F4162: @ 0x82F4162
	.incbin "baserom_jp.gba", 0x2f4162, 0x18
	.globl gUnknown_82F417A
gUnknown_82F417A: @ 0x82F417A
	.string "へいをつJめずれピげやぼげイgツ$$"
	.globl gUnknown_82F418C
gUnknown_82F418C: @ 0x82F418C
	.string "へいをいJいずいをつJめずれピげべどやエげニgィ$$"
	.globl gUnknown_82F41A6
gUnknown_82F41A6: @ 0x82F41A6
	.string "ゴいあいハくぇたワはヒよヌゃビでBカかヒ$$"
	.globl gUnknown_82F41BC
gUnknown_82F41BC: @ 0x82F41BC
	.string "ゴいあいハいハくぇたワはヒよヌゃビでBセかロ$$"
	.globl gUnknown_82F41D4
gUnknown_82F41D4: @ 0x82F41D4
	.string "むいホいぃつずめ♀ぇろぢィイげツ$$"
	.globl gUnknown_82F41E6
gUnknown_82F41E6: @ 0x82F41E6
	.string "ホいぃいずい♀いEぢォイ$$"
	.globl gUnknown_82F41F4
gUnknown_82F41F4: @ 0x82F41F4
	.string "ソいレい'たZはーみナれヘぎゲぢHぶ$$"
	.globl gUnknown_82F4208
gUnknown_82F4208: @ 0x82F4208
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4220
gUnknown_82F4220: @ 0x82F4220
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4238
gUnknown_82F4238: @ 0x82F4238
	.string "むいヌいとつクはハれテぇOぢなぼsコぶテよメ$$"
	.globl gUnknown_82F4250
gUnknown_82F4250: @ 0x82F4250
	.incbin "baserom_jp.gba", 0x2f4250, 0x16
	.globl gUnknown_82F4266
gUnknown_82F4266: @ 0x82F4266
	.incbin "baserom_jp.gba", 0x2f4266, 0x1a
	.globl gUnknown_82F4280
gUnknown_82F4280: @ 0x82F4280
	.string "ダいろこさねハみオぁぬょしで♀イブコ$$"
	.globl gUnknown_82F4294
gUnknown_82F4294: @ 0x82F4294
	.string "ダいろいさいろこさねハみオぁぬょしぴ♀ツブメ$$"
	.globl gUnknown_82F42AC
gUnknown_82F42AC: @ 0x82F42AC
	.string "しうむいヌたぅほWれリょSぞムぼゥエベシÜツ$$"
	.globl gUnknown_82F42C4
gUnknown_82F42C4: @ 0x82F42C4
	.string "しうむいヌいぅいヌたぅほWれリょSでムイゥタベフÜヨ$$"
	.globl gUnknown_82F42E0
gUnknown_82F42E0: @ 0x82F42E0
	.string "ザい{B_COPY_VAR_1}ソいモせべはスよぺぇぷずぽぼぴカ$$"
	.globl gUnknown_82F42F6
gUnknown_82F42F6: @ 0x82F42F6
	.string "ザいソいスいぬよルず$$"
	.globl gUnknown_82F4302
gUnknown_82F4302: @ 0x82F4302
	.string "をいらこヲつへはろめヤれパぇテげTぢゆぼLイよコ$$"
	.globl gUnknown_82F431C
gUnknown_82F431C: @ 0x82F431C
	.string "をいらいヲいへいらこヲつへはろめヤれパぇテぞTぺゆシLハよレ$$"
	.globl gUnknown_82F433C
gUnknown_82F433C: @ 0x82F433C
	.string "ぬうねいタしひにはみねるヤれギゃ9ずGぶQイのシ‘ニ$$"
	.globl gUnknown_82F4358
gUnknown_82F4358: @ 0x82F4358
	.string "ぬうえいチせpは¥りけゃくゃきゃびだおぴKクでト$$"
	.globl gUnknown_82F4372
gUnknown_82F4372: @ 0x82F4372
	.string "レいぃせマねはゆぬんもげぇでなっヌコまヌ$$"
	.globl gUnknown_82F4388
gUnknown_82F4388: @ 0x82F4388
	.string "ゴいむいロつリめワれフぇメぢベイHコかテ$$"
	.globl gUnknown_82F439E
gUnknown_82F439E: @ 0x82F439E
	.string "ゴいむいロいリいロつリめワれフぇメぢベクHニかユ$$"
	.globl gUnknown_82F43B8
gUnknown_82F43B8: @ 0x82F43B8
	.string "ほいらいぬとまほ,ぃセごみぴやカケネlメ$$"
	.globl gUnknown_82F43CE
gUnknown_82F43CE: @ 0x82F43CE
	.string "ほいらいぬいまいぬとまほ,ぃセごみぴやシケヤlャ$$"
	.globl gUnknown_82F43E8
gUnknown_82F43E8: @ 0x82F43E8
	.string "あいをいらこまてガはうめヒんぁげルばマイムツよメ$$"
	.globl gUnknown_82F4402
gUnknown_82F4402: @ 0x82F4402
	.string "てうャいぽくびとぼはぷよにわとぎぶずぺぼなっだス$$"
	.globl gUnknown_82F441C
gUnknown_82F441C: @ 0x82F441C
	.incbin "baserom_jp.gba", 0x2f441c, 0x16
	.globl gUnknown_82F4432
gUnknown_82F4432: @ 0x82F4432
	.string "ダいフたろほがわ▶げチぶぎカスナ$$"
	.globl gUnknown_82F4444
gUnknown_82F4444: @ 0x82F4444
	.string "ダいフいろいがいフたろほがわ▶げチっぎニスヲ$$"
	.globl gUnknown_82F445C
gUnknown_82F445C: @ 0x82F445C
	.string "ぞいらいコうぃとほほ·ぃまげァぴみカチネ$$"
	.globl gUnknown_82F4472
gUnknown_82F4472: @ 0x82F4472
	.string "ぞいらいコうぃいぃとほほ·ぃまげァイみツチレ$$"
	.globl gUnknown_82F448A
gUnknown_82F448A: @ 0x82F448A
	.string "むいハいがしqとノほゆらゥぃじぎヒぢムぼぢオぎシ$$"
	.globl gUnknown_82F44A4
gUnknown_82F44A4: @ 0x82F44A4
	.string "がいqいノいゥいヘぢ$$"
	.globl gUnknown_82F44B0
gUnknown_82F44B0: @ 0x82F44B0
	.string "ミいスこ3つタはうめムれモれoぇざげにづそぱたウセコnツgハ$$"
	.globl gUnknown_82F44D0
gUnknown_82F44D0: @ 0x82F44D0
	.string "ツいろいヤしpにTみチれちゃ2ずせぶネイXシ$$"
	.globl gUnknown_82F44E8
gUnknown_82F44E8: @ 0x82F44E8
	.string "あいレいズい♂いズつ♂はうれくぇZばぐウめニIメごョ$$"
	.globl gUnknown_82F4504
gUnknown_82F4504: @ 0x82F4504
	.string "ツいろいけいけつムめゥぇヌぶオセキヤ$$"
	.globl gUnknown_82F4518
gUnknown_82F4518: @ 0x82F4518
	.string "ゃいろいロいきいろせロはきよフぇÄぢゅイヘツンメ$$"
	.globl gUnknown_82F4532
gUnknown_82F4532: @ 0x82F4532
	.string "さいヤいとせどはハよぬぉねぜしぼぢカせツ$$"
	.globl gUnknown_82F4548
gUnknown_82F4548: @ 0x82F4548
	.string "むいらくテたほは,よpゃピでゆカやハ$$"
	.globl gUnknown_82F455C
gUnknown_82F455C: @ 0x82F455C
	.string "バいむほ·ざ$$"
	.globl gUnknown_82F4564
gUnknown_82F4564: @ 0x82F4564
	.string "ゆいわりイぇろざ▶ばぎっ:コスナぜホ$$"
	.globl gUnknown_82F4578
gUnknown_82F4578: @ 0x82F4578
	.string "がいをいぁいょせめはヘよIぇげず:ぼgカぎツべマ$$"
	.globl gUnknown_82F4592
gUnknown_82F4592: @ 0x82F4592
	.string "ゾい$$"
	.globl gUnknown_82F4596
gUnknown_82F4596: @ 0x82F4596
	.string "むいらいせうふたをみツんわざnぶやエ$$"
	.globl gUnknown_82F45AA
gUnknown_82F45AA: @ 0x82F45AA
	.string "むいらいせうふたがみツんわざずぶメエビセぎネ$$"
	.globl gUnknown_82F45C2
gUnknown_82F45C2: @ 0x82F45C2
	.string "むいらいせうふたエみツんねざれぶカエチセキネ$$"
	.globl gUnknown_82F45DA
gUnknown_82F45DA: @ 0x82F45DA
	.string "むいらいせうふたゃみツんわざウぶロエろセゅネ$$"
	.globl gUnknown_82F45F2
gUnknown_82F45F2: @ 0x82F45F2
	.string "⋯いむいッいチつざねノりポぃMぞ0ぶにケFタ$$"
	.globl gUnknown_82F460A
gUnknown_82F460A: @ 0x82F460A
	.string "ャいホいわはがよオぉろず♀ぼだキüツぎホ$$"
	.globl gUnknown_82F4620
gUnknown_82F4620: @ 0x82F4620
	.string "ャいホいわいわはがよオぉろず♀ぼォっだスüホぎェ$$"
	.globl gUnknown_82F463A
gUnknown_82F463A: @ 0x82F463A
	.string "こいハいびはろよオぉふずQぼぜキぶツüホ$$"
	.globl gUnknown_82F4650
gUnknown_82F4650: @ 0x82F4650
	.string "こいハいびいびはろよオぉふずQぼ2っぜスぶホüェ$$"
	.globl gUnknown_82F466A
gUnknown_82F466A: @ 0x82F466A
	.string "ちいチたわほぃわüげ,ぶやカぜト$$"
	.globl gUnknown_82F467C
gUnknown_82F467C: @ 0x82F467C
	.string "むいュしマとAほへよのぅピぎ。ぎめぢぽぱキオSシぜニ$$"
	.globl gUnknown_82F4698
gUnknown_82F4698: @ 0x82F4698
	.string "たい♂いょはチぇ9ぼげツモレごヂべ！$$"
	.globl gUnknown_82F46AC
gUnknown_82F46AC: @ 0x82F46AC
	.string "ぞいエいカはチぇKぼだツしロムヂキ9$$"
	.globl gUnknown_82F46C0
gUnknown_82F46C0: @ 0x82F46C0
	.string "ちいゃいウはチぇQぼゅツgレあヅゼ9$$"
	.globl gUnknown_82F46D4
gUnknown_82F46D4: @ 0x82F46D4
	.string "もいろいカた▶ほイわなげチぶgカNトぜメ$$"
	.globl gUnknown_82F46EA
gUnknown_82F46EA: @ 0x82F46EA
	.string "もいろいカい▶いカた▶ほイわなげチぴgセNミぜェ$$"
	.globl gUnknown_82F4704
gUnknown_82F4704: @ 0x82F4704
	.string "もいろいカい▶いカた▶ほイわなげチぴgセちホNレぜバ$$"
	.globl gUnknown_82F4720
gUnknown_82F4720: @ 0x82F4720
	.incbin "baserom_jp.gba", 0x2f4720, 0x18
	.globl gUnknown_82F4738
gUnknown_82F4738: @ 0x82F4738
	.string "あいゾとおりヨざセっüト$$"
	.globl gUnknown_82F4746
gUnknown_82F4746: @ 0x82F4746
	.string "むいをいぱたモねぷほwわめげムぶgカぴト$$"
	.globl gUnknown_82F475C
gUnknown_82F475C: @ 0x82F475C
	.string "むいをいぱいモいぱたモねぷほwんめずムぺgセぴホ$$"
	.globl gUnknown_82F4776
gUnknown_82F4776: @ 0x82F4776
	.string "むいをいぱいモいぱたモねぷほwんめずムイgニぴレ$$"
	.globl gUnknown_82F4790
gUnknown_82F4790: @ 0x82F4790
	.string "むいろいフしゃねツよ？ょゥぶゅシ$$"
	.globl gUnknown_82F47A2
gUnknown_82F47A2: @ 0x82F47A2
	.string "むいろいフいフしゃねツれ？ずゥエゅフ$$"
	.globl gUnknown_82F47B6
gUnknown_82F47B6: @ 0x82F47B6
	.string "むいろいフいゃいフしゃねツれ？ずゥコゅリ$$"
	.globl gUnknown_82F47CC
gUnknown_82F47CC: @ 0x82F47CC
	.string "こいろいテせがはわり,ょ2ばヌカぎネ$$"
	.globl gUnknown_82F47E0
gUnknown_82F47E0: @ 0x82F47E0
	.string "こいろいテいテせがはわれ,ぎ2ぼヌコぎホ$$"
	.globl gUnknown_82F47F6
gUnknown_82F47F6: @ 0x82F47F6
	.string "こいろいテいがいテせがはわれ,ぎ2ぴヌセぎヤ$$"
	.globl gUnknown_82F480E
gUnknown_82F480E: @ 0x82F480E
	.string "こいマくツせボねせもなぃこぜピっュツ$$"
	.globl gUnknown_82F4822
gUnknown_82F4822: @ 0x82F4822
	.string "こいマいツいマくツせボねせらなぎこぱピタュヨ$$"
	.globl gUnknown_82F483A
gUnknown_82F483A: @ 0x82F483A
	.string "むいをいGしぞにソみモわやぎスでゲタ$$"
	.globl gUnknown_82F484E
gUnknown_82F484E: @ 0x82F484E
	.string "むいをいGいぞいGしぞにソみモぇやぢスイゲメ$$"
	.globl gUnknown_82F4866
gUnknown_82F4866: @ 0x82F4866
	.string "むいぃたえほムわモわgわnげゥぶチカよト$$"
	.globl gUnknown_82F487C
gUnknown_82F487C: @ 0x82F487C
	.string "むいぃいぃたえほムぃモぃgぃnぢゥエチニよリ$$"
	.globl gUnknown_82F4894
gUnknown_82F4894: @ 0x82F4894
	.string "りいアい,しャにナめジんボざ8ぼチコセハ$$"
	.globl gUnknown_82F48AA
gUnknown_82F48AA: @ 0x82F48AA
	.string "りいアい,いャい,しャにナめジぇボで8カチハセン$$"
	.globl gUnknown_82F48C4
gUnknown_82F48C4: @ 0x82F48C4
	.string "ヌいジいぃいょうぃしょぬわみちれヘぎげびZエぅテメミ$$"
	.globl gUnknown_82F48E0
gUnknown_82F48E0: @ 0x82F48E0
	.string "ダいカいぃこ·はがめWぇヘげやぼぎイしテ$$"
	.globl gUnknown_82F48F6
gUnknown_82F48F6: @ 0x82F48F6
	.string "ダいカいぃいぃこ·はがめWぇヘぞやカぎトしロ$$"
	.globl gUnknown_82F490E
gUnknown_82F490E: @ 0x82F490E
	.string "エいRいらしカた/に$$"
	.globl gUnknown_82F491A
gUnknown_82F491A: @ 0x82F491A
	.string "あいRいoくぁた/は$$"
	.globl gUnknown_82F4926
gUnknown_82F4926: @ 0x82F4926
	.string "ぁいRいマくあつ/ふ$$"
	.globl gUnknown_82F4932
gUnknown_82F4932: @ 0x82F4932
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F4948
gUnknown_82F4948: @ 0x82F4948
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F495E
gUnknown_82F495E: @ 0x82F495E
	.incbin "baserom_jp.gba", 0x2f495e, 0x12
	.globl gUnknown_82F4970
gUnknown_82F4970: @ 0x82F4970
	.incbin "baserom_jp.gba", 0x2f4970, 0x12
	.globl gUnknown_82F4982
gUnknown_82F4982: @ 0x82F4982
	.string "むいをいエつカみ”んムざキぼ$$"
	.globl gUnknown_82F4992
gUnknown_82F4992: @ 0x82F4992
	.string "むいをいエいエつカや”ょムぶキコ$$"
	.globl gUnknown_82F49A4
gUnknown_82F49A4: @ 0x82F49A4
	.string "むいをいエいカいエつカや”ょけざムエキメ$$"
	.globl gUnknown_82F49BA
gUnknown_82F49BA: @ 0x82F49BA
	.string "びいrいぺいケうっクぴホ$$"
	.globl gUnknown_82F49C8
gUnknown_82F49C8: @ 0x82F49C8
	.string "むいマからしがとSほじれよぎ:ぶぎコ$$"
	.globl gUnknown_82F49DC
gUnknown_82F49DC: @ 0x82F49DC
	.string "むいマいらいがいマからしがとSほじぃよで:コぎメ$$"
	.globl gUnknown_82F49F6
gUnknown_82F49F6: @ 0x82F49F6
	.string "クいニい·つづめプぇぽづ×イなツよメ$$"
	.globl gUnknown_82F4A0A
gUnknown_82F4A0A: @ 0x82F4A0A
	.string "がいソいういIいIばUニ$$"
	.globl gUnknown_82F4A18
gUnknown_82F4A18: @ 0x82F4A18
	.string "バいwこらこむとぷはぺほぽめべり”ぇぶざ$$"
	.globl gUnknown_82F4A2E
gUnknown_82F4A2E: @ 0x82F4A2E
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”げぶぶ$$"
	.globl gUnknown_82F4A4A
gUnknown_82F4A4A: @ 0x82F4A4A
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”ぢぶク$$"
	.globl gUnknown_82F4A66
gUnknown_82F4A66: @ 0x82F4A66
	.string "こいらいふしょひnやだぉボずゥぴヌカチト$$"
	.globl gUnknown_82F4A7C
gUnknown_82F4A7C: @ 0x82F4A7C
	.string "びいぼしぶはてゆひぉÄざwぼPエ$$"
	.globl gUnknown_82F4A8E
gUnknown_82F4A8E: @ 0x82F4A8E
	.string "びいあいぼしぱはてゆぱぉÄざっぼぴエ$$"
	.globl gUnknown_82F4AA2
gUnknown_82F4AA2: @ 0x82F4AA2
	.incbin "baserom_jp.gba", 0x2f4aa2, 0x16
