#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/

string str;
bool good_password(){
    bool have_vowel = false;  // 모음 포함 여부
    int vowel = 0;  // 연속 모음 개수 (음수면 연속 자음 개수)
    int cnt = 0;
    for(char c : str){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            have_vowel = true;
            vowel = max(++vowel, 1);
            if (vowel >= 3) return false;  // 모음 3개 연속
        }
        else {
            vowel = min(--vowel, -1);
            if (vowel <= -3) return false;  // 자음 3개 연속
        }
        if(cnt >= 1 && c == str[cnt-1] && c != 'e' && c != 'o') return false;  // 연속 자음, 모음
        cnt++;
    }
    return have_vowel;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while(true){
        cin >> str;
        if(str == "end") break;
        if(good_password()) cout << "<" << str << "> is acceptable.\n";
        else cout << "<" << str << "> is not acceptable.\n";
    }
    
    return 0;
}