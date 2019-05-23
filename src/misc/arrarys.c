#include <stdio.h>
#include <stdlib.h>

#include "arrarys.h"
#include "random.h"

int main_arrays()
{
    int rc = 0;
#if 0
    rc = one_dimensional();
#elif 0
    rc = one_dimensional_malloc();
#elif 0
    rc = two_dimensional();
#elif 1
    rc = one_dimensional_variable_length();
#else

#endif
    return rc;
}

int one_dimensional()
{
    int vector[5] = {1, 2, 3, 4, 5};

    printf("%s: %ld\n", __FUNCTION__, sizeof(vector)/sizeof(int));

    displayArrary(vector, sizeof(vector)/sizeof(int));
    return 0;
}

int two_dimensional()
{
    int matrix[2][3] = {{1, 2, 3},{4, 5,6}};

    printf("%s\n", __FUNCTION__);

    for (int i = 0; i < 0; ++i)
    {
        printf("%s: &matrix[%d]: %p sizeof(matrix[%d]): %ld\n", __FUNCTION__,
               i, &matrix[i], i,  sizeof(matrix[i]));
    }

    for (int i = 0; i < 2; ++i)
    {
        displayArrary(matrix[i], sizeof(matrix[i])/sizeof(int));
    }

    return 0;
}

int one_dimensional_malloc()
{
    printf("%s\n", __FUNCTION__);

    int const size = 5;
    int *pv = (int*) malloc(size * sizeof(int));
    for(int i = 0; i < size; ++i)
    {
        pv[i] = i + 1;
    }

    displayArrary(pv, size);

    free(pv);
    return 0;
}


void displayArrary(int arr[], int size)
{
    printf("%s\n", __FUNCTION__);

    for(int i = 0; i < size; ++i)
    {
        printf("idx %d = %d\n", i, arr[i]);
    }
}

void sortArraryMinToMax(int arr[], int const size)
{
    printf("%s\n", __FUNCTION__);

    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
} // sortArraryMinToMax

int one_dimensional_variable_length()
{
    printf("%s\n", __FUNCTION__);

    int const max_num =  250;
    int const min_num = -250;
    int const size = 100 * 1;

    int * const pv = (int*) malloc(size * sizeof(int)); // remember to free

    for(int i = 0; i < size; ++i)
    {
        pv[i] = random_range(min_num, max_num);
    }

    //displayArrary(pv, size);
    sortArraryMinToMax(pv, size);
    // displayArrary(pv, size);

    int min_value = 1; // default
    {
        int idx = 0;

        // Find first non-negative number
        for(int i = 0; i < size; ++i)
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

        for (int j = idx; j < size; ++j)
        {
            if (j == idx)
            { // check the first location
                if (pv[j] > 1)
                {
                    break;
                }
            }

            int current = pv[j];
            int next    = pv[j+1];
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

// EOF
