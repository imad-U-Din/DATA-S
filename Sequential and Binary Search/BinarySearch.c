#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int nums[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(nums) / sizeof(nums[0]);
    int key = 7;

    int result = binarySearch(nums, n, key);

    if (result != -1)
    {
        printf("Found %d at index %d.\n", key, result);
    }
    else
    {
        printf("%d not found.\n", key);
    }

    return 0;
}
