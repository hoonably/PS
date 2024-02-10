#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    while (true){
        int N;
        cin >> N;
        if (N==-1) break;
        vector<int> divisors = getDivisors(N);
        sort(divisors.begin(), divisors.end());
        divisors.pop_back();

        // 벡터 요소 합 accumulate
        int sum = accumulate(divisors.begin(), divisors.end(), 0);
        if (sum == N){
            cout << N << " = ";

            for (int i=0; i<divisors.size()-1; i++){
                cout << divisors[i] << " + ";
            }
            cout << divisors[divisors.size()-1] << '\n';
        }
        else cout << N << " is NOT perfect.\n";
    }

    return 0;
}
