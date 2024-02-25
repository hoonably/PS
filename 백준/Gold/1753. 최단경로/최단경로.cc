#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
이 문제에서는 양방향이 아니다.
# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.
*/

int INF = 1e9;
int V, E, K;
// 간선 그래프
vector<vector<pair<int,int>>> graph(20001);

vector<int> dijkstra(int start){
    vector<int> dist(V + 1, INF);  // INF로 선언과 동시에 초기화
    priority_queue<pair<int, int>> pq;  // 우선순위 큐 선언

    dist[start] = 0;
    pq.push({0, start});  // 우선순위 큐에 넣기 (힙큐이므로 순서 중요!!)

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[cur_node]) continue;

        for (auto& edge : graph[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second + cur_dist;
            
            if (next_dist < dist[next_node]) {  // 유망하면
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }

    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> V >> E;  // V: 노드 개수, E: 간선 개수
    cin >> K;  // K: 시작점
    
    for (int i=0; i<E; i++){  // 간선 받기
        int u, v, w;
        cin >> u >> v >> w;
        // (목적지 노드, 가중치) 형태로 저장
        graph[u].push_back({v, w});
    }

    // K에서 출발할때 모든 곳의 최단 경로
    vector<int> dist_K = dijkstra(K);

    for (int i=1; i<=V; i++){
        if (dist_K[i]==INF) cout << "INF" << '\n';
        else cout << dist_K[i] << '\n';
    }
    
    return 0;
}