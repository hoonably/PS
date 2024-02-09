#include <iostream>
using namespace std;


int main(void){
    int A, B;
    cin >> A >> B;

    // 기본적으로 cout은 정수부 포함 6자리까지만 출력한다.

    // fixed를 안하면 정수부분까지 포함해서 10자리를 출력하게 된다.
    cout << fixed;  // 소수점 아래 숫자의 출력 범위만 설정
    cout.precision(10);  // 소수점 아래 10자리까지 출력

    cout << (double)A/B << endl;
    return 0;
}