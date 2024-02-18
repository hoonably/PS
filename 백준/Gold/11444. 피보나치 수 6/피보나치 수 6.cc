#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
행렬을 이용해야한다.
*/

#define MOD 1000000007;
using matrix = vector<vector<ll>>;

matrix matrix_mult(matrix mat1, matrix mat2)
{
    // N * N 벡터 생성
    matrix temp(mat1.size(), vector<ll>(mat1.size(), 0));

    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat1.size(); j++) {
            for (int k = 0; k < mat1.size(); k++) {
                temp[i][j] += mat1[i][k] * mat2[k][j];
            }
            temp[i][j] %= MOD;
        }
    }
    return temp;
}

// a의 b제곱 분할정복
matrix power(matrix& a, ll b) {
    if (b == 1) return a;
    if (b == 2) return matrix_mult(a, a);

    // 반제곱 계산
    matrix temp = power(a, b / 2);

    // 홀수 승 : a 한번만 따로 곱해줌
    if (b % 2 == 1) {
        temp = matrix_mult(temp, temp);
        return matrix_mult(temp, a);
    }
    // 짝수 승 : 깔끔하게 반으로 나누면 됨
    else {
        return matrix_mult(temp, temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 초기 행렬
    matrix adj = {{1,1}, {1,0}};
    // 피보나치 초기 값
    matrix start = {{1},{1}};

    ll n;
    cin >> n;
    if (n==0) cout << 0;
    else if (n<=2) cout << 1;
    else {
        cout << matrix_mult(power(adj, n-2), start)[0][0];
    }
    
    return 0;
}