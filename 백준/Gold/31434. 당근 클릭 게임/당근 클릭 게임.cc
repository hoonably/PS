#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

vector<vector<int>> dp;
int N, K, answer, maxS;
vector<pair<int,int>> carrots;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K;
    vector<pair<int,int>> carrots(N);

    for (pair<int,int> &carrot : carrots) {
        cin >> carrot.first >> carrot.second;
        maxS = max(maxS, carrot.second);
    }
    maxS = maxS * K + 1;
    vector<vector<int>> dp(K + 1, vector<int>(maxS, -1));
    dp[0][1] = 0;
    
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j < maxS; ++j) {
            answer = max(answer, dp[i][j]);
            if (dp[i][j] == -1 || i + 1 > K) continue;  // 도달하지 못했거나, 범위를 벗어난 경우

            dp[i + 1][j] = max(dp[i][j] + j, dp[i + 1][j]);
            for (pair<int,int> &carrot : carrots) {
                dp[i + 1][j + carrot.second] = max(dp[i][j] - carrot.first, dp[i + 1][j + carrot.second]);
            }
        }
    }
    cout << answer;

    return 0;
}