// EOF : 입력이 끝날때까지 출력하는 문제
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(!(cin >> a >> b).eof()) {
        cout << a+b << '\n';
    }
    return 0;
}