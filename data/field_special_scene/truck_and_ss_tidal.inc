@ Truck camera and S.S. Tidal movement data retained before rotating_gate.
@ The final zero byte is physical alignment padding, not part of the west
@ movement script.

	.globl sTruckCamera_HorizontalTable
sTruckCamera_HorizontalTable: @ 0x0856A47C
	.byte 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, -1, -1, -1, 0

	.globl sSSTidalSailEastMovementScript
sSSTidalSailEastMovementScript: @ 0x0856A48F
	walk_fast_right
	step_end

	.globl sSSTidalSailWestMovementScript
sSSTidalSailWestMovementScript: @ 0x0856A491
	walk_fast_left
	step_end

sSSTidalSailMovementPadding: @ 0x0856A493
	.byte 0
