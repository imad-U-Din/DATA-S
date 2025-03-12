#include <stdio.h>

int main() {
    int size;

    
    printf("Enter the number of students: ");
    scanf("%d", &size);

    int marks[size]; 

    printf("Enter the marks of the students:\n");
    for (int i = 1; i < size; i++) {
        printf("Student %d: ", i);
        scanf("%d", &marks[i]);
    }

    printf("Students with marks less than 35:\n");
    for (int i = 0; i < size; i++) {
        if (marks[i] < 35) {
            printf("Roll number: %d\n", i); 
        }
    }

    return 0;
}
