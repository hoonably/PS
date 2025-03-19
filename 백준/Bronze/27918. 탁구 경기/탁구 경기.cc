#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    int D=0, P=0;
    while(n--){
        char c;
        cin >> c;
        if (c=='D') D++;
        else P++;
        if (D==P+2) break;
        if (P==D+2) break;
    }
    cout << D << ':' << P;
    
    return 0;
}