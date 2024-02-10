#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    vector<pair<int, int>> v;
	int N;
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		// v.push_back(make_pair(x, y));
        v.push_back({ y, x });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second << ' ' << v[i].first << '\n';
	}
	return 0;
}