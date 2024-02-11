#include <bits/stdc++.h>
using namespace std;

vector<int> primes; // 소수 벡터

vector<int> findPrimes(int N) {

    // 소수 여부를 나타내는 배열
    vector<int> isPrime(N + 1, -1);
    // -1 : 아직 모르거나 2가 아닌 짝수
    // 0  : 합성수 
    // 1  : 소수

    isPrime[2] = true;  // 2는 유일한 짝수 소수
    primes.emplace_back(2);


    // 에라토스테네스의 체 알고리즘 안씀 (소수 벡터 만들어야하기 때문)
    for (int i = 3; i <= N; i+=2) {

        // 합성수 표기가 안된 홀수라면 소수임
        if (isPrime[i] == -1) {
            isPrime[i] = 1; // 소수 표시
            primes.emplace_back(i); // 소수 벡터에 추가

            // 배수는 모두 합성수 표시
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return isPrime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 1000000 이하의 자연수가 각각 소수인지 나타내는 int 배열 얻어오기
    vector<int> isPrime = findPrimes(1000000);

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

