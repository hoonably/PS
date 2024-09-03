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

int N;
vector<ll> t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    t.resize(N);
    for(ll &i : t) cin >> i;

    if (N%2) N++, t.emplace_back(0); // 홀수라면 0 추가해서 짝 맞춰주기

    sort(all(t));

    ll ans = 0;
    for(int i=0; i<N/2; i++){
        ans = max(ans, t[i]+t[N-i-1]);
    }
    cout << ans;

    
    return 0;
}