#include <bits/stdc++.h>
using namespace std;

/*
dp[0][i] : a가 1~i 글자까지에서 나오는 갯수
dp[1][i] : b가 1~i 글자까지에서 나오는 갯수
*/

string S;
int q, l, r;
char a;
int dp[26][200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> S;

    // 처음꺼만
    dp[S[0]-'a'][0] = 1;

    for (int i=1; i<S.size(); i++){
        for (int j=0; j<26; j++){
            dp[j][i] = dp[j][i-1];
        }
        dp[S[i]-'a'][i]++;
    }

    cin >> q;
    while(q--){
        cin >> a >> l >> r;
        // 이 문제에서는 0번째 문자부터 기록
        cout << dp[a-'a'][r] - dp[a-'a'][l-1] << '\n';
    }
    
    return 0;
}