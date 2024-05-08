#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 1'000'001

int N, M, K;
int ramen[MAX];
int parent[MAX];
vector<pii> graph[MAX];

int getFirstCon(int num) {
    // 짜장라면이 남아있다면
	if (ramen[num]) return num;
    // 짜장라면이 안남아있다면
	return parent[num] = getFirstCon(parent[num]);
}

void dijkstra(int start){

    vector<int> dist(N + 1, INF);  // INF로 선언과 동시에 초기화
    priority_queue<pii> pq;  // 우선순위 큐 선언

    dist[start] = 0;
    parent[1] = 0;  // 이거때매 틀렸었음
    
    pq.push({0, start});  // 우선순위 큐에 넣기 (힙큐이므로 순서 중요!!)

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[cur_node]) continue;

        for (auto& edge : graph[cur_node]) {
            int nxt_node = edge.first;
            int nxt_dist = edge.second + cur_dist;
            
            if (nxt_dist < dist[nxt_node]) {  // 유망하면
                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});

                parent[nxt_node] = cur_node;  // 분리 집합
            }

            // 만약 거리가 같을때
            // 바로 다음의 편의점 규모가 더 큰 길로 가야함
			else if (nxt_dist == dist[nxt_node] && parent[nxt_node] < cur_node) {
				parent[nxt_node] = cur_node;  // 분리 집합
			}
        }
    }

    // 이 문제에서는 최단거리를 리턴할 필요가 없음
    // 그냥 parent 관계만 필요
    // return dist;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    memset(parent, -1, sizeof(parent));

	cin >> N >> M >> K;

    // 짜장라면 개수 받기
	for (int i=1; i<=N; i++)
		cin >> ramen[i];

    // 간선 받기
	for (int i=0; i<M; i++) {
		int u, v, c;
		cin >> u >> v >> c;  // u->v 거리 c
		graph[u].emplace_back(v, c);
		graph[v].emplace_back(u, c);
	}

    // 다익스트라
    dijkstra(1);

    // 
	ramen[0] = 1;

	for (int i=0; i<K; i++) {
		int s;
		cin >> s;

        // 경로가 없음
        if (parent[s] == -1){
            cout << "-1\n";
            continue;
        }

		else {
			int sel = getFirstCon(s);

            // 경로상의 편의점 모두 재고 없음
			if (sel == 0) {
				cout << "-1\n";
            }

            // 짜장라면 하나 가져감
			else {
				ramen[sel]--;
                cout << sel << '\n';
            }
		}
	}
}