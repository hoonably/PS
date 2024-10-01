#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

bool isSelfNumber[10001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for(int i=1; i<=10000; i++){
        int sum = i;
        int temp = i;
        while(temp){
            sum += temp%10;
            temp /= 10;
        }
        if(sum <= 10000) isSelfNumber[sum] = true;
    }

    for(int i=1; i<=10000; i++){
        if(!isSelfNumber[i]) cout << i << '\n';
    }
    
    return 0;
}