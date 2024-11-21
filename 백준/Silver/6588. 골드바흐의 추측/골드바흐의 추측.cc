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

int n;
bool isPrime[1000001];
vector<int> primes;

void eratos(int _N){
    fill(isPrime, isPrime+_N+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=_N; i++){
        if(isPrime[i]){
            for(int j=i*2; j<=_N; j+=i){
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3; i<=_N; i+=2){  // odd number
        if(isPrime[i]) primes.push_back(i);
    }
}

void solve(){
    for(int p : primes){
        if(isPrime[n-p]){
            cout << n << " = " << p << " + " << n-p << '\n';
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    eratos(1000000);
    while(true){
        cin >> n;
        if(n == 0) break;
        solve();
    }
    
    return 0;
}