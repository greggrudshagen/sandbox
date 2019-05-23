#include <fsm_cmn.h>
#include <fsm_east.h>

#include <stdio.h>


void *EastState(int state)
{
    printf("%s:state %d\n", __FUNCTION__, state);

    return WestState;
}

// EOF
