#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

string str;
string ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    

    cin >> str;

    int cnt = 0;
    for (int i=0; i<str.length(); i++){

        if (str[i]=='X') cnt++;

        else {
            if (cnt==0) {
                ans += ".";
                continue;
            }
            else if (cnt==2){
                ans += "BB.";
                cnt = 0;
            }

            else {
                cout << -1;
                return 0;
            }
        }

        if (cnt==4){
            ans += "AAAA";
            cnt=0;
            continue;
        }

    }

    if (cnt==0){
        cout << ans;
    }

    else if (cnt==2){
        cout << ans << "BB";
    }

    else if (cnt==1 || cnt==3){
        cout << -1;
    }
    
    return 0;
}