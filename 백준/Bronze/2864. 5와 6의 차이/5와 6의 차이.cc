#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*

*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string a, b;
    cin >> a >> b;

    int smallA = 0;
    int bigA = 0;

    for (int i=0; i<a.length(); i++){

        // 자리수 올려주기
        smallA*=10;
        bigA*=10;

        if(a[i]=='5' || a[i]=='6'){
            smallA += 5;
            bigA += 6;
        }
        else {
            smallA += a[i]-'0';
            bigA += a[i]-'0';
        }
    }

    int smallB = 0;
    int bigB = 0;

    for (int i=0; i<b.length(); i++){

        // 자리수 올려주기
        smallB*=10;
        bigB*=10;

        if(b[i]=='5' || b[i]=='6'){
            smallB += 5;
            bigB += 6;
        }
        else {
            smallB += b[i]-'0';
            bigB += b[i]-'0';
        }
    }

    cout << smallA + smallB << ' ' << bigA + bigB;
    
    return 0;
}