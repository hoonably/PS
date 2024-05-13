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
https://www.acmicpc.net/problem/13164
정렬 후 연속된 수의 차를 구하고
그 차가 가장 큰 부분부터 K-1개 끊어내면 된다.
*/

#define MAX 300'000

int N, K;
int height[MAX], diff[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> height[i];
    }
    sort(height, height+N);

    for (int i=1; i<N; i++){
        // diff[i] = i-1번째와 i번째 차이
        diff[i] = height[i]-height[i-1];
    }
    sort(diff, diff+N, greater<>());

    ll ans = 0;
    // K-1번의 큰 값을 제외하고 그 이후부터는 모두 더하기
    for (int i=K-1; i<N; i++){
        ans += diff[i];
    }
    cout << ans;
    
    return 0;
}