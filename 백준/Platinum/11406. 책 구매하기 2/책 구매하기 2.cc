#include <bits/stdc++.h>
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
네트워크 플로우

디닉 알고리즘 사용으로 빠르게 풀기 O(V^2*E)
단, cap에 현재 flow를 직접 저장하기 때문에, 실시간으로 바뀌어서
flow를 수정하면서 문제를 푸는 문제에서는 다 일일이 수정해줘야 해서 불편함
*/

const int SZ = 210, SRC = 201, SINK = 202;

struct NetworkFlow{  // use Dinic

	using FlowType = int;

	struct Edge{ int to, rev; FlowType cap; };
	vector<Edge> graph[SZ];
	int level[SZ], work[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int _from, int _to, FlowType _cap, FlowType _caprev = 0){
		graph[_from].push_back({_to, (int)graph[_to].size(), _cap});
		graph[_to].push_back({_from, (int)graph[_from].size()-1, -_caprev});
	}

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++) graph[i].clear();
	}

    bool BFS(int SRC, int SINK){
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(SRC); level[SRC] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(const auto &next : graph[now]){
                if(!level[next.to] && next.cap) q.push(next.to), level[next.to] = level[now] + 1;
            }
        }
        return level[SINK];
    }
    FlowType DFS(int now, int SINK, FlowType flow){
        if(now == SINK) return flow;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &next = graph[now][work[now]];
            if(level[next.to] != level[now] + 1 || !next.cap) continue;
            FlowType ret = DFS(next.to, SINK, min(flow, next.cap));
            if(!ret) continue;
            next.cap -= ret;
            graph[next.to][next.rev].cap += ret;
            return ret;
        }
        return 0;
    }
    FlowType maxFlow(int s = SRC, int t = SINK){
        FlowType ret = 0, minFlow;
        while(BFS(s, t)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(s, t, INF))) ret += minFlow;
        }
        return ret;
    }
} nf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        int a; cin >> a;
        nf.addEdge(SRC, i, a);
    }

    for(int i=1; i<=M; i++){
        int b; cin >> b;
        nf.addEdge(i+100, SINK, b);
    }

    for(int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            int c; cin >> c;
            nf.addEdge(j, i+100, c);
        }
    }
    cout << nf.maxFlow();
    
    return 0;
}