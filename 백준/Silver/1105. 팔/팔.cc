#include <bits/stdc++.h>
#define FOR(i,L,R) for(int i=(L);i<(R);i++)
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
https://www.acmicpc.net/problem/1105
L과 R이 주어진다. 이때, L보다 크거나 같고, R보다 작거나 같은 자연수 중에 
8이 가장 적게 들어있는 수에 들어있는 8의 개수를 구하는 프로그램을 작성하시오.

가장 큰 자리수부터 보면서 각 자리수의 숫자가 달라질 때까지
8의 개수를 세어주면 된다.
*/

#define MAX 

string L, R;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> L >> R;

    // 자리수 다르면 무조건 0개의 8로 만들 수 있음
    if (L.length() != R.length()) {
		cout << 0;
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < L.length(); i++) {
		if (L[i] == R[i] && L[i] == '8')
			cnt++;
		else if (L[i] != R[i])
			break;
	}
	cout << cnt;
    
    return 0;
}