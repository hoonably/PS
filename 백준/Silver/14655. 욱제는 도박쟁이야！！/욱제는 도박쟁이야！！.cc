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

*/

#define MAX 



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    vector<int> a(N), b(N);

    // 양끝은 하나 또는 두개만 뒤집을 수 있기 때문에 인덱스 2부터 받기
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];

    int ans = 0;
    for(int i=0; i<N; i++) {
        if (a[i]>0) ans+=a[i];
        else ans-=a[i];
    }
    for(int i=0; i<N; i++) {
        if (b[i]>0) ans+=b[i];
        else ans-=b[i];
    }
    cout << ans;

    
    return 0;
}