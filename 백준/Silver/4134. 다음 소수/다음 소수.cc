#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

// 소수 판별
bool isPrime(unsigned int n) {

    if (n<2) return false;

	int sqrtn = sqrt(n); // 제곱근까지만 보기

    // 구해져있는 소수들로 소수가 맞는지 판단
	for (auto p : primes)
		if (p <= sqrtn && (n % p) == 0)
			return false;

	return true;
}

// 소수 벡터 만들기
void precalcul_prime() {
	for (int i = 2; i < 63246; ++i)
		if (isPrime(i)){
			primes.push_back(i);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precalcul_prime();  // 미리 소수 벡터 만들기

    int T;
    unsigned int n;
    cin >> T;
    while (T--){
        cin >> n;
        while (!isPrime(n)) ++n;  // 소수가 맞을때까지 n 증가시키기
        cout << n << '\n';
    }

    return 0;
}

