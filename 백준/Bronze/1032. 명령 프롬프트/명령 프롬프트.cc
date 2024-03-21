#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;
    
    string str;
    cin >> str;

    int len = str.length();

    for (int i=1; i<N; i++){
        for (int j=0; j<len; j++){
            char a;
            cin >> a;
            if (str[j]=='?') continue;
            if (a!=str[j]) str[j] = '?';
        }
    }
    cout << str;
    
    return 0;
}