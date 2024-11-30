#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int K;
    cin >> K;
    int a = 1, b = 0;
    for(int i=0; i<K; i++){
        int tmp = a;
        a = b;
        b = tmp + b;
    }
    cout << a << ' ' << b;
    
    return 0;
}