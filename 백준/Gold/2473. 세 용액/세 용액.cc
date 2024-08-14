#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
// const int INF = 0x3f3f3f3f;  // 1061109567
const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

int N;
vector<int> A;
ll best = INF;
tiii ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    A.resize(N);
    for(int& num : A) cin >> num;

    sort(all(A));

    int s = 0, e = N-1;

    // 하나 고정
    for (int i=0; i<N-2; i++){

        int s = i+1, e = N-1;
        while(s<e){
            ll sum = (ll)A[i]+A[s]+A[e];

            // 답 갱신
            if (abs(sum) < best){
                best = abs(sum);
                ans = {i, s, e};

                if (best==0) break;
            }

            if (sum<0) s++;
            else e--;
        }
    }

    auto [a, b, c] = ans;
    cout << A[a] << ' ' << A[b] << ' ' << A[c];
    
    return 0;
}