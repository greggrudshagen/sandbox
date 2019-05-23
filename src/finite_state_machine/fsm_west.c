#include <fsm_cmn.h>
#include <fsm_west.h>

#include <stdio.h>


void *WestState(int state)
{
    printf("%s:state %d\n", __FUNCTION__, state);

    return NorthState;
}

// EOF
