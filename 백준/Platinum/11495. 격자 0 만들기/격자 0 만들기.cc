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

*/

#define MAX 

struct FordFulkerson{
	vector<vector<int>> flow, capacity, parent;
	int SRC, SINK, N; //source, sink, verties(+10)

	// 생성자 (SRC, BRIDGE, SINK 위해서 10개 여분)
	FordFulkerson(int N, int source, int sink) : N(N+10), SRC(source), SINK(sink) {
		flow.resize(N+10), capacity.resize(N+10), parent.resize(N+10);
		for(int i=0; i<N+10; i++){
			flow[i].resize(N+10);
			capacity[i].resize(N+10);
		}
	}
	void setSource(int t){ SRC = t; }
	void setSink(int t){ SINK = t; }

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void add_edge(int from, int to, int cap, int caprev = 0) {
		parent[from].emplace_back(to);
		parent[to].emplace_back(from);
		capacity[from][to] += cap;
		capacity[to][from] += caprev;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(SRC, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, SINK, cap);
	}

	// flow 초기화
	void init(){
		fill(flow.begin(), flow.end(), vector<int> (N,0));
	}

	int maxFlow(){
		int ret = 0;
		vector<int> par(N+1);

		while(true){
			fill(par.begin(), par.end(), -1);

			queue<int> q;
			q.push(SRC);
			while(!q.empty()){
				int now = q.front(); q.pop();
				for(auto nxt : parent[now]){
					if(par[nxt] == -1 && capacity[now][nxt]-flow[now][nxt] > 0){
						q.push(nxt); par[nxt] = now;
						if(nxt == SINK) break;
					}
				}
			}

			// 종료
			if(par[SINK] == -1) break;

			// 거꾸로 최소 유량 탐색
			int minFlow = INF;
			for(int i=SINK; i!=SRC; i = par[i]){
				minFlow = min(minFlow, capacity[par[i]][i] - flow[par[i]][i]);
			}
			ret += minFlow;

			// 최소 유량 처리
			for(int i=SINK; i!=SRC; i = par[i]){
				flow[par[i]][i] += minFlow; 
				flow[i][par[i]] -= minFlow;
			}
		}
		return ret;
	}
};

void solve(){
    int n, m;
    cin >> n >> m;

    FordFulkerson ff(2500, 2501, 2502);

    int totalSum = 0;
    bool isRed = true;
    int order = 1;  // 노드 번호
    int change_order[4]= {m, -m, 1, -1};  // 번호변경

    for (int r=0; r<n; r++){
        for (int c=0; c<m; c++){
            int cap;
            cin >> cap;
            totalSum+=cap;

            // red : Source 연결
            // 상하좌우 Blue와 연결
            if (isRed){
                ff.add_edge_from_source(order, cap);
                for(int i=0; i<4 ; ++i){
                    int nr = r + dx[i];
                    int nc = c + dy[i]; 

                    //범위 확인
                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    
                    int blue_order = order + change_order[i];
                    ff.add_edge(order, blue_order, INF);
                }
            }
            // Blue : Sink 연결
            else {
                ff.add_edge_to_sink(order, cap);
            }

            order++;
            isRed^=1;
        }
        // 열이 짝수면 다시 색변경
        if (m%2==0) isRed^=1;
    }

    cout << totalSum - ff.maxFlow() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}