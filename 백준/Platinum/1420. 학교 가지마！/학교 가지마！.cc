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
https://www.acmicpc.net/problem/1420

기존의 그래프에서 in과 out으로 정점을 분할한다.
in -> out 가중치를 1로 설정 (사용된 정점은 더 이상 지나갈 수 없으므로, 더 이상 증가 경로에 포함되지 않는다.)
out -> in 가중치를 1로 설정

그래프가 방대해 디닉 알고리즘 사용
*/

const int SZ = 20010, SRC = 20001, SINK = 20002;

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
            for(const auto &i : graph[now]){
                if(!level[i.to] && i.cap) q.push(i.to), level[i.to] = level[now] + 1;
            }
        }
        return level[SINK];
    }
    FlowType DFS(int now, int SINK, FlowType flow){
        if(now == SINK) return flow;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &i = graph[now][work[now]];
            if(level[i.to] != level[now] + 1 || !i.cap) continue;
            FlowType ret = DFS(i.to, SINK, min(flow, i.cap));
            if(!ret) continue;
            i.cap -= ret;
            graph[i.to][i.rev].cap += ret;
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

char board[100][100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    for (int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> board[i][j];
		}
    }

	int src=0, sink=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]=='#') continue;

			// Source와 sink 정함
            if(board[i][j]=='K')  src = 2*(i*100+j)+1;
            if(board[i][j]=='H')  sink = 2*(i*100+j);
            
			// 자기자신 in -> out
            nf.addEdge(2*(i*100+j), 2*(i*100+j)+1, 1);
            
			// 아래쪽으로 갈 수 있다면
            if(i<N-1 && board[i+1][j]!='#'){
                nf.addEdge(2*(i*100+j)+1, 2*((i+1)*100+j), INF);
                nf.addEdge(2*((i+1)*100+j)+1, 2*(i*100+j), INF);
            }
			// 위쪽으로 갈 수 있다면
            if(j<M-1 && board[i][j+1]!='#'){
                nf.addEdge(2*(i*100+j)+1, 2*(i*100+j+1), INF);
                nf.addEdge(2*(i*100+j+1)+1, 2*(i*100+j), INF);
            }
        }
    }

	int ans = nf.maxFlow(src, sink);

	// 4개로도 못막는다면 둘이 붙어있다는거임
	if (ans>4) cout << "-1";  // 둘이 붙어있는 경우임
	else cout << ans;
    
    return 0;
}