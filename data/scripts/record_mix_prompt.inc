@ Seems this was superseded by the Record Center, and the below scripts are now unused
@ The JP text entries remain in their later physical owner.
EventScript_MixRecordsPrompt::
	lock
	faceplayer
	msgbox 0x08243690, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_MixRecords
	goto_if_eq VAR_RESULT, NO, EventScript_EndMixRecords
	goto EventScript_EndMixRecords

EventScript_MixRecords::
	special RecordMixingPlayerSpotTriggered
	lock
	faceplayer
EventScript_EndMixRecords::
	message 0x082436A4
	waitmessage
	waitbuttonpress
	release
	end
