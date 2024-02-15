#include <bits/stdc++.h>
using namespace std;

/*

*/

int N, K;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;

	dp[0][0] = 1;

	for (int i = 1; i <= N; i++){

        // 파스칼의 삼각형 맨 앞과 뒤만 따로 1로 지정
        dp[i][0] = 1;
        dp[i][i] = 1;

		for (int j = 1; j < i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= 10007;
		}
    }

    cout << dp[N][K];

    return 0;
}