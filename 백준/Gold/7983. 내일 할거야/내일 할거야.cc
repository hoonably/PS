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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    vector<pii> v(n);
    for(pii &i : v){
        cin >> i.second >> i.first;
    }
    sort(all(v), greater<>());

    int now = v[0].first;
    for(int i=0; i<n; i++){
        now = min(now, v[i].first);
        now -= v[i].second;
    }
    cout << now;
    
    return 0;
}