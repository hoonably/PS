#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int K, num;
    stack<int> S;
    cin >> K;
    while(K--){
        cin >> num;
        if (num==0) S.pop();
        else S.push(num);
    }
    int sum = 0;
    while(!(S.empty())){
        sum += S.top();
        S.pop();
    }
    cout << sum;
    
    return 0;
}