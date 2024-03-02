#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e9

/*

*/

int n, m, t, s, g, h;
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

void solve(){
    cin >> n >> m >> t;

    // 간선 그래프 초기화
    graph.clear();
    graph.resize(n+1);

    cin >> s >> g >> h;
    for (int i=0; i<m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    // 목적지 후보
    int goal[t];
    for (int i=0; i<t; i++){
        cin >> goal[i];
    }
    sort(goal, goal+t);

    auto startS = dijkstra(s);  // s에서 출발
    auto startG = dijkstra(g);  // g에서 출발
    auto startH = dijkstra(h);  // h에서 출발

    for (int d : goal){
        // s -> g -> h -> d (목적지)인경우
        if (startS[d]==startS[g]+startG[h]+startH[d]){
            cout << d << ' ';
        }
        // s -> h -> g -> d
        else if (startS[d]==startS[h]+startH[g]+startG[d]){
            cout << d << ' ';
        }
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}