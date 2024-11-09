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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int C; cin >> C;
    cout << fixed; cout.precision(4);
    while(C--){
        int N; cin >> N;
        vector<int> v(N);
        for(int i=0; i<N; i++) cin >> v[i];
        double avg = accumulate(all(v), 0.0) / N;
        sort(all(v));

        int cnt = 0;
        while(cnt < N){
            if(v[cnt] > avg) break;
            cnt++;
        }
        cout << 100.0 * (N-cnt) / N << "%\n";
    }
    
    return 0;
}