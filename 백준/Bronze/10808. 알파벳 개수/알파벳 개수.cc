#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int alpha[26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string str;
    cin >> str;

    for (char i : str){
        alpha[i-'a']++;
    }

    for (int i : alpha){
        cout << i << ' ';
    }

    
    return 0;
}