#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;

/* -----------------------------------------------------


최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int sz = 2000;  // in out 분할이라면 2배
const int SZ = sz+10, bias = sz/2;
const int SRC = sz+1, SINK = sz+2;

struct MCMF{  // use Dinic

    using CostType = int;
    using FlowType = int;
    // const CostType EPS = 1e-6;  // if cost is double type
    const CostType EPS = 0;

	struct Edge{ int to, rev; FlowType cap; CostType cost; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, FlowType _cap, CostType _cost){
		graph[_from].push_back({_to, (int)graph[_to].size(), _cap, _cost, });
		graph[_to].push_back({_from, (int)graph[_from].size()-1, 0, -_cost});
	}

	bool inQ[SZ];
	CostType costs[SZ]; //dijkstra
    bool spfa(int S, int T) {
        fill(costs, costs+SZ, 1e9);
        memset(inQ, false, sizeof(inQ));
        queue<int> q;
        q.push(S);
        inQ[S] = true;
        costs[S] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            inQ[now] = false;
            for (auto edge: graph[now]) {
                if (edge.cap && costs[edge.to] > costs[now] + edge.cost + EPS) {
                    costs[edge.to] = costs[now] + edge.cost;
                    if (!inQ[edge.to]) inQ[edge.to] = true, q.push(edge.to);
                }
            }
        }
        return costs[T] < 1e9;  // costs[T]가 갱신되었다면 true
    }
	bool chk[SZ];
	int work[SZ];
	FlowType dfs(int now, int T, FlowType flow){
        chk[now] = true;
        if(now == T) return flow;
        for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &nxt = graph[now][work[now]];
            if(!chk[nxt.to] && costs[nxt.to] == costs[now] + nxt.cost && nxt.cap){
                FlowType ret = dfs(nxt.to, T, min(flow, nxt.cap));
                if(ret){
                    nxt.cap -= ret; graph[nxt.to][nxt.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
	}
    pair<CostType, FlowType> run(int S = SRC, int T = SINK) {
        CostType cost = 0;
        FlowType flow = 0;
        while (spfa(S, T)) {
            memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
            FlowType now = 0;
            while (true) {
				now = dfs(S, T, 1e9);
				if (now==0) break;
                cost += costs[T] * now;
                flow += now;
                memset(chk, 0, sizeof chk);
            }
        }
        return {cost, flow};
    }

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++)
			graph[i].clear();
	}
} mcmf;

int N, M;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    // for(int i=1; i<=N; i++){
    //     mcmf.addEdge(i, i+bias, 2, 0);
    // }

    for(int i=0; i<M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        mcmf.addEdge(B, A, 1, C);
        mcmf.addEdge(A, B, 1, C);
    }

    mcmf.addEdge(SRC, 1, 2, 0);
    mcmf.addEdge(N, SINK, 2, 0);

    cout << mcmf.run().first;

    return 0;
}