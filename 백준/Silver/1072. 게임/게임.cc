#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll X, Y;
    cin >> X >> Y;
    ll Z = (Y*100)/X;

    // 아무리 해도 100 안됨, 101 안됨
    if (Z>=99){
        cout << -1;
        exit(0);
    }

    int start = 1;
    int end = 1e9;
    int ans = 1e9;
    while (start <= end){
        int mid = (start+end)/2;
        int new_score = (Y+mid) * 100 / (X+mid);
        if (new_score > Z){
            end = mid-1;
            ans = mid;
        }
        else {
            start = mid+1;
        }
    }
    cout << ans;
    
    return 0;
}