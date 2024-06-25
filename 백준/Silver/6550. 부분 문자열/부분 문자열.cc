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

string s, t;
int slen, tlen;

bool check(){
    if (slen>tlen) return false;
    
    int idx = 0;
    for(int i=0; i<tlen; i++){
        if (s[idx]==t[i]) {
            idx++;
            if (idx==slen) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> s >> t){
        slen = s.length();
        tlen = t.length();

        if(check()) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}