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

    string str;
    cin >> str;
    bool check = regex_match(str, regex("(100+1+|01)+"));
    cout << (check ? "SUBMARINE" : "NOISE");

    return 0;
}