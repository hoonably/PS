#include <bits/stdc++.h>
using namespace std;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    stack<char> stick;
    string str;
    cin >> str;

    for (int i=0; i<str.length(); i++){
        if (str[i]=='('){
            stick.push('(');
        }

        // 레이저
        else if (str[i-1]=='('){
            stick.pop();
            ans += stick.size();
        }

        else{
            stick.pop();
            ans ++;
        }
    }

    cout << ans;
    
    return 0;
}