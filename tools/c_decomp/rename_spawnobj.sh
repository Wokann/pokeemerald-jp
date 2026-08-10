#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'TrySpawnEventObject' asm/*.s)
for f in $files; do
  sed -i 's/TrySpawnEventObject/TrySpawnObjectEvent/g' "$f"
  echo "updated $f"
done
