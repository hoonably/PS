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
https://www.acmicpc.net/problem/13161

w[i,j] = 서로 다른 진영일 때 슬픔의 정도

E = 25,000개 F는 최대 500,000만이라 O(EF), O(VE^2) 둘다 택도 없음
그래서 O(V^2E)인 디닉알고리즘을 써야만 시간내에 해결이 가능
*/

const int SZ = 510, SRC = 501, SINK = 502;

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
    
    int N;
    cin >> N;

    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        if (num==1){  // 무조건 A 진영
			nf.addEdge(SRC, i, INF);
        }
        else if (num==2){  // 무조건 B 진영
			nf.addEdge(i, SINK, INF);
        }
    }

	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			int cap;
			cin >> cap;
			if (cap==0) continue;
			nf.addEdge(i, j, cap);
		}
	}

	cout << nf.maxFlow() << '\n';
	
	// A진영
	for (int i=1; i<=N; i++){
		if (nf.level[i] != 0) cout << i << ' ';
	}
	cout << '\n';

	// B진영
	for (int i=1; i<=N; i++){
		if (nf.level[i] == 0) cout << i << ' ';
	}
	cout << '\n';
    
    return 0;
}