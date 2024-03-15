#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1'000'000'007
#define MAX

/*
a^(-1) × a ≡ 1(mod X) 일 때, a^(X - 2) ≡ a^(-1) (mod X) 이다.

즉, 임의의 소수 X에 대한 b의 모듈러 곱셈에 대한 역원은 a^(X - 2) 이다.
*/

// a의 b제곱을 MOD로 나눈 나머지
ll power(ll a, ll b){

    if (b==1) return a % MOD;

    if (b%2==0){
        ll temp = power(a, b/2);
        return temp * temp % MOD;
    }
    else {
        return power(a, b-1) * a % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int M;
    cin >> M;

    ll ans = 0;
    while(M--){
        int b, a;
        cin >> b >> a;

        // b의 모듈러 곱셈에 대한 역원 : b^(MOD-2)
        ans += (a * power(b, MOD-2)) % MOD;
        ans %= MOD;
    }

    cout << ans;
    
    return 0;
}