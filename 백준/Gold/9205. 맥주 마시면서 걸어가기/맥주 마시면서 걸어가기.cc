#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

int dist(pii a, pii b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

bool able[103];

void solve(){
    memset(able, 0, sizeof(able));
    int n; cin >> n;
    vector<pii> v(n+2);
    cin >> v[0].first >> v[0].second;
    for(int i=1; i<=n; i++) cin >> v[i].first >> v[i].second;
    cin >> v[n+1].first >> v[n+1].second;

    able[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=1; i<=n+1; i++){
            if(able[i]) continue;
            if(dist(v[cur], v[i]) <= 1000){
                able[i] = 1;
                q.push(i);
            }
        }
    }
    if (able[n+1]) cout << "happy\n";
    else cout << "sad\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
    
    return 0;
}