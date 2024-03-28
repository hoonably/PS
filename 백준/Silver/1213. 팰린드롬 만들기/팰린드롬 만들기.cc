#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

// 각 문자가 나온 개수
int cnt[26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;

    for (char c : str){
        cnt[c-'A']++;
    }

    // 홀수인 문자 확인
    char odd = '0';
    for (int i=0; i<26; i++){
        if (cnt[i] % 2==1) {
            if (odd=='0') {
                odd = i+'A';
                cnt[i]--;
            }
            else {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }

    // // 출력
    for (int i=0; i<26; i++){
        for (int j=0; j<cnt[i]/2; j++){
            cout << (char)(i+'A');
        }
    }
    
    if (odd!='0') cout << odd;

    for (int i=25; i>=0; i--){
        for (int j=0; j<cnt[i]/2; j++){
            cout << (char)(i+'A');
        }
    }
    
    return 0;
}