#include <bits/stdc++.h>
using namespace std;

/*
길이에 따라 2차원 dp를 사용해
마지막 자리수에 따라 저장한다.
dp[i][j] : i자리수고 마지막 자리수가 j인 경우의 수
*/
int dp[101][11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    // 한자리 수일 경우 초기화
    for(int j=1; j<=9; j++){
        dp[1][j] = 1;
    }

    for(int i=2; i<=N; i++){
        // 두자리수부터는 0이 나올 수 있음
        dp[i][0] = dp[i-1][1];
        for(int j=1; j<=9; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j] %= 1000000000;
        }
    }

    int ans = 0;
    for(int j=0; j<=9; j++){
        ans += dp[N][j];
        ans %= 1000000000;
    }

    cout << ans;

    return 0;
}