#include <bits/stdc++.h>
using namespace std;

/*
마지막 집의 색상에 따라 기록
dp[0][i] = i번째 집까지 빨간색으로 칠하는 비용 최솟값
dp[1][i] = i번째 집까지 초록색으로 칠하는 비용 최솟값
dp[2][i] = i번째 집까지 파랑색으로 칠하는 비용 최솟값
*/

int dp[3][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, cost;
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> cost;
        dp[0][i] = min(dp[1][i-1], dp[2][i-1]);
        dp[0][i] += cost;
        cin >> cost;
        dp[1][i] = min(dp[0][i-1], dp[2][i-1]);
        dp[1][i] += cost;
        cin >> cost;
        dp[2][i] = min(dp[0][i-1], dp[1][i-1]);
        dp[2][i] += cost;
    }

    int ans = min(dp[0][N], dp[1][N]);
    ans = min(ans, dp[2][N]);
    cout << ans;

    
    return 0;
}