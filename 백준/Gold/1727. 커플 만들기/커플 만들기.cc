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

*/

// dp[i][j] : i번째 남자와 j번째 여자까지 매칭했을때 최소 성격차이
int boy[1001], girl[1001];
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> boy[i];
    for(int i=1; i<=m; i++) cin >> girl[i];

    sort(boy+1, boy+n+1); sort(girl+1, girl+m+1);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // i번째 남자와 j번째 여자를 매칭했을때 성격차이

            // 동일하면 바로 매칭
            if(i==j) dp[i][j]=dp[i-1][j-1]+abs(boy[i]-girl[j]);
            else if(i>j) dp[i][j]=min(dp[i-1][j-1]+abs(boy[i]-girl[j]),dp[i-1][j]);
            else dp[i][j]=min(dp[i-1][j-1]+abs(boy[i]-girl[j]),dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    
    return 0;
}