#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/11014

아무도 컨닝을 할 수 없도록 학생을 배치했을 때
배치할 수 있는 최대 학생 수 구하기

o가 학생이라면
x     x
x  o  x
x     x

번갈아가면서 이분그래프 그려지고, 컨닝을 간선이라고 생각 
=> 최소한의 정점을 제거해서 모든 간선 없애기라고 생각

=> 쾨닉의 정리

1차원으로 변환해서 풀면 두배 더 빠름
하지만 가독성 위해 그냥 2차원으로 풀음
*/

#define MAX 82

const int dx[6] = { -1,0,1,-1,0,1 };
const int dy[6] = { -1,-1,-1,1,1,1 };

int N, M;
bool broken[MAX][MAX];  // 부서진 책상
vector<pii> graph[MAX][MAX];  // 
bool visited[MAX][MAX];
pii match[MAX][MAX];  // 매칭 안된건 {-1,?}로 할당

// visited가 없이 진행
bool dfs(int x, int y){
    if(visited[x][y]) return false;
    visited[x][y] = true;
    
	for(pii next : graph[x][y]){
        auto [nx, ny] = next;
        pii &matching = match[nx][ny];

		if(matching.first == -1 || 
        dfs(matching.first, matching.second)){
			matching = {x,y};
            return true;
		}
	}
	return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=1; i<=N; i++){
        // 양방향이 겹치기 때문에
        // 홀수줄과 짝수줄을 분리해 이분 그래프로
        for (int j=1; j<=M; j+=2){
            if (broken[i][j]) continue;
            memset(visited, 0, sizeof(visited));
            if (dfs(i,j)) ret++;
        }
    }
    return ret;
}

void solve(){
    cin >> N >> M;

    memset(broken, true, sizeof(broken));
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            match[i][j].first = -1;  // 매칭 안됨 : -1
            graph[i][j].clear();
        }
    }

    int sum = 0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            char c; cin >> c;
            if (c=='.') {
                broken[i][j] = false;
                sum++;
            }
        }
    }

	for(int x=1; x<=N; x++){
		for(int y=1; y<=M; y++){
            if(broken[x][y]) continue;
			for(int k=0; k<6; k++){
				int ni = x + dx[k];
				int nj = y + dy[k];
				if(broken[ni][nj]) continue;
				graph[x][y].push_back({ni, nj});
			}
		}
	}

    cout << sum - bipartite_match() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int C;
    cin >> C;
    while(C--){
        solve();
    }
    
    return 0;
}