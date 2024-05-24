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

#define MAX 

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

struct MaximumFlow
{
	struct Edge
	{
		int from, to, cap, rev;
		Edge(int from, int to, int cap) : from(from), to(to), cap(cap) {};
	};
	vector<vector<Edge>> graph;
	vector<int> work, level;
	int N, src, sink;

	// 생성자
	MaximumFlow(int N, int src, int sink) : N(N), src(src), sink(sink) {
		graph.resize(N);
		work.resize(N);
		level.resize(N);
	}


	void add_edge(int from, int to, int cap) {
		graph[from].emplace_back(from, to, cap);
		graph[to].emplace_back(to, from, cap);
		graph[from].back().rev = graph[to].size() - 1;
		graph[to].back().rev = graph[from].size() - 1;
	}
	
    void add_diedge(int from, int to, int cap) {
		graph[from].emplace_back(from, to, cap);
		graph[to].emplace_back(to, from, 0);
		graph[from].back().rev = graph[to].size() - 1;
		graph[to].back().rev = graph[from].size() - 1;
	}
	void add_edge_from_source(int to, int cap) {
		add_edge(src, to, cap);
	}
	void add_edge_to_sink(int from, int cap) {
		add_edge(from, sink, cap);
	}
	int dfs(int c, int minFlow = INT_MAX) {
		if (c == sink) {
			return minFlow;
		}
		int flow;
		for (int &i = work[c]; i < graph[c].size(); i++) {
			auto &e = graph[c][i];
			if (e.cap > 0 && level[e.to] == level[e.from] + 1 && (flow = dfs(e.to, min(e.cap, minFlow)))) {
				e.cap -= flow;
				graph[e.to][e.rev].cap += flow;
				return flow;
			}
		}
		return 0;
	}
	int flow() {
		int ret = 0;
		queue<int> q;
		while(true) {
			int flow = 0;
			fill(level.begin(), level.end(), -1);
			q.push(src);
			level[src] = 0;
			while (!q.empty()) {
				int c = q.front();
				q.pop();
				for (auto &e : graph[c]) {
					if (e.cap > 0 && level[e.to] == -1) {
						level[e.to] = level[e.from] + 1;
						q.push(e.to);
					}
				}
			}
			fill(work.begin(), work.end(), 0);
			while (int temp = dfs(src)) {
				flow += temp;
			}
			if (flow == 0) {
				break;
			}
			ret += flow;
		}
		return ret;
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // 집 점, 구멍 수용 인원, 구멍, 쥐
    int n, k, h, m;
    cin >> n >> k >> h >> m;

    // 최대 유량 (구멍 0~49, 쥐: 50~299, src: 301, sink: 302)
    MaximumFlow mf(303, 301, 302);

    // 집 모서리 점 좌표 받기
    vector<pll> walls(n);
    for(int i=0; i<n; i++){
        cin >> walls[i].x >> walls[i].y;
    }

    // 구멍 좌표 받기
    vector<pll> holes(h);
    for(int i=0; i<h; i++){
        cin >> holes[i].x >> holes[i].y;
    }

    // 쥐 좌표 받기
    vector<pll> mouses(m);
    for(int i=0; i<m; i++){
        cin >> mouses[i].x >> mouses[i].y;
    }

	for(int i=0; i<h; i++){
        // source => 구멍 (용량 k)
        mf.add_edge_from_source(i, k);
    }

    for(int i=0; i<m; i++){
        // 쥐 => sink (용량 1)
        mf.add_edge_to_sink(50 + i, 1);
    }



	for (int i=0; i<h; i++){
		pll hole = holes[i];

		for(int j=0; j<m; j++){
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
                mf.add_diedge(i, 50 + j, 1);
            }
        }
    }

    // 최대 유량이 m이 되었다면 가능
	if (mf.flow() >= m) cout << "Possible";
    else cout << "Impossible";
    
    return 0;
}