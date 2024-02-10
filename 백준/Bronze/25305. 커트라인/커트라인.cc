#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	int list[1000];
	cin >> N >> M;

	for ( int i = 0; i < N; i++) {
		cin >> list[i];
	}

	sort(list, list+N);
	cout << list[N-M] << endl;
}