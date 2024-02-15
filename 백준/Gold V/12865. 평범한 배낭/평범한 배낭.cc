#include <bits/stdc++.h>
using namespace std;

/*
냅색 알고리즘
dp[j] : 총 넣은 무게가 j일때 
*/

int N, K;
int W[101], V[101], dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i=0; i<N; i++){
        cin >> W[i] >> V[i];
    }

    for (int i=0; i<N; i++){
        // 이거 탑다운으로 안하면 같은 물건을 여러번 넣는 경우도 계산됨
        for (int j=K; j>=W[i]; j--){
            dp[j] = max(dp[j], dp[j-W[i]] + V[i]);
        }
    }

    cout << dp[K];
    
    return 0;
}