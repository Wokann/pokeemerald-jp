@
@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/Underwater_Route124/map.json
@

Underwater_Route124_MapConnectionsList:
	connection down, 0, MAP_UNDERWATER_ROUTE126
	connection emerge, 0, MAP_ROUTE124

	.globl UNDERWATER_ROUTE124_MapConnections
	.set UNDERWATER_ROUTE124_MapConnections, Underwater_Route124_MapConnectionsList

Underwater_Route124_MapConnections:
	.4byte 2
	.4byte Underwater_Route124_MapConnectionsList
	.globl gMapConnections_UNDERWATER_ROUTE124
	.set gMapConnections_UNDERWATER_ROUTE124, Underwater_Route124_MapConnections
