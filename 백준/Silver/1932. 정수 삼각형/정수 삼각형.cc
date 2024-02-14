#include <bits/stdc++.h>
using namespace std;

/*
dp를 0을 비워두고 진행하면 조건문 없이 편하게 계산이 가능하다.
*/

int dp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            cin >> num;
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num;
        }
    }
    
    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, dp[n][i]);
    }
    
    cout << ans;
    
    return 0;
}