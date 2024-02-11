#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    int ans = 1;
    for (int i=1; i<=n; i++){
        ans *= i;
    }
    return ans;
}

int binomial_coefficient(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    cout << binomial_coefficient(N, K);
    
    return 0;
}