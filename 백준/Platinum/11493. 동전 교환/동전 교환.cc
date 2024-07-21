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
https://www.acmicpc.net/problem/11493

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용
SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크

동전의 교환을 cap로 생각하자.
이 문제에서는 흰색을 흰색으로 모두 옮기면 자동으로 검정색은 검정색에 옮겨져있기 때문에,
흰색 정점이 있는 곳을 SRC와 연결하고 흰색 동전이 있는 곳을 SINK로 연결해서 나오는 MCMF
*/

const int SZ = 1010;
struct MCMF{
	int SRC, SINK; //source, sink
	struct Edge{ int to, cap, cost, rev; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, int _cap, int _cost){
		graph[_from].push_back({_to, _cap, _cost, (int)graph[_to].size()});
		graph[_to].push_back({_from, 0, -_cost, (int)graph[_from].size()-1});
	}

	void initGraph(){
		// 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<=SZ; i++)
			graph[i].clear();
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
		// memset(inQ, 0, sizeof(inQ));

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
        for(; work[now] < graph[now].size(); work[now]++){
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
	pii run(int _s, int _t){ //{최소비용, 최대유량} 반환
		init(_s, _t);
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

void solve(){

	mcmf.initGraph();

	const int SRC = 1001, SINK = 1002;

    int N, M;
    cin >> N >> M;

    // 간선 받기
    for (int i=1; i<=M; i++) {
        int x, y;
        cin >> x >> y;
		mcmf.addEdge(x, y, INF, 1);
		mcmf.addEdge(y, x, INF, 1);
    }

    // 정점의 색 받기
    for (int i=1; i<=N; i++){
        int color;
        cin >> color;

		// 흰색인 경우 Source와 연결
		if (color==1){
			mcmf.addEdge(SRC, i, 1, 0);
		}
    }

    // 동전의 색 받기
    for (int i=1; i<=N; i++){
        int color;
        cin >> color;
		// 흰색인 경우 Sink와 연결
		if (color==1){
			mcmf.addEdge(i, SINK, 1, 0);
		}
    }

    pii ans = mcmf.run(SRC, SINK);
    cout << ans.first << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}