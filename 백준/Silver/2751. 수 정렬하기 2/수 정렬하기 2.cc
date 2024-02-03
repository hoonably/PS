#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {


	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int>arr;

	for (int i = 0; i < n; i++) {

		int a;
		cin >> a;
		arr.push_back(a);

	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {

		cout << arr[i] << '\n';

	}
}