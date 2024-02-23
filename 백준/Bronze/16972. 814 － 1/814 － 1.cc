#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
28 * 29 = 812

28 * (29*20) = 16240
28 * 580 = 16240
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t=0;
    int x = -8140;
    int y = -8140;

    cout << "-8140 -8140\n"; 
    for (int i=1; i<=28; i++){
        x += 580;
        y = -8140; // 초기화
        for (int j=1; j<=29; j++){
            cout << x << ' ' << y << '\n';
            y += 580;
            t++;
        }

    }
    cout << "8140 8140\n"; 
    // cout << t;
    
    return 0;
}