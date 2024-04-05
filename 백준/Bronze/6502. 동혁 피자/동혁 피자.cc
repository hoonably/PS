#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T=1;
    while(true){
        int r, w, l;
        cin >> r;
        if (r==0) break;
        cin >> w >> l;
        cout << "Pizza " << T;
        if (pow(2*r, 2) >= w*w + l*l){
            cout << " fits on the table.\n";
        }
        else {
            cout << " does not fit on the table.\n";
        }
        T++;
    }
    
    return 0;
}