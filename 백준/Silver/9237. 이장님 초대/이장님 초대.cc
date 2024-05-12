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

#define MAX 100'001

int n;
int t[MAX];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    FOR(i,1,n+1){
        cin >> t[i];
    }
    sort(t+1, t+n+1, cmp);

    int ans = 0;
    FOR(i,1,n+1){
        ans = max(ans, t[i]+i);
    }
    cout << ans+1;
    
    return 0;
}