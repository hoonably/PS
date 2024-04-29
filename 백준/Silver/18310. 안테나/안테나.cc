#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 200'000

/*
중앙값
*/

int N;
int loc[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    FOR(i,0,N-1){
        cin >> loc[i];
    }

    sort(loc,loc+N);

    cout << loc[(N+1)/2-1];
    
    return 0;
}