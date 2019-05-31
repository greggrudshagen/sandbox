#include <bits.h>
#include <utility.h>

#include <stdio.h>


static int32_t BitsSetCount(uint32_t);


int32_t BitsSetCount(uint32_t const v)
{
    return bits_set_count(v);
}

int32_t BitsMain(void)
{
    int32_t const rc = 0;

    while(1)
    {
        uint32_t n;

        printf("Enter a positive non-zero integer: ");
        scanf("%u", &n);
        if (0 == n)
        {
            break;
        }
        printf("Binary of %d(0x%08X) has %d set bits.\n", n, n, BitsSetCount(n));
    }

    return rc;
}

// EOF
