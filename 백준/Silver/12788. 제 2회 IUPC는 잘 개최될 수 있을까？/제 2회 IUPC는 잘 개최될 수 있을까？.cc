#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;\
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int N, M, K, A;
priority_queue<int> pq;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        cin >> A;
        pq.push(A);
    }

    int remain = M*K;
    for(int i=0; i<N; i++){
        remain -= pq.top();
        pq.pop();
        if (remain <= 0){
            cout << i+1;
            return 0;
        }
    }
    cout << "STRESS";
    
    return 0;
}