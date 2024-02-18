#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000

/*
행렬의 곱셈이다.

*/

// 2차원 벡터를 matrix라고 호칭
using matrix = vector<vector<int>>;

int N;
ll B;

matrix matrix_mult(matrix mat1, matrix mat2)
{
    // N * N 벡터 생성
    matrix temp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
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
    // 짝수승 : 깔끔하게 반으로 나누면 됨
    else {
        return matrix_mult(temp, temp);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    // N*N 배열 생성
    matrix A(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            A[i][j] %= 1000;  // 1제곱일때 문제가 생길 수 있음
        }
    }

    A = power(A, B);

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}