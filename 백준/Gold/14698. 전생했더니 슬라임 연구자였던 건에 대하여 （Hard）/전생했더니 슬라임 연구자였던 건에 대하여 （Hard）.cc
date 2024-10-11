#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve(){
    int n; cin >> n;
    ll x;
    for(int i=0; i<n; i++){
        cin >> x; pq.push(x);
    }

    ll ans = 1;
    ll newSlime;
    for(int i=0; i<n-1; i++){
        newSlime = pq.top(); pq.pop();
        newSlime *= pq.top(); pq.pop();
        pq.push(newSlime);
        ans *= newSlime % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';

    pq.pop();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) solve();   
    
    return 0;
}