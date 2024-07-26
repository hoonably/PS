#include <bits/stdc++.h>
using namespace std;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/14286
Max-Flow Min-Cut Theorem (최대 유량 최소컷 정리)

어떤 최대 흐름의 잔여 네트워크 위에서는 t가 s로부터 도달할 수 없습니다.
어떤 흐름 네트워크든 최대 흐름의 양은 항상 최소 절단의 용량과 항상 동일하다.
*/

const int INF = 0x7f7f7f7f;
const int SZ = 510, SRC = 501, SINK = 502;

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
} nf;

int n, m, a, b, c, s, t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        nf.addEdge(a, b, c, c);
    }

    cin >> s >> t;
    cout << nf.maxFlow(s, t);
    
    return 0;
}