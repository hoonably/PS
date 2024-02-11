#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

vector<bool> Eratos(int N) {

    // 소수 여부를 나타내는 배열
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;  // 0은 소수가 아님 (실수 방지)
    isPrime[1] = false;  // 1은 소수가 아님

    // 에라토스테네스의 체 알고리즘 적용
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

// n 까지의 소수 벡터 만들기
void make_vector_prime(int n, vector<bool> isPrime) {
	for (int i = 2; i <= n; ++i)
		if (isPrime[i]) primes.push_back(i);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 1000000 이하의 자연수가 각각 소수인지 나타내는 bool 배열 얻어오기
    vector<bool> isPrime = Eratos(1000000);
    make_vector_prime(1000000, isPrime);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin>>n;
        int cnt=0;
        for(int x:primes){
            if (x>n-x) break;
            if (isPrime[n-x] == 1) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}

