gMapLayout_PETALBURG_CITY_Border:
	.incbin "data/layouts/PetalburgCity/border.bin"
gMapLayout_PETALBURG_CITY_Blockdata:
	.incbin "data/layouts/PetalburgCity/map.bin"
	.globl gMapLayout_PETALBURG_CITY
gMapLayout_PETALBURG_CITY: @ 0x083B8944
	.4byte 30  @ width
	.4byte 30  @ height
	.4byte gMapLayout_PETALBURG_CITY_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_Border:
	.incbin "data/layouts/SlateportCity/border.bin"
gMapLayout_SLATEPORT_CITY_Blockdata:
	.incbin "data/layouts/SlateportCity/map.bin"
	.globl gMapLayout_SLATEPORT_CITY
gMapLayout_SLATEPORT_CITY: @ 0x083B9C24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_SLATEPORT_CITY_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_Border:
	.incbin "data/layouts/MauvilleCity/border.bin"
gMapLayout_MAUVILLE_CITY_Blockdata:
	.incbin "data/layouts/MauvilleCity/map.bin"
	.globl gMapLayout_MAUVILLE_CITY
gMapLayout_MAUVILLE_CITY: @ 0x083BA284
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte gMapLayout_MAUVILLE_CITY_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_Border:
	.incbin "data/layouts/RustboroCity/border.bin"
gMapLayout_RUSTBORO_CITY_Blockdata:
	.incbin "data/layouts/RustboroCity/map.bin"
	.globl gMapLayout_RUSTBORO_CITY
gMapLayout_RUSTBORO_CITY: @ 0x083BB564
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_RUSTBORO_CITY_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_Border:
	.incbin "data/layouts/FortreeCity/border.bin"
gMapLayout_FORTREE_CITY_Blockdata:
	.incbin "data/layouts/FortreeCity/map.bin"
	.globl gMapLayout_FORTREE_CITY
gMapLayout_FORTREE_CITY: @ 0x083BBBC4
	.4byte 40  @ width
	.4byte 20  @ height
	.4byte gMapLayout_FORTREE_CITY_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_Border:
	.incbin "data/layouts/LilycoveCity/border.bin"
gMapLayout_LILYCOVE_CITY_Blockdata:
	.incbin "data/layouts/LilycoveCity/map.bin"
	.globl gMapLayout_LILYCOVE_CITY
gMapLayout_LILYCOVE_CITY: @ 0x083BD4E4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_LILYCOVE_CITY_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_Border:
	.incbin "data/layouts/MossdeepCity/border.bin"
gMapLayout_MOSSDEEP_CITY_Blockdata:
	.incbin "data/layouts/MossdeepCity/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY
gMapLayout_MOSSDEEP_CITY: @ 0x083BEE04
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_Border:
	.incbin "data/layouts/SootopolisCity/border.bin"
gMapLayout_SOOTOPOLIS_CITY_Blockdata:
	.incbin "data/layouts/SootopolisCity/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY
gMapLayout_SOOTOPOLIS_CITY: @ 0x083C0A44
	.4byte 60  @ width
	.4byte 60  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_Border:
	.incbin "data/layouts/EverGrandeCity/border.bin"
gMapLayout_EVER_GRANDE_CITY_Blockdata:
	.incbin "data/layouts/EverGrandeCity/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY
gMapLayout_EVER_GRANDE_CITY: @ 0x083C2364
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_Border:
	.incbin "data/layouts/LittlerootTown/border.bin"
gMapLayout_LITTLEROOT_TOWN_Blockdata:
	.incbin "data/layouts/LittlerootTown/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN
gMapLayout_LITTLEROOT_TOWN: @ 0x083C26A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_Border:
	.incbin "data/layouts/OldaleTown/border.bin"
gMapLayout_OLDALE_TOWN_Blockdata:
	.incbin "data/layouts/OldaleTown/map.bin"
	.globl gMapLayout_OLDALE_TOWN
gMapLayout_OLDALE_TOWN: @ 0x083C29E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_OLDALE_TOWN_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_Border:
	.incbin "data/layouts/DewfordTown/border.bin"
gMapLayout_DEWFORD_TOWN_Blockdata:
	.incbin "data/layouts/DewfordTown/map.bin"
	.globl gMapLayout_DEWFORD_TOWN
gMapLayout_DEWFORD_TOWN: @ 0x083C2D24
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_DEWFORD_TOWN_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_Border:
	.incbin "data/layouts/LavaridgeTown/border.bin"
gMapLayout_LAVARIDGE_TOWN_Blockdata:
	.incbin "data/layouts/LavaridgeTown/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN
gMapLayout_LAVARIDGE_TOWN: @ 0x083C3064
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_Border:
	.incbin "data/layouts/FallarborTown/border.bin"
gMapLayout_FALLARBOR_TOWN_Blockdata:
	.incbin "data/layouts/FallarborTown/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN
gMapLayout_FALLARBOR_TOWN: @ 0x083C33A4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_VERDANTURF_TOWN_Border:
	.incbin "data/layouts/VerdanturfTown/border.bin"
gMapLayout_VERDANTURF_TOWN_Blockdata:
	.incbin "data/layouts/VerdanturfTown/map.bin"
	.globl gMapLayout_VERDANTURF_TOWN
gMapLayout_VERDANTURF_TOWN: @ 0x083C36E4
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_Border:
	.incbin "data/layouts/PacifidlogTown/border.bin"
gMapLayout_PACIFIDLOG_TOWN_Blockdata:
	.incbin "data/layouts/PacifidlogTown/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN
gMapLayout_PACIFIDLOG_TOWN: @ 0x083C3D44
	.4byte 20  @ width
	.4byte 40  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE101_Border:
	.incbin "data/layouts/Route101/border.bin"
gMapLayout_ROUTE101_Blockdata:
	.incbin "data/layouts/Route101/map.bin"
	.globl gMapLayout_ROUTE101
gMapLayout_ROUTE101: @ 0x083C4084
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE101_Border  @ border
	.4byte gMapLayout_ROUTE101_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE102_Border:
	.incbin "data/layouts/Route102/border.bin"
gMapLayout_ROUTE102_Blockdata:
	.incbin "data/layouts/Route102/map.bin"
	.globl gMapLayout_ROUTE102
gMapLayout_ROUTE102: @ 0x083C4874
	.4byte 50  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE102_Border  @ border
	.4byte gMapLayout_ROUTE102_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE103_Border:
	.incbin "data/layouts/Route103/border.bin"
gMapLayout_ROUTE103_Blockdata:
	.incbin "data/layouts/Route103/map.bin"
	.globl gMapLayout_ROUTE103
gMapLayout_ROUTE103: @ 0x083C5654
	.4byte 80  @ width
	.4byte 22  @ height
	.4byte gMapLayout_ROUTE103_Border  @ border
	.4byte gMapLayout_ROUTE103_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_Border:
	.incbin "data/layouts/Route104/border.bin"
gMapLayout_ROUTE104_Blockdata:
	.incbin "data/layouts/Route104/map.bin"
	.globl gMapLayout_ROUTE104
gMapLayout_ROUTE104: @ 0x083C6F74
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE104_Border  @ border
	.4byte gMapLayout_ROUTE104_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE105_Border:
	.incbin "data/layouts/Route105/border.bin"
gMapLayout_ROUTE105_Blockdata:
	.incbin "data/layouts/Route105/map.bin"
	.globl gMapLayout_ROUTE105
gMapLayout_ROUTE105: @ 0x083C8894
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE105_Border  @ border
	.4byte gMapLayout_ROUTE105_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE106_Border:
	.incbin "data/layouts/Route106/border.bin"
gMapLayout_ROUTE106_Blockdata:
	.incbin "data/layouts/Route106/map.bin"
	.globl gMapLayout_ROUTE106
gMapLayout_ROUTE106: @ 0x083C9534
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE106_Border  @ border
	.4byte gMapLayout_ROUTE106_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE107_Border:
	.incbin "data/layouts/Route107/border.bin"
gMapLayout_ROUTE107_Blockdata:
	.incbin "data/layouts/Route107/map.bin"
	.globl gMapLayout_ROUTE107
gMapLayout_ROUTE107: @ 0x083C9EB4
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE107_Border  @ border
	.4byte gMapLayout_ROUTE107_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE108_Border:
	.incbin "data/layouts/Route108/border.bin"
gMapLayout_ROUTE108_Blockdata:
	.incbin "data/layouts/Route108/map.bin"
	.globl gMapLayout_ROUTE108
gMapLayout_ROUTE108: @ 0x083CA834
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE108_Border  @ border
	.4byte gMapLayout_ROUTE108_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE109_Border:
	.incbin "data/layouts/Route109/border.bin"
gMapLayout_ROUTE109_Blockdata:
	.incbin "data/layouts/Route109/map.bin"
	.globl gMapLayout_ROUTE109
gMapLayout_ROUTE109: @ 0x083CBC04
	.4byte 40  @ width
	.4byte 63  @ height
	.4byte gMapLayout_ROUTE109_Border  @ border
	.4byte gMapLayout_ROUTE109_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE110_Border:
	.incbin "data/layouts/Route110/border.bin"
gMapLayout_ROUTE110_Blockdata:
	.incbin "data/layouts/Route110/map.bin"
	.globl gMapLayout_ROUTE110
gMapLayout_ROUTE110: @ 0x083CDB64
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte gMapLayout_ROUTE110_Border  @ border
	.4byte gMapLayout_ROUTE110_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE111_Border:
	.incbin "data/layouts/Route111/border.bin"
gMapLayout_ROUTE111_Blockdata:
	.incbin "data/layouts/Route111/map.bin"
	.globl gMapLayout_ROUTE111
gMapLayout_ROUTE111: @ 0x083D0744
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte gMapLayout_ROUTE111_Border  @ border
	.4byte gMapLayout_ROUTE111_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE112_Border:
	.incbin "data/layouts/Route112/border.bin"
gMapLayout_ROUTE112_Blockdata:
	.incbin "data/layouts/Route112/map.bin"
	.globl gMapLayout_ROUTE112
gMapLayout_ROUTE112: @ 0x083D1A24
	.4byte 40  @ width
	.4byte 60  @ height
	.4byte gMapLayout_ROUTE112_Border  @ border
	.4byte gMapLayout_ROUTE112_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE113_Border:
	.incbin "data/layouts/Route113/border.bin"
gMapLayout_ROUTE113_Blockdata:
	.incbin "data/layouts/Route113/map.bin"
	.globl gMapLayout_ROUTE113
gMapLayout_ROUTE113: @ 0x083D29E4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE113_Border  @ border
	.4byte gMapLayout_ROUTE113_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_Border:
	.incbin "data/layouts/Route114/border.bin"
gMapLayout_ROUTE114_Blockdata:
	.incbin "data/layouts/Route114/map.bin"
	.globl gMapLayout_ROUTE114
gMapLayout_ROUTE114: @ 0x083D4304
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE114_Border  @ border
	.4byte gMapLayout_ROUTE114_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE115_Border:
	.incbin "data/layouts/Route115/border.bin"
gMapLayout_ROUTE115_Blockdata:
	.incbin "data/layouts/Route115/map.bin"
	.globl gMapLayout_ROUTE115
gMapLayout_ROUTE115: @ 0x083D5C24
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE115_Border  @ border
	.4byte gMapLayout_ROUTE115_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE116_Border:
	.incbin "data/layouts/Route116/border.bin"
gMapLayout_ROUTE116_Blockdata:
	.incbin "data/layouts/Route116/map.bin"
	.globl gMapLayout_ROUTE116
gMapLayout_ROUTE116: @ 0x083D6BE4
	.4byte 100  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE116_Border  @ border
	.4byte gMapLayout_ROUTE116_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE117_Border:
	.incbin "data/layouts/Route117/border.bin"
gMapLayout_ROUTE117_Blockdata:
	.incbin "data/layouts/Route117/map.bin"
	.globl gMapLayout_ROUTE117
gMapLayout_ROUTE117: @ 0x083D7564
	.4byte 60  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE117_Border  @ border
	.4byte gMapLayout_ROUTE117_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE118_Border:
	.incbin "data/layouts/Route118/border.bin"
gMapLayout_ROUTE118_Blockdata:
	.incbin "data/layouts/Route118/map.bin"
	.globl gMapLayout_ROUTE118
gMapLayout_ROUTE118: @ 0x083D8204
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE118_Border  @ border
	.4byte gMapLayout_ROUTE118_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE119_Border:
	.incbin "data/layouts/Route119/border.bin"
gMapLayout_ROUTE119_Blockdata:
	.incbin "data/layouts/Route119/map.bin"
	.globl gMapLayout_ROUTE119
gMapLayout_ROUTE119: @ 0x083DADE4
	.4byte 40  @ width
	.4byte 140  @ height
	.4byte gMapLayout_ROUTE119_Border  @ border
	.4byte gMapLayout_ROUTE119_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE120_Border:
	.incbin "data/layouts/Route120/border.bin"
gMapLayout_ROUTE120_Blockdata:
	.incbin "data/layouts/Route120/map.bin"
	.globl gMapLayout_ROUTE120
gMapLayout_ROUTE120: @ 0x083DCD44
	.4byte 40  @ width
	.4byte 100  @ height
	.4byte gMapLayout_ROUTE120_Border  @ border
	.4byte gMapLayout_ROUTE120_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE121_Border:
	.incbin "data/layouts/Route121/border.bin"
gMapLayout_ROUTE121_Blockdata:
	.incbin "data/layouts/Route121/map.bin"
	.globl gMapLayout_ROUTE121
gMapLayout_ROUTE121: @ 0x083DD9E4
	.4byte 80  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE121_Border  @ border
	.4byte gMapLayout_ROUTE121_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE122_Border:
	.incbin "data/layouts/Route122/border.bin"
gMapLayout_ROUTE122_Blockdata:
	.incbin "data/layouts/Route122/map.bin"
	.globl gMapLayout_ROUTE122
gMapLayout_ROUTE122: @ 0x083DE684
	.4byte 40  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE122_Border  @ border
	.4byte gMapLayout_ROUTE122_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE123_Border:
	.incbin "data/layouts/Route123/border.bin"
gMapLayout_ROUTE123_Blockdata:
	.incbin "data/layouts/Route123/map.bin"
	.globl gMapLayout_ROUTE123
gMapLayout_ROUTE123: @ 0x083DFC84
	.4byte 140  @ width
	.4byte 20  @ height
	.4byte gMapLayout_ROUTE123_Border  @ border
	.4byte gMapLayout_ROUTE123_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE124_Border:
	.incbin "data/layouts/Route124/border.bin"
gMapLayout_ROUTE124_Blockdata:
	.incbin "data/layouts/Route124/map.bin"
	.globl gMapLayout_ROUTE124
gMapLayout_ROUTE124: @ 0x083E2EA4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE124_Border  @ border
	.4byte gMapLayout_ROUTE124_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE125_Border:
	.incbin "data/layouts/Route125/border.bin"
gMapLayout_ROUTE125_Blockdata:
	.incbin "data/layouts/Route125/map.bin"
	.globl gMapLayout_ROUTE125
gMapLayout_ROUTE125: @ 0x083E47C4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE125_Border  @ border
	.4byte gMapLayout_ROUTE125_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE126_Border:
	.incbin "data/layouts/Route126/border.bin"
gMapLayout_ROUTE126_Blockdata:
	.incbin "data/layouts/Route126/map.bin"
	.globl gMapLayout_ROUTE126
gMapLayout_ROUTE126: @ 0x083E79E4
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE126_Border  @ border
	.4byte gMapLayout_ROUTE126_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE127_Border:
	.incbin "data/layouts/Route127/border.bin"
gMapLayout_ROUTE127_Blockdata:
	.incbin "data/layouts/Route127/map.bin"
	.globl gMapLayout_ROUTE127
gMapLayout_ROUTE127: @ 0x083EAC04
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte gMapLayout_ROUTE127_Border  @ border
	.4byte gMapLayout_ROUTE127_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE128_Border:
	.incbin "data/layouts/Route128/border.bin"
gMapLayout_ROUTE128_Blockdata:
	.incbin "data/layouts/Route128/map.bin"
	.globl gMapLayout_ROUTE128
gMapLayout_ROUTE128: @ 0x083ED1A4
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE128_Border  @ border
	.4byte gMapLayout_ROUTE128_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE129_Border:
	.incbin "data/layouts/Route129/border.bin"
gMapLayout_ROUTE129_Blockdata:
	.incbin "data/layouts/Route129/map.bin"
	.globl gMapLayout_ROUTE129
gMapLayout_ROUTE129: @ 0x083EEAC4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE129_Border  @ border
	.4byte gMapLayout_ROUTE129_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x3eeadc, 0x1920
gMapLayout_ROUTE131_Border:
	.incbin "data/layouts/Route131/border.bin"
gMapLayout_ROUTE131_Blockdata:
	.incbin "data/layouts/Route131/map.bin"
	.globl gMapLayout_ROUTE131
gMapLayout_ROUTE131: @ 0x083F16C4
	.4byte 60  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE131_Border  @ border
	.4byte gMapLayout_ROUTE131_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE132_Border:
	.incbin "data/layouts/Route132/border.bin"
gMapLayout_ROUTE132_Blockdata:
	.incbin "data/layouts/Route132/map.bin"
	.globl gMapLayout_ROUTE132
gMapLayout_ROUTE132: @ 0x083F2FE4
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE132_Border  @ border
	.4byte gMapLayout_ROUTE132_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE133_Border:
	.incbin "data/layouts/Route133/border.bin"
gMapLayout_ROUTE133_Blockdata:
	.incbin "data/layouts/Route133/map.bin"
	.globl gMapLayout_ROUTE133
gMapLayout_ROUTE133: @ 0x083F4904
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE133_Border  @ border
	.4byte gMapLayout_ROUTE133_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE134_Border:
	.incbin "data/layouts/Route134/border.bin"
gMapLayout_ROUTE134_Blockdata:
	.incbin "data/layouts/Route134/map.bin"
	.globl gMapLayout_ROUTE134
gMapLayout_ROUTE134: @ 0x083F6224
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE134_Border  @ border
	.4byte gMapLayout_ROUTE134_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
Underwater_Route126_Layout_Border::
	.incbin "data/layouts/Underwater_Route126/border.bin"
Underwater_Route126_Layout_Blockdata::
	.incbin "data/layouts/Underwater_Route126/map.bin"
Underwater_Route126_Layout:: @ 0x083F9444
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte Underwater_Route126_Layout_Border  @ border
	.4byte Underwater_Route126_Layout_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
Underwater_Route127_Layout_Border::
	.incbin "data/layouts/Underwater_Route127/border.bin"
Underwater_Route127_Layout_Blockdata::
	.incbin "data/layouts/Underwater_Route127/map.bin"
Underwater_Route127_Layout:: @ 0x083FC664
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte Underwater_Route127_Layout_Border  @ border
	.4byte Underwater_Route127_Layout_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
Underwater_Route128_Layout_Border::
	.incbin "data/layouts/Underwater_Route128/border.bin"
Underwater_Route128_Layout_Blockdata::
	.incbin "data/layouts/Underwater_Route128/map.bin"
Underwater_Route128_Layout:: @ 0x083FEC04
	.4byte 120  @ width
	.4byte 40  @ height
	.4byte Underwater_Route128_Layout_Border  @ border
	.4byte Underwater_Route128_Layout_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Border:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_1F/border.bin"
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F: @ 0x083FECEC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Border:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_2F/border.bin"
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Blockdata:
	.incbin "data/layouts/LittlerootTown_BrendansHouse_2F/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F: @ 0x083FED9C
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Border:
	.incbin "data/layouts/LittlerootTown_MaysHouse_1F/border.bin"
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/LittlerootTown_MaysHouse_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F: @ 0x083FEE84
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Border:
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/border.bin"
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Blockdata:
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/map.bin"
	.globl gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F
gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F: @ 0x083FEF34
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_MAYS_HOUSE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Border:
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/border.bin"
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Blockdata:
	.incbin "data/layouts/LittlerootTown_ProfessorBirchsLab/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB
gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB: @ 0x083FF0A8
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Border  @ border
	.4byte gMapLayout_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_HOUSE1_Border:
	.incbin "data/layouts/OldaleTownHouse1/border.bin"
gMapLayout_OLDALE_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/OldaleTownHouse1/map.bin"
	.globl gMapLayout_OLDALE_TOWN_HOUSE1
gMapLayout_OLDALE_TOWN_HOUSE1: @ 0x083FF17C
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_HOUSE2_Border:
	.incbin "data/layouts/OldaleTownHouse2/border.bin"
gMapLayout_OLDALE_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/OldaleTownHouse2/map.bin"
	.globl gMapLayout_OLDALE_TOWN_HOUSE2
gMapLayout_OLDALE_TOWN_HOUSE2: @ 0x083FF24C
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Border:
	.incbin "data/layouts/OldaleTownPokemonCenter1f/border.bin"
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Blockdata:
	.incbin "data/layouts/OldaleTownPokemonCenter1f/map.bin"
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F: @ 0x083FF368
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Border:
	.incbin "data/layouts/OldaleTownPokemonCenter2f/border.bin"
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Blockdata:
	.incbin "data/layouts/OldaleTownPokemonCenter2f/map.bin"
	.globl gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F
gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F: @ 0x083FF4A0
	.4byte 14  @ width
	.4byte 10  @ height
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_POKEMON_CENTER_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
gMapLayout_OLDALE_TOWN_MART_Border:
	.incbin "data/layouts/OldaleTownMart/border.bin"
gMapLayout_OLDALE_TOWN_MART_Blockdata:
	.incbin "data/layouts/OldaleTownMart/map.bin"
	.globl gMapLayout_OLDALE_TOWN_MART
gMapLayout_OLDALE_TOWN_MART: @ 0x083FF570
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_OLDALE_TOWN_MART_Border  @ border
	.4byte gMapLayout_OLDALE_TOWN_MART_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HOUSE1_Border:
	.incbin "data/layouts/DewfordTownHouse1/border.bin"
gMapLayout_DEWFORD_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/DewfordTownHouse1/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_HOUSE1
gMapLayout_DEWFORD_TOWN_HOUSE1: @ 0x083FF630
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_GYM_Border:
	.incbin "data/layouts/DewfordTown_Gym/border.bin"
gMapLayout_DEWFORD_TOWN_GYM_Blockdata:
	.incbin "data/layouts/DewfordTown_Gym/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_GYM
gMapLayout_DEWFORD_TOWN_GYM: @ 0x083FFA40
	.4byte 18  @ width
	.4byte 28  @ height
	.4byte gMapLayout_DEWFORD_TOWN_GYM_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_DEWFORD_TOWN_GYM_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HALL_Border:
	.incbin "data/layouts/DewfordTown_Hall/border.bin"
gMapLayout_DEWFORD_TOWN_HALL_Blockdata:
	.incbin "data/layouts/DewfordTown_Hall/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_DEWFORD_TOWN_HALL
gMapLayout_DEWFORD_TOWN_HALL: @ 0x083FFB94
	.4byte 17  @ width
	.4byte 9  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HALL_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HALL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_DEWFORD_TOWN_HOUSE2_Border:
	.incbin "data/layouts/DewfordTownHouse2/border.bin"
gMapLayout_DEWFORD_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/DewfordTownHouse2/map.bin"
	.globl gMapLayout_DEWFORD_TOWN_HOUSE2
gMapLayout_DEWFORD_TOWN_HOUSE2: @ 0x083FFC68
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_DEWFORD_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Border:
	.incbin "data/layouts/LavaridgeTown_HerbShop/border.bin"
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Blockdata:
	.incbin "data/layouts/LavaridgeTown_HerbShop/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN_HERB_SHOP
gMapLayout_LAVARIDGE_TOWN_HERB_SHOP: @ 0x083FFD38
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_HERB_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_GYM_1F_Border:
	.incbin "data/layouts/LavaridgeTown_Gym_1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_GYM_1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_Gym_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_1F
gMapLayout_LAVARIDGE_TOWN_GYM_1F: @ 0x083FFFE0
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Border:
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LAVARIDGE_TOWN_GYM_B1F
gMapLayout_LAVARIDGE_TOWN_GYM_B1F: @ 0x08400288
	.4byte 17  @ width
	.4byte 19  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_GYM_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Border:
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/border.bin"
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Blockdata:
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/map.bin"
	.globl gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F
gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F: @ 0x084003A4
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Border  @ border
	.4byte gMapLayout_LAVARIDGE_TOWN_POKEMON_CENTER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4003bc, 0x408
gMapLayout_LILYCOVE_CITY_HOUSE2_Border:
	.incbin "data/layouts/LilycoveCity_House2/border.bin"
gMapLayout_LILYCOVE_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/LilycoveCity_House2/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_HOUSE2
gMapLayout_LILYCOVE_CITY_HOUSE2: @ 0x0840084C
	.4byte 8  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x400864, 0x24
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Border:
	.incbin "data/layouts/VerdanturfTown_WandasHouse/border.bin"
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Blockdata:
	.incbin "data/layouts/VerdanturfTown_WandasHouse/map.bin"
	.globl gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE
gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE: @ 0x084009A0
	.4byte 17  @ width
	.4byte 8  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_WANDAS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Border:
	.incbin "data/layouts/PacifidlogTown_House1/border.bin"
gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Blockdata:
	.incbin "data/layouts/PacifidlogTown_House1/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE1
gMapLayout_PACIFIDLOG_TOWN_HOUSE1: @ 0x08400A74
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Border:
	.incbin "data/layouts/PacifidlogTown_House2/border.bin"
gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Blockdata:
	.incbin "data/layouts/PacifidlogTown_House2/map.bin"
	.globl gMapLayout_PACIFIDLOG_TOWN_HOUSE2
gMapLayout_PACIFIDLOG_TOWN_HOUSE2: @ 0x08400B48
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Border  @ border
	.4byte gMapLayout_PACIFIDLOG_TOWN_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_CITY_GYM_Border:
	.incbin "data/layouts/PetalburgCity_Gym/border.bin"
gMapLayout_PETALBURG_CITY_GYM_Blockdata:
	.incbin "data/layouts/PetalburgCity_Gym/map.bin"
	.globl gMapLayout_PETALBURG_CITY_GYM
gMapLayout_PETALBURG_CITY_GYM: @ 0x08401348
	.4byte 9  @ width
	.4byte 112  @ height
	.4byte gMapLayout_PETALBURG_CITY_GYM_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_PETALBURG_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_CITY_HOUSE2_Border:
	.incbin "data/layouts/PetalburgCityHouse2/border.bin"
gMapLayout_PETALBURG_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/PetalburgCityHouse2/map.bin"
	.globl gMapLayout_PETALBURG_CITY_HOUSE2
gMapLayout_PETALBURG_CITY_HOUSE2: @ 0x08401408
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_PETALBURG_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Border:
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/border.bin"
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Blockdata:
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F: @ 0x084016A0
	.4byte 21  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Border:
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/border.bin"
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Blockdata:
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F
gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F: @ 0x084018C0
	.4byte 17  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_STERNS_SHIPYARD_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4018d8, 0x48
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Border:
	.incbin "data/layouts/SlateportCity_PokemonFanClub/border.bin"
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Blockdata:
	.incbin "data/layouts/SlateportCity_PokemonFanClub/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB
gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB: @ 0x08401A5C
	.4byte 14  @ width
	.4byte 11  @ height
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_POKEMON_FAN_CLUB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_POKEMON_FAN_CLUB_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Border:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/border.bin"
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Blockdata:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F: @ 0x08401BE4
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Border:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_2F/border.bin"
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Blockdata:
	.incbin "data/layouts/SlateportCity_OceanicMuseum_2F/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F
gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F: @ 0x08401D6C
	.4byte 20  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_OCEANIC_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SLATEPORT_CITY_HARBOR_Border:
	.incbin "data/layouts/SlateportCityHarbor/border.bin"
gMapLayout_SLATEPORT_CITY_HARBOR_Blockdata:
	.incbin "data/layouts/SlateportCityHarbor/map.bin"
	.globl gMapLayout_SLATEPORT_CITY_HARBOR
gMapLayout_SLATEPORT_CITY_HARBOR: @ 0x0840205C
	.4byte 24  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR_Border  @ border
	.4byte gMapLayout_SLATEPORT_CITY_HARBOR_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_GYM_Border:
	.incbin "data/layouts/MauvilleCity_Gym/border.bin"
gMapLayout_MAUVILLE_CITY_GYM_Blockdata:
	.incbin "data/layouts/MauvilleCity_Gym/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_GYM
gMapLayout_MAUVILLE_CITY_GYM: @ 0x08402220
	.4byte 10  @ width
	.4byte 21  @ height
	.4byte gMapLayout_MAUVILLE_CITY_GYM_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Border:
	.incbin "data/layouts/MauvilleCity_BikeShop/border.bin"
gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Blockdata:
	.incbin "data/layouts/MauvilleCity_BikeShop/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_BIKE_SHOP
gMapLayout_MAUVILLE_CITY_BIKE_SHOP: @ 0x08402318
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_BIKE_SHOP_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY  @ secondaryTileset
gMapLayout_MAUVILLE_CITY_GAME_CORNER_Border:
	.incbin "data/layouts/MauvilleCity_GameCorner/border.bin"
gMapLayout_MAUVILLE_CITY_GAME_CORNER_Blockdata:
	.incbin "data/layouts/MauvilleCity_GameCorner/map.bin"
	.globl gMapLayout_MAUVILLE_CITY_GAME_CORNER
gMapLayout_MAUVILLE_CITY_GAME_CORNER: @ 0x0840251C
	.4byte 22  @ width
	.4byte 11  @ height
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER_Border  @ border
	.4byte gMapLayout_MAUVILLE_CITY_GAME_CORNER_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_GAME_CORNER_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_1F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F: @ 0x08402694
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_2F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F: @ 0x0840280C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_GYM_Border:
	.incbin "data/layouts/RustboroCity_Gym/border.bin"
gMapLayout_RUSTBORO_CITY_GYM_Blockdata:
	.incbin "data/layouts/RustboroCity_Gym/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_GYM
gMapLayout_RUSTBORO_CITY_GYM: @ 0x084029E4
	.4byte 11  @ width
	.4byte 20  @ height
	.4byte gMapLayout_RUSTBORO_CITY_GYM_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Border:
	.incbin "data/layouts/RustboroCity_PokemonSchool/border.bin"
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Blockdata:
	.incbin "data/layouts/RustboroCity_PokemonSchool/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL
gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL: @ 0x08402B0C
	.4byte 12  @ width
	.4byte 11  @ height
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_POKEMON_SCHOOL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_POKEMON_SCHOOL_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_HOUSE2_Border:
	.incbin "data/layouts/RustboroCityHouse2/border.bin"
gMapLayout_RUSTBORO_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/RustboroCityHouse2/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_HOUSE2
gMapLayout_RUSTBORO_CITY_HOUSE2: @ 0x08402C04
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_HOUSE1_Border:
	.incbin "data/layouts/RustboroCity_House1/border.bin"
gMapLayout_RUSTBORO_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/RustboroCity_House1/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_HOUSE1
gMapLayout_RUSTBORO_CITY_HOUSE1: @ 0x08402CF4
	.4byte 13  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Border:
	.incbin "data/layouts/RustboroCity_CuttersHouse/border.bin"
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Blockdata:
	.incbin "data/layouts/RustboroCity_CuttersHouse/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE
gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE: @ 0x08402DDC
	.4byte 11  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_CUTTERS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_HOUSE1_Border:
	.incbin "data/layouts/FortreeCity_House1/border.bin"
gMapLayout_FORTREE_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/FortreeCity_House1/map.bin"
	.globl gMapLayout_FORTREE_CITY_HOUSE1
gMapLayout_FORTREE_CITY_HOUSE1: @ 0x08402E5C
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_GYM_Border:
	.incbin "data/layouts/FortreeCity_Gym/border.bin"
gMapLayout_FORTREE_CITY_GYM_Blockdata:
	.incbin "data/layouts/FortreeCity_Gym/map.bin"
	.globl gMapLayout_FORTREE_CITY_GYM
gMapLayout_FORTREE_CITY_GYM: @ 0x08403264
	.4byte 20  @ width
	.4byte 25  @ height
	.4byte gMapLayout_FORTREE_CITY_GYM_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FORTREE_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_FORTREE_CITY_HOUSE2_Border:
	.incbin "data/layouts/FortreeCity_House2/border.bin"
gMapLayout_FORTREE_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/FortreeCity_House2/map.bin"
	.globl gMapLayout_FORTREE_CITY_HOUSE2
gMapLayout_FORTREE_CITY_HOUSE2: @ 0x084032E4
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Border:
	.incbin "data/layouts/Route104_MrBrineysHouse/border.bin"
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Blockdata:
	.incbin "data/layouts/Route104_MrBrineysHouse/map.bin"
	.globl gMapLayout_ROUTE104_MR_BRINEYS_HOUSE
gMapLayout_ROUTE104_MR_BRINEYS_HOUSE: @ 0x084033DC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE104_MR_BRINEYS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Border:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/border.bin"
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F: @ 0x08403648
	.4byte 21  @ width
	.4byte 14  @ height
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Border:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_2F/border.bin"
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F
gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F: @ 0x084038A4
	.4byte 22  @ width
	.4byte 13  @ height
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_LILYCOVE_MUSEUM_1F_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Border:
	.incbin "data/layouts/LilycoveCity_ContestLobby/border.bin"
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Blockdata:
	.incbin "data/layouts/LilycoveCity_ContestLobby/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY
gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY: @ 0x08403BAC
	.4byte 31  @ width
	.4byte 12  @ height
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_LOBBY_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Border:
	.incbin "data/layouts/LilycoveCity_ContestHall/border.bin"
gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Blockdata:
	.incbin "data/layouts/LilycoveCity_ContestHall/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_LILYCOVE_CITY_CONTEST_HALL
gMapLayout_LILYCOVE_CITY_CONTEST_HALL: @ 0x084048F4
	.4byte 51  @ width
	.4byte 33  @ height
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_CONTEST_HALL_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_CONTEST_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Border:
	.incbin "data/layouts/LilycoveCity_PokemonTrainerFanClub/border.bin"
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Blockdata:
	.incbin "data/layouts/LilycoveCity_PokemonTrainerFanClub/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB
gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB: @ 0x08404A64
	.4byte 12  @ width
	.4byte 14  @ height
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_POKEMON_TRAINER_FAN_CLUB_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_GYM_Border:
	.incbin "data/layouts/MossdeepCity_Gym/border.bin"
gMapLayout_MOSSDEEP_CITY_GYM_Blockdata:
	.incbin "data/layouts/MossdeepCity_Gym/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GYM
gMapLayout_MOSSDEEP_CITY_GYM: @ 0x084051D4
	.4byte 26  @ width
	.4byte 36  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GYM_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GYM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GYM_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Border:
	.incbin "data/layouts/SootopolisCity_Gym_1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_Gym_1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_1F
gMapLayout_SOOTOPOLIS_CITY_GYM_1F: @ 0x08405568
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Border:
	.incbin "data/layouts/SootopolisCity_Gym_B1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_Gym_B1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_GYM_B1F
gMapLayout_SOOTOPOLIS_CITY_GYM_B1F: @ 0x084058FC
	.4byte 17  @ width
	.4byte 26  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_GYM_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_GYM_1F_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM
gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM: @ 0x08405A88
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_SIDNEYS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_PhoebesRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_PhoebesRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM
gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM: @ 0x08405C14
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_PHOEBES_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM
gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM: @ 0x08405DA0
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_GLACIAS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM
gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM: @ 0x08405F2C
	.4byte 13  @ width
	.4byte 14  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_DRAKES_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Border:
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/border.bin"
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Blockdata:
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM
gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM: @ 0x084060A0
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_CHAMPIONS_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL1_Border:
	.incbin "data/layouts/EverGrandeCityHall1/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL1_Blockdata:
	.incbin "data/layouts/EverGrandeCityHall1/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_HALL1
gMapLayout_EVER_GRANDE_CITY_HALL1: @ 0x084061E0
	.4byte 11  @ width
	.4byte 13  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Border:
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/border.bin"
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Blockdata:
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP
gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP: @ 0x08406310
	.4byte 15  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Border  @ border
	.4byte gMapLayout_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE104_PRETTY_PETAL_FLOWER_SHOP_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE112_CABLE_CAR_STATION_Border:
	.incbin "data/layouts/Route112CableCarStation/border.bin"
gMapLayout_ROUTE112_CABLE_CAR_STATION_Blockdata:
	.incbin "data/layouts/Route112CableCarStation/map.bin"
	.globl gMapLayout_ROUTE112_CABLE_CAR_STATION
gMapLayout_ROUTE112_CABLE_CAR_STATION: @ 0x08406468
	.4byte 13  @ width
	.4byte 12  @ height
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION_Border  @ border
	.4byte gMapLayout_ROUTE112_CABLE_CAR_STATION_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Border:
	.incbin "data/layouts/Route114_FossilManiacsHouse/border.bin"
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Blockdata:
	.incbin "data/layouts/Route114_FossilManiacsHouse/map.bin"
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE
gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE: @ 0x08406528
	.4byte 10  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Border:
	.incbin "data/layouts/Route114_FossilManiacsTunnel/border.bin"
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Blockdata:
	.incbin "data/layouts/Route114_FossilManiacsTunnel/map.bin"
	.globl gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL
gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL: @ 0x084067EC
	.4byte 13  @ width
	.4byte 26  @ height
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Border  @ border
	.4byte gMapLayout_ROUTE114_FOSSIL_MANIACS_TUNNEL_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE114_LANETTES_HOUSE_Border:
	.incbin "data/layouts/Route114_LanettesHouse/border.bin"
gMapLayout_ROUTE114_LANETTES_HOUSE_Blockdata:
	.incbin "data/layouts/Route114_LanettesHouse/map.bin"
	.globl gMapLayout_ROUTE114_LANETTES_HOUSE
gMapLayout_ROUTE114_LANETTES_HOUSE: @ 0x084068BC
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE114_LANETTES_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Border:
	.incbin "data/layouts/Route116_TunnelersRestHouse/border.bin"
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Blockdata:
	.incbin "data/layouts/Route116_TunnelersRestHouse/map.bin"
	.globl gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE
gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE: @ 0x08406990
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Border  @ border
	.4byte gMapLayout_ROUTE116_TUNNELERS_REST_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE117_POKEMON_DAY_CARE_Border:
	.incbin "data/layouts/Route117_PokemonDayCare/border.bin"
gMapLayout_ROUTE117_POKEMON_DAY_CARE_Blockdata:
	.incbin "data/layouts/Route117_PokemonDayCare/map.bin"
	.globl gMapLayout_ROUTE117_POKEMON_DAY_CARE
gMapLayout_ROUTE117_POKEMON_DAY_CARE: @ 0x08406A88
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE_Border  @ border
	.4byte gMapLayout_ROUTE117_POKEMON_DAY_CARE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_ROUTE117_POKEMON_DAY_CARE_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Border:
	.incbin "data/layouts/Route121_SafariZoneEntrance/border.bin"
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Blockdata:
	.incbin "data/layouts/Route121_SafariZoneEntrance/map.bin"
	.globl gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE
gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE: @ 0x08406CA0
	.4byte 18  @ width
	.4byte 14  @ height
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Border  @ border
	.4byte gMapLayout_ROUTE121_SAFARI_ZONE_ENTRANCE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_1F_1R_Border:
	.incbin "data/layouts/MeteorFalls_1F_1R/border.bin"
gMapLayout_METEOR_FALLS_1F_1R_Blockdata:
	.incbin "data/layouts/MeteorFalls_1F_1R/map.bin"
	.globl gMapLayout_METEOR_FALLS_1F_1R
gMapLayout_METEOR_FALLS_1F_1R: @ 0x08407698
	.4byte 30  @ width
	.4byte 42  @ height
	.4byte gMapLayout_METEOR_FALLS_1F_1R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_1F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_1F_2R_Border:
	.incbin "data/layouts/MeteorFalls_1F_2R/border.bin"
gMapLayout_METEOR_FALLS_1F_2R_Blockdata:
	.incbin "data/layouts/MeteorFalls_1F_2R/map.bin"
	.globl gMapLayout_METEOR_FALLS_1F_2R
gMapLayout_METEOR_FALLS_1F_2R: @ 0x08407E38
	.4byte 30  @ width
	.4byte 32  @ height
	.4byte gMapLayout_METEOR_FALLS_1F_2R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_1F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_B1F_1R_Border:
	.incbin "data/layouts/MeteorFalls_B1F_1R/border.bin"
gMapLayout_METEOR_FALLS_B1F_1R_Blockdata:
	.incbin "data/layouts/MeteorFalls_B1F_1R/map.bin"
	.globl gMapLayout_METEOR_FALLS_B1F_1R
gMapLayout_METEOR_FALLS_B1F_1R: @ 0x084086F4
	.4byte 29  @ width
	.4byte 38  @ height
	.4byte gMapLayout_METEOR_FALLS_B1F_1R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_B1F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_METEOR_FALLS_B1F_2R_Border:
	.incbin "data/layouts/MeteorFalls_B1F_2R/border.bin"
gMapLayout_METEOR_FALLS_B1F_2R_Blockdata:
	.incbin "data/layouts/MeteorFalls_B1F_2R/map.bin"
	.globl gMapLayout_METEOR_FALLS_B1F_2R
gMapLayout_METEOR_FALLS_B1F_2R: @ 0x084088A0
	.4byte 11  @ width
	.4byte 18  @ height
	.4byte gMapLayout_METEOR_FALLS_B1F_2R_Border  @ border
	.4byte gMapLayout_METEOR_FALLS_B1F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_METEOR_FALLS_1F_1R_SECONDARY  @ secondaryTileset
gMapLayout_RUSTURF_TUNNEL_Border:
	.incbin "data/layouts/RusturfTunnel/border.bin"
gMapLayout_RUSTURF_TUNNEL_Blockdata:
	.incbin "data/layouts/RusturfTunnel/map.bin"
	.globl gMapLayout_RUSTURF_TUNNEL
gMapLayout_RUSTURF_TUNNEL: @ 0x08408F80
	.4byte 36  @ width
	.4byte 24  @ height
	.4byte gMapLayout_RUSTURF_TUNNEL_Border  @ border
	.4byte gMapLayout_RUSTURF_TUNNEL_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTURF_TUNNEL_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Border:
	.incbin "data/layouts/Underwater_SootopolisCity/border.bin"
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Blockdata:
	.incbin "data/layouts/Underwater_SootopolisCity/map.bin"
	.globl gMapLayout_UNDERWATER_SOOTOPOLIS_CITY
gMapLayout_UNDERWATER_SOOTOPOLIS_CITY: @ 0x08409130
	.4byte 20  @ width
	.4byte 10  @ height
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Border  @ border
	.4byte gMapLayout_UNDERWATER_SOOTOPOLIS_CITY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_DESERT_RUINS_Border:
	.incbin "data/layouts/DesertRuins/border.bin"
gMapLayout_DESERT_RUINS_Blockdata:
	.incbin "data/layouts/DesertRuins/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_DESERT_RUINS
gMapLayout_DESERT_RUINS: @ 0x084095B4
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte gMapLayout_DESERT_RUINS_Border  @ border
	.4byte gMapLayout_DESERT_RUINS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_1F_Border:
	.incbin "data/layouts/GraniteCave_1F/border.bin"
gMapLayout_GRANITE_CAVE_1F_Blockdata:
	.incbin "data/layouts/GraniteCave_1F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_1F
gMapLayout_GRANITE_CAVE_1F: @ 0x08409AC0
	.4byte 42  @ width
	.4byte 15  @ height
	.4byte gMapLayout_GRANITE_CAVE_1F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_B1F_Border:
	.incbin "data/layouts/GraniteCave_B1F/border.bin"
gMapLayout_GRANITE_CAVE_B1F_Blockdata:
	.incbin "data/layouts/GraniteCave_B1F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_B1F
gMapLayout_GRANITE_CAVE_B1F: @ 0x0840A160
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte gMapLayout_GRANITE_CAVE_B1F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_GRANITE_CAVE_B2F_Border:
	.incbin "data/layouts/GraniteCave_B2F/border.bin"
gMapLayout_GRANITE_CAVE_B2F_Blockdata:
	.incbin "data/layouts/GraniteCave_B2F/map.bin"
	.globl gMapLayout_GRANITE_CAVE_B2F
gMapLayout_GRANITE_CAVE_B2F: @ 0x0840A800
	.4byte 32  @ width
	.4byte 26  @ height
	.4byte gMapLayout_GRANITE_CAVE_B2F_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_B2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_PETALBURG_WOODS_Border:
	.incbin "data/layouts/PetalburgWoods/border.bin"
gMapLayout_PETALBURG_WOODS_Blockdata:
	.incbin "data/layouts/PetalburgWoods/map.bin"
	.globl gMapLayout_PETALBURG_WOODS
gMapLayout_PETALBURG_WOODS: @ 0x0840B8A0
	.4byte 48  @ width
	.4byte 44  @ height
	.4byte gMapLayout_PETALBURG_WOODS_Border  @ border
	.4byte gMapLayout_PETALBURG_WOODS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_RUSTBORO_CITY_SECONDARY  @ secondaryTileset
gMapLayout_MT_CHIMNEY_Border:
	.incbin "data/layouts/MtChimney/border.bin"
gMapLayout_MT_CHIMNEY_Blockdata:
	.incbin "data/layouts/MtChimney/map.bin"
	.globl gMapLayout_MT_CHIMNEY
gMapLayout_MT_CHIMNEY: @ 0x0840C770
	.4byte 40  @ width
	.4byte 47  @ height
	.4byte gMapLayout_MT_CHIMNEY_Border  @ border
	.4byte gMapLayout_MT_CHIMNEY_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_1F_Border:
	.incbin "data/layouts/MtPyre_1F/border.bin"
gMapLayout_MT_PYRE_1F_Blockdata:
	.incbin "data/layouts/MtPyre_1F/map.bin"
	.globl gMapLayout_MT_PYRE_1F
gMapLayout_MT_PYRE_1F: @ 0x0840CAD4
	.4byte 22  @ width
	.4byte 19  @ height
	.4byte gMapLayout_MT_PYRE_1F_Border  @ border
	.4byte gMapLayout_MT_PYRE_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_2F_Border:
	.incbin "data/layouts/MtPyre_2F/border.bin"
gMapLayout_MT_PYRE_2F_Blockdata:
	.incbin "data/layouts/MtPyre_2F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_2F
gMapLayout_MT_PYRE_2F: @ 0x0840CC48
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_2F_Border  @ border
	.4byte gMapLayout_MT_PYRE_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_3F_Border:
	.incbin "data/layouts/MtPyre_3F/border.bin"
gMapLayout_MT_PYRE_3F_Blockdata:
	.incbin "data/layouts/MtPyre_3F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_3F
gMapLayout_MT_PYRE_3F: @ 0x0840CDBC
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_3F_Border  @ border
	.4byte gMapLayout_MT_PYRE_3F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_4F_Border:
	.incbin "data/layouts/MtPyre_4F/border.bin"
gMapLayout_MT_PYRE_4F_Blockdata:
	.incbin "data/layouts/MtPyre_4F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_4F
gMapLayout_MT_PYRE_4F: @ 0x0840CF30
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_4F_Border  @ border
	.4byte gMapLayout_MT_PYRE_4F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_5F_Border:
	.incbin "data/layouts/MtPyre_5F/border.bin"
gMapLayout_MT_PYRE_5F_Blockdata:
	.incbin "data/layouts/MtPyre_5F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_5F
gMapLayout_MT_PYRE_5F: @ 0x0840D0A4
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_5F_Border  @ border
	.4byte gMapLayout_MT_PYRE_5F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_6F_Border:
	.incbin "data/layouts/MtPyre_6F/border.bin"
gMapLayout_MT_PYRE_6F_Blockdata:
	.incbin "data/layouts/MtPyre_6F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_MT_PYRE_6F
gMapLayout_MT_PYRE_6F: @ 0x0840D218
	.4byte 13  @ width
	.4byte 13  @ height
	.4byte gMapLayout_MT_PYRE_6F_Border  @ border
	.4byte gMapLayout_MT_PYRE_6F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_1F_Border:
	.incbin "data/layouts/AquaHideout_1F/border.bin"
gMapLayout_AQUA_HIDEOUT_1F_Blockdata:
	.incbin "data/layouts/AquaHideout_1F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_1F
gMapLayout_AQUA_HIDEOUT_1F: @ 0x0840D8C8
	.4byte 28  @ width
	.4byte 30  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_1F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_B1F_Border:
	.incbin "data/layouts/AquaHideout_B1F/border.bin"
gMapLayout_AQUA_HIDEOUT_B1F_Blockdata:
	.incbin "data/layouts/AquaHideout_B1F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_B1F
gMapLayout_AQUA_HIDEOUT_B1F: @ 0x0840E278
	.4byte 51  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_B1F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_B2F_Border:
	.incbin "data/layouts/AquaHideout_B2F/border.bin"
gMapLayout_AQUA_HIDEOUT_B2F_Blockdata:
	.incbin "data/layouts/AquaHideout_B2F/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_B2F
gMapLayout_AQUA_HIDEOUT_B2F: @ 0x0840E8F8
	.4byte 34  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_B2F_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_B2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Border:
	.incbin "data/layouts/Underwater_SeafloorCavern/border.bin"
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Blockdata:
	.incbin "data/layouts/Underwater_SeafloorCavern/map.bin"
	.globl gMapLayout_UNDERWATER_SEAFLOOR_CAVERN
gMapLayout_UNDERWATER_SEAFLOOR_CAVERN: @ 0x0840EA14
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Border  @ border
	.4byte gMapLayout_UNDERWATER_SEAFLOOR_CAVERN_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Border:
	.incbin "data/layouts/SeafloorCavern_Entrance/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Entrance/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ENTRANCE
gMapLayout_SEAFLOOR_CAVERN_ENTRANCE: @ 0x0840ED54
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ENTRANCE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM1_Border:
	.incbin "data/layouts/SeafloorCavern_Room1/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM1_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room1/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM1
gMapLayout_SEAFLOOR_CAVERN_ROOM1: @ 0x0840F0BC
	.4byte 20  @ width
	.4byte 21  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM1_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM2_Border:
	.incbin "data/layouts/SeafloorCavern_Room2/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM2_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room2/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM2
gMapLayout_SEAFLOOR_CAVERN_ROOM2: @ 0x0840F28C
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM2_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM3_Border:
	.incbin "data/layouts/SeafloorCavern_Room3/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM3_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room3/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM3
gMapLayout_SEAFLOOR_CAVERN_ROOM3: @ 0x0840F4CC
	.4byte 16  @ width
	.4byte 17  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM3_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM4_Border:
	.incbin "data/layouts/SeafloorCavern_Room4/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM4_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room4/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM4
gMapLayout_SEAFLOOR_CAVERN_ROOM4: @ 0x0840F798
	.4byte 18  @ width
	.4byte 19  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM4_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM5_Border:
	.incbin "data/layouts/SeafloorCavern_Room5/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM5_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room5/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM5
gMapLayout_SEAFLOOR_CAVERN_ROOM5: @ 0x0840FAD8
	.4byte 20  @ width
	.4byte 20  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM5_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM5_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM6_Border:
	.incbin "data/layouts/SeafloorCavern_Room6/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM6_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room6/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM6
gMapLayout_SEAFLOOR_CAVERN_ROOM6: @ 0x0840FF48
	.4byte 24  @ width
	.4byte 23  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM6_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM6_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM7_Border:
	.incbin "data/layouts/SeafloorCavern_Room7/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM7_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room7/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM7
gMapLayout_SEAFLOOR_CAVERN_ROOM7: @ 0x084103E8
	.4byte 23  @ width
	.4byte 25  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM7_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM7_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM8_Border:
	.incbin "data/layouts/SeafloorCavern_Room8/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM8_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room8/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM8
gMapLayout_SEAFLOOR_CAVERN_ROOM8: @ 0x0841053C
	.4byte 11  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM8_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM8_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SEAFLOOR_CAVERN_ROOM9_Border:
	.incbin "data/layouts/SeafloorCavern_Room9/border.bin"
gMapLayout_SEAFLOOR_CAVERN_ROOM9_Blockdata:
	.incbin "data/layouts/SeafloorCavern_Room9/map.bin"
	.globl gMapLayout_SEAFLOOR_CAVERN_ROOM9
gMapLayout_SEAFLOOR_CAVERN_ROOM9: @ 0x08410F10
	.4byte 27  @ width
	.4byte 46  @ height
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM9_Border  @ border
	.4byte gMapLayout_SEAFLOOR_CAVERN_ROOM9_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_ENTRANCE_Border:
	.incbin "data/layouts/CaveOfOrigin_Entrance/border.bin"
gMapLayout_CAVE_OF_ORIGIN_ENTRANCE_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_Entrance/map.bin"
	.globl gMapLayout_CAVE_OF_ORIGIN_ENTRANCE
gMapLayout_CAVE_OF_ORIGIN_ENTRANCE: @ 0x0841130C
	.4byte 19  @ width
	.4byte 26  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_ENTRANCE_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_ENTRANCE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_1F_Border:
	.incbin "data/layouts/CaveOfOrigin_1F/border.bin"
gMapLayout_CAVE_OF_ORIGIN_1F_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_CAVE_OF_ORIGIN_1F
gMapLayout_CAVE_OF_ORIGIN_1F: @ 0x08411750
	.4byte 23  @ width
	.4byte 23  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_1F_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1_Border:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap1/border.bin"
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap1/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1: @ 0x08411B94
	.4byte 23  @ width
	.4byte 23  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP1_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2_Border:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap2/border.bin"
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap2/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2: @ 0x08411F28
	.4byte 21  @ width
	.4byte 21  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP2_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3_Border:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap3/border.bin"
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap3/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3
gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3: @ 0x08412268
	.4byte 19  @ width
	.4byte 21  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_UNUSED_RUBY_SAPPHIRE_MAP3_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_CAVE_OF_ORIGIN_B1F_Border:
	.incbin "data/layouts/CaveOfOrigin_B1F/border.bin"
gMapLayout_CAVE_OF_ORIGIN_B1F_Blockdata:
	.incbin "data/layouts/CaveOfOrigin_B1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_CAVE_OF_ORIGIN_B1F
gMapLayout_CAVE_OF_ORIGIN_B1F: @ 0x0841255C
	.4byte 19  @ width
	.4byte 19  @ height
	.4byte gMapLayout_CAVE_OF_ORIGIN_B1F_Border  @ border
	.4byte gMapLayout_CAVE_OF_ORIGIN_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_VICTORY_ROAD_1F_Border:
	.incbin "data/layouts/VictoryRoad_1F/border.bin"
gMapLayout_VICTORY_ROAD_1F_Blockdata:
	.incbin "data/layouts/VictoryRoad_1F/map.bin"
	.globl gMapLayout_VICTORY_ROAD_1F
gMapLayout_VICTORY_ROAD_1F: @ 0x084135A8
	.4byte 46  @ width
	.4byte 45  @ height
	.4byte gMapLayout_VICTORY_ROAD_1F_Border  @ border
	.4byte gMapLayout_VICTORY_ROAD_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM_Border:
	.incbin "data/layouts/ShoalCave_LowTideEntranceRoom/border.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_LowTideEntranceRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM
gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM: @ 0x08413F5C
	.4byte 35  @ width
	.4byte 35  @ height
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_Border:
	.incbin "data/layouts/ShoalCave_LowTideInnerRoom/border.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_LowTideInnerRoom/map.bin"
	.globl gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM: @ 0x08414D24
	.4byte 46  @ width
	.4byte 38  @ height
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_INNER_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM_Border:
	.incbin "data/layouts/ShoalCave_LowTideStairsRoom/border.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_LowTideStairsRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM
gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM: @ 0x08414FBC
	.4byte 21  @ width
	.4byte 15  @ height
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM_Border:
	.incbin "data/layouts/ShoalCave_LowTideLowerRoom/border.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_LowTideLowerRoom/map.bin"
	.globl gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM
gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM: @ 0x08415340
	.4byte 31  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM_Border:
	.incbin "data/layouts/ShoalCave_HighTideEntranceRoom/border.bin"
gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_HighTideEntranceRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM
gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM: @ 0x08415CF4
	.4byte 35  @ width
	.4byte 35  @ height
	.4byte gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_HIGH_TIDE_ENTRANCE_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM_Border:
	.incbin "data/layouts/ShoalCave_HighTideInnerRoom/border.bin"
gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_HighTideInnerRoom/map.bin"
	.globl gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM
gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM: @ 0x08416ABC
	.4byte 46  @ width
	.4byte 38  @ height
	.4byte gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x416AD4, 0x1F8
gMapLayout_NEW_MAUVILLE_ENTRANCE_Border:
	.incbin "data/layouts/NewMauville_Entrance/border.bin"
gMapLayout_NEW_MAUVILLE_ENTRANCE_Blockdata:
	.incbin "data/layouts/NewMauville_Entrance/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_NEW_MAUVILLE_ENTRANCE
gMapLayout_NEW_MAUVILLE_ENTRANCE: @ 0x08416D78
	.4byte 9  @ width
	.4byte 9  @ height
	.4byte gMapLayout_NEW_MAUVILLE_ENTRANCE_Border  @ border
	.4byte gMapLayout_NEW_MAUVILLE_ENTRANCE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_NEW_MAUVILLE_INSIDE_Border:
	.incbin "data/layouts/NewMauville_Inside/border.bin"
gMapLayout_NEW_MAUVILLE_INSIDE_Blockdata:
	.incbin "data/layouts/NewMauville_Inside/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_NEW_MAUVILLE_INSIDE
gMapLayout_NEW_MAUVILLE_INSIDE: @ 0x08417ABC
	.4byte 41  @ width
	.4byte 41  @ height
	.4byte gMapLayout_NEW_MAUVILLE_INSIDE_Border  @ border
	.4byte gMapLayout_NEW_MAUVILLE_INSIDE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_MAUVILLE_CITY_BIKE_SHOP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_DECK_Border:
	.incbin "data/layouts/AbandonedShip_Deck/border.bin"
gMapLayout_ABANDONED_SHIP_DECK_Blockdata:
	.incbin "data/layouts/AbandonedShip_Deck/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ABANDONED_SHIP_DECK
gMapLayout_ABANDONED_SHIP_DECK: @ 0x08417EA4
	.4byte 23  @ width
	.4byte 21  @ height
	.4byte gMapLayout_ABANDONED_SHIP_DECK_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_DECK_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_CORRIDORS_1F_Border:
	.incbin "data/layouts/AbandonedShip_Corridors_1F/border.bin"
gMapLayout_ABANDONED_SHIP_CORRIDORS_1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Corridors_1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_CORRIDORS_1F
gMapLayout_ABANDONED_SHIP_CORRIDORS_1F: @ 0x08418074
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte gMapLayout_ABANDONED_SHIP_CORRIDORS_1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_CORRIDORS_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_ROOMS_1F_Border:
	.incbin "data/layouts/AbandonedShip_Rooms_1F/border.bin"
gMapLayout_ABANDONED_SHIP_ROOMS_1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Rooms_1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_ROOMS_1F
gMapLayout_ABANDONED_SHIP_ROOMS_1F: @ 0x084182F8
	.4byte 18  @ width
	.4byte 17  @ height
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS_1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F_Border:
	.incbin "data/layouts/AbandonedShip_Corridors_B1F/border.bin"
gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Corridors_B1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F
gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F: @ 0x0841841C
	.4byte 13  @ width
	.4byte 10  @ height
	.4byte gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_CORRIDORS_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_ROOMS_B1F_Border:
	.incbin "data/layouts/AbandonedShip_Rooms_B1F/border.bin"
gMapLayout_ABANDONED_SHIP_ROOMS_B1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Rooms_B1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_ROOMS_B1F
gMapLayout_ABANDONED_SHIP_ROOMS_B1F: @ 0x084185EC
	.4byte 27  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS_B1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_ROOMS2_B1F_Border:
	.incbin "data/layouts/AbandonedShip_Rooms2_B1F/border.bin"
gMapLayout_ABANDONED_SHIP_ROOMS2_B1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Rooms2_B1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_ROOMS2_B1F
gMapLayout_ABANDONED_SHIP_ROOMS2_B1F: @ 0x0841872C
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS2_B1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS2_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_UNDERWATER1_Border:
	.incbin "data/layouts/AbandonedShip_Underwater1/border.bin"
gMapLayout_ABANDONED_SHIP_UNDERWATER1_Blockdata:
	.incbin "data/layouts/AbandonedShip_Underwater1/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_UNDERWATER1
gMapLayout_ABANDONED_SHIP_UNDERWATER1: @ 0x084187CC
	.4byte 8  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ABANDONED_SHIP_UNDERWATER1_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_UNDERWATER1_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_ROOM_B1F_Border:
	.incbin "data/layouts/AbandonedShip_Room_B1F/border.bin"
gMapLayout_ABANDONED_SHIP_ROOM_B1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Room_B1F/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_ROOM_B1F
gMapLayout_ABANDONED_SHIP_ROOM_B1F: @ 0x0841887C
	.4byte 9  @ width
	.4byte 8  @ height
	.4byte gMapLayout_ABANDONED_SHIP_ROOM_B1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_ROOM_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_ROOMS2_1F_Border:
	.incbin "data/layouts/AbandonedShip_Rooms2_1F/border.bin"
gMapLayout_ABANDONED_SHIP_ROOMS2_1F_Blockdata:
	.incbin "data/layouts/AbandonedShip_Rooms2_1F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ABANDONED_SHIP_ROOMS2_1F
gMapLayout_ABANDONED_SHIP_ROOMS2_1F: @ 0x084189D0
	.4byte 9  @ width
	.4byte 17  @ height
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS2_1F_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_ROOMS2_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE_Border:
	.incbin "data/layouts/AbandonedShip_CaptainsOffice/border.bin"
gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE_Blockdata:
	.incbin "data/layouts/AbandonedShip_CaptainsOffice/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE
gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE: @ 0x08418A70
	.4byte 9  @ width
	.4byte 7  @ height
	.4byte gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_CAPTAINS_OFFICE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_UNDERWATER2_Border:
	.incbin "data/layouts/AbandonedShip_Underwater2/border.bin"
gMapLayout_ABANDONED_SHIP_UNDERWATER2_Blockdata:
	.incbin "data/layouts/AbandonedShip_Underwater2/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ABANDONED_SHIP_UNDERWATER2
gMapLayout_ABANDONED_SHIP_UNDERWATER2: @ 0x08418BB8
	.4byte 21  @ width
	.4byte 7  @ height
	.4byte gMapLayout_ABANDONED_SHIP_UNDERWATER2_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_UNDERWATER2_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x418BD0, 0x842C
gMapLayout_FORTREE_CITY_DECORATION_SHOP_Border:
	.incbin "data/layouts/FortreeCity_DecorationShop/border.bin"
gMapLayout_FORTREE_CITY_DECORATION_SHOP_Blockdata:
	.incbin "data/layouts/FortreeCity_DecorationShop/map.bin"
	.globl gMapLayout_FORTREE_CITY_DECORATION_SHOP
gMapLayout_FORTREE_CITY_DECORATION_SHOP: @ 0x08421064
	.4byte 8  @ width
	.4byte 6  @ height
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP_Border  @ border
	.4byte gMapLayout_FORTREE_CITY_DECORATION_SHOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42107c, 0xd4
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_1F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F: @ 0x08421278
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F: @ 0x084213B8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_3F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_3F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F: @ 0x084214F8
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_4F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_4F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F: @ 0x08421638
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_4F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_5F/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStore_5F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F: @ 0x08421778
	.4byte 18  @ width
	.4byte 8  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_5F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP: @ 0x08421948
	.4byte 18  @ width
	.4byte 12  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ROOFTOP_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_MART_SECONDARY  @ secondaryTileset
gMapLayout_ROUTE130_Border:
	.incbin "data/layouts/Route130/border.bin"
gMapLayout_ROUTE130_Blockdata:
	.incbin "data/layouts/Route130/map.bin"
	.globl gMapLayout_ROUTE130
gMapLayout_ROUTE130: @ 0x08423268
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_ROUTE130_Border  @ border
	.4byte gMapLayout_ROUTE130_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x423280, 0x23bc
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Border:
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/border.bin"
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Blockdata:
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F
gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F: @ 0x0842579C
	.4byte 19  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_DEVON_CORP_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Border:
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/border.bin"
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Blockdata:
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F
gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F: @ 0x08425984
	.4byte 19  @ width
	.4byte 12  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_POKEMON_LEAGUE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_POKEMON_CENTER_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42599c, 0x400
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Border:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/border.bin"
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Blockdata:
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR
gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR: @ 0x08425DE0
	.4byte 5  @ width
	.4byte 6  @ height
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR_SECONDARY  @ secondaryTileset
Underwater_Route124_Layout_Border::
	.incbin "data/layouts/Underwater_Route124/border.bin"
Underwater_Route124_Layout_Blockdata::
	.incbin "data/layouts/Underwater_Route124/map.bin"
Underwater_Route124_Layout:: @ 0x08429000
	.4byte 80  @ width
	.4byte 80  @ height
	.4byte Underwater_Route124_Layout_Border  @ border
	.4byte Underwater_Route124_Layout_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Border:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_1F/border.bin"
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F: @ 0x08429160
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Border:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/border.bin"
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Blockdata:
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F
gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F: @ 0x084292C0
	.4byte 16  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_SPACE_CENTER_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4292D8, 0x900
gMapLayout_ISLAND_CAVE_Border:
	.incbin "data/layouts/IslandCave/border.bin"
gMapLayout_ISLAND_CAVE_Blockdata:
	.incbin "data/layouts/IslandCave/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ISLAND_CAVE
gMapLayout_ISLAND_CAVE: @ 0x0842A044
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte gMapLayout_ISLAND_CAVE_Border  @ border
	.4byte gMapLayout_ISLAND_CAVE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_ANCIENT_TOMB_Border:
	.incbin "data/layouts/AncientTomb/border.bin"
gMapLayout_ANCIENT_TOMB_Blockdata:
	.incbin "data/layouts/AncientTomb/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ANCIENT_TOMB
gMapLayout_ANCIENT_TOMB: @ 0x0842A4C8
	.4byte 17  @ width
	.4byte 33  @ height
	.4byte gMapLayout_ANCIENT_TOMB_Border  @ border
	.4byte gMapLayout_ANCIENT_TOMB_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE134_Border:
	.incbin "data/layouts/Underwater_Route134/border.bin"
gMapLayout_UNDERWATER_ROUTE134_Blockdata:
	.incbin "data/layouts/Underwater_Route134/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE134
gMapLayout_UNDERWATER_ROUTE134: @ 0x0842A650
	.4byte 18  @ width
	.4byte 10  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE134_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE134_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_SEALED_CHAMBER_Border:
	.incbin "data/layouts/Underwater_SealedChamber/border.bin"
gMapLayout_UNDERWATER_SEALED_CHAMBER_Blockdata:
	.incbin "data/layouts/Underwater_SealedChamber/map.bin"
	.globl gMapLayout_UNDERWATER_SEALED_CHAMBER
gMapLayout_UNDERWATER_SEALED_CHAMBER: @ 0x0842AEB0
	.4byte 22  @ width
	.4byte 48  @ height
	.4byte gMapLayout_UNDERWATER_SEALED_CHAMBER_Border  @ border
	.4byte gMapLayout_UNDERWATER_SEALED_CHAMBER_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_SEALED_CHAMBER_OUTER_ROOM_Border:
	.incbin "data/layouts/SealedChamber_OuterRoom/border.bin"
gMapLayout_SEALED_CHAMBER_OUTER_ROOM_Blockdata:
	.incbin "data/layouts/SealedChamber_OuterRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SEALED_CHAMBER_OUTER_ROOM
gMapLayout_SEALED_CHAMBER_OUTER_ROOM: @ 0x0842B298
	.4byte 21  @ width
	.4byte 23  @ height
	.4byte gMapLayout_SEALED_CHAMBER_OUTER_ROOM_Border  @ border
	.4byte gMapLayout_SEALED_CHAMBER_OUTER_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_VICTORY_ROAD_B1F_Border:
	.incbin "data/layouts/VictoryRoad_B1F/border.bin"
gMapLayout_VICTORY_ROAD_B1F_Blockdata:
	.incbin "data/layouts/VictoryRoad_B1F/map.bin"
	.globl gMapLayout_VICTORY_ROAD_B1F
gMapLayout_VICTORY_ROAD_B1F: @ 0x0842BDDC
	.4byte 46  @ width
	.4byte 31  @ height
	.4byte gMapLayout_VICTORY_ROAD_B1F_Border  @ border
	.4byte gMapLayout_VICTORY_ROAD_B1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_VICTORY_ROAD_B2F_Border:
	.incbin "data/layouts/VictoryRoad_B2F/border.bin"
gMapLayout_VICTORY_ROAD_B2F_Blockdata:
	.incbin "data/layouts/VictoryRoad_B2F/map.bin"
	.globl gMapLayout_VICTORY_ROAD_B2F
gMapLayout_VICTORY_ROAD_B2F: @ 0x0842C920
	.4byte 46  @ width
	.4byte 31  @ height
	.4byte gMapLayout_VICTORY_ROAD_B2F_Border  @ border
	.4byte gMapLayout_VICTORY_ROAD_B2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42c938, 0x24
gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Border:
	.incbin "data/layouts/GraniteCave_StevensRoom/border.bin"
gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Blockdata:
	.incbin "data/layouts/GraniteCave_StevensRoom/map.bin"
	.globl gMapLayout_GRANITE_CAVE_STEVENS_ROOM
gMapLayout_GRANITE_CAVE_STEVENS_ROOM: @ 0x0842CB08
	.4byte 15  @ width
	.4byte 14  @ height
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Border  @ border
	.4byte gMapLayout_GRANITE_CAVE_STEVENS_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS_Border:
	.incbin "data/layouts/AbandonedShip_HiddenFloorCorridors/border.bin"
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS_Blockdata:
	.incbin "data/layouts/AbandonedShip_HiddenFloorCorridors/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS: @ 0x0842CC48
	.4byte 13  @ width
	.4byte 11  @ height
	.4byte gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42CC60, 0xD0C
gMapLayout_JAGGED_PASS_Border:
	.incbin "data/layouts/JaggedPass/border.bin"
gMapLayout_JAGGED_PASS_Blockdata:
	.incbin "data/layouts/JaggedPass/map.bin"
	.globl gMapLayout_JAGGED_PASS
gMapLayout_JAGGED_PASS: @ 0x0842E43C
	.4byte 30  @ width
	.4byte 46  @ height
	.4byte gMapLayout_JAGGED_PASS_Border  @ border
	.4byte gMapLayout_JAGGED_PASS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_FIERY_PATH_Border:
	.incbin "data/layouts/FieryPath/border.bin"
gMapLayout_FIERY_PATH_Blockdata:
	.incbin "data/layouts/FieryPath/map.bin"
	.globl gMapLayout_FIERY_PATH
gMapLayout_FIERY_PATH: @ 0x0842EEC0
	.4byte 35  @ width
	.4byte 38  @ height
	.4byte gMapLayout_FIERY_PATH_Border  @ border
	.4byte gMapLayout_FIERY_PATH_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_1F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_1F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_1F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_1F
gMapLayout_RUSTBORO_CITY_FLAT2_1F: @ 0x0842EFDC
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_2F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_2F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_2F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_2F
gMapLayout_RUSTBORO_CITY_FLAT2_2F: @ 0x0842F0F8
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT2_3F_Border:
	.incbin "data/layouts/RustboroCity_Flat2_3F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT2_3F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat2_3F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT2_3F
gMapLayout_RUSTBORO_CITY_FLAT2_3F: @ 0x0842F214
	.4byte 14  @ width
	.4byte 9  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT2_3F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Border:
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/border.bin"
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Blockdata:
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE
gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE: @ 0x0842F2A4
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_LOTAD_AND_SEEDOT_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Border:
	.incbin "data/layouts/EverGrandeCity_HallOfFame/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Blockdata:
	.incbin "data/layouts/EverGrandeCity_HallOfFame/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME
gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME: @ 0x0842F4C4
	.4byte 15  @ width
	.4byte 17  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL_OF_FAME_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_HALL_OF_FAME_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Border:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_1F/border.bin"
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Blockdata:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_1F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F: @ 0x0842F5BC
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Border:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_2F/border.bin"
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Blockdata:
	.incbin "data/layouts/LilycoveCity_CoveLilyMotel_2F/map.bin"
	.globl gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F
gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F: @ 0x0842F6B4
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Border  @ border
	.4byte gMapLayout_LILYCOVE_CITY_COVE_LILY_MOTEL_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x42f6cc, 0xd4
gMapLayout_MT_PYRE_EXTERIOR_Border:
	.incbin "data/layouts/MtPyre_Exterior/border.bin"
gMapLayout_MT_PYRE_EXTERIOR_Blockdata:
	.incbin "data/layouts/MtPyre_Exterior/map.bin"
	.globl gMapLayout_MT_PYRE_EXTERIOR
gMapLayout_MT_PYRE_EXTERIOR: @ 0x084306CC
	.4byte 38  @ width
	.4byte 51  @ height
	.4byte gMapLayout_MT_PYRE_EXTERIOR_Border  @ border
	.4byte gMapLayout_MT_PYRE_EXTERIOR_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_MT_PYRE_SUMMIT_Border:
	.incbin "data/layouts/MtPyre_Summit/border.bin"
gMapLayout_MT_PYRE_SUMMIT_Blockdata:
	.incbin "data/layouts/MtPyre_Summit/map.bin"
	.globl gMapLayout_MT_PYRE_SUMMIT
gMapLayout_MT_PYRE_SUMMIT: @ 0x08431560
	.4byte 50  @ width
	.4byte 37  @ height
	.4byte gMapLayout_MT_PYRE_SUMMIT_Border  @ border
	.4byte gMapLayout_MT_PYRE_SUMMIT_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_SEALED_CHAMBER_INNER_ROOM_Border:
	.incbin "data/layouts/SealedChamber_InnerRoom/border.bin"
gMapLayout_SEALED_CHAMBER_INNER_ROOM_Blockdata:
	.incbin "data/layouts/SealedChamber_InnerRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_SEALED_CHAMBER_INNER_ROOM
gMapLayout_SEALED_CHAMBER_INNER_ROOM: @ 0x08431948
	.4byte 21  @ width
	.4byte 23  @ height
	.4byte gMapLayout_SEALED_CHAMBER_INNER_ROOM_Border  @ border
	.4byte gMapLayout_SEALED_CHAMBER_INNER_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Border:
	.incbin "data/layouts/MossdeepCity_GameCorner_1F/border.bin"
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_GameCorner_1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F: @ 0x08431A58
	.4byte 12  @ width
	.4byte 10  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_MOSSDEEP_CITY_GAME_CORNER_1F_SECONDARY  @ secondaryTileset
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Border:
	.incbin "data/layouts/MossdeepCity_GameCorner_B1F/border.bin"
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Blockdata:
	.incbin "data/layouts/MossdeepCity_GameCorner_B1F/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F
gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F: @ 0x08431B50
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_GAME_CORNER_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Border:
	.incbin "data/layouts/SootopolisCity_House1/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Blockdata:
	.incbin "data/layouts/SootopolisCity_House1/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE1
gMapLayout_SOOTOPOLIS_CITY_HOUSE1: @ 0x08431BE0
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE1_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Border:
	.incbin "data/layouts/SootopolisCity_House2/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Blockdata:
	.incbin "data/layouts/SootopolisCity_House2/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE2
gMapLayout_SOOTOPOLIS_CITY_HOUSE2: @ 0x08431C70
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE2_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Border:
	.incbin "data/layouts/SootopolisCity_House3/border.bin"
gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Blockdata:
	.incbin "data/layouts/SootopolisCity_House3/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_HOUSE3
gMapLayout_SOOTOPOLIS_CITY_HOUSE3: @ 0x08431D00
	.4byte 8  @ width
	.4byte 7  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_HOUSE3_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_Border:
	.incbin "data/layouts/AbandonedShip_HiddenFloorRooms/border.bin"
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_Blockdata:
	.incbin "data/layouts/AbandonedShip_HiddenFloorRooms/map.bin"
	.globl gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS
gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS: @ 0x08432248
	.4byte 44  @ width
	.4byte 15  @ height
	.4byte gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_Border  @ border
	.4byte gMapLayout_ABANDONED_SHIP_HIDDEN_FLOOR_ROOMS_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_ABANDONED_SHIP_SECONDARY  @ secondaryTileset
gMapLayout_SCORCHED_SLAB_Border:
	.incbin "data/layouts/ScorchedSlab/border.bin"
gMapLayout_SCORCHED_SLAB_Blockdata:
	.incbin "data/layouts/ScorchedSlab/map.bin"
	.globl gMapLayout_SCORCHED_SLAB
gMapLayout_SCORCHED_SLAB: @ 0x084324C0
	.4byte 15  @ width
	.4byte 20  @ height
	.4byte gMapLayout_SCORCHED_SLAB_Border  @ border
	.4byte gMapLayout_SCORCHED_SLAB_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4324D8, 0x2F4
gMapLayout_RUSTBORO_CITY_FLAT1_1F_Border:
	.incbin "data/layouts/RustboroCity_Flat1_1F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT1_1F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat1_1F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_1F
gMapLayout_RUSTBORO_CITY_FLAT1_1F: @ 0x084328B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_RUSTBORO_CITY_FLAT1_2F_Border:
	.incbin "data/layouts/RustboroCity_Flat1_2F/border.bin"
gMapLayout_RUSTBORO_CITY_FLAT1_2F_Blockdata:
	.incbin "data/layouts/RustboroCity_Flat1_2F/map.bin"
	.globl gMapLayout_RUSTBORO_CITY_FLAT1_2F
gMapLayout_RUSTBORO_CITY_FLAT1_2F: @ 0x084329B4
	.4byte 14  @ width
	.4byte 8  @ height
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F_Border  @ border
	.4byte gMapLayout_RUSTBORO_CITY_FLAT1_2F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_EVER_GRANDE_CITY_HALL4_Border:
	.incbin "data/layouts/EverGrandeCity_Hall4/border.bin"
gMapLayout_EVER_GRANDE_CITY_HALL4_Blockdata:
	.incbin "data/layouts/EverGrandeCity_Hall4/map.bin"
	.globl gMapLayout_EVER_GRANDE_CITY_HALL4
gMapLayout_EVER_GRANDE_CITY_HALL4: @ 0x08432CC0
	.4byte 11  @ width
	.4byte 34  @ height
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4_Border  @ border
	.4byte gMapLayout_EVER_GRANDE_CITY_HALL4_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_EVER_GRANDE_CITY_SIDNEYS_ROOM_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1_Border:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap1/border.bin"
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1_Blockdata:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap1/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1: @ 0x08433370
	.4byte 28  @ width
	.4byte 30  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP1_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2_Border:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap2/border.bin"
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2_Blockdata:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap2/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2: @ 0x08433F30
	.4byte 62  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP2_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3_Border:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap3/border.bin"
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3_Blockdata:
	.incbin "data/layouts/AquaHideout_UnusedRubyMap3/map.bin"
	.globl gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3
gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3: @ 0x084345B0
	.4byte 34  @ width
	.4byte 24  @ height
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3_Border  @ border
	.4byte gMapLayout_AQUA_HIDEOUT_UNUSED_RUBY_MAP3_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_SLATEPORT_CITY_STERNS_SHIPYARD_1F_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x4345C8, 0x12E0
gMapLayout_SKY_PILLAR_ENTRANCE_Border:
	.incbin "data/layouts/SkyPillar_Entrance/border.bin"
gMapLayout_SKY_PILLAR_ENTRANCE_Blockdata:
	.incbin "data/layouts/SkyPillar_Entrance/map.bin"
gMapLayout_SKY_PILLAR_ENTRANCE: @ 0x08435B38
	.4byte 18  @ width
	.4byte 18  @ height
	.4byte gMapLayout_SKY_PILLAR_ENTRANCE_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_ENTRANCE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_OUTSIDE_Border:
	.incbin "data/layouts/SkyPillar_Outside/border.bin"
gMapLayout_SKY_PILLAR_OUTSIDE_Blockdata:
	.incbin "data/layouts/SkyPillar_Outside/map.bin"
gMapLayout_SKY_PILLAR_OUTSIDE: @ 0x08436060
	.4byte 28  @ width
	.4byte 23  @ height
	.4byte gMapLayout_SKY_PILLAR_OUTSIDE_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_OUTSIDE_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_1F_Border:
	.incbin "data/layouts/SkyPillar_1F/border.bin"
gMapLayout_SKY_PILLAR_1F_Blockdata:
	.incbin "data/layouts/SkyPillar_1F/map.bin"
gMapLayout_SKY_PILLAR_1F: @ 0x08436208
	.4byte 14  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SKY_PILLAR_1F_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_2F_Border:
	.incbin "data/layouts/SkyPillar_2F/border.bin"
gMapLayout_SKY_PILLAR_2F_Blockdata:
	.incbin "data/layouts/SkyPillar_2F/map.bin"
gMapLayout_SKY_PILLAR_2F: @ 0x084363B0
	.4byte 14  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SKY_PILLAR_2F_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_2F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_3F_Border:
	.incbin "data/layouts/SkyPillar_3F/border.bin"
gMapLayout_SKY_PILLAR_3F_Blockdata:
	.incbin "data/layouts/SkyPillar_3F/map.bin"
gMapLayout_SKY_PILLAR_3F: @ 0x08436558
	.4byte 14  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SKY_PILLAR_3F_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_3F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_4F_Border:
	.incbin "data/layouts/SkyPillar_4F/border.bin"
gMapLayout_SKY_PILLAR_4F_Blockdata:
	.incbin "data/layouts/SkyPillar_4F/map.bin"
gMapLayout_SKY_PILLAR_4F: @ 0x08436700
	.4byte 14  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SKY_PILLAR_4F_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_4F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x436718, 0x9D4
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Border:
	.incbin "data/layouts/MossdeepCity_StevensHouse/border.bin"
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Blockdata:
	.incbin "data/layouts/MossdeepCity_StevensHouse/map.bin"
	.globl gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE
gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE: @ 0x084371A4
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Border  @ border
	.4byte gMapLayout_MOSSDEEP_CITY_STEVENS_HOUSE_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_OLDALE_TOWN_HOUSE1_SECONDARY  @ secondaryTileset
gMapLayout_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_Border:
	.incbin "data/layouts/ShoalCave_LowTideIceRoom/border.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_Blockdata:
	.incbin "data/layouts/ShoalCave_LowTideIceRoom/map.bin"
gMapLayout_SHOAL_CAVE_LOW_TIDE_ICE_ROOM: @ 0x08437674
	.4byte 20  @ width
	.4byte 30  @ height
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_Border  @ border
	.4byte gMapLayout_SHOAL_CAVE_LOW_TIDE_ICE_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_DESERT_RUINS_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x43768C, 0xD4
gMapLayout_SKY_PILLAR_5F_Border:
	.incbin "data/layouts/SkyPillar_5F/border.bin"
gMapLayout_SKY_PILLAR_5F_Blockdata:
	.incbin "data/layouts/SkyPillar_5F/map.bin"
gMapLayout_SKY_PILLAR_5F: @ 0x084378F0
	.4byte 14  @ width
	.4byte 14  @ height
	.4byte gMapLayout_SKY_PILLAR_5F_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_5F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_SKY_PILLAR_TOP_Border:
	.incbin "data/layouts/SkyPillar_Top/border.bin"
gMapLayout_SKY_PILLAR_TOP_Blockdata:
	.incbin "data/layouts/SkyPillar_Top/map.bin"
gMapLayout_SKY_PILLAR_TOP: @ 0x08437E20
	.4byte 27  @ width
	.4byte 24  @ height
	.4byte gMapLayout_SKY_PILLAR_TOP_Border  @ border
	.4byte gMapLayout_SKY_PILLAR_TOP_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_PACIFIDLOG_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x437E38, 0x850
gMapLayout_MAGMA_HIDEOUT_1F_Border:
	.incbin "data/layouts/MagmaHideout_1F/border.bin"
gMapLayout_MAGMA_HIDEOUT_1F_Blockdata:
	.incbin "data/layouts/MagmaHideout_1F/map.bin"
gMapLayout_MAGMA_HIDEOUT_1F: @ 0x0843918C
	.4byte 37  @ width
	.4byte 38  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_1F_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_1F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_2F_1R_Border:
	.incbin "data/layouts/MagmaHideout_2F_1R/border.bin"
gMapLayout_MAGMA_HIDEOUT_2F_1R_Blockdata:
	.incbin "data/layouts/MagmaHideout_2F_1R/map.bin"
	.byte 0x00, 0x00
gMapLayout_MAGMA_HIDEOUT_2F_1R: @ 0x08439BBC
	.4byte 33  @ width
	.4byte 39  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_1R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_2F_2R_Border:
	.incbin "data/layouts/MagmaHideout_2F_2R/border.bin"
gMapLayout_MAGMA_HIDEOUT_2F_2R_Blockdata:
	.incbin "data/layouts/MagmaHideout_2F_2R/map.bin"
gMapLayout_MAGMA_HIDEOUT_2F_2R: @ 0x0843A694
	.4byte 49  @ width
	.4byte 28  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_2R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_3F_1R_Border:
	.incbin "data/layouts/MagmaHideout_3F_1R/border.bin"
gMapLayout_MAGMA_HIDEOUT_3F_1R_Blockdata:
	.incbin "data/layouts/MagmaHideout_3F_1R/map.bin"
gMapLayout_MAGMA_HIDEOUT_3F_1R: @ 0x0843ABF4
	.4byte 28  @ width
	.4byte 24  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_1R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_1R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_3F_2R_Border:
	.incbin "data/layouts/MagmaHideout_3F_2R/border.bin"
gMapLayout_MAGMA_HIDEOUT_3F_2R_Blockdata:
	.incbin "data/layouts/MagmaHideout_3F_2R/map.bin"
gMapLayout_MAGMA_HIDEOUT_3F_2R: @ 0x0843AF44
	.4byte 24  @ width
	.4byte 17  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_2R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_2R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_4F_Border:
	.incbin "data/layouts/MagmaHideout_4F/border.bin"
gMapLayout_MAGMA_HIDEOUT_4F_Blockdata:
	.incbin "data/layouts/MagmaHideout_4F/map.bin"
gMapLayout_MAGMA_HIDEOUT_4F: @ 0x0843BC4C
	.4byte 59  @ width
	.4byte 28  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_4F_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_4F_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x43BC64, 0x6E98
gMapLayout_MAGMA_HIDEOUT_3F_3R_Border:
	.incbin "data/layouts/MagmaHideout_3F_3R/border.bin"
gMapLayout_MAGMA_HIDEOUT_3F_3R_Blockdata:
	.incbin "data/layouts/MagmaHideout_3F_3R/map.bin"
gMapLayout_MAGMA_HIDEOUT_3F_3R: @ 0x08443134
	.4byte 33  @ width
	.4byte 24  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_3R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_3F_3R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
gMapLayout_MAGMA_HIDEOUT_2F_3R_Border:
	.incbin "data/layouts/MagmaHideout_2F_3R/border.bin"
gMapLayout_MAGMA_HIDEOUT_2F_3R_Blockdata:
	.incbin "data/layouts/MagmaHideout_2F_3R/map.bin"
gMapLayout_MAGMA_HIDEOUT_2F_3R: @ 0x08443A3C
	.4byte 60  @ width
	.4byte 19  @ height
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_3R_Border  @ border
	.4byte gMapLayout_MAGMA_HIDEOUT_2F_3R_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_LAVARIDGE_TOWN_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x443A54, 0x8C4
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Border:
	.incbin "data/layouts/FallarborTownBattleTentLobby/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentLobby/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY: @ 0x08444424
	.4byte 13  @ width
	.4byte 10  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Border:
	.incbin "data/layouts/FallarborTownBattleTentCorridor/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentCorridor/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR: @ 0x08444494
	.4byte 5  @ width
	.4byte 8  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Border:
	.incbin "data/layouts/FallarborTownBattleTentBattleRoom/border.bin"
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata:
	.incbin "data/layouts/FallarborTownBattleTentBattleRoom/map.bin"
	.globl gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444568
	.4byte 10  @ width
	.4byte 9  @ height
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Border  @ border
	.4byte gMapLayout_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Border:
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/border.bin"
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata:
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/map.bin"
	.byte 0x00, 0x00
	.globl gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM
gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM: @ 0x08444674
	.4byte 13  @ width
	.4byte 9  @ height
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Border  @ border
	.4byte gMapLayout_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_FALLARBOR_TOWN_BATTLE_TENT_LOBBY_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x44468c, 0xaf64
gMapLayout_UNDERWATER_ROUTE105_Border:
	.incbin "data/layouts/Underwater_Route105/border.bin"
gMapLayout_UNDERWATER_ROUTE105_Blockdata:
	.incbin "data/layouts/Underwater_Route105/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE105
gMapLayout_UNDERWATER_ROUTE105: @ 0x08450EF8
	.4byte 40  @ width
	.4byte 80  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE105_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE105_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
gMapLayout_UNDERWATER_ROUTE125_Border:
	.incbin "data/layouts/Underwater_Route125/border.bin"
gMapLayout_UNDERWATER_ROUTE125_Blockdata:
	.incbin "data/layouts/Underwater_Route125/map.bin"
	.globl gMapLayout_UNDERWATER_ROUTE125
gMapLayout_UNDERWATER_ROUTE125: @ 0x08452818
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte gMapLayout_UNDERWATER_ROUTE125_Border  @ border
	.4byte gMapLayout_UNDERWATER_ROUTE125_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
Underwater_Route129_Layout_Border::
	.incbin "data/layouts/Underwater_Route129/border.bin"
Underwater_Route129_Layout_Blockdata::
	.incbin "data/layouts/Underwater_Route129/map.bin"
Underwater_Route129_Layout:: @ 0x08454138
	.4byte 80  @ width
	.4byte 40  @ height
	.4byte Underwater_Route129_Layout_Border  @ border
	.4byte Underwater_Route129_Layout_Blockdata  @ map
	.4byte gTileset_PETALBURG_CITY_PRIMARY  @ primaryTileset
	.4byte gTileset_UNDERWATER_ROUTE126_SECONDARY  @ secondaryTileset
	.incbin "baserom_jp.gba", 0x454150, 0x5e0c
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Border:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F: @ 0x0845A014
	.4byte 11  @ width
	.4byte 8  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Border:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/border.bin"
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Blockdata:
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/map.bin"
	.globl gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F
gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F: @ 0x0845A10C
	.4byte 12  @ width
	.4byte 9  @ height
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Border  @ border
	.4byte gMapLayout_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F_Blockdata  @ map
	.4byte gTileset_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F_PRIMARY  @ primaryTileset
	.4byte gTileset_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_SECONDARY  @ secondaryTileset
