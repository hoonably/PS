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
https://www.acmicpc.net/problem/5615

밀러 라빈 소수 판별법
int 범위 : a = 2, 7, 61
long long 범위 : a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37

2xy + x + y = area
4xy + 2x + 2y + 1 = 2area + 1,
(2x+1)(2y+1) = 2area + 1
2area + 1이 소수이면, (2x+1), (2y+1)이 각각 1, 2area + 1이기 때문에 존재할 수 없는 면적
*/

#define MAX 

namespace miller_rabin{
    ll mul(ll x, ll y, ll mod){ return (__int128) x * y % mod; }
	ll ipow(ll x, ll y, ll p){
		ll ret = 1, piv = x % p;
		while(y){
			if(y&1) ret = mul(ret, piv, p);
			piv = mul(piv, piv, p);
			y >>= 1;
		}
		return ret;
	}
	bool miller_rabin(ll x, ll a){
		if(x % a == 0) return 0;
		ll d = x - 1;
		while(1){
			ll tmp = ipow(a, d, x);
			if(d&1) return (tmp != 1 && tmp != x-1);
			else if(tmp == x-1) return 0;
			d >>= 1;
		}
	}
	bool isprime(ll x){
		for(auto &i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
			if(x == i) return 1;
			if(x > 40 && miller_rabin(x, i)) return 0;
		}
		if(x <= 40) return 0;
		return 1;
	}
}

namespace pollard_rho{
	ll f(ll x, ll n, ll c){
		return (c + miller_rabin::mul(x, x, n)) % n;
	}
	void rec(ll n, vector<ll> &v){
		if(n == 1) return;
		if(n % 2 == 0){
			v.push_back(2);
			rec(n/2, v);
			return;
		}
		if(miller_rabin::isprime(n)){
			v.push_back(n);
			return;
		}
		ll a, b, c;
		while(1){
			a = rand() % (n-2) + 2;
			b = a;
			c = rand() % 20 + 1;
			do{
				a = f(a, n, c);
				b = f(f(b, n, c), n, c);
			}while(gcd(abs(a-b), n) == 1);
			if(a != b) break;
		}
		ll x = gcd(abs(a-b), n);
		rec(x, v);
		rec(n/x, v);
	}
	vector<ll> factorize(ll n){
		vector<ll> ret;
		rec(n, ret);
		return ret;
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> ans = pollard_rho::factorize(N);
    
    sort(all(ans));
    for(ll a : ans) cout << a << "\n";
    
    return 0;
}