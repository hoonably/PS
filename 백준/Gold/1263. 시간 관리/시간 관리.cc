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
vector<pii> A;

bool cmp(pii a, pii b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++) cin >> A[i].second >> A[i].first;

    sort(all(A), cmp);  // 끝나는 시간이 늦은 순으로 정렬

    int ans = A[0].first;
    for(int i=0; i<N; i++){
        // cout << A[i].first << " " << A[i].second << "\n";
        ans = min(ans, A[i].first);
        ans -= A[i].second;
    }
    
    ans>=0 ? cout << ans : cout << -1;

    
    return 0;
}