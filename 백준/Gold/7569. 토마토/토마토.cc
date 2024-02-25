#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
처음 시작점이 여러개인 최단거리 bfs
*/

int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int N, M, H;
int graph[100][100][100];

int bfs(){

    int dist = 0;

    // queue의 시작지점이 여러개
    queue<tuple<int,int,int,int>> q;
    for (int i=0; i<H; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<M; k++){
                if (graph[i][j][k]==1){
                    q.push({i,j,k,0});
                }
            }
            
        }
    }
    
    while (!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        dist = get<3>(q.front());
        q.pop();
        for (int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if ( nx<0 || nx>=H || ny<0 || ny>=N || nz<0 || nz>=M) continue;
            if (graph[nx][ny][nz]==0) {
                graph[nx][ny][nz] = 1;
                q.push({nx, ny, nz, dist+1});
            }
            
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> H;
    for (int i=0; i<H; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<M; k++){
                cin >> graph[i][j][k];
            }
        }
    }

    int day = bfs();
    
    // 안익은(0)게 있다면
    for (int i=0; i<H; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<M; k++){
                if (graph[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << day;

    return 0;
}