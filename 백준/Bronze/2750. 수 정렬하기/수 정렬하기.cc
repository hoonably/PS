#include <iostream>
#include <algorithm>
using namespace std;

int num[1000]; 

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

    // sort(시작 배열 주소, 끝 배열 주소)
	sort(num, num + N);

	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}

	return 0;
}