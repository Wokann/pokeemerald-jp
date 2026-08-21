const u8 gText_TeachWhichMoveToPkmn[] = _("{STR_VAR_1}に　どのわざを　おぼえさせる？");

const u8 gText_MoveRelearnerTeachMoveConfirm[] = _("{STR_VAR_2}を　おぼえさせますか？");

const u8 gText_MoveRelearnerPkmnLearnedMove[] = _(
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえた！");

const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] = _(
    "{STR_VAR_1}は　あたらしく　\n"
    "{STR_VAR_2}を　おぼえたい⋯！\p"
    "しかし　{STR_VAR_1}は　わざを　4つ\n"
    "おぼえているので　せいいっぱいだ！\p"
    "{STR_VAR_2}の　かわりに　ほかの　わざを\n"
    "わすれさせますか？");

const u8 gText_MoveRelearnerStopTryingToTeachMove[] = _(
    "それでは⋯⋯　{STR_VAR_2}を\n"
    "おぼえるのを　あきらめますか？");

const u8 gText_MoveRelearnerAndPoof[] = _("{PAUSE}み1　{PAUSE}そ2の　{PAUSE}そ⋯{PAUSE}そ⋯{PAUSE}そ⋯　{PAUSE}そ{PLAY_SE}ぎ　ポカン！\p");

const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] = _(
    "{STR_VAR_1}は　{STR_VAR_3}の　つかいかたを\n"
    "きれいに　わすれた！\p"
    "そして⋯！\p"
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえた！");

const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew_sub1[] = _("{STR_VAR_1}は　{STR_VAR_2}を　おぼえずに　おわった！");

// This JP-only physical tail ends with OAM-shaped fixed padding.  The second
// string has its real EOS before that padding, so it must not get an extra
// automatic terminator.
#define REGION_TEXTS71_MOVE_RELEARNER_TAIL __attribute__((section(".rodata.region_texts71_move_relearner_tail")))

const u8 gText_MoveRelearnerGiveUp[] REGION_TEXTS71_MOVE_RELEARNER_TAIL = _(
    "{B_COPY_VAR_1}に　わざを　おぼえさせるのを\n"
    "あきらめますか？");

const u8 gText_MoveRelearnerWhichMoveToForget[] REGION_TEXTS71_MOVE_RELEARNER_TAIL = __(
    "どの　わざを\n"
    "わすれさせたい？\p"
    "$　　　　　　　　　　　ィ　　　　　　　ぞ　　　　　　");
