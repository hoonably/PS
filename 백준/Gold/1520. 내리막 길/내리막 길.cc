#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
순차적으로 일정한 규칙을 따라 dp를 만드는 것이 아니다.
그저 메모이제이션으로 구했던 것이 나오면 바로 활용하기 위해 DP를 사용한다.

dp[i][j] = (i,j) 부터 도착지점까지 가는 경우의 수

dp[i][j]에서 상하좌우 네방향으로 가는데, 그 중 이미 dp를 구했던 좌표가 나온다면
이미 구해졌던 값을 사용해 더해주면 된다.
*/

int M, N;
int high[501][501];
int dp[501][501];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int x, int y){
    if (x == M-1 && y == N-1) return 1;
    if (dp[x][y]!=-1) return dp[x][y];
    
    dp[x][y]=0;

    for (int move=0; move<4; move++){
        int nx = x + dx[move];
        int ny = y + dy[move];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;  // 범위를 넘어가면 PASS
        if (high[nx][ny]>=high[x][y]) continue;  // 새로 가는 곳이 더 높거나 같다면 PASS
        
        dp[x][y] += dfs(nx, ny);;
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> M >> N;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cin >> high[i][j];
            dp[i][j] = -1;  // 초기화 (아직 탐색 안한 것을 의미)
        }
    }
    cout << dfs(0,0);

    // for (int i=0; i<M; i++){
    //     for (int j=0; j<N; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}