#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N, M, R;
bool visited[100001];
vector<int> graph[100001];
int ans[100001];
int cnt = 1;

void dfs(int cur_node){
    ans[cur_node] = cnt++;
    visited[cur_node] = true;
    for (int next_node : graph[cur_node]){
        if (visited[next_node]) continue;
        dfs(next_node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> R;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 방문이 오름차순으로 한다고 했으니 정렬
    for (int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(R);
    for (int i=1; i<=N; i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}