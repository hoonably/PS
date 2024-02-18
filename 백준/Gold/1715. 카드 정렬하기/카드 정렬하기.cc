#include <bits/stdc++.h>
using namespace std;

/*
우선순위 큐를 사용해 

가장 작은 두 수를 뽑아서 합치고 또 그 큐에 넣는다. (이때 더한 두 수는 삭제)

이걸 반복하면 된다.
*/

int N;
int ans=0;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        int getNum;
        cin >> getNum;
        pq.push(-getNum);
    }
    for (int i=0; i<N-1; i++){
        int temp = -pq.top();
        pq.pop();
        temp += -pq.top();
        pq.pop();
        pq.push(-temp);
        ans += temp;
    }
    cout << ans;
    
    
    return 0;
}