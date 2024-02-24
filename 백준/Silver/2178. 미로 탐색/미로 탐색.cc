#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int graph[100][100];
int dist[100][100];
bool visited[100][100];

int bfs(int start_x, int start_y){
    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    visited[start_x][start_y]=true;
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int now_dist = dist[x][y];
        
        if (x==N-1 && y==M-1){
            return dist[N-1][M-1];
        }

        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
            if (graph[nx][ny]==0) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dist[nx][ny] = now_dist + 1;
            q.push({nx, ny});
        }
    }
    return -1;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            char getChar;
            cin >> getChar;
            graph[i][j] = getChar - '0';
        }
    }

    // 이 문제에서는 시작 위치도 답에 포함하므로 +1
    cout << bfs(0,0) + 1;

    return 0;
}