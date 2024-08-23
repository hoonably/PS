#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
// const int dz[6] = { 0,0,0,0,1,-1 };

/* -----------------------------------------------------

*/

#define MAX 

int h, w;
char board[101][101];
bool visited[101][101];
bool haveKey[26];

int bfs(int sx, int sy){

    int cnt = 0;

    queue<pair<int,int>> q; // Bfs 큐
    queue<pair<int,int>> door[27]; // 열쇠가 없었어서 방문하지 못했던 방의 큐
    visited[sx][sy] = true; 
    q.push({sx,sy});

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        // 현재 있는 곳이 $ 이면 정답 개수 +1
        if(board[x][y] == '$') cnt++;

        // 상하좌우 움직임
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            char c = board[nx][ny]; // 다음 위치의 단어

            // 이미 방문했거나, 벽이거나, 범위 밖으로 벗어나면 안됨
            if (nx < 0 || ny < 0 || nx > h+1 || ny > w+1 ||
                visited[nx][ny] || c == '*') continue;
            visited[nx][ny] = true;

            // 다음 위치가 문이라면
            if('A' <= c && c <= 'Z'){
                // 현재 해당 문의 키를 가지고 있지 않으면 해당 문의 큐에 넣음
                if(!haveKey[c-'A']) door[c-'A'].push({nx,ny});
                // 해당 문의 키를 가지고 있으면 bfs 큐에 넣음
                else q.push({nx,ny});
            }

            // 다음 위치가 열쇠
            else if('a'<= c && c <= 'z'){
                int idx = c-'a';
                haveKey[idx] = true;
                // 해당 문의 큐 안에 있는걸 전부 bfs 큐로 옮김
                while(!door[idx].empty()){
                    q.push(door[idx].front());
                    door[idx].pop();
                }
                q.push({nx,ny}); // 열쇠 칸으로 이동한 것을 큐에 넣음
            }

            // 다음 위치가 . 또는 $ 일때
            else q.push({nx,ny});
        }
    }

    return cnt;
} 

void solve(){

    memset(board, ' ', sizeof(board));
    memset(haveKey, false, sizeof(haveKey));
    memset(visited, false, sizeof(visited));

    cin >> h >> w;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> board[i][j];
        }
    }

    // 이미 가지고 있는 열쇠
    string keys;
    cin >> keys;
    if (keys[0]!='0'){
        for(char k : keys){
            haveKey[k-'a'] = true;
        }
    }

    cout << bfs(0,0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}