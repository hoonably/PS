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

int N, cnt;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;

    ll left = 0, right = 0, sum = 0, cnt = 0;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (num%2) {
            sum += cnt++;
			left += i;
			right += N - i - 1;
        }
    }

    cout << min(left, right) - sum;


    
    return 0;
}