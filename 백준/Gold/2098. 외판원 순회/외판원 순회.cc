#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX


/*

*/

int N;
int W[16][16];
int dp[16][1 << 16];

int dpf(int bit, int now){
    // 다시 원래의 도시로 돌아오는 순회 여행 경로
    // 이기 때문에 0번 으로 돌아오는 것까지 생각해야한다.
    if (bit == (1<<N)-1){ //탐색 완료
        if(W[now][0] == 0) //이동불가능
            return 1e9;
        return W[now][0];
    }

    int &ret = dp[now][bit];

    // 이미 정해진 값이라면 PASS
    if (ret != -1) return ret;
    
    ret = 1e9;
    
    // 현재 안켜져있는 비트에 대해 재귀로 최소값 다지기
    for (int nxt = 0; nxt < N; ++nxt){

        // 갈 수 없는 경우
        if (W[now][nxt]==0) continue;

        // 다음번 비트가 0이라면 켜주고 재귀
        if ((bit & (1 << nxt))==0)
            ret = min(ret, W[now][nxt] + dpf(bit | (1 << nxt), nxt));
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
 
    cout << dpf(1, 0);
    
    
    return 0;
}