#include <bits/stdc++.h>
#define FOR(i,workNum,cost) for(int i=(workNum);i<(cost);i++)
#define all(to) to.begin(), to.end()
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
https://www.acmicpc.net/problem/15504
최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 610, SRC = 601, SINK = 602;

struct MCMF{
	int flow[SZ][SZ], capacity[SZ][SZ], cost[SZ][SZ];
	vector<int> parent[SZ];

	void addEdge(int from, int to, int cap, int c) {
		parent[from].emplace_back(to);
		parent[to].emplace_back(from);
		capacity[from][to] += cap;
		cost[from][to] = c;
        cost[to][from] = -c;
	}

	// Test Case용 init
	void init(){
		memset(flow, 0, sizeof(flow));
		memset(capacity, 0, sizeof(capacity));
		memset(cost, 0, sizeof(cost));
		for(int i=0; i<SZ; i++) parent[i].clear();
	}

    // SPFA를 사용한 MCMF
	pii run(){
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

tiii P[301];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;

    // 실력 받기
    for (int i=1; i<=N; i++) cin >> get<0>(P[i]);
    // 피로도 받기
    for (int i=1; i<=N; i++) cin >> get<1>(P[i]);
    // 최대 경기 수 받기
    for (int i=1; i<=N; i++) cin >> get<2>(P[i]);

    // 실력이 낮은 순으로 정렬
    sort(P+1, P+N+1);

    for (int i=1; i<=N-1; i++) mcmf.addEdge(SRC, i, 1, 0);

    // 그래프 생성 j가 i를 이김
    for (int i=1; i<=N-1; i++){
        for (int j=i+1; j<=N; j++){
                int fun = (get<0>(P[i])^get<0>(P[j])) - (get<1>(P[i])+get<1>(P[j]));
                mcmf.addEdge(i, j+300, 1, -fun);
        }
    }

    // out=>sink 횟수 결정 (여기가 어려움)
    for (int i=1; i<=N; i++){
        if (i==N) mcmf.addEdge(i+300, SINK, get<2>(P[i]), 0);  // 모두 이길 수 있는 애
        // 나머지는 무조건 한게임은 지므로 게임 할 수 있는 횟수보다 1 빼기
        else mcmf.addEdge(i+300, SINK, get<2>(P[i])-1, 0);
    }

	pii ans = mcmf.run();
	cout << -ans.first;
}