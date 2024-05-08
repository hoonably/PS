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
https://www.acmicpc.net/problem/1867

돌멩이를 몇번의 직선으로 갔을 때 주울 수 있는가?

쾨닉의 정리(Kőnig's theorem)
이분그래프에서 최대 매칭 = 최소 정점 커버

결국 최대 매칭을 시키면 된다. 열혈강호 문제랑 같은 문제

https://cocoon1787.tistory.com/819
*/

#define MAX 10'001

int n, k;
vector<int> grid[501];
bool visited[501];
int match[501];

bool dfs(int row){
    if (visited[row]) return false;
    visited[row] = true;

    for(int columm : grid[row]){
        // 매칭이 되어있지 않거나
        // 해당 column과 매칭되어있는 다른 row가 매칭되었을 때
		if (match[columm] == 0 || dfs(match[columm])) {
			match[columm] = row;
			return true;
		}
    }

    return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=1; i<=n; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) ret++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i=1; i<=k; i++){
        int x, y;
        cin >> x >> y;
        grid[x].push_back(y);
    }

    cout << bipartite_match();
    
    return 0;
}