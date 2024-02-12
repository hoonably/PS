#include <bits/stdc++.h>
using namespace std;

long factorial(int n){
    if (n<=1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cout << factorial(N) << endl;
    
    return 0;
}