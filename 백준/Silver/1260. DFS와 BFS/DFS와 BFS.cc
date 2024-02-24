#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
N : 정점의 개수
M : 간선의 개수
R : 시작 노드
*/

int N, M, R;
bool visited1[1001];
bool visited2[1001];
vector<int> graph[1001];


void dfs(int cur_node){
    cout << cur_node << ' ';
    visited1[cur_node] = true;
    for (int next_node : graph[cur_node]){
        if (visited1[next_node]) continue;
        dfs(next_node);
    }
}

void bfs(int start_node){
    queue<int> q;
    q.push(start_node);
    visited2[start_node]=true;
    
    while (!q.empty()){
        int cur_node = q.front();
        cout << cur_node << ' ';
        q.pop();
        for (int next_node : graph[cur_node]){
            if (visited2[next_node]) continue;
            visited2[next_node] = true;
            q.push(next_node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> R;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // 무방향 그래프
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 방문이 오름차순으로 한다고 했으니 정렬
    for (int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(R);
    cout << '\n';
    bfs(R);
    
    return 0;
}