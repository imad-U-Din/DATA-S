#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A, int size)
{
    int i, j;
    // FIND THE MAXIMUM ELEMENT IN A
    int MAX = maximum(A, size);

    // CREATE THE COUNT ARRAY
    int *count = (int *)malloc((MAX + 1) * sizeof(int));
    if (count == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // INITIALIZE THE ARRAY ELEMENTS TO 0
    for (i = 0; i <= MAX; i++)
    {
        count[i] = 0;
    }

    // INCREMENT THE CORRESPONDING INDEX IN THE COUNT ARRAY
    for (i = 0; i < size; i++)
    {
        count[A[i]]++;
    }

    i = 0; // COUNTER FOR COUNT ARRAY
    j = 0; // COUNTER FOR GIVEN ARRAY

    while (i <= MAX) // FIXED LOOP CONDITION
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }

    free(count); // FREE ALLOCATED MEMORY
}

int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int size = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, size);

    countSort(A, size);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
