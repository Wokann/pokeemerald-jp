#!/bin/bash
cd /home/kenny/pokeemerald-jp
mkdir -p /tmp/cbuild
for f in src/*.c; do
    base=$(basename "$f" .c)
    err=$(cpp -P -nostdinc -undef -iquote include \
        -I ../pokeemerald/tools/agbcc/include -I ../pokeemerald/tools/agbcc \
        -Wno-trigraphs -std=gnu89 -x c "$f" \
        | ../pokeemerald/tools/agbcc/bin/agbcc -mthumb-interwork -O2 \
          -ffunction-sections -fhex-asm -o /tmp/cbuild/$base.s - 2>&1 \
        | grep -v "warning:" | head -6)
    if [ -n "$err" ]; then
        echo "===== $base ====="
        echo "$err"
    fi
done
