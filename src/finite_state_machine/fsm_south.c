#include <fsm_cmn.h>
#include <fsm_south.h>

#include <stdio.h>


void *SouthState(int state)
{
    printf("%s:state %d\n", __FUNCTION__, state);

    return EastState;
}

// EOF
