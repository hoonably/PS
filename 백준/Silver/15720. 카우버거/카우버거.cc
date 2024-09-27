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

int b[MAX], c[MAX], d[MAX];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int B, C, D;
    cin >> B >> C >> D;

    
    for(int i=0; i<B; i++){
        cin >> b[i];
    }
    for(int i=0; i<C; i++){
        cin >> c[i];
    }
    for(int i=0; i<D; i++){
        cin >> d[i];
    }

    sort(b, b+B, cmp); sort(c, c+C, cmp); sort(d, d+D, cmp);

    int ans = accumulate(b, b+B, 0) + accumulate(c, c+C, 0) + accumulate(d, d+D, 0);
    cout << ans << '\n';

    // 비싼거 10% 할인
    int mini = min({B, C, D});
    for(int i=0; i<mini; i++){
        ans -= (b[i] + c[i] + d[i]) * 0.1;
    }
    cout << ans << '\n';
    
    return 0;
}