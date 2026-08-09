#!/usr/bin/env python3
import re

path = "funcmap_jp.txt"
lines = open(path, encoding="utf-8").read().splitlines()

# address -> new JP/US name (JP and US names are now identical after the
# pokeemerald name alignment)
renames = {
    "0808e5e8": "GetObjectEventIdByPosition",
    "0808b5d8": "PlayerGetElevation",
    "08092afc": "ObjectEventIsMovementOverridden",
    "08092b30": "ObjectEventSetHeldMovement",
    "08092be0": "ObjectEventCheckHeldMovementStatus",
    "08092bf4": "ObjectEventClearHeldMovementIfFinished",
    "0808dd68": "ObjectEventSetGraphicsId",
    "080987dc": "LockPlayerFieldControls",
    "080987e8": "UnlockPlayerFieldControls",
    "08098880": "ScriptContext_SetupScript",
    "080988c4": "ScriptContext_Enable",
}

out = []
for line in lines:
    m = re.match(r"^([0-9a-fA-F]{8})\s+(\S+)(?:\s+(\S+))?$", line)
    if m and m.group(1).lower() in renames:
        addr, a, b = m.group(1), m.group(2), m.group(3)
        new = renames[addr.lower()]
        # col2 = JP name (file placeholder replaced by real name),
        # col3 = US pokeemerald name
        out.append(f"{addr} {new} {new}")
    else:
        out.append(line)

open(path, "w", encoding="utf-8").write("\n".join(out) + "\n")
print("updated funcmap_jp.txt")
