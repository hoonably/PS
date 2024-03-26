#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*
i 번째 원소를 보고 j개 원소를 뽑아야한다면
i 번째 원소를 뽑을 경우 : dp[i - 2][j - 1]
i 번째 원소를 뽑지 않을 경우 : dp[i - 1] [j]
dp[i][j] = dp[i - 2][j - 1] + dp[i - 1] [j]
*/

const int MOD = 1'000'000'003;
int N, K;
int dp[1002][1002];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    if (K*2 > N) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; ++i) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    
    // i는 n이전까지 n까지하면 순환을 고려하지 않은 답이 생김
    for (int i = 2; i < N; ++i) {
        for (int j = 2; j <= K; ++j) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }

    cout << (dp[N-3][K-1] + dp[N-1][K]) % MOD;
    
    return 0;
}