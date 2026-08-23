// Script-command static data, emitted by graphics.c to preserve scrcmd.c
// code generation while retaining the original JP ROM order.

SCRIPT_COMMAND_NULL_PTR void *const gNullScriptPtr = NULL;

SCRIPT_COMMAND_CONDITION_TABLE const u8 sScriptConditionTable[COMPARISON_OPERATORS_COUNT][3] =
{
//                              <  =  >
    [LESS_THAN] =              {1, 0, 0},
    [EQUAL] =                  {0, 1, 0},
    [GREATER_THAN] =           {0, 0, 1},
    [LESS_THAN_OR_EQUAL] =     {1, 1, 0},
    [GREATER_THAN_OR_EQUAL] =  {0, 1, 1},
    [NOT_EQUAL] =              {1, 0, 1},
};

SCRIPT_COMMAND_STRING_VARS u8 *const sScriptStringVars[] =
{
    gStringVar1,
    gStringVar2,
    gStringVar3,
};
