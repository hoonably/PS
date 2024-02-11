#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int result = 1, tmp = 1;
        cin >> N >> M;
        // nCr을 구현한 코드
        for (int i = M; i > M - N; i--) {
            result = result * i;
            result = result / tmp++;
        }
        cout << result << "\n";
    }

    return 0;
}