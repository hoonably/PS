#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

#define MAX 500

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool visited[MAX+1][MAX+1];
int board[MAX+1][MAX+1];

int bfs(){
    deque<tuple<int,int,int>> dq;
    dq.push_back({0,0,0});
    visited[0][0]=true;
    
    while(!dq.empty()){
        auto [x, y, dist] = dq.front();
        // int x = get<0>(dq.front());
        // int y = get<1>(dq.front());
        // int dist = get<2>(dq.front());
        dq.pop_front();
        
        if (x==MAX && y==MAX) return dist;

		for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if ( nx<0 || nx>MAX || ny<0 || ny>MAX ) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny]=true;
            if (board[nx][ny]==0) dq.push_front({nx,ny,dist});
            else if (board[nx][ny]==1) dq.push_back({nx,ny,dist+1});
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    while(N--){
        int X1, X2, Y1, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int i=min(X1,X2); i<=max(X1,X2); i++){
            for (int j=min(Y1,Y2); j<=max(Y1,Y2); j++){
                board[i][j]=1;
            }
        }
    }
    cin >> M;
    while(M--){
        int X1, X2, Y1, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int i=min(X1,X2); i<=max(X1,X2); i++){
            for (int j=min(Y1,Y2); j<=max(Y1,Y2); j++){
                board[i][j]=2;
            }
        }
    }
    if (board[500][500]==2) cout << -1;
    else cout << bfs();
    
    return 0;
}