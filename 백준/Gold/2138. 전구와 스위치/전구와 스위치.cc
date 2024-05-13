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
i(1 < i < N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다.
*/

#define MAX 100'002

int N;
bool before1[MAX], before2[MAX], after[MAX];

// 세개를 바꿈
void turn(int idx, bool before[]){
    before[idx-1]^=1;
    before[idx]^=1;
    before[idx+1]^=1;
}

// 1번 스위치를 누름
int switchCnt1(){
    int cnt = 1;
    turn(1, before1);
    for (int i=2; i<=N; i++){
        // 이전이 틀렸다면 무조건 눌러야함
        if (before1[i-1]!=after[i-1]){
            turn(i, before1);
            cnt++;
        }
    }
    if (before1[N]!=after[N]) return INF;  // 불가능
    else return cnt;
}

// 1번 스위치를 누르지 않음
int switchCnt2(){
    int cnt = 0;
    for (int i=2; i<=N; i++){
        // 이전이 틀렸다면 무조건 눌러야함
        if (before2[i-1]!=after[i-1]){
            turn(i, before2);
            cnt++;
        }
    }
    if (before2[N]!=after[N]) return INF;  // 불가능
    else return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++){
        char c;
        cin >> c;
        before1[i] = (c=='1');  // 1이면 true
    }

    memcpy(before2, before1, sizeof(before1));

    for (int i=1; i<=N; i++){
        char c;
        cin >> c;
        after[i] = (c=='1');  // 1이면 true
    }

    // 1번 스위치를 누르는 경우, 1번 스위치를 누르지 않는 경우
    int ans = min(switchCnt1(), switchCnt2());
    if (ans==INF) cout << -1;  // 둘 다 불가능
    else cout << ans;

    return 0;
}