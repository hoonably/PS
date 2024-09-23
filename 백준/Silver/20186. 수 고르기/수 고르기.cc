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
    
    int n, k; cin >> n >> k;
	vector<int> v(n);
	for (auto& i : v) cin >> i;
	sort(all(v));
    // accumulate: v.end() - k ~ v.end() 까지의 합
    // k * (k - 1) / 2: 1 ~ k 까지의 합
    // 두 값의 차이가 답
	cout << accumulate(v.end() - k, v.end(), 0) - k * (k - 1) / 2 << '\n';
    
    return 0;
}