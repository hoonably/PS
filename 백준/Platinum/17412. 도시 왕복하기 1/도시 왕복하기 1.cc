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
https://www.acmicpc.net/problem/17412
네트워크 플로우
에드몬드 카프 알고리즘
시간 복잡도 : O(VE^2)


*/

#define MAX 401

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

        // source와 sink가 주어진 경우
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

        // edge 만들기
		void addEdge(int start, int end, int cap, bool directed){
			adjList[start].push_back(end);
			adjList[end].push_back(start);
			capacity[start][end] += cap;
			if(!directed) capacity[end][start] += cap;  // 무방향 그래프
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
	
	int N, P;
    cin >> N >> P;

	FordFulkerson ff(N, 1, 2);

    for(int i=0; i<P; i++){
        int a, b;
        cin >> a >> b;
		ff.addEdge(a, b, 1, 1);
    }

    cout << ff.maxFlow();
    
    return 0;
}