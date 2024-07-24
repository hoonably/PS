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
	int Level[SZ], Work[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int _from, int _to, int _cap, int _caprev = 0){
		graph[_from].push_back({_to, (int)graph[_to].size(), _cap});
		graph[_to].push_back({_from, (int)graph[_from].size()-1, -_caprev});
	}

	void initGraph(){ // 테스트케이스를 위한 그래프 초기화
		for (int i=0; i<SZ; i++) graph[i].clear();
	}

    bool BFS(int S, int T){
        memset(Level, 0, sizeof Level);
        queue<int> Q; Q.push(S); Level[S] = 1;
        while(Q.size()){
            int now = Q.front(); Q.pop();
            for(const auto &i : graph[now]){
                if(!Level[i.to] && i.cap) Q.push(i.to), Level[i.to] = Level[now] + 1;
            }
        }
        return Level[T];
    }
    FlowType DFS(int now, int T, FlowType tot){
        if(now == T) return tot;
        for(int &_i=Work[now]; _i<graph[now].size(); _i++){
            Edge &i = graph[now][_i];
            if(Level[i.to] != Level[now] + 1 || !i.cap) continue;
            FlowType fl = DFS(i.to, T, min(tot, i.cap));
            if(!fl) continue;
            i.cap -= fl;
            graph[i.to][i.rev].cap += fl;
            return fl;
        }
        return 0;
    }
    FlowType maxFlow(int S, int T){
        FlowType ret = 0, tmp;
        while(BFS(S, T)){
            memset(Work, 0, sizeof Work);
            while((tmp = DFS(S, T, INF))) ret += tmp;
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