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
https://www.acmicpc.net/problem/11495

https://everenew.tistory.com/182

간선의 양이 많아
디닉 알고리즘 사용시 56ms
포드 풀커슨 사용시 5600ms
*/

#define MAX 

const int SZ = 2510, SRC = 2501, SINK = 2502;

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

void solve(){

	nf.initGraph();

    int n, m;
    cin >> n >> m;

    int totalSum = 0;
    bool isRed = true;
    int order = 1;  // 노드 번호
    int change_order[4]= {m, -m, 1, -1};  // 번호변경

    for (int r=0; r<n; r++){
        for (int c=0; c<m; c++){
            int cap;
            cin >> cap;
            totalSum+=cap;

			// Blue : Sink 연결
            if ((r + c) % 2) {
				nf.addEdge(order, SINK, cap);
			}

            // red : Source 연결
            // 상하좌우 Blue와 연결
        	else {
                nf.addEdge(SRC, order, cap);
                for(int i=0; i<4 ; ++i){
                    int nr = r + dx[i];
                    int nc = c + dy[i]; 

                    //범위 확인
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    
                    int blue_order = order + change_order[i];
                    nf.addEdge(order, blue_order, INF);
                }
            }
            order++;
        }
    }

    cout << totalSum - nf.maxFlow() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}