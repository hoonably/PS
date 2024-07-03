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

int N, v[26], f[26];

void check(string word, int v[]) {
    memset(v, 0, sizeof(int)*26);
    for(int i = 0; word[i]; i++) v[word[i] - 'A']++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    string word;
    cin >> word;
    check(word, v);
    
    int ans=0;
    while(--N) {
        cin >> word;
        check(word, f);

        int plus = 0, minus = 0;
        for(int i = 0; i < 26; i++) {
            if(f[i] > v[i]) plus += f[i] - v[i];
            else if(f[i] < v[i]) minus += v[i] - f[i];
        }

        if(plus <= 1 && minus <= 1) ans++;
    }
    cout << ans;
}