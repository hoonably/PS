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
https://www.acmicpc.net/submit/1298
이분 매칭

*/

#define MAX 101

int N, M;
vector<int> notebook[MAX];
bool visited[MAX];  // dfs 했는가?
int human[MAX];

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int nb : notebook[cur]){
        // work에 대한 사람이 아직 없다면 그 일 매칭
        // dfs 결과 그 사람이 다른곳으로 배정이 되었다면 매칭완료
		if (human[nb] == 0 || dfs(human[nb])) {
			human[nb] = cur;
			return true;
		}
    }
    return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ret++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        notebook[a].push_back(b);
    }

    cout << bipartite_match();
    
    return 0;
}