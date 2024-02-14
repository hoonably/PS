#include <bits/stdc++.h>
using namespace std;

/*
dp[i] : i번째까지 가장 긴 증가하는 부분수열의 길이
*/

int A[1001], dp_up[1001], dp_down[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        dp_up[i] = 1;  // dp 테이블 초기화
        dp_down[i] = 1;
    }

    // 가장 긴 증가하는 부분수열 길이
    for(int i=2; i<=N+1; i++){
        // 이전으로 탐색
        for(int j=i-1; j>0; j--){
            if (A[j]<A[i]) {
                dp_up[i] = max(dp_up[i], dp_up[j]+1);
            }
        }
    }

    // 가장 긴 감소하는 부분수열 길이
    for(int i=N; i>0; i--){
        // 이후로 탐색
        for(int j=i+1; j<=N; j++){
            if (A[j]<A[i]) {
                dp_down[i] = max(dp_down[i], dp_down[j]+1);
            }
        }
    }

    int ans = 1;
    for(int i=1; i<=N; i++){
        ans = max(ans, dp_up[i] + dp_down[i] - 1);
    }
    cout << ans;
    
    return 0;
}