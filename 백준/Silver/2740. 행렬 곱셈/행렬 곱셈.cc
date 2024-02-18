#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
행렬의 곱셈이다.

*/

int A[100][100], B[100][100], C[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M;

    // Input matrix A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> M >> K;

    // Input matrix B
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> B[i][j];
        }
    }

    // Matrix multiplication
    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < K; ++k) {
            for (int m = 0; m < M; ++m) {
                C[n][k] += A[n][m] * B[m][k];
            }
        }
    }

    // Output
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
