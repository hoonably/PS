#include <bits/stdc++.h>
using namespace std;

/*
Combination 을 모두 출력하는 함수인데 중복 가능
*/

int n, m;
int res[9];

// 마지막으로 넣은 start를 사용하여 start 이후의 수만 넣는다.
void permutation(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        res[depth] = i;
        permutation(depth + 1, i);  // 다음 단계
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    permutation(0, 1);

    return 0;
}