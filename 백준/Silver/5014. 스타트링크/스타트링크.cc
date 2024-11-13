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
전형적인 bfs 문제
*/

int f, s, g, u, d;

bool visited[1'000'001];
int bfs(){
    queue<pii> q;
    q.push({s,0});
    visited[s] = true;
    while(!q.empty()){
        auto [floor, times] = q.front(); q.pop();
        if (floor == g) return times;

        int up = floor + u;
        int down = floor - d;
        if (up<=f && !visited[up]) {
            visited[up] = true;
            q.push({up, times+1});
        }
        if (down>=1 && !visited[down]) {
            visited[down] = true;
            q.push({down, times+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    int ans = bfs();
    if (ans!=-1) cout << ans;
    else cout << "use the stairs";

    
    
    return 0;
}