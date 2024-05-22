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
https://www.acmicpc.net/problem/1911
*/

#define MAX 10'000

int N, L;
pii puddle[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> L;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        puddle[i] = {a, b};
    }

    sort(puddle, puddle+N);

    int ans = 0;
    int now = 0;  // 현재 널빤지의 끝
    for(int i=0; i<N; i++){
        
        now = max(now, puddle[i].first);
        
        while(now < puddle[i].second){
            now += L;
            ans++;
        }
    }

    cout << ans;
    
    return 0;
}