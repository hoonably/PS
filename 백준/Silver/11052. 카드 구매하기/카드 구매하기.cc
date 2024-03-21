#include <bits/stdc++.h>
using namespace std;

/*
dp[i] : i개의 카드를 살 때 드는 최고 돈
*/

int N;
int P[1001], dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> P[i];
    }
    for (int i=1; i<=N; i++){
        for (int j=i; j<=N; j++){
            dp[j] = max(dp[j], dp[j-i]+P[i]);
        }
    }
    cout << dp[N];

    return 0;
}