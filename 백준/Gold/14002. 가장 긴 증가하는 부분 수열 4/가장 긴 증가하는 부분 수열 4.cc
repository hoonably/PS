#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
dp[i] : i번째까지 가장 긴 증가하는 부분수열의 길이
i-1번째까지 중에서 현재 수보다 작을 경우에 
저장된 dp값 + 1 (현재숫자)를 갱신
*/

int arr[1001], dp[1001], pre[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i];
        dp[i] = 1;  // dp 테이블 초기화
    }

    for(int i=1; i<=N; i++){
        // i보다 앞 순서의 숫자가 더 적은지 체크 후 dp 갱신
        for(int j=1; j<i; j++){
            if (arr[j]<arr[i]) {
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    pre[i] = j;
                }
            }
        }
    }

    int idx = max_element(dp+1, dp+N+1) - dp;
    int len = dp[idx];
    cout << len << '\n';

    stack<int> st;
    for (int i=0; i<len; i++){
        st.push(arr[idx]);
        idx = pre[idx];
    }
    while(!st.empty()){
        cout << st.top() << ' ';
        st.pop();
    }

    
    return 0;
}