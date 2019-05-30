#include <arrarys.h>
#include <bits.h>
#include <fsm_main.h>
#include <linklist.h>
#include <utility.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int rc = 0;
#if 1
    printf("%s %s\n", __DATE__, __TIME__);
#endif

#if 0
    printf("argc = %d\n", argc);
    for(int ndx = 0; ndx != argc; ++ndx)
    {
        printf("argv[%d] --> %s\n", ndx, argv[ndx]);
    }
    printf("argv[argc] = %p\n", (void*)argv[argc]);
#endif

#if 0
    { // sizeof details
        time_t t;
        time_t *tptr = &t;
        printf("time size is %d\n", sizeof(time_t));
        printf("time size via ptr is %d\n", sizeof(*tptr));

        int cnt;
        int *cptr = &cnt;
        printf("int size is %d\n", sizeof(int));
        printf("int size via ptr is %d\n", sizeof(*cptr));
        printf("size of pointer is %d\n", sizeof(cptr));
        //printf("cptr contains 0x%08X, 0x%08X\n", cptr, &cnt);

        // pointer size is compiler/implementation specific.
        printf("size of (void *) pointer %d\n", sizeof(void *));
    }
#endif


#if 0 /* ARRAYS */
    main_arrays();

#elif 0
    rc = BitsMain();

#elif 0 /* Finite State Machine */
    fsm_main();

#elif 0
    rc = linklist_main();

#elif 1
    rc = utility_main();
#endif

    return rc;
}
