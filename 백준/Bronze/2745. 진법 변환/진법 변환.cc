#include <iostream>
#include<cmath>
using namespace std;

int main(){
    string N;
    int B, intArr[33], ans=0;

    cin >> N >> B;
    
    int length = N.length();

    for (int i=0; i< length; i++){
        // 알파벳이라면
        if (N[i]>=65){
            intArr[i] = N[i]-65+10;
        }
        // 숫자라면 (0의 아스키코드는 48)
        else{
            intArr[i] = N[i]-48;
        }
    }

    for (int i=length-1; i>=0; i--){
        ans += intArr[i] * pow(B, length-1-i);
    }

    cout << ans;

    return 0;
}