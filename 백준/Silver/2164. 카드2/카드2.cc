#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    queue<int> card;
    
    cin >> N;

    // n이 1일때 예외처리
    if (N==1) {cout << 1; return 0;}

    for(int i=1; i<=N; i++){
        card.push(i);
    }

    while(true){
        // 버리기
        card.pop();

        // check
        if (card.size()==1){
            cout << card.front();
            break;
        }

        // 아래로 옮기기
        card.push(card.front());
        card.pop();
    }

    return 0;
}