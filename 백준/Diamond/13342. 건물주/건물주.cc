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
https://www.acmicpc.net/problem/13342

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(SZ*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(SZ+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 110, SRC = 101, SINK = 102;

class MCMF {
public:
	using edge = tuple<int, ll, ll, ll>;
	MCMF(int SZ) : G(SZ), d(SZ), last(SZ), vst(SZ) { }
	void addEdge(int u, int v, ll w, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, w, 0, c});
		G[v].push_back(E.size());
		E.push_back({u, 0, 0, -c});
		if (!d) {
			addEdge(v, u, w, c);
		}
	}
	pair<ll, ll> run(int s, int t) {
		ll mf{}, mcost{};
		while (spfa(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
				mcost = min(mcost, tcost);
			}
		}
		return {mcost, mf};
	}
private:
	bool spfa(int s, int t) {
		fill(d.begin(), d.end(), INF);
		queue<int> q;
		d[s] = 0, vst[s] = true;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			vst[u] = false;
			for (int idx : G[u]) {
				auto &[v, cap, flow, cost] = E[idx];
				if (d[v] > d[u] + cost && flow < cap) {
					d[v] = d[u] + cost;
					if (!vst[v]) {
						vst[v] = true;
						q.push(v);
					}
				}
			}
		}
		return d[t] < INF;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		vst[u] = true;
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow, cost] = E[G[u][i]];
			if (!vst[v] && d[v] == d[u] + cost && flow < cap) {
				if (ll pushed = dfs(v, t, min(f, cap - flow))) {
					tcost += pushed * cost;
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					vst[u] = false;
					return pushed;
				}
			}
		}
		vst[u] = false;
		return 0;
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<ll> d;
	vector<int> last;
	deque<bool> vst;
	ll tcost{};
}mcmf(SZ);

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

	// SRC => 차고 연결
	for (int i = 0; i < C; ++i) {
		mcmf.addEdge(SRC, i, 1, 0);
	}

	// C개의 차고에서 M개의 방문도시 잇기
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < M; ++j) {
			// 나중에 걸어가는 거리 더해줄거라 빼줌
			int cost = W * dist[A[j]][Car[i]] + D * dist[Car[i]][A[j + 1]] - W * dist[A[j]][A[j + 1]];
			mcmf.addEdge(i, j+50, 1, cost);
		}
	}

	// 방문도시 => Sink 연결
	for (int j = 0; j < M; ++j) {
		mcmf.addEdge(j+50, SINK, 1, 0);
	}

	ll ans = mcmf.run(SRC, SINK).first;

	// 0 => A[1] => A[2] => A[M-1] 기본적으로 걸어가는 거리
	for (int j = 0; j < M; ++j) {
		ans += W * dist[A[j]][A[j + 1]];
	}
	cout << ans << "\n";
}