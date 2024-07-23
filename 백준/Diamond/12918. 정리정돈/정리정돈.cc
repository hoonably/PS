#include <bits/stdc++.h>
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
https://www.acmicpc.net/problem/12918

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 210, SRC = 201, SINK = 202;

struct MCMF{  // use Dinic

    using CostType = double;  // 이 문제에서는 Cost가 double임

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
        // 0x3f = 0x3f3f3f3f = 106,119,567
        // memset(dists, 0x3f, sizeof(dists));  // int
        fill(dists, dists+SZ, 1e9);  // double (memset 불가능)
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

#define x first
#define y second

pii A[201];

double getDist(pii a, pii b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
    cin >> N;

    for (int i=1; i<=N; i++){
        int a, b;
        cin >> a >> b;
        A[i] = {a, b};
        A[i+100] = {-a, b};
    }

    // i번째 점의 선대칭 지점 : i+100으로 표현

    // 각 물건을 y축에 선대칭시켜서 새로운 물건을 하나씩 만들어준 뒤, 
    // x좌표가 음수인 물건을 Li, x좌표가 양수인 물건을 Ri라고 합시다.
    // Li와 Rj를 간선으로 이어주고 가중치를 (두 점 사이의 거리 / 2)로 설정

    // 조심할 포인트
    // 물건을 선 위로 이동시켜도 선대칭임.
    // 하지만, 어차피 하나를 선 위로 이동시키면 다른 하나도 선 위로 이동시켜야 하므로
    // 가중치를 (두 점 사이의 거리 / 2)로 설정하면 따로 처리를 안해줘도 됨.

    for(int i=1; i<=N; i++){
        mcmf.addEdge(SRC, i, 1, 0);
        mcmf.addEdge(i+100, SINK, 1, 0);
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            double dist = getDist(A[i], A[j+100]);
            mcmf.addEdge(i, j+100, 1, dist / 2);
        }
    }

    cout << fixed << setprecision(3);
    cout << mcmf.run().first;

    return 0;
}