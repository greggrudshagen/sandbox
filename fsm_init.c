#include <stdio.h>

#include "fsm_cmn.h"
#include "fsm_init.h"



void *InitState(int state)
{
    printf("%s:state %d\n", __FUNCTION__, state);

    return NorthState;
}

// EOF
