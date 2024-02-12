#include <bits/stdc++.h>
using namespace std;

/*
Permutation 을 모두 출력하는 함수
순서도 중요하다.
*/

int n, m;
bool visited[9];  // 기본적으로 false로 초기화 된다.
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
        if (visited[i]) continue;
        visited[i] = true;
        res[depth] = i;
        permutation(depth + 1);  // 다음 단계
        visited[i] = false;  // 백트래킹
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    permutation(0);

    return 0;
}