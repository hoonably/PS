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

N명의 직원, M개의 일이 주어지고,
각 직원이 할 수 있는 일의 번호가 주어졌을 때

최대 몇개의 일을 할 수 있는가?

풀이 방법
- 직원 1명당 DFS를 1번씩 돌린다.

*/

#define MAX 1001

int N, M;
vector<int> works[MAX];
bool visited[MAX];  // dfs 했는가?
int human[MAX];

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int work : works[cur]){
        // work에 대한 사람이 아직 없다면 그 일 배정
		if (human[work] == 0) {
			human[work] = cur;
			return true;
		} 
        // dfs 결과 그 사람이 다른곳으로 배정이 되었다면 배정
        if (dfs(human[work])){
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
    for (int i=1; i<=N; i++){
        int n;
        cin >> n;
        for (int j=0; j<n; j++){
            int work;
            cin >> work;
            works[i].push_back(work);
        }
    }

    cout << bipartite_match();
    
    return 0;
}