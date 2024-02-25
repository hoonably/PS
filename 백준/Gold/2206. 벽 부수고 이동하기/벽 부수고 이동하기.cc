#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
tuple을 사용해 4개를 넣기
x, y, 벽부순횟수, 거리

첫 시도에서 틀린 이유
graph 방문 표시를 그래프에 직접 해주었는데, 이럴 경우 그곳에 벽을 부순적이 0회인지 1회인지 모르기 때문에
따로 visit 배열을 3차로 만들어서 벽을 부쉈는지의 여부에 따라 방문표시를 해줘야한다.
*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, M;
int graph[1000][1000];
bool visited[1000][1000][2];

int bfs(){

    queue<tuple<int,int,bool,int>> q;
    q.push({0,0,false,1});  // 이문제에서는 시작지점일때도 셈
    
    while (!q.empty()){
        auto [x,y,wall,dist] = q.front();
        q.pop();

        if (x==N-1 && y==M-1){
            return dist;
        }

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( nx<0 || nx>=N || ny<0 || ny>=M ) continue;
            if (visited[nx][ny][wall]) continue;

            // 빈곳일 경우
            if (graph[nx][ny]==0) {
                visited[nx][ny][wall] = true;  // 방문 표시
                q.push({nx, ny, wall, dist+1});
            }
            // 벽인데 아직 벽을 부순 적이 없는 경우
            else if (wall==false){
                visited[nx][ny][1] = true;
                q.push({nx, ny, true, dist+1});
            }
            
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            char getNum;
            cin >> getNum;
            graph[i][j] = getNum - '0';
        }
    }

    cout << bfs();

    return 0;
}