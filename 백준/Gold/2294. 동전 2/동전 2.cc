#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 100

int n, k;
int coin[MAX];
int dp[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> coin[i];
    }
    sort(coin, coin+n);

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int now=1; now<=k; now++){
        for(int c : coin){
            int prev = now-c;
            if (prev<0) break;
            dp[now] = min(dp[now], dp[prev]+1);
        }
    }

    if (dp[k]==INF) cout << -1;
    else cout << dp[k];
    
    return 0;
}