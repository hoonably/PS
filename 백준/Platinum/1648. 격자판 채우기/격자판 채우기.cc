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
const int MOD = 9901;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/1648
비트필드를 이용한 다이나믹 프로그래밍 문제

dp[i][j]: i번째 칸을 채우려는데, 그 줄의 현 상태가 j인 경우에 채울 수 있는 방법의 수
(여기서 j를 비트마스킹으로) ex) 110011011


*/

#define MAX 

int n, m;
int dp[15 * 15][1 << 14];

int dpf(int idx, int bit) {

    // 단위
    if (idx == n * m && !bit) return 1;
    
    // 범위를 넘어감
    if (idx >= n * m) return 0;

    // 수정하는 부분
    int &ret = dp[idx][bit];

    if (~ret) return ret;  // 이미 저장되어있다면 넘김

    ret = 0;
    if (bit & 1) ret = dpf(idx + 1, bit >> 1);
    else {
        ret += dpf(idx + 1, (bit >> 1) | (1 << (m - 1)));
        if ((idx % m) != (m - 1) && !(bit & 2)) ret += dpf(idx + 2, bit >> 2);
    }
    return ret % MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << dpf(0, 0);
    
    return 0;
}