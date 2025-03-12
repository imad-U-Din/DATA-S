#include<stdio.h>
#include<limits.h>
int main(){
    int size;
    printf("Enter the size of an array: ");
    scanf("%d",&size);

    int arr[size];
    int i;
    int min=INT_MAX;

    for(i=0;i<size;i++){
        printf("Enter Element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<size;i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }

    printf("Minimum number in an array is %d",min);
    return 0;
}