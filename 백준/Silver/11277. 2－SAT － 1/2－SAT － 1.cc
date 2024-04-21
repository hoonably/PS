#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*

*/

int N, M;
pair<int, int> clauses[100]; // clause 저장
bool boolean[20]; // x_n의 값

void bt(int k) {
	if (k == N + 1) {
		for (int i = 0;i < M;i++) {
			bool a, b;

			if (clauses[i].first < 0)
				a = !boolean[-clauses[i].first];
			else
				a = boolean[clauses[i].first];

			if (clauses[i].second < 0)
				b = !boolean[-clauses[i].second];
			else
				b = boolean[clauses[i].second];

			if ((a || b) == false) return;
		}
        cout << 1;
        exit(0);
	}

	boolean[k] = true;
	bt(k + 1);

	boolean[k] = false;
	bt(k + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> clauses[i].first >> clauses[i].second;
	}

	bt(1);
	cout << 0;
}