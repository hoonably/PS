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




void solve(){
    int N; cin >> N;
    vector<int> adj(N+1);
    for(int i=1; i<=N; i++) cin >> adj[i];

    vector<bool> visited(N+1);
    int ans = 0;
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;  // already visited
        visited[i] = true;
        int cur = i;
        while(!visited[adj[cur]]){  // while문을 통해 사이클을 찾음
            visited[adj[cur]] = true;
            cur = adj[cur];
        }
        ans++;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}