// Auto-derived from pret's movement-action table order; see the external
// candidate audit for the JP function-name and address evidence.
// Do not run the generator as a build step: this checked-in header is the source of truth.

typedef bool8 (*MovementActionFunc)(struct ObjectEvent *, struct Sprite *);

#define MOVEMENT_ACTION_FUNC_TABLE(name, ...) \
    const MovementActionFunc name[] EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES = { __VA_ARGS__ }

#define MOVEMENT_ACTION_STATIC_U8_FUNC_TABLE(name, ...) \
    static u8 (*const name[])(u8) EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES = { __VA_ARGS__ }

#define MOVEMENT_ACTION_STATIC_S16_TABLE(name, ...) \
    static const s16 name[] EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES = { __VA_ARGS__ }

extern bool8 MovementAction_FaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PauseSpriteAnim(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FaceLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalUpLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08093554(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalUpRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalUpRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalDownLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalDownLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalDownRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDiagonalDownRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkSlowRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalUpLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalUpLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalUpRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalUpRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalDownLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalDownLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalDownRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDiagonalDownRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkNormalRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Down_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Down_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Up_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Up_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Left_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Left_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Right_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Jump2Right_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay1_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095E28(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay2_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay4_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay8_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Delay16_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFastRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceSlowDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceSlow_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceSlowUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceSlowLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceSlowRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceNormalDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlace_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceNormalUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceNormalLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceNormalRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFastDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFastUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFastLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFastRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFasterDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFasterUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFasterLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkInPlaceFasterRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RideWaterCurrentRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkFasterRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SlideRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_PlayerRunRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_StartAnimInDirection_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WaitSpriteAnim(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpSpecialRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FacePlayer_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FaceAwayPlayer_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_LockFacingDirection_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_UnlockFacingDirection_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceDownUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceDownUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceUpDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceUpDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceLeftRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceRightLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FaceOriginalDirection_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_NurseJoyBowDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_EnableJumpLandingGroundEffect_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_DisableJumpLandingGroundEffect_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_DisableAnimation_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RestoreAnimation_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SetInvisible_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SetVisible_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_EmoteExclamationMark_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_EmoteQuestionMark_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_EmoteHeart_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RevealTrainer_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RevealTrainer_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RockSmashBreak_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RockSmashBreak_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_RockSmashBreak_Step2(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_CutTree_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_CutTree_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_CutTree_Step2(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_SetFixedPriority_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_ClearFixedPriority_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_InitAffineAnim_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_ClearAffineAnim_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_HideReflection_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Unknown2_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkDownStartAffine_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkDownStartAffine_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkDownAffine_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkDownAffine_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkLeftAffine_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkLeftAffine_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkRightAffine_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_WalkRightAffine_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieFaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieFaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieFaceLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieFaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieFaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieFaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095388(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieFaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_UnusedAcroActionDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_UnusedAcroActionUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_UnusedAcroActionLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_UnusedAcroActionRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Figure8_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_080954D4(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopFaceRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieHopRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieJumpRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieInPlaceDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieInPlaceUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieInPlaceLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieInPlaceRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095A70_jp(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieMoveDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095AB0_jp(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieMoveUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095AF0_jp(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieMoveLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 sub_08095B30(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroPopWheelieMoveRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroWheelieMoveRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveDown_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveLeft_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveLeft_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveRight_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_AcroEndWheelieMoveRight_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Levitate_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_StopLevitate_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_StoreAndLockAnim_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FreeAndUnlockAnim_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FlyUp_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FlyUp_Step1(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_Finish(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FlyDown_Step0(struct ObjectEvent *, struct Sprite *);
extern bool8 MovementAction_FlyDown_Step1(struct ObjectEvent *, struct Sprite *);
extern const MovementActionFunc gMovementActionFuncs_FaceDown[];
extern const MovementActionFunc gMovementActionFuncs_FaceUp[];
extern const MovementActionFunc gMovementActionFuncs_FaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_FaceRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowDiagonalUpLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowDiagonalUpRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowDiagonalDownLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowDiagonalDownRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkSlowRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalDiagonalUpLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalDiagonalUpRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalDiagonalDownLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalDiagonalDownRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkNormalRight[];
extern const MovementActionFunc gMovementActionFuncs_Jump2Down[];
extern const MovementActionFunc gMovementActionFuncs_Jump2Up[];
extern const MovementActionFunc gMovementActionFuncs_Jump2Left[];
extern const MovementActionFunc gMovementActionFuncs_Jump2Right[];
extern const MovementActionFunc gMovementActionFuncs_Delay1[];
extern const MovementActionFunc gMovementActionFuncs_Delay2[];
extern const MovementActionFunc gMovementActionFuncs_Delay4[];
extern const MovementActionFunc gMovementActionFuncs_Delay8[];
extern const MovementActionFunc gMovementActionFuncs_Delay16[];
extern const MovementActionFunc gMovementActionFuncs_WalkFastDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkFastUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkFastLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkFastRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceSlowDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceSlowUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceSlowLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceSlowRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceNormalDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceNormalUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceNormalLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceNormalRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFastDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFastUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFastLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFastRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFasterDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFasterUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFasterLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkInPlaceFasterRight[];
extern const MovementActionFunc gMovementActionFuncs_RideWaterCurrentDown[];
extern const MovementActionFunc gMovementActionFuncs_RideWaterCurrentUp[];
extern const MovementActionFunc gMovementActionFuncs_RideWaterCurrentLeft[];
extern const MovementActionFunc gMovementActionFuncs_RideWaterCurrentRight[];
extern const MovementActionFunc gMovementActionFuncs_WalkFasterDown[];
extern const MovementActionFunc gMovementActionFuncs_WalkFasterUp[];
extern const MovementActionFunc gMovementActionFuncs_WalkFasterLeft[];
extern const MovementActionFunc gMovementActionFuncs_WalkFasterRight[];
extern const MovementActionFunc gMovementActionFuncs_SlideDown[];
extern const MovementActionFunc gMovementActionFuncs_SlideUp[];
extern const MovementActionFunc gMovementActionFuncs_SlideLeft[];
extern const MovementActionFunc gMovementActionFuncs_SlideRight[];
extern const MovementActionFunc gMovementActionFuncs_PlayerRunDown[];
extern const MovementActionFunc gMovementActionFuncs_PlayerRunUp[];
extern const MovementActionFunc gMovementActionFuncs_PlayerRunLeft[];
extern const MovementActionFunc gMovementActionFuncs_PlayerRunRight[];
extern const MovementActionFunc gMovementActionFuncs_StartAnimInDirection[];
extern const MovementActionFunc gMovementActionFuncs_JumpSpecialDown[];
extern const MovementActionFunc gMovementActionFuncs_JumpSpecialUp[];
extern const MovementActionFunc gMovementActionFuncs_JumpSpecialLeft[];
extern const MovementActionFunc gMovementActionFuncs_JumpSpecialRight[];
extern const MovementActionFunc gMovementActionFuncs_FacePlayer[];
extern const MovementActionFunc gMovementActionFuncs_FaceAwayPlayer[];
extern const MovementActionFunc gMovementActionFuncs_LockFacingDirection[];
extern const MovementActionFunc gMovementActionFuncs_UnlockFacingDirection[];
extern const MovementActionFunc gMovementActionFuncs_JumpDown[];
extern const MovementActionFunc gMovementActionFuncs_JumpUp[];
extern const MovementActionFunc gMovementActionFuncs_JumpLeft[];
extern const MovementActionFunc gMovementActionFuncs_JumpRight[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceDown[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceUp[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceRight[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceDownUp[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceUpDown[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceLeftRight[];
extern const MovementActionFunc gMovementActionFuncs_JumpInPlaceRightLeft[];
extern const MovementActionFunc gMovementActionFuncs_FaceOriginalDirection[];
extern const MovementActionFunc gMovementActionFuncs_NurseJoyBowDown[];
extern const MovementActionFunc gMovementActionFuncs_EnableJumpLandingGroundEffect[];
extern const MovementActionFunc gMovementActionFuncs_DisableJumpLandingGroundEffect[];
extern const MovementActionFunc gMovementActionFuncs_DisableAnimation[];
extern const MovementActionFunc gMovementActionFuncs_RestoreAnimation[];
extern const MovementActionFunc gMovementActionFuncs_SetInvisible[];
extern const MovementActionFunc gMovementActionFuncs_SetVisible[];
extern const MovementActionFunc gMovementActionFuncs_EmoteExclamationMark[];
extern const MovementActionFunc gMovementActionFuncs_EmoteQuestionMark[];
extern const MovementActionFunc gMovementActionFuncs_EmoteHeart[];
extern const MovementActionFunc gMovementActionFuncs_RevealTrainer[];
extern const MovementActionFunc gMovementActionFuncs_RockSmashBreak[];
extern const MovementActionFunc gMovementActionFuncs_CutTree[];
extern const MovementActionFunc gMovementActionFuncs_SetFixedPriority[];
extern const MovementActionFunc gMovementActionFuncs_ClearFixedPriority[];
extern const MovementActionFunc gMovementActionFuncs_InitAffineAnim[];
extern const MovementActionFunc gMovementActionFuncs_ClearAffineAnim[];
extern const MovementActionFunc gMovementActionFuncs_HideReflection[];
extern const MovementActionFunc gMovementActionFuncs_ShowReflection[];
extern const MovementActionFunc gMovementActionFuncs_WalkDownStartAffine[];
extern const MovementActionFunc gMovementActionFuncs_WalkDownAffine[];
extern const MovementActionFunc gMovementActionFuncs_WalkLeftAffine[];
extern const MovementActionFunc gMovementActionFuncs_WalkRightAffine[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieFaceDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieFaceUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieFaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieFaceRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieFaceDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieFaceUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieFaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieFaceRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroUnusedAcroActionDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroUnusedAcroActionUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroUnusedAcroActionLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroUnusedAcroActionRight[];
extern const MovementActionFunc gMovementActionFuncs_Figure8[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopFaceDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopFaceUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopFaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopFaceRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieHopRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieJumpDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieJumpUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieJumpLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieJumpRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieInPlaceDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieInPlaceUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieInPlaceLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieInPlaceRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieMoveDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieMoveUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieMoveLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroPopWheelieMoveRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieMoveDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieMoveUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieMoveLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroWheelieMoveRight[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieMoveDown[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieMoveUp[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieMoveLeft[];
extern const MovementActionFunc gMovementActionFuncs_AcroEndWheelieMoveRight[];
extern const MovementActionFunc gMovementActionFuncs_Levitate[];
extern const MovementActionFunc gMovementActionFuncs_StopLevitate[];
extern const MovementActionFunc gMovementActionFuncs_StopLevitateAtTop[];
extern const MovementActionFunc gMovementActionFuncs_LockAnim[];
extern const MovementActionFunc gMovementActionFuncs_UnlockAnim[];
extern const MovementActionFunc gMovementActionFuncs_FlyUp[];
extern const MovementActionFunc gMovementActionFuncs_FlyDown[];
extern u8 GetJumpInPlaceTurnAroundMovementAction(u32 direction);
extern u8 GetJumpMovementAction(u32 direction);
extern u8 GetJumpSpecialMovementAction(u32 direction);
extern u8 GetPlayerRunMovementAction(u32 direction);

const MovementActionFunc *const gMovementActionFuncs[] EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES = {
    [MOVEMENT_ACTION_FACE_DOWN] = gMovementActionFuncs_FaceDown,
    [MOVEMENT_ACTION_FACE_UP] = gMovementActionFuncs_FaceUp,
    [MOVEMENT_ACTION_FACE_LEFT] = gMovementActionFuncs_FaceLeft,
    [MOVEMENT_ACTION_FACE_RIGHT] = gMovementActionFuncs_FaceRight,
    [MOVEMENT_ACTION_WALK_SLOW_DOWN] = gMovementActionFuncs_WalkSlowDown,
    [MOVEMENT_ACTION_WALK_SLOW_UP] = gMovementActionFuncs_WalkSlowUp,
    [MOVEMENT_ACTION_WALK_SLOW_LEFT] = gMovementActionFuncs_WalkSlowLeft,
    [MOVEMENT_ACTION_WALK_SLOW_RIGHT] = gMovementActionFuncs_WalkSlowRight,
    [MOVEMENT_ACTION_WALK_NORMAL_DOWN] = gMovementActionFuncs_WalkNormalDown,
    [MOVEMENT_ACTION_WALK_NORMAL_UP] = gMovementActionFuncs_WalkNormalUp,
    [MOVEMENT_ACTION_WALK_NORMAL_LEFT] = gMovementActionFuncs_WalkNormalLeft,
    [MOVEMENT_ACTION_WALK_NORMAL_RIGHT] = gMovementActionFuncs_WalkNormalRight,
    [MOVEMENT_ACTION_JUMP_2_DOWN] = gMovementActionFuncs_Jump2Down,
    [MOVEMENT_ACTION_JUMP_2_UP] = gMovementActionFuncs_Jump2Up,
    [MOVEMENT_ACTION_JUMP_2_LEFT] = gMovementActionFuncs_Jump2Left,
    [MOVEMENT_ACTION_JUMP_2_RIGHT] = gMovementActionFuncs_Jump2Right,
    [MOVEMENT_ACTION_DELAY_1] = gMovementActionFuncs_Delay1,
    [MOVEMENT_ACTION_DELAY_2] = gMovementActionFuncs_Delay2,
    [MOVEMENT_ACTION_DELAY_4] = gMovementActionFuncs_Delay4,
    [MOVEMENT_ACTION_DELAY_8] = gMovementActionFuncs_Delay8,
    [MOVEMENT_ACTION_DELAY_16] = gMovementActionFuncs_Delay16,
    [MOVEMENT_ACTION_WALK_FAST_DOWN] = gMovementActionFuncs_WalkFastDown,
    [MOVEMENT_ACTION_WALK_FAST_UP] = gMovementActionFuncs_WalkFastUp,
    [MOVEMENT_ACTION_WALK_FAST_LEFT] = gMovementActionFuncs_WalkFastLeft,
    [MOVEMENT_ACTION_WALK_FAST_RIGHT] = gMovementActionFuncs_WalkFastRight,
    [MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN] = gMovementActionFuncs_WalkInPlaceSlowDown,
    [MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP] = gMovementActionFuncs_WalkInPlaceSlowUp,
    [MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT] = gMovementActionFuncs_WalkInPlaceSlowLeft,
    [MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT] = gMovementActionFuncs_WalkInPlaceSlowRight,
    [MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN] = gMovementActionFuncs_WalkInPlaceNormalDown,
    [MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP] = gMovementActionFuncs_WalkInPlaceNormalUp,
    [MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT] = gMovementActionFuncs_WalkInPlaceNormalLeft,
    [MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT] = gMovementActionFuncs_WalkInPlaceNormalRight,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN] = gMovementActionFuncs_WalkInPlaceFastDown,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP] = gMovementActionFuncs_WalkInPlaceFastUp,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT] = gMovementActionFuncs_WalkInPlaceFastLeft,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT] = gMovementActionFuncs_WalkInPlaceFastRight,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN] = gMovementActionFuncs_WalkInPlaceFasterDown,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_UP] = gMovementActionFuncs_WalkInPlaceFasterUp,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_LEFT] = gMovementActionFuncs_WalkInPlaceFasterLeft,
    [MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT] = gMovementActionFuncs_WalkInPlaceFasterRight,
    [MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN] = gMovementActionFuncs_RideWaterCurrentDown,
    [MOVEMENT_ACTION_RIDE_WATER_CURRENT_UP] = gMovementActionFuncs_RideWaterCurrentUp,
    [MOVEMENT_ACTION_RIDE_WATER_CURRENT_LEFT] = gMovementActionFuncs_RideWaterCurrentLeft,
    [MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT] = gMovementActionFuncs_RideWaterCurrentRight,
    [MOVEMENT_ACTION_WALK_FASTER_DOWN] = gMovementActionFuncs_WalkFasterDown,
    [MOVEMENT_ACTION_WALK_FASTER_UP] = gMovementActionFuncs_WalkFasterUp,
    [MOVEMENT_ACTION_WALK_FASTER_LEFT] = gMovementActionFuncs_WalkFasterLeft,
    [MOVEMENT_ACTION_WALK_FASTER_RIGHT] = gMovementActionFuncs_WalkFasterRight,
    [MOVEMENT_ACTION_SLIDE_DOWN] = gMovementActionFuncs_SlideDown,
    [MOVEMENT_ACTION_SLIDE_UP] = gMovementActionFuncs_SlideUp,
    [MOVEMENT_ACTION_SLIDE_LEFT] = gMovementActionFuncs_SlideLeft,
    [MOVEMENT_ACTION_SLIDE_RIGHT] = gMovementActionFuncs_SlideRight,
    [MOVEMENT_ACTION_PLAYER_RUN_DOWN] = gMovementActionFuncs_PlayerRunDown,
    [MOVEMENT_ACTION_PLAYER_RUN_UP] = gMovementActionFuncs_PlayerRunUp,
    [MOVEMENT_ACTION_PLAYER_RUN_LEFT] = gMovementActionFuncs_PlayerRunLeft,
    [MOVEMENT_ACTION_PLAYER_RUN_RIGHT] = gMovementActionFuncs_PlayerRunRight,
    [MOVEMENT_ACTION_START_ANIM_IN_DIRECTION] = gMovementActionFuncs_StartAnimInDirection,
    [MOVEMENT_ACTION_JUMP_SPECIAL_DOWN] = gMovementActionFuncs_JumpSpecialDown,
    [MOVEMENT_ACTION_JUMP_SPECIAL_UP] = gMovementActionFuncs_JumpSpecialUp,
    [MOVEMENT_ACTION_JUMP_SPECIAL_LEFT] = gMovementActionFuncs_JumpSpecialLeft,
    [MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT] = gMovementActionFuncs_JumpSpecialRight,
    [MOVEMENT_ACTION_FACE_PLAYER] = gMovementActionFuncs_FacePlayer,
    [MOVEMENT_ACTION_FACE_AWAY_PLAYER] = gMovementActionFuncs_FaceAwayPlayer,
    [MOVEMENT_ACTION_LOCK_FACING_DIRECTION] = gMovementActionFuncs_LockFacingDirection,
    [MOVEMENT_ACTION_UNLOCK_FACING_DIRECTION] = gMovementActionFuncs_UnlockFacingDirection,
    [MOVEMENT_ACTION_JUMP_DOWN] = gMovementActionFuncs_JumpDown,
    [MOVEMENT_ACTION_JUMP_UP] = gMovementActionFuncs_JumpUp,
    [MOVEMENT_ACTION_JUMP_LEFT] = gMovementActionFuncs_JumpLeft,
    [MOVEMENT_ACTION_JUMP_RIGHT] = gMovementActionFuncs_JumpRight,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN] = gMovementActionFuncs_JumpInPlaceDown,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_UP] = gMovementActionFuncs_JumpInPlaceUp,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT] = gMovementActionFuncs_JumpInPlaceLeft,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT] = gMovementActionFuncs_JumpInPlaceRight,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP] = gMovementActionFuncs_JumpInPlaceDownUp,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN] = gMovementActionFuncs_JumpInPlaceUpDown,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT] = gMovementActionFuncs_JumpInPlaceLeftRight,
    [MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT] = gMovementActionFuncs_JumpInPlaceRightLeft,
    [MOVEMENT_ACTION_FACE_ORIGINAL_DIRECTION] = gMovementActionFuncs_FaceOriginalDirection,
    [MOVEMENT_ACTION_NURSE_JOY_BOW_DOWN] = gMovementActionFuncs_NurseJoyBowDown,
    [MOVEMENT_ACTION_ENABLE_JUMP_LANDING_GROUND_EFFECT] = gMovementActionFuncs_EnableJumpLandingGroundEffect,
    [MOVEMENT_ACTION_DISABLE_JUMP_LANDING_GROUND_EFFECT] = gMovementActionFuncs_DisableJumpLandingGroundEffect,
    [MOVEMENT_ACTION_DISABLE_ANIMATION] = gMovementActionFuncs_DisableAnimation,
    [MOVEMENT_ACTION_RESTORE_ANIMATION] = gMovementActionFuncs_RestoreAnimation,
    [MOVEMENT_ACTION_SET_INVISIBLE] = gMovementActionFuncs_SetInvisible,
    [MOVEMENT_ACTION_SET_VISIBLE] = gMovementActionFuncs_SetVisible,
    [MOVEMENT_ACTION_EMOTE_EXCLAMATION_MARK] = gMovementActionFuncs_EmoteExclamationMark,
    [MOVEMENT_ACTION_EMOTE_QUESTION_MARK] = gMovementActionFuncs_EmoteQuestionMark,
    [MOVEMENT_ACTION_EMOTE_HEART] = gMovementActionFuncs_EmoteHeart,
    [MOVEMENT_ACTION_REVEAL_TRAINER] = gMovementActionFuncs_RevealTrainer,
    [MOVEMENT_ACTION_ROCK_SMASH_BREAK] = gMovementActionFuncs_RockSmashBreak,
    [MOVEMENT_ACTION_CUT_TREE] = gMovementActionFuncs_CutTree,
    [MOVEMENT_ACTION_SET_FIXED_PRIORITY] = gMovementActionFuncs_SetFixedPriority,
    [MOVEMENT_ACTION_CLEAR_FIXED_PRIORITY] = gMovementActionFuncs_ClearFixedPriority,
    [MOVEMENT_ACTION_INIT_AFFINE_ANIM] = gMovementActionFuncs_InitAffineAnim,
    [MOVEMENT_ACTION_CLEAR_AFFINE_ANIM] = gMovementActionFuncs_ClearAffineAnim,
    [MOVEMENT_ACTION_HIDE_REFLECTION] = gMovementActionFuncs_HideReflection,
    [MOVEMENT_ACTION_SHOW_REFLECTION] = gMovementActionFuncs_ShowReflection,
    [MOVEMENT_ACTION_WALK_DOWN_START_AFFINE] = gMovementActionFuncs_WalkDownStartAffine,
    [MOVEMENT_ACTION_WALK_DOWN_AFFINE] = gMovementActionFuncs_WalkDownAffine,
    [MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN] = gMovementActionFuncs_AcroWheelieFaceDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP] = gMovementActionFuncs_AcroWheelieFaceUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT] = gMovementActionFuncs_AcroWheelieFaceLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT] = gMovementActionFuncs_AcroWheelieFaceRight,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN] = gMovementActionFuncs_AcroPopWheelieDown,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP] = gMovementActionFuncs_AcroPopWheelieUp,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT] = gMovementActionFuncs_AcroPopWheelieLeft,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT] = gMovementActionFuncs_AcroPopWheelieRight,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN] = gMovementActionFuncs_AcroEndWheelieFaceDown,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP] = gMovementActionFuncs_AcroEndWheelieFaceUp,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT] = gMovementActionFuncs_AcroEndWheelieFaceLeft,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT] = gMovementActionFuncs_AcroEndWheelieFaceRight,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN] = gMovementActionFuncs_AcroWheelieHopFaceDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP] = gMovementActionFuncs_AcroWheelieHopFaceUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT] = gMovementActionFuncs_AcroWheelieHopFaceLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT] = gMovementActionFuncs_AcroWheelieHopFaceRight,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN] = gMovementActionFuncs_AcroWheelieHopDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_UP] = gMovementActionFuncs_AcroWheelieHopUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_LEFT] = gMovementActionFuncs_AcroWheelieHopLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT] = gMovementActionFuncs_AcroWheelieHopRight,
    [MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN] = gMovementActionFuncs_AcroWheelieJumpDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_UP] = gMovementActionFuncs_AcroWheelieJumpUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_LEFT] = gMovementActionFuncs_AcroWheelieJumpLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT] = gMovementActionFuncs_AcroWheelieJumpRight,
    [MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN] = gMovementActionFuncs_AcroWheelieInPlaceDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP] = gMovementActionFuncs_AcroWheelieInPlaceUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT] = gMovementActionFuncs_AcroWheelieInPlaceLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT] = gMovementActionFuncs_AcroWheelieInPlaceRight,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN] = gMovementActionFuncs_AcroPopWheelieMoveDown,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_UP] = gMovementActionFuncs_AcroPopWheelieMoveUp,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_LEFT] = gMovementActionFuncs_AcroPopWheelieMoveLeft,
    [MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT] = gMovementActionFuncs_AcroPopWheelieMoveRight,
    [MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN] = gMovementActionFuncs_AcroWheelieMoveDown,
    [MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_UP] = gMovementActionFuncs_AcroWheelieMoveUp,
    [MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_LEFT] = gMovementActionFuncs_AcroWheelieMoveLeft,
    [MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT] = gMovementActionFuncs_AcroWheelieMoveRight,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN] = gMovementActionFuncs_AcroEndWheelieMoveDown,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_UP] = gMovementActionFuncs_AcroEndWheelieMoveUp,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_LEFT] = gMovementActionFuncs_AcroEndWheelieMoveLeft,
    [MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT] = gMovementActionFuncs_AcroEndWheelieMoveRight,
    [MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_UP_LEFT] = gMovementActionFuncs_WalkNormalDiagonalUpLeft,
    [MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_UP_RIGHT] = gMovementActionFuncs_WalkNormalDiagonalUpRight,
    [MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_DOWN_LEFT] = gMovementActionFuncs_WalkNormalDiagonalDownLeft,
    [MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_DOWN_RIGHT] = gMovementActionFuncs_WalkNormalDiagonalDownRight,
    [MOVEMENT_ACTION_WALK_SLOW_DIAGONAL_UP_LEFT] = gMovementActionFuncs_WalkSlowDiagonalUpLeft,
    [MOVEMENT_ACTION_WALK_SLOW_DIAGONAL_UP_RIGHT] = gMovementActionFuncs_WalkSlowDiagonalUpRight,
    [MOVEMENT_ACTION_WALK_SLOW_DIAGONAL_DOWN_LEFT] = gMovementActionFuncs_WalkSlowDiagonalDownLeft,
    [MOVEMENT_ACTION_WALK_SLOW_DIAGONAL_DOWN_RIGHT] = gMovementActionFuncs_WalkSlowDiagonalDownRight,
    [MOVEMENT_ACTION_LOCK_ANIM] = gMovementActionFuncs_LockAnim,
    [MOVEMENT_ACTION_UNLOCK_ANIM] = gMovementActionFuncs_UnlockAnim,
    [MOVEMENT_ACTION_WALK_LEFT_AFFINE] = gMovementActionFuncs_WalkLeftAffine,
    [MOVEMENT_ACTION_WALK_RIGHT_AFFINE] = gMovementActionFuncs_WalkRightAffine,
    [MOVEMENT_ACTION_LEVITATE] = gMovementActionFuncs_Levitate,
    [MOVEMENT_ACTION_STOP_LEVITATE] = gMovementActionFuncs_StopLevitate,
    [MOVEMENT_ACTION_STOP_LEVITATE_AT_TOP] = gMovementActionFuncs_StopLevitateAtTop,
    [MOVEMENT_ACTION_FIGURE_8] = gMovementActionFuncs_Figure8,
    [MOVEMENT_ACTION_FLY_UP] = gMovementActionFuncs_FlyUp,
    [MOVEMENT_ACTION_FLY_DOWN] = gMovementActionFuncs_FlyDown,
};

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceDown,
    MovementAction_FaceDown_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceUp,
    MovementAction_FaceUp_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceLeft,
    MovementAction_FaceLeft_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceRight,
    MovementAction_FaceRight_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_STATIC_U8_FUNC_TABLE(sDirectionAnimFuncsBySpeed,
    GetJumpInPlaceTurnAroundMovementAction,
    GetJumpMovementAction,
    GetJumpMovementAction,
    GetJumpSpecialMovementAction,
    GetPlayerRunMovementAction,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowDiagonalUpLeft,
    MovementAction_WalkSlowDiagonalUpLeft_Step0,
    sub_08093554,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowDiagonalUpRight,
    MovementAction_WalkSlowDiagonalUpRight_Step0,
    MovementAction_WalkSlowDiagonalUpRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowDiagonalDownLeft,
    MovementAction_WalkSlowDiagonalDownLeft_Step0,
    MovementAction_WalkSlowDiagonalDownLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowDiagonalDownRight,
    MovementAction_WalkSlowDiagonalDownRight_Step0,
    MovementAction_WalkSlowDiagonalDownRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowDown,
    MovementAction_WalkSlowDown_Step0,
    MovementAction_WalkSlowDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowUp,
    MovementAction_WalkSlowUp_Step0,
    MovementAction_WalkSlowUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowLeft,
    MovementAction_WalkSlowLeft_Step0,
    MovementAction_WalkSlowLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkSlowRight,
    MovementAction_WalkSlowRight_Step0,
    MovementAction_WalkSlowRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalDiagonalUpLeft,
    MovementAction_WalkNormalDiagonalUpLeft_Step0,
    MovementAction_WalkNormalDiagonalUpLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalDiagonalUpRight,
    MovementAction_WalkNormalDiagonalUpRight_Step0,
    MovementAction_WalkNormalDiagonalUpRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalDiagonalDownLeft,
    MovementAction_WalkNormalDiagonalDownLeft_Step0,
    MovementAction_WalkNormalDiagonalDownLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalDiagonalDownRight,
    MovementAction_WalkNormalDiagonalDownRight_Step0,
    MovementAction_WalkNormalDiagonalDownRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalDown,
    MovementAction_WalkNormalDown_Step0,
    MovementAction_WalkNormalDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalUp,
    MovementAction_WalkNormalUp_Step0,
    MovementAction_WalkNormalUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalLeft,
    MovementAction_WalkNormalLeft_Step0,
    MovementAction_WalkNormalLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkNormalRight,
    MovementAction_WalkNormalRight_Step0,
    MovementAction_WalkNormalRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_STATIC_S16_TABLE(sJumpInitDisplacements,
    0, 1, 1,
);
MOVEMENT_ACTION_STATIC_S16_TABLE(sJumpDisplacements,
    0, 0, 1,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Jump2Down,
    MovementAction_Jump2Down_Step0,
    MovementAction_Jump2Down_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Jump2Up,
    MovementAction_Jump2Up_Step0,
    MovementAction_Jump2Up_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Jump2Left,
    MovementAction_Jump2Left_Step0,
    MovementAction_Jump2Left_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Jump2Right,
    MovementAction_Jump2Right_Step0,
    MovementAction_Jump2Right_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Delay1,
    MovementAction_Delay1_Step0,
    MovementAction_Delay_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Delay2,
    MovementAction_Delay2_Step0,
    MovementAction_Delay_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Delay4,
    MovementAction_Delay4_Step0,
    MovementAction_Delay_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Delay8,
    MovementAction_Delay8_Step0,
    MovementAction_Delay_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Delay16,
    MovementAction_Delay16_Step0,
    MovementAction_Delay_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFastDown,
    MovementAction_WalkFastDown_Step0,
    MovementAction_WalkFastDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFastUp,
    MovementAction_WalkFastUp_Step0,
    MovementAction_WalkFastUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFastLeft,
    MovementAction_WalkFastLeft_Step0,
    MovementAction_WalkFastLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFastRight,
    MovementAction_WalkFastRight_Step0,
    MovementAction_WalkFastRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceSlowDown,
    MovementAction_WalkInPlaceSlowDown_Step0,
    MovementAction_WalkInPlaceSlow_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceSlowUp,
    MovementAction_WalkInPlaceSlowUp_Step0,
    MovementAction_WalkInPlaceSlow_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceSlowLeft,
    MovementAction_WalkInPlaceSlowLeft_Step0,
    MovementAction_WalkInPlaceSlow_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceSlowRight,
    MovementAction_WalkInPlaceSlowRight_Step0,
    MovementAction_WalkInPlaceSlow_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceNormalDown,
    MovementAction_WalkInPlaceNormalDown_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceNormalUp,
    MovementAction_WalkInPlaceNormalUp_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceNormalLeft,
    MovementAction_WalkInPlaceNormalLeft_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceNormalRight,
    MovementAction_WalkInPlaceNormalRight_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFastDown,
    MovementAction_WalkInPlaceFastDown_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFastUp,
    MovementAction_WalkInPlaceFastUp_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFastLeft,
    MovementAction_WalkInPlaceFastLeft_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFastRight,
    MovementAction_WalkInPlaceFastRight_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFasterDown,
    MovementAction_WalkInPlaceFasterDown_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFasterUp,
    MovementAction_WalkInPlaceFasterUp_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFasterLeft,
    MovementAction_WalkInPlaceFasterLeft_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkInPlaceFasterRight,
    MovementAction_WalkInPlaceFasterRight_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RideWaterCurrentDown,
    MovementAction_RideWaterCurrentDown_Step0,
    MovementAction_RideWaterCurrentDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RideWaterCurrentUp,
    MovementAction_RideWaterCurrentUp_Step0,
    MovementAction_RideWaterCurrentUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RideWaterCurrentLeft,
    MovementAction_RideWaterCurrentLeft_Step0,
    MovementAction_RideWaterCurrentLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RideWaterCurrentRight,
    MovementAction_RideWaterCurrentRight_Step0,
    MovementAction_RideWaterCurrentRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFasterDown,
    MovementAction_WalkFasterDown_Step0,
    MovementAction_WalkFasterDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFasterUp,
    MovementAction_WalkFasterUp_Step0,
    MovementAction_WalkFasterUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFasterLeft,
    MovementAction_WalkFasterLeft_Step0,
    MovementAction_WalkFasterLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkFasterRight,
    MovementAction_WalkFasterRight_Step0,
    MovementAction_WalkFasterRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SlideDown,
    MovementAction_SlideDown_Step0,
    MovementAction_SlideDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SlideUp,
    MovementAction_SlideUp_Step0,
    MovementAction_SlideUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SlideLeft,
    MovementAction_SlideLeft_Step0,
    MovementAction_SlideLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SlideRight,
    MovementAction_SlideRight_Step0,
    MovementAction_SlideRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_PlayerRunDown,
    MovementAction_PlayerRunDown_Step0,
    MovementAction_PlayerRunDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_PlayerRunUp,
    MovementAction_PlayerRunUp_Step0,
    MovementAction_PlayerRunUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_PlayerRunLeft,
    MovementAction_PlayerRunLeft_Step0,
    MovementAction_PlayerRunLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_PlayerRunRight,
    MovementAction_PlayerRunRight_Step0,
    MovementAction_PlayerRunRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_StartAnimInDirection,
    MovementAction_StartAnimInDirection_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpSpecialDown,
    MovementAction_JumpSpecialDown_Step0,
    MovementAction_JumpSpecialDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpSpecialUp,
    MovementAction_JumpSpecialUp_Step0,
    MovementAction_JumpSpecialUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpSpecialLeft,
    MovementAction_JumpSpecialLeft_Step0,
    MovementAction_JumpSpecialLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpSpecialRight,
    MovementAction_JumpSpecialRight_Step0,
    MovementAction_JumpSpecialRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FacePlayer,
    MovementAction_FacePlayer_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceAwayPlayer,
    MovementAction_FaceAwayPlayer_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_LockFacingDirection,
    MovementAction_LockFacingDirection_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_UnlockFacingDirection,
    MovementAction_UnlockFacingDirection_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpDown,
    MovementAction_JumpDown_Step0,
    MovementAction_JumpDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpUp,
    MovementAction_JumpUp_Step0,
    MovementAction_JumpUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpLeft,
    MovementAction_JumpLeft_Step0,
    MovementAction_JumpLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpRight,
    MovementAction_JumpRight_Step0,
    MovementAction_JumpRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceDown,
    MovementAction_JumpInPlaceDown_Step0,
    MovementAction_JumpInPlaceDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceUp,
    MovementAction_JumpInPlaceUp_Step0,
    MovementAction_JumpInPlaceUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceLeft,
    MovementAction_JumpInPlaceLeft_Step0,
    MovementAction_JumpInPlaceLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceRight,
    MovementAction_JumpInPlaceRight_Step0,
    MovementAction_JumpInPlaceRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceDownUp,
    MovementAction_JumpInPlaceDownUp_Step0,
    MovementAction_JumpInPlaceDownUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceUpDown,
    MovementAction_JumpInPlaceUpDown_Step0,
    MovementAction_JumpInPlaceUpDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceLeftRight,
    MovementAction_JumpInPlaceLeftRight_Step0,
    MovementAction_JumpInPlaceLeftRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_JumpInPlaceRightLeft,
    MovementAction_JumpInPlaceRightLeft_Step0,
    MovementAction_JumpInPlaceRightLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_FaceOriginalDirection,
    MovementAction_FaceOriginalDirection_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_NurseJoyBowDown,
    MovementAction_NurseJoyBowDown_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_EnableJumpLandingGroundEffect,
    MovementAction_EnableJumpLandingGroundEffect_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_DisableJumpLandingGroundEffect,
    MovementAction_DisableJumpLandingGroundEffect_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_DisableAnimation,
    MovementAction_DisableAnimation_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RestoreAnimation,
    MovementAction_RestoreAnimation_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SetInvisible,
    MovementAction_SetInvisible_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SetVisible,
    MovementAction_SetVisible_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_EmoteExclamationMark,
    MovementAction_EmoteExclamationMark_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_EmoteQuestionMark,
    MovementAction_EmoteQuestionMark_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_EmoteHeart,
    MovementAction_EmoteHeart_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RevealTrainer,
    MovementAction_RevealTrainer_Step0,
    MovementAction_RevealTrainer_Step1,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_RockSmashBreak,
    MovementAction_RockSmashBreak_Step0,
    MovementAction_RockSmashBreak_Step1,
    MovementAction_RockSmashBreak_Step2,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_CutTree,
    MovementAction_CutTree_Step0,
    MovementAction_CutTree_Step1,
    MovementAction_CutTree_Step2,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_SetFixedPriority,
    MovementAction_SetFixedPriority_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_ClearFixedPriority,
    MovementAction_ClearFixedPriority_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_InitAffineAnim,
    MovementAction_InitAffineAnim_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_ClearAffineAnim,
    MovementAction_ClearAffineAnim_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_HideReflection,
    MovementAction_HideReflection_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_ShowReflection,
    MovementAction_Unknown2_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkDownStartAffine,
    MovementAction_WalkDownStartAffine_Step0,
    MovementAction_WalkDownStartAffine_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkDownAffine,
    MovementAction_WalkDownAffine_Step0,
    MovementAction_WalkDownAffine_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkLeftAffine,
    MovementAction_WalkLeftAffine_Step0,
    MovementAction_WalkLeftAffine_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_WalkRightAffine,
    MovementAction_WalkRightAffine_Step0,
    MovementAction_WalkRightAffine_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieFaceDown,
    MovementAction_AcroWheelieFaceDown_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieFaceUp,
    MovementAction_AcroWheelieFaceUp_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieFaceLeft,
    MovementAction_AcroWheelieFaceLeft_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieFaceRight,
    MovementAction_AcroWheelieFaceRight_Step0,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieDown,
    MovementAction_AcroPopWheelieDown_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieUp,
    MovementAction_AcroPopWheelieUp_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieLeft,
    MovementAction_AcroPopWheelieLeft_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieRight,
    MovementAction_AcroPopWheelieRight_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieFaceDown,
    MovementAction_AcroEndWheelieFaceDown_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieFaceUp,
    MovementAction_AcroEndWheelieFaceUp_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieFaceLeft,
    sub_08095388,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieFaceRight,
    MovementAction_AcroEndWheelieFaceRight_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroUnusedAcroActionDown,
    MovementAction_UnusedAcroActionDown_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroUnusedAcroActionUp,
    MovementAction_UnusedAcroActionUp_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroUnusedAcroActionLeft,
    MovementAction_UnusedAcroActionLeft_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroUnusedAcroActionRight,
    MovementAction_UnusedAcroActionRight_Step0,
    MovementAction_WaitSpriteAnim,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Figure8,
    MovementAction_Figure8_Step0,
    sub_080954D4,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopFaceDown,
    MovementAction_AcroWheelieHopFaceDown_Step0,
    MovementAction_AcroWheelieHopFaceDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopFaceUp,
    MovementAction_AcroWheelieHopFaceUp_Step0,
    MovementAction_AcroWheelieHopFaceUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopFaceLeft,
    MovementAction_AcroWheelieHopFaceLeft_Step0,
    MovementAction_AcroWheelieHopFaceLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopFaceRight,
    MovementAction_AcroWheelieHopFaceRight_Step0,
    MovementAction_AcroWheelieHopFaceRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopDown,
    MovementAction_AcroWheelieHopDown_Step0,
    MovementAction_AcroWheelieHopDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopUp,
    MovementAction_AcroWheelieHopUp_Step0,
    MovementAction_AcroWheelieHopUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopLeft,
    MovementAction_AcroWheelieHopLeft_Step0,
    MovementAction_AcroWheelieHopLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieHopRight,
    MovementAction_AcroWheelieHopRight_Step0,
    MovementAction_AcroWheelieHopRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieJumpDown,
    MovementAction_AcroWheelieJumpDown_Step0,
    MovementAction_AcroWheelieJumpDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieJumpUp,
    MovementAction_AcroWheelieJumpUp_Step0,
    MovementAction_AcroWheelieJumpUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieJumpLeft,
    MovementAction_AcroWheelieJumpLeft_Step0,
    MovementAction_AcroWheelieJumpLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieJumpRight,
    MovementAction_AcroWheelieJumpRight_Step0,
    MovementAction_AcroWheelieJumpRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieInPlaceDown,
    MovementAction_AcroWheelieInPlaceDown_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieInPlaceUp,
    MovementAction_AcroWheelieInPlaceUp_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieInPlaceLeft,
    MovementAction_AcroWheelieInPlaceLeft_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieInPlaceRight,
    MovementAction_AcroWheelieInPlaceRight_Step0,
    MovementAction_WalkInPlace_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieMoveDown,
    sub_08095A70_jp,
    MovementAction_AcroPopWheelieMoveDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieMoveUp,
    sub_08095AB0_jp,
    MovementAction_AcroPopWheelieMoveUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieMoveLeft,
    sub_08095AF0_jp,
    MovementAction_AcroPopWheelieMoveLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroPopWheelieMoveRight,
    sub_08095B30,
    MovementAction_AcroPopWheelieMoveRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieMoveDown,
    MovementAction_AcroWheelieMoveDown_Step0,
    MovementAction_AcroWheelieMoveDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieMoveUp,
    MovementAction_AcroWheelieMoveUp_Step0,
    MovementAction_AcroWheelieMoveUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieMoveLeft,
    MovementAction_AcroWheelieMoveLeft_Step0,
    MovementAction_AcroWheelieMoveLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroWheelieMoveRight,
    MovementAction_AcroWheelieMoveRight_Step0,
    MovementAction_AcroWheelieMoveRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieMoveDown,
    MovementAction_AcroEndWheelieMoveDown_Step0,
    MovementAction_AcroEndWheelieMoveDown_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieMoveUp,
    MovementAction_AcroEndWheelieMoveUp_Step0,
    MovementAction_AcroEndWheelieMoveUp_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieMoveLeft,
    MovementAction_AcroEndWheelieMoveLeft_Step0,
    MovementAction_AcroEndWheelieMoveLeft_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_AcroEndWheelieMoveRight,
    MovementAction_AcroEndWheelieMoveRight_Step0,
    MovementAction_AcroEndWheelieMoveRight_Step1,
    MovementAction_PauseSpriteAnim,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_Levitate,
    MovementAction_Levitate_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_StopLevitate,
    MovementAction_StopLevitate_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_FUNC_TABLE(gMovementActionFuncs_StopLevitateAtTop,
    MovementAction_DestroyExtraTaskIfAtTop_Step0,
    sub_08095E28,
);

#undef MOVEMENT_ACTION_STATIC_S16_TABLE
#undef MOVEMENT_ACTION_STATIC_U8_FUNC_TABLE
#undef MOVEMENT_ACTION_FUNC_TABLE

#define MOVEMENT_ACTION_TAIL_FUNC_TABLE(name, ...) \
    const MovementActionFunc name[] EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES_TAIL = { __VA_ARGS__ }

MOVEMENT_ACTION_TAIL_FUNC_TABLE(gMovementActionFuncs_LockAnim,
    MovementAction_StoreAndLockAnim_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_TAIL_FUNC_TABLE(gMovementActionFuncs_UnlockAnim,
    MovementAction_FreeAndUnlockAnim_Step0,
    sub_08095E28,
);

MOVEMENT_ACTION_TAIL_FUNC_TABLE(gMovementActionFuncs_FlyUp,
    MovementAction_FlyUp_Step0,
    MovementAction_FlyUp_Step1,
    MovementAction_Finish,
);

MOVEMENT_ACTION_TAIL_FUNC_TABLE(gMovementActionFuncs_FlyDown,
    MovementAction_FlyDown_Step0,
    MovementAction_FlyDown_Step1,
    MovementAction_Finish,
);

#undef MOVEMENT_ACTION_TAIL_FUNC_TABLE
