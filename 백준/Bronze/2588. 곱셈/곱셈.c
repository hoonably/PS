#include <stdio.h>
#include <stdlib.h> // atoi 사용

int main(void){
    int num1, num2;
    char num[5]; // num[3]으로 하면 틀린다. 개행문자때문
    scanf("%d", &num1);
    scanf("%s", num);

    // 문자를 정수로 변환해주는 함수
    num2 = atoi(num);

    int ans3, ans4, ans5;
    ans3 = num1 * (num[2]-'0');
    ans4 = num1 * (num[1]-'0');
    ans5 = num1 * (num[0]-'0');
    printf("%d\n", ans3);
    printf("%d\n", ans4);
    printf("%d\n", ans5);
    printf("%d\n", num1*num2);
    return 0;
}