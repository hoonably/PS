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

int cnt;
string str;
map<string, int> trees;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    while(getline(cin, str)){
        cnt++;  // 나무 개수

        // 기존 map에 없다면
        if (trees.find(str)==trees.end()){
            trees[str] = 1;
        }
        else{
            trees[str]++;
        }
    }

    cout << fixed;
    cout.precision(4);
    for (pair<string,int> tree : trees){
        cout << tree.first << ' ' << 100.0 * tree.second / cnt << '\n';
    }
    
    return 0;
}