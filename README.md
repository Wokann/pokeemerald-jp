# Pokémon Emerald (J)

This is a disassembly of the Japanese version of Pokémon Emerald.

You must have a Japanese Emerald ROM named `baserom_jp.gba` in the project root.

It builds the following ROM:
* pokeemerald_jp.gba `sha1: d7cf8f156ba9c455d164e1ea780a6bf1945465c2`

## Building

Place a Japanese Emerald ROM named `baserom_jp.gba` in the project root, then
run the one-shot setup script (installs host tools, links the system
`arm-none-eabi` binutils into `tools/binutils`, and clones/builds/installs
[pret/agbcc](https://github.com/pret/agbcc) into `tools/agbcc`):

	sh setup.sh

	make

The ROM regions that are still raw data are `.incbin`'d directly from
`baserom_jp.gba` (absolute offsets), and the multiboot programs
(`data/mb_ereader.gba`, `data/mb_berry_fix.gba`) are committed data files,
following pokeemerald's layout.  No intermediate extraction step is needed.

To verify the output matches the official ROM byte for byte:

	make compare

Build tooling: `sh setup.sh` handles everything; it requires a system
`arm-none-eabi` toolchain (e.g. `gcc-arm-none-eabi` on Debian/Ubuntu or
`arm-none-eabi-gcc` on macOS via Homebrew) plus `gcc`/`g++`/`make`/`git`/`cpp`.

## Data structure

The JP script-data span `[0x081DABAC, 0x0828D2F8)` uses the same eight
assembly owners and linker order as pokeemerald:

* `data/event_scripts.s`
* `data/battle_anim_scripts.s`
* `data/battle_scripts_1.s`
* `data/field_effect_scripts.s`
* `data/battle_scripts_2.s`
* `data/battle_ai_scripts.s`
* `data/contest_ai_scripts.s`
* `data/mystery_event_script_cmd_table.s`

`data/script_cmd_table.inc` and `data/specials.inc` define the JP script
command and Special tables. The build allocates each table once; the
same definitions provide command constants to the script macros.
These are reviewed source tables, not outputs to regenerate during a
normal build.

Map scripts and local text live in `data/maps/<Map>/scripts.inc`.
Shared scripts and text use `data/scripts/` and `data/text/`. The
explicit includes preserve JP physical order even when it differs
from US. Map JSON is the source for generated event, header and
connection includes; the build regenerates these in their canonical
map directories. Layout data is collected in `data/layouts/layouts.inc`.

Assembly text uses `tools/preproc` and `charmap.txt` to reproduce the
original game encoding. C text uses `_` or `__` according to the
object's actual terminator and padding bytes. Preserve JP control
sequences and line/page breaks; use the corresponding US text and
callers to select semantic names, never to replace JP bytes blindly.
Editable graphics use PNG/palette/tilemap inputs and the existing
`gbagfx`/`INCGFX` build chain.

Conversion requires both confirmed ownership and byte equality.
Unproven ranges stay explicit; do not turn arbitrary binary data
into strings merely because it can round-trip. The old monolithic
data source and its one-shot mutation tools have been retired.
See [DECOMP_PROGRESS.md](DECOMP_PROGRESS.md) for current coverage and
remaining raw ranges; an existing file does not prove semantic review.

Current JP verification tools under `tools/` include:

* `jp_script_text.py` - decode JP text and verify it through the real
  preprocessor; unknown controls fail instead of being guessed.
  `python3 tools/jp_script_text.py selftest` exercises the codec.
* `audit_script_text_sources.py` - audit explicit text objects throughout
  the recursive EventScript include chain against linked symbols and
  the JP ROM.
* `audit_special_table.py` - check Special-table ownership, names and
  remaining migration evidence.
* `map_semantic_review.py` - validate recorded map-review evidence.
* `audit_structure.py` - report source structure, linker owners,
  references and conversion progress.
* `decompile_scripts.py` - decode event-script bytes using the JP command
  table and event macros; review generated results before integration.

Set up the build environment and see the skip-already-installed flow in
[INSTALL.md](INSTALL.md).  If you are contributing decompilation work,
the asm-to-C conversion procedure and the mandatory `make compare`
verification are documented in [DECOMPILING.md](DECOMPILING.md).

## See also

Other disassembly and/or decompilation projects:
* [**Pokémon Red and Blue**](https://github.com/pret/pokered)
* [**Pokémon Gold and Silver (Space World '97 demo)**](https://github.com/pret/pokegold-spaceworld)
* [**Pokémon Yellow**](https://github.com/pret/pokeyellow)
* [**Pokémon Trading Card Game**](https://github.com/pret/poketcg)
* [**Pokémon Pinball**](https://github.com/pret/pokepinball)
* [**Pokémon Stadium**](https://github.com/pret/pokestadium)
* [**Pokémon Gold and Silver**](https://github.com/pret/pokegold)
* [**Pokémon Crystal**](https://github.com/pret/pokecrystal)
* [**Pokémon Ruby and Sapphire**](https://github.com/pret/pokeruby)
* [**Pokémon Pinball: Ruby & Sapphire**](https://github.com/pret/pokepinballrs)
* [**Pokémon FireRed and LeafGreen**](https://github.com/pret/pokefirered)
* [**Pokémon Emerald (U)**](https://github.com/pret/pokeemerald)
* [**Pokémon Mystery Dungeon: Red Rescue Team**](https://github.com/pret/pmd-red)


## Contacts

You can find us on [Discord](https://discord.gg/d5dubZ3) and [IRC](https://web.libera.chat/?#pret).
