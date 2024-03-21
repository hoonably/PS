#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX


/*
비트마스킹 연습으로 풀어보자.
집합 사용 X
집합을 숫자 하나로 나타낼 수 있다. (이진법)
이 문제에서는 최대 2^21 이므로 int 내에서 해결 가능하지만,
앞으로는 long long을 사용해야 할 가능성이 크다.

EX)
10진법 17
2진법 001001
배열 false false true false false true
 => 0, 3 이 집합에 존재, 나머지는 없음
*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int M;
    cin >> M;
    int x;
    string command;

    int S = 0;  // 배열로 사용

    while(M--){
        cin >> command;

        // 추가 : 1과 OR 연산
        if (command=="add") {
            cin >> x;
            S |= (1<<x);  // 1을 x만큼 왼쪽으로 시프트 (2^X)
        }

        // 제거 : 0과 AND 연산
        else if (command=="remove"){
            cin >> x;
            S &= ~(1<<x);  // 2^X 의 반대와 and 연산
            
            // 10000 을 NOT(~) 연산 => 01111
            // 01111 과 AND 연산 => 5번째 자리가 0이 될것임.
        }

        // 있는지 확인
        else if (command=="check"){
            cin >> x;
            if (S & (1<<x)) cout << "1\n";  // 있다면
            else cout << "0\n";
        }

        // 반대로 바꿔주기
        else if (command=="toggle"){
            cin >> x;
            S ^= (1<<x);
            // x번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // x번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
        }

        // 모두 true로 바꾸기
        else if (command=="all"){
            S = (1<<21)-1;  
            // 2의 21제곱 -1
            // 11111111111111111111  (1이 20개)
        }

        // 모두 false로
        else {
            S = 0;
        }
    }
    
    return 0;
}