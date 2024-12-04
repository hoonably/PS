#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

/*
# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.

다익스트라, 플로이드 워셜 알고리즘의 INF = 정점수 * 최대간선비용 +1
*/

int INF = 1e9;
int V, E;
// 간선 그래프
vector<vector<pii>> graph;

vector<int> dijkstra(int start){
    vector<int> dist(V + 1, INF);  // INF로 선언과 동시에 초기화
    priority_queue<pii> pq;  // 우선순위 큐 선언

    dist[start] = 0;
    pq.push({0, start});  // 우선순위 큐에 넣기 (힙큐이므로 순서 중요!!)

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[cur_node]) continue;

        for (auto& edge : graph[cur_node]) {
            int nxt_node = edge.first;
            int nxt_dist = edge.second + cur_dist;
            
            if (nxt_dist < dist[nxt_node]) {  // 유망하면
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }

    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int A, B, C;
    cin >> V;
    cin >> A >> B >> C;  // K: 시작점
    cin >> E;

    graph.resize(V+1);
    
    for (int i=0; i<E; i++){  // 간선 받기
        int u, v, w;
        cin >> u >> v >> w;
        // (목적지 노드, 가중치) 형태로 저장
        graph[u].push_back({v, w});
        // 양방향이라면
        graph[v].push_back({u, w});
    }

    vector<int> dist_A = dijkstra(A);
    vector<int> dist_B = dijkstra(B);
    vector<int> dist_C = dijkstra(C);

    int farthest = 0;
    int ans = 0;
    for(int i=1; i<=V; i++){
        int temp = min({dist_A[i], dist_B[i], dist_C[i]});
        if (farthest < temp){
            farthest = temp;
            ans = i;
        }
    }
    cout << ans;

    return 0;
}