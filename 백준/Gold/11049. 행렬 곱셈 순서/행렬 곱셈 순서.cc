#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[i][j] : i~j 구간 곱셈 연산 최솟값

*/

int N, r, c;
int sum[501], matrix[501][2], dp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

    // len : 단계 (길이)
    for (int len=1; len<N; len++){
        for (int s=1; s+len<=N; s++){
            int e = s + len;
            dp[s][e] = 1e9;
            for (int m=s; m<e; m++){
                // 기존 dp값 더하기
                int step1 = dp[s][m] + dp[m+1][e];
                // 두개의 dp결과를 마지막으로 연산할때 하는 연산
                int step2 = matrix[s][0] * matrix[m][1] * matrix[e][1];
                dp[s][e] = min(dp[s][e], step1 + step2);
            }
        }
    }

    cout << dp[1][N];
    
    return 0;
}