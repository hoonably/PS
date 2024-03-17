#include <bits/stdc++.h>
using namespace std;

/*

RGB 거리 1 문제와 다른 점
첫번째와 마지막 집도 달라야함.
원형 dp

마지막 집의 색상에 따라 기록
dp[0][i] = i번째 집까지 빨간색으로 칠하는 비용 최솟값
dp[1][i] = i번째 집까지 초록색으로 칠하는 비용 최솟값
dp[2][i] = i번째 집까지 파랑색으로 칠하는 비용 최솟값
*/

int board[1003][3];
int dp[1003][3]; //0번째 지금 빨강,초록,파랑으로 칠했을 때의 최솟값
int answer = 1e9;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int first = 0; first < 3; first++) { //첫 번째를 뭘로 고정할껀지
        for (int i = 0; i < 3; i++) {
            if (i == first) {
                //first는 첫 번째를 뭘로 고정
                //idx는 R G B를 의미함
                //둘이 같으면 그냥 그 색깔로 칠한다 첫 번째를
                dp[0][i] = board[0][i];
            }
            else {
                dp[0][i] = 1e9;
            }
        }

        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + board[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + board[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + board[i][2];
        }

        for (int i = 0; i < 3; i++) {
            if (i == first) continue;
            answer = min(answer, dp[N-1][i]);
        }

    }
    
    cout << answer;
   
    return 0;
}