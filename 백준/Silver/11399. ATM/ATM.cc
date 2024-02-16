#include <bits/stdc++.h>
using namespace std;

/*
단순히 정렬 후 N-i만큼 곱해서 다 더해주면 된다.
*/

int N;
int P[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> P[i];
    }
    sort(P, P+N);
    int ans = 0;
    for (int i=0; i<N; i++){
        ans += P[i] * (N-i);
    }
    cout << ans;
    
    return 0;
}