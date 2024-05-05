#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 33

/*

*/

int N;
bool graph[MAX][MAX];
ll dp[32][32][3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> graph[i][j];
        }
    }

	dp[0][1][0] = 1;
	for (int j = 2; j < N; j++)	// (0, 2)부터 (0, N-1)까지 체크
		if (!graph[0][j])
			dp[0][j][0] = dp[0][j - 1][0];

	for (int i = 1; i < N; i++)	// 1행부터
	{
		for (int j = 2; j < N; j++)	// 2열부터
		{
			if (!graph[i][j])	// 빈칸이면
			{
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
				dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
				if (!graph[i-1][j] && !graph[i][j-1])
					dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}


    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    
    return 0;
}