#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------
- 위에가 하나 튀어나온 경우
- 아래가 하나 튀어나온 경우
- 꽉 찬 경우

dp[8] = dp[6] * dp[2] + dp[4] * 2 + dp[2] * 2 + dp[0] * 2
dp[8] = dp[6] * 3 + dp[4] * 2 + dp[2] * 2 + dp[0] * 2

dp[2]는 3이다. 

dp[n] = dp[n-2] * 3 + dp[n-4] * 2 + ... + dp[2] * 2 + dp[0] * 2
dp[n] = dp[n-2] * 3 + dp[n-2] - dp[n-4];
dp[n] = dp[n-2] * 4 - dp[n-4];
*/

int dp[31];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=N; i++){
        // dp[n] = dp[n-2] * 3 + dp[n-4] * 2 + ... + dp[2] * 2 + dp[0] * 2
        // dp[n] = dp[n-2] * 3 + dp[n-2] - dp[n-4];
        // dp[n] = dp[n-2] * 4 - dp[n-4];
        dp[i] = dp[i-2] * 4 - dp[i-4];
    }
    cout << dp[N];

    
    return 0;
}