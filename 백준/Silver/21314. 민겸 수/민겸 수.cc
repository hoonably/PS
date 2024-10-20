#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;
    str = 'x' + str;
    int len = str.size();

    string mn;
    int cnt = 0;
    for(int i=1; i<len; i++){
        if (str[i]=='M'){
            if (str[i-1]=='M') mn+='0';
            else mn+='1';
            cnt++;
        }
        else {
            mn += '5';
            cout << '5';
            while(cnt--) cout << '0';
            cnt = 0;
        }
    }
    while(cnt--) cout << '1';
    cout << '\n' << mn;
    
    return 0;
}