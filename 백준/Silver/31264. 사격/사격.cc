#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a;

bool solve(vector<int> s, ll x) {
	ll score = 0;
	for (int i = 0; i < m; ++i) {
		auto it = lower_bound(s.begin(), s.end(), x);
		int target = (it == s.end() || *it != x) ? *(it-1) : *it;

		score += target, x += target;
		if (score >= a) return true;
	} return score >= a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> a;
	vector<int> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];
	sort(s.begin(), s.end());

	ll st = 0, en = s.end()[-1];
	while (st + 1 < en) {
		ll mid = (st + en) >> 1;
		if (solve(s, mid)) en = mid;
		else st = mid;
	} cout << en;
}