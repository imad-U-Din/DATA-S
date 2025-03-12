#include <stdio.h>

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void shellSort(int *A, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) { // Reduce the gap size
        for (int i = gap; i < size; i++) {
            int key = A[i];
            int j = i;
            while (j >= gap && A[j - gap] > key) { // Shift elements for insertion
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = key;
        }
    }
}

int main() {
    int size;

    // Taking input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int A[size]; // Declaring an array dynamically based on user input

    // Taking array input from user
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, size);

    shellSort(A, size);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
