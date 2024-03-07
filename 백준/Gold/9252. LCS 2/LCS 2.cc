#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s1 >> s2;
    int len1 = s1.size();
    int len2 = s2.size();

    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            // 비교하는 문자가 동일한 경우
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            // 동일하지 않은 경우 이전의 두 경우중에 최대값 가져오기
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[len1][len2] << endl;

    // 역추적
    string lcs;
    int i=len1, j=len2;
    while(i>0 && j>0){
        // 글자가 같다면 i랑 j 둘다 빼고 탐색
        if(s1[i-1]==s2[j-1]){
            lcs = s1[i-1]+lcs;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    cout << lcs;
}