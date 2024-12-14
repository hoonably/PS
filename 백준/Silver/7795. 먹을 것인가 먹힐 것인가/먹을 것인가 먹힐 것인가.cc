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

void solve(){
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];
    sort(all(A));
    sort(all(B));
    int ans = 0;
    for(int i=0; i<N; i++){
        int idx = lower_bound(all(B), A[i]) - B.begin();
        ans += idx;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    while(T--) solve();
    
    return 0;
}