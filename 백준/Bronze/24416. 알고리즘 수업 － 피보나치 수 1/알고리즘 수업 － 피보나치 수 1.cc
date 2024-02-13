#include <bits/stdc++.h>
using namespace std;

/*
fib(n) {
    if (n = 1 or n = 2)
    then return 1;  # 코드1
    else return (fib(n - 1) + fib(n - 2));
}
피보나치 수 재귀호출 코드 1 실행 횟수 = 피보나치 수 (N)

fibonacci(n) {
    f[1] <- f[2] <- 1;
    for i <- 3 to n
        f[i] <- f[i - 1] + f[i - 2];  # 코드2
    return f[n];
}
DP 코드 2 실행 횟수 : N-2

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    int dp[41];
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[N] << ' ' << N-2;
    
    return 0;
}