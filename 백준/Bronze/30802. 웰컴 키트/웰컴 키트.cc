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

int N, T, P;
int Tsize[6];
int ansT;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i=0; i<6; i++){
        cin >> Tsize[i];
    }

    cin >> T >> P;
    for(int i=0; i<6; i++){
        ansT += Tsize[i]/T;

        // 나누어떨어지지 않는다면
        if (Tsize[i]%T > 0) ansT++;
    }

    cout << ansT << "\n";
    cout << N/P << " " << N%P;

    
    return 0;
}