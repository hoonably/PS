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

int N;
vector<int> B;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++){
        int a; cin >> a;
        B.push_back(a);
    }

    // 
    int ans = 0;
    while(true){
        for(int &b : B){
            if(b==0) continue;
            if(b%2==1) {ans++, b--;}
            b/=2;
        }
        
        // 모든 수가 0?
        bool flag = true;
        for(int b : B) if(b!=0) {flag = false; break;}
        if(flag) break;  // 모든 수가 0이면 break

        ans++;  // 모든 수를 2로 나눠주는 과정
    }
    cout << ans;
    
    return 0;
}