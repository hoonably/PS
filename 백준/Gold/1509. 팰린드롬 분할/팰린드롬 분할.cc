#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(idx,a,b) for(int idx=(a);idx<(b);idx++)
#define all(v) v.begin(), v.end()
#define MAX 2501

/*
https://www.acmicpc.net/problem/1509
ABACABA를 팰린드롬으로 분할하면, {A, B, A, C, A, B, A}, {A, BACAB, A}, {ABA, C, ABA}, {ABACABA}등이 있다.
분할의 개수의 최솟값을 출력하는 프로그램을 작성하시오.

dp[idx] : i번째 글자까지 팰린드롬 묶음의 개수의 최소값
*/

string str;
int len;
vector<int> v[MAX];  // i~j 까지가 팰린드롬
int dp[MAX];

void Palindrome(int s, int e){
    if (s<=0 || e>len) return;
    if (str[s]!=str[e]) return;

    v[s].push_back(e);
    // cout << s << ' ' << e << '\n';
    Palindrome(s-1, e+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    cin >> str;
    len = str.length();

    str = ' ' + str;
    
    // 홀수 팰린드롬 생성
    for (int i=1; i<=len; i++){
        Palindrome(i, i);
    }

    // 짝수 팰린드롬 생성
    for (int i=2; i<=len; i++){
        if (str[i]==str[i-1]){
            Palindrome(i-1, i);
        }
    }

    // dp 생성
    for (int i=1; i<=len; i++){
        dp[i]=i;
    }

    for (int s=1; s<=len; s++){
        for (int e : v[s]){
            dp[e] = min(dp[e], dp[s-1]+1);
        }
    }

    // for (int i=1; i<=len; i++){
    //     cout << dp[i] << ' ';
    // }
    cout << dp[len];
    
    return 0;
}