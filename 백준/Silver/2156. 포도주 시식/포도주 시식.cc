#include <bits/stdc++.h>
using namespace std;

/*
마지막에 한칸을 오른 경우와 두칸을 오른 경우 dp
마지막에 한칸을 올랐다면 이번에 또 한칸은 못간다.
*/

int drink[10001], dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, num;
    cin >> n;

    for (int i = 1; i <= n; i++) {
		cin >> drink[i];
	}

    dp[0] = 0;
	dp[1] = drink[1];
	dp[2] = drink[1] + drink[2];

    for (int i=3; i<=n; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + drink[i - 1]);
        dp[i] += drink[i];

        // 계단문제랑 다른 이유
        // i까지지만 i번째를 안마시고 최대일 경우 생각!
        // i-1번째까지 먹은게 더 크면 그거 적용
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n];
    
    return 0;
}