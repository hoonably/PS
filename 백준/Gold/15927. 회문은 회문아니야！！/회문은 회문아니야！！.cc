#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
부분 문자열 중 팰린드롬이 아닌 가장 긴 부분 문자열의 길이 출력
*/

bool isPalindrome(const string &str, int len){
    for (int i=0; i<len/2; i++){
        if (str[i]!=str[len-i-1]){
            return false;
        }
    }
    return true;
}

bool isAllSame(const string &str, int len){
    char first = str[0];
    for (int i=1; i<=len/2; i++){
        if (str[i]!=first){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;
    int len = str.length();

    if (isPalindrome(str, len)) {
        if (isAllSame(str, len)) cout << -1;
        else cout << len-1;
    }
    else cout << len;
    
    return 0;
}