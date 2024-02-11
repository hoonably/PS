// 에라토스테네스의 체로 N까지 소수가 맞는지 bool 벡터 얻어오기
// O(N^1/2)

#include <iostream>
#include <vector>

using namespace std;

vector<bool> findPrimes(int N) {

    // 소수 여부를 나타내는 배열
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;  // 0은 소수가 아님 (실수 방지)
    isPrime[1] = false;  // 1은 소수가 아님

    // 에라토스테네스의 체 알고리즘 적용
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int m, n;
    cin >> m >> n;
    // n 이하의 자연수가 각각 소수인지 나타내는 bool 배열 얻어오기
    vector<bool> isPrime = findPrimes(n);
    while (m<=n){
        if (isPrime[m]) cout << m << '\n';
		m++;
    }

    return 0;
}