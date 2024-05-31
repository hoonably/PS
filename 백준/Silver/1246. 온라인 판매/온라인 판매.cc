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
https://www.acmicpc.net/problem/1246

*/

#define MAX 1001

int N, M;
int P[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        cin >> P[i];
    }

    sort(P+1, P+M+1, greater<>());

    ll maxi = 0;
    int idx = 0;
    // 계속 틀렸던 이유
    // N개 넘는 달걀을 팔 수 없음
    for (ll i=1; i<=N; i++){
        ll temp = i * P[i];
        if (temp >= maxi){
            maxi = temp;
            idx = i;
        }
    }
    
    cout << P[idx] << ' ' << maxi;

    return 0;
}