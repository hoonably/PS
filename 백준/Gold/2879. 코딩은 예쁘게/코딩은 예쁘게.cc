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
int now[1001], res[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> now[i];
    for(int i=0; i<N; i++) cin >> res[i];

    // 시작지점부터 맞춰줌
	int ans = 0, gap = 0;
	for (int i = 0; i < N; i++) {
		int diff = res[i] - now[i];

        // 탭을 추가
		if (diff > 0) {
            // 이전 값이 음수면 그 차이만큼 더해줌
			if (gap < 0) ans += diff;
			else {
				if (gap >= diff) gap = diff;
				else ans += (diff - gap);
			}
		}

        // 탭을 삭제
		else {
			if (gap > 0) ans -= diff;
			else {
				if (gap <= diff) gap = diff;
				else ans += (gap - diff);
			}
		}
		gap = diff;
	}
	cout << ans;
    
    return 0;
}