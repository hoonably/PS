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

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int L,R,C;
char building[30][30][30];
int dist[30][30][30];

int solve(){
    int sx,sy,sz,ex,ey,ez;
    for (int i=0; i<L; i++){
        for (int j=0; j<R; j++){
            for (int k=0; k<C; k++){
                cin >> building[i][j][k];
                if (building[i][j][k] == 'S'){
                    sx = i; sy = j; sz = k;
                }
                if (building[i][j][k] == 'E'){
                    ex = i; ey = j; ez = k;
                }
            }
        }
    }

    // BFS
    queue<tiii> q;
    q.push({sx,sy,sz});
    memset(dist,0x3f,sizeof(dist));
    dist[sx][sy][sz] = 0;

    while(!q.empty()){
        auto [x,y,z] = q.front(); q.pop();
        for (int i=0; i<6; i++){
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
            if (building[nx][ny][nz] == '#') continue;  // wall check
            if (dist[nx][ny][nz] != INF) continue;  // visited check
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx,ny,nz});
        }
    }

    if (dist[ex][ey][ez] == INF) return -1;
    return dist[ex][ey][ez];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(true){
        cin >> L >> R >> C;
        if (L == 0) break;
        int ans = solve();
        if (ans == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
    
    return 0;
}