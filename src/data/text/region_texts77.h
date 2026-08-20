const u8 gUnknown_85C9359[] = _("なまえ");

const u8 gUnknown_85C935D[] = _("IDNo,");

const u8 gText_BirchInTrouble[] = _(
    "オダマキはかせが　ピンチだ！\n"
    "ポケモンを　だして　たすけてあげよう！");

const u8 gText_ConfirmStarterChoice[] = _("このポケモンにしますか？");

const u8 gStarterCategorySuffix[] = _("ポケモン");

const u8 gUnknown_85C9398[] = _("どこへ　とびますか？$つかう$すてる$とうろく$もたせる$タグをみる");

// Script Menu aliases share the exact JP menu-text storage above.
__asm__(".global gMenuText_Register\n"
        ".set gMenuText_Register, gUnknown_85C9398 + 0x13");
__asm__(".global gText_Cancel2\n"
        ".set gText_Cancel2, gUnknown_85C9398 + 0x30");
