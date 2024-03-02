#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
파동은 dist변화 없이 pushleft
*/

#define MAX 301

int N, M, X1, Y1, X2, Y2;
char graph[MAX][MAX];
bool visited[MAX][MAX];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int bfs(){
    deque<tuple<int,int,int>> dq;
    dq.push_back({X1, Y1, 1});
    visited[X1][Y1]=true;
    
    while(!dq.empty()){
        auto [x, y, dist] = dq.front();
        dq.pop_front();

        if (x==X2 && y==Y2) return dist;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<=0 || nx>N || ny<=0 || ny>M ) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny]=true;
            // 사람에 부딫힘
            if (graph[nx][ny]=='1'){
                graph[nx][ny] = '0';
                dq.push_back({nx,ny,dist+1});
            }
            // 빈공간이거나 #에 도달
            else {
                dq.push_front({nx,ny,dist});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    cin >> X1 >> Y1 >> X2 >> Y2;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin >> graph[i][j];
        }
    }

    cout << bfs();
    
    return 0;
}