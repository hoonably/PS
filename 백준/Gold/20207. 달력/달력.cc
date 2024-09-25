#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int N;
int cnt[366];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        int S, E; cin >> S >> E;

        for(int j=S; j<=E; j++){
            cnt[j]++;
        }
    }

    int ans = 0;
    int w = 0, h = 0;
    for(int i = 1; i < 366; ++i){

        // 칸이 있음
        if(cnt[i]){
            h = max(h, cnt[i]);  // 최대 높이 설정
            w++;  // 너비 추가
        }

        // 칸이 없거나 마지막 칸
        if(cnt[i] == 0 || i == 365){
            ans += w * h;
            w = 0; h = 0;
        }
    }
    cout << ans;
    
    return 0;
}