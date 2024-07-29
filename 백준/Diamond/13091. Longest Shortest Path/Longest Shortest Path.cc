#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;

/* -----------------------------------------------------


최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int vertexSZ = 200;  // in out 분할이라면 2배
const int SZ = vertexSZ+10, bias = vertexSZ/2;
const int SRC = vertexSZ+1, SINK = vertexSZ+2;

using CostType = double;  // Cost가 double type

struct edge {
    int id, from, to;
    double cap, cost;
    edge(int id, int from, int to, int cap, int cost)
    : id(id), from(from), to(to), cap(cap), cost(cost) {}
};

array<vector<int>, SZ> adj;
vector<edge> graph;

void addEdge(int now, int y, int d, int c) {
    static int id = -1;
    adj[now].emplace_back(++id);
    graph.emplace_back(id, now, y, c, d);
    adj[y].emplace_back(++id);
    graph.emplace_back(id, y, now, 0, -d);
}

array<int, SZ> pred;
bool inQ[SZ];
CostType dists[SZ]; //dijkstra
bool spfa(int SRC, int SINK) {
    // memset(dists, INF, sizeof(dists));  // int
    fill(dists, dists+SZ, INF);  // double (memset 불가능)
    memset(inQ, false, sizeof(inQ));
    queue<int> q;
    q.push(SRC);
    inQ[SRC] = true;
    dists[SRC] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inQ[now] = false;
        for (auto id: adj[now]) {
            auto& e = graph[id];
            if (e.cap > 1e-9 && dists[e.to] > dists[now] + e.cost + 1e-9) {
                dists[e.to] = dists[now] + e.cost;
                pred[e.to] = id;
                if (!inQ[e.to]) {
                    q.emplace(e.to);
                    inQ[e.to] = true;
                }
            }
        }
    }
    return dists[SINK] < INF;  // dists[SINK]가 갱신되었다면 true
}

int N, M, P, s, t;

double solve(){
    double F = 0, C = 0;
    double ans = INF;
    while (spfa(s, t)) {
        double dF = INF;
        for (int now = t; now != s; now = graph[pred[now]].from) {
            dF = min(dF, graph[pred[now]].cap);
        }
        for (int now = t; now != s; now = graph[pred[now]].from) {
            edge& e = graph[pred[now]];
            C += dF * e.cost;
            e.cap -= dF;
            graph[e.id^1].cap += dF;
        }
        F += dF;
        ans = min(ans, (C + P)/F);  // ans
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> P >> s >> t;
    for (int i=0; i<M; i++){
        int v, u, d, c;
        cin >> v >> u >> d >> c;
        addEdge(v, u, d, c);
    }

    double ans = solve();

    cout << fixed << setprecision(9) << ans;

    return 0;
}