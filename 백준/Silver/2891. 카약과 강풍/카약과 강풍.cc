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

#define MAX 12

int N, S, R;
bool broken[MAX];
bool extra[MAX];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> S >> R;
    for(int i=0; i<S; i++){
        int a; cin >> a;
        broken[a] = true;
    }
    for(int i=0; i<R; i++){
        int a; cin >> a;
        extra[a] = true;
    }

    for(int i=1; i<=N; i++){
        if(broken[i]){
            if(extra[i]){
                extra[i] = false;
                broken[i] = false;
            }
        }
    }

    for(int i=1; i<=N; i++){
        if(broken[i]){
            if(extra[i-1]){
                extra[i-1] = false;
                broken[i] = false;
            } 
            else if(extra[i+1]){
                extra[i+1] = false;
                broken[i] = false;
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(broken[i]) cnt++;
    }
    cout << cnt << endl;

    
    return 0;
}