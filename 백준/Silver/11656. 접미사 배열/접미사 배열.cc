#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;

    string S[1001];
    for (int i=str.length()-1; i>=0; i--){
        S[i] = str[i] + S[i+1];
    }

    sort(S, S+str.length());

    for (int i=0; i<str.length(); i++){
        cout << S[i] << '\n';
    }
    
    return 0;
}