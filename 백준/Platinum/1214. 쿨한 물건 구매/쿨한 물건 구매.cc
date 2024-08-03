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

ll d, p, q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> d >> p >> q;
    if (p < q) swap(p, q);


    ll ret = d / (p * q) * (p * q);
    if(ret > 0) ret -= p * q;
    d -= ret;
    
    ll minNum = 2e9;
    for (ll i = 0; i * p <= d + p; i++)
        minNum = min(minNum, i * p + ((d - p * i + q - 1) / q) * q);

    ret += minNum;

    cout << ret;
    
    return 0;
}