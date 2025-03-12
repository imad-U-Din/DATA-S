#include <stdio.h>

// FOR UNSORTED AND SORTED ARRAY
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// USED FOR SORTED ARRAY
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low=0;
    high=size-1;
    // START SEARCHING
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    // SEARCHING ENDS
    return -1;
}

int main()
{   
    //UNSORTED ARRAY FOR LINEAR SEARCH 
    // int arr[] = {1, 2, 5, 56, 4, 3, 23, 5, 4, 54634, 56, 34};
    // int size = sizeof(arr) / sizeof(int);
    
    //SORTED ARRAY FOR BINARY SEARCH
    int arr[]={1,2,3,46,53,66,74,81,95};
    int size = sizeof(arr) / sizeof(int);
    int element = 53;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}