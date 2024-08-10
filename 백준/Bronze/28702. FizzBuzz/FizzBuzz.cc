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

string A;

void printAns(int num){
    if (num%15==0) cout << "FizzBuzz";
    else if (num%3==0) cout << "Fizz";
    else if (num%5==0) cout << "Buzz";
    else cout << num;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    for (int i=3; i>0; i--){
        cin >> A;
        if (A[0] != 'F' && A[0] != 'B') {
            printAns(stoi(A)+i);
            return 0;
        }
    }

    
    return 0;
}