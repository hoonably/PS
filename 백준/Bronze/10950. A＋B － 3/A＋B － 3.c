#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);
    int A, B;
    for (int i=0; i<N; i++){
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }
    return 0;
}