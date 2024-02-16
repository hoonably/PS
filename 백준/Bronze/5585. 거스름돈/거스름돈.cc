#include <bits/stdc++.h>
using namespace std;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int ans = 0, money;
    int en[] = {500, 100, 50, 10, 5, 1};

    cin >> money;
    money = 1000 - money;
    for (int i=0; i<6; i++){
        ans += money / en[i];
        money %= en[i];
    }
    cout << ans;
    
    return 0;
}