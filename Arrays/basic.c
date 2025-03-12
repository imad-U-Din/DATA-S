#include <stdio.h>
int main()
{
    int arr[5];
    int i;
    // arr[4] = 100;
    for (i = 0; i < 5; i++)
    {

        printf("Enter element %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Given Array:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    // printf("%d", arr[4]);
}