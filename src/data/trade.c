#include "global.h"

// Keep the large JP resource block out of src/trade.c: agbcc cannot compile
// that already-large translation unit once these INCBIN initializers are added.
#include "trade.h"

// These labels were assembler aliases in data_b2d_mid51.s and
// data_b2d_mid49.s.  Preserve them for the existing typed declarations in
// src/trade.c while the raw resource bytes live in this data module.
__asm__(
    ".global sSpriteTemplate_Cursor\n"
    ".set sSpriteTemplate_Cursor, gUnknown_830088C\n"
    ".global sSpriteTemplate_MenuText\n"
    ".set sSpriteTemplate_MenuText, gUnknown_83008A4\n"
    ".global sCursorMoveDestinations\n"
    ".set sCursorMoveDestinations, gUnknown_83008E4\n"
    ".global sTradeMonSpriteCoords\n"
    ".set sTradeMonSpriteCoords, gUnknown_8300A1C\n"
    ".global sActionTexts\n"
    ".set sActionTexts, gUnknown_8300AFC\n"
    ".global sSelectTradeMonActions\n"
    ".set sSelectTradeMonActions, gUnknown_8300B28\n"
    ".global sTradeYesNoWindowTemplate\n"
    ".set sTradeYesNoWindowTemplate, gUnknown_8300CAC\n"
);
