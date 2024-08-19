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

#define MAX 1001

int T, n, m;
int S[MAX];
map<int, int> Smap;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;

    // 부분합으로 바로 저장
    int num;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> num;
        S[i] = S[i-1] + num;
    }

    // 모든 부 배열의 합을 cnt에 카운트
    for(int i=0; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            int Asum = S[j]-S[i];
            Smap[Asum]++;
        }
    }

    // for (pii i : Smap) cout << i.first << ' ' << i.second << '\n';
    
    // B 부분합
    memset(S, 0, sizeof(S));
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> num;
        S[i] = S[i-1] + num;
    }

    // B의 부배열 합과 맞췄을 때 T가 나오게 하는
    // A의 부배열이 있으면 그 카운트를 정답에 더하기
    ll ans = 0;
    for(int i=0; i<=m; i++){
        for (int j=i+1; j<=m; j++){
            int need = T - (S[j]-S[i]);
            if (Smap.find(need)==Smap.end()) continue;
            ans += Smap[need];
        }
    }
    cout << ans;

    return 0;
}