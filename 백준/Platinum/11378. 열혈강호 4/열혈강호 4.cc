#include <bits/stdc++.h>
#define FOR(now,a,b) for(int now=(a);now<(b);now++)
#define all(v) v.begin(), v.e()
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
https://www.acmicpc.net/problem/11378
네트워크 플로우

지난달에 벌점을 X점 받은 사람은 일을 최대 X+1개까지 할 수 있다.
각 직원은 자신이 지난달에 받은 벌점을 알지 못하고, 

벌점 총 합 K개를 적절히 분배해서 일을 최대 얼마나 할 수 있는지 구하기

https://kibbomi.tistory.com/46
위 블로그에 설명이 자세히 나와있다.

용량이 K(벌점총합)인 bridge를 사용

*/

#define MAX 



class FordFulkerson{
	private:
		vector<vector<int>> flow, capacity, adjList;
		int s, e, N; //source, sink, verties
	public:
		FordFulkerson(){ N = 0, s = -1, e = -1; }

		FordFulkerson(int N){
			this->N = N;
			flow.resize(N+1), capacity.resize(N+1), adjList.resize(N+1);
			for(int i=0; i<=N; i++){
				flow[i].resize(N+1);
				capacity[i].resize(N+1);
			}
			s = -1, e = -1;
		}

        // source와 sink가 있는 경우
		FordFulkerson(int N, int source, int sink){
			this->N = N;
			flow.resize(N+1), capacity.resize(N+1), adjList.resize(N+1);
			for(int i=0; i<=N; i++){
				flow[i].resize(N+1);
				capacity[i].resize(N+1);
			}
			s = source, e = sink;
		}

		void setSource(int t){ s = t; }
		void setSink(int t){ e = t; }
		void addEdge(int start, int end, int cap, bool directed){
			adjList[start].push_back(end);
			adjList[end].push_back(start);
			capacity[start][end] += cap;
			if(!directed) capacity[end][start] += cap;
		}

		int maxFlow(){
            int ret = 0;
			// if(s==-1 || e==-1) return -1;  // 오류 방지
			vector<int> par(N+1);

			while(true){
				fill(par.begin(), par.end(), -1);

				queue<int> q;
                q.push(s);
				while(!q.empty()){
					int now = q.front(); q.pop();
					for(auto nxt : adjList[now]){
						if(par[nxt] == -1 && capacity[now][nxt]-flow[now][nxt] > 0){
							q.push(nxt); par[nxt] = now;
							if(nxt == e) break;
						}
					}
				}

                // 종료
				if(par[e] == -1) break;

                // 거꾸로 최소 유량 탐색
				int minFlow = INF;
				for(int i=e; i!=s; i = par[i]){
					int a = par[i], b = i;
					minFlow = min(minFlow, capacity[a][b] - flow[a][b]);
				}
				ret += minFlow;

                // 최소 유량 처리
				for(int i=e; i!=s; i = par[i]){
					flow[par[i]][i] += minFlow; 
                    flow[i][par[i]] -= minFlow;
				}
			}
			return ret;
		}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M, K;
	cin >> N >> M >> K;
	int s = 2001, e = 2003, bridge = 2002;
	FordFulkerson flow(2003, s, e);

    // 사람 => 일 연결
	for(int i=1; i<=N; i++){

		flow.addEdge(s, i, 1, 1);
		flow.addEdge(bridge, i, K, 1);

		int cnt; 
        cin >> cnt;
		while(cnt--){
			int t;
            cin >> t;
            // i번 사람이 t번 일을 할 수 있음
            flow.addEdge(i, 1000+t, 1, 1);
		}
	}
	flow.addEdge(s, bridge, K, 1);

    // 일 => 종료 연결
	for(int work=1; work<=M; work++) {
        flow.addEdge(1000+work, e, 1, 1);
    }

	cout << flow.maxFlow();
    
    return 0;
}