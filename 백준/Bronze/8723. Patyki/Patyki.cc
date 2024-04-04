#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
직각삼각형이나 정사각형 둘다 못만들면 0
직각삼각형만 만들 수 있으면 1
정삼각형만 만들 수 있으면 2
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int len[3];
    cin >> len[0] >> len[1] >> len[2];
    sort(len, len+3);
    
    // 직각삼각형
    if (len[2]*len[2] == len[0]*len[0] + len[1]*len[1]) {
        cout << 1;
    }
    // 정삼각형
    else if (len[0]==len[1] && len[1]==len[2]){
        cout << 2;
    }
    else cout << 0;
    
    return 0;
}