#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int N, M;
bool visited[101];
map<int,int> snake;


int bfs(int start_node, int end_node){
    queue<pair<int,int>> q;
    q.push({start_node,0});
    visited[start_node]=true;
    
    while (!q.empty()){
        
        int cur_node = q.front().first;
        int cur_dist = q.front().second;
        q.pop();

        if (cur_node == end_node){
            return cur_dist;
        }
        
        for (int i=1; i<=6; i++){
            int next_node = cur_node+i;
            if (next_node>100) continue;
            if (visited[next_node]) continue;
            visited[next_node] = true;

            // 뱀이나 사다리를 탔다면
            if (snake.find(next_node)!=snake.end()){
                q.push({snake[next_node], cur_dist + 1});
            }
            // 안탔다면
            else {
                q.push({next_node, cur_dist + 1});
            }
        }
    }
    return -1;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N+M; i++){
        int s,e;
        cin >> s >> e;
        snake[s]=e;
    }

    cout << bfs(1, 100);

    return 0;
}