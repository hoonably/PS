#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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
https://www.acmicpc.net/problem/12850

logN 시간복잡도로 풀어야 하므로 행렬의 거듭제곱 연산 진행

0 : 정보과학관
1 : 전산관
2 : 신앙관
3 : 미래관
4 : 진리관
5 : 환경직기념관
6 : 학생회관
7 : 형남공학관
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

int D;

// temp[0] = dp[1] + dp[3];
// temp[1] = dp[0] + dp[2] + dp[3];
// temp[2] = dp[1] + dp[3] + dp[4] + dp[5];
// temp[3] = dp[0] + dp[1] + dp[2] + dp[5];
// temp[4] = dp[2] + dp[5] + dp[6];
// temp[5] = dp[2] + dp[3] + dp[4] + dp[7];
// temp[6] = dp[4] + dp[7];
// temp[7] = dp[5] + dp[6];

matrix v = {
    {0, 1, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {1, 1, 1, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    cin >> D;

    v = power(v, D);

    cout << v[0][0];
    
    return 0;
}