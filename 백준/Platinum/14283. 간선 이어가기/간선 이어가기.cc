#include <bits/stdc++.h>
using namespace std;

/* -----------------------------------------------------
네트워크 플로우

디닉 알고리즘 O(V^2*E)

Edge 구조체 사용으로 매우 빠름

단, cap에 현재 flow를 직접 저장하기 때문에, 실시간으로 바뀌어서
flow를 수정하면서 문제를 푸는 문제에서는 일일이 수정해줘야 해서 불편
*/

const int INF = 0x7f7f7f7f;
const int SZ = 1010;
int SRC, SINK;
int N, M, Sum, S[1010], E[1010], X[1010];

struct NetworkFlow{  // use Dinic

	using FlowType = int;

	struct Edge{ int to, rev; FlowType cap; };
	vector<Edge> graph[SZ];
	int level[SZ], work[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int _from, int _to, FlowType _cap, FlowType _caprev = 0){
		graph[_from].push_back({_to, (int)graph[_to].size(), _cap});
		graph[_to].push_back({_from, (int)graph[_from].size()-1, _caprev});
	}

	void initGraph(){ // for Test Case
		for (int i=0; i<SZ; i++) graph[i].clear();
	}

    bool BFS(int S, int T){  // make level graph
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(S); level[S] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(const auto &next : graph[now]){
                if(!level[next.to] && next.cap) q.push(next.to), level[next.to] = level[now] + 1;
            }
        }
        return level[T];
    }
    FlowType DFS(int now, int T, FlowType flow){  // find Blocking Flow
        if(now == T) return flow;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &next = graph[now][work[now]];
            if(level[next.to] != level[now] + 1 || !next.cap) continue;
            FlowType ret = DFS(next.to, T, min(flow, next.cap));
            if(!ret) continue;
            next.cap -= ret;
            graph[next.to][next.rev].cap += ret;
            return ret;
        }
        return 0;
    }
    FlowType maxFlow(int S = SRC, int T = SINK){
        FlowType ret = 0, minFlow;
        while(BFS(S, T)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(S, T, INF))) ret += minFlow;
        }
        return ret;
    }
    
    // 이 문제에서 Solve 
    FlowType Solve(int del){

        // 최소 컷 구하기
        FlowType minCut = maxFlow();
        
        // for(int i=1; i<=N; i++){
        //     cout << (bool)level[i] << ' ';
        // }cout << '\n';

        // 지운 간선의 시작과 끝이 같은 컴포넌트라면 의미 없는 간선임
        if((bool)level[S[del]] == (bool)level[E[del]]) return -1;
        return Sum - minCut;
    }
} nf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> S[i] >> E[i] >> X[i];
        Sum += X[i];
    }
    cin >> SRC >> SINK;

    int ans = 0;
    for (int del=1; del<=M; del++){
        nf.initGraph();
        for (int j=1; j<=M; j++){
            if (del==j) continue;  // 지울 간선을 제외하고 NetworkFlow
            nf.addEdge(S[j], E[j], X[j], X[j]);
        }
        // cout << nf.maxFlow();
        ans = max(ans, nf.Solve(del));
    }
    cout << ans;
    
    return 0;
}