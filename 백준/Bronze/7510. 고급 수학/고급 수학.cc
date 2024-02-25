#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if (2 * max(max(a,b),c) * max(max(a,b),c) == a*a + b*b + c*c){
            cout << "Scenario #" << i << ":\nyes\n\n";
        }
        else {
            cout << "Scenario #" << i << ":\nno\n\n";
        }
    }


    return 0;
}