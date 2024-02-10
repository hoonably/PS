#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, get_int;
    string get_str;
    string poketmon[100000];
    map<string, int> map_p;
    
    cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> poketmon[i];
		map_p.insert(make_pair(poketmon[i], i));
	}

	for (int i = 0; i < M; i++) {
		cin >> get_str;

		// 1. 입력된 것이 숫자인 경우
		if (isdigit(get_str[0])) {
			get_int = stoi(get_str);
			cout << poketmon[get_int] << "\n";
		}

		// 2. 입력된 것이 문자인 경우
		else {
			auto index = map_p.find(get_str);
			cout << index->second << "\n";
		}
	}

    return 0;
}