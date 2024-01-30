#include <stdio.h>

// 문자 단위로 입력 받기 + EOF 이용 
int main() {
    char a;

    while(scanf("%c", &a) != EOF) {
        printf("%c", a);
    }

    return 0;
}

// 문자 단위로 입력 받기 + scanf 함수의 리턴값 이용
// int main() {
//     char a;

//     while(scanf("%c", &a) == 1) {
//         printf("%c", a);
//     }

//     return 0;
// }

// 문자열 단위로 입력 받기 + gets 함수의 리턴값 이용

// int main() {
//     char a[101];

//     while(gets(a) != NULL) { //gets함수는 char 포인터를 반환, 
//         printf("%s\n", a);   
        
//     }

//     return 0;
// }

// 문자열 단위로 입력 받기 + EOF 이용

// int main() {
//     char a[101];

//     while(scanf("%[^\n]", a) != EOF) {
//         printf("%s\n", a);
//         getchar(); //?
//         // %[^\n]을 사용해 \n이 나올 때까지 입력받고 
//         // \n을 버퍼에 남겨두었을 것이므로 제거해준다.
//     }

//     return 0;
// }
