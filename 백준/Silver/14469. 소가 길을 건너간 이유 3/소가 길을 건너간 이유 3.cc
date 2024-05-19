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

vector<pii> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    FOR(i, 0, N){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(all(v));

    int time = 0;
    FOR(i, 0, N){
        if (time < v[i].first){
            time = v[i].first;
        }
        time += v[i].second;
    }
    cout << time;
    
    return 0;
}