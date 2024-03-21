#include <bits/stdc++.h>
using namespace std;

/*
오름차순을 이루는 수 , 단, 인접한 수가 같아도 됨
ex ) 1234, 12224
dp[i][j] : i자리수면서 일의자리가 j인 수
수는 0으로 시작 할 수 있음
*/

int N;
int dp[1001][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 자리수가 1일때 초기화
    // 맨 앞자리는 0이 될 수 있음!
    for (int j=0; j<=9; j++){
        dp[1][j] = 1;
    }

    cin >> N;

    for (int i=2; i<=N; i++){
        // 누적 합
        int temp = 0;
        for (int j=0; j<=9; j++){
            temp += dp[i-1][j];
            dp[i][j] = temp % 10007;
        }
    }

    int ans=0;
    for (int j=0; j<=9; j++){
        // cout << dp[N][j] << ' ';
        ans += dp[N][j];
    }
    cout << ans % 10007;

    
    return 0;
}