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
&[]* 순으로
*/

#define MAX 

string str;
vector<string> a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    getline(cin, str);
    string now = "";
    for(int i=0;i<str.size();i++){
        if (str[i]==' ' || str[i]==',' || str[i]==';'){
            if (now.length() > 0) {
                a.push_back(now);
            }
            now = "";
        }
       else now+=str[i];
    }

    string base = a[0];
    for (int i=1; i<a.size(); i++) {
        string t = base;
        string str = a[i];
        while (str.length() > 0 && !('a' <= str.back() && str.back() <= 'z')) {
            if (str.back() == '[') {
                t += ']';
            } else if (str.back() == ']') {
                t += '[';
            } else {
                t += str.back();
            }
            str.pop_back();
        }
        cout << t << ' ' << str << ";\n";
    }

    return 0;
}