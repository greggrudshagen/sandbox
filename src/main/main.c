#include <stdc_version.h>

#include <arrarys.h>
#include <bits.h>
#include <fsm_main.h>
#include <linklist.h>
#include <utility.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int32_t main(int32_t argc, char *argv[])
{
    int32_t rc = 0;
#if 1
    printf("%s[%d]:%s %s\n", __FUNCTION__, __LINE__, __DATE__, __TIME__);
#endif

#if 0
    printf("argc = %d\n", argc);
    for(int32_t ndx = 0; ndx != argc; ++ndx)
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

        int32_t cnt;
        int32_t *cptr = &cnt;
        printf("int32_t size is %d\n", sizeof(int32_t));
        printf("int32_t size via ptr is %d\n", sizeof(*cptr));
        printf("size of pointer is %d\n", sizeof(cptr));
        //printf("cptr contains 0x%08X, 0x%08X\n", cptr, &cnt);

        // pointer size is compiler/implementation specific.
        printf("size of (void *) pointer %d\n", sizeof(void *));
    }
#endif


    if (0)
    {
        ; // do nothing
    }
    else if (0)
    {
        rc = arrays_main();
    }
    else if (0)
    {
        rc = BitsMain();
    }
    else if (0)
    {
        rc = fsm_main();
    }
    else if (0)
    {
        rc = linklist_main();
    }
    else if (1)
    {
        rc = utility_main();
    }
    else
    {
    }

    return rc;
}
