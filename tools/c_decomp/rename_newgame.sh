#!/bin/bash
cd /home/kenny/pokeemerald-jp
# Rename JP labels used by NewGameInitData to US names across asm files.
rename() {
  local old=$1 new=$2
  files=$(grep -rln "$old" asm/*.s)
  for f in $files; do
    sed -i "s/$old/$new/g" "$f"
    echo "$f: $old -> $new"
  done
}
rename ClearMailData ClearAllMail
rename copy_strings_to_sav1 InitUnionRoomChatRegisteredTexts
rename ScriptContext2_RunNewScript RunScriptImmediately
rename sub_08136EF8 ClearPokeblocks
rename sub_0801AAAC ClearMysteryGift
rename sub_0813628C ResetPokeblockScrollPositions
rename 'SetLilycoveLady ' 'InitLilycoveLady '
