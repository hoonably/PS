#include <bits/stdc++.h>
using namespace std;

/*
바로 이전 과 5번째 전 꺼를 합한 값이 나옴
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T, N;
    long dp[101] {0, 1, 1, 1, 2, 2, };  // 이런식으로 앞에만 초기화 가능

    for (int i=6; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    cin >> T;
    while(T--){
        cin >> N;
        cout << dp[N] << '\n';
    }

    return 0;
}