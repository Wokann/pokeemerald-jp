#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'decompress_and_copy_tile_data_to_vram\|free_temp_tile_data_buffers_if_possible\|reset_temp_tile_data_buffers' asm/*.s)
for f in $files; do
  sed -i 's/decompress_and_copy_tile_data_to_vram/DecompressAndCopyTileDataToVram/g; s/free_temp_tile_data_buffers_if_possible/FreeTempTileDataBuffersIfPossible/g; s/reset_temp_tile_data_buffers/ResetTempTileDataBuffers/g' "$f"
  echo "updated $f"
done
