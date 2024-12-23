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

int n;
ll v[1000000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        reverse(all(str));
        // v[i] = stoi(str);  // int type
        v[i] = stoll(str);
    }
    sort(v, v+n);
    for(int i=0; i<n; i++) cout << v[i] << '\n';
    
    return 0;
}