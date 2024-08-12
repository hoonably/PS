#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int M = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/11402

뤼카(Édouard Lucas)의 정리 
nCk % p (p : 소수) 를 쉽게 구할 수 있는 방법

쉽게, nCk를 M으로 나눈 나머지를 구하기 위해서는
N과 K를 M진 전개해 얻은 각 자릿수의 조합끼리 곱하고 M으로 나누면 된다.
 
ex) N:100 K:45 M:13
100 = 13*7 + 1*9
 45 = 13*3 + 1*6
*/

#define MAX 

ll N, K;
int M;

int nCk(int N, int K){
    // 페르마 소정리를 이용한 nCk를 M로 나눈 수 (M는 소수)
    int A = 1, B = 1;
    for (int i = N; i > N-K; i--)
        A = A * i % M;
	
    for (int i = K; i >= 2; i--)
        B = B * i % M;

    N = 1, K = M-2;
    while (K){
        if (K & 1) N = N * B % M;
        K >>= 1;
        B = B * B % M;
    }
    return A*N %M;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K >> M;

    int res = 1;
    while (N || K){
        res = res * nCk(N%M, K%M) % M;
        N /= M, K /= M;
    }
    cout << res;
    
    return 0;
}