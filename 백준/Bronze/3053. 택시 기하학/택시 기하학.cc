#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
Pi 값은 <math.h> 의 M_PI 를 사용하면 된다.
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double R;
    cin >> R;

    cout << fixed;  // 소수점 뒤자리 고정
    cout.precision(10);
    cout << R * R * M_PI << endl;
    cout << 2 * pow(R, 2) << endl; 
    
    return 0;
}