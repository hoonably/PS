#include <bits/stdc++.h>
using namespace std;

long fibonaicci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return fibonaicci(n-2) + fibonaicci(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    cout << fibonaicci(N) << endl;
    
    return 0;
}