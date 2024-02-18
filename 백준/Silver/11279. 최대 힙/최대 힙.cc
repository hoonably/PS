#include <bits/stdc++.h>
using namespace std;

/*

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
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            pq.push(getNum);
        }
    }
    
    return 0;
}