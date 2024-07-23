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
https://www.acmicpc.net/problem/1585

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 110, SRC = 101, SINK = 102;

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

	int h[SZ], inQ[SZ];
	int dists[SZ]; //dijkstra
	void init(){
		// SPFA : Shortest Path Faster Algorithm
		// Bellman-Ford로 업데이트 : O(VE)
		// johnson'SRC, SPFA 사용시 O(V+E)
        memset(h, INF, sizeof(h));
        memset(dists, INF, sizeof(dists));

		//johnson'SRC algorithm with spfa
        queue<int> q; q.push(SRC); inQ[SRC] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop(); inQ[now] = 0;
            for(auto next : graph[now]){
                if(next.cap && h[next.to] > h[now] + next.cost){
                    h[next.to] = h[now] + next.cost;
                    if(!inQ[next.to]) inQ[next.to] = 1, q.push(next.to);
                }
            }
        }
        for(int i=0; i<SZ; i++){
            for(auto &j : graph[i]) if(j.cap) j.cost += h[i] - h[j.to];
        }

		//get shortest path DAG with dijkstra
        priority_queue<pii> pq; pq.emplace(0, SRC); dists[SRC] = 0;
        while(pq.size()){
            int now = pq.top().second;
            int retCost = -pq.top().first;
            pq.pop();
            if(dists[now] - retCost) continue;
            for(auto i : graph[now]){
                if(i.cap && dists[i.to] > dists[now] + i.cost){
                    dists[i.to] = dists[now] + i.cost;
                    pq.emplace(-dists[i.to], i.to);
                }
            }
        }
        for(int i=0; i<SZ; i++) dists[i] += h[SINK] - h[SRC];
	}

	int chk[SZ], work[SZ];
	bool update(){
		int minflow = 1e9;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : graph[i]){
                if(j.cap && !chk[j.to]) minflow = min(minflow, dists[i] + j.cost - dists[j.to]);
            }
        }
		if(minflow >= 1e9) return 0;
		for(int i=0; i<SZ; i++){
			if(!chk[i]) dists[i] += minflow;
		}
        return 1;
	}

	int dfs(int now, int flow){
        chk[now] = 1;
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
	pii run(){ //{최소비용, 최대유량} 반환
		init();
		int retCost = 0, retFlow = 0;
		do{
			memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
			int now = 0;
			while(true){
				now = dfs(SRC, 1e9);
				if (now==0) break;
				retCost += dists[SINK] * now;
				retFlow += now;
				memset(chk, 0, sizeof chk);
			}
		}while(update());
		return {retCost, retFlow};
	}
}mcmf;

int s[51], e[51];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	for (int i=1; i<=N; i++){
		cin >> s[i];
	}
	for (int i=1; i<=N; i++){
		cin >> e[i];
	}

	int T; cin >> T;  // 과속 기준 시간
	int F; cin >> F;  // 벌금 최대값

	// SRC => start
	for (int i=1; i<=N; i++){
		mcmf.addEdge(SRC, i, 1, 0);
	}

	// end => SINK
	for (int i=1; i<=N; i++){
		mcmf.addEdge(i+50, SINK, 1, 0);
	}

	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (e[j]<=s[i]) continue;  // 매칭 불가능
			int over =  T - (e[j]-s[i]);
			if (over>0){
				over = min(over*over, F);  // 최대 F
				mcmf.addEdge(i, j+50, 1, over);
			}
			else mcmf.addEdge(i, j+50, 1, 0);
		}
	}

	auto ans = mcmf.run();

	// 최대 유량이 N보다 작다면
	if (ans.second<N) {
		cout << "-1";
		return 0;
	}

	mcmf.initGraph();

	// SRC => start
	for (int i=1; i<=N; i++)
		mcmf.addEdge(SRC, i, 1, 0);

	// end => SINK
	for (int i=1; i<=N; i++)
		mcmf.addEdge(i+50, SINK, 1, 0);

	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (e[j]<=s[i]) continue;  // 매칭 불가능
			int over =  T - (e[j]-s[i]);
			if (over>0){
				over = min(over*over, F);  // 최대 F
				mcmf.addEdge(i, j+50, 1, -over);
			}
			else mcmf.addEdge(i, j+50, 1, 0);
		}
	}

	cout << ans.first << ' ' << -mcmf.run().first;
}