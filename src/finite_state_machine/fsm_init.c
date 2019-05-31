#include <fsm_cmn.h>
#include <fsm_init.h>

#include <stdio.h>


void *InitState(int32_t state)
{
    printf("%s:state %d\n", __FUNCTION__, state);

    return NorthState;
}

// EOF
