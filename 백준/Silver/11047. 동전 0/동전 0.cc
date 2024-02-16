#include <bits/stdc++.h>
using namespace std;

/*

*/

int ans = 0, N, K;
int coin[10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> coin[i];
    }
    for (int i=N-1; i>=0; i--){
        ans += K / coin[i];
        K %= coin[i];
    }
    cout << ans;
    
    return 0;
}