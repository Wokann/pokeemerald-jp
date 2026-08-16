const u8 gText_QuitTheGame[] = _("ゲームを　やめますか？");

const u8 gText_YouveGot9999Coins[] = _(
    "コインが　9999まい\n"
    "たまって　います");

const u8 gText_YouveRunOutOfCoins[] = _(
    "コインが　ありません\n"
    "ゲームを　しゅうりょうします");

const u8 gText_YouDontHaveThreeCoins[] = _("コインが　3まい　ありません！");

// Reel Time help text; JP text is all single-byte kana with no control codes.
__attribute__((section(".rodata.gText_ReelTimeHelp")))
const u8 gText_ReelTimeHelp[] = __(
    "BDタイム\n"
    "じっくり　ねらえば　どんな　マークも\n"
    "とめられる　チャンスゲームだ！\n"
    "ちゅうせん　された　かいすうだけ\n"
    "BDタイムが　つづくぞ！\n"
    "ビッグボーナスがでると　しゅうりょう$　");
