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

bool is_prime[10001];

vector<int> eratos(int n){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> primes = eratos(10000);
    
    int T; cin >> T;
    while(T--){
        int n;
        cin >> n;

        int ans = 0;
        for(int a : primes){
            if (a > n/2) break;
            if(is_prime[n-a]){
                ans = a;
            }
        }
        cout << ans << ' ' << n-ans << '\n';
    }
    
    return 0;
}