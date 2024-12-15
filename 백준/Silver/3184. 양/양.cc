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

int R, C;
char board[250][250];

int bfs(int x, int y){
    int sheep = 0, wolf = 0;
    if(board[x][y] == 'o') ++sheep;
    if(board[x][y] == 'v') ++wolf;
    board[x][y] = '#';

    queue<pii> q;
    q.push({x, y});
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        for(int i=0; i<4; ++i){
            int nx = x + "2011"[i] - '1';
            int ny = y + "1120"[i] - '1';
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == 'o') ++sheep;
            if(board[nx][ny] == 'v') ++wolf;
            board[nx][ny] = '#';
            q.push({nx, ny});
        }
    }
    return sheep > wolf ? sheep : -wolf;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C;
    for(int i=0; i<R; ++i) for(int j=0; j<C; ++j) cin >> board[i][j];
    int sheep = 0, wolf = 0;
    for(int i=0; i<R; ++i) for(int j=0; j<C; ++j){
        if(board[i][j] == 'o') {
            int ret = bfs(i, j);
            if(ret > 0) sheep += ret;
            else wolf -= ret;
        }
        if(board[i][j] == 'v') {
            int ret = bfs(i, j);
            if(ret > 0) sheep += ret;
            else wolf -= ret;
        }
    }
    cout << sheep << ' ' << wolf;
    
    return 0;
}