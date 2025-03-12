#include <stdio.h>

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void heapify(int *A, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && A[left] > A[largest])
        largest = left;

    if (right < size && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapify(A, size, largest);
    }
}

void heapSort(int *A, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(A, size, i);

    for (int i = size - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heapify(A, i, 0);
    }
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

    heapSort(A, size);

    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
