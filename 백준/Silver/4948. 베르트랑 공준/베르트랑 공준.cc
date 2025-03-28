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

// 에라토스테네스의 체 (prime sieve)
// 시간복잡도: O(N loglogN)
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    auto s = sieve(250000);
    int n;
    while(cin >> n && n!=0){
        int cnt=0;
        for (int i=n+1; i<=2*n; i++){
            if (s[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}