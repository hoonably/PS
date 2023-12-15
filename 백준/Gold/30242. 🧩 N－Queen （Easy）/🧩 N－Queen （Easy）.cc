#include <bits/stdc++.h>
using namespace std;

int N, poss[31][31]{}, Q[31]{}, A[31]{};
bool yes = 0;

void solve(int k) {
	if (k == N + 1) {
		if (!yes) {
			for (int i = 1; i <= N; i++)	cout << A[i] << ' ';
			yes = 1;
		}
		return;
	}
	if (Q[k]) {
		solve(k + 1);
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (poss[k][i])	continue;
		A[k] = i;
		for (int j = k + 1; j <= N; j++) {
			int left = i - abs(j - k);
			int right = i + abs(j - k);
			if (left >= 1)	poss[j][left]++;
			if (right <= N)	poss[j][right]++;
			poss[j][i]++;
		}
		solve(k + 1);
		if (yes)	break;
		for (int j = k + 1; j <= N; j++) {
			int left = i - abs(j - k);
			int right = i + abs(j - k);
			if (left >= 1)	poss[j][left]--;
			if (right <= N)	poss[j][right]--;
			poss[j][i]--;
		}
		A[k] = 0;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		Q[i] = (bool)A[i];
		if (!A[i])	continue;
		for (int j = 1; j <= N; j++) {
			int left = A[i] - abs(j - i);
			int right = A[i] + abs(j - i);
			if (left >= 1)	poss[j][left]++;
			if (right <= N)	poss[j][right]++;
			poss[j][A[i]]++;
		}
	}
	solve(1);
	if (!yes)	cout << -1;
}