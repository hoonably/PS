#include <bits/stdc++.h>
using namespace std;

string str;

int main(){
    int N;
    cin >>N;

    int ans = 0;
    for(int i=0; i<N; i++) {
        cin >> str;
        if(str[0]=='C') ans++;
    }
    cout << ans;
}   