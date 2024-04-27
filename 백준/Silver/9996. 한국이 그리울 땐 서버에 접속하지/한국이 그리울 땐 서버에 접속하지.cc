#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*
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