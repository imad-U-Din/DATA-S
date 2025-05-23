#include <stdio.h>

void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    //SWAP A[LOW] AND A[J]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // INDEX OF PIVOT AFTER PARTITION

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // SORT LEFT SUB-ARRAY
        quickSort(A, partitionIndex + 1, high); // SORT RIGHT SUB-ARRAY
    }
}
int main()
{
    int A[] = {3, 5, 2, 13, 12,3,2,13,45};
    int size = 9;
    printArray(A, size);
    quickSort(A, 0, size - 1);
    printArray(A, size);
    return 0;
}