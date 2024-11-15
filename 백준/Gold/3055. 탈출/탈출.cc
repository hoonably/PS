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
flooded fields by '*'
rocks by 'X'
Beaver's den is represented by 'D'
the Painter and the three little hedgehogs are shown as 'S'. 
shortest possible time needed for the Painter and the three little hedgehogs to safely reach the Beaver's den.
*/

int R, C;
char graph[50][50];
int visited[50][50];
queue<pii> Q;
pii start;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int bfs() {
    visited[start.first][start.second] = 1;
 
    // 고슴도치가 가장 마지막에 움직이므로,
    Q.push(start);
 
    while (!Q.empty()) {
        auto [x,y] = Q.front(); Q.pop();
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx < 0 || nx >= R) continue;
            if (ny < 0 || ny >= C) continue;
            if (graph[nx][ny] == 'X') continue;  // rock
            if (visited[nx][ny]) continue;

            // 물이 움직인다.
            if (graph[x][y] == '*') {
                if (graph[nx][ny] == '*' || graph[nx][ny] == 'D') continue;
                graph[nx][ny] = '*';
                Q.push({nx, ny});
            }
            // 고슴도치가 움직인다.
            else if(graph[x][y] == 'S'){
                if (graph[nx][ny] == 'D') return visited[x][y];  // find answer
                if (graph[nx][ny] == '*') continue;  // flooded
 
                graph[nx][ny] = 'S';
                visited[nx][ny] = visited[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
 
    // 정답이 나올 수 없는 경우.
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '*') Q.push({i, j});
            else if (graph[i][j] == 'S') start = {i, j};
        }
    }
    int ans = bfs();
    if (ans!=-1) cout << ans;
    else cout << "KAKTUS";
    
    return 0;
}