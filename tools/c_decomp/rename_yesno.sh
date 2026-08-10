#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'sub_08198C08' asm/*.s)
for f in $files; do
  sed -i 's/sub_08198C08/CreateYesNoMenuAtPos/g' "$f"
  echo "updated $f"
done
