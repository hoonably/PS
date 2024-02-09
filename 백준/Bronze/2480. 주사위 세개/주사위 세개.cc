#include <iostream>
using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    int ans;
    if (a==b && b==c){
        ans = 10000 + a*1000;
    }
    else if (a==b || b==c){
        ans = 1000 + b*100;
    }
    else if (a==c){
        ans = 1000 + a*100;
    }
    else{
        if (a>=b & a>=c){
            ans = a*100;
        }
        else if (b>=c){
            ans = b*100;
        }
        else{
            ans = c*100;
        }
    }
    cout << ans;
    return 0;
}