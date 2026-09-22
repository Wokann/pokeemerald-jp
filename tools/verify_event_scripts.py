import re
import subprocess
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROM = ROOT / "baserom_jp.gba"
ELF = ROOT / "pokeemerald_jp.elf"
OBJCOPY = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-objcopy"
OBJDUMP = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-objdump"
ROM_VMA = 0x08000000


def get_script_data_range():
    """Return the linked script_data VMA and size from the finished ELF."""
    output = subprocess.check_output([str(OBJDUMP), "-h", str(ELF)], text=True)
    for line in output.splitlines():
        match = re.match(r"\s*\d+\s+script_data\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)", line)
        if match:
            return int(match.group(2), 16), int(match.group(1), 16)
    raise RuntimeError("linked ELF has no script_data section")


def first_difference(left, right):
    """Return the first differing byte offset, or None for identical spans."""
    for index, (left_byte, right_byte) in enumerate(zip(left, right)):
        if left_byte != right_byte:
            return index
    if len(left) != len(right):
        return min(len(left), len(right))
    return None


def main():
    # This target uses the same preproc -> cpp -> preproc pipeline as the
    # ordinary build. Linking is required because script_data has relocations
    # to symbols outside data/event_scripts.o.
    subprocess.run(["make", "pokeemerald_jp.elf"], cwd=ROOT, check=True)

    section_vma, section_size = get_script_data_range()
    if section_vma < ROM_VMA:
        raise RuntimeError("script_data is not located in the ROM address range")
    rom_offset = section_vma - ROM_VMA

    with tempfile.TemporaryDirectory(prefix="pokeemerald-jp-script-data-") as tmpdir:
        section_path = Path(tmpdir) / "script_data.bin"
        subprocess.run(
            [str(OBJCOPY), "-j", "script_data", "-O", "binary", str(ELF), str(section_path)],
            check=True,
        )
        built = section_path.read_bytes()

    expected = ROM.read_bytes()[rom_offset:rom_offset + section_size]
    print(
        "script_data: 0x%08X-0x%08X (%d bytes)" %
        (section_vma, section_vma + section_size, section_size)
    )
    if len(built) != section_size:
        print("section extraction size mismatch: expected %d, got %d" % (section_size, len(built)))
        return 1
    if len(expected) != section_size:
        print("baserom span is truncated: expected %d, got %d" % (section_size, len(expected)))
        return 1

    difference = first_difference(built, expected)
    if difference is not None:
        print(
            "script_data mismatch at 0x%08X: built=%02X baserom=%02X" %
            (section_vma + difference, built[difference], expected[difference])
        )
        return 1

    print("script_data: OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
