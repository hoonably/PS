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

int n, m;
int able[100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int P, L;
        cin >> P >> L;
        vector<int> v;
        for (int j=0; j<P; j++){
            int M;
            cin >> M;
            v.push_back(M);
        }

        if (P>=L){
            sort(all(v));
            able[i] = v[P-L]; // L번째로 작은 값
        }
        // 경쟁을 안해도 됨
        else{
            able[i] = 1;
        }
        // cout << able[i] << ' ';
    }

    sort(able, able+n);

    int ans = 0;
    for(int i=0; i<n; i++){
        m -= able[i];
        if (m>=0) ans++;
        else break;
    }
    cout << ans;
    
    return 0;
}