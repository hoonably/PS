#include <bits/stdc++.h>
using namespace std;

int score[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> score[i];
    for (int i = 1; i <= n; i++) {
        // 중요 포인트

        // dp[i] : i번째 항이 포함되고 i번째 항이 마지막인 연속수열중에 최대 합
        
        // 그 이전까지의 dp 와 0 둘중에 큰 값으로 사용
        // 그 이전까지의 dp가 음수라면 그냥 지금 값부터가 최대값
        dp[i] = max(dp[i - 1], 0) + score[i];
    }

    // max_element(시작주소, 끝주소)
    // 가장 큰 값이 있는 주소를 리턴
    // 거기에 *를 붙여주면 값 반환
    cout << *max_element(dp + 1, dp + n + 1);
}