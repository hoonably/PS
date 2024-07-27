#include <bits/stdc++.h>
using namespace std;

/* -----------------------------------------------------
네트워크 플로우

디닉 알고리즘 O(V^2*E)

Max-Flow Min-Cut Theorem (최대 유량 최소컷 정리)

어떤 최대 흐름의 잔여 네트워크 위에서는 t가 s로부터 도달할 수 없습니다.
어떤 흐름 네트워크든 최대 흐름의 양은 항상 최소 절단의 용량과 항상 동일하다.
*/

const int INF = 0x7f7f7f7f;
const int SZ = 180010, SRC = 180001, SINK = 180002, bias = 90000;

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

int board[300][300];
int C, R, S, T;

int in(int i, int j){
    return C*i+j+1;
}
int out(int i, int j){
    return C*i+j+1+bias;
}

const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> R >> C;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> board[i][j];
        }
    }

    cin >> S >> T;
    nf.addEdge(SRC, in(S, T), INF);

    // B에서 시작하여 외부로 최대로 흐를 수 있는 유량 찾기
    // = 최소 컷
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            
            // 유량이 0이면 갈 필요 없음
            // if (board[i][j]==0) continue;

            // 자신 in -> out
            nf.addEdge(in(i, j), out(i, j), board[i][j]);

            // 테두리부분 : SINK와 연결
            if (i==0 || i==R-1 || j==0 || j==C-1){
                nf.addEdge(out(i, j), SINK, INF);
                continue;
            }

            // 상하좌우
            for (int t=0; t<4; t++){
                int ni = i + dx[t];
                int nj = j + dy[t];
                if (ni<0 || ni>=R || nj<0 || nj>=C) continue;
                // if (board[ni][nj]==0) continue;
                nf.addEdge(out(i, j), in(ni, nj), INF);
            }
        }
    }

    // 최대 40만
    cout << nf.maxFlow();  // 최대 유량 = 최소 컷 (총 병력 비용 합)
    
    return 0;
}