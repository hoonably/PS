#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/13976

https://memoacmicpc.tistory.com/entry/%EB%B0%B1%EC%A4%80-13976%EB%B2%88-%ED%83%80%EC%9D%BC-%EC%B1%84%EC%9A%B0%EA%B8%B0-2

2칸으로 채우는 경우 : 3가지
ㅣㅣ   ㅡ   ㅡ
 ㅡ   ㅣㅣ  ㅡ
          ㅡ

4칸으로 채우는 경우 : 2가지 (2칸 + 2칸 누적 미포함)

6칸으로 채우는 경우 : 2가지 (누적 미포함)

바로 이전 경우에 두개 더 채우면 되니까 (이전 *3) 을 더한다.
그 전 (모든 경우 * 2) 를 더한다.
새로 만들어서 한번에 칸을 채우는 경우 (+2)를 더한다.

dp[N+2] = 3*dp[N] + (2*dp[N-2] + 2*dp[N-6] ... + 2*dp[2]) + 2

dp[N] = 3*dp[N-2] + (2*dp[N-4] + 2*dp[N-6] ... + 2*dp[2]) + 2

=> 윗식에서 아래식을 빼면!!

dp[N+2] - dp[N] = 3*dp[N] - dp[N-2]

dp[N+2] = 4*dp[N] - dp[N-2]

행렬을 통한 풀이
[dp[x+2]]  = [4 -1] [dp[x]]
[ dp[x] ]    [1  0] [dp[x-2]]

제곱 연산
[dp[N+2]]  = [4 -1] N/2 [3]
[ dp[N] ]    [1  0]     [1]
*/

#define MAX 

// 2차원 벡터를 matrix라고 호칭
using matrix = vector<vector<ll>>;

matrix operator*(matrix &A, matrix &B) {
    int s1 = A.size();
    int s2 = B.size();
    int s3 = B[0].size();

    // s1 * s3 벡터 생성
    matrix temp(s1, vector<ll>(s3, 0));

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < s3; j++) {
            for (int k = 0; k < s2; k++) {
                temp[i][j] += A[i][k] * B[k][j];
                temp[i][j] %= MOD;
            }
            temp[i][j] = (temp[i][j]+MOD) % MOD;  // 음수 모듈러 연산 방지
        }
    }
    return temp;
}

// 행렬 A의 b제곱 분할정복
matrix power(matrix& A, ll b) {
    if (b == 1) return A;
    if (b == 2) return A*A;

    // 반제곱 계산
    matrix temp = power(A, b / 2);

    // 홀수 승 : A 한번만 따로 곱해줌
    if (b % 2 == 1) {
        temp = temp * temp;
        return temp * A;
    }
    // 짝수승 : 깔끔하게 반으로 나누면 됨
    else {
        return temp * temp;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll N;
    cin >> N;

    // 홀수개의 타일은 절대 채울 수 없음
    if (N%2==1) {
        cout << "0";
        return 0;
    }

    // [dp[N+2]]  = [4 -1] N/2 [3]
    // [ dp[N] ]    [1  0]     [1]

    matrix base = { {{4,-1}, {1,0}} };
    matrix ans = { {3},{1} };
    
    base = power(base, N/2);
    ans = base * ans;

    // cout << ans[0][0];  // 이건 N+2 항
    cout << ans[1][0];  // 이게 N항

    return 0;
}