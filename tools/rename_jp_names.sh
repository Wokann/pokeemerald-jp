#!/bin/bash
cd /home/kenny/pokeemerald-jp
set -e

rename() {
  local old="$1" new="$2"
  # asm and C sources only; word-boundary replacement
  sed -i -E "s/\b${old}\b/${new}/g" asm/*.s src/*.c
  echo "renamed $old -> $new"
}

rename EventObjectSetGraphicsId          ObjectEventSetGraphicsId
rename EventObjectIsMovementOverridden   ObjectEventIsMovementOverridden
rename EventObjectSetHeldMovement        ObjectEventSetHeldMovement
rename EventObjectCheckHeldMovementStatus ObjectEventCheckHeldMovementStatus
rename MovementAction_AcroEndWheelieFaceLeft_Step0 ObjectEventClearHeldMovementIfFinished
rename GetEventObjectIdByXYZ             GetObjectEventIdByPosition
rename PlayerGetZCoord                   PlayerGetElevation
rename ScriptContext2_Enable             LockPlayerFieldControls
rename ScriptContext2_Disable            UnlockPlayerFieldControls
rename ScriptContext1_SetupScript        ScriptContext_SetupScript
rename EnableBothScriptContexts          ScriptContext_Enable
