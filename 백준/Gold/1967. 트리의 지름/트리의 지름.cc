#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001

/*
# 트리의 지름 : 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
# 트리의 지름을 구하는 방법
# 임의의 점 (1) 부터 가장 먼 거리의 노드 (point) 를 구한다.
# 그 후 그 point에서 가장 먼 거리로 한번 더 탐색을 하면 그게 최대인 지름이다.
*/

int V;
vector<pair<int,int>> tree[MAX];

// start_node로부터 가장 먼 노드와 거리를 뽑아내는 함수
pair<int,int> bfs(int start_node){
    queue<pair<int,int>> q;
    q.push({start_node, 0});
    vector<bool> visited(V+1, false);
    visited[start_node] = true;
    int far_dist = 0;  // start node 로부터 가장 먼 거리
    int far_point = 0;  // start node 로부터 가장 먼 노드

    while (!q.empty()){
        auto [now_node, now_dist] = q.front();
        q.pop();
        for (auto [nxt_node, nxt_dist] : tree[now_node]){
            if (visited[nxt_node]) continue;
            visited[nxt_node] = true;
            nxt_dist += now_dist;
            q.push({nxt_node, nxt_dist});

            // 가장 먼 노드와 그 길이 갱신
            if (nxt_dist > far_dist){
                far_dist = nxt_dist;
                far_point = nxt_node;
            }
        }
    }
    return {far_point, far_dist};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> V;
    for(int i=0; i<V-1; i++){
        int start, end, dist;
        cin >> start >> end >> dist;
        tree[start].push_back({end, dist});
        tree[end].push_back({start, dist});
    }

    // 임의의 점(1) 부터 가장 먼 거리의 노드(point) 구하기
    int point = bfs(1).first;
    
    // point에서 가장 먼 노드와의 거리 구하기
    cout << bfs(point).second;
    
    return 0;
}