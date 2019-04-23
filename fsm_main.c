#include <stdio.h>
#include <stdlib.h>


#include "fsm_main.h"
#include "fsm_cmn.h"
#include "fsm_north.h"
#include "fsm_south.h"
#include "fsm_east.h"
#include "fsm_west.h"
#include "fsm_init.h"


int North(int state);
int South(int state);

typedef void *(*FSMFunc)(int state);


typedef int (*fptrInit)(int stateCurrent, int statePrevious);

struct STATE_OPERATIONS
{
    // Init
    // Repeat
}STATE_OPS;

int const FSM_STATE_INIT  = 0;
int const FSM_STATE_NORTH = 1;
int const FSM_STATE_SOUTH = 2;
int const FSM_STATE_EAST  = 3;
int const FSM_STATE_WEST  = 4;
int const FSM_STATE_LAST  = 5; // always last

int fsm_main()
{
    int rc = 0;
    printf("%s\n", __FUNCTION__);
#if 0
    int (*fptr)(int);

    fptr = North;
    rc = fptr(0);
    //rc = North(0);
    //rc = South(0);
    fptr = South;
    rc = fptr(0);
#endif

    FSMFunc fsm_func = InitState;
    for (int begin = 15, end = 0, i = begin; i != end; i--)
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


int North(int state)
{
    int rc = 0;
    printf("%s\n", __FUNCTION__);

    return rc;
}

int South(int state)
{
    int rc = 0;
    printf("%s\n", __FUNCTION__);

    return rc;
}

// EOF
