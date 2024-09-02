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

int A[11];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N;
    cin >> N;

    memset(A, 0x3f, sizeof(A));
    for(int i=1; i<=N; i++){
        int num;
        cin >> num;

        int order = 1;
        while(true){
            if (A[order]>=i && --num == -1) break;
            else order++;
        }
        A[order] = i;
    }

    for(int i=1; i<=N; i++) cout << A[i] << ' ';


    
    return 0;
}