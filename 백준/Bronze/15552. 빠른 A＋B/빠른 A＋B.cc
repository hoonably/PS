// 1. C언어 방식
// #include <stdio.h>

// int main(void){
//     int T, A, B;
//     scanf("%d", &T);
//     for (int i=0; i<T; i++){
//         scanf("%d %d", &A, &B);
//         printf("%d\n", A+B);
//     }
//     return 0;
// }

// 2. C++ 방식
#include <iostream>
using namespace std;

int main(void){
    // 주의 : 이 코드 사용시 printf 등을 사용하면 안된다.
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T, A, B;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> A >> B;
        // endl 사용시 느리다.
        cout << A+B << "\n";
    }
    return 0;
}