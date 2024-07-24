#include <bits/stdc++.h>
#define FOR(now,a,b) for(int now=(a);now<(b);now++)
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
https://www.acmicpc.net/problem/17412
네트워크 플로우

디닉 알고리즘 사용으로 빠르게 풀기
 O(V^2*E)
*/

#define MAX

const int SZ = 410, SRC = 401, SINK = 402;

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
    FlowType maxFlow(int SRC, int SINK){
        FlowType ret = 0, tmp;
        while(BFS(SRC, SINK)){
            memset(work, 0, sizeof(work));
            while((tmp = DFS(SRC, SINK, INF))) ret += tmp;
        }
        return ret;
    }
} nf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N, P;
    cin >> N >> P;

    for(int i=0; i<P; i++){
        int a, b;
        cin >> a >> b;
		nf.addEdge(a, b, 1);
    }

    cout << nf.maxFlow(1, 2);
    
    return 0;
}