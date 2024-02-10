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
    // 사용자로부터 숫자 입력 받기
    int M, N, sum = 0, min;
    cin >> M >> N;

    // 10000 이하의 자연수가 각각 소수인지 나타내는 bool 배열 얻어오기
    vector<bool> isPrime = findPrimes(10000);

    for (int i=M; i<=N; i++){
        if (isPrime[i]) sum+=i;
    }

    // 소수가 없는 경우
    if (sum==0) {cout << -1; return 0;}
    cout << sum << endl;

    // 최소 소수 출력 후 break
    for (int i=M; i<=N; i++){
        if (isPrime[i]) {cout << i; break;}
    }

    return 0;
}

