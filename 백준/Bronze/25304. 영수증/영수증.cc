#include <iostream>
using namespace std;

int main(void){
    int X, N, a, b;
    cin >> X >> N;
    for (int i=0; i<N; i++){
        cin >> a >> b;
        X -= a*b;
    }
    // 삼항연산자 사용
    // 맞으면 ? 뒤에 실행
    // 틀리면 : 뒤에 실행
    (X==0) ? cout << "Yes" : cout << "No";
    return 0;
}