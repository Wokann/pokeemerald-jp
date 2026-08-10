#!/usr/bin/env python3
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
c = (ROOT / "src" / "mail_data.c").read_text()
naked = (Path("/tmp/mail_naked.c")).read_text()

# Rename the JP function to the US name and add .syntax wrappers.
naked = naked.replace("void GiveMailToMon(void)", "u8 GiveMailToMonByItemId(struct Pokemon *mon, u16 itemId)", 1)
naked = naked.replace(
    '    __asm__(".code 16\\n\\t"',
    '    __asm__(".syntax unified\\n\\t"\n            ".code 16\\n\\t"',
    1,
)
body = naked.strip()
if body.endswith("}"):
    body = body[:-1].rstrip()
assert body.endswith('");'), repr(body[-20:])
body = body[:-3] + '\\n\\t"\n            ".syntax divided");'
body += "\n}\n"

lines = c.splitlines(keepends=True)
start = next(i for i, l in enumerate(lines) if l.startswith("u8 GiveMailToMonByItemId"))
end = next(i for i in range(start + 1, len(lines)) if lines[i].rstrip() == "}" and not lines[i].startswith((" ", "\t")))
c = "".join(lines[:start]) + body + "".join(lines[end + 1 :])
(ROOT / "src" / "mail_data.c").write_text(c)
print("replaced")
