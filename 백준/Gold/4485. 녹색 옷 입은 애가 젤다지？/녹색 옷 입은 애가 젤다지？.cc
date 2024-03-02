#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.
*/

#define MAX 126
#define INF 1e9

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N;
int graph[MAX][MAX];

int dijkstra(){

    int dist[N][N];
    fill(&dist[0][0], &dist[N-1][N], INF);  // INF로 2차원 배열 초기화

    priority_queue<tuple<int, int, int>> pq;  // 우선순위 큐 선언

    dist[0][0] = graph[0][0];
    pq.push({-graph[0][0], 0, 0});  // 우선순위 큐에 넣기 (힙큐이므로 순서 중요!!)

    while (!pq.empty()) {
        auto [cur_dist, x, y] = pq.top();
        cur_dist = -cur_dist;  // 음수로 저장되어있으니 양수로 변경
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[x][y]) continue;

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if ( nx<0 || nx>=N || ny<0 || ny>=N ) continue;

            int nxt_dist = cur_dist + graph[nx][ny];
            if (nxt_dist < dist[nx][ny]){  // 유망하다면
                dist[nx][ny] = nxt_dist;
                pq.push({-nxt_dist, nx, ny});
            }
        }
    }

    return dist[N-1][N-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    while (true){
        cin >> N;
        if (N==0) break;

        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                cin >> graph[i][j];
            }
        }
        printf("Problem %d: %d\n", T, dijkstra());
        T++;
    }
    
    return 0;
}