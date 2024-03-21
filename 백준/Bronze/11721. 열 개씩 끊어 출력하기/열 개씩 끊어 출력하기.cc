#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 

/*

*/

string str;
int e;

void print(int now){
    if (now==e) return;
    if (now%10==0) cout << endl;
    cout << str[now];
    print(now+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> str;
    e = str.length();
    cout << str[0];
    print(1);

    
    return 0;
}