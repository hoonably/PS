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

int N;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    int mini = 1e9;
    int now;
    for(int i=0; i<N; i++){
        cin >> now;
        mini = min(mini, now);
        ans = max(ans, now-mini);
        cout << ans << ' ';
    }
    
    return 0;
}