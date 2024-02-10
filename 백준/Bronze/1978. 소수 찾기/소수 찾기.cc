// 에라토스테네스의 체로 1000까지의 소수 벡터를 만든 후 안에 있는지 확인
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
    // 사용자로부터 숫자 입력 받기
    int N, cnt = 0;
    cin >> N;

    // 1000 이하의 자연수가 각각 소수인지 나타내는 bool 배열 얻어오기
    vector<bool> isPrime = findPrimes(1000);

    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        if (isPrime[num]) cnt++;
    }
    cout << cnt;

    return 0;
}

