# Pokémon Emerald (J)

This is a disassembly of the Japanese version of Pokémon Emerald.

You must have a Japanese Emerald ROM named `baserom_jp.gba` in the project root.

It builds the following ROM:
* pokeemerald_jp.gba `sha1: d7cf8f156ba9c455d164e1ea780a6bf1945465c2`

## Building

Place a Japanese Emerald ROM named `baserom_jp.gba` in the project root, then run:

	make

The build extracts the ROM regions that are still represented as raw data
into `build/data/*.bin` via `tools/extract_baserom_data.py` (generated
artifacts, not tracked by git), then assembles the disassembly.  The
extracted binaries are byte-identical copies of the corresponding ROM
regions and are intentionally kept out of version control; only the
decompiled/structured sources are committed.

To verify the output matches the official ROM byte for byte:

	make compare

Build tooling: `sh build_tools.sh` for the host tools, and an
`arm-none-eabi` binutils plus agbcc's `libgcc.a`/`libc.a` installed under
`tools/binutils` and `tools/agbcc` respectively.

## Data structure

The script-data region (0x1DABAC-0x28D2F8) is being converted from raw
`.incbin` chunks into structured sources, following pokeemerald's layout:

* `data/script_cmd_table.inc` - `gScriptCmdTable` (225 script commands
  plus the `gScriptCmdTableEnd` sentinel)
* `data/specials.inc` - `gSpecials` (524 special commands)
* `data/mystery_event_script_cmd_table.inc` - `gMysteryEventScriptCmdTable`
  (17 commands)
* `data/event_scripts.s` - remaining data.  Pointer tables are symbolic
  `.4byte` lists; raw chunks are split at every address referenced by a
  pointer table and labelled (`gUnknown_XXXXXXXX`), making the boundaries
  of the referenced scripts/data visible.

Generator/analysis tools under `tools/`:

* `extract_baserom_data.py` - regenerate `build/data/*.bin` from
  `baserom_jp.gba`
* `generate_script_cmd_table.py`, `generate_specials.py`,
  `generate_mystery_event_cmd_table.py` - regenerate the tables above
* `analyze_chunks.py` - classify every chunk in `data/event_scripts.s`
* `split_script_region.py` - split raw chunks at pointer-table targets and
  convert the pointer tables to symbolic references

To set up the repository, see [INSTALL.md](INSTALL.md)

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
