#include <stdio.h>
#include <stdlib.h>

// GLOBAL VARIABLE
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
    int j;
    printf("%d ", i);
    visited[i]=1;
    for (j = 0; j < 7; j++)
    {
        if(a[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}

int main (){
    //DFS IMPLEMENTATION
    DFS(0); //IT WILL START FROM 0 (WE CAN CHANGE THE VALUE ALSO 1,2,3 ETC..)
    return 0;
}