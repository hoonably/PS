#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
회문 : 팰린드롬
유사회문 : 한 문자를 삭제하면 팰린드롬
그 외에는 일반 문자열
*/

// a번째에서 틀렸을때 유사회문인지 확인
bool isLikePalindrome(const string &str, int len, int a){

    bool ret = true;
    // a번째를 제거
    for (int i=a; i<len/2; i++){
        if (str[i+1]!=str[len-i-1]){
            ret = false;
            break;
        }
    }
    if (ret) return true;

    // 뒤에서 a번째를 제거
    for (int i=a; i<len/2; i++){
        if (str[i]!=str[len-i-2]){
            return false;
        }
    }
    return true;
}

int solve(){
    string str;
    cin >> str;
    int len = str.length();

    for (int i=0; i<len/2; i++){
        if (str[i]!=str[len-i-1]){
            if (isLikePalindrome(str, len, i)) return 1;
            else return 2;
        }
    }
    return 0;  // palindrome
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        cout << solve() << '\n';
    }
    
    return 0;
}