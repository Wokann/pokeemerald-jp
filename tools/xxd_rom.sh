#!/bin/bash
# usage: xxd_rom.sh <rom_addr_hex> <len>
cd /home/kenny/pokeemerald-jp
addr=$((0x$1 - 0x08000000))
len=$2
xxd -s "$addr" -l "$len" baserom_jp.gba
