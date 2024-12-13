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

int N;
ll dp[101][21];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    dp[0][arr[0]] = 1;
    for(int i=1; i<N-1; i++){
        for(int j=0; j<=20; j++){
            if(j-arr[i] >= 0) dp[i][j] += dp[i-1][j-arr[i]];
            if(j+arr[i] <= 20) dp[i][j] += dp[i-1][j+arr[i]];
        }
    }
    cout << dp[N-2][arr[N-1]] << '\n';
    
    return 0;
}