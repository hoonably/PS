#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1000000007;

/* -----------------------------------------------------

*/


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    if(n == 0)
    {
        cout << "0\n";
        return 0;
    }

    string result;
    while (n != 0)
    {
        if(n%-2 == 0)
        {
            result += "0";
            n /= -2;
        }else
        {
            result += "1";
            n = (n-1) / -2;  // 조심
        }
    }
    reverse(result.begin(), result.end());

    cout << result << '\n';
    
    return 0;
}