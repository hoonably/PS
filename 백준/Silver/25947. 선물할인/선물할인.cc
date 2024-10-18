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

ll n, b, a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> b >> a;
    vector<ll> gift(n);
    for(ll &i : gift) cin >> i;
    sort(all(gift));

    b *= 2;
    ll sum = 0;
    for(int idx=0; idx<a; idx++){
        sum += gift[idx];
        if (sum > b) {
            cout << idx;
            return 0;
        }
    }

    for(int idx=a; idx<n; idx++){
        sum += gift[idx] + gift[idx-a];
        if (sum > b) {
            cout << idx;
            return 0;
        }
    }
    cout << n;
    
    return 0;
}