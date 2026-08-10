#!/bin/bash
cd /home/kenny/pokeemerald-jp
for f in asm/*.s; do
  b=$(basename "$f" .s)
  if [ -f ../pokeemerald/src/"$b".c ]; then
    n=$(wc -l < "$f")
    echo "$b $n"
  fi
done | sort -k2 -n
