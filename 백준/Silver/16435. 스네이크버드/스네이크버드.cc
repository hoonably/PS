#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, L;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N >> L;
    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    while(!pq.empty()){
        // 먹을 수 있다면
        if (pq.top() <= L){
            pq.pop();
            L++;
        }
        else break;
    }
    cout << L;

    return 0;
}