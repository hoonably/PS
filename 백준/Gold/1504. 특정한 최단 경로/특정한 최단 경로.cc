#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

INF를 1e9로 설정시 int 범위를 넘어갈 수 있어서 음수의 이상한 값이 나올 수 있다.
INF를 무작정 1e9로 설정하지 말던가, long long 을 사용하자.

# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.
*/

int INF = 1e8;
int N, E, v1, v2;
// 간선 그래프
vector<vector<pair<int,int>>> graph(20001);

vector<int> dijkstra(int start){
    vector<int> dist(N + 1, INF);  // INF로 선언과 동시에 초기화
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
    
    cin >> N >> E;  // V: 노드 개수, E: 간선 개수
    
    for (int i=0; i<E; i++){  // 간선 받기
        int u, v, w;
        cin >> u >> v >> w;
        // (목적지 노드, 가중치) 형태로 저장
        graph[u].push_back({v, w});
        // 양방향이라면
        graph[v].push_back({u, w});
    }
    cin >> v1 >> v2;

    // 1에서 출발할때 모든 곳의 최단 경로
    vector<int> dist_1 = dijkstra(1);
    vector<int> dist_v1 = dijkstra(v1);
    vector<int> dist_v2 = dijkstra(v2);

    // 1 >> v1 >> v2 >> N
    int path_v1v2 = dist_1[v1] + dist_v1[v2] + dist_v2[N];
    // 1 >> v2 >> v1 >> N
    int path_v2v1 = dist_1[v2] + dist_v2[v1] + dist_v1[N];

    int ans = min(path_v1v2, path_v2v1);
    if (ans >= INF) cout << -1;
    else cout << ans;
    
    return 0;
}