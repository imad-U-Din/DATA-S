#include <stdio.h>

int main() {
   int size;
printf("Enter the size of an array: ");
scanf("%d",&size);

int arr[size];
    int element,i;
    int count = 0;

for( i=0;i<size;i++){
    printf("Enter Element %d:",i+1);
    scanf("%d",&arr[i]);
}
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    printf("Element %d found at positions: ", element);
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            printf("%d ", i);  
            count++;            
        }
    }

    if (count > 0) {
        printf("\nElement %d is present %d time(s).\n", element, count);
    } else {
        printf("\nElement %d is not present in the array.\n", element);
    }

    return 0;
}
