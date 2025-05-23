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

int gcd(int a, int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve(){
    int m; cin >> m;
    vector<int> v(m);
    for(int i=0; i<m; i++) cin >> v[i];
    ll ans = 0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            ans += gcd(v[i], v[j]);
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    while(n--){
        solve();
    }
    
    return 0;
}