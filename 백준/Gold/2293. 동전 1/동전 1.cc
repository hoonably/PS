#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

*/

int n, k;
vector<int> coin;
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        coin.emplace_back(num);
    }
    
    dp[0]=1;

    for (int c : coin){
        for (int i=c; i<=k; i++){
            dp[i] += dp[i-c];
        }
    }
    cout << dp[k];
    
    return 0;
}