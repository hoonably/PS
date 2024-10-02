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
https://www.acmicpc.net/problem/17521
살수있는 만큼 많이 사고 떨어지기 전에 팔기
*/

#define MAX 

ll n, W, coinNum, coinPrice[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> W;

    for(int i = 1; i <= n; i++) cin >> coinPrice[i];
    
    for(int i = 1; i <= n - 1; i++){
        if(coinPrice[i] < coinPrice[i+1]){
            coinNum = W / coinPrice[i];
            W %= coinPrice[i];
            W += coinPrice[i+1] * coinNum;
        }        
    }

    cout << W;
    
    return 0;
}