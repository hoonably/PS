#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[i][s] : i번째 파일부터 j번째 파일까지 합치는 최소비용
dp[1][K] 를 구하면 된다.

*/

void solve(){
    int K;
    cin >> K;

    vector<int> S(K+1);  // 누적합 리스트

    for (int i=1; i<=K; i++){
        cin >> S[i];
        S[i] += S[i-1];
    }


    // K+1 * K+1 2차원 배열 선언과 동시에 0으로 초기화
    // dp[i][s]: i부터 j까지 합치는데 드는 최소 비용
    vector<vector<int>> dp(K+1, vector<int>(K+1, 0));

    // l단계 (길이)
    for (int l=1; l<=K-1; l++){
        for (int s=1; s+l<=K; s++){  //j는 시작점

            int e = s+l;  // e는 끝나는점

            // // 1번 이외에 더 더해지는 것들의 최솟값 + 기본으로 들어가는 누적 합
            dp[s][e] = 1e9;
            for (int m=s; m<e; m++){
                dp[s][e] = min(dp[s][e], 
                            dp[s][m] + dp[m+1][e] + S[e]-S[s-1]);
            }
        }
    }
    cout << dp[1][K] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    
    return 0;
}