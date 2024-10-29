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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    vector<pii> v(N);
    for(pii &i : v){
        cin >> i.first >> i.second;
    }
    sort(all(v));

    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(pii i : v){
        while (!pq.empty() && pq.top() <= i.first) pq.pop();
        pq.push(i.second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    
    return 0;
}