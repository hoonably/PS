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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    string sN = to_string(N);
    int len = sN.size();
    
    int ans = 0;
    for(int i=1; i<len; i++){
        ans += i * (9 * pow(10, i-1));
    }
    ans += len * (N - pow(10, len-1) + 1);
    cout << ans;
    
    return 0;
}