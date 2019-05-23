#include <stdio.h>
#include <string.h>

#include "bits.h"

int BitsSetCount(unsigned int v)
{
    int rc = 0; // total set bits in value
    for ( ; v != 0; (v &= (v - 1)))
    {
        rc++;
    }
    return rc;
}

int BitsMain(void)
{
    int const rc = 0;

    while(1)
    {
        unsigned int n;

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
