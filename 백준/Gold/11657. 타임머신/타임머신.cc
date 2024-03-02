#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
# 벨만 포드 알고리즘
# 음수 간선이 있을 때 사용 (다익스트라 사용시 무한루프 발생)
# 시간복잡도 : O(VE)
# V번 반복에 대해서 해당 정점과 연결되어 있는 모든 간선(E)을 탐색해주기 때문에
# 다익스트라보다 시간 복잡도가 느리니 음수 간선있을때만 사용한다.

조심해야할 점!!
INF를 잡을때 충분히 큰 값으로 잡아야한다.
기존 dist에 양수를 추가할때는 최적의 해를 찾기 때문에 막아주지만,
음수 사이클이 계속 갱신된다면 underflow로 음수가 int 범위를 넘을 수 있다. (-23억보다 작아짐)
*/

#define INF 1e11

int v, e;  // v: 노드 개수, e: 간선 개수
vector<tuple<int,int,int>> graph;

pair<bool, vector<ll>> bellmanFord(int start){
    vector<ll> dist (v + 1, INF);
    dist[start] = 0;

    // 전체 v-1 번의 라운드(round)를 반복
    for (int i=0; i<v; i++){
        for (int j=0; j<e; j++){
            auto [cur_node, nxt_node, cost] = graph[j];

            // 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if (dist[cur_node] != INF && dist[nxt_node] > dist[cur_node] + cost){
                dist[nxt_node] = dist[cur_node] + cost;

                // v(노드개수)만큼 반복했을때도 갱신된다면
                if (i == v-1) return {true, dist};  // 음수 순환 존재
            }
        }
    }
    return {false, dist};  // 음수 순환 없고, 최단거리 리스트 반환
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> v >> e;
    for (int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({a,b,c});  //  a -> b 의 비용이 c
    }

    auto [negative_cycle, dist] = bellmanFord(1);

    if (negative_cycle) cout << -1;
    else{
        for (int i=2; i<=v; i++){
            if (dist[i]==INF) cout << "-1\n";  // 도달 못한거임
            else cout << dist[i] << '\n';
        }
    }
    
    
    return 0;
}