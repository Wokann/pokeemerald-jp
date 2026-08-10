#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'RemoveEventObjectByLocalIdAndMap' asm/*.s)
for f in $files; do
  sed -i 's/RemoveEventObjectByLocalIdAndMap/RemoveObjectEventByLocalIdAndMap/g' "$f"
  echo "updated $f"
done
