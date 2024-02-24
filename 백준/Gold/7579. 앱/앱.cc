#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
어려운 냅색 알고리즘
# dp[i][j] = k
# i번째 앱까지 확인하고 j만큼 비용이 들었을때 k만큼의 메모리를 줄일 수 있음
*/

int N, M;
int m[101], c[101], dp[101][10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> m[i];
    }
    int total=0;
    for(int i=1; i<=N; i++){
        cin >> c[i];
        total+=c[i];
    }

    int ans = 1e9;

    for (int i=1; i<=N; i++){
        int mi = m[i], ci = c[i];
        // 일단 그 전 단계로 채우기
        for (int j=0; j<=total; j++){
            dp[i][j] = dp[i-1][j];
        }
        // i앱을 지우는 비용 ~ 총 비용
        for (int cost=ci; cost<=total; cost++){

            // i번째 앱을 지웠을때 vs i번째 앱을 안지웠을때
            if (dp[i-1][cost-ci] + mi > dp[i][cost]){
                dp[i][cost] = dp[i-1][cost-ci] + mi;

                // 정리된 메모리가 M보다 크다면 정답 갱신
                if (dp[i][cost] >= M){
                    ans = min(ans, cost);
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}