#include <stdio.h>

void solve (int t){
    int x, y, z;
    int total = 0;
    scanf("%d %d %d", &x, &y, &z);
    total += x * y;
    if (x % 3 == 0)
        total += (int)(x/3 - 1) * z;
    else
        total += (int)(x/3) * z;
    printf("%d\n", total);
}


int main(void){
    int test = 0;
    scanf("%d", &test);
    for (int i = 0; i < test; i++){
        solve(i);
    }
}