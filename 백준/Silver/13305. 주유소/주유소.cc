#include <bits/stdc++.h>
using namespace std;

/*

*/

long long N, cost, min_cost = 1e9, ans = 0;
long long dist[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i=0; i<N-1; i++){
        cin >> dist[i];
    }
    for (int i=0; i<N-1; i++){
        cin >> cost;
        min_cost = min(min_cost, cost);
        ans += min_cost * dist[i];
    }
    cin >> cost;
    cout << ans;
    
    return 0;
}