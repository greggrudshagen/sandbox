#include <fizzbuzz.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int32_t use_bitmask(int32_t const start, int32_t const end);
static int32_t use_strings(int32_t const start, int32_t const end);

int32_t fizzbuzz_main()
{
    int32_t rc = 0;
    printf("%s\n", __FUNCTION__);

    if (0)
    {
        rc = use_bitmask(1, 15);
    }
    else if (1)
    {
        rc = use_strings(1, 60);
    }
    else
    {

    }
    return rc;
}


static int32_t use_bitmask(int32_t const start, int32_t const end)
{
    int32_t const rc = 0;

    printf("%s\n", __FUNCTION__);

    const char str1[] = "FIZZ";
    const char str2[] = "BUZZ";

    for (int32_t i = start; i < end + 1; i++)
    {
        uint32_t mask = 0;

        mask |= ((i % 3) == 0 ? 0x01 : 0x0);
        mask |= ((i % 5) == 0 ? 0x02 : 0x0);

        switch (mask)
        {
            case 0:
                printf("i = %d\n", i);
                break;
            case 1:
                //printf("i = %d\t", i);
                printf("%s\n", str1);
                break;
            case 2:
                //printf("i = %d\t", i);
                printf("%s\n", str2);
                break;
            case 3:
                //printf("i = %d\t", i);
                printf("%s%s\n", str1, str2);
                break;
            default:
                break;
        }
    }

    return rc;
}

static int32_t use_strings(int32_t const start, int32_t const end)
{
    int32_t const rc = 0;

    printf("%s\n", __FUNCTION__);

    const char str1[] = "FIZZ";
    const char str2[] = "BUZZ";
    const char str3[] = "BOMB";
    char res[strlen(str1) + strlen(str2) + strlen(str3) + 1];

    for (int32_t i = start; i < end + 1; i++)
    {
        res[0] = '\0';

        if ((i % 3) == 0)
        {
            strcat(res, str1);
        }
        if ((i % 5) == 0)
        {
            strcat(res, str2);
        }
        if ((i % 20) == 0)
        {
            //strcat(res, str3);
        }

        if (strlen(res) == 0)
        {
            printf("i = %d\n", i);
        }
        else
        {
            // printf("i = %d\t", i);
            printf("%s\n", res);
        }
    }

    return rc;
}
