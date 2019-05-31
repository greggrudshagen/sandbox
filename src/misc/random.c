#include <random.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void random_number_generator(void);

static int32_t seed_init = 0;

static void random_number_generator(void)
{
    time_t t;
    srand((unsigned) time(&t));
    seed_init = 1;
}

int32_t random_range(int32_t const minimum, int32_t const maximum)
{
    if (0 == seed_init)
    {
        random_number_generator();
    }

    int32_t const rc = (rand() % (maximum + 1 - minimum)) + minimum;
    return rc;
}


// EOF
