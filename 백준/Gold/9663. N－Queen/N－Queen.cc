#include <bits/stdc++.h>
using namespace std;

/*
N-Queen 문제
2차원배열을 사용하면 체크하는데 많은 시간이 걸림.
가로, 우상향 대각선, 우하향 대각선 bool 배열을 사용해 빠르게 판단 할 수 있다.
*/

int N;
int cnt = 0;
bool row[30];
bool x1[30];
bool x2[30];

void backtracking(int n) {
    // 다 도달했을 때 1 카운트 후 종료
    if (n == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; ++i) {
        // 놓을 수 없으면
        if (row[i] || x1[i + n] || x2[i + ((N - 1) - n)]) continue;
        
        row[i] = true;           // 가로줄 제거
        x1[i + n] = true;        // 오른쪽 위 방향 대각선 제거
        x2[i + ((N - 1) - n)] = true;  // 오른쪽 아래 방향 대각선 제거

        // 자식 노드로 이동
        backtracking(n + 1);

        // 백트래킹
        row[i] = false;
        x1[i + n] = false;
        x2[i + ((N-1)-n)] = false;
    }
}

int main() {
    cin >> N;

    backtracking(0);
    cout << cnt << '\n';

    return 0;
}
