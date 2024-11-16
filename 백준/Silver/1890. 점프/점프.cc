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

int n;
int board[100][100];
ll dp[100][100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin >> board[i][j];

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;
            
            int v = board[i][j];
            int down = v + i;
            int right = v + j;
 
            if (down < n) dp[down][j] = dp[down][j] + dp[i][j];
            if (right < n) dp[i][right] = dp[i][right] + dp[i][j];
        }
    }
    cout << dp[n-1][n-1];
    
    return 0;
}