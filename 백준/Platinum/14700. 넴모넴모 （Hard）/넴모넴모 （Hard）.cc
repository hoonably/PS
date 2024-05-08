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

*/

#define MAX 

int dp[301][1<<18];
int N, M;

int dpf(int idx, int bit){
    if (idx == N * M) return 1;

    int &ret = dp[idx][bit];

    if (ret != -1) return ret;  // 이미 저장되어있다면 넘김
 
    ret = dpf(idx + 1, bit >> 1) % MOD;
    
    // 줄이 바뀌서 새로 진행되었다면 무조건 놓아도 됨
    if (idx % M == 0){
        ret += dpf(idx + 1, (bit >> 1) | (1 << M)) % MOD;
    }
    // 다음줄, 다음, 이번 세개 중에 하나라도 비어있다면 놓을 수 있음
    else if (!(bit & (1 << M)) || !(bit & 2) || !(bit & 1)){
        ret += dpf(idx + 1, (bit >> 1) | (1 << M)) % MOD;
    }
 
    return ret % MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // 작은걸로 비트처리하는게 좋음 (작은걸 M으로)
    if (N < M) swap(N, M);

    memset(dp, -1, sizeof(dp));
    cout << dpf(0, 0);
    
    return 0;
}