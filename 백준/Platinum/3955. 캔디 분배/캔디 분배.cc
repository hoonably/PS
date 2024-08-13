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

 K * X + 1 = 1 mod K 이므로 결국 A봉지 준비한다면 C * A = 1 mod K 와 동일
 그러므로 유클리드 알고리즘으로 C^-1 mod K를 구하면 된다.
*/

#define MAX 

ll K, C;

// ax+by=gcd(C,b) 가 되는 x, y 를 구함
pii ext_gcd(int C,int b){
    if(b){
        pii tmp = ext_gcd(b, C%b);
        return pii(tmp.second, tmp.first - (C/b) * tmp.second);
    } else return pii(1, 0);
}

void solve(){
    cin >> K >> C;

    if(gcd(C,K)!=1){
		cout << "IMPOSSIBLE\n";
		return;
	}

    // Cx = 1 (mod K) 를 구하는 문제이지만 사탕을 K명에게 나누어주려면 Cx > K
    ll ans = (ext_gcd(C, K).first + K) % K;
    while(C*ans <= K) ans += K;
    if (ans > 1e9) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}