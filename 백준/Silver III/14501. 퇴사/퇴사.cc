#include <bits/stdc++.h>
using namespace std;

/*
dp[i] : i일까지 상담을 했을 때 최대 금액
*/

int N;
int T[16], P[16], dp[16];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> T[i];
        cin >> P[i];
    }
    for (int i=1; i<=N; i++){
        
        // 최대값은 누적으로 계속 이어져야함
        dp[i] = max(dp[i], dp[i-1]);
        
        // i번째 날 일을 했을때 끝나는 날
        int end = i + T[i]-1;

        // 아예 N일 넘어가는경우 pass
        if (end > N) continue;

        // 기존 저장값 vs 지금 상담을 했을 경우
        dp[end] = max(dp[end], dp[i-1]+P[i]);
        
    }

    int ans = 0;
    for (int i=1; i<=N; i++){
        // cout << dp[i] << ' ';  // test code
        ans = max(ans, dp[i]);
    }

    cout << ans;
    
    return 0;
}