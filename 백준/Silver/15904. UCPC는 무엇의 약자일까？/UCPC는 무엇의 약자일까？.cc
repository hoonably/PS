#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
일단 UCPC 아닌건 다 넘기고, UCPC라면 저장
*/

#define MAX 



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str = "";

    char c;
    while(cin >> c) {
        if (c=='U' || c=='C' || c=='P') str += c;
    }

    string UCPC = "UCPC";
    int level = 0;
    for (char c:str){
        if (c==UCPC[level]){
            level++;
            if (level==4){
                cout << "I love UCPC";
                return 0;
            }
        }
    }
    cout << "I hate UCPC";
    
    return 0;
}