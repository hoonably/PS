#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dx[] = {1, -1, 1, -1, 2, -2, 2, -2};

int l;
int start_x, start_y, end_x, end_y;


int bfs(){
    // 초기화 반드시 해줘야함
    int dist[300][300] = {0};
    bool visited[300][300] = {false};

    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    visited[start_x][start_y]=true;
    
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int cur_dist = dist[x][y];
        q.pop();
        
        if (x==end_x && y==end_y){
            return cur_dist;
        }

        for (int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>=l || ny<0 || ny>=l ) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dist[nx][ny] = cur_dist + 1;
            q.push({nx, ny});
        }
    }
    return -1;  // 도달 못했을 경우
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){

        cin >> l;
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;

        cout << bfs() << '\n';
    }
    return 0;
}