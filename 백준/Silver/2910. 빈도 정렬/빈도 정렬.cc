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

vector<pii> v;
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, C; cin >> N >> C;
    for(int i=0; i<N; i++){
        int x; cin >> x;

        bool found = false;
        for(pii &p: v){
            if(p.first == x){
                p.second++;
                found = true;
                break;
            }
        }
        if (!found) v.push_back({x, 1});
    }
    stable_sort(all(v), cmp);  // stable_sort preserves the order of equal elements
    
    for(auto p: v){
        for(int i=0; i<p.second; i++){
            cout << p.first << ' ';
        }
    }
    
    return 0;
}