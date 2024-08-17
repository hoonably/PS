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
https://www.acmicpc.net/problem/13713

Z 알고리즘

s를 뒤집은 뒤 Z 배열을 O(n)에 구하고, 
t에 대한 쿼리마다 Z[n - t]를 출력
*/

#define MAX 

vector<int> Z_function(const string& S, int len) {
	int l = -1, r = -1;
	vector<int> Z(len);
	Z[0] = len;

	for (int i = 1; i < len; i++) {
		// i <= r이라면 Z[i] = min(r - i + 1, Z[i - l])로 초기화
		if (i <= r) Z[i] = min(r - i + 1, Z[i - l]);

		// naive하게 Z[i] 구하기
		while (i + Z[i] < len && S[Z[i]] == S[i + Z[i]]) Z[i]++;
		// l, r 갱신
		if (r < i + Z[i] - 1) l = i, r = i + Z[i] - 1;
	}
	return Z;
}

string S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> S;
	int len = S.size();
    reverse(all(S));

    auto Z = Z_function(S, len);

    int M; cin >> M;
    while(M--){
		int i; cin >> i;
		cout << Z[len - i] << '\n';
	}

    return 0;
}