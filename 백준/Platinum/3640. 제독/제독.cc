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

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 2010, SRC = 2001, SINK = 2002;

struct MCMF{  // use Dinic
	struct Edge{ int to, cap, cost, rev; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, int _cap, int _cost){
		graph[_from].push_back({_to, _cap, _cost, (int)graph[_to].size()});
		graph[_to].push_back({_from, 0, -_cost, (int)graph[_from].size()-1});
	}

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++)
			graph[i].clear();
	}

	bool inQ[SZ];
	int dists[SZ]; //dijkstra
    bool spfa() {
        memset(dists, 0x3f, sizeof(dists));  // = 0x3f3f3f3f = 106,119,567
        memset(inQ, false, sizeof(inQ));
        queue<int> q;
        q.push(SRC);
        inQ[SRC] = true;
        dists[SRC] = 0;
        while (q.size()) {
            int now = q.front();
            q.pop();
            inQ[now] = false;
            for (auto i: graph[now]) {
                if (i.cap && dists[i.to] > dists[now] + i.cost) {
                    dists[i.to] = dists[now] + i.cost;
                    if (!inQ[i.to]) inQ[i.to] = true, q.push(i.to);
                }
            }
        }
        return dists[SINK] < 1e9;
    }

	bool chk[SZ];
	int work[SZ];
	bool update(){
		int minflow = 1e9;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : graph[i]){
                if(j.cap && !chk[j.to])
					minflow = min(minflow, dists[i] + j.cost - dists[j.to]);
            }
        }
		if(minflow >= 1e9) return 0;
		for(int i=0; i<SZ; i++){
			if(!chk[i]) dists[i] += minflow;
		}
        return 1;
	}

	int dfs(int now, int flow){
        chk[now] = true;
        if(now == SINK) return flow;
        for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &i = graph[now][work[now]];
            if(!chk[i.to] && dists[i.to] == dists[now] + i.cost && i.cap){
                int ret = dfs(i.to, min(flow, i.cap));
                if(ret){
                    i.cap -= ret; graph[i.to][i.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
	}

    pair<int, int> run() {
        int cost = 0, flow = 0;
        while (spfa()) {
            memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
            int now = 0;
            while (true) {
				now = dfs(SRC, 1e9);
				if (now==0) break;
                cost += dists[SINK] * now;
                flow += now;
                memset(chk, 0, sizeof chk);
            }
        }
        return {cost, flow};
    }
} mcmf;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);


    int v, e;

    while(cin >> v >> e){  // EOF

        mcmf.initGraph();

        // in은 그대로, out은 +1000
        for (int i=1; i<=v; i++){
            mcmf.addEdge(i, i+1000, 1, 0);
        }

        // 두가지 경로로 나눠서 가므로 용량 2
        mcmf.addEdge(SRC, 1001, 2, 0);  // SRC=>1(out)
        mcmf.addEdge(v, SINK, 2, 0);    // v(in)=>SINK

        for (int i=1; i<=e; i++){
            int a, b, c;
            cin >> a >> b >> c;
            // 두 경로가 겹치면 안되므로 용량 1
            mcmf.addEdge(a+1000, b, 1, c);
        }

        pii ans = mcmf.run();
        cout << ans.first << '\n';
    }
}