#include <bits/stdc++.h>
using namespace std;

/*
힙은 항상 top만 뽑을 수 있으므로
값의 -값을 넣어주고 출력할때도 -값으로 원상태로 출력한다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int> pq;
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int getNum;
        cin >> getNum;
        if (getNum==0){
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(-getNum);
        }
    }
    
    return 0;
}