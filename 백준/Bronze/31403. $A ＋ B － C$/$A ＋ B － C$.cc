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



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string A, B;
    int C;
    cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - C << '\n';

    A += B;
    cout << stoi(A) - C << '\n';
    
    return 0;
}