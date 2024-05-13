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
각 손님은 강호에게 원래 주려고 생각했던 돈 - (받은 등수 - 1) 
만큼의 팁을 강호에게 준다.

음수가 되면 주지 않는다.
*/

#define MAX 100'000

int N;
int tip[MAX];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    FOR(i, 0, N){
        cin >> tip[i];
    }

    sort(tip, tip+N, cmp);

    ll ans = 0;
    FOR(i, 0, N){
        ans += max(0, tip[i]-i);
    }
    cout << ans;
    
    return 0;
}