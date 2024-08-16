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
https://www.acmicpc.net/problem/15718

모듈로인 100007은 소수가 아니기 때문에 뤼카의 정리를 직접적으로 이용할 수는 없습니다.
100007 = 97 * 1031

뤼카의 정리를 이용해서 (n-1)C(m-2) % 97과 (n-1)C(m-2) % 1031
*/

#define MAX 

const ll MOD = 100007;  // 97 * 1031
const ll MOD1 = 97, MOD2 = 1031;

ll pow(ll x, ll y, ll p){  // (x^y) % p
    ll ret = 1, piv = x % p;
    while(y){
        if(y&1) ret = ret * piv % p;
        piv = piv * piv % p;
        y >>= 1;
    }
    return ret;
}

ll nCr(ll N, ll M, ll mod) {
    if(N < M) return 0;
    
    ll num = 1, den = 1;
    for(ll i=1; i<=N; i++) num  = num * i % mod;
    for(ll i=1; i<=M; i++) den = den * i % mod;
    for(ll i=1; i<=N-M; i++) den = den * i % mod;
    ll inv = pow(den, mod-2, mod);
    return num * inv % mod;
}

ll lucas(ll N, ll M, ll mod) {
    vector<ll> Ns, Ms;
    while(N || M)
    {
        Ns.push_back(N%mod), N/=mod;
        Ms.push_back(M%mod), M/=mod;
    }
    
    ll ret = 1;
    for(int i=0; i<Ns.size(); i++) {
        ret *= nCr(Ns[i], Ms[i], mod);
        ret %= mod;
    }
    return ret;
}

int solve(){
    ll N, M;
    cin >> N >> M;

    // 0세로 생을 마감
    if (N==0){
        if(M==1) return 1;  // 하나도 안먹고 첫째날에 죽음
        else return 0;  // 두살 이후까지 살 수 없음
    }

    // 0세가 아닌데 1일에 생 마감은 불가능
    if (M==1) return 0;

    // (n-1)C(m-2) % 97과 (n-1)C(m-2) % 1031
    return ((lucas(N-1, M-2, MOD1)*MOD2 * pow(MOD2, MOD1-2, MOD1))%MOD
        +(lucas(N-1, M-2, MOD2)*MOD1 * pow(MOD1, MOD2-2, MOD2))%MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) cout << solve() << '\n';
    
    return 0;
}