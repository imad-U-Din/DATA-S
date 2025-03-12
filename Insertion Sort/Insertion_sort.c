#include<stdio.h>

void printArray(int *A,int size){
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertionSort(int *A,int size){
    int key,j; 
    //LOOP FOR PASSES
    for(int i=1;i<= size - 1;i++){
        //LOOP FOR EACH PASS
        key=A[i];
        j=i-1;
        while (j>=0 && A[j] > key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key; 
    }
    printf("\n");
}
int main(){
    //-1  0  1  2  3  4  5 -> INDEX
    //    7 12 54  65  23  9 -> SORTED ARRAY
    int A[]={12,54,65,7,23,9};
    int size=6;
    printArray(A,size);
    insertionSort(A,size);
    printArray(A,size);
    return 0;
}