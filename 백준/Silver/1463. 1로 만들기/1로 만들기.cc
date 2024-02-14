#include <bits/stdc++.h>
using namespace std;

/*
탑다운 방식으로 거꾸로 1에서 가는 방향으로 구현한다.
dp[i] : i까지 가는데 최소 거리
*/

int dp[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i=2; i<=N; i++){
        // 1을 더하는 경우
        dp[i] = dp[i-1];
        // 2를 곱한 경우
        if (i%2==0){
            dp[i] = min(dp[i], dp[i/2]);
        }
        // 3를 곱한 경우
        if (i%3==0){
            dp[i] = min(dp[i], dp[i/3]);
        }
        // 지금 횟수 추가
        dp[i]++;
    }
    cout << dp[N];
    
    return 0;
}