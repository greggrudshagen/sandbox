//#include <stdint.h>
#include <utility.h>

#include <stdio.h>
#include <math.h>


// Prototype local routines here.
void swap_int_no_tmp(int32_t *x, int32_t *y);
void swap_dbl_no_tmp(double *x, double *y);




void swap_int_no_tmp(int32_t *x, int32_t *y)
{
    *x = *x - *y;
    *y = *x + *y;
    *x = *y - *x;
}
void swap_dbl_no_tmp(double *x, double *y)
{
    *x = *x - *y;
    *y = *x + *y;
    *x = *y - *x;
}

int32_t is_even(uint32_t const v)
{
    return ((v & 0x01) ? 0 : 1);
}

int32_t b_to_the_nth(int32_t const base, uint32_t const nth)
{
    if (0 == nth)
    {
        return 1;
    }

    if (is_even(nth))
    {
        return(b_to_the_nth(base*base, nth/2));
    }

    return(b_to_the_nth(base*base, nth/2) * base);
}

int32_t bits_set_count(uint32_t v)
{
    int32_t rc = 0; // total set bits in value
    for ( ; v != 0; (v &= (v - 1)))
    {
        rc++;
    }
    return rc;
}

int32_t utility_main()
{
    int32_t rc = 0;
    printf("%s\n", __FUNCTION__);

#if 0
    {
        int32_t const base = 2;
        for (int32_t n = 0; n <= 8; ++n)
        {
            printf("%d^%d = %d\n", base, n, b_to_the_nth(base, n));
        }
    }
    {
        int32_t const base = 10;
        for (int32_t n = 0; n <= 8; ++n)
        {
            printf("%d^%d = %d\n", base, n, b_to_the_nth(base, n));
        }
    }

#elif 1
    {
        {
            int32_t a = 4;
            int32_t b = 10;
            printf("a = %d, b = %d\n", a, b);
            swap_int_no_tmp(&a, &b);
            printf("a = %d, b = %d\n", a, b);
            swap_int_no_tmp(&a, &b);
            printf("a = %d, b = %d\n", a, b);
        }
        {
            double a = 4.111111;
            double b = 10.999999;
            printf("a = %f, b = %f\n", a, b);
            swap_dbl_no_tmp(&a, &b);
            printf("a = %f, b = %f\n", a, b);
            swap_dbl_no_tmp(&a, &b);
            printf("a = %f, b = %f\n", a, b);
        }
    }
#else

#endif
    return rc;
}

// EOF
