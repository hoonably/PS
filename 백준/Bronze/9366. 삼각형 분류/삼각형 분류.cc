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
    
    int T;
    ll len[3];
    cin >> T;
    for (int i=1; i<=T; i++){
        
        cin >> len[0] >> len[1] >> len[2];
        sort(len, len+3);
        
        cout << "Case #" << i <<": ";

        // 삼각형이 만들어지지 않음
        if (len[0]+len[1]<=len[2]){
            cout << "invalid!\n";
        }
        // 정삼각형
        else if (len[0]==len[1] && len[1]==len[2]){
            cout << "equilateral\n";
        }
        // 이등변삼각형
        else if (len[0]==len[1] || len[1]==len[2]) {
            cout << "isosceles\n";
        }
        else cout << "scalene\n";
    }

    return 0;
}