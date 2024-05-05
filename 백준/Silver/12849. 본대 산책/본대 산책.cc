#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/12849

그냥 노가다로 갈 수 있는곳에서 와서 합해서 경우의 수를 구하면 됨
0 : 정보과학관
1 : 전산관
2 : 신앙관
3 : 미래관
4 : 진리관
5 : 환경직기념관
6 : 학생회관
7 : 형남공학관
*/

#define MAX 

int D;
ll dp[8] = {1, 0, 0, 0, 0, 0, 0, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    cin >> D;

    while (D--) {
        ll temp[8];
        for (int i = 0; i < 8; i++) {
            temp[0] = dp[1] + dp[3];
            temp[1] = dp[0] + dp[2] + dp[3];
            temp[2] = dp[1] + dp[3] + dp[4] + dp[5];
            temp[3] = dp[0] + dp[1] + dp[2] + dp[5];
            temp[4] = dp[2] + dp[5] + dp[6];
            temp[5] = dp[3] + dp[2] + dp[4] + dp[7];
            temp[6] = dp[4] + dp[7];
            temp[7] = dp[5] + dp[6];
        }

        for (int i = 0; i < 8; i++) {
            dp[i] = temp[i] % MOD;
        }
    }

    cout << dp[0];
    
    return 0;
}