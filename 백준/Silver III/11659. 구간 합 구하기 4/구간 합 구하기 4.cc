#include <bits/stdc++.h>
using namespace std;

/*
S[i] = 1~i의 합
i ~ j 번째 수 합 : S[j] - S[i-1]
*/

int N, M, num, s, e;
int S[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> S[i];
        S[i] += S[i-1];
    }
    while(M--){
        cin >> s >> e;
        cout << S[e]-S[s-1] << '\n';
    }

    
    return 0;
}