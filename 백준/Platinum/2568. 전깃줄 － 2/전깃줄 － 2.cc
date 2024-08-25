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
새로운 정답 배열을 만들고,
이분탐색을 이용

이 문제에서는 제거해야할 것을 출력함
*/

#define MAX 100001

int N;
pii arr[MAX];
int before[MAX];
vector<int> ans;

void backtrace (int idx, int num) {
	if (idx == 0) return;
	
    // 사용
	if (before[idx] == num) {
		backtrace(idx-1, num-1);		
    }

    // 제거
	else {
		backtrace(idx-1, num);
        cout << arr[idx].first << '\n';
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr+1, arr+N+1);

    for (int i=1; i<=N; i++){

        // B의 마지막 값보다 크다면 B에 push
        if (ans.empty() || arr[i].second > ans.back()){
            ans.push_back(arr[i].second);
            before[i]=ans.size()-1;
        }
        // 아니라면 들어갈 자리 탐색
        else{
            int idx = lower_bound(ans.begin(), ans.end(), arr[i].second) - ans.begin();
            ans[idx] = arr[i].second;
            before[i] = idx;
        }
    }

    int len = ans.size();
    cout << N - len << '\n';
    backtrace(N, len-1);
    
    return 0;
}