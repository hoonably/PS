#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

int n, m;
int arr[1010][1010];
int dp[1010][1010][3];
// Down, ->, <-

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // Stream Init

    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    memset(dp, -INF, sizeof(dp));

    // 첫째줄 초기화
    dp[0][0][1] = arr[0][0];
    for (int i = 1; i < m; i++)
        dp[0][i][1] = dp[0][i - 1][1] + arr[0][i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j][0] = arr[i][j];
            dp[i][j][0] += max({ dp[i - 1][j][0] ,dp[i - 1][j][1] ,dp[i - 1][j][2] });
        }
        // Down


        for (int j = 1; j < m; j++) {
            dp[i][j][1] = arr[i][j];
            dp[i][j][1] += max(dp[i][j - 1][0], dp[i][j - 1][1]);
        }
        // ->

        for (int j = m - 2; j >= 0; j--) {
            dp[i][j][2] = arr[i][j];
            dp[i][j][2] += max(dp[i][j + 1][0], dp[i][j + 1][2]);
        }
        // <-
    }
    // DP

    cout << max(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);

    return 0;
}

// 느린 코드

// #define MAX 1001

// int N, M;
// int val[MAX][MAX];
// int dp[MAX][MAX];  // dp[i][j] = i,j 에서 종료했을때 최대값

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
    
//     cin >> N >> M;

//     for (int i=1; i<=N; i++){
//         for (int j=1; j<=M; j++){
//             cin >> val[i][j];
//         }
//     }

//     // 첫째줄 예외처리 (1,1) 에서 시작하므로
//     for (int j=1; j<=M; j++){
//         dp[1][j] = dp[1][j-1] + val[1][j];
//     }

//     for (int i=2; i<=N; i++){

//         // 내려오자마자
//         for (int j=1; j<=M; j++){
//             dp[i][j] = dp[i-1][j]+val[i][j];
//         }

//         // 좌우 이동
//         for (int j=1; j<=M; j++){

//             int score = dp[i-1][j]+val[i][j];  // 내려오자마자 점수

//             // 오른쪽으로 이동 (최대값 갱신 못하면 의미 없음)
//             for (int k=j+1; k<=M; k++){
//                 score += val[i][k];
//                 dp[i][k] = max(dp[i][k], score);
//             }

//             // 왼쪽으로 이동
//             score = dp[i-1][j]+val[i][j];  // 내려오자마자 점수
//             for (int k=j-1; k>=1; k--){
//                 score += val[i][k];
//                 dp[i][k] = max(dp[i][k], score);
//             }
//         }
//     }

//     // for (int i=1; i<=N; i++){
//     //     for (int j=1; j<=M; j++){
//     //         cout << dp[i][j] << ' ';
//     //     }
//     //     cout << '\n';
//     // }

//     cout << dp[N][M];
    
//     return 0;
// }