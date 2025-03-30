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

unordered_map<string, pair<int,bool>> S;
bool comp(pair<string,pair<int,bool>> &a, pair<string,pair<int,bool>> &b){

    if (a.second.second && !b.second.second){
        return true;
    }
    if (!a.second.second && b.second.second){
        return false;
    }
    return a.second.first > b.second.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;

        S[str] = {i,false};
    }
    int M; cin >> M;
    for(int i=0; i<M; i++){
        string str;
        cin >> str;
        S[str].second = true;
    }
    vector<pair<string,pair<int,bool>>> v(all(S));
    sort(all(v), comp);
    for(auto a : v){
        cout << a.first << '\n';
    }

    
    return 0;
}