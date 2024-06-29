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

int s, p;
string DNA;
int A, C, G, T;
int a, c, g, t;

void slide(char alphabet, int plusMinus){
    if (alphabet=='A') a+=plusMinus;
    else if (alphabet=='C') c+=plusMinus;
    else if (alphabet=='G') g+=plusMinus;
    else t+=plusMinus;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> p;
    cin >> DNA;
    cin >> A >> C >> G >> T;

    int start=0, end=p-1;
    
    for (int i=0; i<p; i++){
        slide(DNA[i],1);
    }

    int ans = 0;
    
    while(end<s){
        // 만족
        if (a>=A && c>=C && g>=G && t>=T){
            ans++;
        }
        slide(DNA[start], -1);  // 제거
        start++; end++;
        slide(DNA[end], 1);  // 추가
    }
    cout << ans;
    
    return 0;
}