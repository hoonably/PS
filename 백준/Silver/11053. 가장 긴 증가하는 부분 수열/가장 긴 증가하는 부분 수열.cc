#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
새로운 정답 배열을 만들고,
가장 큰 값이 나왔다면 뒤에 붙이고,
아니라면 대신 들어갈 수 있는 자리에 넣는다.

10 15 20 50 40 100 30 35 50

LIS: 10 15 20  50
LIS: 10 15 20 (40)         (40로 대체)
LIS: 10 15 20  40 (100)
LIS: 10 15 20 (30) 100      (30으로 대체)
LIS: 10 15 20  30  (35)     (35로 대체)
LIS: 10 15 20 30 35 (50)    (완성)
*/

int N;

// void backtraceLIS (vector<int> &v, vector<int> &before, int idx, int num) {
//     // 역추적으로 출력해야하는경우
// 	if (idx == -1) return;
// 	if (before[idx] == num) {
// 		backtraceLIS(v, before, idx-1, num-1);
// 		cout << v[idx] << ' ';
// 	}
// 	else backtraceLIS(v, before, idx-1, num);
// }
int LIS(vector<int> &v){
    int size = v.size();
    vector<int> ans;
    // vector<int> before(size);
    for(int i=0; i<v.size(); i++){
        // B의 마지막 값보다 크다면 B에 push
        if (ans.size()==0 || v[i] > ans.back()){
            ans.push_back(v[i]);
            // before[i]=ans.size()-1;
        }
        // 아니라면 들어갈 자리 탐색
        else{
            int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[idx] = v[i];
            // before[i] = idx;
        }
    }
    int len = ans.size();
    // cout << len << '\n';
    // backtraceLIS(v, before, size-1, len-1);
    return len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; i++){
        cin >> v[i];
    }
    cout << LIS(v);
    
    return 0;
}