#include <stdio.h>
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int arr[size];
    int i;
    int product = 1;

    for (i = 0; i < size; i++)
    {
        printf("Enter element %d :", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < size; i++)
    {

        product = product * arr[i];
    }
    printf("%d", product);
}