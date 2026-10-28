	.equiv NUM_TRACKS_BGM, 10
	.equiv NUM_TRACKS_SE1, 3
	.equiv NUM_TRACKS_SE2, 9
	.equiv NUM_TRACKS_SE3, 1

@ Track buffers use the fixed JP IWRAM layout in sym_iwram_jp.txt.
	.align 2
gMPlayTable::
	music_player gMPlayInfo_BGM, gMPlayTrack_BGM, NUM_TRACKS_BGM, 0
	music_player gMPlayInfo_SE1, gMPlayTrack_SE1, NUM_TRACKS_SE1, 1
	music_player gMPlayInfo_SE2, gMPlayTrack_SE2, NUM_TRACKS_SE2, 1
	music_player gMPlayInfo_SE3, gMPlayTrack_SE3, NUM_TRACKS_SE3, 0
