#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
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
dp[i][j] = i번째 나사까지 왼쪽으로 누적 j번 돌렸을때 돌린 총 횟수

단, j는 일의자리 정수만 표기
ex) 왼쪽으로 총 23번 돌렸다면 숫자는 3번 돌린 것과 같음
*/

#define MAX 10001

int N;

int dp[MAX][10];
bool able[10];

int Start[MAX];
int End[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        char c;
        cin >> c;
        Start[i] = c-'0';
    }
    for (int i=1; i<=N; i++) {
        char c;
        cin >> c;
        End[i] = c-'0';
    }

    memset(dp, INF, sizeof(dp));

    int leftCnt;
    int rightCnt;

    FOR(i, 0, 9) dp[0][i] = i;

	FOR(i, 1, N) FOR(j, 0, 9){
        // 시작 = Start[i]+j
		int lcnt = (End[i] - (Start[i]+j) + 20) % 10;
		int rcnt = 10 - lcnt;
		dp[i][j] = min(dp[i][j], dp[i - 1][j] + rcnt);
		dp[i][(j + lcnt) % 10] = min(dp[i][(j + lcnt) % 10], dp[i - 1][j] + lcnt);
	}

    // for (int i=0; i<=N; i++){
    //     for (int j=0; j<10; j++){
    //         if (dp[i][j]==INF) cout << "X ";
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << *min_element(dp[N], dp[N]+10);
    
    return 0;
}