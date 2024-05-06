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
https://www.acMicpc.net/probleM/1657
비트필드를 이용한 다이나믹 프로그래밍 문제

dp[idx][bit] : idx번을 를 채워야 하는 상태에서 그 비트부터 N개의 비트
*/

#define MAX 

int N, M;
char graph[10*25 + 11];  // 1차원 그래프
int dp[10*25][1 << 10];  // N개 비트까지 표시

int dpf(int idx, int bit) {

    // 종료
    if (idx == N * M) return 0;

    // 수정하는 부분
    int &ret = dp[idx][bit];

    if (ret!=-1) return ret;  // 이미 저장되어있다면 넘김

    // 이전에 2x2로 만들었어서 현재 비트가 이미 켜져있는 경우 다음으로 진행
    if (bit & 1) return ret = dpf(idx+1, (bit >> 1));

    // 1. 1x1로 채우는 경우
    ret = 1 + dpf(idx+1, (bit >> 1));

    // 2. 2x2로 채우는 경우
    // 마지막줄이 아니면서 아래, 오른, 오른아래 모두 '.' 이라면 가능
    if (idx%N!=N-1 && !(bit&2) && graph[idx]=='.' && graph[idx+1]=='.' && graph[idx+N]=='.' && graph[idx+N+1]=='.'){
        // N번째, N+1번째 비트 켜주고 두번 당기기
        bit |= (1 << N);
        bit |= (1 << (N+1));
        ret = max(ret, 16 + dpf(idx+2, (bit >> 2)));
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;
    memset(dp, -1, sizeof dp);

    // 1차원 그래프로 받기
    // 조심할점 : 비트마스킹을 위해 세로 크기가 제한이 작으니 세로로 내려가는 순으로 저장
    // 0 3 6
    // 1 4 7
    // 2 5 8
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> graph[i+N*j];
        }
    }

    cout << dpf(0, 0);
    
    return 0;
}