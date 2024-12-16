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

int k;
vector<int> input;
vector<int> arr[10];
void insertTree(int depth,int start, int end) {
	
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	arr[depth].push_back(input[mid]);
	insertTree(depth + 1, start, mid);
	insertTree(depth + 1, mid+1, end);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k;
	
    int len = 1 << k;
    input.resize(len);

    int idx = 0;
	for (int i = 1; i < len; i++) cin >> input[i];

	insertTree(0,0,len);
	for (int i = 0; i < k; i++) {
		for (int o : arr[i]) {
			cout << o << ' ';
		}
		cout << '\n';
	}
    
    return 0;
}