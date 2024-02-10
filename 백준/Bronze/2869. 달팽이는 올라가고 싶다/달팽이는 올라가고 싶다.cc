#include <iostream>
using namespace std;

int main(){
    int a, b, v;
    cin >> a >> b >> v;
    int go = a - b;
    int answer = (v - a) / go; // 마지막 a만큼 가는걸 미리 빼고 나눈 횟수
    int now = go * answer;
    while(true) {
        now+=a;
        answer++;
        if(now>=v) {
            break;
        }
    }
    cout << answer;
    
    return 0;
}