#include <bits/stdc++.h>
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

int R, C;
char puzzle[20][20];
string ans = "{";

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin >> puzzle[i][j];
    
    // 가로
    string temp;
    for(int i=0; i<R; i++){
        temp = "";
        for(int j=0; j<C; j++){
            if(puzzle[i][j] == '#') {
                if (temp.size() > 1) ans = min(ans, temp);
                temp = "";
                continue;
            }
            temp += puzzle[i][j];
        }
        if (temp.size() > 1) ans = min(ans, temp);
    }
    for(int j=0; j<C; j++){
        temp = "";
        for(int i=0; i<R; i++){
            if(puzzle[i][j] == '#') {
                if (temp.size() > 1) ans = min(ans, temp);
                temp = "";
                continue;
            }
            temp += puzzle[i][j];
        }
        if (temp.size() > 1) ans = min(ans, temp);
    }
    cout << ans << endl;
    
    return 0;
}