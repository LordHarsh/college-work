#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[30];
    float percentage;
};

int main() {
    int i, n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student record[n];
    // input details
    for(i=0; i<n; i++){
        printf("Enter details of student %d \n", i+1);
        printf("Enter student id: ");
        scanf("%d", &record[i].id);
        printf("Enter student name: ");
        scanf("%19s", record[i].name);
        printf("Enter student percentage: ");
        scanf("%f", &record[i].percentage);
    }
    
    for(i=0; i<n; i++){
        printf("Records of STUDENT : %d \n", i+1);
        printf("Id is: %d \n", record[i].id);
        printf("Name is: %s \n", record[i].name);
        printf("Percentage is: %f\n\n",record[i].percentage);
    }
    return 0;
}