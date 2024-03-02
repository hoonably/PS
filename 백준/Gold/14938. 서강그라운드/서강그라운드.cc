#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
# heapq를 사용한 다익스트라 알고리즘
# 음수 간선이 없을때만 사용 가능 -> 음수 간선이 있을 땐 벨만 포드
# O(ElogV) 로 시간복잡도가 빠르다.

다익스트라, 플로이드 워셜 알고리즘의 INF = 정점수 * 최대간선비용 +1
*/

int INF = 1e9;
int n, m, r;
// 간선 그래프
vector<vector<pair<int,int>>> graph;

vector<int> dijkstra(int start){
    vector<int> dist(n + 1, INF);  // INF로 선언과 동시에 초기화
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> r;
    graph.resize(n+1);

    // 아이템 수 받기
    int item[n+1];
    for (int i=1; i<=n; i++){
        cin >> item[i];
    }
    
    for (int i=0; i<r; i++){  // 간선 받기
        int a, b, l;
        cin >> a >> b >> l;
        if (l>m) continue;  // 가중치가 수색범위를 넘어가면 필요가 없음
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        // i에서 출발할때 모든 곳의 최단 경로
        vector<int> dist_i = dijkstra(i);

        int temp = 0;
        for (int d=1; d<=n; d++){
            if (dist_i[d]<=m){  // i->d 최단거리가 수색범위 이하라면
                temp += item[d];  // 아이템 먹기 가능
            }
        }
        ans = max(ans, temp);
    }
    cout << ans;
    
    return 0;
}