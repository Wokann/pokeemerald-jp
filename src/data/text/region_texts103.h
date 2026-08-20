const u8 gText_Give[] = _("もたせるべき");
const u8 gText_NoNeed[] = _("もたせない");
const u8 gText_ColorLightShadowDarkGray[] = _("{COLOR 3}{SHADOW 2}");
const u8 gText_ColorBlue[] = _("{COLOR 8}");

// The final 0xFF is the COLOR parameter and also the StringCopy terminator.
// __() is required here so that charmap_jp does not append a second EOS.
const u8 gText_ColorTransparent[] = __("{HIGHLIGHT 0}{COLOR 255}");

__asm__(".global gUnknown_85CC47F\n"
        ".set gUnknown_85CC47F, gText_Give\n"
        ".global gUnknown_85CC486\n"
        ".set gUnknown_85CC486, gText_NoNeed\n"
        ".global gUnknown_85CC48C\n"
        ".set gUnknown_85CC48C, gText_ColorLightShadowDarkGray\n"
        ".global gUnknown_85CC493\n"
        ".set gUnknown_85CC493, gText_ColorBlue\n"
        ".global gUnknown_85CC497\n"
        ".set gUnknown_85CC497, gText_ColorTransparent");
