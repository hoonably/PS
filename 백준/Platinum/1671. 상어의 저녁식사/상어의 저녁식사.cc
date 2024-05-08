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
상어의 크기, 속도, 지능이 모두 크거나 같으면 먹을 수 있음
한 상어가 최대 두개의 상어만 먹을 수 있음

이미 먹힌 상어는 다른 상어 못잡음

살아남을 수 있는 상어 수의 최솟값 구하기

조심할 점 : 값이 같다면 서로를 먹을 수 있으니
먹을 수 있는 관계를 미리 벡터로 나타내주자.
*/

#define MAX 51

int N;
struct shark{
    int a, b, c;
    bool operator==(const shark &B){
        return a==B.a && b==B.b && c==B.c;
    }
    bool operator>=(const shark &B){
        return a>=B.a && b>=B.b && c>=B.c;
    }
};

shark sharks[MAX];
vector<int> eat[MAX];

bool visited[MAX];  // dfs 했는가?
int eated[MAX];  // 누구한테 먹혔는가? (0이라면 안먹힘)

bool dfs(int cur){
    if (visited[cur]) return false;
    visited[cur] = true;

    for(int small : eat[cur]){
        // 아직 안먹혔다면 먹음
        // dfs 결과 그걸 먹었던 애가 다른 것을 먹을 수 있다면 뺏어먹음
		if (eated[small] == 0 || dfs(eated[small])) {
			eated[small] = cur;
			return true;
		}
    }
    return false;
}

void bipartite_match() {
    for (int i=1; i<=N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i);
        memset(visited, 0, sizeof(visited));
        dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N; 
    for (int i=1; i<=N; i++){
        cin >> sharks[i].a >> sharks[i].b >> sharks[i].c;
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i==j) continue;

            // 서로 같다면 인덱스 낮은게 먹도록
            if (sharks[i]==sharks[j]){
                eat[min(i,j)].push_back(max(i,j));
            }
            
            // i번째 상어가 j번째 상어를 먹음
            else if (sharks[i]>=sharks[j]){
                eat[i].push_back(j);
            }
        }
    }

    // 이분매칭 두번
    bipartite_match();

    // 남아있는 상어의 수
    int cnt = 0;
    for (int i=1; i<=N; i++){
        if (!eated[i]) cnt++;
    }
    cout << cnt;
    
    return 0;
}