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
https://www.acmicpc.net/problem/16833

선형 계획법 문제
보석상 https://www.acmicpc.net/problem/1281 문제와 반대

생각하기 매우 어려움.

(a0+a1+a2+...+an) - (b0+b1+b2+...+bn) 이 최대가 되려면?

모든 ai-bj <= cij 만족하려면
ai-bj가 가장 작은 값부터 최대인 Cij가 되도록 매칭시키면 된다.

최대유량이 되려면 모두 매칭이 되어야함
최소비용인듯 하지만 어쩔 수 없이 모두 만족시키려면 최대한 작게 매칭시키면서 Cij로 매칭시켜야함.

모든 매칭에 성공한다면 그게 바로 ai-bj를 모두 만족하면서 최대일 때이다.
*/

const int SZ = 410, SRC = 401, SINK = 402;
const double eps = 1e-4;

struct MCMF{  // use Dinic

    using CostType = double;  // Cost가 double type

	struct Edge{ int to, cap; CostType cost; int rev; };
	vector<Edge> graph[SZ];
	void addEdge(int _from, int _to, int _cap, CostType _cost){
		graph[_from].push_back({_to, _cap, _cost, (int)graph[_to].size()});
		graph[_to].push_back({_from, 0, -_cost, (int)graph[_from].size()-1});
	}

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++)
			graph[i].clear();
	}

	bool inQ[SZ];
	CostType dists[SZ]; //dijkstra
    bool spfa() {
        // memset(dists, 1e9, sizeof(dists));  // int
        fill(dists, dists+SZ, 1e9);  // double (memset 불가능)
        memset(inQ, false, sizeof(inQ));
        queue<int> q;
        q.push(SRC);
        inQ[SRC] = true;
        dists[SRC] = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            inQ[now] = false;
            for (auto edge: graph[now]) {
                if (edge.cap && dists[edge.to] > dists[now] + edge.cost + eps) {
                    dists[edge.to] = dists[now] + edge.cost;
                    if (!inQ[edge.to]) inQ[edge.to] = true, q.push(edge.to);
                }
            }
        }
        return dists[SINK] < 1e9;  // dist[SINK]가 갱신되었다면 true
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

    pair<CostType, int> run() {
        CostType cost = 0;
        int flow = 0;
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

struct dot{int x, y;};
double getDist(dot a, dot b){
    int dx = a.x-b.x;
    int dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}

dot A[201];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    for (int i=1; i<=N; i++){
        int x, y;
        cin >> A[i].x >> A[i].y;
    }

    for (int i=1; i<=N; i++){
        mcmf.addEdge(SRC, i, 1, 0);
        mcmf.addEdge(i+200, SINK, 1, 0);
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i==j) continue;
            // 두 반지름의 합 <= d
            double d = getDist(A[i], A[j]);
            mcmf.addEdge(i, j+200, 1, d);
        }
    }

    cout << setprecision(9);
    cout << M_PI * mcmf.run().first;  // 2배 해주면 중복이라 안해줄거임

    return 0;
}