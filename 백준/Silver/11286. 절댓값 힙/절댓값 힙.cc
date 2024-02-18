#include <bits/stdc++.h>
using namespace std;

/*
힙은 항상 top만 뽑을 수 있으므로
값의 -값을 넣어주고 출력할때도 -값으로 원상태로 출력한다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int> pq_minus;
    priority_queue<int> pq_plus;

    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        int getNum;
        cin >> getNum;
        if (getNum==0){
            if (pq_minus.empty() && pq_plus.empty()) cout << 0 << '\n';
            else if (pq_minus.empty()) {
                cout << -pq_plus.top() << '\n';
                pq_plus.pop();
            }
            else if (pq_plus.empty()) {
                cout << pq_minus.top() << '\n';
                pq_minus.pop();
            }
            else {
                if (-pq_minus.top() <= -pq_plus.top()){
                    cout << pq_minus.top() << '\n';
                    pq_minus.pop();
                }
                else {
                    cout << -pq_plus.top() << '\n';
                    pq_plus.pop();
                }
            }
        }
        else if (getNum > 0) pq_plus.push(-getNum);
        else pq_minus.push(getNum);
    }
    
    return 0;
}