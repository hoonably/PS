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

bool isPrime(int num){
    for(int i=2; i*i<=num; i++){
        if (num%i==0) return false;
    }
    return true;
}

void backtracking(int level, int now){
    if (level==N){
        cout << now << '\n';
        return;
    }
    vector<int> v = {1, 3, 5, 7, 9};
    for(int i : v){
        int nxt = 10 * now + i;
        if (isPrime(nxt)) backtracking(level+1, nxt);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    backtracking(1, 2);
    backtracking(1, 3);
    backtracking(1, 5);
    backtracking(1, 7);
    

    return 0;
}