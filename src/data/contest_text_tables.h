#ifndef GUARD_CONTEST_TEXT_TABLES_H
#define GUARD_CONTEST_TEXT_TABLES_H

#define CONTEST_TEXT_TABLES __attribute__((section(".rodata.contest_mid57b_text_tables")))

extern const u8 gText_HighlyAppealingMove[];
extern const u8 gText_UserMoreEasilyStartled[];
extern const u8 gText_GreatAppealButNoMoreToEnd[];
extern const u8 gText_UsedRepeatedlyWithoutBoringJudge[];
extern const u8 gText_AvoidStartledByOthersOnce[];
extern const u8 gText_AvoidStartledByOthers[];
extern const u8 gText_AvoidStartledByOthersLittle[];
extern const u8 gText_UserLessEasilyStartled[];
extern const u8 gText_SlightlyStartleFrontMon[];
extern const u8 gText_SlightlyStartleAppealed[];
extern const u8 gText_StartleAppealedBeforeUser[];
extern const u8 gText_StartleAllAppealed[];
extern const u8 gText_BadlyStartleFrontMon[];
extern const u8 gText_BadlyStartleAppealed[];
extern const u8 gText_StartleAppealedBeforeUser2[];
extern const u8 gText_StartleAllAppealed2[];
extern const u8 gText_ShiftJudgesAttentionFromOthers[];
extern const u8 gText_StartleMonHasJudgesAttention[];
extern const u8 gText_JamOthersMissesTurn[];
extern const u8 gText_StartleMonsMadeSameTypeAppeal[];
extern const u8 gText_BadlyStartleCoolAppeals[];
extern const u8 gText_BadlyStartleBeautyAppeals[];
extern const u8 gText_BadlyStartleCuteAppeals[];
extern const u8 gText_BadlyStartleSmartAppeals[];
extern const u8 gText_BadlyStartleToughAppeals[];
extern const u8 gText_MakeMonAfterUserNervous[];
extern const u8 gText_MakeAllMonsAfterUserNervous[];
extern const u8 gText_WorsenConditionOfThoseMadeAppeals[];
extern const u8 gText_BadlyStartleMonsGoodCondition[];
extern const u8 gText_AppealGreatIfPerformedFirst[];
extern const u8 gText_AppealGreatIfPerformedLast[];
extern const u8 gText_AppealAsGoodAsThoseBeforeIt[];
extern const u8 gText_AppealAsGoodAsOneBeforeIt[];
extern const u8 gText_AppealBetterLaterItsPerformed[];
extern const u8 gText_AppealVariesDependingOnTiming[];
extern const u8 gText_WorksWellIfSameTypeAsBefore[];
extern const u8 gText_WorksWellIfDifferentTypeAsBefore[];
extern const u8 gText_AffectedByAppealInFront[];
extern const u8 gText_UpsConditionHelpsPreventNervousness[];
extern const u8 gText_AppealWorksWellIfConditionGood[];
extern const u8 gText_NextAppealMadeEarlier[];
extern const u8 gText_NextAppealMadeLater[];
extern const u8 gText_TurnOrderMoreEasilyScrambled[];
extern const u8 gText_ScrambleOrderOfNextAppeals[];
extern const u8 gText_AppealExcitesAudienceInAnyContest[];
extern const u8 gText_BadlyStartlesMonsGoodAppeals[];
extern const u8 gText_AppealBestMoreCrowdExcited[];
extern const u8 gText_TemporarilyStopCrowdExcited[];
extern const u8 gText_RainDance[];
extern const u8 gText_Rage[];
extern const u8 gText_FocusEnergy[];
extern const u8 gText_Hypnosis[];
extern const u8 gText_Softboiled[];
extern const u8 gText_HornAttack[];
extern const u8 gText_SwordsDance[];
extern const u8 gText_Conversion[];
extern const u8 gText_SunnyDay[];
extern const u8 gText_Rest2[];
extern const u8 gText_Vicegrip[];
extern const u8 gText_DefenseCurl[];
extern const u8 gText_LockOn[];
extern const u8 gContestMoveTypeCoolText[];
extern const u8 gContestMoveTypeBeautyText[];
extern const u8 gContestMoveTypeCuteText[];
extern const u8 gContestMoveTypeSmartText[];
extern const u8 gContestMoveTypeToughText[];
extern const u8 gText_ButAppealWasJammed[];
extern const u8 gText_FollowedAnotherMonsLead[];
extern const u8 gText_ButItMessedUp[];
extern const u8 gText_WentBetterThanUsual[];
extern const u8 gText_JudgeLookedAwayForSomeReason[];
extern const u8 gText_WorkedHardToBuildOnPastMistakes[];
extern const u8 gText_CantMakeAnyMoreMoves[];
extern const u8 gText_WorkedFrighteninglyWell[];
extern const u8 gText_WorkedHardAsStandoutMon[];
extern const u8 gText_JudgedLookedOnExpectantly[];
extern const u8 gText_WorkedRatherWell[];
extern const u8 gText_WorkedLittleBetterThanUsual[];

CONTEST_TEXT_TABLES const u8 *const gContestEffectDescriptionPointers[] = {
    [CONTEST_EFFECT_HIGHLY_APPEALING]                      = gText_HighlyAppealingMove,
    [CONTEST_EFFECT_USER_MORE_EASILY_STARTLED]             = gText_UserMoreEasilyStartled,
    [CONTEST_EFFECT_GREAT_APPEAL_BUT_NO_MORE_MOVES]        = gText_GreatAppealButNoMoreToEnd,
    [CONTEST_EFFECT_REPETITION_NOT_BORING]                 = gText_UsedRepeatedlyWithoutBoringJudge,
    [CONTEST_EFFECT_AVOID_STARTLE_ONCE]                    = gText_AvoidStartledByOthersOnce,
    [CONTEST_EFFECT_AVOID_STARTLE]                         = gText_AvoidStartledByOthers,
    [CONTEST_EFFECT_AVOID_STARTLE_SLIGHTLY]                = gText_AvoidStartledByOthersLittle,
    [CONTEST_EFFECT_USER_LESS_EASILY_STARTLED]             = gText_UserLessEasilyStartled,
    [CONTEST_EFFECT_STARTLE_FRONT_MON]                     = gText_SlightlyStartleFrontMon,
    [CONTEST_EFFECT_SLIGHTLY_STARTLE_PREV_MONS]            = gText_SlightlyStartleAppealed,
    [CONTEST_EFFECT_STARTLE_PREV_MON]                      = gText_StartleAppealedBeforeUser,
    [CONTEST_EFFECT_STARTLE_PREV_MONS]                     = gText_StartleAllAppealed,
    [CONTEST_EFFECT_BADLY_STARTLE_FRONT_MON]               = gText_BadlyStartleFrontMon,
    [CONTEST_EFFECT_BADLY_STARTLE_PREV_MONS]               = gText_BadlyStartleAppealed,
    [CONTEST_EFFECT_STARTLE_PREV_MON_2]                    = gText_StartleAppealedBeforeUser2,
    [CONTEST_EFFECT_STARTLE_PREV_MONS_2]                   = gText_StartleAllAppealed2,
    [CONTEST_EFFECT_SHIFT_JUDGE_ATTENTION]                 = gText_ShiftJudgesAttentionFromOthers,
    [CONTEST_EFFECT_STARTLE_MON_WITH_JUDGES_ATTENTION]     = gText_StartleMonHasJudgesAttention,
    [CONTEST_EFFECT_JAMS_OTHERS_BUT_MISS_ONE_TURN]         = gText_JamOthersMissesTurn,
    [CONTEST_EFFECT_STARTLE_MONS_SAME_TYPE_APPEAL]         = gText_StartleMonsMadeSameTypeAppeal,
    [CONTEST_EFFECT_STARTLE_MONS_COOL_APPEAL]              = gText_BadlyStartleCoolAppeals,
    [CONTEST_EFFECT_STARTLE_MONS_BEAUTY_APPEAL]            = gText_BadlyStartleBeautyAppeals,
    [CONTEST_EFFECT_STARTLE_MONS_CUTE_APPEAL]              = gText_BadlyStartleCuteAppeals,
    [CONTEST_EFFECT_STARTLE_MONS_SMART_APPEAL]             = gText_BadlyStartleSmartAppeals,
    [CONTEST_EFFECT_STARTLE_MONS_TOUGH_APPEAL]             = gText_BadlyStartleToughAppeals,
    [CONTEST_EFFECT_MAKE_FOLLOWING_MON_NERVOUS]            = gText_MakeMonAfterUserNervous,
    [CONTEST_EFFECT_MAKE_FOLLOWING_MONS_NERVOUS]           = gText_MakeAllMonsAfterUserNervous,
    [CONTEST_EFFECT_WORSEN_CONDITION_OF_PREV_MONS]         = gText_WorsenConditionOfThoseMadeAppeals,
    [CONTEST_EFFECT_BADLY_STARTLES_MONS_IN_GOOD_CONDITION] = gText_BadlyStartleMonsGoodCondition,
    [CONTEST_EFFECT_BETTER_IF_FIRST]                       = gText_AppealGreatIfPerformedFirst,
    [CONTEST_EFFECT_BETTER_IF_LAST]                        = gText_AppealGreatIfPerformedLast,
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONES]           = gText_AppealAsGoodAsThoseBeforeIt,
    [CONTEST_EFFECT_APPEAL_AS_GOOD_AS_PREV_ONE]            = gText_AppealAsGoodAsOneBeforeIt,
    [CONTEST_EFFECT_BETTER_WHEN_LATER]                     = gText_AppealBetterLaterItsPerformed,
    [CONTEST_EFFECT_QUALITY_DEPENDS_ON_TIMING]             = gText_AppealVariesDependingOnTiming,
    [CONTEST_EFFECT_BETTER_IF_SAME_TYPE]                   = gText_WorksWellIfSameTypeAsBefore,
    [CONTEST_EFFECT_BETTER_IF_DIFF_TYPE]                   = gText_WorksWellIfDifferentTypeAsBefore,
    [CONTEST_EFFECT_AFFECTED_BY_PREV_APPEAL]               = gText_AffectedByAppealInFront,
    [CONTEST_EFFECT_IMPROVE_CONDITION_PREVENT_NERVOUSNESS] = gText_UpsConditionHelpsPreventNervousness,
    [CONTEST_EFFECT_BETTER_WITH_GOOD_CONDITION]            = gText_AppealWorksWellIfConditionGood,
    [CONTEST_EFFECT_NEXT_APPEAL_EARLIER]                   = gText_NextAppealMadeEarlier,
    [CONTEST_EFFECT_NEXT_APPEAL_LATER]                     = gText_NextAppealMadeLater,
    [CONTEST_EFFECT_MAKE_SCRAMBLING_TURN_ORDER_EASIER]     = gText_TurnOrderMoreEasilyScrambled,
    [CONTEST_EFFECT_SCRAMBLE_NEXT_TURN_ORDER]              = gText_ScrambleOrderOfNextAppeals,
    [CONTEST_EFFECT_EXCITE_AUDIENCE_IN_ANY_CONTEST]        = gText_AppealExcitesAudienceInAnyContest,
    [CONTEST_EFFECT_BADLY_STARTLE_MONS_WITH_GOOD_APPEALS]  = gText_BadlyStartlesMonsGoodAppeals,
    [CONTEST_EFFECT_BETTER_WHEN_AUDIENCE_EXCITED]          = gText_AppealBestMoreCrowdExcited,
    [CONTEST_EFFECT_DONT_EXCITE_AUDIENCE]                  = gText_TemporarilyStopCrowdExcited
};

// Unreferenced array of pointers to move names.
// All of the moves except Conversion are combo starters, so this may have
// been an early list of combo starters.
CONTEST_TEXT_TABLES static const u8 *const sUnusedComboMoveNameTexts[] = {
    gText_RainDance,
    gText_RainDance,
    gText_Rage,
    gText_FocusEnergy,
    gText_Hypnosis,
    gText_Softboiled,
    gText_HornAttack,
    gText_SwordsDance,
    gText_Conversion,
    gText_SunnyDay,
    gText_Rest2,
    gText_Vicegrip,
    gText_DefenseCurl,
    gText_LockOn
};

CONTEST_TEXT_TABLES const u8 *const gContestMoveTypeTextPointers[] = {
    [CONTEST_CATEGORY_COOL]   = gContestMoveTypeCoolText,
    [CONTEST_CATEGORY_BEAUTY] = gContestMoveTypeBeautyText,
    [CONTEST_CATEGORY_CUTE]   = gContestMoveTypeCuteText,
    [CONTEST_CATEGORY_SMART]  = gContestMoveTypeSmartText,
    [CONTEST_CATEGORY_TOUGH]  = gContestMoveTypeToughText
};

CONTEST_TEXT_TABLES static const u8 *const sUnusedAppealResultTexts[] = {
    gText_ButAppealWasJammed,
    gText_FollowedAnotherMonsLead,
    gText_ButItMessedUp,
    gText_WentBetterThanUsual,
    gText_WentBetterThanUsual,
    gText_JudgeLookedAwayForSomeReason,
    gText_WorkedHardToBuildOnPastMistakes,
    gText_CantMakeAnyMoreMoves,
    gText_WorkedFrighteninglyWell,
    gText_WorkedHardAsStandoutMon,
    gText_JudgedLookedOnExpectantly,
    gText_WorkedRatherWell,
    gText_WorkedLittleBetterThanUsual
};

#undef CONTEST_TEXT_TABLES

#endif // GUARD_CONTEST_TEXT_TABLES_H
