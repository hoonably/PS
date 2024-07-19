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

*/

#define MAX 

struct MCMF{
	vector<vector<int>> flow, capacity, parent, cost;
	int SRC, SINK, N; //source, sink, verties(+10)

	// 생성자 (SRC, BRIDGE, SINK 위해서 10개 여분)
	MCMF(int N, int source, int sink) : N(N+10), SRC(source), SINK(sink) {
		flow.resize(N+10), capacity.resize(N+10), parent.resize(N+10), cost.resize(N+10);
		for(int i=0; i<N+10; i++){
			flow[i].resize(N+10);
			capacity[i].resize(N+10);
            cost[i].resize(N+10);
		}
	}
	void setSource(int t){ SRC = t; }
	void setSink(int t){ SINK = t; }

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void add_edge(int from, int to, int cap, int caprev = 0) {
		parent[from].emplace_back(to);
		parent[to].emplace_back(from);
		capacity[from][to] += cap;
		capacity[to][from] += caprev;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(SRC, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, SINK, cap);
	}

    // 비용
    void add_cost(int from, int to, int c){
        cost[from][to] = c;
        cost[to][from] = -c;
    }

	// flow 초기화
	void init(){
		fill(flow.begin(), flow.end(), vector<int> (N,0));
	}

    // SPFA를 사용한 MCMF
	pii getMCMF(){
		int retCost = 0, retFlow=0;
		vector<int> par(N+1), c(N+1);
        vector<bool> inQ(N+1);

		while(true){
			fill(par.begin(), par.end(), -1);
            fill(c.begin(), c.end(), INF);

            c[SRC] = 0;
            inQ[SRC] = true;

			queue<int> q;
			q.push(SRC);
			while(!q.empty()){
				int now = q.front(); q.pop();
                inQ[now] = false;
				for (auto nxt : parent[now]){
                    // par[nxt] == -1 && 
					if (capacity[now][nxt]-flow[now][nxt] > 0 && c[nxt] > c[now] + cost[now][nxt]){
						c[nxt] = c[now] + cost[now][nxt];
                        par[nxt] = now;
                        if (!inQ[nxt]) {
                            q.push(nxt);
                            inQ[nxt] = true;
                        }
					}
				}
			}

			// 종료
			if(par[SINK] == -1) break;

			// 거꾸로 최소 유량 탐색
			int minFlow = INF;
			for(int i=SINK; i!=SRC; i = par[i]){
				minFlow = min(minFlow, capacity[par[i]][i] - flow[par[i]][i]);
			}
			// 최소 유량 처리
			for(int i=SINK; i!=SRC; i = par[i]){
                retCost += minFlow * cost[par[i]][i];  // 최소 비용
				flow[par[i]][i] += minFlow; 
				flow[i][par[i]] -= minFlow;
			}
            retFlow++;
		}
		return {retCost,retFlow};  // {최소비용, 최대유량}
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    MCMF mf(800, 801, 802);

    for (int i=1; i<=N; i++) {
        int x;
		cin >> x;
        for (int j=0; j<x; j++) {
            int work, cost;
			cin >> work >> cost;
			// 사람 => 일 (용량 1)
            mf.add_edge(i, work+N, 1);
            // 거리 cost, -cost로 설정
            mf.add_cost(i, work+N, cost);
        }

		// source => 사람 (용량 1)
        mf.add_edge_from_source(i, 1);
    }

    for (int iwork=1; iwork<=M; iwork++) {
		// 일 => Sink
		mf.add_edge_to_sink(iwork+N, 1);
	}

    pii ans = mf.getMCMF();
    cout << ans.second << '\n' << ans.first << '\n';
    
    return 0;
}