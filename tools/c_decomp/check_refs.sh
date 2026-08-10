#!/bin/bash
cd /home/kenny/pokeemerald-jp
for f in DecompressGlyph_Small DecompressGlyph_Normal DecompressGlyph_Short DecompressGlyph_Narrow DecompressGlyph_SmallNarrow DecompressGlyph_Bold GetGlyphWidth_Small GetGlyphWidth_Normal GetGlyphWidth_Short GetGlyphWidth_Narrow GetGlyphWidth_SmallNarrow FillGlyphBufferWithColor FontFunc_Narrow FontFunc_SmallNarrow; do
  n=$(grep -c "\\b${f}\\b" src/text.c)
  echo "${f}: ${n} refs"
done
