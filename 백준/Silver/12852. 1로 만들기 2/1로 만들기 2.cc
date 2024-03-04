#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
before vector를 사용해 그 이전 값 저장
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> dp(N+1);
    vector<int> before(N+1);

    for (int i=2; i<=N; i++){
        // 1 빼기
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        // 3 나누기
        if (i%3==0){
            if (dp[i/3]+1 < dp[i]){
                dp[i] = dp[i/3]+1;
                before[i] = i/3;
            }
        }
        // 2 나누기
        if (i%2==0){
            if (dp[i/2]+1 < dp[i]){
                dp[i] = dp[i/2]+1;
                before[i] = i/2;
            }
        }
    }

    cout << dp[N] << '\n';

    // 역추적
    while (N>0){
        cout << N << ' ';
        N = before[N];
    }
    
    return 0;
}