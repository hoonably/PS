#include <bits/stdc++.h>
using namespace std;

/*
M이 짝수일 경우 줄이 바뀔때 같은 문자가 와야한다.
B가 시작인것을 기준으로 dp 생성 (dp : 자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합)
*/

int N, M, K;

int idx = 0;
const char color[2] = {'B','W'};

int dp[2001][2001];
char board[2001][2001];

void colorchange(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin >> board[i][j];
        }
    }
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            //         자신의 왼쪽합 + 자신의 위쪽 합 - 겹치는 합
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            if (board[i][j]==color[idx]) dp[i][j]++;

            idx^=1;  // 비트연산을 통해 0이면 1, 1이면 0으로 변환
        }
        // M이 짝수일 경우 줄바뀔때 그대로 이므로 다시 바꿔줌
        if (M%2==0) idx^=1;
    }

    // 부분 합
    int ans = 1e9;
    for (int i=0; i+K<=N; i++){
        for (int j=0; j+K<=M; j++){
            int temp = dp[i+K][j+K] - dp[i+K][j] - dp[i][j+K] + dp[i][j];  // K*K만큼 구간합
            temp = min(temp, K*K-temp);  // W로 시작하는 경우랑 비교
            ans = min(ans, temp);
        }
    }
    
    cout << ans;

    return 0;
}