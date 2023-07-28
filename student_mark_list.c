// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int num_students;
    printf("Enter number of students:\t");
    scanf ("%d", &num_students);
    int num_subjects;
    printf("Enter number of subjects:\t");
    scanf ("%d", &num_subjects);
    // input the marks
    int marks[num_students][num_subjects];
    for (int i = 0; i < num_students; i++){
        for (int j = 0; j < num_subjects; j++){
            printf("Enter marks of student %d subject %d:\t", i + 1, j + 1);
            scanf("%d",& marks[i][j]);
        }
    }
    // display the output
    for (int i = 0; i < num_students; i++){
        printf("Marks of student %d:\n", i + 1);
        for (int j = 0; j < num_subjects; j++){
            printf("Subject %d => %d\n", j+1, marks[i][j]);
        }
    }
    return 0;
}