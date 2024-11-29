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

int N, M, K;
bool grid[101][101];

int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int bfs(int x, int y){
    queue<pii> q;
    q.push({x, y});
    grid[x][y] = 0;
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        auto [x, y] = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<=0 || nx>N || ny<=0 || ny>M || !grid[nx][ny]) continue;
            grid[nx][ny] = 0;
            q.push({nx, ny});
            
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<K; ++i){
        int r, c; cin >> r >> c;
        grid[r][c] = 1;
    }

    int ans = 0;
    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            if(grid[i][j]){
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans;
    
    return 0;
}