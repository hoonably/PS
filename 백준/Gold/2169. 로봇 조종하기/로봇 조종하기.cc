#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define MAX 1001

/*
거꾸로 오는거라고 생각하기
*/

int N, M;
int val[MAX][MAX];
int dp[MAX][MAX];  // dp[i][j] = i,j 에서 종료했을때 최대값

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin >> val[i][j];
        }
    }

    // 첫째줄 예외처리 (1,1) 에서 시작하므로
    for (int j=1; j<=M; j++){
        dp[1][j] = dp[1][j-1] + val[1][j];
    }

    for (int i=2; i<=N; i++){

        // 내려오자마자
        for (int j=1; j<=M; j++){
            dp[i][j] = dp[i-1][j]+val[i][j];
        }

        // 좌우 이동
        for (int j=1; j<=M; j++){

            int score = dp[i-1][j]+val[i][j];  // 내려오자마자 점수

            // 오른쪽으로 이동 (최대값 갱신 못하면 의미 없음)
            for (int k=j+1; k<=M; k++){
                score += val[i][k];
                dp[i][k] = max(dp[i][k], score);
                // if (score < dp[i][k]) break;
                // dp[i][k] = score;
            }

            // 왼쪽으로 이동
            score = dp[i-1][j]+val[i][j];  // 내려오자마자 점수
            for (int k=j-1; k>=1; k--){
                score += val[i][k];
                dp[i][k] = max(dp[i][k], score);
                // if (score < dp[i][k]) break;
                // dp[i][k] = score;
            }
        }
    }

    // for (int i=1; i<=N; i++){
    //     for (int j=1; j<=M; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[N][M];
    
    return 0;
}