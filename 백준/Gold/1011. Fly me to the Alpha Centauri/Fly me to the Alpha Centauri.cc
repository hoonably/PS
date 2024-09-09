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
https://www.acmicpc.net/problem/1011

제곱근 <= 반올림값일 경우, 2*반올림 - 1
제곱근 > 반올림값일 경우 2*반올림 
*/

#define MAX 

void solve(){
    ll x,y;
    ll move, max = 0;
    cin >> x >> y;

    // y-x를 이하의 제곱수 찾기
    while(max*max <= y-x)
        max++;
    max--;

    move = 2 * max -1;
    ll rem = y-x - max * max;
    rem = ceil((double)rem / (double)max);
    move += rem;
    
    cout << move << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}