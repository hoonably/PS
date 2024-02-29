#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

#define MAX 500

// (1,0) 이라면 board[0,0], [1,0] 을 봐야함
// (2,2) 라면 board[1,1], [2,1], [1,2], [2,2] 봐야하므로

// 0, 1 번째는 \ 일 경우 갈 수 있다.
// 2, 3 번째는 / 일 경우 갈 수 있다.
int dy[] = {-1, 0, 0, -1};
int dx[] = {-1, 0, -1, 0};

int N, M;
bool visited[MAX+1][MAX+1];
char board[MAX+1][MAX+1];

int bfs(){
    deque<tuple<int,int,int>> dq;
    dq.push_back({0,0,0});
    visited[0][0]=true;
    
    while(!dq.empty()){
        auto [x, y, dist] = dq.front();
        dq.pop_front();
        
        if (x==N && y==M) return dist;

        // visited를 넣어줄때 먼저 true로 한다면
        // 그 다음 더 빠른 0 가중치가 오면 그 탐색을 안하므로 틀릴 수 있다.
        // 그래서 visited 표시는 큐에 넣을때가 아닌 탐색 도달 했을때 해준다.
        visited[x][y]=true;



        int nx, ny;

        // \ 일 경우 갈 수 있는 경우
        // 1. 왼쪽 위
        nx = x-1; ny = y-1;
        if ( nx>=0 && nx<=N && ny>=0 && ny<=M && !visited[nx][ny]){
                if (board[x-1][y-1]=='\\')
                    dq.push_front({nx,ny,dist});
                else dq.push_back({nx,ny,dist+1});
        }
        // 2. 오른쪽 아래
        nx = x+1; ny = y+1;
        if ( nx>=0 && nx<=N && ny>=0 && ny<=M && !visited[nx][ny]){
                if (board[x][y]=='\\')  // board[x+1][y+1] 아님! 조심하기
                    dq.push_front({nx,ny,dist});
                else dq.push_back({nx,ny,dist+1});
        }
        
        // / 일 경우 갈 수 있는 경우
        // 3. 왼쪽 아래
        nx = x+1; ny = y-1;
        if ( nx>=0 && nx<=N && ny>=0 && ny<=M && !visited[nx][ny]){
                if (board[x][y-1]=='/')
                    dq.push_front({nx,ny,dist});
                else dq.push_back({nx,ny,dist+1});
        }
        // 4. 오른쪽 위
        nx = x-1; ny = y+1;
        if ( nx>=0 && nx<=N && ny>=0 && ny<=M && !visited[nx][ny]){
                if (board[x-1][y]=='/')
                    dq.push_front({nx,ny,dist});
                else dq.push_back({nx,ny,dist+1});
        }

    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }
    
    int ans = bfs();
    if (ans==-1) cout << "NO SOLUTION";
    else cout << ans;
    
    return 0;
}