#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout<<fixed;
    cout.precision(9);
    
    int T;
    cin >> T;
    while(T--){
        double A, B, C;
        cin >> A >> B >> C;

        A = A*30 + B/2 + C/120;  // 시침
        B = B*6 + C/10;
        C = C*6;  // 초침

        double x = min(abs(A - B), 360 - abs(A - B));
        double y = min(abs(B - C), 360 - abs(B - C));
        double z = min(abs(C - A), 360 - abs(C - A));
        cout << min({x, y, z}) << '\n';
    }
    
    return 0;
}