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

int N, L;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> L;
    while(L <= 100){
        int sum = L*(L-1)/2;
        if((N-sum)%L == 0 && (N-sum)/L >= 0){
            for(int i = 0; i < L; i++){
                cout << (N-sum)/L+i << " ";
            }
            return 0;
        }
        L++;
    }
    cout << -1;
    
    return 0;
}