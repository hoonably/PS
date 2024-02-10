#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> v;
	int N;
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
        // v.push_back({ x, y }); 랑 같음
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}