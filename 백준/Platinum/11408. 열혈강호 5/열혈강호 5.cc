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
https://www.acmicpc.net/problem/11408

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 888;
struct MCMF{
	int s, t; //source, sink
	struct Edge{ int v, c, d, dual; };
	vector<Edge> g[SZ];
	void addEdge(int s, int e, int c, int d){
		g[s].push_back({e, c, d, (int)g[e].size()});
		g[e].push_back({s, 0, -d, (int)g[s].size()-1});
	}

	int h[SZ], inq[SZ]; //johnson's algorithm, spfa
	int dst[SZ]; //dijkstra
	void init(int _s, int _t){
		s = _s, t = _t;
        memset(h, 0x3f, sizeof h);
        memset(dst, 0x3f, sizeof dst);

		//johnson's algorithm with spfa
        queue<int> q; q.push(s); inq[s] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop(); inq[now] = 0;
            for(auto i : g[now]){
                if(i.c && h[i.v] > h[now] + i.d){
                    h[i.v] = h[now] + i.d;
                    if(!inq[i.v]) inq[i.v] = 1, q.push(i.v);
                }
            }
        }
        for(int i=0; i<SZ; i++){
            for(auto &j : g[i]) if(j.c) j.d += h[i] - h[j.v];
        }

		//get shortest path DAG with dijkstra
        priority_queue<pii> pq; pq.emplace(0, s); dst[s] = 0;
        while(pq.size()){
            int now = pq.top().second;
            int cst = -pq.top().first;
            pq.pop();
            if(dst[now] - cst) continue;
            for(auto i : g[now]){
                if(i.c && dst[i.v] > dst[now] + i.d){
                    dst[i.v] = dst[now] + i.d;
                    pq.emplace(-dst[i.v], i.v);
                }
            }
        }
        for(int i=0; i<SZ; i++) dst[i] += h[t] - h[s];
	}

	int chk[SZ], work[SZ];
	bool update(){
		// SPFA : Shortest Path Faster Algorithm
		// Bellman-Ford로 업데이트 : O(VE)
		// SPFA로 사용시 O(V+E)
		int mn = 1e9;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : g[i]){
                if(j.c && !chk[j.v]) mn = min(mn, dst[i] + j.d - dst[j.v]);
            }
        }
		if(mn >= 1e9) return 0;
		for(int i=0; i<SZ; i++){
			if(!chk[i]) dst[i] += mn;
		}
        return 1;
	}

	int dfs(int now, int fl){
        chk[now] = 1;
        if(now == t) return fl;
        for(; work[now] < g[now].size(); work[now]++){
            auto &i = g[now][work[now]];
            if(!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c){
                int ret = dfs(i.v, min(fl, i.c));
                if(ret){
                    i.c -= ret; g[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
	}
	pii run(int _s, int _t){ //{cost, flow} 반환
		init(_s, _t);
		int cst = 0, fl = 0;
		do{
			memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
			int now = 0;
			while(true){
				now = dfs(s, 1e9);
				if (now==0) break;
				cst += dst[t] * now;
				fl += now;
				memset(chk, 0, sizeof chk);
			}
		}while(update());
		return {cst, fl};
	}
} mcmf;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		int cnt; cin >> cnt;
		while(cnt--){
			int a, b; cin >> a >> b;
			mcmf.addEdge(i, a+400, 1, b);
		}
	}
	const int s = 881, t = 882;
	for(int i=1; i<=n; i++) mcmf.addEdge(s, i, 1, 0);
	for(int j=1; j<=m; j++) mcmf.addEdge(j+400, t, 1, 0);

	auto now = mcmf.run(s, t);
	cout << now.second << "\n" << now.first;
}