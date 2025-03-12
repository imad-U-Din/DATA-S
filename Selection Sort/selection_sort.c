#include <stdio.h>
void printArray(int *A, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int size)
{
    int indexOfMin,temp;
    printf("Running selection Sort....\n");
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[j] < A[indexOfMin]){
                indexOfMin=j;
            }
        }
        //SWAP A[I] AND A[INDEXOFMIN]
        temp=A[i];
        A[i]=A[indexOfMin];
        A[indexOfMin]=temp;
    }
}
int main()
{
    // 0  1  2  3  4 ->INDEX
    // 3  5  2  13 12->ARRAY

    int A[] = {3, 5, 2, 13, 12};
    int size = 5;
    printArray(A, size);
    selectionSort(A, size);
    printArray(A, size);
    return 0;
}