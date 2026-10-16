#include "global.h"

#define TEXT_INPUT_EASY_CHAT __attribute__((section(".rodata.text_input_easy_chat"), aligned(1)))
#define TEXT_INPUT_NAMING_SCREEN __attribute__((section(".rodata.text_input_naming_screen"), aligned(1)))

// Easy Chat keyboard
TEXT_INPUT_EASY_CHAT const u8 gText_EasyChatKeyboard_Hiragana1[] = _("あいうえお　なにぬねの　やゆよ　わ");
TEXT_INPUT_EASY_CHAT const u8 gText_EasyChatKeyboard_Hiragana2[] = _("かきくけこ　はひふへほ　そのた");
TEXT_INPUT_EASY_CHAT const u8 gText_EasyChatKeyboard_Hiragana3[] = _("さしすせそ　まみむめも");
TEXT_INPUT_EASY_CHAT const u8 gText_EasyChatKeyboard_Hiragana4[] = _("たちつてと　らりるれろ");

// Naming Screen keyboard. JP second rows retain the native EOS/newline/space/EOS suffix.
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Katakana1[20] = _("アイウエオ　ナニヌネノ　ヤユヨ！？　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Katakana2[20] = __(
    "カキクケコ　ハヒフヘホ　ワヲン　$\n"
    "　$");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Katakana3[20] = _("サシスセソ　マミムメモ　ャュョッー　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Katakana4[20] = _("タチツテト　ラリルレロ　ァィゥェォ　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Hiragana1[20] = _("あいうえお　なにぬねの　やゆよ！？　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Hiragana2[20] = __(
    "かきくけこ　はひふへほ　わをん　$\n"
    "　$");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Hiragana3[20] = _("さしすせそ　まみむめも　ゃゅょっー　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_Hiragana4[20] = _("たちつてと　らりるれろ　ぁぃぅぇぉ　　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_LatinUpper1[20] = _("ABCDEFGHIJKLMNOPQRS");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_LatinUpper2[20] = _("TUVWXYZ　0123456789　");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_LatinLower1[20] = _("abcdefghijklmnopqrs");
TEXT_INPUT_NAMING_SCREEN const u8 gText_NamingScreenKeyboard_LatinLower2[20] = _("tuvwxyz　.·…“”‘’/♂♀　");

// Union Room Chat keyboard
const u8 gText_UnionRoomChatKeyboard_Hiragana1[] = _("あいうえお");
const u8 gText_UnionRoomChatKeyboard_Hiragana2[] = _("かきくけこ");
const u8 gText_UnionRoomChatKeyboard_Hiragana3[] = _("さしすせそ");
const u8 gText_UnionRoomChatKeyboard_Hiragana4[] = _("たちつてと");
const u8 gText_UnionRoomChatKeyboard_Hiragana5[] = _("なにぬねの");
const u8 gText_UnionRoomChatKeyboard_Hiragana6[] = _("はひふへほ");
const u8 gText_UnionRoomChatKeyboard_Hiragana7[] = _("まみむめも");
const u8 gText_UnionRoomChatKeyboard_Hiragana8[] = _("やゆよ！？");
const u8 gText_UnionRoomChatKeyboard_Hiragana9[] = _("らりるれろ");
const u8 gText_UnionRoomChatKeyboard_Hiragana10[] = _("わをんー　");
const u8 gText_UnionRoomChatKeyboard_Katakana1[] = _("アイウエオ");
const u8 gText_UnionRoomChatKeyboard_Katakana2[] = _("カキクケコ");
const u8 gText_UnionRoomChatKeyboard_Katakana3[] = _("サシスセソ");
const u8 gText_UnionRoomChatKeyboard_Katakana4[] = _("タチツテト");
const u8 gText_UnionRoomChatKeyboard_Katakana5[] = _("ナニヌネノ");
const u8 gText_UnionRoomChatKeyboard_Katakana6[] = _("ハヒフヘホ");
const u8 gText_UnionRoomChatKeyboard_Katakana7[] = _("マミムメモ");
const u8 gText_UnionRoomChatKeyboard_Katakana8[] = _("ヤユヨ！？");
const u8 gText_UnionRoomChatKeyboard_Katakana9[] = _("ラリルレロ");
const u8 gText_UnionRoomChatKeyboard_Katakana10[] = _("ワヲンー　");
const u8 gText_UnionRoomChatKeyboard_ABCDE[] = _("ABCDE");
const u8 gText_UnionRoomChatKeyboard_FGHIJ[] = _("FGHIJ");
const u8 gText_UnionRoomChatKeyboard_KLMNO[] = _("KLMNO");
const u8 gText_UnionRoomChatKeyboard_PQRST[] = _("PQRST");
const u8 gText_UnionRoomChatKeyboard_UVWXY[] = _("UVWXY");
const u8 gText_UnionRoomChatKeyboard_Z[] = _("Z·⋯　　");
const u8 gText_UnionRoomChatKeyboard_01234Upper[] = _("01234");
const u8 gText_UnionRoomChatKeyboard_56789Upper[] = _("56789");

// Union Room Chat keyboard emojis
const u8 gText_UnionRoomChatKeyboard_Emoji1[] = _("{EMOJI_MISCHIEVOUS}{EMOJI_HAPPY}{EMOJI_ANGRY}{EMOJI_SURPRISED}{EMOJI_BIGANGER}");
const u8 gText_UnionRoomChatKeyboard_Emoji2[] = _("{EMOJI_BIGSMILE}{EMOJI_EVIL}{EMOJI_NEUTRAL}{EMOJI_TIRED}{EMOJI_SHOCKED}");
const u8 gText_UnionRoomChatKeyboard_Emoji3[] = _("{EMOJI_LEAF}{EMOJI_FIRE}{EMOJI_WATER}{EMOJI_BOLT}{EMOJI_BALL}");
const u8 gText_UnionRoomChatKeyboard_Emoji4[] = _("♂♀{EMOJI_LEFT_PAREN}{EMOJI_RIGHT_PAREN}{EMOJI_TILDE}");
const u8 gText_UnionRoomChatKeyboard_Emoji5[] = _("{EMOJI_LEFT_EYE}{EMOJI_RIGHT_EYE}{EMOJI_SMALLWHEEL}{EMOJI_SPHERE}{EMOJI_IRRITATED}");
const u8 gText_UnionRoomChatKeyboard_Emoji6[] = _("{EMOJI_SPIRAL}{EMOJI_BIGWHEEL}{EMOJI_TONGUE}{EMOJI_ACUTE}{EMOJI_GRAVE}");
const u8 gText_UnionRoomChatKeyboard_Emoji7[] = _("{EMOJI_RIGHT_FIST}{EMOJI_LEFT_FIST}{EMOJI_TRIANGLE_OUTLINE}{EMOJI_UNION}{EMOJI_GREATER_THAN}");
const u8 gText_UnionRoomChatKeyboard_Emoji8[] = _("{EMOJI_CIRCLE}{EMOJI_TRIANGLE}{EMOJI_SQUARE}{EMOJI_HEART}{EMOJI_MOON}");
const u8 gText_UnionRoomChatKeyboard_Emoji9[] = _("{EMOJI_NOTE}{EMOJI_PLUS}{EMOJI_MINUS}{EMOJI_EQUALS}{EMOJI_PIPE}");
const u8 gText_UnionRoomChatKeyboard_Emoji10[] = _("{EMOJI_HIGHBAR}{UNDERSCORE}{EMOJI_SEMICOLON}:　");
