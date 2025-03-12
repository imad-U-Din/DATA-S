#include<stdio.h>
#include<limits.h>
int main(){
    int size;
    printf("Enter size of an array: ");
    scanf("%d",&size);

    int arr[size];
    int i;
     int max=INT_MIN;
    for( i=0;i<size;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<size;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("Maximum number in an array is %d",max);


    return 0;
}