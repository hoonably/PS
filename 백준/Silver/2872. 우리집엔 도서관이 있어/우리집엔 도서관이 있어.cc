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

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
	vector<int> book(n);
	for (int &i : book) cin >> i;

	int cnt = n;
	for (int i = n - 1; i >= 0; i--) {
		if (book[i] == cnt)
			cnt--;
	}
	cout << cnt;

    return 0;
}