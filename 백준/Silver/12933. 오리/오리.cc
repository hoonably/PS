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

map<char, int> cnt = {
    {'q',0},
    {'u',0},
    {'a',0},
    {'c',0}
};

map<char, char> need = {
    {'u','q'},
    {'a','u'},
    {'c','a'},
    {'k','c'}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;

    int now = 0;  // 현재 오리의 수
    int ans = 0;  // 최대 오리의 수
    for(auto c : str) {
        if (c == 'q'){
            cnt['q']++;
            ans = max(ans, ++now);
            continue;
        }

        // 불가능
        if (cnt[need[c]]==0) {
            cout << -1;
            return 0;
        }

        // 오리를 만들 수 있음
        cnt[need[c]]--;
        if (c == 'k') {
            now--;
            continue;
        }
        cnt[c]++;
    }

    // 남아있는 문자가 있으면 안됨
    for(auto [k,v] : cnt) {
        if(v>0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    
    return 0;
}