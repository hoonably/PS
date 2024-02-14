#include <bits/stdc++.h>
using namespace std;

/*
마지막에 한칸을 오른 경우와 두칸을 오른 경우 dp
마지막에 한칸을 올랐다면 이번에 또 한칸은 못간다.
*/

int stair[301], dp[301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, num;
    cin >> n;

    for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

    dp[0] = 0;
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

    for (int i=3; i<=n; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]);
        dp[i] += stair[i];
    }
    cout << dp[n];
    
    return 0;
}