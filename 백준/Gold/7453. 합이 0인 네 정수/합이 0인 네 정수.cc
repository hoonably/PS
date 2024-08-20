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

#define MAX 4000

int n;
int A[MAX], B[MAX], C[MAX], D[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> sumAB, sumCD;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            sumAB.emplace_back(A[i]+B[j]);
            sumCD.emplace_back(C[i]+D[j]);
        }
    }

    sort(all(sumAB));
    sort(all(sumCD));

    ll ans = 0;
    for(int i=0; i<sumAB.size(); i++){
        int f = -sumAB[i];
        ans += upper_bound(all(sumCD), f) - lower_bound(all(sumCD), f);
    }
    cout << ans;

    
    return 0;
}