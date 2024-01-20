// EOF : 입력이 끝날때까지 출력하는 문제
#include <stdio.h>

int main(void) {
    int a,b;
    while(scanf("%d %d", &a, &b)!= EOF) {
        printf("%d\n", a+b);
    }
    return 0;
}