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
https://www.acmicpc.net/problem/11111

최소 비용 최대 유량 (MCMF) 문제.

벨만 포드를 사용하면 시간복잡도가 느림. 이를 해결하기 위해 SPFA 사용

SPFA : 바뀐 정점은 큐를 이용해서 관리하고, 큐에 해당 정점이 있는지 없는지는 배열을 이용해서 체크
시간 복잡도는 O(V*E)이지만 실제로는 훨씬 빨리 돌아가는 알고리즘으로 O(V+E) 혹은 O(E)라고 해도 무방
*/

const int SZ = 2510, SRC = 2501, SINK = 2502;

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

int prices[6][6] = {
//   A   B  C  D     F
    {10, 8, 7, 5, 0, 1},  // A
    {8, 6, 4, 3, 0, 1},  // B
    {7, 4, 3, 2, 0, 1},  // C
    {5, 3, 2, 2, 0, 1},  // D
    {0, 0, 0, 0, 0, 0},  // (없음)
    {1, 1, 1, 1, 0, 0}  // F
};
int graph[50][50];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, M;
	cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            char c;
            cin >> c;
            graph[i][j] = c-'A';  // 가격 배열에 접근하기 편하도록 숫자로 저장
        }
    }

    int nowOrder = 0;  // 노드 번호
    int changeOrder[4]= {M, -M, 1, -1};  // 번호변경

    for (int r=0; r<N; r++){
        for (int c=0; c<M; c++){
            nowOrder++;
            
            // 홀수번째칸은 SINK와만 연결
            if ((r + c) % 2) {
                mcmf.addEdge(nowOrder, SINK, 1, 0);
                continue;
            }

            mcmf.addEdge(SRC, nowOrder, 1, 0);
            mcmf.addEdge(nowOrder, SINK, 1, 0);

            // 자신의 아래와 오른쪽과 합쳤을때 효과
            int now = graph[r][c];

            for(int i=0; i<4; ++i){
                int nr = r + dx[i];
                int nc = c + dy[i]; 
                //범위 확인
                if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                
                int nextOrder = nowOrder + changeOrder[i];
                int next = graph[nr][nc];

                // 최대비용을 위해서 음수로 넣어줌
                mcmf.addEdge(nowOrder, nextOrder, 1, -prices[now][next]);
            }
        }
    }

	cout << -mcmf.run().first;  // 최대비용
}