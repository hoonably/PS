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
typedef unsigned long long ull;

ull pow(ull a, ull b, ull mod){  // (a^b)%mod
    ull ret = 1;
    a %= mod;
    while (b){
        if (b%2 == 1) ret = ret*a %mod;
        b /= 2;
        a = a*a %mod;
    }
    return ret;
}
bool miller_rabin(ull n, int a){
    if (a%n == 0) return true;
    ull d = n - 1;
    while(1) {
        ull temp = pow(a, d, n);
        if(temp == n-1) return true;
        if(d%2 == 1) return (temp == 1 || temp == n-1);
        d /= 2;
    }
}
int a_list[] = {2, 7, 61};  // int 범위
// int a_list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};  // long long 범위
bool isPrime(ull n){
    for (int a : a_list){
        if (!miller_rabin(n, a)) return false;
    }
    return true;
}

int N, cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    while(N--){
        ull area;
        cin >> area;
        if (isPrime(2*area+1)) cnt++;
    }
    cout << cnt;
    
    return 0;
}