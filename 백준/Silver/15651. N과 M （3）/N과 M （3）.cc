#include <bits/stdc++.h>
using namespace std;

/*
nπr 중복순열이므로 visited를 체크할 필요가 없다.
*/

int n, m;
int res[9];

void permutation(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        res[depth] = i;
        permutation(depth + 1);  // 다음 단계
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    permutation(0);

    return 0;
}