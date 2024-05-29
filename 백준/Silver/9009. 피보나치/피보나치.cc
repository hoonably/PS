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

#define MAX 1e9

int fib[45];

void solve(){
    int n;
    cin >> n;

    stack<int> st;

    int idx = 44;
    while(true){
        if (n>=fib[idx]){
            n -= fib[idx];
            st.push(fib[idx]);

            if (n==0) break;
        }
        else {
            idx--;
        }
    }

    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    // fib[45] 부터 10억 넘음
    fib[1] = 1;
    for(int i=2; i<45; i++){
        fib[i] = fib[i-1] + fib[i-2];
        // cout << fib[i] << ' ';
    }
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    
    return 0;
}