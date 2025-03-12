#include <stdio.h>

#define MAX_SIZE 100

void Array(int arr[], int size);
void printArray(int arr[], int size);
int sequentialSearch(int arr[], int size, int key);

int main()
{
    int arr[MAX_SIZE];
    int size = 10;
    int key = 12;

    Array(arr, size);

    printf("Array contents:\n");
    printArray(arr, size);

    // Perform sequential search
    printf("\nPerforming Sequential Search for %d:\n", key);
    int result = sequentialSearch(arr, size, key);
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

void Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sequentialSearch(int arr[], int size, int key)
{
    printf("Sequential Search steps:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Checking index %d: %d\n", i, arr[i]);
        if (arr[i] == key)
        {
            printf("Key found!\n");
            return i;
        } 
        if (arr[i] > key)
        {
            printf("Passed key value, stopping search.\n");
            break;
        }
    }
    printf("Key not found.\n");
    return -1;
}