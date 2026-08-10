#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'sub_08019370\|sub_08019388\|sub_080193D8' asm/*.s)
for f in $files; do
  sed -i 's/sub_08019370/GetUnionRoomPlayerGraphicsId/g; s/sub_08019388/GetUnionRoomPlayerCoords/g; s/sub_080193D8/IsUnionRoomPlayerAt/g' "$f"
  echo "updated $f"
done
