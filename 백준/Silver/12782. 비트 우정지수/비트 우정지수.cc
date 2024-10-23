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
0과 1의 개수를 맞춘 후 위치 변경
*/

#define MAX 



void solve(){
    string N, M;
    cin >> N >> M;

    int cntN = 0, cntM = 0;
    for(char c : N) if(c=='1') cntN++;
    for(char c : M) if(c=='1') cntM++;

    int diff = 0;
    int ans = abs(cntN-cntM);
    for(int i=0; i<N.size(); i++) if (M[i]!=N[i]) diff++;
    diff -= ans;  // 1의 개수 차이만큼 빼줌
    ans += (diff+1)/2;
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    while(T--) solve();

    return 0;
}