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
const int MOD = 1e9+7;

/* -----------------------------------------------------
https://www.acmicpc.net/problem/1648
비트필드를 이용한 다이나믹 프로그래밍 문제

dp[i][j]: i-1번째 칸까지 모두 채워져있고, 
i+1번째부터 i+m번째까지 채워져있는 상태

k 번째 타일을 놓기 위해 필요한 정보는 k + 1 번째 타일이 채워져 있는지 여부와
k + m 번째 타일이 채워져 있는지 여부이다.  

k+1~k+m 번째 타일이 채워져있는지 비트로 기록

이와 같이 k번째 타일을 채우기 위해서는 m개의 타일 정보만 가지고 있으면 된다. 
그렇기 때문에 m개의 타일 정보를 비트 마스킹하며 채워나가면 된다.
*/

#define MAX 

int n, m;
ll dp[11 * 11][1 << 11];

ll dpf(int idx, int bit) {

    // 단위
    if (idx == n * m && bit == 0) return 1;
    
    // 범위를 넘어감
    if (idx >= n * m) return 0;

    // 수정하는 부분
    ll &ret = dp[idx][bit];

    if (ret!=-1) return ret;  // 이미 저장되어있다면 넘김

    ret = 0;

    // 이번 타일이 채워져있다면 다음으로 진행
    // (이전에 세로로 넣었기 때문에 이미 1로 채워져있는거임)
    if (bit & 1) ret = dpf(idx + 1, bit >> 1);

    else {
        // 세로로 넣는 경우 이번 타일 + m번째 타일에 1 표시해주고 재귀
        
        // ? ? ? ? (0) 1 0 0
        // 0 1 0 0 (0) ? ? ?   이었다면

        // ? ? ? ? (?) 1 0 0   (?)는 (1)로 채워진거임
        // 1 1 1 0 (1) ? ? ? 
        ret += dpf(idx + 1, (bit >> 1) | (1 << (m - 1)));

        // 그 줄에서 마지막이 아니면서 바로 다음 타일이 비어있다면 연달아서 넣음

        // ? ? ? ? (0 0) 0 1
        // 1 1 1 0  ? ?  ? ?   이었다면

        // ? ? ? ? (? ?) 0 1    (? ?)는 (1 1)로 채워진거임
        // 1 1 1 0  0 0  ? ? 
        if ((idx % m) != (m - 1) && !(bit & 2)) ret += dpf(idx + 2, bit >> 2);
    }
    return ret;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(true){
        cin >> n >> m;
        if (n==0) break;
        memset(dp, -1, sizeof dp);
        cout << dpf(0, 0) << '\n';
    }

    
    return 0;
}