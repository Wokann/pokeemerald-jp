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
	.set LAYOUT_UNDERWATER_ROUTE129, 412

	.set MAPSEC_UNDERWATER_124, 50
	.set MAPSEC_UNDERWATER_126, 51
	.set MAPSEC_UNDERWATER_127, 52
	.set MAPSEC_UNDERWATER_128, 53
	.set MAPSEC_UNDERWATER_129, 208

	.set WEATHER_UNDERWATER_BUBBLES, 14
	.set MAP_TYPE_UNDERWATER, 5
	.set MAP_BATTLE_SCENE_NORMAL, 0

@ constants/songs.inc does not yet export this semantic alias.
	.set MUS_UNDERWATER, 411
