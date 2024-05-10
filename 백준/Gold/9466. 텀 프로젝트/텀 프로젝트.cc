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
방문과 따로 사이클이 완료된 것을 처리해줘야한다.
틀렸었음. 생각보다 까다로움
*/

#define MAX 100'001

int n;
int graph[MAX];
int visited[MAX];  // 방문
bool done[MAX];  // 사이클 체크 완료

int cnt;  // 사이클이 되는 사람 카운트

void hasCycle(int node) {

	visited[node] = true;
	int next = graph[node];

	
	if (!visited[next]) {
		hasCycle(next);
	}

    // 방문하지 않았는데 done이라면 사이클 완성
	else if (!done[next]) {
		// 자기 자신을 포함한 팀의 멤버를 카운트
        while(next!=node){
            cnt++;
            next = graph[next];
        }
		cnt++;
	}
	done[node] = true;
}

void solve(){

    // init
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    memset(done, 0, sizeof(done));

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> graph[i];
    }

    for (int i=1; i<=n; i++){
        if (!visited[i]){
            hasCycle(i);
        }
    }

    cout << n-cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}