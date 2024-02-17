#include <bits/stdc++.h>
using namespace std;

/*

*/

int T;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;

    if (T%10 > 0) cout << -1;
    else{
        cout << T/300 << ' ';
        T%=300;
        cout << T/60 << ' ';
        T%=60;
        cout << T/10;
    }



    
    return 0;
}