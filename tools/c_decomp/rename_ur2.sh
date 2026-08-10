#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'RemoveUnionRoomPlayerEventObject\|CreateUnionRoomPlayerEventObject' asm/*.s)
for f in $files; do
  sed -i 's/RemoveUnionRoomPlayerEventObject/RemoveUnionRoomPlayerObjectEvent/g; s/CreateUnionRoomPlayerEventObject/CreateUnionRoomPlayerObjectEvent/g' "$f"
  echo "updated $f"
done
