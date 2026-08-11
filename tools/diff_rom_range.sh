#!/bin/bash
# Diff a ROM address range (GBA virtual addresses) between the two ROMs.
set -e
OBJDUMP="tools/binutils/bin/arm-none-eabi-objdump -D -bbinary -marmv4t -Mforce-thumb"
START=$(( $1 - 0x08000000 ))
LEN=$(( $2 ))
$OBJDUMP --start-address="$START" --stop-address=$((START + LEN)) baserom_jp.gba > /tmp/rom_a.dump
$OBJDUMP --start-address="$START" --stop-address=$((START + LEN)) pokeemerald_jp.gba > /tmp/rom_b.dump
diff -u /tmp/rom_a.dump /tmp/rom_b.dump | head -100
