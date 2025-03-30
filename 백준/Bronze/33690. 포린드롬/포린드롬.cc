#include <bits/stdc++.h>

using namespace std;

// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

int a[] = {1,11,111,1111,11111,111111,1111111,11111111,111111111};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    int ans = 1;  // 0도 포함
    for(int j=0; j<9; j++){
        for(int i=1; i<=9; i++){
            if (N >= a[j]*i) {
                ans++;
                // cout << a[j]*i << '\n';
            }
            else {
                cout << ans;
                return 0;
            }
        }
    }
    cout << ans;
    
    return 0;
}