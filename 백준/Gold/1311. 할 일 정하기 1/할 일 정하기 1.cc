#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define INF 1e9

/*
https://21ha.tistory.com/213

*/

int N;
int D[20][20];
int dp[1 << 20];

//ex) bt = 110, index 2, 1인 일을 처리 했을 때, 앞으로 남은 사람들이 처리해야 하는 일의 최소 비용은 dp[110]
//ex) bt = 100, index 2인 일을 처리 했을 때, 앞으로 남은 사람들이 처리해야 하는 일의 최소 비용은 dp[100]

int memo(int bt, int idx) {

    // 모두 채운것임
    if (idx == N) return 0;
    
    // 이미 정해진 값이라면
    if (dp[bt] != -1) return dp[bt];  
    
    dp[bt] = 1e9;
    
    // 현재 안켜져있는 비트에 대해 재귀로 최소값 다지기
    for (int i = 0; i < N; ++i)
        // i번 비트가 0이라면
        if (!(bt & (1 << i)))
            dp[bt] = min(dp[bt], D[idx][i] + memo(bt | (1 << i), idx + 1));  // i번 비트를 키고 idx를 하나 늘린 dp값
 
    return dp[bt];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
 
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> D[i][j];
        }
    }
    
    // dp 초기화
    memset(dp, -1, sizeof(int)*(1 << N));
    int res = 1e9;
 
    for (int i = 0; i < N; ++i)
        res = min(res, D[0][i] + memo(1 << i, 1));
 
    cout << res;
    
    return 0;
}