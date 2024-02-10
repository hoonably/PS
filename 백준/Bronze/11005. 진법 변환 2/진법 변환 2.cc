#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, B;
    string ans = "";
    cin >> N >> B;
    while(N>0){
        int temp = N % B;
        N /= B;
        if (temp < 10){
            ans += temp + 48; // 0의 아스키코드는 48
        }
        else {
            ans += temp - 10 + 65;  // A의 아스키코드는 65
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}