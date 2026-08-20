#include "global.h"

// Keep the JP Frontier Pass resource stream independent from the still-naked
// implementation in src/frontier_pass.c.  The declarations below deliberately
// retain the original ROM order and linker section.
#include "frontier_pass.h"
