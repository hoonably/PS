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
    
    int N, P;
    cin >> P >> N;

    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    sort(all(v));

    int ans = 0;
    for(int i=0; i<N; i++){
        if (P>=200) break;
        P += v[i];
        ans++;
    }
    cout << ans;
    
    return 0;
}