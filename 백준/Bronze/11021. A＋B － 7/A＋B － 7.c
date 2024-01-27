#include <stdio.h>

int main(void){
    int T, A, B;
    scanf("%d", &T);
    for (int i=1; i<=T; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
    }
    return 0;
}