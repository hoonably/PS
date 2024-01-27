#include <stdio.h>

int main(void){
    int X, N, a, b;
    scanf("%d %d", &X, &N);
    for (int i=0; i<N; i++){
        scanf("%d %d", &a, &b);
        X -= a*b;
    }
    // 삼항연산자 사용
    // 맞으면 ? 뒤에 실행
    // 틀리면 : 뒤에 실행
    (X==0) ? printf("Yes") : printf("No");
    return 0;
}