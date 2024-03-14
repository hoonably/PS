#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*
자기 자신으로 돌아오는 음수 간선이 있다면 YES
INF 비교를 사용하지 않음.
*/

#define INF 1e9

int N, M, W;  // N: 노드 개수, M: 간선 개수
vector<tuple<int,int,int>> edges;

bool time_travel() {
	vector<int> dist(N + 1, INF);

	dist[1] = 0;

    // N-1번 반복으로 돌리면서 dist 갱신
	for (int i = 1; i < N; i++) {
		for (auto edge : edges) {
			auto [cur_node, nxt_node, cost] = edge;
			if (dist[nxt_node] > dist[cur_node] + cost) {
				dist[nxt_node] = dist[cur_node] + cost;
			}
		}
	}
    // N번째에 또 감소하는 곳이 있으면 음수 사이클 존재
    for (auto edge : edges) {
        auto [cur_node, nxt_node, cost] = edge;
        if (dist[nxt_node] > dist[cur_node] + cost) {
			return true;
		}
    }

	return false;
}

void solve(){
    cin >> N >> M >> W;
    for (int i=0; i<M; i++){
        int S, E, T;
        cin >> S >> E >> T;
        edges.push_back({S,E,T});  //  S -> E 의 비용이 T
        edges.push_back({E,S,T});
    }
    for (int i=0; i<W; i++){
        int S, E, T;
        cin >> S >> E >> T;
        // 웜홀은 양방향 아님
        edges.push_back({S,E,-T});  //  S -> E 의 비용이 -T
    }

    if (time_travel()) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int TC;
    cin >> TC;

    while(TC--) {
        edges.clear();
        solve();
    }
    
    return 0;
}