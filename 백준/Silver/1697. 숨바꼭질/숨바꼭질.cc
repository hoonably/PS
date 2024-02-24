#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N, K;
int dist[200000];
bool visited[200000];

int move(int loc, int num){
    if (num==0) return loc-1;
    if (num==1) return loc+1;
    return 2*loc;
}

int bfs(int start_node, int end_node){
    queue<int> q;
    q.push(start_node);
    visited[start_node]=true;
    
    while (!q.empty()){
        
        int cur_node = q.front();
        int cur_dist = dist[cur_node];
        
        if (cur_node == end_node){
            return cur_dist;
        }

        q.pop();
        for (int i=0; i<3; i++){
            int next_node = move(cur_node, i);
            if ( next_node<0 || next_node>100000) continue;
            if (visited[next_node]) continue;
            visited[next_node] = true;
            dist[next_node] = cur_dist + 1;
            q.push(next_node);
        }
    }
    return -1;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    cout << bfs(N, K);

    return 0;
}