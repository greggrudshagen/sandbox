#include <fsm_cmn.h>
#include <fsm_north.h>

#include <stdio.h>


static int32_t north_state_cnt = 2;

void *NorthState(int32_t state)
{
    printf("%s:state %d\n", __FUNCTION__, state);
    if (north_state_cnt != 0)
    {
        north_state_cnt--;
        return NorthState;
    }

    north_state_cnt = 2;
    return SouthState;
}

// EOF
