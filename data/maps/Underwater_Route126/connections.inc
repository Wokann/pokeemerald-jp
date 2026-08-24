@
@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/Underwater_Route126/map.json
@

Underwater_Route126_MapConnectionsList:
	connection up, 0, MAP_UNDERWATER_ROUTE124
	connection right, 0, MAP_UNDERWATER_ROUTE127
	connection emerge, 0, MAP_ROUTE126

	.globl UNDERWATER_ROUTE126_MapConnections
	.set UNDERWATER_ROUTE126_MapConnections, Underwater_Route126_MapConnectionsList

Underwater_Route126_MapConnections:
	.4byte 3
	.4byte Underwater_Route126_MapConnectionsList
	.globl gMapConnections_UNDERWATER_ROUTE126
	.set gMapConnections_UNDERWATER_ROUTE126, Underwater_Route126_MapConnections
