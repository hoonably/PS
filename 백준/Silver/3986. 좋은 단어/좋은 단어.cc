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

bool check(){
    string str; cin >> str;
    stack<char> st;
    for(char c : str){
        if (st.empty()) st.push(c);
        else if (st.top()==c) st.pop();
        else (st.push(c));
    }
    return st.empty();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    int ans = 0;
    while(N--) if(check()) ans++;
    cout << ans;
    
    return 0;
}