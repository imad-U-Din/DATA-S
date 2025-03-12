#include <stdio.h>

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int size) {
    int key, j;
    // LOOP FOR PASSES
    for (int i = 1; i < size; i++) { 
        key = A[i];
        j = i - 1;
        // LOOP FOR EACH PASS
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
        printf("Enter element %d: ", i+1);
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, size);

    insertionSort(A, size);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
