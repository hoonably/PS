#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 제곱근을 사용하여 약수들을 리턴하는 함수
vector<int> getDivisors(int n) {
    vector<int> divisors;

    int i=1;
    while (i * i < n){
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
        i++;
    }
    // 제곱수인경우 중복하지 않도록 하나만 추가
    if (i*i == n) divisors.push_back(i);
    
    return divisors;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> divisors = getDivisors(N);
    sort(divisors.begin(), divisors.end());

    if (K>divisors.size()) cout << 0;
    else cout << divisors[K-1];

    return 0;
}
