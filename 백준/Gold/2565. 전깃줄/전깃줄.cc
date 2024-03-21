#include <bits/stdc++.h>
using namespace std;

/*
가장 긴 증가하는 부분수열 문제와 비슷하다.
대신 idx도 지정될 뿐이다.
*/

int dp[100];
vector<pair<int, int>> line;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int s, e;
        cin >> s >> e;
        line.push_back(make_pair(s,e));
        dp[i] = 1;  // dp 테이블 초기화
    }

    // pair 배열 first 기준으로 정렬
    sort(line.begin(), line.end());

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            // i보다 앞 순서의 도착지점이 더 적은지 체크
            if (line[j].second < line[i].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 1;
    for(int i=0; i<N; i++){
        // cout << dp[i] << ' ';  // TEST Code
        ans = max(ans, dp[i]);
    }

    // 없애야 하는 최소 개수이기 때문에
    // 총 줄의 개수에서 계속 증가하는 줄의 최대 개수를 빼면 된다.
    cout << N - ans;
    
    return 0;
}