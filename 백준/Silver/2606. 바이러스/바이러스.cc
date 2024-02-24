#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
N : 정점의 개수
M : 간선의 개수
1 : 시작 노드
*/

int N, M;
bool visited[101];
vector<int> graph[101];
int cnt = 0;

void bfs(int start_node){
    queue<int> q;
    q.push(start_node);
    visited[start_node]=true;
    
    while (!q.empty()){
        int cur_node = q.front();
        q.pop();
        for (int next_node : graph[cur_node]){
            if (visited[next_node]) continue;
            cnt++;
            visited[next_node] = true;
            q.push(next_node);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // 무방향 그래프
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(1);
    cout << cnt;
    
    return 0;
}