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
https://www.acmicpc.net/problem/14433
이분 매칭

*/

#define MAX 301

int N, M;
vector<int> troll[MAX];
bool visited[MAX];  // dfs 했는가?
int human[MAX];

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int work : troll[cur]){
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

    int K1, K2;
    cin >> K1 >> K2;

    // 우리팀 픽 받기
    for (int i=0; i<K1; i++){
        int a, b;
        cin >> a >> b;  // a가 b번 트롤픽을 하고싶어함
        troll[a].push_back(b);
    }
    int trollK1 = bipartite_match();

    // 초기화
    memset(human, 0, sizeof(human));
    for (int i=1; i<=N; i++){
        troll[i].clear();
    }

    // 상대팀 픽 받기
    for (int i=0; i<K2; i++){
        int a, b;
        cin >> a >> b;  // a가 b번 트롤픽을 하고싶어함
        troll[a].push_back(b);
    }
    int trollK2 = bipartite_match();

    // 우리팀의 트롤픽이 더 많거나 같다면 승급 실패
    if (trollK1 >= trollK2) cout << "그만 알아보자";
    // 우리팀 트롤픽이 더 적다면 승급 성공
    else cout << "네 다음 힐딱이";
    
    return 0;
}