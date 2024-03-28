#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define MAX

/*
반례 : 무조건 V의 나머지를 더해주는 것은 아닙니다.
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T = 1;
    ll L, P, V;
    while(true){
        cin >> L >> P >> V;
        if (L==0) break;

        printf("Case %d: %d\n", T++, L * (V/P) + min(L,(V%P)));
    }
    
    return 0;
}