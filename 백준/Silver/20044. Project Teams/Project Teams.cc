#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int n;
int w[10000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for(int i=0; i<2*n; i++){
        cin >> w[i];
    }

    sort(w, w+2*n);

    int ans = INF;
    for (int i=0; i<n; i++){
        ans = min(ans, w[i]+w[2*n-i-1]);
    }
    cout << ans;
    
    return 0;
}