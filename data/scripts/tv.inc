Event_TV:: @ 81A6E72
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForBigMovieOrEmergencyNewsOnTV
	compare VAR_RESULT, 2
	goto_if_eq EventScript_1A6F01
	compare VAR_RESULT, 1
	goto_if_eq EventScript_1A6F0B
	goto_if_unset FLAG_SYS_TV_START, EventScript_1A6EF1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_1A6EF1
	specialvar VAR_RESULT, IsTVShowInSearchOfTrainersAiring
	compare VAR_RESULT, 1
	goto_if_eq EventScript_1A6F66
	goto EventScript_1A6F50
	end

EventScript_1A6EBB:
	specialvar VAR_0x8004, special_0x44
	compare VAR_0x8004, 255
	goto_if_eq EventScript_1A6F3F
	specialvar VAR_RESULT, GetNonMassOutbreakActiveTVShow
	compare VAR_RESULT, 255
	goto_if_eq EventScript_1A6F3F
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetTVShowType
	compare VAR_RESULT, 0
	goto_if_ne EventScript_1A6F21
	end

EventScript_1A6EF1:
	special GetMomOrDadStringForTVMessage
	msgbox UnknownString_81A0E68, 4
	special TurnOffTVScreen
	releaseall
	end

EventScript_1A6F01:
	msgbox UnknownString_817288C, 4
	releaseall
	end

EventScript_1A6F0B:
	.ifdef SAPPHIRE
	msgbox UnknownString_8172D30, 4
	.else
	msgbox UnknownString_8172C50, 4
	.endif
	special InitRoamer
	clearflag FLAG_SYS_TV_LATI
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

EventScript_1A6F21:
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 1
	goto_if_ne EventScript_1A6F21
	goto EventScript_1A6F37
	end

EventScript_1A6F37:
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_1A6F3F:
	special GetMomOrDadStringForTVMessage
	msgbox UnknownString_81A0E68, 4
	goto EventScript_1A6F37
	end

EventScript_1A6F50:
	special DoPokeNews
	compare VAR_RESULT, 0
	goto_if_eq EventScript_1A6EBB
	waitmessage
	waitbuttonpress
	goto EventScript_1A6F37
	end

EventScript_1A6F66:
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 0
	goto_if_eq EventScript_1A6F66
	goto EventScript_1A6F37
	end
