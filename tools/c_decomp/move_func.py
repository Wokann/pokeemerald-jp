#!/usr/bin/env python3
"""Move a function block in a C file from the start area to before a marker."""
import sys
from pathlib import Path

path = Path(sys.argv[1])
func_start = sys.argv[2]  # exact line that starts the function
end_marker = sys.argv[3]  # next definition line after the function
insert_before = sys.argv[4]  # line before which to insert

t = path.read_text(encoding="utf-8")
start = t.index(func_start + "\n")
end = t.index(end_marker + "\n", start)
block = t[start:end]
t = t[:start] + t[end:]
pos = t.index(insert_before + "\n")
t = t[:pos] + block + t[pos:]
path.write_text(t, encoding="utf-8")
print("moved")
