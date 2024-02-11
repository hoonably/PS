#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

// 소수 판별
bool isPrime(int n) {

    if (n<2) return false;

	int sqrtn = sqrt(n); // 제곱근까지만 보기

    // 구해져있는 소수들로 소수가 맞는지 판단
	for (auto p : primes)
		if (p <= sqrtn && (n % p) == 0)
			return false;

	return true;
}

// n 까지의 소수 벡터 만들기
void precalcul_prime(int n) {
	for (int i = 2; i <= n; ++i)
		if (isPrime(i)){
			primes.push_back(i);
        }
}


// 이진탐색
int* lower_bound(int *arr, int *end, const int& key) {
    int l = 0, r = (int)(end - arr) - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < key) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return arr + l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int M, N;
	cin >> M >> N;
    precalcul_prime(N);  // 미리 소수 벡터 만들기

	// M 이상 첫 소수의 주소
	auto start = lower_bound(primes.begin(), primes.end(), M);

	for (auto i = start; i<primes.end(); i++) cout << *i << '\n';

    return 0;
}
