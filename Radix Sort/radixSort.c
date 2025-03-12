#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int getMax(int *A, int size) {
    int max = A[0];
    for (int i = 1; i < size; i++) {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countingSort(int *A, int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(A[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        A[i] = output[i];
}

void radixSort(int *A, int size) {
    int max = getMax(A, size);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(A, size, exp);
}

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int A[size];

    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, size);

    radixSort(A, size);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
