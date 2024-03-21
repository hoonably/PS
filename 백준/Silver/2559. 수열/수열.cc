#include <bits/stdc++.h>
using namespace std;

/*
S[i] = 1~i의 합
i ~ j 번째 수 합 : S[j] - S[i-1]
*/

int N, K, num;
int S[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i=1; i<=N; i++){
        cin >> S[i];
        S[i] += S[i-1];
    }

    // 이걸 0으로 해놨다가 계속 틀렸음
    // 마이너스가 가능하기 때문에
    int ans = -1e9;
    for (int j=K; j<=N; j++){
        ans = max(ans, S[j]-S[j-K]);
    }
    cout << ans;
    
    return 0;
}