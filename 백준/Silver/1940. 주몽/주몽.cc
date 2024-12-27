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

int N, M;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(all(A));

    int s = 0;
    int e = N-1;
    int cnt = 0;
    while(s < e){
        if (A[s] + A[e] == M) {
            cnt++;
            s++;
        }
        else if (A[s] + A[e] < M) s++;
        else e--;
    }
    cout << cnt;
    
    return 0;
}