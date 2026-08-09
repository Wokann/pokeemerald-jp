#!/bin/bash
cd /home/kenny/pokeemerald-jp
make clean > /dev/null 2>&1
make > /tmp/rebuild.log 2>&1
echo "make exit: $?"
grep -E "Error|error:|multiple definition|undefined reference" /tmp/rebuild.log | head -15
echo "=== sha1 ==="
sha1sum pokeemerald_jp.gba 2>/dev/null || echo "NO ROM"
cat rom_jp.sha1
