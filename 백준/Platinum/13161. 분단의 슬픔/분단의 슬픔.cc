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
https://www.acmicpc.net/problem/13161

w[i,j] = 서로 다른 진영일 때 슬픔의 정도

E = 25,000개 F는 최대 500,000만이라 O(EF), O(VE^2) 둘다 택도 없음
그래서 O(V^2E)인 디닉알고리즘을 써야만 시간내에 해결이 가능
*/

#define MAX 

struct Dinic {
	struct Edge {
		int from, to, cap, rev;
		Edge(int from, int to, int cap) : from(from), to(to), cap(cap) {};
	};
	vector<vector<Edge>> graph;
	vector<int> work, level;
	int N, SRC, SINK;  // SOURCE(시작) => node => SINK(끝)

	// 생성자 (SRC, BRIDGE, SINK 위해서 10개 여분)
	Dinic(int N, int SRC, int SINK) : N(N+10), SRC(SRC), SINK(SINK) {
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
	int flow() {
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    Dinic mf(N, N+1, N+2);

    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        if (num==1){  // 무조건 A 진영
			mf.add_edge_from_source(i, INF);
        }
        else if (num==2){  // 무조건 B 진영
			mf.add_edge_to_sink(i,INF);
        }
    }

	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			int cap;
			cin >> cap;
			if (i==j) continue;
			mf.add_edge(i, j, cap);
		}
	}

	cout << mf.flow() << '\n';
	
	// A진영
	for (int i=1; i<=N; i++){
		if (mf.level[i] != -1) cout << i << ' ';
	}
	cout << '\n';

	// B진영
	for (int i=1; i<=N; i++){
		if (mf.level[i] == -1) cout << i << ' ';
	}
	cout << '\n';
    
    return 0;
}