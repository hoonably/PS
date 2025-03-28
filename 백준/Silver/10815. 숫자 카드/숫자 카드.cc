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

unordered_set<int> S;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int card; cin >> card;
        S.insert(card);
    }
    int M; cin >> M;
    for(int i=0; i<M; i++){
        int card; cin >> card;
        if (S.find(card)!=S.end()) cout << "1 ";
        else cout << "0 ";
    }

    
    return 0;
}