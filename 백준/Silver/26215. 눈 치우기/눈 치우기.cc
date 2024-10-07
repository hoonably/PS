#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;\
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int N;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    int m = 0, sum = 0;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        m = max(m, a);
        sum += a;
    }

    int ans;
    if (sum <= 2*m) ans = m;
    else ans = sum/2 + (sum-2*m)%2;

    ans > 1440 ? cout << "-1" : cout << ans;
    
    return 0;
}


