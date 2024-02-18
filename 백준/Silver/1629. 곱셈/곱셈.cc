#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
분할정복으로 제곱식 구하기
*/

ll A, B, C;

// a의 b제곱
ll power(ll a, ll b){

    if (b==1) return a % C;

    ll temp = power(a, b/2);
    if (b%2==0){
        return temp * temp % C;
    }
    else {
        return ((temp * temp) % C) * A % C;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> A >> B >> C;
    cout << power(A, B);
    
    return 0;
}