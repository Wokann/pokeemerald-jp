#!/bin/bash
cd /home/kenny/pokeemerald-jp
files=$(grep -rln 'GiveMailToMon2\|GiveMailToMon\b\|TakeMailFromMon2\|ClearMailStruct' asm/*.s)
for f in $files; do
  sed -i 's/GiveMailToMon2/ZZZMAILTMP/g; s/GiveMailToMon\b/GiveMailToMonByItemId/g; s/ZZZMAILTMP/GiveMailToMon/g; s/TakeMailFromMon2/TakeMailFromMonAndSave/g; s/ClearMailStruct/ClearMail/g' "$f"
  echo "updated $f"
done
