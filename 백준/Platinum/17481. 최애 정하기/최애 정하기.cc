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
https://www.acmicpc.net/problem/11375
이분 매칭
*/

#define MAX 1001

int N, M;
map<string, int> idx;
vector<int> works[MAX];
bool visited[MAX];  // dfs 했는가?
int human[MAX];

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int work : works[cur]){
        // work에 대한 사람이 아직 없다면 그 일 매칭
        // dfs 결과 그 사람이 다른곳으로 배정이 되었다면 매칭완료
		if (human[work] == 0 || dfs(human[work])) {
			human[work] = cur;
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

    // 멤버의 숫자를 맵으로 저장
    for (int i=1; i<=M; i++){
        string name;
        cin >> name;
        idx[name] = i;
    }

    for (int i=1; i<=N; i++){
        int n;
        cin >> n;
        for (int j=0; j<n; j++){
            string name;
            cin >> name;
            works[i].push_back(idx[name]);
        }
    }

    int ans = bipartite_match();
    if (ans==N) cout << "YES";
    else cout << "NO\n" << ans;
    
    return 0;
}