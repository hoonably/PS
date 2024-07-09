#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
b를 만족시키는 1~N으로 이루어진 수열 a가 있는가?

N = 8 , p = 3 이라면 
나머지는 1 2 0 1 2 0 1 2
1:3개, 2:3개, 0:2개

아래 두 수열 사이면 됨
1 1 1 2 2 2 3 3
1 2 3 3 3 3 3 3
*/

#define MAX 500'000

ll N, p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> p;

    ll prev = 0;
    for (ll i = 1; i <= N; i++) {
        ll x;
        cin >> x;

        if (x < prev || x > prev + 1 || x> (N-1)/p+1) {
            cout << "NO";
            return 0;
        }

        if (p * x < i) {
            cout << "NO";
            return 0;
        }
        prev = x;
    }

    cout << "YES";

    return 0;
}