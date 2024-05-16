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
https://www.acmicpc.net/problem/19939
 
N개의 공을 K개의 바구니에 빠짐없이 나누어 담는다.
각 바구니에는 1개 이상의 공이 들어 있어야 한다.
각 바구니에 담긴 공의 개수는 모두 달라야 한다.
가장 많이 담긴 바구니와 가장 적게 담긴 바구니의 공의 개수 차이가 최소가 되어야 한다.
*/

#define MAX 

int N, K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int sum = 0;

    cin >> N >> K;

    N -= K*(K+1)/2;


    // 1~K 누적합보다 작다면
    if (N < 0) {
        cout << -1;
        return 0;
    }

    // 나누어떨어지면
    if (N % K == 0) cout << K - 1;

    // 나누어떨어지지 않는다면
    else cout << K;

    return 0;
}