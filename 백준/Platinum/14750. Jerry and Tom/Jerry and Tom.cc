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
https://www.acmicpc.net/problem/14750
쥐와 점을 이은 선분이 벽 선분과 교차하지 않는다면 graph 생성

그 이후는 네트워크 플로우
*/

const int SZ = 310, SRC = 301, SINK = 302;

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

#define x first
#define y second

int ccw(pll p1, pll p2, pll p3) {
    ll s = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    s -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
    if (s > 0) return 1;  // 반시계방향
    else if (s == 0) return 0;  //직선
    else return -1;  // 시계방향
}

bool isOverlapped(pll A, pll B, pll C, pll D) {
    int ans1 = ccw(A, B, C) * ccw(A, B, D); // 선분AB를 기준으로 점 C, 점 D 를 체크하는 부분
    int ans2 = ccw(C, D, A) * ccw(C, D, B); // 선분CD를 기준으로 점 A, 점 B 를 체크하는 부분
    
    // 1. 선분이 일직선인 경우
    if(ans1 == 0 && ans2 == 0){     
        if(B <= A) swap(A, B);  // A, B 정렬
        if(D <= C) swap(D, C);  // C, D 정렬
        
        return A <= D && C <= B;  // 순위가 겹치면 true
    }

    // 2. 한 점에서 교차 (CCW가 방향이 모두 다름)
    if(ans1 <= 0 && ans2 <= 0){
        return true;
    }
    // 3. 교차 안함
    else return false;  //CCW가 같은 방향이 있음
}

pll walls[1000], holes[51], mouses[251];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // 집 점, 구멍 수용 인원, 구멍, 쥐
    int n, k, h, m;
    cin >> n >> k >> h >> m;

    // 최대 유량 (구멍 1~50, 쥐: 51~300, SRC: 301, SINK: 302)

    // 집 모서리 점 좌표 받기
    for(int i=0; i<n; i++){
        cin >> walls[i].x >> walls[i].y;
    }

    // 구멍 좌표 받기
    for(int i=1; i<=h; i++){
        cin >> holes[i].x >> holes[i].y;
    }

    // 쥐 좌표 받기
    for(int i=1; i<=m; i++){
        cin >> mouses[i].x >> mouses[i].y;
    }

	for(int i=1; i<=h; i++){
        // source => 구멍 (용량 k)
        nf.addEdge(SRC, i, k);
    }

    for(int i=1; i<=m; i++){
        // 쥐 => SINK (용량 1)
        nf.addEdge(50 + i, SINK, 1);
    }



	for (int i=1; i<=h; i++){
		pll hole = holes[i];

		for(int j=1; j<=m; j++){
			pll mouse = mouses[j];

            int overlap = 0;
			int maximum = 1;  // 일단 벽 하나랑은 무조건 만남
            for(int p=0; p<n; p++){
				// 계속 틀렸던 이유 : 점이 벽의 끝에 있다면 두개의 선분과 만나는 것이 됨
				if (walls[p]==hole) maximum = 2;

                // 쥐-구멍 선분과 집 모서리가 교차?
                if (isOverlapped(walls[p], walls[(p+1)%n], mouse, hole)){
                    overlap++;
					if (overlap > maximum) break;
                }
            }

            // 나머지 아무것도 교차 안한다면 graph에 추가
            if (overlap<=maximum){
                // i번 구멍 => j번 쥐
                nf.addEdge(i, 50 + j, 1);
            }
        }
    }

    // 최대 유량이 m이 되었다면 가능
	if (nf.maxFlow() == m) cout << "Possible";
    else cout << "Impossible";
    
    return 0;
}