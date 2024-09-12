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

#define MAX 1000

int square[MAX];

bool cmp(int a, int b){
    return a >= b;
}

void solve(){
    int J, N;
    cin >> J >> N;
    for(int i=0; i<N; i++){
        int R, C;
        cin >> R >> C;
        square[i] = R*C;
    }
    sort(square, square+N, cmp);
    
    for(int i=0; i<N; i++){
        J -= square[i];
        if (J<=0) {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << N << '\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve();
    
    return 0;
}