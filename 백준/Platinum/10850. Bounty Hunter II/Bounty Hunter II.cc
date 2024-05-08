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
https://www.acmicpc.net/problem/10850
이분 매칭

*/

#define MAX 1000

int N;
vector<int> adj[MAX];
bool visited[MAX];  // dfs 했는가?
int par[MAX];

bool match(int cur){
	visited[cur] = true;
    for(int next : adj[cur]){
		if (par[next] == -1 || !visited[par[next]] && match(par[next])) {
			par[next] = cur;
			return true;
		}
    }
    return false;
}

int bipartite_match() {
    int ret = 0;
    for (int i=0; i<N; i++) {
        memset(visited, 0, sizeof(visited));
        if (match(i)) ret++;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    memset(par, -1, sizeof(par));
    
    cin >> N;
    for (int i=0; i<N; i++){
        int K;
        cin >> K;
        for (int j=0; j<K; j++){
            int work;
            cin >> work;
            adj[i].push_back(work);
        }
    }

    cout << N - bipartite_match();
    
    return 0;
}