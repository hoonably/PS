#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;

/* -----------------------------------------------------
네트워크 플로우

디닉 알고리즘 O(V^2*E)

Edge 구조체 사용으로 매우 빠름

단, cap에 현재 flow를 직접 저장하기 때문에, 실시간으로 바뀌어서
flow를 수정하면서 문제를 푸는 문제에서는 일일이 수정해줘야 해서 불편
*/

const int vertexSZ = 50;  // in out 분할이라면 2배
const int SZ = vertexSZ+5, bias = vertexSZ/2;
int SRC = 0, SINK = vertexSZ+1;

struct NetworkFlow{  // use Dinic

	using FlowType = int;

	struct Edge{ int to, rev; FlowType cap; };
	vector<Edge> graph[SZ];
	int level[SZ], work[SZ];

	// 마지막 인자를 안쓰면 유방향, cap과 같게 쓰면 무방향(양쪽 cap 같음)
	void addEdge(int _from, int _to, FlowType _cap, FlowType _caprev = 0){
		graph[_from].push_back({_to, (int)graph[_to].size(), _cap});
		graph[_to].push_back({_from, (int)graph[_from].size()-1, _caprev});
	}

	void initGraph(){ // for Test Case
		for (int i=0; i<SZ; i++) graph[i].clear();
	}

    bool BFS(int S, int T){  // make level graph
        memset(level, 0, sizeof(level));
        queue<int> q; q.push(S); level[S] = 1;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(const auto &next : graph[now]){
                if(!level[next.to] && next.cap) q.push(next.to), level[next.to] = level[now] + 1;
            }
        }
        return level[T];
    }
    FlowType DFS(int now, int T, FlowType flow){  // find Blocking Flow
        if(now == T) return flow;
		for(; work[now] < (int)graph[now].size(); work[now]++){
            auto &next = graph[now][work[now]];
            if(level[next.to] != level[now] + 1 || !next.cap) continue;
            FlowType ret = DFS(next.to, T, min(flow, next.cap));
            if(!ret) continue;
            next.cap -= ret;
            graph[next.to][next.rev].cap += ret;
            return ret;
        }
        return 0;
    }
    FlowType maxFlow(int S = SRC, int T = SINK){
        FlowType ret = 0, minFlow;
        while(BFS(S, T)){
            memset(work, 0, sizeof(work));
            while((minFlow = DFS(S, T, INF))) ret += minFlow;
        }
        return ret;
    }
} nf;

int N, K;
bool A[SZ][SZ]; // 협력관계
bool guard[SZ][SZ];  // guard[i][j] : i 도시에 j 경비업체가 이미 있음
bool office[SZ][SZ];  //  office[i][j] : i도시에 j 경비업체 사무실이 있음

// SRC -> 가드가 있는 나라
// 경비업체가있는 나라 -> SINK
void makeNetwork(int cur) {
    int from, to;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(A[i][j]) { // 협력한다면

                if(guard[i][cur]) from = SRC; else if(!office[i][cur]) from = SINK; else from = i;
                if(guard[j][cur]) to = SRC; else if(!office[j][cur]) to = SINK;  else to = j;

                if (from == to) continue;

                // swap하기 편하도록 SRC = 0, SINK = 51 설정
                if (from > to) swap(from, to);
                // cout << from << ' ' << to << '\n';

                if (from == SRC) nf.addEdge(SRC, to, 1);  // SRC와 연결 : 단방향
                else if (to == SINK) nf.addEdge(from, SINK, 1);  // SINK와 연결 : 단방향
                else nf.addEdge(from, to, 1, 1); // 양방향
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    cin >> N;

    // 협력관계 받기
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            char temp; cin >> temp;
            if(temp == '1') {
                A[i][j] = true;
            }
        }
    }

    cin >> K;  // 떡국에 존재하는 경비업체 수

    // 각 도시에 이미 있는 경비업체의 번호
    for(int i = 1; i <= N; i++) {
        int num; cin >> num;
        while(num--) {
            int x; cin >> x;
            guard[i][x] = true;
        }
    }

    // 각 도시에 있는 경비업체 사무실을 가진 경비업체의 번호
    for(int i = 1; i <= N; i++) {
        int num; cin >> num;
        while(num--) {
            int x; cin >> x;
            office[i][x] = true;
        }
    }

    int result = 0;

    // 경비업체별 최대 뽑기
    for(int i = 0; i < K; i++) {
        nf.initGraph();
        makeNetwork(i);
        result += nf.maxFlow();
    }
  
    cout << result;
    
    return 0;
}