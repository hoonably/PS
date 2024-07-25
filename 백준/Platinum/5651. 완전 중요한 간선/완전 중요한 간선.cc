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

const int SZ = 310, SRC = 301, SINK = 302;

struct FordFulkerson{

	using FlowType = int;

	FlowType flow[SZ][SZ], capacity[SZ][SZ];
	vector<int> graph[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int from, int to, int cap, int caprev = 0) {
		graph[from].emplace_back(to);
		graph[to].emplace_back(from);
		capacity[from][to] += cap;
		capacity[to][from] += caprev;
    }

	int level[SZ], work[SZ];
    bool BFS(int S, int T){
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(S); level[S] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int &next : graph[now]){
                if(!level[next] && capacity[now][next]-flow[now][next]>0) {
					q.push(next), level[next] = level[now] + 1;
				}
            }
        }
        return level[T];
    }
    FlowType DFS(int now, int T, FlowType f){
        if(now == T) return f;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            int next = graph[now][work[now]];
            if(level[next] != level[now] + 1 || capacity[now][next]-flow[now][next]==0) continue;
            FlowType ret = DFS(next, T, min(f, capacity[now][next]-flow[now][next]));
            if(!ret) continue;
            flow[now][next]+=ret;
			flow[next][now]-=ret;
            return ret;
        }
        return 0;
    }
	FlowType maxFlow(int S = SRC, int T = SINK){
		memset(flow, 0, sizeof(flow));
        FlowType ret = 0, minFlow;
        while(BFS(S, T)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(S, T, INF))) ret += minFlow;
        }
        return ret;
    }

    void init(){  // for Test Case
		memset(capacity, 0, sizeof(capacity));
        for(int i=0; i<SZ; i++) graph[i].clear();
	}
}nf;

pii edges[5000];  // from, to 기록해놨다가 나중에 사용

void solve(){

    nf.init();

    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int f, t, b;
        cin >> f >> t >> b;
        nf.addEdge(f, t, b);
        edges[i] = {f, t};
    }

    nf.maxFlow(1, N);

    // 완전 중요한 간선인지 확인
    int ans = 0;
    for (int i = 0; i < M; i++) {
        auto [S, T] = edges[i];
        if (nf.capacity[S][T]==0 || nf.capacity[S][T] - nf.flow[S][T] != 0) continue;
        // S=>T로 도달하지 못한다면 완전 중요한 간선
        if (!nf.BFS(S, T)) ans++;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}