#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 21

/*
단순히 4방향으로 bfs를 하면 우선순위가 맞지 않음
*/

// 순서 중요하지 않음 위 -> 왼 -> 오른 -> 아래 지만,
// 이대로 하면 두번 이상 이동했을때 뒤죽박죽되서 틀림.
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int N, ans, nowX, nowY, nowDist;
int babyShark = 2;
int eatCount;
int graph[MAX][MAX];
bool visited[MAX][MAX];

void initVisited(){
    for (int i = 0; i < N; i++){
        for (int j=0; j < N; j++){
            visited[i][j]=false;
        }
    }
}

int bfs(){
    initVisited();
    queue<tuple<int,int,int>> q;

    // 최단거리로 먹을 수 있는 좌표들 pq
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    q.push({nowX, nowY, nowDist});

    // cout << "shark: " << babyShark << 
    // " / x : " << nowX << " / y : " << nowY << " / dist : " << nowDist << '\n';

    graph[nowX][nowY]=0;
    visited[nowX][nowY]=true;

    int time = -1;
    
    while (!q.empty()){

        auto [x, y, dist] = q.front();
        q.pop();

        // 최단거리에 이미 먹을게 있는데 다음 거리를 탐색한다면 종료
        if (dist == time) break;

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=N ) continue;
            if (visited[nx][ny]) continue;
            
            
            // 빈칸이거나 지날 수 있다면
            if (graph[nx][ny]==0 || graph[nx][ny]==babyShark) {
                visited[nx][ny]=true;
                q.push({nx, ny, dist+1});
            }

            // 경로에 먹을 수 있는게 있다면 pq에 기록
            else if (graph[nx][ny] < babyShark) {
                visited[nx][ny]=true;
                time = dist+1;
                pq.push({nx,ny});
            }
        }
    }

    // 아무것도 못먹는다면
    if (pq.empty()) return 0;

    // 우선순위 큐로 가장 위, 왼쪽에 있는 최단거리 
    pii now = pq.top();
    nowX = now.first;
    nowY = now.second;
    nowDist = time;

    graph[nowX][nowY] = 0;

    // 먹은 횟수가 넘어간다면 성장
    if (++eatCount==babyShark) {
        eatCount = 0;
        babyShark++;
    }

    return time;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (graph[i][j]==9) {
                nowX = i; nowY = j;
                break;
            }
        }
    }

    while (true){
        int time = bfs();
        if (time==0) break;  // 아무 것도 먹을 수 없음
        ans = time;
    }
    cout << ans;
    
    return 0;
}