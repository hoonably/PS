#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M, K;
int graph[50][50] = {0};

void bfs(int start_x, int start_y){
    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    graph[start_x][start_y]=0;
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
            if (graph[nx][ny]==0) continue;
            graph[nx][ny]=0;
            q.push({nx, ny});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
    
        cin >> N >> M >> K;
        for (int i=0; i<K; i++){
            int x, y;
            cin >> x >> y;
            graph[x][y]=1;
        }

        int ans = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (graph[i][j]==1){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n'; 

    }
    return 0;
}