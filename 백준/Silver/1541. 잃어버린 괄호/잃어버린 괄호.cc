#include <bits/stdc++.h>
using namespace std;

/*
-가 한번 나온 이후부터는 무조건 다 빼면 된다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    int temp = 0;
    bool minus = false;
    string line;
    

    cin >> line;
    line += '+';  // 마지막 연산 위해

    for(int i=0; i<line.size(); i++){
        if (line[i]=='+'){
            if (minus) {
                ans -= temp;
                temp=0;
            }
            else {
                ans += temp;
                temp=0;
            }
        }
        else if (line[i]=='-') {
            if (minus) {
                ans -= temp;
                temp=0;
            }
            else {
                ans += temp;
                temp=0;
            }
            minus = true;
            ans -= temp;
            temp=0;
        }
        else{
            temp *= 10;  // 자리수 올려주기
            temp += line[i]-'0';
        }
    }
    cout << ans;
    
    return 0;
}