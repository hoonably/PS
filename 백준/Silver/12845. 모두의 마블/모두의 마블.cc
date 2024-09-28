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

int L[1000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> L[i];
    int maxi = 0;
    for(int i=0; i<n; i++) maxi = max(maxi, L[i]);

    int ans = accumulate(L, L+n, 0) - maxi;
    ans += maxi * (n-1);
    cout << ans;
    
    return 0;
}