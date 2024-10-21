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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    ll ans = 0;
    int h;
    for(int i=0; i<n; i++) {
        cin >> h;
        ans += h;
    }
    vector<int> trees(n);
    for(int &t : trees) cin >> t;
    sort(all(trees));

    for(int i=0; i<n; i++) {
        ans += trees[i] * i;
    }
    cout << ans;

    return 0;
}