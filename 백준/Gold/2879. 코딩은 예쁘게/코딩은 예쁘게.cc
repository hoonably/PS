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
int diff[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++) cin >> diff[i];
    for(int i=0; i<N; i++) {
        int res;
        cin >> res;
        diff[i] = res - diff[i];
    }

    // 시작지점부터 맞춰줌
	int ans = 0, gap = 0;
	for (int i = 0; i < N; i++) {

        // 탭을 추가
		if (diff[i] > 0) {
            // 이전 값이 음수면 그 차이만큼 더해줌
			if (gap < 0) ans += diff[i];
			else if (gap < diff[i]) ans += (diff[i] - gap);
		}

        // 탭을 삭제
		else {
			if (gap > 0) ans -= diff[i];
			else if (gap > diff[i]) ans += (gap - diff[i]);
		}
		gap = diff[i];
	}
	cout << ans;
    
    return 0;
}