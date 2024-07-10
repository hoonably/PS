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
https://www.acmicpc.net/problem/27084

*/

#define MAX 200'001

int N;
int A[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        A[num]++;
    }

    ll ans = 1;
    for(int i=1; i<=N; i++){
        if (A[i]) {
            ans *= A[i]+1;
            ans %= MOD;
        }
    }

    // 아무것도 안뽑았을때 빼주기
    if (ans==0) {
        cout << MOD-1;
    }
    else {
        cout << ans-1;
    }

    return 0;
}