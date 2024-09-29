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
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    int max_num = -1;
    int ans = 0;
    for(int i=N-1; i>=0; i--){
        if(v[i] > max_num){
            max_num = v[i];
        }
        ans = max(ans, max_num - v[i]);
    }
    cout<<ans;
    
    return 0;
}