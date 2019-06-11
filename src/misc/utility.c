//#include <stdint.h>
#include <utility.h>

#include <stdio.h>
#include <math.h>


// Prototype local routines here.
void swap_int_no_tmp(int32_t *x, int32_t *y);
void swap_dbl_no_tmp(double *x, double *y);

int32_t b_to_the_nth(int32_t const base, uint32_t const nth);


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

int32_t b_to_the_nth_recursive(int32_t const base, uint32_t const nth)
{
    // printf("%s[%d]: %d^%d\n", __FUNCTION__, __LINE__, base, nth);

    if (0 == nth)
    {
        int32_t const rc = 1;
        // printf("%s[%d]:%d^%d = %d\n", __FUNCTION__, __LINE__, base, nth, rc);
        return rc;
    }

    if (is_even(nth))
    {
        int32_t const rc = b_to_the_nth_recursive(base*base, nth/2);
        return rc;
    }

    int32_t const rc = b_to_the_nth_recursive(base*base, nth/2) * base;
    return rc;
}

int32_t b_to_the_nth(int32_t const base, uint32_t const nth)
{
    // printf("%s[%d]: %d^%d\n", __FUNCTION__, __LINE__, base, nth);

    int32_t result = 1; // default because b^0 = 1

    for (int32_t j = nth; j > 0; --j)
    {
        result *= base;
    }

    return result;
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
            printf("%d^%d = %d\n", base, n, b_to_the_nth_recursive(base, n));
        }
    }
    {
        int32_t const base = 10;
        for (int32_t n = 0; n <= 8; ++n)
        {
            printf("%d^%d = %d\n", base, n, b_to_the_nth_recursive(base, n));
        }
    }
#elif 1
    { // base^nth 
        typedef struct
        {
            int32_t base;
            int32_t power;
        } Exponent_t;

        {
            static Exponent_t const exp[] = { {2, 8}
                                              , {10, 8}
                                              // , {4, 8}
            };

            // printf(" %zu\n", sizeof(exp));
            for (int32_t i = 0; i < (sizeof(exp)/sizeof exp[0]); ++i)
            {
                int32_t const base = exp[i].base;
                for (int32_t n = 0; n <= exp[i].power; ++n)
                {
                    printf("%d^%d = %d\n", base, n, b_to_the_nth(base, n));
                }
            }
        }

        { // Recursively
            static Exponent_t const exp[] = { // {10, 8}
                                              //, {2, 8}
                                              // , {4, 8}
            };

            // printf(" %zu\n", sizeof(exp));
            for (int32_t i = 0; i < (sizeof(exp)/sizeof exp[0]); ++i)
            {
                int32_t const base = exp[i].base;
                for (int32_t n = 0; n <= exp[i].power; ++n)
                {
                    printf("%d^%d = %d\n", base, n, b_to_the_nth_recursive(base, n));
                }
            }
        }
    }
#elif 0
    { // swap values without using a tmp variable
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
