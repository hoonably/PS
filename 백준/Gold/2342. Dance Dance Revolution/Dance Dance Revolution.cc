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
중앙 -> 1234 : 2
1 -> 24 : 3 (이웃)
1 -> 3 : 4 (반대편)
1 -> 1 : 1 (같은 지점)
*/

#define MAX 

int costs[5][5] = {
    {0,2,2,2,2},
    {0,1,3,4,3},
    {0,3,1,3,4},
    {0,4,3,1,3},
    {0,3,4,3,1}
};

int dp[100'001][5][5];

void MIN(int& change, const int other){
    if (change > other) change = other;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;  // start

    int next;
    int t = 1;
    while(true){
        cin >> next;
        if(next==0) break;

        for(int i=0; i<4; i++){
            for(int j=i; j<=4; j++){
                int prev = dp[t-1][i][j];
                if (prev==INF) continue;

                // i를 바꾸기
                if (next < j) MIN(dp[t][next][j], prev + costs[i][next]);
                else if (next > j) MIN(dp[t][j][next], prev + costs[i][next]);

                // j를 바꾸기
                if (next < i) MIN(dp[t][next][i], prev + costs[j][next]);
                else if (next > i) MIN(dp[t][i][next], prev + costs[j][next]);
            }
        }
        ++t;
    }

    int ans = INF;
    for(int i=0; i<=4; i++){
        for(int j=i; j<=4; j++){
            ans = min(ans, dp[t-1][i][j]);
        }
    }
    cout << ans;

    
    
    return 0;
}