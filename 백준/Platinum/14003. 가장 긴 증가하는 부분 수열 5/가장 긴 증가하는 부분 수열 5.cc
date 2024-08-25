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
이분탐색을 이용해 
*/

#define MAX 1000001

int N;
int arr[MAX], before[MAX];
vector<int> ans;

void backtrace (int idx, int num) {
	if (idx == 0) return;
		
	if (before[idx] == num) {
		backtrace(idx-1, num-1);
		cout << arr[idx] << ' ';
	}
	else {
		backtrace(idx-1, num);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;

    for (int i=1; i<=N; i++){

        cin >> arr[i];

        // B의 마지막 값보다 크다면 B에 push
        if (ans.empty() || arr[i] > ans.back()){
            ans.push_back(arr[i]);
            before[i]=ans.size()-1;
        }
        // 아니라면 들어갈 자리 탐색
        else{
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
            before[i] = idx;
        }
    }

    int len = ans.size();
    cout << len << '\n';
    backtrace(N, len-1);
    
    return 0;
}