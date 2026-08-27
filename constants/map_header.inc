@ Assembly constants for map headers that have moved into map directories.
@
@ These mirror the corresponding values in include/constants/*.h. Extend this
@ bridge as additional JP map headers are structured; the full JP layouts.json
@ migration will eventually replace the layout subset with generated constants.

	.set TRUE, 1
	.set FALSE, 0
	.set NULL, 0

	.set LAYOUT_UNDERWATER_ROUTE126, 51
	.set LAYOUT_UNDERWATER_ROUTE127, 52
	.set LAYOUT_UNDERWATER_ROUTE128, 53
	.set LAYOUT_UNDERWATER_ROUTE124, 274
	.set LAYOUT_UNDERWATER_ROUTE105, 410
	.set LAYOUT_UNDERWATER_ROUTE125, 411
	.set LAYOUT_UNDERWATER_ROUTE129, 412
	.set LAYOUT_CAVE_OF_ORIGIN_B1F, 162
	.set LAYOUT_VICTORY_ROAD_1F, 163
	.set LAYOUT_VICTORY_ROAD_B1F, 285
	.set LAYOUT_VICTORY_ROAD_B2F, 286

	.set MAPSEC_UNDERWATER_124, 50
	.set MAPSEC_UNDERWATER_126, 51
	.set MAPSEC_UNDERWATER_127, 52
	.set MAPSEC_UNDERWATER_128, 53
	.set MAPSEC_UNDERWATER_105, 206
	.set MAPSEC_UNDERWATER_125, 207
	.set MAPSEC_UNDERWATER_129, 208
	.set MAPSEC_CAVE_OF_ORIGIN, 72
	.set MAPSEC_VICTORY_ROAD, 70

	.set WEATHER_NONE, 0
	.set WEATHER_UNDERWATER_BUBBLES, 14
	.set WEATHER_FOG_HORIZONTAL, 6
	.set MAP_TYPE_UNDERWATER, 5
	.set MAP_TYPE_UNDERGROUND, 4
	.set MAP_BATTLE_SCENE_NORMAL, 0

@ constants/songs.inc does not yet export this semantic alias.
	.set MUS_UNDERWATER, 411
	.set MUS_NONE, 0xFFFF
	.set MUS_VICTORY_ROAD, 429
