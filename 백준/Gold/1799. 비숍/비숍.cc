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

int N, M;
bool board[MAX][MAX];  // 장애물
int diag1[MAX][MAX]; // to the right down
int diag2[MAX][MAX]; // to the right up
int cnt1, cnt2;  // 오른아래 방향, 오른위 방향 개수

vector<int> adj[MAX*MAX];
bool visited[MAX*MAX];  // match 했는가?
int par[MAX*MAX];

bool match(int cur){
	visited[cur] = true;
    for(int next : adj[cur]){
		if (par[next] == 0 || !visited[par[next]] && match(par[next])) {
			par[next] = cur;
			return true;
		}
    }
    return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=1; i<=cnt1; i++) {
        memset(visited, 0, sizeof(visited));
        if (match(i)) ret++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	cin >> N;
	for(int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            int num;
            cin >> num;
            board[i][j]=num^1;
        }
	}

	// to the right down
    for (int i = 2; i<=2*N; i++){
		cnt1++;
        for (int j = 1; i-j>=1; j++){
            if (board[j][i-j] == 0) diag1[j][i-j] = cnt1;
        }
    }

	// to the right up
    for (int i = -N+1; i<=N-1; i++){
		cnt2++;
        for (int j = 1; j-i<=N; j++){
            if (board[j][j-i] == 0) diag2[j][j-i] = cnt2;;
        }
    }

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(board[i][j]) continue;
			adj[diag1[i][j]].push_back(diag2[i][j]);
		}
	}

	cout << bipartite_match();
    
    return 0;
}