#include <bits/stdc++.h>
using namespace std;

/*
LCS 최장 공통 부분 수열
두번째 수열의 i번째 문자까지의 LCS로 DP
*/

int LCS[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    // 첫번째 수를 한단계씩 나아가면서 탐색
    for (int i=0; i<len1; i++){
        int cnt = 0;

        // 두번째 수의 모든 것을 탐색
        for (int j=0; j<len2; j++){
            // 그 전 값이 카운트보다 크다면 그 값이 카운트
            if (cnt < LCS[j]){
                cnt = LCS[j];
            }

            // 값이 일치한다면 dp 저장
            // 현재 j보다 작은 값 까지의 cnt에 지금 일치하니 1 더해서 저장
            else if (str1[i] == str2[j]){
                LCS[j] = cnt + 1;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<len2; i++){
        ans = max(ans, LCS[i]);
    }
    cout << ans;
    
    return 0;
}