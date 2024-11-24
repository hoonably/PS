#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

vector<int> adj[10001];
bool visited[10001];

int dfs(int cur){
    int cnt = 1;
    for(int nxt : adj[cur]){
        if(visited[nxt]) continue;
        visited[nxt] = true;
        cnt += dfs(nxt);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i=0; i<M; i++){
        // a가 b를 신뢰한다. => b를 해킹하면 a도 해킹할 수 있다.
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }

    int max_cnt = 0;
    vector<int> ans;
    for(int i=1; i<=N; i++){
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        int cnt = dfs(i);
        if(cnt > max_cnt){
            max_cnt = cnt;
            ans.clear();  // ans 초기화
            ans.push_back(i);
        }else if(cnt == max_cnt){
            ans.push_back(i);
        }
    }
    for (int a : ans) cout << a << ' ';
    
    return 0;
}