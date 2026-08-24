@
@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/Underwater_Route127/map.json
@

Underwater_Route127_MapConnectionsList:
	connection emerge, 0, MAP_ROUTE127
	connection left, 0, MAP_UNDERWATER_ROUTE126
	connection down, 0, MAP_UNDERWATER_ROUTE128

	.globl UNDERWATER_ROUTE127_MapConnections
	.set UNDERWATER_ROUTE127_MapConnections, Underwater_Route127_MapConnectionsList

Underwater_Route127_MapConnections:
	.4byte 3
	.4byte Underwater_Route127_MapConnectionsList
	.globl gMapConnections_UNDERWATER_ROUTE127
	.set gMapConnections_UNDERWATER_ROUTE127, Underwater_Route127_MapConnections
