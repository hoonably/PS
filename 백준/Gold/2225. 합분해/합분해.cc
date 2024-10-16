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
0~N 까지 정수를 K개 더해서 그 합이 N이 되는 경우의 수를 구하기
*/

#define MAX 

int N, K;
int dp[201][201];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    // dp[a][b] = a개를 더해서 b가 되는 경우의 수

    // 본인 하나로 이루어진것
    for(int i=0; i<=N; i++) dp[1][i] = 1;

    for(int i=2; i<=K; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=j; k++){
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= 1000000000;
            }
        }
    }
    cout << dp[K][N] << '\n';
    
    return 0;
}