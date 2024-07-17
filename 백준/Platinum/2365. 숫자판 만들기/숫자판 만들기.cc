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
https://www.acmicpc.net/problem/2365
row의 합을 왼쪽 노드로, col의 합을 오른쪽 노드로 분리
*/

#define MAX

struct FordFulkerson{
	vector<vector<int>> flow, capacity, parent;
	int SRC, SINK, N; //source, sink, verties

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
		fill(flow.begin(), flow.end(), vector<int> (N+10,0));
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

int row[51], col[51];
int rowSum, colSum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
    cin >> N;

	FordFulkerson ff(100, 101, 102);

	// 가로합
	for(int i=1; i<=N; i++){
		cin >> row[i];
		ff.add_edge_from_source(i, row[i]);
		rowSum+=row[i];
	}
	// 세로합
	for(int i=1; i<=N; i++){
		cin >> col[i];
		ff.add_edge_to_sink(i+50, col[i]);
		colSum+=col[i];
	}

	// row => col 잇기
	for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ff.add_edge(i,j+50,0);
		}
	}

	int Left = 0, Right = 10000, Mid, Ans;
	while(Left <= Right) {
		Mid = (Left + Right)/2;

		// flow를 모두 0으로 초기화
		ff.init();

		// 모든 사이 용량을 mid로 맞춰줌
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++) {
				ff.capacity[i][j+50] = Mid;
			}
		}

		if(ff.maxFlow() == rowSum) {
			Ans = Mid;
			Right = Mid-1;
		}

		else Left = Mid+1;
	}

	cout << Ans << '\n';


    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) ff.capacity[i][j+50] = Ans;

	ff.init();
	ff.maxFlow();
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) cout << ff.flow[i][j+50] << ' ';
        cout << '\n';
    }


	
    
    return 0;
}