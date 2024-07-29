#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solve (char *str, int t){
    int count = 0;
    int flag;
    for (int i = 0; i < strlen(str) - 1; i++){
        flag = 0;
        for (int j = 0; j < i; i++){
            if (str[i] == str[j] && str[i+1] == str[j+1]) {
                flag = 1;
            }
        }
        if (flag == 0){
            count++;
        }
    }
    printf("%d\n", count);
}


int main(void){
    int test = 0;
    char *ss;
    scanf("%d", &test);
    for (int i = 0; i < test; i++){
        ss = malloc(sizeof(char) * 100);
        scanf("%[^\n]s",ss);
        printf("cin");
        solve(ss, i);
        free(ss);
    }
}
