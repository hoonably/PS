#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MOD 1'000'000'007

/*
1과 5로만 이루어진 N자리 자연수 중 15의 배수가 몇개인지 판별
15의 배수 : 각 자리수의 합이 3으로 나누어 떨어지면서, 일의 자리 숫자가 0 또는 5
*/

ll dp[1516][3];  // dp[n][k] : n 자리수 중 3으로 나눈 나머지가 k 인 개수

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    // 무조건 1의자리는 5 고정이므로!!

    dp[1][1] = 0;  // 자리수가 1일때 3으로 나눈 나머지가 1이면서 5의 배수는 없다.
    dp[1][2] = 1;  // 자리수가 1일때 3으로 나눈 나머지가 2면서 5의 배수 : 1개 (5)

    for (int i=2; i<=N; i++){
        dp[i][0] = (dp[i-1][2] + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;  // 나머지가 1이면 맨 앞에 5 추가
        dp[i][2] = (dp[i-1][1] + dp[i-1][0]) % MOD;
    }
    cout << dp[N][0];
    
    return 0;
}