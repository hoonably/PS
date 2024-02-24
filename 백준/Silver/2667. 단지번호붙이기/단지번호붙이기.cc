#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
N : 정점의 개수
M : 간선의 개수
R : 시작 노드
*/

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int N;
int graph[25][25];

int bfs(int start_x, int start_y){
    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    graph[start_x][start_y]=1;
    
    int cnt = 0; // 한단지 내의 집의 수
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        graph[x][y]=0;
        cnt++;
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=N || ny<0 || ny>=N ) continue;
            if (graph[nx][ny]==0) continue;
            graph[nx][ny]=0;
            q.push({nx, ny});
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            char getChar;
            cin >> getChar;
            graph[i][j] = getChar - '0';
        }
    }

    vector<int> ans;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (graph[i][j]==1){
                ans.push_back(bfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n'; 
    for (int i : ans){
        cout << i << '\n';
    }
    
    return 0;
}