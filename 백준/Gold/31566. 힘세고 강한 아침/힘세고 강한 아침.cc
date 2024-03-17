#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
오프라인 쿼리 + 플로이드 워셜
특정 노드(k)를 거치지 않고
s -> e 언어로 가는 최소비용을 구하기
플로이드 워셜
dp[i][j][l] : 노드 l을 거치지 않고 노드 i에서 노드 j로 가는 최소 비용
*/

int N, E, Q;
int dp[101][101][101];
#define INF 1e9

void solve() {
    cin >> N >> E >> Q;

    // INF 초기화
    // dp[i][j][l] : 노드 l을 거치지 않고 노드 i에서 노드 j로 가는 최소 비용
    for (int l=1; l<=N; l++) {
        for (int i=1; i<=N; i++) {
            if(i==l) continue;
            for (int j=1; j<=N; j++) {
                if(i==j) continue;
                if(j==l) continue;

                dp[i][j][l] = INF;
            }
        }
    }

    // 간선 처리
    // 모든 i에 대해서 초기화
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        for(int i=1;i<=N;i++) {
            dp[a][b][i] = c;
        }
    }

    // 플로이드 워셜
    // for문이 4개 (원래는 3개인데 l의 추가)
    // l은 지나지 않는 노드

    // k는 중간에 거치는 노드 (원래 플로이드 워셜에 있음)
    for(int l=1;l<=N;l++) {
        for(int k=1;k<=N;k++) {
            if(k==l) continue;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) {
                    dp[i][j][l] = min(dp[i][j][l], dp[i][k][l] + dp[k][j][l]);
                }
            }
        }
    }

    while(Q--) {
        int a, b, x; 
        cin >> a >> x >> b;

        if(dp[a][b][x]==INF) cout << "No\n";
        else cout << dp[a][b][x] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}