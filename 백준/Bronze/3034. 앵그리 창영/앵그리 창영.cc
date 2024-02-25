#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, W, H;
    cin >> N >> W >> H;

    int limit = sqrt(W*W+H*H);
    while(N--){
        int len;
        cin >> len;
        if(len>limit) cout << "NE\n";
        else cout << "DA\n";
    }
    
    return 0;
}