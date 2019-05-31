#include <fsm_main.h>
#include <fsm_cmn.h>
#include <fsm_north.h>
#include <fsm_south.h>
#include <fsm_east.h>
#include <fsm_west.h>
#include <fsm_init.h>

#include <stdio.h>
#include <stdlib.h>



typedef void *(*FSMFunc)(int32_t state);


typedef int32_t (*fptrInit)(int32_t stateCurrent, int32_t statePrevious);

int32_t const FSM_STATE_INIT  = 0;
int32_t const FSM_STATE_NORTH = 1;
int32_t const FSM_STATE_SOUTH = 2;
int32_t const FSM_STATE_EAST  = 3;
int32_t const FSM_STATE_WEST  = 4;
int32_t const FSM_STATE_LAST  = 5; // always last

int32_t fsm_main()
{
    int32_t rc = 0;
    printf("%s\n", __FUNCTION__);

    FSMFunc fsm_func = InitState;
    for (int32_t begin = 15, end = 0, i = begin; i != end; i--)
    {
        FSMFunc fsm_func_next = (FSMFunc)(*fsm_func)(i);
        if (fsm_func == fsm_func_next)
        {
            ; // printf("%s, fsm func are the same.\n", __FUNCTION__);
        }
        else
        {
        }

        fsm_func = fsm_func_next;
    } // for

    return rc;
}

// EOF
