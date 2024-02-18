#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
페르마의 소정리

p가 소수, a가 정수일 때
a의 p제곱 ≡ a   (mod p)   

세 줄은 합동기호이고, p로 나눈 나머지가 서로 같다는 뜻이다.

ex) 12의 7승을 7로 나눈 나머지 = > 12를 7로 나눈 나머지



!!! 여기서 이 식의 양 변을 a의 제곱으로 나눠주면 !!!
a의 p-2제곱 ≡ 1/a  (mod p)

이를 통해 나눗셈이었던 것을 곱셈 형태로 변형하면 된다.
nCk = N! / ((N-K)! * K!) % p
nCk = N! * ((N-K)! * K!) ^ (p-2) % p

*/

#define MOD 1000000007
ll N, K;
ll factorial[4000001];

// a의 b제곱을 C로 나눈 나머지
ll power(ll a, ll b){

    if (b==1) return a % MOD;

    if (b%2==0){
        ll temp = power(a, b/2);
        return temp * temp % MOD;
    }
    else {
        return power(a, b-1) * a % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // 여러 테스트케이스이므로 팩토리얼 미리 구해놓기
    factorial[0] = 1;
    for (int i=1; i<=4000000; i++){
        factorial[i] = (factorial[i-1] * i) % MOD;
    }

    int M;
    cin >> M;
    while(M--){
        cin >> N >> K;

        // 조합 nCk = N! / ((N-K)! * K!) % p

        // 분자
        ll top = factorial[N];
        // 분모
        ll bottom = factorial[N - K] * factorial[K] % MOD;

        // 페르마의 소정리 적용
        
        // nCk = N! * ((N-K)! * K!) ^ (p-2) % p
        cout << top * power(bottom, MOD - 2) % MOD << '\n';
    }

    return 0;
}