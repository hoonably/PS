#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,0,0,-1,0,0 };
const int dy[6] = { 0,1,-1,0,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------
메모리 제한 매우 낮음 -> 배열, 세그먼트 트리, 등등 사용 X

dp 점화식 사용

1에서 인덱스가 시작하면, 총 n명일 때 s에 있던 사람이 옮겨지면서 ((s-1){mod {n}})+1} 의 위치로 간다.


f(n,k)이 생존자의 자리라고 하자. k번째 사람이 죽으면, n-1개가 원안에 남는다.

다시 시작되는 카운트(원을 순환)는 k mod {n} + 1 자리에 있던 사람부터 시작한다.

남은 원 안에 남은 생존자의 자리는 f(n-1,k)가 될 것이다.

따라서 다음의 점화식이 나온다.

f(n, k)이 마지막으로 남는 번호라고 할 때,
f(n, k) = ((f(n - 1, k) + k - 1) mod n) + 1
*/

#define MAX 



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    int ans = 0;
	for (int i = 1; i <= n; i++){
		ans = (ans + k - 1) % i + 1;
    }
	cout << ans;
    
    return 0;
}