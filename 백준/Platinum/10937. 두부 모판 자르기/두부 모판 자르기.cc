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

dp[x][y][bit] : (x, y) 를 채워야 하는 상태에서 뒤 M개의 비트
*/

#define MAX 11

int N;
int graph[MAX][MAX];
int prices[6][6] = {
//   A   B  C  D     F
    {100, 70, 40, 0, 0, 0},  // A
    {70, 50, 30, 0, 0, 0},  // B
    {40, 30, 20, 0, 0, 0},  // C
    {0, 0, 0, 0, 0, 0},  // D
    {0, 0, 0, 0, 0, 0},  // (없음)
    {0, 0, 0, 0, 0, 0}  // F
};
int dp[MAX][MAX][1 << MAX];

int dpf(int x, int y, int bit) {

    // 줄 변경
    if (x==N) {
        y++;
        x=0;
    }

    // 끝까지 만들었을 경우
    if (y==N) {
        return 0;
    }

    // 수정하는 부분
    int &ret = dp[x][y][bit];

    if (ret!=-1) return ret;  // 저장이 이미 되어있다면

    // 이번 한개 버리고 넘어가는 경우
    ret = dpf(x+1, y, bit >> 1);

    // 이전줄에서 세로로 넣었어서 지금 타일이 이미 채워져있다면
    if ((bit&1)==1) return ret;

    // 이번 타일이 안채워져있을때 할 수 있는 행동

    // 가로로 넣는 경우 => 다다음단계로
    if (x!=N-1 && (bit & 2)==0) {
        int price = prices[graph[x][y]][graph[x+1][y]];
        ret = max(ret, price + dpf(x + 2, y, bit >> 2));
    }
    
    // 세로로 넣는 경우 => (이번 타일 + N)번째 타일에 1 표시해주고 다음 단계
    if (y!=N-1){
        int price = prices[graph[x][y]][graph[x][y+1]];
        ret = max(ret, price + dpf(x + 1, y, (bit >> 1) | (1 << (N - 1))));
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    memset(dp, -1, sizeof dp);

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            char c;
            cin >> c;
            graph[i][j] = c-'A';  // 가격 배열에 접근하기 편하도록 숫자로 저장
        }
    }

    cout << dpf(0, 0, 0);
    
    return 0;
}