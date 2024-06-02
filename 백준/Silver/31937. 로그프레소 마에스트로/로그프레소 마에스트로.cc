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

*/

#define MAX 

int N, M, K;

bool virus[1001];
bool virus2[1001];
tiii sends[10000];

bool check(int start){
    int cnt = 1;
    memset(virus2, false, sizeof(virus2));
    virus2[start] = true;

    for (int i=0; i<M; i++){
        auto [t,a,b] = sends[i];

        // 보내는 컴퓨터가 감염되어있다면
        if (virus2[a]) {

            // 원래 감염 안된거였으면 종료
            if (virus[b]==false) return false;

            if (virus2[b]==false){
                cnt++;
                virus2[b]=true;
            }
        }
    }

    // 감염된 수가 일치한다면
    if (cnt==K) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M >> K;

    // 감염된 컴퓨터
    for (int i=0; i<K; i++){
        int num;
        cin >> num;
        virus[num] = true; 
    }

    // 파일 전송 로그
    for (int i=0; i<M; i++){
        int t, a, b;
        cin >> t >> a >> b;
        sends[i] = {t,a,b};
    }
    sort(sends, sends+M);

    // 브루트 포스
    for (int i=1; i<=N; i++){
        if (virus[i] && check(i)){
            cout << i;
            break;
        }
    }
    
    return 0;
}