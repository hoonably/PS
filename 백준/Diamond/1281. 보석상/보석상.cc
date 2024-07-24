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
https://www.acmicpc.net/problem/1281

선형 계획법 문제

생각하기 매우 어려움.

(a0+a1+a2+...+an) - (b0+b1+b2+...+bn) 이 최대가 되려면?

모든 ai-bj <= cij 만족하려면
ai-bj가 가장 작은 값부터 최대인 Cij가 되도록 매칭시키면 된다.

최대유량이 되려면 모두 매칭이 되어야함
최소비용인듯 하지만 어쩔 수 없이 모두 만족시키려면 최대한 작게 매칭시키면서 Cij로 매칭시켜야함.

모든 매칭에 성공한다면 그게 바로 ai-bj를 모두 만족하면서 최대일 때이다.
*/

const int SZ = 520, SRC = 513, SINK = 514;

struct MCMF{  // use Dinic
	struct Edge{ int to, cap, cost, rev; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, int _cap, int _cost){
		graph[_from].push_back({_to, _cap, _cost, (int)graph[_to].size()});
		graph[_to].push_back({_from, 0, -_cost, (int)graph[_from].size()-1});
	}

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++) graph[i].clear();
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
            int now = q.front(); q.pop();
            inQ[now] = false;
            for (auto i: graph[now]) {
                if (i.cap && dists[i.to] > dists[now] + i.cost) {
                    dists[i.to] = dists[now] + i.cost;
                    if (!inQ[i.to]) inQ[i.to] = true, q.push(i.to);
                }
            }
        }
        return dists[SINK] < 0x3f3f3f3f;  // dist[SINK]가 갱신되었다면 true
    }

	bool chk[SZ];
	int work[SZ];
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

    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            int C;
            cin >> C;
            mcmf.addEdge(i, j+256, 1, -C);
        }
    }

    for (int i=1; i<=N; i++){
        mcmf.addEdge(SRC, i, 1, 0);
    }

    for (int i=1; i<=M; i++){
        mcmf.addEdge(i+256, SINK, 1, 0);
    }

    cout << -mcmf.run().first;

    return 0;
}