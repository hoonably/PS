#include <bits/stdc++.h>
using namespace std;

/*
dp[i] : i번째까지 가장 긴 증가하는 부분수열의 길이
*/

int A[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        dp[i] = 1;  // dp 테이블 초기화
    }

    for(int i=2; i<=N+1; i++){
        // 뒤로 탐색
        for(int j=i-1; j>0; j--){
            if (A[j]<A[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 1;
    for(int i=1; i<=N; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;
    
    return 0;
}