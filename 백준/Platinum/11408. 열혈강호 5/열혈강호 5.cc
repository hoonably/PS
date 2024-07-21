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

#define MAX 

const int SZ = 810, SRC = 801, SINK = 802;

struct MCMF{
	int flow[SZ][SZ], capacity[SZ][SZ], cost[SZ][SZ];
	vector<int> parent[SZ];

	void add_edge(int from, int to, int cap, int c) {
		parent[from].emplace_back(to);
		parent[to].emplace_back(from);
		capacity[from][to] += cap;
		cost[from][to] = c;
        cost[to][from] = -c;
	}

	void init(){
		memset(flow, 0, sizeof(flow));
		memset(capacity, 0, sizeof(capacity));
		memset(cost, 0, sizeof(cost));
	}

    // SPFA를 사용한 MCMF
	pii getMCMF(){
		int retCost = 0, retFlow=0;
		vector<int> par(SZ), c(SZ);
        vector<bool> inQ(SZ);

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
}mcmf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

	// mcmf.init();

    for (int i=1; i<=N; i++) {
        int x;
		cin >> x;
        for (int j=0; j<x; j++) {
            int work, cost;
			cin >> work >> cost;
			// 사람 => 일 (용량 1, 비용 cost)
            mcmf.add_edge(i, work+N, 1, cost);
        }

		// source => 사람 (용량 1)
        mcmf.add_edge(SRC, i, 1, 0);
    }

    for (int iwork=1; iwork<=M; iwork++) {
		// 일 => Sink
		mcmf.add_edge(iwork+N, SINK, 1, 0);
	}

    pii ans = mcmf.getMCMF();
    cout << ans.second << '\n' << ans.first << '\n';
    
    return 0;
}