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
    
    int N, L;
    int W[1001];
    cin >> N >> L;

    L--;

    for (int i=0; i<N; i++){
        cin >> W[i];
    }
    sort(W, W+N);

    int ans = 0;
    int last = W[0];
    for (int i=1; i<N; i++){
        if (W[i] - last > L) {
            ans++;
            last = W[i];
        }
    }
    cout << ans+1;
    
    return 0;
}