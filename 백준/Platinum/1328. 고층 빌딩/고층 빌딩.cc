#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/1328
*/

#define MAX 

int N, L, R;
ll dp[101][101][101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L >> R;

    // dp[N][L][R] 
    // = dp[N-1][L-1][R] + dp[N-1][L][R-1] + dp[N-1][L][R]*(N-2)

    // 거꾸로 큰 건물부터 계속해서 작은 건물을 세우는거임
    // 왼쪽에 세우는 경우 : 1가지 (L이 하나 늘어난거임)
    // 오른쪽에 세우는 경우 : 1가지 (R이 하나 늘어난거임)
    // 사이에 건물을 세우는 경우 : N-2가지 (L, R에 영향 없음)

    dp[1][1][1] =1;
    for(int n=2; n<=N ; ++n)
        for(int l=1 ; l<=n ; ++l)
            for(int r=1; r<=n ; ++r)
                dp[n][l][r] = (dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r]*(n-2))%MOD;

    cout << dp[N][L][R];
    
    return 0;
}