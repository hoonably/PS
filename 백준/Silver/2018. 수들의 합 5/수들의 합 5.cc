#include <bits/stdc++.h>
#define all(v) v.begin(), v.e()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

vector<int> S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int ans = 0;
    for(int s = 1; s <= N; s++){
        int sum = s;
        for(int e = s + 1; e <= N; e++){
            sum += e;
            if(sum == N){
                ans++;
                break;
            }
            else if(sum > N){
                break;
            }
        }
    }
    ans++;
    cout << ans;
    
    return 0;
}