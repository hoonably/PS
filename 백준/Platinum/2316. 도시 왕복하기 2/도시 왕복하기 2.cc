#include <bits/stdc++.h>
#define FOR(now,a,b) for(int now=(a);now<(b);now++)
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
https://www.acmicpc.net/problem/2316
네트워크 플로우

기존의 그래프에서 in과 out으로 정점을 분할한다.
in -> out 가중치를 1로 설정 (사용된 정점은 더 이상 지나갈 수 없으므로, 더 이상 증가 경로에 포함되지 않는다.)
out -> in 가중치를 1로 설정
*/

const int SZ = 810, SRC = 801, SINK = 802;

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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, P;
    cin >> N >> P;

	// out은 400 더하기

	// 각자 자신의 수 in => out 간선 1로 생성
	for(int i=1; i<=N; i++){
		nf.addEdge(i, i+400, 1);
	}

	// 도로 out -> in 양방향
    for(int i=0; i<P; i++){
        int a, b;
        cin >> a >> b;
		nf.addEdge(a+400, b, 1);
		nf.addEdge(b+400, a, 1);
    }

	// 1->2 이므로 401->2 임
	// source out = 401 / sink in = 2
    cout << nf.maxFlow(401, 2);
    
    return 0;
}