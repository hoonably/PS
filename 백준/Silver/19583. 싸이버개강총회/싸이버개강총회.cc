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

int S, E, Q;
unordered_set<string> in, ans;

int strToInt(string str){
    return str[0]*1000 + str[1]*100 + str[3]*10 + str[4];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string temp;
    cin >> temp;
    S = strToInt(temp);
    cin >> temp;
    E = strToInt(temp);
    cin >> temp;
    Q = strToInt(temp);

    while(cin >> temp){
        string name;
        cin >> name;

        int time = strToInt(temp);
        if (time <= S){
            in.insert(name);
        }
        else if (E <= time && time <= Q && in.find(name)!=in.end()){
            ans.insert(name);
        }
    }
    
    cout << ans.size();

    return 0;
}