#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b){
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0); 
    cin.tie(0);

	int n; 
    cin >> n;

	vector<pair<int, string>> v;

	for (int i = 0; i < n; i++) {
		int age; 
        string name;
		cin >> age >> name;
		v.push_back(make_pair(age, name));
	}

    // 중요!!!
    // stable_sort : 안정 정렬
    // 순위가 같은 key들을 바꾸지 않고 원래 순서대로 정렬.
	stable_sort(v.begin(), v.end(), compare);

	for (auto x : v) {
        cout << x.first << ' ' << x.second << '\n';
    }
	return 0;
}