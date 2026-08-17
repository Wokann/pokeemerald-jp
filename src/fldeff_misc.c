#include "global.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "constants/field_effects.h"
#include "event_data.h"
#include "fieldmap.h"
#include "event_object_movement.h"
#include "script.h"
#include "field_player_avatar.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "secret_base.h"
#include "task.h"
extern void StartSecretBaseCaveFieldEffect(void);
extern void StartSecretBaseShrubFieldEffect(void);
extern void StartSecretBaseTreeFieldEffect(void);

#define tMetatileID data[0]
#define tX data[0]
#define tY data[1]
#define tState data[2]
extern void Task_SecretBasePCTurnOn(u8 taskId);
extern void Task_PopSecretBaseBalloon(u8 taskId);
extern void Task_SecretBaseMusicNoteMatSound(u8 taskId);
extern void Task_FieldPoisonEffect(u8 taskId);
extern void sub_080FA66C(void);
extern void sub_080FA500(u8 taskId);
static __attribute__((naked)) void sub_080FA4B4(void (*func)(u8), u16 x, u16 y, u8 z);
extern void Task_WateringBerryTreeAnim_0(u8 taskId);
extern void Task_WateringBerryTreeAnim_1(u8 taskId);
extern void Task_WateringBerryTreeAnim_2(u8 taskId);
extern void Task_WateringBerryTreeAnim_3(u8 taskId);
extern u8 sub_0808B634(void);
extern void sub_0808BB8C(u8 direction);
extern u8 sub_08092F08(u32 direction);
extern void FieldCallback_SecretBaseCave(void);
extern void FieldCallback_SecretBaseTree(void);
extern void FieldCallback_SecretBaseShrub(void);
extern const u8 SecretBase_EventScript_Cave[];
extern const u8 SecretBase_EventScript_Tree[];
extern const u8 SecretBase_EventScript_Shrub[];

#include "fldeff_misc.h"

void sub_080FA43C(u16 x, u16 y, u8 z)
{
    sub_080FA4B4(sub_080FA500, x, y, z);
}

void sub_080FA464(u16 x, u16 y, u8 z)
{
    sub_080FA4B4(sub_080FA66C, x, y, z);
}

bool32 sub_080FA48C(void)
{
    return FuncIsActiveTask(sub_080FA500);
}

bool32 FldEffPoison_IsActive(void)
{
    return FuncIsActiveTask(sub_080FA66C);
}

static __attribute__((naked)) void sub_080FA4B4(void (*func)(u8), u16 x, u16 y, u8 z)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r4, r1, #0x10\n\t"
        "	adds r5, r4, #0\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r1, _080FA4FC\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r0, r1\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	movs r0, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _080FA4E2\n\t"
        "	adds r0, r4, #0\n\t"
        "_080FA4E2:\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	movs r0, #0x14\n\t"
        "	cmp r5, #0\n\t"
        "	beq _080FA4EC\n\t"
        "	adds r0, r5, #0\n\t"
        "_080FA4EC:\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl _call_via_r1\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FA4FC: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080FA500(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080FA524\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080FA580\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080FA528\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FA532\n\t"
        "	b _080FA64E\n\t"
        "	.align 2, 0\n\t"
        "_080FA524: .4byte gTasks\n\t"
        "_080FA528:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080FA5A2\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080FA604\n\t"
        "	b _080FA64E\n\t"
        "_080FA532:\n\t"
        "	movs r0, #0x78\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	movs r0, #0x50\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	movs r0, #0x51\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuRegBits\n\t"
        "	ldrh r1, [r4, #0xe]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	ldrh r1, [r4, #0x12]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x44\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x48\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x4a\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	b _080FA65E\n\t"
        "_080FA580:\n\t"
        "	movs r0, #0x50\n\t"
        "	bl GetGpuReg\n\t"
        "	strh r0, [r4, #0x16]\n\t"
        "	movs r0, #0x54\n\t"
        "	bl GetGpuReg\n\t"
        "	strh r0, [r4, #0x18]\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0xbf\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #0x10\n\t"
        "	bl SetGpuReg\n\t"
        "	b _080FA65E\n\t"
        "_080FA5A2:\n\t"
        "	ldrh r0, [r4, #0xe]\n\t"
        "	ldrh r1, [r4, #0xa]\n\t"
        "	subs r0, r0, r1\n\t"
        "	movs r5, #0\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	ldrh r2, [r4, #0x10]\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r1, [r4, #0x10]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	ble _080FA5C0\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xef\n\t"
        "	ble _080FA5E6\n\t"
        "_080FA5C0:\n\t"
        "	strh r5, [r4, #0xe]\n\t"
        "	movs r0, #0xf0\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	ldrh r1, [r4, #0x16]\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl BlendPalettes\n\t"
        "	ldr r0, _080FA600\n\t"
        "	strh r5, [r0]\n\t"
        "_080FA5E6:\n\t"
        "	ldrh r1, [r4, #0xe]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r1, #0xe\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	b _080FA648\n\t"
        "	.align 2, 0\n\t"
        "_080FA600: .4byte gPlttBufferFaded\n\t"
        "_080FA604:\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	ldrh r1, [r4, #0xc]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	ldrh r2, [r4, #0x14]\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r1, [r4, #0x14]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	ble _080FA620\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x9f\n\t"
        "	ble _080FA632\n\t"
        "_080FA620:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	movs r0, #0xa0\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0\n\t"
        "	bl ClearGpuRegBits\n\t"
        "_080FA632:\n\t"
        "	ldrh r1, [r4, #0x12]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x44\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "_080FA648:\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080FA664\n\t"
        "	b _080FA65E\n\t"
        "_080FA64E:\n\t"
        "	ldrh r1, [r4, #0x16]\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _080FA664\n\t"
        "_080FA65E:\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_080FA664:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080FA66C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080FA690\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	cmp r1, #1\n\t"
        "	beq _080FA6A8\n\t"
        "	cmp r1, #1\n\t"
        "	bgt _080FA694\n\t"
        "	cmp r1, #0\n\t"
        "	beq _080FA69E\n\t"
        "	b _080FA79C\n\t"
        "	.align 2, 0\n\t"
        "_080FA690: .4byte gTasks\n\t"
        "_080FA694:\n\t"
        "	cmp r1, #2\n\t"
        "	beq _080FA6F6\n\t"
        "	cmp r1, #3\n\t"
        "	beq _080FA748\n\t"
        "	b _080FA79C\n\t"
        "_080FA69E:\n\t"
        "	ldr r0, _080FA6A4\n\t"
        "	strh r1, [r0]\n\t"
        "	b _080FA7BE\n\t"
        "	.align 2, 0\n\t"
        "_080FA6A4: .4byte gPlttBufferFaded\n\t"
        "_080FA6A8:\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r4, #0xe]\n\t"
        "	movs r0, #0xf0\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	strh r1, [r4, #0x12]\n\t"
        "	movs r0, #0xa0\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuRegBits\n\t"
        "	ldrh r1, [r4, #0xe]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	ldrh r1, [r4, #0x12]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x44\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x48\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x4a\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	b _080FA7BE\n\t"
        "_080FA6F6:\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	ldrh r2, [r4, #0x12]\n\t"
        "	adds r1, r0, r2\n\t"
        "	strh r1, [r4, #0x12]\n\t"
        "	ldrh r2, [r4, #0x14]\n\t"
        "	subs r0, r2, r0\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	cmp r1, #0x4f\n\t"
        "	bgt _080FA714\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x51\n\t"
        "	bgt _080FA72C\n\t"
        "_080FA714:\n\t"
        "	movs r0, #0x50\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	movs r0, #0x51\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0xbf\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #0x10\n\t"
        "	bl SetGpuReg\n\t"
        "_080FA72C:\n\t"
        "	ldrh r1, [r4, #0x12]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x44\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x50\n\t"
        "	bne _080FA7C4\n\t"
        "	b _080FA7BE\n\t"
        "_080FA748:\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	ldrh r2, [r4, #0xe]\n\t"
        "	adds r1, r0, r2\n\t"
        "	strh r1, [r4, #0xe]\n\t"
        "	ldrh r2, [r4, #0x10]\n\t"
        "	subs r0, r2, r0\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	cmp r1, #0x77\n\t"
        "	bgt _080FA766\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x78\n\t"
        "	bgt _080FA77C\n\t"
        "_080FA766:\n\t"
        "	movs r0, #0x78\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	subs r0, #0x79\n\t"
        "	movs r1, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	bl BlendPalettes\n\t"
        "	ldr r1, _080FA798\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "_080FA77C:\n\t"
        "	ldrh r1, [r4, #0xe]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r1, #0xe\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x78\n\t"
        "	bne _080FA7C4\n\t"
        "	b _080FA7BE\n\t"
        "	.align 2, 0\n\t"
        "_080FA798: .4byte gPlttBufferFaded\n\t"
        "_080FA79C:\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0\n\t"
        "	bl ClearGpuRegBits\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _080FA7C4\n\t"
        "_080FA7BE:\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_080FA7C4:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void SetCurrentSecretBase(void)
{
    SetCurSecretBaseIdFromPosition(&gPlayerFacingPosition, gMapHeader.events);
    TrySetCurSecretBaseIndex();
}


void AdjustSecretPowerSpritePixelOffsets(void)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 16;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
    else
    {
        switch (gFieldEffectArguments[1])
        {
        case DIR_SOUTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 40;
            break;
        case DIR_NORTH:
            gFieldEffectArguments[5] = 8;
            gFieldEffectArguments[6] = 8;
            break;
        case DIR_WEST:
            gFieldEffectArguments[5] = -8;
            gFieldEffectArguments[6] = 24;
            break;
        case DIR_EAST:
            gFieldEffectArguments[5] = 24;
            gFieldEffectArguments[6] = 24;
            break;
        }
    }
}


bool8 SetUpFieldMove_SecretPower(void)
{
    u8 mb;

    CheckPlayerHasSecretBase();

    if (gSpecialVar_Result == 1 || (u8)GetPlayerFacingDirection() != DIR_NORTH)
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    mb = MapGridGetMetatileBehaviorAt(gPlayerFacingPosition.x, gPlayerFacingPosition.y);

    if ((u8)MetatileBehavior_IsSecretBaseCave(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseCave;
        return TRUE;
    }

    if ((u8)MetatileBehavior_IsSecretBaseTree(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseShrub;
        return TRUE;
    }

    if ((u8)MetatileBehavior_IsSecretBaseShrub(mb) == TRUE)
    {
        SetCurrentSecretBase();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_SecretBaseTree;
        return TRUE;
    }

    return FALSE;
}


void FieldCallback_SecretBaseCave(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_Tree);
}


bool8 FldEff_UseSecretPowerCave(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseCaveFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseCaveFieldEffect;

    return FALSE;
}

void StartSecretBaseCaveFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_CAVE);
    FieldEffectStart(FLDEFF_SECRET_POWER_CAVE);
}

__attribute__((naked)) bool8 FldEff_SecretPowerCave()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl AdjustSecretPowerSpritePixelOffsets\n\t"
        "	ldr r0, _080FA9EC\n\t"
        "	ldr r3, _080FA9F0\n\t"
        "	ldr r1, _080FA9F4\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #0x17\n\t"
        "	ldr r4, _080FA9F8\n\t"
        "	ldr r3, [r4, #0x14]\n\t"
        "	adds r1, r1, r3\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	ldr r3, [r4, #0x18]\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	movs r3, #0x94\n\t"
        "	bl CreateSprite\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080FA9EC: .4byte gUnknown_856A1E4\n\t"
        "_080FA9F0: .4byte gSprites\n\t"
        "_080FA9F4: .4byte gPlayerAvatar\n\t"
        "_080FA9F8: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CaveEntranceSpriteCallback1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0x83\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	ldr r0, _080FAA14\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FAA14: .4byte ShrubEntranceSpriteCallback2 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShrubEntranceSpriteCallback2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldrh r2, [r1, #0x2e]\n\t"
        "	movs r3, #0x2e\n\t"
        "	ldrsh r0, [r1, r3]\n\t"
        "	cmp r0, #0x27\n\t"
        "	bgt _080FAA38\n\t"
        "	adds r0, r2, #1\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x14\n\t"
        "	bne _080FAA40\n\t"
        "	bl ToggleSecretBaseEntranceMetatile\n\t"
        "	b _080FAA40\n\t"
        "_080FAA38:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	ldr r0, _080FAA44\n\t"
        "	str r0, [r1, #0x1c]\n\t"
        "_080FAA40:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FAA44: .4byte CaveEntranceSpriteCallbackEnd + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CaveEntranceSpriteCallbackEnd(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r1, #0x37\n\t"
        "	bl FieldEffectStop\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void FieldCallback_SecretBaseShrub(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_Shrub);
}


bool8 FldEff_UseSecretPowerShrub(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseTreeFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseTreeFieldEffect;

    return FALSE;
}

void StartSecretBaseTreeFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_TREE);
    FieldEffectStart(FLDEFF_SECRET_POWER_TREE);
}

__attribute__((naked)) bool8 FldEff_SecretPowerTree()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r1, _080FAB30\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	movs r2, #2\n\t"
        "	ldrsh r1, [r1, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r1, _080FAB34\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0x96\n\t"
        "	bne _080FAADA\n\t"
        "	ldr r1, _080FAB38\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1, #0x1c]\n\t"
        "_080FAADA:\n\t"
        "	cmp r2, #0x9c\n\t"
        "	bne _080FAAE4\n\t"
        "	ldr r1, _080FAB38\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r1, #0x1c]\n\t"
        "_080FAAE4:\n\t"
        "	bl AdjustSecretPowerSpritePixelOffsets\n\t"
        "	ldr r0, _080FAB3C\n\t"
        "	ldr r3, _080FAB40\n\t"
        "	ldr r1, _080FAB44\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #0x17\n\t"
        "	ldr r4, _080FAB38\n\t"
        "	ldr r3, [r4, #0x14]\n\t"
        "	adds r1, r1, r3\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	ldr r3, [r4, #0x18]\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	movs r3, #0x94\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r0, [r4, #0x1c]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080FAB22\n\t"
        "	cmp r0, #3\n\t"
        "	bne _080FAB26\n\t"
        "_080FAB22:\n\t"
        "	bl ToggleSecretBaseEntranceMetatile\n\t"
        "_080FAB26:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080FAB30: .4byte gPlayerFacingPosition\n\t"
        "_080FAB34: .4byte 0x00000FFF\n\t"
        "_080FAB38: .4byte gFieldEffectArguments\n\t"
        "_080FAB3C: .4byte gUnknown_856A1FC\n\t"
        "_080FAB40: .4byte gSprites\n\t"
        "_080FAB44: .4byte gPlayerAvatar\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TreeEntranceSpriteCallback1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0x9b\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _080FAB6C\n\t"
        "	ldr r1, [r0, #0x1c]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2a\n\t"
        "	movs r0, #0\n\t"
        "	strb r1, [r2]\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	ldr r0, _080FAB70\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FAB6C: .4byte gFieldEffectArguments\n\t"
        "_080FAB70: .4byte TreeEntranceSpriteCallback2 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TreeEntranceSpriteCallback2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x27\n\t"
        "	ble _080FAB9E\n\t"
        "	ldr r0, _080FABA4\n\t"
        "	ldr r0, [r0, #0x1c]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FAB92\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080FAB96\n\t"
        "_080FAB92:\n\t"
        "	bl ToggleSecretBaseEntranceMetatile\n\t"
        "_080FAB96:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	ldr r0, _080FABA8\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_080FAB9E:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FABA4: .4byte gFieldEffectArguments\n\t"
        "_080FABA8: .4byte TreeEntranceSpriteCallbackEnd + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TreeEntranceSpriteCallbackEnd(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r1, #0x38\n\t"
        "	bl FieldEffectStop\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void FieldCallback_SecretBaseTree(void)
{
    gFieldEffectArguments[0] = (u8)GetCursorSelectionMonId();
    ScriptContext_SetupScript(SecretBase_EventScript_Cave);
}


bool8 FldEff_UseSecretPowerTree(void)
{
    u8 taskId = CreateFieldMoveTask();

    gTasks[taskId].data[8] = (u32)StartSecretBaseShrubFieldEffect >> 16;
    gTasks[taskId].data[9] = (u32)StartSecretBaseShrubFieldEffect;

    return FALSE;
}

void StartSecretBaseShrubFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_SECRET_POWER_SHRUB);
    FieldEffectStart(FLDEFF_SECRET_POWER_SHRUB);
}

__attribute__((naked)) bool8 FldEff_SecretPowerShrub()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl AdjustSecretPowerSpritePixelOffsets\n\t"
        "	ldr r0, _080FAC5C\n\t"
        "	ldr r3, _080FAC60\n\t"
        "	ldr r1, _080FAC64\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #0x17\n\t"
        "	ldr r4, _080FAC68\n\t"
        "	ldr r3, [r4, #0x14]\n\t"
        "	adds r1, r1, r3\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	ldr r3, [r4, #0x18]\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	movs r3, #0x94\n\t"
        "	bl CreateSprite\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080FAC5C: .4byte gUnknown_856A214\n\t"
        "_080FAC60: .4byte gSprites\n\t"
        "_080FAC64: .4byte gPlayerAvatar\n\t"
        "_080FAC68: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShrubEntranceSpriteCallback1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0xa9\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	ldr r0, _080FAC84\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FAC84: .4byte CaveEntranceSpriteCallback2 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CaveEntranceSpriteCallback2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldrh r2, [r1, #0x2e]\n\t"
        "	movs r3, #0x2e\n\t"
        "	ldrsh r0, [r1, r3]\n\t"
        "	cmp r0, #0x27\n\t"
        "	bgt _080FACA8\n\t"
        "	adds r0, r2, #1\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x14\n\t"
        "	bne _080FACB0\n\t"
        "	bl ToggleSecretBaseEntranceMetatile\n\t"
        "	b _080FACB0\n\t"
        "_080FACA8:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	ldr r0, _080FACB4\n\t"
        "	str r0, [r1, #0x1c]\n\t"
        "_080FACB0:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FACB4: .4byte ShrubEntranceSpriteCallbackEnd + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShrubEntranceSpriteCallbackEnd(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r1, #0x39\n\t"
        "	bl FieldEffectStop\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 FldEff_SecretBasePCTurnOn(void)
{
    s16 x, y;
    u8 taskId;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    taskId = CreateTask(Task_SecretBasePCTurnOn, 0);
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tState = 0;

    return FALSE;
}

void Task_SecretBasePCTurnOn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 4:
    case 12:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 8:
    case 16:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC);
        CurrentMapDrawMetatileAt(tX, tY);
        break;
    case 20:
        MapGridSetMetatileIdAt(tX, tY, METATILE_SecretBase_PC_On);
        CurrentMapDrawMetatileAt(tX, tY);
        FieldEffectActiveListRemove(FLDEFF_PCTURN_ON);
        ScriptContext_Enable();
        DestroyTask(taskId);
        return;
    }

    tState++;
}


void DoSecretBasePCTurnOffEffect(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    PlaySE(SE_PC_OFF);

    if (!(u16)VarGet(VAR_CURRENT_SECRET_BASE))
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_PC | MAPGRID_IMPASSABLE);
    else
        MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_RegisterPC | MAPGRID_IMPASSABLE);

    CurrentMapDrawMetatileAt(x, y);
}

void PopSecretBaseBalloon(s16 metatileId, s16 x, s16 y)
{
    u8 taskId = CreateTask(Task_PopSecretBaseBalloon, 0);

    gTasks[taskId].data[0] = metatileId;
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = 0;
    gTasks[taskId].data[4] = 1;
}

void Task_PopSecretBaseBalloon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[3] == 6)
        data[3] = 0;
    else
        data[3]++;

    if (data[3] == 0)
    {
        if (data[4] == 2)
            DoBalloonSoundEffect(data[0]);

        MapGridSetMetatileIdAt(data[1], data[2], data[0] + data[4]);
        CurrentMapDrawMetatileAt(data[1], data[2]);

        if (data[4] == 3)
            DestroyTask(taskId);
        else
            data[4]++;
    }
}


static void DoBalloonSoundEffect(s16 metatileId)
{
    switch (metatileId)
    {
    case METATILE_SecretBase_RedBalloon:
        PlaySE(SE_BALLOON_RED);
        break;
    case METATILE_SecretBase_BlueBalloon:
        PlaySE(SE_BALLOON_BLUE);
        break;
    case METATILE_SecretBase_YellowBalloon:
        PlaySE(SE_BALLOON_YELLOW);
        break;
    case METATILE_SecretBase_MudBall:
        PlaySE(SE_MUD_BALL);
        break;
    }
}


bool8 FldEff_NopA700(void)
{
    return FALSE;
}

bool8 FldEff_NopA6FC(void)
{
    return FALSE;
}

void DoSecretBaseBreakableDoorEffect(s16 x, s16 y)
{
    PlaySE(SE_BREAKABLE_DOOR);
    MapGridSetMetatileIdAt(x, y, METATILE_SecretBase_BreakableDoor_BottomOpen);
    MapGridSetMetatileIdAt(x, y - 1, METATILE_SecretBase_BreakableDoor_TopOpen);
    CurrentMapDrawMetatileAt(x, y);
    CurrentMapDrawMetatileAt(x, y - 1);
}


static void Task_ShatterSecretBaseBreakableDoor(u8 taskId)
{
    if (gTasks[taskId].data[0] == 7)
    {
        DoSecretBaseBreakableDoorEffect(gTasks[taskId].data[1], gTasks[taskId].data[2]);
        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[0]++;
    }
}


void ShatterSecretBaseBreakableDoor(s16 x, s16 y)
{
    u8 dir = (u8)GetPlayerFacingDirection();

    if (dir == DIR_SOUTH)
    {
        DoSecretBaseBreakableDoorEffect(x, y);
    }
    else if (dir == DIR_NORTH)
    {
        u8 taskId = CreateTask(Task_ShatterSecretBaseBreakableDoor, 5);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = x;
        gTasks[taskId].data[2] = y;
    }
}


static void Task_SecretBaseMusicNoteMatSound(u8 taskId)
{
    if (gTasks[taskId].data[1] == 7)
    {
        switch (gTasks[taskId].tMetatileID)
        {
        case METATILE_SecretBase_NoteMat_C_Low:
            PlaySE(SE_NOTE_C);
            break;
        case METATILE_SecretBase_NoteMat_D:
            PlaySE(SE_NOTE_D);
            break;
        case METATILE_SecretBase_NoteMat_E:
            PlaySE(SE_NOTE_E);
            break;
        case METATILE_SecretBase_NoteMat_F:
            PlaySE(SE_NOTE_F);
            break;
        case METATILE_SecretBase_NoteMat_G:
            PlaySE(SE_NOTE_G);
            break;
        case METATILE_SecretBase_NoteMat_A:
            PlaySE(SE_NOTE_A);
            break;
        case METATILE_SecretBase_NoteMat_B:
            PlaySE(SE_NOTE_B);
            break;
        case METATILE_SecretBase_NoteMat_C_High:
            PlaySE(SE_NOTE_C_HIGH);
            break;
        }

        DestroyTask(taskId);
    }
    else
    {
        gTasks[taskId].data[1]++;
    }
}


void PlaySecretBaseMusicNoteMatSound(s16 metatileId)
{
    u8 taskId = CreateTask(Task_SecretBaseMusicNoteMatSound, 5);

    gTasks[taskId].tMetatileID = metatileId;
    gTasks[taskId].data[1] = 0;
}

static void SpriteCB_GlitterMatSparkle(struct Sprite *sprite)
{
    sprite->data[0]++;

    if (sprite->data[0] == 8)
        PlaySE(SE_M_HEAL_BELL);

    if (sprite->data[0] >= 32)
        DestroySprite(sprite);
}


void DoSecretBaseGlitterMatSparkle(void)
{
    s16 x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    s16 y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    u8 spriteId;

    SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].oam.paletteNum = 5;
        gSprites[spriteId].callback = SpriteCB_GlitterMatSparkle;
        gSprites[spriteId].data[0] = 0;
    }
}


__attribute__((naked)) bool8 FldEff_SandPillar()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetXYCoordsOneStepInFrontOfPlayer\n\t"
        "	ldr r1, _080FB328\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	str r0, [r1, #0x14]\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	str r0, [r1, #0x18]\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080FB36C\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _080FB32C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080FB336\n\t"
        "	b _080FB3FC\n\t"
        "	.align 2, 0\n\t"
        "_080FB328: .4byte gFieldEffectArguments\n\t"
        "_080FB32C:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080FB39C\n\t"
        "	cmp r0, #4\n\t"
        "	beq _080FB3D4\n\t"
        "	b _080FB3FC\n\t"
        "_080FB336:\n\t"
        "	ldr r0, _080FB360\n\t"
        "	ldr r3, _080FB364\n\t"
        "	ldr r1, _080FB368\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #0xc\n\t"
        "	adds r1, r1, r3\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r2, #0x20\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	b _080FB3FC\n\t"
        "	.align 2, 0\n\t"
        "_080FB360: .4byte gUnknown_856A270\n\t"
        "_080FB364: .4byte gSprites\n\t"
        "_080FB368: .4byte gPlayerAvatar\n\t"
        "_080FB36C:\n\t"
        "	ldr r0, _080FB390\n\t"
        "	ldr r3, _080FB394\n\t"
        "	ldr r1, _080FB398\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #0xc\n\t"
        "	adds r1, r1, r3\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	b _080FB3BC\n\t"
        "	.align 2, 0\n\t"
        "_080FB390: .4byte gUnknown_856A270\n\t"
        "_080FB394: .4byte gSprites\n\t"
        "_080FB398: .4byte gPlayerAvatar\n\t"
        "_080FB39C:\n\t"
        "	ldr r0, _080FB3C4\n\t"
        "	ldr r3, _080FB3C8\n\t"
        "	ldr r1, _080FB3CC\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	ldr r3, _080FB3D0\n\t"
        "	adds r1, r1, r3\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r2, #0x10\n\t"
        "_080FB3BC:\n\t"
        "	movs r3, #0x94\n\t"
        "	bl CreateSprite\n\t"
        "	b _080FB3FC\n\t"
        "	.align 2, 0\n\t"
        "_080FB3C4: .4byte gUnknown_856A270\n\t"
        "_080FB3C8: .4byte gSprites\n\t"
        "_080FB3CC: .4byte gPlayerAvatar\n\t"
        "_080FB3D0: .4byte 0xFFF80000\n\t"
        "_080FB3D4:\n\t"
        "	ldr r0, _080FB408\n\t"
        "	ldr r3, _080FB40C\n\t"
        "	ldr r1, _080FB410\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x17\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #0xd\n\t"
        "	adds r1, r1, r3\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r2, #0x10\n\t"
        "	movs r3, #0x94\n\t"
        "	bl CreateSprite\n\t"
        "_080FB3FC:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080FB408: .4byte gUnknown_856A270\n\t"
        "_080FB40C: .4byte gSprites\n\t"
        "_080FB410: .4byte gPlayerAvatar\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_SandPillar_0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r0, #0x83\n\t"
        "	bl PlaySE\n\t"
        "	ldr r4, _080FB440\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	subs r1, #1\n\t"
        "	bl MapGridGetMetatileIdAt\n\t"
        "	ldr r1, _080FB444\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080FB44C\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	subs r1, #1\n\t"
        "	ldr r2, _080FB448\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	b _080FB45A\n\t"
        "	.align 2, 0\n\t"
        "_080FB440: .4byte gFieldEffectArguments\n\t"
        "_080FB444: .4byte 0x00000286\n\t"
        "_080FB448: .4byte 0x00000E02\n\t"
        "_080FB44C:\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	subs r1, #1\n\t"
        "	movs r2, #0xa1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "_080FB45A:\n\t"
        "	ldr r4, _080FB488\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	ldr r2, _080FB48C\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	subs r1, #1\n\t"
        "	bl CurrentMapDrawMetatileAt\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	bl CurrentMapDrawMetatileAt\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x2e]\n\t"
        "	ldr r0, _080FB490\n\t"
        "	str r0, [r5, #0x1c]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FB488: .4byte gFieldEffectArguments\n\t"
        "_080FB48C: .4byte SPECIAL_sub_08139C4C\n\t"
        "_080FB490: .4byte SpriteCB_SandPillar_1 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_SandPillar_1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r1, [r5, #0x2e]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	cmp r0, #0x11\n\t"
        "	bgt _080FB4A8\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r5, #0x2e]\n\t"
        "	b _080FB4C4\n\t"
        "_080FB4A8:\n\t"
        "	ldr r4, _080FB4CC\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	ldr r2, _080FB4D0\n\t"
        "	bl MapGridSetMetatileIdAt\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	ldr r1, [r4, #0x18]\n\t"
        "	bl CurrentMapDrawMetatileAt\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x2e]\n\t"
        "	ldr r0, _080FB4D4\n\t"
        "	str r0, [r5, #0x1c]\n\t"
        "_080FB4C4:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FB4CC: .4byte gFieldEffectArguments\n\t"
        "_080FB4D0: .4byte 0x00000E8C\n\t"
        "_080FB4D4: .4byte SpriteCB_SandPillar_2 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_SandPillar_2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r1, #0x34\n\t"
        "	bl FieldEffectStop\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetShieldToyTVDecorationInfo(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetXYCoordsOneStepInFrontOfPlayer\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl MapGridGetMetatileIdAt\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _080FB520\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080FB5DC\n\t"
        "	cmp r1, r0\n\t"
        "	bgt _080FB524\n\t"
        "	subs r0, #0x17\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080FB584\n\t"
        "	adds r0, #0x16\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080FB5D0\n\t"
        "	b _080FB63E\n\t"
        "	.align 2, 0\n\t"
        "_080FB520: .4byte 0x000002F5\n\t"
        "_080FB524:\n\t"
        "	ldr r0, _080FB568\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080FB614\n\t"
        "	adds r0, #0x40\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080FB532\n\t"
        "	b _080FB63E\n\t"
        "_080FB532:\n\t"
        "	ldr r0, _080FB56C\n\t"
        "	movs r1, #0x64\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _080FB570\n\t"
        "	ldr r1, _080FB574\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _080FB578\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080FB57C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FB63E\n\t"
        "	ldr r4, _080FB580\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0x10\n\t"
        "	b _080FB5FA\n\t"
        "	.align 2, 0\n\t"
        "_080FB568: .4byte 0x000002F6\n\t"
        "_080FB56C: .4byte gStringVar1\n\t"
        "_080FB570: .4byte gStringVar2\n\t"
        "_080FB574: .4byte gUnknown_85CA70B + 0x34\n\t"
        "_080FB578: .4byte gSpecialVar_Result\n\t"
        "_080FB57C: .4byte 0x00004054\n\t"
        "_080FB580: .4byte 0x000040EE\n\t"
        "_080FB584:\n\t"
        "	ldr r0, _080FB5B8\n\t"
        "	movs r1, #0x32\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _080FB5BC\n\t"
        "	ldr r1, _080FB5C0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r1, _080FB5C4\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080FB5C8\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FB63E\n\t"
        "	ldr r4, _080FB5CC\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0x20\n\t"
        "	b _080FB5FA\n\t"
        "	.align 2, 0\n\t"
        "_080FB5B8: .4byte gStringVar1\n\t"
        "_080FB5BC: .4byte gStringVar2\n\t"
        "_080FB5C0: .4byte gUnknown_85CA70B + 0x37\n\t"
        "_080FB5C4: .4byte gSpecialVar_Result\n\t"
        "_080FB5C8: .4byte 0x00004054\n\t"
        "_080FB5CC: .4byte 0x000040EE\n\t"
        "_080FB5D0:\n\t"
        "	ldr r1, _080FB5D8\n\t"
        "	movs r0, #1\n\t"
        "	b _080FB5E0\n\t"
        "	.align 2, 0\n\t"
        "_080FB5D8: .4byte gSpecialVar_Result\n\t"
        "_080FB5DC:\n\t"
        "	ldr r1, _080FB608\n\t"
        "	movs r0, #2\n\t"
        "_080FB5E0:\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080FB60C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FB63E\n\t"
        "	ldr r4, _080FB610\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0x80\n\t"
        "_080FB5FA:\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarSet\n\t"
        "	b _080FB63E\n\t"
        "	.align 2, 0\n\t"
        "_080FB608: .4byte gSpecialVar_Result\n\t"
        "_080FB60C: .4byte 0x00004054\n\t"
        "_080FB610: .4byte 0x000040EE\n\t"
        "_080FB614:\n\t"
        "	ldr r1, _080FB648\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080FB64C\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080FB63E\n\t"
        "	ldr r4, _080FB650\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarGet\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0x80\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl VarSet\n\t"
        "_080FB63E:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FB648: .4byte gSpecialVar_Result\n\t"
        "_080FB64C: .4byte 0x00004054\n\t"
        "_080FB650: .4byte 0x000040EE\n\t"
        ".syntax divided\n\t"
    );
}

bool8 sub_080FB654(u16 x, u8 y)
{
    if (!CurMapIsSecretBase())
        return FALSE;
    if (y == 0)
    {
        if ((u16)(x - METATILE_SecretBase_SandOrnament_Top) <= 1)
            return TRUE;
        if (x == METATILE_SecretBase_BreakableDoor_TopClosed)
            return TRUE;
    }
    else
    {
        if (x == METATILE_SecretBase_SandOrnament_Base1)
            return TRUE;
        if (x == METATILE_SecretBase_BreakableDoor_BottomClosed)
            return TRUE;
    }
    return FALSE;
}

#undef tState
#define tState data[0]
#define tMosaic data[1]

static void Task_FieldPoisonEffect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        tMosaic += 2;
        if (tMosaic > 8)
            tState++;
        break;
    case 1:
        tMosaic -= 2;
        if (tMosaic == 0)
            tState++;
        break;
    case 2:
        DestroyTask(taskId);
        return;
    }
    SetGpuReg(REG_OFFSET_MOSAIC, (u16)((tMosaic << 4) | tMosaic));
}

#undef tState
#undef tMosaic
#define tState data[2]


void FldEffPoison_Start(void)
{
    PlaySE(SE_FIELD_POISON);
    CreateTask(Task_FieldPoisonEffect, 80);
}

bool32 sub_080FB730(void)
{
    return FuncIsActiveTask(Task_FieldPoisonEffect);
}

void Task_WateringBerryTreeAnim_0(u8 taskId)
{
    gTasks[taskId].func = Task_WateringBerryTreeAnim_1;
}

void Task_WateringBerryTreeAnim_1(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (!ObjectEventIsMovementOverridden(playerObjEvent)
        || ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        sub_0808BB8C((u8)GetPlayerFacingDirection());
        ObjectEventSetHeldMovement(playerObjEvent, sub_08092F08((u8)GetPlayerFacingDirection()));
        gTasks[taskId].func = Task_WateringBerryTreeAnim_2;
    }
}


void Task_WateringBerryTreeAnim_2(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        s16 value = gTasks[taskId].data[1]++;

        if (value < 10)
            ObjectEventSetHeldMovement(playerObjEvent, sub_08092F08((u8)GetPlayerFacingDirection()));
        else
            gTasks[taskId].func = Task_WateringBerryTreeAnim_3;
    }
}


void Task_WateringBerryTreeAnim_3(u8 taskId)
{
    SetPlayerAvatarTransitionFlags((u8)sub_0808B634());
    DestroyTask(taskId);
    ScriptContext_Enable();
}


void DoWateringBerryTreeAnim(void)
{
    CreateTask(Task_WateringBerryTreeAnim_0, 80);
}

__attribute__((naked)) void CreateRecordMixingSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _080FB8D0\n\t"
        "	bl LoadSpritePalette\n\t"
        "	ldr r0, _080FB8D4\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x52\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0x40\n\t"
        "	beq _080FB8DC\n\t"
        "	lsls r0, r5, #4\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080FB8D8\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x22\n\t"
        "	movs r0, #0x10\n\t"
        "	movs r1, #0xd\n\t"
        "	bl GetMapCoordsFromSpritePos\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	adds r0, #0x10\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	adds r0, #2\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	adds r0, r5, #0\n\t"
        "	b _080FB8DE\n\t"
        "	.align 2, 0\n\t"
        "_080FB8D0: .4byte gUnknown_856A448\n\t"
        "_080FB8D4: .4byte gUnknown_856A464\n\t"
        "_080FB8D8: .4byte gSprites\n\t"
        "_080FB8DC:\n\t"
        "	movs r0, #0x40\n\t"
        "_080FB8DE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DestroyRecordMixingSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r4, _080FB918\n\t"
        "	adds r7, r4, #0\n\t"
        "	movs r6, #0\n\t"
        "	movs r5, #0x3f\n\t"
        "_080FB8EE:\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x14\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080FB91C\n\t"
        "	cmp r1, r0\n\t"
        "	bne _080FB908\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpritePalette\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroySprite\n\t"
        "_080FB908:\n\t"
        "	adds r4, #0x44\n\t"
        "	adds r6, #0x44\n\t"
        "	subs r5, #1\n\t"
        "	cmp r5, #0\n\t"
        "	bge _080FB8EE\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080FB918: .4byte gSprites\n\t"
        "_080FB91C: .4byte gUnknown_856A464\n\t"
        ".syntax divided\n\t"
    );
}
