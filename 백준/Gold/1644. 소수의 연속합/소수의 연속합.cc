#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

vector<int> primes;

void eratos(int n) {
    vector<bool> isPrime(n + 1, true);
    
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    // 1일때 예외처리
    if (N==1) {
        cout << 0;
        exit(0);
    }

    eratos(N);

    int s=0, e=0;
    int sum = 0;
    int cnt = 0;

    while(e < primes.size()){
        if (sum == N) {
            cnt++;
            sum -= primes[s++];
        }
        else if (sum > N) {
            sum -= primes[s++];
        }
        else {
            sum += primes[e++];
        }
    }
    // 본인이 소수인 경우 (따로 해주면 시간 좀 빨라짐)
    if (N==primes.back()) cnt++;

    cout << cnt;
    
    return 0;
}