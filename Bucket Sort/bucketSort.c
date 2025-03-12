#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10 // Define the number of buckets

// Function to print the array
void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Function to perform Bucket Sort
void bucketSort(int *A, int size) {
    int i, j, k;
    int max = A[0], min = A[0];
    
    // Find the maximum and minimum values in the array
    for (i = 1; i < size; i++) {
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }
    
    // Calculate the range of each bucket
    int bucketRange = (max - min) / BUCKET_COUNT + 1;
    int buckets[BUCKET_COUNT][size]; // Buckets to store elements
    int bucketSizes[BUCKET_COUNT] = {0}; // Keep track of the number of elements in each bucket

    // Distribute elements into buckets
    for (i = 0; i < size; i++) {
        int bucketIndex = (A[i] - min) / bucketRange;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = A[i];
    }

    // Sort individual buckets using insertion sort
    for (i = 0; i < BUCKET_COUNT; i++) {
        for (j = 1; j < bucketSizes[i]; j++) {
            int key = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate sorted buckets back into the original array
    k = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            A[k++] = buckets[i][j];
        }
    } 
}

int main() {
    int size;

    // Take input for array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int A[size]; // Declare the array

    // Take array input from the user
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Print the original array
    printf("Original array: ");
    printArray(A, size);

    // Perform Bucket Sort
    bucketSort(A, size);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(A, size);

    return 0;
}
