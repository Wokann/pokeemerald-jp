#!/bin/bash
# usage: disasm_range.sh <start_hex> <end_hex> [rom]
cd /home/kenny/pokeemerald-jp
ROM=${3:-baserom_jp.gba}
arm-none-eabi-objdump -D -b binary -m arm --disassembler-options=force-thumb \
  --start-address=$((0x$1 - 0x08000000)) --stop-address=$((0x$2 - 0x08000000)) \
  "$ROM" 2>/dev/null | sed -n '7,$p'
