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

*/

#define MAX 

int N, A, B, C;
vector<int> D;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> A >> B >> C;
    D.resize(N);
    for(int& d : D) cin >> d;
    sort(all(D), greater<int>());

    int a = C;
    int b = A;  // 분자, 분모

    int ans = C/A;
    for(int d : D){
        a += d;
        b += B;
        int now = a/b;
        if (ans > now) break;
        ans = now;
    }
    cout << ans;

    return 0;
}