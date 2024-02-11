#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    int ans = 1;
    for (int i=1; i<=n; i++){
        ans *= i;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cout << factorial(N) << endl;
    
    return 0;
}