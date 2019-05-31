#include <arrarys.h>

#include <random.h>

#include <stdio.h>
#include <stdlib.h>



static int32_t one_dimensional();
static int32_t two_dimensional();

static int32_t one_dimensional_malloc();

static int32_t one_dimensional_variable_length();

static void displayArrary(int32_t arr[], int32_t size);



static int32_t one_dimensional()
{
    int32_t vector[5] = {1, 2, 3, 4, 5};

    printf("%s: %ld\n", __FUNCTION__, sizeof(vector)/sizeof(int32_t));

    displayArrary(vector, sizeof(vector)/sizeof(int32_t));
    return 0;
}

int32_t two_dimensional()
{
    int32_t matrix[2][3] = {{1, 2, 3},{4, 5,6}};

    printf("%s\n", __FUNCTION__);

    for (int32_t i = 0; i < 0; ++i)
    {
        printf("%s: &matrix[%d]: %p sizeof(matrix[%d]): %ld\n", __FUNCTION__,
               i, &matrix[i], i,  sizeof(matrix[i]));
    }

    for (int32_t i = 0; i < 2; ++i)
    {
        displayArrary(matrix[i], sizeof(matrix[i])/sizeof(int32_t));
    }

    return 0;
}

int32_t one_dimensional_malloc()
{
    printf("%s\n", __FUNCTION__);

    int32_t const size = 5;
    int32_t *pv = (int32_t*) malloc(size * sizeof(int32_t));
    for(int32_t i = 0; i < size; ++i)
    {
        pv[i] = i + 1;
    }

    displayArrary(pv, size);

    free(pv);
    return 0;
}


void displayArrary(int32_t arr[], int32_t size)
{
    printf("%s\n", __FUNCTION__);

    for(int32_t i = 0; i < size; ++i)
    {
        printf("idx %d = %d\n", i, arr[i]);
    }
}

void sortArraryMinToMax(int32_t arr[], int32_t const size)
{
    printf("%s\n", __FUNCTION__);

    for(int32_t i = 0; i < size; ++i)
    {
        for(int32_t j = 0; j < size - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int32_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
} // sortArraryMinToMax

int32_t one_dimensional_variable_length()
{
    printf("%s\n", __FUNCTION__);

    int32_t const max_num =  250;
    int32_t const min_num = -250;
    int32_t const size = 100 * 1;

    int32_t * const pv = (int32_t*) malloc(size * sizeof(int32_t)); // remember to free

    for(int32_t i = 0; i < size; ++i)
    {
        pv[i] = random_range(min_num, max_num);
    }

    //displayArrary(pv, size);
    sortArraryMinToMax(pv, size);
    // displayArrary(pv, size);

    int32_t min_value = 1; // default
    {
        int32_t idx = 0;

        // Find first non-negative number
        for(int32_t i = 0; i < size; ++i)
        {
            if (pv[i] >= 0)
            {
                idx = i;
                while ((i < idx + 10) && (i < size))
                {
                    printf("i %d = %d\n", i, pv[i]);
                    i++;
                }
                break;
            }
        }
        printf("\n");
        printf("idx %d = %d\n", idx, pv[idx]);

        for (int32_t j = idx; j < size; ++j)
        {
            if (j == idx)
            { // check the first location
                if (pv[j] > 1)
                {
                    break;
                }
            }

            int32_t current = pv[j];
            int32_t next    = pv[j+1];
            if ((current == next) ||
                (current == (next - 1)))
            {
                continue;
            }

            // Found least positive value not in arrary.
            min_value = (current + 1);
            break;
        }
    }

    free(pv);

    printf("value is %d\n", min_value);
    return 0;
}

int32_t arrays_main()
{
    int32_t rc = 0;
    if (0)
    {
        ; // do nothing
    }
    else if (0)
    {
        rc = one_dimensional();
    }
    else if (0)
    {
        rc = one_dimensional_malloc();
    }
    else if (0)
    {
        rc = two_dimensional();
    }
    else if (1)
    {
        rc = one_dimensional_variable_length();
    }
    else
    {
    }

    return rc;
}

// EOF
