#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 100'001

int N, Q;
vector<int> graph[MAX];
int parent[MAX], sons[MAX];  // 자식 정점의 수
ll fruit[MAX];

void dfs(int now, int par){
    for(int nxt : graph[now]){
        if (nxt==par) continue;
        parent[nxt] = now;
        dfs(nxt, now);
        sons[now]++;
    }
}

void addWater(int now, int x){
    if (fruit[now] >= x) {
        fruit[now] += x;
        return;
    }
    x -= fruit[now];
    fruit[now] *= 2;

    if (sons[now]==0) return;

    x = x / sons[now];
    if (x==0) return;

    for(int nxt : graph[now]){
        if (nxt==parent[now]) continue;
        parent[nxt] = now;
        addWater(nxt, x);
    }  
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> Q;
    for(int i=1; i<N; i++){
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for(int i=1; i<=N; i++){
        cin >> fruit[i];
    }

    dfs(1, 0);
    
    while(Q--){
        int order;
        cin >> order;
        if (order==1){
            int u, x;
            cin >> u >> x;
            addWater(u, x);
        }
        else{
            int u;
            cin >> u;
            cout << fruit[u] << '\n';
        }
    }

    return 0;
}