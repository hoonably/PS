#include <bits/stdc++.h>
using namespace std;

/*
바로 이전 과 5번째 전 꺼를 합한 값이 나옴
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N;
    long dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i=6; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    cin >> T;
    while(T--){
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}