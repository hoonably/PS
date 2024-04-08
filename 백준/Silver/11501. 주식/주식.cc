#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX 1000001

/*
- 주식 하나를 산다.
- 원하는 만큼 가지고 있는 주식을 판다.
- 아무것도 안한다.
*/

ll price[MAX];

void solve(){
    int N;
    cin >> N;
    vector<int> v;

    for(int i=0;i<N;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    ll ans = 0;
    int max_value = -1;

    // 뒤에서부터
    for(int i=N-1; i>=0; i--) {
        max_value = max(max_value, v[i]);
        ans += max_value - v[i];
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}