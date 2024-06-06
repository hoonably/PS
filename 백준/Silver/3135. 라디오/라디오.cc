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
https://www.acmicpc.net/problem/3135
*/

#define MAX 

int A, B, N;
int button[5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> A >> B >> N;
    FOR(i,0,N){
        cin >> button[i];
    }

    int ans = abs(A-B);
    FOR(i, 0, N){
        ans = min(ans, 1+abs(button[i]-B));
    }
    cout << ans;
    
    return 0;
}