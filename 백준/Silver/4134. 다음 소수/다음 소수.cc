#include <bits/stdc++.h>
using namespace std;

bool isPrime(long N) {

    if (N<2) return false;

    // 에라토스테네스의 체 알고리즘 적용
    for (long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    long n;
    cin >> T;
    while (T--){
        cin >> n;
        while (true){
            if (isPrime(n)){
                cout << n << '\n';
                break;
            }
            n++;
        }
    }

    return 0;
}

