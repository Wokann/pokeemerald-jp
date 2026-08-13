	lockall 
	setvar 0x8004, 0x0
	special ShowLinkBattleRecords
	waitbuttonpress 
	special RemoveRecordsWindow
	releaseall 
	end 
