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
https://www.acmicpc.net/problem/2570

이분그래프 : 
4방향으로 간선을 만들지 않고 
아래왼, 아래오른 두방향으로 가면서
간선을 생성하면 단방향이라 이분 그래프가 된다.

(1,1) (2,2) (3,3) 이 있다면
모두 이분매칭이 되므로 그 셋 중에 한 곳에 놓으면 된다.

최대 독립 집합의 크기를 구하면 된다.
*/

#define MAX 101
const int dx[] = {1, 1};
const int dy[] = {1, -1};

int N, M;
bool board[MAX][MAX];
int idCnt;  // id 카운트
int cnt0;  // 오른아래 방향 id 개수
int id[MAX][MAX][2];

void makeGroup(int dir){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(board[i][j]) continue;
			if(id[i][j][dir]) continue;
			int nx = i;
            int ny = j;
			id[i][j][dir] = ++idCnt;
			while(true){
				nx += dx[dir], ny += dy[dir];
				if(ny < 1 || nx > N || ny > N) break;
				if(board[nx][ny]) break;
				if(id[nx][ny][dir]) break;
				id[nx][ny][dir] = idCnt;
			}
		}
	}
}

set<int> g[MAX*MAX];
bool visited[MAX*MAX];  // match 했는가?
int par[MAX*MAX];

bool match(int cur){
    for(int next : g[cur]){
        if (visited[next]) continue;
        visited[next] = true;
		if (par[next] == 0 || match(par[next])) {
			par[next] = cur;
			return true;
		}
    }
    return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=1; i<=cnt0; i++) {
        memset(visited, 0, sizeof(visited));
        if (match(i)) ret++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin >> N >> M;
	for(int i=0; i<M; i++){
		int a, b; 
        cin >> a >> b;
		board[a][b] = true;
	}

	makeGroup(0);
    cnt0 = idCnt;
	makeGroup(1);

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(board[i][j]) continue;
			g[id[i][j][0]].insert(id[i][j][1]);
		}
	}

	cout << bipartite_match();
    
    return 0;
}