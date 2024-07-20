#include <bits/stdc++.h>
#define FOR(i,workNum,cost) for(int i=(workNum);i<(cost);i++)
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
https://www.acmicpc.net/problem/11408

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 810;
struct MCMF{
	int SRC, SINK; //source, sink
	struct Edge{ int v, c, dist, dual; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, int _cap, int _dist){
		graph[_from].push_back({_to, _cap, _dist, (int)graph[_to].size()});
		graph[_to].push_back({_from, 0, -_dist, (int)graph[_from].size()-1});
	}

	int h[SZ], inQ[SZ];
	int dists[SZ]; //dijkstra
	void init(int _s, int _t){
		// SPFA : Shortest Path Faster Algorithm
		// Bellman-Ford로 업데이트 : O(VE)
		// johnson'SRC, SPFA 사용시 O(V+E)
		SRC = _s, SINK = _t;
        memset(h, INF, sizeof(h));
        memset(dists, INF, sizeof(dists));

		//johnson'SRC algorithm with spfa
        queue<int> q; q.push(SRC); inQ[SRC] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop(); inQ[now] = 0;
            for(auto next : graph[now]){
                if(next.c && h[next.v] > h[now] + next.dist){
                    h[next.v] = h[now] + next.dist;
                    if(!inQ[next.v]) inQ[next.v] = 1, q.push(next.v);
                }
            }
        }
        for(int i=0; i<SZ; i++){
            for(auto &j : graph[i]) if(j.c) j.dist += h[i] - h[j.v];
        }

		//get shortest path DAG with dijkstra
        priority_queue<pii> pq; pq.emplace(0, SRC); dists[SRC] = 0;
        while(pq.size()){
            int now = pq.top().second;
            int cst = -pq.top().first;
            pq.pop();
            if(dists[now] - cst) continue;
            for(auto i : graph[now]){
                if(i.c && dists[i.v] > dists[now] + i.dist){
                    dists[i.v] = dists[now] + i.dist;
                    pq.emplace(-dists[i.v], i.v);
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
                if(j.c && !chk[j.v]) minflow = min(minflow, dists[i] + j.dist - dists[j.v]);
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
        for(; work[now] < graph[now].size(); work[now]++){
            auto &i = graph[now][work[now]];
            if(!chk[i.v] && dists[i.v] == dists[now] + i.dist && i.c){
                int ret = dfs(i.v, min(flow, i.c));
                if(ret){
                    i.c -= ret; graph[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
	}
	pii run(int _s, int _t){ //{cost, flow} 반환
		init(_s, _t);
		int cst = 0, flow = 0;
		do{
			memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
			int now = 0;
			while(true){
				now = dfs(SRC, 1e9);
				if (now==0) break;
				cst += dists[SINK] * now;
				flow += now;
				memset(chk, 0, sizeof chk);
			}
		}while(update());
		return {cst, flow};
	}
} mcmf;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	const int SRC = 801, SINK = 802;

	int N, M; 
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		int cnt; 
		cin >> cnt;
		while(cnt--){
			int workNum, cost; 
			cin >> workNum >> cost;
			// 사람 => 일 (용량 1, 비용 cost)
			mcmf.addEdge(i, workNum+400, 1, cost);
		}
	}

	// source => 사람 (용량 1)
	for(int human=1; human<=N; human++) mcmf.addEdge(SRC, human, 1, 0);

	// 일 => Sink 
	for(int workNum=1; workNum<=M; workNum++) mcmf.addEdge(workNum+400, SINK, 1, 0);

	auto now = mcmf.run(SRC, SINK);
	cout << now.second << "\n" << now.first;
}