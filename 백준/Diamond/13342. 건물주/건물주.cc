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
https://www.acmicpc.net/problem/13342

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(SZ*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(SZ+E) 혹은 O(E)라고 해도 무방
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
        return dists[SINK] < 1e9;
    }

	bool chk[SZ];
	int work[SZ];
	bool update(){
		int minflow = 1e9;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : graph[i]){
                if(j.cap && !chk[j.to])
					minflow = min(minflow, dists[i] + j.cost - dists[j.to]);
            }
        }
		if(minflow >= 1e9) return 0;
		for(int i=0; i<SZ; i++){
			if(!chk[i]) dists[i] += minflow;
		}
        return 1;
	}

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

int Car[50], A[51];
int dist[50][50];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, C, M, W, D;
	cin >> N >> C >> M >> W >> D;

	// 차가 주차되어있는 구역
	for (int i = 0; i < C; ++i) {
		cin >> Car[i];
	}

	// 월세를 받아야 하는 도시넘버 (순서대로)
	// A[0]은 0으로 고정
	for (int i = 1; i <= M; ++i) {
		cin >> A[i];
	}

	// 도시 간 도로 정보
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> dist[i][j];
			if (dist[i][j]==0 && i!=j) dist[i][j] = 1e9;  // 본인이 아닌데 0이면 못가는거
		}
	}

	// 플로이드 워셜 각 도시 최단거리 갱신
	for (int k=0; k<N; k++)
		for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	// SRC => 도시 연결
	for (int i = 0; i < M; ++i) {
		mcmf.addEdge(SRC, i, 1, 0);
	}

	// M개의 방문도시에서 차를 타는 경우
	for(int i=0; i<M; i++) {
		mcmf.addEdge(i, SINK, 1, dist[A[i]][A[i+1]] * W);
		for(int j=0; j<C; j++) {
			mcmf.addEdge(i, j+50, 1, dist[A[i]][Car[j]] * W + dist[Car[j]][A[i+1]] * D);
		}
	}

	// 차고 => Sink 연결
	for (int j = 0; j < C; ++j) {
		mcmf.addEdge(j+50, SINK, 1, 0);
	}

	ll ans = mcmf.run().first;

	cout << ans << "\n";
}