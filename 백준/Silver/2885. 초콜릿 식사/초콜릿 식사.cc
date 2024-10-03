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

int K;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> K;

    int cho = 1;  // 구매해야하는 가장 작은 초콜릿의 크기
    while(K > cho) cho *= 2;
    cout << cho << ' ';

    int cnt = 0;
    while(K>0){
        if (K >= cho) K-=cho;
        else {
            cnt++;
            cho /= 2;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}