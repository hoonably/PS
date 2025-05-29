#include <stdio.h>
#include <iostream>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    char c;
    bool white = true;
    int cnt = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> c;
            if(white && c=='F') cnt++;
            white ^= 1;
        }
        white ^= 1;
    }
    cout << cnt;
    
    return 0;
}