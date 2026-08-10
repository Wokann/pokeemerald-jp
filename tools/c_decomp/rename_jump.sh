#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'ResetPokeJumpResults' asm/*.s)
for f in $files; do
  sed -i 's/ResetPokeJumpResults/ResetPokemonJumpRecords/g' "$f"
  echo "updated $f"
done
