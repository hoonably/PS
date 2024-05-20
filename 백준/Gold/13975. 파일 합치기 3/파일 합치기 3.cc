#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/13975
이 문제는 dp 문제와 다르게 순서가 연속된 것이 
*/

#define MAX 

int K;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve(){
    
    cin >> K;

    for (int i=0; i<K; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    ll ans = 0;
    while(true){

        ll temp = pq.top();
        pq.pop();

        if (pq.empty()) break;

        temp += pq.top();
        pq.pop();
        
        ans += temp;

        pq.push(temp);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}