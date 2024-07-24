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
이분탐색을 이용해 maxFlow가 모든 숫자의 합일때
모든 flow(edge 연결값)의 최대값이 가장 작도록 하는 ans 탐색

이 문제는 간선 수가 많지 않아서 
포드 풀커슨 방법 사용하고 자유롭게 flow 변경
O((V+E)F)
*/

const int SZ = 110, SRC = 101, SINK = 102;

struct FordFulkerson{

	using FlowType = int;

	FlowType flow[SZ][SZ], capacity[SZ][SZ];
	vector<int> graph[SZ];
	int level[SZ], work[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int from, int to, int cap, int caprev = 0) {
		graph[from].emplace_back(to);
		graph[to].emplace_back(from);
		capacity[from][to] += cap;
		capacity[to][from] += caprev;
	}

    bool BFS(int SRC, int SINK){
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(SRC); level[SRC] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int &next : graph[now]){
                if(!level[next] && capacity[now][next]-flow[now][next]>0) {
					q.push(next), level[next] = level[now] + 1;
				}
            }
        }
        return level[SINK];
    }

    FlowType DFS(int now, int SINK, FlowType f){
        if(now == SINK) return f;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            int next = graph[now][work[now]];
            if(level[next] != level[now] + 1 || capacity[now][next]-flow[now][next]==0) continue;
            FlowType ret = DFS(next, SINK, min(f, capacity[now][next]-flow[now][next]));
            if(!ret) continue;
            flow[now][next]+=ret;
			flow[next][now]-=ret;
            return ret;
        }
        return 0;
    }

	FlowType maxFlow(int s = SRC, int t = SINK){
		memset(flow, 0, sizeof(flow));
        FlowType ret = 0, minFlow;
        while(BFS(s, t)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(s, t, INF))) ret += minFlow;
        }
        return ret;
    }

	// 이 문제는 독특하게 중간 연결 cap를 모두 Mid로 설정하고 
	// 이분탐색으로 찾기 때문에 capacity를 c로 변경시켜주는 함수
	void initCap(int N, int c){
		for (int i=1; i<=N; i++)
			for (int j=1; j<=N; j++)
				capacity[i][j+50]=c;
	}

	void printFlow(int N){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
				cout << flow[i][j+50] << ' ';
			}
			cout << '\n';
		}		
	}
}nf;

int sum;  // 총 숫자의 합

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
    cin >> N;

	// 가로합
	for(int i=1; i<=N; i++){
		int rowSum;
		cin >> rowSum;
		nf.addEdge(SRC, i, rowSum);
		sum+=rowSum;
	}
	// 세로합
	for(int i=1; i<=N; i++){
		int colSum;
		cin >> colSum;
		nf.addEdge(i+50, SINK, colSum);
	}

	// row => col 잇기
	for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            nf.addEdge(i,j+50,0);
		}
	}

	// 숫자판에 들어가는 최대 숫자의 값을 최소로 해야하므로
	// 최대로 흐를 수 있는 유량 중 최소값을 이분탐색으로 찾기
	int Left = 0, Right = 10000, Mid, ans;
	while(Left <= Right) {
		Mid = (Left + Right)/2;

		// 모든 사이 용량을 mid로 맞춰줌
		nf.initCap(N, Mid);

		if(nf.maxFlow() == sum) {
			ans = Mid;
			Right = Mid-1;
			// 최소값을 찾아야하므로 마치지 않고 더 진행
		}

		else Left = Mid+1;
	}

	cout << ans << '\n';

    nf.initCap(N, ans);  // ans 였을 때로 cap 맞춰주기
	nf.maxFlow();
	nf.printFlow(N);
    
    return 0;
}