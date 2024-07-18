#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/11495

https://everenew.tistory.com/182

*/

#define MAX 

struct MaximumFlow
{
	struct Edge
	{
		int from, to, cap, rev;
		Edge(int from, int to, int cap) : from(from), to(to), cap(cap) {};
	};
	vector<vector<Edge>> graph;
	vector<int> work, level;
	int N, SRC, SINK;  // SOURCE(시작) => node => SINK(끝)

	// 생성자 (SRC, BRIDGE, SINK 위해서 10개 여분)
	MaximumFlow(int N, int SRC, int SINK) : N(N), SRC(SRC), SINK(SINK) {
		graph.resize(N+10);
		work.resize(N+10);
		level.resize(N+10);
	}

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void add_edge(int from, int to, int cap, int caprev = 0) {
		graph[from].emplace_back(from, to, cap);
		graph[to].emplace_back(to, from, caprev);
		graph[from].back().rev = graph[to].size() - 1;
		graph[to].back().rev = graph[from].size() - 1;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(SRC, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, SINK, cap);
	}
	int dfs(int c, int minFlow = INT_MAX) {
		if (c == SINK) {
			return minFlow;
		}
		int flow;
		for (int &i = work[c]; i < graph[c].size(); i++) {
			auto &e = graph[c][i];
			if (e.cap > 0 && level[e.to] == level[e.from] + 1 && (flow = dfs(e.to, min(e.cap, minFlow)))) {
				e.cap -= flow;
				graph[e.to][e.rev].cap += flow;
				return flow;
			}
		}
		return 0;
	}
	int maxFlow() {
		int ret = 0;
		queue<int> q;
		while(true) {
			int flow = 0;
			fill(level.begin(), level.end(), -1);
			q.push(SRC);
			level[SRC] = 0;
			while (!q.empty()) {
				int c = q.front();
				q.pop();
				for (auto &e : graph[c]) {
					if (e.cap > 0 && level[e.to] == -1) {
						level[e.to] = level[e.from] + 1;
						q.push(e.to);
					}
				}
			}
			fill(work.begin(), work.end(), 0);
			while (int temp = dfs(SRC)) {
				flow += temp;
			}
			if (flow == 0) {
				break;
			}
			ret += flow;
		}
		return ret;
	}
};

void solve(){
    int n, m;
    cin >> n >> m;

    MaximumFlow ff(2500, 2501, 2502);

    int totalSum = 0;
    bool isRed = true;
    int order = 1;  // 노드 번호
    int change_order[4]= {m, -m, 1, -1};  // 번호변경

    for (int r=0; r<n; r++){
        for (int c=0; c<m; c++){
            int cap;
            cin >> cap;
            totalSum+=cap;

            // red : Source 연결
            // 상하좌우 Blue와 연결
            if (isRed){
                ff.add_edge_from_source(order, cap);
                for(int i=0; i<4 ; ++i){
                    int nr = r + dx[i];
                    int nc = c + dy[i]; 

                    //범위 확인
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    
                    int blue_order = order + change_order[i];
                    ff.add_edge(order, blue_order, INF);
                }
            }
            // Blue : Sink 연결
            else {
                ff.add_edge_to_sink(order, cap);
            }

            order++;
            isRed^=1;
        }
        // 열이 짝수면 다시 색변경
        if (m%2==0) isRed^=1;
    }

    cout << totalSum - ff.maxFlow() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}