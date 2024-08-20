#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1000000000;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/1562
*/

#define MAX 

int n;
int dp[101][10][1<<10];	

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
	//base
	dp[1][0][1] = 0;	//명시적
	for (int i=1; i<=9; ++i){
		dp[1][i][1<<i] = 1;
	}
 
	//step
	for (int i = 2; i <= n; ++i) {

		// cur = 0
        int cur = 0;
        for (int state = 0; state <= 1023; ++state) 
            dp[i][cur][state | (1 << cur)] = (dp[i][cur][state | (1 << cur)] + dp[i - 1][cur + 1][state])%MOD;
        
        // cur 1~8
		while(++cur<9) {
			for (int state = 0; state <= 1023; ++state) {
					dp[i][cur][state | (1 << cur)] = (dp[i][cur][state | (1 << cur)] + dp[i - 1][cur + 1][state]) % MOD;
					dp[i][cur][state | (1 << cur)] = (dp[i][cur][state | (1 << cur)] + dp[i - 1][cur - 1][state]) % MOD;
			}
		}

        // cur 9
        for (int state = 0; state <= 1023; ++state)
            dp[i][cur][state | (1 << cur)] = (dp[i][cur][state | (1 << cur)] + dp[i - 1][cur - 1][state]) % MOD;
    }
 
	int ans = 0;
	for (int cur = 0; cur <= 9; ++cur) ans = (ans + dp[n][cur][1023]) % MOD;

    cout << ans;
    
    return 0;
}