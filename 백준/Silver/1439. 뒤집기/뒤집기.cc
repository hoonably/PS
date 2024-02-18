#include <bits/stdc++.h>
using namespace std;

/*

*/

string str;
int ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    int len = str.length();

    // 1에서 0으로 바뀌는 경우
    for (int i=0; i<len; i++){
        if (str[i-1]=='1' && str[i]=='0') ans++;
    }

    if (str[0]=='0') {
        ans++;
        if (str[len-1]=='0') ans--;
    }
    
    cout << ans;

    return 0;
}