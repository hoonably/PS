#include <bits/stdc++.h>
#define FOR(i,X,Y) for(int i=(X);i<(Y);i++)
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
https://www.acmicpc.net/problem/2252
위상정렬
: 방향이 있는 그래프의 꼭짓점들을 나열
*/

#define MAX 1001

int N, K, W;
int D[MAX];  // 건설에 걸리는 시간
int resultD[MAX];  // 건설하는데 최소 시간
int inDegree[MAX];  // 진입차수 (자신으로 오는 노드의 개수)
vector<int> graph[MAX];

void topology_sort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i); // 진입차수가 0인 노드 push
	}

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (int next : graph[now]) {
            resultD[next] = max(resultD[next], resultD[now]+D[next]);
			inDegree[next]--;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
}

void solve(){

    memset(D, 0, sizeof(D));
    memset(resultD, 0, sizeof(resultD));
    memset(inDegree, 0, sizeof(inDegree));
    for (int i=0; i<MAX; i++) graph[i].clear();

    cin >> N >> K;

    // 건설에 걸리는 시간
    for (int i=1; i<=N; i++){
        cin >> D[i];
    }

    for (int i=0; i<K; i++){
        int X, Y;
        cin >> X >> Y;
		// X가 Y 앞에 선다
        graph[X].push_back(Y);
        inDegree[Y]++;  // 진입차수
    }

    cin >> W;  // 건설해야할 건물의 번호

    // 바로 건설 가능하다면
    if (inDegree[W]==0) {
        cout << D[W] << '\n';
        return;
    }

    copy(D, D+N+1, resultD);

    topology_sort();

    cout << resultD[W] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}