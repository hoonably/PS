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

#define MAX 10'001

int N;
int rock[MAX];
int l, r;
int coin[] = {100, 50, 20, 10, 5, 2, 1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    cin >> l;
    cin >> r;

    int newRock;
    for(int i=2; i<N; i++){
        cin >> newRock;
        
        if (l <= r) l += newRock;
        else r += newRock;
    }

    int diff = max(l, r) - min(l, r);
    int idx = 0;
    int ans = 0;
    while(diff!=0){
        if (diff>=coin[idx]) {
            diff -= coin[idx];
            ans++;
        }
        else idx++;
    }
    cout << ans;
    
    
    return 0;
}