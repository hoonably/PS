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
주의할 점 : 0으로 시작하는 수는 없다.
*/

#define MAX 

ll alpha[10];
ll ans;
bool notZero[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		notZero[str[0] - 'A'] = 1;	// 첫 번째 자리에 있는 알파벳은 0이 되면 안 됨
		ll k = 1;
		for (int j = str.size() - 1; j >= 0; j--) {
			alpha[str[j] - 'A'] += k;
			k *= 10;
		}
	}

	bool flg = 0;
	for (int i = 0; i < 10; i++)
		if (!alpha[i])
			flg = 1;
	if (!flg) {
		// A부터 J까지의 모든 알파벳이 사용된 경우에는 어딘가에 0을 줘야 함
		// 0이 되도 괜찮은 것 중 가장 작은 것에 0을 배정
		ll min = 10000000000000000;
		int idx;	// 0을 배정할 알파벳 index
		for (int i = 0; i < 10; i++) {
			if (!notZero[i] && alpha[i] < min) {
				min = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;	// 가장 작은 것에 0 배정
	}

	sort(alpha, alpha + 10, greater<>());	// 내림차순 정렬
	for (int i = 0, j = 9; i < 10; i++, j--)
		ans += alpha[i] * j;	// 각 알파벳에 숫자 배정 후 계산
	cout << ans;

    
    return 0;
}