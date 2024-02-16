#include <bits/stdc++.h>
using namespace std;

/*

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int min_cost = 1e9, ans = 0;
    int N, cost;

    cin >> N;
    int div[N-1];
    for (int i=0; i<N-1; i++){
        cin >> div[i];
    }
    for (int i=0; i<N-1; i++){
        cin >> cost;
        min_cost = min(min_cost, cost);
        ans += min_cost * div[i];
    }
    cin >> cost;
    cout << ans;
    
    return 0;
}