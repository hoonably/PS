#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
처음 시작점이 여러개인 최단거리 bfs
*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int graph[1000][1000];

int bfs(){

    int dist = 0;

    // queue의 시작지점이 여러개
    queue<tuple<int,int,int>> q;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (graph[i][j]==1){
                q.push({i,j,0});
            }
        }
    }
    
    while (!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        dist = get<2>(q.front());
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
            if (graph[nx][ny]==0) {
                graph[nx][ny] = 1;
                q.push({nx, ny, dist+1});
            }
            
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i][j];
        }
    }

    int day = bfs();
    
    // 안익은(0)게 있다면
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (graph[i][j]==0){
                cout << -1;
                return 0;
            }
        }
    }
    cout << day;

    return 0;
}