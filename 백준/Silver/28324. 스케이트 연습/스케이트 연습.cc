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
vector<int> V;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];

    ll ans = 0;
    int last = 0;
    for(int i=N-1; i>=0; i--){
        last = min(V[i], last+1);
        ans += last;
    }
    cout << ans;

    
    return 0;
}