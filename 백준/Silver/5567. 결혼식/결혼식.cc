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


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1);

    // 상근이의 친구들
    for(int i : adj[1]){
        visited[i] = true;
        for(int j=0; j<adj[i].size(); ++j){
            visited[adj[i][j]] = true;
        }
    }
    int ans = 0;
    for(int i=2; i<=n; ++i){
        if(visited[i]) ans++;
    }
    cout << ans;
    
    return 0;
}