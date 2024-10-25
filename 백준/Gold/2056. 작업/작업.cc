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
https://www.acmicpc.net/problem/2252
위상정렬
: 방향이 있는 그래프의 꼭짓점들을 나열
*/

#define MAX 32001

int N;
int t[MAX];
int inDegree[MAX];  // 진입차수 (자신으로 오는 노드의 개수)
vector<int> graph[MAX];  // graph[i] = {i 뒤에 오는 것들}

int dp[MAX];
// 이번에는 돌면서 dp 사용
void topology_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i); // 진입차수가 0인 노드 push
	}
	for (int rep = 0; rep < N; rep++) {
		if (q.empty()) return;

		int now = q.front();
		q.pop();

		for (int next : graph[now]) {
			dp[next] = max(dp[next],dp[now]+t[next]);
			inDegree[next]--;
			if (inDegree[next] == 0)
				q.push(next);
		}
	}
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> t[i] >> inDegree[i];
        for(int j=0; j<inDegree[i]; j++){
            int before;
            cin >> before;
            graph[before].push_back(i);
        }
    }
	for(int i=1; i<=N; i++){
		dp[i] = t[i];
	}

    topology_sort();
	int ans = 0;
	for(int i=1; i<=N; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans;

    return 0;
}