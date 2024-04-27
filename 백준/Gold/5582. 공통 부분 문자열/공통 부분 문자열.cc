#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 4001

/*

*/

string a, b;
int dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;

    int ans = 0;
    for (int i=0; i<a.length(); i++){
        for (int j=0; j<b.length(); j++){
            if (a[i]==b[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                ans = max(ans, dp[i+1][j+1]);
            }
        }
    }
    cout << ans;
    
    return 0;
}