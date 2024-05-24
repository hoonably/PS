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

struct MaximumFlow
{
	struct Edge
	{
		int from, to, cap, rev;
		Edge(int from, int to, int cap) : from(from), to(to), cap(cap) {};
	};
	vector<vector<Edge>> graph;
	vector<int> work, level;
	int N, src, sink;

	// 생성자
	MaximumFlow(int N, int src, int sink) : N(N), src(src), sink(sink) {
		graph.resize(N);
		work.resize(N);
		level.resize(N);
	}


	void add_edge(int from, int to, int cap) {
		graph[from].emplace_back(from, to, cap);
		graph[to].emplace_back(to, from, cap);
		graph[from].back().rev = graph[to].size() - 1;
		graph[to].back().rev = graph[from].size() - 1;
	}
	
    void add_diedge(int from, int to, int cap) {
		graph[from].emplace_back(from, to, cap);
		graph[to].emplace_back(to, from, 0);
		graph[from].back().rev = graph[to].size() - 1;
		graph[to].back().rev = graph[from].size() - 1;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(src, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, sink, cap);
	}
	int dfs(int c, int MF = INT_MAX) {
		if (c == sink) {
			return MF;
		}
		int flow;
		for (int &i = work[c]; i < graph[c].size(); i++) {
			auto &e = graph[c][i];
			if (e.cap > 0 && level[e.to] == level[e.from] + 1 && (flow = dfs(e.to, min(e.cap, MF)))) {
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
			q.push(src);
			level[src] = 0;
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
			while (int temp = dfs(src)) {
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
	MaximumFlow mf(2005, 2001, 2002);


    mf.add_edge_from_source(2000, K);

    for (int i=1; i<=N; i++) {
        int x;
		cin >> x;
        for (int j=0; j<x; j++) {
            int to;
			cin >> to;
            mf.add_diedge(i, to+N, 1);
        }
        mf.add_diedge(2000, i, K);
        mf.add_edge_from_source(i, 1);
    }
    for (int i=1; i<=M; i++) {
		mf.add_edge_to_sink(i+N, 1);
	}
    cout << mf.flow();
    
    return 0;
}