#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
DFA 문제
그래프를 그려 해결해야함.

(100+1+ | 01)+ 패턴 찾기

(10 0여러개 1여러개  or 01) 반복 패턴이면 YES

지금 풀이는 정규표현식 사용
*/

string pattern;

bool solve(){
    string str;
    cin >> str;
    return regex_match(str, regex(pattern));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;

    cin >> pattern;

    // 정규표현식으로 업데이트
    pattern.replace(pattern.find('*'), 1, "\\w*");

    while(T--){
        cout << (solve() ? "DA\n" : "NE\n");
    }
    
    return 0;
}