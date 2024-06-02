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
int send[1001][1001];  // 최초로 i->j로 보낸 시각
vector<tiii> sends;

bool check(int start){
    int cnt = 1;
    vector<bool> virus2(N+1, false);
    virus2[start] = true;

    for (tiii send : sends){
        auto [t,a,b] = send;

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
        sends.push_back({t,a,b});
    }
    sort(all(sends));

    // 브루트 포스
    for (int i=1; i<=N; i++){
        if (virus[i] && check(i)){
            cout << i;
            break;
        }
    }
    
    return 0;
}