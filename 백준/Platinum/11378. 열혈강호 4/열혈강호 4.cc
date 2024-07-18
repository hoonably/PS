#include <bits/stdc++.h>
#define FOR(now,a,b) for(int now=(a);now<(b);now++)
#define all(v) v.begin(), v.e()
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
https://www.acmicpc.net/problem/11378
네트워크 플로우

지난달에 벌점을 X점 받은 사람은 일을 최대 X+1개까지 할 수 있다.
각 직원은 자신이 지난달에 받은 벌점을 알지 못하고, 

벌점 총 합 K개를 적절히 분배해서 일을 최대 얼마나 할 수 있는지 구하기

https://kibbomi.tistory.com/46
위 블로그에 설명이 자세히 나와있다.

용량이 K(벌점총합)인 bridge를 사용

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	int N, M, K;
    cin >> N >> M >> K;
	Dinic mf(2005, 2001, 2002);

	// brunch 생성
    mf.add_edge_from_source(2000, K);

    for (int i=1; i<=N; i++) {
        int x;
		cin >> x;
        for (int j=0; j<x; j++) {
            int work;
			cin >> work;
			// 사람 => 일 (용량 1)
            mf.add_edge(i, work+N, 1);
        }

		// brunch => 사람 (용량 K)
        mf.add_edge(2000, i, K);

		// source => 사람 (용량 1)
        mf.add_edge_from_source(i, 1);
    }

    for (int iwork=1; iwork<=M; iwork++) {
		// 일 => Sink
		mf.add_edge_to_sink(iwork+N, 1);
	}
    cout << mf.maxFlow();
    
    return 0;
}