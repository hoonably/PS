#include <bits/stdc++.h>
using namespace std;

int S[13];
int lotto[6];
int k;

//start는 S의 인덱스, depth는 lotto의 인덱스 
void getCombi(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << '\n';
		return;
	}
	//start부터
	for (int i = start; i < k; i++) {
		lotto[depth] = S[i];
		getCombi(i+1, depth+1);
	}
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}
		getCombi(0, 0);
        cout << '\n';
	}
}