// c program to store bank customer details using structure with pointer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct customer {
    int account_no;
    char name[30];
    float balance;
    char address[100];
};

int main(){
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    struct customer *ptr;
    ptr = (struct customer*) malloc(n * sizeof(struct customer));
    for(int i=0; i<n; i++){
        printf("Enter details of customer %d \n", i+1);
        printf("Enter customer account number: ");
        scanf("%d", &ptr->account_no);
        printf("Enter customer name: ");
        scanf("%19s", ptr->name);
        printf("Enter customer balance: ");
        scanf("%f", &ptr->balance);
        printf("Enter customer address: ");
        scanf("%99s", ptr->address);
        ptr++;
    }
    ptr = ptr - n;
    for(int i=0; i<n; i++){
        printf("Records of CUSTOMER : %d \n", i+1);
        printf("Account number is: %d \n", ptr->account_no);
        printf("Name is: %s \n", ptr->name);
        printf("Balance is: %f\n",ptr->balance);
        printf("Address is: %s\n\n",ptr->address);
        ptr++;
    }
    free(ptr);
    return 0;
}