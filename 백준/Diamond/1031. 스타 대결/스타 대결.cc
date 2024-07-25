#include <bits/stdc++.h>
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
네트워크 플로우
https://www.acmicpc.net/problem/1031

포드 풀커슨 알고리즘
O((V+E)F)

flow와 cap을 따로 관리하기 때문에 디닉보다 느리지만,
나중에 개별 flow를 출력해야한다면 용이
*/

const int SZ = 110, SRC = 101, SINK = 102, bias = 50;

struct EdmondsKarp{

	using FlowType = int;

	FlowType flow[SZ][SZ], capacity[SZ][SZ];
	vector<int> parent[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int from, int to, int cap, int caprev = 0) {
		parent[from].emplace_back(to);
		parent[to].emplace_back(from);
		capacity[from][to] += cap;
		capacity[to][from] += caprev;
	}

	int par[SZ];
	bool BFS(int S, int T){
		memset(par, -1, sizeof(par));
		queue<int> q; q.push(S);
		while(!q.empty()){  //
			int now = q.front(); q.pop();
			for(auto nxt : parent[now]){
				if(par[nxt] == -1 && capacity[now][nxt]-flow[now][nxt] > 0){
					q.push(nxt); par[nxt] = now;
					if(nxt == T) break;
				}
			}
		}
		return par[T] != -1;
	}
	FlowType maxFlow(int S = SRC, int T = SINK){
		memset(flow, 0, sizeof(flow));
		FlowType ret = 0;
		while(BFS(S, T)){
			// 거꾸로 최소 유량 탐색
			FlowType minFlow = INF;
			for(int i=T; i!=S; i = par[i]){
				minFlow = min(minFlow, capacity[par[i]][i] - flow[par[i]][i]);
			}
			ret += minFlow;

			// 최소 유량 처리
			for(int i=T; i!=S; i = par[i]){
				flow[par[i]][i] += minFlow; 
				flow[i][par[i]] -= minFlow;
			}
		}
		return ret;
	}

    // Flow가 Sink로 흐른다면 Sink로부터 돌아오면서 Flow 모두 바꿔주기
    void changeFlow(int S, int T){
		memset(par, -1, sizeof(par));
		queue<int> q; q.push(S);
		while(!q.empty()){  //
			int now = q.front(); q.pop();
			for(auto nxt : parent[now]){
                // 기존 BFS에서 추가해준 뒷번호 노드만 보기
                if(now < S || (now == S && nxt < T)) continue;
				if(par[nxt] == -1 && capacity[now][nxt]-flow[now][nxt] > 0){
					q.push(nxt); par[nxt] = now;
					if(nxt == T) break;
				}
			}
		}
		if (par[T] == -1) return;  // 변경할 필요 없음

        flow[S][T] = flow[T][S] = 0;
        for(int i=T; i!=S; i = par[i]){
            flow[par[i]][i]++; 
            flow[i][par[i]]--;
        }
    }

	// Flow를 출력
	void printFlow(int N, int M){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				cout << flow[i][j+bias];
			}
			cout << '\n';
		}		
	}
}nf;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
	cin >> N >> M;

    int Asum = 0, Bsum = 0;

    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        nf.addEdge(SRC, i, num);
        Asum += num;
    }

    for(int i=1; i<=M; i++){
        int num;
        cin >> num;
        nf.addEdge(i+bias, SINK, num);
        Bsum += num;
    }

    // 역순으로 넣어주기
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            nf.addEdge(i, j+bias, 1);
        }
    }

    // cout << nf.maxFlow() << '\n';
    if (Asum!=Bsum || nf.maxFlow()!=Asum){
        cout << -1;
        return 0;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if (nf.flow[i][j+bias]) nf.changeFlow(i,j+bias);
        }
    }
    nf.printFlow(N, M);
    
    return 0;
}