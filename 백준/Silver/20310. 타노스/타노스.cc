#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
const int dx[6] = { 1,-1,0,0,0,0 };
const int dy[6] = { 0,0,1,-1,0,0 };
const int dz[6] = { 0,0,0,0,1,-1 };
const int INF = 0x7f7f7f7f;
const ll LINF = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1'000'000'007;

/* -----------------------------------------------------

*/

#define MAX 

string str;
int cnt0, cnt1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    cin >> str;
    for (char c:str){
        if (c=='0')cnt0++;
        else cnt1++;
    }

    cnt0/=2;
    cnt1/=2;
    
    for (char c:str){
        if (c=='0'){
            if (cnt0) {
                cnt0--;
                cout << '0';
            }            
        }
        else {
            if (cnt1) cnt1--;
            else cout << '1';   
        }
    }
    
    return 0;
}