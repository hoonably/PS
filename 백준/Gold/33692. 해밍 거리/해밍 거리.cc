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

long long pow_fast(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll A, B;
    cin >> A >> B;

    // 2^60 >1018
    bitset<60> a(A);
    bitset<60> b(B);

    // 바뀌는 지점부터만 생각하면 됨.
    // 바뀌는 지점에 A는 0, B는 1임 무조건
    
    // A는 011111111
    // B는 100000000
    // 이러면 무조건 최대 해밍 거리
    int idx = 59;
    for(; idx>=0; idx--){
        if (b[idx]!=a[idx]){
            break;
        }
    }

    // idx번까지 그대로 + 그 이후부터 A는 모두 1, B는 모두 0
    // B만 구하고 A = B-1
    // B도 쉽게 구할 수 있음.
    // 2^idx으로 나눈 나머지 빼면 됨
    B = B - (B % pow_fast(2,idx));

    cout << B-1 << '\n' << B;
    
    
    return 0;
}