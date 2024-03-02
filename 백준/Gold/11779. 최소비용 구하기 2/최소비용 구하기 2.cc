#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e9

/*
다익스트라에 경로까지 구하는 것이다.
문제의 지문에 명시되어 있지는 않지만, 동일 경로에 대해 다른 비용 값이 들어올 수 있음.
이때 최소 비용으로 업데이트 해주는 과정 필요함. 
A->B : 10
A->B : 5
*/

int n, m;
vector<vector<pair<int,int>>> graph;
int ans[1001];  // ans[i]=j  : j->i로 가는것이 최단루트

vector<int> dijkstra(int start){
    vector<int> dist(n + 1, INF);  // INF로 선언과 동시에 초기화
    priority_queue<pair<int, int>> pq;  // 우선순위 큐 선언

    dist[start] = 0;
    pq.push({0, start});  // 우선순위 큐에 넣기 (힙큐이므로 순서 중요!!)

    while (!pq.empty()) {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 테이블보다 가중치가 큰 튜플이면 무시
        if (cur_dist > dist[cur_node]) continue;

        for (auto& edge : graph[cur_node]) {
            int nxt_node = edge.first;
            int nxt_dist = edge.second + cur_dist;
            
            if (nxt_dist < dist[nxt_node]) {  // 유망하면

                // nxt를 가기 위한 그 이전 경로 기록
                ans[nxt_node]=cur_node;

                dist[nxt_node] = nxt_dist;
                pq.push({-nxt_dist, nxt_node});
            }
        }
    }

    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    graph.resize(n+1);
    for (int i=0; i<m; i++){
        int s, e, v;
        cin >> s >> e >> v;
        // 동일 경로에 대해 다른 비용 값이 들어올 수 있음.
        // 이때 최소 비용으로 업데이트 해주는 과정 필요함.

        graph[s].push_back({e, v});
    }

    

    int start, end;
    cin >> start >> end;
    vector<int> distS = dijkstra(start);
    cout << distS[end] << '\n';

    // 뒤로 돌아오면서 경로 탐색
    vector<int> temp = {end};
    int next = end;
    while (next != start){
        next = ans[next];
        temp.push_back(next);
    }

    cout << temp.size() << '\n';
    for (int i=temp.size()-1; i>=0; i--){
        cout << temp[i] << ' ';
    }
    
    return 0;
}