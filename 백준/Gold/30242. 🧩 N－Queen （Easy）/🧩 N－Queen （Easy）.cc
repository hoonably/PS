#include <bits/stdc++.h>
using namespace std;

/*
N-Queen 문제
2차원배열을 사용하면 체크하는데 많은 시간이 걸림.
가로, 우상향 대각선, 우하향 대각선 bool 배열을 사용해 빠르게 판단 할 수 있다.
*/

int N;
int cnt = 0;
int ans[20];
bool fix[20];  // 미리 고정된 단계
bool row[21];
bool x1[42];
bool x2[42];

void backtracking(int depth) {
    
    if (depth == N) {
        for (int i=0; i<N; i++){
            cout << ans[i] << ' ';
        }
        exit(0);  //아예 프로그램 종료
    }

    if (fix[depth]) {
        backtracking(depth + 1);
        return;
    }

    for (int i = 1; i < N+1; ++i) {
        // 놓을 수 없으면 패스
        if (row[i] || x1[i + depth] || x2[i + ((N - 1) - depth)]) continue;
        
        row[i] = true;           // 가로줄 제거
        x1[i + depth] = true;        // 오른쪽 위 방향 대각선 제거
        x2[i + ((N - 1) - depth)] = true;  // 오른쪽 아래 방향 대각선 제거
        ans[depth] = i;  // 말 놓기

        // 자식 노드로 이동
        backtracking(depth + 1);

        // 백트래킹
        row[i] = false;
        x1[i + depth] = false;
        x2[i + ((N-1)-depth)] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int get_num;
    for (int i=0; i<N; i++){
        cin >> get_num;
        if (get_num==0) continue;

        fix[i] = true;
        ans[i] = get_num;
        row[get_num] = true;           // 가로줄 제거
        x1[get_num + i] = true;        // 오른쪽 위 방향 대각선 제거
        x2[get_num + ((N - 1) - i)] = true;  // 오른쪽 아래 방향 대각선 제거
    }

    backtracking(0);

    // exit(0) 을 만나지 않았다면 답이 없는거임
    cout << -1;

    return 0;
}
