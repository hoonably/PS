#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

string str;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> str;

    int idx = 0;
    int num = 1;
    while (idx != str.length()) {
        string numString = to_string(num);

        for (int i = 0; i < numString.length(); i++) {
            if (str[idx] == numString[i]) {
                idx++;
                if (idx >= str.length()) {
                    cout << num;
                    return 0;
                }
            }
        }
        num++;
    }
    
    return 0;
}