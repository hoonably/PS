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

vector<ll> factorial = {1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll N;
    cin >> N;

    if (N==0) {
        cout << "NO";
        return 0;
    }
    
    ll now = 1;
    for(int i=1; ; i++){
        now *= i;
        if (now > N) break;
        factorial.emplace_back(now);
    }

    int idx = factorial.size();
    while(idx){
        ll now = factorial[--idx];
        if (N>=now) N-=now;
    }
    if(N==0) cout << "YES";
    else cout << "NO";


    
    return 0;
}