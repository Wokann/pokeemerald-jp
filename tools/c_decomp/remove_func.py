#!/usr/bin/env python3
"""Remove a function definition from a C file between two markers."""
import sys
from pathlib import Path

path = Path(sys.argv[1])
start_marker = sys.argv[2]
end_marker = sys.argv[3]
t = path.read_text(encoding="utf-8")
start = t.index(start_marker)
end = t.index(end_marker, start)
t = t[:start] + t[end:]
path.write_text(t, encoding="utf-8")
print(f"removed {end - start} bytes")
