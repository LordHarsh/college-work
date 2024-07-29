#include <stdio.h>
#include <string.h>
struct employee {
    int id;
    char name[30];
    float salary;
};

int main(){
    int n;
    // printf("Enter number of employee");
    // scanf("%d", &n);
    struct employee emp;
    printf("Enter employee id: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%19s", emp.name);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    // output
    printf("Employee id: %d\n", emp.id);
    printf("Employee name: %s\n", emp.name);
    printf("Employee salary: %f\n", emp.salary);
    return 0;
}