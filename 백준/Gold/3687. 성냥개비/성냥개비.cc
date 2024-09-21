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

#define MAX 

int n;
ll dp[101];

int num[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};

void Min_Calculate(){
    for(int i=1; i<9; i++){
        dp[i] = num[i];
    }
    dp[6] = 6;

    for(int i=9; i<101; i++){
        dp[i] = dp[i-2]*10 + num[2];

        for(int j=3; j<8; j++){
            dp[i] = min(dp[i], dp[i-j]*10 + num[j]);
        }
    }
}

void solve(){
    cin >> n;
    // 최소값
    cout << dp[n] << ' ';

    // 최대값
    if (n%2==1){
        n-=3;
        cout << '7';
        for(int i=0; i<n/2; i++) cout << '1';
        cout << '\n';
        return;
    }
    else {
        for(int i=0; i<n/2; i++) cout << '1';
        cout << '\n';
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    Min_Calculate();

    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}